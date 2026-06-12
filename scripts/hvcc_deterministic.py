#!/usr/bin/env python3
"""Deterministic drop-in wrapper around hvcc's CLI.

hvcc 0.15.0 emits non-reproducible C++ for byte-identical input. Three
independent sources of randomness churn the vendored Heavy/ sources on every
regeneration -- burying real patch changes under thousands of lines of noise:

  1. The 8-char object IDs (cBinop_<id>_sendMessage, ...) are drawn from an
     unseeded random.Random() instance in HeavyLangObject.
  2. The seed arguments hvcc synthesises for random~/noise~ DSP objects come
     from the unseeded global `random` module -- and these DO land in the
     generated C++ as literal integers.
  3. The per-object sendMessage decls/defs are emitted in Python set-iteration
     order, which for graph objects is keyed by identity (memory address) and
     so varies per process. PYTHONHASHSEED does not affect this.

None of the three changes runtime behaviour: the order-sensitive init and
process code is generated from a separate, already-deterministic ordering.
This wrapper pins all of it so `build_hvcc.sh` produces a stable diff:

  * PYTHONHASHSEED=0          -- fixes str/bytes set ordering (e.g. #include
                                 order). It is read only at interpreter
                                 startup, so we re-exec ourselves once if it
                                 is not already set.
  * random.seed(0)           -- fixes the random~/noise~ seed arguments.
  * HeavyLangObject RNG seed -- fixes the object IDs.
  * sort get_ir_control_list -- emits sendMessage functions by object id
                                 instead of memory-address order.

Invoke exactly like the `hvcc` binary; all argv are forwarded to hvcc.main()
and the exit code mirrors it (0 = clean, 1 = errors).
"""
import os
import sys

# PYTHONHASHSEED is consumed at interpreter start-up, so it cannot be set from
# within a running process -- re-exec ourselves once with it pinned.
if os.environ.get("PYTHONHASHSEED") != "0":
    os.environ["PYTHONHASHSEED"] = "0"
    os.execv(sys.executable, [sys.executable, *sys.argv])

import random

# (2) global RNG -> deterministic random~/noise~ seed arguments.
random.seed(0)

# (1) per-object 8-char IDs are minted from this private Random() instance.
from hvcc.core.hv2ir.HeavyLangObject import HeavyLangObject
HeavyLangObject._HeavyLangObject__RANDOM.seed(0)

# self.objs is a dict, but its insertion order follows set-based graph
# resolution (object identity), so .values() iteration varies per process.
# Two independent traversals key off it; we make both deterministic by walking
# objects in object-id order.
from hvcc.core.hv2ir.HeavyGraph import HeavyGraph


# (3) emit the order-independent sendMessage functions in a stable order.
# C++ does not care about decl/def order, and init order is produced separately.
def _deterministic_control_list(self):
    return [
        x
        for o in sorted(self.objs.values(), key=lambda o: o.id)
        for x in o.get_ir_control_list()
    ]


HeavyGraph.get_ir_control_list = _deterministic_control_list


# (4) the signal-processing schedule walks the graph's leaves in self.objs
# order. Independent signal subtrees may be emitted in either relative order;
# sort the leaves by id so the choice is stable. This only breaks ties between
# data-independent subtrees -- get_parent_order still follows inlet connections,
# so every data dependency (and thus the computed audio) is preserved.
def _deterministic_signal_order(self):
    self.signal_order = []
    leaves = sorted((o for o in self.objs.values() if o.is_leaf()), key=lambda o: o.id)
    for o in leaves:
        self.signal_order.extend(o.get_parent_order())
    self.signal_order = [o for o in self.signal_order if o.does_process_signal]


HeavyGraph.order_signal_objects = _deterministic_signal_order

from hvcc.main import main

sys.exit(main())

#!/usr/bin/env python3
"""Flag control floats wired into the LEFT (signal) inlet of tilde objects.

Heavy (hvcc) silently drops a control connection into the signal inlet of
*some* ~ objects -- per the Heavy docs: "Many objects do not take control
signals on their left inlet. [osc~] for instance always requires the use of
[sig~] before connecting a value." There is no compile warning; the patch just
goes silent / near-DC. [samphold~] is a confirmed-dropping case in this repo
(fixed by inserting [sig~] in sampler-overlap.pd).

This linter parses Pd patches (handling subpatch/canvas nesting so object
indices line up) and reports every connection from a CONTROL source outlet
into inlet 0 of a tilde object. It already excludes the common false positives:
  - local abstractions / subpatches whose outlet is a signal (outlet~)
  - tilde objects whose inlet 0 is message-driven by design
    ([sig~], [line~], [snapshot~] bang, [tabread4~] set, [readsf~], ...)

Remaining hits still need a human verdict: Heavy DOES auto-convert control for
some signal inlets ([lop~]/[*~] via an implicit signal-var, [phasor~]/[osc~]
frequency via a _k message setter), so a hit is not automatically a bug. When
unsure, insert [sig~] before the inlet, or check the generated C++ for an empty
cReceive_*_sendMessage body / a VIf(ZERO) signal input.

Usage:
    python3 tools/heavy_harness/check_control_to_signal_inlet.py PATH.pd [...]
    python3 tools/heavy_harness/check_control_to_signal_inlet.py $(find synth -name '*.pd')
"""
import sys, os, glob
from collections import defaultdict

# Tilde objects whose inlet 0 is message/control-driven BY DESIGN (safe).
MSG_LEFT = {"sig~", "line~", "vline~", "snapshot~", "tabwrite~", "tabplay~",
            "tabread4~", "tabread~", "tabreceive~", "tabsend~", "delwrite~",
            "readsf~", "writesf~", "throw~", "catch~", "send~", "s~",
            "block~", "switch~", "print~"}
# Tilde objects whose outlet 0 is control-rate (so feeding it into a signal
# inlet is itself a control connection).
CONTROL_OUTLET_TILDE = {"snapshot~", "env~", "threshold~", "sigmund~",
                        "fiddle~", "bonk~", "bang~"}


def parse(path):
    """Return list of canvases; each = {objs:[(type,text)], conns:[(s,o,d,i)]}."""
    stack, canvases = [], []
    raw = open(path, encoding="utf-8", errors="replace").read().replace("\r", "")
    lines = []
    for ln in raw.split("\n"):              # merge continuation lines
        if ln.startswith("#") or not lines:
            lines.append(ln)
        else:
            lines[-1] += " " + ln
    for ln in lines:
        ln = ln.strip()
        body = ln[:-1] if ln.endswith(";") else ln
        toks = body.split()
        if len(toks) < 2:
            continue
        if toks[0] == "#N" and toks[1] == "canvas":
            cv = {"objs": [], "conns": []}
            stack.append(cv); canvases.append(cv)
        elif toks[0] == "#X":
            rec = toks[1]
            cur = stack[-1] if stack else None
            if rec == "restore":
                stack.pop()
                if stack:
                    stack[-1]["objs"].append(("pd", body))
            elif rec == "obj":
                cur["objs"].append((toks[4] if len(toks) > 4 else "", body))
            elif rec in ("msg", "floatatom", "symbolatom", "text", "scalar",
                         "listbox", "array"):
                cur["objs"].append((rec, body))
            elif rec == "connect":
                cur["conns"].append(tuple(int(x) for x in toks[2:6]))
    return canvases


def io_types(path):
    """Ordered (left->right) inlet/outlet signal-ness for an abstraction."""
    cvs = parse(path)
    if not cvs:
        return [], []
    ins, outs = [], []
    for typ, body in cvs[0]["objs"]:
        t = body.split()
        if typ in ("inlet", "inlet~"):
            ins.append((int(t[2]), typ == "inlet~"))
        elif typ in ("outlet", "outlet~"):
            outs.append((int(t[2]), typ == "outlet~"))
    ins.sort(); outs.sort()
    return [sig for _, sig in ins], [sig for _, sig in outs]


def main(argv):
    paths = sorted(set(argv))
    # abstraction name -> file, for resolving local abstractions' inlet/outlet types
    search = set(os.path.dirname(p) for p in paths) | {"synth",
                                                        "synth/libs"}
    abstr = {}
    for d in search:
        for p in glob.glob(os.path.join(d, "*.pd")):
            abstr.setdefault(os.path.basename(p)[:-3], p)
    abstr_io = {n: io_types(p) for n, p in abstr.items()}

    def dest_in0_signal(t):
        if t in MSG_LEFT:
            return False
        if t in abstr_io:
            ins = abstr_io[t][0]
            return ins[0] if ins else False
        return t.endswith("~")

    def src_control(t, outlet):
        if t == "pd":
            return False            # subpatch: assume signal (outlet~); rare FN
        if t in abstr_io:
            outs = abstr_io[t][1]
            return (not outs[outlet]) if outlet < len(outs) else False
        if t.endswith("~"):
            return t in CONTROL_OUTLET_TILDE
        return True

    findings = []
    for path in paths:
        for ci, cv in enumerate(parse(path)):
            objs = cv["objs"]
            for (s, o, d, i) in cv["conns"]:
                if s >= len(objs) or d >= len(objs) or i != 0:
                    continue
                dtyp, styp = objs[d][0], objs[s][0]
                if dest_in0_signal(dtyp) and src_control(styp, o):
                    findings.append((path, styp, o, dtyp, objs[s][1][:55]))

    byfile = defaultdict(list)
    for f in findings:
        byfile[f[0]].append(f)
    for path in sorted(byfile):
        print("\n### %s" % path)
        for (_, styp, o, dtyp, stext) in byfile[path]:
            print("  [%s].out%d -> [%s].in0   src: %s"
                  % (styp or "<empty>", o, dtyp, stext))
    print("\n%d control->signal-left-inlet candidate(s). Verify each: Heavy "
          "drops some (e.g. samphold~, osc~) but auto-converts others." % len(findings))
    return 1 if findings else 0


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))

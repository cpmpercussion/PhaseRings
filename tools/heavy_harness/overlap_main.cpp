// Dedicated harness for the [sampler-overlap] abstraction (Puckette's
// overlapped granular sampler, adapted from the Pd manual). Wraps it via
// PhaseRingSynth/sampler_overlap_test.pd, which exposes four clean receivers
// and routes the abstraction's outlet to dac~:
//
//   so_table   (symbol) -> inlet 0  switch tabread4~ to a named table
//   so_chunk   (float)  -> inlet 1  grain/chunk size in ms
//   so_readpt  (float)  -> inlet 2  read point in ms
//   so_cents   (float)  -> inlet 3  transposition in cents
//
// Two tables are filled at startup so both code paths can be exercised:
//   _1002_DEFAULT  the abstraction's own $0_default table (read by default)
//   TESTSAMPLE     a top-level table reached by sending so_table testsample
//
// Usage:
//   overlap_harness [--sr 44100] [--duration-ms 4000] [--script events.txt]
//                   [--out out.wav] [--samples-dir PhaseRingSynth/samples]
//                   [--default-wav bowl.wav] [--table-wav crotale.wav]
//
// NOTE: the abstraction's ms->samples conversion hardcodes *44.1, so it
// assumes a 44100 Hz sample rate. Run at --sr 44100.

#include <cstdint>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include "Heavy_SamplerOverlap.h"
#include "Heavy_SamplerOverlap.hpp"
#include "HvMessage.h"

#include "wav.hpp"

namespace {

constexpr int kBlockSize = 256;

// The abstraction's own table is named "<$0>_default"; hvcc resolved $0 to
// 1002 for the current wrapper patch. If sampler_overlap_test.pd is edited and
// regenerated, $0 may change -- update this constant to the new enum name
// printed by overlap_build.sh (grep "enum Table").
constexpr Heavy_SamplerOverlap::Table kDefaultTable = Heavy_SamplerOverlap::_1002_DEFAULT;
constexpr Heavy_SamplerOverlap::Table kSwitchTable = Heavy_SamplerOverlap::TESTSAMPLE;

struct Event {
    int timeMs;
    enum Kind { Float, Bang, Symbol } kind;
    std::string receiver;
    float value;
    std::string symbol;
};

void printHook(HeavyContextInterface *, const char *name, const char *str,
               const HvMessage *) {
    fprintf(stderr, "  [print %s] %s\n", name ? name : "?", str ? str : "");
}

std::vector<Event> loadScript(const std::string &path) {
    std::vector<Event> evs;
    if (path.empty()) return evs;
    std::ifstream in(path);
    if (!in) {
        fprintf(stderr, "failed to open script %s\n", path.c_str());
        std::exit(1);
    }
    std::string line;
    while (std::getline(in, line)) {
        size_t hash = line.find('#');
        if (hash != std::string::npos) line.resize(hash);
        std::istringstream iss(line);
        Event e;
        std::string kind;
        if (!(iss >> e.timeMs >> kind >> e.receiver)) continue;
        if (kind == "float") {
            e.kind = Event::Float;
            if (!(iss >> e.value)) continue;
        } else if (kind == "bang") {
            e.kind = Event::Bang;
        } else if (kind == "sym" || kind == "symbol") {
            e.kind = Event::Symbol;
            if (!(iss >> e.symbol)) continue;
        } else {
            continue;
        }
        evs.push_back(std::move(e));
    }
    return evs;
}

void fillTable(Heavy_SamplerOverlap *ctx, Heavy_SamplerOverlap::Table table,
               const std::string &dir, const std::string &file, double sr) {
    std::string path = dir + "/" + file;
    wav::ReadResult r = wav::readMonoFloat(path.c_str());
    if (!r.ok) {
        fprintf(stderr, "  WARN: failed to load %s\n", path.c_str());
        return;
    }
    auto pcm = wav::resampleMono(r.samples, r.sourceSampleRate, sr);
    float *dst = ctx->getBufferForTable(table);
    int alloc = ctx->getLengthForTable(table);
    if (!dst) {
        fprintf(stderr, "  WARN: getBufferForTable nil for 0x%X\n", (unsigned)table);
        return;
    }
    size_t toCopy = pcm.size();
    if ((int)toCopy > alloc) toCopy = (size_t)alloc;
    std::memcpy(dst, pcm.data(), toCopy * sizeof(float));
    fprintf(stderr, "  loaded %-16s -> table 0x%X  src=%.0fHz frames=%zu (alloc=%d)\n",
            file.c_str(), (unsigned)table, r.sourceSampleRate, pcm.size(), alloc);
}

void sendEvent(HeavyContextInterface *ctx, const Event &e) {
    hv_uint32_t hash = HeavyContext::getHashForString(e.receiver.c_str());
    switch (e.kind) {
        case Event::Float:
            ctx->sendFloatToReceiver(hash, e.value);
            fprintf(stderr, "  t=%dms  -> %s float %g\n", e.timeMs, e.receiver.c_str(), e.value);
            break;
        case Event::Bang:
            ctx->sendBangToReceiver(hash);
            fprintf(stderr, "  t=%dms  -> %s bang\n", e.timeMs, e.receiver.c_str());
            break;
        case Event::Symbol:
            ctx->sendSymbolToReceiver(hash, e.symbol.c_str());
            fprintf(stderr, "  t=%dms  -> %s sym %s\n", e.timeMs, e.receiver.c_str(), e.symbol.c_str());
            break;
    }
}

}  // namespace

int main(int argc, char **argv) {
    double sr = 44100;
    int durationMs = 4000;
    std::string script, out = "overlap_out.wav";
    std::string samplesDir = "PhaseRingSynth/samples";
    std::string defaultWav = "bowl.wav";
    std::string tableWav = "crotale.wav";

    for (int i = 1; i < argc; ++i) {
        std::string a = argv[i];
        auto next = [&]() -> std::string {
            if (i + 1 >= argc) { fprintf(stderr, "missing value for %s\n", a.c_str()); std::exit(1); }
            return argv[++i];
        };
        if (a == "--sr") sr = std::stod(next());
        else if (a == "--duration-ms") durationMs = std::stoi(next());
        else if (a == "--script") script = next();
        else if (a == "--out") out = next();
        else if (a == "--samples-dir") samplesDir = next();
        else if (a == "--default-wav") defaultWav = next();
        else if (a == "--table-wav") tableWav = next();
        else { fprintf(stderr, "unknown arg: %s\n", a.c_str()); return 1; }
    }

    Heavy_SamplerOverlap ctx(sr);
    ctx.setPrintHook(printHook);

    fprintf(stderr, "loading samples from %s ...\n", samplesDir.c_str());
    fillTable(&ctx, kDefaultTable, samplesDir, defaultWav, sr);
    fillTable(&ctx, kSwitchTable, samplesDir, tableWav, sr);

    auto events = loadScript(script);

    int channels = ctx.getNumOutputChannels();
    int totalFrames = (int)(sr * durationMs / 1000.0);
    totalFrames = (totalFrames / kBlockSize) * kBlockSize;
    fprintf(stderr, "rendering sr=%g ch=%d frames=%d (%.2fs) events=%zu\n",
            sr, channels, totalFrames, totalFrames / sr, events.size());

    std::vector<float> outL(kBlockSize), outR(kBlockSize);
    float *outs[2] = {outL.data(), outR.data()};
    std::vector<float> interleaved((size_t)totalFrames * channels, 0.0f);

    size_t evIdx = 0;
    for (int frame = 0; frame < totalFrames; frame += kBlockSize) {
        double t_ms = 1000.0 * frame / sr;
        while (evIdx < events.size() && events[evIdx].timeMs <= t_ms) {
            sendEvent(&ctx, events[evIdx]);
            ++evIdx;
        }
        ctx.process(nullptr, outs, kBlockSize);
        for (int i = 0; i < kBlockSize; ++i)
            for (int c = 0; c < channels; ++c)
                interleaved[(size_t)(frame + i) * channels + c] = outs[c][i];
    }
    while (evIdx < events.size()) { sendEvent(&ctx, events[evIdx]); ++evIdx; }

    if (!wav::writeFloat32(out.c_str(), interleaved.data(), totalFrames, channels, sr)) {
        fprintf(stderr, "failed to write %s\n", out.c_str());
        return 1;
    }
    fprintf(stderr, "wrote %s (%d frames, %d ch, %g Hz)\n", out.c_str(), totalFrames, channels, sr);
    return 0;
}

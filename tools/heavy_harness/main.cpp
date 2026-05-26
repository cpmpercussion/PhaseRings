// Heavy harness: drives a Heavy context outside the iOS app so we can probe
// patch behavior in isolation (pitch sweeps, sing/no-sing diagnostics, etc.)
// and dump the result as a float32 WAV.
//
// Usage:
//   harness --synth scraper|phase|strings
//           [--sr 48000]
//           [--duration-ms 3000]
//           [--script events.txt]
//           [--out out.wav]
//           [--samples-dir PhaseRingSynth/samples]
//
// Script format (one event per line, time-sorted not required):
//   <time_ms> float <receiver> <value>
//   <time_ms> bang  <receiver>
//   <time_ms> sym   <receiver> <symbol>
//   # comment
//
// `[print]` and `[s]` (send-to-symbol) messages from the patch are dumped to
// stderr with the patch-time of the block in which they fired.

#include <cstdarg>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <memory>
#include <sstream>
#include <string>
#include <vector>

#include "HeavyContext.hpp"
#include "Heavy_CircleStrings.hpp"
#include "Heavy_PhaseRing.hpp"
#include "Heavy_SoundScraper.h"
#include "Heavy_SoundScraper.hpp"
#include "HvMessage.h"

#include "wav.hpp"

namespace {

constexpr int kBlockSize = 256;

struct Event {
    int timeMs;
    enum Kind { Float, Bang, Symbol } kind;
    std::string receiver;
    float value;
    std::string symbol;
};

struct SampleMap {
    Heavy_SoundScraper::Table table;
    const char *file;
};
constexpr SampleMap kSamples[] = {
    {Heavy_SoundScraper::BOWL, "bowl.wav"},
    {Heavy_SoundScraper::GONG, "gong.wav"},
    {Heavy_SoundScraper::CROTALE, "crotale.wav"},
    {Heavy_SoundScraper::ALMGLOCKEN, "almglockenC-441.wav"},
    {Heavy_SoundScraper::MARIMBA, "marimba.wav"},
    {Heavy_SoundScraper::XYLO, "xylo.wav"},
};

// Print hook -- patch [print] messages.
void printHook(HeavyContextInterface *ctx,
               const char *name,
               const char *str,
               const HvMessage *msg) {
    (void)msg;
    fprintf(stderr, "  [print %s] %s\n",
            name ? name : "?",
            str ? str : "");
}

// Send hook -- any [s name] in the patch (excluding non-name [s]).
// Heavy invokes this for `[s name]` *and* for the implicit `__hv_output_*`
// senders, so we filter to the receivers we care about.
void sendHook(HeavyContextInterface *ctx,
              const char *name,
              hv_uint32_t hash,
              const HvMessage *msg) {
    (void)ctx;
    (void)hash;
    if (!name) return;
    // Skip noisy internal senders.
    if (name[0] == '_' && name[1] == '_') return;
    fprintf(stderr, "  [send %s]", name);
    int n = msg_getNumElements(msg);
    for (int i = 0; i < n; ++i) {
        if (msg_isFloat(msg, i)) {
            fprintf(stderr, " %g", msg_getFloat(msg, i));
        } else if (msg_isSymbol(msg, i)) {
            fprintf(stderr, " %s", msg_getSymbol(msg, i));
        } else if (msg_isBang(msg, i)) {
            fprintf(stderr, " bang");
        } else {
            fprintf(stderr, " ?");
        }
    }
    fprintf(stderr, "\n");
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
            fprintf(stderr, "unknown kind: %s\n", kind.c_str());
            continue;
        }
        evs.push_back(std::move(e));
    }
    return evs;
}

void loadSoundScraperSamples(Heavy_SoundScraper *ctx,
                             const std::string &dir,
                             double sr) {
    for (auto &m : kSamples) {
        std::string path = dir + "/" + m.file;
        wav::ReadResult r = wav::readMonoFloat(path.c_str());
        if (!r.ok) {
            fprintf(stderr, "  WARN: failed to load %s\n", path.c_str());
            continue;
        }
        auto pcm = wav::resampleMono(r.samples, r.sourceSampleRate, sr);
        float *dst = ctx->getBufferForTable(m.table);
        int alloc = ctx->getLengthForTable(m.table);
        if (!dst) {
            fprintf(stderr, "  WARN: getBufferForTable nil for 0x%X\n", (unsigned)m.table);
            continue;
        }
        size_t toCopy = pcm.size();
        if ((int)toCopy > alloc) toCopy = (size_t)alloc;
        std::memcpy(dst, pcm.data(), toCopy * sizeof(float));
        fprintf(stderr, "  loaded %-14s src=%-5.0fHz frames=%zu (alloc=%d)\n",
                m.file, r.sourceSampleRate, pcm.size(), alloc);
    }
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
    std::string synth = "scraper";
    double sr = 48000;
    int durationMs = 3000;
    std::string script;
    std::string out = "harness_out.wav";
    std::string samplesDir = "PhaseRingSynth/samples";

    for (int i = 1; i < argc; ++i) {
        std::string a = argv[i];
        auto next = [&]() -> std::string {
            if (i + 1 >= argc) {
                fprintf(stderr, "missing value for %s\n", a.c_str());
                std::exit(1);
            }
            return argv[++i];
        };
        if (a == "--synth") synth = next();
        else if (a == "--sr") sr = std::stod(next());
        else if (a == "--duration-ms") durationMs = std::stoi(next());
        else if (a == "--script") script = next();
        else if (a == "--out") out = next();
        else if (a == "--samples-dir") samplesDir = next();
        else {
            fprintf(stderr, "unknown arg: %s\n", a.c_str());
            return 1;
        }
    }

    std::unique_ptr<HeavyContextInterface> ctx;
    if (synth == "phase") {
        ctx.reset(new Heavy_PhaseRing(sr));
    } else if (synth == "strings") {
        ctx.reset(new Heavy_CircleStrings(sr));
    } else if (synth == "scraper") {
        auto *s = new Heavy_SoundScraper(sr);
        ctx.reset(s);
        fprintf(stderr, "loading scraper samples from %s ...\n", samplesDir.c_str());
        loadSoundScraperSamples(s, samplesDir, sr);
    } else {
        fprintf(stderr, "unknown synth: %s (use phase|strings|scraper)\n", synth.c_str());
        return 1;
    }

    ctx->setPrintHook(printHook);
    ctx->setSendHook(sendHook);

    auto events = loadScript(script);

    int channels = ctx->getNumOutputChannels();
    int totalFrames = (int)(sr * durationMs / 1000.0);
    totalFrames = (totalFrames / kBlockSize) * kBlockSize;

    fprintf(stderr, "rendering synth=%s sr=%g ch=%d frames=%d (%.2fs) events=%zu\n",
            synth.c_str(), sr, channels, totalFrames,
            totalFrames / sr, events.size());

    std::vector<float> outL(kBlockSize), outR(kBlockSize);
    float *outs[2] = {outL.data(), outR.data()};
    std::vector<float> interleaved((size_t)totalFrames * channels, 0.0f);

    size_t evIdx = 0;
    for (int frame = 0; frame < totalFrames; frame += kBlockSize) {
        double t_ms = 1000.0 * frame / sr;
        while (evIdx < events.size() && events[evIdx].timeMs <= t_ms) {
            sendEvent(ctx.get(), events[evIdx]);
            ++evIdx;
        }
        ctx->process(nullptr, outs, kBlockSize);
        for (int i = 0; i < kBlockSize; ++i) {
            for (int c = 0; c < channels; ++c) {
                interleaved[(size_t)(frame + i) * channels + c] = outs[c][i];
            }
        }
    }

    // Fire any remaining events (so their side effects show in logs) even
    // though their audio won't be rendered.
    while (evIdx < events.size()) {
        sendEvent(ctx.get(), events[evIdx]);
        ++evIdx;
    }

    if (!wav::writeFloat32(out.c_str(), interleaved.data(), totalFrames, channels, sr)) {
        fprintf(stderr, "failed to write %s\n", out.c_str());
        return 1;
    }
    fprintf(stderr, "wrote %s (%d frames, %d ch, %g Hz)\n", out.c_str(), totalFrames, channels, sr);
    return 0;
}

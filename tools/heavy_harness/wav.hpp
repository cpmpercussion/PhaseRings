// Minimal WAV I/O for the Heavy harness.
// Reads: 16-bit PCM mono/stereo, any SR. Resamples to target SR via linear interp.
// Writes: 32-bit float PCM, interleaved channels, arbitrary SR.

#pragma once

#include <cstdint>
#include <cstdio>
#include <cstring>
#include <vector>

namespace wav {

struct ReadResult {
    std::vector<float> samples;  // mono float, length == frames
    double sourceSampleRate = 0;
    bool ok = false;
};

// Read a 16-bit PCM WAV (mono or stereo), downmix to mono, return float32 at native SR.
// Caller is responsible for resampling if engine SR differs.
inline ReadResult readMonoFloat(const char *path) {
    ReadResult out;
    FILE *f = fopen(path, "rb");
    if (!f) return out;

    char riff[4]; fread(riff, 1, 4, f);
    if (memcmp(riff, "RIFF", 4) != 0) { fclose(f); return out; }
    fseek(f, 4, SEEK_CUR);  // file size
    char wave[4]; fread(wave, 1, 4, f);
    if (memcmp(wave, "WAVE", 4) != 0) { fclose(f); return out; }

    uint16_t format = 0, channels = 0, bps = 0;
    uint32_t sr = 0;
    uint32_t dataSize = 0;
    long dataPos = -1;
    while (!feof(f)) {
        char id[4];
        uint32_t sz;
        if (fread(id, 1, 4, f) != 4) break;
        if (fread(&sz, 4, 1, f) != 1) break;
        if (memcmp(id, "fmt ", 4) == 0) {
            long after = ftell(f) + sz;
            fread(&format, 2, 1, f);
            fread(&channels, 2, 1, f);
            fread(&sr, 4, 1, f);
            fseek(f, 6, SEEK_CUR);  // byterate + blockalign
            fread(&bps, 2, 1, f);
            fseek(f, after, SEEK_SET);
        } else if (memcmp(id, "data", 4) == 0) {
            dataSize = sz;
            dataPos = ftell(f);
            break;
        } else {
            fseek(f, sz, SEEK_CUR);
        }
    }
    if (dataPos < 0 || format != 1 || bps != 16 || channels == 0) {
        fclose(f);
        return out;
    }

    fseek(f, dataPos, SEEK_SET);
    int frames = dataSize / (2 * channels);
    std::vector<int16_t> raw(frames * channels);
    fread(raw.data(), 2, raw.size(), f);
    fclose(f);

    out.samples.resize(frames);
    const float invScale = 1.0f / 32768.0f;
    for (int i = 0; i < frames; ++i) {
        float sum = 0;
        for (int c = 0; c < channels; ++c) sum += raw[i * channels + c] * invScale;
        out.samples[i] = sum / channels;
    }
    out.sourceSampleRate = sr;
    out.ok = true;
    return out;
}

// Linear-interp resample mono float32 from srcSR to dstSR.
inline std::vector<float> resampleMono(const std::vector<float> &in, double srcSR, double dstSR) {
    if (srcSR == dstSR) return in;
    double ratio = dstSR / srcSR;
    int outFrames = (int)(in.size() * ratio);
    std::vector<float> out(outFrames);
    for (int i = 0; i < outFrames; ++i) {
        double srcIdx = i / ratio;
        int i0 = (int)srcIdx;
        int i1 = i0 + 1 < (int)in.size() ? i0 + 1 : i0;
        float frac = (float)(srcIdx - i0);
        out[i] = in[i0] * (1.0f - frac) + in[i1] * frac;
    }
    return out;
}

// Write interleaved float32 PCM. Channels is e.g. 2 for stereo.
inline bool writeFloat32(const char *path, const float *interleaved, int frames, int channels, double sr) {
    FILE *f = fopen(path, "wb");
    if (!f) return false;
    uint32_t dataSize = (uint32_t)(frames * channels * sizeof(float));
    uint32_t fmtSize = 16;
    uint32_t riffSize = 4 + (8 + fmtSize) + (8 + dataSize);
    uint16_t fmt = 3;  // IEEE float
    uint16_t ch = (uint16_t)channels;
    uint32_t srL = (uint32_t)sr;
    uint16_t bps = 32;
    uint32_t byteRate = srL * ch * (bps / 8);
    uint16_t blockAlign = ch * (bps / 8);

    fwrite("RIFF", 1, 4, f);
    fwrite(&riffSize, 4, 1, f);
    fwrite("WAVE", 1, 4, f);
    fwrite("fmt ", 1, 4, f);
    fwrite(&fmtSize, 4, 1, f);
    fwrite(&fmt, 2, 1, f);
    fwrite(&ch, 2, 1, f);
    fwrite(&srL, 4, 1, f);
    fwrite(&byteRate, 4, 1, f);
    fwrite(&blockAlign, 2, 1, f);
    fwrite(&bps, 2, 1, f);
    fwrite("data", 1, 4, f);
    fwrite(&dataSize, 4, 1, f);
    fwrite(interleaved, sizeof(float), frames * channels, f);
    fclose(f);
    return true;
}

}  // namespace wav

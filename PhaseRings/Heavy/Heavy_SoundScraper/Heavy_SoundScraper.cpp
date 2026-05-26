/**
 * Copyright (c) 2026 Enzien Audio, Ltd.
 * 
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 * 
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions, and the following disclaimer.
 * 
 * 2. Redistributions in binary form must reproduce the phrase "powered by heavy",
 *    the heavy logo, and a hyperlink to https://enzienaudio.com, all in a visible
 *    form.
 * 
 *   2.1 If the Application is distributed in a store system (for example,
 *       the Apple "App Store" or "Google Play"), the phrase "powered by heavy"
 *       shall be included in the app description or the copyright text as well as
 *       the in the app itself. The heavy logo will shall be visible in the app
 *       itself as well.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * 
 */

#include "Heavy_SoundScraper.hpp"

#include <new>

#define Context(_c) static_cast<Heavy_SoundScraper *>(_c)


/*
 * C Functions
 */

extern "C" {
  HV_EXPORT HeavyContextInterface *hv_SoundScraper_new(double sampleRate) {
    // allocate aligned memory
    void *ptr = hv_malloc(sizeof(Heavy_SoundScraper));
    // ensure non-null
    if (!ptr) return nullptr;
    // call constructor
    new(ptr) Heavy_SoundScraper(sampleRate);
    return Context(ptr);
  }

  HV_EXPORT HeavyContextInterface *hv_SoundScraper_new_with_options(double sampleRate,
      int poolKb, int inQueueKb, int outQueueKb) {
    // allocate aligned memory
    void *ptr = hv_malloc(sizeof(Heavy_SoundScraper));
    // ensure non-null
    if (!ptr) return nullptr;
    // call constructor
    new(ptr) Heavy_SoundScraper(sampleRate, poolKb, inQueueKb, outQueueKb);
    return Context(ptr);
  }

  HV_EXPORT void hv_SoundScraper_free(HeavyContextInterface *instance) {
    // call destructor
    Context(instance)->~Heavy_SoundScraper();
    // free memory
    hv_free(instance);
  }
} // extern "C"







/*
 * Class Functions
 */

Heavy_SoundScraper::Heavy_SoundScraper(double sampleRate, int poolKb, int inQueueKb, int outQueueKb)
    : HeavyContext(sampleRate, poolKb, inQueueKb, outQueueKb) {
  numBytes += sRPole_init(&sRPole_dBnyUxXY);
  numBytes += sLine_init(&sLine_wDgMEk6l);
  numBytes += sPhasor_k_init(&sPhasor_8xOJbste, 0.0f, sampleRate);
  numBytes += sDel1_init(&sDel1_afJDwwW5);
  numBytes += sSamphold_init(&sSamphold_9D9qkxX9);
  numBytes += sDel1_init(&sDel1_kFre3RYR);
  numBytes += sSamphold_init(&sSamphold_zK1VMapu);
  numBytes += sTabread_init(&sTabread_bF5EsO64, &hTable_ZUcNjdus, false);
  numBytes += sTabread_init(&sTabread_Nz5yK9h1, &hTable_ZUcNjdus, false);
  numBytes += sDel1_init(&sDel1_1pbz9IhA);
  numBytes += sSamphold_init(&sSamphold_ajdckugh);
  numBytes += sDel1_init(&sDel1_8gIeySxJ);
  numBytes += sSamphold_init(&sSamphold_YbLplgYb);
  numBytes += sTabread_init(&sTabread_LCieUrpa, &hTable_ZUcNjdus, false);
  numBytes += sTabread_init(&sTabread_oVRyjie9, &hTable_ZUcNjdus, false);
  numBytes += sRPole_init(&sRPole_6QHmTwSt);
  numBytes += sDel1_init(&sDel1_QypWBSjn);
  numBytes += sLine_init(&sLine_kPytG5Co);
  numBytes += sSample_init(&sSample_GybwLLos);
  numBytes += sSample_init(&sSample_VSl3MWpb);
  numBytes += sLine_init(&sLine_Sn9TVkmF);
  numBytes += sTabread_init(&sTabread_xBw5RJ3t, &hTable_ZUcNjdus, false);
  numBytes += sTabread_init(&sTabread_mgsZO6Oc, &hTable_ZUcNjdus, false);
  numBytes += sLine_init(&sLine_6mNXXCJ7);
  numBytes += sLine_init(&sLine_eWf6Hcd7);
  numBytes += sLine_init(&sLine_BTi6nfqs);
  numBytes += sLine_init(&sLine_DZJ2zHzL);
  numBytes += sLine_init(&sLine_NcgVXeVL);
  numBytes += sTabread_init(&sTabread_hwNjTqPz, &hTable_ZUcNjdus, false);
  numBytes += sTabread_init(&sTabread_PboqmQLM, &hTable_ZUcNjdus, false);
  numBytes += sLine_init(&sLine_MFD5QceL);
  numBytes += sLine_init(&sLine_GqCKfENF);
  numBytes += sLine_init(&sLine_LH3Dh0ra);
  numBytes += sLine_init(&sLine_7GFtrkKz);
  numBytes += sLine_init(&sLine_msp1Ye3X);
  numBytes += sTabread_init(&sTabread_SFqZFvrg, &hTable_ZUcNjdus, false);
  numBytes += sTabread_init(&sTabread_PElgroJl, &hTable_ZUcNjdus, false);
  numBytes += sLine_init(&sLine_PgJfdgEk);
  numBytes += sLine_init(&sLine_OTTrIrh4);
  numBytes += sLine_init(&sLine_qMIERDg8);
  numBytes += sLine_init(&sLine_FoyksauD);
  numBytes += sLine_init(&sLine_F9IeWvwf);
  numBytes += sTabread_init(&sTabread_ma6MgTzX, &hTable_ZUcNjdus, false);
  numBytes += sTabread_init(&sTabread_TgEMkHGs, &hTable_ZUcNjdus, false);
  numBytes += sLine_init(&sLine_uFCAYdsC);
  numBytes += sLine_init(&sLine_GiixFRac);
  numBytes += sLine_init(&sLine_T6lK4JNJ);
  numBytes += sLine_init(&sLine_MJbLJ0NW);
  numBytes += sLine_init(&sLine_kYf3Wxnv);
  numBytes += sLine_init(&sLine_uqeTqrvX);
  numBytes += sLine_init(&sLine_lwwd2OJE);
  numBytes += sLine_init(&sLine_z8VOYOp9);
  numBytes += sLine_init(&sLine_Nnx4w0Pj);
  numBytes += sTabwrite_init(&sTabwrite_OwXIKauj, &hTable_sMRYwHe2);
  numBytes += sLine_init(&sLine_Pcfne5it);
  numBytes += sPhasor_init(&sPhasor_Q1oGyOk9, sampleRate);
  numBytes += sLine_init(&sLine_blkWxGKA);
  numBytes += sLine_init(&sLine_c0vz6sat);
  numBytes += sTabhead_init(&sTabhead_2CIAiSzb, &hTable_sMRYwHe2);
  numBytes += sTabread_init(&sTabread_6YS6Zas8, &hTable_sMRYwHe2, false);
  numBytes += sTabread_init(&sTabread_uWdc53DZ, &hTable_sMRYwHe2, false);
  numBytes += sTabhead_init(&sTabhead_ZwjePcq4, &hTable_sMRYwHe2);
  numBytes += sTabread_init(&sTabread_jnYLdFyM, &hTable_sMRYwHe2, false);
  numBytes += sTabread_init(&sTabread_kI6fXTcH, &hTable_sMRYwHe2, false);
  numBytes += sTabhead_init(&sTabhead_dLY8yDtT, &hTable_9yO01bfg);
  numBytes += sTabread_init(&sTabread_tOyhtBjq, &hTable_9yO01bfg, false);
  numBytes += sTabread_init(&sTabread_aAWoqMMG, &hTable_9yO01bfg, false);
  numBytes += sRPole_init(&sRPole_qFQZYD1i);
  numBytes += sDel1_init(&sDel1_GlhZDR3P);
  numBytes += sLine_init(&sLine_IaVB52Ee);
  numBytes += sRPole_init(&sRPole_Q0PpMq1N);
  numBytes += sTabwrite_init(&sTabwrite_bKDfZCiT, &hTable_9yO01bfg);
  numBytes += sTabread_init(&sTabread_HVCRVxfI, &hTable_NR1Sx6Hm, true);
  numBytes += sRPole_init(&sRPole_SutmEs0C);
  numBytes += sLine_init(&sLine_VNCvY9SK);
  numBytes += sLine_init(&sLine_8eT4FstA);
  numBytes += sTabread_init(&sTabread_AZxD1A9S, &hTable_eE2EZu5g, true);
  numBytes += sTabread_init(&sTabread_9cGt4C5J, &hTable_YFXVwWdu, true);
  numBytes += sTabread_init(&sTabread_41vYJHEg, &hTable_rYVysgEh, true);
  numBytes += sTabread_init(&sTabread_NrulwpP8, &hTable_CrW75vpS, true);
  numBytes += sTabread_init(&sTabread_aTDR6e40, &hTable_H2qu6ske, true);
  numBytes += sTabwrite_init(&sTabwrite_ryUt1QY8, &hTable_TdUQXZuW);
  numBytes += sTabwrite_init(&sTabwrite_U8Cp5GTq, &hTable_H2qu6ske);
  numBytes += sTabwrite_init(&sTabwrite_0hu6njQb, &hTable_CrW75vpS);
  numBytes += sTabwrite_init(&sTabwrite_xVutPYcz, &hTable_rYVysgEh);
  numBytes += sTabwrite_init(&sTabwrite_ZMXvfo1q, &hTable_YFXVwWdu);
  numBytes += sTabwrite_init(&sTabwrite_lH279H20, &hTable_eE2EZu5g);
  numBytes += sTabread_init(&sTabread_29P1pciG, &hTable_TdUQXZuW, true);
  numBytes += sTabread_init(&sTabread_2hC6Db7E, &hTable_RRX9To4g, true);
  numBytes += sRPole_init(&sRPole_2KREmCB6);
  numBytes += sTabread_init(&sTabread_gQLapaUV, &hTable_xSiPWMdz, true);
  numBytes += sRPole_init(&sRPole_P7X8k6Ta);
  numBytes += sTabread_init(&sTabread_3YatQhob, &hTable_fgnk3ARH, true);
  numBytes += sRPole_init(&sRPole_NN07t0Gf);
  numBytes += sTabwrite_init(&sTabwrite_koAtA5XQ, &hTable_NR1Sx6Hm);
  numBytes += sTabwrite_init(&sTabwrite_BOOP7cdA, &hTable_RRX9To4g);
  numBytes += sTabwrite_init(&sTabwrite_0oIs1K0q, &hTable_xSiPWMdz);
  numBytes += sTabwrite_init(&sTabwrite_E7kC2rzN, &hTable_fgnk3ARH);
  numBytes += sLine_init(&sLine_6roDgJna);
  numBytes += sLine_init(&sLine_R9hVG6i4);
  numBytes += sTabwrite_init(&sTabwrite_Livcz3dG, &hTable_vhIJk1Ey);
  numBytes += sLine_init(&sLine_1fVuvFyw);
  numBytes += sPhasor_init(&sPhasor_5MiEcEx9, sampleRate);
  numBytes += sLine_init(&sLine_GxuX9dDK);
  numBytes += sLine_init(&sLine_lk7epkND);
  numBytes += sTabhead_init(&sTabhead_a84pMSJc, &hTable_vhIJk1Ey);
  numBytes += sTabread_init(&sTabread_piN0qW5X, &hTable_vhIJk1Ey, false);
  numBytes += sTabread_init(&sTabread_x16Bq9xb, &hTable_vhIJk1Ey, false);
  numBytes += sTabhead_init(&sTabhead_2dcgrhkp, &hTable_vhIJk1Ey);
  numBytes += sTabread_init(&sTabread_eOAhoL4N, &hTable_vhIJk1Ey, false);
  numBytes += sTabread_init(&sTabread_nhgnYHLv, &hTable_vhIJk1Ey, false);
  numBytes += sTabhead_init(&sTabhead_xuisShaE, &hTable_6lkVgUXs);
  numBytes += sTabread_init(&sTabread_9PJksFqd, &hTable_6lkVgUXs, false);
  numBytes += sTabread_init(&sTabread_eCfV51s0, &hTable_6lkVgUXs, false);
  numBytes += sRPole_init(&sRPole_yg1cb6Lj);
  numBytes += sDel1_init(&sDel1_vVZE1hF6);
  numBytes += sLine_init(&sLine_4CNE9bol);
  numBytes += sRPole_init(&sRPole_DljXFU6d);
  numBytes += sTabwrite_init(&sTabwrite_fhhUv73T, &hTable_6lkVgUXs);
  numBytes += sCPole_init(&sCPole_tBVRetvl);
  numBytes += sRPole_init(&sRPole_oJkgfbWW);
  numBytes += sRPole_init(&sRPole_LJJLWiXf);
  numBytes += sRPole_init(&sRPole_0IgGcqq3);
  numBytes += sTabread_init(&sTabread_jD5IbQdJ, &hTable_EX2NbWdD, true);
  numBytes += sRPole_init(&sRPole_PjEM5rLI);
  numBytes += sLine_init(&sLine_Z2qmG9sK);
  numBytes += sLine_init(&sLine_jqDt2JHm);
  numBytes += sTabread_init(&sTabread_5iyvOZtU, &hTable_WV7xZOVY, true);
  numBytes += sTabread_init(&sTabread_1mmTSLm7, &hTable_U6dbCP58, true);
  numBytes += sTabread_init(&sTabread_1wURQaYl, &hTable_ah2ngOUs, true);
  numBytes += sTabread_init(&sTabread_xjG6hQnr, &hTable_iUbvzypp, true);
  numBytes += sTabread_init(&sTabread_OVjTHdeX, &hTable_X9Rp52Xj, true);
  numBytes += sTabwrite_init(&sTabwrite_AC7RFqlE, &hTable_agfe5c5k);
  numBytes += sTabwrite_init(&sTabwrite_pt0bpv9P, &hTable_X9Rp52Xj);
  numBytes += sTabwrite_init(&sTabwrite_yHsIgnQe, &hTable_iUbvzypp);
  numBytes += sTabwrite_init(&sTabwrite_qDzEn88v, &hTable_ah2ngOUs);
  numBytes += sTabwrite_init(&sTabwrite_QJKGekIF, &hTable_U6dbCP58);
  numBytes += sTabwrite_init(&sTabwrite_yaFSIK1K, &hTable_WV7xZOVY);
  numBytes += sTabread_init(&sTabread_qqQxRIH1, &hTable_agfe5c5k, true);
  numBytes += sTabread_init(&sTabread_XflJIGJu, &hTable_28ZFj778, true);
  numBytes += sRPole_init(&sRPole_GpAMy306);
  numBytes += sTabread_init(&sTabread_0JWiUFjx, &hTable_lgFvSbvj, true);
  numBytes += sRPole_init(&sRPole_DhZe5W1m);
  numBytes += sTabread_init(&sTabread_je7JarWD, &hTable_sUDRhsRz, true);
  numBytes += sRPole_init(&sRPole_5eFkv67A);
  numBytes += sTabwrite_init(&sTabwrite_68XwZE8t, &hTable_EX2NbWdD);
  numBytes += sTabwrite_init(&sTabwrite_cPJ4FJgN, &hTable_28ZFj778);
  numBytes += sTabwrite_init(&sTabwrite_pLV6Qlb7, &hTable_lgFvSbvj);
  numBytes += sTabwrite_init(&sTabwrite_GHM6ve2y, &hTable_sUDRhsRz);
  numBytes += sLine_init(&sLine_z0zOuuMF);
  numBytes += sLine_init(&sLine_LXXPPTAJ);
  numBytes += sLine_init(&sLine_MZIVMHwM);
  numBytes += cVar_init_s(&cVar_16IO5Mhm, "floatatom");
  numBytes += cVar_init_f(&cVar_vrfKeGqf, 98.0f);
  numBytes += cIf_init(&cIf_i8BID9N6, false);
  numBytes += cBinop_init(&cBinop_oxl5fD4r, 0.0f); // __pow
  numBytes += cPack_init(&cPack_AzwVq8dQ, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_OxJlfBEp, 0.0f);
  numBytes += cRandom_init(&cRandom_Wthc4urx, -800391687);
  numBytes += cSlice_init(&cSlice_mFDQYYnR, 1, 1);
  numBytes += cBinop_init(&cBinop_ulByXTNU, 1.0f); // __pow
  numBytes += cRandom_init(&cRandom_suXWbygU, 566674924);
  numBytes += cSlice_init(&cSlice_uUyHGNsT, 1, 1);
  numBytes += cSlice_init(&cSlice_wNWlnUt6, 1, 1);
  numBytes += cSlice_init(&cSlice_vbIVip9l, 0, 1);
  numBytes += cPack_init(&cPack_NNRvXRiE, 2, 0.0f, 10.0f);
  numBytes += cPack_init(&cPack_gN4U6vTY, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_WGv05G1Y, 0.0f);
  numBytes += cDelay_init(this, &cDelay_bKRFhH0W, 25.0f);
  numBytes += cVar_init_f(&cVar_BWR5CV5M, 0.0f);
  numBytes += sVarf_init(&sVarf_PD4Yfl3A, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_ElZ8w9SJ, "crotale");
  numBytes += cSlice_init(&cSlice_2dhjyFg0, 1, 1);
  numBytes += sVarf_init(&sVarf_JXcwgGbZ, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_frDkIQGI, 0.0f);
  numBytes += cVar_init_f(&cVar_fg8rT0PD, 1.0f);
  numBytes += cIf_init(&cIf_ANzVnbf8, false);
  numBytes += cVar_init_f(&cVar_nMJDjlol, 1.0f);
  numBytes += cVar_init_f(&cVar_BT78dqfH, 0.0f);
  numBytes += cDelay_init(this, &cDelay_nN8z599O, 2.0f);
  numBytes += cPack_init(&cPack_9R0OC239, 2, 0.0f, 0.0f);
  numBytes += cDelay_init(this, &cDelay_uZ6UQQ2c, 0.0f);
  numBytes += cDelay_init(this, &cDelay_V04rFeho, 2.0f);
  numBytes += cPack_init(&cPack_V94TjeUb, 2, 0.0f, 0.0f);
  numBytes += cPack_init(&cPack_pDCY6tUo, 2, 0.0f, 2.0f);
  numBytes += cPack_init(&cPack_nPHqOih6, 2, 0.0f, 2.0f);
  numBytes += cVar_init_f(&cVar_9NVBnswA, 0.0f);
  numBytes += cVar_init_f(&cVar_7pPQB3AE, 1.0f);
  numBytes += cPack_init(&cPack_R4WVTS4e, 2, 0.0f, 0.0f);
  numBytes += cSlice_init(&cSlice_FewOWP42, 1, 1);
  numBytes += cSlice_init(&cSlice_gQOevhEt, 0, 1);
  numBytes += cSlice_init(&cSlice_Tmrdpmmk, 1, 1);
  numBytes += cSlice_init(&cSlice_ORyvwG2L, 0, 1);
  numBytes += cPack_init(&cPack_R9Mb9Q6C, 2, 0.0f, 441000000.0f);
  numBytes += cPack_init(&cPack_F3lFBbY7, 2, 0.0f, -441000000.0f);
  numBytes += cBinop_init(&cBinop_BNqeNXWZ, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_RcMRP1aZ, 2.0f); // __sub
  numBytes += cBinop_init(&cBinop_izmXpH4S, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_e5AjJpPc, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_nP8Tbkw6, 44.1f); // __mul
  numBytes += cSlice_init(&cSlice_sOGnVyGV, 5, 1);
  numBytes += cSlice_init(&cSlice_89Uix1kS, 4, 1);
  numBytes += cSlice_init(&cSlice_IgHAKEXO, 3, 1);
  numBytes += cSlice_init(&cSlice_IbTr7vdw, 2, 1);
  numBytes += cSlice_init(&cSlice_P0lHMemF, 1, 1);
  numBytes += cSlice_init(&cSlice_y9SeDNZ3, 0, 1);
  numBytes += cSlice_init(&cSlice_q913uTQy, 1, 1);
  numBytes += cSlice_init(&cSlice_SNqauEsw, 0, 1);
  numBytes += cPack_init(&cPack_CenH7Iu5, 2, 0.0f, 0.0f);
  numBytes += cVar_init_s(&cVar_3JjI015I, "floatatom");
  numBytes += cSlice_init(&cSlice_YsFyi4wb, 1, 1);
  numBytes += cSlice_init(&cSlice_PjiW2wIC, 0, 1);
  numBytes += cBinop_init(&cBinop_xzRERvmG, 10000.0f); // __mul
  numBytes += cBinop_init(&cBinop_tcY0TnkR, 10000.0f); // __mul
  numBytes += cSlice_init(&cSlice_OpJn6SpZ, 1, 1);
  numBytes += cSlice_init(&cSlice_8FYGSYOx, 0, 1);
  numBytes += cVar_init_f(&cVar_uAmKGXU3, 0.0f);
  numBytes += cVar_init_f(&cVar_keCa5M7B, 1.0f);
  numBytes += cPack_init(&cPack_qE6uJ60d, 3, 0.0f, 0.0f, 0.0f);
  numBytes += cBinop_init(&cBinop_E2SNNb7M, 1.0f); // __mul
  numBytes += cBinop_init(&cBinop_AHEJrPNI, 0.0f); // __div
  numBytes += cRandom_init(&cRandom_QbC9d9sF, 1591780979);
  numBytes += cSlice_init(&cSlice_jL1aemTM, 1, 1);
  numBytes += cBinop_init(&cBinop_MlUgg5hq, 1.0f); // __pow
  numBytes += cRandom_init(&cRandom_xNsxWC1Q, 259067137);
  numBytes += cSlice_init(&cSlice_jW3NkgoX, 1, 1);
  numBytes += cSlice_init(&cSlice_PNo0Dq9R, 1, 1);
  numBytes += cSlice_init(&cSlice_jKNtMYot, 0, 1);
  numBytes += cPack_init(&cPack_wOMA16Om, 2, 0.0f, 10.0f);
  numBytes += cPack_init(&cPack_jy5Fm3e7, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_Y1Jf5hjX, 0.0f);
  numBytes += cDelay_init(this, &cDelay_DMddClrK, 25.0f);
  numBytes += cVar_init_f(&cVar_1TqhJKMh, 0.0f);
  numBytes += sVarf_init(&sVarf_z0ORyX7o, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_6CDrXQCO, "crotale");
  numBytes += cSlice_init(&cSlice_mKwufd6I, 1, 1);
  numBytes += sVarf_init(&sVarf_Nn7V9Hd7, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_rFdNLdNc, 0.0f);
  numBytes += cVar_init_f(&cVar_589Ow6JA, 1.0f);
  numBytes += cIf_init(&cIf_15EWwi9y, false);
  numBytes += cVar_init_f(&cVar_IdoFatIK, 1.0f);
  numBytes += cVar_init_f(&cVar_ur5Ln5zg, 0.0f);
  numBytes += cDelay_init(this, &cDelay_gdJ2NfSa, 2.0f);
  numBytes += cPack_init(&cPack_ta6qkmA5, 2, 0.0f, 0.0f);
  numBytes += cDelay_init(this, &cDelay_bM1ORgnN, 0.0f);
  numBytes += cDelay_init(this, &cDelay_ZOYBwgG7, 2.0f);
  numBytes += cPack_init(&cPack_KaAMU7IT, 2, 0.0f, 0.0f);
  numBytes += cPack_init(&cPack_sPOghNV4, 2, 0.0f, 2.0f);
  numBytes += cPack_init(&cPack_h3QM94QA, 2, 0.0f, 2.0f);
  numBytes += cVar_init_f(&cVar_JX5EUlhL, 0.0f);
  numBytes += cVar_init_f(&cVar_jd2GXLKc, 1.0f);
  numBytes += cPack_init(&cPack_9Oxen0Bc, 2, 0.0f, 0.0f);
  numBytes += cSlice_init(&cSlice_hOu2I4yS, 1, 1);
  numBytes += cSlice_init(&cSlice_N7Ns57ec, 0, 1);
  numBytes += cSlice_init(&cSlice_CaFCmnf6, 1, 1);
  numBytes += cSlice_init(&cSlice_A0Axd9YA, 0, 1);
  numBytes += cPack_init(&cPack_423BdKRO, 2, 0.0f, 441000000.0f);
  numBytes += cPack_init(&cPack_YjvOV4Tn, 2, 0.0f, -441000000.0f);
  numBytes += cBinop_init(&cBinop_Caxp42Nq, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_ysWP8rO3, 2.0f); // __sub
  numBytes += cBinop_init(&cBinop_mzDQcHrD, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_qh5fAEbB, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_R39gb8US, 44.1f); // __mul
  numBytes += cSlice_init(&cSlice_gaAw5WGI, 5, 1);
  numBytes += cSlice_init(&cSlice_V8KTCLuF, 4, 1);
  numBytes += cSlice_init(&cSlice_VSVVtVk8, 3, 1);
  numBytes += cSlice_init(&cSlice_uQ8d03ER, 2, 1);
  numBytes += cSlice_init(&cSlice_1rh66Dec, 1, 1);
  numBytes += cSlice_init(&cSlice_J9Iz24XV, 0, 1);
  numBytes += cSlice_init(&cSlice_loWxhItA, 1, 1);
  numBytes += cSlice_init(&cSlice_cgmFh1Qk, 0, 1);
  numBytes += cPack_init(&cPack_jcWimDQH, 2, 0.0f, 0.0f);
  numBytes += cVar_init_s(&cVar_eVS3JXNs, "floatatom");
  numBytes += cSlice_init(&cSlice_6yYIQnJT, 1, 1);
  numBytes += cSlice_init(&cSlice_s0BjkqeN, 0, 1);
  numBytes += cBinop_init(&cBinop_MNQFgYqQ, 10000.0f); // __mul
  numBytes += cBinop_init(&cBinop_9N2IuUdJ, 10000.0f); // __mul
  numBytes += cSlice_init(&cSlice_XVu6ikGS, 1, 1);
  numBytes += cSlice_init(&cSlice_yxD3gljR, 0, 1);
  numBytes += cVar_init_f(&cVar_EOi2HGD9, 0.0f);
  numBytes += cVar_init_f(&cVar_bwLv7dUn, 1.0f);
  numBytes += cPack_init(&cPack_hHOPTAfo, 3, 0.0f, 0.0f, 0.0f);
  numBytes += cBinop_init(&cBinop_D5wxfPmT, 1.0f); // __mul
  numBytes += cBinop_init(&cBinop_hatdRi6q, 0.0f); // __div
  numBytes += cRandom_init(&cRandom_skGozKfJ, 629625815);
  numBytes += cSlice_init(&cSlice_3pmyhKo4, 1, 1);
  numBytes += cBinop_init(&cBinop_Pcm2RgL2, 1.0f); // __pow
  numBytes += cRandom_init(&cRandom_q9TYbDK2, 1983859176);
  numBytes += cSlice_init(&cSlice_sAt3HrcJ, 1, 1);
  numBytes += cSlice_init(&cSlice_PGQ4Pvv1, 1, 1);
  numBytes += cSlice_init(&cSlice_AcxWZBRR, 0, 1);
  numBytes += cPack_init(&cPack_7oUJxeou, 2, 0.0f, 10.0f);
  numBytes += cPack_init(&cPack_6cQGxbVt, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_ri8Mlkro, 0.0f);
  numBytes += cDelay_init(this, &cDelay_VIeFyLs0, 25.0f);
  numBytes += cVar_init_f(&cVar_01oBirK5, 0.0f);
  numBytes += sVarf_init(&sVarf_zVNmO2Vt, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_bBqSfWKO, "crotale");
  numBytes += cSlice_init(&cSlice_cWfcNRWL, 1, 1);
  numBytes += sVarf_init(&sVarf_Wy3LrshP, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_Jg2pMQjT, 0.0f);
  numBytes += cVar_init_f(&cVar_EUs9TnFw, 1.0f);
  numBytes += cIf_init(&cIf_Kuji9Nec, false);
  numBytes += cVar_init_f(&cVar_5zPInNvG, 1.0f);
  numBytes += cVar_init_f(&cVar_Uib05Tbx, 0.0f);
  numBytes += cDelay_init(this, &cDelay_bzT6UMTk, 2.0f);
  numBytes += cPack_init(&cPack_2LI1XrBL, 2, 0.0f, 0.0f);
  numBytes += cDelay_init(this, &cDelay_hd7gJTKL, 0.0f);
  numBytes += cDelay_init(this, &cDelay_KjddI1gI, 2.0f);
  numBytes += cPack_init(&cPack_tDLqCbb7, 2, 0.0f, 0.0f);
  numBytes += cPack_init(&cPack_saxqacrc, 2, 0.0f, 2.0f);
  numBytes += cPack_init(&cPack_Xc7ntLVj, 2, 0.0f, 2.0f);
  numBytes += cVar_init_f(&cVar_a8j5Q2lF, 0.0f);
  numBytes += cVar_init_f(&cVar_kFdErUcA, 1.0f);
  numBytes += cPack_init(&cPack_e71LtL8n, 2, 0.0f, 0.0f);
  numBytes += cSlice_init(&cSlice_gfM9Wn8z, 1, 1);
  numBytes += cSlice_init(&cSlice_h2HrXCon, 0, 1);
  numBytes += cSlice_init(&cSlice_We5PIwMt, 1, 1);
  numBytes += cSlice_init(&cSlice_ErslUNmy, 0, 1);
  numBytes += cPack_init(&cPack_brY9h3Vd, 2, 0.0f, 441000000.0f);
  numBytes += cPack_init(&cPack_RekycmzL, 2, 0.0f, -441000000.0f);
  numBytes += cBinop_init(&cBinop_SwrbOnAU, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_ZFKHNyoD, 2.0f); // __sub
  numBytes += cBinop_init(&cBinop_M1lRMp2G, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_STcsu9K9, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_01IlQV3w, 44.1f); // __mul
  numBytes += cSlice_init(&cSlice_ApCCvTmv, 5, 1);
  numBytes += cSlice_init(&cSlice_Gecb1JWl, 4, 1);
  numBytes += cSlice_init(&cSlice_qJohb2H1, 3, 1);
  numBytes += cSlice_init(&cSlice_AC2tscxo, 2, 1);
  numBytes += cSlice_init(&cSlice_FOyQBVtx, 1, 1);
  numBytes += cSlice_init(&cSlice_Mh6QYJvP, 0, 1);
  numBytes += cSlice_init(&cSlice_4j5ABp08, 1, 1);
  numBytes += cSlice_init(&cSlice_TZCgvfl0, 0, 1);
  numBytes += cPack_init(&cPack_2SSaZdHB, 2, 0.0f, 0.0f);
  numBytes += cVar_init_s(&cVar_qzZXuj4B, "floatatom");
  numBytes += cSlice_init(&cSlice_xJ1bCm3v, 1, 1);
  numBytes += cSlice_init(&cSlice_ZgHgt0SM, 0, 1);
  numBytes += cBinop_init(&cBinop_zX7PUf0O, 10000.0f); // __mul
  numBytes += cBinop_init(&cBinop_WhLCFLiN, 10000.0f); // __mul
  numBytes += cSlice_init(&cSlice_IurT5bZ5, 1, 1);
  numBytes += cSlice_init(&cSlice_fgHdAuc2, 0, 1);
  numBytes += cVar_init_f(&cVar_lUbzbGRo, 0.0f);
  numBytes += cVar_init_f(&cVar_CrxWVgiL, 1.0f);
  numBytes += cPack_init(&cPack_rYDTbRQU, 3, 0.0f, 0.0f, 0.0f);
  numBytes += cBinop_init(&cBinop_MC3HYsYt, 1.0f); // __mul
  numBytes += cBinop_init(&cBinop_rTqbfmim, 0.0f); // __div
  numBytes += cRandom_init(&cRandom_k6ysHC47, 1966234551);
  numBytes += cSlice_init(&cSlice_6JVmCgFk, 1, 1);
  numBytes += cBinop_init(&cBinop_5wRphlpC, 1.0f); // __pow
  numBytes += cRandom_init(&cRandom_Ph0zdZnV, -948244355);
  numBytes += cSlice_init(&cSlice_dmjYQP45, 1, 1);
  numBytes += cSlice_init(&cSlice_lMwK2PDu, 1, 1);
  numBytes += cSlice_init(&cSlice_qFnkX7kz, 0, 1);
  numBytes += cPack_init(&cPack_yuVyzJT2, 2, 0.0f, 10.0f);
  numBytes += cPack_init(&cPack_iFqNXbf1, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_WufKUwGz, 0.0f);
  numBytes += cDelay_init(this, &cDelay_Nk57QC6V, 25.0f);
  numBytes += cVar_init_f(&cVar_lixryVfh, 0.0f);
  numBytes += sVarf_init(&sVarf_IFUHA6vp, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_nef6V9QF, "crotale");
  numBytes += cSlice_init(&cSlice_KeVHo4Er, 1, 1);
  numBytes += sVarf_init(&sVarf_YRzOT6qX, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_WHqQWP4a, 0.0f);
  numBytes += cVar_init_f(&cVar_CreoyV6G, 1.0f);
  numBytes += cIf_init(&cIf_NeigteuQ, false);
  numBytes += cVar_init_f(&cVar_gDYtbDXY, 1.0f);
  numBytes += cVar_init_f(&cVar_vcqW9VRG, 0.0f);
  numBytes += cDelay_init(this, &cDelay_Lmic2ooA, 2.0f);
  numBytes += cPack_init(&cPack_Cj80grqU, 2, 0.0f, 0.0f);
  numBytes += cDelay_init(this, &cDelay_GUp7YJYT, 0.0f);
  numBytes += cDelay_init(this, &cDelay_z81SmhBk, 2.0f);
  numBytes += cPack_init(&cPack_Axd1f9xo, 2, 0.0f, 0.0f);
  numBytes += cPack_init(&cPack_12k9YW6T, 2, 0.0f, 2.0f);
  numBytes += cPack_init(&cPack_Bdzaz865, 2, 0.0f, 2.0f);
  numBytes += cVar_init_f(&cVar_DIotbER9, 0.0f);
  numBytes += cVar_init_f(&cVar_2ZHP8BLm, 1.0f);
  numBytes += cPack_init(&cPack_ylsFMtrD, 2, 0.0f, 0.0f);
  numBytes += cSlice_init(&cSlice_MaNR8zbS, 1, 1);
  numBytes += cSlice_init(&cSlice_2spbwqzH, 0, 1);
  numBytes += cSlice_init(&cSlice_QHEmzThe, 1, 1);
  numBytes += cSlice_init(&cSlice_K6hoWwlY, 0, 1);
  numBytes += cPack_init(&cPack_RVnqtGla, 2, 0.0f, 441000000.0f);
  numBytes += cPack_init(&cPack_Ssvku24h, 2, 0.0f, -441000000.0f);
  numBytes += cBinop_init(&cBinop_XJgk42Pm, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_k7e4Sxkz, 2.0f); // __sub
  numBytes += cBinop_init(&cBinop_zrQXZfgl, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_X4qcjLwl, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_xeThoO0o, 44.1f); // __mul
  numBytes += cSlice_init(&cSlice_rksI0agz, 5, 1);
  numBytes += cSlice_init(&cSlice_qyKmCgQ8, 4, 1);
  numBytes += cSlice_init(&cSlice_QS4zRMck, 3, 1);
  numBytes += cSlice_init(&cSlice_NC8HPd9e, 2, 1);
  numBytes += cSlice_init(&cSlice_XXXCOwuJ, 1, 1);
  numBytes += cSlice_init(&cSlice_Ul0Jseam, 0, 1);
  numBytes += cSlice_init(&cSlice_DiMOISKG, 1, 1);
  numBytes += cSlice_init(&cSlice_do7zs6km, 0, 1);
  numBytes += cPack_init(&cPack_jZJkPY3i, 2, 0.0f, 0.0f);
  numBytes += cVar_init_s(&cVar_JGFOHNCS, "floatatom");
  numBytes += cSlice_init(&cSlice_El2PdRjP, 1, 1);
  numBytes += cSlice_init(&cSlice_C5k0PNmq, 0, 1);
  numBytes += cBinop_init(&cBinop_GGSlXK5F, 10000.0f); // __mul
  numBytes += cBinop_init(&cBinop_nNU1opL1, 10000.0f); // __mul
  numBytes += cSlice_init(&cSlice_DSbFWVlt, 1, 1);
  numBytes += cSlice_init(&cSlice_QcDTIro3, 0, 1);
  numBytes += cVar_init_f(&cVar_xqkVCOjX, 0.0f);
  numBytes += cVar_init_f(&cVar_tHLO0ADo, 1.0f);
  numBytes += cPack_init(&cPack_Xy9Lv1He, 3, 0.0f, 0.0f, 0.0f);
  numBytes += cBinop_init(&cBinop_Y3WMF4ly, 1.0f); // __mul
  numBytes += cBinop_init(&cBinop_HyY3IW42, 0.0f); // __div
  numBytes += cVar_init_f(&cVar_WJ02Lnq9, 98.0f);
  numBytes += cIf_init(&cIf_xxS5ce62, false);
  numBytes += cBinop_init(&cBinop_M6Qw9pWk, 0.0f); // __pow
  numBytes += cPack_init(&cPack_HPKK7RNe, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_JiB1FTll, 0.0f);
  numBytes += cVar_init_f(&cVar_QfuerMvY, 100.0f);
  numBytes += cIf_init(&cIf_5cJcge5C, false);
  numBytes += cBinop_init(&cBinop_qbZRBZpc, 0.0f); // __pow
  numBytes += cPack_init(&cPack_hq9laY55, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_o0jNTS0T, 0.0f);
  numBytes += cIf_init(&cIf_gkD7BATS, false);
  numBytes += cVar_init_f(&cVar_N3aCVSCL, 97.0f);
  numBytes += cIf_init(&cIf_3D4LYxyk, false);
  numBytes += cBinop_init(&cBinop_JWW8SBEk, 0.0f); // __pow
  numBytes += cPack_init(&cPack_ph6et5U8, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_OuWINYw5, 0.0f);
  numBytes += cVar_init_f(&cVar_BS8eTW7l, 97.0f);
  numBytes += cIf_init(&cIf_rgPQlBGT, false);
  numBytes += cBinop_init(&cBinop_nTUjTO88, 0.0f); // __pow
  numBytes += cPack_init(&cPack_L9vietTl, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_U3nzcL9h, 0.0f);
  numBytes += cPack_init(&cPack_cNc5mneP, 2, 0.0f, 0.0f);
  numBytes += cSlice_init(&cSlice_VAl5RBAS, 1, 1);
  numBytes += cSlice_init(&cSlice_RMP5CxSW, 0, 1);
  numBytes += cIf_init(&cIf_Z3ZtWZf3, false);
  numBytes += cIf_init(&cIf_w8zjnI4v, false);
  numBytes += cIf_init(&cIf_FZKZzRPl, false);
  numBytes += cSlice_init(&cSlice_Wqr6plxg, 1, 1);
  numBytes += cSlice_init(&cSlice_dP0hflEp, 0, 1);
  numBytes += cVar_init_f(&cVar_1yPibb6Q, 0.0f);
  numBytes += cIf_init(&cIf_W3grlikk, false);
  numBytes += cPack_init(&cPack_wSs9s9x5, 2, 0.0f, 0.0f);
  numBytes += cSlice_init(&cSlice_YD2wAdMA, 1, -1);
  numBytes += cSlice_init(&cSlice_yUAaKjXD, 1, -1);
  numBytes += cSlice_init(&cSlice_GlQCzqJr, 1, -1);
  numBytes += cSlice_init(&cSlice_9OsCUMvp, 1, -1);
  numBytes += cIf_init(&cIf_835cs9Dc, false);
  numBytes += cVar_init_f(&cVar_JIviyRuX, 1.0f);
  numBytes += cPack_init(&cPack_0ip4pDLD, 3, 0.0f, 0.0f, 0.0f);
  numBytes += cVar_init_f(&cVar_ISdmdXxz, 0.0f);
  numBytes += cVar_init_f(&cVar_avJg9MHw, 1.0f);
  numBytes += cPack_init(&cPack_B2JZKtpU, 2, 0.0f, 50.0f);
  numBytes += cRandom_init(&cRandom_DQaJqdb9, 1633754913);
  numBytes += cSlice_init(&cSlice_mZOtfodU, 1, 1);
  numBytes += cRandom_init(&cRandom_QThJ7jVy, 411554336);
  numBytes += cSlice_init(&cSlice_v1kpkVmq, 1, 1);
  numBytes += cRandom_init(&cRandom_9wxYnRji, 1615047089);
  numBytes += cSlice_init(&cSlice_1zAZXxp7, 1, 1);
  numBytes += cPack_init(&cPack_XjFGRNor, 4, 0.0f, 0.0f, 0.0f, 0.0f);
  numBytes += cVar_init_s(&cVar_VBavTZpM, "floatatom");
  numBytes += cVar_init_s(&cVar_EZ8VdiIH, "floatatom");
  numBytes += cIf_init(&cIf_NwM2wEAy, false);
  numBytes += cVar_init_s(&cVar_ExEXb4JY, "floatatom");
  numBytes += cBinop_init(&cBinop_miciUGFh, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_dmS6zry0, 72.07f); // __sub
  numBytes += cSlice_init(&cSlice_xxE9lItg, 1, -1);
  numBytes += cSlice_init(&cSlice_X403lTYb, 1, -1);
  numBytes += cBinop_init(&cBinop_K1ho3Iac, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_aUvQubJe, 0.0f); // __div
  numBytes += cSlice_init(&cSlice_BJYPq7Fk, 1, 1);
  numBytes += cSlice_init(&cSlice_Nksac4C4, 0, 1);
  numBytes += cPack_init(&cPack_qS6AWxh7, 2, 0.0f, 0.0f);
  numBytes += cVar_init_f(&cVar_2r1tmWiL, 0.0f);
  numBytes += cVar_init_f(&cVar_xfKLPUcG, 10.0f);
  numBytes += cPack_init(&cPack_JxKp8eJG, 2, 0.0f, 0.0f);
  numBytes += cSlice_init(&cSlice_iu94BBFJ, 1, 1);
  numBytes += cSlice_init(&cSlice_BMPefG1F, 0, 1);
  numBytes += cBinop_init(&cBinop_iGtFsPXS, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_rW0hnDQk, 44.1f); // __mul
  numBytes += cVar_init_f(&cVar_cFrIq1vt, 5.0f);
  numBytes += cBinop_init(&cBinop_623CtA8V, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_K3dgw4Sa, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_FA2TIi6z, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_174WmMc5, 0.0f);
  numBytes += cIf_init(&cIf_mEcpKqON, false);
  numBytes += cSlice_init(&cSlice_g6xTrs7y, 1, 1);
  numBytes += cSlice_init(&cSlice_6ZmhuSSs, 0, 1);
  numBytes += cVar_init_s(&cVar_7o7TgulL, "crotale");
  numBytes += cSlice_init(&cSlice_ZzzpqcSO, 1, 1);
  numBytes += sVarf_init(&sVarf_luAwHcST, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_uBppO2Vj, "crotale");
  numBytes += cSlice_init(&cSlice_4OF1c1oS, 1, 1);
  numBytes += sVarf_init(&sVarf_tZzwfsDn, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_G6r73YyA, 0.0f); // __pow
  numBytes += cBinop_init(&cBinop_BHsy5fn4, 0.0f); // __div
  numBytes += sVarf_init(&sVarf_Z9Nnl08n, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_4IlEGoBW, 5.0f);
  numBytes += cBinop_init(&cBinop_RRClXl33, 0.0f); // __div
  numBytes += sVarf_init(&sVarf_gS5Sasrq, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_2ewha5i3, 50.0f);
  numBytes += cVar_init_s(&cVar_neyIrWpR, "floatatom");
  numBytes += cDelay_init(this, &cDelay_l1fP3848, 350.0f);
  numBytes += cVar_init_s(&cVar_MExqo7ty, "floatatom");
  numBytes += cDelay_init(this, &cDelay_J9oaZi53, 0.0f);
  numBytes += cVar_init_f(&cVar_BiBKnVql, 50.0f);
  numBytes += cBinop_init(&cBinop_JIs4N9u6, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_dTXmA0QR, 1.0f);
  numBytes += cBinop_init(&cBinop_UW96iTWX, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_mRM51ZAW, 220.5f); // __mul
  numBytes += sVarf_init(&sVarf_OVlYzOUE, 0.0f, 0.0f, false);
  numBytes += hTable_init(&hTable_NGxVaLvv, 36000);
  numBytes += hTable_init(&hTable_ZUcNjdus, 290000);
  numBytes += hTable_init(&hTable_SmPFedMc, 288000);
  numBytes += hTable_init(&hTable_loPteidh, 66000);
  numBytes += hTable_init(&hTable_fYwlxwqf, 25000);
  numBytes += hTable_init(&hTable_DmLOFayB, 384000);
  numBytes += cSlice_init(&cSlice_PqnASR9N, 2, 1);
  numBytes += cSlice_init(&cSlice_SpCzCgYF, 1, 1);
  numBytes += cSlice_init(&cSlice_opGBFbz3, 0, 1);
  numBytes += cVar_init_f(&cVar_5mzvLwtF, 0.0f);
  numBytes += cIf_init(&cIf_y0qNP8KP, false);
  numBytes += cIf_init(&cIf_t1Ul5cO3, false);
  numBytes += cIf_init(&cIf_066ZSh0T, false);
  numBytes += cIf_init(&cIf_8Z1m1whM, false);
  numBytes += cIf_init(&cIf_AkdPGvYY, false);
  numBytes += cBinop_init(&cBinop_2Fbr1vCP, 0.0f); // __eq
  numBytes += cRandom_init(&cRandom_8Q9cSHfr, -588335748);
  numBytes += cSlice_init(&cSlice_teoKsPlh, 1, 1);
  numBytes += cRandom_init(&cRandom_97IvFN19, -249735264);
  numBytes += cSlice_init(&cSlice_qrhHQWpn, 1, 1);
  numBytes += cRandom_init(&cRandom_RO54tJR1, 626228917);
  numBytes += cSlice_init(&cSlice_23PFll20, 1, 1);
  numBytes += cVar_init_s(&cVar_Kf0VGfsh, "floatatom");
  numBytes += cPack_init(&cPack_5WRLRdQN, 2, 0.0f, 200.0f);
  numBytes += cPack_init(&cPack_a45tjlCM, 2, 0.0f, 200.0f);
  numBytes += cVar_init_s(&cVar_G1XPK6zO, "floatatom");
  numBytes += cDelay_init(this, &cDelay_AUPUVBHW, 0.0f);
  numBytes += cDelay_init(this, &cDelay_8BIVRQwA, 0.0f);
  numBytes += hTable_init(&hTable_sMRYwHe2, 256);
  numBytes += cVar_init_s(&cVar_SzbcFAbH, "del-1303-del");
  numBytes += sVarf_init(&sVarf_njY9Ofxm, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_LjwTSmA8, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_N0A1Kr2F, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_hpvHlXoL, "del-1303-del");
  numBytes += sVarf_init(&sVarf_FdQ7zxf8, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_0PKrJtLn, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_O1JsRuAR, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_2Q48V8Dc, 0.0f); // __div
  numBytes += cVar_init_s(&cVar_oBhsRn85, "del-1332-del1");
  numBytes += sVarf_init(&sVarf_EZAD5Gze, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_4vQNbW7d, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_Br8Tz02Z, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_xCLrqwCD, 10000.0f);
  numBytes += cBinop_init(&cBinop_BzwmfNYe, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_vhqubXcr, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_pgji7FqZ, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_M9shA97f, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_1xnHjaAd, 10.0f);
  numBytes += cBinop_init(&cBinop_tUGullWe, 0.0f); // __div
  numBytes += sVarf_init(&sVarf_ZMBkLo27, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_udGhWkWj, "floatatom");
  numBytes += sVarf_init(&sVarf_xPvk0wcy, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_zBWwXQ8U, 0.0f);
  numBytes += cDelay_init(this, &cDelay_KgfIui3K, 0.0f);
  numBytes += hTable_init(&hTable_9yO01bfg, 256);
  numBytes += sVarf_init(&sVarf_HfaUnYke, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_9KHtj5MC, "floatatom");
  numBytes += cDelay_init(this, &cDelay_6nDyrfp4, 0.0f);
  numBytes += cVar_init_f(&cVar_aXruJVKo, 20.0f);
  numBytes += cBinop_init(&cBinop_jZHmX1Uq, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_o4VbzjHR, 0.0f);
  numBytes += cSlice_init(&cSlice_PFdOvmcZ, 1, -1);
  numBytes += cSlice_init(&cSlice_JjjlbNMR, 1, -1);
  numBytes += cVar_init_f(&cVar_3RWtlg0z, 0.0f);
  numBytes += cVar_init_f(&cVar_5J9dVY4X, 20.0f);
  numBytes += cVar_init_f(&cVar_aCHYjPwB, 0.0f);
  numBytes += cVar_init_f(&cVar_zlj0xaR5, 0.0f);
  numBytes += cVar_init_f(&cVar_kWPVCn6I, 0.0f);
  numBytes += cSlice_init(&cSlice_f2J5ooHV, 1, 1);
  numBytes += cSlice_init(&cSlice_UW7EP10g, 0, 1);
  numBytes += cBinop_init(&cBinop_nBnh8cYM, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_BhdHEIdg, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_19PhHHHP, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_fFSnciQ6, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_msGSOL38, 20.0f); // __div
  numBytes += cBinop_init(&cBinop_YvoQElAg, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_YL4nbDdX, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_e6l5jBY0, 0.0f); // __sub
  numBytes += cVar_init_s(&cVar_LcoOvPlc, "floatatom");
  numBytes += cPack_init(&cPack_yytqlwcz, 2, 0.0f, 1000.0f);
  numBytes += cDelay_init(this, &cDelay_K4nmsUfn, 0.0f);
  numBytes += cVar_init_f(&cVar_Z7aFCRjz, 20.0f);
  numBytes += cBinop_init(&cBinop_1USANWln, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_STqvoCdQ, 0.0f);
  numBytes += cSlice_init(&cSlice_h0bVWvnz, 1, -1);
  numBytes += cSlice_init(&cSlice_t8a0Q4oK, 1, -1);
  numBytes += cVar_init_f(&cVar_2f5ORazZ, 0.0f);
  numBytes += cVar_init_f(&cVar_9tg7n64e, 20.0f);
  numBytes += cVar_init_f(&cVar_T4OFEPGA, 0.0f);
  numBytes += cVar_init_f(&cVar_QlDcJrpl, 0.0f);
  numBytes += cVar_init_f(&cVar_iqfM5VMu, 0.0f);
  numBytes += cSlice_init(&cSlice_Msftsw0G, 1, 1);
  numBytes += cSlice_init(&cSlice_SVEYS63i, 0, 1);
  numBytes += cBinop_init(&cBinop_Cvm8ZXMI, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_DHoLjx8J, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_VUN6eP1t, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_kC3oWS3I, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_mE81p5ad, 20.0f); // __div
  numBytes += cBinop_init(&cBinop_6ZtwFiIn, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_TSLYVnVf, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_4c0adzPb, 0.0f); // __sub
  numBytes += cPack_init(&cPack_6fBOyrFL, 2, 0.0f, 1000.0f);
  numBytes += cPack_init(&cPack_RTeLKE1d, 2, 0.0f, 1000.0f);
  numBytes += cTabhead_init(&cTabhead_QvY2LiNE, &hTable_NR1Sx6Hm);
  numBytes += cVar_init_s(&cVar_tC4XMKnA, "del-1393-del1");
  numBytes += cDelay_init(this, &cDelay_oAJaFN2e, 58.6435f);
  numBytes += cDelay_init(this, &cDelay_gbMGHkCV, 0.0f);
  numBytes += cBinop_init(&cBinop_oEi5QTal, 58.6435f); // __mul
  numBytes += cBinop_init(&cBinop_dTeYXrDl, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_z6foeIOP, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_60Y6DHJp, 0.0f); // __sub
  numBytes += cTabhead_init(&cTabhead_bhvaQbli, &hTable_RRX9To4g);
  numBytes += cVar_init_s(&cVar_C2sSl45I, "del-1393-del2");
  numBytes += cDelay_init(this, &cDelay_JtdhoKH8, 69.4325f);
  numBytes += cDelay_init(this, &cDelay_Cmw50uta, 0.0f);
  numBytes += cBinop_init(&cBinop_d852eafI, 69.4325f); // __mul
  numBytes += cBinop_init(&cBinop_pSESNx1L, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_7Rp98ZKp, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_hzJtDlwu, 0.0f); // __sub
  numBytes += cTabhead_init(&cTabhead_RUe0Gccm, &hTable_xSiPWMdz);
  numBytes += cVar_init_s(&cVar_WsqgjK17, "del-1393-del3");
  numBytes += cDelay_init(this, &cDelay_RVzz8WDl, 74.5234f);
  numBytes += cDelay_init(this, &cDelay_0EwTKcIM, 0.0f);
  numBytes += cBinop_init(&cBinop_rcS4PaEl, 74.5234f); // __mul
  numBytes += cBinop_init(&cBinop_3Qs4lRF4, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_ulxFy8cF, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_r2Y1O77v, 0.0f); // __sub
  numBytes += cTabhead_init(&cTabhead_5fdu0lwC, &hTable_fgnk3ARH);
  numBytes += cVar_init_s(&cVar_rMzr815S, "del-1393-del4");
  numBytes += cDelay_init(this, &cDelay_QUnvqiZs, 86.1244f);
  numBytes += cDelay_init(this, &cDelay_9RKKk7vP, 0.0f);
  numBytes += cBinop_init(&cBinop_1X4S67RQ, 86.1244f); // __mul
  numBytes += cBinop_init(&cBinop_HU1mWRQM, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_wVQDbl12, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_n4ZN10g3, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_Dz25kfaK, 0.0f);
  numBytes += cDelay_init(this, &cDelay_qfi60WnN, 0.0f);
  numBytes += hTable_init(&hTable_NR1Sx6Hm, 256);
  numBytes += cDelay_init(this, &cDelay_KiIdWzNx, 0.0f);
  numBytes += cDelay_init(this, &cDelay_XM4zDGKL, 0.0f);
  numBytes += hTable_init(&hTable_RRX9To4g, 256);
  numBytes += cDelay_init(this, &cDelay_gHmZVaUV, 0.0f);
  numBytes += cDelay_init(this, &cDelay_33JGHF2k, 0.0f);
  numBytes += hTable_init(&hTable_xSiPWMdz, 256);
  numBytes += cDelay_init(this, &cDelay_N8PZ3q9n, 0.0f);
  numBytes += cDelay_init(this, &cDelay_CDRwGiyD, 0.0f);
  numBytes += hTable_init(&hTable_fgnk3ARH, 256);
  numBytes += cIf_init(&cIf_5sa7txuN, false);
  numBytes += cBinop_init(&cBinop_BVKbHj9d, 0.0f); // __pow
  numBytes += cPack_init(&cPack_DXf6hEff, 2, 0.0f, 30.0f);
  numBytes += cPack_init(&cPack_bSKlwpWY, 2, 0.0f, 50.0f);
  numBytes += cVar_init_f(&cVar_OquQCk2n, 22050.0f);
  numBytes += cBinop_init(&cBinop_pjylq8DL, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_iQtwBMRY, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_l81GUvvI, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_NXkYuOEu, 95.0f);
  numBytes += cVar_init_f(&cVar_1wl9HEjT, 90.0f);
  numBytes += cVar_init_f(&cVar_hCfWcIUY, 6000.0f);
  numBytes += cVar_init_f(&cVar_4MuHOyD3, 60.0f);
  numBytes += cIf_init(&cIf_nBs6UzPX, false);
  numBytes += cTabhead_init(&cTabhead_Po3NiZVj, &hTable_TdUQXZuW);
  numBytes += cVar_init_s(&cVar_jZ8jzNSN, "del-1393-ref6");
  numBytes += cDelay_init(this, &cDelay_N4DK4Z68, 13.645f);
  numBytes += cDelay_init(this, &cDelay_LkvUEk9g, 0.0f);
  numBytes += cBinop_init(&cBinop_XFBmOojv, 13.645f); // __mul
  numBytes += cBinop_init(&cBinop_0TwkBBem, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_eQqf7bo5, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_eZGPsNBt, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_OJcUJA4T, 0.0f);
  numBytes += cDelay_init(this, &cDelay_Ed8h5hj0, 0.0f);
  numBytes += hTable_init(&hTable_TdUQXZuW, 256);
  numBytes += cTabhead_init(&cTabhead_Ouu7jbUj, &hTable_H2qu6ske);
  numBytes += cVar_init_s(&cVar_kRzJ71eU, "del-1393-ref5");
  numBytes += cDelay_init(this, &cDelay_227QwP2x, 16.364f);
  numBytes += cDelay_init(this, &cDelay_jTQDGVu6, 0.0f);
  numBytes += cBinop_init(&cBinop_Eyb4FdC9, 16.364f); // __mul
  numBytes += cBinop_init(&cBinop_41Gn0GK8, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_F6ROEjDe, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_p6hNfJvR, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_DQ1IsHft, 0.0f);
  numBytes += cDelay_init(this, &cDelay_RRNoMS9l, 0.0f);
  numBytes += hTable_init(&hTable_H2qu6ske, 256);
  numBytes += cTabhead_init(&cTabhead_SHUICP2Q, &hTable_CrW75vpS);
  numBytes += cVar_init_s(&cVar_ZegJPXJC, "del-1393-ref4");
  numBytes += cDelay_init(this, &cDelay_p1EPHYCN, 19.392f);
  numBytes += cDelay_init(this, &cDelay_0nZV4qbG, 0.0f);
  numBytes += cBinop_init(&cBinop_R5M612yX, 19.392f); // __mul
  numBytes += cBinop_init(&cBinop_gNWrVKG4, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_Jzs9wolS, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_2GAPHqER, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_eYxs6ToY, 0.0f);
  numBytes += cDelay_init(this, &cDelay_gy6UBCn3, 0.0f);
  numBytes += hTable_init(&hTable_CrW75vpS, 256);
  numBytes += cTabhead_init(&cTabhead_9PnigjGs, &hTable_rYVysgEh);
  numBytes += cVar_init_s(&cVar_mE8kTSAF, "del-1393-ref3");
  numBytes += cDelay_init(this, &cDelay_H1KBfMCU, 25.796f);
  numBytes += cDelay_init(this, &cDelay_Wjoc7elw, 0.0f);
  numBytes += cBinop_init(&cBinop_ervKyagz, 25.796f); // __mul
  numBytes += cBinop_init(&cBinop_PvxAsyH2, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_ETYqLNbB, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_TyqZbmJS, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_aGvCGyAm, 0.0f);
  numBytes += cDelay_init(this, &cDelay_1nkNNzv6, 0.0f);
  numBytes += hTable_init(&hTable_rYVysgEh, 256);
  numBytes += cTabhead_init(&cTabhead_x8bN9o2l, &hTable_YFXVwWdu);
  numBytes += cVar_init_s(&cVar_nJ4e88Oq, "del-1393-ref2");
  numBytes += cDelay_init(this, &cDelay_YYD2LPZr, 43.5337f);
  numBytes += cDelay_init(this, &cDelay_IhSevSaw, 0.0f);
  numBytes += cBinop_init(&cBinop_9HsmoXYB, 43.5337f); // __mul
  numBytes += cBinop_init(&cBinop_2o1pyAEx, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_qLoEc7vZ, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_KrKZw3dV, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_wv7eP3AI, 0.0f);
  numBytes += cDelay_init(this, &cDelay_DOKXEIpu, 0.0f);
  numBytes += hTable_init(&hTable_YFXVwWdu, 256);
  numBytes += cTabhead_init(&cTabhead_Od3PmTyw, &hTable_eE2EZu5g);
  numBytes += cVar_init_s(&cVar_RzLuAeYa, "del-1393-ref1");
  numBytes += cDelay_init(this, &cDelay_crmO2Wg3, 75.2546f);
  numBytes += cDelay_init(this, &cDelay_6WU3jSms, 0.0f);
  numBytes += cBinop_init(&cBinop_ekC05dXV, 75.2546f); // __mul
  numBytes += cBinop_init(&cBinop_7cAzLlIN, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_7Wkh3oJC, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_JFvTAyJR, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_FYBd88Ig, 0.0f);
  numBytes += cDelay_init(this, &cDelay_AoQ1txdb, 0.0f);
  numBytes += hTable_init(&hTable_eE2EZu5g, 256);
  numBytes += cVar_init_f(&cVar_s6CeOL6P, 0.0f);
  numBytes += cVar_init_f(&cVar_i2QSqJs1, 0.0f);
  numBytes += cPack_init(&cPack_My8Rh77t, 2, 0.0f, 50.0f);
  numBytes += cVar_init_f(&cVar_XWPguoBd, 22050.0f);
  numBytes += cBinop_init(&cBinop_MiWCLYyZ, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_QG70fgrH, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_v2f1kXja, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_9xpBajhW, 22050.0f);
  numBytes += cBinop_init(&cBinop_Kcmd7gtN, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_L80vbO3y, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_9MNi9syW, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_jUxYxiCk, 22050.0f);
  numBytes += cBinop_init(&cBinop_WS9KKNeB, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_QPD9tpJ9, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_0elU9Ujj, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_qEtJMY78, 100.0f);
  numBytes += cIf_init(&cIf_GsFOnAIb, false);
  numBytes += cBinop_init(&cBinop_peqiZpeu, 0.0f); // __pow
  numBytes += cPack_init(&cPack_EDR7bHgq, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_68NPTu4r, 0.0f);
  numBytes += cIf_init(&cIf_soOHGFuI, false);
  numBytes += cIf_init(&cIf_WMBlm1uz, false);
  numBytes += cDelay_init(this, &cDelay_ApALkWcM, 50.0f);
  numBytes += cVar_init_f(&cVar_uwSSpmLr, 0.0f);
  numBytes += cVar_init_f(&cVar_OyMLgXc9, 12.0f);
  numBytes += cVar_init_s(&cVar_Igdo8Sxz, "floatatom");
  numBytes += cPack_init(&cPack_xYUyzGCB, 2, 0.0f, 200.0f);
  numBytes += cPack_init(&cPack_rhP1bQMt, 2, 0.0f, 200.0f);
  numBytes += cVar_init_s(&cVar_kMObPYow, "floatatom");
  numBytes += cDelay_init(this, &cDelay_cJ6vGtlD, 0.0f);
  numBytes += cDelay_init(this, &cDelay_BpaUg4vp, 0.0f);
  numBytes += hTable_init(&hTable_vhIJk1Ey, 256);
  numBytes += cVar_init_s(&cVar_CNNYNcNM, "del-1511-del");
  numBytes += sVarf_init(&sVarf_xmhx0KYd, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_Itk7TK5B, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_qXVAzdEr, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_q68DMaA0, "del-1511-del");
  numBytes += sVarf_init(&sVarf_wP98dVQc, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_ESzMXuks, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_dymcxWlX, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_6537XKHt, 0.0f); // __div
  numBytes += cVar_init_f(&cVar_W4WQPcAH, 4720.0f);
  numBytes += cBinop_init(&cBinop_QfTa3oSd, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_AWbLPLRP, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_0UciwyL3, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_48NckNlx, 4720.0f);
  numBytes += cBinop_init(&cBinop_L3d6IZnq, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_Km2MV9xh, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_t1Vuvfnr, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_3O9x0mjC, 4720.0f);
  numBytes += cBinop_init(&cBinop_5yVfg7eR, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_UDdEKmRm, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_ONXlxAYt, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_mWe7l3bg, 1.0f);
  numBytes += cIf_init(&cIf_cZ1Itnha, false);
  numBytes += sVarf_init(&sVarf_QyuLEbsj, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_LTG3pOAi, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_cTf8HQBR, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_Vk7edBvA, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_WCtoU3g6, 4720.0f, 0.0f, false);
  numBytes += cTabhead_init(&cTabhead_0NeWkSQb, &hTable_EX2NbWdD);
  numBytes += cVar_init_s(&cVar_3ZHo8Mi0, "del-1574-del1");
  numBytes += cDelay_init(this, &cDelay_BqwmyDHK, 58.6435f);
  numBytes += cDelay_init(this, &cDelay_o93no4Ac, 0.0f);
  numBytes += cBinop_init(&cBinop_A950JeTv, 58.6435f); // __mul
  numBytes += cBinop_init(&cBinop_TPKF0NRK, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_Wb3T4zRm, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_0SpN1Ruw, 0.0f); // __sub
  numBytes += cTabhead_init(&cTabhead_droFzCYz, &hTable_28ZFj778);
  numBytes += cVar_init_s(&cVar_bCo5eEl9, "del-1574-del2");
  numBytes += cDelay_init(this, &cDelay_EvJkLTEX, 69.4325f);
  numBytes += cDelay_init(this, &cDelay_05ELP2ch, 0.0f);
  numBytes += cBinop_init(&cBinop_bUT9xxBC, 69.4325f); // __mul
  numBytes += cBinop_init(&cBinop_9qE5WHmx, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_rCo5WFRy, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_hH6Rp8uA, 0.0f); // __sub
  numBytes += cTabhead_init(&cTabhead_ezQPKc4W, &hTable_lgFvSbvj);
  numBytes += cVar_init_s(&cVar_Zv79gRqB, "del-1574-del3");
  numBytes += cDelay_init(this, &cDelay_e5M2k9gm, 74.5234f);
  numBytes += cDelay_init(this, &cDelay_VMUtglgy, 0.0f);
  numBytes += cBinop_init(&cBinop_3QQcAhdI, 74.5234f); // __mul
  numBytes += cBinop_init(&cBinop_4qVXwXlv, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_1CanDtsw, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_KFKhAkZ4, 0.0f); // __sub
  numBytes += cTabhead_init(&cTabhead_3s44gkgu, &hTable_sUDRhsRz);
  numBytes += cVar_init_s(&cVar_xzjh7ySP, "del-1574-del4");
  numBytes += cDelay_init(this, &cDelay_wr5mnzke, 86.1244f);
  numBytes += cDelay_init(this, &cDelay_gmNUSCDr, 0.0f);
  numBytes += cBinop_init(&cBinop_SSX9TZbZ, 86.1244f); // __mul
  numBytes += cBinop_init(&cBinop_jDRipueY, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_J2XYXbxC, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_0cXr7Qlj, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_Hl4T8VzR, 0.0f);
  numBytes += cDelay_init(this, &cDelay_laIkAd4B, 0.0f);
  numBytes += hTable_init(&hTable_EX2NbWdD, 256);
  numBytes += cDelay_init(this, &cDelay_2J42PbzH, 0.0f);
  numBytes += cDelay_init(this, &cDelay_hH5WVK8o, 0.0f);
  numBytes += hTable_init(&hTable_28ZFj778, 256);
  numBytes += cDelay_init(this, &cDelay_yWQa6TIv, 0.0f);
  numBytes += cDelay_init(this, &cDelay_UUGUJzQx, 0.0f);
  numBytes += hTable_init(&hTable_lgFvSbvj, 256);
  numBytes += cDelay_init(this, &cDelay_4kN75IcF, 0.0f);
  numBytes += cDelay_init(this, &cDelay_mtVZ7G3N, 0.0f);
  numBytes += hTable_init(&hTable_sUDRhsRz, 256);
  numBytes += cIf_init(&cIf_mJsgeD0d, false);
  numBytes += cBinop_init(&cBinop_bPxFEPQq, 0.0f); // __pow
  numBytes += cPack_init(&cPack_yQeXeUk5, 2, 0.0f, 30.0f);
  numBytes += cPack_init(&cPack_AFdVsdAV, 2, 0.0f, 50.0f);
  numBytes += cVar_init_f(&cVar_3rhRsBRc, 22050.0f);
  numBytes += cBinop_init(&cBinop_dIarltvC, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_wmD7T1pZ, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_bYAW0lRE, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_9iNKqoVA, 100.0f);
  numBytes += cVar_init_f(&cVar_cyxqyKDW, 95.0f);
  numBytes += cVar_init_f(&cVar_lbm63Qtq, 14400.0f);
  numBytes += cVar_init_f(&cVar_pVcev6ol, 60.0f);
  numBytes += cIf_init(&cIf_Km74vsg8, false);
  numBytes += cTabhead_init(&cTabhead_QiOOFcml, &hTable_agfe5c5k);
  numBytes += cVar_init_s(&cVar_pKPtBNOl, "del-1574-ref6");
  numBytes += cDelay_init(this, &cDelay_T5nEDQit, 13.645f);
  numBytes += cDelay_init(this, &cDelay_8cuTCb7w, 0.0f);
  numBytes += cBinop_init(&cBinop_crAnvbSm, 13.645f); // __mul
  numBytes += cBinop_init(&cBinop_pXJQbiLW, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_eS1QCKEM, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_SXSG2UBl, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_LwvXKkgz, 0.0f);
  numBytes += cDelay_init(this, &cDelay_EzUQOb5J, 0.0f);
  numBytes += hTable_init(&hTable_agfe5c5k, 256);
  numBytes += cTabhead_init(&cTabhead_kDXQ7QLM, &hTable_X9Rp52Xj);
  numBytes += cVar_init_s(&cVar_S4EuVlB0, "del-1574-ref5");
  numBytes += cDelay_init(this, &cDelay_ROf0Ysqv, 16.364f);
  numBytes += cDelay_init(this, &cDelay_T4yLfQmJ, 0.0f);
  numBytes += cBinop_init(&cBinop_SgZW07GD, 16.364f); // __mul
  numBytes += cBinop_init(&cBinop_r2L03AIi, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_qUKE8I4L, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_eogrrdow, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_rH9sp1un, 0.0f);
  numBytes += cDelay_init(this, &cDelay_ijjkJaeO, 0.0f);
  numBytes += hTable_init(&hTable_X9Rp52Xj, 256);
  numBytes += cTabhead_init(&cTabhead_ahsqQdLQ, &hTable_iUbvzypp);
  numBytes += cVar_init_s(&cVar_tMXvxuga, "del-1574-ref4");
  numBytes += cDelay_init(this, &cDelay_PGV6AEeA, 19.392f);
  numBytes += cDelay_init(this, &cDelay_LbHjd7xB, 0.0f);
  numBytes += cBinop_init(&cBinop_lHqJ41KC, 19.392f); // __mul
  numBytes += cBinop_init(&cBinop_facGQ0vA, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_eXiONQ5Q, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_dPiKj5gG, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_EDiyZhJX, 0.0f);
  numBytes += cDelay_init(this, &cDelay_CSDkFQk0, 0.0f);
  numBytes += hTable_init(&hTable_iUbvzypp, 256);
  numBytes += cTabhead_init(&cTabhead_pFISdq5z, &hTable_ah2ngOUs);
  numBytes += cVar_init_s(&cVar_WaX5KXjt, "del-1574-ref3");
  numBytes += cDelay_init(this, &cDelay_B7TYCZdh, 25.796f);
  numBytes += cDelay_init(this, &cDelay_QvcgaLA6, 0.0f);
  numBytes += cBinop_init(&cBinop_fOApZV4J, 25.796f); // __mul
  numBytes += cBinop_init(&cBinop_k9Ag6k3n, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_gZjKCL3A, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_CyZqt5ks, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_lYbemdsU, 0.0f);
  numBytes += cDelay_init(this, &cDelay_WVpeQjkw, 0.0f);
  numBytes += hTable_init(&hTable_ah2ngOUs, 256);
  numBytes += cTabhead_init(&cTabhead_WywdLMgD, &hTable_U6dbCP58);
  numBytes += cVar_init_s(&cVar_cNWyJC44, "del-1574-ref2");
  numBytes += cDelay_init(this, &cDelay_Gst1ZEzt, 43.5337f);
  numBytes += cDelay_init(this, &cDelay_D6rnqTnt, 0.0f);
  numBytes += cBinop_init(&cBinop_gJ1aCxzk, 43.5337f); // __mul
  numBytes += cBinop_init(&cBinop_hxKr90jA, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_fCbxwNt1, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_fdOC22Vk, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_yduAxMF5, 0.0f);
  numBytes += cDelay_init(this, &cDelay_KKfSloIp, 0.0f);
  numBytes += hTable_init(&hTable_U6dbCP58, 256);
  numBytes += cTabhead_init(&cTabhead_6N6O1MMN, &hTable_WV7xZOVY);
  numBytes += cVar_init_s(&cVar_esOvarCE, "del-1574-ref1");
  numBytes += cDelay_init(this, &cDelay_JrmpE96l, 75.2546f);
  numBytes += cDelay_init(this, &cDelay_f6VgesCo, 0.0f);
  numBytes += cBinop_init(&cBinop_2cte1FGA, 75.2546f); // __mul
  numBytes += cBinop_init(&cBinop_djpvQCWA, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_eagQneGN, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_mN4dNoDx, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_q619Tmry, 0.0f);
  numBytes += cDelay_init(this, &cDelay_VpNcoCMf, 0.0f);
  numBytes += hTable_init(&hTable_WV7xZOVY, 256);
  numBytes += cVar_init_f(&cVar_lBK10Z6K, 0.0f);
  numBytes += cVar_init_f(&cVar_NzRi3X7d, 0.0f);
  numBytes += cPack_init(&cPack_1ifWPd6t, 2, 0.0f, 50.0f);
  numBytes += cVar_init_f(&cVar_pRFeL14J, 22050.0f);
  numBytes += cBinop_init(&cBinop_O7lvoF2t, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_CCMxd4tc, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_ZvWkDnS5, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_43VYicc7, 22050.0f);
  numBytes += cBinop_init(&cBinop_PhDPKXe2, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_tPyb9atp, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_q13eUdEG, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_0K40rC9K, 22050.0f);
  numBytes += cBinop_init(&cBinop_8BrjMn4k, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_uTVDKciq, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_26IUawB8, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_4qvG46Jq, "del-1673-del1");
  numBytes += sVarf_init(&sVarf_mVJTqDkL, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_Zditxlwn, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_m66pWKob, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_pP01gfXv, 10000.0f);
  numBytes += cBinop_init(&cBinop_30PHl35y, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_ZhS7koEk, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_WPWtNQuY, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_miixX56K, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_Qw8ow7Vi, 10.0f);
  numBytes += cBinop_init(&cBinop_nyaiJEop, 0.0f); // __div
  numBytes += sVarf_init(&sVarf_9y8LJ3DQ, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_5VThGmkt, "floatatom");
  numBytes += sVarf_init(&sVarf_BC4uhilG, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_RO0HAD1w, 0.0f);
  numBytes += cDelay_init(this, &cDelay_CZFi29WS, 0.0f);
  numBytes += hTable_init(&hTable_6lkVgUXs, 256);
  numBytes += sVarf_init(&sVarf_y1NMUgFi, 0.0f, 0.0f, false);
  numBytes += cPack_init(&cPack_pwHA4CK0, 2, 0.0f, 50.0f);
  
  // schedule a message to trigger all loadbangs via the __hv_init receiver
  scheduleMessageForReceiver(0xCE5CC65B, msg_initWithBang(HV_MESSAGE_ON_STACK(1), 0));
}

Heavy_SoundScraper::~Heavy_SoundScraper() {
  cPack_free(&cPack_AzwVq8dQ);
  cPack_free(&cPack_NNRvXRiE);
  cPack_free(&cPack_gN4U6vTY);
  cPack_free(&cPack_9R0OC239);
  cPack_free(&cPack_V94TjeUb);
  cPack_free(&cPack_pDCY6tUo);
  cPack_free(&cPack_nPHqOih6);
  cPack_free(&cPack_R4WVTS4e);
  cPack_free(&cPack_R9Mb9Q6C);
  cPack_free(&cPack_F3lFBbY7);
  cPack_free(&cPack_CenH7Iu5);
  cPack_free(&cPack_qE6uJ60d);
  cPack_free(&cPack_wOMA16Om);
  cPack_free(&cPack_jy5Fm3e7);
  cPack_free(&cPack_ta6qkmA5);
  cPack_free(&cPack_KaAMU7IT);
  cPack_free(&cPack_sPOghNV4);
  cPack_free(&cPack_h3QM94QA);
  cPack_free(&cPack_9Oxen0Bc);
  cPack_free(&cPack_423BdKRO);
  cPack_free(&cPack_YjvOV4Tn);
  cPack_free(&cPack_jcWimDQH);
  cPack_free(&cPack_hHOPTAfo);
  cPack_free(&cPack_7oUJxeou);
  cPack_free(&cPack_6cQGxbVt);
  cPack_free(&cPack_2LI1XrBL);
  cPack_free(&cPack_tDLqCbb7);
  cPack_free(&cPack_saxqacrc);
  cPack_free(&cPack_Xc7ntLVj);
  cPack_free(&cPack_e71LtL8n);
  cPack_free(&cPack_brY9h3Vd);
  cPack_free(&cPack_RekycmzL);
  cPack_free(&cPack_2SSaZdHB);
  cPack_free(&cPack_rYDTbRQU);
  cPack_free(&cPack_yuVyzJT2);
  cPack_free(&cPack_iFqNXbf1);
  cPack_free(&cPack_Cj80grqU);
  cPack_free(&cPack_Axd1f9xo);
  cPack_free(&cPack_12k9YW6T);
  cPack_free(&cPack_Bdzaz865);
  cPack_free(&cPack_ylsFMtrD);
  cPack_free(&cPack_RVnqtGla);
  cPack_free(&cPack_Ssvku24h);
  cPack_free(&cPack_jZJkPY3i);
  cPack_free(&cPack_Xy9Lv1He);
  cPack_free(&cPack_HPKK7RNe);
  cPack_free(&cPack_hq9laY55);
  cPack_free(&cPack_ph6et5U8);
  cPack_free(&cPack_L9vietTl);
  cPack_free(&cPack_cNc5mneP);
  cPack_free(&cPack_wSs9s9x5);
  cPack_free(&cPack_0ip4pDLD);
  cPack_free(&cPack_B2JZKtpU);
  cPack_free(&cPack_XjFGRNor);
  cPack_free(&cPack_qS6AWxh7);
  cPack_free(&cPack_JxKp8eJG);
  hTable_free(&hTable_NGxVaLvv);
  hTable_free(&hTable_ZUcNjdus);
  hTable_free(&hTable_SmPFedMc);
  hTable_free(&hTable_loPteidh);
  hTable_free(&hTable_fYwlxwqf);
  hTable_free(&hTable_DmLOFayB);
  cPack_free(&cPack_5WRLRdQN);
  cPack_free(&cPack_a45tjlCM);
  hTable_free(&hTable_sMRYwHe2);
  hTable_free(&hTable_9yO01bfg);
  cPack_free(&cPack_yytqlwcz);
  cPack_free(&cPack_6fBOyrFL);
  cPack_free(&cPack_RTeLKE1d);
  hTable_free(&hTable_NR1Sx6Hm);
  hTable_free(&hTable_RRX9To4g);
  hTable_free(&hTable_xSiPWMdz);
  hTable_free(&hTable_fgnk3ARH);
  cPack_free(&cPack_DXf6hEff);
  cPack_free(&cPack_bSKlwpWY);
  hTable_free(&hTable_TdUQXZuW);
  hTable_free(&hTable_H2qu6ske);
  hTable_free(&hTable_CrW75vpS);
  hTable_free(&hTable_rYVysgEh);
  hTable_free(&hTable_YFXVwWdu);
  hTable_free(&hTable_eE2EZu5g);
  cPack_free(&cPack_My8Rh77t);
  cPack_free(&cPack_EDR7bHgq);
  cPack_free(&cPack_xYUyzGCB);
  cPack_free(&cPack_rhP1bQMt);
  hTable_free(&hTable_vhIJk1Ey);
  hTable_free(&hTable_EX2NbWdD);
  hTable_free(&hTable_28ZFj778);
  hTable_free(&hTable_lgFvSbvj);
  hTable_free(&hTable_sUDRhsRz);
  cPack_free(&cPack_yQeXeUk5);
  cPack_free(&cPack_AFdVsdAV);
  hTable_free(&hTable_agfe5c5k);
  hTable_free(&hTable_X9Rp52Xj);
  hTable_free(&hTable_iUbvzypp);
  hTable_free(&hTable_ah2ngOUs);
  hTable_free(&hTable_U6dbCP58);
  hTable_free(&hTable_WV7xZOVY);
  cPack_free(&cPack_1ifWPd6t);
  hTable_free(&hTable_6lkVgUXs);
  cPack_free(&cPack_pwHA4CK0);
}

HvTable *Heavy_SoundScraper::getTableForHash(hv_uint32_t tableHash) {switch (tableHash) {
    case 0x9BCAD111: return &hTable_NGxVaLvv; // bowl
    case 0x782CD90: return &hTable_ZUcNjdus; // crotale
    case 0x53C964B5: return &hTable_SmPFedMc; // gong
    case 0xAC13AE99: return &hTable_loPteidh; // marimba
    case 0x1FD931DF: return &hTable_fYwlxwqf; // xylo
    case 0x6F52CA74: return &hTable_DmLOFayB; // almglocken
    case 0x9E6ABCE4: return &hTable_sMRYwHe2; // del-1303-del
    case 0xABEED8EA: return &hTable_9yO01bfg; // del-1332-del1
    case 0xE5CC8D79: return &hTable_NR1Sx6Hm; // del-1393-del1
    case 0xAD26471C: return &hTable_RRX9To4g; // del-1393-del2
    case 0x104708F2: return &hTable_xSiPWMdz; // del-1393-del3
    case 0xC7EE6CBE: return &hTable_fgnk3ARH; // del-1393-del4
    case 0xC8F8DD70: return &hTable_TdUQXZuW; // del-1393-ref6
    case 0x5FF6250C: return &hTable_H2qu6ske; // del-1393-ref5
    case 0x8E145DAF: return &hTable_CrW75vpS; // del-1393-ref4
    case 0x2F596D8F: return &hTable_rYVysgEh; // del-1393-ref3
    case 0xEAEB1929: return &hTable_YFXVwWdu; // del-1393-ref2
    case 0x87D1D38B: return &hTable_eE2EZu5g; // del-1393-ref1
    case 0x628570F1: return &hTable_vhIJk1Ey; // del-1511-del
    case 0xF231816E: return &hTable_EX2NbWdD; // del-1574-del1
    case 0xEC1E4DCF: return &hTable_28ZFj778; // del-1574-del2
    case 0x86A7D3EC: return &hTable_lgFvSbvj; // del-1574-del3
    case 0xD660D38B: return &hTable_sUDRhsRz; // del-1574-del4
    case 0xADA0AAB5: return &hTable_agfe5c5k; // del-1574-ref6
    case 0x26FB64C9: return &hTable_X9Rp52Xj; // del-1574-ref5
    case 0x5D519D31: return &hTable_iUbvzypp; // del-1574-ref4
    case 0xBE751912: return &hTable_ah2ngOUs; // del-1574-ref3
    case 0x2ACF1BA5: return &hTable_U6dbCP58; // del-1574-ref2
    case 0x7F9AA596: return &hTable_WV7xZOVY; // del-1574-ref1
    case 0x9CECC699: return &hTable_6lkVgUXs; // del-1673-del1
    default: return nullptr;
  }
}

void Heavy_SoundScraper::scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) {
  switch (receiverHash) {
    case 0x676151E5: { // 1005-levelin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_8DrY27zU_sendMessage);
      break;
    }
    case 0x4518BA34: { // 1005-levelout
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_etBTPXps_sendMessage);
      break;
    }
    case 0x6F9FBEC2: { // 1013-attack
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_qx8avAm4_sendMessage);
      break;
    }
    case 0xF2645EF2: { // 1013-cutoff
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_0OX4nuXD_sendMessage);
      break;
    }
    case 0x2DB48039: { // 1013-fade-in
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_YcEnJgFp_sendMessage);
      break;
    }
    case 0x62D46891: { // 1013-fade-out
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_DyIEfgWu_sendMessage);
      break;
    }
    case 0x349D3D62: { // 1013-phase
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_L6M6ma00_sendMessage);
      break;
    }
    case 0x6AE0114A: { // 1013-rel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_2e6PYhdn_sendMessage);
      break;
    }
    case 0xCB92FB18: { // 1013-release
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_THR8gmeI_sendMessage);
      break;
    }
    case 0x57A7FD72: { // 1013-sr
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_g1ubUxkO_sendMessage);
      break;
    }
    case 0x4E70A642: { // 1013-stop
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_VZTDMNsR_sendMessage);
      break;
    }
    case 0x14D190E8: { // 1013-tableFreq
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_DzVcW1fk_sendMessage);
      break;
    }
    case 0xC268AA1B: { // 1013-tableName
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_VwClcVqs_sendMessage);
      break;
    }
    case 0xE7AF8038: { // 1013-velocity
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_cKALy0NQ_sendMessage);
      break;
    }
    case 0x64DCFC2F: { // 1013-vol
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_IFUpBw1c_sendMessage);
      break;
    }
    case 0x50D5F76A: { // 1049-attack
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_clBs53qK_sendMessage);
      break;
    }
    case 0xF3BF4624: { // 1049-cutoff
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_WSXk0mmC_sendMessage);
      break;
    }
    case 0xCFE3E7FB: { // 1049-fade-in
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_iTu3jDc3_sendMessage);
      break;
    }
    case 0xF1B8B621: { // 1049-fade-out
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_cJVsE5lQ_sendMessage);
      break;
    }
    case 0x525CAC1A: { // 1049-phase
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_DkrCXPjl_sendMessage);
      break;
    }
    case 0xA87A2151: { // 1049-rel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_Ny20W2gi_sendMessage);
      break;
    }
    case 0x55029BFC: { // 1049-release
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_4xL6NZkO_sendMessage);
      break;
    }
    case 0xBE690FC3: { // 1049-sr
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_o0z1zy04_sendMessage);
      break;
    }
    case 0xE6BC7AD3: { // 1049-stop
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_w13qlHox_sendMessage);
      break;
    }
    case 0x69F33369: { // 1049-tableFreq
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_bQmnjCmK_sendMessage);
      break;
    }
    case 0x5BCC58C7: { // 1049-tableName
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_sy7lEKy8_sendMessage);
      break;
    }
    case 0x6FC5959F: { // 1049-velocity
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_e7iVXB92_sendMessage);
      break;
    }
    case 0x2B9DF2E0: { // 1049-vol
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_t6QY9Ufm_sendMessage);
      break;
    }
    case 0xE673386D: { // 1085-attack
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_oeSsjeA8_sendMessage);
      break;
    }
    case 0xCCCAA185: { // 1085-cutoff
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_1QZjeYxp_sendMessage);
      break;
    }
    case 0xBE83E2EA: { // 1085-fade-in
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_E5r1whBf_sendMessage);
      break;
    }
    case 0x5F2BBD8F: { // 1085-fade-out
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_1B2ZmZT2_sendMessage);
      break;
    }
    case 0x43D27577: { // 1085-phase
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_mc6V2H4k_sendMessage);
      break;
    }
    case 0x87E8930F: { // 1085-rel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_lxIjFjfC_sendMessage);
      break;
    }
    case 0x3003429A: { // 1085-release
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_ZxjvOMhA_sendMessage);
      break;
    }
    case 0x87C3D901: { // 1085-sr
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_5G6xqCtZ_sendMessage);
      break;
    }
    case 0x1F62B01B: { // 1085-stop
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_0ScNl2kt_sendMessage);
      break;
    }
    case 0x60A106AB: { // 1085-tableFreq
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_BGcziFMq_sendMessage);
      break;
    }
    case 0xED68D23A: { // 1085-tableName
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_riILnXBB_sendMessage);
      break;
    }
    case 0xC109014F: { // 1085-velocity
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_WFssAnEw_sendMessage);
      break;
    }
    case 0x688A0E3D: { // 1085-vol
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_cONpp1hQ_sendMessage);
      break;
    }
    case 0xCE21EA29: { // 1121-attack
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_e35GHAhy_sendMessage);
      break;
    }
    case 0xD98D9624: { // 1121-cutoff
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_awHHteN2_sendMessage);
      break;
    }
    case 0xB3F51013: { // 1121-fade-in
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_E1SWCp1C_sendMessage);
      break;
    }
    case 0xB3F35933: { // 1121-fade-out
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_X1vh0qHw_sendMessage);
      break;
    }
    case 0x400EFFA6: { // 1121-phase
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_N2sXvvqu_sendMessage);
      break;
    }
    case 0xFC727EE1: { // 1121-rel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_kI7qPxx1_sendMessage);
      break;
    }
    case 0xD259DE3: { // 1121-release
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_FOz3tbya_sendMessage);
      break;
    }
    case 0x337F255C: { // 1121-sr
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_lhW2cGxb_sendMessage);
      break;
    }
    case 0x86D3C00C: { // 1121-stop
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_Gq0yrwEQ_sendMessage);
      break;
    }
    case 0x45D3BE8E: { // 1121-tableFreq
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_TdP6j73A_sendMessage);
      break;
    }
    case 0xD67DE73F: { // 1121-tableName
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_WlnyW5Fy_sendMessage);
      break;
    }
    case 0x57DA7AEC: { // 1121-velocity
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_3GKJBOeE_sendMessage);
      break;
    }
    case 0x34F8F5A3: { // 1121-vol
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_8q0BecEz_sendMessage);
      break;
    }
    case 0xAB370A60: { // 1157-levelin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_qpf2y1H8_sendMessage);
      break;
    }
    case 0x774A69D5: { // 1157-levelout
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_mxugVG4b_sendMessage);
      break;
    }
    case 0x1345C8C4: { // 1165-levelin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_Tua8aZM9_sendMessage);
      break;
    }
    case 0x352D518B: { // 1165-levelout
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_cZvy4ruV_sendMessage);
      break;
    }
    case 0x82209D15: { // 1175-levelin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_eoZuUIQ9_sendMessage);
      break;
    }
    case 0x4925B226: { // 1175-levelout
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_WSwPhInE_sendMessage);
      break;
    }
    case 0x7FA13EC5: { // 1183-levelin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_ddqkBFuQ_sendMessage);
      break;
    }
    case 0xD9AC1997: { // 1183-levelout
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_JqOZht76_sendMessage);
      break;
    }
    case 0x1DAFCB8F: { // 1203-bend
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_NwIyOnyO_sendMessage);
      break;
    }
    case 0xC2C6F92F: { // 1203-chunk-size
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_9STUb7Kr_sendMessage);
      break;
    }
    case 0x37E438D0: { // 1203-chunk-size-samples
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_LC0dknMg_sendMessage);
      break;
    }
    case 0x992BA3AE: { // 1203-chunk-size-sec
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_nUWs5YwR_sendMessage);
      break;
    }
    case 0x8361FA9F: { // 1203-dur
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_EjgEjYvl_sendMessage);
      break;
    }
    case 0x148BDD57: { // 1203-level
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_bt4qx8Gw_sendMessage);
      break;
    }
    case 0x382F5CA0: { // 1203-loopstart
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_lT5oD7Bt_sendMessage);
      break;
    }
    case 0x831ECB71: { // 1203-pitch
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_FWuAtFNd_sendMessage);
      break;
    }
    case 0x9B39FE5C: { // 1203-reset
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_0L6LdJYF_sendMessage);
      break;
    }
    case 0xC0081691: { // 1203-sample
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_B8BtruqY_sendMessage);
      break;
    }
    case 0xD734BA5A: { // 1203-sample-pitch
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_lUjd3Nar_sendMessage);
      break;
    }
    case 0x3BD3BAC8: { // 1203-sr
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_7RUsYlr2_sendMessage);
      break;
    }
    case 0x8E2277A1: { // 1203-start
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_ncNJGndH_sendMessage);
      break;
    }
    case 0xB8FDBD6B: { // 1203-stop
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_9VX7qlqA_sendMessage);
      break;
    }
    case 0x82F39390: { // 1203-table
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_8kzssOge_sendMessage);
      break;
    }
    case 0xD62F9293: { // 1203-transposition
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_d50G3Uhc_sendMessage);
      break;
    }
    case 0xDD4ECC54: { // 1203-vline
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_6bxAHBNN_sendMessage);
      break;
    }
    case 0xE7F5AE4C: { // 1492-levelin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_8vApesEO_sendMessage);
      break;
    }
    case 0x69552749: { // 1492-levelout
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_OiRrXBoZ_sendMessage);
      break;
    }
    case 0xCE5CC65B: { // __hv_init
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_gCsEyfTf_sendMessage);
      break;
    }
    case 0x67E37CA3: { // __hv_notein
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_vZqDTXhI_sendMessage);
      break;
    }
    case 0x40AA4AF1: { // changesound
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_bZk1Nd4p_sendMessage);
      break;
    }
    case 0xA41806F7: { // distortlevel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_wJPVNgp2_sendMessage);
      break;
    }
    case 0xFCD12E4C: { // mastervolume
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_7wiZ7dLr_sendMessage);
      break;
    }
    case 0xEF5F3308: { // panTranslation
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_yYG5GQKK_sendMessage);
      break;
    }
    case 0x8B2148DD: { // pitch
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_raXZ1cVU_sendMessage);
      break;
    }
    case 0x4409C659: { // processeffects
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_jrw4fox1_sendMessage);
      break;
    }
    case 0x7B795C5A: { // resetsing
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_NBOMRz6a_sendMessage);
      break;
    }
    case 0xA987B741: { // reverbvolume
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_djqFP2O8_sendMessage);
      break;
    }
    case 0x7FFAC478: { // sampleNameFreq
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_3hh6qDY3_sendMessage);
      break;
    }
    case 0x62D6FDDE: { // selectsound
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_Y9s9lBtb_sendMessage);
      break;
    }
    case 0x7AAE6786: { // sinPanAngle
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_VDv4sxci_sendMessage);
      break;
    }
    case 0x6731B2E0: { // sing
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_X5Rl7do8_sendMessage);
      break;
    }
    case 0x57292445: { // singlevel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_ZOVkv1UA_sendMessage);
      break;
    }
    case 0xC7DE3B07: { // singpitch
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_IO7AyTIn_sendMessage);
      break;
    }
    case 0x853B1BE7: { // velocity
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_xr3hShfa_sendMessage);
      break;
    }
    default: return;
  }
}

int Heavy_SoundScraper::getParameterInfo(int index, HvParameterInfo *info) {
  if (info != nullptr) {
    switch (index) {
      default: {
        info->name = "invalid parameter index";
        info->hash = 0;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 0.0f;
        info->defaultVal = 0.0f;
        break;
      }
    }
  }
  return 0;
}



/*
 * Send Function Implementations
 */


void Heavy_SoundScraper::cVar_16IO5Mhm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cVar_vrfKeGqf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_hSBxLEYO_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_maWUakGy_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_eCksQGuZ_sendMessage);
}

void Heavy_SoundScraper::cIf_i8BID9N6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_Dw9BDTCr_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_ocwzgEpa_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cMsg_1cAXcq7V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_oxl5fD4r, HV_BINOP_POW, 0, m, &cBinop_oxl5fD4r_sendMessage);
}

void Heavy_SoundScraper::cBinop_oxl5fD4r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_AzwVq8dQ, 0, m, &cPack_AzwVq8dQ_sendMessage);
}

void Heavy_SoundScraper::cBinop_Dj679Elf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_eqaLST74_sendMessage);
}

void Heavy_SoundScraper::cCast_eCksQGuZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_i8BID9N6, 0, m, &cIf_i8BID9N6_sendMessage);
}

void Heavy_SoundScraper::cCast_maWUakGy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_VL67Lx6V_sendMessage);
}

void Heavy_SoundScraper::cBinop_VL67Lx6V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_i8BID9N6, 1, m, &cIf_i8BID9N6_sendMessage);
}

void Heavy_SoundScraper::cBinop_ocwzgEpa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_Dj679Elf_sendMessage);
}

void Heavy_SoundScraper::cMsg_Dw9BDTCr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_AzwVq8dQ, 0, m, &cPack_AzwVq8dQ_sendMessage);
}

void Heavy_SoundScraper::cBinop_eqaLST74_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_oxl5fD4r, HV_BINOP_POW, 1, m, &cBinop_oxl5fD4r_sendMessage);
  cMsg_1cAXcq7V_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_AzwVq8dQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_lwwd2OJE, 0, m, NULL);
}

void Heavy_SoundScraper::cVar_OxJlfBEp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_i14IeC7J_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_hSBxLEYO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSend_gCWSGd7h_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_gCWSGd7h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_8DrY27zU_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_i14IeC7J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_etBTPXps_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_j6cL7sPq_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_mFDQYYnR, 0, m, &cSlice_mFDQYYnR_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_Wthc4urx, 0, m, &cRandom_Wthc4urx_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_aeq5df9b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_pyCSxAJW_sendMessage);
}

void Heavy_SoundScraper::cUnop_pyCSxAJW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_w9b3CYcq_sendMessage);
}

void Heavy_SoundScraper::cRandom_Wthc4urx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_aeq5df9b_sendMessage);
}

void Heavy_SoundScraper::cSlice_mFDQYYnR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_Wthc4urx, 1, m, &cRandom_Wthc4urx_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_uSqk68ID_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_AHEJrPNI, HV_BINOP_DIVIDE, 0, m, &cBinop_AHEJrPNI_sendMessage);
}

void Heavy_SoundScraper::cBinop_hbO7bOzI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_lKb7gd5p_sendMessage);
}

void Heavy_SoundScraper::cBinop_lKb7gd5p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ulByXTNU, HV_BINOP_POW, 1, m, &cBinop_ulByXTNU_sendMessage);
  cMsg_kMzzLmAB_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_ulByXTNU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_uSqk68ID_sendMessage);
}

void Heavy_SoundScraper::cMsg_kMzzLmAB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_ulByXTNU, HV_BINOP_POW, 0, m, &cBinop_ulByXTNU_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_jVqQrccF_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_uUyHGNsT, 0, m, &cSlice_uUyHGNsT_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_suXWbygU, 0, m, &cRandom_suXWbygU_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_PUS0DV9O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_nhyJvJpZ_sendMessage);
}

void Heavy_SoundScraper::cUnop_nhyJvJpZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_JSbDhlg4_sendMessage);
}

void Heavy_SoundScraper::cRandom_suXWbygU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 15.0f, 0, m, &cBinop_PUS0DV9O_sendMessage);
}

void Heavy_SoundScraper::cSlice_uUyHGNsT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_suXWbygU, 1, m, &cRandom_suXWbygU_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_wNWlnUt6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSend_yc6uqMRX_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_vbIVip9l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSend_2u2M9IC0_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cUnop_YClodQnA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_gN4U6vTY, 0, m, &cPack_gN4U6vTY_sendMessage);
}

void Heavy_SoundScraper::cUnop_TPoAeY6b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_NNRvXRiE, 0, m, &cPack_NNRvXRiE_sendMessage);
}

void Heavy_SoundScraper::cPack_NNRvXRiE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_DZJ2zHzL, 0, m, NULL);
}

void Heavy_SoundScraper::cPack_gN4U6vTY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_BTi6nfqs, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_8nDPSpzL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_YClodQnA_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_SIN, m, &cUnop_TPoAeY6b_sendMessage);
}

void Heavy_SoundScraper::cMsg_jOiggj2V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.5f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_8nDPSpzL_sendMessage);
}

void Heavy_SoundScraper::cCast_JFGsAJ3K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cVar_WGv05G1Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_zGPhhkUJ_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_66zP3TH8_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_3hRmPNYA_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_PLzuIvrA_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_ogqCs2UF_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_ogqCs2UF_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_bKRFhH0W, 1, m, &cDelay_bKRFhH0W_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_lqgHLHR0_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cDelay_bKRFhH0W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_bKRFhH0W, m);
  cVar_onMessage(_c, &Context(_c)->cVar_BWR5CV5M, 0, m, &cVar_BWR5CV5M_sendMessage);
}

void Heavy_SoundScraper::cMsg_ogqCs2UF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_bKRFhH0W, 0, m, &cDelay_bKRFhH0W_sendMessage);
}

void Heavy_SoundScraper::cCast_lqgHLHR0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_bKRFhH0W, 0, m, &cDelay_bKRFhH0W_sendMessage);
}

void Heavy_SoundScraper::cVar_BWR5CV5M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_1ujLEQYz_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_cxEGqYti_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_WGv05G1Y, 0, m, &cVar_WGv05G1Y_sendMessage);
}

void Heavy_SoundScraper::cSend_OY5A0T4E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cSend_qmQWpRuD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_2e6PYhdn_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_E0iG91dj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 25.0f);
  cSend_OY5A0T4E_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_t6TeTkd9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 4000.0f);
  cSend_qmQWpRuD_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_UVHSV1g9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_IFUpBw1c_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_6gIik2nV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSend_UVHSV1g9_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_oJgrTUvf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cSend_AVd1ivxo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_2e6PYhdn_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_1S06fTvj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_IFUpBw1c_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_6Owfb85y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 25.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_eWf6Hcd7, 0, m, NULL);
}

void Heavy_SoundScraper::cMsg_1ujLEQYz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 0);
  sLine_onMessage(_c, &Context(_c)->sLine_eWf6Hcd7, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_3hRmPNYA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_PLzuIvrA_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_zGPhhkUJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_6Owfb85y_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_66zP3TH8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_BWR5CV5M, 1, m, &cVar_BWR5CV5M_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_EOemmzYQ_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_2dhjyFg0, 0, m, &cSlice_2dhjyFg0_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cVar_ElZ8w9SJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_y1r9ePSd_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSystem_AnAg9zN3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 2.0f, 0, m, &cBinop_GDQOSifj_sendMessage);
}

void Heavy_SoundScraper::cBinop_GDQOSifj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_JXcwgGbZ, m);
}

void Heavy_SoundScraper::cMsg_y1r9ePSd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_AnAg9zN3_sendMessage);
}

void Heavy_SoundScraper::cSlice_2dhjyFg0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sTabread_onMessage(_c, &Context(_c)->sTabread_xBw5RJ3t, 1, m, NULL);
      sTabread_onMessage(_c, &Context(_c)->sTabread_mgsZO6Oc, 1, m, NULL);
      cVar_onMessage(_c, &Context(_c)->cVar_ElZ8w9SJ, 0, m, &cVar_ElZ8w9SJ_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cVar_frDkIQGI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_R4WVTS4e, 0, m, &cPack_R4WVTS4e_sendMessage);
}

void Heavy_SoundScraper::cVar_fg8rT0PD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 10000000.0f, 0, m, &cBinop_U29JRYP6_sendMessage);
}

void Heavy_SoundScraper::cIf_ANzVnbf8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_ABS, m, &cUnop_mExc1Bl2_sendMessage);
      break;
    }
    case 1: {
      cVar_onMessage(_c, &Context(_c)->cVar_fg8rT0PD, 1, m, &cVar_fg8rT0PD_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_V2B5NHyD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_ANzVnbf8, 1, m, &cIf_ANzVnbf8_sendMessage);
}

void Heavy_SoundScraper::cVar_nMJDjlol_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 10000000.0f, 0, m, &cBinop_WtrveEH2_sendMessage);
}

void Heavy_SoundScraper::cUnop_mExc1Bl2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_nMJDjlol, 1, m, &cVar_nMJDjlol_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_WRk9Ypdf_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_p7rW0mpf_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Rw3NkxgV_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_p7rW0mpf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_fg8rT0PD, 0, m, &cVar_fg8rT0PD_sendMessage);
}

void Heavy_SoundScraper::cCast_Rw3NkxgV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_nMJDjlol, 0, m, &cVar_nMJDjlol_sendMessage);
}

void Heavy_SoundScraper::cVar_BT78dqfH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_LESS_THAN, 0.0f, 0, m, &cBinop_f4qH72LB_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_g9mQtbNG_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_8qAxQwp7_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_8qAxQwp7_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_nN8z599O, 1, m, &cDelay_nN8z599O_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_iTPxab0r_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cDelay_nN8z599O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_nN8z599O, m);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_jNNrNOQc_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Ff2tZCFa_sendMessage);
}

void Heavy_SoundScraper::cMsg_8qAxQwp7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_nN8z599O, 0, m, &cDelay_nN8z599O_sendMessage);
}

void Heavy_SoundScraper::cCast_iTPxab0r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_nN8z599O, 0, m, &cDelay_nN8z599O_sendMessage);
}

void Heavy_SoundScraper::cPack_9R0OC239_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_3JqjhCx9_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_TiZ6Qx4X_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_QnUfpgt9_sendMessage);
      break;
    }
    default: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_RcMRP1aZ, HV_BINOP_SUBTRACT, 0, m, &cBinop_RcMRP1aZ_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_QnUfpgt9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_XI3jp864_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_8jqwbyrR_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_qsAyJYkK_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_qsAyJYkK_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_uZ6UQQ2c, 1, m, &cDelay_uZ6UQQ2c_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_EuZBaMfv_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cDelay_uZ6UQQ2c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_uZ6UQQ2c, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_CFtSEFTG_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_XUeWV2BS_sendMessage);
}

void Heavy_SoundScraper::cMsg_qsAyJYkK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_uZ6UQQ2c, 0, m, &cDelay_uZ6UQQ2c_sendMessage);
}

void Heavy_SoundScraper::cCast_EuZBaMfv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_uZ6UQQ2c, 0, m, &cDelay_uZ6UQQ2c_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_jTEk0ZG5_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_92ICaQID_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_92ICaQID_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_V04rFeho, 1, m, &cDelay_V04rFeho_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_nwyOVbVp_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cDelay_V04rFeho_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_V04rFeho, m);
}

void Heavy_SoundScraper::cMsg_92ICaQID_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_V04rFeho, 0, m, &cDelay_V04rFeho_sendMessage);
}

void Heavy_SoundScraper::cCast_nwyOVbVp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_V04rFeho, 0, m, &cDelay_V04rFeho_sendMessage);
}

void Heavy_SoundScraper::cPack_V94TjeUb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_Yug8ti9O_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_pDCY6tUo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_GPFaeEob_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_nPHqOih6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_qnq9bDsU_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_9NVBnswA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_e5AjJpPc, HV_BINOP_DIVIDE, 1, m, &cBinop_e5AjJpPc_sendMessage);
}

void Heavy_SoundScraper::cVar_7pPQB3AE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_e5AjJpPc, HV_BINOP_DIVIDE, 0, m, &cBinop_e5AjJpPc_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_VOhMe8KT_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0xFFFFFFFF: { // "bang"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_mLFcf3nb_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_wkxyV09I_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_FzeC6GBw_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_fn0kF0q1_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_mLFcf3nb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_9NVBnswA, 0, m, &cVar_9NVBnswA_sendMessage);
}

void Heavy_SoundScraper::cCast_wkxyV09I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_7pPQB3AE, 0, m, &cVar_7pPQB3AE_sendMessage);
}

void Heavy_SoundScraper::cCast_FzeC6GBw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_9NVBnswA, 0, m, &cVar_9NVBnswA_sendMessage);
}

void Heavy_SoundScraper::cCast_fn0kF0q1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_7pPQB3AE, 0, m, &cVar_7pPQB3AE_sendMessage);
}

void Heavy_SoundScraper::cPack_R4WVTS4e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_eYIDg7Vi_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSlice_FewOWP42_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cPack_onMessage(_c, &Context(_c)->cPack_9R0OC239, 1, m, &cPack_9R0OC239_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_gQOevhEt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_BNqeNXWZ, HV_BINOP_ADD, 0, m, &cBinop_BNqeNXWZ_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_Tmrdpmmk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cPack_onMessage(_c, &Context(_c)->cPack_V94TjeUb, 1, m, &cPack_V94TjeUb_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_ORyvwG2L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_izmXpH4S, HV_BINOP_ADD, 0, m, &cBinop_izmXpH4S_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cPack_R9Mb9Q6C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_s1j8rXun_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_F3lFBbY7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_5r210bIB_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_Ff2tZCFa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_frDkIQGI, 0, m, &cVar_frDkIQGI_sendMessage);
}

void Heavy_SoundScraper::cCast_jNNrNOQc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_BT78dqfH, 0, m, &cVar_BT78dqfH_sendMessage);
}

void Heavy_SoundScraper::cSend_3JqjhCx9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_L6M6ma00_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_eYIDg7Vi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_0OX4nuXD_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_GPFaeEob_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_0OX4nuXD_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_FzxG0IoL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_g9mQtbNG_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_UMmBJsFA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_pDCY6tUo, 0, m, &cPack_pDCY6tUo_sendMessage);
}

void Heavy_SoundScraper::cBinop_U29JRYP6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_R9Mb9Q6C, 0, m, &cPack_R9Mb9Q6C_sendMessage);
}

void Heavy_SoundScraper::cSend_Yug8ti9O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_L6M6ma00_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_WtrveEH2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_F3lFBbY7, 0, m, &cPack_F3lFBbY7_sendMessage);
}

void Heavy_SoundScraper::cBinop_f4qH72LB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_WRk9Ypdf_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_BNqeNXWZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_9R0OC239, 0, m, &cPack_9R0OC239_sendMessage);
}

void Heavy_SoundScraper::cBinop_RcMRP1aZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_8jqwbyrR_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_izmXpH4S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_V94TjeUb, 0, m, &cPack_V94TjeUb_sendMessage);
}

void Heavy_SoundScraper::cMsg_XI3jp864_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "stop");
  cSwitchcase_8jqwbyrR_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_7ub5aOJD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_nP8Tbkw6, HV_BINOP_MULTIPLY, 1, m, &cBinop_nP8Tbkw6_sendMessage);
}

void Heavy_SoundScraper::cMsg_5r210bIB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 0.0f);
  cSlice_onMessage(_c, &Context(_c)->cSlice_Tmrdpmmk, 0, m, &cSlice_Tmrdpmmk_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_ORyvwG2L, 0, m, &cSlice_ORyvwG2L_sendMessage);
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 1);
  msg_setElementToFrom(m, 1, n, 0);
  cSlice_onMessage(_c, &Context(_c)->cSlice_Tmrdpmmk, 0, m, &cSlice_Tmrdpmmk_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_ORyvwG2L, 0, m, &cSlice_ORyvwG2L_sendMessage);
}

void Heavy_SoundScraper::cBinop_vg4Yb766_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_F3lFBbY7, 1, m, &cPack_F3lFBbY7_sendMessage);
}

void Heavy_SoundScraper::cBinop_hLv19Ayl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_R9Mb9Q6C, 1, m, &cPack_R9Mb9Q6C_sendMessage);
}

void Heavy_SoundScraper::cMsg_s1j8rXun_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 0.0f);
  cSlice_onMessage(_c, &Context(_c)->cSlice_FewOWP42, 0, m, &cSlice_FewOWP42_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_gQOevhEt, 0, m, &cSlice_gQOevhEt_sendMessage);
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 1);
  msg_setElementToFrom(m, 1, n, 0);
  cSlice_onMessage(_c, &Context(_c)->cSlice_FewOWP42, 0, m, &cSlice_FewOWP42_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_gQOevhEt, 0, m, &cSlice_gQOevhEt_sendMessage);
}

void Heavy_SoundScraper::cSend_qnq9bDsU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_0OX4nuXD_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_e5AjJpPc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 0.0f, 0, m, &cBinop_V2B5NHyD_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_ANzVnbf8, 0, m, &cIf_ANzVnbf8_sendMessage);
}

void Heavy_SoundScraper::cCast_OuLgaUhq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_pDCY6tUo, 1, m, &cPack_pDCY6tUo_sendMessage);
}

void Heavy_SoundScraper::cCast_oRmJ2g6h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_nN8z599O, 1, m, &cDelay_nN8z599O_sendMessage);
}

void Heavy_SoundScraper::cCast_IMWDPjjz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_izmXpH4S, HV_BINOP_ADD, 1, m, &cBinop_izmXpH4S_sendMessage);
}

void Heavy_SoundScraper::cCast_Jsqsimxa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_BNqeNXWZ, HV_BINOP_ADD, 1, m, &cBinop_BNqeNXWZ_sendMessage);
}

void Heavy_SoundScraper::cCast_5KVuXS7o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_V04rFeho, 1, m, &cDelay_V04rFeho_sendMessage);
}

void Heavy_SoundScraper::cCast_dtptFiL9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_RcMRP1aZ, HV_BINOP_SUBTRACT, 1, m, &cBinop_RcMRP1aZ_sendMessage);
}

void Heavy_SoundScraper::cCast_XUeWV2BS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_nPHqOih6, 0, m, &cPack_nPHqOih6_sendMessage);
}

void Heavy_SoundScraper::cCast_CFtSEFTG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_jTEk0ZG5_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_A24UBkmi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_jTEk0ZG5_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_UlhEjkPA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_8jqwbyrR_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_nP8Tbkw6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_IMWDPjjz_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Jsqsimxa_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_T9juF2RO_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_AJfreagC_sendMessage);
      break;
    }
    default: {
      cVar_onMessage(_c, &Context(_c)->cVar_frDkIQGI, 1, m, &cVar_frDkIQGI_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_AJfreagC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_LAPkjMyp_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_9RKe0T0C_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_4pYW5aan_sendMessage);
      break;
    }
    default: {
      cSwitchcase_VOhMe8KT_onMessage(_c, NULL, 0, m, NULL);
      cVar_onMessage(_c, &Context(_c)->cVar_BT78dqfH, 1, m, &cVar_BT78dqfH_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_4pYW5aan_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_aTrUEevr_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSlice_sOGnVyGV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_89Uix1kS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSwitchcase_TiZ6Qx4X_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_IgHAKEXO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_nP8Tbkw6, HV_BINOP_MULTIPLY, 0, m, &cBinop_nP8Tbkw6_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_IbTr7vdw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSwitchcase_9RKe0T0C_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_P0lHMemF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_y9SeDNZ3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSwitchcase_T9juF2RO_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cMsg_LAPkjMyp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_frDkIQGI, 1, m, &cVar_frDkIQGI_sendMessage);
}

void Heavy_SoundScraper::cCast_FlGnUtx1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_o475p7kG_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_aTrUEevr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_VOhMe8KT_onMessage(_c, NULL, 0, m, NULL);
  cVar_onMessage(_c, &Context(_c)->cVar_BT78dqfH, 1, m, &cVar_BT78dqfH_sendMessage);
}

void Heavy_SoundScraper::cMsg_o475p7kG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(6);
  msg_init(m, 6, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setSymbol(m, 1, "xylo");
  msg_setFloat(m, 2, 1.0f);
  msg_setFloat(m, 3, 0.0f);
  msg_setFloat(m, 4, 0.0f);
  msg_setFloat(m, 5, 0.0f);
  cSlice_onMessage(_c, &Context(_c)->cSlice_sOGnVyGV, 0, m, &cSlice_sOGnVyGV_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_89Uix1kS, 0, m, &cSlice_89Uix1kS_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_IgHAKEXO, 0, m, &cSlice_IgHAKEXO_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_IbTr7vdw, 0, m, &cSlice_IbTr7vdw_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_P0lHMemF, 0, m, &cSlice_P0lHMemF_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_y9SeDNZ3, 0, m, &cSlice_y9SeDNZ3_sendMessage);
}

void Heavy_SoundScraper::cSlice_q913uTQy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_bC5AqSRN_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_SNqauEsw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_WOH9KlXe_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_WOH9KlXe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_16P3DXvh_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_16P3DXvh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_YcEnJgFp_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_bC5AqSRN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_UiMWUvo4_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_UiMWUvo4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_DyIEfgWu_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_CenH7Iu5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_5EuPGgkJ_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_3JjI015I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_xzRERvmG, HV_BINOP_MULTIPLY, 1, m, &cBinop_xzRERvmG_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_tcY0TnkR, HV_BINOP_MULTIPLY, 1, m, &cBinop_tcY0TnkR_sendMessage);
}

void Heavy_SoundScraper::cSlice_YsFyi4wb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_xzRERvmG, HV_BINOP_MULTIPLY, 0, m, &cBinop_xzRERvmG_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_PjiW2wIC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_tcY0TnkR, HV_BINOP_MULTIPLY, 0, m, &cBinop_tcY0TnkR_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cMsg_5EuPGgkJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setElementToFrom(m, 2, n, 1);
  cMsg_nUX2NDRy_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_nUX2NDRy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 441000000.0f);
  msg_setFloat(m, 1, 10000000.0f);
}

void Heavy_SoundScraper::cBinop_xzRERvmG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_CenH7Iu5, 1, m, &cPack_CenH7Iu5_sendMessage);
}

void Heavy_SoundScraper::cBinop_tcY0TnkR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_CenH7Iu5, 0, m, &cPack_CenH7Iu5_sendMessage);
}

void Heavy_SoundScraper::cMsg_fW2cMLmM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 44100.0f);
  msg_setFloat(m, 1, 1000.0f);
  cSlice_onMessage(_c, &Context(_c)->cSlice_YsFyi4wb, 0, m, &cSlice_YsFyi4wb_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_PjiW2wIC, 0, m, &cSlice_PjiW2wIC_sendMessage);
}

void Heavy_SoundScraper::cSend_jlQhp6Rx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_g1ubUxkO_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_E6cPTECb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 1);
  cSwitchcase_EOemmzYQ_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cSlice_OpJn6SpZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 127.0f, 0, m, &cBinop_TBMlqiKx_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_8FYGSYOx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_DaxYFkxD_sendMessage);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_hbO7bOzI_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cVar_uAmKGXU3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_qE6uJ60d, 1, m, &cPack_qE6uJ60d_sendMessage);
}

void Heavy_SoundScraper::cVar_keCa5M7B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_qE6uJ60d, 0, m, &cPack_qE6uJ60d_sendMessage);
}

void Heavy_SoundScraper::cPack_qE6uJ60d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_6XYGl7Wo_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_8vRRyaJA_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_FlGnUtx1_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_sOGnVyGV, 0, m, &cSlice_sOGnVyGV_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_89Uix1kS, 0, m, &cSlice_89Uix1kS_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_IgHAKEXO, 0, m, &cSlice_IgHAKEXO_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_IbTr7vdw, 0, m, &cSlice_IbTr7vdw_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_P0lHMemF, 0, m, &cSlice_P0lHMemF_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_y9SeDNZ3, 0, m, &cSlice_y9SeDNZ3_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_UMmBJsFA_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_FzxG0IoL_sendMessage);
  cMsg_E6cPTECb_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_wSxcIlYp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_uAmKGXU3, 0, m, &cVar_uAmKGXU3_sendMessage);
}

void Heavy_SoundScraper::cCast_KDtuPWrz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_qE6uJ60d, 2, m, &cPack_qE6uJ60d_sendMessage);
}

void Heavy_SoundScraper::cCast_KmRtDOzr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_keCa5M7B, 0, m, &cVar_keCa5M7B_sendMessage);
}

void Heavy_SoundScraper::cBinop_w9b3CYcq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.4f, 0, m, &cBinop_UBEE9rIR_sendMessage);
}

void Heavy_SoundScraper::cBinop_UBEE9rIR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_8nDPSpzL_sendMessage);
}

void Heavy_SoundScraper::cBinop_TBMlqiKx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_wNwbst8b_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_E2SNNb7M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_KDtuPWrz_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_wSxcIlYp_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_KmRtDOzr_sendMessage);
}

void Heavy_SoundScraper::cBinop_JSbDhlg4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.99f, 0, m, &cBinop_hAqjW8oL_sendMessage);
}

void Heavy_SoundScraper::cBinop_hAqjW8oL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_E2SNNb7M, HV_BINOP_MULTIPLY, 1, m, &cBinop_E2SNNb7M_sendMessage);
}

void Heavy_SoundScraper::cCast_DaxYFkxD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_jVqQrccF_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_6XYGl7Wo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_j6cL7sPq_onMessage(_c, NULL, 0, m, NULL);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_JFGsAJ3K_sendMessage);
}

void Heavy_SoundScraper::cCast_8vRRyaJA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_cxEGqYti_sendMessage);
}

void Heavy_SoundScraper::cSend_2u2M9IC0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_VwClcVqs_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_yc6uqMRX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_DzVcW1fk_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_AHEJrPNI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_E2SNNb7M, HV_BINOP_MULTIPLY, 0, m, &cBinop_E2SNNb7M_sendMessage);
}

void Heavy_SoundScraper::cSend_wNwbst8b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_cKALy0NQ_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_qWZTx8PI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 44100.0f);
  cSend_jlQhp6Rx_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_ps1Fx2iB_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_jL1aemTM, 0, m, &cSlice_jL1aemTM_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_QbC9d9sF, 0, m, &cRandom_QbC9d9sF_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_SgUmQgcf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_IKhDDuT3_sendMessage);
}

void Heavy_SoundScraper::cUnop_IKhDDuT3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_9no95Sac_sendMessage);
}

void Heavy_SoundScraper::cRandom_QbC9d9sF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_SgUmQgcf_sendMessage);
}

void Heavy_SoundScraper::cSlice_jL1aemTM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_QbC9d9sF, 1, m, &cRandom_QbC9d9sF_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_8A15pcHc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_hatdRi6q, HV_BINOP_DIVIDE, 0, m, &cBinop_hatdRi6q_sendMessage);
}

void Heavy_SoundScraper::cBinop_qFjnd1v7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_Tf7JWWFY_sendMessage);
}

void Heavy_SoundScraper::cBinop_Tf7JWWFY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MlUgg5hq, HV_BINOP_POW, 1, m, &cBinop_MlUgg5hq_sendMessage);
  cMsg_a227zo9A_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_MlUgg5hq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_8A15pcHc_sendMessage);
}

void Heavy_SoundScraper::cMsg_a227zo9A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_MlUgg5hq, HV_BINOP_POW, 0, m, &cBinop_MlUgg5hq_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_Gx9SyL6q_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_jW3NkgoX, 0, m, &cSlice_jW3NkgoX_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_xNsxWC1Q, 0, m, &cRandom_xNsxWC1Q_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_yXy8NabF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_55P3tT4D_sendMessage);
}

void Heavy_SoundScraper::cUnop_55P3tT4D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_wYKF9xzh_sendMessage);
}

void Heavy_SoundScraper::cRandom_xNsxWC1Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 15.0f, 0, m, &cBinop_yXy8NabF_sendMessage);
}

void Heavy_SoundScraper::cSlice_jW3NkgoX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_xNsxWC1Q, 1, m, &cRandom_xNsxWC1Q_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_PNo0Dq9R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSend_YqiOSiwi_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_jKNtMYot_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSend_AgpnNZxM_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cUnop_7AViV4qI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_jy5Fm3e7, 0, m, &cPack_jy5Fm3e7_sendMessage);
}

void Heavy_SoundScraper::cUnop_LLZynnw6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_wOMA16Om, 0, m, &cPack_wOMA16Om_sendMessage);
}

void Heavy_SoundScraper::cPack_wOMA16Om_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_7GFtrkKz, 0, m, NULL);
}

void Heavy_SoundScraper::cPack_jy5Fm3e7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_LH3Dh0ra, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_xetW2Mde_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_7AViV4qI_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_SIN, m, &cUnop_LLZynnw6_sendMessage);
}

void Heavy_SoundScraper::cMsg_xSgukN5j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.5f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_xetW2Mde_sendMessage);
}

void Heavy_SoundScraper::cCast_BVo8aw70_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cVar_Y1Jf5hjX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_7svDorcm_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_XepdE2CX_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_qq5ami8Y_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_1SHoROpP_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_yGpz6y4J_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_yGpz6y4J_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_DMddClrK, 1, m, &cDelay_DMddClrK_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_UCSl0i9W_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cDelay_DMddClrK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_DMddClrK, m);
  cVar_onMessage(_c, &Context(_c)->cVar_1TqhJKMh, 0, m, &cVar_1TqhJKMh_sendMessage);
}

void Heavy_SoundScraper::cMsg_yGpz6y4J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_DMddClrK, 0, m, &cDelay_DMddClrK_sendMessage);
}

void Heavy_SoundScraper::cCast_UCSl0i9W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_DMddClrK, 0, m, &cDelay_DMddClrK_sendMessage);
}

void Heavy_SoundScraper::cVar_1TqhJKMh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_eT94ZZd0_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_EvPzy6Pn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Y1Jf5hjX, 0, m, &cVar_Y1Jf5hjX_sendMessage);
}

void Heavy_SoundScraper::cSend_cGVSFouL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cSend_CbfTeFTP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_Ny20W2gi_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_eaLezNaR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 25.0f);
  cSend_cGVSFouL_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_IPCexPic_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 4000.0f);
  cSend_CbfTeFTP_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_4IEYFDlj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_t6QY9Ufm_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_9A2mmMok_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSend_4IEYFDlj_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_9IsRQ8TE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cSend_nUQIH1rt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_Ny20W2gi_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_NdS3fQsC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_t6QY9Ufm_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_vvfLvsTi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 25.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_GqCKfENF, 0, m, NULL);
}

void Heavy_SoundScraper::cMsg_eT94ZZd0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 0);
  sLine_onMessage(_c, &Context(_c)->sLine_GqCKfENF, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_qq5ami8Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_1SHoROpP_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_7svDorcm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_vvfLvsTi_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_XepdE2CX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_1TqhJKMh, 1, m, &cVar_1TqhJKMh_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_e3FzBopW_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_mKwufd6I, 0, m, &cSlice_mKwufd6I_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cVar_6CDrXQCO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_nR0sPy1X_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSystem_Ke3mr3Hg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 2.0f, 0, m, &cBinop_vuzJNDld_sendMessage);
}

void Heavy_SoundScraper::cBinop_vuzJNDld_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_Nn7V9Hd7, m);
}

void Heavy_SoundScraper::cMsg_nR0sPy1X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Ke3mr3Hg_sendMessage);
}

void Heavy_SoundScraper::cSlice_mKwufd6I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sTabread_onMessage(_c, &Context(_c)->sTabread_hwNjTqPz, 1, m, NULL);
      sTabread_onMessage(_c, &Context(_c)->sTabread_PboqmQLM, 1, m, NULL);
      cVar_onMessage(_c, &Context(_c)->cVar_6CDrXQCO, 0, m, &cVar_6CDrXQCO_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cVar_rFdNLdNc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_9Oxen0Bc, 0, m, &cPack_9Oxen0Bc_sendMessage);
}

void Heavy_SoundScraper::cVar_589Ow6JA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 10000000.0f, 0, m, &cBinop_XgHCuMkE_sendMessage);
}

void Heavy_SoundScraper::cIf_15EWwi9y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_ABS, m, &cUnop_WFJs0l5x_sendMessage);
      break;
    }
    case 1: {
      cVar_onMessage(_c, &Context(_c)->cVar_589Ow6JA, 1, m, &cVar_589Ow6JA_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_9RJGhkkU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_15EWwi9y, 1, m, &cIf_15EWwi9y_sendMessage);
}

void Heavy_SoundScraper::cVar_IdoFatIK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 10000000.0f, 0, m, &cBinop_q2ZYVdxQ_sendMessage);
}

void Heavy_SoundScraper::cUnop_WFJs0l5x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_IdoFatIK, 1, m, &cVar_IdoFatIK_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_DdZXDGGu_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_9bpVlvbT_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_w9XIcBk5_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_9bpVlvbT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_589Ow6JA, 0, m, &cVar_589Ow6JA_sendMessage);
}

void Heavy_SoundScraper::cCast_w9XIcBk5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_IdoFatIK, 0, m, &cVar_IdoFatIK_sendMessage);
}

void Heavy_SoundScraper::cVar_ur5Ln5zg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_LESS_THAN, 0.0f, 0, m, &cBinop_Iw6draHU_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_35hT12Yu_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_FsTRCEyk_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_FsTRCEyk_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_gdJ2NfSa, 1, m, &cDelay_gdJ2NfSa_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_fcGfYK6b_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cDelay_gdJ2NfSa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_gdJ2NfSa, m);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Sl1ZkKAn_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_UiygUVuo_sendMessage);
}

void Heavy_SoundScraper::cMsg_FsTRCEyk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_gdJ2NfSa, 0, m, &cDelay_gdJ2NfSa_sendMessage);
}

void Heavy_SoundScraper::cCast_fcGfYK6b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_gdJ2NfSa, 0, m, &cDelay_gdJ2NfSa_sendMessage);
}

void Heavy_SoundScraper::cPack_ta6qkmA5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_3WBtDhtd_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_M5z4BQYl_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ytKIYzbB_sendMessage);
      break;
    }
    default: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_ysWP8rO3, HV_BINOP_SUBTRACT, 0, m, &cBinop_ysWP8rO3_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_ytKIYzbB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_kSSZzUNE_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_r2qL6lyi_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_iDXsljX0_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_iDXsljX0_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_bM1ORgnN, 1, m, &cDelay_bM1ORgnN_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_LK2PeAxd_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cDelay_bM1ORgnN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_bM1ORgnN, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_sLoDuJcv_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_FyJ5Bpn8_sendMessage);
}

void Heavy_SoundScraper::cMsg_iDXsljX0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_bM1ORgnN, 0, m, &cDelay_bM1ORgnN_sendMessage);
}

void Heavy_SoundScraper::cCast_LK2PeAxd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_bM1ORgnN, 0, m, &cDelay_bM1ORgnN_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_71ANC3KL_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_cATHs7R3_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_cATHs7R3_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_ZOYBwgG7, 1, m, &cDelay_ZOYBwgG7_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_kPzwwEfW_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cDelay_ZOYBwgG7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_ZOYBwgG7, m);
}

void Heavy_SoundScraper::cMsg_cATHs7R3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_ZOYBwgG7, 0, m, &cDelay_ZOYBwgG7_sendMessage);
}

void Heavy_SoundScraper::cCast_kPzwwEfW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_ZOYBwgG7, 0, m, &cDelay_ZOYBwgG7_sendMessage);
}

void Heavy_SoundScraper::cPack_KaAMU7IT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_xSX6inOI_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_sPOghNV4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_xJ5d1pm3_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_h3QM94QA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_beuXNbqN_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_JX5EUlhL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_qh5fAEbB, HV_BINOP_DIVIDE, 1, m, &cBinop_qh5fAEbB_sendMessage);
}

void Heavy_SoundScraper::cVar_jd2GXLKc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_qh5fAEbB, HV_BINOP_DIVIDE, 0, m, &cBinop_qh5fAEbB_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_0nAdpW10_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0xFFFFFFFF: { // "bang"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_YtNkFrNo_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_9qM55o5h_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_sjPelDWa_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Ii2mMkyg_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_9qM55o5h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_jd2GXLKc, 0, m, &cVar_jd2GXLKc_sendMessage);
}

void Heavy_SoundScraper::cCast_YtNkFrNo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_JX5EUlhL, 0, m, &cVar_JX5EUlhL_sendMessage);
}

void Heavy_SoundScraper::cCast_Ii2mMkyg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_jd2GXLKc, 0, m, &cVar_jd2GXLKc_sendMessage);
}

void Heavy_SoundScraper::cCast_sjPelDWa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_JX5EUlhL, 0, m, &cVar_JX5EUlhL_sendMessage);
}

void Heavy_SoundScraper::cPack_9Oxen0Bc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_2iT1er4r_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSlice_hOu2I4yS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cPack_onMessage(_c, &Context(_c)->cPack_ta6qkmA5, 1, m, &cPack_ta6qkmA5_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_N7Ns57ec_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_Caxp42Nq, HV_BINOP_ADD, 0, m, &cBinop_Caxp42Nq_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_CaFCmnf6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cPack_onMessage(_c, &Context(_c)->cPack_KaAMU7IT, 1, m, &cPack_KaAMU7IT_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_A0Axd9YA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_mzDQcHrD, HV_BINOP_ADD, 0, m, &cBinop_mzDQcHrD_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cPack_423BdKRO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_A1S4wI10_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_YjvOV4Tn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_MjmbCG2G_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_UiygUVuo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_rFdNLdNc, 0, m, &cVar_rFdNLdNc_sendMessage);
}

void Heavy_SoundScraper::cCast_Sl1ZkKAn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ur5Ln5zg, 0, m, &cVar_ur5Ln5zg_sendMessage);
}

void Heavy_SoundScraper::cSend_3WBtDhtd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_DkrCXPjl_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_2iT1er4r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_WSXk0mmC_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_xJ5d1pm3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_WSXk0mmC_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_bV0JQ8b5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_35hT12Yu_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_DnCWrcsS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_sPOghNV4, 0, m, &cPack_sPOghNV4_sendMessage);
}

void Heavy_SoundScraper::cBinop_XgHCuMkE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_423BdKRO, 0, m, &cPack_423BdKRO_sendMessage);
}

void Heavy_SoundScraper::cSend_xSX6inOI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_DkrCXPjl_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_q2ZYVdxQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_YjvOV4Tn, 0, m, &cPack_YjvOV4Tn_sendMessage);
}

void Heavy_SoundScraper::cBinop_Iw6draHU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_DdZXDGGu_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_Caxp42Nq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_ta6qkmA5, 0, m, &cPack_ta6qkmA5_sendMessage);
}

void Heavy_SoundScraper::cBinop_ysWP8rO3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_r2qL6lyi_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_mzDQcHrD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_KaAMU7IT, 0, m, &cPack_KaAMU7IT_sendMessage);
}

void Heavy_SoundScraper::cMsg_kSSZzUNE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "stop");
  cSwitchcase_r2qL6lyi_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_749hPpiX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_R39gb8US, HV_BINOP_MULTIPLY, 1, m, &cBinop_R39gb8US_sendMessage);
}

void Heavy_SoundScraper::cMsg_MjmbCG2G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 0.0f);
  cSlice_onMessage(_c, &Context(_c)->cSlice_CaFCmnf6, 0, m, &cSlice_CaFCmnf6_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_A0Axd9YA, 0, m, &cSlice_A0Axd9YA_sendMessage);
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 1);
  msg_setElementToFrom(m, 1, n, 0);
  cSlice_onMessage(_c, &Context(_c)->cSlice_CaFCmnf6, 0, m, &cSlice_CaFCmnf6_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_A0Axd9YA, 0, m, &cSlice_A0Axd9YA_sendMessage);
}

void Heavy_SoundScraper::cBinop_CPNK3XrI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_YjvOV4Tn, 1, m, &cPack_YjvOV4Tn_sendMessage);
}

void Heavy_SoundScraper::cBinop_wtxz4mNH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_423BdKRO, 1, m, &cPack_423BdKRO_sendMessage);
}

void Heavy_SoundScraper::cMsg_A1S4wI10_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 0.0f);
  cSlice_onMessage(_c, &Context(_c)->cSlice_hOu2I4yS, 0, m, &cSlice_hOu2I4yS_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_N7Ns57ec, 0, m, &cSlice_N7Ns57ec_sendMessage);
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 1);
  msg_setElementToFrom(m, 1, n, 0);
  cSlice_onMessage(_c, &Context(_c)->cSlice_hOu2I4yS, 0, m, &cSlice_hOu2I4yS_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_N7Ns57ec, 0, m, &cSlice_N7Ns57ec_sendMessage);
}

void Heavy_SoundScraper::cSend_beuXNbqN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_WSXk0mmC_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_qh5fAEbB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 0.0f, 0, m, &cBinop_9RJGhkkU_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_15EWwi9y, 0, m, &cIf_15EWwi9y_sendMessage);
}

void Heavy_SoundScraper::cCast_yAt4kJ9U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_gdJ2NfSa, 1, m, &cDelay_gdJ2NfSa_sendMessage);
}

void Heavy_SoundScraper::cCast_8aECMBjy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_sPOghNV4, 1, m, &cPack_sPOghNV4_sendMessage);
}

void Heavy_SoundScraper::cCast_cD2Rwl9E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Caxp42Nq, HV_BINOP_ADD, 1, m, &cBinop_Caxp42Nq_sendMessage);
}

void Heavy_SoundScraper::cCast_PGoZD9IP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_mzDQcHrD, HV_BINOP_ADD, 1, m, &cBinop_mzDQcHrD_sendMessage);
}

void Heavy_SoundScraper::cCast_YCspmILG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ysWP8rO3, HV_BINOP_SUBTRACT, 1, m, &cBinop_ysWP8rO3_sendMessage);
}

void Heavy_SoundScraper::cCast_6C4xKD9C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_ZOYBwgG7, 1, m, &cDelay_ZOYBwgG7_sendMessage);
}

void Heavy_SoundScraper::cCast_FyJ5Bpn8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_h3QM94QA, 0, m, &cPack_h3QM94QA_sendMessage);
}

void Heavy_SoundScraper::cCast_sLoDuJcv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_71ANC3KL_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_T9MpY4lq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_71ANC3KL_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_vKS7Qtz2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_r2qL6lyi_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_R39gb8US_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_PGoZD9IP_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_cD2Rwl9E_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_s3Uut6u4_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_GaixoBxX_sendMessage);
      break;
    }
    default: {
      cVar_onMessage(_c, &Context(_c)->cVar_rFdNLdNc, 1, m, &cVar_rFdNLdNc_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_GaixoBxX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ggs8Bhe1_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_J44n695G_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_05UGwyeF_sendMessage);
      break;
    }
    default: {
      cSwitchcase_0nAdpW10_onMessage(_c, NULL, 0, m, NULL);
      cVar_onMessage(_c, &Context(_c)->cVar_ur5Ln5zg, 1, m, &cVar_ur5Ln5zg_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_05UGwyeF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_6bTZF3vW_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSlice_gaAw5WGI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_V8KTCLuF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSwitchcase_M5z4BQYl_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_VSVVtVk8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_R39gb8US, HV_BINOP_MULTIPLY, 0, m, &cBinop_R39gb8US_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_uQ8d03ER_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSwitchcase_J44n695G_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_1rh66Dec_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_J9Iz24XV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSwitchcase_s3Uut6u4_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cMsg_ggs8Bhe1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_rFdNLdNc, 1, m, &cVar_rFdNLdNc_sendMessage);
}

void Heavy_SoundScraper::cCast_wqlINXE8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_A7P11vgv_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_6bTZF3vW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_0nAdpW10_onMessage(_c, NULL, 0, m, NULL);
  cVar_onMessage(_c, &Context(_c)->cVar_ur5Ln5zg, 1, m, &cVar_ur5Ln5zg_sendMessage);
}

void Heavy_SoundScraper::cMsg_A7P11vgv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(6);
  msg_init(m, 6, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setSymbol(m, 1, "xylo");
  msg_setFloat(m, 2, 1.0f);
  msg_setFloat(m, 3, 0.0f);
  msg_setFloat(m, 4, 0.0f);
  msg_setFloat(m, 5, 0.0f);
  cSlice_onMessage(_c, &Context(_c)->cSlice_gaAw5WGI, 0, m, &cSlice_gaAw5WGI_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_V8KTCLuF, 0, m, &cSlice_V8KTCLuF_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_VSVVtVk8, 0, m, &cSlice_VSVVtVk8_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_uQ8d03ER, 0, m, &cSlice_uQ8d03ER_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_1rh66Dec, 0, m, &cSlice_1rh66Dec_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_J9Iz24XV, 0, m, &cSlice_J9Iz24XV_sendMessage);
}

void Heavy_SoundScraper::cSlice_loWxhItA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_3DonLMpV_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_cgmFh1Qk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_ZZJvlY9B_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_ZZJvlY9B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_kXjoNm1S_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_kXjoNm1S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_iTu3jDc3_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_3DonLMpV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_3KrzUap7_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_3KrzUap7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_cJVsE5lQ_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_jcWimDQH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_SHNUi0c6_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_eVS3JXNs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MNQFgYqQ, HV_BINOP_MULTIPLY, 1, m, &cBinop_MNQFgYqQ_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_9N2IuUdJ, HV_BINOP_MULTIPLY, 1, m, &cBinop_9N2IuUdJ_sendMessage);
}

void Heavy_SoundScraper::cSlice_6yYIQnJT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_MNQFgYqQ, HV_BINOP_MULTIPLY, 0, m, &cBinop_MNQFgYqQ_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_s0BjkqeN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_9N2IuUdJ, HV_BINOP_MULTIPLY, 0, m, &cBinop_9N2IuUdJ_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cMsg_SHNUi0c6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setElementToFrom(m, 2, n, 1);
  cMsg_oeWnPaCz_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_oeWnPaCz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 441000000.0f);
  msg_setFloat(m, 1, 10000000.0f);
}

void Heavy_SoundScraper::cBinop_MNQFgYqQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_jcWimDQH, 1, m, &cPack_jcWimDQH_sendMessage);
}

void Heavy_SoundScraper::cBinop_9N2IuUdJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_jcWimDQH, 0, m, &cPack_jcWimDQH_sendMessage);
}

void Heavy_SoundScraper::cMsg_69lVSQcA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 44100.0f);
  msg_setFloat(m, 1, 1000.0f);
  cSlice_onMessage(_c, &Context(_c)->cSlice_6yYIQnJT, 0, m, &cSlice_6yYIQnJT_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_s0BjkqeN, 0, m, &cSlice_s0BjkqeN_sendMessage);
}

void Heavy_SoundScraper::cSend_RbdjymVR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_o0z1zy04_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_FLPK1t9U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 1);
  cSwitchcase_e3FzBopW_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cSlice_XVu6ikGS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 127.0f, 0, m, &cBinop_hi2uUy0E_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_yxD3gljR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ia4fApGr_sendMessage);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_qFjnd1v7_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cVar_EOi2HGD9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_hHOPTAfo, 1, m, &cPack_hHOPTAfo_sendMessage);
}

void Heavy_SoundScraper::cVar_bwLv7dUn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_hHOPTAfo, 0, m, &cPack_hHOPTAfo_sendMessage);
}

void Heavy_SoundScraper::cPack_hHOPTAfo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_YgRWbMWe_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_9R5ASU4T_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_wqlINXE8_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_gaAw5WGI, 0, m, &cSlice_gaAw5WGI_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_V8KTCLuF, 0, m, &cSlice_V8KTCLuF_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_VSVVtVk8, 0, m, &cSlice_VSVVtVk8_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_uQ8d03ER, 0, m, &cSlice_uQ8d03ER_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_1rh66Dec, 0, m, &cSlice_1rh66Dec_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_J9Iz24XV, 0, m, &cSlice_J9Iz24XV_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_DnCWrcsS_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_bV0JQ8b5_sendMessage);
  cMsg_FLPK1t9U_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_jFFijKWx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_EOi2HGD9, 0, m, &cVar_EOi2HGD9_sendMessage);
}

void Heavy_SoundScraper::cCast_K1njCKaL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_hHOPTAfo, 2, m, &cPack_hHOPTAfo_sendMessage);
}

void Heavy_SoundScraper::cCast_yvoKEvEr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_bwLv7dUn, 0, m, &cVar_bwLv7dUn_sendMessage);
}

void Heavy_SoundScraper::cBinop_9no95Sac_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.4f, 0, m, &cBinop_akajrebD_sendMessage);
}

void Heavy_SoundScraper::cBinop_akajrebD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_xetW2Mde_sendMessage);
}

void Heavy_SoundScraper::cBinop_hi2uUy0E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_N9gxfacm_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_D5wxfPmT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_K1njCKaL_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_jFFijKWx_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_yvoKEvEr_sendMessage);
}

void Heavy_SoundScraper::cBinop_wYKF9xzh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.99f, 0, m, &cBinop_TgtKyTds_sendMessage);
}

void Heavy_SoundScraper::cBinop_TgtKyTds_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_D5wxfPmT, HV_BINOP_MULTIPLY, 1, m, &cBinop_D5wxfPmT_sendMessage);
}

void Heavy_SoundScraper::cCast_ia4fApGr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_Gx9SyL6q_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_YgRWbMWe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_ps1Fx2iB_onMessage(_c, NULL, 0, m, NULL);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_BVo8aw70_sendMessage);
}

void Heavy_SoundScraper::cCast_9R5ASU4T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_EvPzy6Pn_sendMessage);
}

void Heavy_SoundScraper::cSend_AgpnNZxM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_sy7lEKy8_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_YqiOSiwi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_bQmnjCmK_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_hatdRi6q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_D5wxfPmT, HV_BINOP_MULTIPLY, 0, m, &cBinop_D5wxfPmT_sendMessage);
}

void Heavy_SoundScraper::cSend_N9gxfacm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_e7iVXB92_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_GuO8q63e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 44100.0f);
  cSend_RbdjymVR_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_AA6If2A8_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_3pmyhKo4, 0, m, &cSlice_3pmyhKo4_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_skGozKfJ, 0, m, &cRandom_skGozKfJ_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_qrVTSxkN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_0vO4MDPO_sendMessage);
}

void Heavy_SoundScraper::cUnop_0vO4MDPO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_Tie3kjDG_sendMessage);
}

void Heavy_SoundScraper::cRandom_skGozKfJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_qrVTSxkN_sendMessage);
}

void Heavy_SoundScraper::cSlice_3pmyhKo4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_skGozKfJ, 1, m, &cRandom_skGozKfJ_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_eqchUWIi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_rTqbfmim, HV_BINOP_DIVIDE, 0, m, &cBinop_rTqbfmim_sendMessage);
}

void Heavy_SoundScraper::cBinop_wwYakmut_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_nnRrhFxz_sendMessage);
}

void Heavy_SoundScraper::cBinop_nnRrhFxz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Pcm2RgL2, HV_BINOP_POW, 1, m, &cBinop_Pcm2RgL2_sendMessage);
  cMsg_QfWFgIwT_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_Pcm2RgL2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_eqchUWIi_sendMessage);
}

void Heavy_SoundScraper::cMsg_QfWFgIwT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_Pcm2RgL2, HV_BINOP_POW, 0, m, &cBinop_Pcm2RgL2_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_7qysyEk6_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_sAt3HrcJ, 0, m, &cSlice_sAt3HrcJ_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_q9TYbDK2, 0, m, &cRandom_q9TYbDK2_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_RftgQI58_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_GAtPp1Sn_sendMessage);
}

void Heavy_SoundScraper::cUnop_GAtPp1Sn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_C6zjyhoY_sendMessage);
}

void Heavy_SoundScraper::cRandom_q9TYbDK2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 15.0f, 0, m, &cBinop_RftgQI58_sendMessage);
}

void Heavy_SoundScraper::cSlice_sAt3HrcJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_q9TYbDK2, 1, m, &cRandom_q9TYbDK2_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_PGQ4Pvv1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSend_ME5gEDap_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_AcxWZBRR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSend_o45Vw17R_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cUnop_s1LzbMFQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_6cQGxbVt, 0, m, &cPack_6cQGxbVt_sendMessage);
}

void Heavy_SoundScraper::cUnop_9L9jdK9u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_7oUJxeou, 0, m, &cPack_7oUJxeou_sendMessage);
}

void Heavy_SoundScraper::cPack_7oUJxeou_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_FoyksauD, 0, m, NULL);
}

void Heavy_SoundScraper::cPack_6cQGxbVt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_qMIERDg8, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_XcAkTQed_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_s1LzbMFQ_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_SIN, m, &cUnop_9L9jdK9u_sendMessage);
}

void Heavy_SoundScraper::cMsg_R9pXDnMm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.5f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_XcAkTQed_sendMessage);
}

void Heavy_SoundScraper::cCast_tBhfBFU6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cVar_ri8Mlkro_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_SoQsaDtl_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_iMS5EPPw_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_cjUqswMa_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_CKz4pb4A_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_p3llWyon_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_p3llWyon_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_VIeFyLs0, 1, m, &cDelay_VIeFyLs0_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_jXndjml3_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cDelay_VIeFyLs0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_VIeFyLs0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_01oBirK5, 0, m, &cVar_01oBirK5_sendMessage);
}

void Heavy_SoundScraper::cMsg_p3llWyon_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_VIeFyLs0, 0, m, &cDelay_VIeFyLs0_sendMessage);
}

void Heavy_SoundScraper::cCast_jXndjml3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_VIeFyLs0, 0, m, &cDelay_VIeFyLs0_sendMessage);
}

void Heavy_SoundScraper::cVar_01oBirK5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_HpKZm6sH_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_acszxk8b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ri8Mlkro, 0, m, &cVar_ri8Mlkro_sendMessage);
}

void Heavy_SoundScraper::cSend_iTLiBS0o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cSend_E10hMhg1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_lxIjFjfC_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_ljBcdP4e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 25.0f);
  cSend_iTLiBS0o_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_rysE6euh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 4000.0f);
  cSend_E10hMhg1_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_8utf7ED4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_cONpp1hQ_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_I2VFb2kW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSend_8utf7ED4_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_d0pQpExF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cSend_ya8nYagu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_lxIjFjfC_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_BW4UYQ0I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_cONpp1hQ_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_GsAcT1IB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 25.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_OTTrIrh4, 0, m, NULL);
}

void Heavy_SoundScraper::cMsg_HpKZm6sH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 0);
  sLine_onMessage(_c, &Context(_c)->sLine_OTTrIrh4, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_iMS5EPPw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_01oBirK5, 1, m, &cVar_01oBirK5_sendMessage);
}

void Heavy_SoundScraper::cCast_cjUqswMa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_CKz4pb4A_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_SoQsaDtl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_GsAcT1IB_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_D6etWM05_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_cWfcNRWL, 0, m, &cSlice_cWfcNRWL_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cVar_bBqSfWKO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_L8iMj0NE_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSystem_CCT6BbGJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 2.0f, 0, m, &cBinop_LIqVuy9c_sendMessage);
}

void Heavy_SoundScraper::cBinop_LIqVuy9c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_Wy3LrshP, m);
}

void Heavy_SoundScraper::cMsg_L8iMj0NE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_CCT6BbGJ_sendMessage);
}

void Heavy_SoundScraper::cSlice_cWfcNRWL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sTabread_onMessage(_c, &Context(_c)->sTabread_SFqZFvrg, 1, m, NULL);
      sTabread_onMessage(_c, &Context(_c)->sTabread_PElgroJl, 1, m, NULL);
      cVar_onMessage(_c, &Context(_c)->cVar_bBqSfWKO, 0, m, &cVar_bBqSfWKO_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cVar_Jg2pMQjT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_e71LtL8n, 0, m, &cPack_e71LtL8n_sendMessage);
}

void Heavy_SoundScraper::cVar_EUs9TnFw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 10000000.0f, 0, m, &cBinop_jg2TAgsW_sendMessage);
}

void Heavy_SoundScraper::cIf_Kuji9Nec_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_ABS, m, &cUnop_dzSuVEpR_sendMessage);
      break;
    }
    case 1: {
      cVar_onMessage(_c, &Context(_c)->cVar_EUs9TnFw, 1, m, &cVar_EUs9TnFw_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_DN6B6to5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_Kuji9Nec, 1, m, &cIf_Kuji9Nec_sendMessage);
}

void Heavy_SoundScraper::cVar_5zPInNvG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 10000000.0f, 0, m, &cBinop_FiuFBsN6_sendMessage);
}

void Heavy_SoundScraper::cUnop_dzSuVEpR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_5zPInNvG, 1, m, &cVar_5zPInNvG_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_dJZdC6BX_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_WwV0irpf_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_cTjzjhVR_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_WwV0irpf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_EUs9TnFw, 0, m, &cVar_EUs9TnFw_sendMessage);
}

void Heavy_SoundScraper::cCast_cTjzjhVR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_5zPInNvG, 0, m, &cVar_5zPInNvG_sendMessage);
}

void Heavy_SoundScraper::cVar_Uib05Tbx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_LESS_THAN, 0.0f, 0, m, &cBinop_sw4kBUOG_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_kd3JJU0K_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_BbSsjcyw_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_BbSsjcyw_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_bzT6UMTk, 1, m, &cDelay_bzT6UMTk_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_DObzncCl_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cDelay_bzT6UMTk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_bzT6UMTk, m);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_smoSlZ3v_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_UYCTkOoZ_sendMessage);
}

void Heavy_SoundScraper::cMsg_BbSsjcyw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_bzT6UMTk, 0, m, &cDelay_bzT6UMTk_sendMessage);
}

void Heavy_SoundScraper::cCast_DObzncCl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_bzT6UMTk, 0, m, &cDelay_bzT6UMTk_sendMessage);
}

void Heavy_SoundScraper::cPack_2LI1XrBL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_DiwHTRTe_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_dbmT6dxw_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Z3Vdsunx_sendMessage);
      break;
    }
    default: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_ZFKHNyoD, HV_BINOP_SUBTRACT, 0, m, &cBinop_ZFKHNyoD_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_Z3Vdsunx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_nFTGRlZd_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_DMEpzcoC_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_JeBeR9RL_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_JeBeR9RL_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_hd7gJTKL, 1, m, &cDelay_hd7gJTKL_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_nNA8rcDG_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cDelay_hd7gJTKL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_hd7gJTKL, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_IFjT9q72_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_BWR5TOrB_sendMessage);
}

void Heavy_SoundScraper::cMsg_JeBeR9RL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_hd7gJTKL, 0, m, &cDelay_hd7gJTKL_sendMessage);
}

void Heavy_SoundScraper::cCast_nNA8rcDG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_hd7gJTKL, 0, m, &cDelay_hd7gJTKL_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_JRzk5Rja_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_DW3N4yvS_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_DW3N4yvS_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_KjddI1gI, 1, m, &cDelay_KjddI1gI_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_oPH5eIQN_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cDelay_KjddI1gI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_KjddI1gI, m);
}

void Heavy_SoundScraper::cMsg_DW3N4yvS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_KjddI1gI, 0, m, &cDelay_KjddI1gI_sendMessage);
}

void Heavy_SoundScraper::cCast_oPH5eIQN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_KjddI1gI, 0, m, &cDelay_KjddI1gI_sendMessage);
}

void Heavy_SoundScraper::cPack_tDLqCbb7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_VhZyvvBn_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_saxqacrc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_BSZQOYEm_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_Xc7ntLVj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_00wVvWVf_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_a8j5Q2lF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_STcsu9K9, HV_BINOP_DIVIDE, 1, m, &cBinop_STcsu9K9_sendMessage);
}

void Heavy_SoundScraper::cVar_kFdErUcA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_STcsu9K9, HV_BINOP_DIVIDE, 0, m, &cBinop_STcsu9K9_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_E0u6z9qo_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0xFFFFFFFF: { // "bang"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_yI2RkZVA_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Xh32XCyX_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Qoke9SWQ_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_4Dd96fQe_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_Xh32XCyX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_kFdErUcA, 0, m, &cVar_kFdErUcA_sendMessage);
}

void Heavy_SoundScraper::cCast_yI2RkZVA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_a8j5Q2lF, 0, m, &cVar_a8j5Q2lF_sendMessage);
}

void Heavy_SoundScraper::cCast_Qoke9SWQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_a8j5Q2lF, 0, m, &cVar_a8j5Q2lF_sendMessage);
}

void Heavy_SoundScraper::cCast_4Dd96fQe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_kFdErUcA, 0, m, &cVar_kFdErUcA_sendMessage);
}

void Heavy_SoundScraper::cPack_e71LtL8n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_lrX8bQKT_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSlice_gfM9Wn8z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cPack_onMessage(_c, &Context(_c)->cPack_2LI1XrBL, 1, m, &cPack_2LI1XrBL_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_h2HrXCon_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_SwrbOnAU, HV_BINOP_ADD, 0, m, &cBinop_SwrbOnAU_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_We5PIwMt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cPack_onMessage(_c, &Context(_c)->cPack_tDLqCbb7, 1, m, &cPack_tDLqCbb7_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_ErslUNmy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_M1lRMp2G, HV_BINOP_ADD, 0, m, &cBinop_M1lRMp2G_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cPack_brY9h3Vd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_yzMJeuHB_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_RekycmzL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_uWxPNJzX_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_UYCTkOoZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Jg2pMQjT, 0, m, &cVar_Jg2pMQjT_sendMessage);
}

void Heavy_SoundScraper::cCast_smoSlZ3v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Uib05Tbx, 0, m, &cVar_Uib05Tbx_sendMessage);
}

void Heavy_SoundScraper::cSend_DiwHTRTe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_mc6V2H4k_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_lrX8bQKT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_1QZjeYxp_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_BSZQOYEm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_1QZjeYxp_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_3kVwQgee_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_kd3JJU0K_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_9IS3kyaM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_saxqacrc, 0, m, &cPack_saxqacrc_sendMessage);
}

void Heavy_SoundScraper::cBinop_jg2TAgsW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_brY9h3Vd, 0, m, &cPack_brY9h3Vd_sendMessage);
}

void Heavy_SoundScraper::cSend_VhZyvvBn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_mc6V2H4k_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_FiuFBsN6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_RekycmzL, 0, m, &cPack_RekycmzL_sendMessage);
}

void Heavy_SoundScraper::cBinop_sw4kBUOG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_dJZdC6BX_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_SwrbOnAU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_2LI1XrBL, 0, m, &cPack_2LI1XrBL_sendMessage);
}

void Heavy_SoundScraper::cBinop_ZFKHNyoD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_DMEpzcoC_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_M1lRMp2G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_tDLqCbb7, 0, m, &cPack_tDLqCbb7_sendMessage);
}

void Heavy_SoundScraper::cMsg_nFTGRlZd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "stop");
  cSwitchcase_DMEpzcoC_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_MAzjvveK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_01IlQV3w, HV_BINOP_MULTIPLY, 1, m, &cBinop_01IlQV3w_sendMessage);
}

void Heavy_SoundScraper::cMsg_uWxPNJzX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 0.0f);
  cSlice_onMessage(_c, &Context(_c)->cSlice_We5PIwMt, 0, m, &cSlice_We5PIwMt_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_ErslUNmy, 0, m, &cSlice_ErslUNmy_sendMessage);
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 1);
  msg_setElementToFrom(m, 1, n, 0);
  cSlice_onMessage(_c, &Context(_c)->cSlice_We5PIwMt, 0, m, &cSlice_We5PIwMt_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_ErslUNmy, 0, m, &cSlice_ErslUNmy_sendMessage);
}

void Heavy_SoundScraper::cBinop_KcwP8wyh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_RekycmzL, 1, m, &cPack_RekycmzL_sendMessage);
}

void Heavy_SoundScraper::cBinop_090Av5Xi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_brY9h3Vd, 1, m, &cPack_brY9h3Vd_sendMessage);
}

void Heavy_SoundScraper::cMsg_yzMJeuHB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 0.0f);
  cSlice_onMessage(_c, &Context(_c)->cSlice_gfM9Wn8z, 0, m, &cSlice_gfM9Wn8z_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_h2HrXCon, 0, m, &cSlice_h2HrXCon_sendMessage);
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 1);
  msg_setElementToFrom(m, 1, n, 0);
  cSlice_onMessage(_c, &Context(_c)->cSlice_gfM9Wn8z, 0, m, &cSlice_gfM9Wn8z_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_h2HrXCon, 0, m, &cSlice_h2HrXCon_sendMessage);
}

void Heavy_SoundScraper::cSend_00wVvWVf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_1QZjeYxp_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_STcsu9K9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 0.0f, 0, m, &cBinop_DN6B6to5_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_Kuji9Nec, 0, m, &cIf_Kuji9Nec_sendMessage);
}

void Heavy_SoundScraper::cCast_uYEucu0t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_saxqacrc, 1, m, &cPack_saxqacrc_sendMessage);
}

void Heavy_SoundScraper::cCast_iBOwR4tj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_bzT6UMTk, 1, m, &cDelay_bzT6UMTk_sendMessage);
}

void Heavy_SoundScraper::cCast_F2OkpW6z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_M1lRMp2G, HV_BINOP_ADD, 1, m, &cBinop_M1lRMp2G_sendMessage);
}

void Heavy_SoundScraper::cCast_mI8wCagh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_SwrbOnAU, HV_BINOP_ADD, 1, m, &cBinop_SwrbOnAU_sendMessage);
}

void Heavy_SoundScraper::cCast_8Yqv9hjG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_KjddI1gI, 1, m, &cDelay_KjddI1gI_sendMessage);
}

void Heavy_SoundScraper::cCast_EfcpNhue_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ZFKHNyoD, HV_BINOP_SUBTRACT, 1, m, &cBinop_ZFKHNyoD_sendMessage);
}

void Heavy_SoundScraper::cCast_IFjT9q72_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_JRzk5Rja_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_BWR5TOrB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_Xc7ntLVj, 0, m, &cPack_Xc7ntLVj_sendMessage);
}

void Heavy_SoundScraper::cCast_R45vGCiq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_JRzk5Rja_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_di7FJ4kt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_DMEpzcoC_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_01IlQV3w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_F2OkpW6z_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_mI8wCagh_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_kieAY7ZH_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_7H5FGQXc_sendMessage);
      break;
    }
    default: {
      cVar_onMessage(_c, &Context(_c)->cVar_Jg2pMQjT, 1, m, &cVar_Jg2pMQjT_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_7H5FGQXc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ip5XZKuX_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_pjA5x5MH_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_pj2DXXFY_sendMessage);
      break;
    }
    default: {
      cSwitchcase_E0u6z9qo_onMessage(_c, NULL, 0, m, NULL);
      cVar_onMessage(_c, &Context(_c)->cVar_Uib05Tbx, 1, m, &cVar_Uib05Tbx_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_pj2DXXFY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_6eyVYYIc_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSlice_ApCCvTmv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_Gecb1JWl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSwitchcase_dbmT6dxw_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_qJohb2H1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_01IlQV3w, HV_BINOP_MULTIPLY, 0, m, &cBinop_01IlQV3w_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_AC2tscxo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSwitchcase_pjA5x5MH_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_FOyQBVtx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_Mh6QYJvP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSwitchcase_kieAY7ZH_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cMsg_ip5XZKuX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_Jg2pMQjT, 1, m, &cVar_Jg2pMQjT_sendMessage);
}

void Heavy_SoundScraper::cCast_TCo8br93_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_AildFclo_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_6eyVYYIc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_E0u6z9qo_onMessage(_c, NULL, 0, m, NULL);
  cVar_onMessage(_c, &Context(_c)->cVar_Uib05Tbx, 1, m, &cVar_Uib05Tbx_sendMessage);
}

void Heavy_SoundScraper::cMsg_AildFclo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(6);
  msg_init(m, 6, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setSymbol(m, 1, "xylo");
  msg_setFloat(m, 2, 1.0f);
  msg_setFloat(m, 3, 0.0f);
  msg_setFloat(m, 4, 0.0f);
  msg_setFloat(m, 5, 0.0f);
  cSlice_onMessage(_c, &Context(_c)->cSlice_ApCCvTmv, 0, m, &cSlice_ApCCvTmv_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_Gecb1JWl, 0, m, &cSlice_Gecb1JWl_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_qJohb2H1, 0, m, &cSlice_qJohb2H1_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_AC2tscxo, 0, m, &cSlice_AC2tscxo_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_FOyQBVtx, 0, m, &cSlice_FOyQBVtx_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_Mh6QYJvP, 0, m, &cSlice_Mh6QYJvP_sendMessage);
}

void Heavy_SoundScraper::cSlice_4j5ABp08_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_t39QU9Kq_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_TZCgvfl0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_JJN9Iyud_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_JJN9Iyud_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_DQFTJKIw_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_DQFTJKIw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_E5r1whBf_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_t39QU9Kq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_kChtnOqJ_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_kChtnOqJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_1B2ZmZT2_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_2SSaZdHB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_aHLli7Fv_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_qzZXuj4B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_zX7PUf0O, HV_BINOP_MULTIPLY, 1, m, &cBinop_zX7PUf0O_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_WhLCFLiN, HV_BINOP_MULTIPLY, 1, m, &cBinop_WhLCFLiN_sendMessage);
}

void Heavy_SoundScraper::cSlice_xJ1bCm3v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_zX7PUf0O, HV_BINOP_MULTIPLY, 0, m, &cBinop_zX7PUf0O_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_ZgHgt0SM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_WhLCFLiN, HV_BINOP_MULTIPLY, 0, m, &cBinop_WhLCFLiN_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cMsg_aHLli7Fv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setElementToFrom(m, 2, n, 1);
  cMsg_AKG5DAF6_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_AKG5DAF6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 441000000.0f);
  msg_setFloat(m, 1, 10000000.0f);
}

void Heavy_SoundScraper::cBinop_zX7PUf0O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_2SSaZdHB, 1, m, &cPack_2SSaZdHB_sendMessage);
}

void Heavy_SoundScraper::cBinop_WhLCFLiN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_2SSaZdHB, 0, m, &cPack_2SSaZdHB_sendMessage);
}

void Heavy_SoundScraper::cMsg_rdEZV317_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 44100.0f);
  msg_setFloat(m, 1, 1000.0f);
  cSlice_onMessage(_c, &Context(_c)->cSlice_xJ1bCm3v, 0, m, &cSlice_xJ1bCm3v_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_ZgHgt0SM, 0, m, &cSlice_ZgHgt0SM_sendMessage);
}

void Heavy_SoundScraper::cSend_IoxlzFE9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_5G6xqCtZ_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_nzLptggo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 1);
  cSwitchcase_D6etWM05_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cSlice_IurT5bZ5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 127.0f, 0, m, &cBinop_cRvMyExT_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_fgHdAuc2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_QKusRqbu_sendMessage);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_wwYakmut_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cVar_lUbzbGRo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_rYDTbRQU, 1, m, &cPack_rYDTbRQU_sendMessage);
}

void Heavy_SoundScraper::cVar_CrxWVgiL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_rYDTbRQU, 0, m, &cPack_rYDTbRQU_sendMessage);
}

void Heavy_SoundScraper::cPack_rYDTbRQU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_R8ySlUvA_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ilNHzo4d_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_TCo8br93_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_ApCCvTmv, 0, m, &cSlice_ApCCvTmv_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_Gecb1JWl, 0, m, &cSlice_Gecb1JWl_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_qJohb2H1, 0, m, &cSlice_qJohb2H1_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_AC2tscxo, 0, m, &cSlice_AC2tscxo_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_FOyQBVtx, 0, m, &cSlice_FOyQBVtx_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_Mh6QYJvP, 0, m, &cSlice_Mh6QYJvP_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_9IS3kyaM_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_3kVwQgee_sendMessage);
  cMsg_nzLptggo_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_yKbNqJId_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_rYDTbRQU, 2, m, &cPack_rYDTbRQU_sendMessage);
}

void Heavy_SoundScraper::cCast_Rug44MLc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_CrxWVgiL, 0, m, &cVar_CrxWVgiL_sendMessage);
}

void Heavy_SoundScraper::cCast_gm3zXiJ0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_lUbzbGRo, 0, m, &cVar_lUbzbGRo_sendMessage);
}

void Heavy_SoundScraper::cBinop_Tie3kjDG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.4f, 0, m, &cBinop_TIEZx3CC_sendMessage);
}

void Heavy_SoundScraper::cBinop_TIEZx3CC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_XcAkTQed_sendMessage);
}

void Heavy_SoundScraper::cBinop_cRvMyExT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_1LSb65pm_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_MC3HYsYt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_yKbNqJId_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_gm3zXiJ0_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Rug44MLc_sendMessage);
}

void Heavy_SoundScraper::cBinop_C6zjyhoY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.99f, 0, m, &cBinop_L02humqK_sendMessage);
}

void Heavy_SoundScraper::cBinop_L02humqK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MC3HYsYt, HV_BINOP_MULTIPLY, 1, m, &cBinop_MC3HYsYt_sendMessage);
}

void Heavy_SoundScraper::cCast_QKusRqbu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_7qysyEk6_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_ilNHzo4d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_acszxk8b_sendMessage);
}

void Heavy_SoundScraper::cCast_R8ySlUvA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_AA6If2A8_onMessage(_c, NULL, 0, m, NULL);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_tBhfBFU6_sendMessage);
}

void Heavy_SoundScraper::cSend_o45Vw17R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_riILnXBB_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_ME5gEDap_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_BGcziFMq_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_rTqbfmim_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MC3HYsYt, HV_BINOP_MULTIPLY, 0, m, &cBinop_MC3HYsYt_sendMessage);
}

void Heavy_SoundScraper::cSend_1LSb65pm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_WFssAnEw_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_DPxKgyTY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 44100.0f);
  cSend_IoxlzFE9_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_J6aJLHkU_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_6JVmCgFk, 0, m, &cSlice_6JVmCgFk_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_k6ysHC47, 0, m, &cRandom_k6ysHC47_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_KD1X7fQi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_43tT33d2_sendMessage);
}

void Heavy_SoundScraper::cUnop_43tT33d2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_NjvVkH01_sendMessage);
}

void Heavy_SoundScraper::cRandom_k6ysHC47_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_KD1X7fQi_sendMessage);
}

void Heavy_SoundScraper::cSlice_6JVmCgFk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_k6ysHC47, 1, m, &cRandom_k6ysHC47_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_rE4lINgV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_HyY3IW42, HV_BINOP_DIVIDE, 0, m, &cBinop_HyY3IW42_sendMessage);
}

void Heavy_SoundScraper::cBinop_68XRnf33_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_gISV8dki_sendMessage);
}

void Heavy_SoundScraper::cBinop_gISV8dki_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_5wRphlpC, HV_BINOP_POW, 1, m, &cBinop_5wRphlpC_sendMessage);
  cMsg_Zo4XpRlA_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_5wRphlpC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_rE4lINgV_sendMessage);
}

void Heavy_SoundScraper::cMsg_Zo4XpRlA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_5wRphlpC, HV_BINOP_POW, 0, m, &cBinop_5wRphlpC_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_n4rBqBka_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_dmjYQP45, 0, m, &cSlice_dmjYQP45_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_Ph0zdZnV, 0, m, &cRandom_Ph0zdZnV_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_BYuW3YaF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_x6O5QTOc_sendMessage);
}

void Heavy_SoundScraper::cUnop_x6O5QTOc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_CiceS2Au_sendMessage);
}

void Heavy_SoundScraper::cRandom_Ph0zdZnV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 15.0f, 0, m, &cBinop_BYuW3YaF_sendMessage);
}

void Heavy_SoundScraper::cSlice_dmjYQP45_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_Ph0zdZnV, 1, m, &cRandom_Ph0zdZnV_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_lMwK2PDu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSend_wK0KaMBI_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_qFnkX7kz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSend_luBC76gn_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cUnop_JAlN24YM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_iFqNXbf1, 0, m, &cPack_iFqNXbf1_sendMessage);
}

void Heavy_SoundScraper::cUnop_951KgDcO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_yuVyzJT2, 0, m, &cPack_yuVyzJT2_sendMessage);
}

void Heavy_SoundScraper::cPack_yuVyzJT2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_MJbLJ0NW, 0, m, NULL);
}

void Heavy_SoundScraper::cPack_iFqNXbf1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_T6lK4JNJ, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_awN0ltpe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_JAlN24YM_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_SIN, m, &cUnop_951KgDcO_sendMessage);
}

void Heavy_SoundScraper::cMsg_XMvlwh2w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.5f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_awN0ltpe_sendMessage);
}

void Heavy_SoundScraper::cCast_b1UQ0qQX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cVar_WufKUwGz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Pb7ErQK8_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ms9B4Y9r_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_QJIBN5FZ_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_5eNy6v57_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_al4jjmfw_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_al4jjmfw_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_Nk57QC6V, 1, m, &cDelay_Nk57QC6V_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_wZplQEdB_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cDelay_Nk57QC6V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Nk57QC6V, m);
  cVar_onMessage(_c, &Context(_c)->cVar_lixryVfh, 0, m, &cVar_lixryVfh_sendMessage);
}

void Heavy_SoundScraper::cMsg_al4jjmfw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_Nk57QC6V, 0, m, &cDelay_Nk57QC6V_sendMessage);
}

void Heavy_SoundScraper::cCast_wZplQEdB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Nk57QC6V, 0, m, &cDelay_Nk57QC6V_sendMessage);
}

void Heavy_SoundScraper::cVar_lixryVfh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Gwqe3pQZ_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_Wc8DGzbU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_WufKUwGz, 0, m, &cVar_WufKUwGz_sendMessage);
}

void Heavy_SoundScraper::cSend_cp4kAIpn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cSend_TXkFyLft_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_kI7qPxx1_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_uGHMY7qM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 25.0f);
  cSend_cp4kAIpn_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_B0C1W80G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 4000.0f);
  cSend_TXkFyLft_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_xyIMxax2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_8q0BecEz_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_UivV2UUt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSend_xyIMxax2_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_yQOMVb3z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cSend_mVbHJTA6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_kI7qPxx1_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_MluF9AF8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_8q0BecEz_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_yWSxijxW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 25.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_GiixFRac, 0, m, NULL);
}

void Heavy_SoundScraper::cMsg_Gwqe3pQZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 0);
  sLine_onMessage(_c, &Context(_c)->sLine_GiixFRac, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_ms9B4Y9r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_lixryVfh, 1, m, &cVar_lixryVfh_sendMessage);
}

void Heavy_SoundScraper::cCast_Pb7ErQK8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_yWSxijxW_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_QJIBN5FZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_5eNy6v57_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cSwitchcase_p9X3Ivee_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_KeVHo4Er, 0, m, &cSlice_KeVHo4Er_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cVar_nef6V9QF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_vkTZlPU6_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSystem_FQLN4DfO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 2.0f, 0, m, &cBinop_2x1WYbTL_sendMessage);
}

void Heavy_SoundScraper::cBinop_2x1WYbTL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_YRzOT6qX, m);
}

void Heavy_SoundScraper::cMsg_vkTZlPU6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_FQLN4DfO_sendMessage);
}

void Heavy_SoundScraper::cSlice_KeVHo4Er_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sTabread_onMessage(_c, &Context(_c)->sTabread_ma6MgTzX, 1, m, NULL);
      sTabread_onMessage(_c, &Context(_c)->sTabread_TgEMkHGs, 1, m, NULL);
      cVar_onMessage(_c, &Context(_c)->cVar_nef6V9QF, 0, m, &cVar_nef6V9QF_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cVar_WHqQWP4a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_ylsFMtrD, 0, m, &cPack_ylsFMtrD_sendMessage);
}

void Heavy_SoundScraper::cVar_CreoyV6G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 10000000.0f, 0, m, &cBinop_yMADbQ5v_sendMessage);
}

void Heavy_SoundScraper::cIf_NeigteuQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_ABS, m, &cUnop_KMShEJis_sendMessage);
      break;
    }
    case 1: {
      cVar_onMessage(_c, &Context(_c)->cVar_CreoyV6G, 1, m, &cVar_CreoyV6G_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_lhA0kVCb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_NeigteuQ, 1, m, &cIf_NeigteuQ_sendMessage);
}

void Heavy_SoundScraper::cVar_gDYtbDXY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 10000000.0f, 0, m, &cBinop_6ecttKse_sendMessage);
}

void Heavy_SoundScraper::cUnop_KMShEJis_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_gDYtbDXY, 1, m, &cVar_gDYtbDXY_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_awzVWdK7_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ap0Uamfl_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_7doNB8Pm_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_ap0Uamfl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_CreoyV6G, 0, m, &cVar_CreoyV6G_sendMessage);
}

void Heavy_SoundScraper::cCast_7doNB8Pm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_gDYtbDXY, 0, m, &cVar_gDYtbDXY_sendMessage);
}

void Heavy_SoundScraper::cVar_vcqW9VRG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_LESS_THAN, 0.0f, 0, m, &cBinop_KGz1X2Lt_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_igKvECrU_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_xVLMNaof_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_xVLMNaof_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_Lmic2ooA, 1, m, &cDelay_Lmic2ooA_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_3iaRl40V_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cDelay_Lmic2ooA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Lmic2ooA, m);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_eAoNOp4S_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_JqreUGqR_sendMessage);
}

void Heavy_SoundScraper::cMsg_xVLMNaof_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_Lmic2ooA, 0, m, &cDelay_Lmic2ooA_sendMessage);
}

void Heavy_SoundScraper::cCast_3iaRl40V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Lmic2ooA, 0, m, &cDelay_Lmic2ooA_sendMessage);
}

void Heavy_SoundScraper::cPack_Cj80grqU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_uB1DiQa0_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_fVtlTLTa_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_KQbq0rim_sendMessage);
      break;
    }
    default: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_k7e4Sxkz, HV_BINOP_SUBTRACT, 0, m, &cBinop_k7e4Sxkz_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_KQbq0rim_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_KudvcsX9_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_ruVtFkAW_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_WBgl8VDS_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_WBgl8VDS_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_GUp7YJYT, 1, m, &cDelay_GUp7YJYT_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_n2EmyAng_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cDelay_GUp7YJYT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_GUp7YJYT, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_TMphQOMW_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_LP6ugaDB_sendMessage);
}

void Heavy_SoundScraper::cMsg_WBgl8VDS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_GUp7YJYT, 0, m, &cDelay_GUp7YJYT_sendMessage);
}

void Heavy_SoundScraper::cCast_n2EmyAng_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_GUp7YJYT, 0, m, &cDelay_GUp7YJYT_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_HAFAAoyq_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_CabmTWM6_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_CabmTWM6_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_z81SmhBk, 1, m, &cDelay_z81SmhBk_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_l62QLXLg_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cDelay_z81SmhBk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_z81SmhBk, m);
}

void Heavy_SoundScraper::cMsg_CabmTWM6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_z81SmhBk, 0, m, &cDelay_z81SmhBk_sendMessage);
}

void Heavy_SoundScraper::cCast_l62QLXLg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_z81SmhBk, 0, m, &cDelay_z81SmhBk_sendMessage);
}

void Heavy_SoundScraper::cPack_Axd1f9xo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_8YlpZQGD_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_12k9YW6T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_H3t6cTtq_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_Bdzaz865_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_Vticj5pW_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_DIotbER9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_X4qcjLwl, HV_BINOP_DIVIDE, 1, m, &cBinop_X4qcjLwl_sendMessage);
}

void Heavy_SoundScraper::cVar_2ZHP8BLm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_X4qcjLwl, HV_BINOP_DIVIDE, 0, m, &cBinop_X4qcjLwl_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_pKYPFSXB_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0xFFFFFFFF: { // "bang"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_HyBeWN7K_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_yHI8ajMA_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_mO8exvoO_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Mvej8e8h_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_HyBeWN7K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_DIotbER9, 0, m, &cVar_DIotbER9_sendMessage);
}

void Heavy_SoundScraper::cCast_yHI8ajMA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_2ZHP8BLm, 0, m, &cVar_2ZHP8BLm_sendMessage);
}

void Heavy_SoundScraper::cCast_mO8exvoO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_DIotbER9, 0, m, &cVar_DIotbER9_sendMessage);
}

void Heavy_SoundScraper::cCast_Mvej8e8h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_2ZHP8BLm, 0, m, &cVar_2ZHP8BLm_sendMessage);
}

void Heavy_SoundScraper::cPack_ylsFMtrD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_w3LQF7BV_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSlice_MaNR8zbS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cPack_onMessage(_c, &Context(_c)->cPack_Cj80grqU, 1, m, &cPack_Cj80grqU_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_2spbwqzH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_XJgk42Pm, HV_BINOP_ADD, 0, m, &cBinop_XJgk42Pm_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_QHEmzThe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cPack_onMessage(_c, &Context(_c)->cPack_Axd1f9xo, 1, m, &cPack_Axd1f9xo_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_K6hoWwlY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_zrQXZfgl, HV_BINOP_ADD, 0, m, &cBinop_zrQXZfgl_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cPack_RVnqtGla_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_54AAU24T_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_Ssvku24h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_MfY8Cwfl_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_eAoNOp4S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_vcqW9VRG, 0, m, &cVar_vcqW9VRG_sendMessage);
}

void Heavy_SoundScraper::cCast_JqreUGqR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_WHqQWP4a, 0, m, &cVar_WHqQWP4a_sendMessage);
}

void Heavy_SoundScraper::cSend_uB1DiQa0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_N2sXvvqu_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_w3LQF7BV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_awHHteN2_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_H3t6cTtq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_awHHteN2_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_AjJ1HhPt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_igKvECrU_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_0p8kwpfX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_12k9YW6T, 0, m, &cPack_12k9YW6T_sendMessage);
}

void Heavy_SoundScraper::cBinop_yMADbQ5v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_RVnqtGla, 0, m, &cPack_RVnqtGla_sendMessage);
}

void Heavy_SoundScraper::cSend_8YlpZQGD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_N2sXvvqu_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_6ecttKse_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_Ssvku24h, 0, m, &cPack_Ssvku24h_sendMessage);
}

void Heavy_SoundScraper::cBinop_KGz1X2Lt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_awzVWdK7_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_XJgk42Pm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_Cj80grqU, 0, m, &cPack_Cj80grqU_sendMessage);
}

void Heavy_SoundScraper::cBinop_k7e4Sxkz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_ruVtFkAW_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_zrQXZfgl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_Axd1f9xo, 0, m, &cPack_Axd1f9xo_sendMessage);
}

void Heavy_SoundScraper::cMsg_KudvcsX9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "stop");
  cSwitchcase_ruVtFkAW_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_U6QqNqIa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_xeThoO0o, HV_BINOP_MULTIPLY, 1, m, &cBinop_xeThoO0o_sendMessage);
}

void Heavy_SoundScraper::cMsg_MfY8Cwfl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 0.0f);
  cSlice_onMessage(_c, &Context(_c)->cSlice_QHEmzThe, 0, m, &cSlice_QHEmzThe_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_K6hoWwlY, 0, m, &cSlice_K6hoWwlY_sendMessage);
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 1);
  msg_setElementToFrom(m, 1, n, 0);
  cSlice_onMessage(_c, &Context(_c)->cSlice_QHEmzThe, 0, m, &cSlice_QHEmzThe_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_K6hoWwlY, 0, m, &cSlice_K6hoWwlY_sendMessage);
}

void Heavy_SoundScraper::cBinop_r6EjDZGZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_Ssvku24h, 1, m, &cPack_Ssvku24h_sendMessage);
}

void Heavy_SoundScraper::cBinop_gsggKc9F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_RVnqtGla, 1, m, &cPack_RVnqtGla_sendMessage);
}

void Heavy_SoundScraper::cMsg_54AAU24T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 0.0f);
  cSlice_onMessage(_c, &Context(_c)->cSlice_MaNR8zbS, 0, m, &cSlice_MaNR8zbS_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_2spbwqzH, 0, m, &cSlice_2spbwqzH_sendMessage);
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 1);
  msg_setElementToFrom(m, 1, n, 0);
  cSlice_onMessage(_c, &Context(_c)->cSlice_MaNR8zbS, 0, m, &cSlice_MaNR8zbS_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_2spbwqzH, 0, m, &cSlice_2spbwqzH_sendMessage);
}

void Heavy_SoundScraper::cSend_Vticj5pW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_awHHteN2_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_X4qcjLwl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 0.0f, 0, m, &cBinop_lhA0kVCb_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_NeigteuQ, 0, m, &cIf_NeigteuQ_sendMessage);
}

void Heavy_SoundScraper::cCast_dvnwC4q3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_12k9YW6T, 1, m, &cPack_12k9YW6T_sendMessage);
}

void Heavy_SoundScraper::cCast_SDp37AW3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Lmic2ooA, 1, m, &cDelay_Lmic2ooA_sendMessage);
}

void Heavy_SoundScraper::cCast_hzWa06Nr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_XJgk42Pm, HV_BINOP_ADD, 1, m, &cBinop_XJgk42Pm_sendMessage);
}

void Heavy_SoundScraper::cCast_bYahBlQD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_zrQXZfgl, HV_BINOP_ADD, 1, m, &cBinop_zrQXZfgl_sendMessage);
}

void Heavy_SoundScraper::cCast_wBN9k0lw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_k7e4Sxkz, HV_BINOP_SUBTRACT, 1, m, &cBinop_k7e4Sxkz_sendMessage);
}

void Heavy_SoundScraper::cCast_fvo4NoPN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_z81SmhBk, 1, m, &cDelay_z81SmhBk_sendMessage);
}

void Heavy_SoundScraper::cCast_LP6ugaDB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_Bdzaz865, 0, m, &cPack_Bdzaz865_sendMessage);
}

void Heavy_SoundScraper::cCast_TMphQOMW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_HAFAAoyq_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_dkrY6O6K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_ruVtFkAW_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_xnP9nnTQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_HAFAAoyq_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_xeThoO0o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_bYahBlQD_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_hzWa06Nr_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_h7RoIv6B_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ALEfY39T_sendMessage);
      break;
    }
    default: {
      cVar_onMessage(_c, &Context(_c)->cVar_WHqQWP4a, 1, m, &cVar_WHqQWP4a_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_ALEfY39T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_jezkOqO2_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_xX5M6Smw_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_wDfI48Rn_sendMessage);
      break;
    }
    default: {
      cSwitchcase_pKYPFSXB_onMessage(_c, NULL, 0, m, NULL);
      cVar_onMessage(_c, &Context(_c)->cVar_vcqW9VRG, 1, m, &cVar_vcqW9VRG_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_wDfI48Rn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Y7LsHHbU_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSlice_rksI0agz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_qyKmCgQ8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSwitchcase_fVtlTLTa_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_QS4zRMck_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_xeThoO0o, HV_BINOP_MULTIPLY, 0, m, &cBinop_xeThoO0o_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_NC8HPd9e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSwitchcase_xX5M6Smw_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_XXXCOwuJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_Ul0Jseam_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSwitchcase_h7RoIv6B_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cMsg_jezkOqO2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_WHqQWP4a, 1, m, &cVar_WHqQWP4a_sendMessage);
}

void Heavy_SoundScraper::cCast_bLIpqj1c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_gsUWuA19_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_Y7LsHHbU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_pKYPFSXB_onMessage(_c, NULL, 0, m, NULL);
  cVar_onMessage(_c, &Context(_c)->cVar_vcqW9VRG, 1, m, &cVar_vcqW9VRG_sendMessage);
}

void Heavy_SoundScraper::cMsg_gsUWuA19_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(6);
  msg_init(m, 6, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setSymbol(m, 1, "xylo");
  msg_setFloat(m, 2, 1.0f);
  msg_setFloat(m, 3, 0.0f);
  msg_setFloat(m, 4, 0.0f);
  msg_setFloat(m, 5, 0.0f);
  cSlice_onMessage(_c, &Context(_c)->cSlice_rksI0agz, 0, m, &cSlice_rksI0agz_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_qyKmCgQ8, 0, m, &cSlice_qyKmCgQ8_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_QS4zRMck, 0, m, &cSlice_QS4zRMck_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_NC8HPd9e, 0, m, &cSlice_NC8HPd9e_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_XXXCOwuJ, 0, m, &cSlice_XXXCOwuJ_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_Ul0Jseam, 0, m, &cSlice_Ul0Jseam_sendMessage);
}

void Heavy_SoundScraper::cSlice_DiMOISKG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_PLs9K6nq_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_do7zs6km_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_6XE1hbcX_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_6XE1hbcX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_cBUAy3Mc_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_cBUAy3Mc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_E1SWCp1C_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_PLs9K6nq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_gR0okRl2_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_gR0okRl2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_X1vh0qHw_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_jZJkPY3i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_jrZlACxK_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_JGFOHNCS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_GGSlXK5F, HV_BINOP_MULTIPLY, 1, m, &cBinop_GGSlXK5F_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_nNU1opL1, HV_BINOP_MULTIPLY, 1, m, &cBinop_nNU1opL1_sendMessage);
}

void Heavy_SoundScraper::cSlice_El2PdRjP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_GGSlXK5F, HV_BINOP_MULTIPLY, 0, m, &cBinop_GGSlXK5F_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_C5k0PNmq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_nNU1opL1, HV_BINOP_MULTIPLY, 0, m, &cBinop_nNU1opL1_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cMsg_jrZlACxK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setElementToFrom(m, 2, n, 1);
  cMsg_CZ6v0Olv_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_CZ6v0Olv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 441000000.0f);
  msg_setFloat(m, 1, 10000000.0f);
}

void Heavy_SoundScraper::cBinop_GGSlXK5F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_jZJkPY3i, 1, m, &cPack_jZJkPY3i_sendMessage);
}

void Heavy_SoundScraper::cBinop_nNU1opL1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_jZJkPY3i, 0, m, &cPack_jZJkPY3i_sendMessage);
}

void Heavy_SoundScraper::cMsg_tPO6DOMV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 44100.0f);
  msg_setFloat(m, 1, 1000.0f);
  cSlice_onMessage(_c, &Context(_c)->cSlice_El2PdRjP, 0, m, &cSlice_El2PdRjP_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_C5k0PNmq, 0, m, &cSlice_C5k0PNmq_sendMessage);
}

void Heavy_SoundScraper::cSend_NVAFUZx6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_lhW2cGxb_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_8ZXjMR4t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 1);
  cSwitchcase_p9X3Ivee_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cSlice_DSbFWVlt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 127.0f, 0, m, &cBinop_JvXFEyd5_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_QcDTIro3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_NLRgEimd_sendMessage);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_68XRnf33_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cVar_xqkVCOjX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_Xy9Lv1He, 1, m, &cPack_Xy9Lv1He_sendMessage);
}

void Heavy_SoundScraper::cVar_tHLO0ADo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_Xy9Lv1He, 0, m, &cPack_Xy9Lv1He_sendMessage);
}

void Heavy_SoundScraper::cPack_Xy9Lv1He_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_7ZQ6jwTn_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_g47VqKW1_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_bLIpqj1c_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_rksI0agz, 0, m, &cSlice_rksI0agz_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_qyKmCgQ8, 0, m, &cSlice_qyKmCgQ8_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_QS4zRMck, 0, m, &cSlice_QS4zRMck_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_NC8HPd9e, 0, m, &cSlice_NC8HPd9e_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_XXXCOwuJ, 0, m, &cSlice_XXXCOwuJ_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_Ul0Jseam, 0, m, &cSlice_Ul0Jseam_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_0p8kwpfX_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_AjJ1HhPt_sendMessage);
  cMsg_8ZXjMR4t_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_UXcMlDdD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_xqkVCOjX, 0, m, &cVar_xqkVCOjX_sendMessage);
}

void Heavy_SoundScraper::cCast_O2OBbMN6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_Xy9Lv1He, 2, m, &cPack_Xy9Lv1He_sendMessage);
}

void Heavy_SoundScraper::cCast_qQB7yDmJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_tHLO0ADo, 0, m, &cVar_tHLO0ADo_sendMessage);
}

void Heavy_SoundScraper::cBinop_NjvVkH01_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.4f, 0, m, &cBinop_nX0HO1j6_sendMessage);
}

void Heavy_SoundScraper::cBinop_nX0HO1j6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_awN0ltpe_sendMessage);
}

void Heavy_SoundScraper::cBinop_JvXFEyd5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_8PIpPN6Q_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_Y3WMF4ly_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_O2OBbMN6_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_UXcMlDdD_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_qQB7yDmJ_sendMessage);
}

void Heavy_SoundScraper::cBinop_CiceS2Au_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.99f, 0, m, &cBinop_RqcTZ0Vo_sendMessage);
}

void Heavy_SoundScraper::cBinop_RqcTZ0Vo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Y3WMF4ly, HV_BINOP_MULTIPLY, 1, m, &cBinop_Y3WMF4ly_sendMessage);
}

void Heavy_SoundScraper::cCast_NLRgEimd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_n4rBqBka_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_7ZQ6jwTn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_J6aJLHkU_onMessage(_c, NULL, 0, m, NULL);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_b1UQ0qQX_sendMessage);
}

void Heavy_SoundScraper::cCast_g47VqKW1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Wc8DGzbU_sendMessage);
}

void Heavy_SoundScraper::cSend_luBC76gn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_WlnyW5Fy_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_wK0KaMBI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_TdP6j73A_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_HyY3IW42_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Y3WMF4ly, HV_BINOP_MULTIPLY, 0, m, &cBinop_Y3WMF4ly_sendMessage);
}

void Heavy_SoundScraper::cSend_8PIpPN6Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_3GKJBOeE_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_8uR7XCHC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 44100.0f);
  cSend_NVAFUZx6_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_WJ02Lnq9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_SbFWUIep_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_u0LfjI2o_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_WSY0zyXv_sendMessage);
}

void Heavy_SoundScraper::cIf_xxS5ce62_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_Mv0HC2h8_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_GFPHbGb4_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cMsg_AKeOHv0V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_M6Qw9pWk, HV_BINOP_POW, 0, m, &cBinop_M6Qw9pWk_sendMessage);
}

void Heavy_SoundScraper::cBinop_M6Qw9pWk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_HPKK7RNe, 0, m, &cPack_HPKK7RNe_sendMessage);
}

void Heavy_SoundScraper::cBinop_hXLYt1TJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_cFr68mdl_sendMessage);
}

void Heavy_SoundScraper::cCast_WSY0zyXv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_xxS5ce62, 0, m, &cIf_xxS5ce62_sendMessage);
}

void Heavy_SoundScraper::cCast_u0LfjI2o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_bujF0NPm_sendMessage);
}

void Heavy_SoundScraper::cBinop_bujF0NPm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_xxS5ce62, 1, m, &cIf_xxS5ce62_sendMessage);
}

void Heavy_SoundScraper::cBinop_GFPHbGb4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_hXLYt1TJ_sendMessage);
}

void Heavy_SoundScraper::cMsg_Mv0HC2h8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_HPKK7RNe, 0, m, &cPack_HPKK7RNe_sendMessage);
}

void Heavy_SoundScraper::cBinop_cFr68mdl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_M6Qw9pWk, HV_BINOP_POW, 1, m, &cBinop_M6Qw9pWk_sendMessage);
  cMsg_AKeOHv0V_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_HPKK7RNe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_LXXPPTAJ, 0, m, NULL);
}

void Heavy_SoundScraper::cVar_JiB1FTll_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_9sh6fdYz_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_SbFWUIep_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSend_4ARznk9s_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_4ARznk9s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_qpf2y1H8_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_9sh6fdYz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_mxugVG4b_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_QfuerMvY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_iwF17uBc_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_BbWPYIbB_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_j3cH3bzV_sendMessage);
}

void Heavy_SoundScraper::cIf_5cJcge5C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_QgpdeIOa_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_dXksM7gI_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cMsg_gLnWJRQI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_qbZRBZpc, HV_BINOP_POW, 0, m, &cBinop_qbZRBZpc_sendMessage);
}

void Heavy_SoundScraper::cBinop_qbZRBZpc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_hq9laY55, 0, m, &cPack_hq9laY55_sendMessage);
}

void Heavy_SoundScraper::cBinop_YIPgHBzC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_bPSEVEF3_sendMessage);
}

void Heavy_SoundScraper::cCast_j3cH3bzV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_5cJcge5C, 0, m, &cIf_5cJcge5C_sendMessage);
}

void Heavy_SoundScraper::cCast_BbWPYIbB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_GBLI4Ytx_sendMessage);
}

void Heavy_SoundScraper::cBinop_GBLI4Ytx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_5cJcge5C, 1, m, &cIf_5cJcge5C_sendMessage);
}

void Heavy_SoundScraper::cBinop_dXksM7gI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_YIPgHBzC_sendMessage);
}

void Heavy_SoundScraper::cMsg_QgpdeIOa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_hq9laY55, 0, m, &cPack_hq9laY55_sendMessage);
}

void Heavy_SoundScraper::cBinop_bPSEVEF3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_qbZRBZpc, HV_BINOP_POW, 1, m, &cBinop_qbZRBZpc_sendMessage);
  cMsg_gLnWJRQI_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_hq9laY55_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_MZIVMHwM, 0, m, NULL);
}

void Heavy_SoundScraper::cVar_o0jNTS0T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_w2flDT4u_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_iwF17uBc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSend_F92h4cTy_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_F92h4cTy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_Tua8aZM9_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_w2flDT4u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_cZvy4ruV_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cIf_gkD7BATS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_6MSj9ie8_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_LOG10, m, &cUnop_qQiMtsVW_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cUnop_qQiMtsVW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_6dvuENOx_sendMessage);
}

void Heavy_SoundScraper::cCast_I3Wk9T1r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_gkD7BATS, 0, m, &cIf_gkD7BATS_sendMessage);
}

void Heavy_SoundScraper::cCast_ewjb0Nxp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_3znEzjzE_sendMessage);
}

void Heavy_SoundScraper::cMsg_6MSj9ie8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cMsg_iwF17uBc_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_BbWPYIbB_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_j3cH3bzV_sendMessage);
}

void Heavy_SoundScraper::cBinop_6dvuENOx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 100.0f, 0, m, &cBinop_GYXaqh2g_sendMessage);
}

void Heavy_SoundScraper::cBinop_GYXaqh2g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_dckapaAm_sendMessage);
}

void Heavy_SoundScraper::cBinop_dckapaAm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_iwF17uBc_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_BbWPYIbB_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_j3cH3bzV_sendMessage);
}

void Heavy_SoundScraper::cBinop_3znEzjzE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_gkD7BATS, 1, m, &cIf_gkD7BATS_sendMessage);
}

void Heavy_SoundScraper::cBinop_Cyb7BUqu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ewjb0Nxp_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_I3Wk9T1r_sendMessage);
}

void Heavy_SoundScraper::cBinop_MO9zL718_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_Cyb7BUqu_sendMessage);
}

void Heavy_SoundScraper::cVar_N3aCVSCL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_dNDtO1TL_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_H8O9dQQD_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_C3iYtObj_sendMessage);
}

void Heavy_SoundScraper::cIf_3D4LYxyk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_bKOn6OE4_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_VEidjNGU_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cMsg_DcKyaiFr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_JWW8SBEk, HV_BINOP_POW, 0, m, &cBinop_JWW8SBEk_sendMessage);
}

void Heavy_SoundScraper::cBinop_JWW8SBEk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_ph6et5U8, 0, m, &cPack_ph6et5U8_sendMessage);
}

void Heavy_SoundScraper::cBinop_0JYgtQR3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_47U4Jic7_sendMessage);
}

void Heavy_SoundScraper::cCast_C3iYtObj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_3D4LYxyk, 0, m, &cIf_3D4LYxyk_sendMessage);
}

void Heavy_SoundScraper::cCast_H8O9dQQD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_yeCuPmYd_sendMessage);
}

void Heavy_SoundScraper::cBinop_yeCuPmYd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_3D4LYxyk, 1, m, &cIf_3D4LYxyk_sendMessage);
}

void Heavy_SoundScraper::cBinop_VEidjNGU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_0JYgtQR3_sendMessage);
}

void Heavy_SoundScraper::cMsg_bKOn6OE4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_ph6et5U8, 0, m, &cPack_ph6et5U8_sendMessage);
}

void Heavy_SoundScraper::cBinop_47U4Jic7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_JWW8SBEk, HV_BINOP_POW, 1, m, &cBinop_JWW8SBEk_sendMessage);
  cMsg_DcKyaiFr_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_ph6et5U8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_kYf3Wxnv, 0, m, NULL);
}

void Heavy_SoundScraper::cVar_OuWINYw5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_uDRdO0YM_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_dNDtO1TL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSend_REkM9QYT_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_REkM9QYT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_eoZuUIQ9_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_uDRdO0YM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_WSwPhInE_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_BS8eTW7l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_69LaDCPu_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_mOKnbsiL_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_botQG8St_sendMessage);
}

void Heavy_SoundScraper::cIf_rgPQlBGT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_UBFmBzZH_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_CoYb0UPU_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cMsg_ifuQY1zl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_nTUjTO88, HV_BINOP_POW, 0, m, &cBinop_nTUjTO88_sendMessage);
}

void Heavy_SoundScraper::cBinop_nTUjTO88_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_L9vietTl, 0, m, &cPack_L9vietTl_sendMessage);
}

void Heavy_SoundScraper::cBinop_YYbEyuWx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_kbGTBaUc_sendMessage);
}

void Heavy_SoundScraper::cCast_mOKnbsiL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_y9hESgJE_sendMessage);
}

void Heavy_SoundScraper::cCast_botQG8St_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_rgPQlBGT, 0, m, &cIf_rgPQlBGT_sendMessage);
}

void Heavy_SoundScraper::cBinop_y9hESgJE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_rgPQlBGT, 1, m, &cIf_rgPQlBGT_sendMessage);
}

void Heavy_SoundScraper::cBinop_CoYb0UPU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_YYbEyuWx_sendMessage);
}

void Heavy_SoundScraper::cMsg_UBFmBzZH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_L9vietTl, 0, m, &cPack_L9vietTl_sendMessage);
}

void Heavy_SoundScraper::cBinop_kbGTBaUc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_nTUjTO88, HV_BINOP_POW, 1, m, &cBinop_nTUjTO88_sendMessage);
  cMsg_ifuQY1zl_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_L9vietTl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_uqeTqrvX, 0, m, NULL);
}

void Heavy_SoundScraper::cVar_U3nzcL9h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_R6BetvOw_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_69LaDCPu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSend_Sl5ziC40_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_Sl5ziC40_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_ddqkBFuQ_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_R6BetvOw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_JqOZht76_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_cNc5mneP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_835cs9Dc, 0, m, &cIf_835cs9Dc_sendMessage);
}

void Heavy_SoundScraper::cSlice_VAl5RBAS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_XgpCD8BL_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_wxsyvKS8_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_RMP5CxSW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cIf_onMessage(_c, &Context(_c)->cIf_Z3ZtWZf3, 0, m, &cIf_Z3ZtWZf3_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cIf_Z3ZtWZf3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_yweIwGEX_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_qIUovUe2_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cIf_w8zjnI4v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cPack_onMessage(_c, &Context(_c)->cPack_0ip4pDLD, 2, m, &cPack_0ip4pDLD_sendMessage);
      cPack_onMessage(_c, &Context(_c)->cPack_wSs9s9x5, 1, m, &cPack_wSs9s9x5_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cIf_FZKZzRPl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_VAl5RBAS, 0, m, &cSlice_VAl5RBAS_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_RMP5CxSW, 0, m, &cSlice_RMP5CxSW_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_Wqr6plxg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_j1GsK5jQ_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_dP0hflEp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_apkOUVj6_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_2a09GlPP_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_UiU07FJX_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cVar_1yPibb6Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_W3grlikk, 1, m, &cIf_W3grlikk_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_XEwqsK1J_sendMessage);
}

void Heavy_SoundScraper::cIf_W3grlikk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_VAl5RBAS, 0, m, &cSlice_VAl5RBAS_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_RMP5CxSW, 0, m, &cSlice_RMP5CxSW_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cPack_wSs9s9x5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_FZKZzRPl, 0, m, &cIf_FZKZzRPl_sendMessage);
}

void Heavy_SoundScraper::cBinop_3Dl2brWs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_Z3ZtWZf3, 1, m, &cIf_Z3ZtWZf3_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_w8zjnI4v, 1, m, &cIf_w8zjnI4v_sendMessage);
}

void Heavy_SoundScraper::cCast_wxsyvKS8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_w8zjnI4v, 0, m, &cIf_w8zjnI4v_sendMessage);
}

void Heavy_SoundScraper::cCast_XgpCD8BL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_NEQ, 0.0f, 0, m, &cBinop_3Dl2brWs_sendMessage);
}

void Heavy_SoundScraper::cMsg_ObWYqGaC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_1yPibb6Q, 1, m, &cVar_1yPibb6Q_sendMessage);
}

void Heavy_SoundScraper::cMsg_j1GsK5jQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_1yPibb6Q, 1, m, &cVar_1yPibb6Q_sendMessage);
}

void Heavy_SoundScraper::cCast_2a09GlPP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_wSs9s9x5, 0, m, &cPack_wSs9s9x5_sendMessage);
}

void Heavy_SoundScraper::cCast_apkOUVj6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_1yPibb6Q, 0, m, &cVar_1yPibb6Q_sendMessage);
}

void Heavy_SoundScraper::cCast_UiU07FJX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ObWYqGaC_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_XEwqsK1J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_FZKZzRPl, 1, m, &cIf_FZKZzRPl_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_RJjMLyNi_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_YD2wAdMA, 0, m, &cSlice_YD2wAdMA_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_yUAaKjXD, 0, m, &cSlice_yUAaKjXD_sendMessage);
      break;
    }
    case 0x40000000: { // "2.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_GlQCzqJr, 0, m, &cSlice_GlQCzqJr_sendMessage);
      break;
    }
    case 0x40400000: { // "3.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_9OsCUMvp, 0, m, &cSlice_9OsCUMvp_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cSlice_YD2wAdMA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_OpJn6SpZ, 0, m, &cSlice_OpJn6SpZ_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_8FYGSYOx, 0, m, &cSlice_8FYGSYOx_sendMessage);
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_OpJn6SpZ, 0, m, &cSlice_OpJn6SpZ_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_8FYGSYOx, 0, m, &cSlice_8FYGSYOx_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_yUAaKjXD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_XVu6ikGS, 0, m, &cSlice_XVu6ikGS_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_yxD3gljR, 0, m, &cSlice_yxD3gljR_sendMessage);
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_XVu6ikGS, 0, m, &cSlice_XVu6ikGS_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_yxD3gljR, 0, m, &cSlice_yxD3gljR_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_GlQCzqJr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_IurT5bZ5, 0, m, &cSlice_IurT5bZ5_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_fgHdAuc2, 0, m, &cSlice_fgHdAuc2_sendMessage);
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_IurT5bZ5, 0, m, &cSlice_IurT5bZ5_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_fgHdAuc2, 0, m, &cSlice_fgHdAuc2_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_9OsCUMvp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_DSbFWVlt, 0, m, &cSlice_DSbFWVlt_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_QcDTIro3, 0, m, &cSlice_QcDTIro3_sendMessage);
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_DSbFWVlt, 0, m, &cSlice_DSbFWVlt_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_QcDTIro3, 0, m, &cSlice_QcDTIro3_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSwitchcase_vtvOeQVC_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_YYMNgzrr_sendMessage);
      break;
    }
    default: {
      cMsg_qrmBzZob_sendMessage(_c, 0, m);
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_YYMNgzrr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_g1SYm656_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cIf_835cs9Dc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_Wqr6plxg, 0, m, &cSlice_Wqr6plxg_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_dP0hflEp, 0, m, &cSlice_dP0hflEp_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_W3grlikk, 0, m, &cIf_W3grlikk_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cVar_JIviyRuX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_xPIwHIPd_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_835cs9Dc, 1, m, &cIf_835cs9Dc_sendMessage);
}

void Heavy_SoundScraper::cBinop_xPIwHIPd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_JIviyRuX, 1, m, &cVar_JIviyRuX_sendMessage);
}

void Heavy_SoundScraper::cMsg_g1SYm656_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_JIviyRuX, 0, m, &cVar_JIviyRuX_sendMessage);
}

void Heavy_SoundScraper::cMsg_qrmBzZob_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_JIviyRuX, 0, m, &cVar_JIviyRuX_sendMessage);
}

void Heavy_SoundScraper::cPack_0ip4pDLD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_RJjMLyNi_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cVar_ISdmdXxz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_0ip4pDLD, 0, m, &cPack_0ip4pDLD_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_aEWMway7_sendMessage);
}

void Heavy_SoundScraper::cBinop_aEWMway7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MOD_BIPOLAR, 4.0f, 0, m, &cBinop_3AQAzdn9_sendMessage);
}

void Heavy_SoundScraper::cBinop_3AQAzdn9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ISdmdXxz, 1, m, &cVar_ISdmdXxz_sendMessage);
}

void Heavy_SoundScraper::cMsg_25uqYvvn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_vtvOeQVC_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_yweIwGEX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_0ip4pDLD, 1, m, &cPack_0ip4pDLD_sendMessage);
}

void Heavy_SoundScraper::cCast_qIUovUe2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ISdmdXxz, 0, m, &cVar_ISdmdXxz_sendMessage);
}

void Heavy_SoundScraper::cVar_avJg9MHw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_C3KNHipB_sendMessage);
}

void Heavy_SoundScraper::cBinop_C3KNHipB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_avJg9MHw, 1, m, &cVar_avJg9MHw_sendMessage);
}

void Heavy_SoundScraper::cPack_B2JZKtpU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_kPytG5Co, 0, m, NULL);
}

void Heavy_SoundScraper::cSwitchcase_MJ1fQp7B_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_mZOtfodU, 0, m, &cSlice_mZOtfodU_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_DQaJqdb9, 0, m, &cRandom_DQaJqdb9_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_B43nduHJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_rJAiAOck_sendMessage);
}

void Heavy_SoundScraper::cUnop_rJAiAOck_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 25.0f, 0, m, &cBinop_ADwhYiAl_sendMessage);
}

void Heavy_SoundScraper::cRandom_DQaJqdb9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 30.0f, 0, m, &cBinop_B43nduHJ_sendMessage);
}

void Heavy_SoundScraper::cSlice_mZOtfodU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_DQaJqdb9, 1, m, &cRandom_DQaJqdb9_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSwitchcase_9w5Zc6pP_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_v1kpkVmq, 0, m, &cSlice_v1kpkVmq_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_QThJ7jVy, 0, m, &cRandom_QThJ7jVy_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_XolyJj6F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_Z1ujbEgV_sendMessage);
}

void Heavy_SoundScraper::cUnop_Z1ujbEgV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 10.0f, 0, m, &cBinop_JZqzKI0Y_sendMessage);
}

void Heavy_SoundScraper::cRandom_QThJ7jVy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 40.0f, 0, m, &cBinop_XolyJj6F_sendMessage);
}

void Heavy_SoundScraper::cSlice_v1kpkVmq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_QThJ7jVy, 1, m, &cRandom_QThJ7jVy_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSwitchcase_1lm2IdvV_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_1zAZXxp7, 0, m, &cSlice_1zAZXxp7_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_9wxYnRji, 0, m, &cRandom_9wxYnRji_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_IOA4iCJr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_7wslPh7g_sendMessage);
}

void Heavy_SoundScraper::cUnop_7wslPh7g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_kd3U435Q_sendMessage);
}

void Heavy_SoundScraper::cRandom_9wxYnRji_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 100.0f, 0, m, &cBinop_IOA4iCJr_sendMessage);
}

void Heavy_SoundScraper::cSlice_1zAZXxp7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_9wxYnRji, 1, m, &cRandom_9wxYnRji_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cPack_XjFGRNor_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPrint_onMessage(_c, m, "SCRAPER_RESET");
}

void Heavy_SoundScraper::cBinop_ADwhYiAl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_lAUkto2F_sendMessage(_c, 0, m);
  cPack_onMessage(_c, &Context(_c)->cPack_XjFGRNor, 1, m, &cPack_XjFGRNor_sendMessage);
}

void Heavy_SoundScraper::cBinop_JZqzKI0Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_n3JeIJqA_sendMessage(_c, 0, m);
  cPack_onMessage(_c, &Context(_c)->cPack_XjFGRNor, 0, m, &cPack_XjFGRNor_sendMessage);
}

void Heavy_SoundScraper::cBinop_kd3U435Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_LtCsAXf0_sendMessage(_c, 0, m);
  cPack_onMessage(_c, &Context(_c)->cPack_XjFGRNor, 2, m, &cPack_XjFGRNor_sendMessage);
}

void Heavy_SoundScraper::cCast_ivJK7gl9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_9w5Zc6pP_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_92Nmr0On_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_0De4oiRa_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_nWVjSeFU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_MJ1fQp7B_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_dDRWvyXu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_1lm2IdvV_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cMsg_0De4oiRa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSend_hbJtk5EC_sendMessage(_c, 0, m);
  cPack_onMessage(_c, &Context(_c)->cPack_XjFGRNor, 3, m, &cPack_XjFGRNor_sendMessage);
}

void Heavy_SoundScraper::cSend_hbJtk5EC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_NwIyOnyO_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_LtCsAXf0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_9STUb7Kr_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_n3JeIJqA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_EjgEjYvl_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_lAUkto2F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_lT5oD7Bt_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_VBavTZpM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_FUiH1nXC_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_EZ8VdiIH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_wt4STuQ7_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_e9Q8F5jj_sendMessage);
}

void Heavy_SoundScraper::cIf_NwM2wEAy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_FKcZ6I9M_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 440.0f, 0, m, &cBinop_SNdGuy0o_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cUnop_fEUxTAf4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 12.0f, 0, m, &cBinop_gt1vrOp3_sendMessage);
}

void Heavy_SoundScraper::cBinop_SNdGuy0o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_LOG2, m, &cUnop_fEUxTAf4_sendMessage);
}

void Heavy_SoundScraper::cBinop_gt1vrOp3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 69.0f, 0, m, &cBinop_aEC9MBYq_sendMessage);
}

void Heavy_SoundScraper::cBinop_aEC9MBYq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ExEXb4JY, 0, m, &cVar_ExEXb4JY_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_dmS6zry0, HV_BINOP_SUBTRACT, 1, m, &cBinop_dmS6zry0_sendMessage);
}

void Heavy_SoundScraper::cCast_wt4STuQ7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_SsrjLS70_sendMessage);
}

void Heavy_SoundScraper::cCast_e9Q8F5jj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_NwM2wEAy, 0, m, &cIf_NwM2wEAy_sendMessage);
}

void Heavy_SoundScraper::cBinop_SsrjLS70_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_NwM2wEAy, 1, m, &cIf_NwM2wEAy_sendMessage);
}

void Heavy_SoundScraper::cMsg_FKcZ6I9M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, -1500.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_ExEXb4JY, 0, m, &cVar_ExEXb4JY_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_dmS6zry0, HV_BINOP_SUBTRACT, 1, m, &cBinop_dmS6zry0_sendMessage);
}

void Heavy_SoundScraper::cVar_ExEXb4JY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cCast_4xxEHpfz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_dmS6zry0, HV_BINOP_SUBTRACT, 0, m, &cBinop_dmS6zry0_sendMessage);
}

void Heavy_SoundScraper::cBinop_miciUGFh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_VBavTZpM, 0, m, &cVar_VBavTZpM_sendMessage);
}

void Heavy_SoundScraper::cBinop_B5x4hefd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_miciUGFh, HV_BINOP_ADD, 1, m, &cBinop_miciUGFh_sendMessage);
}

void Heavy_SoundScraper::cBinop_dmS6zry0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_miciUGFh, HV_BINOP_ADD, 0, m, &cBinop_miciUGFh_sendMessage);
}

void Heavy_SoundScraper::cSend_FUiH1nXC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_d50G3Uhc_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_QnIBKCPb_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3F800000: { // "1.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_xxE9lItg, 0, m, &cSlice_xxE9lItg_sendMessage);
      break;
    }
    case 0x0: { // "0.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_X403lTYb, 0, m, &cSlice_X403lTYb_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cSlice_xxE9lItg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Cpg9f7Jj_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Cpg9f7Jj_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_X403lTYb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_8YGiU2dY_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_umKdLmGa_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_8YGiU2dY_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_umKdLmGa_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSystem_7oxKmhbq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_K1ho3Iac, HV_BINOP_SUBTRACT, 1, m, &cBinop_K1ho3Iac_sendMessage);
}

void Heavy_SoundScraper::cMsg_WDODVqTY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "currentTime");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_7oxKmhbq_sendMessage);
}

void Heavy_SoundScraper::cBinop_K1ho3Iac_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_aUvQubJe, HV_BINOP_DIVIDE, 0, m, &cBinop_aUvQubJe_sendMessage);
}

void Heavy_SoundScraper::cSystem_IFc9S82p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_K1ho3Iac, HV_BINOP_SUBTRACT, 0, m, &cBinop_K1ho3Iac_sendMessage);
}

void Heavy_SoundScraper::cMsg_DLNBSShW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "currentTime");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_IFc9S82p_sendMessage);
}

void Heavy_SoundScraper::cBinop_aUvQubJe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_UW96iTWX, HV_BINOP_SUBTRACT, 1, m, &cBinop_UW96iTWX_sendMessage);
}

void Heavy_SoundScraper::cSystem_IfBMBOLB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_qQFAEiAB_sendMessage);
}

void Heavy_SoundScraper::cMsg_7BcDKfke_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_IfBMBOLB_sendMessage);
}

void Heavy_SoundScraper::cBinop_qQFAEiAB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_aUvQubJe, HV_BINOP_DIVIDE, 1, m, &cBinop_aUvQubJe_sendMessage);
}

void Heavy_SoundScraper::cSlice_BJYPq7Fk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 10000000.0f, 0, m, &cBinop_nCzLBPHN_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_Nksac4C4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 10000000.0f, 0, m, &cBinop_EOvYY0WN_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cPack_qS6AWxh7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSlice_onMessage(_c, &Context(_c)->cSlice_iu94BBFJ, 0, m, &cSlice_iu94BBFJ_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_BMPefG1F, 0, m, &cSlice_BMPefG1F_sendMessage);
}

void Heavy_SoundScraper::cVar_2r1tmWiL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_OuVMRQQh_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_OuVMRQQh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 1000.0f);
  cSlice_onMessage(_c, &Context(_c)->cSlice_BJYPq7Fk, 0, m, &cSlice_BJYPq7Fk_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_Nksac4C4, 0, m, &cSlice_Nksac4C4_sendMessage);
}

void Heavy_SoundScraper::cBinop_EOvYY0WN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_qS6AWxh7, 0, m, &cPack_qS6AWxh7_sendMessage);
}

void Heavy_SoundScraper::cBinop_nCzLBPHN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_qS6AWxh7, 1, m, &cPack_qS6AWxh7_sendMessage);
}

void Heavy_SoundScraper::cVar_xfKLPUcG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_mEcpKqON, 0, m, &cIf_mEcpKqON_sendMessage);
}

void Heavy_SoundScraper::cPack_JxKp8eJG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_KsdNcXbg_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSlice_iu94BBFJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cPack_onMessage(_c, &Context(_c)->cPack_JxKp8eJG, 1, m, &cPack_JxKp8eJG_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_BMPefG1F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_iGtFsPXS, HV_BINOP_ADD, 0, m, &cBinop_iGtFsPXS_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_iGtFsPXS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_JxKp8eJG, 0, m, &cPack_JxKp8eJG_sendMessage);
}

void Heavy_SoundScraper::cBinop_b7emUf7t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_rW0hnDQk, HV_BINOP_MULTIPLY, 1, m, &cBinop_rW0hnDQk_sendMessage);
}

void Heavy_SoundScraper::cBinop_rW0hnDQk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_iGtFsPXS, HV_BINOP_ADD, 1, m, &cBinop_iGtFsPXS_sendMessage);
}

void Heavy_SoundScraper::cVar_cFrIq1vt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_623CtA8V, HV_BINOP_MULTIPLY, 0, m, &cBinop_623CtA8V_sendMessage);
}

void Heavy_SoundScraper::cMsg_a0DRoa8N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_mAniFIil_sendMessage);
}

void Heavy_SoundScraper::cSystem_mAniFIil_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_yTq8Fgol_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_623CtA8V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_WqiRcBdO_sendMessage);
}

void Heavy_SoundScraper::cBinop_djfdbi5o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_623CtA8V, HV_BINOP_MULTIPLY, 1, m, &cBinop_623CtA8V_sendMessage);
}

void Heavy_SoundScraper::cMsg_yTq8Fgol_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_djfdbi5o_sendMessage);
}

void Heavy_SoundScraper::cBinop_WqiRcBdO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_6jadjVvA_sendMessage);
}

void Heavy_SoundScraper::cBinop_6jadjVvA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_6HfcsER0_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_FA2TIi6z, m);
}

void Heavy_SoundScraper::cBinop_6HfcsER0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_K3dgw4Sa, m);
}

void Heavy_SoundScraper::cSwitchcase_wPg1aliP_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_O6W6NI2S_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_O6W6NI2S_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_174WmMc5, 1, m, &cDelay_174WmMc5_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_YKiLWnF3_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cDelay_174WmMc5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_174WmMc5, m);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_UymREhVI_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_UVvSiatJ_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_6JnuiR3f_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_rzauETi9_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Tw4YrCQG_sendMessage);
}

void Heavy_SoundScraper::cMsg_O6W6NI2S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_174WmMc5, 0, m, &cDelay_174WmMc5_sendMessage);
}

void Heavy_SoundScraper::cCast_YKiLWnF3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_174WmMc5, 0, m, &cDelay_174WmMc5_sendMessage);
}

void Heavy_SoundScraper::cIf_mEcpKqON_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSwitchcase_wPg1aliP_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cMsg_y5BsQRfl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "stop");
  cSwitchcase_wPg1aliP_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cMsg_pot1h9pG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cIf_onMessage(_c, &Context(_c)->cIf_mEcpKqON, 1, m, &cIf_mEcpKqON_sendMessage);
}

void Heavy_SoundScraper::cMsg_OFkCXGwf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cIf_onMessage(_c, &Context(_c)->cIf_mEcpKqON, 1, m, &cIf_mEcpKqON_sendMessage);
}

void Heavy_SoundScraper::cCast_IMTZYsmJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_pot1h9pG_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_wIa2gpxM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_UymREhVI_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_UVvSiatJ_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_6JnuiR3f_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_rzauETi9_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Tw4YrCQG_sendMessage);
}

void Heavy_SoundScraper::cCast_3IWl68TZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_OFkCXGwf_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_F478LNRE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_y5BsQRfl_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSlice_g6xTrs7y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSend_g4AvtpMi_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_6ZmhuSSs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSend_ezzLf6xM_sendMessage(_c, 0, m);
      cPrint_onMessage(_c, m, "SCRAPER_TAB");
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSwitchcase_T4M28Fzm_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_ZzzpqcSO, 0, m, &cSlice_ZzzpqcSO_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cVar_7o7TgulL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_kSokpexz_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSystem_ZZnn6IHp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 2.0f, 0, m, &cBinop_YGSTLasK_sendMessage);
}

void Heavy_SoundScraper::cBinop_YGSTLasK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_luAwHcST, m);
}

void Heavy_SoundScraper::cMsg_kSokpexz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ZZnn6IHp_sendMessage);
}

void Heavy_SoundScraper::cSlice_ZzzpqcSO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sTabread_onMessage(_c, &Context(_c)->sTabread_bF5EsO64, 1, m, NULL);
      sTabread_onMessage(_c, &Context(_c)->sTabread_Nz5yK9h1, 1, m, NULL);
      cVar_onMessage(_c, &Context(_c)->cVar_7o7TgulL, 0, m, &cVar_7o7TgulL_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cMsg_g14fvhST_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSwitchcase_T4M28Fzm_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cSwitchcase_l1HYYp9U_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_4OF1c1oS, 0, m, &cSlice_4OF1c1oS_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cVar_uBppO2Vj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_rqhobUiH_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSystem_6mqfdS84_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 2.0f, 0, m, &cBinop_4Cxkvg7g_sendMessage);
}

void Heavy_SoundScraper::cBinop_4Cxkvg7g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_tZzwfsDn, m);
}

void Heavy_SoundScraper::cMsg_rqhobUiH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_6mqfdS84_sendMessage);
}

void Heavy_SoundScraper::cSlice_4OF1c1oS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sTabread_onMessage(_c, &Context(_c)->sTabread_LCieUrpa, 1, m, NULL);
      sTabread_onMessage(_c, &Context(_c)->sTabread_oVRyjie9, 1, m, NULL);
      cVar_onMessage(_c, &Context(_c)->cVar_uBppO2Vj, 0, m, &cVar_uBppO2Vj_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cMsg_VSxgw51w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSwitchcase_l1HYYp9U_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_G6r73YyA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_BHsy5fn4, HV_BINOP_DIVIDE, 0, m, &cBinop_BHsy5fn4_sendMessage);
}

void Heavy_SoundScraper::cCast_EIAdq0e2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_04RWfZVy_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_0RpUDxEo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_G6r73YyA, HV_BINOP_POW, 1, m, &cBinop_G6r73YyA_sendMessage);
}

void Heavy_SoundScraper::cMsg_04RWfZVy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_G6r73YyA, HV_BINOP_POW, 0, m, &cBinop_G6r73YyA_sendMessage);
}

void Heavy_SoundScraper::cCast_64g2pYpE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_BHsy5fn4, HV_BINOP_DIVIDE, 0, m, &cBinop_BHsy5fn4_sendMessage);
}

void Heavy_SoundScraper::cCast_WhEeEGUt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_BHsy5fn4, HV_BINOP_DIVIDE, 1, m, &cBinop_BHsy5fn4_sendMessage);
}

void Heavy_SoundScraper::cBinop_BHsy5fn4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_8xOJbste, 0, m);
  cPrint_onMessage(_c, m, "SCRAPER_LOOP_FREQ");
}

void Heavy_SoundScraper::cBinop_ufWwa0XK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_0RpUDxEo_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_EIAdq0e2_sendMessage);
}

void Heavy_SoundScraper::cMsg_IHFzBC3Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSend_imIfBcHF_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_imIfBcHF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_d50G3Uhc_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_HVfE4MLs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_9STUb7Kr_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_0tEByGfQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 5.0f);
  cSend_HVfE4MLs_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_8B5zZ27w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 44100.0f);
  cSend_QLWvrfpq_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_QLWvrfpq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_7RUsYlr2_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_2FnJW1tQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSend_7dIUq2pN_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_7dIUq2pN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_bt4qx8Gw_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_gWDK1gCH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_SjvShhnn_sendMessage);
}

void Heavy_SoundScraper::cBinop_SjvShhnn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_G6GReZOF_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_ijOmPDNW_sendMessage);
}

void Heavy_SoundScraper::cVar_4IlEGoBW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_zAqc9WC6_sendMessage);
}

void Heavy_SoundScraper::cMsg_wtwXK4JU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_orWiKvlm_sendMessage);
}

void Heavy_SoundScraper::cSystem_orWiKvlm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_RRClXl33, HV_BINOP_DIVIDE, 1, m, &cBinop_RRClXl33_sendMessage);
}

void Heavy_SoundScraper::cBinop_G6GReZOF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_tLikNFAl_sendMessage);
}

void Heavy_SoundScraper::cBinop_tLikNFAl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_gS5Sasrq, m);
}

void Heavy_SoundScraper::cMsg_C7xxQLVV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_aj31MXKW_sendMessage);
}

void Heavy_SoundScraper::cBinop_aj31MXKW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_gWDK1gCH_sendMessage);
}

void Heavy_SoundScraper::cBinop_ijOmPDNW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_Z9Nnl08n, m);
}

void Heavy_SoundScraper::cBinop_zAqc9WC6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_GRWx7h0X_sendMessage);
}

void Heavy_SoundScraper::cBinop_GRWx7h0X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_RRClXl33, HV_BINOP_DIVIDE, 0, m, &cBinop_RRClXl33_sendMessage);
}

void Heavy_SoundScraper::cBinop_RRClXl33_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_C7xxQLVV_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::sSample_VSl3MWpb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_neyIrWpR, 0, m, &cVar_neyIrWpR_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_YrKT5qDS_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_eHIuMmNh_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_eHIuMmNh_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_2ewha5i3, 1, m, &cDelay_2ewha5i3_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_bi8gRZGI_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cDelay_2ewha5i3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_2ewha5i3, m);
  sSample_onMessage(_c, &Context(_c)->sSample_VSl3MWpb, 1, m);
}

void Heavy_SoundScraper::cMsg_eHIuMmNh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_2ewha5i3, 0, m, &cDelay_2ewha5i3_sendMessage);
}

void Heavy_SoundScraper::cCast_bi8gRZGI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_2ewha5i3, 0, m, &cDelay_2ewha5i3_sendMessage);
}

void Heavy_SoundScraper::cVar_neyIrWpR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPrint_onMessage(_c, m, "SCRAPER_SIG");
}

void Heavy_SoundScraper::cCast_9DiFQ73C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sSample_onMessage(_c, &Context(_c)->sSample_VSl3MWpb, 1, m);
}

void Heavy_SoundScraper::cSwitchcase_UDqoeNTR_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_g8pWRc4w_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_g8pWRc4w_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_l1fP3848, 1, m, &cDelay_l1fP3848_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_janOGycr_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cDelay_l1fP3848_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_l1fP3848, m);
  sSample_onMessage(_c, &Context(_c)->sSample_VSl3MWpb, 1, m);
}

void Heavy_SoundScraper::cMsg_g8pWRc4w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_l1fP3848, 0, m, &cDelay_l1fP3848_sendMessage);
}

void Heavy_SoundScraper::cCast_janOGycr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_l1fP3848, 0, m, &cDelay_l1fP3848_sendMessage);
}

void Heavy_SoundScraper::sSample_GybwLLos_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_MExqo7ty, 0, m, &cVar_MExqo7ty_sendMessage);
}

void Heavy_SoundScraper::cVar_MExqo7ty_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cSwitchcase_QfVMfgoa_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cMsg_OWJSeqUH_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_OWJSeqUH_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_jdeEGOG8_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cDelay_J9oaZi53_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_J9oaZi53, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_J9oaZi53, 0, m, &cDelay_J9oaZi53_sendMessage);
  sSample_onMessage(_c, &Context(_c)->sSample_GybwLLos, 1, m);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_AWXt4Nna_sendMessage);
}

void Heavy_SoundScraper::cCast_jdeEGOG8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_OWJSeqUH_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_J9oaZi53, 0, m, &cDelay_J9oaZi53_sendMessage);
  sSample_onMessage(_c, &Context(_c)->sSample_GybwLLos, 1, m);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_AWXt4Nna_sendMessage);
}

void Heavy_SoundScraper::cMsg_lnRvebjY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_GsaHrQud_sendMessage);
}

void Heavy_SoundScraper::cSystem_GsaHrQud_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_aaVM2GxQ_sendMessage);
}

void Heavy_SoundScraper::cVar_BiBKnVql_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_JIs4N9u6, HV_BINOP_MULTIPLY, 0, m, &cBinop_JIs4N9u6_sendMessage);
}

void Heavy_SoundScraper::cMsg_OWJSeqUH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_J9oaZi53, 0, m, &cDelay_J9oaZi53_sendMessage);
}

void Heavy_SoundScraper::cBinop_nVXFHEog_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_J9oaZi53, 2, m, &cDelay_J9oaZi53_sendMessage);
}

void Heavy_SoundScraper::cBinop_aaVM2GxQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_JIs4N9u6, HV_BINOP_MULTIPLY, 1, m, &cBinop_JIs4N9u6_sendMessage);
}

void Heavy_SoundScraper::cBinop_JIs4N9u6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_nVXFHEog_sendMessage);
}

void Heavy_SoundScraper::cVar_dTXmA0QR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_QtSGr6U1_sendMessage);
  cSwitchcase_QfVMfgoa_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_QtSGr6U1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_dTXmA0QR, 1, m, &cVar_dTXmA0QR_sendMessage);
}

void Heavy_SoundScraper::cCast_AWXt4Nna_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cSend_XrcelLBY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_FWuAtFNd_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_g5uFS5np_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_bt4qx8Gw_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_YaoUxTYb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_B8BtruqY_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_zDv510z4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_0L6LdJYF_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_7M60O1jp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_NwIyOnyO_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_EWr5RlBF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_APxztZjY_sendMessage);
}

void Heavy_SoundScraper::cBinop_APxztZjY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_B2JZKtpU, 0, m, &cPack_B2JZKtpU_sendMessage);
}

void Heavy_SoundScraper::cSend_2lXZjFWv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_0L6LdJYF_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_VeKa3hXs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_ncNJGndH_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_KPFrQrtc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_9VX7qlqA_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_Cpg9f7Jj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_VeKa3hXs_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_UW96iTWX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_uE49i0Kg_sendMessage);
}

void Heavy_SoundScraper::cCast_o8Pa2rCv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_UW96iTWX, HV_BINOP_SUBTRACT, 0, m, &cBinop_UW96iTWX_sendMessage);
}

void Heavy_SoundScraper::cCast_9a5bNn58_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_7BcDKfke_sendMessage(_c, 0, m);
  cMsg_DLNBSShW_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_uE49i0Kg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_mEcpKqON, 0, m, &cIf_mEcpKqON_sendMessage);
}

void Heavy_SoundScraper::cMsg_BfBGovU9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 0.0f);
  cSlice_onMessage(_c, &Context(_c)->cSlice_iu94BBFJ, 0, m, &cSlice_iu94BBFJ_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_BMPefG1F, 0, m, &cSlice_BMPefG1F_sendMessage);
}

void Heavy_SoundScraper::cBinop_sD8kQdO9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_9a5bNn58_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_o8Pa2rCv_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_xfKLPUcG, 1, m, &cVar_xfKLPUcG_sendMessage);
}

void Heavy_SoundScraper::cMsg_3Yj4iRHV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cPrint_onMessage(_c, m, "SCRAPER_RUNNING");
  sVarf_onMessage(_c, &Context(_c)->sVarf_OVlYzOUE, m);
}

void Heavy_SoundScraper::cMsg_2m7uDB8f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPrint_onMessage(_c, m, "SCRAPER_RUNNING");
  sVarf_onMessage(_c, &Context(_c)->sVarf_OVlYzOUE, m);
}

void Heavy_SoundScraper::cSend_KsdNcXbg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_6bxAHBNN_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_ew9zOFyz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "stop");
  sLine_onMessage(_c, &Context(_c)->sLine_wDgMEk6l, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_rzauETi9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_BfBGovU9_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_UymREhVI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_WDODVqTY_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_Tw4YrCQG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_2r1tmWiL, 0, m, &cVar_2r1tmWiL_sendMessage);
}

void Heavy_SoundScraper::cCast_6JnuiR3f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cCast_UVvSiatJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_xfKLPUcG, 0, m, &cVar_xfKLPUcG_sendMessage);
}

void Heavy_SoundScraper::cSend_ezzLf6xM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_8kzssOge_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_g4AvtpMi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_lUjd3Nar_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_zeeuRA8y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_XQAbllUE_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_XQAbllUE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_nUWs5YwR_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_v50csgzS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_nzCTYJd0_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_wCyW7LBp_sendMessage);
}

void Heavy_SoundScraper::cCast_nzCTYJd0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_mRM51ZAW, HV_BINOP_MULTIPLY, 1, m, &cBinop_mRM51ZAW_sendMessage);
}

void Heavy_SoundScraper::cCast_wCyW7LBp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_mRM51ZAW, HV_BINOP_MULTIPLY, 0, m, &cBinop_mRM51ZAW_sendMessage);
}

void Heavy_SoundScraper::cBinop_mRM51ZAW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_uGjybpIq_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_uGjybpIq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_LC0dknMg_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_8YGiU2dY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_2lXZjFWv_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_umKdLmGa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_KPFrQrtc_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_NGxVaLvv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::hTable_ZUcNjdus_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::hTable_SmPFedMc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::hTable_loPteidh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::hTable_fYwlxwqf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::hTable_DmLOFayB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cSlice_PqnASR9N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_JcP0mOrb_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_SpCzCgYF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cIf_onMessage(_c, &Context(_c)->cIf_8Z1m1whM, 0, m, &cIf_8Z1m1whM_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_t1Ul5cO3, 0, m, &cIf_t1Ul5cO3_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_opGBFbz3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cIf_onMessage(_c, &Context(_c)->cIf_AkdPGvYY, 0, m, &cIf_AkdPGvYY_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_066ZSh0T, 0, m, &cIf_066ZSh0T_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cVar_5mzvLwtF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_DwEfw5Fu_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_y0qNP8KP, 0, m, &cIf_y0qNP8KP_sendMessage);
}

void Heavy_SoundScraper::cUnop_TxHGHs5p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_w1UWs7wn_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_2Fbr1vCP, HV_BINOP_EQ, 1, m, &cBinop_2Fbr1vCP_sendMessage);
}

void Heavy_SoundScraper::cUnop_htOKhOAr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_w1UWs7wn_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_2Fbr1vCP, HV_BINOP_EQ, 1, m, &cBinop_2Fbr1vCP_sendMessage);
}

void Heavy_SoundScraper::cIf_y0qNP8KP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_htOKhOAr_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_TxHGHs5p_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_DwEfw5Fu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_y0qNP8KP, 1, m, &cIf_y0qNP8KP_sendMessage);
}

void Heavy_SoundScraper::cIf_t1Ul5cO3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSend_P2b4iI3r_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cIf_066ZSh0T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSend_b5ODd9MW_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cIf_8Z1m1whM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSend_P2b4iI3r_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cIf_AkdPGvYY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSend_b5ODd9MW_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_JcP0mOrb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_2Fbr1vCP, HV_BINOP_EQ, 0, m, &cBinop_2Fbr1vCP_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_K5hpv9wF_sendMessage);
}

void Heavy_SoundScraper::cBinop_w1UWs7wn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_7nS2IzIR_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_dX6f7ywu_sendMessage);
}

void Heavy_SoundScraper::cBinop_2Fbr1vCP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Ftk68Fbx_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_jskMlQGY_sendMessage);
}

void Heavy_SoundScraper::cCast_jskMlQGY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_AkdPGvYY, 1, m, &cIf_AkdPGvYY_sendMessage);
}

void Heavy_SoundScraper::cCast_Ftk68Fbx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_t1Ul5cO3, 1, m, &cIf_t1Ul5cO3_sendMessage);
}

void Heavy_SoundScraper::cCast_7nS2IzIR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_8Z1m1whM, 1, m, &cIf_8Z1m1whM_sendMessage);
}

void Heavy_SoundScraper::cCast_dX6f7ywu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_066ZSh0T, 1, m, &cIf_066ZSh0T_sendMessage);
}

void Heavy_SoundScraper::cBinop_K5hpv9wF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_cQsY9Gi5_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_b5ODd9MW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_raXZ1cVU_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_P2b4iI3r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_xr3hShfa_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_cQsY9Gi5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cSend_u9CF5GpJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_Y9s9lBtb_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_SdF0aTrK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cSend_u9CF5GpJ_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_wkYiQ8ft_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x40000000: { // "2.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Cpa5UQHK_sendMessage);
      break;
    }
    case 0x40400000: { // "3.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_CyAKJsF9_sendMessage);
      break;
    }
    case 0x40800000: { // "4.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ZNtGpYmS_sendMessage);
      break;
    }
    case 0x40A00000: { // "5.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_dFeCz670_sendMessage);
      break;
    }
    case 0x40C00000: { // "6.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_8JgG5lcO_sendMessage);
      break;
    }
    case 0x40E00000: { // "7.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_7SSP1Vqu_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_Cpa5UQHK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ttQ8U0lj_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_CyAKJsF9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_be1E0MEC_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_ZNtGpYmS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_F5cbmrJK_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_dFeCz670_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_4zfdgn5u_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_8JgG5lcO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_pycXKRWe_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_7SSP1Vqu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Z7KdZYZf_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_ZqXmJ0fy_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_teoKsPlh, 0, m, &cSlice_teoKsPlh_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_8Q9cSHfr, 0, m, &cRandom_8Q9cSHfr_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_1t8Vi9Aq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_R9VfC1G6_sendMessage);
}

void Heavy_SoundScraper::cUnop_R9VfC1G6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_7xga6m1R_sendMessage);
}

void Heavy_SoundScraper::cRandom_8Q9cSHfr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 5.0f, 0, m, &cBinop_1t8Vi9Aq_sendMessage);
}

void Heavy_SoundScraper::cSlice_teoKsPlh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_8Q9cSHfr, 1, m, &cRandom_8Q9cSHfr_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cMsg_pycXKRWe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "marimba");
  msg_setFloat(m, 1, 264.0f);
  cSend_CF2Is4dg_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_Z7KdZYZf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "xylo");
  msg_setFloat(m, 1, 2116.9f);
  cSend_CF2Is4dg_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_4zfdgn5u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "bowl");
  msg_setFloat(m, 1, 705.52f);
  cSend_CF2Is4dg_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_be1E0MEC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "gong");
  msg_setFloat(m, 1, 179.88f);
  cSend_CF2Is4dg_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_CF2Is4dg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_3hh6qDY3_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_F5cbmrJK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "crotale");
  msg_setFloat(m, 1, 1058.39f);
  cSend_CF2Is4dg_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_7xga6m1R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPrint_onMessage(_c, m, "SOUND_CHOICE");
  cSwitchcase_wkYiQ8ft_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cMsg_ttQ8U0lj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "almglocken");
  msg_setFloat(m, 1, 262.6f);
  cSend_CF2Is4dg_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_Ko8rSen0_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_qrhHQWpn, 0, m, &cSlice_qrhHQWpn_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_97IvFN19, 0, m, &cRandom_97IvFN19_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_8wbdP0ML_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_s9az8UNC_sendMessage);
}

void Heavy_SoundScraper::cUnop_s9az8UNC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 10.0f, 0, m, &cBinop_i9yazbPk_sendMessage);
}

void Heavy_SoundScraper::cRandom_97IvFN19_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 80.0f, 0, m, &cBinop_8wbdP0ML_sendMessage);
}

void Heavy_SoundScraper::cSlice_qrhHQWpn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_97IvFN19, 1, m, &cRandom_97IvFN19_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSwitchcase_Lz7x9zEp_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_23PFll20, 0, m, &cSlice_23PFll20_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_RO54tJR1, 0, m, &cRandom_RO54tJR1_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_ShCxNJ2v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_eP7ZZZXM_sendMessage);
}

void Heavy_SoundScraper::cUnop_eP7ZZZXM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_6fBOyrFL, 0, m, &cPack_6fBOyrFL_sendMessage);
}

void Heavy_SoundScraper::cRandom_RO54tJR1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 200.0f, 0, m, &cBinop_ShCxNJ2v_sendMessage);
}

void Heavy_SoundScraper::cSlice_23PFll20_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_RO54tJR1, 1, m, &cRandom_RO54tJR1_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cVar_Kf0VGfsh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_5VA4Bj3r_sendMessage);
}

void Heavy_SoundScraper::cPack_5WRLRdQN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_blkWxGKA, 0, m, NULL);
}

void Heavy_SoundScraper::cUnop_HImlZnoU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_hRLMnziQ_sendMessage);
}

void Heavy_SoundScraper::cBinop_GZrOHVJB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_EXP, m, &cUnop_HImlZnoU_sendMessage);
}

void Heavy_SoundScraper::cPack_a45tjlCM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_c0vz6sat, 0, m, NULL);
}

void Heavy_SoundScraper::cVar_G1XPK6zO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.5f, 0, m, &cBinop_TPoZ2uhx_sendMessage);
}

void Heavy_SoundScraper::cMsg_vd6gdUrW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_DuBxgyQD_sendMessage);
}

void Heavy_SoundScraper::cSystem_DuBxgyQD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_Nw3Fne69_sendMessage);
}

void Heavy_SoundScraper::cDelay_AUPUVBHW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_AUPUVBHW, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_8BIVRQwA, 0, m, &cDelay_8BIVRQwA_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_AUPUVBHW, 0, m, &cDelay_AUPUVBHW_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_OwXIKauj, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_8BIVRQwA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_8BIVRQwA, m);
  cMsg_QvDxSO7P_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_bJK5OA3b_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_iVWGrgzV_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_3t8P0QYb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_t9XzhNd4_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_sMRYwHe2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_oSIUl037_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_AUPUVBHW, 2, m, &cDelay_AUPUVBHW_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_3i2UnegJ_sendMessage);
}

void Heavy_SoundScraper::cMsg_t9XzhNd4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_sMRYwHe2, 0, m, &hTable_sMRYwHe2_sendMessage);
}

void Heavy_SoundScraper::cBinop_Nw3Fne69_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 5000.0f, 0, m, &cBinop_3t8P0QYb_sendMessage);
}

void Heavy_SoundScraper::cMsg_QvDxSO7P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_sMRYwHe2, 0, m, &hTable_sMRYwHe2_sendMessage);
}

void Heavy_SoundScraper::cCast_3i2UnegJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_AUPUVBHW, 0, m, &cDelay_AUPUVBHW_sendMessage);
}

void Heavy_SoundScraper::cMsg_oSIUl037_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_8BIVRQwA, 2, m, &cDelay_8BIVRQwA_sendMessage);
}

void Heavy_SoundScraper::cMsg_iVWGrgzV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_OwXIKauj, 1, m, NULL);
}

void Heavy_SoundScraper::cMsg_KITo6ATS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_1LirC9eJ_sendMessage);
}

void Heavy_SoundScraper::cSystem_1LirC9eJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_ejwF7Ryt_sendMessage);
}

void Heavy_SoundScraper::cVar_SzbcFAbH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_pY0Sc0OP_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSystem_K80i26ZY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_MeeZjLCe_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_njY9Ofxm, m);
}

void Heavy_SoundScraper::cBinop_ejwF7Ryt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_LjwTSmA8, m);
}

void Heavy_SoundScraper::cMsg_pY0Sc0OP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_K80i26ZY_sendMessage);
}

void Heavy_SoundScraper::cBinop_MeeZjLCe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_N0A1Kr2F, m);
}

void Heavy_SoundScraper::cMsg_NFSFjRJl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_T3ha4GNR_sendMessage);
}

void Heavy_SoundScraper::cSystem_T3ha4GNR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_TZVBwsXz_sendMessage);
}

void Heavy_SoundScraper::cVar_hpvHlXoL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_KnxeTKR9_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSystem_uSdDZyHh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_cy7oFy82_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_FdQ7zxf8, m);
}

void Heavy_SoundScraper::cBinop_TZVBwsXz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_0PKrJtLn, m);
}

void Heavy_SoundScraper::cMsg_KnxeTKR9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_uSdDZyHh_sendMessage);
}

void Heavy_SoundScraper::cBinop_cy7oFy82_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_O1JsRuAR, m);
}

void Heavy_SoundScraper::cBinop_2Q48V8Dc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_0198RHMn_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_KdtHBiyS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_0wXYCPEY_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_EsVjqKn9_sendMessage);
}

void Heavy_SoundScraper::cCast_EsVjqKn9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_2Q48V8Dc, HV_BINOP_DIVIDE, 0, m, &cBinop_2Q48V8Dc_sendMessage);
}

void Heavy_SoundScraper::cCast_0wXYCPEY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_2Q48V8Dc, HV_BINOP_DIVIDE, 1, m, &cBinop_2Q48V8Dc_sendMessage);
}

void Heavy_SoundScraper::cBinop_hRLMnziQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_OSYscVIv_sendMessage);
}

void Heavy_SoundScraper::cBinop_GAhhBhKf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 87.3365f, 0, m, &cBinop_GZrOHVJB_sendMessage);
}

void Heavy_SoundScraper::cBinop_OSYscVIv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_2Q48V8Dc, HV_BINOP_DIVIDE, 0, m, &cBinop_2Q48V8Dc_sendMessage);
}

void Heavy_SoundScraper::cBinop_TPoZ2uhx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_a45tjlCM, 0, m, &cPack_a45tjlCM_sendMessage);
}

void Heavy_SoundScraper::cBinop_5VA4Bj3r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.001f, 0, m, &cBinop_KdtHBiyS_sendMessage);
  cPack_onMessage(_c, &Context(_c)->cPack_5WRLRdQN, 0, m, &cPack_5WRLRdQN_sendMessage);
}

void Heavy_SoundScraper::cMsg_gouEbF8e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 100.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_Kf0VGfsh, 0, m, &cVar_Kf0VGfsh_sendMessage);
}

void Heavy_SoundScraper::cMsg_XBLmNFPB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.5f);
  cVar_onMessage(_c, &Context(_c)->cVar_G1XPK6zO, 0, m, &cVar_G1XPK6zO_sendMessage);
}

void Heavy_SoundScraper::cMsg_0198RHMn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 30.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_Pcfne5it, 0, m, NULL);
}

void Heavy_SoundScraper::cMsg_rpmxuMpZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_W1LmGvqS_sendMessage);
}

void Heavy_SoundScraper::cSystem_W1LmGvqS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_KXiw9ryn_sendMessage);
}

void Heavy_SoundScraper::cVar_oBhsRn85_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_EA4uTe1O_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSystem_HNntHary_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_B64Xf9aT_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_EZAD5Gze, m);
}

void Heavy_SoundScraper::cBinop_KXiw9ryn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_4vQNbW7d, m);
}

void Heavy_SoundScraper::cMsg_EA4uTe1O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_HNntHary_sendMessage);
}

void Heavy_SoundScraper::cBinop_B64Xf9aT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_Br8Tz02Z, m);
}

void Heavy_SoundScraper::cVar_xCLrqwCD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_BzwmfNYe, HV_BINOP_MULTIPLY, 0, m, &cBinop_BzwmfNYe_sendMessage);
}

void Heavy_SoundScraper::cMsg_hTVwU2Ty_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_HBWfkqiB_sendMessage);
}

void Heavy_SoundScraper::cSystem_HBWfkqiB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_DJNXRvcE_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_BzwmfNYe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_IlpSG6DI_sendMessage);
}

void Heavy_SoundScraper::cBinop_iARRNUDL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_BzwmfNYe, HV_BINOP_MULTIPLY, 1, m, &cBinop_BzwmfNYe_sendMessage);
}

void Heavy_SoundScraper::cMsg_DJNXRvcE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_iARRNUDL_sendMessage);
}

void Heavy_SoundScraper::cBinop_IlpSG6DI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_A2CTbrAh_sendMessage);
}

void Heavy_SoundScraper::cBinop_A2CTbrAh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_yjkcTAaL_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_pgji7FqZ, m);
}

void Heavy_SoundScraper::cBinop_yjkcTAaL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_vhqubXcr, m);
}

void Heavy_SoundScraper::cBinop_Yfomiqge_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, -1.0f, 0, m, &cBinop_OdlVTmEj_sendMessage);
}

void Heavy_SoundScraper::cBinop_OdlVTmEj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_HfaUnYke, m);
}

void Heavy_SoundScraper::cBinop_ncdWgaPn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_7raZ84l3_sendMessage);
}

void Heavy_SoundScraper::cBinop_7raZ84l3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_bgt0WI2E_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_rKYPwTEo_sendMessage);
}

void Heavy_SoundScraper::cVar_1xnHjaAd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_I828vHGU_sendMessage);
}

void Heavy_SoundScraper::cMsg_aFTIQgSI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_SQai3UIY_sendMessage);
}

void Heavy_SoundScraper::cSystem_SQai3UIY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_tUGullWe, HV_BINOP_DIVIDE, 1, m, &cBinop_tUGullWe_sendMessage);
}

void Heavy_SoundScraper::cBinop_bgt0WI2E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_RhUv0abD_sendMessage);
}

void Heavy_SoundScraper::cBinop_RhUv0abD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_ZMBkLo27, m);
}

void Heavy_SoundScraper::cMsg_tjoFaLnh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_P0z5TgNG_sendMessage);
}

void Heavy_SoundScraper::cBinop_P0z5TgNG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_ncdWgaPn_sendMessage);
}

void Heavy_SoundScraper::cBinop_rKYPwTEo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_M9shA97f, m);
}

void Heavy_SoundScraper::cBinop_I828vHGU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_B3S1gVm4_sendMessage);
}

void Heavy_SoundScraper::cBinop_B3S1gVm4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_tUGullWe, HV_BINOP_DIVIDE, 0, m, &cBinop_tUGullWe_sendMessage);
}

void Heavy_SoundScraper::cBinop_tUGullWe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_tjoFaLnh_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_udGhWkWj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_oV2PdZsP_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_6xlsfE82_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_6mKBcYTP_sendMessage);
}

void Heavy_SoundScraper::cSystem_6mKBcYTP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_KrUXvosm_sendMessage);
}

void Heavy_SoundScraper::cDelay_zBWwXQ8U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_zBWwXQ8U, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_KgfIui3K, 0, m, &cDelay_KgfIui3K_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_zBWwXQ8U, 0, m, &cDelay_zBWwXQ8U_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_bKDfZCiT, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_KgfIui3K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_KgfIui3K, m);
  cMsg_b9fPEH6l_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_89PrMXNU_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_Q1dyx76F_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_eAPX3TtH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_UlWKJOHF_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_9yO01bfg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_qNqJaNbX_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_zBWwXQ8U, 2, m, &cDelay_zBWwXQ8U_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_vRUJs1Or_sendMessage);
}

void Heavy_SoundScraper::cMsg_UlWKJOHF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_9yO01bfg, 0, m, &hTable_9yO01bfg_sendMessage);
}

void Heavy_SoundScraper::cBinop_KrUXvosm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 200.0f, 0, m, &cBinop_eAPX3TtH_sendMessage);
}

void Heavy_SoundScraper::cMsg_b9fPEH6l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_9yO01bfg, 0, m, &hTable_9yO01bfg_sendMessage);
}

void Heavy_SoundScraper::cCast_vRUJs1Or_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_zBWwXQ8U, 0, m, &cDelay_zBWwXQ8U_sendMessage);
}

void Heavy_SoundScraper::cMsg_qNqJaNbX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_KgfIui3K, 2, m, &cDelay_KgfIui3K_sendMessage);
}

void Heavy_SoundScraper::cMsg_Q1dyx76F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_bKDfZCiT, 1, m, NULL);
}

void Heavy_SoundScraper::cMsg_mJwgkCVT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cMsg_oV2PdZsP_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_oV2PdZsP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 20.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_IaVB52Ee, 0, m, NULL);
}

void Heavy_SoundScraper::cVar_9KHtj5MC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cMsg_oYjTKZuf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_OyQGSTrR_sendMessage);
}

void Heavy_SoundScraper::cSystem_OyQGSTrR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_BhdHEIdg, HV_BINOP_MULTIPLY, 1, m, &cBinop_BhdHEIdg_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_nBnh8cYM, HV_BINOP_MULTIPLY, 1, m, &cBinop_nBnh8cYM_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_vp3glvTL_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cMsg_aZPyroZR_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_aZPyroZR_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_b7AuNzGK_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cDelay_6nDyrfp4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_6nDyrfp4, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_6nDyrfp4, 0, m, &cDelay_6nDyrfp4_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_o4VbzjHR, 0, m, &cVar_o4VbzjHR_sendMessage);
}

void Heavy_SoundScraper::cCast_b7AuNzGK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_aZPyroZR_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_6nDyrfp4, 0, m, &cDelay_6nDyrfp4_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_o4VbzjHR, 0, m, &cVar_o4VbzjHR_sendMessage);
}

void Heavy_SoundScraper::cMsg_REGrMhE1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_GqBj8W4K_sendMessage);
}

void Heavy_SoundScraper::cSystem_GqBj8W4K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_6y2737aS_sendMessage);
}

void Heavy_SoundScraper::cVar_aXruJVKo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_jZHmX1Uq, HV_BINOP_MULTIPLY, 0, m, &cBinop_jZHmX1Uq_sendMessage);
}

void Heavy_SoundScraper::cMsg_aZPyroZR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_6nDyrfp4, 0, m, &cDelay_6nDyrfp4_sendMessage);
}

void Heavy_SoundScraper::cBinop_ndO8oEzf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_6nDyrfp4, 2, m, &cDelay_6nDyrfp4_sendMessage);
}

void Heavy_SoundScraper::cBinop_6y2737aS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_jZHmX1Uq, HV_BINOP_MULTIPLY, 1, m, &cBinop_jZHmX1Uq_sendMessage);
}

void Heavy_SoundScraper::cBinop_jZHmX1Uq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_ndO8oEzf_sendMessage);
}

void Heavy_SoundScraper::cVar_o4VbzjHR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_19PhHHHP, HV_BINOP_SUBTRACT, 0, m, &cBinop_19PhHHHP_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_LESS_THAN_EQL, 0.0f, 0, m, &cBinop_CnSJOdwP_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_v82mv2TN_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Rwvji0NU_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ZDAl7veD_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_Rwvji0NU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_kWPVCn6I, 0, m, &cVar_kWPVCn6I_sendMessage);
}

void Heavy_SoundScraper::cCast_ZDAl7veD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_gtXEbEXc_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_gtX4YD0w_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_C6UcFRXw_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cSlice_onMessage(_c, &Context(_c)->cSlice_PFdOvmcZ, 0, m, &cSlice_PFdOvmcZ_sendMessage);
      break;
    }
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_JjjlbNMR, 0, m, &cSlice_JjjlbNMR_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Y6B8AobN_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_f2J5ooHV, 0, m, &cSlice_f2J5ooHV_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_UW7EP10g, 0, m, &cSlice_UW7EP10g_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_AzO6YC22_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_OVYoMx3P_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cSlice_PFdOvmcZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_ZzgRGXyh_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_ZzgRGXyh_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_JjjlbNMR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ZZsX4OCv_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_W2jx5bzp_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ZZsX4OCv_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_W2jx5bzp_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cVar_3RWtlg0z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_xn61r5ZP_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ropHWTGR_sendMessage);
}

void Heavy_SoundScraper::cVar_5J9dVY4X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_xXRKCpWb_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cSwitchcase_xXRKCpWb_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_w0dwziMy_sendMessage);
      break;
    }
    default: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_BhdHEIdg, HV_BINOP_MULTIPLY, 0, m, &cBinop_BhdHEIdg_sendMessage);
      cBinop_onMessage(_c, &Context(_c)->cBinop_msGSOL38, HV_BINOP_DIVIDE, 1, m, &cBinop_msGSOL38_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_aXruJVKo, 0, m, &cVar_aXruJVKo_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_w0dwziMy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_cdJyyTnJ_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_aCHYjPwB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_e6l5jBY0, HV_BINOP_SUBTRACT, 1, m, &cBinop_e6l5jBY0_sendMessage);
}

void Heavy_SoundScraper::cVar_zlj0xaR5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_kWPVCn6I, 0, m, &cVar_kWPVCn6I_sendMessage);
}

void Heavy_SoundScraper::cVar_kWPVCn6I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_fFSnciQ6, HV_BINOP_ADD, 0, m, &cBinop_fFSnciQ6_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_YL4nbDdX, HV_BINOP_ADD, 0, m, &cBinop_YL4nbDdX_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_LcoOvPlc, 0, m, &cVar_LcoOvPlc_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.05776f, 0, m, &cBinop_GAhhBhKf_sendMessage);
}

void Heavy_SoundScraper::cSlice_f2J5ooHV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_xn61r5ZP_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ropHWTGR_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_UW7EP10g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_eodiaU8e_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_hcNoUQmF_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_dMWf3iik_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_o4VbzjHR, 1, m, &cVar_o4VbzjHR_sendMessage);
}

void Heavy_SoundScraper::cBinop_nBnh8cYM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_dMWf3iik_sendMessage);
}

void Heavy_SoundScraper::cBinop_BhdHEIdg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_wVCporSC_sendMessage);
}

void Heavy_SoundScraper::cBinop_wVCporSC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_19PhHHHP, HV_BINOP_SUBTRACT, 1, m, &cBinop_19PhHHHP_sendMessage);
}

void Heavy_SoundScraper::cBinop_19PhHHHP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_o4VbzjHR, 1, m, &cVar_o4VbzjHR_sendMessage);
}

void Heavy_SoundScraper::cMsg_ZufntvKE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_vp3glvTL_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cMsg_jtUYfmbY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_vp3glvTL_onMessage(_c, NULL, 0, m, NULL);
  cBinop_onMessage(_c, &Context(_c)->cBinop_YL4nbDdX, HV_BINOP_ADD, 1, m, &cBinop_YL4nbDdX_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_fFSnciQ6, HV_BINOP_ADD, 1, m, &cBinop_fFSnciQ6_sendMessage);
}

void Heavy_SoundScraper::cBinop_CnSJOdwP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_v82mv2TN_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_fFSnciQ6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_kWPVCn6I, 1, m, &cVar_kWPVCn6I_sendMessage);
}

void Heavy_SoundScraper::cBinop_msGSOL38_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_YvoQElAg, HV_BINOP_DIVIDE, 1, m, &cBinop_YvoQElAg_sendMessage);
}

void Heavy_SoundScraper::cBinop_YvoQElAg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_YL4nbDdX, HV_BINOP_ADD, 1, m, &cBinop_YL4nbDdX_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_fFSnciQ6, HV_BINOP_ADD, 1, m, &cBinop_fFSnciQ6_sendMessage);
}

void Heavy_SoundScraper::cCast_ropHWTGR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_msGSOL38, HV_BINOP_DIVIDE, 0, m, &cBinop_msGSOL38_sendMessage);
}

void Heavy_SoundScraper::cCast_xn61r5ZP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_nBnh8cYM, HV_BINOP_MULTIPLY, 0, m, &cBinop_nBnh8cYM_sendMessage);
}

void Heavy_SoundScraper::cCast_eodiaU8e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_zlj0xaR5, 1, m, &cVar_zlj0xaR5_sendMessage);
}

void Heavy_SoundScraper::cCast_hcNoUQmF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_e6l5jBY0, HV_BINOP_SUBTRACT, 0, m, &cBinop_e6l5jBY0_sendMessage);
}

void Heavy_SoundScraper::cCast_gtX4YD0w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_zlj0xaR5, 0, m, &cVar_zlj0xaR5_sendMessage);
}

void Heavy_SoundScraper::cCast_gtXEbEXc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_jtUYfmbY_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_YL4nbDdX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_aCHYjPwB, 0, m, &cVar_aCHYjPwB_sendMessage);
}

void Heavy_SoundScraper::cMsg_ZzgRGXyh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_vp3glvTL_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cMsg_T0iGWPak_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_3RWtlg0z, 1, m, &cVar_3RWtlg0z_sendMessage);
}

void Heavy_SoundScraper::cMsg_cdJyyTnJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 20.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_BhdHEIdg, HV_BINOP_MULTIPLY, 0, m, &cBinop_BhdHEIdg_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_msGSOL38, HV_BINOP_DIVIDE, 1, m, &cBinop_msGSOL38_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_aXruJVKo, 0, m, &cVar_aXruJVKo_sendMessage);
}

void Heavy_SoundScraper::cCast_ZZsX4OCv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ZzgRGXyh_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_W2jx5bzp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_105twQbm_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_YL4nbDdX, HV_BINOP_ADD, 0, m, &cBinop_YL4nbDdX_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_kWPVCn6I, 1, m, &cVar_kWPVCn6I_sendMessage);
}

void Heavy_SoundScraper::cBinop_e6l5jBY0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_YvoQElAg, HV_BINOP_DIVIDE, 0, m, &cBinop_YvoQElAg_sendMessage);
}

void Heavy_SoundScraper::cCast_105twQbm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_jtUYfmbY_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_Y6B8AobN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_3RWtlg0z, 0, m, &cVar_3RWtlg0z_sendMessage);
}

void Heavy_SoundScraper::cCast_OVYoMx3P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_T0iGWPak_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_AzO6YC22_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ZufntvKE_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_LcoOvPlc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cPack_yytqlwcz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_C6UcFRXw_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cMsg_RJjx0qOy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_vYhzfjiE_sendMessage);
}

void Heavy_SoundScraper::cSystem_vYhzfjiE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_DHoLjx8J, HV_BINOP_MULTIPLY, 1, m, &cBinop_DHoLjx8J_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_Cvm8ZXMI, HV_BINOP_MULTIPLY, 1, m, &cBinop_Cvm8ZXMI_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_RCl4XFqQ_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cMsg_7knXreEJ_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_7knXreEJ_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_yqIyOy9w_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cDelay_K4nmsUfn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_K4nmsUfn, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_K4nmsUfn, 0, m, &cDelay_K4nmsUfn_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_STqvoCdQ, 0, m, &cVar_STqvoCdQ_sendMessage);
}

void Heavy_SoundScraper::cCast_yqIyOy9w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_7knXreEJ_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_K4nmsUfn, 0, m, &cDelay_K4nmsUfn_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_STqvoCdQ, 0, m, &cVar_STqvoCdQ_sendMessage);
}

void Heavy_SoundScraper::cMsg_9zV9bvOy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_KbpGWuUA_sendMessage);
}

void Heavy_SoundScraper::cSystem_KbpGWuUA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_FQlctxEa_sendMessage);
}

void Heavy_SoundScraper::cVar_Z7aFCRjz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_1USANWln, HV_BINOP_MULTIPLY, 0, m, &cBinop_1USANWln_sendMessage);
}

void Heavy_SoundScraper::cMsg_7knXreEJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_K4nmsUfn, 0, m, &cDelay_K4nmsUfn_sendMessage);
}

void Heavy_SoundScraper::cBinop_4G3ahJwy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_K4nmsUfn, 2, m, &cDelay_K4nmsUfn_sendMessage);
}

void Heavy_SoundScraper::cBinop_FQlctxEa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_1USANWln, HV_BINOP_MULTIPLY, 1, m, &cBinop_1USANWln_sendMessage);
}

void Heavy_SoundScraper::cBinop_1USANWln_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_4G3ahJwy_sendMessage);
}

void Heavy_SoundScraper::cVar_STqvoCdQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_VUN6eP1t, HV_BINOP_SUBTRACT, 0, m, &cBinop_VUN6eP1t_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_LESS_THAN_EQL, 0.0f, 0, m, &cBinop_TfAJmblX_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_viTzOqwp_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_gWu6DEzK_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_VwwOHJNJ_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_gWu6DEzK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_iqfM5VMu, 0, m, &cVar_iqfM5VMu_sendMessage);
}

void Heavy_SoundScraper::cCast_VwwOHJNJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_CeTxgsaT_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_R6QIUr7R_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_nxTJSEGi_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cSlice_onMessage(_c, &Context(_c)->cSlice_h0bVWvnz, 0, m, &cSlice_h0bVWvnz_sendMessage);
      break;
    }
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_t8a0Q4oK, 0, m, &cSlice_t8a0Q4oK_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_T8gKnbEn_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_Msftsw0G, 0, m, &cSlice_Msftsw0G_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_SVEYS63i, 0, m, &cSlice_SVEYS63i_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_QuxcNkdh_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_TmpC6wd9_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cSlice_h0bVWvnz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_fdIj16Zq_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_fdIj16Zq_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_t8a0Q4oK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_yaF0vc0I_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_PcufOttR_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_yaF0vc0I_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_PcufOttR_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cVar_2f5ORazZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_gSBMJ8Ex_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_k890jWHf_sendMessage);
}

void Heavy_SoundScraper::cVar_9tg7n64e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_V9dXRQRx_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cSwitchcase_V9dXRQRx_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_4spHmiNi_sendMessage);
      break;
    }
    default: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_DHoLjx8J, HV_BINOP_MULTIPLY, 0, m, &cBinop_DHoLjx8J_sendMessage);
      cBinop_onMessage(_c, &Context(_c)->cBinop_mE81p5ad, HV_BINOP_DIVIDE, 1, m, &cBinop_mE81p5ad_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_Z7aFCRjz, 0, m, &cVar_Z7aFCRjz_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_4spHmiNi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_QymSxdBm_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_T4OFEPGA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4c0adzPb, HV_BINOP_SUBTRACT, 1, m, &cBinop_4c0adzPb_sendMessage);
}

void Heavy_SoundScraper::cVar_QlDcJrpl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_iqfM5VMu, 0, m, &cVar_iqfM5VMu_sendMessage);
}

void Heavy_SoundScraper::cVar_iqfM5VMu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_kC3oWS3I, HV_BINOP_ADD, 0, m, &cBinop_kC3oWS3I_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_TSLYVnVf, HV_BINOP_ADD, 0, m, &cBinop_TSLYVnVf_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_9KHtj5MC, 0, m, &cVar_9KHtj5MC_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_xPvk0wcy, m);
}

void Heavy_SoundScraper::cSlice_Msftsw0G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_gSBMJ8Ex_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_k890jWHf_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_SVEYS63i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_158GEjrT_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_AdD4C1Rs_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_gLDds5nj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_STqvoCdQ, 1, m, &cVar_STqvoCdQ_sendMessage);
}

void Heavy_SoundScraper::cBinop_Cvm8ZXMI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_gLDds5nj_sendMessage);
}

void Heavy_SoundScraper::cBinop_DHoLjx8J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_AUtSWbVG_sendMessage);
}

void Heavy_SoundScraper::cBinop_AUtSWbVG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_VUN6eP1t, HV_BINOP_SUBTRACT, 1, m, &cBinop_VUN6eP1t_sendMessage);
}

void Heavy_SoundScraper::cBinop_VUN6eP1t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_STqvoCdQ, 1, m, &cVar_STqvoCdQ_sendMessage);
}

void Heavy_SoundScraper::cMsg_Bc8aEjKS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_RCl4XFqQ_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cMsg_SKPDrlvo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_RCl4XFqQ_onMessage(_c, NULL, 0, m, NULL);
  cBinop_onMessage(_c, &Context(_c)->cBinop_TSLYVnVf, HV_BINOP_ADD, 1, m, &cBinop_TSLYVnVf_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_kC3oWS3I, HV_BINOP_ADD, 1, m, &cBinop_kC3oWS3I_sendMessage);
}

void Heavy_SoundScraper::cBinop_TfAJmblX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_viTzOqwp_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_kC3oWS3I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_iqfM5VMu, 1, m, &cVar_iqfM5VMu_sendMessage);
}

void Heavy_SoundScraper::cBinop_mE81p5ad_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6ZtwFiIn, HV_BINOP_DIVIDE, 1, m, &cBinop_6ZtwFiIn_sendMessage);
}

void Heavy_SoundScraper::cBinop_6ZtwFiIn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_TSLYVnVf, HV_BINOP_ADD, 1, m, &cBinop_TSLYVnVf_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_kC3oWS3I, HV_BINOP_ADD, 1, m, &cBinop_kC3oWS3I_sendMessage);
}

void Heavy_SoundScraper::cCast_k890jWHf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_mE81p5ad, HV_BINOP_DIVIDE, 0, m, &cBinop_mE81p5ad_sendMessage);
}

void Heavy_SoundScraper::cCast_gSBMJ8Ex_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Cvm8ZXMI, HV_BINOP_MULTIPLY, 0, m, &cBinop_Cvm8ZXMI_sendMessage);
}

void Heavy_SoundScraper::cCast_AdD4C1Rs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4c0adzPb, HV_BINOP_SUBTRACT, 0, m, &cBinop_4c0adzPb_sendMessage);
}

void Heavy_SoundScraper::cCast_158GEjrT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_QlDcJrpl, 1, m, &cVar_QlDcJrpl_sendMessage);
}

void Heavy_SoundScraper::cCast_R6QIUr7R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_QlDcJrpl, 0, m, &cVar_QlDcJrpl_sendMessage);
}

void Heavy_SoundScraper::cCast_CeTxgsaT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_SKPDrlvo_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_TSLYVnVf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_T4OFEPGA, 0, m, &cVar_T4OFEPGA_sendMessage);
}

void Heavy_SoundScraper::cMsg_fdIj16Zq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_RCl4XFqQ_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cMsg_EWtLntfp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_2f5ORazZ, 1, m, &cVar_2f5ORazZ_sendMessage);
}

void Heavy_SoundScraper::cMsg_QymSxdBm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 20.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_DHoLjx8J, HV_BINOP_MULTIPLY, 0, m, &cBinop_DHoLjx8J_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_mE81p5ad, HV_BINOP_DIVIDE, 1, m, &cBinop_mE81p5ad_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_Z7aFCRjz, 0, m, &cVar_Z7aFCRjz_sendMessage);
}

void Heavy_SoundScraper::cCast_yaF0vc0I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_fdIj16Zq_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_PcufOttR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_CqxTT9vR_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_TSLYVnVf, HV_BINOP_ADD, 0, m, &cBinop_TSLYVnVf_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_iqfM5VMu, 1, m, &cVar_iqfM5VMu_sendMessage);
}

void Heavy_SoundScraper::cBinop_4c0adzPb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6ZtwFiIn, HV_BINOP_DIVIDE, 0, m, &cBinop_6ZtwFiIn_sendMessage);
}

void Heavy_SoundScraper::cCast_CqxTT9vR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_SKPDrlvo_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_QuxcNkdh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Bc8aEjKS_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_T8gKnbEn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_2f5ORazZ, 0, m, &cVar_2f5ORazZ_sendMessage);
}

void Heavy_SoundScraper::cCast_TmpC6wd9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_EWtLntfp_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_6fBOyrFL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_nxTJSEGi_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cPack_RTeLKE1d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_Nnx4w0Pj, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_0CvkLmFf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 4.0f, 0, m, &cBinop_Q1vJ3S64_sendMessage);
}

void Heavy_SoundScraper::cBinop_Q1vJ3S64_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_yytqlwcz, 0, m, &cPack_yytqlwcz_sendMessage);
}

void Heavy_SoundScraper::cBinop_i9yazbPk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_0CvkLmFf_sendMessage);
}

void Heavy_SoundScraper::cCast_TK7779oI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_Lz7x9zEp_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_mM3Pp2AW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_Ko8rSen0_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cMsg_SRJyRjsZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.15f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_Yfomiqge_sendMessage);
}

void Heavy_SoundScraper::cTabhead_QvY2LiNE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_dTeYXrDl, HV_BINOP_SUBTRACT, 0, m, &cBinop_dTeYXrDl_sendMessage);
}

void Heavy_SoundScraper::cMsg_hfXqsQkG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_wHkLSxcd_sendMessage);
}

void Heavy_SoundScraper::cSystem_wHkLSxcd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_VCxKoYXU_sendMessage);
}

void Heavy_SoundScraper::cVar_tC4XMKnA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_biQ8DOp1_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_oAJaFN2e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_oAJaFN2e, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_gbMGHkCV, 0, m, &cDelay_gbMGHkCV_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_HVCRVxfI, 0, m, &sTabread_HVCRVxfI_sendMessage);
}

void Heavy_SoundScraper::cDelay_gbMGHkCV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_gbMGHkCV, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_HVCRVxfI, 0, m, &sTabread_HVCRVxfI_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_gbMGHkCV, 0, m, &cDelay_gbMGHkCV_sendMessage);
}

void Heavy_SoundScraper::sTabread_HVCRVxfI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_60Y6DHJp, HV_BINOP_SUBTRACT, 0, m, &cBinop_60Y6DHJp_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_oEi5QTal_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_z6foeIOP, HV_BINOP_MAX, 0, m, &cBinop_z6foeIOP_sendMessage);
}

void Heavy_SoundScraper::cBinop_VCxKoYXU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_oEi5QTal, HV_BINOP_MULTIPLY, 0, m, &cBinop_oEi5QTal_sendMessage);
}

void Heavy_SoundScraper::cBinop_dTeYXrDl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_mGG9YKTz_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_HVCRVxfI, 0, m, &sTabread_HVCRVxfI_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_nHSEcVh0_sendMessage);
}

void Heavy_SoundScraper::cSystem_5wMZkFtl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_60Y6DHJp, HV_BINOP_SUBTRACT, 1, m, &cBinop_60Y6DHJp_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_gbMGHkCV, 2, m, &cDelay_gbMGHkCV_sendMessage);
}

void Heavy_SoundScraper::cMsg_biQ8DOp1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_5wMZkFtl_sendMessage);
}

void Heavy_SoundScraper::cMsg_mGG9YKTz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_oAJaFN2e, 0, m, &cDelay_oAJaFN2e_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_gbMGHkCV, 0, m, &cDelay_gbMGHkCV_sendMessage);
}

void Heavy_SoundScraper::cMsg_IgF8c0jX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_z6foeIOP, HV_BINOP_MAX, 1, m, &cBinop_z6foeIOP_sendMessage);
}

void Heavy_SoundScraper::cBinop_z6foeIOP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_dTeYXrDl, HV_BINOP_SUBTRACT, 1, m, &cBinop_dTeYXrDl_sendMessage);
}

void Heavy_SoundScraper::cCast_nHSEcVh0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_oAJaFN2e, 0, m, &cDelay_oAJaFN2e_sendMessage);
}

void Heavy_SoundScraper::cBinop_IqeOyFGH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_oAJaFN2e, 2, m, &cDelay_oAJaFN2e_sendMessage);
}

void Heavy_SoundScraper::cBinop_60Y6DHJp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_IqeOyFGH_sendMessage);
}

void Heavy_SoundScraper::cCast_7qLkrsYa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_tC4XMKnA, 0, m, &cVar_tC4XMKnA_sendMessage);
  cMsg_hfXqsQkG_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_QvY2LiNE, 0, m, &cTabhead_QvY2LiNE_sendMessage);
}

void Heavy_SoundScraper::cTabhead_bhvaQbli_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_pSESNx1L, HV_BINOP_SUBTRACT, 0, m, &cBinop_pSESNx1L_sendMessage);
}

void Heavy_SoundScraper::cMsg_gVfgEHLC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_2lLVrvuj_sendMessage);
}

void Heavy_SoundScraper::cSystem_2lLVrvuj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_EZ3rqkhL_sendMessage);
}

void Heavy_SoundScraper::cVar_C2sSl45I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_8TVwcL63_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_JtdhoKH8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_JtdhoKH8, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Cmw50uta, 0, m, &cDelay_Cmw50uta_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_2hC6Db7E, 0, m, &sTabread_2hC6Db7E_sendMessage);
}

void Heavy_SoundScraper::cDelay_Cmw50uta_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Cmw50uta, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_2hC6Db7E, 0, m, &sTabread_2hC6Db7E_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Cmw50uta, 0, m, &cDelay_Cmw50uta_sendMessage);
}

void Heavy_SoundScraper::sTabread_2hC6Db7E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_hzJtDlwu, HV_BINOP_SUBTRACT, 0, m, &cBinop_hzJtDlwu_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_d852eafI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_7Rp98ZKp, HV_BINOP_MAX, 0, m, &cBinop_7Rp98ZKp_sendMessage);
}

void Heavy_SoundScraper::cBinop_EZ3rqkhL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_d852eafI, HV_BINOP_MULTIPLY, 0, m, &cBinop_d852eafI_sendMessage);
}

void Heavy_SoundScraper::cBinop_pSESNx1L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_f8TfY2kr_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_2hC6Db7E, 0, m, &sTabread_2hC6Db7E_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_hQCnnoqr_sendMessage);
}

void Heavy_SoundScraper::cSystem_brJ0wSEp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_hzJtDlwu, HV_BINOP_SUBTRACT, 1, m, &cBinop_hzJtDlwu_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Cmw50uta, 2, m, &cDelay_Cmw50uta_sendMessage);
}

void Heavy_SoundScraper::cMsg_8TVwcL63_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_brJ0wSEp_sendMessage);
}

void Heavy_SoundScraper::cMsg_f8TfY2kr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_JtdhoKH8, 0, m, &cDelay_JtdhoKH8_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Cmw50uta, 0, m, &cDelay_Cmw50uta_sendMessage);
}

void Heavy_SoundScraper::cMsg_XQxSTKdb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_7Rp98ZKp, HV_BINOP_MAX, 1, m, &cBinop_7Rp98ZKp_sendMessage);
}

void Heavy_SoundScraper::cBinop_7Rp98ZKp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_pSESNx1L, HV_BINOP_SUBTRACT, 1, m, &cBinop_pSESNx1L_sendMessage);
}

void Heavy_SoundScraper::cCast_hQCnnoqr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_JtdhoKH8, 0, m, &cDelay_JtdhoKH8_sendMessage);
}

void Heavy_SoundScraper::cBinop_Fd27Poe7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_JtdhoKH8, 2, m, &cDelay_JtdhoKH8_sendMessage);
}

void Heavy_SoundScraper::cBinop_hzJtDlwu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_Fd27Poe7_sendMessage);
}

void Heavy_SoundScraper::cCast_777sYmud_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_C2sSl45I, 0, m, &cVar_C2sSl45I_sendMessage);
  cMsg_gVfgEHLC_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_bhvaQbli, 0, m, &cTabhead_bhvaQbli_sendMessage);
}

void Heavy_SoundScraper::cTabhead_RUe0Gccm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_3Qs4lRF4, HV_BINOP_SUBTRACT, 0, m, &cBinop_3Qs4lRF4_sendMessage);
}

void Heavy_SoundScraper::cMsg_dOZ7u3v4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_FOOykeQw_sendMessage);
}

void Heavy_SoundScraper::cSystem_FOOykeQw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_Os9g5QhH_sendMessage);
}

void Heavy_SoundScraper::cVar_WsqgjK17_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_tBtNVyGD_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_RVzz8WDl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_RVzz8WDl, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_0EwTKcIM, 0, m, &cDelay_0EwTKcIM_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_gQLapaUV, 0, m, &sTabread_gQLapaUV_sendMessage);
}

void Heavy_SoundScraper::cDelay_0EwTKcIM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_0EwTKcIM, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_gQLapaUV, 0, m, &sTabread_gQLapaUV_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_0EwTKcIM, 0, m, &cDelay_0EwTKcIM_sendMessage);
}

void Heavy_SoundScraper::sTabread_gQLapaUV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_r2Y1O77v, HV_BINOP_SUBTRACT, 0, m, &cBinop_r2Y1O77v_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_rcS4PaEl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ulxFy8cF, HV_BINOP_MAX, 0, m, &cBinop_ulxFy8cF_sendMessage);
}

void Heavy_SoundScraper::cBinop_Os9g5QhH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_rcS4PaEl, HV_BINOP_MULTIPLY, 0, m, &cBinop_rcS4PaEl_sendMessage);
}

void Heavy_SoundScraper::cBinop_3Qs4lRF4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_rlXHysxw_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_gQLapaUV, 0, m, &sTabread_gQLapaUV_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_lKMS92qk_sendMessage);
}

void Heavy_SoundScraper::cSystem_5lIKSIWs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_r2Y1O77v, HV_BINOP_SUBTRACT, 1, m, &cBinop_r2Y1O77v_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_0EwTKcIM, 2, m, &cDelay_0EwTKcIM_sendMessage);
}

void Heavy_SoundScraper::cMsg_tBtNVyGD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_5lIKSIWs_sendMessage);
}

void Heavy_SoundScraper::cMsg_rlXHysxw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_RVzz8WDl, 0, m, &cDelay_RVzz8WDl_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_0EwTKcIM, 0, m, &cDelay_0EwTKcIM_sendMessage);
}

void Heavy_SoundScraper::cMsg_iwumyRPN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_ulxFy8cF, HV_BINOP_MAX, 1, m, &cBinop_ulxFy8cF_sendMessage);
}

void Heavy_SoundScraper::cBinop_ulxFy8cF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_3Qs4lRF4, HV_BINOP_SUBTRACT, 1, m, &cBinop_3Qs4lRF4_sendMessage);
}

void Heavy_SoundScraper::cCast_lKMS92qk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_RVzz8WDl, 0, m, &cDelay_RVzz8WDl_sendMessage);
}

void Heavy_SoundScraper::cBinop_WTVkbRJt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_RVzz8WDl, 2, m, &cDelay_RVzz8WDl_sendMessage);
}

void Heavy_SoundScraper::cBinop_r2Y1O77v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_WTVkbRJt_sendMessage);
}

void Heavy_SoundScraper::cCast_sc82cikp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_WsqgjK17, 0, m, &cVar_WsqgjK17_sendMessage);
  cMsg_dOZ7u3v4_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_RUe0Gccm, 0, m, &cTabhead_RUe0Gccm_sendMessage);
}

void Heavy_SoundScraper::cTabhead_5fdu0lwC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_HU1mWRQM, HV_BINOP_SUBTRACT, 0, m, &cBinop_HU1mWRQM_sendMessage);
}

void Heavy_SoundScraper::cMsg_Nug95GVn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_xspeYekF_sendMessage);
}

void Heavy_SoundScraper::cSystem_xspeYekF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_iyeOaHyJ_sendMessage);
}

void Heavy_SoundScraper::cVar_rMzr815S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ZIjfCKR6_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_QUnvqiZs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_QUnvqiZs, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_9RKKk7vP, 0, m, &cDelay_9RKKk7vP_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_3YatQhob, 0, m, &sTabread_3YatQhob_sendMessage);
}

void Heavy_SoundScraper::cDelay_9RKKk7vP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_9RKKk7vP, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_3YatQhob, 0, m, &sTabread_3YatQhob_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_9RKKk7vP, 0, m, &cDelay_9RKKk7vP_sendMessage);
}

void Heavy_SoundScraper::sTabread_3YatQhob_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_n4ZN10g3, HV_BINOP_SUBTRACT, 0, m, &cBinop_n4ZN10g3_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_1X4S67RQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_wVQDbl12, HV_BINOP_MAX, 0, m, &cBinop_wVQDbl12_sendMessage);
}

void Heavy_SoundScraper::cBinop_iyeOaHyJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_1X4S67RQ, HV_BINOP_MULTIPLY, 0, m, &cBinop_1X4S67RQ_sendMessage);
}

void Heavy_SoundScraper::cBinop_HU1mWRQM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_7JZKa3Sq_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_3YatQhob, 0, m, &sTabread_3YatQhob_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Ne6bqV7G_sendMessage);
}

void Heavy_SoundScraper::cSystem_LQtT2np5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_n4ZN10g3, HV_BINOP_SUBTRACT, 1, m, &cBinop_n4ZN10g3_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_9RKKk7vP, 2, m, &cDelay_9RKKk7vP_sendMessage);
}

void Heavy_SoundScraper::cMsg_ZIjfCKR6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_LQtT2np5_sendMessage);
}

void Heavy_SoundScraper::cMsg_7JZKa3Sq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_QUnvqiZs, 0, m, &cDelay_QUnvqiZs_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_9RKKk7vP, 0, m, &cDelay_9RKKk7vP_sendMessage);
}

void Heavy_SoundScraper::cMsg_afyZn4jf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_wVQDbl12, HV_BINOP_MAX, 1, m, &cBinop_wVQDbl12_sendMessage);
}

void Heavy_SoundScraper::cBinop_wVQDbl12_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_HU1mWRQM, HV_BINOP_SUBTRACT, 1, m, &cBinop_HU1mWRQM_sendMessage);
}

void Heavy_SoundScraper::cCast_Ne6bqV7G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_QUnvqiZs, 0, m, &cDelay_QUnvqiZs_sendMessage);
}

void Heavy_SoundScraper::cBinop_VPO9AnZF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_QUnvqiZs, 2, m, &cDelay_QUnvqiZs_sendMessage);
}

void Heavy_SoundScraper::cBinop_n4ZN10g3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_VPO9AnZF_sendMessage);
}

void Heavy_SoundScraper::cCast_dsivHj0Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_rMzr815S, 0, m, &cVar_rMzr815S_sendMessage);
  cMsg_Nug95GVn_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_5fdu0lwC, 0, m, &cTabhead_5fdu0lwC_sendMessage);
}

void Heavy_SoundScraper::cMsg_wl4V3pBM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_HejdB0qI_sendMessage);
}

void Heavy_SoundScraper::cSystem_HejdB0qI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_BaqXlDLw_sendMessage);
}

void Heavy_SoundScraper::cDelay_Dz25kfaK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Dz25kfaK, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_qfi60WnN, 0, m, &cDelay_qfi60WnN_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Dz25kfaK, 0, m, &cDelay_Dz25kfaK_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_koAtA5XQ, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_qfi60WnN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_qfi60WnN, m);
  cMsg_hTOp4hhQ_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_yjimVMjq_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_QkAiqsHW_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_6p8AaVIr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_fU8V6j4G_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_NR1Sx6Hm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_2faK7hgf_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Dz25kfaK, 2, m, &cDelay_Dz25kfaK_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_yBoIKa0T_sendMessage);
}

void Heavy_SoundScraper::cMsg_fU8V6j4G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_NR1Sx6Hm, 0, m, &hTable_NR1Sx6Hm_sendMessage);
}

void Heavy_SoundScraper::cBinop_BaqXlDLw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 58.6435f, 0, m, &cBinop_6p8AaVIr_sendMessage);
}

void Heavy_SoundScraper::cMsg_hTOp4hhQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_NR1Sx6Hm, 0, m, &hTable_NR1Sx6Hm_sendMessage);
}

void Heavy_SoundScraper::cCast_yBoIKa0T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Dz25kfaK, 0, m, &cDelay_Dz25kfaK_sendMessage);
}

void Heavy_SoundScraper::cMsg_2faK7hgf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_qfi60WnN, 2, m, &cDelay_qfi60WnN_sendMessage);
}

void Heavy_SoundScraper::cMsg_QkAiqsHW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_koAtA5XQ, 1, m, NULL);
}

void Heavy_SoundScraper::cMsg_isVZbgCQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_lnTeZs1i_sendMessage);
}

void Heavy_SoundScraper::cSystem_lnTeZs1i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_aGfi79ST_sendMessage);
}

void Heavy_SoundScraper::cDelay_KiIdWzNx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_KiIdWzNx, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_XM4zDGKL, 0, m, &cDelay_XM4zDGKL_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_KiIdWzNx, 0, m, &cDelay_KiIdWzNx_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_BOOP7cdA, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_XM4zDGKL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_XM4zDGKL, m);
  cMsg_eyfFMbLo_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_BtcjeioU_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_6M54XhjA_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_xrVKX8v5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_YPHKjBtG_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_RRX9To4g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_fh1wYDZT_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_KiIdWzNx, 2, m, &cDelay_KiIdWzNx_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_lWQQ5Guo_sendMessage);
}

void Heavy_SoundScraper::cMsg_YPHKjBtG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_RRX9To4g, 0, m, &hTable_RRX9To4g_sendMessage);
}

void Heavy_SoundScraper::cBinop_aGfi79ST_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 69.4325f, 0, m, &cBinop_xrVKX8v5_sendMessage);
}

void Heavy_SoundScraper::cMsg_eyfFMbLo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_RRX9To4g, 0, m, &hTable_RRX9To4g_sendMessage);
}

void Heavy_SoundScraper::cCast_lWQQ5Guo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_KiIdWzNx, 0, m, &cDelay_KiIdWzNx_sendMessage);
}

void Heavy_SoundScraper::cMsg_fh1wYDZT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_XM4zDGKL, 2, m, &cDelay_XM4zDGKL_sendMessage);
}

void Heavy_SoundScraper::cMsg_6M54XhjA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_BOOP7cdA, 1, m, NULL);
}

void Heavy_SoundScraper::cMsg_AZRcK4Kd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_jkjYTr4i_sendMessage);
}

void Heavy_SoundScraper::cSystem_jkjYTr4i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_VCfF94QI_sendMessage);
}

void Heavy_SoundScraper::cDelay_gHmZVaUV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_gHmZVaUV, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_33JGHF2k, 0, m, &cDelay_33JGHF2k_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_gHmZVaUV, 0, m, &cDelay_gHmZVaUV_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_0oIs1K0q, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_33JGHF2k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_33JGHF2k, m);
  cMsg_iRuLM96g_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_s4lgskYQ_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_mznZXOon_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_spbpaysX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_v10JKzDG_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_xSiPWMdz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_4jfIZRkJ_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_gHmZVaUV, 2, m, &cDelay_gHmZVaUV_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_iu2DVNLA_sendMessage);
}

void Heavy_SoundScraper::cMsg_v10JKzDG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_xSiPWMdz, 0, m, &hTable_xSiPWMdz_sendMessage);
}

void Heavy_SoundScraper::cBinop_VCfF94QI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 74.5234f, 0, m, &cBinop_spbpaysX_sendMessage);
}

void Heavy_SoundScraper::cMsg_iRuLM96g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_xSiPWMdz, 0, m, &hTable_xSiPWMdz_sendMessage);
}

void Heavy_SoundScraper::cCast_iu2DVNLA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_gHmZVaUV, 0, m, &cDelay_gHmZVaUV_sendMessage);
}

void Heavy_SoundScraper::cMsg_4jfIZRkJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_33JGHF2k, 2, m, &cDelay_33JGHF2k_sendMessage);
}

void Heavy_SoundScraper::cMsg_mznZXOon_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_0oIs1K0q, 1, m, NULL);
}

void Heavy_SoundScraper::cMsg_EmlSyUeV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ffUPLbFE_sendMessage);
}

void Heavy_SoundScraper::cSystem_ffUPLbFE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_4GwKD36I_sendMessage);
}

void Heavy_SoundScraper::cDelay_N8PZ3q9n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_N8PZ3q9n, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_CDRwGiyD, 0, m, &cDelay_CDRwGiyD_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_N8PZ3q9n, 0, m, &cDelay_N8PZ3q9n_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_E7kC2rzN, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_CDRwGiyD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_CDRwGiyD, m);
  cMsg_QnVcFAzr_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_OkGwrc7Y_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_BRN8ZStr_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_Pa8bySSt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_u1iX7DwH_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_fgnk3ARH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_uopjriLu_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_N8PZ3q9n, 2, m, &cDelay_N8PZ3q9n_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_5GH5ymQZ_sendMessage);
}

void Heavy_SoundScraper::cMsg_u1iX7DwH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_fgnk3ARH, 0, m, &hTable_fgnk3ARH_sendMessage);
}

void Heavy_SoundScraper::cBinop_4GwKD36I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 86.1244f, 0, m, &cBinop_Pa8bySSt_sendMessage);
}

void Heavy_SoundScraper::cMsg_QnVcFAzr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_fgnk3ARH, 0, m, &hTable_fgnk3ARH_sendMessage);
}

void Heavy_SoundScraper::cCast_5GH5ymQZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_N8PZ3q9n, 0, m, &cDelay_N8PZ3q9n_sendMessage);
}

void Heavy_SoundScraper::cMsg_uopjriLu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_CDRwGiyD, 2, m, &cDelay_CDRwGiyD_sendMessage);
}

void Heavy_SoundScraper::cMsg_BRN8ZStr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_E7kC2rzN, 1, m, NULL);
}

void Heavy_SoundScraper::cIf_5sa7txuN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_UbM5NOIm_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_aTcjU49t_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cMsg_n9Dxe89O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_BVKbHj9d, HV_BINOP_POW, 0, m, &cBinop_BVKbHj9d_sendMessage);
}

void Heavy_SoundScraper::cBinop_BVKbHj9d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.125f, 0, m, &cBinop_CbpReXvW_sendMessage);
}

void Heavy_SoundScraper::cBinop_RkBAMk2f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_jIkVcsB2_sendMessage);
}

void Heavy_SoundScraper::cCast_g6aIr5Fm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_5sa7txuN, 0, m, &cIf_5sa7txuN_sendMessage);
}

void Heavy_SoundScraper::cCast_Jz8HCtWg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_KfoXys5M_sendMessage);
}

void Heavy_SoundScraper::cBinop_KfoXys5M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_5sa7txuN, 1, m, &cIf_5sa7txuN_sendMessage);
}

void Heavy_SoundScraper::cBinop_aTcjU49t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_RkBAMk2f_sendMessage);
}

void Heavy_SoundScraper::cMsg_UbM5NOIm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.125f, 0, m, &cBinop_CbpReXvW_sendMessage);
}

void Heavy_SoundScraper::cBinop_jIkVcsB2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_BVKbHj9d, HV_BINOP_POW, 1, m, &cBinop_BVKbHj9d_sendMessage);
  cMsg_n9Dxe89O_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_DXf6hEff_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_6roDgJna, 0, m, NULL);
}

void Heavy_SoundScraper::cPack_bSKlwpWY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_8eT4FstA, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_Yz5zKaAl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_PNnrHMMC_sendMessage);
}

void Heavy_SoundScraper::cBinop_PNnrHMMC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 200.0f, 0, m, &cBinop_WZdt0wyT_sendMessage);
}

void Heavy_SoundScraper::cVar_OquQCk2n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_pjylq8DL, HV_BINOP_MULTIPLY, 0, m, &cBinop_pjylq8DL_sendMessage);
}

void Heavy_SoundScraper::cMsg_6ZLnzzKE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_1n71uILs_sendMessage);
}

void Heavy_SoundScraper::cSystem_1n71uILs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_c1B03kHj_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_pjylq8DL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_JJxDf4fE_sendMessage);
}

void Heavy_SoundScraper::cBinop_CyiqN2Zw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_pjylq8DL, HV_BINOP_MULTIPLY, 1, m, &cBinop_pjylq8DL_sendMessage);
}

void Heavy_SoundScraper::cMsg_c1B03kHj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_CyiqN2Zw_sendMessage);
}

void Heavy_SoundScraper::cBinop_JJxDf4fE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_46K76Wo2_sendMessage);
}

void Heavy_SoundScraper::cBinop_46K76Wo2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_6kOBBXf0_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_l81GUvvI, m);
}

void Heavy_SoundScraper::cBinop_6kOBBXf0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_iQtwBMRY, m);
}

void Heavy_SoundScraper::cVar_NXkYuOEu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Jz8HCtWg_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_g6aIr5Fm_sendMessage);
}

void Heavy_SoundScraper::cVar_1wl9HEjT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 100.0f, 0, m, &cBinop_Yz5zKaAl_sendMessage);
}

void Heavy_SoundScraper::cVar_hCfWcIUY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_Az6cYioW_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_nBs6UzPX, 0, m, &cIf_nBs6UzPX_sendMessage);
}

void Heavy_SoundScraper::cVar_4MuHOyD3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 100.0f, 0, m, &cBinop_oa57XZJc_sendMessage);
}

void Heavy_SoundScraper::cIf_nBs6UzPX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_dTwAQFjg_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cVar_onMessage(_c, &Context(_c)->cVar_s6CeOL6P, 0, m, &cVar_s6CeOL6P_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_Az6cYioW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_nBs6UzPX, 1, m, &cIf_nBs6UzPX_sendMessage);
}

void Heavy_SoundScraper::cBinop_oa57XZJc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_bF2c2kCb_sendMessage);
}

void Heavy_SoundScraper::cBinop_bF2c2kCb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_i2QSqJs1, 0, m, &cVar_i2QSqJs1_sendMessage);
}

void Heavy_SoundScraper::cTabhead_Po3NiZVj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_0TwkBBem, HV_BINOP_SUBTRACT, 0, m, &cBinop_0TwkBBem_sendMessage);
}

void Heavy_SoundScraper::cMsg_rfdNynv4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_yX4m4nCB_sendMessage);
}

void Heavy_SoundScraper::cSystem_yX4m4nCB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_YhfSRFKn_sendMessage);
}

void Heavy_SoundScraper::cVar_jZ8jzNSN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_PL7jf3hK_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_N4DK4Z68_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_N4DK4Z68, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_LkvUEk9g, 0, m, &cDelay_LkvUEk9g_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_29P1pciG, 0, m, &sTabread_29P1pciG_sendMessage);
}

void Heavy_SoundScraper::cDelay_LkvUEk9g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_LkvUEk9g, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_29P1pciG, 0, m, &sTabread_29P1pciG_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_LkvUEk9g, 0, m, &cDelay_LkvUEk9g_sendMessage);
}

void Heavy_SoundScraper::sTabread_29P1pciG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_eZGPsNBt, HV_BINOP_SUBTRACT, 0, m, &cBinop_eZGPsNBt_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_XFBmOojv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_eQqf7bo5, HV_BINOP_MAX, 0, m, &cBinop_eQqf7bo5_sendMessage);
}

void Heavy_SoundScraper::cBinop_YhfSRFKn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_XFBmOojv, HV_BINOP_MULTIPLY, 0, m, &cBinop_XFBmOojv_sendMessage);
}

void Heavy_SoundScraper::cBinop_0TwkBBem_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_nvRrGxhX_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_29P1pciG, 0, m, &sTabread_29P1pciG_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_GgsAmbAg_sendMessage);
}

void Heavy_SoundScraper::cSystem_SylKpo9G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_eZGPsNBt, HV_BINOP_SUBTRACT, 1, m, &cBinop_eZGPsNBt_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_LkvUEk9g, 2, m, &cDelay_LkvUEk9g_sendMessage);
}

void Heavy_SoundScraper::cMsg_PL7jf3hK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_SylKpo9G_sendMessage);
}

void Heavy_SoundScraper::cMsg_nvRrGxhX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_N4DK4Z68, 0, m, &cDelay_N4DK4Z68_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_LkvUEk9g, 0, m, &cDelay_LkvUEk9g_sendMessage);
}

void Heavy_SoundScraper::cMsg_yirqP5WT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_eQqf7bo5, HV_BINOP_MAX, 1, m, &cBinop_eQqf7bo5_sendMessage);
}

void Heavy_SoundScraper::cBinop_eQqf7bo5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_0TwkBBem, HV_BINOP_SUBTRACT, 1, m, &cBinop_0TwkBBem_sendMessage);
}

void Heavy_SoundScraper::cCast_GgsAmbAg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_N4DK4Z68, 0, m, &cDelay_N4DK4Z68_sendMessage);
}

void Heavy_SoundScraper::cBinop_zIcbUkPi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_N4DK4Z68, 2, m, &cDelay_N4DK4Z68_sendMessage);
}

void Heavy_SoundScraper::cBinop_eZGPsNBt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_zIcbUkPi_sendMessage);
}

void Heavy_SoundScraper::cCast_s1yjcm8D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_jZ8jzNSN, 0, m, &cVar_jZ8jzNSN_sendMessage);
  cMsg_rfdNynv4_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_Po3NiZVj, 0, m, &cTabhead_Po3NiZVj_sendMessage);
}

void Heavy_SoundScraper::cMsg_uWgXaFFN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_9KS7OQcj_sendMessage);
}

void Heavy_SoundScraper::cSystem_9KS7OQcj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_6gWlgzRS_sendMessage);
}

void Heavy_SoundScraper::cDelay_OJcUJA4T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_OJcUJA4T, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Ed8h5hj0, 0, m, &cDelay_Ed8h5hj0_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_OJcUJA4T, 0, m, &cDelay_OJcUJA4T_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_ryUt1QY8, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_Ed8h5hj0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Ed8h5hj0, m);
  cMsg_AXjEfyTQ_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_jpT1vQLh_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_Vm2OZ4lo_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_6rnhMTcf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Faawm2DA_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_TdUQXZuW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_vGcZpqNI_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_OJcUJA4T, 2, m, &cDelay_OJcUJA4T_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_vtpFTDk6_sendMessage);
}

void Heavy_SoundScraper::cMsg_Faawm2DA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_TdUQXZuW, 0, m, &hTable_TdUQXZuW_sendMessage);
}

void Heavy_SoundScraper::cBinop_6gWlgzRS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 13.645f, 0, m, &cBinop_6rnhMTcf_sendMessage);
}

void Heavy_SoundScraper::cMsg_AXjEfyTQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_TdUQXZuW, 0, m, &hTable_TdUQXZuW_sendMessage);
}

void Heavy_SoundScraper::cCast_vtpFTDk6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_OJcUJA4T, 0, m, &cDelay_OJcUJA4T_sendMessage);
}

void Heavy_SoundScraper::cMsg_vGcZpqNI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_Ed8h5hj0, 2, m, &cDelay_Ed8h5hj0_sendMessage);
}

void Heavy_SoundScraper::cMsg_Vm2OZ4lo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_ryUt1QY8, 1, m, NULL);
}

void Heavy_SoundScraper::cTabhead_Ouu7jbUj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_41Gn0GK8, HV_BINOP_SUBTRACT, 0, m, &cBinop_41Gn0GK8_sendMessage);
}

void Heavy_SoundScraper::cMsg_akwVB60m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_1Z0zQtXv_sendMessage);
}

void Heavy_SoundScraper::cSystem_1Z0zQtXv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_LXIHTQ2W_sendMessage);
}

void Heavy_SoundScraper::cVar_kRzJ71eU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_uw2AvW5L_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_227QwP2x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_227QwP2x, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_jTQDGVu6, 0, m, &cDelay_jTQDGVu6_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_aTDR6e40, 0, m, &sTabread_aTDR6e40_sendMessage);
}

void Heavy_SoundScraper::cDelay_jTQDGVu6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_jTQDGVu6, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_aTDR6e40, 0, m, &sTabread_aTDR6e40_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_jTQDGVu6, 0, m, &cDelay_jTQDGVu6_sendMessage);
}

void Heavy_SoundScraper::sTabread_aTDR6e40_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_p6hNfJvR, HV_BINOP_SUBTRACT, 0, m, &cBinop_p6hNfJvR_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_Eyb4FdC9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_F6ROEjDe, HV_BINOP_MAX, 0, m, &cBinop_F6ROEjDe_sendMessage);
}

void Heavy_SoundScraper::cBinop_LXIHTQ2W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Eyb4FdC9, HV_BINOP_MULTIPLY, 0, m, &cBinop_Eyb4FdC9_sendMessage);
}

void Heavy_SoundScraper::cBinop_41Gn0GK8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_tb682bCk_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_aTDR6e40, 0, m, &sTabread_aTDR6e40_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_PBHU8Y7h_sendMessage);
}

void Heavy_SoundScraper::cSystem_5Np594Xn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_p6hNfJvR, HV_BINOP_SUBTRACT, 1, m, &cBinop_p6hNfJvR_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_jTQDGVu6, 2, m, &cDelay_jTQDGVu6_sendMessage);
}

void Heavy_SoundScraper::cMsg_uw2AvW5L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_5Np594Xn_sendMessage);
}

void Heavy_SoundScraper::cMsg_tb682bCk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_227QwP2x, 0, m, &cDelay_227QwP2x_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_jTQDGVu6, 0, m, &cDelay_jTQDGVu6_sendMessage);
}

void Heavy_SoundScraper::cMsg_BP6pkyFY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_F6ROEjDe, HV_BINOP_MAX, 1, m, &cBinop_F6ROEjDe_sendMessage);
}

void Heavy_SoundScraper::cBinop_F6ROEjDe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_41Gn0GK8, HV_BINOP_SUBTRACT, 1, m, &cBinop_41Gn0GK8_sendMessage);
}

void Heavy_SoundScraper::cCast_PBHU8Y7h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_227QwP2x, 0, m, &cDelay_227QwP2x_sendMessage);
}

void Heavy_SoundScraper::cBinop_4TR56iOS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_227QwP2x, 2, m, &cDelay_227QwP2x_sendMessage);
}

void Heavy_SoundScraper::cBinop_p6hNfJvR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_4TR56iOS_sendMessage);
}

void Heavy_SoundScraper::cCast_Du3rDnhS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_kRzJ71eU, 0, m, &cVar_kRzJ71eU_sendMessage);
  cMsg_akwVB60m_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_Ouu7jbUj, 0, m, &cTabhead_Ouu7jbUj_sendMessage);
}

void Heavy_SoundScraper::cMsg_TjGSaK6m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_JmdtrI9G_sendMessage);
}

void Heavy_SoundScraper::cSystem_JmdtrI9G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_VS1UBdjW_sendMessage);
}

void Heavy_SoundScraper::cDelay_DQ1IsHft_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_DQ1IsHft, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_RRNoMS9l, 0, m, &cDelay_RRNoMS9l_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_DQ1IsHft, 0, m, &cDelay_DQ1IsHft_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_U8Cp5GTq, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_RRNoMS9l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_RRNoMS9l, m);
  cMsg_ais87KPB_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_hnlO777C_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_ymfd3R4N_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_jgICyE0h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_8QxjXFRJ_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_H2qu6ske_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_mrsNy9k3_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_DQ1IsHft, 2, m, &cDelay_DQ1IsHft_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_SYosB5Xb_sendMessage);
}

void Heavy_SoundScraper::cMsg_8QxjXFRJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_H2qu6ske, 0, m, &hTable_H2qu6ske_sendMessage);
}

void Heavy_SoundScraper::cBinop_VS1UBdjW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 16.364f, 0, m, &cBinop_jgICyE0h_sendMessage);
}

void Heavy_SoundScraper::cMsg_ais87KPB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_H2qu6ske, 0, m, &hTable_H2qu6ske_sendMessage);
}

void Heavy_SoundScraper::cCast_SYosB5Xb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_DQ1IsHft, 0, m, &cDelay_DQ1IsHft_sendMessage);
}

void Heavy_SoundScraper::cMsg_mrsNy9k3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_RRNoMS9l, 2, m, &cDelay_RRNoMS9l_sendMessage);
}

void Heavy_SoundScraper::cMsg_ymfd3R4N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_U8Cp5GTq, 1, m, NULL);
}

void Heavy_SoundScraper::cTabhead_SHUICP2Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_gNWrVKG4, HV_BINOP_SUBTRACT, 0, m, &cBinop_gNWrVKG4_sendMessage);
}

void Heavy_SoundScraper::cMsg_cqGLgsZp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_5u0gGZnc_sendMessage);
}

void Heavy_SoundScraper::cSystem_5u0gGZnc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_iZtBuxo8_sendMessage);
}

void Heavy_SoundScraper::cVar_ZegJPXJC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_sw6jXUZa_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_p1EPHYCN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_p1EPHYCN, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_0nZV4qbG, 0, m, &cDelay_0nZV4qbG_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_NrulwpP8, 0, m, &sTabread_NrulwpP8_sendMessage);
}

void Heavy_SoundScraper::cDelay_0nZV4qbG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_0nZV4qbG, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_NrulwpP8, 0, m, &sTabread_NrulwpP8_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_0nZV4qbG, 0, m, &cDelay_0nZV4qbG_sendMessage);
}

void Heavy_SoundScraper::sTabread_NrulwpP8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_2GAPHqER, HV_BINOP_SUBTRACT, 0, m, &cBinop_2GAPHqER_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_R5M612yX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Jzs9wolS, HV_BINOP_MAX, 0, m, &cBinop_Jzs9wolS_sendMessage);
}

void Heavy_SoundScraper::cBinop_iZtBuxo8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_R5M612yX, HV_BINOP_MULTIPLY, 0, m, &cBinop_R5M612yX_sendMessage);
}

void Heavy_SoundScraper::cBinop_gNWrVKG4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_G79rSY5q_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_NrulwpP8, 0, m, &sTabread_NrulwpP8_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ZmAD2w32_sendMessage);
}

void Heavy_SoundScraper::cSystem_vQsxoZ9S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_2GAPHqER, HV_BINOP_SUBTRACT, 1, m, &cBinop_2GAPHqER_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_0nZV4qbG, 2, m, &cDelay_0nZV4qbG_sendMessage);
}

void Heavy_SoundScraper::cMsg_sw6jXUZa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_vQsxoZ9S_sendMessage);
}

void Heavy_SoundScraper::cMsg_G79rSY5q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_p1EPHYCN, 0, m, &cDelay_p1EPHYCN_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_0nZV4qbG, 0, m, &cDelay_0nZV4qbG_sendMessage);
}

void Heavy_SoundScraper::cMsg_lEE5P46e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_Jzs9wolS, HV_BINOP_MAX, 1, m, &cBinop_Jzs9wolS_sendMessage);
}

void Heavy_SoundScraper::cBinop_Jzs9wolS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_gNWrVKG4, HV_BINOP_SUBTRACT, 1, m, &cBinop_gNWrVKG4_sendMessage);
}

void Heavy_SoundScraper::cCast_ZmAD2w32_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_p1EPHYCN, 0, m, &cDelay_p1EPHYCN_sendMessage);
}

void Heavy_SoundScraper::cBinop_BHfk4G1v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_p1EPHYCN, 2, m, &cDelay_p1EPHYCN_sendMessage);
}

void Heavy_SoundScraper::cBinop_2GAPHqER_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_BHfk4G1v_sendMessage);
}

void Heavy_SoundScraper::cCast_cWrLCtwH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ZegJPXJC, 0, m, &cVar_ZegJPXJC_sendMessage);
  cMsg_cqGLgsZp_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_SHUICP2Q, 0, m, &cTabhead_SHUICP2Q_sendMessage);
}

void Heavy_SoundScraper::cMsg_LzwTP0qu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_sUA7fSmn_sendMessage);
}

void Heavy_SoundScraper::cSystem_sUA7fSmn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_3pO5XgMj_sendMessage);
}

void Heavy_SoundScraper::cDelay_eYxs6ToY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_eYxs6ToY, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_gy6UBCn3, 0, m, &cDelay_gy6UBCn3_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_eYxs6ToY, 0, m, &cDelay_eYxs6ToY_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_0hu6njQb, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_gy6UBCn3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_gy6UBCn3, m);
  cMsg_ftl4KPap_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_F8t4LrIt_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_A88e8YkM_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_LKMB1vKx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_XvImTwxs_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_CrW75vpS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_FN4WYn0l_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_eYxs6ToY, 2, m, &cDelay_eYxs6ToY_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_L2B32NmW_sendMessage);
}

void Heavy_SoundScraper::cMsg_XvImTwxs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_CrW75vpS, 0, m, &hTable_CrW75vpS_sendMessage);
}

void Heavy_SoundScraper::cBinop_3pO5XgMj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 19.392f, 0, m, &cBinop_LKMB1vKx_sendMessage);
}

void Heavy_SoundScraper::cMsg_ftl4KPap_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_CrW75vpS, 0, m, &hTable_CrW75vpS_sendMessage);
}

void Heavy_SoundScraper::cCast_L2B32NmW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_eYxs6ToY, 0, m, &cDelay_eYxs6ToY_sendMessage);
}

void Heavy_SoundScraper::cMsg_FN4WYn0l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_gy6UBCn3, 2, m, &cDelay_gy6UBCn3_sendMessage);
}

void Heavy_SoundScraper::cMsg_A88e8YkM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_0hu6njQb, 1, m, NULL);
}

void Heavy_SoundScraper::cTabhead_9PnigjGs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_PvxAsyH2, HV_BINOP_SUBTRACT, 0, m, &cBinop_PvxAsyH2_sendMessage);
}

void Heavy_SoundScraper::cMsg_Wn9g9Cv7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_n5r3UwF4_sendMessage);
}

void Heavy_SoundScraper::cSystem_n5r3UwF4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_U0VTvRx8_sendMessage);
}

void Heavy_SoundScraper::cVar_mE8kTSAF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_AXrilCP3_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_H1KBfMCU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_H1KBfMCU, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Wjoc7elw, 0, m, &cDelay_Wjoc7elw_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_41vYJHEg, 0, m, &sTabread_41vYJHEg_sendMessage);
}

void Heavy_SoundScraper::cDelay_Wjoc7elw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Wjoc7elw, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_41vYJHEg, 0, m, &sTabread_41vYJHEg_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Wjoc7elw, 0, m, &cDelay_Wjoc7elw_sendMessage);
}

void Heavy_SoundScraper::sTabread_41vYJHEg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_TyqZbmJS, HV_BINOP_SUBTRACT, 0, m, &cBinop_TyqZbmJS_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_ervKyagz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ETYqLNbB, HV_BINOP_MAX, 0, m, &cBinop_ETYqLNbB_sendMessage);
}

void Heavy_SoundScraper::cBinop_U0VTvRx8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ervKyagz, HV_BINOP_MULTIPLY, 0, m, &cBinop_ervKyagz_sendMessage);
}

void Heavy_SoundScraper::cBinop_PvxAsyH2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_g5HXsARp_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_41vYJHEg, 0, m, &sTabread_41vYJHEg_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_7XLkBkS5_sendMessage);
}

void Heavy_SoundScraper::cSystem_A5Al3i2d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_TyqZbmJS, HV_BINOP_SUBTRACT, 1, m, &cBinop_TyqZbmJS_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Wjoc7elw, 2, m, &cDelay_Wjoc7elw_sendMessage);
}

void Heavy_SoundScraper::cMsg_AXrilCP3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_A5Al3i2d_sendMessage);
}

void Heavy_SoundScraper::cMsg_g5HXsARp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_H1KBfMCU, 0, m, &cDelay_H1KBfMCU_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Wjoc7elw, 0, m, &cDelay_Wjoc7elw_sendMessage);
}

void Heavy_SoundScraper::cMsg_ZFGs9FOA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_ETYqLNbB, HV_BINOP_MAX, 1, m, &cBinop_ETYqLNbB_sendMessage);
}

void Heavy_SoundScraper::cBinop_ETYqLNbB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_PvxAsyH2, HV_BINOP_SUBTRACT, 1, m, &cBinop_PvxAsyH2_sendMessage);
}

void Heavy_SoundScraper::cCast_7XLkBkS5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_H1KBfMCU, 0, m, &cDelay_H1KBfMCU_sendMessage);
}

void Heavy_SoundScraper::cBinop_0MFp8WQT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_H1KBfMCU, 2, m, &cDelay_H1KBfMCU_sendMessage);
}

void Heavy_SoundScraper::cBinop_TyqZbmJS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_0MFp8WQT_sendMessage);
}

void Heavy_SoundScraper::cCast_jWlAcSxI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_mE8kTSAF, 0, m, &cVar_mE8kTSAF_sendMessage);
  cMsg_Wn9g9Cv7_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_9PnigjGs, 0, m, &cTabhead_9PnigjGs_sendMessage);
}

void Heavy_SoundScraper::cMsg_LEAKKrwD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ec9jDKe9_sendMessage);
}

void Heavy_SoundScraper::cSystem_ec9jDKe9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_vJaq8hFA_sendMessage);
}

void Heavy_SoundScraper::cDelay_aGvCGyAm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_aGvCGyAm, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_1nkNNzv6, 0, m, &cDelay_1nkNNzv6_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_aGvCGyAm, 0, m, &cDelay_aGvCGyAm_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_xVutPYcz, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_1nkNNzv6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_1nkNNzv6, m);
  cMsg_QcmDWOAF_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_qQVE7snl_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_JuhH9Aox_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_bIazL2ij_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_q7vHoQnP_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_rYVysgEh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_EITRZmB8_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_aGvCGyAm, 2, m, &cDelay_aGvCGyAm_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_6qVjstUQ_sendMessage);
}

void Heavy_SoundScraper::cMsg_q7vHoQnP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_rYVysgEh, 0, m, &hTable_rYVysgEh_sendMessage);
}

void Heavy_SoundScraper::cBinop_vJaq8hFA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 25.796f, 0, m, &cBinop_bIazL2ij_sendMessage);
}

void Heavy_SoundScraper::cMsg_QcmDWOAF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_rYVysgEh, 0, m, &hTable_rYVysgEh_sendMessage);
}

void Heavy_SoundScraper::cCast_6qVjstUQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_aGvCGyAm, 0, m, &cDelay_aGvCGyAm_sendMessage);
}

void Heavy_SoundScraper::cMsg_EITRZmB8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_1nkNNzv6, 2, m, &cDelay_1nkNNzv6_sendMessage);
}

void Heavy_SoundScraper::cMsg_JuhH9Aox_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_xVutPYcz, 1, m, NULL);
}

void Heavy_SoundScraper::cTabhead_x8bN9o2l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_2o1pyAEx, HV_BINOP_SUBTRACT, 0, m, &cBinop_2o1pyAEx_sendMessage);
}

void Heavy_SoundScraper::cMsg_ZFvHevtn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_rPJAPQs1_sendMessage);
}

void Heavy_SoundScraper::cSystem_rPJAPQs1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_xTHLek1Q_sendMessage);
}

void Heavy_SoundScraper::cVar_nJ4e88Oq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_h9HvkF9w_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_YYD2LPZr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_YYD2LPZr, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_IhSevSaw, 0, m, &cDelay_IhSevSaw_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_9cGt4C5J, 0, m, &sTabread_9cGt4C5J_sendMessage);
}

void Heavy_SoundScraper::cDelay_IhSevSaw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_IhSevSaw, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_9cGt4C5J, 0, m, &sTabread_9cGt4C5J_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_IhSevSaw, 0, m, &cDelay_IhSevSaw_sendMessage);
}

void Heavy_SoundScraper::sTabread_9cGt4C5J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_KrKZw3dV, HV_BINOP_SUBTRACT, 0, m, &cBinop_KrKZw3dV_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_9HsmoXYB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_qLoEc7vZ, HV_BINOP_MAX, 0, m, &cBinop_qLoEc7vZ_sendMessage);
}

void Heavy_SoundScraper::cBinop_xTHLek1Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_9HsmoXYB, HV_BINOP_MULTIPLY, 0, m, &cBinop_9HsmoXYB_sendMessage);
}

void Heavy_SoundScraper::cBinop_2o1pyAEx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_cArEp0bW_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_9cGt4C5J, 0, m, &sTabread_9cGt4C5J_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Top7Mf15_sendMessage);
}

void Heavy_SoundScraper::cSystem_H2wCP538_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_KrKZw3dV, HV_BINOP_SUBTRACT, 1, m, &cBinop_KrKZw3dV_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_IhSevSaw, 2, m, &cDelay_IhSevSaw_sendMessage);
}

void Heavy_SoundScraper::cMsg_h9HvkF9w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_H2wCP538_sendMessage);
}

void Heavy_SoundScraper::cMsg_cArEp0bW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_YYD2LPZr, 0, m, &cDelay_YYD2LPZr_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_IhSevSaw, 0, m, &cDelay_IhSevSaw_sendMessage);
}

void Heavy_SoundScraper::cMsg_nRoRXsgS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_qLoEc7vZ, HV_BINOP_MAX, 1, m, &cBinop_qLoEc7vZ_sendMessage);
}

void Heavy_SoundScraper::cBinop_qLoEc7vZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_2o1pyAEx, HV_BINOP_SUBTRACT, 1, m, &cBinop_2o1pyAEx_sendMessage);
}

void Heavy_SoundScraper::cCast_Top7Mf15_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_YYD2LPZr, 0, m, &cDelay_YYD2LPZr_sendMessage);
}

void Heavy_SoundScraper::cBinop_jPQR6Ocs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_YYD2LPZr, 2, m, &cDelay_YYD2LPZr_sendMessage);
}

void Heavy_SoundScraper::cBinop_KrKZw3dV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_jPQR6Ocs_sendMessage);
}

void Heavy_SoundScraper::cCast_bQy9Jo08_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_nJ4e88Oq, 0, m, &cVar_nJ4e88Oq_sendMessage);
  cMsg_ZFvHevtn_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_x8bN9o2l, 0, m, &cTabhead_x8bN9o2l_sendMessage);
}

void Heavy_SoundScraper::cMsg_nzq7ZikR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_y4fvV77d_sendMessage);
}

void Heavy_SoundScraper::cSystem_y4fvV77d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_S0jXWcct_sendMessage);
}

void Heavy_SoundScraper::cDelay_wv7eP3AI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_wv7eP3AI, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_DOKXEIpu, 0, m, &cDelay_DOKXEIpu_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_wv7eP3AI, 0, m, &cDelay_wv7eP3AI_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_ZMXvfo1q, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_DOKXEIpu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_DOKXEIpu, m);
  cMsg_aTdfqLSI_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_fUjoDkRa_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_WGA2RYo3_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_T8mgdcLM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_PpC4VO6h_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_YFXVwWdu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_XZLktssK_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_wv7eP3AI, 2, m, &cDelay_wv7eP3AI_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_pH2LzNEG_sendMessage);
}

void Heavy_SoundScraper::cMsg_PpC4VO6h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_YFXVwWdu, 0, m, &hTable_YFXVwWdu_sendMessage);
}

void Heavy_SoundScraper::cBinop_S0jXWcct_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 43.5337f, 0, m, &cBinop_T8mgdcLM_sendMessage);
}

void Heavy_SoundScraper::cMsg_aTdfqLSI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_YFXVwWdu, 0, m, &hTable_YFXVwWdu_sendMessage);
}

void Heavy_SoundScraper::cCast_pH2LzNEG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_wv7eP3AI, 0, m, &cDelay_wv7eP3AI_sendMessage);
}

void Heavy_SoundScraper::cMsg_XZLktssK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_DOKXEIpu, 2, m, &cDelay_DOKXEIpu_sendMessage);
}

void Heavy_SoundScraper::cMsg_WGA2RYo3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_ZMXvfo1q, 1, m, NULL);
}

void Heavy_SoundScraper::cTabhead_Od3PmTyw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_7cAzLlIN, HV_BINOP_SUBTRACT, 0, m, &cBinop_7cAzLlIN_sendMessage);
}

void Heavy_SoundScraper::cMsg_89GjDZOc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_zoCc20G0_sendMessage);
}

void Heavy_SoundScraper::cSystem_zoCc20G0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_d48E6MwC_sendMessage);
}

void Heavy_SoundScraper::cVar_RzLuAeYa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_k2VCfpSH_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_crmO2Wg3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_crmO2Wg3, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_6WU3jSms, 0, m, &cDelay_6WU3jSms_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_AZxD1A9S, 0, m, &sTabread_AZxD1A9S_sendMessage);
}

void Heavy_SoundScraper::cDelay_6WU3jSms_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_6WU3jSms, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_AZxD1A9S, 0, m, &sTabread_AZxD1A9S_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_6WU3jSms, 0, m, &cDelay_6WU3jSms_sendMessage);
}

void Heavy_SoundScraper::sTabread_AZxD1A9S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_JFvTAyJR, HV_BINOP_SUBTRACT, 0, m, &cBinop_JFvTAyJR_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_ekC05dXV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_7Wkh3oJC, HV_BINOP_MAX, 0, m, &cBinop_7Wkh3oJC_sendMessage);
}

void Heavy_SoundScraper::cBinop_d48E6MwC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ekC05dXV, HV_BINOP_MULTIPLY, 0, m, &cBinop_ekC05dXV_sendMessage);
}

void Heavy_SoundScraper::cBinop_7cAzLlIN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_EGtXmBuR_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_AZxD1A9S, 0, m, &sTabread_AZxD1A9S_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_O8KF58xe_sendMessage);
}

void Heavy_SoundScraper::cSystem_RIvUdDgS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_JFvTAyJR, HV_BINOP_SUBTRACT, 1, m, &cBinop_JFvTAyJR_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_6WU3jSms, 2, m, &cDelay_6WU3jSms_sendMessage);
}

void Heavy_SoundScraper::cMsg_k2VCfpSH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_RIvUdDgS_sendMessage);
}

void Heavy_SoundScraper::cMsg_EGtXmBuR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_crmO2Wg3, 0, m, &cDelay_crmO2Wg3_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_6WU3jSms, 0, m, &cDelay_6WU3jSms_sendMessage);
}

void Heavy_SoundScraper::cMsg_9VrOyBl8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_7Wkh3oJC, HV_BINOP_MAX, 1, m, &cBinop_7Wkh3oJC_sendMessage);
}

void Heavy_SoundScraper::cBinop_7Wkh3oJC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_7cAzLlIN, HV_BINOP_SUBTRACT, 1, m, &cBinop_7cAzLlIN_sendMessage);
}

void Heavy_SoundScraper::cCast_O8KF58xe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_crmO2Wg3, 0, m, &cDelay_crmO2Wg3_sendMessage);
}

void Heavy_SoundScraper::cBinop_lWfdbx4j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_crmO2Wg3, 2, m, &cDelay_crmO2Wg3_sendMessage);
}

void Heavy_SoundScraper::cBinop_JFvTAyJR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_lWfdbx4j_sendMessage);
}

void Heavy_SoundScraper::cCast_wk2Cay1q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_RzLuAeYa, 0, m, &cVar_RzLuAeYa_sendMessage);
  cMsg_89GjDZOc_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_Od3PmTyw, 0, m, &cTabhead_Od3PmTyw_sendMessage);
}

void Heavy_SoundScraper::cMsg_0AbQ659J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_y1rh6NtL_sendMessage);
}

void Heavy_SoundScraper::cSystem_y1rh6NtL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_1qAZ6BUi_sendMessage);
}

void Heavy_SoundScraper::cDelay_FYBd88Ig_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_FYBd88Ig, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_AoQ1txdb, 0, m, &cDelay_AoQ1txdb_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_FYBd88Ig, 0, m, &cDelay_FYBd88Ig_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_lH279H20, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_AoQ1txdb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_AoQ1txdb, m);
  cMsg_77uWIAM9_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_TYDEI8cH_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_BqdngsPr_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_vkpp7KpT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_yeHwCVtU_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_eE2EZu5g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_YoMCyrc3_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_FYBd88Ig, 2, m, &cDelay_FYBd88Ig_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_kOMLXpIq_sendMessage);
}

void Heavy_SoundScraper::cMsg_yeHwCVtU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_eE2EZu5g, 0, m, &hTable_eE2EZu5g_sendMessage);
}

void Heavy_SoundScraper::cBinop_1qAZ6BUi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 75.2546f, 0, m, &cBinop_vkpp7KpT_sendMessage);
}

void Heavy_SoundScraper::cMsg_77uWIAM9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_eE2EZu5g, 0, m, &hTable_eE2EZu5g_sendMessage);
}

void Heavy_SoundScraper::cCast_kOMLXpIq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_FYBd88Ig, 0, m, &cDelay_FYBd88Ig_sendMessage);
}

void Heavy_SoundScraper::cMsg_YoMCyrc3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_AoQ1txdb, 2, m, &cDelay_AoQ1txdb_sendMessage);
}

void Heavy_SoundScraper::cMsg_BqdngsPr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_lH279H20, 1, m, NULL);
}

void Heavy_SoundScraper::cVar_s6CeOL6P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_OquQCk2n, 0, m, &cVar_OquQCk2n_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_XWPguoBd, 0, m, &cVar_XWPguoBd_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_9xpBajhW, 0, m, &cVar_9xpBajhW_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_jUxYxiCk, 0, m, &cVar_jUxYxiCk_sendMessage);
}

void Heavy_SoundScraper::cVar_i2QSqJs1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.01f, 0, m, &cBinop_g9jopkbX_sendMessage);
}

void Heavy_SoundScraper::cPack_My8Rh77t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_VNCvY9SK, 0, m, NULL);
}

void Heavy_SoundScraper::cVar_XWPguoBd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MiWCLYyZ, HV_BINOP_MULTIPLY, 0, m, &cBinop_MiWCLYyZ_sendMessage);
}

void Heavy_SoundScraper::cMsg_WsQaR7BM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_9uH08rtD_sendMessage);
}

void Heavy_SoundScraper::cSystem_9uH08rtD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_vF7uf91V_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_MiWCLYyZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_iuYtTy21_sendMessage);
}

void Heavy_SoundScraper::cBinop_5nUyKMwQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MiWCLYyZ, HV_BINOP_MULTIPLY, 1, m, &cBinop_MiWCLYyZ_sendMessage);
}

void Heavy_SoundScraper::cMsg_vF7uf91V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_5nUyKMwQ_sendMessage);
}

void Heavy_SoundScraper::cBinop_iuYtTy21_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_VI2nouMX_sendMessage);
}

void Heavy_SoundScraper::cBinop_VI2nouMX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_xPfKJVBV_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_v2f1kXja, m);
}

void Heavy_SoundScraper::cBinop_xPfKJVBV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_QG70fgrH, m);
}

void Heavy_SoundScraper::cVar_9xpBajhW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Kcmd7gtN, HV_BINOP_MULTIPLY, 0, m, &cBinop_Kcmd7gtN_sendMessage);
}

void Heavy_SoundScraper::cMsg_is65mE4M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_C09dJDEq_sendMessage);
}

void Heavy_SoundScraper::cSystem_C09dJDEq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_UtniR4ob_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_Kcmd7gtN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_bfHkgFed_sendMessage);
}

void Heavy_SoundScraper::cBinop_rrtRfc25_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Kcmd7gtN, HV_BINOP_MULTIPLY, 1, m, &cBinop_Kcmd7gtN_sendMessage);
}

void Heavy_SoundScraper::cMsg_UtniR4ob_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_rrtRfc25_sendMessage);
}

void Heavy_SoundScraper::cBinop_bfHkgFed_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_WbjZvudb_sendMessage);
}

void Heavy_SoundScraper::cBinop_WbjZvudb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_MdEi1Jqn_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_9MNi9syW, m);
}

void Heavy_SoundScraper::cBinop_MdEi1Jqn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_L80vbO3y, m);
}

void Heavy_SoundScraper::cVar_jUxYxiCk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_WS9KKNeB, HV_BINOP_MULTIPLY, 0, m, &cBinop_WS9KKNeB_sendMessage);
}

void Heavy_SoundScraper::cMsg_1HOMcLlv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_S2VoiVyV_sendMessage);
}

void Heavy_SoundScraper::cSystem_S2VoiVyV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_msYALnd7_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_WS9KKNeB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_21e9vj8X_sendMessage);
}

void Heavy_SoundScraper::cBinop_gTBCIpu4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_WS9KKNeB, HV_BINOP_MULTIPLY, 1, m, &cBinop_WS9KKNeB_sendMessage);
}

void Heavy_SoundScraper::cMsg_msYALnd7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_gTBCIpu4_sendMessage);
}

void Heavy_SoundScraper::cBinop_21e9vj8X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_qOAlpYTu_sendMessage);
}

void Heavy_SoundScraper::cBinop_qOAlpYTu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_d95DmQL4_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_0elU9Ujj, m);
}

void Heavy_SoundScraper::cBinop_d95DmQL4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_QPD9tpJ9, m);
}

void Heavy_SoundScraper::cBinop_WZdt0wyT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_bSKlwpWY, 0, m, &cPack_bSKlwpWY_sendMessage);
}

void Heavy_SoundScraper::cMsg_dTwAQFjg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 3000.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_s6CeOL6P, 0, m, &cVar_s6CeOL6P_sendMessage);
}

void Heavy_SoundScraper::cBinop_g9jopkbX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_My8Rh77t, 0, m, &cPack_My8Rh77t_sendMessage);
}

void Heavy_SoundScraper::cBinop_CbpReXvW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_DXf6hEff, 0, m, &cPack_DXf6hEff_sendMessage);
}

void Heavy_SoundScraper::cVar_qEtJMY78_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_MqjgkIvg_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_qk6kdWr5_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_IoGTVvIL_sendMessage);
}

void Heavy_SoundScraper::cIf_GsFOnAIb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_7aMBq0Sh_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_9xkaCnbB_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cMsg_hetvBL3h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_peqiZpeu, HV_BINOP_POW, 0, m, &cBinop_peqiZpeu_sendMessage);
}

void Heavy_SoundScraper::cBinop_peqiZpeu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_EDR7bHgq, 0, m, &cPack_EDR7bHgq_sendMessage);
}

void Heavy_SoundScraper::cBinop_z5ksATLv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_DLZb1vpd_sendMessage);
}

void Heavy_SoundScraper::cCast_qk6kdWr5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_eKUuCeM1_sendMessage);
}

void Heavy_SoundScraper::cCast_IoGTVvIL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_GsFOnAIb, 0, m, &cIf_GsFOnAIb_sendMessage);
}

void Heavy_SoundScraper::cBinop_eKUuCeM1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_GsFOnAIb, 1, m, &cIf_GsFOnAIb_sendMessage);
}

void Heavy_SoundScraper::cBinop_9xkaCnbB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_z5ksATLv_sendMessage);
}

void Heavy_SoundScraper::cMsg_7aMBq0Sh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_EDR7bHgq, 0, m, &cPack_EDR7bHgq_sendMessage);
}

void Heavy_SoundScraper::cBinop_DLZb1vpd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_peqiZpeu, HV_BINOP_POW, 1, m, &cBinop_peqiZpeu_sendMessage);
  cMsg_hetvBL3h_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_EDR7bHgq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_z8VOYOp9, 0, m, NULL);
}

void Heavy_SoundScraper::cVar_68NPTu4r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_eXiVaOQZ_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_MqjgkIvg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSend_1GpsOgKb_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_1GpsOgKb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_8vApesEO_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_eXiVaOQZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_OiRrXBoZ_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cIf_soOHGFuI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_LGhEAWbd_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_LOG10, m, &cUnop_X7MACpVP_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cUnop_X7MACpVP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_FAnroYqX_sendMessage);
}

void Heavy_SoundScraper::cCast_cPMpeg8i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_soOHGFuI, 0, m, &cIf_soOHGFuI_sendMessage);
}

void Heavy_SoundScraper::cCast_dX1iN5rN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_65wrVOIR_sendMessage);
}

void Heavy_SoundScraper::cMsg_LGhEAWbd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_NXkYuOEu, 0, m, &cVar_NXkYuOEu_sendMessage);
}

void Heavy_SoundScraper::cBinop_FAnroYqX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 100.0f, 0, m, &cBinop_vukcqJ6f_sendMessage);
}

void Heavy_SoundScraper::cBinop_vukcqJ6f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_kkEpoUHc_sendMessage);
}

void Heavy_SoundScraper::cBinop_kkEpoUHc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_NXkYuOEu, 0, m, &cVar_NXkYuOEu_sendMessage);
}

void Heavy_SoundScraper::cBinop_65wrVOIR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_soOHGFuI, 1, m, &cIf_soOHGFuI_sendMessage);
}

void Heavy_SoundScraper::cBinop_eanc4Li3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_dX1iN5rN_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_cPMpeg8i_sendMessage);
}

void Heavy_SoundScraper::cBinop_gyw3oFYW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_eanc4Li3_sendMessage);
}

void Heavy_SoundScraper::cIf_WMBlm1uz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_QCjlwvMh_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_LOG10, m, &cUnop_mrKqw1qK_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cUnop_mrKqw1qK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_r95yk2Oo_sendMessage);
}

void Heavy_SoundScraper::cCast_VS6EYzuG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_v90nI1uF_sendMessage);
}

void Heavy_SoundScraper::cCast_SDy96kz7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_WMBlm1uz, 0, m, &cIf_WMBlm1uz_sendMessage);
}

void Heavy_SoundScraper::cMsg_QCjlwvMh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cMsg_MqjgkIvg_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_qk6kdWr5_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_IoGTVvIL_sendMessage);
}

void Heavy_SoundScraper::cBinop_r95yk2Oo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 100.0f, 0, m, &cBinop_0UzhxAZ8_sendMessage);
}

void Heavy_SoundScraper::cBinop_0UzhxAZ8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_iAsDu2JD_sendMessage);
}

void Heavy_SoundScraper::cBinop_iAsDu2JD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_MqjgkIvg_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_qk6kdWr5_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_IoGTVvIL_sendMessage);
}

void Heavy_SoundScraper::cBinop_v90nI1uF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_WMBlm1uz, 1, m, &cIf_WMBlm1uz_sendMessage);
}

void Heavy_SoundScraper::cBinop_GI5SE3ec_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_VS6EYzuG_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_SDy96kz7_sendMessage);
}

void Heavy_SoundScraper::cBinop_il5g3S6p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_GI5SE3ec_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_5hDepWSM_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_57R2txWV_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_57R2txWV_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_ApALkWcM, 1, m, &cDelay_ApALkWcM_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_gGhHYcUr_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cDelay_ApALkWcM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_ApALkWcM, m);
  cMsg_hmDGC6vU_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_57R2txWV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_ApALkWcM, 0, m, &cDelay_ApALkWcM_sendMessage);
}

void Heavy_SoundScraper::cCast_gGhHYcUr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_ApALkWcM, 0, m, &cDelay_ApALkWcM_sendMessage);
}

void Heavy_SoundScraper::cVar_uwSSpmLr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_pwHA4CK0, 0, m, &cPack_pwHA4CK0_sendMessage);
}

void Heavy_SoundScraper::cVar_OyMLgXc9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.05776f, 0, m, &cBinop_Qn5gci5R_sendMessage);
}

void Heavy_SoundScraper::cVar_Igdo8Sxz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_f9zLYsq2_sendMessage);
}

void Heavy_SoundScraper::cPack_xYUyzGCB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_GxuX9dDK, 0, m, NULL);
}

void Heavy_SoundScraper::cUnop_vOin5ELL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_rb9bCV7Z_sendMessage);
}

void Heavy_SoundScraper::cBinop_gq9Qg1Wd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_EXP, m, &cUnop_vOin5ELL_sendMessage);
}

void Heavy_SoundScraper::cPack_rhP1bQMt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_lk7epkND, 0, m, NULL);
}

void Heavy_SoundScraper::cVar_kMObPYow_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.5f, 0, m, &cBinop_PorX22ak_sendMessage);
}

void Heavy_SoundScraper::cMsg_nFK5nf2q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_5Eq3nlB1_sendMessage);
}

void Heavy_SoundScraper::cSystem_5Eq3nlB1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_tt2MXWnm_sendMessage);
}

void Heavy_SoundScraper::cDelay_cJ6vGtlD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_cJ6vGtlD, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_BpaUg4vp, 0, m, &cDelay_BpaUg4vp_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_cJ6vGtlD, 0, m, &cDelay_cJ6vGtlD_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_Livcz3dG, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_BpaUg4vp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_BpaUg4vp, m);
  cMsg_s7YDMp1L_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_MMj8Ursu_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_3C8jyGWt_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_OsRKMBnO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Wz573GKQ_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_vhIJk1Ey_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_DWZBOXfM_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_cJ6vGtlD, 2, m, &cDelay_cJ6vGtlD_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_MfP8CXcY_sendMessage);
}

void Heavy_SoundScraper::cMsg_Wz573GKQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_vhIJk1Ey, 0, m, &hTable_vhIJk1Ey_sendMessage);
}

void Heavy_SoundScraper::cBinop_tt2MXWnm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 5000.0f, 0, m, &cBinop_OsRKMBnO_sendMessage);
}

void Heavy_SoundScraper::cMsg_s7YDMp1L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_vhIJk1Ey, 0, m, &hTable_vhIJk1Ey_sendMessage);
}

void Heavy_SoundScraper::cCast_MfP8CXcY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_cJ6vGtlD, 0, m, &cDelay_cJ6vGtlD_sendMessage);
}

void Heavy_SoundScraper::cMsg_DWZBOXfM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_BpaUg4vp, 2, m, &cDelay_BpaUg4vp_sendMessage);
}

void Heavy_SoundScraper::cMsg_3C8jyGWt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_Livcz3dG, 1, m, NULL);
}

void Heavy_SoundScraper::cMsg_Igx93Vbq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_7rkA7fk4_sendMessage);
}

void Heavy_SoundScraper::cSystem_7rkA7fk4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_meG29o6K_sendMessage);
}

void Heavy_SoundScraper::cVar_CNNYNcNM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_hQuX20y1_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSystem_TDGvcRcG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_Q4v9BIcq_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_xmhx0KYd, m);
}

void Heavy_SoundScraper::cBinop_meG29o6K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_Itk7TK5B, m);
}

void Heavy_SoundScraper::cMsg_hQuX20y1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_TDGvcRcG_sendMessage);
}

void Heavy_SoundScraper::cBinop_Q4v9BIcq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_qXVAzdEr, m);
}

void Heavy_SoundScraper::cMsg_ic7iKpNx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_qgpPfplC_sendMessage);
}

void Heavy_SoundScraper::cSystem_qgpPfplC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_t3aNyezf_sendMessage);
}

void Heavy_SoundScraper::cVar_q68DMaA0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_GSX8G0iT_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSystem_4dlTQII6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_duh7CHkW_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_wP98dVQc, m);
}

void Heavy_SoundScraper::cBinop_t3aNyezf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_ESzMXuks, m);
}

void Heavy_SoundScraper::cMsg_GSX8G0iT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_4dlTQII6_sendMessage);
}

void Heavy_SoundScraper::cBinop_duh7CHkW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_dymcxWlX, m);
}

void Heavy_SoundScraper::cBinop_6537XKHt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ZXGIc5m0_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_zZLzPe13_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_gHxm4A1f_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_SGaUi40L_sendMessage);
}

void Heavy_SoundScraper::cCast_SGaUi40L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6537XKHt, HV_BINOP_DIVIDE, 0, m, &cBinop_6537XKHt_sendMessage);
}

void Heavy_SoundScraper::cCast_gHxm4A1f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6537XKHt, HV_BINOP_DIVIDE, 1, m, &cBinop_6537XKHt_sendMessage);
}

void Heavy_SoundScraper::cBinop_rb9bCV7Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_tFCiSVri_sendMessage);
}

void Heavy_SoundScraper::cBinop_Qn5gci5R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 87.3365f, 0, m, &cBinop_gq9Qg1Wd_sendMessage);
}

void Heavy_SoundScraper::cBinop_tFCiSVri_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6537XKHt, HV_BINOP_DIVIDE, 0, m, &cBinop_6537XKHt_sendMessage);
}

void Heavy_SoundScraper::cBinop_PorX22ak_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_rhP1bQMt, 0, m, &cPack_rhP1bQMt_sendMessage);
}

void Heavy_SoundScraper::cBinop_f9zLYsq2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.001f, 0, m, &cBinop_zZLzPe13_sendMessage);
  cPack_onMessage(_c, &Context(_c)->cPack_xYUyzGCB, 0, m, &cPack_xYUyzGCB_sendMessage);
}

void Heavy_SoundScraper::cMsg_UfHtdik3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 100.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_Igdo8Sxz, 0, m, &cVar_Igdo8Sxz_sendMessage);
}

void Heavy_SoundScraper::cMsg_YpBxHFwr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.5f);
  cVar_onMessage(_c, &Context(_c)->cVar_kMObPYow, 0, m, &cVar_kMObPYow_sendMessage);
}

void Heavy_SoundScraper::cMsg_ZXGIc5m0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 30.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_1fVuvFyw, 0, m, NULL);
}

void Heavy_SoundScraper::cVar_W4WQPcAH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_QfTa3oSd, HV_BINOP_MULTIPLY, 0, m, &cBinop_QfTa3oSd_sendMessage);
}

void Heavy_SoundScraper::cMsg_62ZaNWc2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_EtwrUZBI_sendMessage);
}

void Heavy_SoundScraper::cSystem_EtwrUZBI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_EhKelmHM_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_QfTa3oSd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_rltwlUip_sendMessage);
}

void Heavy_SoundScraper::cBinop_RgjvB3sy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_QfTa3oSd, HV_BINOP_MULTIPLY, 1, m, &cBinop_QfTa3oSd_sendMessage);
}

void Heavy_SoundScraper::cMsg_EhKelmHM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_RgjvB3sy_sendMessage);
}

void Heavy_SoundScraper::cBinop_rltwlUip_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_8DSIxjo0_sendMessage);
}

void Heavy_SoundScraper::cBinop_8DSIxjo0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_qAqPSMKI_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_0UciwyL3, m);
}

void Heavy_SoundScraper::cBinop_qAqPSMKI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_AWbLPLRP, m);
}

void Heavy_SoundScraper::cVar_48NckNlx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_L3d6IZnq, HV_BINOP_MULTIPLY, 0, m, &cBinop_L3d6IZnq_sendMessage);
}

void Heavy_SoundScraper::cMsg_kVJbSJ6F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_jRCbYIZU_sendMessage);
}

void Heavy_SoundScraper::cSystem_jRCbYIZU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_3VJDo01m_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_L3d6IZnq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_0Xb7LKJm_sendMessage);
}

void Heavy_SoundScraper::cBinop_YNNrqLOf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_L3d6IZnq, HV_BINOP_MULTIPLY, 1, m, &cBinop_L3d6IZnq_sendMessage);
}

void Heavy_SoundScraper::cMsg_3VJDo01m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_YNNrqLOf_sendMessage);
}

void Heavy_SoundScraper::cBinop_0Xb7LKJm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_0aTmMLeM_sendMessage);
}

void Heavy_SoundScraper::cBinop_0aTmMLeM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_qqtKJLQD_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_t1Vuvfnr, m);
}

void Heavy_SoundScraper::cBinop_qqtKJLQD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_Km2MV9xh, m);
}

void Heavy_SoundScraper::cVar_3O9x0mjC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_5yVfg7eR, HV_BINOP_MULTIPLY, 0, m, &cBinop_5yVfg7eR_sendMessage);
}

void Heavy_SoundScraper::cMsg_Mm7nQiYX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_38IUueda_sendMessage);
}

void Heavy_SoundScraper::cSystem_38IUueda_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_X9FMhuxB_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_5yVfg7eR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_fP0sPUZZ_sendMessage);
}

void Heavy_SoundScraper::cBinop_r19MWvAA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_5yVfg7eR, HV_BINOP_MULTIPLY, 1, m, &cBinop_5yVfg7eR_sendMessage);
}

void Heavy_SoundScraper::cMsg_X9FMhuxB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_r19MWvAA_sendMessage);
}

void Heavy_SoundScraper::cBinop_fP0sPUZZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_WjgJUARt_sendMessage);
}

void Heavy_SoundScraper::cBinop_WjgJUARt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_Q39zt70M_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_ONXlxAYt, m);
}

void Heavy_SoundScraper::cBinop_Q39zt70M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_UDdEKmRm, m);
}

void Heavy_SoundScraper::cMsg_uUH1BRVt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_UNTQHcqu_sendMessage);
}

void Heavy_SoundScraper::cSystem_UNTQHcqu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_1BMCyF0p_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_mWe7l3bg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1e-05f, 0, m, &cBinop_04fB3HzJ_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_cZ1Itnha, 0, m, &cIf_cZ1Itnha_sendMessage);
}

void Heavy_SoundScraper::cIf_cZ1Itnha_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_MwrlwZzI_sendMessage(_c, 0, m);
      cMsg_Jv6nK7MD_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_9HTMbwp6_sendMessage(_c, 0, m);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_eh9BLXy5_sendMessage);
      sVarf_onMessage(_c, &Context(_c)->sVarf_Vk7edBvA, m);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_04fB3HzJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_cZ1Itnha, 1, m, &cIf_cZ1Itnha_sendMessage);
}

void Heavy_SoundScraper::cMsg_9HTMbwp6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_tYHC8Wv4_sendMessage);
}

void Heavy_SoundScraper::cBinop_tYHC8Wv4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_LTG3pOAi, m);
}

void Heavy_SoundScraper::cBinop_eh9BLXy5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_3nYvBQgE_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_3nYvBQgE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_YTrcFrXl_sendMessage);
}

void Heavy_SoundScraper::cBinop_YTrcFrXl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_TKl00kLm_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_TKl00kLm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_RrjJ3hDU_sendMessage);
}

void Heavy_SoundScraper::cBinop_RrjJ3hDU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_cTf8HQBR, m);
}

void Heavy_SoundScraper::cBinop_KqeBEbNd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_QyuLEbsj, m);
}

void Heavy_SoundScraper::cMsg_1BMCyF0p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_KqeBEbNd_sendMessage);
}

void Heavy_SoundScraper::cMsg_MwrlwZzI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_eh9BLXy5_sendMessage);
}

void Heavy_SoundScraper::cMsg_Jv6nK7MD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, -1.0f);
  sVarf_onMessage(_c, &Context(_c)->sVarf_LTG3pOAi, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_Vk7edBvA, m);
}

void Heavy_SoundScraper::cBinop_iK8xDDbK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_48NckNlx, 0, m, &cVar_48NckNlx_sendMessage);
}

void Heavy_SoundScraper::cBinop_joIxQ9J3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_W4WQPcAH, 0, m, &cVar_W4WQPcAH_sendMessage);
}

void Heavy_SoundScraper::cBinop_fILFJBE9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_3O9x0mjC, 0, m, &cVar_3O9x0mjC_sendMessage);
}

void Heavy_SoundScraper::cCast_HT7PXu8Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_WCtoU3g6, m);
}

void Heavy_SoundScraper::cCast_arpIDf4d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.0f, 0, m, &cBinop_joIxQ9J3_sendMessage);
}

void Heavy_SoundScraper::cCast_DaIP2nZ2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.0f, 0, m, &cBinop_fILFJBE9_sendMessage);
}

void Heavy_SoundScraper::cCast_GiEyEYDo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.0f, 0, m, &cBinop_iK8xDDbK_sendMessage);
}

void Heavy_SoundScraper::cTabhead_0NeWkSQb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_TPKF0NRK, HV_BINOP_SUBTRACT, 0, m, &cBinop_TPKF0NRK_sendMessage);
}

void Heavy_SoundScraper::cMsg_TtNy7ACk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_DM325hOP_sendMessage);
}

void Heavy_SoundScraper::cSystem_DM325hOP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_yobW7nkM_sendMessage);
}

void Heavy_SoundScraper::cVar_3ZHo8Mi0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_A0qXFxV4_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_BqwmyDHK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_BqwmyDHK, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_o93no4Ac, 0, m, &cDelay_o93no4Ac_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_jD5IbQdJ, 0, m, &sTabread_jD5IbQdJ_sendMessage);
}

void Heavy_SoundScraper::cDelay_o93no4Ac_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_o93no4Ac, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_jD5IbQdJ, 0, m, &sTabread_jD5IbQdJ_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_o93no4Ac, 0, m, &cDelay_o93no4Ac_sendMessage);
}

void Heavy_SoundScraper::sTabread_jD5IbQdJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_0SpN1Ruw, HV_BINOP_SUBTRACT, 0, m, &cBinop_0SpN1Ruw_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_A950JeTv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Wb3T4zRm, HV_BINOP_MAX, 0, m, &cBinop_Wb3T4zRm_sendMessage);
}

void Heavy_SoundScraper::cBinop_yobW7nkM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_A950JeTv, HV_BINOP_MULTIPLY, 0, m, &cBinop_A950JeTv_sendMessage);
}

void Heavy_SoundScraper::cBinop_TPKF0NRK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_oBJL8EOT_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_jD5IbQdJ, 0, m, &sTabread_jD5IbQdJ_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_hgKvB3uZ_sendMessage);
}

void Heavy_SoundScraper::cSystem_0kEJRKhu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_0SpN1Ruw, HV_BINOP_SUBTRACT, 1, m, &cBinop_0SpN1Ruw_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_o93no4Ac, 2, m, &cDelay_o93no4Ac_sendMessage);
}

void Heavy_SoundScraper::cMsg_A0qXFxV4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_0kEJRKhu_sendMessage);
}

void Heavy_SoundScraper::cMsg_oBJL8EOT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_BqwmyDHK, 0, m, &cDelay_BqwmyDHK_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_o93no4Ac, 0, m, &cDelay_o93no4Ac_sendMessage);
}

void Heavy_SoundScraper::cMsg_goSScwcV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_Wb3T4zRm, HV_BINOP_MAX, 1, m, &cBinop_Wb3T4zRm_sendMessage);
}

void Heavy_SoundScraper::cBinop_Wb3T4zRm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_TPKF0NRK, HV_BINOP_SUBTRACT, 1, m, &cBinop_TPKF0NRK_sendMessage);
}

void Heavy_SoundScraper::cCast_hgKvB3uZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_BqwmyDHK, 0, m, &cDelay_BqwmyDHK_sendMessage);
}

void Heavy_SoundScraper::cBinop_2mMSavRv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_BqwmyDHK, 2, m, &cDelay_BqwmyDHK_sendMessage);
}

void Heavy_SoundScraper::cBinop_0SpN1Ruw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_2mMSavRv_sendMessage);
}

void Heavy_SoundScraper::cCast_KLDcbDYo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_3ZHo8Mi0, 0, m, &cVar_3ZHo8Mi0_sendMessage);
  cMsg_TtNy7ACk_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_0NeWkSQb, 0, m, &cTabhead_0NeWkSQb_sendMessage);
}

void Heavy_SoundScraper::cTabhead_droFzCYz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_9qE5WHmx, HV_BINOP_SUBTRACT, 0, m, &cBinop_9qE5WHmx_sendMessage);
}

void Heavy_SoundScraper::cMsg_GApETzrb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Hnd3yOgU_sendMessage);
}

void Heavy_SoundScraper::cSystem_Hnd3yOgU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_ZAqp8FGH_sendMessage);
}

void Heavy_SoundScraper::cVar_bCo5eEl9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_y7RRHuTC_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_EvJkLTEX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_EvJkLTEX, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_05ELP2ch, 0, m, &cDelay_05ELP2ch_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_XflJIGJu, 0, m, &sTabread_XflJIGJu_sendMessage);
}

void Heavy_SoundScraper::cDelay_05ELP2ch_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_05ELP2ch, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_XflJIGJu, 0, m, &sTabread_XflJIGJu_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_05ELP2ch, 0, m, &cDelay_05ELP2ch_sendMessage);
}

void Heavy_SoundScraper::sTabread_XflJIGJu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_hH6Rp8uA, HV_BINOP_SUBTRACT, 0, m, &cBinop_hH6Rp8uA_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_bUT9xxBC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_rCo5WFRy, HV_BINOP_MAX, 0, m, &cBinop_rCo5WFRy_sendMessage);
}

void Heavy_SoundScraper::cBinop_ZAqp8FGH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_bUT9xxBC, HV_BINOP_MULTIPLY, 0, m, &cBinop_bUT9xxBC_sendMessage);
}

void Heavy_SoundScraper::cBinop_9qE5WHmx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_MfU4HoX3_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_XflJIGJu, 0, m, &sTabread_XflJIGJu_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_rIfu8Eij_sendMessage);
}

void Heavy_SoundScraper::cSystem_3iVsqJDD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_hH6Rp8uA, HV_BINOP_SUBTRACT, 1, m, &cBinop_hH6Rp8uA_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_05ELP2ch, 2, m, &cDelay_05ELP2ch_sendMessage);
}

void Heavy_SoundScraper::cMsg_y7RRHuTC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_3iVsqJDD_sendMessage);
}

void Heavy_SoundScraper::cMsg_MfU4HoX3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_EvJkLTEX, 0, m, &cDelay_EvJkLTEX_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_05ELP2ch, 0, m, &cDelay_05ELP2ch_sendMessage);
}

void Heavy_SoundScraper::cMsg_GjAAtAaZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_rCo5WFRy, HV_BINOP_MAX, 1, m, &cBinop_rCo5WFRy_sendMessage);
}

void Heavy_SoundScraper::cBinop_rCo5WFRy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_9qE5WHmx, HV_BINOP_SUBTRACT, 1, m, &cBinop_9qE5WHmx_sendMessage);
}

void Heavy_SoundScraper::cCast_rIfu8Eij_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_EvJkLTEX, 0, m, &cDelay_EvJkLTEX_sendMessage);
}

void Heavy_SoundScraper::cBinop_lu52Hqkx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_EvJkLTEX, 2, m, &cDelay_EvJkLTEX_sendMessage);
}

void Heavy_SoundScraper::cBinop_hH6Rp8uA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_lu52Hqkx_sendMessage);
}

void Heavy_SoundScraper::cCast_NRaf913G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_bCo5eEl9, 0, m, &cVar_bCo5eEl9_sendMessage);
  cMsg_GApETzrb_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_droFzCYz, 0, m, &cTabhead_droFzCYz_sendMessage);
}

void Heavy_SoundScraper::cTabhead_ezQPKc4W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4qVXwXlv, HV_BINOP_SUBTRACT, 0, m, &cBinop_4qVXwXlv_sendMessage);
}

void Heavy_SoundScraper::cMsg_rjzKMgGX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ow62rxr6_sendMessage);
}

void Heavy_SoundScraper::cSystem_ow62rxr6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_si7JOTsj_sendMessage);
}

void Heavy_SoundScraper::cVar_Zv79gRqB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_iIPcJN5s_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_e5M2k9gm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_e5M2k9gm, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_VMUtglgy, 0, m, &cDelay_VMUtglgy_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_0JWiUFjx, 0, m, &sTabread_0JWiUFjx_sendMessage);
}

void Heavy_SoundScraper::cDelay_VMUtglgy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_VMUtglgy, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_0JWiUFjx, 0, m, &sTabread_0JWiUFjx_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_VMUtglgy, 0, m, &cDelay_VMUtglgy_sendMessage);
}

void Heavy_SoundScraper::sTabread_0JWiUFjx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_KFKhAkZ4, HV_BINOP_SUBTRACT, 0, m, &cBinop_KFKhAkZ4_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_3QQcAhdI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_1CanDtsw, HV_BINOP_MAX, 0, m, &cBinop_1CanDtsw_sendMessage);
}

void Heavy_SoundScraper::cBinop_si7JOTsj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_3QQcAhdI, HV_BINOP_MULTIPLY, 0, m, &cBinop_3QQcAhdI_sendMessage);
}

void Heavy_SoundScraper::cBinop_4qVXwXlv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_zOK0TZ8S_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_0JWiUFjx, 0, m, &sTabread_0JWiUFjx_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_2Sxkh9Tl_sendMessage);
}

void Heavy_SoundScraper::cSystem_s1bS4cVS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_KFKhAkZ4, HV_BINOP_SUBTRACT, 1, m, &cBinop_KFKhAkZ4_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_VMUtglgy, 2, m, &cDelay_VMUtglgy_sendMessage);
}

void Heavy_SoundScraper::cMsg_iIPcJN5s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_s1bS4cVS_sendMessage);
}

void Heavy_SoundScraper::cMsg_zOK0TZ8S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_e5M2k9gm, 0, m, &cDelay_e5M2k9gm_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_VMUtglgy, 0, m, &cDelay_VMUtglgy_sendMessage);
}

void Heavy_SoundScraper::cMsg_CO8VUzoO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_1CanDtsw, HV_BINOP_MAX, 1, m, &cBinop_1CanDtsw_sendMessage);
}

void Heavy_SoundScraper::cBinop_1CanDtsw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4qVXwXlv, HV_BINOP_SUBTRACT, 1, m, &cBinop_4qVXwXlv_sendMessage);
}

void Heavy_SoundScraper::cCast_2Sxkh9Tl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_e5M2k9gm, 0, m, &cDelay_e5M2k9gm_sendMessage);
}

void Heavy_SoundScraper::cBinop_BWBWXBLD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_e5M2k9gm, 2, m, &cDelay_e5M2k9gm_sendMessage);
}

void Heavy_SoundScraper::cBinop_KFKhAkZ4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_BWBWXBLD_sendMessage);
}

void Heavy_SoundScraper::cCast_KkkxclbL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Zv79gRqB, 0, m, &cVar_Zv79gRqB_sendMessage);
  cMsg_rjzKMgGX_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_ezQPKc4W, 0, m, &cTabhead_ezQPKc4W_sendMessage);
}

void Heavy_SoundScraper::cTabhead_3s44gkgu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_jDRipueY, HV_BINOP_SUBTRACT, 0, m, &cBinop_jDRipueY_sendMessage);
}

void Heavy_SoundScraper::cMsg_oRvcvLTn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_hv50lUTK_sendMessage);
}

void Heavy_SoundScraper::cSystem_hv50lUTK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_NIUB1dq4_sendMessage);
}

void Heavy_SoundScraper::cVar_xzjh7ySP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_OJ6Yuyvu_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_wr5mnzke_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_wr5mnzke, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_gmNUSCDr, 0, m, &cDelay_gmNUSCDr_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_je7JarWD, 0, m, &sTabread_je7JarWD_sendMessage);
}

void Heavy_SoundScraper::cDelay_gmNUSCDr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_gmNUSCDr, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_je7JarWD, 0, m, &sTabread_je7JarWD_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_gmNUSCDr, 0, m, &cDelay_gmNUSCDr_sendMessage);
}

void Heavy_SoundScraper::sTabread_je7JarWD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_0cXr7Qlj, HV_BINOP_SUBTRACT, 0, m, &cBinop_0cXr7Qlj_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_SSX9TZbZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_J2XYXbxC, HV_BINOP_MAX, 0, m, &cBinop_J2XYXbxC_sendMessage);
}

void Heavy_SoundScraper::cBinop_NIUB1dq4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_SSX9TZbZ, HV_BINOP_MULTIPLY, 0, m, &cBinop_SSX9TZbZ_sendMessage);
}

void Heavy_SoundScraper::cBinop_jDRipueY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_d38qlLO2_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_je7JarWD, 0, m, &sTabread_je7JarWD_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_PtHGYOvX_sendMessage);
}

void Heavy_SoundScraper::cSystem_WIqKXcaT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_0cXr7Qlj, HV_BINOP_SUBTRACT, 1, m, &cBinop_0cXr7Qlj_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_gmNUSCDr, 2, m, &cDelay_gmNUSCDr_sendMessage);
}

void Heavy_SoundScraper::cMsg_OJ6Yuyvu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_WIqKXcaT_sendMessage);
}

void Heavy_SoundScraper::cMsg_d38qlLO2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_wr5mnzke, 0, m, &cDelay_wr5mnzke_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_gmNUSCDr, 0, m, &cDelay_gmNUSCDr_sendMessage);
}

void Heavy_SoundScraper::cMsg_633w4RSM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_J2XYXbxC, HV_BINOP_MAX, 1, m, &cBinop_J2XYXbxC_sendMessage);
}

void Heavy_SoundScraper::cBinop_J2XYXbxC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_jDRipueY, HV_BINOP_SUBTRACT, 1, m, &cBinop_jDRipueY_sendMessage);
}

void Heavy_SoundScraper::cCast_PtHGYOvX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_wr5mnzke, 0, m, &cDelay_wr5mnzke_sendMessage);
}

void Heavy_SoundScraper::cBinop_d5vnyuvj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_wr5mnzke, 2, m, &cDelay_wr5mnzke_sendMessage);
}

void Heavy_SoundScraper::cBinop_0cXr7Qlj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_d5vnyuvj_sendMessage);
}

void Heavy_SoundScraper::cCast_QyebLsBc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_xzjh7ySP, 0, m, &cVar_xzjh7ySP_sendMessage);
  cMsg_oRvcvLTn_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_3s44gkgu, 0, m, &cTabhead_3s44gkgu_sendMessage);
}

void Heavy_SoundScraper::cMsg_5NNAKo1n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_eeN3NAo8_sendMessage);
}

void Heavy_SoundScraper::cSystem_eeN3NAo8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_ghBPkH1I_sendMessage);
}

void Heavy_SoundScraper::cDelay_Hl4T8VzR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Hl4T8VzR, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_laIkAd4B, 0, m, &cDelay_laIkAd4B_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Hl4T8VzR, 0, m, &cDelay_Hl4T8VzR_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_68XwZE8t, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_laIkAd4B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_laIkAd4B, m);
  cMsg_rnTtpkAX_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_ypJvAtNZ_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_YTPKcBoh_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_7GK3xxWJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_g4l90TB4_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_EX2NbWdD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_7QS9AGjF_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Hl4T8VzR, 2, m, &cDelay_Hl4T8VzR_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_PjjyyjMW_sendMessage);
}

void Heavy_SoundScraper::cMsg_g4l90TB4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_EX2NbWdD, 0, m, &hTable_EX2NbWdD_sendMessage);
}

void Heavy_SoundScraper::cBinop_ghBPkH1I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 58.6435f, 0, m, &cBinop_7GK3xxWJ_sendMessage);
}

void Heavy_SoundScraper::cMsg_rnTtpkAX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_EX2NbWdD, 0, m, &hTable_EX2NbWdD_sendMessage);
}

void Heavy_SoundScraper::cCast_PjjyyjMW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Hl4T8VzR, 0, m, &cDelay_Hl4T8VzR_sendMessage);
}

void Heavy_SoundScraper::cMsg_7QS9AGjF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_laIkAd4B, 2, m, &cDelay_laIkAd4B_sendMessage);
}

void Heavy_SoundScraper::cMsg_YTPKcBoh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_68XwZE8t, 1, m, NULL);
}

void Heavy_SoundScraper::cMsg_7PaqMqCC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_taUifrf6_sendMessage);
}

void Heavy_SoundScraper::cSystem_taUifrf6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_lLLc5uL7_sendMessage);
}

void Heavy_SoundScraper::cDelay_2J42PbzH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_2J42PbzH, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_hH5WVK8o, 0, m, &cDelay_hH5WVK8o_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_2J42PbzH, 0, m, &cDelay_2J42PbzH_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_cPJ4FJgN, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_hH5WVK8o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_hH5WVK8o, m);
  cMsg_D3ZbsHmL_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_U8gC9o1b_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_vdckscpq_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_vkgWVmdw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_2cvcEHSh_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_28ZFj778_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Tb2bX1Qd_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_2J42PbzH, 2, m, &cDelay_2J42PbzH_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_50yb7HiY_sendMessage);
}

void Heavy_SoundScraper::cMsg_2cvcEHSh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_28ZFj778, 0, m, &hTable_28ZFj778_sendMessage);
}

void Heavy_SoundScraper::cBinop_lLLc5uL7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 69.4325f, 0, m, &cBinop_vkgWVmdw_sendMessage);
}

void Heavy_SoundScraper::cMsg_D3ZbsHmL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_28ZFj778, 0, m, &hTable_28ZFj778_sendMessage);
}

void Heavy_SoundScraper::cCast_50yb7HiY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_2J42PbzH, 0, m, &cDelay_2J42PbzH_sendMessage);
}

void Heavy_SoundScraper::cMsg_Tb2bX1Qd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_hH5WVK8o, 2, m, &cDelay_hH5WVK8o_sendMessage);
}

void Heavy_SoundScraper::cMsg_vdckscpq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_cPJ4FJgN, 1, m, NULL);
}

void Heavy_SoundScraper::cMsg_YKlbKeM4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Ce9wbOGr_sendMessage);
}

void Heavy_SoundScraper::cSystem_Ce9wbOGr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_iLiSoLxn_sendMessage);
}

void Heavy_SoundScraper::cDelay_yWQa6TIv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_yWQa6TIv, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_UUGUJzQx, 0, m, &cDelay_UUGUJzQx_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_yWQa6TIv, 0, m, &cDelay_yWQa6TIv_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_pLV6Qlb7, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_UUGUJzQx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_UUGUJzQx, m);
  cMsg_cPWdxNKq_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_TWQJxdNu_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_GBoHaH6O_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_4LIzE1aI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_NY4vljTD_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_lgFvSbvj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_h6rxLlvk_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_yWQa6TIv, 2, m, &cDelay_yWQa6TIv_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_iIsjOTcD_sendMessage);
}

void Heavy_SoundScraper::cMsg_NY4vljTD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_lgFvSbvj, 0, m, &hTable_lgFvSbvj_sendMessage);
}

void Heavy_SoundScraper::cBinop_iLiSoLxn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 74.5234f, 0, m, &cBinop_4LIzE1aI_sendMessage);
}

void Heavy_SoundScraper::cMsg_cPWdxNKq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_lgFvSbvj, 0, m, &hTable_lgFvSbvj_sendMessage);
}

void Heavy_SoundScraper::cCast_iIsjOTcD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_yWQa6TIv, 0, m, &cDelay_yWQa6TIv_sendMessage);
}

void Heavy_SoundScraper::cMsg_h6rxLlvk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_UUGUJzQx, 2, m, &cDelay_UUGUJzQx_sendMessage);
}

void Heavy_SoundScraper::cMsg_GBoHaH6O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_pLV6Qlb7, 1, m, NULL);
}

void Heavy_SoundScraper::cMsg_hccYgUTk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_H4aqlmty_sendMessage);
}

void Heavy_SoundScraper::cSystem_H4aqlmty_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_6AHcbRgu_sendMessage);
}

void Heavy_SoundScraper::cDelay_4kN75IcF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_4kN75IcF, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_mtVZ7G3N, 0, m, &cDelay_mtVZ7G3N_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_4kN75IcF, 0, m, &cDelay_4kN75IcF_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_GHM6ve2y, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_mtVZ7G3N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_mtVZ7G3N, m);
  cMsg_jq8K81oY_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_qheElhGG_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_fupsOi7M_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_OHcB0ItR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_8Rp3kKkV_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_sUDRhsRz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_S6J8gAG6_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_4kN75IcF, 2, m, &cDelay_4kN75IcF_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_gFTzuBKH_sendMessage);
}

void Heavy_SoundScraper::cMsg_8Rp3kKkV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_sUDRhsRz, 0, m, &hTable_sUDRhsRz_sendMessage);
}

void Heavy_SoundScraper::cBinop_6AHcbRgu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 86.1244f, 0, m, &cBinop_OHcB0ItR_sendMessage);
}

void Heavy_SoundScraper::cMsg_jq8K81oY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_sUDRhsRz, 0, m, &hTable_sUDRhsRz_sendMessage);
}

void Heavy_SoundScraper::cCast_gFTzuBKH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_4kN75IcF, 0, m, &cDelay_4kN75IcF_sendMessage);
}

void Heavy_SoundScraper::cMsg_S6J8gAG6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_mtVZ7G3N, 2, m, &cDelay_mtVZ7G3N_sendMessage);
}

void Heavy_SoundScraper::cMsg_fupsOi7M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_GHM6ve2y, 1, m, NULL);
}

void Heavy_SoundScraper::cIf_mJsgeD0d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_rhzfym8V_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_tJK3Zzyj_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cMsg_KmVCdjuQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_bPxFEPQq, HV_BINOP_POW, 0, m, &cBinop_bPxFEPQq_sendMessage);
}

void Heavy_SoundScraper::cBinop_bPxFEPQq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.125f, 0, m, &cBinop_fyRc4XIe_sendMessage);
}

void Heavy_SoundScraper::cBinop_keViaESu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_yuP76A4N_sendMessage);
}

void Heavy_SoundScraper::cCast_mn8WuHKR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_jOxKPIrH_sendMessage);
}

void Heavy_SoundScraper::cCast_NgfiCLzs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_mJsgeD0d, 0, m, &cIf_mJsgeD0d_sendMessage);
}

void Heavy_SoundScraper::cBinop_jOxKPIrH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_mJsgeD0d, 1, m, &cIf_mJsgeD0d_sendMessage);
}

void Heavy_SoundScraper::cBinop_tJK3Zzyj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_keViaESu_sendMessage);
}

void Heavy_SoundScraper::cMsg_rhzfym8V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.125f, 0, m, &cBinop_fyRc4XIe_sendMessage);
}

void Heavy_SoundScraper::cBinop_yuP76A4N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_bPxFEPQq, HV_BINOP_POW, 1, m, &cBinop_bPxFEPQq_sendMessage);
  cMsg_KmVCdjuQ_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_yQeXeUk5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_z0zOuuMF, 0, m, NULL);
}

void Heavy_SoundScraper::cPack_AFdVsdAV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_jqDt2JHm, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_ICzk55Af_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_JBFqW9ol_sendMessage);
}

void Heavy_SoundScraper::cBinop_JBFqW9ol_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 200.0f, 0, m, &cBinop_hc88Hrpp_sendMessage);
}

void Heavy_SoundScraper::cVar_3rhRsBRc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_dIarltvC, HV_BINOP_MULTIPLY, 0, m, &cBinop_dIarltvC_sendMessage);
}

void Heavy_SoundScraper::cMsg_Zew8JQyO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_pBPLtITG_sendMessage);
}

void Heavy_SoundScraper::cSystem_pBPLtITG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_bz9PzsgC_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_dIarltvC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_BaFcff75_sendMessage);
}

void Heavy_SoundScraper::cBinop_RRV0MkuR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_dIarltvC, HV_BINOP_MULTIPLY, 1, m, &cBinop_dIarltvC_sendMessage);
}

void Heavy_SoundScraper::cMsg_bz9PzsgC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_RRV0MkuR_sendMessage);
}

void Heavy_SoundScraper::cBinop_BaFcff75_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_6sLhoa9J_sendMessage);
}

void Heavy_SoundScraper::cBinop_6sLhoa9J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_3YTwBF60_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_bYAW0lRE, m);
}

void Heavy_SoundScraper::cBinop_3YTwBF60_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_wmD7T1pZ, m);
}

void Heavy_SoundScraper::cVar_9iNKqoVA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_mn8WuHKR_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_NgfiCLzs_sendMessage);
}

void Heavy_SoundScraper::cVar_cyxqyKDW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 100.0f, 0, m, &cBinop_ICzk55Af_sendMessage);
}

void Heavy_SoundScraper::cVar_lbm63Qtq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_tZQlV1nM_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_Km74vsg8, 0, m, &cIf_Km74vsg8_sendMessage);
}

void Heavy_SoundScraper::cVar_pVcev6ol_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 100.0f, 0, m, &cBinop_OJgJjhMv_sendMessage);
}

void Heavy_SoundScraper::cIf_Km74vsg8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_WMdriDqT_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cVar_onMessage(_c, &Context(_c)->cVar_lBK10Z6K, 0, m, &cVar_lBK10Z6K_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_tZQlV1nM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_Km74vsg8, 1, m, &cIf_Km74vsg8_sendMessage);
}

void Heavy_SoundScraper::cBinop_OJgJjhMv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_QPpQOo11_sendMessage);
}

void Heavy_SoundScraper::cBinop_QPpQOo11_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_NzRi3X7d, 0, m, &cVar_NzRi3X7d_sendMessage);
}

void Heavy_SoundScraper::cTabhead_QiOOFcml_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_pXJQbiLW, HV_BINOP_SUBTRACT, 0, m, &cBinop_pXJQbiLW_sendMessage);
}

void Heavy_SoundScraper::cMsg_PQ7T3nCM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_YUZ41rJb_sendMessage);
}

void Heavy_SoundScraper::cSystem_YUZ41rJb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_dbpnzNOw_sendMessage);
}

void Heavy_SoundScraper::cVar_pKPtBNOl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_muTv3Cx2_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_T5nEDQit_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_T5nEDQit, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_8cuTCb7w, 0, m, &cDelay_8cuTCb7w_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_qqQxRIH1, 0, m, &sTabread_qqQxRIH1_sendMessage);
}

void Heavy_SoundScraper::cDelay_8cuTCb7w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_8cuTCb7w, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_qqQxRIH1, 0, m, &sTabread_qqQxRIH1_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_8cuTCb7w, 0, m, &cDelay_8cuTCb7w_sendMessage);
}

void Heavy_SoundScraper::sTabread_qqQxRIH1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_SXSG2UBl, HV_BINOP_SUBTRACT, 0, m, &cBinop_SXSG2UBl_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_crAnvbSm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_eS1QCKEM, HV_BINOP_MAX, 0, m, &cBinop_eS1QCKEM_sendMessage);
}

void Heavy_SoundScraper::cBinop_dbpnzNOw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_crAnvbSm, HV_BINOP_MULTIPLY, 0, m, &cBinop_crAnvbSm_sendMessage);
}

void Heavy_SoundScraper::cBinop_pXJQbiLW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_4GLveQbE_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_qqQxRIH1, 0, m, &sTabread_qqQxRIH1_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_xiMC6wOt_sendMessage);
}

void Heavy_SoundScraper::cSystem_JSLIPfz6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_SXSG2UBl, HV_BINOP_SUBTRACT, 1, m, &cBinop_SXSG2UBl_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_8cuTCb7w, 2, m, &cDelay_8cuTCb7w_sendMessage);
}

void Heavy_SoundScraper::cMsg_muTv3Cx2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_JSLIPfz6_sendMessage);
}

void Heavy_SoundScraper::cMsg_4GLveQbE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_T5nEDQit, 0, m, &cDelay_T5nEDQit_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_8cuTCb7w, 0, m, &cDelay_8cuTCb7w_sendMessage);
}

void Heavy_SoundScraper::cMsg_qlvLB5gH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_eS1QCKEM, HV_BINOP_MAX, 1, m, &cBinop_eS1QCKEM_sendMessage);
}

void Heavy_SoundScraper::cBinop_eS1QCKEM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_pXJQbiLW, HV_BINOP_SUBTRACT, 1, m, &cBinop_pXJQbiLW_sendMessage);
}

void Heavy_SoundScraper::cCast_xiMC6wOt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_T5nEDQit, 0, m, &cDelay_T5nEDQit_sendMessage);
}

void Heavy_SoundScraper::cBinop_OuntnjOv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_T5nEDQit, 2, m, &cDelay_T5nEDQit_sendMessage);
}

void Heavy_SoundScraper::cBinop_SXSG2UBl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_OuntnjOv_sendMessage);
}

void Heavy_SoundScraper::cCast_cjraSAGm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_pKPtBNOl, 0, m, &cVar_pKPtBNOl_sendMessage);
  cMsg_PQ7T3nCM_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_QiOOFcml, 0, m, &cTabhead_QiOOFcml_sendMessage);
}

void Heavy_SoundScraper::cMsg_T5MSRbEg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_QZ3MiJEr_sendMessage);
}

void Heavy_SoundScraper::cSystem_QZ3MiJEr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_BeotMt6A_sendMessage);
}

void Heavy_SoundScraper::cDelay_LwvXKkgz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_LwvXKkgz, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_EzUQOb5J, 0, m, &cDelay_EzUQOb5J_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_LwvXKkgz, 0, m, &cDelay_LwvXKkgz_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_AC7RFqlE, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_EzUQOb5J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_EzUQOb5J, m);
  cMsg_ExIUdV72_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_YnYWXg5u_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_33OYBjFS_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_hGKdbKJV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_jL3BNnPK_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_agfe5c5k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_gR3NY5Rv_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_LwvXKkgz, 2, m, &cDelay_LwvXKkgz_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_WrVAzG8q_sendMessage);
}

void Heavy_SoundScraper::cMsg_jL3BNnPK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_agfe5c5k, 0, m, &hTable_agfe5c5k_sendMessage);
}

void Heavy_SoundScraper::cBinop_BeotMt6A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 13.645f, 0, m, &cBinop_hGKdbKJV_sendMessage);
}

void Heavy_SoundScraper::cMsg_ExIUdV72_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_agfe5c5k, 0, m, &hTable_agfe5c5k_sendMessage);
}

void Heavy_SoundScraper::cCast_WrVAzG8q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_LwvXKkgz, 0, m, &cDelay_LwvXKkgz_sendMessage);
}

void Heavy_SoundScraper::cMsg_gR3NY5Rv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_EzUQOb5J, 2, m, &cDelay_EzUQOb5J_sendMessage);
}

void Heavy_SoundScraper::cMsg_33OYBjFS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_AC7RFqlE, 1, m, NULL);
}

void Heavy_SoundScraper::cTabhead_kDXQ7QLM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_r2L03AIi, HV_BINOP_SUBTRACT, 0, m, &cBinop_r2L03AIi_sendMessage);
}

void Heavy_SoundScraper::cMsg_ALmWWi38_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_jEkN4VQp_sendMessage);
}

void Heavy_SoundScraper::cSystem_jEkN4VQp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_LnpqPgHu_sendMessage);
}

void Heavy_SoundScraper::cVar_S4EuVlB0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_jh3kz4Pc_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_ROf0Ysqv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_ROf0Ysqv, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_T4yLfQmJ, 0, m, &cDelay_T4yLfQmJ_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_OVjTHdeX, 0, m, &sTabread_OVjTHdeX_sendMessage);
}

void Heavy_SoundScraper::cDelay_T4yLfQmJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_T4yLfQmJ, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_OVjTHdeX, 0, m, &sTabread_OVjTHdeX_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_T4yLfQmJ, 0, m, &cDelay_T4yLfQmJ_sendMessage);
}

void Heavy_SoundScraper::sTabread_OVjTHdeX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_eogrrdow, HV_BINOP_SUBTRACT, 0, m, &cBinop_eogrrdow_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_SgZW07GD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_qUKE8I4L, HV_BINOP_MAX, 0, m, &cBinop_qUKE8I4L_sendMessage);
}

void Heavy_SoundScraper::cBinop_LnpqPgHu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_SgZW07GD, HV_BINOP_MULTIPLY, 0, m, &cBinop_SgZW07GD_sendMessage);
}

void Heavy_SoundScraper::cBinop_r2L03AIi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_UpnpFNs2_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_OVjTHdeX, 0, m, &sTabread_OVjTHdeX_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ezTYDQ5H_sendMessage);
}

void Heavy_SoundScraper::cSystem_ZD2pi7qb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_eogrrdow, HV_BINOP_SUBTRACT, 1, m, &cBinop_eogrrdow_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_T4yLfQmJ, 2, m, &cDelay_T4yLfQmJ_sendMessage);
}

void Heavy_SoundScraper::cMsg_jh3kz4Pc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ZD2pi7qb_sendMessage);
}

void Heavy_SoundScraper::cMsg_UpnpFNs2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_ROf0Ysqv, 0, m, &cDelay_ROf0Ysqv_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_T4yLfQmJ, 0, m, &cDelay_T4yLfQmJ_sendMessage);
}

void Heavy_SoundScraper::cMsg_Ygg71HIO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_qUKE8I4L, HV_BINOP_MAX, 1, m, &cBinop_qUKE8I4L_sendMessage);
}

void Heavy_SoundScraper::cBinop_qUKE8I4L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_r2L03AIi, HV_BINOP_SUBTRACT, 1, m, &cBinop_r2L03AIi_sendMessage);
}

void Heavy_SoundScraper::cCast_ezTYDQ5H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_ROf0Ysqv, 0, m, &cDelay_ROf0Ysqv_sendMessage);
}

void Heavy_SoundScraper::cBinop_wphqdMtU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_ROf0Ysqv, 2, m, &cDelay_ROf0Ysqv_sendMessage);
}

void Heavy_SoundScraper::cBinop_eogrrdow_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_wphqdMtU_sendMessage);
}

void Heavy_SoundScraper::cCast_KUxElVw7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_S4EuVlB0, 0, m, &cVar_S4EuVlB0_sendMessage);
  cMsg_ALmWWi38_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_kDXQ7QLM, 0, m, &cTabhead_kDXQ7QLM_sendMessage);
}

void Heavy_SoundScraper::cMsg_zt4otUNN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_mbLaMQ7A_sendMessage);
}

void Heavy_SoundScraper::cSystem_mbLaMQ7A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_5hTV9mRB_sendMessage);
}

void Heavy_SoundScraper::cDelay_rH9sp1un_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_rH9sp1un, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ijjkJaeO, 0, m, &cDelay_ijjkJaeO_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_rH9sp1un, 0, m, &cDelay_rH9sp1un_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_pt0bpv9P, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_ijjkJaeO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_ijjkJaeO, m);
  cMsg_e627ainM_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_DuNtLdys_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_cEXVKFV8_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_1R899AeV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_kJhQ0JrY_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_X9Rp52Xj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_fDVJV4tS_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_rH9sp1un, 2, m, &cDelay_rH9sp1un_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_dY89uyGg_sendMessage);
}

void Heavy_SoundScraper::cMsg_kJhQ0JrY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_X9Rp52Xj, 0, m, &hTable_X9Rp52Xj_sendMessage);
}

void Heavy_SoundScraper::cBinop_5hTV9mRB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 16.364f, 0, m, &cBinop_1R899AeV_sendMessage);
}

void Heavy_SoundScraper::cMsg_e627ainM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_X9Rp52Xj, 0, m, &hTable_X9Rp52Xj_sendMessage);
}

void Heavy_SoundScraper::cCast_dY89uyGg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_rH9sp1un, 0, m, &cDelay_rH9sp1un_sendMessage);
}

void Heavy_SoundScraper::cMsg_fDVJV4tS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_ijjkJaeO, 2, m, &cDelay_ijjkJaeO_sendMessage);
}

void Heavy_SoundScraper::cMsg_cEXVKFV8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_pt0bpv9P, 1, m, NULL);
}

void Heavy_SoundScraper::cTabhead_ahsqQdLQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_facGQ0vA, HV_BINOP_SUBTRACT, 0, m, &cBinop_facGQ0vA_sendMessage);
}

void Heavy_SoundScraper::cMsg_97bramSA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_DqzhOxUQ_sendMessage);
}

void Heavy_SoundScraper::cSystem_DqzhOxUQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_c6Pzq4wf_sendMessage);
}

void Heavy_SoundScraper::cVar_tMXvxuga_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Mcbw10h7_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_PGV6AEeA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_PGV6AEeA, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_LbHjd7xB, 0, m, &cDelay_LbHjd7xB_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_xjG6hQnr, 0, m, &sTabread_xjG6hQnr_sendMessage);
}

void Heavy_SoundScraper::cDelay_LbHjd7xB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_LbHjd7xB, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_xjG6hQnr, 0, m, &sTabread_xjG6hQnr_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_LbHjd7xB, 0, m, &cDelay_LbHjd7xB_sendMessage);
}

void Heavy_SoundScraper::sTabread_xjG6hQnr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_dPiKj5gG, HV_BINOP_SUBTRACT, 0, m, &cBinop_dPiKj5gG_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_lHqJ41KC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_eXiONQ5Q, HV_BINOP_MAX, 0, m, &cBinop_eXiONQ5Q_sendMessage);
}

void Heavy_SoundScraper::cBinop_c6Pzq4wf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_lHqJ41KC, HV_BINOP_MULTIPLY, 0, m, &cBinop_lHqJ41KC_sendMessage);
}

void Heavy_SoundScraper::cBinop_facGQ0vA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_gSXxobum_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_xjG6hQnr, 0, m, &sTabread_xjG6hQnr_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_lrZnBg83_sendMessage);
}

void Heavy_SoundScraper::cSystem_f4cDIF2R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_dPiKj5gG, HV_BINOP_SUBTRACT, 1, m, &cBinop_dPiKj5gG_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_LbHjd7xB, 2, m, &cDelay_LbHjd7xB_sendMessage);
}

void Heavy_SoundScraper::cMsg_Mcbw10h7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_f4cDIF2R_sendMessage);
}

void Heavy_SoundScraper::cMsg_gSXxobum_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_PGV6AEeA, 0, m, &cDelay_PGV6AEeA_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_LbHjd7xB, 0, m, &cDelay_LbHjd7xB_sendMessage);
}

void Heavy_SoundScraper::cMsg_0YU4gTy0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_eXiONQ5Q, HV_BINOP_MAX, 1, m, &cBinop_eXiONQ5Q_sendMessage);
}

void Heavy_SoundScraper::cBinop_eXiONQ5Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_facGQ0vA, HV_BINOP_SUBTRACT, 1, m, &cBinop_facGQ0vA_sendMessage);
}

void Heavy_SoundScraper::cCast_lrZnBg83_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_PGV6AEeA, 0, m, &cDelay_PGV6AEeA_sendMessage);
}

void Heavy_SoundScraper::cBinop_UOsstNAB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_PGV6AEeA, 2, m, &cDelay_PGV6AEeA_sendMessage);
}

void Heavy_SoundScraper::cBinop_dPiKj5gG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_UOsstNAB_sendMessage);
}

void Heavy_SoundScraper::cCast_y2FeTKIp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_tMXvxuga, 0, m, &cVar_tMXvxuga_sendMessage);
  cMsg_97bramSA_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_ahsqQdLQ, 0, m, &cTabhead_ahsqQdLQ_sendMessage);
}

void Heavy_SoundScraper::cMsg_Vr47FdT3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_h2CnhQyi_sendMessage);
}

void Heavy_SoundScraper::cSystem_h2CnhQyi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_y4isWYDa_sendMessage);
}

void Heavy_SoundScraper::cDelay_EDiyZhJX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_EDiyZhJX, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_CSDkFQk0, 0, m, &cDelay_CSDkFQk0_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_EDiyZhJX, 0, m, &cDelay_EDiyZhJX_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_yHsIgnQe, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_CSDkFQk0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_CSDkFQk0, m);
  cMsg_qbAgqT2s_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_fkgDbPUg_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_kpHheTJ3_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_J0GdaDpS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_4yoEnHiA_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_iUbvzypp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_w3r93pJ3_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_EDiyZhJX, 2, m, &cDelay_EDiyZhJX_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_kmGmLnZu_sendMessage);
}

void Heavy_SoundScraper::cMsg_4yoEnHiA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_iUbvzypp, 0, m, &hTable_iUbvzypp_sendMessage);
}

void Heavy_SoundScraper::cBinop_y4isWYDa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 19.392f, 0, m, &cBinop_J0GdaDpS_sendMessage);
}

void Heavy_SoundScraper::cMsg_qbAgqT2s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_iUbvzypp, 0, m, &hTable_iUbvzypp_sendMessage);
}

void Heavy_SoundScraper::cCast_kmGmLnZu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_EDiyZhJX, 0, m, &cDelay_EDiyZhJX_sendMessage);
}

void Heavy_SoundScraper::cMsg_w3r93pJ3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_CSDkFQk0, 2, m, &cDelay_CSDkFQk0_sendMessage);
}

void Heavy_SoundScraper::cMsg_kpHheTJ3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_yHsIgnQe, 1, m, NULL);
}

void Heavy_SoundScraper::cTabhead_pFISdq5z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_k9Ag6k3n, HV_BINOP_SUBTRACT, 0, m, &cBinop_k9Ag6k3n_sendMessage);
}

void Heavy_SoundScraper::cMsg_v5BbUSHf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_zQZ7mxTc_sendMessage);
}

void Heavy_SoundScraper::cSystem_zQZ7mxTc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_Z7RIfqMc_sendMessage);
}

void Heavy_SoundScraper::cVar_WaX5KXjt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_o1fUoY7N_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_B7TYCZdh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_B7TYCZdh, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_QvcgaLA6, 0, m, &cDelay_QvcgaLA6_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_1wURQaYl, 0, m, &sTabread_1wURQaYl_sendMessage);
}

void Heavy_SoundScraper::cDelay_QvcgaLA6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_QvcgaLA6, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_1wURQaYl, 0, m, &sTabread_1wURQaYl_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_QvcgaLA6, 0, m, &cDelay_QvcgaLA6_sendMessage);
}

void Heavy_SoundScraper::sTabread_1wURQaYl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_CyZqt5ks, HV_BINOP_SUBTRACT, 0, m, &cBinop_CyZqt5ks_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_fOApZV4J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_gZjKCL3A, HV_BINOP_MAX, 0, m, &cBinop_gZjKCL3A_sendMessage);
}

void Heavy_SoundScraper::cBinop_Z7RIfqMc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_fOApZV4J, HV_BINOP_MULTIPLY, 0, m, &cBinop_fOApZV4J_sendMessage);
}

void Heavy_SoundScraper::cBinop_k9Ag6k3n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_GULRRsVr_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_1wURQaYl, 0, m, &sTabread_1wURQaYl_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_kXilepuI_sendMessage);
}

void Heavy_SoundScraper::cSystem_xFoIzFig_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_CyZqt5ks, HV_BINOP_SUBTRACT, 1, m, &cBinop_CyZqt5ks_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_QvcgaLA6, 2, m, &cDelay_QvcgaLA6_sendMessage);
}

void Heavy_SoundScraper::cMsg_o1fUoY7N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_xFoIzFig_sendMessage);
}

void Heavy_SoundScraper::cMsg_GULRRsVr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_B7TYCZdh, 0, m, &cDelay_B7TYCZdh_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_QvcgaLA6, 0, m, &cDelay_QvcgaLA6_sendMessage);
}

void Heavy_SoundScraper::cMsg_yJQqhPRb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_gZjKCL3A, HV_BINOP_MAX, 1, m, &cBinop_gZjKCL3A_sendMessage);
}

void Heavy_SoundScraper::cBinop_gZjKCL3A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_k9Ag6k3n, HV_BINOP_SUBTRACT, 1, m, &cBinop_k9Ag6k3n_sendMessage);
}

void Heavy_SoundScraper::cCast_kXilepuI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_B7TYCZdh, 0, m, &cDelay_B7TYCZdh_sendMessage);
}

void Heavy_SoundScraper::cBinop_NYy93vXi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_B7TYCZdh, 2, m, &cDelay_B7TYCZdh_sendMessage);
}

void Heavy_SoundScraper::cBinop_CyZqt5ks_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_NYy93vXi_sendMessage);
}

void Heavy_SoundScraper::cCast_Li1N7aTW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_WaX5KXjt, 0, m, &cVar_WaX5KXjt_sendMessage);
  cMsg_v5BbUSHf_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_pFISdq5z, 0, m, &cTabhead_pFISdq5z_sendMessage);
}

void Heavy_SoundScraper::cMsg_cUBePfno_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_6Rgl6b8E_sendMessage);
}

void Heavy_SoundScraper::cSystem_6Rgl6b8E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_ARMxYdDu_sendMessage);
}

void Heavy_SoundScraper::cDelay_lYbemdsU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_lYbemdsU, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_WVpeQjkw, 0, m, &cDelay_WVpeQjkw_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_lYbemdsU, 0, m, &cDelay_lYbemdsU_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_qDzEn88v, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_WVpeQjkw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_WVpeQjkw, m);
  cMsg_TYHCo9OC_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_6fD2ZI3t_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_EZKmGy0h_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_LTNy4IOV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_OGp9V4sZ_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_ah2ngOUs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Tp6RwxNt_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_lYbemdsU, 2, m, &cDelay_lYbemdsU_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_V4ZRCCNB_sendMessage);
}

void Heavy_SoundScraper::cMsg_OGp9V4sZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_ah2ngOUs, 0, m, &hTable_ah2ngOUs_sendMessage);
}

void Heavy_SoundScraper::cBinop_ARMxYdDu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 25.796f, 0, m, &cBinop_LTNy4IOV_sendMessage);
}

void Heavy_SoundScraper::cMsg_TYHCo9OC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_ah2ngOUs, 0, m, &hTable_ah2ngOUs_sendMessage);
}

void Heavy_SoundScraper::cCast_V4ZRCCNB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_lYbemdsU, 0, m, &cDelay_lYbemdsU_sendMessage);
}

void Heavy_SoundScraper::cMsg_Tp6RwxNt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_WVpeQjkw, 2, m, &cDelay_WVpeQjkw_sendMessage);
}

void Heavy_SoundScraper::cMsg_EZKmGy0h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_qDzEn88v, 1, m, NULL);
}

void Heavy_SoundScraper::cTabhead_WywdLMgD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_hxKr90jA, HV_BINOP_SUBTRACT, 0, m, &cBinop_hxKr90jA_sendMessage);
}

void Heavy_SoundScraper::cMsg_BT2zkuNp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ksxwU8oB_sendMessage);
}

void Heavy_SoundScraper::cSystem_ksxwU8oB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_A741dDsw_sendMessage);
}

void Heavy_SoundScraper::cVar_cNWyJC44_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Bhi7HQan_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_Gst1ZEzt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Gst1ZEzt, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_D6rnqTnt, 0, m, &cDelay_D6rnqTnt_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_1mmTSLm7, 0, m, &sTabread_1mmTSLm7_sendMessage);
}

void Heavy_SoundScraper::cDelay_D6rnqTnt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_D6rnqTnt, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_1mmTSLm7, 0, m, &sTabread_1mmTSLm7_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_D6rnqTnt, 0, m, &cDelay_D6rnqTnt_sendMessage);
}

void Heavy_SoundScraper::sTabread_1mmTSLm7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_fdOC22Vk, HV_BINOP_SUBTRACT, 0, m, &cBinop_fdOC22Vk_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_gJ1aCxzk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_fCbxwNt1, HV_BINOP_MAX, 0, m, &cBinop_fCbxwNt1_sendMessage);
}

void Heavy_SoundScraper::cBinop_A741dDsw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_gJ1aCxzk, HV_BINOP_MULTIPLY, 0, m, &cBinop_gJ1aCxzk_sendMessage);
}

void Heavy_SoundScraper::cBinop_hxKr90jA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Ga7hRKCI_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_1mmTSLm7, 0, m, &sTabread_1mmTSLm7_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_AIV8GnLN_sendMessage);
}

void Heavy_SoundScraper::cSystem_OBwRyjSq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_fdOC22Vk, HV_BINOP_SUBTRACT, 1, m, &cBinop_fdOC22Vk_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_D6rnqTnt, 2, m, &cDelay_D6rnqTnt_sendMessage);
}

void Heavy_SoundScraper::cMsg_Bhi7HQan_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_OBwRyjSq_sendMessage);
}

void Heavy_SoundScraper::cMsg_Ga7hRKCI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_Gst1ZEzt, 0, m, &cDelay_Gst1ZEzt_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_D6rnqTnt, 0, m, &cDelay_D6rnqTnt_sendMessage);
}

void Heavy_SoundScraper::cMsg_AIhUKNtz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_fCbxwNt1, HV_BINOP_MAX, 1, m, &cBinop_fCbxwNt1_sendMessage);
}

void Heavy_SoundScraper::cBinop_fCbxwNt1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_hxKr90jA, HV_BINOP_SUBTRACT, 1, m, &cBinop_hxKr90jA_sendMessage);
}

void Heavy_SoundScraper::cCast_AIV8GnLN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Gst1ZEzt, 0, m, &cDelay_Gst1ZEzt_sendMessage);
}

void Heavy_SoundScraper::cBinop_uDCzpclk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Gst1ZEzt, 2, m, &cDelay_Gst1ZEzt_sendMessage);
}

void Heavy_SoundScraper::cBinop_fdOC22Vk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_uDCzpclk_sendMessage);
}

void Heavy_SoundScraper::cCast_hbleQVNj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_cNWyJC44, 0, m, &cVar_cNWyJC44_sendMessage);
  cMsg_BT2zkuNp_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_WywdLMgD, 0, m, &cTabhead_WywdLMgD_sendMessage);
}

void Heavy_SoundScraper::cMsg_lNAVCesf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_lxLtGMpa_sendMessage);
}

void Heavy_SoundScraper::cSystem_lxLtGMpa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_OmW5guex_sendMessage);
}

void Heavy_SoundScraper::cDelay_yduAxMF5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_yduAxMF5, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_KKfSloIp, 0, m, &cDelay_KKfSloIp_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_yduAxMF5, 0, m, &cDelay_yduAxMF5_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_QJKGekIF, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_KKfSloIp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_KKfSloIp, m);
  cMsg_F3qYYDL9_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_at2V7wZp_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_DnH23DDw_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_iv28SUxw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_nFReLlBl_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_U6dbCP58_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_SuMxPhgy_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_yduAxMF5, 2, m, &cDelay_yduAxMF5_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_zcBNv42M_sendMessage);
}

void Heavy_SoundScraper::cMsg_nFReLlBl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_U6dbCP58, 0, m, &hTable_U6dbCP58_sendMessage);
}

void Heavy_SoundScraper::cBinop_OmW5guex_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 43.5337f, 0, m, &cBinop_iv28SUxw_sendMessage);
}

void Heavy_SoundScraper::cMsg_F3qYYDL9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_U6dbCP58, 0, m, &hTable_U6dbCP58_sendMessage);
}

void Heavy_SoundScraper::cCast_zcBNv42M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_yduAxMF5, 0, m, &cDelay_yduAxMF5_sendMessage);
}

void Heavy_SoundScraper::cMsg_SuMxPhgy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_KKfSloIp, 2, m, &cDelay_KKfSloIp_sendMessage);
}

void Heavy_SoundScraper::cMsg_DnH23DDw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_QJKGekIF, 1, m, NULL);
}

void Heavy_SoundScraper::cTabhead_6N6O1MMN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_djpvQCWA, HV_BINOP_SUBTRACT, 0, m, &cBinop_djpvQCWA_sendMessage);
}

void Heavy_SoundScraper::cMsg_xulu5X8H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_y8ulUQgM_sendMessage);
}

void Heavy_SoundScraper::cSystem_y8ulUQgM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_7mKQ9Epf_sendMessage);
}

void Heavy_SoundScraper::cVar_esOvarCE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_RkRZ74lw_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_JrmpE96l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_JrmpE96l, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_f6VgesCo, 0, m, &cDelay_f6VgesCo_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_5iyvOZtU, 0, m, &sTabread_5iyvOZtU_sendMessage);
}

void Heavy_SoundScraper::cDelay_f6VgesCo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_f6VgesCo, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_5iyvOZtU, 0, m, &sTabread_5iyvOZtU_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_f6VgesCo, 0, m, &cDelay_f6VgesCo_sendMessage);
}

void Heavy_SoundScraper::sTabread_5iyvOZtU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_mN4dNoDx, HV_BINOP_SUBTRACT, 0, m, &cBinop_mN4dNoDx_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_2cte1FGA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_eagQneGN, HV_BINOP_MAX, 0, m, &cBinop_eagQneGN_sendMessage);
}

void Heavy_SoundScraper::cBinop_7mKQ9Epf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_2cte1FGA, HV_BINOP_MULTIPLY, 0, m, &cBinop_2cte1FGA_sendMessage);
}

void Heavy_SoundScraper::cBinop_djpvQCWA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_p71mqZkn_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_5iyvOZtU, 0, m, &sTabread_5iyvOZtU_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_3VYLVoIN_sendMessage);
}

void Heavy_SoundScraper::cSystem_KB48gjYu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_mN4dNoDx, HV_BINOP_SUBTRACT, 1, m, &cBinop_mN4dNoDx_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_f6VgesCo, 2, m, &cDelay_f6VgesCo_sendMessage);
}

void Heavy_SoundScraper::cMsg_RkRZ74lw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_KB48gjYu_sendMessage);
}

void Heavy_SoundScraper::cMsg_p71mqZkn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_JrmpE96l, 0, m, &cDelay_JrmpE96l_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_f6VgesCo, 0, m, &cDelay_f6VgesCo_sendMessage);
}

void Heavy_SoundScraper::cMsg_Mvw8dp0w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_eagQneGN, HV_BINOP_MAX, 1, m, &cBinop_eagQneGN_sendMessage);
}

void Heavy_SoundScraper::cBinop_eagQneGN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_djpvQCWA, HV_BINOP_SUBTRACT, 1, m, &cBinop_djpvQCWA_sendMessage);
}

void Heavy_SoundScraper::cCast_3VYLVoIN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_JrmpE96l, 0, m, &cDelay_JrmpE96l_sendMessage);
}

void Heavy_SoundScraper::cBinop_VgilgeAx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_JrmpE96l, 2, m, &cDelay_JrmpE96l_sendMessage);
}

void Heavy_SoundScraper::cBinop_mN4dNoDx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_VgilgeAx_sendMessage);
}

void Heavy_SoundScraper::cCast_19hG6J59_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_esOvarCE, 0, m, &cVar_esOvarCE_sendMessage);
  cMsg_xulu5X8H_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_6N6O1MMN, 0, m, &cTabhead_6N6O1MMN_sendMessage);
}

void Heavy_SoundScraper::cMsg_gbuNbLNn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_2kR8OzQo_sendMessage);
}

void Heavy_SoundScraper::cSystem_2kR8OzQo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_tbt8hm9U_sendMessage);
}

void Heavy_SoundScraper::cDelay_q619Tmry_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_q619Tmry, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_VpNcoCMf, 0, m, &cDelay_VpNcoCMf_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_q619Tmry, 0, m, &cDelay_q619Tmry_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_yaFSIK1K, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_VpNcoCMf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_VpNcoCMf, m);
  cMsg_wQ1dIloa_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_yuEDTDLg_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_BcPX396X_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_Zrj7fgzb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_blRLEc28_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_WV7xZOVY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_BOcQKpYF_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_q619Tmry, 2, m, &cDelay_q619Tmry_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_nU31Rews_sendMessage);
}

void Heavy_SoundScraper::cMsg_blRLEc28_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_WV7xZOVY, 0, m, &hTable_WV7xZOVY_sendMessage);
}

void Heavy_SoundScraper::cBinop_tbt8hm9U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 75.2546f, 0, m, &cBinop_Zrj7fgzb_sendMessage);
}

void Heavy_SoundScraper::cMsg_wQ1dIloa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_WV7xZOVY, 0, m, &hTable_WV7xZOVY_sendMessage);
}

void Heavy_SoundScraper::cCast_nU31Rews_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_q619Tmry, 0, m, &cDelay_q619Tmry_sendMessage);
}

void Heavy_SoundScraper::cMsg_BOcQKpYF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_VpNcoCMf, 2, m, &cDelay_VpNcoCMf_sendMessage);
}

void Heavy_SoundScraper::cMsg_BcPX396X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_yaFSIK1K, 1, m, NULL);
}

void Heavy_SoundScraper::cVar_lBK10Z6K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_3rhRsBRc, 0, m, &cVar_3rhRsBRc_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_pRFeL14J, 0, m, &cVar_pRFeL14J_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_43VYicc7, 0, m, &cVar_43VYicc7_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_0K40rC9K, 0, m, &cVar_0K40rC9K_sendMessage);
}

void Heavy_SoundScraper::cVar_NzRi3X7d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.01f, 0, m, &cBinop_Sc1uqGxd_sendMessage);
}

void Heavy_SoundScraper::cPack_1ifWPd6t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_Z2qmG9sK, 0, m, NULL);
}

void Heavy_SoundScraper::cVar_pRFeL14J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_O7lvoF2t, HV_BINOP_MULTIPLY, 0, m, &cBinop_O7lvoF2t_sendMessage);
}

void Heavy_SoundScraper::cMsg_a6F96i03_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_V1IcLfhO_sendMessage);
}

void Heavy_SoundScraper::cSystem_V1IcLfhO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_BYTXxG7y_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_O7lvoF2t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_vmly0q8C_sendMessage);
}

void Heavy_SoundScraper::cBinop_hyA4oi6h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_O7lvoF2t, HV_BINOP_MULTIPLY, 1, m, &cBinop_O7lvoF2t_sendMessage);
}

void Heavy_SoundScraper::cMsg_BYTXxG7y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_hyA4oi6h_sendMessage);
}

void Heavy_SoundScraper::cBinop_vmly0q8C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_32w9GsRS_sendMessage);
}

void Heavy_SoundScraper::cBinop_32w9GsRS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_DPRcIZTh_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_ZvWkDnS5, m);
}

void Heavy_SoundScraper::cBinop_DPRcIZTh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_CCMxd4tc, m);
}

void Heavy_SoundScraper::cVar_43VYicc7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_PhDPKXe2, HV_BINOP_MULTIPLY, 0, m, &cBinop_PhDPKXe2_sendMessage);
}

void Heavy_SoundScraper::cMsg_iHrls22T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_J9gQqVGt_sendMessage);
}

void Heavy_SoundScraper::cSystem_J9gQqVGt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_NGXayaBq_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_PhDPKXe2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_1jkNbmg7_sendMessage);
}

void Heavy_SoundScraper::cBinop_2Kx49aYJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_PhDPKXe2, HV_BINOP_MULTIPLY, 1, m, &cBinop_PhDPKXe2_sendMessage);
}

void Heavy_SoundScraper::cMsg_NGXayaBq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_2Kx49aYJ_sendMessage);
}

void Heavy_SoundScraper::cBinop_1jkNbmg7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_FxVFzDkh_sendMessage);
}

void Heavy_SoundScraper::cBinop_FxVFzDkh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_yUeyaVkY_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_q13eUdEG, m);
}

void Heavy_SoundScraper::cBinop_yUeyaVkY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_tPyb9atp, m);
}

void Heavy_SoundScraper::cVar_0K40rC9K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_8BrjMn4k, HV_BINOP_MULTIPLY, 0, m, &cBinop_8BrjMn4k_sendMessage);
}

void Heavy_SoundScraper::cMsg_S44NAtLN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_GgM1EAVv_sendMessage);
}

void Heavy_SoundScraper::cSystem_GgM1EAVv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_iOm8QWka_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_8BrjMn4k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_Uce3oGeW_sendMessage);
}

void Heavy_SoundScraper::cBinop_cMBvv5i7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_8BrjMn4k, HV_BINOP_MULTIPLY, 1, m, &cBinop_8BrjMn4k_sendMessage);
}

void Heavy_SoundScraper::cMsg_iOm8QWka_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_cMBvv5i7_sendMessage);
}

void Heavy_SoundScraper::cBinop_Uce3oGeW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_QZVH839R_sendMessage);
}

void Heavy_SoundScraper::cBinop_QZVH839R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_NcYy5BYd_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_26IUawB8, m);
}

void Heavy_SoundScraper::cBinop_NcYy5BYd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_uTVDKciq, m);
}

void Heavy_SoundScraper::cBinop_hc88Hrpp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_AFdVsdAV, 0, m, &cPack_AFdVsdAV_sendMessage);
}

void Heavy_SoundScraper::cMsg_WMdriDqT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 3000.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_lBK10Z6K, 0, m, &cVar_lBK10Z6K_sendMessage);
}

void Heavy_SoundScraper::cBinop_Sc1uqGxd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_1ifWPd6t, 0, m, &cPack_1ifWPd6t_sendMessage);
}

void Heavy_SoundScraper::cBinop_fyRc4XIe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_yQeXeUk5, 0, m, &cPack_yQeXeUk5_sendMessage);
}

void Heavy_SoundScraper::cMsg_VLsE9RE1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_wKyxS6AB_sendMessage);
}

void Heavy_SoundScraper::cSystem_wKyxS6AB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_M91Ru5T5_sendMessage);
}

void Heavy_SoundScraper::cVar_4qvG46Jq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Ijnihfjw_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSystem_fOleTpOm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_RSUi7tCy_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_mVJTqDkL, m);
}

void Heavy_SoundScraper::cBinop_M91Ru5T5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_Zditxlwn, m);
}

void Heavy_SoundScraper::cMsg_Ijnihfjw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_fOleTpOm_sendMessage);
}

void Heavy_SoundScraper::cBinop_RSUi7tCy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_m66pWKob, m);
}

void Heavy_SoundScraper::cVar_pP01gfXv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_30PHl35y, HV_BINOP_MULTIPLY, 0, m, &cBinop_30PHl35y_sendMessage);
}

void Heavy_SoundScraper::cMsg_M4l0nXiR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Xd2QnVMj_sendMessage);
}

void Heavy_SoundScraper::cSystem_Xd2QnVMj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_d65hsS0W_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_30PHl35y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_ZdfoMVK6_sendMessage);
}

void Heavy_SoundScraper::cBinop_sxqjDfSj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_30PHl35y, HV_BINOP_MULTIPLY, 1, m, &cBinop_30PHl35y_sendMessage);
}

void Heavy_SoundScraper::cMsg_d65hsS0W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_sxqjDfSj_sendMessage);
}

void Heavy_SoundScraper::cBinop_ZdfoMVK6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_nuhhPwSc_sendMessage);
}

void Heavy_SoundScraper::cBinop_nuhhPwSc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_296sJdwZ_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_WPWtNQuY, m);
}

void Heavy_SoundScraper::cBinop_296sJdwZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_ZhS7koEk, m);
}

void Heavy_SoundScraper::cBinop_v32fQBEd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, -1.0f, 0, m, &cBinop_75oAlgPH_sendMessage);
}

void Heavy_SoundScraper::cBinop_75oAlgPH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_y1NMUgFi, m);
}

void Heavy_SoundScraper::cBinop_7LCXD2uF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_lwgyyqYN_sendMessage);
}

void Heavy_SoundScraper::cBinop_lwgyyqYN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_Sa29ZPQZ_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_uHmWXg8e_sendMessage);
}

void Heavy_SoundScraper::cVar_Qw8ow7Vi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_vVq5YRGr_sendMessage);
}

void Heavy_SoundScraper::cMsg_SXZ3cbFr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_sBIA3qgt_sendMessage);
}

void Heavy_SoundScraper::cSystem_sBIA3qgt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_nyaiJEop, HV_BINOP_DIVIDE, 1, m, &cBinop_nyaiJEop_sendMessage);
}

void Heavy_SoundScraper::cBinop_Sa29ZPQZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_7N4d60eb_sendMessage);
}

void Heavy_SoundScraper::cBinop_7N4d60eb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_9y8LJ3DQ, m);
}

void Heavy_SoundScraper::cMsg_Z3tLr46i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_6Rn9lkLk_sendMessage);
}

void Heavy_SoundScraper::cBinop_6Rn9lkLk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_7LCXD2uF_sendMessage);
}

void Heavy_SoundScraper::cBinop_uHmWXg8e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_miixX56K, m);
}

void Heavy_SoundScraper::cBinop_vVq5YRGr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_IFMHYKSB_sendMessage);
}

void Heavy_SoundScraper::cBinop_IFMHYKSB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_nyaiJEop, HV_BINOP_DIVIDE, 0, m, &cBinop_nyaiJEop_sendMessage);
}

void Heavy_SoundScraper::cBinop_nyaiJEop_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Z3tLr46i_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_5VThGmkt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_HUYKbmbR_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_U5dclz2M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_6p9iXM8R_sendMessage);
}

void Heavy_SoundScraper::cSystem_6p9iXM8R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_JgeGUPBp_sendMessage);
}

void Heavy_SoundScraper::cDelay_RO0HAD1w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_RO0HAD1w, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_CZFi29WS, 0, m, &cDelay_CZFi29WS_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_RO0HAD1w, 0, m, &cDelay_RO0HAD1w_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_fhhUv73T, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_CZFi29WS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_CZFi29WS, m);
  cMsg_2VnAnevd_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_PMdGwCK1_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_4QhzQB3l_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_70kxUhN7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_yCORlyOd_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_6lkVgUXs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_iChqKkXI_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_RO0HAD1w, 2, m, &cDelay_RO0HAD1w_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_TQ2hwERa_sendMessage);
}

void Heavy_SoundScraper::cMsg_yCORlyOd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_6lkVgUXs, 0, m, &hTable_6lkVgUXs_sendMessage);
}

void Heavy_SoundScraper::cBinop_JgeGUPBp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 500.0f, 0, m, &cBinop_70kxUhN7_sendMessage);
}

void Heavy_SoundScraper::cMsg_2VnAnevd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_6lkVgUXs, 0, m, &hTable_6lkVgUXs_sendMessage);
}

void Heavy_SoundScraper::cCast_TQ2hwERa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_RO0HAD1w, 0, m, &cDelay_RO0HAD1w_sendMessage);
}

void Heavy_SoundScraper::cMsg_iChqKkXI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_CZFi29WS, 2, m, &cDelay_CZFi29WS_sendMessage);
}

void Heavy_SoundScraper::cMsg_4QhzQB3l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_fhhUv73T, 1, m, NULL);
}

void Heavy_SoundScraper::cMsg_6ycg5u2u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cMsg_HUYKbmbR_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_HUYKbmbR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 20.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_4CNE9bol, 0, m, NULL);
}

void Heavy_SoundScraper::cPack_pwHA4CK0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_R9hVG6i4, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_mxfAxcPu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_pwHA4CK0, 0, m, &cPack_pwHA4CK0_sendMessage);
}

void Heavy_SoundScraper::cCast_o4eovfYb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_5hDepWSM_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cMsg_hmDGC6vU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 500.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_R9hVG6i4, 0, m, NULL);
}

void Heavy_SoundScraper::cMsg_OIxZvEFo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 500.0f);
  sVarf_onMessage(_c, &Context(_c)->sVarf_BC4uhilG, m);
}

void Heavy_SoundScraper::cMsg_VK50rZCy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.3f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_v32fQBEd_sendMessage);
}

void Heavy_SoundScraper::cReceive_raXZ1cVU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_cNc5mneP, 0, m, &cPack_cNc5mneP_sendMessage);
}

void Heavy_SoundScraper::cReceive_xr3hShfa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_cNc5mneP, 1, m, &cPack_cNc5mneP_sendMessage);
}

void Heavy_SoundScraper::cReceive_3hh6qDY3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPrint_onMessage(_c, m, "SET_TABLE");
  cSlice_onMessage(_c, &Context(_c)->cSlice_wNWlnUt6, 0, m, &cSlice_wNWlnUt6_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_vbIVip9l, 0, m, &cSlice_vbIVip9l_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_lMwK2PDu, 0, m, &cSlice_lMwK2PDu_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_qFnkX7kz, 0, m, &cSlice_qFnkX7kz_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_PNo0Dq9R, 0, m, &cSlice_PNo0Dq9R_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_jKNtMYot, 0, m, &cSlice_jKNtMYot_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_PGQ4Pvv1, 0, m, &cSlice_PGQ4Pvv1_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_AcxWZBRR, 0, m, &cSlice_AcxWZBRR_sendMessage);
  cSend_YaoUxTYb_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cReceive_ZOVkv1UA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_g5uFS5np_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cReceive_IO7AyTIn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_XrcelLBY_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cReceive_X5Rl7do8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_avJg9MHw, 0, m, &cVar_avJg9MHw_sendMessage);
  cSwitchcase_QnIBKCPb_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cReceive_VDv4sxci_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_7M60O1jp_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cReceive_NBOMRz6a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_zDv510z4_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cReceive_gCsEyfTf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_T5MSRbEg_sendMessage(_c, 0, m);
  cMsg_zt4otUNN_sendMessage(_c, 0, m);
  cMsg_Vr47FdT3_sendMessage(_c, 0, m);
  cMsg_cUBePfno_sendMessage(_c, 0, m);
  cMsg_lNAVCesf_sendMessage(_c, 0, m);
  cMsg_gbuNbLNn_sendMessage(_c, 0, m);
  cMsg_vd6gdUrW_sendMessage(_c, 0, m);
  cMsg_hTVwU2Ty_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_xCLrqwCD, 0, m, &cVar_xCLrqwCD_sendMessage);
  cMsg_aFTIQgSI_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_1xnHjaAd, 0, m, &cVar_1xnHjaAd_sendMessage);
  cMsg_6xlsfE82_sendMessage(_c, 0, m);
  cMsg_REGrMhE1_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_aXruJVKo, 0, m, &cVar_aXruJVKo_sendMessage);
  cMsg_9zV9bvOy_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_Z7aFCRjz, 0, m, &cVar_Z7aFCRjz_sendMessage);
  cMsg_uWgXaFFN_sendMessage(_c, 0, m);
  cMsg_TjGSaK6m_sendMessage(_c, 0, m);
  cMsg_LzwTP0qu_sendMessage(_c, 0, m);
  cMsg_LEAKKrwD_sendMessage(_c, 0, m);
  cMsg_nzq7ZikR_sendMessage(_c, 0, m);
  cMsg_0AbQ659J_sendMessage(_c, 0, m);
  cMsg_nFK5nf2q_sendMessage(_c, 0, m);
  cMsg_62ZaNWc2_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_W4WQPcAH, 0, m, &cVar_W4WQPcAH_sendMessage);
  cMsg_kVJbSJ6F_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_48NckNlx, 0, m, &cVar_48NckNlx_sendMessage);
  cMsg_Mm7nQiYX_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_3O9x0mjC, 0, m, &cVar_3O9x0mjC_sendMessage);
  cMsg_uUH1BRVt_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_mWe7l3bg, 0, m, &cVar_mWe7l3bg_sendMessage);
  cMsg_5NNAKo1n_sendMessage(_c, 0, m);
  cMsg_7PaqMqCC_sendMessage(_c, 0, m);
  cMsg_YKlbKeM4_sendMessage(_c, 0, m);
  cMsg_hccYgUTk_sendMessage(_c, 0, m);
  cMsg_Zew8JQyO_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_3rhRsBRc, 0, m, &cVar_3rhRsBRc_sendMessage);
  cMsg_a6F96i03_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_pRFeL14J, 0, m, &cVar_pRFeL14J_sendMessage);
  cMsg_iHrls22T_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_43VYicc7, 0, m, &cVar_43VYicc7_sendMessage);
  cMsg_S44NAtLN_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_0K40rC9K, 0, m, &cVar_0K40rC9K_sendMessage);
  cMsg_M4l0nXiR_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_pP01gfXv, 0, m, &cVar_pP01gfXv_sendMessage);
  cMsg_SXZ3cbFr_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_Qw8ow7Vi, 0, m, &cVar_Qw8ow7Vi_sendMessage);
  cMsg_U5dclz2M_sendMessage(_c, 0, m);
  cMsg_gouEbF8e_sendMessage(_c, 0, m);
  cMsg_XBLmNFPB_sendMessage(_c, 0, m);
  cMsg_mJwgkCVT_sendMessage(_c, 0, m);
  cMsg_oYjTKZuf_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_aCHYjPwB, 0, m, &cVar_aCHYjPwB_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_5J9dVY4X, 0, m, &cVar_5J9dVY4X_sendMessage);
  cMsg_RJjx0qOy_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_T4OFEPGA, 0, m, &cVar_T4OFEPGA_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_9tg7n64e, 0, m, &cVar_9tg7n64e_sendMessage);
  cMsg_wl4V3pBM_sendMessage(_c, 0, m);
  cMsg_isVZbgCQ_sendMessage(_c, 0, m);
  cMsg_AZRcK4Kd_sendMessage(_c, 0, m);
  cMsg_EmlSyUeV_sendMessage(_c, 0, m);
  cMsg_6ZLnzzKE_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_OquQCk2n, 0, m, &cVar_OquQCk2n_sendMessage);
  cMsg_WsQaR7BM_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_XWPguoBd, 0, m, &cVar_XWPguoBd_sendMessage);
  cMsg_is65mE4M_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_9xpBajhW, 0, m, &cVar_9xpBajhW_sendMessage);
  cMsg_1HOMcLlv_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_jUxYxiCk, 0, m, &cVar_jUxYxiCk_sendMessage);
  cMsg_UfHtdik3_sendMessage(_c, 0, m);
  cMsg_YpBxHFwr_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_9iNKqoVA, 0, m, &cVar_9iNKqoVA_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_cyxqyKDW, 0, m, &cVar_cyxqyKDW_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_lbm63Qtq, 0, m, &cVar_lbm63Qtq_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_pVcev6ol, 0, m, &cVar_pVcev6ol_sendMessage);
  cMsg_6ycg5u2u_sendMessage(_c, 0, m);
  cMsg_jOiggj2V_sendMessage(_c, 0, m);
  cMsg_E0iG91dj_sendMessage(_c, 0, m);
  cMsg_t6TeTkd9_sendMessage(_c, 0, m);
  cMsg_6gIik2nV_sendMessage(_c, 0, m);
  cMsg_xSgukN5j_sendMessage(_c, 0, m);
  cMsg_eaLezNaR_sendMessage(_c, 0, m);
  cMsg_IPCexPic_sendMessage(_c, 0, m);
  cMsg_9A2mmMok_sendMessage(_c, 0, m);
  cMsg_R9pXDnMm_sendMessage(_c, 0, m);
  cMsg_ljBcdP4e_sendMessage(_c, 0, m);
  cMsg_rysE6euh_sendMessage(_c, 0, m);
  cMsg_I2VFb2kW_sendMessage(_c, 0, m);
  cMsg_XMvlwh2w_sendMessage(_c, 0, m);
  cMsg_uGHMY7qM_sendMessage(_c, 0, m);
  cMsg_B0C1W80G_sendMessage(_c, 0, m);
  cMsg_UivV2UUt_sendMessage(_c, 0, m);
  cMsg_a0DRoa8N_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_cFrIq1vt, 0, m, &cVar_cFrIq1vt_sendMessage);
  cMsg_IHFzBC3Q_sendMessage(_c, 0, m);
  cMsg_0tEByGfQ_sendMessage(_c, 0, m);
  cMsg_8B5zZ27w_sendMessage(_c, 0, m);
  cMsg_2FnJW1tQ_sendMessage(_c, 0, m);
  cMsg_wtwXK4JU_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_4IlEGoBW, 0, m, &cVar_4IlEGoBW_sendMessage);
  cMsg_lnRvebjY_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_BiBKnVql, 0, m, &cVar_BiBKnVql_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_5mzvLwtF, 0, m, &cVar_5mzvLwtF_sendMessage);
  cMsg_SRJyRjsZ_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_NXkYuOEu, 0, m, &cVar_NXkYuOEu_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_1wl9HEjT, 0, m, &cVar_1wl9HEjT_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_hCfWcIUY, 0, m, &cVar_hCfWcIUY_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_4MuHOyD3, 0, m, &cVar_4MuHOyD3_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_qEtJMY78, 0, m, &cVar_qEtJMY78_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_OyMLgXc9, 0, m, &cVar_OyMLgXc9_sendMessage);
  cMsg_OIxZvEFo_sendMessage(_c, 0, m);
  cMsg_VK50rZCy_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_vrfKeGqf, 0, m, &cVar_vrfKeGqf_sendMessage);
  cMsg_qWZTx8PI_sendMessage(_c, 0, m);
  cMsg_GuO8q63e_sendMessage(_c, 0, m);
  cMsg_DPxKgyTY_sendMessage(_c, 0, m);
  cMsg_8uR7XCHC_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_WJ02Lnq9, 0, m, &cVar_WJ02Lnq9_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_QfuerMvY, 0, m, &cVar_QfuerMvY_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_N3aCVSCL, 0, m, &cVar_N3aCVSCL_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_BS8eTW7l, 0, m, &cVar_BS8eTW7l_sendMessage);
  cMsg_25uqYvvn_sendMessage(_c, 0, m);
  cSend_zDv510z4_sendMessage(_c, 0, m);
  cMsg_SdF0aTrK_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_ElZ8w9SJ, 0, m, &cVar_ElZ8w9SJ_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_6CDrXQCO, 0, m, &cVar_6CDrXQCO_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_bBqSfWKO, 0, m, &cVar_bBqSfWKO_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_nef6V9QF, 0, m, &cVar_nef6V9QF_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_7o7TgulL, 0, m, &cVar_7o7TgulL_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_uBppO2Vj, 0, m, &cVar_uBppO2Vj_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_SzbcFAbH, 0, m, &cVar_SzbcFAbH_sendMessage);
  cMsg_KITo6ATS_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_hpvHlXoL, 0, m, &cVar_hpvHlXoL_sendMessage);
  cMsg_NFSFjRJl_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_oBhsRn85, 0, m, &cVar_oBhsRn85_sendMessage);
  cMsg_rpmxuMpZ_sendMessage(_c, 0, m);
  cMsg_IgF8c0jX_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_tC4XMKnA, 0, m, &cVar_tC4XMKnA_sendMessage);
  cMsg_hfXqsQkG_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_QvY2LiNE, 0, m, &cTabhead_QvY2LiNE_sendMessage);
  cMsg_XQxSTKdb_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_C2sSl45I, 0, m, &cVar_C2sSl45I_sendMessage);
  cMsg_gVfgEHLC_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_bhvaQbli, 0, m, &cTabhead_bhvaQbli_sendMessage);
  cMsg_iwumyRPN_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_WsqgjK17, 0, m, &cVar_WsqgjK17_sendMessage);
  cMsg_dOZ7u3v4_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_RUe0Gccm, 0, m, &cTabhead_RUe0Gccm_sendMessage);
  cMsg_afyZn4jf_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_rMzr815S, 0, m, &cVar_rMzr815S_sendMessage);
  cMsg_Nug95GVn_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_5fdu0lwC, 0, m, &cTabhead_5fdu0lwC_sendMessage);
  cMsg_yirqP5WT_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_jZ8jzNSN, 0, m, &cVar_jZ8jzNSN_sendMessage);
  cMsg_rfdNynv4_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_Po3NiZVj, 0, m, &cTabhead_Po3NiZVj_sendMessage);
  cMsg_BP6pkyFY_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_kRzJ71eU, 0, m, &cVar_kRzJ71eU_sendMessage);
  cMsg_akwVB60m_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_Ouu7jbUj, 0, m, &cTabhead_Ouu7jbUj_sendMessage);
  cMsg_lEE5P46e_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_ZegJPXJC, 0, m, &cVar_ZegJPXJC_sendMessage);
  cMsg_cqGLgsZp_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_SHUICP2Q, 0, m, &cTabhead_SHUICP2Q_sendMessage);
  cMsg_ZFGs9FOA_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_mE8kTSAF, 0, m, &cVar_mE8kTSAF_sendMessage);
  cMsg_Wn9g9Cv7_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_9PnigjGs, 0, m, &cTabhead_9PnigjGs_sendMessage);
  cMsg_nRoRXsgS_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_nJ4e88Oq, 0, m, &cVar_nJ4e88Oq_sendMessage);
  cMsg_ZFvHevtn_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_x8bN9o2l, 0, m, &cTabhead_x8bN9o2l_sendMessage);
  cMsg_9VrOyBl8_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_RzLuAeYa, 0, m, &cVar_RzLuAeYa_sendMessage);
  cMsg_89GjDZOc_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_Od3PmTyw, 0, m, &cTabhead_Od3PmTyw_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_CNNYNcNM, 0, m, &cVar_CNNYNcNM_sendMessage);
  cMsg_Igx93Vbq_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_q68DMaA0, 0, m, &cVar_q68DMaA0_sendMessage);
  cMsg_ic7iKpNx_sendMessage(_c, 0, m);
  cMsg_goSScwcV_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_3ZHo8Mi0, 0, m, &cVar_3ZHo8Mi0_sendMessage);
  cMsg_TtNy7ACk_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_0NeWkSQb, 0, m, &cTabhead_0NeWkSQb_sendMessage);
  cMsg_GjAAtAaZ_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_bCo5eEl9, 0, m, &cVar_bCo5eEl9_sendMessage);
  cMsg_GApETzrb_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_droFzCYz, 0, m, &cTabhead_droFzCYz_sendMessage);
  cMsg_CO8VUzoO_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_Zv79gRqB, 0, m, &cVar_Zv79gRqB_sendMessage);
  cMsg_rjzKMgGX_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_ezQPKc4W, 0, m, &cTabhead_ezQPKc4W_sendMessage);
  cMsg_633w4RSM_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_xzjh7ySP, 0, m, &cVar_xzjh7ySP_sendMessage);
  cMsg_oRvcvLTn_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_3s44gkgu, 0, m, &cTabhead_3s44gkgu_sendMessage);
  cMsg_qlvLB5gH_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_pKPtBNOl, 0, m, &cVar_pKPtBNOl_sendMessage);
  cMsg_PQ7T3nCM_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_QiOOFcml, 0, m, &cTabhead_QiOOFcml_sendMessage);
  cMsg_Ygg71HIO_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_S4EuVlB0, 0, m, &cVar_S4EuVlB0_sendMessage);
  cMsg_ALmWWi38_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_kDXQ7QLM, 0, m, &cTabhead_kDXQ7QLM_sendMessage);
  cMsg_0YU4gTy0_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_tMXvxuga, 0, m, &cVar_tMXvxuga_sendMessage);
  cMsg_97bramSA_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_ahsqQdLQ, 0, m, &cTabhead_ahsqQdLQ_sendMessage);
  cMsg_yJQqhPRb_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_WaX5KXjt, 0, m, &cVar_WaX5KXjt_sendMessage);
  cMsg_v5BbUSHf_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_pFISdq5z, 0, m, &cTabhead_pFISdq5z_sendMessage);
  cMsg_AIhUKNtz_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_cNWyJC44, 0, m, &cVar_cNWyJC44_sendMessage);
  cMsg_BT2zkuNp_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_WywdLMgD, 0, m, &cTabhead_WywdLMgD_sendMessage);
  cMsg_Mvw8dp0w_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_esOvarCE, 0, m, &cVar_esOvarCE_sendMessage);
  cMsg_xulu5X8H_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_6N6O1MMN, 0, m, &cTabhead_6N6O1MMN_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_4qvG46Jq, 0, m, &cVar_4qvG46Jq_sendMessage);
  cMsg_VLsE9RE1_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cReceive_8DrY27zU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_OxJlfBEp, 0, m, &cVar_OxJlfBEp_sendMessage);
}

void Heavy_SoundScraper::cReceive_etBTPXps_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_maWUakGy_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_eCksQGuZ_sendMessage);
}

void Heavy_SoundScraper::cReceive_VwClcVqs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_uAmKGXU3, 1, m, &cVar_uAmKGXU3_sendMessage);
}

void Heavy_SoundScraper::cReceive_DzVcW1fk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_AHEJrPNI, HV_BINOP_DIVIDE, 1, m, &cBinop_AHEJrPNI_sendMessage);
}

void Heavy_SoundScraper::cReceive_cKALy0NQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_1S06fTvj_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cReceive_THR8gmeI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_AVd1ivxo_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cReceive_qx8avAm4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_oJgrTUvf_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cReceive_2e6PYhdn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_WGv05G1Y, 1, m, &cVar_WGv05G1Y_sendMessage);
}

void Heavy_SoundScraper::cReceive_IFUpBw1c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_PD4Yfl3A, m);
}

void Heavy_SoundScraper::cReceive_L6M6ma00_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_Sn9TVkmF, 0, m, NULL);
}

void Heavy_SoundScraper::cReceive_0OX4nuXD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_6mNXXCJ7, 0, m, NULL);
}

void Heavy_SoundScraper::cReceive_g1ubUxkO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_7ub5aOJD_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -10000.0f, 0, m, &cBinop_vg4Yb766_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 10000.0f, 0, m, &cBinop_hLv19Ayl_sendMessage);
}

void Heavy_SoundScraper::cReceive_VZTDMNsR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_A24UBkmi_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_UlhEjkPA_sendMessage);
  sLine_onMessage(_c, &Context(_c)->sLine_Sn9TVkmF, 0, m, NULL);
}

void Heavy_SoundScraper::cReceive_DyIEfgWu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_OuLgaUhq_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_oRmJ2g6h_sendMessage);
  cPack_onMessage(_c, &Context(_c)->cPack_nPHqOih6, 1, m, &cPack_nPHqOih6_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_5KVuXS7o_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_dtptFiL9_sendMessage);
}

void Heavy_SoundScraper::cReceive_YcEnJgFp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_R4WVTS4e, 1, m, &cPack_R4WVTS4e_sendMessage);
}

void Heavy_SoundScraper::cReceive_sy7lEKy8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_EOi2HGD9, 1, m, &cVar_EOi2HGD9_sendMessage);
}

void Heavy_SoundScraper::cReceive_bQmnjCmK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_hatdRi6q, HV_BINOP_DIVIDE, 1, m, &cBinop_hatdRi6q_sendMessage);
}

void Heavy_SoundScraper::cReceive_e7iVXB92_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_NdS3fQsC_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cReceive_4xL6NZkO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_nUQIH1rt_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cReceive_clBs53qK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_9IsRQ8TE_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cReceive_Ny20W2gi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Y1Jf5hjX, 1, m, &cVar_Y1Jf5hjX_sendMessage);
}

void Heavy_SoundScraper::cReceive_t6QY9Ufm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_z0ORyX7o, m);
}

void Heavy_SoundScraper::cReceive_DkrCXPjl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_NcgVXeVL, 0, m, NULL);
}

void Heavy_SoundScraper::cReceive_WSXk0mmC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_MFD5QceL, 0, m, NULL);
}

void Heavy_SoundScraper::cReceive_o0z1zy04_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_749hPpiX_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -10000.0f, 0, m, &cBinop_CPNK3XrI_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 10000.0f, 0, m, &cBinop_wtxz4mNH_sendMessage);
}

void Heavy_SoundScraper::cReceive_w13qlHox_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_T9MpY4lq_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_vKS7Qtz2_sendMessage);
  sLine_onMessage(_c, &Context(_c)->sLine_NcgVXeVL, 0, m, NULL);
}

void Heavy_SoundScraper::cReceive_cJVsE5lQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_8aECMBjy_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_yAt4kJ9U_sendMessage);
  cPack_onMessage(_c, &Context(_c)->cPack_h3QM94QA, 1, m, &cPack_h3QM94QA_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_6C4xKD9C_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_YCspmILG_sendMessage);
}

void Heavy_SoundScraper::cReceive_iTu3jDc3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_9Oxen0Bc, 1, m, &cPack_9Oxen0Bc_sendMessage);
}

void Heavy_SoundScraper::cReceive_riILnXBB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_lUbzbGRo, 1, m, &cVar_lUbzbGRo_sendMessage);
}

void Heavy_SoundScraper::cReceive_BGcziFMq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_rTqbfmim, HV_BINOP_DIVIDE, 1, m, &cBinop_rTqbfmim_sendMessage);
}

void Heavy_SoundScraper::cReceive_WFssAnEw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_BW4UYQ0I_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cReceive_ZxjvOMhA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_ya8nYagu_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cReceive_oeSsjeA8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_d0pQpExF_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cReceive_lxIjFjfC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ri8Mlkro, 1, m, &cVar_ri8Mlkro_sendMessage);
}

void Heavy_SoundScraper::cReceive_cONpp1hQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_zVNmO2Vt, m);
}

void Heavy_SoundScraper::cReceive_mc6V2H4k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_msp1Ye3X, 0, m, NULL);
}

void Heavy_SoundScraper::cReceive_1QZjeYxp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_PgJfdgEk, 0, m, NULL);
}

void Heavy_SoundScraper::cReceive_5G6xqCtZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_MAzjvveK_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -10000.0f, 0, m, &cBinop_KcwP8wyh_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 10000.0f, 0, m, &cBinop_090Av5Xi_sendMessage);
}

void Heavy_SoundScraper::cReceive_0ScNl2kt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_R45vGCiq_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_di7FJ4kt_sendMessage);
  sLine_onMessage(_c, &Context(_c)->sLine_msp1Ye3X, 0, m, NULL);
}

void Heavy_SoundScraper::cReceive_1B2ZmZT2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_uYEucu0t_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_iBOwR4tj_sendMessage);
  cPack_onMessage(_c, &Context(_c)->cPack_Xc7ntLVj, 1, m, &cPack_Xc7ntLVj_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_8Yqv9hjG_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_EfcpNhue_sendMessage);
}

void Heavy_SoundScraper::cReceive_E5r1whBf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_e71LtL8n, 1, m, &cPack_e71LtL8n_sendMessage);
}

void Heavy_SoundScraper::cReceive_WlnyW5Fy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_xqkVCOjX, 1, m, &cVar_xqkVCOjX_sendMessage);
}

void Heavy_SoundScraper::cReceive_TdP6j73A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_HyY3IW42, HV_BINOP_DIVIDE, 1, m, &cBinop_HyY3IW42_sendMessage);
}

void Heavy_SoundScraper::cReceive_3GKJBOeE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_MluF9AF8_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cReceive_FOz3tbya_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_mVbHJTA6_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cReceive_e35GHAhy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_yQOMVb3z_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cReceive_kI7qPxx1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_WufKUwGz, 1, m, &cVar_WufKUwGz_sendMessage);
}

void Heavy_SoundScraper::cReceive_8q0BecEz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_IFUHA6vp, m);
}

void Heavy_SoundScraper::cReceive_N2sXvvqu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_F9IeWvwf, 0, m, NULL);
}

void Heavy_SoundScraper::cReceive_awHHteN2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_uFCAYdsC, 0, m, NULL);
}

void Heavy_SoundScraper::cReceive_lhW2cGxb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_U6QqNqIa_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -10000.0f, 0, m, &cBinop_r6EjDZGZ_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 10000.0f, 0, m, &cBinop_gsggKc9F_sendMessage);
}

void Heavy_SoundScraper::cReceive_Gq0yrwEQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_xnP9nnTQ_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_dkrY6O6K_sendMessage);
  sLine_onMessage(_c, &Context(_c)->sLine_F9IeWvwf, 0, m, NULL);
}

void Heavy_SoundScraper::cReceive_X1vh0qHw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_dvnwC4q3_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_SDp37AW3_sendMessage);
  cPack_onMessage(_c, &Context(_c)->cPack_Bdzaz865, 1, m, &cPack_Bdzaz865_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_fvo4NoPN_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_wBN9k0lw_sendMessage);
}

void Heavy_SoundScraper::cReceive_E1SWCp1C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_ylsFMtrD, 1, m, &cPack_ylsFMtrD_sendMessage);
}

void Heavy_SoundScraper::cReceive_qpf2y1H8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_JiB1FTll, 0, m, &cVar_JiB1FTll_sendMessage);
}

void Heavy_SoundScraper::cReceive_mxugVG4b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_u0LfjI2o_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_WSY0zyXv_sendMessage);
}

void Heavy_SoundScraper::cReceive_Tua8aZM9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_o0jNTS0T, 0, m, &cVar_o0jNTS0T_sendMessage);
}

void Heavy_SoundScraper::cReceive_cZvy4ruV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_BbWPYIbB_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_j3cH3bzV_sendMessage);
}

void Heavy_SoundScraper::cReceive_7wiZ7dLr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 2.0f, 0, m, &cBinop_MO9zL718_sendMessage);
}

void Heavy_SoundScraper::cReceive_eoZuUIQ9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_OuWINYw5, 0, m, &cVar_OuWINYw5_sendMessage);
}

void Heavy_SoundScraper::cReceive_WSwPhInE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_H8O9dQQD_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_C3iYtObj_sendMessage);
}

void Heavy_SoundScraper::cReceive_ddqkBFuQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_U3nzcL9h, 0, m, &cVar_U3nzcL9h_sendMessage);
}

void Heavy_SoundScraper::cReceive_JqOZht76_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_mOKnbsiL_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_botQG8St_sendMessage);
}

void Heavy_SoundScraper::cReceive_FWuAtFNd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_dmS6zry0, HV_BINOP_SUBTRACT, 0, m, &cBinop_dmS6zry0_sendMessage);
}

void Heavy_SoundScraper::cReceive_bt4qx8Gw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_EWr5RlBF_sendMessage);
  cPrint_onMessage(_c, m, "SCRAPER_LEVEL");
  cVar_onMessage(_c, &Context(_c)->cVar_16IO5Mhm, 0, m, &cVar_16IO5Mhm_sendMessage);
}

void Heavy_SoundScraper::cReceive_B8BtruqY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSlice_onMessage(_c, &Context(_c)->cSlice_g6xTrs7y, 0, m, &cSlice_g6xTrs7y_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_6ZmhuSSs, 0, m, &cSlice_6ZmhuSSs_sendMessage);
}

void Heavy_SoundScraper::cReceive_0L6LdJYF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_92Nmr0On_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_dDRWvyXu_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_nWVjSeFU_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ivJK7gl9_sendMessage);
}

void Heavy_SoundScraper::cReceive_NwIyOnyO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.25f, 0, m, &cBinop_B5x4hefd_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_4xxEHpfz_sendMessage);
}

void Heavy_SoundScraper::cReceive_9STUb7Kr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.01f, 0, m, &cBinop_zeeuRA8y_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_mRM51ZAW, HV_BINOP_MULTIPLY, 0, m, &cBinop_mRM51ZAW_sendMessage);
}

void Heavy_SoundScraper::cReceive_EjgEjYvl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 10.0f, 0, m, &cBinop_sD8kQdO9_sendMessage);
}

void Heavy_SoundScraper::cReceive_lT5oD7Bt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_rW0hnDQk, HV_BINOP_MULTIPLY, 0, m, &cBinop_rW0hnDQk_sendMessage);
}

void Heavy_SoundScraper::cReceive_d50G3Uhc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_ufWwa0XK_sendMessage);
  cPrint_onMessage(_c, m, "SCRAPER_RESET");
}

void Heavy_SoundScraper::cReceive_lUjd3Nar_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_EZ8VdiIH, 0, m, &cVar_EZ8VdiIH_sendMessage);
}

void Heavy_SoundScraper::cReceive_ncNJGndH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_IMTZYsmJ_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_wIa2gpxM_sendMessage);
  cMsg_3Yj4iRHV_sendMessage(_c, 0, m);
  cSwitchcase_YrKT5qDS_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cReceive_9VX7qlqA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_3IWl68TZ_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_F478LNRE_sendMessage);
  cMsg_2m7uDB8f_sendMessage(_c, 0, m);
  cMsg_ew9zOFyz_sendMessage(_c, 0, m);
  cSwitchcase_UDqoeNTR_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cReceive_7RUsYlr2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_2r1tmWiL, 1, m, &cVar_2r1tmWiL_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.001f, 0, m, &cBinop_b7emUf7t_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.01f, 0, m, &cBinop_v50csgzS_sendMessage);
}

void Heavy_SoundScraper::cReceive_6bxAHBNN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_wDgMEk6l, 0, m, NULL);
  cPrint_onMessage(_c, m, "SCRAPER_VLINE");
}

void Heavy_SoundScraper::cReceive_8kzssOge_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_g14fvhST_sendMessage(_c, 0, m);
  cMsg_VSxgw51w_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cReceive_LC0dknMg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cReceive_nUWs5YwR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_WhEeEGUt_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_64g2pYpE_sendMessage);
}

void Heavy_SoundScraper::cReceive_vZqDTXhI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSlice_onMessage(_c, &Context(_c)->cSlice_PqnASR9N, 0, m, &cSlice_PqnASR9N_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_SpCzCgYF, 0, m, &cSlice_SpCzCgYF_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_opGBFbz3, 0, m, &cSlice_opGBFbz3_sendMessage);
}

void Heavy_SoundScraper::cReceive_Y9s9lBtb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPrint_onMessage(_c, m, "SOUND_CHOICE");
  cSwitchcase_wkYiQ8ft_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cReceive_bZk1Nd4p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_ZqXmJ0fy_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cReceive_wJPVNgp2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_TK7779oI_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_mM3Pp2AW_sendMessage);
  cPack_onMessage(_c, &Context(_c)->cPack_RTeLKE1d, 0, m, &cPack_RTeLKE1d_sendMessage);
}

void Heavy_SoundScraper::cReceive_yYG5GQKK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_mxfAxcPu_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_o4eovfYb_sendMessage);
}

void Heavy_SoundScraper::cReceive_djqFP2O8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 2.0f, 0, m, &cBinop_gyw3oFYW_sendMessage);
}

void Heavy_SoundScraper::cReceive_8vApesEO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_68NPTu4r, 0, m, &cVar_68NPTu4r_sendMessage);
}

void Heavy_SoundScraper::cReceive_OiRrXBoZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_qk6kdWr5_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_IoGTVvIL_sendMessage);
}

void Heavy_SoundScraper::cReceive_jrw4fox1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 2.0f, 0, m, &cBinop_il5g3S6p_sendMessage);
}



/*
 * Code for expr~ implementation
 * Write out the generic implementation code
 */

 // per class code

 // per object code


/*
 * Context Process Implementation
 */

int Heavy_SoundScraper::process(float **inputBuffers, float **outputBuffers, int n) {
  while (hLp_hasData(&inQueue)) {
    hv_uint32_t numBytes = 0;
    ReceiverMessagePair *p = reinterpret_cast<ReceiverMessagePair *>(hLp_getReadBuffer(&inQueue, &numBytes));
    hv_assert(numBytes >= sizeof(ReceiverMessagePair));
    scheduleMessageForReceiver(p->receiverHash, &p->msg);
    hLp_consume(&inQueue);
  }

  sendBangToReceiver(0xDD21C0EB); // send to __hv_bang~ on next cycle
  const int n4 = n & ~HV_N_SIMD_MASK; // ensure that the block size is a multiple of HV_N_SIMD

  // temporary signal vars
  hv_bufferf_t Bf0, Bf1, Bf2, Bf3, Bf4, Bf5, Bf6, Bf7, Bf8, Bf9, Bf10, Bf11, Bf12, Bf13, Bf14, Bf15, Bf16, Bf17, Bf18;
  hv_bufferi_t Bi0, Bi1;

  // input and output vars
  hv_bufferf_t O0, O1;

  // declare and init the zero buffer
  hv_bufferf_t ZERO; __hv_zero_f(VOf(ZERO));

  hv_uint32_t nextBlock = blockStartTimestamp;
  for (int n = 0; n < n4; n += HV_N_SIMD) {

    // process all of the messages for this block
    nextBlock += HV_N_SIMD;
    while (mq_hasMessageBefore(&mq, nextBlock)) {
      MessageNode *const node = mq_peek(&mq);
      node->sendMessage(this, node->let, node->m);
      mq_pop(&mq);
    }

    

    // zero output buffers
    __hv_zero_f(VOf(O0));
    __hv_zero_f(VOf(O1));

    // process all signal functions
    __hv_varread_f(&sVarf_OVlYzOUE, VOf(Bf0));
    __hv_varread_f(&sVarf_FA2TIi6z, VOf(Bf1));
    __hv_mul_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_K3dgw4Sa, VOf(Bf0));
    __hv_rpole_f(&sRPole_dBnyUxXY, VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_line_f(&sLine_wDgMEk6l, VOf(Bf1));
    __hv_phasor_k_f(&sPhasor_8xOJbste, VOf(Bf2));
    __hv_var_k_f(VOf(Bf3), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_add_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_floor_f(VIf(Bf3), VOf(Bf4));
    __hv_sub_f(VIf(Bf3), VIf(Bf4), VOf(Bf4));
    __hv_del1_f(&sDel1_afJDwwW5, VIf(Bf2), VOf(Bf3));
    __hv_lt_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_samphold_f(&sSamphold_9D9qkxX9, VIf(ZERO), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf5), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_fma_f(VIf(Bf3), VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_del1_f(&sDel1_kFre3RYR, VIf(Bf2), VOf(Bf3));
    __hv_lt_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_samphold_f(&sSamphold_zK1VMapu, VIf(Bf1), VIf(Bf3), VOf(Bf3));
    __hv_add_f(VIf(Bf5), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_luAwHcST, VOf(Bf5));
    __hv_min_f(VIf(Bf3), VIf(Bf5), VOf(Bf5));
    __hv_zero_f(VOf(Bf3));
    __hv_max_f(VIf(Bf5), VIf(Bf3), VOf(Bf3));
    __hv_floor_f(VIf(Bf3), VOf(Bf5));
    __hv_cast_fi(VIf(Bf5), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_bF5EsO64, VIi(Bi1), VOf(Bf6));
    __hv_tabread_if(&sTabread_Nz5yK9h1, VIi(Bi0), VOf(Bf7));
    __hv_sub_f(VIf(Bf6), VIf(Bf7), VOf(Bf6));
    __hv_sub_f(VIf(Bf3), VIf(Bf5), VOf(Bf5));
    __hv_fma_f(VIf(Bf6), VIf(Bf5), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf5), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf2), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_floor_f(VIf(Bf2), VOf(Bf5));
    __hv_sub_f(VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf2), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_abs_f(VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf5), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf2), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_mul_f(VIf(Bf2), VIf(Bf2), VOf(Bf5));
    __hv_mul_f(VIf(Bf2), VIf(Bf5), VOf(Bf6));
    __hv_mul_f(VIf(Bf6), VIf(Bf5), VOf(Bf3));
    __hv_mul_f(VIf(Bf3), VIf(Bf5), VOf(Bf8));
    __hv_mul_f(VIf(Bf8), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf9), 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f);
    __hv_var_k_f(VOf(Bf10), 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f);
    __hv_var_k_f(VOf(Bf11), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf6), VIf(Bf11), VOf(Bf11));
    __hv_sub_f(VIf(Bf2), VIf(Bf11), VOf(Bf11));
    __hv_fma_f(VIf(Bf3), VIf(Bf10), VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf10), 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f);
    __hv_mul_f(VIf(Bf8), VIf(Bf10), VOf(Bf10));
    __hv_sub_f(VIf(Bf11), VIf(Bf10), VOf(Bf10));
    __hv_fma_f(VIf(Bf5), VIf(Bf9), VIf(Bf10), VOf(Bf10));
    __hv_mul_f(VIf(Bf7), VIf(Bf10), VOf(Bf10));
    __hv_del1_f(&sDel1_1pbz9IhA, VIf(Bf4), VOf(Bf7));
    __hv_lt_f(VIf(Bf4), VIf(Bf7), VOf(Bf7));
    __hv_samphold_f(&sSamphold_ajdckugh, VIf(ZERO), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf9), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_fma_f(VIf(Bf7), VIf(Bf4), VIf(Bf9), VOf(Bf9));
    __hv_del1_f(&sDel1_8gIeySxJ, VIf(Bf4), VOf(Bf7));
    __hv_lt_f(VIf(Bf4), VIf(Bf7), VOf(Bf7));
    __hv_samphold_f(&sSamphold_YbLplgYb, VIf(Bf1), VIf(Bf7), VOf(Bf7));
    __hv_add_f(VIf(Bf9), VIf(Bf7), VOf(Bf7));
    __hv_varread_f(&sVarf_tZzwfsDn, VOf(Bf9));
    __hv_min_f(VIf(Bf7), VIf(Bf9), VOf(Bf9));
    __hv_zero_f(VOf(Bf7));
    __hv_max_f(VIf(Bf9), VIf(Bf7), VOf(Bf7));
    __hv_floor_f(VIf(Bf7), VOf(Bf9));
    __hv_cast_fi(VIf(Bf9), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_LCieUrpa, VIi(Bi1), VOf(Bf1));
    __hv_tabread_if(&sTabread_oVRyjie9, VIi(Bi0), VOf(Bf5));
    __hv_sub_f(VIf(Bf1), VIf(Bf5), VOf(Bf1));
    __hv_sub_f(VIf(Bf7), VIf(Bf9), VOf(Bf9));
    __hv_fma_f(VIf(Bf1), VIf(Bf9), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf9), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf4), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf4), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf9), VIf(Bf4), VOf(Bf4));
    __hv_floor_f(VIf(Bf4), VOf(Bf9));
    __hv_sub_f(VIf(Bf4), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf4), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf9), VIf(Bf4), VOf(Bf4));
    __hv_abs_f(VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf9), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf4), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf4), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf9), VIf(Bf4), VOf(Bf4));
    __hv_mul_f(VIf(Bf4), VIf(Bf4), VOf(Bf9));
    __hv_mul_f(VIf(Bf4), VIf(Bf9), VOf(Bf1));
    __hv_mul_f(VIf(Bf1), VIf(Bf9), VOf(Bf7));
    __hv_mul_f(VIf(Bf7), VIf(Bf9), VOf(Bf11));
    __hv_mul_f(VIf(Bf11), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf8), 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f);
    __hv_var_k_f(VOf(Bf3), 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f);
    __hv_var_k_f(VOf(Bf2), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_sub_f(VIf(Bf4), VIf(Bf2), VOf(Bf2));
    __hv_fma_f(VIf(Bf7), VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf3), 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f);
    __hv_mul_f(VIf(Bf11), VIf(Bf3), VOf(Bf3));
    __hv_sub_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_fma_f(VIf(Bf9), VIf(Bf8), VIf(Bf3), VOf(Bf3));
    __hv_mul_f(VIf(Bf5), VIf(Bf3), VOf(Bf3));
    __hv_add_f(VIf(Bf10), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_Z9Nnl08n, VOf(Bf10));
    __hv_rpole_f(&sRPole_6QHmTwSt, VIf(Bf3), VIf(Bf10), VOf(Bf10));
    __hv_var_k_f(VOf(Bf3), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_del1_f(&sDel1_QypWBSjn, VIf(Bf10), VOf(Bf5));
    __hv_mul_f(VIf(Bf5), VIf(Bf3), VOf(Bf3));
    __hv_sub_f(VIf(Bf10), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_gS5Sasrq, VOf(Bf10));
    __hv_mul_f(VIf(Bf3), VIf(Bf10), VOf(Bf10));
    __hv_mul_f(VIf(Bf0), VIf(Bf10), VOf(Bf10));
    __hv_line_f(&sLine_kPytG5Co, VOf(Bf0));
    __hv_mul_f(VIf(Bf10), VIf(Bf0), VOf(Bf0));
    __hv_sample_f(this, &sSample_GybwLLos, VIf(ZERO), &sSample_GybwLLos_sendMessage);
    __hv_sample_f(this, &sSample_VSl3MWpb, VIf(Bf10), &sSample_VSl3MWpb_sendMessage);
    __hv_line_f(&sLine_Sn9TVkmF, VOf(Bf10));
    __hv_varread_f(&sVarf_JXcwgGbZ, VOf(Bf3));
    __hv_min_f(VIf(Bf10), VIf(Bf3), VOf(Bf3));
    __hv_zero_f(VOf(Bf10));
    __hv_max_f(VIf(Bf3), VIf(Bf10), VOf(Bf10));
    __hv_floor_f(VIf(Bf10), VOf(Bf3));
    __hv_cast_fi(VIf(Bf3), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_xBw5RJ3t, VIi(Bi1), VOf(Bf5));
    __hv_tabread_if(&sTabread_mgsZO6Oc, VIi(Bi0), VOf(Bf8));
    __hv_sub_f(VIf(Bf5), VIf(Bf8), VOf(Bf5));
    __hv_sub_f(VIf(Bf10), VIf(Bf3), VOf(Bf3));
    __hv_fma_f(VIf(Bf5), VIf(Bf3), VIf(Bf8), VOf(Bf8));
    __hv_line_f(&sLine_6mNXXCJ7, VOf(Bf3));
    __hv_mul_f(VIf(Bf8), VIf(Bf3), VOf(Bf3));
    __hv_line_f(&sLine_eWf6Hcd7, VOf(Bf8));
    __hv_varread_f(&sVarf_PD4Yfl3A, VOf(Bf5));
    __hv_mul_f(VIf(Bf8), VIf(Bf5), VOf(Bf5));
    __hv_mul_f(VIf(Bf3), VIf(Bf5), VOf(Bf5));
    __hv_line_f(&sLine_BTi6nfqs, VOf(Bf3));
    __hv_mul_f(VIf(Bf5), VIf(Bf3), VOf(Bf3));
    __hv_line_f(&sLine_DZJ2zHzL, VOf(Bf8));
    __hv_mul_f(VIf(Bf5), VIf(Bf8), VOf(Bf8));
    __hv_line_f(&sLine_NcgVXeVL, VOf(Bf5));
    __hv_varread_f(&sVarf_Nn7V9Hd7, VOf(Bf10));
    __hv_min_f(VIf(Bf5), VIf(Bf10), VOf(Bf10));
    __hv_zero_f(VOf(Bf5));
    __hv_max_f(VIf(Bf10), VIf(Bf5), VOf(Bf5));
    __hv_floor_f(VIf(Bf5), VOf(Bf10));
    __hv_cast_fi(VIf(Bf10), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_hwNjTqPz, VIi(Bi1), VOf(Bf9));
    __hv_tabread_if(&sTabread_PboqmQLM, VIi(Bi0), VOf(Bf2));
    __hv_sub_f(VIf(Bf9), VIf(Bf2), VOf(Bf9));
    __hv_sub_f(VIf(Bf5), VIf(Bf10), VOf(Bf10));
    __hv_fma_f(VIf(Bf9), VIf(Bf10), VIf(Bf2), VOf(Bf2));
    __hv_line_f(&sLine_MFD5QceL, VOf(Bf10));
    __hv_mul_f(VIf(Bf2), VIf(Bf10), VOf(Bf10));
    __hv_line_f(&sLine_GqCKfENF, VOf(Bf2));
    __hv_varread_f(&sVarf_z0ORyX7o, VOf(Bf9));
    __hv_mul_f(VIf(Bf2), VIf(Bf9), VOf(Bf9));
    __hv_mul_f(VIf(Bf10), VIf(Bf9), VOf(Bf9));
    __hv_line_f(&sLine_LH3Dh0ra, VOf(Bf10));
    __hv_mul_f(VIf(Bf9), VIf(Bf10), VOf(Bf10));
    __hv_line_f(&sLine_7GFtrkKz, VOf(Bf2));
    __hv_mul_f(VIf(Bf9), VIf(Bf2), VOf(Bf2));
    __hv_add_f(VIf(Bf3), VIf(Bf10), VOf(Bf10));
    __hv_line_f(&sLine_msp1Ye3X, VOf(Bf3));
    __hv_varread_f(&sVarf_Wy3LrshP, VOf(Bf9));
    __hv_min_f(VIf(Bf3), VIf(Bf9), VOf(Bf9));
    __hv_zero_f(VOf(Bf3));
    __hv_max_f(VIf(Bf9), VIf(Bf3), VOf(Bf3));
    __hv_floor_f(VIf(Bf3), VOf(Bf9));
    __hv_cast_fi(VIf(Bf9), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_SFqZFvrg, VIi(Bi1), VOf(Bf5));
    __hv_tabread_if(&sTabread_PElgroJl, VIi(Bi0), VOf(Bf11));
    __hv_sub_f(VIf(Bf5), VIf(Bf11), VOf(Bf5));
    __hv_sub_f(VIf(Bf3), VIf(Bf9), VOf(Bf9));
    __hv_fma_f(VIf(Bf5), VIf(Bf9), VIf(Bf11), VOf(Bf11));
    __hv_line_f(&sLine_PgJfdgEk, VOf(Bf9));
    __hv_mul_f(VIf(Bf11), VIf(Bf9), VOf(Bf9));
    __hv_line_f(&sLine_OTTrIrh4, VOf(Bf11));
    __hv_varread_f(&sVarf_zVNmO2Vt, VOf(Bf5));
    __hv_mul_f(VIf(Bf11), VIf(Bf5), VOf(Bf5));
    __hv_mul_f(VIf(Bf9), VIf(Bf5), VOf(Bf5));
    __hv_line_f(&sLine_qMIERDg8, VOf(Bf9));
    __hv_mul_f(VIf(Bf5), VIf(Bf9), VOf(Bf9));
    __hv_line_f(&sLine_FoyksauD, VOf(Bf11));
    __hv_mul_f(VIf(Bf5), VIf(Bf11), VOf(Bf11));
    __hv_add_f(VIf(Bf10), VIf(Bf9), VOf(Bf9));
    __hv_line_f(&sLine_F9IeWvwf, VOf(Bf10));
    __hv_varread_f(&sVarf_YRzOT6qX, VOf(Bf5));
    __hv_min_f(VIf(Bf10), VIf(Bf5), VOf(Bf5));
    __hv_zero_f(VOf(Bf10));
    __hv_max_f(VIf(Bf5), VIf(Bf10), VOf(Bf10));
    __hv_floor_f(VIf(Bf10), VOf(Bf5));
    __hv_cast_fi(VIf(Bf5), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_ma6MgTzX, VIi(Bi1), VOf(Bf3));
    __hv_tabread_if(&sTabread_TgEMkHGs, VIi(Bi0), VOf(Bf7));
    __hv_sub_f(VIf(Bf3), VIf(Bf7), VOf(Bf3));
    __hv_sub_f(VIf(Bf10), VIf(Bf5), VOf(Bf5));
    __hv_fma_f(VIf(Bf3), VIf(Bf5), VIf(Bf7), VOf(Bf7));
    __hv_line_f(&sLine_uFCAYdsC, VOf(Bf5));
    __hv_mul_f(VIf(Bf7), VIf(Bf5), VOf(Bf5));
    __hv_line_f(&sLine_GiixFRac, VOf(Bf7));
    __hv_varread_f(&sVarf_IFUHA6vp, VOf(Bf3));
    __hv_mul_f(VIf(Bf7), VIf(Bf3), VOf(Bf3));
    __hv_mul_f(VIf(Bf5), VIf(Bf3), VOf(Bf3));
    __hv_line_f(&sLine_T6lK4JNJ, VOf(Bf5));
    __hv_mul_f(VIf(Bf3), VIf(Bf5), VOf(Bf5));
    __hv_line_f(&sLine_MJbLJ0NW, VOf(Bf7));
    __hv_mul_f(VIf(Bf3), VIf(Bf7), VOf(Bf7));
    __hv_add_f(VIf(Bf9), VIf(Bf5), VOf(Bf5));
    __hv_add_f(VIf(Bf8), VIf(Bf2), VOf(Bf2));
    __hv_add_f(VIf(Bf2), VIf(Bf11), VOf(Bf11));
    __hv_add_f(VIf(Bf11), VIf(Bf7), VOf(Bf7));
    __hv_line_f(&sLine_kYf3Wxnv, VOf(Bf11));
    __hv_mul_f(VIf(Bf5), VIf(Bf11), VOf(Bf5));
    __hv_mul_f(VIf(Bf7), VIf(Bf11), VOf(Bf11));
    __hv_line_f(&sLine_uqeTqrvX, VOf(Bf7));
    __hv_mul_f(VIf(Bf0), VIf(Bf7), VOf(Bf7));
    __hv_add_f(VIf(Bf5), VIf(Bf7), VOf(Bf0));
    __hv_add_f(VIf(Bf11), VIf(Bf7), VOf(Bf11));
    __hv_line_f(&sLine_lwwd2OJE, VOf(Bf2));
    __hv_mul_f(VIf(Bf0), VIf(Bf2), VOf(Bf0));
    __hv_mul_f(VIf(Bf11), VIf(Bf2), VOf(Bf2));
    __hv_add_f(VIf(Bf5), VIf(Bf7), VOf(Bf7));
    __hv_line_f(&sLine_z8VOYOp9, VOf(Bf5));
    __hv_mul_f(VIf(Bf7), VIf(Bf5), VOf(Bf5));
    __hv_line_f(&sLine_Nnx4w0Pj, VOf(Bf7));
    __hv_mul_f(VIf(Bf5), VIf(Bf7), VOf(Bf7));
    __hv_tabwrite_f(&sTabwrite_OwXIKauj, VIf(Bf7));
    __hv_line_f(&sLine_Pcfne5it, VOf(Bf7));
    __hv_phasor_f(&sPhasor_Q1oGyOk9, VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf11), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf7), VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf8), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf11), VIf(Bf8), VOf(Bf8));
    __hv_floor_f(VIf(Bf8), VOf(Bf11));
    __hv_sub_f(VIf(Bf8), VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf8), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf11), VIf(Bf8), VOf(Bf8));
    __hv_abs_f(VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf11), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf8), VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf8), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf11), VIf(Bf8), VOf(Bf8));
    __hv_mul_f(VIf(Bf8), VIf(Bf8), VOf(Bf11));
    __hv_mul_f(VIf(Bf8), VIf(Bf11), VOf(Bf9));
    __hv_mul_f(VIf(Bf9), VIf(Bf11), VOf(Bf3));
    __hv_mul_f(VIf(Bf3), VIf(Bf11), VOf(Bf10));
    __hv_mul_f(VIf(Bf10), VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf4), 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f);
    __hv_var_k_f(VOf(Bf1), 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f);
    __hv_var_k_f(VOf(Bf6), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf9), VIf(Bf6), VOf(Bf6));
    __hv_sub_f(VIf(Bf8), VIf(Bf6), VOf(Bf6));
    __hv_fma_f(VIf(Bf3), VIf(Bf1), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf1), 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f);
    __hv_mul_f(VIf(Bf10), VIf(Bf1), VOf(Bf1));
    __hv_sub_f(VIf(Bf6), VIf(Bf1), VOf(Bf1));
    __hv_fma_f(VIf(Bf11), VIf(Bf4), VIf(Bf1), VOf(Bf1));
    __hv_line_f(&sLine_blkWxGKA, VOf(Bf4));
    __hv_line_f(&sLine_c0vz6sat, VOf(Bf11));
    __hv_fma_f(VIf(Bf7), VIf(Bf4), VIf(Bf11), VOf(Bf6));
    __hv_tabhead_f(&sTabhead_2CIAiSzb, VOf(Bf10));
    __hv_var_k_f_r(VOf(Bf3), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf10), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_LjwTSmA8, VOf(Bf10));
    __hv_mul_f(VIf(Bf6), VIf(Bf10), VOf(Bf10));
    __hv_varread_f(&sVarf_N0A1Kr2F, VOf(Bf6));
    __hv_min_f(VIf(Bf10), VIf(Bf6), VOf(Bf6));
    __hv_zero_f(VOf(Bf10));
    __hv_max_f(VIf(Bf6), VIf(Bf10), VOf(Bf10));
    __hv_sub_f(VIf(Bf3), VIf(Bf10), VOf(Bf10));
    __hv_floor_f(VIf(Bf10), VOf(Bf3));
    __hv_varread_f(&sVarf_njY9Ofxm, VOf(Bf6));
    __hv_zero_f(VOf(Bf8));
    __hv_lt_f(VIf(Bf3), VIf(Bf8), VOf(Bf8));
    __hv_and_f(VIf(Bf6), VIf(Bf8), VOf(Bf8));
    __hv_add_f(VIf(Bf3), VIf(Bf8), VOf(Bf8));
    __hv_cast_fi(VIf(Bf8), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_6YS6Zas8, VIi(Bi1), VOf(Bf8));
    __hv_tabread_if(&sTabread_uWdc53DZ, VIi(Bi0), VOf(Bf6));
    __hv_sub_f(VIf(Bf8), VIf(Bf6), VOf(Bf8));
    __hv_sub_f(VIf(Bf10), VIf(Bf3), VOf(Bf3));
    __hv_fma_f(VIf(Bf8), VIf(Bf3), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf3), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_add_f(VIf(Bf7), VIf(Bf3), VOf(Bf3));
    __hv_floor_f(VIf(Bf3), VOf(Bf7));
    __hv_sub_f(VIf(Bf3), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf3), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf7), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf8), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf3), VIf(Bf8), VOf(Bf8));
    __hv_floor_f(VIf(Bf8), VOf(Bf3));
    __hv_sub_f(VIf(Bf8), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf8), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf3), VIf(Bf8), VOf(Bf8));
    __hv_abs_f(VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf3), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf8), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf8), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf3), VIf(Bf8), VOf(Bf8));
    __hv_mul_f(VIf(Bf8), VIf(Bf8), VOf(Bf3));
    __hv_mul_f(VIf(Bf8), VIf(Bf3), VOf(Bf10));
    __hv_mul_f(VIf(Bf10), VIf(Bf3), VOf(Bf9));
    __hv_mul_f(VIf(Bf9), VIf(Bf3), VOf(Bf12));
    __hv_mul_f(VIf(Bf12), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf13), 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f);
    __hv_var_k_f(VOf(Bf14), 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f);
    __hv_var_k_f(VOf(Bf15), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf10), VIf(Bf15), VOf(Bf15));
    __hv_sub_f(VIf(Bf8), VIf(Bf15), VOf(Bf15));
    __hv_fma_f(VIf(Bf9), VIf(Bf14), VIf(Bf15), VOf(Bf15));
    __hv_var_k_f(VOf(Bf14), 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f);
    __hv_mul_f(VIf(Bf12), VIf(Bf14), VOf(Bf14));
    __hv_sub_f(VIf(Bf15), VIf(Bf14), VOf(Bf14));
    __hv_fma_f(VIf(Bf3), VIf(Bf13), VIf(Bf14), VOf(Bf14));
    __hv_fma_f(VIf(Bf7), VIf(Bf4), VIf(Bf11), VOf(Bf11));
    __hv_tabhead_f(&sTabhead_ZwjePcq4, VOf(Bf4));
    __hv_var_k_f_r(VOf(Bf7), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf4), VIf(Bf7), VOf(Bf7));
    __hv_varread_f(&sVarf_0PKrJtLn, VOf(Bf4));
    __hv_mul_f(VIf(Bf11), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_O1JsRuAR, VOf(Bf11));
    __hv_min_f(VIf(Bf4), VIf(Bf11), VOf(Bf11));
    __hv_zero_f(VOf(Bf4));
    __hv_max_f(VIf(Bf11), VIf(Bf4), VOf(Bf4));
    __hv_sub_f(VIf(Bf7), VIf(Bf4), VOf(Bf4));
    __hv_floor_f(VIf(Bf4), VOf(Bf7));
    __hv_varread_f(&sVarf_FdQ7zxf8, VOf(Bf11));
    __hv_zero_f(VOf(Bf13));
    __hv_lt_f(VIf(Bf7), VIf(Bf13), VOf(Bf13));
    __hv_and_f(VIf(Bf11), VIf(Bf13), VOf(Bf13));
    __hv_add_f(VIf(Bf7), VIf(Bf13), VOf(Bf13));
    __hv_cast_fi(VIf(Bf13), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_jnYLdFyM, VIi(Bi1), VOf(Bf13));
    __hv_tabread_if(&sTabread_kI6fXTcH, VIi(Bi0), VOf(Bf11));
    __hv_sub_f(VIf(Bf13), VIf(Bf11), VOf(Bf13));
    __hv_sub_f(VIf(Bf4), VIf(Bf7), VOf(Bf7));
    __hv_fma_f(VIf(Bf13), VIf(Bf7), VIf(Bf11), VOf(Bf11));
    __hv_mul_f(VIf(Bf14), VIf(Bf11), VOf(Bf11));
    __hv_fma_f(VIf(Bf1), VIf(Bf6), VIf(Bf11), VOf(Bf11));
    __hv_varread_f(&sVarf_xPvk0wcy, VOf(Bf6));
    __hv_tabhead_f(&sTabhead_dLY8yDtT, VOf(Bf1));
    __hv_var_k_f_r(VOf(Bf14), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf1), VIf(Bf14), VOf(Bf14));
    __hv_varread_f(&sVarf_4vQNbW7d, VOf(Bf1));
    __hv_mul_f(VIf(Bf6), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_Br8Tz02Z, VOf(Bf6));
    __hv_min_f(VIf(Bf1), VIf(Bf6), VOf(Bf6));
    __hv_zero_f(VOf(Bf1));
    __hv_max_f(VIf(Bf6), VIf(Bf1), VOf(Bf1));
    __hv_sub_f(VIf(Bf14), VIf(Bf1), VOf(Bf1));
    __hv_floor_f(VIf(Bf1), VOf(Bf14));
    __hv_varread_f(&sVarf_EZAD5Gze, VOf(Bf6));
    __hv_zero_f(VOf(Bf7));
    __hv_lt_f(VIf(Bf14), VIf(Bf7), VOf(Bf7));
    __hv_and_f(VIf(Bf6), VIf(Bf7), VOf(Bf7));
    __hv_add_f(VIf(Bf14), VIf(Bf7), VOf(Bf7));
    __hv_cast_fi(VIf(Bf7), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_tOyhtBjq, VIi(Bi1), VOf(Bf7));
    __hv_tabread_if(&sTabread_aAWoqMMG, VIi(Bi0), VOf(Bf6));
    __hv_sub_f(VIf(Bf7), VIf(Bf6), VOf(Bf7));
    __hv_sub_f(VIf(Bf1), VIf(Bf14), VOf(Bf14));
    __hv_fma_f(VIf(Bf7), VIf(Bf14), VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_M9shA97f, VOf(Bf14));
    __hv_rpole_f(&sRPole_qFQZYD1i, VIf(Bf6), VIf(Bf14), VOf(Bf14));
    __hv_var_k_f(VOf(Bf6), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_del1_f(&sDel1_GlhZDR3P, VIf(Bf14), VOf(Bf7));
    __hv_mul_f(VIf(Bf7), VIf(Bf6), VOf(Bf6));
    __hv_sub_f(VIf(Bf14), VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_ZMBkLo27, VOf(Bf14));
    __hv_mul_f(VIf(Bf6), VIf(Bf14), VOf(Bf14));
    __hv_varread_f(&sVarf_HfaUnYke, VOf(Bf6));
    __hv_mul_f(VIf(Bf14), VIf(Bf6), VOf(Bf6));
    __hv_add_f(VIf(Bf11), VIf(Bf6), VOf(Bf14));
    __hv_line_f(&sLine_IaVB52Ee, VOf(Bf7));
    __hv_varread_f(&sVarf_pgji7FqZ, VOf(Bf1));
    __hv_mul_f(VIf(Bf6), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_vhqubXcr, VOf(Bf6));
    __hv_rpole_f(&sRPole_Q0PpMq1N, VIf(Bf1), VIf(Bf6), VOf(Bf6));
    __hv_fma_f(VIf(Bf11), VIf(Bf7), VIf(Bf6), VOf(Bf6));
    __hv_tabwrite_f(&sTabwrite_bKDfZCiT, VIf(Bf6));
    __hv_var_k_f(VOf(Bf6), 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f);
    __hv_mul_f(VIf(Bf14), VIf(Bf6), VOf(Bf6));
    __hv_tabread_f(&sTabread_HVCRVxfI, VOf(Bf14));
    __hv_varread_f(&sVarf_l81GUvvI, VOf(Bf7));
    __hv_mul_f(VIf(Bf14), VIf(Bf7), VOf(Bf7));
    __hv_varread_f(&sVarf_iQtwBMRY, VOf(Bf11));
    __hv_rpole_f(&sRPole_SutmEs0C, VIf(Bf7), VIf(Bf11), VOf(Bf11));
    __hv_sub_f(VIf(Bf11), VIf(Bf14), VOf(Bf11));
    __hv_line_f(&sLine_VNCvY9SK, VOf(Bf7));
    __hv_fma_f(VIf(Bf11), VIf(Bf7), VIf(Bf14), VOf(Bf14));
    __hv_line_f(&sLine_8eT4FstA, VOf(Bf11));
    __hv_tabread_f(&sTabread_AZxD1A9S, VOf(Bf1));
    __hv_add_f(VIf(Bf5), VIf(Bf1), VOf(Bf13));
    __hv_tabread_f(&sTabread_9cGt4C5J, VOf(Bf4));
    __hv_add_f(VIf(Bf13), VIf(Bf4), VOf(Bf3));
    __hv_tabread_f(&sTabread_41vYJHEg, VOf(Bf15));
    __hv_add_f(VIf(Bf3), VIf(Bf15), VOf(Bf12));
    __hv_tabread_f(&sTabread_NrulwpP8, VOf(Bf9));
    __hv_add_f(VIf(Bf12), VIf(Bf9), VOf(Bf8));
    __hv_tabread_f(&sTabread_aTDR6e40, VOf(Bf10));
    __hv_sub_f(VIf(Bf8), VIf(Bf10), VOf(Bf16));
    __hv_tabwrite_f(&sTabwrite_ryUt1QY8, VIf(Bf16));
    __hv_sub_f(VIf(Bf12), VIf(Bf9), VOf(Bf9));
    __hv_tabwrite_f(&sTabwrite_U8Cp5GTq, VIf(Bf9));
    __hv_sub_f(VIf(Bf3), VIf(Bf15), VOf(Bf15));
    __hv_tabwrite_f(&sTabwrite_0hu6njQb, VIf(Bf15));
    __hv_sub_f(VIf(Bf13), VIf(Bf4), VOf(Bf4));
    __hv_tabwrite_f(&sTabwrite_xVutPYcz, VIf(Bf4));
    __hv_sub_f(VIf(Bf5), VIf(Bf1), VOf(Bf1));
    __hv_tabwrite_f(&sTabwrite_ZMXvfo1q, VIf(Bf1));
    __hv_tabwrite_f(&sTabwrite_lH279H20, VIf(Bf5));
    __hv_add_f(VIf(Bf8), VIf(Bf10), VOf(Bf10));
    __hv_tabread_f(&sTabread_29P1pciG, VOf(Bf8));
    __hv_fma_f(VIf(Bf14), VIf(Bf11), VIf(Bf10), VOf(Bf10));
    __hv_tabread_f(&sTabread_2hC6Db7E, VOf(Bf14));
    __hv_varread_f(&sVarf_v2f1kXja, VOf(Bf1));
    __hv_mul_f(VIf(Bf14), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_QG70fgrH, VOf(Bf4));
    __hv_rpole_f(&sRPole_2KREmCB6, VIf(Bf1), VIf(Bf4), VOf(Bf4));
    __hv_sub_f(VIf(Bf4), VIf(Bf14), VOf(Bf4));
    __hv_fma_f(VIf(Bf4), VIf(Bf7), VIf(Bf14), VOf(Bf14));
    __hv_fma_f(VIf(Bf14), VIf(Bf11), VIf(Bf8), VOf(Bf8));
    __hv_add_f(VIf(Bf10), VIf(Bf8), VOf(Bf14));
    __hv_tabread_f(&sTabread_gQLapaUV, VOf(Bf4));
    __hv_varread_f(&sVarf_9MNi9syW, VOf(Bf1));
    __hv_mul_f(VIf(Bf4), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_L80vbO3y, VOf(Bf13));
    __hv_rpole_f(&sRPole_P7X8k6Ta, VIf(Bf1), VIf(Bf13), VOf(Bf13));
    __hv_sub_f(VIf(Bf13), VIf(Bf4), VOf(Bf13));
    __hv_fma_f(VIf(Bf13), VIf(Bf7), VIf(Bf4), VOf(Bf4));
    __hv_mul_f(VIf(Bf4), VIf(Bf11), VOf(Bf4));
    __hv_tabread_f(&sTabread_3YatQhob, VOf(Bf13));
    __hv_varread_f(&sVarf_0elU9Ujj, VOf(Bf1));
    __hv_mul_f(VIf(Bf13), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_QPD9tpJ9, VOf(Bf15));
    __hv_rpole_f(&sRPole_NN07t0Gf, VIf(Bf1), VIf(Bf15), VOf(Bf15));
    __hv_sub_f(VIf(Bf15), VIf(Bf13), VOf(Bf15));
    __hv_fma_f(VIf(Bf15), VIf(Bf7), VIf(Bf13), VOf(Bf13));
    __hv_mul_f(VIf(Bf13), VIf(Bf11), VOf(Bf11));
    __hv_add_f(VIf(Bf4), VIf(Bf11), VOf(Bf13));
    __hv_add_f(VIf(Bf14), VIf(Bf13), VOf(Bf7));
    __hv_tabwrite_f(&sTabwrite_koAtA5XQ, VIf(Bf7));
    __hv_sub_f(VIf(Bf10), VIf(Bf8), VOf(Bf7));
    __hv_sub_f(VIf(Bf4), VIf(Bf11), VOf(Bf15));
    __hv_add_f(VIf(Bf7), VIf(Bf15), VOf(Bf1));
    __hv_tabwrite_f(&sTabwrite_BOOP7cdA, VIf(Bf1));
    __hv_sub_f(VIf(Bf14), VIf(Bf13), VOf(Bf13));
    __hv_tabwrite_f(&sTabwrite_0oIs1K0q, VIf(Bf13));
    __hv_sub_f(VIf(Bf7), VIf(Bf15), VOf(Bf15));
    __hv_tabwrite_f(&sTabwrite_E7kC2rzN, VIf(Bf15));
    __hv_line_f(&sLine_6roDgJna, VOf(Bf15));
    __hv_mul_f(VIf(Bf10), VIf(Bf15), VOf(Bf10));
    __hv_mul_f(VIf(Bf8), VIf(Bf15), VOf(Bf8));
    __hv_mul_f(VIf(Bf4), VIf(Bf15), VOf(Bf4));
    __hv_mul_f(VIf(Bf11), VIf(Bf15), VOf(Bf15));
    __hv_add_f(VIf(Bf6), VIf(Bf10), VOf(Bf10));
    __hv_line_f(&sLine_R9hVG6i4, VOf(Bf15));
    __hv_mul_f(VIf(Bf5), VIf(Bf15), VOf(Bf15));
    __hv_var_k_f(VOf(Bf5), 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f);
    __hv_mul_f(VIf(Bf15), VIf(Bf5), VOf(Bf5));
    __hv_tabwrite_f(&sTabwrite_Livcz3dG, VIf(Bf5));
    __hv_line_f(&sLine_1fVuvFyw, VOf(Bf15));
    __hv_phasor_f(&sPhasor_5MiEcEx9, VIf(Bf15), VOf(Bf15));
    __hv_var_k_f(VOf(Bf4), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf15), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf11), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf4), VIf(Bf11), VOf(Bf11));
    __hv_floor_f(VIf(Bf11), VOf(Bf4));
    __hv_sub_f(VIf(Bf11), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf11), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf4), VIf(Bf11), VOf(Bf11));
    __hv_abs_f(VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf4), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf11), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf11), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf4), VIf(Bf11), VOf(Bf11));
    __hv_mul_f(VIf(Bf11), VIf(Bf11), VOf(Bf4));
    __hv_mul_f(VIf(Bf11), VIf(Bf4), VOf(Bf7));
    __hv_mul_f(VIf(Bf7), VIf(Bf4), VOf(Bf13));
    __hv_mul_f(VIf(Bf13), VIf(Bf4), VOf(Bf14));
    __hv_mul_f(VIf(Bf14), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf1), 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f);
    __hv_var_k_f(VOf(Bf3), 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f);
    __hv_var_k_f(VOf(Bf9), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf7), VIf(Bf9), VOf(Bf9));
    __hv_sub_f(VIf(Bf11), VIf(Bf9), VOf(Bf9));
    __hv_fma_f(VIf(Bf13), VIf(Bf3), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf3), 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f);
    __hv_mul_f(VIf(Bf14), VIf(Bf3), VOf(Bf3));
    __hv_sub_f(VIf(Bf9), VIf(Bf3), VOf(Bf3));
    __hv_fma_f(VIf(Bf4), VIf(Bf1), VIf(Bf3), VOf(Bf3));
    __hv_line_f(&sLine_GxuX9dDK, VOf(Bf1));
    __hv_line_f(&sLine_lk7epkND, VOf(Bf4));
    __hv_fma_f(VIf(Bf15), VIf(Bf1), VIf(Bf4), VOf(Bf9));
    __hv_tabhead_f(&sTabhead_a84pMSJc, VOf(Bf14));
    __hv_var_k_f_r(VOf(Bf13), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf14), VIf(Bf13), VOf(Bf13));
    __hv_varread_f(&sVarf_Itk7TK5B, VOf(Bf14));
    __hv_mul_f(VIf(Bf9), VIf(Bf14), VOf(Bf14));
    __hv_varread_f(&sVarf_qXVAzdEr, VOf(Bf9));
    __hv_min_f(VIf(Bf14), VIf(Bf9), VOf(Bf9));
    __hv_zero_f(VOf(Bf14));
    __hv_max_f(VIf(Bf9), VIf(Bf14), VOf(Bf14));
    __hv_sub_f(VIf(Bf13), VIf(Bf14), VOf(Bf14));
    __hv_floor_f(VIf(Bf14), VOf(Bf13));
    __hv_varread_f(&sVarf_xmhx0KYd, VOf(Bf9));
    __hv_zero_f(VOf(Bf11));
    __hv_lt_f(VIf(Bf13), VIf(Bf11), VOf(Bf11));
    __hv_and_f(VIf(Bf9), VIf(Bf11), VOf(Bf11));
    __hv_add_f(VIf(Bf13), VIf(Bf11), VOf(Bf11));
    __hv_cast_fi(VIf(Bf11), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_piN0qW5X, VIi(Bi1), VOf(Bf11));
    __hv_tabread_if(&sTabread_x16Bq9xb, VIi(Bi0), VOf(Bf9));
    __hv_sub_f(VIf(Bf11), VIf(Bf9), VOf(Bf11));
    __hv_sub_f(VIf(Bf14), VIf(Bf13), VOf(Bf13));
    __hv_fma_f(VIf(Bf11), VIf(Bf13), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf13), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_add_f(VIf(Bf15), VIf(Bf13), VOf(Bf13));
    __hv_floor_f(VIf(Bf13), VOf(Bf15));
    __hv_sub_f(VIf(Bf13), VIf(Bf15), VOf(Bf15));
    __hv_var_k_f(VOf(Bf13), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf15), VIf(Bf13), VOf(Bf13));
    __hv_var_k_f(VOf(Bf11), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf13), VIf(Bf11), VOf(Bf11));
    __hv_floor_f(VIf(Bf11), VOf(Bf13));
    __hv_sub_f(VIf(Bf11), VIf(Bf13), VOf(Bf13));
    __hv_var_k_f(VOf(Bf11), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf13), VIf(Bf11), VOf(Bf11));
    __hv_abs_f(VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf13), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf11), VIf(Bf13), VOf(Bf13));
    __hv_var_k_f(VOf(Bf11), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf13), VIf(Bf11), VOf(Bf11));
    __hv_mul_f(VIf(Bf11), VIf(Bf11), VOf(Bf13));
    __hv_mul_f(VIf(Bf11), VIf(Bf13), VOf(Bf14));
    __hv_mul_f(VIf(Bf14), VIf(Bf13), VOf(Bf7));
    __hv_mul_f(VIf(Bf7), VIf(Bf13), VOf(Bf12));
    __hv_mul_f(VIf(Bf12), VIf(Bf13), VOf(Bf13));
    __hv_var_k_f(VOf(Bf16), 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f);
    __hv_var_k_f(VOf(Bf17), 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f);
    __hv_var_k_f(VOf(Bf18), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf14), VIf(Bf18), VOf(Bf18));
    __hv_sub_f(VIf(Bf11), VIf(Bf18), VOf(Bf18));
    __hv_fma_f(VIf(Bf7), VIf(Bf17), VIf(Bf18), VOf(Bf18));
    __hv_var_k_f(VOf(Bf17), 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f);
    __hv_mul_f(VIf(Bf12), VIf(Bf17), VOf(Bf17));
    __hv_sub_f(VIf(Bf18), VIf(Bf17), VOf(Bf17));
    __hv_fma_f(VIf(Bf13), VIf(Bf16), VIf(Bf17), VOf(Bf17));
    __hv_fma_f(VIf(Bf15), VIf(Bf1), VIf(Bf4), VOf(Bf4));
    __hv_tabhead_f(&sTabhead_2dcgrhkp, VOf(Bf1));
    __hv_var_k_f_r(VOf(Bf15), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf1), VIf(Bf15), VOf(Bf15));
    __hv_varread_f(&sVarf_ESzMXuks, VOf(Bf1));
    __hv_mul_f(VIf(Bf4), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_dymcxWlX, VOf(Bf4));
    __hv_min_f(VIf(Bf1), VIf(Bf4), VOf(Bf4));
    __hv_zero_f(VOf(Bf1));
    __hv_max_f(VIf(Bf4), VIf(Bf1), VOf(Bf1));
    __hv_sub_f(VIf(Bf15), VIf(Bf1), VOf(Bf1));
    __hv_floor_f(VIf(Bf1), VOf(Bf15));
    __hv_varread_f(&sVarf_wP98dVQc, VOf(Bf4));
    __hv_zero_f(VOf(Bf16));
    __hv_lt_f(VIf(Bf15), VIf(Bf16), VOf(Bf16));
    __hv_and_f(VIf(Bf4), VIf(Bf16), VOf(Bf16));
    __hv_add_f(VIf(Bf15), VIf(Bf16), VOf(Bf16));
    __hv_cast_fi(VIf(Bf16), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_eOAhoL4N, VIi(Bi1), VOf(Bf16));
    __hv_tabread_if(&sTabread_nhgnYHLv, VIi(Bi0), VOf(Bf4));
    __hv_sub_f(VIf(Bf16), VIf(Bf4), VOf(Bf16));
    __hv_sub_f(VIf(Bf1), VIf(Bf15), VOf(Bf15));
    __hv_fma_f(VIf(Bf16), VIf(Bf15), VIf(Bf4), VOf(Bf4));
    __hv_mul_f(VIf(Bf17), VIf(Bf4), VOf(Bf4));
    __hv_fma_f(VIf(Bf3), VIf(Bf9), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_BC4uhilG, VOf(Bf9));
    __hv_tabhead_f(&sTabhead_xuisShaE, VOf(Bf3));
    __hv_var_k_f_r(VOf(Bf17), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf3), VIf(Bf17), VOf(Bf17));
    __hv_varread_f(&sVarf_Zditxlwn, VOf(Bf3));
    __hv_mul_f(VIf(Bf9), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_m66pWKob, VOf(Bf9));
    __hv_min_f(VIf(Bf3), VIf(Bf9), VOf(Bf9));
    __hv_zero_f(VOf(Bf3));
    __hv_max_f(VIf(Bf9), VIf(Bf3), VOf(Bf3));
    __hv_sub_f(VIf(Bf17), VIf(Bf3), VOf(Bf3));
    __hv_floor_f(VIf(Bf3), VOf(Bf17));
    __hv_varread_f(&sVarf_mVJTqDkL, VOf(Bf9));
    __hv_zero_f(VOf(Bf15));
    __hv_lt_f(VIf(Bf17), VIf(Bf15), VOf(Bf15));
    __hv_and_f(VIf(Bf9), VIf(Bf15), VOf(Bf15));
    __hv_add_f(VIf(Bf17), VIf(Bf15), VOf(Bf15));
    __hv_cast_fi(VIf(Bf15), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_9PJksFqd, VIi(Bi1), VOf(Bf15));
    __hv_tabread_if(&sTabread_eCfV51s0, VIi(Bi0), VOf(Bf9));
    __hv_sub_f(VIf(Bf15), VIf(Bf9), VOf(Bf15));
    __hv_sub_f(VIf(Bf3), VIf(Bf17), VOf(Bf17));
    __hv_fma_f(VIf(Bf15), VIf(Bf17), VIf(Bf9), VOf(Bf9));
    __hv_varread_f(&sVarf_miixX56K, VOf(Bf17));
    __hv_rpole_f(&sRPole_yg1cb6Lj, VIf(Bf9), VIf(Bf17), VOf(Bf17));
    __hv_var_k_f(VOf(Bf9), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_del1_f(&sDel1_vVZE1hF6, VIf(Bf17), VOf(Bf15));
    __hv_mul_f(VIf(Bf15), VIf(Bf9), VOf(Bf9));
    __hv_sub_f(VIf(Bf17), VIf(Bf9), VOf(Bf9));
    __hv_varread_f(&sVarf_9y8LJ3DQ, VOf(Bf17));
    __hv_mul_f(VIf(Bf9), VIf(Bf17), VOf(Bf17));
    __hv_varread_f(&sVarf_y1NMUgFi, VOf(Bf9));
    __hv_mul_f(VIf(Bf17), VIf(Bf9), VOf(Bf9));
    __hv_add_f(VIf(Bf4), VIf(Bf9), VOf(Bf17));
    __hv_line_f(&sLine_4CNE9bol, VOf(Bf15));
    __hv_varread_f(&sVarf_WPWtNQuY, VOf(Bf3));
    __hv_mul_f(VIf(Bf9), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_ZhS7koEk, VOf(Bf9));
    __hv_rpole_f(&sRPole_DljXFU6d, VIf(Bf3), VIf(Bf9), VOf(Bf9));
    __hv_fma_f(VIf(Bf4), VIf(Bf15), VIf(Bf9), VOf(Bf9));
    __hv_tabwrite_f(&sTabwrite_fhhUv73T, VIf(Bf9));
    __hv_add_f(VIf(Bf17), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_WCtoU3g6, VOf(Bf17));
    __hv_varread_f(&sVarf_QyuLEbsj, VOf(Bf9));
    __hv_mul_f(VIf(Bf17), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf17), 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f);
    __hv_max_f(VIf(Bf9), VIf(Bf17), VOf(Bf17));
    __hv_varread_f(&sVarf_Vk7edBvA, VOf(Bf9));
    __hv_min_f(VIf(Bf17), VIf(Bf9), VOf(Bf9));
    __hv_varread_f(&sVarf_LTG3pOAi, VOf(Bf15));
    __hv_mul_f(VIf(Bf9), VIf(Bf15), VOf(Bf15));
    __hv_mul_f(VIf(Bf5), VIf(Bf15), VOf(Bf5));
    __hv_varread_f(&sVarf_cTf8HQBR, VOf(Bf9));
    __hv_mul_f(VIf(Bf5), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf5), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_sub_f(VIf(Bf15), VIf(Bf5), VOf(Bf15));
    __hv_cos_f(VIf(Bf17), VOf(Bf17));
    __hv_mul_f(VIf(Bf15), VIf(Bf17), VOf(Bf4));
    __hv_mul_f(VIf(Bf17), VIf(Bf17), VOf(Bf17));
    __hv_sub_f(VIf(Bf5), VIf(Bf17), VOf(Bf17));
    __hv_zero_f(VOf(Bf5));
    __hv_gt_f(VIf(Bf17), VIf(Bf5), VOf(Bf5));
    __hv_sqrt_f(VIf(Bf17), VOf(Bf17));
    __hv_and_f(VIf(Bf5), VIf(Bf17), VOf(Bf17));
    __hv_mul_f(VIf(Bf15), VIf(Bf17), VOf(Bf17));
    __hv_cpole_f(&sCPole_tBVRetvl, VIf(Bf9), VIf(ZERO), VIf(Bf4), VIf(Bf17), VOf(Bf17), VOf(Bf4));
    __hv_varread_f(&sVarf_0UciwyL3, VOf(Bf4));
    __hv_mul_f(VIf(Bf17), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_AWbLPLRP, VOf(Bf17));
    __hv_rpole_f(&sRPole_oJkgfbWW, VIf(Bf4), VIf(Bf17), VOf(Bf17));
    __hv_varread_f(&sVarf_t1Vuvfnr, VOf(Bf4));
    __hv_mul_f(VIf(Bf17), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_Km2MV9xh, VOf(Bf17));
    __hv_rpole_f(&sRPole_LJJLWiXf, VIf(Bf4), VIf(Bf17), VOf(Bf17));
    __hv_varread_f(&sVarf_ONXlxAYt, VOf(Bf4));
    __hv_mul_f(VIf(Bf17), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_UDdEKmRm, VOf(Bf17));
    __hv_rpole_f(&sRPole_0IgGcqq3, VIf(Bf4), VIf(Bf17), VOf(Bf17));
    __hv_tabread_f(&sTabread_jD5IbQdJ, VOf(Bf4));
    __hv_varread_f(&sVarf_bYAW0lRE, VOf(Bf9));
    __hv_mul_f(VIf(Bf4), VIf(Bf9), VOf(Bf9));
    __hv_varread_f(&sVarf_wmD7T1pZ, VOf(Bf15));
    __hv_rpole_f(&sRPole_PjEM5rLI, VIf(Bf9), VIf(Bf15), VOf(Bf15));
    __hv_sub_f(VIf(Bf15), VIf(Bf4), VOf(Bf15));
    __hv_line_f(&sLine_Z2qmG9sK, VOf(Bf9));
    __hv_fma_f(VIf(Bf15), VIf(Bf9), VIf(Bf4), VOf(Bf4));
    __hv_line_f(&sLine_jqDt2JHm, VOf(Bf15));
    __hv_tabread_f(&sTabread_5iyvOZtU, VOf(Bf5));
    __hv_add_f(VIf(Bf17), VIf(Bf5), VOf(Bf3));
    __hv_tabread_f(&sTabread_1mmTSLm7, VOf(Bf16));
    __hv_add_f(VIf(Bf3), VIf(Bf16), VOf(Bf1));
    __hv_tabread_f(&sTabread_1wURQaYl, VOf(Bf13));
    __hv_add_f(VIf(Bf1), VIf(Bf13), VOf(Bf18));
    __hv_tabread_f(&sTabread_xjG6hQnr, VOf(Bf12));
    __hv_add_f(VIf(Bf18), VIf(Bf12), VOf(Bf7));
    __hv_tabread_f(&sTabread_OVjTHdeX, VOf(Bf11));
    __hv_sub_f(VIf(Bf7), VIf(Bf11), VOf(Bf14));
    __hv_tabwrite_f(&sTabwrite_AC7RFqlE, VIf(Bf14));
    __hv_sub_f(VIf(Bf18), VIf(Bf12), VOf(Bf12));
    __hv_tabwrite_f(&sTabwrite_pt0bpv9P, VIf(Bf12));
    __hv_sub_f(VIf(Bf1), VIf(Bf13), VOf(Bf13));
    __hv_tabwrite_f(&sTabwrite_yHsIgnQe, VIf(Bf13));
    __hv_sub_f(VIf(Bf3), VIf(Bf16), VOf(Bf16));
    __hv_tabwrite_f(&sTabwrite_qDzEn88v, VIf(Bf16));
    __hv_sub_f(VIf(Bf17), VIf(Bf5), VOf(Bf5));
    __hv_tabwrite_f(&sTabwrite_QJKGekIF, VIf(Bf5));
    __hv_tabwrite_f(&sTabwrite_yaFSIK1K, VIf(Bf17));
    __hv_add_f(VIf(Bf7), VIf(Bf11), VOf(Bf11));
    __hv_tabread_f(&sTabread_qqQxRIH1, VOf(Bf7));
    __hv_fma_f(VIf(Bf4), VIf(Bf15), VIf(Bf11), VOf(Bf11));
    __hv_tabread_f(&sTabread_XflJIGJu, VOf(Bf4));
    __hv_varread_f(&sVarf_ZvWkDnS5, VOf(Bf5));
    __hv_mul_f(VIf(Bf4), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_CCMxd4tc, VOf(Bf16));
    __hv_rpole_f(&sRPole_GpAMy306, VIf(Bf5), VIf(Bf16), VOf(Bf16));
    __hv_sub_f(VIf(Bf16), VIf(Bf4), VOf(Bf16));
    __hv_fma_f(VIf(Bf16), VIf(Bf9), VIf(Bf4), VOf(Bf4));
    __hv_fma_f(VIf(Bf4), VIf(Bf15), VIf(Bf7), VOf(Bf7));
    __hv_add_f(VIf(Bf11), VIf(Bf7), VOf(Bf4));
    __hv_tabread_f(&sTabread_0JWiUFjx, VOf(Bf16));
    __hv_varread_f(&sVarf_q13eUdEG, VOf(Bf5));
    __hv_mul_f(VIf(Bf16), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_tPyb9atp, VOf(Bf3));
    __hv_rpole_f(&sRPole_DhZe5W1m, VIf(Bf5), VIf(Bf3), VOf(Bf3));
    __hv_sub_f(VIf(Bf3), VIf(Bf16), VOf(Bf3));
    __hv_fma_f(VIf(Bf3), VIf(Bf9), VIf(Bf16), VOf(Bf16));
    __hv_mul_f(VIf(Bf16), VIf(Bf15), VOf(Bf16));
    __hv_tabread_f(&sTabread_je7JarWD, VOf(Bf3));
    __hv_varread_f(&sVarf_26IUawB8, VOf(Bf5));
    __hv_mul_f(VIf(Bf3), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_uTVDKciq, VOf(Bf13));
    __hv_rpole_f(&sRPole_5eFkv67A, VIf(Bf5), VIf(Bf13), VOf(Bf13));
    __hv_sub_f(VIf(Bf13), VIf(Bf3), VOf(Bf13));
    __hv_fma_f(VIf(Bf13), VIf(Bf9), VIf(Bf3), VOf(Bf3));
    __hv_mul_f(VIf(Bf3), VIf(Bf15), VOf(Bf15));
    __hv_add_f(VIf(Bf16), VIf(Bf15), VOf(Bf3));
    __hv_add_f(VIf(Bf4), VIf(Bf3), VOf(Bf9));
    __hv_tabwrite_f(&sTabwrite_68XwZE8t, VIf(Bf9));
    __hv_sub_f(VIf(Bf11), VIf(Bf7), VOf(Bf9));
    __hv_sub_f(VIf(Bf16), VIf(Bf15), VOf(Bf13));
    __hv_add_f(VIf(Bf9), VIf(Bf13), VOf(Bf5));
    __hv_tabwrite_f(&sTabwrite_cPJ4FJgN, VIf(Bf5));
    __hv_sub_f(VIf(Bf4), VIf(Bf3), VOf(Bf3));
    __hv_tabwrite_f(&sTabwrite_pLV6Qlb7, VIf(Bf3));
    __hv_sub_f(VIf(Bf9), VIf(Bf13), VOf(Bf13));
    __hv_tabwrite_f(&sTabwrite_GHM6ve2y, VIf(Bf13));
    __hv_line_f(&sLine_z0zOuuMF, VOf(Bf13));
    __hv_mul_f(VIf(Bf11), VIf(Bf13), VOf(Bf11));
    __hv_mul_f(VIf(Bf7), VIf(Bf13), VOf(Bf7));
    __hv_mul_f(VIf(Bf16), VIf(Bf13), VOf(Bf16));
    __hv_mul_f(VIf(Bf15), VIf(Bf13), VOf(Bf13));
    __hv_add_f(VIf(Bf17), VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf17), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf11), VIf(Bf17), VOf(Bf17));
    __hv_add_f(VIf(Bf10), VIf(Bf17), VOf(Bf10));
    __hv_add_f(VIf(Bf6), VIf(Bf8), VOf(Bf8));
    __hv_add_f(VIf(Bf8), VIf(Bf17), VOf(Bf17));
    __hv_line_f(&sLine_LXXPPTAJ, VOf(Bf8));
    __hv_mul_f(VIf(Bf10), VIf(Bf8), VOf(Bf10));
    __hv_mul_f(VIf(Bf17), VIf(Bf8), VOf(Bf8));
    __hv_add_f(VIf(Bf0), VIf(Bf10), VOf(Bf10));
    __hv_add_f(VIf(Bf2), VIf(Bf8), VOf(Bf8));
    __hv_line_f(&sLine_MZIVMHwM, VOf(Bf2));
    __hv_mul_f(VIf(Bf10), VIf(Bf2), VOf(Bf10));
    __hv_mul_f(VIf(Bf8), VIf(Bf2), VOf(Bf2));
    __hv_add_f(VIf(Bf10), VIf(O0), VOf(O0));
    __hv_add_f(VIf(Bf2), VIf(O1), VOf(O1));

    // save output vars to output buffer
    __hv_store_f(outputBuffers[0]+n, VIf(O0));
    __hv_store_f(outputBuffers[1]+n, VIf(O1));
  }

  blockStartTimestamp = nextBlock;

  return n4; // return the number of frames processed

}

int Heavy_SoundScraper::processInline(float *inputBuffers, float *outputBuffers, int n4) {
  hv_assert(!(n4 & HV_N_SIMD_MASK)); // ensure that n4 is a multiple of HV_N_SIMD

  // define the heavy input buffer for 0 channel(s)
  float **const bIn = NULL;

  // define the heavy output buffer for 2 channel(s)
  float **const bOut = reinterpret_cast<float **>(hv_alloca(2*sizeof(float *)));
  bOut[0] = outputBuffers+(0*n4);
  bOut[1] = outputBuffers+(1*n4);

  int n = process(bIn, bOut, n4);
  return n;
}

int Heavy_SoundScraper::processInlineInterleaved(float *inputBuffers, float *outputBuffers, int n4) {
  hv_assert(n4 & ~HV_N_SIMD_MASK); // ensure that n4 is a multiple of HV_N_SIMD

  // define the heavy input buffer for 0 channel(s), uninterleave
  float *const bIn = NULL;

  // define the heavy output buffer for 2 channel(s)
  float *const bOut = reinterpret_cast<float *>(hv_alloca(2*n4*sizeof(float)));

  int n = processInline(bIn, bOut, n4);

  // interleave the heavy output into the output buffer
  #if HV_SIMD_AVX
  for (int i = 0, j = 0; j < n4; j += 8, i += 16) {
    __m256 x = _mm256_load_ps(bOut+j);    // LLLLLLLL
    __m256 y = _mm256_load_ps(bOut+n4+j); // RRRRRRRR
    __m256 a = _mm256_unpacklo_ps(x, y);  // LRLRLRLR
    __m256 b = _mm256_unpackhi_ps(x, y);  // LRLRLRLR
    _mm256_store_ps(outputBuffers+i, a);
    _mm256_store_ps(outputBuffers+8+i, b);
  }
  #elif HV_SIMD_SSE
  for (int i = 0, j = 0; j < n4; j += 4, i += 8) {
    __m128 x = _mm_load_ps(bOut+j);    // LLLL
    __m128 y = _mm_load_ps(bOut+n4+j); // RRRR
    __m128 a = _mm_unpacklo_ps(x, y);  // LRLR
    __m128 b = _mm_unpackhi_ps(x, y);  // LRLR
    _mm_store_ps(outputBuffers+i, a);
    _mm_store_ps(outputBuffers+4+i, b);
  }
  #elif HV_SIMD_NEON
  // https://community.arm.com/groups/processors/blog/2012/03/13/coding-for-neon--part-5-rearranging-vectors
  for (int i = 0, j = 0; j < n4; j += 4, i += 8) {
    float32x4_t x = vld1q_f32(bOut+j);
    float32x4_t y = vld1q_f32(bOut+n4+j);
    float32x4x2_t z = {x, y};
    vst2q_f32(outputBuffers+i, z); // interleave and store
  }
  #else // HV_SIMD_NONE
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < n4; ++j) {
      outputBuffers[i+2*j] = bOut[i*n4+j];
    }
  }
  #endif

  return n;
}

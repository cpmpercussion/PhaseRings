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
  numBytes += sRPole_init(&sRPole_zmgChI6k);
  numBytes += sDel1_init(&sDel1_hefnXSBE);
  numBytes += sSamphold_init(&sSamphold_EjWcv9KA);
  numBytes += sDel1_init(&sDel1_sOqRqJ7B);
  numBytes += sSamphold_init(&sSamphold_9QrdqH1g);
  numBytes += sTabread_init(&sTabread_C9ecPpbq, &hTable_ENQ9TLFR, false);
  numBytes += sTabread_init(&sTabread_Th7thTkq, &hTable_ENQ9TLFR, false);
  numBytes += sDel1_init(&sDel1_X0OAmIMc);
  numBytes += sSamphold_init(&sSamphold_RZftgFSf);
  numBytes += sDel1_init(&sDel1_Z7IpF8zq);
  numBytes += sSamphold_init(&sSamphold_hilgfVnI);
  numBytes += sTabread_init(&sTabread_ckBmIu1s, &hTable_ENQ9TLFR, false);
  numBytes += sTabread_init(&sTabread_ENryHyQb, &hTable_ENQ9TLFR, false);
  numBytes += sPhasor_k_init(&sPhasor_a7DCv1VX, 0.0f, sampleRate);
  numBytes += sRPole_init(&sRPole_34wQa56D);
  numBytes += sDel1_init(&sDel1_k7HxwGom);
  numBytes += sLine_init(&sLine_PE54GZBr);
  numBytes += sSample_init(&sSample_uvES4F4q);
  numBytes += sLine_init(&sLine_mroKF1MH);
  numBytes += sTabread_init(&sTabread_KllqsCaA, &hTable_teJVa6yG, false);
  numBytes += sTabread_init(&sTabread_8LcxcY9e, &hTable_teJVa6yG, false);
  numBytes += sLine_init(&sLine_im2TaAoE);
  numBytes += sLine_init(&sLine_bCXr4EvD);
  numBytes += sLine_init(&sLine_2dJXG7Q9);
  numBytes += sLine_init(&sLine_oDVE0pvn);
  numBytes += sLine_init(&sLine_vUDsrQ3I);
  numBytes += sTabread_init(&sTabread_VVNnBoCl, &hTable_teJVa6yG, false);
  numBytes += sTabread_init(&sTabread_RKhlvguZ, &hTable_teJVa6yG, false);
  numBytes += sLine_init(&sLine_Vy4vLllM);
  numBytes += sLine_init(&sLine_IvF9IHet);
  numBytes += sLine_init(&sLine_hevpodVb);
  numBytes += sLine_init(&sLine_e3XeXHT4);
  numBytes += sLine_init(&sLine_AC7yIQnV);
  numBytes += sTabread_init(&sTabread_teeVnAf5, &hTable_teJVa6yG, false);
  numBytes += sTabread_init(&sTabread_e9K0lSYN, &hTable_teJVa6yG, false);
  numBytes += sLine_init(&sLine_JA9nCj39);
  numBytes += sLine_init(&sLine_zrBuOQF3);
  numBytes += sLine_init(&sLine_GuV54yvL);
  numBytes += sLine_init(&sLine_2fh87dfQ);
  numBytes += sLine_init(&sLine_HxdbGcMn);
  numBytes += sTabread_init(&sTabread_roJt7v8z, &hTable_teJVa6yG, false);
  numBytes += sTabread_init(&sTabread_e2Vk1u9s, &hTable_teJVa6yG, false);
  numBytes += sLine_init(&sLine_TtHVnNvD);
  numBytes += sLine_init(&sLine_GY4Dkh1P);
  numBytes += sLine_init(&sLine_Qjb9MdFa);
  numBytes += sLine_init(&sLine_P3JxrZ3P);
  numBytes += sLine_init(&sLine_5kqe3ww4);
  numBytes += sLine_init(&sLine_clyHWvTj);
  numBytes += sLine_init(&sLine_RKUx47KF);
  numBytes += sLine_init(&sLine_G4tPG2mq);
  numBytes += sLine_init(&sLine_uGff1jyA);
  numBytes += sTabwrite_init(&sTabwrite_mqGmSwHE, &hTable_kwb3HxN8);
  numBytes += sLine_init(&sLine_C4j67utO);
  numBytes += sPhasor_init(&sPhasor_UBdDWePO, sampleRate);
  numBytes += sLine_init(&sLine_NWaIhvDv);
  numBytes += sLine_init(&sLine_QVlR4es3);
  numBytes += sTabhead_init(&sTabhead_wmv56ULT, &hTable_kwb3HxN8);
  numBytes += sTabread_init(&sTabread_t5rk7vDG, &hTable_kwb3HxN8, false);
  numBytes += sTabread_init(&sTabread_OAIFDd9S, &hTable_kwb3HxN8, false);
  numBytes += sTabhead_init(&sTabhead_V43ZtulN, &hTable_kwb3HxN8);
  numBytes += sTabread_init(&sTabread_uXUnhsRm, &hTable_kwb3HxN8, false);
  numBytes += sTabread_init(&sTabread_8gv4Ce1N, &hTable_kwb3HxN8, false);
  numBytes += sTabhead_init(&sTabhead_TTkKU5ki, &hTable_SFNzaQne);
  numBytes += sTabread_init(&sTabread_QXCP1TNP, &hTable_SFNzaQne, false);
  numBytes += sTabread_init(&sTabread_rRCO5RXp, &hTable_SFNzaQne, false);
  numBytes += sRPole_init(&sRPole_GWyzCVDt);
  numBytes += sDel1_init(&sDel1_vF2FTMWY);
  numBytes += sLine_init(&sLine_thLkgnxU);
  numBytes += sRPole_init(&sRPole_PfLVJPMS);
  numBytes += sTabwrite_init(&sTabwrite_8O0A9Pu4, &hTable_SFNzaQne);
  numBytes += sTabread_init(&sTabread_dj81ruJi, &hTable_BDlw4p4k, true);
  numBytes += sRPole_init(&sRPole_4Fcgcwvj);
  numBytes += sLine_init(&sLine_yWjVeTiD);
  numBytes += sLine_init(&sLine_a84zihT1);
  numBytes += sTabread_init(&sTabread_b9g38sSt, &hTable_78RfxJhK, true);
  numBytes += sTabread_init(&sTabread_CMXK6XqO, &hTable_rsyMKuWL, true);
  numBytes += sTabread_init(&sTabread_bghJeFu0, &hTable_VYf61oBw, true);
  numBytes += sTabread_init(&sTabread_BxCiE5Lx, &hTable_7NVE3FN1, true);
  numBytes += sTabread_init(&sTabread_PLCfNsd5, &hTable_TugJfLtQ, true);
  numBytes += sTabwrite_init(&sTabwrite_GVECn9lp, &hTable_DvofHMe4);
  numBytes += sTabwrite_init(&sTabwrite_YkTV5vwK, &hTable_TugJfLtQ);
  numBytes += sTabwrite_init(&sTabwrite_S6pGnhqD, &hTable_7NVE3FN1);
  numBytes += sTabwrite_init(&sTabwrite_i2nr6az6, &hTable_VYf61oBw);
  numBytes += sTabwrite_init(&sTabwrite_xOecdRP1, &hTable_rsyMKuWL);
  numBytes += sTabwrite_init(&sTabwrite_Xtx7SXZE, &hTable_78RfxJhK);
  numBytes += sTabread_init(&sTabread_3t5VJQw5, &hTable_DvofHMe4, true);
  numBytes += sTabread_init(&sTabread_Jt2pjvQn, &hTable_aZEd6ida, true);
  numBytes += sRPole_init(&sRPole_AUJUXxKr);
  numBytes += sTabread_init(&sTabread_MC2Hs4Y3, &hTable_Ua2nJmIp, true);
  numBytes += sRPole_init(&sRPole_kjyzw8dg);
  numBytes += sTabread_init(&sTabread_EPo9lqrA, &hTable_zGd0W84V, true);
  numBytes += sRPole_init(&sRPole_gJaRr4kH);
  numBytes += sTabwrite_init(&sTabwrite_eLj86jli, &hTable_BDlw4p4k);
  numBytes += sTabwrite_init(&sTabwrite_Ulp4BOlH, &hTable_aZEd6ida);
  numBytes += sTabwrite_init(&sTabwrite_X8BJe9P9, &hTable_Ua2nJmIp);
  numBytes += sTabwrite_init(&sTabwrite_Vjo3KuJ9, &hTable_zGd0W84V);
  numBytes += sLine_init(&sLine_lmi7kD9G);
  numBytes += sLine_init(&sLine_tk8fsAw0);
  numBytes += sTabwrite_init(&sTabwrite_PebHL3hD, &hTable_GndqmX2H);
  numBytes += sLine_init(&sLine_87ldDbSW);
  numBytes += sPhasor_init(&sPhasor_7LdFZlRq, sampleRate);
  numBytes += sLine_init(&sLine_YkiltBOq);
  numBytes += sLine_init(&sLine_jVKbQJy3);
  numBytes += sTabhead_init(&sTabhead_GsJWATQb, &hTable_GndqmX2H);
  numBytes += sTabread_init(&sTabread_tWNEUtBl, &hTable_GndqmX2H, false);
  numBytes += sTabread_init(&sTabread_ooGcIXkD, &hTable_GndqmX2H, false);
  numBytes += sTabhead_init(&sTabhead_ZW0ght7z, &hTable_GndqmX2H);
  numBytes += sTabread_init(&sTabread_kaWIefkE, &hTable_GndqmX2H, false);
  numBytes += sTabread_init(&sTabread_VJr9bQAJ, &hTable_GndqmX2H, false);
  numBytes += sTabhead_init(&sTabhead_IxAWa6aV, &hTable_Vs9lEBjn);
  numBytes += sTabread_init(&sTabread_UauKCSGb, &hTable_Vs9lEBjn, false);
  numBytes += sTabread_init(&sTabread_0QoJXrOz, &hTable_Vs9lEBjn, false);
  numBytes += sRPole_init(&sRPole_2PhyP4MO);
  numBytes += sDel1_init(&sDel1_mxNI4Q82);
  numBytes += sLine_init(&sLine_2mLrveBd);
  numBytes += sRPole_init(&sRPole_ABwrgtIP);
  numBytes += sTabwrite_init(&sTabwrite_Pb6uuJkx, &hTable_Vs9lEBjn);
  numBytes += sCPole_init(&sCPole_5TaKkrQ5);
  numBytes += sRPole_init(&sRPole_BhlVStKK);
  numBytes += sRPole_init(&sRPole_mNi4E67X);
  numBytes += sRPole_init(&sRPole_pCzFsLOI);
  numBytes += sTabread_init(&sTabread_RifD0f6y, &hTable_7LsDOYF6, true);
  numBytes += sRPole_init(&sRPole_gEGCTt1F);
  numBytes += sLine_init(&sLine_glSWgFyi);
  numBytes += sLine_init(&sLine_zusUuoW7);
  numBytes += sTabread_init(&sTabread_bYPtTgj3, &hTable_Vl2XxejY, true);
  numBytes += sTabread_init(&sTabread_6JoEa4Rx, &hTable_eI9c7xE2, true);
  numBytes += sTabread_init(&sTabread_hvXwyfuS, &hTable_8OBIMoeC, true);
  numBytes += sTabread_init(&sTabread_hwttHFZi, &hTable_UUU4p40c, true);
  numBytes += sTabread_init(&sTabread_ZypL9G2b, &hTable_caFOb0L8, true);
  numBytes += sTabwrite_init(&sTabwrite_5wohD85C, &hTable_X1sWepvN);
  numBytes += sTabwrite_init(&sTabwrite_xEqUPJcW, &hTable_caFOb0L8);
  numBytes += sTabwrite_init(&sTabwrite_1TF3Xi34, &hTable_UUU4p40c);
  numBytes += sTabwrite_init(&sTabwrite_65hrwXRR, &hTable_8OBIMoeC);
  numBytes += sTabwrite_init(&sTabwrite_q1nfTchJ, &hTable_eI9c7xE2);
  numBytes += sTabwrite_init(&sTabwrite_3OdrNL5D, &hTable_Vl2XxejY);
  numBytes += sTabread_init(&sTabread_cCPK1SxE, &hTable_X1sWepvN, true);
  numBytes += sTabread_init(&sTabread_3qjsq7ya, &hTable_tUav5lY2, true);
  numBytes += sRPole_init(&sRPole_oO0sNQsf);
  numBytes += sTabread_init(&sTabread_oVRZbKxD, &hTable_6R5an42N, true);
  numBytes += sRPole_init(&sRPole_JU8lSWfv);
  numBytes += sTabread_init(&sTabread_oaMZ0dHH, &hTable_rjOzbEZE, true);
  numBytes += sRPole_init(&sRPole_yqoCvbkZ);
  numBytes += sTabwrite_init(&sTabwrite_dvdnNiuf, &hTable_7LsDOYF6);
  numBytes += sTabwrite_init(&sTabwrite_fhb54cn5, &hTable_tUav5lY2);
  numBytes += sTabwrite_init(&sTabwrite_wGQCtqrr, &hTable_6R5an42N);
  numBytes += sTabwrite_init(&sTabwrite_QTTuUDMa, &hTable_rjOzbEZE);
  numBytes += sLine_init(&sLine_HhK41dBC);
  numBytes += sLine_init(&sLine_i5agM2D2);
  numBytes += sLine_init(&sLine_TWTetHHL);
  numBytes += cVar_init_s(&cVar_O8k01LXR, "floatatom");
  numBytes += cVar_init_f(&cVar_StYoNaJd, 98.0f);
  numBytes += cIf_init(&cIf_Ioz9s22C, false);
  numBytes += cBinop_init(&cBinop_hVBEV9CN, 0.0f); // __pow
  numBytes += cPack_init(&cPack_t45KCxyH, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_kAy81P4N, 0.0f);
  numBytes += cRandom_init(&cRandom_eRpMOh1l, -1364834871);
  numBytes += cSlice_init(&cSlice_KkDWnMgv, 1, 1);
  numBytes += cBinop_init(&cBinop_NSav0z2q, 1.0f); // __pow
  numBytes += cRandom_init(&cRandom_HK4oXe04, -1249094743);
  numBytes += cSlice_init(&cSlice_bLlUX3bT, 1, 1);
  numBytes += cSlice_init(&cSlice_xH1PcvAO, 1, 1);
  numBytes += cSlice_init(&cSlice_uixhqqOG, 0, 1);
  numBytes += cPack_init(&cPack_CafWK5oZ, 2, 0.0f, 10.0f);
  numBytes += cPack_init(&cPack_xVnqfZIu, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_rrmykqSu, 0.0f);
  numBytes += cDelay_init(this, &cDelay_WVwnSGvF, 25.0f);
  numBytes += cVar_init_f(&cVar_6XFtM8oq, 0.0f);
  numBytes += sVarf_init(&sVarf_ajkQXhqq, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_J4eHOjeW, "crotale");
  numBytes += cSlice_init(&cSlice_ZZ3HhSkJ, 1, 1);
  numBytes += sVarf_init(&sVarf_5hl3G6sl, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_RtlGDBzB, 0.0f);
  numBytes += cVar_init_f(&cVar_qpZFqbst, 1.0f);
  numBytes += cIf_init(&cIf_MZg0SU5F, false);
  numBytes += cVar_init_f(&cVar_RApaYfeB, 1.0f);
  numBytes += cVar_init_f(&cVar_KotIcBWk, 0.0f);
  numBytes += cDelay_init(this, &cDelay_FNbsubLf, 2.0f);
  numBytes += cPack_init(&cPack_2pIV6F5w, 2, 0.0f, 0.0f);
  numBytes += cDelay_init(this, &cDelay_eJiuDJqr, 0.0f);
  numBytes += cDelay_init(this, &cDelay_kRjgB4kN, 2.0f);
  numBytes += cPack_init(&cPack_FtcNOzmc, 2, 0.0f, 0.0f);
  numBytes += cPack_init(&cPack_X5fEAV4y, 2, 0.0f, 2.0f);
  numBytes += cPack_init(&cPack_CsLjerEM, 2, 0.0f, 2.0f);
  numBytes += cVar_init_f(&cVar_oc7CZsKi, 0.0f);
  numBytes += cVar_init_f(&cVar_TQ2qr3Xw, 1.0f);
  numBytes += cPack_init(&cPack_fNevwtaB, 2, 0.0f, 0.0f);
  numBytes += cSlice_init(&cSlice_Ipk1vL7j, 1, 1);
  numBytes += cSlice_init(&cSlice_RsvFBTCW, 0, 1);
  numBytes += cSlice_init(&cSlice_vEfdKSmY, 1, 1);
  numBytes += cSlice_init(&cSlice_1PJ1b071, 0, 1);
  numBytes += cPack_init(&cPack_ll00wYEj, 2, 0.0f, 441000000.0f);
  numBytes += cPack_init(&cPack_YBvHZ5HH, 2, 0.0f, -441000000.0f);
  numBytes += cBinop_init(&cBinop_j8DWn77o, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_jEp7it3T, 2.0f); // __sub
  numBytes += cBinop_init(&cBinop_nEFwvtYt, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_5aCja6rV, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_xpTLUpRi, 44.1f); // __mul
  numBytes += cSlice_init(&cSlice_10HamewP, 5, 1);
  numBytes += cSlice_init(&cSlice_zE389FZN, 4, 1);
  numBytes += cSlice_init(&cSlice_3ZC90v6W, 3, 1);
  numBytes += cSlice_init(&cSlice_pRepDomy, 2, 1);
  numBytes += cSlice_init(&cSlice_spWHApFp, 1, 1);
  numBytes += cSlice_init(&cSlice_ACr5PHjA, 0, 1);
  numBytes += cSlice_init(&cSlice_Eu3wobdY, 1, 1);
  numBytes += cSlice_init(&cSlice_LVXCfAfn, 0, 1);
  numBytes += cPack_init(&cPack_Tq5AG5UD, 2, 0.0f, 0.0f);
  numBytes += cVar_init_s(&cVar_uSFpDnDg, "floatatom");
  numBytes += cSlice_init(&cSlice_7ztOTE0T, 1, 1);
  numBytes += cSlice_init(&cSlice_UDrlqyix, 0, 1);
  numBytes += cBinop_init(&cBinop_J7pBN7Ic, 10000.0f); // __mul
  numBytes += cBinop_init(&cBinop_b6AWpUpP, 10000.0f); // __mul
  numBytes += cSlice_init(&cSlice_bTZvq2Q6, 1, 1);
  numBytes += cSlice_init(&cSlice_X1xg4S0T, 0, 1);
  numBytes += cVar_init_f(&cVar_fWyob0BP, 0.0f);
  numBytes += cVar_init_f(&cVar_O14krN9r, 1.0f);
  numBytes += cPack_init(&cPack_fxOvKXea, 3, 0.0f, 0.0f, 0.0f);
  numBytes += cBinop_init(&cBinop_jpvTQ23W, 1.0f); // __mul
  numBytes += cBinop_init(&cBinop_d0IYt5DF, 0.0f); // __div
  numBytes += cRandom_init(&cRandom_aNGIPKtI, 802318274);
  numBytes += cSlice_init(&cSlice_04mY4PiZ, 1, 1);
  numBytes += cBinop_init(&cBinop_gjIXCRlq, 1.0f); // __pow
  numBytes += cRandom_init(&cRandom_MPodtBWR, -1585841576);
  numBytes += cSlice_init(&cSlice_FhCXbuPJ, 1, 1);
  numBytes += cSlice_init(&cSlice_JpbPnq7o, 1, 1);
  numBytes += cSlice_init(&cSlice_TrBGFBQn, 0, 1);
  numBytes += cPack_init(&cPack_ywJFQ3AM, 2, 0.0f, 10.0f);
  numBytes += cPack_init(&cPack_SbjKVBag, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_py55N7Ov, 0.0f);
  numBytes += cDelay_init(this, &cDelay_o797bv2q, 25.0f);
  numBytes += cVar_init_f(&cVar_yjQBMTRF, 0.0f);
  numBytes += sVarf_init(&sVarf_i5uSVJmz, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_33TIBgYM, "crotale");
  numBytes += cSlice_init(&cSlice_akvWdkUf, 1, 1);
  numBytes += sVarf_init(&sVarf_WyRbmsYM, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_KPNKEGI6, 0.0f);
  numBytes += cVar_init_f(&cVar_pgdapD11, 1.0f);
  numBytes += cIf_init(&cIf_VeeDnSqp, false);
  numBytes += cVar_init_f(&cVar_55Q3cf9F, 1.0f);
  numBytes += cVar_init_f(&cVar_NPVSjjQp, 0.0f);
  numBytes += cDelay_init(this, &cDelay_Y1Ldvfgx, 2.0f);
  numBytes += cPack_init(&cPack_fv8q4ynA, 2, 0.0f, 0.0f);
  numBytes += cDelay_init(this, &cDelay_IdLEcmj0, 0.0f);
  numBytes += cDelay_init(this, &cDelay_C9wFeNw7, 2.0f);
  numBytes += cPack_init(&cPack_cb6HbLyS, 2, 0.0f, 0.0f);
  numBytes += cPack_init(&cPack_tpzyTrBc, 2, 0.0f, 2.0f);
  numBytes += cPack_init(&cPack_mtB46fWX, 2, 0.0f, 2.0f);
  numBytes += cVar_init_f(&cVar_dphh1rEn, 0.0f);
  numBytes += cVar_init_f(&cVar_4LyPXZrS, 1.0f);
  numBytes += cPack_init(&cPack_fe8EG0PJ, 2, 0.0f, 0.0f);
  numBytes += cSlice_init(&cSlice_NS1EWbah, 1, 1);
  numBytes += cSlice_init(&cSlice_8fvTjkys, 0, 1);
  numBytes += cSlice_init(&cSlice_ml782NaG, 1, 1);
  numBytes += cSlice_init(&cSlice_njaArJ8J, 0, 1);
  numBytes += cPack_init(&cPack_tNmyHW7N, 2, 0.0f, 441000000.0f);
  numBytes += cPack_init(&cPack_X1AiotjA, 2, 0.0f, -441000000.0f);
  numBytes += cBinop_init(&cBinop_yQjKfd9L, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_g78aXXDa, 2.0f); // __sub
  numBytes += cBinop_init(&cBinop_bSyFpmLK, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_LU4SqPa9, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_SfHhnon1, 44.1f); // __mul
  numBytes += cSlice_init(&cSlice_SH7sAkGK, 5, 1);
  numBytes += cSlice_init(&cSlice_3KUbv5pL, 4, 1);
  numBytes += cSlice_init(&cSlice_jLpSeOM5, 3, 1);
  numBytes += cSlice_init(&cSlice_r7XmmRWB, 2, 1);
  numBytes += cSlice_init(&cSlice_GMT7DeWn, 1, 1);
  numBytes += cSlice_init(&cSlice_fqzBitNk, 0, 1);
  numBytes += cSlice_init(&cSlice_S2wPoZju, 1, 1);
  numBytes += cSlice_init(&cSlice_cwh30pIu, 0, 1);
  numBytes += cPack_init(&cPack_wC1rXIon, 2, 0.0f, 0.0f);
  numBytes += cVar_init_s(&cVar_LBO772qc, "floatatom");
  numBytes += cSlice_init(&cSlice_X9dFCfGi, 1, 1);
  numBytes += cSlice_init(&cSlice_83WO8NMr, 0, 1);
  numBytes += cBinop_init(&cBinop_V0d3TTgb, 10000.0f); // __mul
  numBytes += cBinop_init(&cBinop_Yjb9lhHA, 10000.0f); // __mul
  numBytes += cSlice_init(&cSlice_XGiwhxDP, 1, 1);
  numBytes += cSlice_init(&cSlice_LeeZKd24, 0, 1);
  numBytes += cVar_init_f(&cVar_dRJoBjiU, 0.0f);
  numBytes += cVar_init_f(&cVar_boSonE4l, 1.0f);
  numBytes += cPack_init(&cPack_zwii0lPP, 3, 0.0f, 0.0f, 0.0f);
  numBytes += cBinop_init(&cBinop_m6inSF8a, 1.0f); // __mul
  numBytes += cBinop_init(&cBinop_rs14SgKQ, 0.0f); // __div
  numBytes += cRandom_init(&cRandom_JnTQZFju, -900312542);
  numBytes += cSlice_init(&cSlice_KhBwgPNG, 1, 1);
  numBytes += cBinop_init(&cBinop_IJ60b2Rh, 1.0f); // __pow
  numBytes += cRandom_init(&cRandom_ihFMj5cS, -1446700974);
  numBytes += cSlice_init(&cSlice_xYCcPSeP, 1, 1);
  numBytes += cSlice_init(&cSlice_qBXnUcR4, 1, 1);
  numBytes += cSlice_init(&cSlice_cSjjEiCm, 0, 1);
  numBytes += cPack_init(&cPack_XN6Ia42e, 2, 0.0f, 10.0f);
  numBytes += cPack_init(&cPack_pFdbxRaA, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_lZjdGFHS, 0.0f);
  numBytes += cDelay_init(this, &cDelay_mABdZ2AB, 25.0f);
  numBytes += cVar_init_f(&cVar_x2FyupTW, 0.0f);
  numBytes += sVarf_init(&sVarf_dMM8Pk4r, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_zVNxjGY9, "crotale");
  numBytes += cSlice_init(&cSlice_gCCvqliF, 1, 1);
  numBytes += sVarf_init(&sVarf_5vbSjb3z, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_iuVpGF7e, 0.0f);
  numBytes += cVar_init_f(&cVar_b43vKyAV, 1.0f);
  numBytes += cIf_init(&cIf_o9JRawQV, false);
  numBytes += cVar_init_f(&cVar_VBFU3Haf, 1.0f);
  numBytes += cVar_init_f(&cVar_wtANnlDz, 0.0f);
  numBytes += cDelay_init(this, &cDelay_0UZDIhlT, 2.0f);
  numBytes += cPack_init(&cPack_itfmeIXz, 2, 0.0f, 0.0f);
  numBytes += cDelay_init(this, &cDelay_ohRZNwRJ, 0.0f);
  numBytes += cDelay_init(this, &cDelay_4DWQ6dTC, 2.0f);
  numBytes += cPack_init(&cPack_E8COPE7k, 2, 0.0f, 0.0f);
  numBytes += cPack_init(&cPack_J5q7sQ5W, 2, 0.0f, 2.0f);
  numBytes += cPack_init(&cPack_9uoQwgtp, 2, 0.0f, 2.0f);
  numBytes += cVar_init_f(&cVar_ZL2NtQkw, 0.0f);
  numBytes += cVar_init_f(&cVar_cCq9U32x, 1.0f);
  numBytes += cPack_init(&cPack_aRU3bjzn, 2, 0.0f, 0.0f);
  numBytes += cSlice_init(&cSlice_060v7k4E, 1, 1);
  numBytes += cSlice_init(&cSlice_GEUTtpjf, 0, 1);
  numBytes += cSlice_init(&cSlice_h4FOeNEG, 1, 1);
  numBytes += cSlice_init(&cSlice_yU4FZwGD, 0, 1);
  numBytes += cPack_init(&cPack_UH95E8FT, 2, 0.0f, 441000000.0f);
  numBytes += cPack_init(&cPack_i65kIUnR, 2, 0.0f, -441000000.0f);
  numBytes += cBinop_init(&cBinop_LSuSl3Tn, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_9uliDmoL, 2.0f); // __sub
  numBytes += cBinop_init(&cBinop_rFhHdy3I, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_GZOBW3aB, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_Lt6LUj4q, 44.1f); // __mul
  numBytes += cSlice_init(&cSlice_yhExvdEj, 5, 1);
  numBytes += cSlice_init(&cSlice_tGwGnzhZ, 4, 1);
  numBytes += cSlice_init(&cSlice_IKY7JfI0, 3, 1);
  numBytes += cSlice_init(&cSlice_LuAhS2m6, 2, 1);
  numBytes += cSlice_init(&cSlice_URnynw7Z, 1, 1);
  numBytes += cSlice_init(&cSlice_iIHsriNg, 0, 1);
  numBytes += cSlice_init(&cSlice_5ylQh6US, 1, 1);
  numBytes += cSlice_init(&cSlice_5FtWk7tO, 0, 1);
  numBytes += cPack_init(&cPack_pvZFOWUZ, 2, 0.0f, 0.0f);
  numBytes += cVar_init_s(&cVar_6D4UXtLi, "floatatom");
  numBytes += cSlice_init(&cSlice_2wry0N4X, 1, 1);
  numBytes += cSlice_init(&cSlice_BHZPbfCO, 0, 1);
  numBytes += cBinop_init(&cBinop_9EDLXK5E, 10000.0f); // __mul
  numBytes += cBinop_init(&cBinop_IkajEG6G, 10000.0f); // __mul
  numBytes += cSlice_init(&cSlice_7y2iSHU6, 1, 1);
  numBytes += cSlice_init(&cSlice_zdiBQKnD, 0, 1);
  numBytes += cVar_init_f(&cVar_sqaPBYhh, 0.0f);
  numBytes += cVar_init_f(&cVar_LTitF40t, 1.0f);
  numBytes += cPack_init(&cPack_vRHMX787, 3, 0.0f, 0.0f, 0.0f);
  numBytes += cBinop_init(&cBinop_IGlwP67w, 1.0f); // __mul
  numBytes += cBinop_init(&cBinop_6AC6W0C9, 0.0f); // __div
  numBytes += cRandom_init(&cRandom_nS87wgcH, -886445865);
  numBytes += cSlice_init(&cSlice_LIJIkpHL, 1, 1);
  numBytes += cBinop_init(&cBinop_pw5TfvuW, 1.0f); // __pow
  numBytes += cRandom_init(&cRandom_LzSrMaOs, -1952718724);
  numBytes += cSlice_init(&cSlice_f8HBLFa2, 1, 1);
  numBytes += cSlice_init(&cSlice_v4S319M7, 1, 1);
  numBytes += cSlice_init(&cSlice_qtZG4vQY, 0, 1);
  numBytes += cPack_init(&cPack_baediq0f, 2, 0.0f, 10.0f);
  numBytes += cPack_init(&cPack_dlnf1mZs, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_VRVw4P4A, 0.0f);
  numBytes += cDelay_init(this, &cDelay_QbD9NQRN, 25.0f);
  numBytes += cVar_init_f(&cVar_bR9za15E, 0.0f);
  numBytes += sVarf_init(&sVarf_Z6OROFjn, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_ozAWR6jV, "crotale");
  numBytes += cSlice_init(&cSlice_qHuDRc3x, 1, 1);
  numBytes += sVarf_init(&sVarf_JWj8QhxO, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_S1cZ0Gnq, 0.0f);
  numBytes += cVar_init_f(&cVar_GvztUjBL, 1.0f);
  numBytes += cIf_init(&cIf_iPPySbbO, false);
  numBytes += cVar_init_f(&cVar_CuYJi230, 1.0f);
  numBytes += cVar_init_f(&cVar_z34jc0Np, 0.0f);
  numBytes += cDelay_init(this, &cDelay_Js39jhV4, 2.0f);
  numBytes += cPack_init(&cPack_jGGNTkzv, 2, 0.0f, 0.0f);
  numBytes += cDelay_init(this, &cDelay_lkIOOjY4, 0.0f);
  numBytes += cDelay_init(this, &cDelay_q7rXjGjp, 2.0f);
  numBytes += cPack_init(&cPack_uWbDOps4, 2, 0.0f, 0.0f);
  numBytes += cPack_init(&cPack_dmAFTH8T, 2, 0.0f, 2.0f);
  numBytes += cPack_init(&cPack_baUqD3UH, 2, 0.0f, 2.0f);
  numBytes += cVar_init_f(&cVar_QGpCpm3d, 0.0f);
  numBytes += cVar_init_f(&cVar_K22Bzlg3, 1.0f);
  numBytes += cPack_init(&cPack_42rxGRaF, 2, 0.0f, 0.0f);
  numBytes += cSlice_init(&cSlice_x2BBRT6i, 1, 1);
  numBytes += cSlice_init(&cSlice_RXio1ALa, 0, 1);
  numBytes += cSlice_init(&cSlice_ukHzN9OE, 1, 1);
  numBytes += cSlice_init(&cSlice_FrciKGe7, 0, 1);
  numBytes += cPack_init(&cPack_R5IdV5Yw, 2, 0.0f, 441000000.0f);
  numBytes += cPack_init(&cPack_2DxqkVEV, 2, 0.0f, -441000000.0f);
  numBytes += cBinop_init(&cBinop_pKjoSEia, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_TbdAnVia, 2.0f); // __sub
  numBytes += cBinop_init(&cBinop_SGkGiMXg, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_BTwTVWFi, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_KD8gQJzK, 44.1f); // __mul
  numBytes += cSlice_init(&cSlice_gowVA5Bs, 5, 1);
  numBytes += cSlice_init(&cSlice_DmVQ9c44, 4, 1);
  numBytes += cSlice_init(&cSlice_Lc78Dhw2, 3, 1);
  numBytes += cSlice_init(&cSlice_DUkgjMAc, 2, 1);
  numBytes += cSlice_init(&cSlice_V0qKurPu, 1, 1);
  numBytes += cSlice_init(&cSlice_TDgrepgv, 0, 1);
  numBytes += cSlice_init(&cSlice_Hok53Qfa, 1, 1);
  numBytes += cSlice_init(&cSlice_2IFqOvKW, 0, 1);
  numBytes += cPack_init(&cPack_CFSB7hbZ, 2, 0.0f, 0.0f);
  numBytes += cVar_init_s(&cVar_JGRtxMXi, "floatatom");
  numBytes += cSlice_init(&cSlice_q7FVdqSl, 1, 1);
  numBytes += cSlice_init(&cSlice_JcLZjbjv, 0, 1);
  numBytes += cBinop_init(&cBinop_bg8bWn5I, 10000.0f); // __mul
  numBytes += cBinop_init(&cBinop_kqZTZO7V, 10000.0f); // __mul
  numBytes += cSlice_init(&cSlice_i2FuKAyH, 1, 1);
  numBytes += cSlice_init(&cSlice_E5Bh3Ute, 0, 1);
  numBytes += cVar_init_f(&cVar_DF3DdT7c, 0.0f);
  numBytes += cVar_init_f(&cVar_COTqQ4YD, 1.0f);
  numBytes += cPack_init(&cPack_DDFTP4p0, 3, 0.0f, 0.0f, 0.0f);
  numBytes += cBinop_init(&cBinop_hCq5HwWL, 1.0f); // __mul
  numBytes += cBinop_init(&cBinop_bBobFv06, 0.0f); // __div
  numBytes += cVar_init_f(&cVar_juT2JvKY, 98.0f);
  numBytes += cIf_init(&cIf_uAOkPRSf, false);
  numBytes += cBinop_init(&cBinop_Le3D7rpF, 0.0f); // __pow
  numBytes += cPack_init(&cPack_zujddLT8, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_5datEgv1, 0.0f);
  numBytes += cVar_init_f(&cVar_KMuYXZjJ, 100.0f);
  numBytes += cIf_init(&cIf_lmuhSOl4, false);
  numBytes += cBinop_init(&cBinop_yabpxvBe, 0.0f); // __pow
  numBytes += cPack_init(&cPack_rehIwvM0, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_SccN7krs, 0.0f);
  numBytes += cIf_init(&cIf_vwUzXcdB, false);
  numBytes += cVar_init_f(&cVar_Xd4TaDWV, 97.0f);
  numBytes += cIf_init(&cIf_d5BprS40, false);
  numBytes += cBinop_init(&cBinop_DIoEm4CM, 0.0f); // __pow
  numBytes += cPack_init(&cPack_tSUDMHK5, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_x2unxKzg, 0.0f);
  numBytes += cVar_init_f(&cVar_wMSka1wE, 97.0f);
  numBytes += cIf_init(&cIf_8MGBv1cP, false);
  numBytes += cBinop_init(&cBinop_D8IwbAIq, 0.0f); // __pow
  numBytes += cPack_init(&cPack_sIRtwrnC, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_J5dGcJlH, 0.0f);
  numBytes += cPack_init(&cPack_U63jsgqi, 2, 0.0f, 0.0f);
  numBytes += cSlice_init(&cSlice_qpanm8m2, 1, 1);
  numBytes += cSlice_init(&cSlice_4rCkqgSs, 0, 1);
  numBytes += cIf_init(&cIf_DBwntGhY, false);
  numBytes += cIf_init(&cIf_eJxcLW7r, false);
  numBytes += cIf_init(&cIf_yuBQ3VPY, false);
  numBytes += cSlice_init(&cSlice_Bt0DMSSQ, 1, 1);
  numBytes += cSlice_init(&cSlice_28n9SgzZ, 0, 1);
  numBytes += cVar_init_f(&cVar_9TG72Op6, 0.0f);
  numBytes += cIf_init(&cIf_xsvBn3go, false);
  numBytes += cPack_init(&cPack_FLvP6J69, 2, 0.0f, 0.0f);
  numBytes += cSlice_init(&cSlice_LNYDHvvL, 1, -1);
  numBytes += cSlice_init(&cSlice_8B7GxxK8, 1, -1);
  numBytes += cSlice_init(&cSlice_K8C5Iwgt, 1, -1);
  numBytes += cSlice_init(&cSlice_Dvng9pSx, 1, -1);
  numBytes += cIf_init(&cIf_RXiZj7W8, false);
  numBytes += cVar_init_f(&cVar_n4P3YVaA, 1.0f);
  numBytes += cPack_init(&cPack_fneOoWBx, 3, 0.0f, 0.0f, 0.0f);
  numBytes += cVar_init_f(&cVar_IbDOdfOW, 0.0f);
  numBytes += hTable_init(&hTable_oWR8pmBA, 36000);
  numBytes += hTable_init(&hTable_teJVa6yG, 290000);
  numBytes += hTable_init(&hTable_JomIt6y9, 288000);
  numBytes += hTable_init(&hTable_nOD1MkVi, 66000);
  numBytes += hTable_init(&hTable_AV8Uleub, 25000);
  numBytes += hTable_init(&hTable_xc853M9T, 384000);
  numBytes += cSlice_init(&cSlice_w8Nr3ubL, 2, 1);
  numBytes += cSlice_init(&cSlice_vTqCAAmK, 1, 1);
  numBytes += cSlice_init(&cSlice_13dGuUl1, 0, 1);
  numBytes += cVar_init_f(&cVar_k3N7iSoe, 0.0f);
  numBytes += cIf_init(&cIf_0gv1krso, false);
  numBytes += cIf_init(&cIf_K7JnV13y, false);
  numBytes += cIf_init(&cIf_o3j6rvhJ, false);
  numBytes += cIf_init(&cIf_TIhHmKuO, false);
  numBytes += cIf_init(&cIf_WGtML1W1, false);
  numBytes += cBinop_init(&cBinop_D41EENlH, 0.0f); // __eq
  numBytes += cRandom_init(&cRandom_TIx4K0o4, -947062851);
  numBytes += cSlice_init(&cSlice_740gNqWB, 1, 1);
  numBytes += cRandom_init(&cRandom_y2L6VOK5, -2122091703);
  numBytes += cSlice_init(&cSlice_5E8B9DNo, 1, 1);
  numBytes += cRandom_init(&cRandom_RRw0yKLK, 1679426192);
  numBytes += cSlice_init(&cSlice_zbZuNIKy, 1, 1);
  numBytes += cVar_init_s(&cVar_h0Wb04ot, "floatatom");
  numBytes += cPack_init(&cPack_qrlXgzV2, 2, 0.0f, 200.0f);
  numBytes += cPack_init(&cPack_YTI2wDDT, 2, 0.0f, 200.0f);
  numBytes += cVar_init_s(&cVar_U0QPmYjI, "floatatom");
  numBytes += cDelay_init(this, &cDelay_E3oQ8e6G, 0.0f);
  numBytes += cDelay_init(this, &cDelay_OF0IZkmp, 0.0f);
  numBytes += hTable_init(&hTable_kwb3HxN8, 256);
  numBytes += cVar_init_s(&cVar_rcjf3SDj, "del-1220-del");
  numBytes += sVarf_init(&sVarf_loioO01H, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_Ftw3ql1o, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_e2Zzds5I, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_23iyp1fg, "del-1220-del");
  numBytes += sVarf_init(&sVarf_6gTTdqqR, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_atbmY5Dv, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_h3K6ScRe, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_gA5B5gkb, 0.0f); // __div
  numBytes += cVar_init_s(&cVar_e77iYaUb, "del-1249-del1");
  numBytes += sVarf_init(&sVarf_IILCOUkj, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_eGBesSoR, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_xdWOs8ll, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_1OAzPySG, 10000.0f);
  numBytes += cBinop_init(&cBinop_HuQSXYR4, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_WWRtHYUq, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_fEfALegh, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_toE901Wj, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_JFI1M2Kw, 10.0f);
  numBytes += cBinop_init(&cBinop_tOuNgEAN, 0.0f); // __div
  numBytes += sVarf_init(&sVarf_5pgMUuSl, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_r3nNffBh, "floatatom");
  numBytes += sVarf_init(&sVarf_8VQ2N8Ei, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_IfEdnP6q, 0.0f);
  numBytes += cDelay_init(this, &cDelay_fcgarXxo, 0.0f);
  numBytes += hTable_init(&hTable_SFNzaQne, 256);
  numBytes += sVarf_init(&sVarf_wg4UNVk3, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_mNeNzRqT, "floatatom");
  numBytes += cDelay_init(this, &cDelay_jNEeoJAh, 0.0f);
  numBytes += cVar_init_f(&cVar_iIjBEoKw, 20.0f);
  numBytes += cBinop_init(&cBinop_N06H1oWB, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_rj2uM0X5, 0.0f);
  numBytes += cSlice_init(&cSlice_2fCZljHc, 1, -1);
  numBytes += cSlice_init(&cSlice_fDlFPg7r, 1, -1);
  numBytes += cVar_init_f(&cVar_uX9tK8Mz, 0.0f);
  numBytes += cVar_init_f(&cVar_k7NHxPuo, 20.0f);
  numBytes += cVar_init_f(&cVar_8kmKr67X, 0.0f);
  numBytes += cVar_init_f(&cVar_4AoArzfL, 0.0f);
  numBytes += cVar_init_f(&cVar_ipT94t5z, 0.0f);
  numBytes += cSlice_init(&cSlice_N68AgZWY, 1, 1);
  numBytes += cSlice_init(&cSlice_vR4uxQmU, 0, 1);
  numBytes += cBinop_init(&cBinop_0m4IcsLg, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_mWS7l2Qv, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_yg2x9tLj, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_UHKFDNAE, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_5M00dT5c, 20.0f); // __div
  numBytes += cBinop_init(&cBinop_UUe1Ai2h, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_IRBrqjx8, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_rtQjLxJs, 0.0f); // __sub
  numBytes += cVar_init_s(&cVar_ZQtf2nwS, "floatatom");
  numBytes += cPack_init(&cPack_gbbxVdnG, 2, 0.0f, 1000.0f);
  numBytes += cDelay_init(this, &cDelay_gGRG7G4A, 0.0f);
  numBytes += cVar_init_f(&cVar_9PxGGMkN, 20.0f);
  numBytes += cBinop_init(&cBinop_lwipBM0s, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_XkXmCuDR, 0.0f);
  numBytes += cSlice_init(&cSlice_PBZSVtit, 1, -1);
  numBytes += cSlice_init(&cSlice_XEJnjcPU, 1, -1);
  numBytes += cVar_init_f(&cVar_GQwtc3qh, 0.0f);
  numBytes += cVar_init_f(&cVar_uG4H4pOF, 20.0f);
  numBytes += cVar_init_f(&cVar_gssQJxMj, 0.0f);
  numBytes += cVar_init_f(&cVar_iPKqDrRJ, 0.0f);
  numBytes += cVar_init_f(&cVar_OgGmOEXI, 0.0f);
  numBytes += cSlice_init(&cSlice_UP0Amu02, 1, 1);
  numBytes += cSlice_init(&cSlice_Yv5dP9Xr, 0, 1);
  numBytes += cBinop_init(&cBinop_vdY2YYdY, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_LTUG6e9t, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_jQZcFwvg, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_JWVh3bLc, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_fkItBcQK, 20.0f); // __div
  numBytes += cBinop_init(&cBinop_Zs0TFRUg, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_U744s2dN, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_eK3dGTiz, 0.0f); // __sub
  numBytes += cPack_init(&cPack_Ys1KLikb, 2, 0.0f, 1000.0f);
  numBytes += cPack_init(&cPack_f73hkHp6, 2, 0.0f, 1000.0f);
  numBytes += cTabhead_init(&cTabhead_qVF37Eil, &hTable_BDlw4p4k);
  numBytes += cVar_init_s(&cVar_DHRgYpdP, "del-1310-del1");
  numBytes += cDelay_init(this, &cDelay_TkVADJRj, 58.6435f);
  numBytes += cDelay_init(this, &cDelay_Jlyfl0bb, 0.0f);
  numBytes += cBinop_init(&cBinop_H7AlOLFR, 58.6435f); // __mul
  numBytes += cBinop_init(&cBinop_TNVNqReS, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_AFLy0EnA, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_IyVswin5, 0.0f); // __sub
  numBytes += cTabhead_init(&cTabhead_oqVCEBbQ, &hTable_aZEd6ida);
  numBytes += cVar_init_s(&cVar_t8P3L1EW, "del-1310-del2");
  numBytes += cDelay_init(this, &cDelay_gLUeKYtU, 69.4325f);
  numBytes += cDelay_init(this, &cDelay_V8XTvG9l, 0.0f);
  numBytes += cBinop_init(&cBinop_MX8pfgWp, 69.4325f); // __mul
  numBytes += cBinop_init(&cBinop_wt9QCutb, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_lTOGjWd9, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_pOmf6gqL, 0.0f); // __sub
  numBytes += cTabhead_init(&cTabhead_neDLBLlx, &hTable_Ua2nJmIp);
  numBytes += cVar_init_s(&cVar_HqrDdm4K, "del-1310-del3");
  numBytes += cDelay_init(this, &cDelay_aeMDgzWH, 74.5234f);
  numBytes += cDelay_init(this, &cDelay_S6UjVzAR, 0.0f);
  numBytes += cBinop_init(&cBinop_SOYyPH1l, 74.5234f); // __mul
  numBytes += cBinop_init(&cBinop_6s8Sg1Cu, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_YATcnKsm, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_DmO8gvNF, 0.0f); // __sub
  numBytes += cTabhead_init(&cTabhead_nmlLjw0L, &hTable_zGd0W84V);
  numBytes += cVar_init_s(&cVar_mlMz6f9p, "del-1310-del4");
  numBytes += cDelay_init(this, &cDelay_8oqwsESb, 86.1244f);
  numBytes += cDelay_init(this, &cDelay_oDEWjQ3T, 0.0f);
  numBytes += cBinop_init(&cBinop_2t9qZSK8, 86.1244f); // __mul
  numBytes += cBinop_init(&cBinop_wq6KmTcC, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_IVq712Zu, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_E1QaerUg, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_jwqyWtId, 0.0f);
  numBytes += cDelay_init(this, &cDelay_vWDNwy1w, 0.0f);
  numBytes += hTable_init(&hTable_BDlw4p4k, 256);
  numBytes += cDelay_init(this, &cDelay_9R8hII4k, 0.0f);
  numBytes += cDelay_init(this, &cDelay_EZcoAr7y, 0.0f);
  numBytes += hTable_init(&hTable_aZEd6ida, 256);
  numBytes += cDelay_init(this, &cDelay_xjA8dIDl, 0.0f);
  numBytes += cDelay_init(this, &cDelay_OSgYrk2I, 0.0f);
  numBytes += hTable_init(&hTable_Ua2nJmIp, 256);
  numBytes += cDelay_init(this, &cDelay_wCoY3zJq, 0.0f);
  numBytes += cDelay_init(this, &cDelay_9YTjERv9, 0.0f);
  numBytes += hTable_init(&hTable_zGd0W84V, 256);
  numBytes += cIf_init(&cIf_aQvTScCH, false);
  numBytes += cBinop_init(&cBinop_zBNhWJN1, 0.0f); // __pow
  numBytes += cPack_init(&cPack_y9dIYkvo, 2, 0.0f, 30.0f);
  numBytes += cPack_init(&cPack_HDF4aKkM, 2, 0.0f, 50.0f);
  numBytes += cVar_init_f(&cVar_5mTuFX24, 22050.0f);
  numBytes += cBinop_init(&cBinop_P43d7ZAS, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_Ok1oEGU1, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_icJKbmbr, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_uHprLQ22, 95.0f);
  numBytes += cVar_init_f(&cVar_NDxUjmjF, 90.0f);
  numBytes += cVar_init_f(&cVar_NEr1rfD8, 6000.0f);
  numBytes += cVar_init_f(&cVar_OJ2tXarU, 60.0f);
  numBytes += cIf_init(&cIf_kmQGICQe, false);
  numBytes += cTabhead_init(&cTabhead_yGPTgMHi, &hTable_DvofHMe4);
  numBytes += cVar_init_s(&cVar_oo9Oo4OI, "del-1310-ref6");
  numBytes += cDelay_init(this, &cDelay_xzfeE3J3, 13.645f);
  numBytes += cDelay_init(this, &cDelay_AmnrjBrE, 0.0f);
  numBytes += cBinop_init(&cBinop_KxgtqBiR, 13.645f); // __mul
  numBytes += cBinop_init(&cBinop_cGhAIxcv, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_6jn0ZkUH, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_P5FTVuwl, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_seFX0RIx, 0.0f);
  numBytes += cDelay_init(this, &cDelay_Gc9EsfL4, 0.0f);
  numBytes += hTable_init(&hTable_DvofHMe4, 256);
  numBytes += cTabhead_init(&cTabhead_2ogH3jPz, &hTable_TugJfLtQ);
  numBytes += cVar_init_s(&cVar_go6JxS6N, "del-1310-ref5");
  numBytes += cDelay_init(this, &cDelay_dFBR9Idg, 16.364f);
  numBytes += cDelay_init(this, &cDelay_jIjXWFcG, 0.0f);
  numBytes += cBinop_init(&cBinop_UJVhBtPH, 16.364f); // __mul
  numBytes += cBinop_init(&cBinop_tnbqq1xO, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_cOSmERe4, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_zBxPBTss, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_M67esJ8Q, 0.0f);
  numBytes += cDelay_init(this, &cDelay_4VhLuzkl, 0.0f);
  numBytes += hTable_init(&hTable_TugJfLtQ, 256);
  numBytes += cTabhead_init(&cTabhead_8TqEvFo9, &hTable_7NVE3FN1);
  numBytes += cVar_init_s(&cVar_MCV48FmN, "del-1310-ref4");
  numBytes += cDelay_init(this, &cDelay_sDcUFbVJ, 19.392f);
  numBytes += cDelay_init(this, &cDelay_dnwD2Vnw, 0.0f);
  numBytes += cBinop_init(&cBinop_zo7g1Rx2, 19.392f); // __mul
  numBytes += cBinop_init(&cBinop_iDQujRWJ, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_mbsmuDUT, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_GF3qRII8, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_uq5JNuH7, 0.0f);
  numBytes += cDelay_init(this, &cDelay_3FZSj1l7, 0.0f);
  numBytes += hTable_init(&hTable_7NVE3FN1, 256);
  numBytes += cTabhead_init(&cTabhead_ybSPns1X, &hTable_VYf61oBw);
  numBytes += cVar_init_s(&cVar_JoJFwX7x, "del-1310-ref3");
  numBytes += cDelay_init(this, &cDelay_yI6SF9oL, 25.796f);
  numBytes += cDelay_init(this, &cDelay_Q7wEBTu9, 0.0f);
  numBytes += cBinop_init(&cBinop_m9sY4JEv, 25.796f); // __mul
  numBytes += cBinop_init(&cBinop_Fb7Q7h33, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_amfBNKP2, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_bwW3c2QK, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_F8QQw9M7, 0.0f);
  numBytes += cDelay_init(this, &cDelay_ukaXPaHY, 0.0f);
  numBytes += hTable_init(&hTable_VYf61oBw, 256);
  numBytes += cTabhead_init(&cTabhead_7ssKdvOe, &hTable_rsyMKuWL);
  numBytes += cVar_init_s(&cVar_ChpvNp45, "del-1310-ref2");
  numBytes += cDelay_init(this, &cDelay_GR04MAXK, 43.5337f);
  numBytes += cDelay_init(this, &cDelay_FfAtGOcp, 0.0f);
  numBytes += cBinop_init(&cBinop_GXRGtmcU, 43.5337f); // __mul
  numBytes += cBinop_init(&cBinop_tBmXxtqA, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_XhBHv1EL, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_PqCyKZxA, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_EGis0rvd, 0.0f);
  numBytes += cDelay_init(this, &cDelay_eSjzhXsT, 0.0f);
  numBytes += hTable_init(&hTable_rsyMKuWL, 256);
  numBytes += cTabhead_init(&cTabhead_St48b3LR, &hTable_78RfxJhK);
  numBytes += cVar_init_s(&cVar_tC7ToJhX, "del-1310-ref1");
  numBytes += cDelay_init(this, &cDelay_OV5SFkRD, 75.2546f);
  numBytes += cDelay_init(this, &cDelay_3YratDpi, 0.0f);
  numBytes += cBinop_init(&cBinop_RA2KAf5K, 75.2546f); // __mul
  numBytes += cBinop_init(&cBinop_zfZNITkd, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_ehlwY1f1, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_cERJj7MT, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_szXkQCGD, 0.0f);
  numBytes += cDelay_init(this, &cDelay_FInaOi4n, 0.0f);
  numBytes += hTable_init(&hTable_78RfxJhK, 256);
  numBytes += cVar_init_f(&cVar_U3rlCBoG, 0.0f);
  numBytes += cVar_init_f(&cVar_KiZPD2c8, 0.0f);
  numBytes += cPack_init(&cPack_2xZiRLAx, 2, 0.0f, 50.0f);
  numBytes += cVar_init_f(&cVar_zjrIYr3p, 22050.0f);
  numBytes += cBinop_init(&cBinop_mp25tMxX, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_6RiiC3ev, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_hmGj91V8, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_z6qTTlA4, 22050.0f);
  numBytes += cBinop_init(&cBinop_vCodnZcs, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_hcGctyo5, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_DfDnxfV8, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_aUBUF7A9, 22050.0f);
  numBytes += cBinop_init(&cBinop_nwnO02oK, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_0DQyJA3b, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_nHDVwMMM, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_gCVVrHuG, 100.0f);
  numBytes += cIf_init(&cIf_IgQCLjWm, false);
  numBytes += cBinop_init(&cBinop_fGIu3Jbi, 0.0f); // __pow
  numBytes += cPack_init(&cPack_vnxY5A7U, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_44UXrCfW, 0.0f);
  numBytes += cIf_init(&cIf_2SolLrJK, false);
  numBytes += cIf_init(&cIf_JJVJQUMJ, false);
  numBytes += cDelay_init(this, &cDelay_7xLaZa2E, 50.0f);
  numBytes += cVar_init_f(&cVar_hsrIJ4yr, 0.0f);
  numBytes += cVar_init_f(&cVar_RJybhnyg, 12.0f);
  numBytes += cVar_init_s(&cVar_cx6enyvp, "floatatom");
  numBytes += cPack_init(&cPack_n8nrn1uo, 2, 0.0f, 200.0f);
  numBytes += cPack_init(&cPack_C5APbCi5, 2, 0.0f, 200.0f);
  numBytes += cVar_init_s(&cVar_XHoXWdfg, "floatatom");
  numBytes += cDelay_init(this, &cDelay_KwPNmtEW, 0.0f);
  numBytes += cDelay_init(this, &cDelay_09egtzdi, 0.0f);
  numBytes += hTable_init(&hTable_GndqmX2H, 256);
  numBytes += cVar_init_s(&cVar_dTAAFNnq, "del-1428-del");
  numBytes += sVarf_init(&sVarf_nQ4E3bwN, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_kbdZGu1G, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_aMLcAFzq, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_VyRXTWaQ, "del-1428-del");
  numBytes += sVarf_init(&sVarf_pdQ3Ejpp, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_U7vX9PQx, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_masf72jC, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_fKeTgMRY, 0.0f); // __div
  numBytes += cVar_init_f(&cVar_wuOfDgb2, 4720.0f);
  numBytes += cBinop_init(&cBinop_rqEp3zek, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_4eYiY0Fp, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_qXx3NkpA, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_ODgcRrf1, 4720.0f);
  numBytes += cBinop_init(&cBinop_aV2hkLar, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_pm6SGIWw, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_4Aq5SqLC, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_v3sA9HUq, 4720.0f);
  numBytes += cBinop_init(&cBinop_fv89qSUD, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_pnP15uQM, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_vRKr3pEf, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_Y04IlGaJ, 1.0f);
  numBytes += cIf_init(&cIf_WPZpAnww, false);
  numBytes += sVarf_init(&sVarf_bGXM7Urz, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_F9Kl3kXb, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_tcP5yXgU, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_lLuH2O4I, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_LQkF2yxi, 4720.0f, 0.0f, false);
  numBytes += cTabhead_init(&cTabhead_g3bDoRJh, &hTable_7LsDOYF6);
  numBytes += cVar_init_s(&cVar_TyNcSDcn, "del-1491-del1");
  numBytes += cDelay_init(this, &cDelay_RK0Wo8tQ, 58.6435f);
  numBytes += cDelay_init(this, &cDelay_WRnv6Uz5, 0.0f);
  numBytes += cBinop_init(&cBinop_gfmQI2or, 58.6435f); // __mul
  numBytes += cBinop_init(&cBinop_WiCJq3IL, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_oGZsuRuA, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_s39WrzPN, 0.0f); // __sub
  numBytes += cTabhead_init(&cTabhead_SaueSYpz, &hTable_tUav5lY2);
  numBytes += cVar_init_s(&cVar_tCr4Txa4, "del-1491-del2");
  numBytes += cDelay_init(this, &cDelay_D3HRWLdw, 69.4325f);
  numBytes += cDelay_init(this, &cDelay_wgQHNY1s, 0.0f);
  numBytes += cBinop_init(&cBinop_uPjbTV26, 69.4325f); // __mul
  numBytes += cBinop_init(&cBinop_6oVaTLSY, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_G539oxKf, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_UCW2qyHY, 0.0f); // __sub
  numBytes += cTabhead_init(&cTabhead_sGFhYcyg, &hTable_6R5an42N);
  numBytes += cVar_init_s(&cVar_r7u0diin, "del-1491-del3");
  numBytes += cDelay_init(this, &cDelay_sri5vpP5, 74.5234f);
  numBytes += cDelay_init(this, &cDelay_4LlpkR2S, 0.0f);
  numBytes += cBinop_init(&cBinop_0OssJC2q, 74.5234f); // __mul
  numBytes += cBinop_init(&cBinop_x0X6mqgW, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_tTNv9Tq7, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_wpnxkcjP, 0.0f); // __sub
  numBytes += cTabhead_init(&cTabhead_pHZ1ktCN, &hTable_rjOzbEZE);
  numBytes += cVar_init_s(&cVar_SzDT1Qtb, "del-1491-del4");
  numBytes += cDelay_init(this, &cDelay_ggdfsjLf, 86.1244f);
  numBytes += cDelay_init(this, &cDelay_aZR6UZgd, 0.0f);
  numBytes += cBinop_init(&cBinop_mbCk7wKY, 86.1244f); // __mul
  numBytes += cBinop_init(&cBinop_OinmEaEM, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_VPVh62jA, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_jCd0TpZ8, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_KXgvFeK9, 0.0f);
  numBytes += cDelay_init(this, &cDelay_uXyScthK, 0.0f);
  numBytes += hTable_init(&hTable_7LsDOYF6, 256);
  numBytes += cDelay_init(this, &cDelay_rumW5d5m, 0.0f);
  numBytes += cDelay_init(this, &cDelay_VpsUpr1Y, 0.0f);
  numBytes += hTable_init(&hTable_tUav5lY2, 256);
  numBytes += cDelay_init(this, &cDelay_OGqgEGFU, 0.0f);
  numBytes += cDelay_init(this, &cDelay_y6jrWs3E, 0.0f);
  numBytes += hTable_init(&hTable_6R5an42N, 256);
  numBytes += cDelay_init(this, &cDelay_DVRi2YYx, 0.0f);
  numBytes += cDelay_init(this, &cDelay_fXCmmqA2, 0.0f);
  numBytes += hTable_init(&hTable_rjOzbEZE, 256);
  numBytes += cIf_init(&cIf_P0M4nDpw, false);
  numBytes += cBinop_init(&cBinop_JkcBagQn, 0.0f); // __pow
  numBytes += cPack_init(&cPack_egjSAywK, 2, 0.0f, 30.0f);
  numBytes += cPack_init(&cPack_QncVoE9J, 2, 0.0f, 50.0f);
  numBytes += cVar_init_f(&cVar_nTONyhq2, 22050.0f);
  numBytes += cBinop_init(&cBinop_CQSmMKdN, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_3VKgAxzB, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_UAknzTth, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_qSxGogwg, 100.0f);
  numBytes += cVar_init_f(&cVar_2McqJ0E3, 95.0f);
  numBytes += cVar_init_f(&cVar_Aa2xXIut, 14400.0f);
  numBytes += cVar_init_f(&cVar_xn9YB15O, 60.0f);
  numBytes += cIf_init(&cIf_p4FnGATS, false);
  numBytes += cTabhead_init(&cTabhead_GBH0McQH, &hTable_X1sWepvN);
  numBytes += cVar_init_s(&cVar_iJ3msAzO, "del-1491-ref6");
  numBytes += cDelay_init(this, &cDelay_61CX6xoZ, 13.645f);
  numBytes += cDelay_init(this, &cDelay_l9fnkq1s, 0.0f);
  numBytes += cBinop_init(&cBinop_RIyJRJRj, 13.645f); // __mul
  numBytes += cBinop_init(&cBinop_n8owfffD, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_wm8pgWfA, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_i8gtiPtD, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_ynSWo1uR, 0.0f);
  numBytes += cDelay_init(this, &cDelay_Ogi5UdWM, 0.0f);
  numBytes += hTable_init(&hTable_X1sWepvN, 256);
  numBytes += cTabhead_init(&cTabhead_mOIY8167, &hTable_caFOb0L8);
  numBytes += cVar_init_s(&cVar_bFedv5Jg, "del-1491-ref5");
  numBytes += cDelay_init(this, &cDelay_NFJIjzL1, 16.364f);
  numBytes += cDelay_init(this, &cDelay_JYOlSGNy, 0.0f);
  numBytes += cBinop_init(&cBinop_vRxD0T0K, 16.364f); // __mul
  numBytes += cBinop_init(&cBinop_28eCfElO, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_0YHS0pEr, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_MbbwMyzh, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_cjxk6vcy, 0.0f);
  numBytes += cDelay_init(this, &cDelay_OyJy4J4O, 0.0f);
  numBytes += hTable_init(&hTable_caFOb0L8, 256);
  numBytes += cTabhead_init(&cTabhead_Woe8xP8g, &hTable_UUU4p40c);
  numBytes += cVar_init_s(&cVar_5EAwz1s1, "del-1491-ref4");
  numBytes += cDelay_init(this, &cDelay_bPizPluu, 19.392f);
  numBytes += cDelay_init(this, &cDelay_sr7vkyHL, 0.0f);
  numBytes += cBinop_init(&cBinop_pybcb7sV, 19.392f); // __mul
  numBytes += cBinop_init(&cBinop_yhElLTeN, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_n4jsbmOF, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_6tHsuZvD, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_5jUtUgIN, 0.0f);
  numBytes += cDelay_init(this, &cDelay_Tc4xuv0o, 0.0f);
  numBytes += hTable_init(&hTable_UUU4p40c, 256);
  numBytes += cTabhead_init(&cTabhead_OPKyeqS7, &hTable_8OBIMoeC);
  numBytes += cVar_init_s(&cVar_MWbeBsTD, "del-1491-ref3");
  numBytes += cDelay_init(this, &cDelay_Ce8iE1Eh, 25.796f);
  numBytes += cDelay_init(this, &cDelay_H6WQVmxj, 0.0f);
  numBytes += cBinop_init(&cBinop_KmvIB8Mx, 25.796f); // __mul
  numBytes += cBinop_init(&cBinop_iluI5w0g, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_XNCCQXPH, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_I6458TTN, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_s1R1hExp, 0.0f);
  numBytes += cDelay_init(this, &cDelay_uYjulRu6, 0.0f);
  numBytes += hTable_init(&hTable_8OBIMoeC, 256);
  numBytes += cTabhead_init(&cTabhead_GAXQJEnH, &hTable_eI9c7xE2);
  numBytes += cVar_init_s(&cVar_K4ETKfTt, "del-1491-ref2");
  numBytes += cDelay_init(this, &cDelay_8FnyJ1iH, 43.5337f);
  numBytes += cDelay_init(this, &cDelay_WmwEniCL, 0.0f);
  numBytes += cBinop_init(&cBinop_mNbfKs66, 43.5337f); // __mul
  numBytes += cBinop_init(&cBinop_aE6bDREm, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_rIcWaGAr, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_liAjgoXe, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_Zy3ArC5r, 0.0f);
  numBytes += cDelay_init(this, &cDelay_VJCjXGVd, 0.0f);
  numBytes += hTable_init(&hTable_eI9c7xE2, 256);
  numBytes += cTabhead_init(&cTabhead_9kylz7eQ, &hTable_Vl2XxejY);
  numBytes += cVar_init_s(&cVar_TMIyXNEM, "del-1491-ref1");
  numBytes += cDelay_init(this, &cDelay_7Lq1eEXe, 75.2546f);
  numBytes += cDelay_init(this, &cDelay_Ie98y6HT, 0.0f);
  numBytes += cBinop_init(&cBinop_k3txeQT5, 75.2546f); // __mul
  numBytes += cBinop_init(&cBinop_KapXdUVY, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_nWMSlIBL, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_v4PJA7Zb, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_RNZRVaiV, 0.0f);
  numBytes += cDelay_init(this, &cDelay_to4qf1lP, 0.0f);
  numBytes += hTable_init(&hTable_Vl2XxejY, 256);
  numBytes += cVar_init_f(&cVar_olUdTNuo, 0.0f);
  numBytes += cVar_init_f(&cVar_eSLj9Q2y, 0.0f);
  numBytes += cPack_init(&cPack_40qDVDwB, 2, 0.0f, 50.0f);
  numBytes += cVar_init_f(&cVar_jsAL57BZ, 22050.0f);
  numBytes += cBinop_init(&cBinop_mmzPTI9P, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_HavsYL9f, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_k5uaGEKM, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_1JCAOllX, 22050.0f);
  numBytes += cBinop_init(&cBinop_GLfmJiS7, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_aYIMPjPM, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_xod8zom1, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_AwjOhgqW, 22050.0f);
  numBytes += cBinop_init(&cBinop_c2O730QV, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_9sZMKgF4, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_06XvneXY, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_RQaLlKs2, "del-1590-del1");
  numBytes += sVarf_init(&sVarf_t984n1aS, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_EtKtBAFO, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_DuKdmKRX, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_3tw4OpaD, 10000.0f);
  numBytes += cBinop_init(&cBinop_7e6oKO6t, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_LRNq5qN4, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_ENoVCC2J, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_qch2Y6GQ, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_RkW1iRG7, 10.0f);
  numBytes += cBinop_init(&cBinop_cEmO8IDD, 0.0f); // __div
  numBytes += sVarf_init(&sVarf_dyLctu6G, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_AKnfDmur, "floatatom");
  numBytes += sVarf_init(&sVarf_7lvNK8gW, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_mMUpGRAU, 0.0f);
  numBytes += cDelay_init(this, &cDelay_l3shmK9h, 0.0f);
  numBytes += hTable_init(&hTable_Vs9lEBjn, 256);
  numBytes += sVarf_init(&sVarf_cbs2aAnN, 0.0f, 0.0f, false);
  numBytes += cPack_init(&cPack_29XfAuyN, 2, 0.0f, 50.0f);
  numBytes += cVar_init_f(&cVar_pFlPyHAq, 1.0f);
  numBytes += cPack_init(&cPack_sLD6VSmq, 2, 0.0f, 50.0f);
  numBytes += cRandom_init(&cRandom_W1fSSohl, -960837402);
  numBytes += cSlice_init(&cSlice_2ODEHdlV, 1, 1);
  numBytes += cRandom_init(&cRandom_anyNpluQ, -1157824536);
  numBytes += cSlice_init(&cSlice_9vtHRgTX, 1, 1);
  numBytes += cRandom_init(&cRandom_GkNej76Y, -845647861);
  numBytes += cSlice_init(&cSlice_ehYYPh94, 1, 1);
  numBytes += cPack_init(&cPack_uOA5F3Gy, 4, 0.0f, 0.0f, 0.0f, 0.0f);
  numBytes += cVar_init_s(&cVar_kGooD0FO, "floatatom");
  numBytes += cVar_init_s(&cVar_4AY27DI0, "floatatom");
  numBytes += cIf_init(&cIf_cvgDPIIQ, false);
  numBytes += cVar_init_s(&cVar_M80MQmAb, "floatatom");
  numBytes += cBinop_init(&cBinop_2xrIyTtO, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_rJQyfo0R, 72.07f); // __sub
  numBytes += cSlice_init(&cSlice_02amxWQc, 1, -1);
  numBytes += cSlice_init(&cSlice_2BuwMAsK, 1, -1);
  numBytes += cVar_init_f(&cVar_Gg6rijWZ, 5.0f);
  numBytes += cBinop_init(&cBinop_U7y31pL0, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_DGrLtH6g, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_pOB2J8iV, 0.0f, 0.0f, false);
  numBytes += cSlice_init(&cSlice_lkIyh1d5, 1, 1);
  numBytes += cSlice_init(&cSlice_HB6epsln, 0, 1);
  numBytes += sVarf_init(&sVarf_R5EWxVIc, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_5xHICv36, 5.0f);
  numBytes += cBinop_init(&cBinop_ijhFmPJ9, 0.0f); // __div
  numBytes += sVarf_init(&sVarf_h6JxsK9j, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_47y7V84o, 50.0f);
  numBytes += cVar_init_s(&cVar_GULKZKTG, "floatatom");
  numBytes += cDelay_init(this, &cDelay_XsUg7GTr, 350.0f);
  numBytes += cVar_init_s(&cVar_DTpbSWDG, "floatatom");
  numBytes += cVar_init_s(&cVar_2vwaBkTe, "floatatom");
  numBytes += cVar_init_s(&cVar_R2CgXvGG, "floatatom");
  numBytes += cExpr_init(&cExpr_2jBKcYU2, &Heavy_SoundScraper::cExpr_2jBKcYU2_evaluate);
  numBytes += cVar_init_s(&cVar_UMwRnK03, "floatatom");
  numBytes += cVar_init_f(&cVar_m36CtkJV, 0.0f);
  numBytes += cVar_init_f(&cVar_2wqMA3Qb, 0.0f);
  numBytes += cVar_init_s(&cVar_BvSLDSzN, "1666_default");
  numBytes += cSlice_init(&cSlice_pYCeGFll, 1, 1);
  numBytes += sVarf_init(&sVarf_tnfrMHs2, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_hs3RJH8f, "1666_default");
  numBytes += cSlice_init(&cSlice_MlzfkOd6, 1, 1);
  numBytes += sVarf_init(&sVarf_2S2rbbGI, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_zvyJl14F, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_qFngxfzl, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_KiC3yEXU, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_x5s3QE1H, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_NXJI1ey2, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_Kb6VrfWt, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_5je1f1ZB, 0.0f); // __div
  numBytes += hTable_init(&hTable_ENQ9TLFR, 10000);
  numBytes += sVarf_init(&sVarf_ui2z5bvS, 0.0f, 0.0f, false);
  
  // schedule a message to trigger all loadbangs via the __hv_init receiver
  scheduleMessageForReceiver(0xCE5CC65B, msg_initWithBang(HV_MESSAGE_ON_STACK(1), 0));
}

Heavy_SoundScraper::~Heavy_SoundScraper() {
  cPack_free(&cPack_t45KCxyH);
  cPack_free(&cPack_CafWK5oZ);
  cPack_free(&cPack_xVnqfZIu);
  cPack_free(&cPack_2pIV6F5w);
  cPack_free(&cPack_FtcNOzmc);
  cPack_free(&cPack_X5fEAV4y);
  cPack_free(&cPack_CsLjerEM);
  cPack_free(&cPack_fNevwtaB);
  cPack_free(&cPack_ll00wYEj);
  cPack_free(&cPack_YBvHZ5HH);
  cPack_free(&cPack_Tq5AG5UD);
  cPack_free(&cPack_fxOvKXea);
  cPack_free(&cPack_ywJFQ3AM);
  cPack_free(&cPack_SbjKVBag);
  cPack_free(&cPack_fv8q4ynA);
  cPack_free(&cPack_cb6HbLyS);
  cPack_free(&cPack_tpzyTrBc);
  cPack_free(&cPack_mtB46fWX);
  cPack_free(&cPack_fe8EG0PJ);
  cPack_free(&cPack_tNmyHW7N);
  cPack_free(&cPack_X1AiotjA);
  cPack_free(&cPack_wC1rXIon);
  cPack_free(&cPack_zwii0lPP);
  cPack_free(&cPack_XN6Ia42e);
  cPack_free(&cPack_pFdbxRaA);
  cPack_free(&cPack_itfmeIXz);
  cPack_free(&cPack_E8COPE7k);
  cPack_free(&cPack_J5q7sQ5W);
  cPack_free(&cPack_9uoQwgtp);
  cPack_free(&cPack_aRU3bjzn);
  cPack_free(&cPack_UH95E8FT);
  cPack_free(&cPack_i65kIUnR);
  cPack_free(&cPack_pvZFOWUZ);
  cPack_free(&cPack_vRHMX787);
  cPack_free(&cPack_baediq0f);
  cPack_free(&cPack_dlnf1mZs);
  cPack_free(&cPack_jGGNTkzv);
  cPack_free(&cPack_uWbDOps4);
  cPack_free(&cPack_dmAFTH8T);
  cPack_free(&cPack_baUqD3UH);
  cPack_free(&cPack_42rxGRaF);
  cPack_free(&cPack_R5IdV5Yw);
  cPack_free(&cPack_2DxqkVEV);
  cPack_free(&cPack_CFSB7hbZ);
  cPack_free(&cPack_DDFTP4p0);
  cPack_free(&cPack_zujddLT8);
  cPack_free(&cPack_rehIwvM0);
  cPack_free(&cPack_tSUDMHK5);
  cPack_free(&cPack_sIRtwrnC);
  cPack_free(&cPack_U63jsgqi);
  cPack_free(&cPack_FLvP6J69);
  cPack_free(&cPack_fneOoWBx);
  hTable_free(&hTable_oWR8pmBA);
  hTable_free(&hTable_teJVa6yG);
  hTable_free(&hTable_JomIt6y9);
  hTable_free(&hTable_nOD1MkVi);
  hTable_free(&hTable_AV8Uleub);
  hTable_free(&hTable_xc853M9T);
  cPack_free(&cPack_qrlXgzV2);
  cPack_free(&cPack_YTI2wDDT);
  hTable_free(&hTable_kwb3HxN8);
  hTable_free(&hTable_SFNzaQne);
  cPack_free(&cPack_gbbxVdnG);
  cPack_free(&cPack_Ys1KLikb);
  cPack_free(&cPack_f73hkHp6);
  hTable_free(&hTable_BDlw4p4k);
  hTable_free(&hTable_aZEd6ida);
  hTable_free(&hTable_Ua2nJmIp);
  hTable_free(&hTable_zGd0W84V);
  cPack_free(&cPack_y9dIYkvo);
  cPack_free(&cPack_HDF4aKkM);
  hTable_free(&hTable_DvofHMe4);
  hTable_free(&hTable_TugJfLtQ);
  hTable_free(&hTable_7NVE3FN1);
  hTable_free(&hTable_VYf61oBw);
  hTable_free(&hTable_rsyMKuWL);
  hTable_free(&hTable_78RfxJhK);
  cPack_free(&cPack_2xZiRLAx);
  cPack_free(&cPack_vnxY5A7U);
  cPack_free(&cPack_n8nrn1uo);
  cPack_free(&cPack_C5APbCi5);
  hTable_free(&hTable_GndqmX2H);
  hTable_free(&hTable_7LsDOYF6);
  hTable_free(&hTable_tUav5lY2);
  hTable_free(&hTable_6R5an42N);
  hTable_free(&hTable_rjOzbEZE);
  cPack_free(&cPack_egjSAywK);
  cPack_free(&cPack_QncVoE9J);
  hTable_free(&hTable_X1sWepvN);
  hTable_free(&hTable_caFOb0L8);
  hTable_free(&hTable_UUU4p40c);
  hTable_free(&hTable_8OBIMoeC);
  hTable_free(&hTable_eI9c7xE2);
  hTable_free(&hTable_Vl2XxejY);
  cPack_free(&cPack_40qDVDwB);
  hTable_free(&hTable_Vs9lEBjn);
  cPack_free(&cPack_29XfAuyN);
  cPack_free(&cPack_sLD6VSmq);
  cPack_free(&cPack_uOA5F3Gy);
  cExpr_free(&cExpr_2jBKcYU2);
  hTable_free(&hTable_ENQ9TLFR);
}

HvTable *Heavy_SoundScraper::getTableForHash(hv_uint32_t tableHash) {switch (tableHash) {
    case 0x9BCAD111: return &hTable_oWR8pmBA; // bowl
    case 0x782CD90: return &hTable_teJVa6yG; // crotale
    case 0x53C964B5: return &hTable_JomIt6y9; // gong
    case 0xAC13AE99: return &hTable_nOD1MkVi; // marimba
    case 0x1FD931DF: return &hTable_AV8Uleub; // xylo
    case 0x6F52CA74: return &hTable_xc853M9T; // almglocken
    case 0x97A40253: return &hTable_kwb3HxN8; // del-1220-del
    case 0x976EFC70: return &hTable_SFNzaQne; // del-1249-del1
    case 0xCBC44FA8: return &hTable_BDlw4p4k; // del-1310-del1
    case 0xC68CB410: return &hTable_aZEd6ida; // del-1310-del2
    case 0x5F0D1297: return &hTable_Ua2nJmIp; // del-1310-del3
    case 0x5295D61B: return &hTable_zGd0W84V; // del-1310-del4
    case 0x9B3F7581: return &hTable_DvofHMe4; // del-1310-ref6
    case 0xB347B9D8: return &hTable_TugJfLtQ; // del-1310-ref5
    case 0x1741C12A: return &hTable_7NVE3FN1; // del-1310-ref4
    case 0x65BC4D58: return &hTable_VYf61oBw; // del-1310-ref3
    case 0x4EE2F2F4: return &hTable_rsyMKuWL; // del-1310-ref2
    case 0x4FBBCC78: return &hTable_78RfxJhK; // del-1310-ref1
    case 0x9D2C614D: return &hTable_GndqmX2H; // del-1428-del
    case 0xAB93A9C0: return &hTable_7LsDOYF6; // del-1491-del1
    case 0x96A2BDA7: return &hTable_tUav5lY2; // del-1491-del2
    case 0x1EEB315F: return &hTable_6R5an42N; // del-1491-del3
    case 0x9E5FA7F9: return &hTable_rjOzbEZE; // del-1491-del4
    case 0xD4CFF0C: return &hTable_X1sWepvN; // del-1491-ref6
    case 0x1057EB92: return &hTable_caFOb0L8; // del-1491-ref5
    case 0x1C8EDA04: return &hTable_UUU4p40c; // del-1491-ref4
    case 0xA95EFC5E: return &hTable_8OBIMoeC; // del-1491-ref3
    case 0x8710B6BB: return &hTable_eI9c7xE2; // del-1491-ref2
    case 0xC09DF5E6: return &hTable_Vl2XxejY; // del-1491-ref1
    case 0x24E4AAE0: return &hTable_Vs9lEBjn; // del-1590-del1
    case 0xBE2E7346: return &hTable_ENQ9TLFR; // 1666_default
    default: return nullptr;
  }
}

void Heavy_SoundScraper::scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) {
  switch (receiverHash) {
    case 0x676151E5: { // 1005-levelin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_u9IR7Pjw_sendMessage);
      break;
    }
    case 0x4518BA34: { // 1005-levelout
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_OkGskKAJ_sendMessage);
      break;
    }
    case 0x6F9FBEC2: { // 1013-attack
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_7izOKg0D_sendMessage);
      break;
    }
    case 0xF2645EF2: { // 1013-cutoff
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_FqsruA17_sendMessage);
      break;
    }
    case 0x2DB48039: { // 1013-fade-in
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_EQm1ZcpX_sendMessage);
      break;
    }
    case 0x62D46891: { // 1013-fade-out
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_EeyoHP8Q_sendMessage);
      break;
    }
    case 0x349D3D62: { // 1013-phase
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_51D9FzDZ_sendMessage);
      break;
    }
    case 0x6AE0114A: { // 1013-rel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_chC0fDsM_sendMessage);
      break;
    }
    case 0xCB92FB18: { // 1013-release
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_C0f1lQ37_sendMessage);
      break;
    }
    case 0x57A7FD72: { // 1013-sr
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_veJrJ2vf_sendMessage);
      break;
    }
    case 0x4E70A642: { // 1013-stop
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_3k6blV8A_sendMessage);
      break;
    }
    case 0x14D190E8: { // 1013-tableFreq
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_dLBuuyyH_sendMessage);
      break;
    }
    case 0xC268AA1B: { // 1013-tableName
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_8D8z32Fi_sendMessage);
      break;
    }
    case 0xE7AF8038: { // 1013-velocity
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_oCRfDneS_sendMessage);
      break;
    }
    case 0x64DCFC2F: { // 1013-vol
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_MGIpARuG_sendMessage);
      break;
    }
    case 0x50D5F76A: { // 1049-attack
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_BiwFDNsH_sendMessage);
      break;
    }
    case 0xF3BF4624: { // 1049-cutoff
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_Z8qTBs1F_sendMessage);
      break;
    }
    case 0xCFE3E7FB: { // 1049-fade-in
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_IOBCdr60_sendMessage);
      break;
    }
    case 0xF1B8B621: { // 1049-fade-out
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_5WsxjXS0_sendMessage);
      break;
    }
    case 0x525CAC1A: { // 1049-phase
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_tKYFMlpy_sendMessage);
      break;
    }
    case 0xA87A2151: { // 1049-rel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_s2w97Arv_sendMessage);
      break;
    }
    case 0x55029BFC: { // 1049-release
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_pmg97VVY_sendMessage);
      break;
    }
    case 0xBE690FC3: { // 1049-sr
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_MzEKMcDD_sendMessage);
      break;
    }
    case 0xE6BC7AD3: { // 1049-stop
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_q7vHf6zg_sendMessage);
      break;
    }
    case 0x69F33369: { // 1049-tableFreq
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_bj2r78Uf_sendMessage);
      break;
    }
    case 0x5BCC58C7: { // 1049-tableName
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_oY8i2pLw_sendMessage);
      break;
    }
    case 0x6FC5959F: { // 1049-velocity
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_spCWf3Qz_sendMessage);
      break;
    }
    case 0x2B9DF2E0: { // 1049-vol
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_QnMQhgXf_sendMessage);
      break;
    }
    case 0xE673386D: { // 1085-attack
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_WmeGRCg4_sendMessage);
      break;
    }
    case 0xCCCAA185: { // 1085-cutoff
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_K4HZG2wh_sendMessage);
      break;
    }
    case 0xBE83E2EA: { // 1085-fade-in
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_YfEvkani_sendMessage);
      break;
    }
    case 0x5F2BBD8F: { // 1085-fade-out
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_qtVcehxi_sendMessage);
      break;
    }
    case 0x43D27577: { // 1085-phase
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_7xvPxd0G_sendMessage);
      break;
    }
    case 0x87E8930F: { // 1085-rel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_dV8bOv46_sendMessage);
      break;
    }
    case 0x3003429A: { // 1085-release
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_38hDWPAm_sendMessage);
      break;
    }
    case 0x87C3D901: { // 1085-sr
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_7tK5H609_sendMessage);
      break;
    }
    case 0x1F62B01B: { // 1085-stop
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_98xtv1B0_sendMessage);
      break;
    }
    case 0x60A106AB: { // 1085-tableFreq
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_kB9kdzJ2_sendMessage);
      break;
    }
    case 0xED68D23A: { // 1085-tableName
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_f2DNYbGG_sendMessage);
      break;
    }
    case 0xC109014F: { // 1085-velocity
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_Typ4JIoB_sendMessage);
      break;
    }
    case 0x688A0E3D: { // 1085-vol
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_6rMjBsDU_sendMessage);
      break;
    }
    case 0xCE21EA29: { // 1121-attack
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_xIDwRCR0_sendMessage);
      break;
    }
    case 0xD98D9624: { // 1121-cutoff
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_aU7J7wm9_sendMessage);
      break;
    }
    case 0xB3F51013: { // 1121-fade-in
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_njpx9hp5_sendMessage);
      break;
    }
    case 0xB3F35933: { // 1121-fade-out
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_Md0gFRwU_sendMessage);
      break;
    }
    case 0x400EFFA6: { // 1121-phase
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_AGQqEzBj_sendMessage);
      break;
    }
    case 0xFC727EE1: { // 1121-rel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_SZRranTr_sendMessage);
      break;
    }
    case 0xD259DE3: { // 1121-release
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_QDmKJtXm_sendMessage);
      break;
    }
    case 0x337F255C: { // 1121-sr
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_V10EzN6A_sendMessage);
      break;
    }
    case 0x86D3C00C: { // 1121-stop
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_C3gkOwhg_sendMessage);
      break;
    }
    case 0x45D3BE8E: { // 1121-tableFreq
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_cw4Jl4Ws_sendMessage);
      break;
    }
    case 0xD67DE73F: { // 1121-tableName
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_EksLlOPh_sendMessage);
      break;
    }
    case 0x57DA7AEC: { // 1121-velocity
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_KgXQczVj_sendMessage);
      break;
    }
    case 0x34F8F5A3: { // 1121-vol
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_S7bU7ctr_sendMessage);
      break;
    }
    case 0xAB370A60: { // 1157-levelin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_L5xfvBzh_sendMessage);
      break;
    }
    case 0x774A69D5: { // 1157-levelout
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_ovIkSJRX_sendMessage);
      break;
    }
    case 0x1345C8C4: { // 1165-levelin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_UM8pxCIq_sendMessage);
      break;
    }
    case 0x352D518B: { // 1165-levelout
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_sQa0mp8d_sendMessage);
      break;
    }
    case 0x82209D15: { // 1175-levelin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_M17zPons_sendMessage);
      break;
    }
    case 0x4925B226: { // 1175-levelout
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_lzK2PWxi_sendMessage);
      break;
    }
    case 0x7FA13EC5: { // 1183-levelin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_SDyRUZVe_sendMessage);
      break;
    }
    case 0xD9AC1997: { // 1183-levelout
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_SHAlY3PM_sendMessage);
      break;
    }
    case 0xD12AC7A7: { // 1409-levelin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_E26AmS55_sendMessage);
      break;
    }
    case 0x596BE5B0: { // 1409-levelout
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_SPwDNL2J_sendMessage);
      break;
    }
    case 0xDCBC0592: { // 1618-bend
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_fYbtdYAQ_sendMessage);
      break;
    }
    case 0xF3669DE2: { // 1618-chunk-size
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_DsOxX40y_sendMessage);
      break;
    }
    case 0x5FF69CCF: { // 1618-level
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_UuGL7T2H_sendMessage);
      break;
    }
    case 0x99CA0B53: { // 1618-loopstart
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_yKuRHk4T_sendMessage);
      break;
    }
    case 0xB05A685C: { // 1618-pitch
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_if9dP39u_sendMessage);
      break;
    }
    case 0x2A32E300: { // 1618-reset
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_pl4thiSB_sendMessage);
      break;
    }
    case 0xB74798DD: { // 1618-sample
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_Zooi0MsG_sendMessage);
      break;
    }
    case 0xD52F93B1: { // 1618-sample-pitch
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_WsASZSZc_sendMessage);
      break;
    }
    case 0x92D60D7E: { // 1618-start
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_dFOpWous_sendMessage);
      break;
    }
    case 0x3B83D938: { // 1618-stop
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_8uy8pCnV_sendMessage);
      break;
    }
    case 0xBEC1E87A: { // 1618-table
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_KYtdp8Cr_sendMessage);
      break;
    }
    case 0xB88C984C: { // 1618-transposition
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_jW0BSIiH_sendMessage);
      break;
    }
    case 0x3DC2315F: { // 1666-cents
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_CLqUCZ3N_sendMessage);
      break;
    }
    case 0x1BDB8292: { // 1666-chunk-size
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_8ROaVYr0_sendMessage);
      break;
    }
    case 0x26B47E00: { // 1666-chunk-size-samples
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_m5hw2QJU_sendMessage);
      break;
    }
    case 0x415CFB0E: { // 1666-read-point
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_do9XHRQM_sendMessage);
      break;
    }
    case 0xEB707B3: { // 1666-read-pt
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_FX6TpWuY_sendMessage);
      break;
    }
    case 0x4FC50B2D: { // 1666-size
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_2rJDeVKt_sendMessage);
      break;
    }
    case 0x7043856: { // 1666-table
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_pU9JNKCf_sendMessage);
      break;
    }
    case 0xCE5CC65B: { // __hv_init
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_VOzSTOIU_sendMessage);
      break;
    }
    case 0x67E37CA3: { // __hv_notein
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_pmgk8PyJ_sendMessage);
      break;
    }
    case 0x40AA4AF1: { // changesound
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_5am08un8_sendMessage);
      break;
    }
    case 0xA41806F7: { // distortlevel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_R0NCyYvY_sendMessage);
      break;
    }
    case 0xFCD12E4C: { // mastervolume
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_lrj6wOD4_sendMessage);
      break;
    }
    case 0xEF5F3308: { // panTranslation
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_GO7kADgY_sendMessage);
      break;
    }
    case 0x8B2148DD: { // pitch
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_xnnDkUgV_sendMessage);
      break;
    }
    case 0x4409C659: { // processeffects
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_T8EaOrbu_sendMessage);
      break;
    }
    case 0x7B795C5A: { // resetsing
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_RTjz4diq_sendMessage);
      break;
    }
    case 0xA987B741: { // reverbvolume
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_noM8Uo6S_sendMessage);
      break;
    }
    case 0x7FFAC478: { // sampleNameFreq
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_j1FDTCrp_sendMessage);
      break;
    }
    case 0x62D6FDDE: { // selectsound
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_x0bU9Pi4_sendMessage);
      break;
    }
    case 0x7AAE6786: { // sinPanAngle
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_imFvNAYz_sendMessage);
      break;
    }
    case 0x6731B2E0: { // sing
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_a54R3rPR_sendMessage);
      break;
    }
    case 0x57292445: { // singlevel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_COMiAszK_sendMessage);
      break;
    }
    case 0xC7DE3B07: { // singpitch
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_UO2GPTgP_sendMessage);
      break;
    }
    case 0x853B1BE7: { // velocity
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_JaZN56v9_sendMessage);
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


void Heavy_SoundScraper::cVar_O8k01LXR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cVar_StYoNaJd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Wcz9Dwzo_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_vsc7n5pZ_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_yPSiKuS7_sendMessage);
}

void Heavy_SoundScraper::cIf_Ioz9s22C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_uZbjTE1u_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_5O36kA1l_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cMsg_Q8wQcXRw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_hVBEV9CN, HV_BINOP_POW, 0, m, &cBinop_hVBEV9CN_sendMessage);
}

void Heavy_SoundScraper::cBinop_hVBEV9CN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_t45KCxyH, 0, m, &cPack_t45KCxyH_sendMessage);
}

void Heavy_SoundScraper::cBinop_tuPhbC18_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_IhObJ4MS_sendMessage);
}

void Heavy_SoundScraper::cCast_yPSiKuS7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_Ioz9s22C, 0, m, &cIf_Ioz9s22C_sendMessage);
}

void Heavy_SoundScraper::cCast_vsc7n5pZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_hf2z9654_sendMessage);
}

void Heavy_SoundScraper::cBinop_hf2z9654_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_Ioz9s22C, 1, m, &cIf_Ioz9s22C_sendMessage);
}

void Heavy_SoundScraper::cBinop_5O36kA1l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_tuPhbC18_sendMessage);
}

void Heavy_SoundScraper::cMsg_uZbjTE1u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_t45KCxyH, 0, m, &cPack_t45KCxyH_sendMessage);
}

void Heavy_SoundScraper::cBinop_IhObJ4MS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_hVBEV9CN, HV_BINOP_POW, 1, m, &cBinop_hVBEV9CN_sendMessage);
  cMsg_Q8wQcXRw_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_t45KCxyH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_RKUx47KF, 0, m, NULL);
}

void Heavy_SoundScraper::cVar_kAy81P4N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_79uxPCQS_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_Wcz9Dwzo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSend_luUJBO5U_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_luUJBO5U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_u9IR7Pjw_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_79uxPCQS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_OkGskKAJ_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_9vtroTVf_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_KkDWnMgv, 0, m, &cSlice_KkDWnMgv_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_eRpMOh1l, 0, m, &cRandom_eRpMOh1l_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_cXgmWAbK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_YPvbGPap_sendMessage);
}

void Heavy_SoundScraper::cUnop_YPvbGPap_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_n7JA7VIG_sendMessage);
}

void Heavy_SoundScraper::cRandom_eRpMOh1l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_cXgmWAbK_sendMessage);
}

void Heavy_SoundScraper::cSlice_KkDWnMgv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_eRpMOh1l, 1, m, &cRandom_eRpMOh1l_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_Wh8fJ7Jw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_d0IYt5DF, HV_BINOP_DIVIDE, 0, m, &cBinop_d0IYt5DF_sendMessage);
}

void Heavy_SoundScraper::cBinop_Ibtzu3mp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_LsFX2qzH_sendMessage);
}

void Heavy_SoundScraper::cBinop_LsFX2qzH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_NSav0z2q, HV_BINOP_POW, 1, m, &cBinop_NSav0z2q_sendMessage);
  cMsg_4RktLCdk_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_NSav0z2q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_Wh8fJ7Jw_sendMessage);
}

void Heavy_SoundScraper::cMsg_4RktLCdk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_NSav0z2q, HV_BINOP_POW, 0, m, &cBinop_NSav0z2q_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_H0RdKRql_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_bLlUX3bT, 0, m, &cSlice_bLlUX3bT_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_HK4oXe04, 0, m, &cRandom_HK4oXe04_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_ETv2kGXl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_RObJ1E5g_sendMessage);
}

void Heavy_SoundScraper::cUnop_RObJ1E5g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_8NamzPaJ_sendMessage);
}

void Heavy_SoundScraper::cRandom_HK4oXe04_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 15.0f, 0, m, &cBinop_ETv2kGXl_sendMessage);
}

void Heavy_SoundScraper::cSlice_bLlUX3bT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_HK4oXe04, 1, m, &cRandom_HK4oXe04_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_xH1PcvAO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSend_BD7vQuBs_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_uixhqqOG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSend_oacxwXvL_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cUnop_gBijMmA5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_xVnqfZIu, 0, m, &cPack_xVnqfZIu_sendMessage);
}

void Heavy_SoundScraper::cUnop_qQ4j7IQz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_CafWK5oZ, 0, m, &cPack_CafWK5oZ_sendMessage);
}

void Heavy_SoundScraper::cPack_CafWK5oZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_oDVE0pvn, 0, m, NULL);
}

void Heavy_SoundScraper::cPack_xVnqfZIu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_2dJXG7Q9, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_MnaNVfXu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_gBijMmA5_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_SIN, m, &cUnop_qQ4j7IQz_sendMessage);
}

void Heavy_SoundScraper::cMsg_mfocQWvH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.5f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_MnaNVfXu_sendMessage);
}

void Heavy_SoundScraper::cCast_FENTk4Ts_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cVar_rrmykqSu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_eBHUil5v_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_3NaZ4Tuv_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_TVTPclwx_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_BEYoQTJN_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_5KfQ9FcJ_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_5KfQ9FcJ_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_WVwnSGvF, 1, m, &cDelay_WVwnSGvF_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_wSvC4ma3_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cDelay_WVwnSGvF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_WVwnSGvF, m);
  cVar_onMessage(_c, &Context(_c)->cVar_6XFtM8oq, 0, m, &cVar_6XFtM8oq_sendMessage);
}

void Heavy_SoundScraper::cMsg_5KfQ9FcJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_WVwnSGvF, 0, m, &cDelay_WVwnSGvF_sendMessage);
}

void Heavy_SoundScraper::cCast_wSvC4ma3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_WVwnSGvF, 0, m, &cDelay_WVwnSGvF_sendMessage);
}

void Heavy_SoundScraper::cVar_6XFtM8oq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Ufawdh83_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_lRhqpZHN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_rrmykqSu, 0, m, &cVar_rrmykqSu_sendMessage);
}

void Heavy_SoundScraper::cSend_LppeK2T9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cSend_j0Z3SG5f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_chC0fDsM_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_aR41c0G2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 25.0f);
  cSend_LppeK2T9_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_ybGcBx0Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 4000.0f);
  cSend_j0Z3SG5f_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_6qO1mvKY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_MGIpARuG_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_zFDBnSh6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSend_6qO1mvKY_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_e5BRQYoz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cSend_ELZ4wWIv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_chC0fDsM_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_CHTs94PA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_MGIpARuG_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_vOWWaUCd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 25.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_bCXr4EvD, 0, m, NULL);
}

void Heavy_SoundScraper::cMsg_Ufawdh83_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 0);
  sLine_onMessage(_c, &Context(_c)->sLine_bCXr4EvD, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_TVTPclwx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_BEYoQTJN_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_eBHUil5v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_vOWWaUCd_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_3NaZ4Tuv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_6XFtM8oq, 1, m, &cVar_6XFtM8oq_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_Zg9kic8X_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_ZZ3HhSkJ, 0, m, &cSlice_ZZ3HhSkJ_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cVar_J4eHOjeW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_EkhsylPU_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSystem_aXDx8LJK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 2.0f, 0, m, &cBinop_she6dkMW_sendMessage);
}

void Heavy_SoundScraper::cBinop_she6dkMW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_5hl3G6sl, m);
}

void Heavy_SoundScraper::cMsg_EkhsylPU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_aXDx8LJK_sendMessage);
}

void Heavy_SoundScraper::cSlice_ZZ3HhSkJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sTabread_onMessage(_c, &Context(_c)->sTabread_KllqsCaA, 1, m, NULL);
      sTabread_onMessage(_c, &Context(_c)->sTabread_8LcxcY9e, 1, m, NULL);
      cVar_onMessage(_c, &Context(_c)->cVar_J4eHOjeW, 0, m, &cVar_J4eHOjeW_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cVar_RtlGDBzB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_fNevwtaB, 0, m, &cPack_fNevwtaB_sendMessage);
}

void Heavy_SoundScraper::cVar_qpZFqbst_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 10000000.0f, 0, m, &cBinop_90PqbPBV_sendMessage);
}

void Heavy_SoundScraper::cIf_MZg0SU5F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_ABS, m, &cUnop_cuY7dZXc_sendMessage);
      break;
    }
    case 1: {
      cVar_onMessage(_c, &Context(_c)->cVar_qpZFqbst, 1, m, &cVar_qpZFqbst_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_jPLD8jzs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_MZg0SU5F, 1, m, &cIf_MZg0SU5F_sendMessage);
}

void Heavy_SoundScraper::cVar_RApaYfeB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 10000000.0f, 0, m, &cBinop_Z8ooBx7L_sendMessage);
}

void Heavy_SoundScraper::cUnop_cuY7dZXc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_RApaYfeB, 1, m, &cVar_RApaYfeB_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_xmLrAbUm_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_mVukWvnj_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_LAwvA4gj_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_mVukWvnj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_qpZFqbst, 0, m, &cVar_qpZFqbst_sendMessage);
}

void Heavy_SoundScraper::cCast_LAwvA4gj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_RApaYfeB, 0, m, &cVar_RApaYfeB_sendMessage);
}

void Heavy_SoundScraper::cVar_KotIcBWk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_LESS_THAN, 0.0f, 0, m, &cBinop_DfK1hXBi_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_lroWiSB2_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_Mwq1WGUg_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_Mwq1WGUg_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_FNbsubLf, 1, m, &cDelay_FNbsubLf_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_4g3ZtrAK_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cDelay_FNbsubLf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_FNbsubLf, m);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ZFzLYajQ_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_hqUD4ZwO_sendMessage);
}

void Heavy_SoundScraper::cMsg_Mwq1WGUg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_FNbsubLf, 0, m, &cDelay_FNbsubLf_sendMessage);
}

void Heavy_SoundScraper::cCast_4g3ZtrAK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_FNbsubLf, 0, m, &cDelay_FNbsubLf_sendMessage);
}

void Heavy_SoundScraper::cPack_2pIV6F5w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_R1zWKfs3_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_FD8xDxpR_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_D7XzuOg9_sendMessage);
      break;
    }
    default: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_jEp7it3T, HV_BINOP_SUBTRACT, 0, m, &cBinop_jEp7it3T_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_D7XzuOg9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_yngiNUoG_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_q9r8o6My_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_fBhAt8KS_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_fBhAt8KS_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_eJiuDJqr, 1, m, &cDelay_eJiuDJqr_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_g8fCfq0F_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cDelay_eJiuDJqr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_eJiuDJqr, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_6FwJg7V4_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_OSTRbdgG_sendMessage);
}

void Heavy_SoundScraper::cMsg_fBhAt8KS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_eJiuDJqr, 0, m, &cDelay_eJiuDJqr_sendMessage);
}

void Heavy_SoundScraper::cCast_g8fCfq0F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_eJiuDJqr, 0, m, &cDelay_eJiuDJqr_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_rR9Sg6Vv_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_TKZHcQac_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_TKZHcQac_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_kRjgB4kN, 1, m, &cDelay_kRjgB4kN_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_j828HnBe_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cDelay_kRjgB4kN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_kRjgB4kN, m);
}

void Heavy_SoundScraper::cMsg_TKZHcQac_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_kRjgB4kN, 0, m, &cDelay_kRjgB4kN_sendMessage);
}

void Heavy_SoundScraper::cCast_j828HnBe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_kRjgB4kN, 0, m, &cDelay_kRjgB4kN_sendMessage);
}

void Heavy_SoundScraper::cPack_FtcNOzmc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_afK1R6yL_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_X5fEAV4y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_ZfY4RlH8_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_CsLjerEM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_PVHRI3Z2_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_oc7CZsKi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_5aCja6rV, HV_BINOP_DIVIDE, 1, m, &cBinop_5aCja6rV_sendMessage);
}

void Heavy_SoundScraper::cVar_TQ2qr3Xw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_5aCja6rV, HV_BINOP_DIVIDE, 0, m, &cBinop_5aCja6rV_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_KPQwojb7_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0xFFFFFFFF: { // "bang"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_DcqWHsPz_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_lmRGI1Mr_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_BPqezhCW_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_gG3yTMSe_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_lmRGI1Mr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_TQ2qr3Xw, 0, m, &cVar_TQ2qr3Xw_sendMessage);
}

void Heavy_SoundScraper::cCast_DcqWHsPz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_oc7CZsKi, 0, m, &cVar_oc7CZsKi_sendMessage);
}

void Heavy_SoundScraper::cCast_BPqezhCW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_oc7CZsKi, 0, m, &cVar_oc7CZsKi_sendMessage);
}

void Heavy_SoundScraper::cCast_gG3yTMSe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_TQ2qr3Xw, 0, m, &cVar_TQ2qr3Xw_sendMessage);
}

void Heavy_SoundScraper::cPack_fNevwtaB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_x4Q1MhNj_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSlice_Ipk1vL7j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cPack_onMessage(_c, &Context(_c)->cPack_2pIV6F5w, 1, m, &cPack_2pIV6F5w_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_RsvFBTCW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_j8DWn77o, HV_BINOP_ADD, 0, m, &cBinop_j8DWn77o_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_vEfdKSmY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cPack_onMessage(_c, &Context(_c)->cPack_FtcNOzmc, 1, m, &cPack_FtcNOzmc_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_1PJ1b071_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_nEFwvtYt, HV_BINOP_ADD, 0, m, &cBinop_nEFwvtYt_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cPack_ll00wYEj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_De2IVihJ_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_YBvHZ5HH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_FPlDl04H_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_hqUD4ZwO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_RtlGDBzB, 0, m, &cVar_RtlGDBzB_sendMessage);
}

void Heavy_SoundScraper::cCast_ZFzLYajQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_KotIcBWk, 0, m, &cVar_KotIcBWk_sendMessage);
}

void Heavy_SoundScraper::cSend_R1zWKfs3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_51D9FzDZ_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_x4Q1MhNj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_FqsruA17_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_ZfY4RlH8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_FqsruA17_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_mhAeH9vC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_lroWiSB2_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_veslu42R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_X5fEAV4y, 0, m, &cPack_X5fEAV4y_sendMessage);
}

void Heavy_SoundScraper::cBinop_90PqbPBV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_ll00wYEj, 0, m, &cPack_ll00wYEj_sendMessage);
}

void Heavy_SoundScraper::cSend_afK1R6yL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_51D9FzDZ_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_Z8ooBx7L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_YBvHZ5HH, 0, m, &cPack_YBvHZ5HH_sendMessage);
}

void Heavy_SoundScraper::cBinop_DfK1hXBi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_xmLrAbUm_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_j8DWn77o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_2pIV6F5w, 0, m, &cPack_2pIV6F5w_sendMessage);
}

void Heavy_SoundScraper::cBinop_jEp7it3T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_q9r8o6My_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_nEFwvtYt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_FtcNOzmc, 0, m, &cPack_FtcNOzmc_sendMessage);
}

void Heavy_SoundScraper::cMsg_yngiNUoG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "stop");
  cSwitchcase_q9r8o6My_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_U05yaoqV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_xpTLUpRi, HV_BINOP_MULTIPLY, 1, m, &cBinop_xpTLUpRi_sendMessage);
}

void Heavy_SoundScraper::cMsg_FPlDl04H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 0.0f);
  cSlice_onMessage(_c, &Context(_c)->cSlice_vEfdKSmY, 0, m, &cSlice_vEfdKSmY_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_1PJ1b071, 0, m, &cSlice_1PJ1b071_sendMessage);
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 1);
  msg_setElementToFrom(m, 1, n, 0);
  cSlice_onMessage(_c, &Context(_c)->cSlice_vEfdKSmY, 0, m, &cSlice_vEfdKSmY_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_1PJ1b071, 0, m, &cSlice_1PJ1b071_sendMessage);
}

void Heavy_SoundScraper::cBinop_lsH4ypI4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_YBvHZ5HH, 1, m, &cPack_YBvHZ5HH_sendMessage);
}

void Heavy_SoundScraper::cBinop_YM7Tq6a5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_ll00wYEj, 1, m, &cPack_ll00wYEj_sendMessage);
}

void Heavy_SoundScraper::cMsg_De2IVihJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 0.0f);
  cSlice_onMessage(_c, &Context(_c)->cSlice_Ipk1vL7j, 0, m, &cSlice_Ipk1vL7j_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_RsvFBTCW, 0, m, &cSlice_RsvFBTCW_sendMessage);
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 1);
  msg_setElementToFrom(m, 1, n, 0);
  cSlice_onMessage(_c, &Context(_c)->cSlice_Ipk1vL7j, 0, m, &cSlice_Ipk1vL7j_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_RsvFBTCW, 0, m, &cSlice_RsvFBTCW_sendMessage);
}

void Heavy_SoundScraper::cSend_PVHRI3Z2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_FqsruA17_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_5aCja6rV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 0.0f, 0, m, &cBinop_jPLD8jzs_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_MZg0SU5F, 0, m, &cIf_MZg0SU5F_sendMessage);
}

void Heavy_SoundScraper::cCast_3WeH5dYL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_FNbsubLf, 1, m, &cDelay_FNbsubLf_sendMessage);
}

void Heavy_SoundScraper::cCast_uv0rJ7zX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_X5fEAV4y, 1, m, &cPack_X5fEAV4y_sendMessage);
}

void Heavy_SoundScraper::cCast_0PUcmcBn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_nEFwvtYt, HV_BINOP_ADD, 1, m, &cBinop_nEFwvtYt_sendMessage);
}

void Heavy_SoundScraper::cCast_R9BBiwVr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_j8DWn77o, HV_BINOP_ADD, 1, m, &cBinop_j8DWn77o_sendMessage);
}

void Heavy_SoundScraper::cCast_5Jpx55lz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_jEp7it3T, HV_BINOP_SUBTRACT, 1, m, &cBinop_jEp7it3T_sendMessage);
}

void Heavy_SoundScraper::cCast_Ctbd2VMg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_kRjgB4kN, 1, m, &cDelay_kRjgB4kN_sendMessage);
}

void Heavy_SoundScraper::cCast_OSTRbdgG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_CsLjerEM, 0, m, &cPack_CsLjerEM_sendMessage);
}

void Heavy_SoundScraper::cCast_6FwJg7V4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_rR9Sg6Vv_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_C9VowApn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_q9r8o6My_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_aRisPBxr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_rR9Sg6Vv_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_xpTLUpRi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_0PUcmcBn_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_R9BBiwVr_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_eauKBq91_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_SjlX6h7r_sendMessage);
      break;
    }
    default: {
      cVar_onMessage(_c, &Context(_c)->cVar_RtlGDBzB, 1, m, &cVar_RtlGDBzB_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_SjlX6h7r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_vd15CEQb_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_bN7opBn0_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_FUaYojlV_sendMessage);
      break;
    }
    default: {
      cSwitchcase_KPQwojb7_onMessage(_c, NULL, 0, m, NULL);
      cVar_onMessage(_c, &Context(_c)->cVar_KotIcBWk, 1, m, &cVar_KotIcBWk_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_FUaYojlV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_bLFYo1e6_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSlice_10HamewP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
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

void Heavy_SoundScraper::cSlice_zE389FZN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSwitchcase_FD8xDxpR_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_3ZC90v6W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_xpTLUpRi, HV_BINOP_MULTIPLY, 0, m, &cBinop_xpTLUpRi_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_pRepDomy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSwitchcase_bN7opBn0_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_spWHApFp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
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

void Heavy_SoundScraper::cSlice_ACr5PHjA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSwitchcase_eauKBq91_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cMsg_vd15CEQb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_RtlGDBzB, 1, m, &cVar_RtlGDBzB_sendMessage);
}

void Heavy_SoundScraper::cCast_32tWxiCE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ktp19iCs_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_bLFYo1e6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_KPQwojb7_onMessage(_c, NULL, 0, m, NULL);
  cVar_onMessage(_c, &Context(_c)->cVar_KotIcBWk, 1, m, &cVar_KotIcBWk_sendMessage);
}

void Heavy_SoundScraper::cMsg_ktp19iCs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(6);
  msg_init(m, 6, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setSymbol(m, 1, "xylo");
  msg_setFloat(m, 2, 1.0f);
  msg_setFloat(m, 3, 0.0f);
  msg_setFloat(m, 4, 0.0f);
  msg_setFloat(m, 5, 0.0f);
  cSlice_onMessage(_c, &Context(_c)->cSlice_10HamewP, 0, m, &cSlice_10HamewP_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_zE389FZN, 0, m, &cSlice_zE389FZN_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_3ZC90v6W, 0, m, &cSlice_3ZC90v6W_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_pRepDomy, 0, m, &cSlice_pRepDomy_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_spWHApFp, 0, m, &cSlice_spWHApFp_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_ACr5PHjA, 0, m, &cSlice_ACr5PHjA_sendMessage);
}

void Heavy_SoundScraper::cSlice_Eu3wobdY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_kSRdpMDa_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_LVXCfAfn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_1sKO0Wkv_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_1sKO0Wkv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_Auj2QbVY_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_Auj2QbVY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_EQm1ZcpX_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_kSRdpMDa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_dlCYsovk_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_dlCYsovk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_EeyoHP8Q_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_Tq5AG5UD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_CgIBVJmF_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_uSFpDnDg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_J7pBN7Ic, HV_BINOP_MULTIPLY, 1, m, &cBinop_J7pBN7Ic_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_b6AWpUpP, HV_BINOP_MULTIPLY, 1, m, &cBinop_b6AWpUpP_sendMessage);
}

void Heavy_SoundScraper::cSlice_7ztOTE0T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_J7pBN7Ic, HV_BINOP_MULTIPLY, 0, m, &cBinop_J7pBN7Ic_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_UDrlqyix_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_b6AWpUpP, HV_BINOP_MULTIPLY, 0, m, &cBinop_b6AWpUpP_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cMsg_CgIBVJmF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setElementToFrom(m, 2, n, 1);
  cMsg_elhZKqjH_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_elhZKqjH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 441000000.0f);
  msg_setFloat(m, 1, 10000000.0f);
}

void Heavy_SoundScraper::cBinop_J7pBN7Ic_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_Tq5AG5UD, 1, m, &cPack_Tq5AG5UD_sendMessage);
}

void Heavy_SoundScraper::cBinop_b6AWpUpP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_Tq5AG5UD, 0, m, &cPack_Tq5AG5UD_sendMessage);
}

void Heavy_SoundScraper::cMsg_LgCSZChr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 44100.0f);
  msg_setFloat(m, 1, 1000.0f);
  cSlice_onMessage(_c, &Context(_c)->cSlice_7ztOTE0T, 0, m, &cSlice_7ztOTE0T_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_UDrlqyix, 0, m, &cSlice_UDrlqyix_sendMessage);
}

void Heavy_SoundScraper::cSend_6ZZMfOaY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_veJrJ2vf_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_vq8z3D22_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 1);
  cSwitchcase_Zg9kic8X_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cSlice_bTZvq2Q6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 127.0f, 0, m, &cBinop_2u79LqYx_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_X1xg4S0T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_tksbcWnA_sendMessage);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_Ibtzu3mp_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cVar_fWyob0BP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_fxOvKXea, 1, m, &cPack_fxOvKXea_sendMessage);
}

void Heavy_SoundScraper::cVar_O14krN9r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_fxOvKXea, 0, m, &cPack_fxOvKXea_sendMessage);
}

void Heavy_SoundScraper::cPack_fxOvKXea_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_xgVBSPqe_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_kxoUtnPF_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_32tWxiCE_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_10HamewP, 0, m, &cSlice_10HamewP_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_zE389FZN, 0, m, &cSlice_zE389FZN_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_3ZC90v6W, 0, m, &cSlice_3ZC90v6W_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_pRepDomy, 0, m, &cSlice_pRepDomy_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_spWHApFp, 0, m, &cSlice_spWHApFp_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_ACr5PHjA, 0, m, &cSlice_ACr5PHjA_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_veslu42R_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_mhAeH9vC_sendMessage);
  cMsg_vq8z3D22_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_ypBEZbw8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_fWyob0BP, 0, m, &cVar_fWyob0BP_sendMessage);
}

void Heavy_SoundScraper::cCast_y6yMaUl0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_fxOvKXea, 2, m, &cPack_fxOvKXea_sendMessage);
}

void Heavy_SoundScraper::cCast_yyxaEEMG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_O14krN9r, 0, m, &cVar_O14krN9r_sendMessage);
}

void Heavy_SoundScraper::cBinop_n7JA7VIG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.4f, 0, m, &cBinop_ntnp1eKs_sendMessage);
}

void Heavy_SoundScraper::cBinop_ntnp1eKs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_MnaNVfXu_sendMessage);
}

void Heavy_SoundScraper::cBinop_2u79LqYx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_fyuU0ckQ_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_jpvTQ23W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_y6yMaUl0_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ypBEZbw8_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_yyxaEEMG_sendMessage);
}

void Heavy_SoundScraper::cBinop_8NamzPaJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.99f, 0, m, &cBinop_WXwnrMgZ_sendMessage);
}

void Heavy_SoundScraper::cBinop_WXwnrMgZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_jpvTQ23W, HV_BINOP_MULTIPLY, 1, m, &cBinop_jpvTQ23W_sendMessage);
}

void Heavy_SoundScraper::cCast_tksbcWnA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_H0RdKRql_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_xgVBSPqe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_9vtroTVf_onMessage(_c, NULL, 0, m, NULL);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_FENTk4Ts_sendMessage);
}

void Heavy_SoundScraper::cCast_kxoUtnPF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_lRhqpZHN_sendMessage);
}

void Heavy_SoundScraper::cSend_oacxwXvL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_8D8z32Fi_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_BD7vQuBs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_dLBuuyyH_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_d0IYt5DF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_jpvTQ23W, HV_BINOP_MULTIPLY, 0, m, &cBinop_jpvTQ23W_sendMessage);
}

void Heavy_SoundScraper::cSend_fyuU0ckQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_oCRfDneS_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_iYWKzmg2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 44100.0f);
  cSend_6ZZMfOaY_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_Gdzb0tWA_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_04mY4PiZ, 0, m, &cSlice_04mY4PiZ_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_aNGIPKtI, 0, m, &cRandom_aNGIPKtI_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_JOs4wHWz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_n54sd9tV_sendMessage);
}

void Heavy_SoundScraper::cUnop_n54sd9tV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_1aDqakr1_sendMessage);
}

void Heavy_SoundScraper::cRandom_aNGIPKtI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_JOs4wHWz_sendMessage);
}

void Heavy_SoundScraper::cSlice_04mY4PiZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_aNGIPKtI, 1, m, &cRandom_aNGIPKtI_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_rRSfiO3D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_rs14SgKQ, HV_BINOP_DIVIDE, 0, m, &cBinop_rs14SgKQ_sendMessage);
}

void Heavy_SoundScraper::cBinop_ZTH1IIs8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_SKTQMvNC_sendMessage);
}

void Heavy_SoundScraper::cBinop_SKTQMvNC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_gjIXCRlq, HV_BINOP_POW, 1, m, &cBinop_gjIXCRlq_sendMessage);
  cMsg_a0qbx6l9_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_gjIXCRlq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_rRSfiO3D_sendMessage);
}

void Heavy_SoundScraper::cMsg_a0qbx6l9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_gjIXCRlq, HV_BINOP_POW, 0, m, &cBinop_gjIXCRlq_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_8Om8W8Tm_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_FhCXbuPJ, 0, m, &cSlice_FhCXbuPJ_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_MPodtBWR, 0, m, &cRandom_MPodtBWR_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_Bpsc0EsX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_21lPVbq8_sendMessage);
}

void Heavy_SoundScraper::cUnop_21lPVbq8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_abhcYwsv_sendMessage);
}

void Heavy_SoundScraper::cRandom_MPodtBWR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 15.0f, 0, m, &cBinop_Bpsc0EsX_sendMessage);
}

void Heavy_SoundScraper::cSlice_FhCXbuPJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_MPodtBWR, 1, m, &cRandom_MPodtBWR_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_JpbPnq7o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSend_DQYA42rY_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_TrBGFBQn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSend_yIYI5NWo_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cUnop_DiezLtWC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_SbjKVBag, 0, m, &cPack_SbjKVBag_sendMessage);
}

void Heavy_SoundScraper::cUnop_sY9Bconh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_ywJFQ3AM, 0, m, &cPack_ywJFQ3AM_sendMessage);
}

void Heavy_SoundScraper::cPack_ywJFQ3AM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_e3XeXHT4, 0, m, NULL);
}

void Heavy_SoundScraper::cPack_SbjKVBag_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_hevpodVb, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_iKiUIj4H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_DiezLtWC_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_SIN, m, &cUnop_sY9Bconh_sendMessage);
}

void Heavy_SoundScraper::cMsg_thE0RbRj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.5f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_iKiUIj4H_sendMessage);
}

void Heavy_SoundScraper::cCast_7nnkHHMI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cVar_py55N7Ov_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_1StaZrop_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ITyiWnDx_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_T7525ouE_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_bmBt1gFg_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_az7Px3Rm_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_az7Px3Rm_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_o797bv2q, 1, m, &cDelay_o797bv2q_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_z3Y1k8bD_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cDelay_o797bv2q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_o797bv2q, m);
  cVar_onMessage(_c, &Context(_c)->cVar_yjQBMTRF, 0, m, &cVar_yjQBMTRF_sendMessage);
}

void Heavy_SoundScraper::cMsg_az7Px3Rm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_o797bv2q, 0, m, &cDelay_o797bv2q_sendMessage);
}

void Heavy_SoundScraper::cCast_z3Y1k8bD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_o797bv2q, 0, m, &cDelay_o797bv2q_sendMessage);
}

void Heavy_SoundScraper::cVar_yjQBMTRF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_vewcpFRB_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_vvkuXbf3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_py55N7Ov, 0, m, &cVar_py55N7Ov_sendMessage);
}

void Heavy_SoundScraper::cSend_DW5KEasV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cSend_r3FN4DtM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_s2w97Arv_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_aEuPwSz9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 25.0f);
  cSend_DW5KEasV_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_YjglOL77_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 4000.0f);
  cSend_r3FN4DtM_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_GXAJEH3S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_QnMQhgXf_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_vncNQ8U9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSend_GXAJEH3S_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_t8Zz4frm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cSend_26zRrYBF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_s2w97Arv_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_XFXaSDTK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_QnMQhgXf_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_Y82nMQYW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 25.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_IvF9IHet, 0, m, NULL);
}

void Heavy_SoundScraper::cMsg_vewcpFRB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 0);
  sLine_onMessage(_c, &Context(_c)->sLine_IvF9IHet, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_ITyiWnDx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_yjQBMTRF, 1, m, &cVar_yjQBMTRF_sendMessage);
}

void Heavy_SoundScraper::cCast_T7525ouE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_bmBt1gFg_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_1StaZrop_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Y82nMQYW_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_ZFU0OBRd_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_akvWdkUf, 0, m, &cSlice_akvWdkUf_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cVar_33TIBgYM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_2VzgbZWh_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSystem_szDCK4GU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 2.0f, 0, m, &cBinop_NTidffGn_sendMessage);
}

void Heavy_SoundScraper::cBinop_NTidffGn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_WyRbmsYM, m);
}

void Heavy_SoundScraper::cMsg_2VzgbZWh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_szDCK4GU_sendMessage);
}

void Heavy_SoundScraper::cSlice_akvWdkUf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sTabread_onMessage(_c, &Context(_c)->sTabread_VVNnBoCl, 1, m, NULL);
      sTabread_onMessage(_c, &Context(_c)->sTabread_RKhlvguZ, 1, m, NULL);
      cVar_onMessage(_c, &Context(_c)->cVar_33TIBgYM, 0, m, &cVar_33TIBgYM_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cVar_KPNKEGI6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_fe8EG0PJ, 0, m, &cPack_fe8EG0PJ_sendMessage);
}

void Heavy_SoundScraper::cVar_pgdapD11_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 10000000.0f, 0, m, &cBinop_v1WdPsZ8_sendMessage);
}

void Heavy_SoundScraper::cIf_VeeDnSqp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_ABS, m, &cUnop_BYva1BL0_sendMessage);
      break;
    }
    case 1: {
      cVar_onMessage(_c, &Context(_c)->cVar_pgdapD11, 1, m, &cVar_pgdapD11_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_ZdrTgjvP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_VeeDnSqp, 1, m, &cIf_VeeDnSqp_sendMessage);
}

void Heavy_SoundScraper::cVar_55Q3cf9F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 10000000.0f, 0, m, &cBinop_iq23fPJp_sendMessage);
}

void Heavy_SoundScraper::cUnop_BYva1BL0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_55Q3cf9F, 1, m, &cVar_55Q3cf9F_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_Pj6508FX_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_iK8KI30I_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_gxU6zki7_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_iK8KI30I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_pgdapD11, 0, m, &cVar_pgdapD11_sendMessage);
}

void Heavy_SoundScraper::cCast_gxU6zki7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_55Q3cf9F, 0, m, &cVar_55Q3cf9F_sendMessage);
}

void Heavy_SoundScraper::cVar_NPVSjjQp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_LESS_THAN, 0.0f, 0, m, &cBinop_7EuOMWHU_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_htEA80cb_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_yXphWWNE_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_yXphWWNE_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_Y1Ldvfgx, 1, m, &cDelay_Y1Ldvfgx_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_prkteIfF_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cDelay_Y1Ldvfgx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Y1Ldvfgx, m);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_z2MXDyxa_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_JiY1dgFQ_sendMessage);
}

void Heavy_SoundScraper::cMsg_yXphWWNE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_Y1Ldvfgx, 0, m, &cDelay_Y1Ldvfgx_sendMessage);
}

void Heavy_SoundScraper::cCast_prkteIfF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Y1Ldvfgx, 0, m, &cDelay_Y1Ldvfgx_sendMessage);
}

void Heavy_SoundScraper::cPack_fv8q4ynA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_CzAFopkb_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_S1nkqARp_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_j0o1MiCe_sendMessage);
      break;
    }
    default: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_g78aXXDa, HV_BINOP_SUBTRACT, 0, m, &cBinop_g78aXXDa_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_j0o1MiCe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_UHpLOyLq_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_fQupbF7t_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_aHIehstT_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_aHIehstT_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_IdLEcmj0, 1, m, &cDelay_IdLEcmj0_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_4tDBkdd6_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cDelay_IdLEcmj0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_IdLEcmj0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_nQblx1CA_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_yYyIeysw_sendMessage);
}

void Heavy_SoundScraper::cMsg_aHIehstT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_IdLEcmj0, 0, m, &cDelay_IdLEcmj0_sendMessage);
}

void Heavy_SoundScraper::cCast_4tDBkdd6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_IdLEcmj0, 0, m, &cDelay_IdLEcmj0_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_vH06frSs_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_x6Z9DDrc_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_x6Z9DDrc_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_C9wFeNw7, 1, m, &cDelay_C9wFeNw7_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_JssFGmcT_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cDelay_C9wFeNw7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_C9wFeNw7, m);
}

void Heavy_SoundScraper::cMsg_x6Z9DDrc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_C9wFeNw7, 0, m, &cDelay_C9wFeNw7_sendMessage);
}

void Heavy_SoundScraper::cCast_JssFGmcT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_C9wFeNw7, 0, m, &cDelay_C9wFeNw7_sendMessage);
}

void Heavy_SoundScraper::cPack_cb6HbLyS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_wxxde4Q6_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_tpzyTrBc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_2lNMCOTI_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_mtB46fWX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_AicOqMoj_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_dphh1rEn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_LU4SqPa9, HV_BINOP_DIVIDE, 1, m, &cBinop_LU4SqPa9_sendMessage);
}

void Heavy_SoundScraper::cVar_4LyPXZrS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_LU4SqPa9, HV_BINOP_DIVIDE, 0, m, &cBinop_LU4SqPa9_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_0g0nNgZv_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0xFFFFFFFF: { // "bang"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_BGSi6rz4_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_cnIMaBjg_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_gjuhGDJt_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_1Fk2XmNF_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_BGSi6rz4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_dphh1rEn, 0, m, &cVar_dphh1rEn_sendMessage);
}

void Heavy_SoundScraper::cCast_cnIMaBjg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_4LyPXZrS, 0, m, &cVar_4LyPXZrS_sendMessage);
}

void Heavy_SoundScraper::cCast_1Fk2XmNF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_4LyPXZrS, 0, m, &cVar_4LyPXZrS_sendMessage);
}

void Heavy_SoundScraper::cCast_gjuhGDJt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_dphh1rEn, 0, m, &cVar_dphh1rEn_sendMessage);
}

void Heavy_SoundScraper::cPack_fe8EG0PJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_1sVlYbS7_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSlice_NS1EWbah_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cPack_onMessage(_c, &Context(_c)->cPack_fv8q4ynA, 1, m, &cPack_fv8q4ynA_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_8fvTjkys_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_yQjKfd9L, HV_BINOP_ADD, 0, m, &cBinop_yQjKfd9L_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_ml782NaG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cPack_onMessage(_c, &Context(_c)->cPack_cb6HbLyS, 1, m, &cPack_cb6HbLyS_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_njaArJ8J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_bSyFpmLK, HV_BINOP_ADD, 0, m, &cBinop_bSyFpmLK_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cPack_tNmyHW7N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_iNmKyueM_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_X1AiotjA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_AV0oDw98_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_JiY1dgFQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_KPNKEGI6, 0, m, &cVar_KPNKEGI6_sendMessage);
}

void Heavy_SoundScraper::cCast_z2MXDyxa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_NPVSjjQp, 0, m, &cVar_NPVSjjQp_sendMessage);
}

void Heavy_SoundScraper::cSend_CzAFopkb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_tKYFMlpy_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_1sVlYbS7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_Z8qTBs1F_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_2lNMCOTI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_Z8qTBs1F_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_QWX6oNzr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_htEA80cb_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_6HJ0d9Hh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_tpzyTrBc, 0, m, &cPack_tpzyTrBc_sendMessage);
}

void Heavy_SoundScraper::cBinop_v1WdPsZ8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_tNmyHW7N, 0, m, &cPack_tNmyHW7N_sendMessage);
}

void Heavy_SoundScraper::cSend_wxxde4Q6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_tKYFMlpy_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_iq23fPJp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_X1AiotjA, 0, m, &cPack_X1AiotjA_sendMessage);
}

void Heavy_SoundScraper::cBinop_7EuOMWHU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_Pj6508FX_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_yQjKfd9L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_fv8q4ynA, 0, m, &cPack_fv8q4ynA_sendMessage);
}

void Heavy_SoundScraper::cBinop_g78aXXDa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_fQupbF7t_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_bSyFpmLK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_cb6HbLyS, 0, m, &cPack_cb6HbLyS_sendMessage);
}

void Heavy_SoundScraper::cMsg_UHpLOyLq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "stop");
  cSwitchcase_fQupbF7t_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_BydhZp18_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_SfHhnon1, HV_BINOP_MULTIPLY, 1, m, &cBinop_SfHhnon1_sendMessage);
}

void Heavy_SoundScraper::cMsg_AV0oDw98_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 0.0f);
  cSlice_onMessage(_c, &Context(_c)->cSlice_ml782NaG, 0, m, &cSlice_ml782NaG_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_njaArJ8J, 0, m, &cSlice_njaArJ8J_sendMessage);
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 1);
  msg_setElementToFrom(m, 1, n, 0);
  cSlice_onMessage(_c, &Context(_c)->cSlice_ml782NaG, 0, m, &cSlice_ml782NaG_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_njaArJ8J, 0, m, &cSlice_njaArJ8J_sendMessage);
}

void Heavy_SoundScraper::cBinop_noThb7jC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_X1AiotjA, 1, m, &cPack_X1AiotjA_sendMessage);
}

void Heavy_SoundScraper::cBinop_fZeP7CoA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_tNmyHW7N, 1, m, &cPack_tNmyHW7N_sendMessage);
}

void Heavy_SoundScraper::cMsg_iNmKyueM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 0.0f);
  cSlice_onMessage(_c, &Context(_c)->cSlice_NS1EWbah, 0, m, &cSlice_NS1EWbah_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_8fvTjkys, 0, m, &cSlice_8fvTjkys_sendMessage);
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 1);
  msg_setElementToFrom(m, 1, n, 0);
  cSlice_onMessage(_c, &Context(_c)->cSlice_NS1EWbah, 0, m, &cSlice_NS1EWbah_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_8fvTjkys, 0, m, &cSlice_8fvTjkys_sendMessage);
}

void Heavy_SoundScraper::cSend_AicOqMoj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_Z8qTBs1F_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_LU4SqPa9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 0.0f, 0, m, &cBinop_ZdrTgjvP_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_VeeDnSqp, 0, m, &cIf_VeeDnSqp_sendMessage);
}

void Heavy_SoundScraper::cCast_yW8kHc4M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Y1Ldvfgx, 1, m, &cDelay_Y1Ldvfgx_sendMessage);
}

void Heavy_SoundScraper::cCast_HqRqtOEc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_tpzyTrBc, 1, m, &cPack_tpzyTrBc_sendMessage);
}

void Heavy_SoundScraper::cCast_JMxROElG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_bSyFpmLK, HV_BINOP_ADD, 1, m, &cBinop_bSyFpmLK_sendMessage);
}

void Heavy_SoundScraper::cCast_1u52XTry_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_yQjKfd9L, HV_BINOP_ADD, 1, m, &cBinop_yQjKfd9L_sendMessage);
}

void Heavy_SoundScraper::cCast_khmHZvTM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_C9wFeNw7, 1, m, &cDelay_C9wFeNw7_sendMessage);
}

void Heavy_SoundScraper::cCast_jTP4r5QV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_g78aXXDa, HV_BINOP_SUBTRACT, 1, m, &cBinop_g78aXXDa_sendMessage);
}

void Heavy_SoundScraper::cCast_nQblx1CA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_vH06frSs_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_yYyIeysw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_mtB46fWX, 0, m, &cPack_mtB46fWX_sendMessage);
}

void Heavy_SoundScraper::cCast_Snvyherv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_vH06frSs_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_4p3sLUlq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_fQupbF7t_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_SfHhnon1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_JMxROElG_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_1u52XTry_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_aYOEueJL_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Rc7vVxgk_sendMessage);
      break;
    }
    default: {
      cVar_onMessage(_c, &Context(_c)->cVar_KPNKEGI6, 1, m, &cVar_KPNKEGI6_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_Rc7vVxgk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_1705K8y4_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_TnSLKhke_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Nivn93kx_sendMessage);
      break;
    }
    default: {
      cSwitchcase_0g0nNgZv_onMessage(_c, NULL, 0, m, NULL);
      cVar_onMessage(_c, &Context(_c)->cVar_NPVSjjQp, 1, m, &cVar_NPVSjjQp_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_Nivn93kx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_t0st3BFh_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSlice_SH7sAkGK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
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

void Heavy_SoundScraper::cSlice_3KUbv5pL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSwitchcase_S1nkqARp_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_jLpSeOM5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_SfHhnon1, HV_BINOP_MULTIPLY, 0, m, &cBinop_SfHhnon1_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_r7XmmRWB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSwitchcase_TnSLKhke_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_GMT7DeWn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
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

void Heavy_SoundScraper::cSlice_fqzBitNk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSwitchcase_aYOEueJL_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cMsg_1705K8y4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_KPNKEGI6, 1, m, &cVar_KPNKEGI6_sendMessage);
}

void Heavy_SoundScraper::cCast_caTtJFC3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_B7GDTbfh_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_t0st3BFh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_0g0nNgZv_onMessage(_c, NULL, 0, m, NULL);
  cVar_onMessage(_c, &Context(_c)->cVar_NPVSjjQp, 1, m, &cVar_NPVSjjQp_sendMessage);
}

void Heavy_SoundScraper::cMsg_B7GDTbfh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(6);
  msg_init(m, 6, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setSymbol(m, 1, "xylo");
  msg_setFloat(m, 2, 1.0f);
  msg_setFloat(m, 3, 0.0f);
  msg_setFloat(m, 4, 0.0f);
  msg_setFloat(m, 5, 0.0f);
  cSlice_onMessage(_c, &Context(_c)->cSlice_SH7sAkGK, 0, m, &cSlice_SH7sAkGK_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_3KUbv5pL, 0, m, &cSlice_3KUbv5pL_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_jLpSeOM5, 0, m, &cSlice_jLpSeOM5_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_r7XmmRWB, 0, m, &cSlice_r7XmmRWB_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_GMT7DeWn, 0, m, &cSlice_GMT7DeWn_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_fqzBitNk, 0, m, &cSlice_fqzBitNk_sendMessage);
}

void Heavy_SoundScraper::cSlice_S2wPoZju_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_11WHsR68_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_cwh30pIu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_TcdKG24j_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_TcdKG24j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_knxRczLN_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_knxRczLN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_IOBCdr60_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_11WHsR68_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_tgEGEokk_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_tgEGEokk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_5WsxjXS0_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_wC1rXIon_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_9lb3cTHx_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_LBO772qc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_V0d3TTgb, HV_BINOP_MULTIPLY, 1, m, &cBinop_V0d3TTgb_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_Yjb9lhHA, HV_BINOP_MULTIPLY, 1, m, &cBinop_Yjb9lhHA_sendMessage);
}

void Heavy_SoundScraper::cSlice_X9dFCfGi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_V0d3TTgb, HV_BINOP_MULTIPLY, 0, m, &cBinop_V0d3TTgb_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_83WO8NMr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_Yjb9lhHA, HV_BINOP_MULTIPLY, 0, m, &cBinop_Yjb9lhHA_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cMsg_9lb3cTHx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setElementToFrom(m, 2, n, 1);
  cMsg_Ax63QgMR_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_Ax63QgMR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 441000000.0f);
  msg_setFloat(m, 1, 10000000.0f);
}

void Heavy_SoundScraper::cBinop_V0d3TTgb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_wC1rXIon, 1, m, &cPack_wC1rXIon_sendMessage);
}

void Heavy_SoundScraper::cBinop_Yjb9lhHA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_wC1rXIon, 0, m, &cPack_wC1rXIon_sendMessage);
}

void Heavy_SoundScraper::cMsg_I1pu5xM1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 44100.0f);
  msg_setFloat(m, 1, 1000.0f);
  cSlice_onMessage(_c, &Context(_c)->cSlice_X9dFCfGi, 0, m, &cSlice_X9dFCfGi_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_83WO8NMr, 0, m, &cSlice_83WO8NMr_sendMessage);
}

void Heavy_SoundScraper::cSend_cCeDjpls_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_MzEKMcDD_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_BxlPbfSI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 1);
  cSwitchcase_ZFU0OBRd_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cSlice_XGiwhxDP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 127.0f, 0, m, &cBinop_kMDKgV3G_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_LeeZKd24_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_o0jbfXdJ_sendMessage);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_ZTH1IIs8_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cVar_dRJoBjiU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_zwii0lPP, 1, m, &cPack_zwii0lPP_sendMessage);
}

void Heavy_SoundScraper::cVar_boSonE4l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_zwii0lPP, 0, m, &cPack_zwii0lPP_sendMessage);
}

void Heavy_SoundScraper::cPack_zwii0lPP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_NMjBIRWh_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_C9aoFGqw_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_caTtJFC3_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_SH7sAkGK, 0, m, &cSlice_SH7sAkGK_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_3KUbv5pL, 0, m, &cSlice_3KUbv5pL_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_jLpSeOM5, 0, m, &cSlice_jLpSeOM5_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_r7XmmRWB, 0, m, &cSlice_r7XmmRWB_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_GMT7DeWn, 0, m, &cSlice_GMT7DeWn_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_fqzBitNk, 0, m, &cSlice_fqzBitNk_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_6HJ0d9Hh_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_QWX6oNzr_sendMessage);
  cMsg_BxlPbfSI_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_qqD0HndH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_dRJoBjiU, 0, m, &cVar_dRJoBjiU_sendMessage);
}

void Heavy_SoundScraper::cCast_GO1vYFm4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_zwii0lPP, 2, m, &cPack_zwii0lPP_sendMessage);
}

void Heavy_SoundScraper::cCast_ew5YgIxg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_boSonE4l, 0, m, &cVar_boSonE4l_sendMessage);
}

void Heavy_SoundScraper::cBinop_1aDqakr1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.4f, 0, m, &cBinop_pTuAeTrj_sendMessage);
}

void Heavy_SoundScraper::cBinop_pTuAeTrj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_iKiUIj4H_sendMessage);
}

void Heavy_SoundScraper::cBinop_kMDKgV3G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_Rd8YaTrx_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_m6inSF8a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_GO1vYFm4_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_qqD0HndH_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ew5YgIxg_sendMessage);
}

void Heavy_SoundScraper::cBinop_abhcYwsv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.99f, 0, m, &cBinop_ylkqDq38_sendMessage);
}

void Heavy_SoundScraper::cBinop_ylkqDq38_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_m6inSF8a, HV_BINOP_MULTIPLY, 1, m, &cBinop_m6inSF8a_sendMessage);
}

void Heavy_SoundScraper::cCast_o0jbfXdJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_8Om8W8Tm_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_NMjBIRWh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_Gdzb0tWA_onMessage(_c, NULL, 0, m, NULL);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_7nnkHHMI_sendMessage);
}

void Heavy_SoundScraper::cCast_C9aoFGqw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_vvkuXbf3_sendMessage);
}

void Heavy_SoundScraper::cSend_yIYI5NWo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_oY8i2pLw_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_DQYA42rY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_bj2r78Uf_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_rs14SgKQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_m6inSF8a, HV_BINOP_MULTIPLY, 0, m, &cBinop_m6inSF8a_sendMessage);
}

void Heavy_SoundScraper::cSend_Rd8YaTrx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_spCWf3Qz_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_qQaRTtiV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 44100.0f);
  cSend_cCeDjpls_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_jBwh39U3_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_KhBwgPNG, 0, m, &cSlice_KhBwgPNG_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_JnTQZFju, 0, m, &cRandom_JnTQZFju_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_9YnHJw9x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_v0CAZa1p_sendMessage);
}

void Heavy_SoundScraper::cUnop_v0CAZa1p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_5UNMft2F_sendMessage);
}

void Heavy_SoundScraper::cRandom_JnTQZFju_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_9YnHJw9x_sendMessage);
}

void Heavy_SoundScraper::cSlice_KhBwgPNG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_JnTQZFju, 1, m, &cRandom_JnTQZFju_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_nbIfHtzz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6AC6W0C9, HV_BINOP_DIVIDE, 0, m, &cBinop_6AC6W0C9_sendMessage);
}

void Heavy_SoundScraper::cBinop_5DHiEBYN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_SDSYiMXw_sendMessage);
}

void Heavy_SoundScraper::cBinop_SDSYiMXw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_IJ60b2Rh, HV_BINOP_POW, 1, m, &cBinop_IJ60b2Rh_sendMessage);
  cMsg_3GkIiULz_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_IJ60b2Rh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_nbIfHtzz_sendMessage);
}

void Heavy_SoundScraper::cMsg_3GkIiULz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_IJ60b2Rh, HV_BINOP_POW, 0, m, &cBinop_IJ60b2Rh_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_EolvsM8B_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_xYCcPSeP, 0, m, &cSlice_xYCcPSeP_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_ihFMj5cS, 0, m, &cRandom_ihFMj5cS_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_AvH9hhQr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_juJIyufa_sendMessage);
}

void Heavy_SoundScraper::cUnop_juJIyufa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_G3LWoF0Y_sendMessage);
}

void Heavy_SoundScraper::cRandom_ihFMj5cS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 15.0f, 0, m, &cBinop_AvH9hhQr_sendMessage);
}

void Heavy_SoundScraper::cSlice_xYCcPSeP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_ihFMj5cS, 1, m, &cRandom_ihFMj5cS_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_qBXnUcR4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSend_ZrQ8XCz2_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_cSjjEiCm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSend_DonTFUEF_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cUnop_KkxMVT5S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_pFdbxRaA, 0, m, &cPack_pFdbxRaA_sendMessage);
}

void Heavy_SoundScraper::cUnop_Ck7eFHgU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_XN6Ia42e, 0, m, &cPack_XN6Ia42e_sendMessage);
}

void Heavy_SoundScraper::cPack_XN6Ia42e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_2fh87dfQ, 0, m, NULL);
}

void Heavy_SoundScraper::cPack_pFdbxRaA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_GuV54yvL, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_h7YCxOeG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_KkxMVT5S_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_SIN, m, &cUnop_Ck7eFHgU_sendMessage);
}

void Heavy_SoundScraper::cMsg_H9otBfi4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.5f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_h7YCxOeG_sendMessage);
}

void Heavy_SoundScraper::cCast_xNKgaM2C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cVar_lZjdGFHS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_uNY5NryI_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_8btUYpn0_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_lQnKG2Id_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_LcxME8Wk_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_TYSh09Sp_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_TYSh09Sp_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_mABdZ2AB, 1, m, &cDelay_mABdZ2AB_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_hJSBORMH_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cDelay_mABdZ2AB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_mABdZ2AB, m);
  cVar_onMessage(_c, &Context(_c)->cVar_x2FyupTW, 0, m, &cVar_x2FyupTW_sendMessage);
}

void Heavy_SoundScraper::cMsg_TYSh09Sp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_mABdZ2AB, 0, m, &cDelay_mABdZ2AB_sendMessage);
}

void Heavy_SoundScraper::cCast_hJSBORMH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_mABdZ2AB, 0, m, &cDelay_mABdZ2AB_sendMessage);
}

void Heavy_SoundScraper::cVar_x2FyupTW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_jLThNNa9_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_wh3HIg3H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_lZjdGFHS, 0, m, &cVar_lZjdGFHS_sendMessage);
}

void Heavy_SoundScraper::cSend_vWEGzxXA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cSend_VvjTXZ76_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_dV8bOv46_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_s8EpBLai_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 25.0f);
  cSend_vWEGzxXA_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_gTjcSgzI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 4000.0f);
  cSend_VvjTXZ76_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_9TcrtHOT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_6rMjBsDU_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_4iFEUH0u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSend_9TcrtHOT_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_Iy2i0OXs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cSend_McP6xgQH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_dV8bOv46_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_LR8eyBbn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_6rMjBsDU_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_mVA32Grm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 25.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_zrBuOQF3, 0, m, NULL);
}

void Heavy_SoundScraper::cMsg_jLThNNa9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 0);
  sLine_onMessage(_c, &Context(_c)->sLine_zrBuOQF3, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_8btUYpn0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_x2FyupTW, 1, m, &cVar_x2FyupTW_sendMessage);
}

void Heavy_SoundScraper::cCast_lQnKG2Id_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_LcxME8Wk_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_uNY5NryI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_mVA32Grm_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_hfU8WMUF_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_gCCvqliF, 0, m, &cSlice_gCCvqliF_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cVar_zVNxjGY9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_2WI5lYvL_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSystem_TqvnTt9b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 2.0f, 0, m, &cBinop_BxYYODsf_sendMessage);
}

void Heavy_SoundScraper::cBinop_BxYYODsf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_5vbSjb3z, m);
}

void Heavy_SoundScraper::cMsg_2WI5lYvL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_TqvnTt9b_sendMessage);
}

void Heavy_SoundScraper::cSlice_gCCvqliF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sTabread_onMessage(_c, &Context(_c)->sTabread_teeVnAf5, 1, m, NULL);
      sTabread_onMessage(_c, &Context(_c)->sTabread_e9K0lSYN, 1, m, NULL);
      cVar_onMessage(_c, &Context(_c)->cVar_zVNxjGY9, 0, m, &cVar_zVNxjGY9_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cVar_iuVpGF7e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_aRU3bjzn, 0, m, &cPack_aRU3bjzn_sendMessage);
}

void Heavy_SoundScraper::cVar_b43vKyAV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 10000000.0f, 0, m, &cBinop_bDbI2c5L_sendMessage);
}

void Heavy_SoundScraper::cIf_o9JRawQV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_ABS, m, &cUnop_bRKbE5RM_sendMessage);
      break;
    }
    case 1: {
      cVar_onMessage(_c, &Context(_c)->cVar_b43vKyAV, 1, m, &cVar_b43vKyAV_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_twdrpU5o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_o9JRawQV, 1, m, &cIf_o9JRawQV_sendMessage);
}

void Heavy_SoundScraper::cVar_VBFU3Haf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 10000000.0f, 0, m, &cBinop_8yK5xDET_sendMessage);
}

void Heavy_SoundScraper::cUnop_bRKbE5RM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_VBFU3Haf, 1, m, &cVar_VBFU3Haf_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_RazW1EZR_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_hNe5haIE_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_rS23CUAM_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_hNe5haIE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_b43vKyAV, 0, m, &cVar_b43vKyAV_sendMessage);
}

void Heavy_SoundScraper::cCast_rS23CUAM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_VBFU3Haf, 0, m, &cVar_VBFU3Haf_sendMessage);
}

void Heavy_SoundScraper::cVar_wtANnlDz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_LESS_THAN, 0.0f, 0, m, &cBinop_ZD2xPhhJ_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_vph8Ajsw_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_a7BmqCed_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_a7BmqCed_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_0UZDIhlT, 1, m, &cDelay_0UZDIhlT_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Eq9Y7lXl_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cDelay_0UZDIhlT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_0UZDIhlT, m);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_bkfg8mmI_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_aVJwOb3u_sendMessage);
}

void Heavy_SoundScraper::cMsg_a7BmqCed_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_0UZDIhlT, 0, m, &cDelay_0UZDIhlT_sendMessage);
}

void Heavy_SoundScraper::cCast_Eq9Y7lXl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_0UZDIhlT, 0, m, &cDelay_0UZDIhlT_sendMessage);
}

void Heavy_SoundScraper::cPack_itfmeIXz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_zaVUvPw6_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_Nj8JEoHK_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_311EL5pQ_sendMessage);
      break;
    }
    default: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_9uliDmoL, HV_BINOP_SUBTRACT, 0, m, &cBinop_9uliDmoL_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_311EL5pQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_4LfEogzw_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_abQeg73E_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_vPCRTBrQ_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_vPCRTBrQ_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_ohRZNwRJ, 1, m, &cDelay_ohRZNwRJ_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_kEynnW9a_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cDelay_ohRZNwRJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_ohRZNwRJ, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Da0e1nsV_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_J2bDH2r3_sendMessage);
}

void Heavy_SoundScraper::cMsg_vPCRTBrQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_ohRZNwRJ, 0, m, &cDelay_ohRZNwRJ_sendMessage);
}

void Heavy_SoundScraper::cCast_kEynnW9a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_ohRZNwRJ, 0, m, &cDelay_ohRZNwRJ_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_KmUqyisZ_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_s4ODexd3_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_s4ODexd3_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_4DWQ6dTC, 1, m, &cDelay_4DWQ6dTC_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_NRpzUGu8_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cDelay_4DWQ6dTC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_4DWQ6dTC, m);
}

void Heavy_SoundScraper::cMsg_s4ODexd3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_4DWQ6dTC, 0, m, &cDelay_4DWQ6dTC_sendMessage);
}

void Heavy_SoundScraper::cCast_NRpzUGu8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_4DWQ6dTC, 0, m, &cDelay_4DWQ6dTC_sendMessage);
}

void Heavy_SoundScraper::cPack_E8COPE7k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_HZYskzPb_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_J5q7sQ5W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_05xf2ST1_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_9uoQwgtp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_NBvRV1E3_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_ZL2NtQkw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_GZOBW3aB, HV_BINOP_DIVIDE, 1, m, &cBinop_GZOBW3aB_sendMessage);
}

void Heavy_SoundScraper::cVar_cCq9U32x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_GZOBW3aB, HV_BINOP_DIVIDE, 0, m, &cBinop_GZOBW3aB_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_AGI5JLZo_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0xFFFFFFFF: { // "bang"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_2n9bY7I8_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_CkWIGfiT_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_wHJFEer3_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ezNHYoKI_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_2n9bY7I8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ZL2NtQkw, 0, m, &cVar_ZL2NtQkw_sendMessage);
}

void Heavy_SoundScraper::cCast_CkWIGfiT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_cCq9U32x, 0, m, &cVar_cCq9U32x_sendMessage);
}

void Heavy_SoundScraper::cCast_wHJFEer3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ZL2NtQkw, 0, m, &cVar_ZL2NtQkw_sendMessage);
}

void Heavy_SoundScraper::cCast_ezNHYoKI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_cCq9U32x, 0, m, &cVar_cCq9U32x_sendMessage);
}

void Heavy_SoundScraper::cPack_aRU3bjzn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_1R2fmXLQ_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSlice_060v7k4E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cPack_onMessage(_c, &Context(_c)->cPack_itfmeIXz, 1, m, &cPack_itfmeIXz_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_GEUTtpjf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_LSuSl3Tn, HV_BINOP_ADD, 0, m, &cBinop_LSuSl3Tn_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_h4FOeNEG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cPack_onMessage(_c, &Context(_c)->cPack_E8COPE7k, 1, m, &cPack_E8COPE7k_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_yU4FZwGD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_rFhHdy3I, HV_BINOP_ADD, 0, m, &cBinop_rFhHdy3I_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cPack_UH95E8FT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_POTsmzaY_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_i65kIUnR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_DZfKnRBR_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_aVJwOb3u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_iuVpGF7e, 0, m, &cVar_iuVpGF7e_sendMessage);
}

void Heavy_SoundScraper::cCast_bkfg8mmI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_wtANnlDz, 0, m, &cVar_wtANnlDz_sendMessage);
}

void Heavy_SoundScraper::cSend_zaVUvPw6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_7xvPxd0G_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_1R2fmXLQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_K4HZG2wh_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_05xf2ST1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_K4HZG2wh_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_Z19Muuke_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_vph8Ajsw_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_irZ8YKhW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_J5q7sQ5W, 0, m, &cPack_J5q7sQ5W_sendMessage);
}

void Heavy_SoundScraper::cBinop_bDbI2c5L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_UH95E8FT, 0, m, &cPack_UH95E8FT_sendMessage);
}

void Heavy_SoundScraper::cSend_HZYskzPb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_7xvPxd0G_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_8yK5xDET_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_i65kIUnR, 0, m, &cPack_i65kIUnR_sendMessage);
}

void Heavy_SoundScraper::cBinop_ZD2xPhhJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_RazW1EZR_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_LSuSl3Tn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_itfmeIXz, 0, m, &cPack_itfmeIXz_sendMessage);
}

void Heavy_SoundScraper::cBinop_9uliDmoL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_abQeg73E_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_rFhHdy3I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_E8COPE7k, 0, m, &cPack_E8COPE7k_sendMessage);
}

void Heavy_SoundScraper::cMsg_4LfEogzw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "stop");
  cSwitchcase_abQeg73E_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_GekOn0DA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Lt6LUj4q, HV_BINOP_MULTIPLY, 1, m, &cBinop_Lt6LUj4q_sendMessage);
}

void Heavy_SoundScraper::cMsg_DZfKnRBR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 0.0f);
  cSlice_onMessage(_c, &Context(_c)->cSlice_h4FOeNEG, 0, m, &cSlice_h4FOeNEG_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_yU4FZwGD, 0, m, &cSlice_yU4FZwGD_sendMessage);
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 1);
  msg_setElementToFrom(m, 1, n, 0);
  cSlice_onMessage(_c, &Context(_c)->cSlice_h4FOeNEG, 0, m, &cSlice_h4FOeNEG_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_yU4FZwGD, 0, m, &cSlice_yU4FZwGD_sendMessage);
}

void Heavy_SoundScraper::cBinop_nBDBdQ7z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_i65kIUnR, 1, m, &cPack_i65kIUnR_sendMessage);
}

void Heavy_SoundScraper::cBinop_lLmlRGJT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_UH95E8FT, 1, m, &cPack_UH95E8FT_sendMessage);
}

void Heavy_SoundScraper::cMsg_POTsmzaY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 0.0f);
  cSlice_onMessage(_c, &Context(_c)->cSlice_060v7k4E, 0, m, &cSlice_060v7k4E_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_GEUTtpjf, 0, m, &cSlice_GEUTtpjf_sendMessage);
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 1);
  msg_setElementToFrom(m, 1, n, 0);
  cSlice_onMessage(_c, &Context(_c)->cSlice_060v7k4E, 0, m, &cSlice_060v7k4E_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_GEUTtpjf, 0, m, &cSlice_GEUTtpjf_sendMessage);
}

void Heavy_SoundScraper::cSend_NBvRV1E3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_K4HZG2wh_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_GZOBW3aB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 0.0f, 0, m, &cBinop_twdrpU5o_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_o9JRawQV, 0, m, &cIf_o9JRawQV_sendMessage);
}

void Heavy_SoundScraper::cCast_rnvGNjWM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_J5q7sQ5W, 1, m, &cPack_J5q7sQ5W_sendMessage);
}

void Heavy_SoundScraper::cCast_IuOfwuNr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_0UZDIhlT, 1, m, &cDelay_0UZDIhlT_sendMessage);
}

void Heavy_SoundScraper::cCast_d88gOTIX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_rFhHdy3I, HV_BINOP_ADD, 1, m, &cBinop_rFhHdy3I_sendMessage);
}

void Heavy_SoundScraper::cCast_NLH561ru_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_LSuSl3Tn, HV_BINOP_ADD, 1, m, &cBinop_LSuSl3Tn_sendMessage);
}

void Heavy_SoundScraper::cCast_3DgKozhT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_9uliDmoL, HV_BINOP_SUBTRACT, 1, m, &cBinop_9uliDmoL_sendMessage);
}

void Heavy_SoundScraper::cCast_N5UJvXxt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_4DWQ6dTC, 1, m, &cDelay_4DWQ6dTC_sendMessage);
}

void Heavy_SoundScraper::cCast_J2bDH2r3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_9uoQwgtp, 0, m, &cPack_9uoQwgtp_sendMessage);
}

void Heavy_SoundScraper::cCast_Da0e1nsV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_KmUqyisZ_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_fJxHH2aO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_abQeg73E_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_MbhvY3nY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_KmUqyisZ_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_Lt6LUj4q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_d88gOTIX_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_NLH561ru_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_UyaQ5pbA_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_eeDT1Px8_sendMessage);
      break;
    }
    default: {
      cVar_onMessage(_c, &Context(_c)->cVar_iuVpGF7e, 1, m, &cVar_iuVpGF7e_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_eeDT1Px8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_9q83qKDq_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_8A9zJ37O_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_HadGIMUq_sendMessage);
      break;
    }
    default: {
      cSwitchcase_AGI5JLZo_onMessage(_c, NULL, 0, m, NULL);
      cVar_onMessage(_c, &Context(_c)->cVar_wtANnlDz, 1, m, &cVar_wtANnlDz_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_HadGIMUq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_pNVg5MBh_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSlice_yhExvdEj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
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

void Heavy_SoundScraper::cSlice_tGwGnzhZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSwitchcase_Nj8JEoHK_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_IKY7JfI0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_Lt6LUj4q, HV_BINOP_MULTIPLY, 0, m, &cBinop_Lt6LUj4q_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_LuAhS2m6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSwitchcase_8A9zJ37O_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_URnynw7Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
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

void Heavy_SoundScraper::cSlice_iIHsriNg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSwitchcase_UyaQ5pbA_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cMsg_9q83qKDq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_iuVpGF7e, 1, m, &cVar_iuVpGF7e_sendMessage);
}

void Heavy_SoundScraper::cCast_mGQImPvV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_mSPkgoXp_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_pNVg5MBh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_AGI5JLZo_onMessage(_c, NULL, 0, m, NULL);
  cVar_onMessage(_c, &Context(_c)->cVar_wtANnlDz, 1, m, &cVar_wtANnlDz_sendMessage);
}

void Heavy_SoundScraper::cMsg_mSPkgoXp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(6);
  msg_init(m, 6, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setSymbol(m, 1, "xylo");
  msg_setFloat(m, 2, 1.0f);
  msg_setFloat(m, 3, 0.0f);
  msg_setFloat(m, 4, 0.0f);
  msg_setFloat(m, 5, 0.0f);
  cSlice_onMessage(_c, &Context(_c)->cSlice_yhExvdEj, 0, m, &cSlice_yhExvdEj_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_tGwGnzhZ, 0, m, &cSlice_tGwGnzhZ_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_IKY7JfI0, 0, m, &cSlice_IKY7JfI0_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_LuAhS2m6, 0, m, &cSlice_LuAhS2m6_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_URnynw7Z, 0, m, &cSlice_URnynw7Z_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_iIHsriNg, 0, m, &cSlice_iIHsriNg_sendMessage);
}

void Heavy_SoundScraper::cSlice_5ylQh6US_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_w1OT6oNE_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_5FtWk7tO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_dh2XtEKe_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_dh2XtEKe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_JaiCMXJY_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_JaiCMXJY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_YfEvkani_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_w1OT6oNE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_kA512rfj_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_kA512rfj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_qtVcehxi_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_pvZFOWUZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_tQwbColR_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_6D4UXtLi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_9EDLXK5E, HV_BINOP_MULTIPLY, 1, m, &cBinop_9EDLXK5E_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_IkajEG6G, HV_BINOP_MULTIPLY, 1, m, &cBinop_IkajEG6G_sendMessage);
}

void Heavy_SoundScraper::cSlice_2wry0N4X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_9EDLXK5E, HV_BINOP_MULTIPLY, 0, m, &cBinop_9EDLXK5E_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_BHZPbfCO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_IkajEG6G, HV_BINOP_MULTIPLY, 0, m, &cBinop_IkajEG6G_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cMsg_tQwbColR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setElementToFrom(m, 2, n, 1);
  cMsg_BlR5qZbi_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_BlR5qZbi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 441000000.0f);
  msg_setFloat(m, 1, 10000000.0f);
}

void Heavy_SoundScraper::cBinop_9EDLXK5E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_pvZFOWUZ, 1, m, &cPack_pvZFOWUZ_sendMessage);
}

void Heavy_SoundScraper::cBinop_IkajEG6G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_pvZFOWUZ, 0, m, &cPack_pvZFOWUZ_sendMessage);
}

void Heavy_SoundScraper::cMsg_2zGFAmic_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 44100.0f);
  msg_setFloat(m, 1, 1000.0f);
  cSlice_onMessage(_c, &Context(_c)->cSlice_2wry0N4X, 0, m, &cSlice_2wry0N4X_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_BHZPbfCO, 0, m, &cSlice_BHZPbfCO_sendMessage);
}

void Heavy_SoundScraper::cSend_bvbZioih_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_7tK5H609_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_hnJN4iPW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 1);
  cSwitchcase_hfU8WMUF_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cSlice_7y2iSHU6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 127.0f, 0, m, &cBinop_i0CaCaXh_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_zdiBQKnD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_bOHLDSTK_sendMessage);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_5DHiEBYN_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cVar_sqaPBYhh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_vRHMX787, 1, m, &cPack_vRHMX787_sendMessage);
}

void Heavy_SoundScraper::cVar_LTitF40t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_vRHMX787, 0, m, &cPack_vRHMX787_sendMessage);
}

void Heavy_SoundScraper::cPack_vRHMX787_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_roZojJ03_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_M1IdJheL_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_mGQImPvV_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_yhExvdEj, 0, m, &cSlice_yhExvdEj_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_tGwGnzhZ, 0, m, &cSlice_tGwGnzhZ_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_IKY7JfI0, 0, m, &cSlice_IKY7JfI0_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_LuAhS2m6, 0, m, &cSlice_LuAhS2m6_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_URnynw7Z, 0, m, &cSlice_URnynw7Z_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_iIHsriNg, 0, m, &cSlice_iIHsriNg_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_irZ8YKhW_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Z19Muuke_sendMessage);
  cMsg_hnJN4iPW_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_LJN2AguD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_LTitF40t, 0, m, &cVar_LTitF40t_sendMessage);
}

void Heavy_SoundScraper::cCast_KEjyIXOz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_sqaPBYhh, 0, m, &cVar_sqaPBYhh_sendMessage);
}

void Heavy_SoundScraper::cCast_DHqALwmb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_vRHMX787, 2, m, &cPack_vRHMX787_sendMessage);
}

void Heavy_SoundScraper::cBinop_5UNMft2F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.4f, 0, m, &cBinop_689XPuGZ_sendMessage);
}

void Heavy_SoundScraper::cBinop_689XPuGZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_h7YCxOeG_sendMessage);
}

void Heavy_SoundScraper::cBinop_i0CaCaXh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_VNpNjQcY_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_IGlwP67w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_DHqALwmb_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_KEjyIXOz_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_LJN2AguD_sendMessage);
}

void Heavy_SoundScraper::cBinop_G3LWoF0Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.99f, 0, m, &cBinop_kQpEgfAt_sendMessage);
}

void Heavy_SoundScraper::cBinop_kQpEgfAt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_IGlwP67w, HV_BINOP_MULTIPLY, 1, m, &cBinop_IGlwP67w_sendMessage);
}

void Heavy_SoundScraper::cCast_bOHLDSTK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_EolvsM8B_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_M1IdJheL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_wh3HIg3H_sendMessage);
}

void Heavy_SoundScraper::cCast_roZojJ03_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_jBwh39U3_onMessage(_c, NULL, 0, m, NULL);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_xNKgaM2C_sendMessage);
}

void Heavy_SoundScraper::cSend_DonTFUEF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_f2DNYbGG_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_ZrQ8XCz2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_kB9kdzJ2_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_6AC6W0C9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_IGlwP67w, HV_BINOP_MULTIPLY, 0, m, &cBinop_IGlwP67w_sendMessage);
}

void Heavy_SoundScraper::cSend_VNpNjQcY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_Typ4JIoB_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_nd0bDNqv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 44100.0f);
  cSend_bvbZioih_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_XA4D5OwY_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_LIJIkpHL, 0, m, &cSlice_LIJIkpHL_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_nS87wgcH, 0, m, &cRandom_nS87wgcH_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_b5JCjhvr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_BLghhrxf_sendMessage);
}

void Heavy_SoundScraper::cUnop_BLghhrxf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_ES1uK4uh_sendMessage);
}

void Heavy_SoundScraper::cRandom_nS87wgcH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_b5JCjhvr_sendMessage);
}

void Heavy_SoundScraper::cSlice_LIJIkpHL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_nS87wgcH, 1, m, &cRandom_nS87wgcH_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_1V5MgkHb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_bBobFv06, HV_BINOP_DIVIDE, 0, m, &cBinop_bBobFv06_sendMessage);
}

void Heavy_SoundScraper::cBinop_p7OLpR0X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_J7hfrmN3_sendMessage);
}

void Heavy_SoundScraper::cBinop_J7hfrmN3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_pw5TfvuW, HV_BINOP_POW, 1, m, &cBinop_pw5TfvuW_sendMessage);
  cMsg_9KQL9yYA_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_pw5TfvuW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_1V5MgkHb_sendMessage);
}

void Heavy_SoundScraper::cMsg_9KQL9yYA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_pw5TfvuW, HV_BINOP_POW, 0, m, &cBinop_pw5TfvuW_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_9DTQCcwj_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_f8HBLFa2, 0, m, &cSlice_f8HBLFa2_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_LzSrMaOs, 0, m, &cRandom_LzSrMaOs_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_k3Vr5Xos_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_G7MaxgwI_sendMessage);
}

void Heavy_SoundScraper::cUnop_G7MaxgwI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_GuOjLwkU_sendMessage);
}

void Heavy_SoundScraper::cRandom_LzSrMaOs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 15.0f, 0, m, &cBinop_k3Vr5Xos_sendMessage);
}

void Heavy_SoundScraper::cSlice_f8HBLFa2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_LzSrMaOs, 1, m, &cRandom_LzSrMaOs_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_v4S319M7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSend_QwHh7VEa_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_qtZG4vQY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSend_nWLtywTo_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cUnop_Vh9DYPBY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_dlnf1mZs, 0, m, &cPack_dlnf1mZs_sendMessage);
}

void Heavy_SoundScraper::cUnop_wZgk8rPM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_baediq0f, 0, m, &cPack_baediq0f_sendMessage);
}

void Heavy_SoundScraper::cPack_baediq0f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_P3JxrZ3P, 0, m, NULL);
}

void Heavy_SoundScraper::cPack_dlnf1mZs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_Qjb9MdFa, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_vklTUlbG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_Vh9DYPBY_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_SIN, m, &cUnop_wZgk8rPM_sendMessage);
}

void Heavy_SoundScraper::cMsg_SU1KdcCS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.5f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_vklTUlbG_sendMessage);
}

void Heavy_SoundScraper::cCast_2II917EK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cVar_VRVw4P4A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_2PHHGjBE_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_LRRXfCWJ_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_B1YGUhZe_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_m9L8uM89_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_sb12G72Z_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_sb12G72Z_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_QbD9NQRN, 1, m, &cDelay_QbD9NQRN_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_6o4gUv7V_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cDelay_QbD9NQRN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_QbD9NQRN, m);
  cVar_onMessage(_c, &Context(_c)->cVar_bR9za15E, 0, m, &cVar_bR9za15E_sendMessage);
}

void Heavy_SoundScraper::cMsg_sb12G72Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_QbD9NQRN, 0, m, &cDelay_QbD9NQRN_sendMessage);
}

void Heavy_SoundScraper::cCast_6o4gUv7V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_QbD9NQRN, 0, m, &cDelay_QbD9NQRN_sendMessage);
}

void Heavy_SoundScraper::cVar_bR9za15E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_v4Bw1h01_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_7yUxN8rl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_VRVw4P4A, 0, m, &cVar_VRVw4P4A_sendMessage);
}

void Heavy_SoundScraper::cSend_aoEcAY4I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cSend_yONSdGcx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_SZRranTr_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_L8QxHo68_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 25.0f);
  cSend_aoEcAY4I_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_nHJrKpPh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 4000.0f);
  cSend_yONSdGcx_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_DIPDii8o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_S7bU7ctr_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_DpyvTY6G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSend_DIPDii8o_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_cxlceXza_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cSend_jaPQMPEN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_SZRranTr_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_ZbzmPPhW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_S7bU7ctr_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_3RfUT8lH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 25.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_GY4Dkh1P, 0, m, NULL);
}

void Heavy_SoundScraper::cMsg_v4Bw1h01_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 0);
  sLine_onMessage(_c, &Context(_c)->sLine_GY4Dkh1P, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_LRRXfCWJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_bR9za15E, 1, m, &cVar_bR9za15E_sendMessage);
}

void Heavy_SoundScraper::cCast_2PHHGjBE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_3RfUT8lH_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_B1YGUhZe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_m9L8uM89_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cSwitchcase_r7TAiHpp_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_qHuDRc3x, 0, m, &cSlice_qHuDRc3x_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cVar_ozAWR6jV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_is5wYnfb_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSystem_oFpE9DTP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 2.0f, 0, m, &cBinop_xbYbV65B_sendMessage);
}

void Heavy_SoundScraper::cBinop_xbYbV65B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_JWj8QhxO, m);
}

void Heavy_SoundScraper::cMsg_is5wYnfb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_oFpE9DTP_sendMessage);
}

void Heavy_SoundScraper::cSlice_qHuDRc3x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sTabread_onMessage(_c, &Context(_c)->sTabread_roJt7v8z, 1, m, NULL);
      sTabread_onMessage(_c, &Context(_c)->sTabread_e2Vk1u9s, 1, m, NULL);
      cVar_onMessage(_c, &Context(_c)->cVar_ozAWR6jV, 0, m, &cVar_ozAWR6jV_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cVar_S1cZ0Gnq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_42rxGRaF, 0, m, &cPack_42rxGRaF_sendMessage);
}

void Heavy_SoundScraper::cVar_GvztUjBL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 10000000.0f, 0, m, &cBinop_b1WqppEZ_sendMessage);
}

void Heavy_SoundScraper::cIf_iPPySbbO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_ABS, m, &cUnop_e63toiup_sendMessage);
      break;
    }
    case 1: {
      cVar_onMessage(_c, &Context(_c)->cVar_GvztUjBL, 1, m, &cVar_GvztUjBL_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_sXhMFD5o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_iPPySbbO, 1, m, &cIf_iPPySbbO_sendMessage);
}

void Heavy_SoundScraper::cVar_CuYJi230_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 10000000.0f, 0, m, &cBinop_zWvt1W8P_sendMessage);
}

void Heavy_SoundScraper::cUnop_e63toiup_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_CuYJi230, 1, m, &cVar_CuYJi230_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_07vKaGIm_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_EXIwhVcC_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_UZmbatWY_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_EXIwhVcC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_GvztUjBL, 0, m, &cVar_GvztUjBL_sendMessage);
}

void Heavy_SoundScraper::cCast_UZmbatWY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_CuYJi230, 0, m, &cVar_CuYJi230_sendMessage);
}

void Heavy_SoundScraper::cVar_z34jc0Np_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_LESS_THAN, 0.0f, 0, m, &cBinop_hG2M5pYk_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_6eXFiGg9_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_v855x97c_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_v855x97c_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_Js39jhV4, 1, m, &cDelay_Js39jhV4_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_psz6LgHg_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cDelay_Js39jhV4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Js39jhV4, m);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_x5cWG9iw_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_3jtA4FJf_sendMessage);
}

void Heavy_SoundScraper::cMsg_v855x97c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_Js39jhV4, 0, m, &cDelay_Js39jhV4_sendMessage);
}

void Heavy_SoundScraper::cCast_psz6LgHg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Js39jhV4, 0, m, &cDelay_Js39jhV4_sendMessage);
}

void Heavy_SoundScraper::cPack_jGGNTkzv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_SGElsvJZ_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_eKOHPvVy_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_TXnSj6HW_sendMessage);
      break;
    }
    default: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_TbdAnVia, HV_BINOP_SUBTRACT, 0, m, &cBinop_TbdAnVia_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_TXnSj6HW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_8Fj2Higx_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_Rn9X5Rqk_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_gRWLpLsJ_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_gRWLpLsJ_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_lkIOOjY4, 1, m, &cDelay_lkIOOjY4_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ZfNzpFfG_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cDelay_lkIOOjY4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_lkIOOjY4, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_x1WmdKp7_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_R10oG39w_sendMessage);
}

void Heavy_SoundScraper::cMsg_gRWLpLsJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_lkIOOjY4, 0, m, &cDelay_lkIOOjY4_sendMessage);
}

void Heavy_SoundScraper::cCast_ZfNzpFfG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_lkIOOjY4, 0, m, &cDelay_lkIOOjY4_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_QzYruKmb_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_71U3cDbT_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_71U3cDbT_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_q7rXjGjp, 1, m, &cDelay_q7rXjGjp_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_JUicpEFN_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cDelay_q7rXjGjp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_q7rXjGjp, m);
}

void Heavy_SoundScraper::cMsg_71U3cDbT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_q7rXjGjp, 0, m, &cDelay_q7rXjGjp_sendMessage);
}

void Heavy_SoundScraper::cCast_JUicpEFN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_q7rXjGjp, 0, m, &cDelay_q7rXjGjp_sendMessage);
}

void Heavy_SoundScraper::cPack_uWbDOps4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_pbulVc8O_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_dmAFTH8T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_Ja6nlJfp_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_baUqD3UH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_j18GiNgf_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_QGpCpm3d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_BTwTVWFi, HV_BINOP_DIVIDE, 1, m, &cBinop_BTwTVWFi_sendMessage);
}

void Heavy_SoundScraper::cVar_K22Bzlg3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_BTwTVWFi, HV_BINOP_DIVIDE, 0, m, &cBinop_BTwTVWFi_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_6i7A0MGv_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0xFFFFFFFF: { // "bang"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ptB46lx4_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_oCfksU8q_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ck4mO9Gm_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_PT4n3bV0_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_oCfksU8q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_K22Bzlg3, 0, m, &cVar_K22Bzlg3_sendMessage);
}

void Heavy_SoundScraper::cCast_ptB46lx4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_QGpCpm3d, 0, m, &cVar_QGpCpm3d_sendMessage);
}

void Heavy_SoundScraper::cCast_PT4n3bV0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_K22Bzlg3, 0, m, &cVar_K22Bzlg3_sendMessage);
}

void Heavy_SoundScraper::cCast_ck4mO9Gm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_QGpCpm3d, 0, m, &cVar_QGpCpm3d_sendMessage);
}

void Heavy_SoundScraper::cPack_42rxGRaF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_nYUCOjxl_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSlice_x2BBRT6i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cPack_onMessage(_c, &Context(_c)->cPack_jGGNTkzv, 1, m, &cPack_jGGNTkzv_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_RXio1ALa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_pKjoSEia, HV_BINOP_ADD, 0, m, &cBinop_pKjoSEia_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_ukHzN9OE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cPack_onMessage(_c, &Context(_c)->cPack_uWbDOps4, 1, m, &cPack_uWbDOps4_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_FrciKGe7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_SGkGiMXg, HV_BINOP_ADD, 0, m, &cBinop_SGkGiMXg_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cPack_R5IdV5Yw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_N3YEzYTj_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_2DxqkVEV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_i68J4ZED_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_3jtA4FJf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_S1cZ0Gnq, 0, m, &cVar_S1cZ0Gnq_sendMessage);
}

void Heavy_SoundScraper::cCast_x5cWG9iw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_z34jc0Np, 0, m, &cVar_z34jc0Np_sendMessage);
}

void Heavy_SoundScraper::cSend_SGElsvJZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_AGQqEzBj_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_nYUCOjxl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_aU7J7wm9_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_Ja6nlJfp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_aU7J7wm9_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_MEH3LrYY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_dmAFTH8T, 0, m, &cPack_dmAFTH8T_sendMessage);
}

void Heavy_SoundScraper::cCast_86CjdYnn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_6eXFiGg9_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_b1WqppEZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_R5IdV5Yw, 0, m, &cPack_R5IdV5Yw_sendMessage);
}

void Heavy_SoundScraper::cSend_pbulVc8O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_AGQqEzBj_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_zWvt1W8P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_2DxqkVEV, 0, m, &cPack_2DxqkVEV_sendMessage);
}

void Heavy_SoundScraper::cBinop_hG2M5pYk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_07vKaGIm_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_pKjoSEia_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_jGGNTkzv, 0, m, &cPack_jGGNTkzv_sendMessage);
}

void Heavy_SoundScraper::cBinop_TbdAnVia_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_Rn9X5Rqk_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_SGkGiMXg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_uWbDOps4, 0, m, &cPack_uWbDOps4_sendMessage);
}

void Heavy_SoundScraper::cMsg_8Fj2Higx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "stop");
  cSwitchcase_Rn9X5Rqk_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_yEF5lsKN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_KD8gQJzK, HV_BINOP_MULTIPLY, 1, m, &cBinop_KD8gQJzK_sendMessage);
}

void Heavy_SoundScraper::cMsg_i68J4ZED_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 0.0f);
  cSlice_onMessage(_c, &Context(_c)->cSlice_ukHzN9OE, 0, m, &cSlice_ukHzN9OE_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_FrciKGe7, 0, m, &cSlice_FrciKGe7_sendMessage);
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 1);
  msg_setElementToFrom(m, 1, n, 0);
  cSlice_onMessage(_c, &Context(_c)->cSlice_ukHzN9OE, 0, m, &cSlice_ukHzN9OE_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_FrciKGe7, 0, m, &cSlice_FrciKGe7_sendMessage);
}

void Heavy_SoundScraper::cBinop_iOf7BHNE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_2DxqkVEV, 1, m, &cPack_2DxqkVEV_sendMessage);
}

void Heavy_SoundScraper::cBinop_TQ5OZ7xK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_R5IdV5Yw, 1, m, &cPack_R5IdV5Yw_sendMessage);
}

void Heavy_SoundScraper::cMsg_N3YEzYTj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 0.0f);
  cSlice_onMessage(_c, &Context(_c)->cSlice_x2BBRT6i, 0, m, &cSlice_x2BBRT6i_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_RXio1ALa, 0, m, &cSlice_RXio1ALa_sendMessage);
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 1);
  msg_setElementToFrom(m, 1, n, 0);
  cSlice_onMessage(_c, &Context(_c)->cSlice_x2BBRT6i, 0, m, &cSlice_x2BBRT6i_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_RXio1ALa, 0, m, &cSlice_RXio1ALa_sendMessage);
}

void Heavy_SoundScraper::cSend_j18GiNgf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_aU7J7wm9_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_BTwTVWFi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 0.0f, 0, m, &cBinop_sXhMFD5o_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_iPPySbbO, 0, m, &cIf_iPPySbbO_sendMessage);
}

void Heavy_SoundScraper::cCast_BGtMrUyW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Js39jhV4, 1, m, &cDelay_Js39jhV4_sendMessage);
}

void Heavy_SoundScraper::cCast_UWq8Hgcz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_dmAFTH8T, 1, m, &cPack_dmAFTH8T_sendMessage);
}

void Heavy_SoundScraper::cCast_PVLaBO1W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_pKjoSEia, HV_BINOP_ADD, 1, m, &cBinop_pKjoSEia_sendMessage);
}

void Heavy_SoundScraper::cCast_QqfEBMpF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_SGkGiMXg, HV_BINOP_ADD, 1, m, &cBinop_SGkGiMXg_sendMessage);
}

void Heavy_SoundScraper::cCast_SnOW4eiS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_TbdAnVia, HV_BINOP_SUBTRACT, 1, m, &cBinop_TbdAnVia_sendMessage);
}

void Heavy_SoundScraper::cCast_OVrB2bRg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_q7rXjGjp, 1, m, &cDelay_q7rXjGjp_sendMessage);
}

void Heavy_SoundScraper::cCast_R10oG39w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_baUqD3UH, 0, m, &cPack_baUqD3UH_sendMessage);
}

void Heavy_SoundScraper::cCast_x1WmdKp7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_QzYruKmb_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_0PyL00ch_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_Rn9X5Rqk_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_abiGYk8n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_QzYruKmb_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_KD8gQJzK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_QqfEBMpF_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_PVLaBO1W_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_JMHDOLC5_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Q99VohVd_sendMessage);
      break;
    }
    default: {
      cVar_onMessage(_c, &Context(_c)->cVar_S1cZ0Gnq, 1, m, &cVar_S1cZ0Gnq_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_Q99VohVd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_3stNvwT0_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_jBgRvyaJ_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_fNSPwzno_sendMessage);
      break;
    }
    default: {
      cSwitchcase_6i7A0MGv_onMessage(_c, NULL, 0, m, NULL);
      cVar_onMessage(_c, &Context(_c)->cVar_z34jc0Np, 1, m, &cVar_z34jc0Np_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_fNSPwzno_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_8OoERaI3_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSlice_gowVA5Bs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
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

void Heavy_SoundScraper::cSlice_DmVQ9c44_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSwitchcase_eKOHPvVy_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_Lc78Dhw2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_KD8gQJzK, HV_BINOP_MULTIPLY, 0, m, &cBinop_KD8gQJzK_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_DUkgjMAc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSwitchcase_jBgRvyaJ_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_V0qKurPu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
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

void Heavy_SoundScraper::cSlice_TDgrepgv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSwitchcase_JMHDOLC5_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cMsg_3stNvwT0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_S1cZ0Gnq, 1, m, &cVar_S1cZ0Gnq_sendMessage);
}

void Heavy_SoundScraper::cCast_270GvyR0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_v3eDIUMQ_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_8OoERaI3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_6i7A0MGv_onMessage(_c, NULL, 0, m, NULL);
  cVar_onMessage(_c, &Context(_c)->cVar_z34jc0Np, 1, m, &cVar_z34jc0Np_sendMessage);
}

void Heavy_SoundScraper::cMsg_v3eDIUMQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(6);
  msg_init(m, 6, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setSymbol(m, 1, "xylo");
  msg_setFloat(m, 2, 1.0f);
  msg_setFloat(m, 3, 0.0f);
  msg_setFloat(m, 4, 0.0f);
  msg_setFloat(m, 5, 0.0f);
  cSlice_onMessage(_c, &Context(_c)->cSlice_gowVA5Bs, 0, m, &cSlice_gowVA5Bs_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_DmVQ9c44, 0, m, &cSlice_DmVQ9c44_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_Lc78Dhw2, 0, m, &cSlice_Lc78Dhw2_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_DUkgjMAc, 0, m, &cSlice_DUkgjMAc_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_V0qKurPu, 0, m, &cSlice_V0qKurPu_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_TDgrepgv, 0, m, &cSlice_TDgrepgv_sendMessage);
}

void Heavy_SoundScraper::cSlice_Hok53Qfa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_vh6f0S5d_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_2IFqOvKW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_czarZ96q_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_czarZ96q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_uCdZPhRm_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_uCdZPhRm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_njpx9hp5_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_vh6f0S5d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_iuB7DM6i_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_iuB7DM6i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_Md0gFRwU_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_CFSB7hbZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_hfBWCJo5_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_JGRtxMXi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_bg8bWn5I, HV_BINOP_MULTIPLY, 1, m, &cBinop_bg8bWn5I_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_kqZTZO7V, HV_BINOP_MULTIPLY, 1, m, &cBinop_kqZTZO7V_sendMessage);
}

void Heavy_SoundScraper::cSlice_q7FVdqSl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_bg8bWn5I, HV_BINOP_MULTIPLY, 0, m, &cBinop_bg8bWn5I_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_JcLZjbjv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_kqZTZO7V, HV_BINOP_MULTIPLY, 0, m, &cBinop_kqZTZO7V_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cMsg_hfBWCJo5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setElementToFrom(m, 2, n, 1);
  cMsg_VYvsJnlv_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_VYvsJnlv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 441000000.0f);
  msg_setFloat(m, 1, 10000000.0f);
}

void Heavy_SoundScraper::cBinop_bg8bWn5I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_CFSB7hbZ, 1, m, &cPack_CFSB7hbZ_sendMessage);
}

void Heavy_SoundScraper::cBinop_kqZTZO7V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_CFSB7hbZ, 0, m, &cPack_CFSB7hbZ_sendMessage);
}

void Heavy_SoundScraper::cMsg_IdqlBode_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 44100.0f);
  msg_setFloat(m, 1, 1000.0f);
  cSlice_onMessage(_c, &Context(_c)->cSlice_q7FVdqSl, 0, m, &cSlice_q7FVdqSl_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_JcLZjbjv, 0, m, &cSlice_JcLZjbjv_sendMessage);
}

void Heavy_SoundScraper::cSend_kuW1XgIs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_V10EzN6A_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_DDu1d52I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 1);
  cSwitchcase_r7TAiHpp_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cSlice_i2FuKAyH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 127.0f, 0, m, &cBinop_7ChHYAc8_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_E5Bh3Ute_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_j378EorC_sendMessage);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_p7OLpR0X_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cVar_DF3DdT7c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_DDFTP4p0, 1, m, &cPack_DDFTP4p0_sendMessage);
}

void Heavy_SoundScraper::cVar_COTqQ4YD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_DDFTP4p0, 0, m, &cPack_DDFTP4p0_sendMessage);
}

void Heavy_SoundScraper::cPack_DDFTP4p0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_lQ7AOFQK_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_uIMd0NQP_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_270GvyR0_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_gowVA5Bs, 0, m, &cSlice_gowVA5Bs_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_DmVQ9c44, 0, m, &cSlice_DmVQ9c44_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_Lc78Dhw2, 0, m, &cSlice_Lc78Dhw2_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_DUkgjMAc, 0, m, &cSlice_DUkgjMAc_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_V0qKurPu, 0, m, &cSlice_V0qKurPu_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_TDgrepgv, 0, m, &cSlice_TDgrepgv_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_MEH3LrYY_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_86CjdYnn_sendMessage);
  cMsg_DDu1d52I_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_K23RjapC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_DF3DdT7c, 0, m, &cVar_DF3DdT7c_sendMessage);
}

void Heavy_SoundScraper::cCast_vDm7qo5m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_DDFTP4p0, 2, m, &cPack_DDFTP4p0_sendMessage);
}

void Heavy_SoundScraper::cCast_3U6SSWn9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_COTqQ4YD, 0, m, &cVar_COTqQ4YD_sendMessage);
}

void Heavy_SoundScraper::cBinop_ES1uK4uh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.4f, 0, m, &cBinop_ASsF1uCo_sendMessage);
}

void Heavy_SoundScraper::cBinop_ASsF1uCo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_vklTUlbG_sendMessage);
}

void Heavy_SoundScraper::cBinop_7ChHYAc8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_9qPxkFdt_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_hCq5HwWL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_vDm7qo5m_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_K23RjapC_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_3U6SSWn9_sendMessage);
}

void Heavy_SoundScraper::cBinop_GuOjLwkU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.99f, 0, m, &cBinop_aV8fY8nq_sendMessage);
}

void Heavy_SoundScraper::cBinop_aV8fY8nq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_hCq5HwWL, HV_BINOP_MULTIPLY, 1, m, &cBinop_hCq5HwWL_sendMessage);
}

void Heavy_SoundScraper::cCast_j378EorC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_9DTQCcwj_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_lQ7AOFQK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_XA4D5OwY_onMessage(_c, NULL, 0, m, NULL);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_2II917EK_sendMessage);
}

void Heavy_SoundScraper::cCast_uIMd0NQP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_7yUxN8rl_sendMessage);
}

void Heavy_SoundScraper::cSend_nWLtywTo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_EksLlOPh_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_QwHh7VEa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_cw4Jl4Ws_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_bBobFv06_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_hCq5HwWL, HV_BINOP_MULTIPLY, 0, m, &cBinop_hCq5HwWL_sendMessage);
}

void Heavy_SoundScraper::cSend_9qPxkFdt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_KgXQczVj_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_AXdQ2k8U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 44100.0f);
  cSend_kuW1XgIs_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_juT2JvKY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_T9mN1gI9_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_qAufY60n_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_z6VDUbXm_sendMessage);
}

void Heavy_SoundScraper::cIf_uAOkPRSf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_8b5KJHeP_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_Oa4fjXqm_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cMsg_GQiPjiKG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_Le3D7rpF, HV_BINOP_POW, 0, m, &cBinop_Le3D7rpF_sendMessage);
}

void Heavy_SoundScraper::cBinop_Le3D7rpF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_zujddLT8, 0, m, &cPack_zujddLT8_sendMessage);
}

void Heavy_SoundScraper::cBinop_PPCRgjDF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_JZzy4oHO_sendMessage);
}

void Heavy_SoundScraper::cCast_qAufY60n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_7Y4QInhF_sendMessage);
}

void Heavy_SoundScraper::cCast_z6VDUbXm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_uAOkPRSf, 0, m, &cIf_uAOkPRSf_sendMessage);
}

void Heavy_SoundScraper::cBinop_7Y4QInhF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_uAOkPRSf, 1, m, &cIf_uAOkPRSf_sendMessage);
}

void Heavy_SoundScraper::cBinop_Oa4fjXqm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_PPCRgjDF_sendMessage);
}

void Heavy_SoundScraper::cMsg_8b5KJHeP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_zujddLT8, 0, m, &cPack_zujddLT8_sendMessage);
}

void Heavy_SoundScraper::cBinop_JZzy4oHO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Le3D7rpF, HV_BINOP_POW, 1, m, &cBinop_Le3D7rpF_sendMessage);
  cMsg_GQiPjiKG_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_zujddLT8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_i5agM2D2, 0, m, NULL);
}

void Heavy_SoundScraper::cVar_5datEgv1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_1xf7wf6a_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_T9mN1gI9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSend_pDjTOzwG_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_pDjTOzwG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_L5xfvBzh_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_1xf7wf6a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_ovIkSJRX_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_KMuYXZjJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_5QVp7Rv7_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_S4ifRtSb_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_9JrcGnF7_sendMessage);
}

void Heavy_SoundScraper::cIf_lmuhSOl4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_PI6pbqNr_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_6esL8KUG_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cMsg_MUiBKUyp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_yabpxvBe, HV_BINOP_POW, 0, m, &cBinop_yabpxvBe_sendMessage);
}

void Heavy_SoundScraper::cBinop_yabpxvBe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_rehIwvM0, 0, m, &cPack_rehIwvM0_sendMessage);
}

void Heavy_SoundScraper::cBinop_hlQ7qCbx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_i9iFYRwm_sendMessage);
}

void Heavy_SoundScraper::cCast_9JrcGnF7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_lmuhSOl4, 0, m, &cIf_lmuhSOl4_sendMessage);
}

void Heavy_SoundScraper::cCast_S4ifRtSb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_M0Y55AU2_sendMessage);
}

void Heavy_SoundScraper::cBinop_M0Y55AU2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_lmuhSOl4, 1, m, &cIf_lmuhSOl4_sendMessage);
}

void Heavy_SoundScraper::cBinop_6esL8KUG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_hlQ7qCbx_sendMessage);
}

void Heavy_SoundScraper::cMsg_PI6pbqNr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_rehIwvM0, 0, m, &cPack_rehIwvM0_sendMessage);
}

void Heavy_SoundScraper::cBinop_i9iFYRwm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_yabpxvBe, HV_BINOP_POW, 1, m, &cBinop_yabpxvBe_sendMessage);
  cMsg_MUiBKUyp_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_rehIwvM0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_TWTetHHL, 0, m, NULL);
}

void Heavy_SoundScraper::cVar_SccN7krs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_E8eNHMzn_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_5QVp7Rv7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSend_UGdKae2D_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_UGdKae2D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_UM8pxCIq_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_E8eNHMzn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_sQa0mp8d_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cIf_vwUzXcdB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_rp73T1dr_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_LOG10, m, &cUnop_RMoLH6vL_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cUnop_RMoLH6vL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_XdXUG6L2_sendMessage);
}

void Heavy_SoundScraper::cCast_FpwmJlSM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_lHuZmtvV_sendMessage);
}

void Heavy_SoundScraper::cCast_vVjKlHNP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_vwUzXcdB, 0, m, &cIf_vwUzXcdB_sendMessage);
}

void Heavy_SoundScraper::cMsg_rp73T1dr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cMsg_5QVp7Rv7_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_S4ifRtSb_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_9JrcGnF7_sendMessage);
}

void Heavy_SoundScraper::cBinop_XdXUG6L2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 100.0f, 0, m, &cBinop_cLICavlJ_sendMessage);
}

void Heavy_SoundScraper::cBinop_cLICavlJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_qAMktQ0y_sendMessage);
}

void Heavy_SoundScraper::cBinop_qAMktQ0y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_5QVp7Rv7_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_S4ifRtSb_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_9JrcGnF7_sendMessage);
}

void Heavy_SoundScraper::cBinop_lHuZmtvV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_vwUzXcdB, 1, m, &cIf_vwUzXcdB_sendMessage);
}

void Heavy_SoundScraper::cBinop_w9HhRDN3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_FpwmJlSM_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_vVjKlHNP_sendMessage);
}

void Heavy_SoundScraper::cBinop_ps1V98P9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_w9HhRDN3_sendMessage);
}

void Heavy_SoundScraper::cVar_Xd4TaDWV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_jYz2bDK0_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ceLXRUbZ_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_oUL6oxvc_sendMessage);
}

void Heavy_SoundScraper::cIf_d5BprS40_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_oYSUG5PH_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_fPXYRSnE_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cMsg_YcylmfEV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_DIoEm4CM, HV_BINOP_POW, 0, m, &cBinop_DIoEm4CM_sendMessage);
}

void Heavy_SoundScraper::cBinop_DIoEm4CM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_tSUDMHK5, 0, m, &cPack_tSUDMHK5_sendMessage);
}

void Heavy_SoundScraper::cBinop_qozdaApJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_ch1DAHuO_sendMessage);
}

void Heavy_SoundScraper::cCast_ceLXRUbZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_iRG3MrSO_sendMessage);
}

void Heavy_SoundScraper::cCast_oUL6oxvc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_d5BprS40, 0, m, &cIf_d5BprS40_sendMessage);
}

void Heavy_SoundScraper::cBinop_iRG3MrSO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_d5BprS40, 1, m, &cIf_d5BprS40_sendMessage);
}

void Heavy_SoundScraper::cBinop_fPXYRSnE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_qozdaApJ_sendMessage);
}

void Heavy_SoundScraper::cMsg_oYSUG5PH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_tSUDMHK5, 0, m, &cPack_tSUDMHK5_sendMessage);
}

void Heavy_SoundScraper::cBinop_ch1DAHuO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_DIoEm4CM, HV_BINOP_POW, 1, m, &cBinop_DIoEm4CM_sendMessage);
  cMsg_YcylmfEV_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_tSUDMHK5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_5kqe3ww4, 0, m, NULL);
}

void Heavy_SoundScraper::cVar_x2unxKzg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_CRQ1kIGB_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_jYz2bDK0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSend_ThhRUQYb_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_ThhRUQYb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_M17zPons_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_CRQ1kIGB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_lzK2PWxi_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_wMSka1wE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_6O4kmxQP_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Fdbkz6PM_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_qKEobDGM_sendMessage);
}

void Heavy_SoundScraper::cIf_8MGBv1cP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_51PK89u3_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_MY56eAfF_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cMsg_v8BkyKgR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_D8IwbAIq, HV_BINOP_POW, 0, m, &cBinop_D8IwbAIq_sendMessage);
}

void Heavy_SoundScraper::cBinop_D8IwbAIq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_sIRtwrnC, 0, m, &cPack_sIRtwrnC_sendMessage);
}

void Heavy_SoundScraper::cBinop_BphCrHWZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_XaVJ7Xdz_sendMessage);
}

void Heavy_SoundScraper::cCast_qKEobDGM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_8MGBv1cP, 0, m, &cIf_8MGBv1cP_sendMessage);
}

void Heavy_SoundScraper::cCast_Fdbkz6PM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_yb1zn3v0_sendMessage);
}

void Heavy_SoundScraper::cBinop_yb1zn3v0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_8MGBv1cP, 1, m, &cIf_8MGBv1cP_sendMessage);
}

void Heavy_SoundScraper::cBinop_MY56eAfF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_BphCrHWZ_sendMessage);
}

void Heavy_SoundScraper::cMsg_51PK89u3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_sIRtwrnC, 0, m, &cPack_sIRtwrnC_sendMessage);
}

void Heavy_SoundScraper::cBinop_XaVJ7Xdz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_D8IwbAIq, HV_BINOP_POW, 1, m, &cBinop_D8IwbAIq_sendMessage);
  cMsg_v8BkyKgR_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_sIRtwrnC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_clyHWvTj, 0, m, NULL);
}

void Heavy_SoundScraper::cVar_J5dGcJlH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_cjh4uK0T_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_6O4kmxQP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSend_5G1ozIHy_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_5G1ozIHy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_SDyRUZVe_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_cjh4uK0T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_SHAlY3PM_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_U63jsgqi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_RXiZj7W8, 0, m, &cIf_RXiZj7W8_sendMessage);
}

void Heavy_SoundScraper::cSlice_qpanm8m2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_vwMnF7FV_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_HfbS4SNE_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_4rCkqgSs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cIf_onMessage(_c, &Context(_c)->cIf_DBwntGhY, 0, m, &cIf_DBwntGhY_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cIf_DBwntGhY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_I6xJS0lt_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_5vJvFDoc_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cIf_eJxcLW7r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cPack_onMessage(_c, &Context(_c)->cPack_fneOoWBx, 2, m, &cPack_fneOoWBx_sendMessage);
      cPack_onMessage(_c, &Context(_c)->cPack_FLvP6J69, 1, m, &cPack_FLvP6J69_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cIf_yuBQ3VPY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_qpanm8m2, 0, m, &cSlice_qpanm8m2_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_4rCkqgSs, 0, m, &cSlice_4rCkqgSs_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_Bt0DMSSQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_RPACuCuo_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_28n9SgzZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_3bCKyYZN_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Qx8Yqq77_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_8T2sNoBA_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cVar_9TG72Op6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_xsvBn3go, 1, m, &cIf_xsvBn3go_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_FsGvccjj_sendMessage);
}

void Heavy_SoundScraper::cIf_xsvBn3go_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_qpanm8m2, 0, m, &cSlice_qpanm8m2_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_4rCkqgSs, 0, m, &cSlice_4rCkqgSs_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cPack_FLvP6J69_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_yuBQ3VPY, 0, m, &cIf_yuBQ3VPY_sendMessage);
}

void Heavy_SoundScraper::cBinop_4PvqRlrM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_DBwntGhY, 1, m, &cIf_DBwntGhY_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_eJxcLW7r, 1, m, &cIf_eJxcLW7r_sendMessage);
}

void Heavy_SoundScraper::cCast_HfbS4SNE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_eJxcLW7r, 0, m, &cIf_eJxcLW7r_sendMessage);
}

void Heavy_SoundScraper::cCast_vwMnF7FV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_NEQ, 0.0f, 0, m, &cBinop_4PvqRlrM_sendMessage);
}

void Heavy_SoundScraper::cMsg_PM88IzWt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_9TG72Op6, 1, m, &cVar_9TG72Op6_sendMessage);
}

void Heavy_SoundScraper::cMsg_RPACuCuo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_9TG72Op6, 1, m, &cVar_9TG72Op6_sendMessage);
}

void Heavy_SoundScraper::cCast_3bCKyYZN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_9TG72Op6, 0, m, &cVar_9TG72Op6_sendMessage);
}

void Heavy_SoundScraper::cCast_8T2sNoBA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_PM88IzWt_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_Qx8Yqq77_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_FLvP6J69, 0, m, &cPack_FLvP6J69_sendMessage);
}

void Heavy_SoundScraper::cBinop_FsGvccjj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_yuBQ3VPY, 1, m, &cIf_yuBQ3VPY_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_NJbbtcGO_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_LNYDHvvL, 0, m, &cSlice_LNYDHvvL_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_8B7GxxK8, 0, m, &cSlice_8B7GxxK8_sendMessage);
      break;
    }
    case 0x40000000: { // "2.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_K8C5Iwgt, 0, m, &cSlice_K8C5Iwgt_sendMessage);
      break;
    }
    case 0x40400000: { // "3.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_Dvng9pSx, 0, m, &cSlice_Dvng9pSx_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cSlice_LNYDHvvL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_bTZvq2Q6, 0, m, &cSlice_bTZvq2Q6_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_X1xg4S0T, 0, m, &cSlice_X1xg4S0T_sendMessage);
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_bTZvq2Q6, 0, m, &cSlice_bTZvq2Q6_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_X1xg4S0T, 0, m, &cSlice_X1xg4S0T_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_8B7GxxK8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_XGiwhxDP, 0, m, &cSlice_XGiwhxDP_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_LeeZKd24, 0, m, &cSlice_LeeZKd24_sendMessage);
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_XGiwhxDP, 0, m, &cSlice_XGiwhxDP_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_LeeZKd24, 0, m, &cSlice_LeeZKd24_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_K8C5Iwgt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_7y2iSHU6, 0, m, &cSlice_7y2iSHU6_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_zdiBQKnD, 0, m, &cSlice_zdiBQKnD_sendMessage);
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_7y2iSHU6, 0, m, &cSlice_7y2iSHU6_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_zdiBQKnD, 0, m, &cSlice_zdiBQKnD_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_Dvng9pSx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_i2FuKAyH, 0, m, &cSlice_i2FuKAyH_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_E5Bh3Ute, 0, m, &cSlice_E5Bh3Ute_sendMessage);
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_i2FuKAyH, 0, m, &cSlice_i2FuKAyH_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_E5Bh3Ute, 0, m, &cSlice_E5Bh3Ute_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSwitchcase_C6apJMi1_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Z0QMfy98_sendMessage);
      break;
    }
    default: {
      cMsg_BeaLifRK_sendMessage(_c, 0, m);
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_Z0QMfy98_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_BhOIjZEV_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cIf_RXiZj7W8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_Bt0DMSSQ, 0, m, &cSlice_Bt0DMSSQ_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_28n9SgzZ, 0, m, &cSlice_28n9SgzZ_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_xsvBn3go, 0, m, &cIf_xsvBn3go_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cVar_n4P3YVaA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_EW8D6KlM_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_RXiZj7W8, 1, m, &cIf_RXiZj7W8_sendMessage);
}

void Heavy_SoundScraper::cBinop_EW8D6KlM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_n4P3YVaA, 1, m, &cVar_n4P3YVaA_sendMessage);
}

void Heavy_SoundScraper::cMsg_BhOIjZEV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_n4P3YVaA, 0, m, &cVar_n4P3YVaA_sendMessage);
}

void Heavy_SoundScraper::cMsg_BeaLifRK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_n4P3YVaA, 0, m, &cVar_n4P3YVaA_sendMessage);
}

void Heavy_SoundScraper::cPack_fneOoWBx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_NJbbtcGO_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cVar_IbDOdfOW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_fneOoWBx, 0, m, &cPack_fneOoWBx_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_lcx9Cbzz_sendMessage);
}

void Heavy_SoundScraper::cBinop_lcx9Cbzz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MOD_BIPOLAR, 4.0f, 0, m, &cBinop_LqsFAstb_sendMessage);
}

void Heavy_SoundScraper::cBinop_LqsFAstb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_IbDOdfOW, 1, m, &cVar_IbDOdfOW_sendMessage);
}

void Heavy_SoundScraper::cMsg_y2jWBt42_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_C6apJMi1_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_I6xJS0lt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_fneOoWBx, 1, m, &cPack_fneOoWBx_sendMessage);
}

void Heavy_SoundScraper::cCast_5vJvFDoc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_IbDOdfOW, 0, m, &cVar_IbDOdfOW_sendMessage);
}

void Heavy_SoundScraper::hTable_oWR8pmBA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::hTable_teJVa6yG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::hTable_JomIt6y9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::hTable_nOD1MkVi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::hTable_AV8Uleub_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::hTable_xc853M9T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cSlice_w8Nr3ubL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_i1jxczyc_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_vTqCAAmK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cIf_onMessage(_c, &Context(_c)->cIf_TIhHmKuO, 0, m, &cIf_TIhHmKuO_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_K7JnV13y, 0, m, &cIf_K7JnV13y_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_13dGuUl1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cIf_onMessage(_c, &Context(_c)->cIf_WGtML1W1, 0, m, &cIf_WGtML1W1_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_o3j6rvhJ, 0, m, &cIf_o3j6rvhJ_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cVar_k3N7iSoe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_Aa7iNAq6_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_0gv1krso, 0, m, &cIf_0gv1krso_sendMessage);
}

void Heavy_SoundScraper::cUnop_JOuFdvbr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_mXTskD2D_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_D41EENlH, HV_BINOP_EQ, 1, m, &cBinop_D41EENlH_sendMessage);
}

void Heavy_SoundScraper::cUnop_55t5eBzH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_mXTskD2D_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_D41EENlH, HV_BINOP_EQ, 1, m, &cBinop_D41EENlH_sendMessage);
}

void Heavy_SoundScraper::cIf_0gv1krso_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_55t5eBzH_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_JOuFdvbr_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_Aa7iNAq6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_0gv1krso, 1, m, &cIf_0gv1krso_sendMessage);
}

void Heavy_SoundScraper::cIf_K7JnV13y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSend_riPZClDu_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cIf_o3j6rvhJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSend_HAUcxrAx_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cIf_TIhHmKuO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSend_riPZClDu_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cIf_WGtML1W1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSend_HAUcxrAx_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_i1jxczyc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_D41EENlH, HV_BINOP_EQ, 0, m, &cBinop_D41EENlH_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_Br772PSP_sendMessage);
}

void Heavy_SoundScraper::cBinop_mXTskD2D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_IbCdhWV6_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_l5TCQPoG_sendMessage);
}

void Heavy_SoundScraper::cBinop_D41EENlH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_zEDtoTY0_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_CO9WEMDK_sendMessage);
}

void Heavy_SoundScraper::cCast_zEDtoTY0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_K7JnV13y, 1, m, &cIf_K7JnV13y_sendMessage);
}

void Heavy_SoundScraper::cCast_CO9WEMDK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_WGtML1W1, 1, m, &cIf_WGtML1W1_sendMessage);
}

void Heavy_SoundScraper::cCast_IbCdhWV6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_TIhHmKuO, 1, m, &cIf_TIhHmKuO_sendMessage);
}

void Heavy_SoundScraper::cCast_l5TCQPoG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_o3j6rvhJ, 1, m, &cIf_o3j6rvhJ_sendMessage);
}

void Heavy_SoundScraper::cBinop_Br772PSP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_pHv0LPJc_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_HAUcxrAx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_xnnDkUgV_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_riPZClDu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_JaZN56v9_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_pHv0LPJc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cSend_cznlR50F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_x0bU9Pi4_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_LZUpOBin_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cSend_cznlR50F_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_yCiPtOun_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x40000000: { // "2.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_WloHs8Om_sendMessage);
      break;
    }
    case 0x40400000: { // "3.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_4o85cGG8_sendMessage);
      break;
    }
    case 0x40800000: { // "4.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_7YU4WC90_sendMessage);
      break;
    }
    case 0x40A00000: { // "5.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_h7lT7rRO_sendMessage);
      break;
    }
    case 0x40C00000: { // "6.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_rKAnJiSr_sendMessage);
      break;
    }
    case 0x40E00000: { // "7.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_5krhxghP_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_WloHs8Om_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_0Ptmhr6Y_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_4o85cGG8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_74HAssXt_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_7YU4WC90_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_oQeyXmnd_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_h7lT7rRO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_JRNVns3S_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_rKAnJiSr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_a7vnlH3R_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_5krhxghP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_cxUbdKsF_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_CZdKpDNj_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_740gNqWB, 0, m, &cSlice_740gNqWB_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_TIx4K0o4, 0, m, &cRandom_TIx4K0o4_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_rXFjPICh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_l0sn64K0_sendMessage);
}

void Heavy_SoundScraper::cUnop_l0sn64K0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_VWhO8bi7_sendMessage);
}

void Heavy_SoundScraper::cRandom_TIx4K0o4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 5.0f, 0, m, &cBinop_rXFjPICh_sendMessage);
}

void Heavy_SoundScraper::cSlice_740gNqWB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_TIx4K0o4, 1, m, &cRandom_TIx4K0o4_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cMsg_a7vnlH3R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "marimba");
  msg_setFloat(m, 1, 264.0f);
  cSend_ULxvM4Ty_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_cxUbdKsF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "xylo");
  msg_setFloat(m, 1, 2116.9f);
  cSend_ULxvM4Ty_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_JRNVns3S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "bowl");
  msg_setFloat(m, 1, 705.52f);
  cSend_ULxvM4Ty_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_74HAssXt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "gong");
  msg_setFloat(m, 1, 179.88f);
  cSend_ULxvM4Ty_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_ULxvM4Ty_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_j1FDTCrp_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_oQeyXmnd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "crotale");
  msg_setFloat(m, 1, 1058.39f);
  cSend_ULxvM4Ty_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_VWhO8bi7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPrint_onMessage(_c, m, "SOUND_CHOICE");
  cSwitchcase_yCiPtOun_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cMsg_0Ptmhr6Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "almglocken");
  msg_setFloat(m, 1, 262.6f);
  cSend_ULxvM4Ty_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_3d0hP1mZ_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_5E8B9DNo, 0, m, &cSlice_5E8B9DNo_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_y2L6VOK5, 0, m, &cRandom_y2L6VOK5_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_iAD13atm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_vD896bD4_sendMessage);
}

void Heavy_SoundScraper::cUnop_vD896bD4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 10.0f, 0, m, &cBinop_csHwni79_sendMessage);
}

void Heavy_SoundScraper::cRandom_y2L6VOK5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 80.0f, 0, m, &cBinop_iAD13atm_sendMessage);
}

void Heavy_SoundScraper::cSlice_5E8B9DNo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_y2L6VOK5, 1, m, &cRandom_y2L6VOK5_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSwitchcase_mBnfzN4l_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_zbZuNIKy, 0, m, &cSlice_zbZuNIKy_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_RRw0yKLK, 0, m, &cRandom_RRw0yKLK_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_xMkOTvtR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_WBolmbIH_sendMessage);
}

void Heavy_SoundScraper::cUnop_WBolmbIH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_Ys1KLikb, 0, m, &cPack_Ys1KLikb_sendMessage);
}

void Heavy_SoundScraper::cRandom_RRw0yKLK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 200.0f, 0, m, &cBinop_xMkOTvtR_sendMessage);
}

void Heavy_SoundScraper::cSlice_zbZuNIKy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_RRw0yKLK, 1, m, &cRandom_RRw0yKLK_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cVar_h0Wb04ot_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_F1sZb4LU_sendMessage);
}

void Heavy_SoundScraper::cPack_qrlXgzV2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_NWaIhvDv, 0, m, NULL);
}

void Heavy_SoundScraper::cUnop_Koi1s1Om_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_L9kag5uq_sendMessage);
}

void Heavy_SoundScraper::cBinop_u8PCpkod_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_EXP, m, &cUnop_Koi1s1Om_sendMessage);
}

void Heavy_SoundScraper::cPack_YTI2wDDT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_QVlR4es3, 0, m, NULL);
}

void Heavy_SoundScraper::cVar_U0QPmYjI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.5f, 0, m, &cBinop_ALFBqyi1_sendMessage);
}

void Heavy_SoundScraper::cMsg_eacOvbsV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ZIGdL8T1_sendMessage);
}

void Heavy_SoundScraper::cSystem_ZIGdL8T1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_TUN7xelV_sendMessage);
}

void Heavy_SoundScraper::cDelay_E3oQ8e6G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_E3oQ8e6G, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_OF0IZkmp, 0, m, &cDelay_OF0IZkmp_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_E3oQ8e6G, 0, m, &cDelay_E3oQ8e6G_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_mqGmSwHE, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_OF0IZkmp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_OF0IZkmp, m);
  cMsg_6cwPWVzR_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_ZcGRz2wh_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_Dofw0nWt_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_z3gVgqzB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_VUPRSlt5_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_kwb3HxN8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_3AMtxr3q_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_E3oQ8e6G, 2, m, &cDelay_E3oQ8e6G_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_JznOhH8W_sendMessage);
}

void Heavy_SoundScraper::cMsg_VUPRSlt5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_kwb3HxN8, 0, m, &hTable_kwb3HxN8_sendMessage);
}

void Heavy_SoundScraper::cBinop_TUN7xelV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 5000.0f, 0, m, &cBinop_z3gVgqzB_sendMessage);
}

void Heavy_SoundScraper::cMsg_6cwPWVzR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_kwb3HxN8, 0, m, &hTable_kwb3HxN8_sendMessage);
}

void Heavy_SoundScraper::cCast_JznOhH8W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_E3oQ8e6G, 0, m, &cDelay_E3oQ8e6G_sendMessage);
}

void Heavy_SoundScraper::cMsg_3AMtxr3q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_OF0IZkmp, 2, m, &cDelay_OF0IZkmp_sendMessage);
}

void Heavy_SoundScraper::cMsg_Dofw0nWt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_mqGmSwHE, 1, m, NULL);
}

void Heavy_SoundScraper::cMsg_3P7YT8Zc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_v9LO6G5y_sendMessage);
}

void Heavy_SoundScraper::cSystem_v9LO6G5y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_1cTfN5wj_sendMessage);
}

void Heavy_SoundScraper::cVar_rcjf3SDj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_weCn4gHd_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSystem_7YPlsQMG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_VigawLkd_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_loioO01H, m);
}

void Heavy_SoundScraper::cBinop_1cTfN5wj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_Ftw3ql1o, m);
}

void Heavy_SoundScraper::cMsg_weCn4gHd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_7YPlsQMG_sendMessage);
}

void Heavy_SoundScraper::cBinop_VigawLkd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_e2Zzds5I, m);
}

void Heavy_SoundScraper::cMsg_r1eELBQX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_1vaeurIC_sendMessage);
}

void Heavy_SoundScraper::cSystem_1vaeurIC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_vqGXM2Bv_sendMessage);
}

void Heavy_SoundScraper::cVar_23iyp1fg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_HxuDKjxy_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSystem_IrBcEGHu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_69KhE7Qm_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_6gTTdqqR, m);
}

void Heavy_SoundScraper::cBinop_vqGXM2Bv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_atbmY5Dv, m);
}

void Heavy_SoundScraper::cMsg_HxuDKjxy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_IrBcEGHu_sendMessage);
}

void Heavy_SoundScraper::cBinop_69KhE7Qm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_h3K6ScRe, m);
}

void Heavy_SoundScraper::cBinop_gA5B5gkb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_GHiBmGoB_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_emBc1IDZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_wyjMcgOx_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_w9B4vjGm_sendMessage);
}

void Heavy_SoundScraper::cCast_wyjMcgOx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_gA5B5gkb, HV_BINOP_DIVIDE, 1, m, &cBinop_gA5B5gkb_sendMessage);
}

void Heavy_SoundScraper::cCast_w9B4vjGm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_gA5B5gkb, HV_BINOP_DIVIDE, 0, m, &cBinop_gA5B5gkb_sendMessage);
}

void Heavy_SoundScraper::cBinop_L9kag5uq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_xeqT61ZN_sendMessage);
}

void Heavy_SoundScraper::cBinop_dq9JK1jl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 87.3365f, 0, m, &cBinop_u8PCpkod_sendMessage);
}

void Heavy_SoundScraper::cBinop_xeqT61ZN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_gA5B5gkb, HV_BINOP_DIVIDE, 0, m, &cBinop_gA5B5gkb_sendMessage);
}

void Heavy_SoundScraper::cBinop_ALFBqyi1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_YTI2wDDT, 0, m, &cPack_YTI2wDDT_sendMessage);
}

void Heavy_SoundScraper::cBinop_F1sZb4LU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.001f, 0, m, &cBinop_emBc1IDZ_sendMessage);
  cPack_onMessage(_c, &Context(_c)->cPack_qrlXgzV2, 0, m, &cPack_qrlXgzV2_sendMessage);
}

void Heavy_SoundScraper::cMsg_ufZfDLfL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 100.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_h0Wb04ot, 0, m, &cVar_h0Wb04ot_sendMessage);
}

void Heavy_SoundScraper::cMsg_uXfJOiYb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.5f);
  cVar_onMessage(_c, &Context(_c)->cVar_U0QPmYjI, 0, m, &cVar_U0QPmYjI_sendMessage);
}

void Heavy_SoundScraper::cMsg_GHiBmGoB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 30.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_C4j67utO, 0, m, NULL);
}

void Heavy_SoundScraper::cMsg_zWI3BuqO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_u8Suv5yC_sendMessage);
}

void Heavy_SoundScraper::cSystem_u8Suv5yC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_hilWSh5e_sendMessage);
}

void Heavy_SoundScraper::cVar_e77iYaUb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_I7zHlnPh_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSystem_6NDfuUcl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_fri4jYv0_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_IILCOUkj, m);
}

void Heavy_SoundScraper::cBinop_hilWSh5e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_eGBesSoR, m);
}

void Heavy_SoundScraper::cMsg_I7zHlnPh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_6NDfuUcl_sendMessage);
}

void Heavy_SoundScraper::cBinop_fri4jYv0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_xdWOs8ll, m);
}

void Heavy_SoundScraper::cVar_1OAzPySG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_HuQSXYR4, HV_BINOP_MULTIPLY, 0, m, &cBinop_HuQSXYR4_sendMessage);
}

void Heavy_SoundScraper::cMsg_PqSxkbUk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_3bi5NgIX_sendMessage);
}

void Heavy_SoundScraper::cSystem_3bi5NgIX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_aP3us8xn_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_HuQSXYR4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_8bZ313gZ_sendMessage);
}

void Heavy_SoundScraper::cBinop_way1Nane_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_HuQSXYR4, HV_BINOP_MULTIPLY, 1, m, &cBinop_HuQSXYR4_sendMessage);
}

void Heavy_SoundScraper::cMsg_aP3us8xn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_way1Nane_sendMessage);
}

void Heavy_SoundScraper::cBinop_8bZ313gZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_kCxg2dv0_sendMessage);
}

void Heavy_SoundScraper::cBinop_kCxg2dv0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_41X7I2N7_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_fEfALegh, m);
}

void Heavy_SoundScraper::cBinop_41X7I2N7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_WWRtHYUq, m);
}

void Heavy_SoundScraper::cBinop_QGq1QVwA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, -1.0f, 0, m, &cBinop_R90m8DIy_sendMessage);
}

void Heavy_SoundScraper::cBinop_R90m8DIy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_wg4UNVk3, m);
}

void Heavy_SoundScraper::cBinop_MbGZRupi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_GVgyzsP7_sendMessage);
}

void Heavy_SoundScraper::cBinop_GVgyzsP7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_rt4Yjsrp_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_pRiR5DSI_sendMessage);
}

void Heavy_SoundScraper::cVar_JFI1M2Kw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_8AjagMZ9_sendMessage);
}

void Heavy_SoundScraper::cMsg_taZczRJi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_jPZJ59iR_sendMessage);
}

void Heavy_SoundScraper::cSystem_jPZJ59iR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_tOuNgEAN, HV_BINOP_DIVIDE, 1, m, &cBinop_tOuNgEAN_sendMessage);
}

void Heavy_SoundScraper::cBinop_rt4Yjsrp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_tG1t5vaF_sendMessage);
}

void Heavy_SoundScraper::cBinop_tG1t5vaF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_5pgMUuSl, m);
}

void Heavy_SoundScraper::cMsg_XsLtG3Al_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_ZsDRzWcT_sendMessage);
}

void Heavy_SoundScraper::cBinop_ZsDRzWcT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_MbGZRupi_sendMessage);
}

void Heavy_SoundScraper::cBinop_pRiR5DSI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_toE901Wj, m);
}

void Heavy_SoundScraper::cBinop_8AjagMZ9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_6CFHEzyK_sendMessage);
}

void Heavy_SoundScraper::cBinop_6CFHEzyK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_tOuNgEAN, HV_BINOP_DIVIDE, 0, m, &cBinop_tOuNgEAN_sendMessage);
}

void Heavy_SoundScraper::cBinop_tOuNgEAN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_XsLtG3Al_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_r3nNffBh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_XroAiHC8_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_U8SSk7at_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_LjlMmajE_sendMessage);
}

void Heavy_SoundScraper::cSystem_LjlMmajE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_2ALgtyAy_sendMessage);
}

void Heavy_SoundScraper::cDelay_IfEdnP6q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_IfEdnP6q, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_fcgarXxo, 0, m, &cDelay_fcgarXxo_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_IfEdnP6q, 0, m, &cDelay_IfEdnP6q_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_8O0A9Pu4, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_fcgarXxo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_fcgarXxo, m);
  cMsg_MT2MA5y0_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_22pvt3yo_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_BPGZgxbn_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_9WM1aDMv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_4P7waR3Y_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_SFNzaQne_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_B9I9xueK_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_IfEdnP6q, 2, m, &cDelay_IfEdnP6q_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_hYIrFg4r_sendMessage);
}

void Heavy_SoundScraper::cMsg_4P7waR3Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_SFNzaQne, 0, m, &hTable_SFNzaQne_sendMessage);
}

void Heavy_SoundScraper::cBinop_2ALgtyAy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 200.0f, 0, m, &cBinop_9WM1aDMv_sendMessage);
}

void Heavy_SoundScraper::cMsg_MT2MA5y0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_SFNzaQne, 0, m, &hTable_SFNzaQne_sendMessage);
}

void Heavy_SoundScraper::cCast_hYIrFg4r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_IfEdnP6q, 0, m, &cDelay_IfEdnP6q_sendMessage);
}

void Heavy_SoundScraper::cMsg_B9I9xueK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_fcgarXxo, 2, m, &cDelay_fcgarXxo_sendMessage);
}

void Heavy_SoundScraper::cMsg_BPGZgxbn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_8O0A9Pu4, 1, m, NULL);
}

void Heavy_SoundScraper::cMsg_U6s41R8f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cMsg_XroAiHC8_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_XroAiHC8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 20.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_thLkgnxU, 0, m, NULL);
}

void Heavy_SoundScraper::cVar_mNeNzRqT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cMsg_oBZElT3B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Xi7LbjZj_sendMessage);
}

void Heavy_SoundScraper::cSystem_Xi7LbjZj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_mWS7l2Qv, HV_BINOP_MULTIPLY, 1, m, &cBinop_mWS7l2Qv_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_0m4IcsLg, HV_BINOP_MULTIPLY, 1, m, &cBinop_0m4IcsLg_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_4JokVVMT_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cMsg_iXtpVgjh_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_iXtpVgjh_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_hMSzvkxO_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cDelay_jNEeoJAh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_jNEeoJAh, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_jNEeoJAh, 0, m, &cDelay_jNEeoJAh_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_rj2uM0X5, 0, m, &cVar_rj2uM0X5_sendMessage);
}

void Heavy_SoundScraper::cCast_hMSzvkxO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_iXtpVgjh_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_jNEeoJAh, 0, m, &cDelay_jNEeoJAh_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_rj2uM0X5, 0, m, &cVar_rj2uM0X5_sendMessage);
}

void Heavy_SoundScraper::cMsg_4CIbfUeX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_4eJMsbQV_sendMessage);
}

void Heavy_SoundScraper::cSystem_4eJMsbQV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_ELehfhGZ_sendMessage);
}

void Heavy_SoundScraper::cVar_iIjBEoKw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_N06H1oWB, HV_BINOP_MULTIPLY, 0, m, &cBinop_N06H1oWB_sendMessage);
}

void Heavy_SoundScraper::cMsg_iXtpVgjh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_jNEeoJAh, 0, m, &cDelay_jNEeoJAh_sendMessage);
}

void Heavy_SoundScraper::cBinop_4b64UisA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_jNEeoJAh, 2, m, &cDelay_jNEeoJAh_sendMessage);
}

void Heavy_SoundScraper::cBinop_ELehfhGZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_N06H1oWB, HV_BINOP_MULTIPLY, 1, m, &cBinop_N06H1oWB_sendMessage);
}

void Heavy_SoundScraper::cBinop_N06H1oWB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_4b64UisA_sendMessage);
}

void Heavy_SoundScraper::cVar_rj2uM0X5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_yg2x9tLj, HV_BINOP_SUBTRACT, 0, m, &cBinop_yg2x9tLj_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_LESS_THAN_EQL, 0.0f, 0, m, &cBinop_3cdUOcJJ_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_tAmtN7J5_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_trDasCyN_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_WhIZ6m0p_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_trDasCyN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ipT94t5z, 0, m, &cVar_ipT94t5z_sendMessage);
}

void Heavy_SoundScraper::cCast_WhIZ6m0p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_JVt9jav6_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_M4YA0qY4_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_3Lv0buNt_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cSlice_onMessage(_c, &Context(_c)->cSlice_2fCZljHc, 0, m, &cSlice_2fCZljHc_sendMessage);
      break;
    }
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_fDlFPg7r, 0, m, &cSlice_fDlFPg7r_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_72DKMzVE_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_N68AgZWY, 0, m, &cSlice_N68AgZWY_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_vR4uxQmU, 0, m, &cSlice_vR4uxQmU_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_NzRKhFIT_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_heytzCvD_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cSlice_2fCZljHc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_0xoBpEqe_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_0xoBpEqe_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_fDlFPg7r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_NwuQW5Gx_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Bla4dlvc_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_NwuQW5Gx_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Bla4dlvc_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cVar_uX9tK8Mz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_xQ3AavhE_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_cyVgT51i_sendMessage);
}

void Heavy_SoundScraper::cVar_k7NHxPuo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_dHgx38M1_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cSwitchcase_dHgx38M1_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_0DaPL9o0_sendMessage);
      break;
    }
    default: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_mWS7l2Qv, HV_BINOP_MULTIPLY, 0, m, &cBinop_mWS7l2Qv_sendMessage);
      cBinop_onMessage(_c, &Context(_c)->cBinop_5M00dT5c, HV_BINOP_DIVIDE, 1, m, &cBinop_5M00dT5c_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_iIjBEoKw, 0, m, &cVar_iIjBEoKw_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_0DaPL9o0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_PbWDFnqz_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_8kmKr67X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_rtQjLxJs, HV_BINOP_SUBTRACT, 1, m, &cBinop_rtQjLxJs_sendMessage);
}

void Heavy_SoundScraper::cVar_4AoArzfL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ipT94t5z, 0, m, &cVar_ipT94t5z_sendMessage);
}

void Heavy_SoundScraper::cVar_ipT94t5z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_UHKFDNAE, HV_BINOP_ADD, 0, m, &cBinop_UHKFDNAE_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_IRBrqjx8, HV_BINOP_ADD, 0, m, &cBinop_IRBrqjx8_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_ZQtf2nwS, 0, m, &cVar_ZQtf2nwS_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.05776f, 0, m, &cBinop_dq9JK1jl_sendMessage);
}

void Heavy_SoundScraper::cSlice_N68AgZWY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_xQ3AavhE_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_cyVgT51i_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_vR4uxQmU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_fJQibE0g_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_HgX6iXfq_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_7Ag38yHN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_rj2uM0X5, 1, m, &cVar_rj2uM0X5_sendMessage);
}

void Heavy_SoundScraper::cBinop_0m4IcsLg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_7Ag38yHN_sendMessage);
}

void Heavy_SoundScraper::cBinop_mWS7l2Qv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_eDy9Xbb7_sendMessage);
}

void Heavy_SoundScraper::cBinop_eDy9Xbb7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_yg2x9tLj, HV_BINOP_SUBTRACT, 1, m, &cBinop_yg2x9tLj_sendMessage);
}

void Heavy_SoundScraper::cBinop_yg2x9tLj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_rj2uM0X5, 1, m, &cVar_rj2uM0X5_sendMessage);
}

void Heavy_SoundScraper::cMsg_rkanNXJB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_4JokVVMT_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cMsg_BfVHZhUt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_4JokVVMT_onMessage(_c, NULL, 0, m, NULL);
  cBinop_onMessage(_c, &Context(_c)->cBinop_IRBrqjx8, HV_BINOP_ADD, 1, m, &cBinop_IRBrqjx8_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_UHKFDNAE, HV_BINOP_ADD, 1, m, &cBinop_UHKFDNAE_sendMessage);
}

void Heavy_SoundScraper::cBinop_3cdUOcJJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_tAmtN7J5_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_UHKFDNAE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ipT94t5z, 1, m, &cVar_ipT94t5z_sendMessage);
}

void Heavy_SoundScraper::cBinop_5M00dT5c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_UUe1Ai2h, HV_BINOP_DIVIDE, 1, m, &cBinop_UUe1Ai2h_sendMessage);
}

void Heavy_SoundScraper::cBinop_UUe1Ai2h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_IRBrqjx8, HV_BINOP_ADD, 1, m, &cBinop_IRBrqjx8_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_UHKFDNAE, HV_BINOP_ADD, 1, m, &cBinop_UHKFDNAE_sendMessage);
}

void Heavy_SoundScraper::cCast_xQ3AavhE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_0m4IcsLg, HV_BINOP_MULTIPLY, 0, m, &cBinop_0m4IcsLg_sendMessage);
}

void Heavy_SoundScraper::cCast_cyVgT51i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_5M00dT5c, HV_BINOP_DIVIDE, 0, m, &cBinop_5M00dT5c_sendMessage);
}

void Heavy_SoundScraper::cCast_HgX6iXfq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_rtQjLxJs, HV_BINOP_SUBTRACT, 0, m, &cBinop_rtQjLxJs_sendMessage);
}

void Heavy_SoundScraper::cCast_fJQibE0g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_4AoArzfL, 1, m, &cVar_4AoArzfL_sendMessage);
}

void Heavy_SoundScraper::cCast_M4YA0qY4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_4AoArzfL, 0, m, &cVar_4AoArzfL_sendMessage);
}

void Heavy_SoundScraper::cCast_JVt9jav6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_BfVHZhUt_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_IRBrqjx8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_8kmKr67X, 0, m, &cVar_8kmKr67X_sendMessage);
}

void Heavy_SoundScraper::cMsg_0xoBpEqe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_4JokVVMT_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cMsg_nBG4ps5F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_uX9tK8Mz, 1, m, &cVar_uX9tK8Mz_sendMessage);
}

void Heavy_SoundScraper::cMsg_PbWDFnqz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 20.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_mWS7l2Qv, HV_BINOP_MULTIPLY, 0, m, &cBinop_mWS7l2Qv_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_5M00dT5c, HV_BINOP_DIVIDE, 1, m, &cBinop_5M00dT5c_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_iIjBEoKw, 0, m, &cVar_iIjBEoKw_sendMessage);
}

void Heavy_SoundScraper::cCast_Bla4dlvc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_aKnzJkrt_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_IRBrqjx8, HV_BINOP_ADD, 0, m, &cBinop_IRBrqjx8_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_ipT94t5z, 1, m, &cVar_ipT94t5z_sendMessage);
}

void Heavy_SoundScraper::cCast_NwuQW5Gx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_0xoBpEqe_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_rtQjLxJs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_UUe1Ai2h, HV_BINOP_DIVIDE, 0, m, &cBinop_UUe1Ai2h_sendMessage);
}

void Heavy_SoundScraper::cCast_aKnzJkrt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_BfVHZhUt_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_72DKMzVE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_uX9tK8Mz, 0, m, &cVar_uX9tK8Mz_sendMessage);
}

void Heavy_SoundScraper::cCast_NzRKhFIT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_rkanNXJB_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_heytzCvD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_nBG4ps5F_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_ZQtf2nwS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cPack_gbbxVdnG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_3Lv0buNt_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cMsg_XC2gToZy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_mloy4pkN_sendMessage);
}

void Heavy_SoundScraper::cSystem_mloy4pkN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_LTUG6e9t, HV_BINOP_MULTIPLY, 1, m, &cBinop_LTUG6e9t_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_vdY2YYdY, HV_BINOP_MULTIPLY, 1, m, &cBinop_vdY2YYdY_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_aSA6GYUc_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cMsg_KTLE5LYj_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_KTLE5LYj_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_SyywKbrh_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cDelay_gGRG7G4A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_gGRG7G4A, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_gGRG7G4A, 0, m, &cDelay_gGRG7G4A_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_XkXmCuDR, 0, m, &cVar_XkXmCuDR_sendMessage);
}

void Heavy_SoundScraper::cCast_SyywKbrh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_KTLE5LYj_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_gGRG7G4A, 0, m, &cDelay_gGRG7G4A_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_XkXmCuDR, 0, m, &cVar_XkXmCuDR_sendMessage);
}

void Heavy_SoundScraper::cMsg_iyXPLXkX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Qcy6ztsn_sendMessage);
}

void Heavy_SoundScraper::cSystem_Qcy6ztsn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_Mk6jqAPj_sendMessage);
}

void Heavy_SoundScraper::cVar_9PxGGMkN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_lwipBM0s, HV_BINOP_MULTIPLY, 0, m, &cBinop_lwipBM0s_sendMessage);
}

void Heavy_SoundScraper::cMsg_KTLE5LYj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_gGRG7G4A, 0, m, &cDelay_gGRG7G4A_sendMessage);
}

void Heavy_SoundScraper::cBinop_tJbor8nX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_gGRG7G4A, 2, m, &cDelay_gGRG7G4A_sendMessage);
}

void Heavy_SoundScraper::cBinop_Mk6jqAPj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_lwipBM0s, HV_BINOP_MULTIPLY, 1, m, &cBinop_lwipBM0s_sendMessage);
}

void Heavy_SoundScraper::cBinop_lwipBM0s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_tJbor8nX_sendMessage);
}

void Heavy_SoundScraper::cVar_XkXmCuDR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_jQZcFwvg, HV_BINOP_SUBTRACT, 0, m, &cBinop_jQZcFwvg_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_LESS_THAN_EQL, 0.0f, 0, m, &cBinop_JSARVk7e_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_y4GFDJle_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_VqORqfDf_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_RTwDePnw_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_VqORqfDf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_OgGmOEXI, 0, m, &cVar_OgGmOEXI_sendMessage);
}

void Heavy_SoundScraper::cCast_RTwDePnw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Lh0kjmH0_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_gJ1TDnE3_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_8N3daVe0_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cSlice_onMessage(_c, &Context(_c)->cSlice_PBZSVtit, 0, m, &cSlice_PBZSVtit_sendMessage);
      break;
    }
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_XEJnjcPU, 0, m, &cSlice_XEJnjcPU_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ZJLe5YRe_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_UP0Amu02, 0, m, &cSlice_UP0Amu02_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_Yv5dP9Xr, 0, m, &cSlice_Yv5dP9Xr_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_yWWQ1Pjd_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_O1X85RLM_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cSlice_PBZSVtit_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_Wd9qtBrH_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_Wd9qtBrH_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_XEJnjcPU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_sPor0VYl_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_aDgyyFQl_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_sPor0VYl_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_aDgyyFQl_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cVar_GQwtc3qh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_oNVnAo9G_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_b0k1C6gl_sendMessage);
}

void Heavy_SoundScraper::cVar_uG4H4pOF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_bPFzxh8e_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cSwitchcase_bPFzxh8e_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_PH0eo1ku_sendMessage);
      break;
    }
    default: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_LTUG6e9t, HV_BINOP_MULTIPLY, 0, m, &cBinop_LTUG6e9t_sendMessage);
      cBinop_onMessage(_c, &Context(_c)->cBinop_fkItBcQK, HV_BINOP_DIVIDE, 1, m, &cBinop_fkItBcQK_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_9PxGGMkN, 0, m, &cVar_9PxGGMkN_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_PH0eo1ku_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ms62lfo0_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_gssQJxMj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_eK3dGTiz, HV_BINOP_SUBTRACT, 1, m, &cBinop_eK3dGTiz_sendMessage);
}

void Heavy_SoundScraper::cVar_iPKqDrRJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_OgGmOEXI, 0, m, &cVar_OgGmOEXI_sendMessage);
}

void Heavy_SoundScraper::cVar_OgGmOEXI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_JWVh3bLc, HV_BINOP_ADD, 0, m, &cBinop_JWVh3bLc_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_U744s2dN, HV_BINOP_ADD, 0, m, &cBinop_U744s2dN_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_mNeNzRqT, 0, m, &cVar_mNeNzRqT_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_8VQ2N8Ei, m);
}

void Heavy_SoundScraper::cSlice_UP0Amu02_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_oNVnAo9G_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_b0k1C6gl_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_Yv5dP9Xr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_U0gT25wd_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_dAyjDcRG_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_GgQeGCeh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_XkXmCuDR, 1, m, &cVar_XkXmCuDR_sendMessage);
}

void Heavy_SoundScraper::cBinop_vdY2YYdY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_GgQeGCeh_sendMessage);
}

void Heavy_SoundScraper::cBinop_LTUG6e9t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_crWz0KfQ_sendMessage);
}

void Heavy_SoundScraper::cBinop_crWz0KfQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_jQZcFwvg, HV_BINOP_SUBTRACT, 1, m, &cBinop_jQZcFwvg_sendMessage);
}

void Heavy_SoundScraper::cBinop_jQZcFwvg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_XkXmCuDR, 1, m, &cVar_XkXmCuDR_sendMessage);
}

void Heavy_SoundScraper::cMsg_QPAdD3Ax_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_aSA6GYUc_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cMsg_aFwMeJFG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_aSA6GYUc_onMessage(_c, NULL, 0, m, NULL);
  cBinop_onMessage(_c, &Context(_c)->cBinop_U744s2dN, HV_BINOP_ADD, 1, m, &cBinop_U744s2dN_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_JWVh3bLc, HV_BINOP_ADD, 1, m, &cBinop_JWVh3bLc_sendMessage);
}

void Heavy_SoundScraper::cBinop_JSARVk7e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_y4GFDJle_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_JWVh3bLc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_OgGmOEXI, 1, m, &cVar_OgGmOEXI_sendMessage);
}

void Heavy_SoundScraper::cBinop_fkItBcQK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Zs0TFRUg, HV_BINOP_DIVIDE, 1, m, &cBinop_Zs0TFRUg_sendMessage);
}

void Heavy_SoundScraper::cBinop_Zs0TFRUg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_U744s2dN, HV_BINOP_ADD, 1, m, &cBinop_U744s2dN_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_JWVh3bLc, HV_BINOP_ADD, 1, m, &cBinop_JWVh3bLc_sendMessage);
}

void Heavy_SoundScraper::cCast_oNVnAo9G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_vdY2YYdY, HV_BINOP_MULTIPLY, 0, m, &cBinop_vdY2YYdY_sendMessage);
}

void Heavy_SoundScraper::cCast_b0k1C6gl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_fkItBcQK, HV_BINOP_DIVIDE, 0, m, &cBinop_fkItBcQK_sendMessage);
}

void Heavy_SoundScraper::cCast_dAyjDcRG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_eK3dGTiz, HV_BINOP_SUBTRACT, 0, m, &cBinop_eK3dGTiz_sendMessage);
}

void Heavy_SoundScraper::cCast_U0gT25wd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_iPKqDrRJ, 1, m, &cVar_iPKqDrRJ_sendMessage);
}

void Heavy_SoundScraper::cCast_Lh0kjmH0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_aFwMeJFG_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_gJ1TDnE3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_iPKqDrRJ, 0, m, &cVar_iPKqDrRJ_sendMessage);
}

void Heavy_SoundScraper::cBinop_U744s2dN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_gssQJxMj, 0, m, &cVar_gssQJxMj_sendMessage);
}

void Heavy_SoundScraper::cMsg_Wd9qtBrH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_aSA6GYUc_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cMsg_qjLo6JkI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_GQwtc3qh, 1, m, &cVar_GQwtc3qh_sendMessage);
}

void Heavy_SoundScraper::cMsg_ms62lfo0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 20.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_LTUG6e9t, HV_BINOP_MULTIPLY, 0, m, &cBinop_LTUG6e9t_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_fkItBcQK, HV_BINOP_DIVIDE, 1, m, &cBinop_fkItBcQK_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_9PxGGMkN, 0, m, &cVar_9PxGGMkN_sendMessage);
}

void Heavy_SoundScraper::cCast_sPor0VYl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Wd9qtBrH_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_aDgyyFQl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_IFSRh4VF_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_U744s2dN, HV_BINOP_ADD, 0, m, &cBinop_U744s2dN_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_OgGmOEXI, 1, m, &cVar_OgGmOEXI_sendMessage);
}

void Heavy_SoundScraper::cBinop_eK3dGTiz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Zs0TFRUg, HV_BINOP_DIVIDE, 0, m, &cBinop_Zs0TFRUg_sendMessage);
}

void Heavy_SoundScraper::cCast_IFSRh4VF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_aFwMeJFG_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_O1X85RLM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_qjLo6JkI_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_ZJLe5YRe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_GQwtc3qh, 0, m, &cVar_GQwtc3qh_sendMessage);
}

void Heavy_SoundScraper::cCast_yWWQ1Pjd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_QPAdD3Ax_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_Ys1KLikb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_8N3daVe0_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cPack_f73hkHp6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_uGff1jyA, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_hB2MLZ2M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 4.0f, 0, m, &cBinop_tR6nKaqC_sendMessage);
}

void Heavy_SoundScraper::cBinop_tR6nKaqC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_gbbxVdnG, 0, m, &cPack_gbbxVdnG_sendMessage);
}

void Heavy_SoundScraper::cBinop_csHwni79_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_hB2MLZ2M_sendMessage);
}

void Heavy_SoundScraper::cCast_8J58vMYa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_3d0hP1mZ_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_OwUxuiHC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_mBnfzN4l_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cMsg_iE8iaihz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.15f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_QGq1QVwA_sendMessage);
}

void Heavy_SoundScraper::cTabhead_qVF37Eil_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_TNVNqReS, HV_BINOP_SUBTRACT, 0, m, &cBinop_TNVNqReS_sendMessage);
}

void Heavy_SoundScraper::cMsg_4jh3V1GP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_nhjh0f48_sendMessage);
}

void Heavy_SoundScraper::cSystem_nhjh0f48_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_f3kmxooA_sendMessage);
}

void Heavy_SoundScraper::cVar_DHRgYpdP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_CJIA0HSY_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_TkVADJRj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_TkVADJRj, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Jlyfl0bb, 0, m, &cDelay_Jlyfl0bb_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_dj81ruJi, 0, m, &sTabread_dj81ruJi_sendMessage);
}

void Heavy_SoundScraper::cDelay_Jlyfl0bb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Jlyfl0bb, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_dj81ruJi, 0, m, &sTabread_dj81ruJi_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Jlyfl0bb, 0, m, &cDelay_Jlyfl0bb_sendMessage);
}

void Heavy_SoundScraper::sTabread_dj81ruJi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_IyVswin5, HV_BINOP_SUBTRACT, 0, m, &cBinop_IyVswin5_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_H7AlOLFR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_AFLy0EnA, HV_BINOP_MAX, 0, m, &cBinop_AFLy0EnA_sendMessage);
}

void Heavy_SoundScraper::cBinop_f3kmxooA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_H7AlOLFR, HV_BINOP_MULTIPLY, 0, m, &cBinop_H7AlOLFR_sendMessage);
}

void Heavy_SoundScraper::cBinop_TNVNqReS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_JqWkrS4B_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_dj81ruJi, 0, m, &sTabread_dj81ruJi_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_6mEOkNwt_sendMessage);
}

void Heavy_SoundScraper::cSystem_9LU3n2aH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_IyVswin5, HV_BINOP_SUBTRACT, 1, m, &cBinop_IyVswin5_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Jlyfl0bb, 2, m, &cDelay_Jlyfl0bb_sendMessage);
}

void Heavy_SoundScraper::cMsg_CJIA0HSY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_9LU3n2aH_sendMessage);
}

void Heavy_SoundScraper::cMsg_JqWkrS4B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_TkVADJRj, 0, m, &cDelay_TkVADJRj_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Jlyfl0bb, 0, m, &cDelay_Jlyfl0bb_sendMessage);
}

void Heavy_SoundScraper::cMsg_YqfLe7rH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_AFLy0EnA, HV_BINOP_MAX, 1, m, &cBinop_AFLy0EnA_sendMessage);
}

void Heavy_SoundScraper::cBinop_AFLy0EnA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_TNVNqReS, HV_BINOP_SUBTRACT, 1, m, &cBinop_TNVNqReS_sendMessage);
}

void Heavy_SoundScraper::cCast_6mEOkNwt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_TkVADJRj, 0, m, &cDelay_TkVADJRj_sendMessage);
}

void Heavy_SoundScraper::cBinop_W8vc4dqt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_TkVADJRj, 2, m, &cDelay_TkVADJRj_sendMessage);
}

void Heavy_SoundScraper::cBinop_IyVswin5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_W8vc4dqt_sendMessage);
}

void Heavy_SoundScraper::cCast_6i5iVAhj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_DHRgYpdP, 0, m, &cVar_DHRgYpdP_sendMessage);
  cMsg_4jh3V1GP_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_qVF37Eil, 0, m, &cTabhead_qVF37Eil_sendMessage);
}

void Heavy_SoundScraper::cTabhead_oqVCEBbQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_wt9QCutb, HV_BINOP_SUBTRACT, 0, m, &cBinop_wt9QCutb_sendMessage);
}

void Heavy_SoundScraper::cMsg_zcM9RDHG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_WhGtXoqO_sendMessage);
}

void Heavy_SoundScraper::cSystem_WhGtXoqO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_AIdhDR1F_sendMessage);
}

void Heavy_SoundScraper::cVar_t8P3L1EW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_UKUqngC0_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_gLUeKYtU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_gLUeKYtU, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_V8XTvG9l, 0, m, &cDelay_V8XTvG9l_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_Jt2pjvQn, 0, m, &sTabread_Jt2pjvQn_sendMessage);
}

void Heavy_SoundScraper::cDelay_V8XTvG9l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_V8XTvG9l, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_Jt2pjvQn, 0, m, &sTabread_Jt2pjvQn_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_V8XTvG9l, 0, m, &cDelay_V8XTvG9l_sendMessage);
}

void Heavy_SoundScraper::sTabread_Jt2pjvQn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_pOmf6gqL, HV_BINOP_SUBTRACT, 0, m, &cBinop_pOmf6gqL_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_MX8pfgWp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_lTOGjWd9, HV_BINOP_MAX, 0, m, &cBinop_lTOGjWd9_sendMessage);
}

void Heavy_SoundScraper::cBinop_AIdhDR1F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MX8pfgWp, HV_BINOP_MULTIPLY, 0, m, &cBinop_MX8pfgWp_sendMessage);
}

void Heavy_SoundScraper::cBinop_wt9QCutb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_btvM4MaR_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_Jt2pjvQn, 0, m, &sTabread_Jt2pjvQn_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_dWPEkSm5_sendMessage);
}

void Heavy_SoundScraper::cSystem_gWvWt6kw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_pOmf6gqL, HV_BINOP_SUBTRACT, 1, m, &cBinop_pOmf6gqL_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_V8XTvG9l, 2, m, &cDelay_V8XTvG9l_sendMessage);
}

void Heavy_SoundScraper::cMsg_UKUqngC0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_gWvWt6kw_sendMessage);
}

void Heavy_SoundScraper::cMsg_btvM4MaR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_gLUeKYtU, 0, m, &cDelay_gLUeKYtU_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_V8XTvG9l, 0, m, &cDelay_V8XTvG9l_sendMessage);
}

void Heavy_SoundScraper::cMsg_YI8gZmpw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_lTOGjWd9, HV_BINOP_MAX, 1, m, &cBinop_lTOGjWd9_sendMessage);
}

void Heavy_SoundScraper::cBinop_lTOGjWd9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_wt9QCutb, HV_BINOP_SUBTRACT, 1, m, &cBinop_wt9QCutb_sendMessage);
}

void Heavy_SoundScraper::cCast_dWPEkSm5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_gLUeKYtU, 0, m, &cDelay_gLUeKYtU_sendMessage);
}

void Heavy_SoundScraper::cBinop_yyvyXsPg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_gLUeKYtU, 2, m, &cDelay_gLUeKYtU_sendMessage);
}

void Heavy_SoundScraper::cBinop_pOmf6gqL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_yyvyXsPg_sendMessage);
}

void Heavy_SoundScraper::cCast_IPMT6OwY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_t8P3L1EW, 0, m, &cVar_t8P3L1EW_sendMessage);
  cMsg_zcM9RDHG_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_oqVCEBbQ, 0, m, &cTabhead_oqVCEBbQ_sendMessage);
}

void Heavy_SoundScraper::cTabhead_neDLBLlx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6s8Sg1Cu, HV_BINOP_SUBTRACT, 0, m, &cBinop_6s8Sg1Cu_sendMessage);
}

void Heavy_SoundScraper::cMsg_nlnf2lHS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_cPA0VagK_sendMessage);
}

void Heavy_SoundScraper::cSystem_cPA0VagK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_oBratGCd_sendMessage);
}

void Heavy_SoundScraper::cVar_HqrDdm4K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ewb7hRpy_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_aeMDgzWH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_aeMDgzWH, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_S6UjVzAR, 0, m, &cDelay_S6UjVzAR_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_MC2Hs4Y3, 0, m, &sTabread_MC2Hs4Y3_sendMessage);
}

void Heavy_SoundScraper::cDelay_S6UjVzAR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_S6UjVzAR, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_MC2Hs4Y3, 0, m, &sTabread_MC2Hs4Y3_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_S6UjVzAR, 0, m, &cDelay_S6UjVzAR_sendMessage);
}

void Heavy_SoundScraper::sTabread_MC2Hs4Y3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_DmO8gvNF, HV_BINOP_SUBTRACT, 0, m, &cBinop_DmO8gvNF_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_SOYyPH1l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_YATcnKsm, HV_BINOP_MAX, 0, m, &cBinop_YATcnKsm_sendMessage);
}

void Heavy_SoundScraper::cBinop_oBratGCd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_SOYyPH1l, HV_BINOP_MULTIPLY, 0, m, &cBinop_SOYyPH1l_sendMessage);
}

void Heavy_SoundScraper::cBinop_6s8Sg1Cu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_vTV2gj8d_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_MC2Hs4Y3, 0, m, &sTabread_MC2Hs4Y3_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_R2b8jkF2_sendMessage);
}

void Heavy_SoundScraper::cSystem_gItCQSpN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_DmO8gvNF, HV_BINOP_SUBTRACT, 1, m, &cBinop_DmO8gvNF_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_S6UjVzAR, 2, m, &cDelay_S6UjVzAR_sendMessage);
}

void Heavy_SoundScraper::cMsg_ewb7hRpy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_gItCQSpN_sendMessage);
}

void Heavy_SoundScraper::cMsg_vTV2gj8d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_aeMDgzWH, 0, m, &cDelay_aeMDgzWH_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_S6UjVzAR, 0, m, &cDelay_S6UjVzAR_sendMessage);
}

void Heavy_SoundScraper::cMsg_6Ykj3Diu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_YATcnKsm, HV_BINOP_MAX, 1, m, &cBinop_YATcnKsm_sendMessage);
}

void Heavy_SoundScraper::cBinop_YATcnKsm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6s8Sg1Cu, HV_BINOP_SUBTRACT, 1, m, &cBinop_6s8Sg1Cu_sendMessage);
}

void Heavy_SoundScraper::cCast_R2b8jkF2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_aeMDgzWH, 0, m, &cDelay_aeMDgzWH_sendMessage);
}

void Heavy_SoundScraper::cBinop_OYS5lD87_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_aeMDgzWH, 2, m, &cDelay_aeMDgzWH_sendMessage);
}

void Heavy_SoundScraper::cBinop_DmO8gvNF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_OYS5lD87_sendMessage);
}

void Heavy_SoundScraper::cCast_Uvg0BOYK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_HqrDdm4K, 0, m, &cVar_HqrDdm4K_sendMessage);
  cMsg_nlnf2lHS_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_neDLBLlx, 0, m, &cTabhead_neDLBLlx_sendMessage);
}

void Heavy_SoundScraper::cTabhead_nmlLjw0L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_wq6KmTcC, HV_BINOP_SUBTRACT, 0, m, &cBinop_wq6KmTcC_sendMessage);
}

void Heavy_SoundScraper::cMsg_KOwESreD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_x5pG9Jby_sendMessage);
}

void Heavy_SoundScraper::cSystem_x5pG9Jby_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_Ez1EUvQy_sendMessage);
}

void Heavy_SoundScraper::cVar_mlMz6f9p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_MLwC9FIR_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_8oqwsESb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_8oqwsESb, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_oDEWjQ3T, 0, m, &cDelay_oDEWjQ3T_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_EPo9lqrA, 0, m, &sTabread_EPo9lqrA_sendMessage);
}

void Heavy_SoundScraper::cDelay_oDEWjQ3T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_oDEWjQ3T, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_EPo9lqrA, 0, m, &sTabread_EPo9lqrA_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_oDEWjQ3T, 0, m, &cDelay_oDEWjQ3T_sendMessage);
}

void Heavy_SoundScraper::sTabread_EPo9lqrA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_E1QaerUg, HV_BINOP_SUBTRACT, 0, m, &cBinop_E1QaerUg_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_2t9qZSK8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_IVq712Zu, HV_BINOP_MAX, 0, m, &cBinop_IVq712Zu_sendMessage);
}

void Heavy_SoundScraper::cBinop_Ez1EUvQy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_2t9qZSK8, HV_BINOP_MULTIPLY, 0, m, &cBinop_2t9qZSK8_sendMessage);
}

void Heavy_SoundScraper::cBinop_wq6KmTcC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_NgJwbbh0_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_EPo9lqrA, 0, m, &sTabread_EPo9lqrA_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Urugi0vT_sendMessage);
}

void Heavy_SoundScraper::cSystem_vcfhdEMC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_E1QaerUg, HV_BINOP_SUBTRACT, 1, m, &cBinop_E1QaerUg_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_oDEWjQ3T, 2, m, &cDelay_oDEWjQ3T_sendMessage);
}

void Heavy_SoundScraper::cMsg_MLwC9FIR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_vcfhdEMC_sendMessage);
}

void Heavy_SoundScraper::cMsg_NgJwbbh0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_8oqwsESb, 0, m, &cDelay_8oqwsESb_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_oDEWjQ3T, 0, m, &cDelay_oDEWjQ3T_sendMessage);
}

void Heavy_SoundScraper::cMsg_RE2CU8P3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_IVq712Zu, HV_BINOP_MAX, 1, m, &cBinop_IVq712Zu_sendMessage);
}

void Heavy_SoundScraper::cBinop_IVq712Zu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_wq6KmTcC, HV_BINOP_SUBTRACT, 1, m, &cBinop_wq6KmTcC_sendMessage);
}

void Heavy_SoundScraper::cCast_Urugi0vT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_8oqwsESb, 0, m, &cDelay_8oqwsESb_sendMessage);
}

void Heavy_SoundScraper::cBinop_HIIHH7dN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_8oqwsESb, 2, m, &cDelay_8oqwsESb_sendMessage);
}

void Heavy_SoundScraper::cBinop_E1QaerUg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_HIIHH7dN_sendMessage);
}

void Heavy_SoundScraper::cCast_jMeyyFRl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_mlMz6f9p, 0, m, &cVar_mlMz6f9p_sendMessage);
  cMsg_KOwESreD_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_nmlLjw0L, 0, m, &cTabhead_nmlLjw0L_sendMessage);
}

void Heavy_SoundScraper::cMsg_jUoVoCca_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_C9RFmryU_sendMessage);
}

void Heavy_SoundScraper::cSystem_C9RFmryU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_dUncUnOi_sendMessage);
}

void Heavy_SoundScraper::cDelay_jwqyWtId_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_jwqyWtId, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_vWDNwy1w, 0, m, &cDelay_vWDNwy1w_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_jwqyWtId, 0, m, &cDelay_jwqyWtId_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_eLj86jli, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_vWDNwy1w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_vWDNwy1w, m);
  cMsg_yr5MtC4y_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_UeUZD85s_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_cCkOyFeF_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_eEI1QXLj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ehJRSUTu_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_BDlw4p4k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_yNir7RNg_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_jwqyWtId, 2, m, &cDelay_jwqyWtId_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_VjPr0T8N_sendMessage);
}

void Heavy_SoundScraper::cMsg_ehJRSUTu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_BDlw4p4k, 0, m, &hTable_BDlw4p4k_sendMessage);
}

void Heavy_SoundScraper::cBinop_dUncUnOi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 58.6435f, 0, m, &cBinop_eEI1QXLj_sendMessage);
}

void Heavy_SoundScraper::cMsg_yr5MtC4y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_BDlw4p4k, 0, m, &hTable_BDlw4p4k_sendMessage);
}

void Heavy_SoundScraper::cCast_VjPr0T8N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_jwqyWtId, 0, m, &cDelay_jwqyWtId_sendMessage);
}

void Heavy_SoundScraper::cMsg_yNir7RNg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_vWDNwy1w, 2, m, &cDelay_vWDNwy1w_sendMessage);
}

void Heavy_SoundScraper::cMsg_cCkOyFeF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_eLj86jli, 1, m, NULL);
}

void Heavy_SoundScraper::cMsg_nX3FOewU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_qLqUrbMw_sendMessage);
}

void Heavy_SoundScraper::cSystem_qLqUrbMw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_XBg8OQnE_sendMessage);
}

void Heavy_SoundScraper::cDelay_9R8hII4k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_9R8hII4k, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_EZcoAr7y, 0, m, &cDelay_EZcoAr7y_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_9R8hII4k, 0, m, &cDelay_9R8hII4k_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_Ulp4BOlH, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_EZcoAr7y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_EZcoAr7y, m);
  cMsg_WvQC2NDA_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_KjFuCXN0_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_rJIl1Uav_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_uyROMmWC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ZbSlFYRE_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_aZEd6ida_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Fd5Fi3r9_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_9R8hII4k, 2, m, &cDelay_9R8hII4k_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_hCm2165H_sendMessage);
}

void Heavy_SoundScraper::cMsg_ZbSlFYRE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_aZEd6ida, 0, m, &hTable_aZEd6ida_sendMessage);
}

void Heavy_SoundScraper::cBinop_XBg8OQnE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 69.4325f, 0, m, &cBinop_uyROMmWC_sendMessage);
}

void Heavy_SoundScraper::cMsg_WvQC2NDA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_aZEd6ida, 0, m, &hTable_aZEd6ida_sendMessage);
}

void Heavy_SoundScraper::cCast_hCm2165H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_9R8hII4k, 0, m, &cDelay_9R8hII4k_sendMessage);
}

void Heavy_SoundScraper::cMsg_Fd5Fi3r9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_EZcoAr7y, 2, m, &cDelay_EZcoAr7y_sendMessage);
}

void Heavy_SoundScraper::cMsg_rJIl1Uav_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_Ulp4BOlH, 1, m, NULL);
}

void Heavy_SoundScraper::cMsg_Dxwepj2x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_WewYbzlq_sendMessage);
}

void Heavy_SoundScraper::cSystem_WewYbzlq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_No0y4vWB_sendMessage);
}

void Heavy_SoundScraper::cDelay_xjA8dIDl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_xjA8dIDl, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_OSgYrk2I, 0, m, &cDelay_OSgYrk2I_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_xjA8dIDl, 0, m, &cDelay_xjA8dIDl_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_X8BJe9P9, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_OSgYrk2I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_OSgYrk2I, m);
  cMsg_wsmpQ7bm_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_Kor6t9M8_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_Pn3yEN1H_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_Scj80tJr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_LRST6w69_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_Ua2nJmIp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_s6a7urb5_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_xjA8dIDl, 2, m, &cDelay_xjA8dIDl_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ba5joC6Y_sendMessage);
}

void Heavy_SoundScraper::cMsg_LRST6w69_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_Ua2nJmIp, 0, m, &hTable_Ua2nJmIp_sendMessage);
}

void Heavy_SoundScraper::cBinop_No0y4vWB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 74.5234f, 0, m, &cBinop_Scj80tJr_sendMessage);
}

void Heavy_SoundScraper::cMsg_wsmpQ7bm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_Ua2nJmIp, 0, m, &hTable_Ua2nJmIp_sendMessage);
}

void Heavy_SoundScraper::cCast_ba5joC6Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_xjA8dIDl, 0, m, &cDelay_xjA8dIDl_sendMessage);
}

void Heavy_SoundScraper::cMsg_s6a7urb5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_OSgYrk2I, 2, m, &cDelay_OSgYrk2I_sendMessage);
}

void Heavy_SoundScraper::cMsg_Pn3yEN1H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_X8BJe9P9, 1, m, NULL);
}

void Heavy_SoundScraper::cMsg_vuOR1nI9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_4J2IwCLN_sendMessage);
}

void Heavy_SoundScraper::cSystem_4J2IwCLN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_NfTVEnUj_sendMessage);
}

void Heavy_SoundScraper::cDelay_wCoY3zJq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_wCoY3zJq, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_9YTjERv9, 0, m, &cDelay_9YTjERv9_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_wCoY3zJq, 0, m, &cDelay_wCoY3zJq_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_Vjo3KuJ9, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_9YTjERv9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_9YTjERv9, m);
  cMsg_0efVDhPH_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_nbEWG5MH_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_dY7yO79k_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_swCdEOx1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_is5tUfA7_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_zGd0W84V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_6fdiQPxx_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_wCoY3zJq, 2, m, &cDelay_wCoY3zJq_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_D4M8vB7c_sendMessage);
}

void Heavy_SoundScraper::cMsg_is5tUfA7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_zGd0W84V, 0, m, &hTable_zGd0W84V_sendMessage);
}

void Heavy_SoundScraper::cBinop_NfTVEnUj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 86.1244f, 0, m, &cBinop_swCdEOx1_sendMessage);
}

void Heavy_SoundScraper::cMsg_0efVDhPH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_zGd0W84V, 0, m, &hTable_zGd0W84V_sendMessage);
}

void Heavy_SoundScraper::cCast_D4M8vB7c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_wCoY3zJq, 0, m, &cDelay_wCoY3zJq_sendMessage);
}

void Heavy_SoundScraper::cMsg_6fdiQPxx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_9YTjERv9, 2, m, &cDelay_9YTjERv9_sendMessage);
}

void Heavy_SoundScraper::cMsg_dY7yO79k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_Vjo3KuJ9, 1, m, NULL);
}

void Heavy_SoundScraper::cIf_aQvTScCH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_XS6Eg6Z6_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_cZLr3Ee7_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cMsg_7bkObDxL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_zBNhWJN1, HV_BINOP_POW, 0, m, &cBinop_zBNhWJN1_sendMessage);
}

void Heavy_SoundScraper::cBinop_zBNhWJN1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.125f, 0, m, &cBinop_NSMkeBXe_sendMessage);
}

void Heavy_SoundScraper::cBinop_kcqWzWUu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_ewCPpE5L_sendMessage);
}

void Heavy_SoundScraper::cCast_c5HStUMb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_QLbka2ZD_sendMessage);
}

void Heavy_SoundScraper::cCast_i4C14606_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_aQvTScCH, 0, m, &cIf_aQvTScCH_sendMessage);
}

void Heavy_SoundScraper::cBinop_QLbka2ZD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_aQvTScCH, 1, m, &cIf_aQvTScCH_sendMessage);
}

void Heavy_SoundScraper::cBinop_cZLr3Ee7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_kcqWzWUu_sendMessage);
}

void Heavy_SoundScraper::cMsg_XS6Eg6Z6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.125f, 0, m, &cBinop_NSMkeBXe_sendMessage);
}

void Heavy_SoundScraper::cBinop_ewCPpE5L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_zBNhWJN1, HV_BINOP_POW, 1, m, &cBinop_zBNhWJN1_sendMessage);
  cMsg_7bkObDxL_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_y9dIYkvo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_lmi7kD9G, 0, m, NULL);
}

void Heavy_SoundScraper::cPack_HDF4aKkM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_a84zihT1, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_dGqqs8tN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_yRgjm8su_sendMessage);
}

void Heavy_SoundScraper::cBinop_yRgjm8su_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 200.0f, 0, m, &cBinop_kGBnv0BU_sendMessage);
}

void Heavy_SoundScraper::cVar_5mTuFX24_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_P43d7ZAS, HV_BINOP_MULTIPLY, 0, m, &cBinop_P43d7ZAS_sendMessage);
}

void Heavy_SoundScraper::cMsg_Bk7KfjpK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_cGcPqwTW_sendMessage);
}

void Heavy_SoundScraper::cSystem_cGcPqwTW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_wyTy6ejW_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_P43d7ZAS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_a05O262C_sendMessage);
}

void Heavy_SoundScraper::cBinop_6pOWCMPv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_P43d7ZAS, HV_BINOP_MULTIPLY, 1, m, &cBinop_P43d7ZAS_sendMessage);
}

void Heavy_SoundScraper::cMsg_wyTy6ejW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_6pOWCMPv_sendMessage);
}

void Heavy_SoundScraper::cBinop_a05O262C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_VB7y3pTo_sendMessage);
}

void Heavy_SoundScraper::cBinop_VB7y3pTo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_WjgbaB6o_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_icJKbmbr, m);
}

void Heavy_SoundScraper::cBinop_WjgbaB6o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_Ok1oEGU1, m);
}

void Heavy_SoundScraper::cVar_uHprLQ22_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_c5HStUMb_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_i4C14606_sendMessage);
}

void Heavy_SoundScraper::cVar_NDxUjmjF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 100.0f, 0, m, &cBinop_dGqqs8tN_sendMessage);
}

void Heavy_SoundScraper::cVar_NEr1rfD8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_shWgVWRr_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_kmQGICQe, 0, m, &cIf_kmQGICQe_sendMessage);
}

void Heavy_SoundScraper::cVar_OJ2tXarU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 100.0f, 0, m, &cBinop_s12vqdX3_sendMessage);
}

void Heavy_SoundScraper::cIf_kmQGICQe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_RV7h76a9_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cVar_onMessage(_c, &Context(_c)->cVar_U3rlCBoG, 0, m, &cVar_U3rlCBoG_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_shWgVWRr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_kmQGICQe, 1, m, &cIf_kmQGICQe_sendMessage);
}

void Heavy_SoundScraper::cBinop_s12vqdX3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_CbwdRkkj_sendMessage);
}

void Heavy_SoundScraper::cBinop_CbwdRkkj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_KiZPD2c8, 0, m, &cVar_KiZPD2c8_sendMessage);
}

void Heavy_SoundScraper::cTabhead_yGPTgMHi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_cGhAIxcv, HV_BINOP_SUBTRACT, 0, m, &cBinop_cGhAIxcv_sendMessage);
}

void Heavy_SoundScraper::cMsg_OixAgxhf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_KGHCEvtn_sendMessage);
}

void Heavy_SoundScraper::cSystem_KGHCEvtn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_qULFk6aR_sendMessage);
}

void Heavy_SoundScraper::cVar_oo9Oo4OI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_7kc6S9Qk_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_xzfeE3J3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_xzfeE3J3, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_AmnrjBrE, 0, m, &cDelay_AmnrjBrE_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_3t5VJQw5, 0, m, &sTabread_3t5VJQw5_sendMessage);
}

void Heavy_SoundScraper::cDelay_AmnrjBrE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_AmnrjBrE, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_3t5VJQw5, 0, m, &sTabread_3t5VJQw5_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_AmnrjBrE, 0, m, &cDelay_AmnrjBrE_sendMessage);
}

void Heavy_SoundScraper::sTabread_3t5VJQw5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_P5FTVuwl, HV_BINOP_SUBTRACT, 0, m, &cBinop_P5FTVuwl_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_KxgtqBiR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6jn0ZkUH, HV_BINOP_MAX, 0, m, &cBinop_6jn0ZkUH_sendMessage);
}

void Heavy_SoundScraper::cBinop_qULFk6aR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_KxgtqBiR, HV_BINOP_MULTIPLY, 0, m, &cBinop_KxgtqBiR_sendMessage);
}

void Heavy_SoundScraper::cBinop_cGhAIxcv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_l8KojBru_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_3t5VJQw5, 0, m, &sTabread_3t5VJQw5_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_B3P3ca9Y_sendMessage);
}

void Heavy_SoundScraper::cSystem_B6uksbRK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_P5FTVuwl, HV_BINOP_SUBTRACT, 1, m, &cBinop_P5FTVuwl_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_AmnrjBrE, 2, m, &cDelay_AmnrjBrE_sendMessage);
}

void Heavy_SoundScraper::cMsg_7kc6S9Qk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_B6uksbRK_sendMessage);
}

void Heavy_SoundScraper::cMsg_l8KojBru_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_xzfeE3J3, 0, m, &cDelay_xzfeE3J3_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_AmnrjBrE, 0, m, &cDelay_AmnrjBrE_sendMessage);
}

void Heavy_SoundScraper::cMsg_nSFKb99m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_6jn0ZkUH, HV_BINOP_MAX, 1, m, &cBinop_6jn0ZkUH_sendMessage);
}

void Heavy_SoundScraper::cBinop_6jn0ZkUH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_cGhAIxcv, HV_BINOP_SUBTRACT, 1, m, &cBinop_cGhAIxcv_sendMessage);
}

void Heavy_SoundScraper::cCast_B3P3ca9Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_xzfeE3J3, 0, m, &cDelay_xzfeE3J3_sendMessage);
}

void Heavy_SoundScraper::cBinop_5KU3VDz6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_xzfeE3J3, 2, m, &cDelay_xzfeE3J3_sendMessage);
}

void Heavy_SoundScraper::cBinop_P5FTVuwl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_5KU3VDz6_sendMessage);
}

void Heavy_SoundScraper::cCast_zJAbhQ8C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_oo9Oo4OI, 0, m, &cVar_oo9Oo4OI_sendMessage);
  cMsg_OixAgxhf_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_yGPTgMHi, 0, m, &cTabhead_yGPTgMHi_sendMessage);
}

void Heavy_SoundScraper::cMsg_p0iVO1WG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_zwESq4PR_sendMessage);
}

void Heavy_SoundScraper::cSystem_zwESq4PR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_pMGDCz1P_sendMessage);
}

void Heavy_SoundScraper::cDelay_seFX0RIx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_seFX0RIx, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Gc9EsfL4, 0, m, &cDelay_Gc9EsfL4_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_seFX0RIx, 0, m, &cDelay_seFX0RIx_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_GVECn9lp, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_Gc9EsfL4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Gc9EsfL4, m);
  cMsg_h0rYcm4G_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_USZ4f21i_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_DJ7GL3OY_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_nOgtmBUZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_pCtStX7K_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_DvofHMe4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_uAb68Eq4_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_seFX0RIx, 2, m, &cDelay_seFX0RIx_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_iWEUN8UQ_sendMessage);
}

void Heavy_SoundScraper::cMsg_pCtStX7K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_DvofHMe4, 0, m, &hTable_DvofHMe4_sendMessage);
}

void Heavy_SoundScraper::cBinop_pMGDCz1P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 13.645f, 0, m, &cBinop_nOgtmBUZ_sendMessage);
}

void Heavy_SoundScraper::cMsg_h0rYcm4G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_DvofHMe4, 0, m, &hTable_DvofHMe4_sendMessage);
}

void Heavy_SoundScraper::cCast_iWEUN8UQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_seFX0RIx, 0, m, &cDelay_seFX0RIx_sendMessage);
}

void Heavy_SoundScraper::cMsg_uAb68Eq4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_Gc9EsfL4, 2, m, &cDelay_Gc9EsfL4_sendMessage);
}

void Heavy_SoundScraper::cMsg_DJ7GL3OY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_GVECn9lp, 1, m, NULL);
}

void Heavy_SoundScraper::cTabhead_2ogH3jPz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_tnbqq1xO, HV_BINOP_SUBTRACT, 0, m, &cBinop_tnbqq1xO_sendMessage);
}

void Heavy_SoundScraper::cMsg_1ulv16wd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_GMQ3ijHq_sendMessage);
}

void Heavy_SoundScraper::cSystem_GMQ3ijHq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_4pE1f3Wr_sendMessage);
}

void Heavy_SoundScraper::cVar_go6JxS6N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_FxEqqO0a_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_dFBR9Idg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_dFBR9Idg, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_jIjXWFcG, 0, m, &cDelay_jIjXWFcG_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_PLCfNsd5, 0, m, &sTabread_PLCfNsd5_sendMessage);
}

void Heavy_SoundScraper::cDelay_jIjXWFcG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_jIjXWFcG, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_PLCfNsd5, 0, m, &sTabread_PLCfNsd5_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_jIjXWFcG, 0, m, &cDelay_jIjXWFcG_sendMessage);
}

void Heavy_SoundScraper::sTabread_PLCfNsd5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_zBxPBTss, HV_BINOP_SUBTRACT, 0, m, &cBinop_zBxPBTss_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_UJVhBtPH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_cOSmERe4, HV_BINOP_MAX, 0, m, &cBinop_cOSmERe4_sendMessage);
}

void Heavy_SoundScraper::cBinop_4pE1f3Wr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_UJVhBtPH, HV_BINOP_MULTIPLY, 0, m, &cBinop_UJVhBtPH_sendMessage);
}

void Heavy_SoundScraper::cBinop_tnbqq1xO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_pPmAu2kQ_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_PLCfNsd5, 0, m, &sTabread_PLCfNsd5_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_538JrPlH_sendMessage);
}

void Heavy_SoundScraper::cSystem_l7A6fLzl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_zBxPBTss, HV_BINOP_SUBTRACT, 1, m, &cBinop_zBxPBTss_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_jIjXWFcG, 2, m, &cDelay_jIjXWFcG_sendMessage);
}

void Heavy_SoundScraper::cMsg_FxEqqO0a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_l7A6fLzl_sendMessage);
}

void Heavy_SoundScraper::cMsg_pPmAu2kQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_dFBR9Idg, 0, m, &cDelay_dFBR9Idg_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_jIjXWFcG, 0, m, &cDelay_jIjXWFcG_sendMessage);
}

void Heavy_SoundScraper::cMsg_SFZqwoCm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_cOSmERe4, HV_BINOP_MAX, 1, m, &cBinop_cOSmERe4_sendMessage);
}

void Heavy_SoundScraper::cBinop_cOSmERe4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_tnbqq1xO, HV_BINOP_SUBTRACT, 1, m, &cBinop_tnbqq1xO_sendMessage);
}

void Heavy_SoundScraper::cCast_538JrPlH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_dFBR9Idg, 0, m, &cDelay_dFBR9Idg_sendMessage);
}

void Heavy_SoundScraper::cBinop_23iOxzNZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_dFBR9Idg, 2, m, &cDelay_dFBR9Idg_sendMessage);
}

void Heavy_SoundScraper::cBinop_zBxPBTss_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_23iOxzNZ_sendMessage);
}

void Heavy_SoundScraper::cCast_CZimpOj4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_go6JxS6N, 0, m, &cVar_go6JxS6N_sendMessage);
  cMsg_1ulv16wd_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_2ogH3jPz, 0, m, &cTabhead_2ogH3jPz_sendMessage);
}

void Heavy_SoundScraper::cMsg_MMyqEwPY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_x8h4QJ70_sendMessage);
}

void Heavy_SoundScraper::cSystem_x8h4QJ70_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_95d7hBhX_sendMessage);
}

void Heavy_SoundScraper::cDelay_M67esJ8Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_M67esJ8Q, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_4VhLuzkl, 0, m, &cDelay_4VhLuzkl_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_M67esJ8Q, 0, m, &cDelay_M67esJ8Q_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_YkTV5vwK, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_4VhLuzkl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_4VhLuzkl, m);
  cMsg_PL7t9iyG_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_vwqQJEMx_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_qafC56vF_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_btYCaLC2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_nXlbsvj6_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_TugJfLtQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_IbtZ3XtF_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_M67esJ8Q, 2, m, &cDelay_M67esJ8Q_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_pGswZQge_sendMessage);
}

void Heavy_SoundScraper::cMsg_nXlbsvj6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_TugJfLtQ, 0, m, &hTable_TugJfLtQ_sendMessage);
}

void Heavy_SoundScraper::cBinop_95d7hBhX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 16.364f, 0, m, &cBinop_btYCaLC2_sendMessage);
}

void Heavy_SoundScraper::cMsg_PL7t9iyG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_TugJfLtQ, 0, m, &hTable_TugJfLtQ_sendMessage);
}

void Heavy_SoundScraper::cCast_pGswZQge_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_M67esJ8Q, 0, m, &cDelay_M67esJ8Q_sendMessage);
}

void Heavy_SoundScraper::cMsg_IbtZ3XtF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_4VhLuzkl, 2, m, &cDelay_4VhLuzkl_sendMessage);
}

void Heavy_SoundScraper::cMsg_qafC56vF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_YkTV5vwK, 1, m, NULL);
}

void Heavy_SoundScraper::cTabhead_8TqEvFo9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_iDQujRWJ, HV_BINOP_SUBTRACT, 0, m, &cBinop_iDQujRWJ_sendMessage);
}

void Heavy_SoundScraper::cMsg_gvw7QSx4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_QutnhqW6_sendMessage);
}

void Heavy_SoundScraper::cSystem_QutnhqW6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_VRe8Guws_sendMessage);
}

void Heavy_SoundScraper::cVar_MCV48FmN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_611ogfZe_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_sDcUFbVJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_sDcUFbVJ, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_dnwD2Vnw, 0, m, &cDelay_dnwD2Vnw_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_BxCiE5Lx, 0, m, &sTabread_BxCiE5Lx_sendMessage);
}

void Heavy_SoundScraper::cDelay_dnwD2Vnw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_dnwD2Vnw, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_BxCiE5Lx, 0, m, &sTabread_BxCiE5Lx_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_dnwD2Vnw, 0, m, &cDelay_dnwD2Vnw_sendMessage);
}

void Heavy_SoundScraper::sTabread_BxCiE5Lx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_GF3qRII8, HV_BINOP_SUBTRACT, 0, m, &cBinop_GF3qRII8_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_zo7g1Rx2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_mbsmuDUT, HV_BINOP_MAX, 0, m, &cBinop_mbsmuDUT_sendMessage);
}

void Heavy_SoundScraper::cBinop_VRe8Guws_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_zo7g1Rx2, HV_BINOP_MULTIPLY, 0, m, &cBinop_zo7g1Rx2_sendMessage);
}

void Heavy_SoundScraper::cBinop_iDQujRWJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_7q9o9xhn_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_BxCiE5Lx, 0, m, &sTabread_BxCiE5Lx_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_XTvQ2qBj_sendMessage);
}

void Heavy_SoundScraper::cSystem_o1Zl5x4F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_GF3qRII8, HV_BINOP_SUBTRACT, 1, m, &cBinop_GF3qRII8_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_dnwD2Vnw, 2, m, &cDelay_dnwD2Vnw_sendMessage);
}

void Heavy_SoundScraper::cMsg_611ogfZe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_o1Zl5x4F_sendMessage);
}

void Heavy_SoundScraper::cMsg_7q9o9xhn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_sDcUFbVJ, 0, m, &cDelay_sDcUFbVJ_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_dnwD2Vnw, 0, m, &cDelay_dnwD2Vnw_sendMessage);
}

void Heavy_SoundScraper::cMsg_1vapgiEr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_mbsmuDUT, HV_BINOP_MAX, 1, m, &cBinop_mbsmuDUT_sendMessage);
}

void Heavy_SoundScraper::cBinop_mbsmuDUT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_iDQujRWJ, HV_BINOP_SUBTRACT, 1, m, &cBinop_iDQujRWJ_sendMessage);
}

void Heavy_SoundScraper::cCast_XTvQ2qBj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_sDcUFbVJ, 0, m, &cDelay_sDcUFbVJ_sendMessage);
}

void Heavy_SoundScraper::cBinop_1CSYwGpa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_sDcUFbVJ, 2, m, &cDelay_sDcUFbVJ_sendMessage);
}

void Heavy_SoundScraper::cBinop_GF3qRII8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_1CSYwGpa_sendMessage);
}

void Heavy_SoundScraper::cCast_dQ6tYQfc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_MCV48FmN, 0, m, &cVar_MCV48FmN_sendMessage);
  cMsg_gvw7QSx4_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_8TqEvFo9, 0, m, &cTabhead_8TqEvFo9_sendMessage);
}

void Heavy_SoundScraper::cMsg_q1CxEIxM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_8atYtr2G_sendMessage);
}

void Heavy_SoundScraper::cSystem_8atYtr2G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_Nzbyh2Un_sendMessage);
}

void Heavy_SoundScraper::cDelay_uq5JNuH7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_uq5JNuH7, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_3FZSj1l7, 0, m, &cDelay_3FZSj1l7_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_uq5JNuH7, 0, m, &cDelay_uq5JNuH7_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_S6pGnhqD, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_3FZSj1l7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_3FZSj1l7, m);
  cMsg_keoFTBoN_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_IISQrnnv_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_TZz48bEF_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_Sf58bFQO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_c3CvKrOv_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_7NVE3FN1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_4HvoWfLJ_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_uq5JNuH7, 2, m, &cDelay_uq5JNuH7_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_qNVk3myE_sendMessage);
}

void Heavy_SoundScraper::cMsg_c3CvKrOv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_7NVE3FN1, 0, m, &hTable_7NVE3FN1_sendMessage);
}

void Heavy_SoundScraper::cBinop_Nzbyh2Un_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 19.392f, 0, m, &cBinop_Sf58bFQO_sendMessage);
}

void Heavy_SoundScraper::cMsg_keoFTBoN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_7NVE3FN1, 0, m, &hTable_7NVE3FN1_sendMessage);
}

void Heavy_SoundScraper::cCast_qNVk3myE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_uq5JNuH7, 0, m, &cDelay_uq5JNuH7_sendMessage);
}

void Heavy_SoundScraper::cMsg_4HvoWfLJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_3FZSj1l7, 2, m, &cDelay_3FZSj1l7_sendMessage);
}

void Heavy_SoundScraper::cMsg_TZz48bEF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_S6pGnhqD, 1, m, NULL);
}

void Heavy_SoundScraper::cTabhead_ybSPns1X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Fb7Q7h33, HV_BINOP_SUBTRACT, 0, m, &cBinop_Fb7Q7h33_sendMessage);
}

void Heavy_SoundScraper::cMsg_Xi2p4KyA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_u0MCtwkS_sendMessage);
}

void Heavy_SoundScraper::cSystem_u0MCtwkS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_HkkkyY6o_sendMessage);
}

void Heavy_SoundScraper::cVar_JoJFwX7x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ErtYmPTM_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_yI6SF9oL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_yI6SF9oL, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Q7wEBTu9, 0, m, &cDelay_Q7wEBTu9_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_bghJeFu0, 0, m, &sTabread_bghJeFu0_sendMessage);
}

void Heavy_SoundScraper::cDelay_Q7wEBTu9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Q7wEBTu9, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_bghJeFu0, 0, m, &sTabread_bghJeFu0_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Q7wEBTu9, 0, m, &cDelay_Q7wEBTu9_sendMessage);
}

void Heavy_SoundScraper::sTabread_bghJeFu0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_bwW3c2QK, HV_BINOP_SUBTRACT, 0, m, &cBinop_bwW3c2QK_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_m9sY4JEv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_amfBNKP2, HV_BINOP_MAX, 0, m, &cBinop_amfBNKP2_sendMessage);
}

void Heavy_SoundScraper::cBinop_HkkkyY6o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_m9sY4JEv, HV_BINOP_MULTIPLY, 0, m, &cBinop_m9sY4JEv_sendMessage);
}

void Heavy_SoundScraper::cBinop_Fb7Q7h33_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_OrKcK6mo_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_bghJeFu0, 0, m, &sTabread_bghJeFu0_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_qLIb6qAw_sendMessage);
}

void Heavy_SoundScraper::cSystem_MLCaflHO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_bwW3c2QK, HV_BINOP_SUBTRACT, 1, m, &cBinop_bwW3c2QK_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Q7wEBTu9, 2, m, &cDelay_Q7wEBTu9_sendMessage);
}

void Heavy_SoundScraper::cMsg_ErtYmPTM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_MLCaflHO_sendMessage);
}

void Heavy_SoundScraper::cMsg_OrKcK6mo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_yI6SF9oL, 0, m, &cDelay_yI6SF9oL_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Q7wEBTu9, 0, m, &cDelay_Q7wEBTu9_sendMessage);
}

void Heavy_SoundScraper::cMsg_xkbVPQEd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_amfBNKP2, HV_BINOP_MAX, 1, m, &cBinop_amfBNKP2_sendMessage);
}

void Heavy_SoundScraper::cBinop_amfBNKP2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Fb7Q7h33, HV_BINOP_SUBTRACT, 1, m, &cBinop_Fb7Q7h33_sendMessage);
}

void Heavy_SoundScraper::cCast_qLIb6qAw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_yI6SF9oL, 0, m, &cDelay_yI6SF9oL_sendMessage);
}

void Heavy_SoundScraper::cBinop_3FzedHwV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_yI6SF9oL, 2, m, &cDelay_yI6SF9oL_sendMessage);
}

void Heavy_SoundScraper::cBinop_bwW3c2QK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_3FzedHwV_sendMessage);
}

void Heavy_SoundScraper::cCast_Loml9ex5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_JoJFwX7x, 0, m, &cVar_JoJFwX7x_sendMessage);
  cMsg_Xi2p4KyA_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_ybSPns1X, 0, m, &cTabhead_ybSPns1X_sendMessage);
}

void Heavy_SoundScraper::cMsg_A0xPNonJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_rce075bC_sendMessage);
}

void Heavy_SoundScraper::cSystem_rce075bC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_UCbyc2Gk_sendMessage);
}

void Heavy_SoundScraper::cDelay_F8QQw9M7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_F8QQw9M7, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ukaXPaHY, 0, m, &cDelay_ukaXPaHY_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_F8QQw9M7, 0, m, &cDelay_F8QQw9M7_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_i2nr6az6, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_ukaXPaHY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_ukaXPaHY, m);
  cMsg_ctlfCSJb_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_MNLICmTY_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_eOv0bcny_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_F2HClN56_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_B8E1jtrv_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_VYf61oBw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_qbTYNfVm_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_F8QQw9M7, 2, m, &cDelay_F8QQw9M7_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_5BtWLH7h_sendMessage);
}

void Heavy_SoundScraper::cMsg_B8E1jtrv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_VYf61oBw, 0, m, &hTable_VYf61oBw_sendMessage);
}

void Heavy_SoundScraper::cBinop_UCbyc2Gk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 25.796f, 0, m, &cBinop_F2HClN56_sendMessage);
}

void Heavy_SoundScraper::cMsg_ctlfCSJb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_VYf61oBw, 0, m, &hTable_VYf61oBw_sendMessage);
}

void Heavy_SoundScraper::cCast_5BtWLH7h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_F8QQw9M7, 0, m, &cDelay_F8QQw9M7_sendMessage);
}

void Heavy_SoundScraper::cMsg_qbTYNfVm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_ukaXPaHY, 2, m, &cDelay_ukaXPaHY_sendMessage);
}

void Heavy_SoundScraper::cMsg_eOv0bcny_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_i2nr6az6, 1, m, NULL);
}

void Heavy_SoundScraper::cTabhead_7ssKdvOe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_tBmXxtqA, HV_BINOP_SUBTRACT, 0, m, &cBinop_tBmXxtqA_sendMessage);
}

void Heavy_SoundScraper::cMsg_8PKHbAmK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_SecEoh7e_sendMessage);
}

void Heavy_SoundScraper::cSystem_SecEoh7e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_oj4s8elF_sendMessage);
}

void Heavy_SoundScraper::cVar_ChpvNp45_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_h1aJi7hu_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_GR04MAXK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_GR04MAXK, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_FfAtGOcp, 0, m, &cDelay_FfAtGOcp_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_CMXK6XqO, 0, m, &sTabread_CMXK6XqO_sendMessage);
}

void Heavy_SoundScraper::cDelay_FfAtGOcp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_FfAtGOcp, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_CMXK6XqO, 0, m, &sTabread_CMXK6XqO_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_FfAtGOcp, 0, m, &cDelay_FfAtGOcp_sendMessage);
}

void Heavy_SoundScraper::sTabread_CMXK6XqO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_PqCyKZxA, HV_BINOP_SUBTRACT, 0, m, &cBinop_PqCyKZxA_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_GXRGtmcU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_XhBHv1EL, HV_BINOP_MAX, 0, m, &cBinop_XhBHv1EL_sendMessage);
}

void Heavy_SoundScraper::cBinop_oj4s8elF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_GXRGtmcU, HV_BINOP_MULTIPLY, 0, m, &cBinop_GXRGtmcU_sendMessage);
}

void Heavy_SoundScraper::cBinop_tBmXxtqA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_NeMudc7K_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_CMXK6XqO, 0, m, &sTabread_CMXK6XqO_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_u4e8g5AX_sendMessage);
}

void Heavy_SoundScraper::cSystem_5ILIlteI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_PqCyKZxA, HV_BINOP_SUBTRACT, 1, m, &cBinop_PqCyKZxA_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_FfAtGOcp, 2, m, &cDelay_FfAtGOcp_sendMessage);
}

void Heavy_SoundScraper::cMsg_h1aJi7hu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_5ILIlteI_sendMessage);
}

void Heavy_SoundScraper::cMsg_NeMudc7K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_GR04MAXK, 0, m, &cDelay_GR04MAXK_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_FfAtGOcp, 0, m, &cDelay_FfAtGOcp_sendMessage);
}

void Heavy_SoundScraper::cMsg_sRO0XvGq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_XhBHv1EL, HV_BINOP_MAX, 1, m, &cBinop_XhBHv1EL_sendMessage);
}

void Heavy_SoundScraper::cBinop_XhBHv1EL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_tBmXxtqA, HV_BINOP_SUBTRACT, 1, m, &cBinop_tBmXxtqA_sendMessage);
}

void Heavy_SoundScraper::cCast_u4e8g5AX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_GR04MAXK, 0, m, &cDelay_GR04MAXK_sendMessage);
}

void Heavy_SoundScraper::cBinop_kz6Hfw9H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_GR04MAXK, 2, m, &cDelay_GR04MAXK_sendMessage);
}

void Heavy_SoundScraper::cBinop_PqCyKZxA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_kz6Hfw9H_sendMessage);
}

void Heavy_SoundScraper::cCast_UAQyFue3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ChpvNp45, 0, m, &cVar_ChpvNp45_sendMessage);
  cMsg_8PKHbAmK_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_7ssKdvOe, 0, m, &cTabhead_7ssKdvOe_sendMessage);
}

void Heavy_SoundScraper::cMsg_pmKKuiG2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_FSaTCroT_sendMessage);
}

void Heavy_SoundScraper::cSystem_FSaTCroT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_5zZD9rZ4_sendMessage);
}

void Heavy_SoundScraper::cDelay_EGis0rvd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_EGis0rvd, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_eSjzhXsT, 0, m, &cDelay_eSjzhXsT_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_EGis0rvd, 0, m, &cDelay_EGis0rvd_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_xOecdRP1, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_eSjzhXsT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_eSjzhXsT, m);
  cMsg_I6jsXzWF_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_1iI32oxP_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_IrULokzx_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_Y9nURgVp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_VLTq6DDA_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_rsyMKuWL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_OGGNzqmL_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_EGis0rvd, 2, m, &cDelay_EGis0rvd_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_bFQRfrZA_sendMessage);
}

void Heavy_SoundScraper::cMsg_VLTq6DDA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_rsyMKuWL, 0, m, &hTable_rsyMKuWL_sendMessage);
}

void Heavy_SoundScraper::cBinop_5zZD9rZ4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 43.5337f, 0, m, &cBinop_Y9nURgVp_sendMessage);
}

void Heavy_SoundScraper::cMsg_I6jsXzWF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_rsyMKuWL, 0, m, &hTable_rsyMKuWL_sendMessage);
}

void Heavy_SoundScraper::cCast_bFQRfrZA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_EGis0rvd, 0, m, &cDelay_EGis0rvd_sendMessage);
}

void Heavy_SoundScraper::cMsg_OGGNzqmL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_eSjzhXsT, 2, m, &cDelay_eSjzhXsT_sendMessage);
}

void Heavy_SoundScraper::cMsg_IrULokzx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_xOecdRP1, 1, m, NULL);
}

void Heavy_SoundScraper::cTabhead_St48b3LR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_zfZNITkd, HV_BINOP_SUBTRACT, 0, m, &cBinop_zfZNITkd_sendMessage);
}

void Heavy_SoundScraper::cMsg_X5caIRDV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_PEEEs8Xj_sendMessage);
}

void Heavy_SoundScraper::cSystem_PEEEs8Xj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_UZtEzSrG_sendMessage);
}

void Heavy_SoundScraper::cVar_tC7ToJhX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_VNuFCk2a_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_OV5SFkRD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_OV5SFkRD, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_3YratDpi, 0, m, &cDelay_3YratDpi_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_b9g38sSt, 0, m, &sTabread_b9g38sSt_sendMessage);
}

void Heavy_SoundScraper::cDelay_3YratDpi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_3YratDpi, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_b9g38sSt, 0, m, &sTabread_b9g38sSt_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_3YratDpi, 0, m, &cDelay_3YratDpi_sendMessage);
}

void Heavy_SoundScraper::sTabread_b9g38sSt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_cERJj7MT, HV_BINOP_SUBTRACT, 0, m, &cBinop_cERJj7MT_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_RA2KAf5K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ehlwY1f1, HV_BINOP_MAX, 0, m, &cBinop_ehlwY1f1_sendMessage);
}

void Heavy_SoundScraper::cBinop_UZtEzSrG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_RA2KAf5K, HV_BINOP_MULTIPLY, 0, m, &cBinop_RA2KAf5K_sendMessage);
}

void Heavy_SoundScraper::cBinop_zfZNITkd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Zhkv0ion_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_b9g38sSt, 0, m, &sTabread_b9g38sSt_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ABhv6vai_sendMessage);
}

void Heavy_SoundScraper::cSystem_BWRxQXTS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_cERJj7MT, HV_BINOP_SUBTRACT, 1, m, &cBinop_cERJj7MT_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_3YratDpi, 2, m, &cDelay_3YratDpi_sendMessage);
}

void Heavy_SoundScraper::cMsg_VNuFCk2a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_BWRxQXTS_sendMessage);
}

void Heavy_SoundScraper::cMsg_Zhkv0ion_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_OV5SFkRD, 0, m, &cDelay_OV5SFkRD_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_3YratDpi, 0, m, &cDelay_3YratDpi_sendMessage);
}

void Heavy_SoundScraper::cMsg_1il5XksI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_ehlwY1f1, HV_BINOP_MAX, 1, m, &cBinop_ehlwY1f1_sendMessage);
}

void Heavy_SoundScraper::cBinop_ehlwY1f1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_zfZNITkd, HV_BINOP_SUBTRACT, 1, m, &cBinop_zfZNITkd_sendMessage);
}

void Heavy_SoundScraper::cCast_ABhv6vai_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_OV5SFkRD, 0, m, &cDelay_OV5SFkRD_sendMessage);
}

void Heavy_SoundScraper::cBinop_QWg57Xk2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_OV5SFkRD, 2, m, &cDelay_OV5SFkRD_sendMessage);
}

void Heavy_SoundScraper::cBinop_cERJj7MT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_QWg57Xk2_sendMessage);
}

void Heavy_SoundScraper::cCast_r466mbrh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_tC7ToJhX, 0, m, &cVar_tC7ToJhX_sendMessage);
  cMsg_X5caIRDV_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_St48b3LR, 0, m, &cTabhead_St48b3LR_sendMessage);
}

void Heavy_SoundScraper::cMsg_FF6JJ0Wk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_WUwxYw16_sendMessage);
}

void Heavy_SoundScraper::cSystem_WUwxYw16_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_pJyH183a_sendMessage);
}

void Heavy_SoundScraper::cDelay_szXkQCGD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_szXkQCGD, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_FInaOi4n, 0, m, &cDelay_FInaOi4n_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_szXkQCGD, 0, m, &cDelay_szXkQCGD_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_Xtx7SXZE, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_FInaOi4n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_FInaOi4n, m);
  cMsg_7vGWyFoO_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_TofbihzN_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_4Mj6sUn0_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_S34fbzxa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_31FLi57m_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_78RfxJhK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_7D4lchkR_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_szXkQCGD, 2, m, &cDelay_szXkQCGD_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_lFNUwhdb_sendMessage);
}

void Heavy_SoundScraper::cMsg_31FLi57m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_78RfxJhK, 0, m, &hTable_78RfxJhK_sendMessage);
}

void Heavy_SoundScraper::cBinop_pJyH183a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 75.2546f, 0, m, &cBinop_S34fbzxa_sendMessage);
}

void Heavy_SoundScraper::cMsg_7vGWyFoO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_78RfxJhK, 0, m, &hTable_78RfxJhK_sendMessage);
}

void Heavy_SoundScraper::cCast_lFNUwhdb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_szXkQCGD, 0, m, &cDelay_szXkQCGD_sendMessage);
}

void Heavy_SoundScraper::cMsg_7D4lchkR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_FInaOi4n, 2, m, &cDelay_FInaOi4n_sendMessage);
}

void Heavy_SoundScraper::cMsg_4Mj6sUn0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_Xtx7SXZE, 1, m, NULL);
}

void Heavy_SoundScraper::cVar_U3rlCBoG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_5mTuFX24, 0, m, &cVar_5mTuFX24_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_zjrIYr3p, 0, m, &cVar_zjrIYr3p_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_z6qTTlA4, 0, m, &cVar_z6qTTlA4_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_aUBUF7A9, 0, m, &cVar_aUBUF7A9_sendMessage);
}

void Heavy_SoundScraper::cVar_KiZPD2c8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.01f, 0, m, &cBinop_2BSLuzOb_sendMessage);
}

void Heavy_SoundScraper::cPack_2xZiRLAx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_yWjVeTiD, 0, m, NULL);
}

void Heavy_SoundScraper::cVar_zjrIYr3p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_mp25tMxX, HV_BINOP_MULTIPLY, 0, m, &cBinop_mp25tMxX_sendMessage);
}

void Heavy_SoundScraper::cMsg_OPXwkZrk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_yRyZq6iC_sendMessage);
}

void Heavy_SoundScraper::cSystem_yRyZq6iC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_4CuY3HWW_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_mp25tMxX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_amNDEiHh_sendMessage);
}

void Heavy_SoundScraper::cBinop_VKZJiIhp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_mp25tMxX, HV_BINOP_MULTIPLY, 1, m, &cBinop_mp25tMxX_sendMessage);
}

void Heavy_SoundScraper::cMsg_4CuY3HWW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_VKZJiIhp_sendMessage);
}

void Heavy_SoundScraper::cBinop_amNDEiHh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_4e3gzgIx_sendMessage);
}

void Heavy_SoundScraper::cBinop_4e3gzgIx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_3AEkE0Sy_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_hmGj91V8, m);
}

void Heavy_SoundScraper::cBinop_3AEkE0Sy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_6RiiC3ev, m);
}

void Heavy_SoundScraper::cVar_z6qTTlA4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_vCodnZcs, HV_BINOP_MULTIPLY, 0, m, &cBinop_vCodnZcs_sendMessage);
}

void Heavy_SoundScraper::cMsg_QD0FqzvJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_fPi83cTB_sendMessage);
}

void Heavy_SoundScraper::cSystem_fPi83cTB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_nV3JgUrQ_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_vCodnZcs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_fCR2QahL_sendMessage);
}

void Heavy_SoundScraper::cBinop_up9dy9BG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_vCodnZcs, HV_BINOP_MULTIPLY, 1, m, &cBinop_vCodnZcs_sendMessage);
}

void Heavy_SoundScraper::cMsg_nV3JgUrQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_up9dy9BG_sendMessage);
}

void Heavy_SoundScraper::cBinop_fCR2QahL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_NgWGhQ8g_sendMessage);
}

void Heavy_SoundScraper::cBinop_NgWGhQ8g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_3ODEwnnd_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_DfDnxfV8, m);
}

void Heavy_SoundScraper::cBinop_3ODEwnnd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_hcGctyo5, m);
}

void Heavy_SoundScraper::cVar_aUBUF7A9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_nwnO02oK, HV_BINOP_MULTIPLY, 0, m, &cBinop_nwnO02oK_sendMessage);
}

void Heavy_SoundScraper::cMsg_xso9kqO8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_UysZ7duJ_sendMessage);
}

void Heavy_SoundScraper::cSystem_UysZ7duJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_g9lWtPms_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_nwnO02oK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_QHrsoAxW_sendMessage);
}

void Heavy_SoundScraper::cBinop_ZguDba0Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_nwnO02oK, HV_BINOP_MULTIPLY, 1, m, &cBinop_nwnO02oK_sendMessage);
}

void Heavy_SoundScraper::cMsg_g9lWtPms_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_ZguDba0Q_sendMessage);
}

void Heavy_SoundScraper::cBinop_QHrsoAxW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_1tJMDU4h_sendMessage);
}

void Heavy_SoundScraper::cBinop_1tJMDU4h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_qBZ0ZdQb_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_nHDVwMMM, m);
}

void Heavy_SoundScraper::cBinop_qBZ0ZdQb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_0DQyJA3b, m);
}

void Heavy_SoundScraper::cBinop_kGBnv0BU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_HDF4aKkM, 0, m, &cPack_HDF4aKkM_sendMessage);
}

void Heavy_SoundScraper::cMsg_RV7h76a9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 3000.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_U3rlCBoG, 0, m, &cVar_U3rlCBoG_sendMessage);
}

void Heavy_SoundScraper::cBinop_2BSLuzOb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_2xZiRLAx, 0, m, &cPack_2xZiRLAx_sendMessage);
}

void Heavy_SoundScraper::cBinop_NSMkeBXe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_y9dIYkvo, 0, m, &cPack_y9dIYkvo_sendMessage);
}

void Heavy_SoundScraper::cVar_gCVVrHuG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_zEPU8Ik6_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_S5ZBzOlH_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_5kFKN3MW_sendMessage);
}

void Heavy_SoundScraper::cIf_IgQCLjWm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_5ziW4aHL_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_wYDdMQws_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cMsg_Ud1Pz0GB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_fGIu3Jbi, HV_BINOP_POW, 0, m, &cBinop_fGIu3Jbi_sendMessage);
}

void Heavy_SoundScraper::cBinop_fGIu3Jbi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_vnxY5A7U, 0, m, &cPack_vnxY5A7U_sendMessage);
}

void Heavy_SoundScraper::cBinop_HS8SBdcF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_weuhMbRF_sendMessage);
}

void Heavy_SoundScraper::cCast_S5ZBzOlH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_9Ld4tayY_sendMessage);
}

void Heavy_SoundScraper::cCast_5kFKN3MW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_IgQCLjWm, 0, m, &cIf_IgQCLjWm_sendMessage);
}

void Heavy_SoundScraper::cBinop_9Ld4tayY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_IgQCLjWm, 1, m, &cIf_IgQCLjWm_sendMessage);
}

void Heavy_SoundScraper::cBinop_wYDdMQws_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_HS8SBdcF_sendMessage);
}

void Heavy_SoundScraper::cMsg_5ziW4aHL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_vnxY5A7U, 0, m, &cPack_vnxY5A7U_sendMessage);
}

void Heavy_SoundScraper::cBinop_weuhMbRF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_fGIu3Jbi, HV_BINOP_POW, 1, m, &cBinop_fGIu3Jbi_sendMessage);
  cMsg_Ud1Pz0GB_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_vnxY5A7U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_G4tPG2mq, 0, m, NULL);
}

void Heavy_SoundScraper::cVar_44UXrCfW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_x1hXRGu3_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_zEPU8Ik6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSend_bNECEep0_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_bNECEep0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_E26AmS55_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_x1hXRGu3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_SPwDNL2J_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cIf_2SolLrJK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_O5j2biHu_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_LOG10, m, &cUnop_zhxz80qd_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cUnop_zhxz80qd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_r5Is7UU0_sendMessage);
}

void Heavy_SoundScraper::cCast_JR8cxChW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_soCjVCoE_sendMessage);
}

void Heavy_SoundScraper::cCast_WH2QjEzT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_2SolLrJK, 0, m, &cIf_2SolLrJK_sendMessage);
}

void Heavy_SoundScraper::cMsg_O5j2biHu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_uHprLQ22, 0, m, &cVar_uHprLQ22_sendMessage);
}

void Heavy_SoundScraper::cBinop_r5Is7UU0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 100.0f, 0, m, &cBinop_0sRt7Csm_sendMessage);
}

void Heavy_SoundScraper::cBinop_0sRt7Csm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_HTLuPcc5_sendMessage);
}

void Heavy_SoundScraper::cBinop_HTLuPcc5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_uHprLQ22, 0, m, &cVar_uHprLQ22_sendMessage);
}

void Heavy_SoundScraper::cBinop_soCjVCoE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_2SolLrJK, 1, m, &cIf_2SolLrJK_sendMessage);
}

void Heavy_SoundScraper::cBinop_FhyY5Pw4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_JR8cxChW_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_WH2QjEzT_sendMessage);
}

void Heavy_SoundScraper::cBinop_FdkNYIHd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_FhyY5Pw4_sendMessage);
}

void Heavy_SoundScraper::cIf_JJVJQUMJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_fraA4iPy_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_LOG10, m, &cUnop_clG5cnpT_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cUnop_clG5cnpT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_G1kF1Wdx_sendMessage);
}

void Heavy_SoundScraper::cCast_SoONVjQ7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_JJVJQUMJ, 0, m, &cIf_JJVJQUMJ_sendMessage);
}

void Heavy_SoundScraper::cCast_iZrGRZWa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_T0uLNKNr_sendMessage);
}

void Heavy_SoundScraper::cMsg_fraA4iPy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cMsg_zEPU8Ik6_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_S5ZBzOlH_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_5kFKN3MW_sendMessage);
}

void Heavy_SoundScraper::cBinop_G1kF1Wdx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 100.0f, 0, m, &cBinop_oo0oi6SH_sendMessage);
}

void Heavy_SoundScraper::cBinop_oo0oi6SH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_OoAS789E_sendMessage);
}

void Heavy_SoundScraper::cBinop_OoAS789E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_zEPU8Ik6_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_S5ZBzOlH_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_5kFKN3MW_sendMessage);
}

void Heavy_SoundScraper::cBinop_T0uLNKNr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_JJVJQUMJ, 1, m, &cIf_JJVJQUMJ_sendMessage);
}

void Heavy_SoundScraper::cBinop_hnHSzzHw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_iZrGRZWa_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_SoONVjQ7_sendMessage);
}

void Heavy_SoundScraper::cBinop_sI7jsqQP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_hnHSzzHw_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_OJbJtB0B_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_SstpVHkg_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_SstpVHkg_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_7xLaZa2E, 1, m, &cDelay_7xLaZa2E_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_2TK3uO8n_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cDelay_7xLaZa2E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_7xLaZa2E, m);
  cMsg_Z1AxSLqo_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_SstpVHkg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_7xLaZa2E, 0, m, &cDelay_7xLaZa2E_sendMessage);
}

void Heavy_SoundScraper::cCast_2TK3uO8n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_7xLaZa2E, 0, m, &cDelay_7xLaZa2E_sendMessage);
}

void Heavy_SoundScraper::cVar_hsrIJ4yr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_29XfAuyN, 0, m, &cPack_29XfAuyN_sendMessage);
}

void Heavy_SoundScraper::cVar_RJybhnyg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.05776f, 0, m, &cBinop_eUB4SQ38_sendMessage);
}

void Heavy_SoundScraper::cVar_cx6enyvp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_bGSuX7oC_sendMessage);
}

void Heavy_SoundScraper::cPack_n8nrn1uo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_YkiltBOq, 0, m, NULL);
}

void Heavy_SoundScraper::cUnop_rE30z1IQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_1NVJ4Mfy_sendMessage);
}

void Heavy_SoundScraper::cBinop_bhG18gNq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_EXP, m, &cUnop_rE30z1IQ_sendMessage);
}

void Heavy_SoundScraper::cPack_C5APbCi5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_jVKbQJy3, 0, m, NULL);
}

void Heavy_SoundScraper::cVar_XHoXWdfg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.5f, 0, m, &cBinop_MkHJqixR_sendMessage);
}

void Heavy_SoundScraper::cMsg_usvefzxV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_aSpcA3pj_sendMessage);
}

void Heavy_SoundScraper::cSystem_aSpcA3pj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_UAnovAkP_sendMessage);
}

void Heavy_SoundScraper::cDelay_KwPNmtEW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_KwPNmtEW, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_09egtzdi, 0, m, &cDelay_09egtzdi_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_KwPNmtEW, 0, m, &cDelay_KwPNmtEW_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_PebHL3hD, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_09egtzdi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_09egtzdi, m);
  cMsg_cAWgp1zP_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_WhGrWYS5_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_T2izIf1b_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_fFbfWQhl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_YKtg0e6B_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_GndqmX2H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_kP0rdbSb_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_KwPNmtEW, 2, m, &cDelay_KwPNmtEW_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_oAVlkyZr_sendMessage);
}

void Heavy_SoundScraper::cMsg_YKtg0e6B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_GndqmX2H, 0, m, &hTable_GndqmX2H_sendMessage);
}

void Heavy_SoundScraper::cBinop_UAnovAkP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 5000.0f, 0, m, &cBinop_fFbfWQhl_sendMessage);
}

void Heavy_SoundScraper::cMsg_cAWgp1zP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_GndqmX2H, 0, m, &hTable_GndqmX2H_sendMessage);
}

void Heavy_SoundScraper::cCast_oAVlkyZr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_KwPNmtEW, 0, m, &cDelay_KwPNmtEW_sendMessage);
}

void Heavy_SoundScraper::cMsg_kP0rdbSb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_09egtzdi, 2, m, &cDelay_09egtzdi_sendMessage);
}

void Heavy_SoundScraper::cMsg_T2izIf1b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_PebHL3hD, 1, m, NULL);
}

void Heavy_SoundScraper::cMsg_hKLseir2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_4SmPRn40_sendMessage);
}

void Heavy_SoundScraper::cSystem_4SmPRn40_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_g6ionZGW_sendMessage);
}

void Heavy_SoundScraper::cVar_dTAAFNnq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_P6JVau2q_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSystem_JRPpYM9N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_q2m401uk_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_nQ4E3bwN, m);
}

void Heavy_SoundScraper::cBinop_g6ionZGW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_kbdZGu1G, m);
}

void Heavy_SoundScraper::cMsg_P6JVau2q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_JRPpYM9N_sendMessage);
}

void Heavy_SoundScraper::cBinop_q2m401uk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_aMLcAFzq, m);
}

void Heavy_SoundScraper::cMsg_2nE9OEwE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_44tfzEEw_sendMessage);
}

void Heavy_SoundScraper::cSystem_44tfzEEw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_ydqzZ2iE_sendMessage);
}

void Heavy_SoundScraper::cVar_VyRXTWaQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Qb6XL134_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSystem_e0dT9kHL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_hDv4iEsF_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_pdQ3Ejpp, m);
}

void Heavy_SoundScraper::cBinop_ydqzZ2iE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_U7vX9PQx, m);
}

void Heavy_SoundScraper::cMsg_Qb6XL134_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_e0dT9kHL_sendMessage);
}

void Heavy_SoundScraper::cBinop_hDv4iEsF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_masf72jC, m);
}

void Heavy_SoundScraper::cBinop_fKeTgMRY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_2QIuLOvo_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_28qqN8L1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_HYvtlFJz_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_dRB0x4Qw_sendMessage);
}

void Heavy_SoundScraper::cCast_HYvtlFJz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_fKeTgMRY, HV_BINOP_DIVIDE, 1, m, &cBinop_fKeTgMRY_sendMessage);
}

void Heavy_SoundScraper::cCast_dRB0x4Qw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_fKeTgMRY, HV_BINOP_DIVIDE, 0, m, &cBinop_fKeTgMRY_sendMessage);
}

void Heavy_SoundScraper::cBinop_1NVJ4Mfy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_k9wPRR8f_sendMessage);
}

void Heavy_SoundScraper::cBinop_eUB4SQ38_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 87.3365f, 0, m, &cBinop_bhG18gNq_sendMessage);
}

void Heavy_SoundScraper::cBinop_k9wPRR8f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_fKeTgMRY, HV_BINOP_DIVIDE, 0, m, &cBinop_fKeTgMRY_sendMessage);
}

void Heavy_SoundScraper::cBinop_MkHJqixR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_C5APbCi5, 0, m, &cPack_C5APbCi5_sendMessage);
}

void Heavy_SoundScraper::cBinop_bGSuX7oC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.001f, 0, m, &cBinop_28qqN8L1_sendMessage);
  cPack_onMessage(_c, &Context(_c)->cPack_n8nrn1uo, 0, m, &cPack_n8nrn1uo_sendMessage);
}

void Heavy_SoundScraper::cMsg_ecmgwB4s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 100.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_cx6enyvp, 0, m, &cVar_cx6enyvp_sendMessage);
}

void Heavy_SoundScraper::cMsg_PXzTfySZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.5f);
  cVar_onMessage(_c, &Context(_c)->cVar_XHoXWdfg, 0, m, &cVar_XHoXWdfg_sendMessage);
}

void Heavy_SoundScraper::cMsg_2QIuLOvo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 30.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_87ldDbSW, 0, m, NULL);
}

void Heavy_SoundScraper::cVar_wuOfDgb2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_rqEp3zek, HV_BINOP_MULTIPLY, 0, m, &cBinop_rqEp3zek_sendMessage);
}

void Heavy_SoundScraper::cMsg_QbpKhrss_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_aQlbI7RT_sendMessage);
}

void Heavy_SoundScraper::cSystem_aQlbI7RT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_xsHE7NQP_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_rqEp3zek_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_6fRAjtCH_sendMessage);
}

void Heavy_SoundScraper::cBinop_qUB3okiz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_rqEp3zek, HV_BINOP_MULTIPLY, 1, m, &cBinop_rqEp3zek_sendMessage);
}

void Heavy_SoundScraper::cMsg_xsHE7NQP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_qUB3okiz_sendMessage);
}

void Heavy_SoundScraper::cBinop_6fRAjtCH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_3NIbqBer_sendMessage);
}

void Heavy_SoundScraper::cBinop_3NIbqBer_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_2IBljoZl_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_qXx3NkpA, m);
}

void Heavy_SoundScraper::cBinop_2IBljoZl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_4eYiY0Fp, m);
}

void Heavy_SoundScraper::cVar_ODgcRrf1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_aV2hkLar, HV_BINOP_MULTIPLY, 0, m, &cBinop_aV2hkLar_sendMessage);
}

void Heavy_SoundScraper::cMsg_WK9gnN8v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_S5g4Bz1K_sendMessage);
}

void Heavy_SoundScraper::cSystem_S5g4Bz1K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_AljwjFkR_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_aV2hkLar_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_ZnVQJg8W_sendMessage);
}

void Heavy_SoundScraper::cBinop_aWzbrU0S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_aV2hkLar, HV_BINOP_MULTIPLY, 1, m, &cBinop_aV2hkLar_sendMessage);
}

void Heavy_SoundScraper::cMsg_AljwjFkR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_aWzbrU0S_sendMessage);
}

void Heavy_SoundScraper::cBinop_ZnVQJg8W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_OsfngqE1_sendMessage);
}

void Heavy_SoundScraper::cBinop_OsfngqE1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_9VTgXIHn_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_4Aq5SqLC, m);
}

void Heavy_SoundScraper::cBinop_9VTgXIHn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_pm6SGIWw, m);
}

void Heavy_SoundScraper::cVar_v3sA9HUq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_fv89qSUD, HV_BINOP_MULTIPLY, 0, m, &cBinop_fv89qSUD_sendMessage);
}

void Heavy_SoundScraper::cMsg_19jH6Trp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Sk7TX31D_sendMessage);
}

void Heavy_SoundScraper::cSystem_Sk7TX31D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_PjcRfYvE_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_fv89qSUD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_FuyNec4u_sendMessage);
}

void Heavy_SoundScraper::cBinop_UnReLv3c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_fv89qSUD, HV_BINOP_MULTIPLY, 1, m, &cBinop_fv89qSUD_sendMessage);
}

void Heavy_SoundScraper::cMsg_PjcRfYvE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_UnReLv3c_sendMessage);
}

void Heavy_SoundScraper::cBinop_FuyNec4u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_e32Q3rWV_sendMessage);
}

void Heavy_SoundScraper::cBinop_e32Q3rWV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_5dzhR1yE_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_vRKr3pEf, m);
}

void Heavy_SoundScraper::cBinop_5dzhR1yE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_pnP15uQM, m);
}

void Heavy_SoundScraper::cMsg_lxTkG8wj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_0pFwPg28_sendMessage);
}

void Heavy_SoundScraper::cSystem_0pFwPg28_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_RuPGVFbE_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_Y04IlGaJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1e-05f, 0, m, &cBinop_InksRw44_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_WPZpAnww, 0, m, &cIf_WPZpAnww_sendMessage);
}

void Heavy_SoundScraper::cIf_WPZpAnww_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_tsG9yDqR_sendMessage(_c, 0, m);
      cMsg_UR1hA8SQ_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_JYxeGgN5_sendMessage(_c, 0, m);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_M65w9Nwe_sendMessage);
      sVarf_onMessage(_c, &Context(_c)->sVarf_lLuH2O4I, m);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_InksRw44_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_WPZpAnww, 1, m, &cIf_WPZpAnww_sendMessage);
}

void Heavy_SoundScraper::cMsg_JYxeGgN5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_4NYTWIGm_sendMessage);
}

void Heavy_SoundScraper::cBinop_4NYTWIGm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_F9Kl3kXb, m);
}

void Heavy_SoundScraper::cBinop_M65w9Nwe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ZgzyLk5v_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_ZgzyLk5v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_ryhXZL5Y_sendMessage);
}

void Heavy_SoundScraper::cBinop_ryhXZL5Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_VqqSXJLN_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_VqqSXJLN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_qF4nEUcK_sendMessage);
}

void Heavy_SoundScraper::cBinop_qF4nEUcK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_tcP5yXgU, m);
}

void Heavy_SoundScraper::cBinop_AKo3UZZa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_bGXM7Urz, m);
}

void Heavy_SoundScraper::cMsg_RuPGVFbE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_AKo3UZZa_sendMessage);
}

void Heavy_SoundScraper::cMsg_tsG9yDqR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_M65w9Nwe_sendMessage);
}

void Heavy_SoundScraper::cMsg_UR1hA8SQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, -1.0f);
  sVarf_onMessage(_c, &Context(_c)->sVarf_F9Kl3kXb, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_lLuH2O4I, m);
}

void Heavy_SoundScraper::cBinop_1RF7CGEY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ODgcRrf1, 0, m, &cVar_ODgcRrf1_sendMessage);
}

void Heavy_SoundScraper::cBinop_YNv074Po_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_wuOfDgb2, 0, m, &cVar_wuOfDgb2_sendMessage);
}

void Heavy_SoundScraper::cBinop_GRI3MX2N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_v3sA9HUq, 0, m, &cVar_v3sA9HUq_sendMessage);
}

void Heavy_SoundScraper::cCast_pOn241wh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_LQkF2yxi, m);
}

void Heavy_SoundScraper::cCast_o1bHRgpi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.0f, 0, m, &cBinop_1RF7CGEY_sendMessage);
}

void Heavy_SoundScraper::cCast_IOfzGc8c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.0f, 0, m, &cBinop_GRI3MX2N_sendMessage);
}

void Heavy_SoundScraper::cCast_lu72cHsQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.0f, 0, m, &cBinop_YNv074Po_sendMessage);
}

void Heavy_SoundScraper::cTabhead_g3bDoRJh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_WiCJq3IL, HV_BINOP_SUBTRACT, 0, m, &cBinop_WiCJq3IL_sendMessage);
}

void Heavy_SoundScraper::cMsg_TVKsxiXj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_V6f98h8y_sendMessage);
}

void Heavy_SoundScraper::cSystem_V6f98h8y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_B1KpFUjv_sendMessage);
}

void Heavy_SoundScraper::cVar_TyNcSDcn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_BIv5jTrU_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_RK0Wo8tQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_RK0Wo8tQ, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_WRnv6Uz5, 0, m, &cDelay_WRnv6Uz5_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_RifD0f6y, 0, m, &sTabread_RifD0f6y_sendMessage);
}

void Heavy_SoundScraper::cDelay_WRnv6Uz5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_WRnv6Uz5, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_RifD0f6y, 0, m, &sTabread_RifD0f6y_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_WRnv6Uz5, 0, m, &cDelay_WRnv6Uz5_sendMessage);
}

void Heavy_SoundScraper::sTabread_RifD0f6y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_s39WrzPN, HV_BINOP_SUBTRACT, 0, m, &cBinop_s39WrzPN_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_gfmQI2or_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_oGZsuRuA, HV_BINOP_MAX, 0, m, &cBinop_oGZsuRuA_sendMessage);
}

void Heavy_SoundScraper::cBinop_B1KpFUjv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_gfmQI2or, HV_BINOP_MULTIPLY, 0, m, &cBinop_gfmQI2or_sendMessage);
}

void Heavy_SoundScraper::cBinop_WiCJq3IL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_4ri0BrNw_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_RifD0f6y, 0, m, &sTabread_RifD0f6y_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ZuhlirRf_sendMessage);
}

void Heavy_SoundScraper::cSystem_qaYf5FgY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_s39WrzPN, HV_BINOP_SUBTRACT, 1, m, &cBinop_s39WrzPN_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_WRnv6Uz5, 2, m, &cDelay_WRnv6Uz5_sendMessage);
}

void Heavy_SoundScraper::cMsg_BIv5jTrU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_qaYf5FgY_sendMessage);
}

void Heavy_SoundScraper::cMsg_4ri0BrNw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_RK0Wo8tQ, 0, m, &cDelay_RK0Wo8tQ_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_WRnv6Uz5, 0, m, &cDelay_WRnv6Uz5_sendMessage);
}

void Heavy_SoundScraper::cMsg_NFVzouae_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_oGZsuRuA, HV_BINOP_MAX, 1, m, &cBinop_oGZsuRuA_sendMessage);
}

void Heavy_SoundScraper::cBinop_oGZsuRuA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_WiCJq3IL, HV_BINOP_SUBTRACT, 1, m, &cBinop_WiCJq3IL_sendMessage);
}

void Heavy_SoundScraper::cCast_ZuhlirRf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_RK0Wo8tQ, 0, m, &cDelay_RK0Wo8tQ_sendMessage);
}

void Heavy_SoundScraper::cBinop_bmja5mtO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_RK0Wo8tQ, 2, m, &cDelay_RK0Wo8tQ_sendMessage);
}

void Heavy_SoundScraper::cBinop_s39WrzPN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_bmja5mtO_sendMessage);
}

void Heavy_SoundScraper::cCast_EyKnpoO2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_TyNcSDcn, 0, m, &cVar_TyNcSDcn_sendMessage);
  cMsg_TVKsxiXj_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_g3bDoRJh, 0, m, &cTabhead_g3bDoRJh_sendMessage);
}

void Heavy_SoundScraper::cTabhead_SaueSYpz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6oVaTLSY, HV_BINOP_SUBTRACT, 0, m, &cBinop_6oVaTLSY_sendMessage);
}

void Heavy_SoundScraper::cMsg_gDnNAJhh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_YCAiVNWC_sendMessage);
}

void Heavy_SoundScraper::cSystem_YCAiVNWC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_ab0FsMKu_sendMessage);
}

void Heavy_SoundScraper::cVar_tCr4Txa4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_7FOFcEHT_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_D3HRWLdw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_D3HRWLdw, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_wgQHNY1s, 0, m, &cDelay_wgQHNY1s_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_3qjsq7ya, 0, m, &sTabread_3qjsq7ya_sendMessage);
}

void Heavy_SoundScraper::cDelay_wgQHNY1s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_wgQHNY1s, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_3qjsq7ya, 0, m, &sTabread_3qjsq7ya_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_wgQHNY1s, 0, m, &cDelay_wgQHNY1s_sendMessage);
}

void Heavy_SoundScraper::sTabread_3qjsq7ya_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_UCW2qyHY, HV_BINOP_SUBTRACT, 0, m, &cBinop_UCW2qyHY_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_uPjbTV26_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_G539oxKf, HV_BINOP_MAX, 0, m, &cBinop_G539oxKf_sendMessage);
}

void Heavy_SoundScraper::cBinop_ab0FsMKu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_uPjbTV26, HV_BINOP_MULTIPLY, 0, m, &cBinop_uPjbTV26_sendMessage);
}

void Heavy_SoundScraper::cBinop_6oVaTLSY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_7iwtbXAj_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_3qjsq7ya, 0, m, &sTabread_3qjsq7ya_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Bom2LDhu_sendMessage);
}

void Heavy_SoundScraper::cSystem_I313mKEX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_UCW2qyHY, HV_BINOP_SUBTRACT, 1, m, &cBinop_UCW2qyHY_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_wgQHNY1s, 2, m, &cDelay_wgQHNY1s_sendMessage);
}

void Heavy_SoundScraper::cMsg_7FOFcEHT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_I313mKEX_sendMessage);
}

void Heavy_SoundScraper::cMsg_7iwtbXAj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_D3HRWLdw, 0, m, &cDelay_D3HRWLdw_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_wgQHNY1s, 0, m, &cDelay_wgQHNY1s_sendMessage);
}

void Heavy_SoundScraper::cMsg_89murrK3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_G539oxKf, HV_BINOP_MAX, 1, m, &cBinop_G539oxKf_sendMessage);
}

void Heavy_SoundScraper::cBinop_G539oxKf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6oVaTLSY, HV_BINOP_SUBTRACT, 1, m, &cBinop_6oVaTLSY_sendMessage);
}

void Heavy_SoundScraper::cCast_Bom2LDhu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_D3HRWLdw, 0, m, &cDelay_D3HRWLdw_sendMessage);
}

void Heavy_SoundScraper::cBinop_fYw6OtPD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_D3HRWLdw, 2, m, &cDelay_D3HRWLdw_sendMessage);
}

void Heavy_SoundScraper::cBinop_UCW2qyHY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_fYw6OtPD_sendMessage);
}

void Heavy_SoundScraper::cCast_P1GZd8FO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_tCr4Txa4, 0, m, &cVar_tCr4Txa4_sendMessage);
  cMsg_gDnNAJhh_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_SaueSYpz, 0, m, &cTabhead_SaueSYpz_sendMessage);
}

void Heavy_SoundScraper::cTabhead_sGFhYcyg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_x0X6mqgW, HV_BINOP_SUBTRACT, 0, m, &cBinop_x0X6mqgW_sendMessage);
}

void Heavy_SoundScraper::cMsg_HoXI0RmS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_60Evl8oZ_sendMessage);
}

void Heavy_SoundScraper::cSystem_60Evl8oZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_FM3ssKFn_sendMessage);
}

void Heavy_SoundScraper::cVar_r7u0diin_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_tvDjwX9f_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_sri5vpP5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_sri5vpP5, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_4LlpkR2S, 0, m, &cDelay_4LlpkR2S_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_oVRZbKxD, 0, m, &sTabread_oVRZbKxD_sendMessage);
}

void Heavy_SoundScraper::cDelay_4LlpkR2S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_4LlpkR2S, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_oVRZbKxD, 0, m, &sTabread_oVRZbKxD_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_4LlpkR2S, 0, m, &cDelay_4LlpkR2S_sendMessage);
}

void Heavy_SoundScraper::sTabread_oVRZbKxD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_wpnxkcjP, HV_BINOP_SUBTRACT, 0, m, &cBinop_wpnxkcjP_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_0OssJC2q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_tTNv9Tq7, HV_BINOP_MAX, 0, m, &cBinop_tTNv9Tq7_sendMessage);
}

void Heavy_SoundScraper::cBinop_FM3ssKFn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_0OssJC2q, HV_BINOP_MULTIPLY, 0, m, &cBinop_0OssJC2q_sendMessage);
}

void Heavy_SoundScraper::cBinop_x0X6mqgW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_VuWpq83O_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_oVRZbKxD, 0, m, &sTabread_oVRZbKxD_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_DJTG4TXT_sendMessage);
}

void Heavy_SoundScraper::cSystem_fI6KLkPN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_wpnxkcjP, HV_BINOP_SUBTRACT, 1, m, &cBinop_wpnxkcjP_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_4LlpkR2S, 2, m, &cDelay_4LlpkR2S_sendMessage);
}

void Heavy_SoundScraper::cMsg_tvDjwX9f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_fI6KLkPN_sendMessage);
}

void Heavy_SoundScraper::cMsg_VuWpq83O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_sri5vpP5, 0, m, &cDelay_sri5vpP5_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_4LlpkR2S, 0, m, &cDelay_4LlpkR2S_sendMessage);
}

void Heavy_SoundScraper::cMsg_M62Si4Up_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_tTNv9Tq7, HV_BINOP_MAX, 1, m, &cBinop_tTNv9Tq7_sendMessage);
}

void Heavy_SoundScraper::cBinop_tTNv9Tq7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_x0X6mqgW, HV_BINOP_SUBTRACT, 1, m, &cBinop_x0X6mqgW_sendMessage);
}

void Heavy_SoundScraper::cCast_DJTG4TXT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_sri5vpP5, 0, m, &cDelay_sri5vpP5_sendMessage);
}

void Heavy_SoundScraper::cBinop_VetTue7s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_sri5vpP5, 2, m, &cDelay_sri5vpP5_sendMessage);
}

void Heavy_SoundScraper::cBinop_wpnxkcjP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_VetTue7s_sendMessage);
}

void Heavy_SoundScraper::cCast_ph1yJbOx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_r7u0diin, 0, m, &cVar_r7u0diin_sendMessage);
  cMsg_HoXI0RmS_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_sGFhYcyg, 0, m, &cTabhead_sGFhYcyg_sendMessage);
}

void Heavy_SoundScraper::cTabhead_pHZ1ktCN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_OinmEaEM, HV_BINOP_SUBTRACT, 0, m, &cBinop_OinmEaEM_sendMessage);
}

void Heavy_SoundScraper::cMsg_0LlJPGBe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_i4c8FPgu_sendMessage);
}

void Heavy_SoundScraper::cSystem_i4c8FPgu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_MZ1nQd2E_sendMessage);
}

void Heavy_SoundScraper::cVar_SzDT1Qtb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_6ToRFYRJ_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_ggdfsjLf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_ggdfsjLf, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_aZR6UZgd, 0, m, &cDelay_aZR6UZgd_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_oaMZ0dHH, 0, m, &sTabread_oaMZ0dHH_sendMessage);
}

void Heavy_SoundScraper::cDelay_aZR6UZgd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_aZR6UZgd, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_oaMZ0dHH, 0, m, &sTabread_oaMZ0dHH_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_aZR6UZgd, 0, m, &cDelay_aZR6UZgd_sendMessage);
}

void Heavy_SoundScraper::sTabread_oaMZ0dHH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_jCd0TpZ8, HV_BINOP_SUBTRACT, 0, m, &cBinop_jCd0TpZ8_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_mbCk7wKY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_VPVh62jA, HV_BINOP_MAX, 0, m, &cBinop_VPVh62jA_sendMessage);
}

void Heavy_SoundScraper::cBinop_MZ1nQd2E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_mbCk7wKY, HV_BINOP_MULTIPLY, 0, m, &cBinop_mbCk7wKY_sendMessage);
}

void Heavy_SoundScraper::cBinop_OinmEaEM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Lz78iSQF_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_oaMZ0dHH, 0, m, &sTabread_oaMZ0dHH_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_3vAI0nND_sendMessage);
}

void Heavy_SoundScraper::cSystem_r4K1OOMD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_jCd0TpZ8, HV_BINOP_SUBTRACT, 1, m, &cBinop_jCd0TpZ8_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_aZR6UZgd, 2, m, &cDelay_aZR6UZgd_sendMessage);
}

void Heavy_SoundScraper::cMsg_6ToRFYRJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_r4K1OOMD_sendMessage);
}

void Heavy_SoundScraper::cMsg_Lz78iSQF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_ggdfsjLf, 0, m, &cDelay_ggdfsjLf_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_aZR6UZgd, 0, m, &cDelay_aZR6UZgd_sendMessage);
}

void Heavy_SoundScraper::cMsg_rkYTYmS1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_VPVh62jA, HV_BINOP_MAX, 1, m, &cBinop_VPVh62jA_sendMessage);
}

void Heavy_SoundScraper::cBinop_VPVh62jA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_OinmEaEM, HV_BINOP_SUBTRACT, 1, m, &cBinop_OinmEaEM_sendMessage);
}

void Heavy_SoundScraper::cCast_3vAI0nND_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_ggdfsjLf, 0, m, &cDelay_ggdfsjLf_sendMessage);
}

void Heavy_SoundScraper::cBinop_B2m5JOwg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_ggdfsjLf, 2, m, &cDelay_ggdfsjLf_sendMessage);
}

void Heavy_SoundScraper::cBinop_jCd0TpZ8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_B2m5JOwg_sendMessage);
}

void Heavy_SoundScraper::cCast_UbZXeDw3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_SzDT1Qtb, 0, m, &cVar_SzDT1Qtb_sendMessage);
  cMsg_0LlJPGBe_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_pHZ1ktCN, 0, m, &cTabhead_pHZ1ktCN_sendMessage);
}

void Heavy_SoundScraper::cMsg_Icnhxqki_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_n77L34hx_sendMessage);
}

void Heavy_SoundScraper::cSystem_n77L34hx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_EbsCIgDM_sendMessage);
}

void Heavy_SoundScraper::cDelay_KXgvFeK9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_KXgvFeK9, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_uXyScthK, 0, m, &cDelay_uXyScthK_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_KXgvFeK9, 0, m, &cDelay_KXgvFeK9_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_dvdnNiuf, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_uXyScthK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_uXyScthK, m);
  cMsg_gNlZCVc1_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_LXuj2Ygi_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_jWODvHoy_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_d366StYu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_VoMiUSne_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_7LsDOYF6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_s4q31vgy_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_KXgvFeK9, 2, m, &cDelay_KXgvFeK9_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_LAVLdNk2_sendMessage);
}

void Heavy_SoundScraper::cMsg_VoMiUSne_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_7LsDOYF6, 0, m, &hTable_7LsDOYF6_sendMessage);
}

void Heavy_SoundScraper::cBinop_EbsCIgDM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 58.6435f, 0, m, &cBinop_d366StYu_sendMessage);
}

void Heavy_SoundScraper::cMsg_gNlZCVc1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_7LsDOYF6, 0, m, &hTable_7LsDOYF6_sendMessage);
}

void Heavy_SoundScraper::cCast_LAVLdNk2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_KXgvFeK9, 0, m, &cDelay_KXgvFeK9_sendMessage);
}

void Heavy_SoundScraper::cMsg_s4q31vgy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_uXyScthK, 2, m, &cDelay_uXyScthK_sendMessage);
}

void Heavy_SoundScraper::cMsg_jWODvHoy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_dvdnNiuf, 1, m, NULL);
}

void Heavy_SoundScraper::cMsg_mdNFQms4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_7uGl1FK3_sendMessage);
}

void Heavy_SoundScraper::cSystem_7uGl1FK3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_94LtyCXP_sendMessage);
}

void Heavy_SoundScraper::cDelay_rumW5d5m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_rumW5d5m, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_VpsUpr1Y, 0, m, &cDelay_VpsUpr1Y_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_rumW5d5m, 0, m, &cDelay_rumW5d5m_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_fhb54cn5, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_VpsUpr1Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_VpsUpr1Y, m);
  cMsg_cfGZyHCm_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_EJUbJW59_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_LMhRUH7G_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_G8yCuGhH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_qCsfJVKI_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_tUav5lY2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_2F3YE0vS_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_rumW5d5m, 2, m, &cDelay_rumW5d5m_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_zJsdxiN7_sendMessage);
}

void Heavy_SoundScraper::cMsg_qCsfJVKI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_tUav5lY2, 0, m, &hTable_tUav5lY2_sendMessage);
}

void Heavy_SoundScraper::cBinop_94LtyCXP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 69.4325f, 0, m, &cBinop_G8yCuGhH_sendMessage);
}

void Heavy_SoundScraper::cMsg_cfGZyHCm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_tUav5lY2, 0, m, &hTable_tUav5lY2_sendMessage);
}

void Heavy_SoundScraper::cCast_zJsdxiN7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_rumW5d5m, 0, m, &cDelay_rumW5d5m_sendMessage);
}

void Heavy_SoundScraper::cMsg_2F3YE0vS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_VpsUpr1Y, 2, m, &cDelay_VpsUpr1Y_sendMessage);
}

void Heavy_SoundScraper::cMsg_LMhRUH7G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_fhb54cn5, 1, m, NULL);
}

void Heavy_SoundScraper::cMsg_Lpm6xwJc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_0I5EfYGH_sendMessage);
}

void Heavy_SoundScraper::cSystem_0I5EfYGH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_yzA5qJGJ_sendMessage);
}

void Heavy_SoundScraper::cDelay_OGqgEGFU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_OGqgEGFU, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_y6jrWs3E, 0, m, &cDelay_y6jrWs3E_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_OGqgEGFU, 0, m, &cDelay_OGqgEGFU_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_wGQCtqrr, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_y6jrWs3E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_y6jrWs3E, m);
  cMsg_qnZXI7vt_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_KFPZZqXY_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_wa2qx1Jm_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_qftRKwDg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_pifsZh6O_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_6R5an42N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_mkQIGByi_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_OGqgEGFU, 2, m, &cDelay_OGqgEGFU_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_kQeGoF1I_sendMessage);
}

void Heavy_SoundScraper::cMsg_pifsZh6O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_6R5an42N, 0, m, &hTable_6R5an42N_sendMessage);
}

void Heavy_SoundScraper::cBinop_yzA5qJGJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 74.5234f, 0, m, &cBinop_qftRKwDg_sendMessage);
}

void Heavy_SoundScraper::cMsg_qnZXI7vt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_6R5an42N, 0, m, &hTable_6R5an42N_sendMessage);
}

void Heavy_SoundScraper::cCast_kQeGoF1I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_OGqgEGFU, 0, m, &cDelay_OGqgEGFU_sendMessage);
}

void Heavy_SoundScraper::cMsg_mkQIGByi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_y6jrWs3E, 2, m, &cDelay_y6jrWs3E_sendMessage);
}

void Heavy_SoundScraper::cMsg_wa2qx1Jm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_wGQCtqrr, 1, m, NULL);
}

void Heavy_SoundScraper::cMsg_Phe8aIXG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_1PKRBJU1_sendMessage);
}

void Heavy_SoundScraper::cSystem_1PKRBJU1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_nn6IVtKp_sendMessage);
}

void Heavy_SoundScraper::cDelay_DVRi2YYx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_DVRi2YYx, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_fXCmmqA2, 0, m, &cDelay_fXCmmqA2_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_DVRi2YYx, 0, m, &cDelay_DVRi2YYx_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_QTTuUDMa, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_fXCmmqA2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_fXCmmqA2, m);
  cMsg_bB4Cg1AK_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_vIYrhBks_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_NCX2WiSt_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_oPOlnpP1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_94aBZjZ7_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_rjOzbEZE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_YnarEdKH_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_DVRi2YYx, 2, m, &cDelay_DVRi2YYx_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_1EiV13Dg_sendMessage);
}

void Heavy_SoundScraper::cMsg_94aBZjZ7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_rjOzbEZE, 0, m, &hTable_rjOzbEZE_sendMessage);
}

void Heavy_SoundScraper::cBinop_nn6IVtKp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 86.1244f, 0, m, &cBinop_oPOlnpP1_sendMessage);
}

void Heavy_SoundScraper::cMsg_bB4Cg1AK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_rjOzbEZE, 0, m, &hTable_rjOzbEZE_sendMessage);
}

void Heavy_SoundScraper::cCast_1EiV13Dg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_DVRi2YYx, 0, m, &cDelay_DVRi2YYx_sendMessage);
}

void Heavy_SoundScraper::cMsg_YnarEdKH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_fXCmmqA2, 2, m, &cDelay_fXCmmqA2_sendMessage);
}

void Heavy_SoundScraper::cMsg_NCX2WiSt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_QTTuUDMa, 1, m, NULL);
}

void Heavy_SoundScraper::cIf_P0M4nDpw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_JFEltohD_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_sYJoZk9b_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cMsg_SNGb0a2u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_JkcBagQn, HV_BINOP_POW, 0, m, &cBinop_JkcBagQn_sendMessage);
}

void Heavy_SoundScraper::cBinop_JkcBagQn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.125f, 0, m, &cBinop_OC8KP6NP_sendMessage);
}

void Heavy_SoundScraper::cBinop_EUyK0RKo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_1pYcKUq2_sendMessage);
}

void Heavy_SoundScraper::cCast_U2vUAiiI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_P0M4nDpw, 0, m, &cIf_P0M4nDpw_sendMessage);
}

void Heavy_SoundScraper::cCast_nbZlaenN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_7L1oSyKy_sendMessage);
}

void Heavy_SoundScraper::cBinop_7L1oSyKy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_P0M4nDpw, 1, m, &cIf_P0M4nDpw_sendMessage);
}

void Heavy_SoundScraper::cBinop_sYJoZk9b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_EUyK0RKo_sendMessage);
}

void Heavy_SoundScraper::cMsg_JFEltohD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.125f, 0, m, &cBinop_OC8KP6NP_sendMessage);
}

void Heavy_SoundScraper::cBinop_1pYcKUq2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_JkcBagQn, HV_BINOP_POW, 1, m, &cBinop_JkcBagQn_sendMessage);
  cMsg_SNGb0a2u_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_egjSAywK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_HhK41dBC, 0, m, NULL);
}

void Heavy_SoundScraper::cPack_QncVoE9J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_zusUuoW7, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_04fu1DYC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_BJikpZ60_sendMessage);
}

void Heavy_SoundScraper::cBinop_BJikpZ60_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 200.0f, 0, m, &cBinop_kWFyhfKQ_sendMessage);
}

void Heavy_SoundScraper::cVar_nTONyhq2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_CQSmMKdN, HV_BINOP_MULTIPLY, 0, m, &cBinop_CQSmMKdN_sendMessage);
}

void Heavy_SoundScraper::cMsg_yDzeGE5l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_oYeS3NUs_sendMessage);
}

void Heavy_SoundScraper::cSystem_oYeS3NUs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_khnpFxEc_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_CQSmMKdN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_dC7a9ToH_sendMessage);
}

void Heavy_SoundScraper::cBinop_HZNkzcpx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_CQSmMKdN, HV_BINOP_MULTIPLY, 1, m, &cBinop_CQSmMKdN_sendMessage);
}

void Heavy_SoundScraper::cMsg_khnpFxEc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_HZNkzcpx_sendMessage);
}

void Heavy_SoundScraper::cBinop_dC7a9ToH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_3CD9mmJm_sendMessage);
}

void Heavy_SoundScraper::cBinop_3CD9mmJm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_d6RuaNag_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_UAknzTth, m);
}

void Heavy_SoundScraper::cBinop_d6RuaNag_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_3VKgAxzB, m);
}

void Heavy_SoundScraper::cVar_qSxGogwg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_nbZlaenN_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_U2vUAiiI_sendMessage);
}

void Heavy_SoundScraper::cVar_2McqJ0E3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 100.0f, 0, m, &cBinop_04fu1DYC_sendMessage);
}

void Heavy_SoundScraper::cVar_Aa2xXIut_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_URt4JvDS_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_p4FnGATS, 0, m, &cIf_p4FnGATS_sendMessage);
}

void Heavy_SoundScraper::cVar_xn9YB15O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 100.0f, 0, m, &cBinop_Hc61yCmx_sendMessage);
}

void Heavy_SoundScraper::cIf_p4FnGATS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_sUXG5Pd4_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cVar_onMessage(_c, &Context(_c)->cVar_olUdTNuo, 0, m, &cVar_olUdTNuo_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_URt4JvDS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_p4FnGATS, 1, m, &cIf_p4FnGATS_sendMessage);
}

void Heavy_SoundScraper::cBinop_Hc61yCmx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_FPWtJthn_sendMessage);
}

void Heavy_SoundScraper::cBinop_FPWtJthn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_eSLj9Q2y, 0, m, &cVar_eSLj9Q2y_sendMessage);
}

void Heavy_SoundScraper::cTabhead_GBH0McQH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_n8owfffD, HV_BINOP_SUBTRACT, 0, m, &cBinop_n8owfffD_sendMessage);
}

void Heavy_SoundScraper::cMsg_u9dOb9jW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_yDzUhDjL_sendMessage);
}

void Heavy_SoundScraper::cSystem_yDzUhDjL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_1B4qpHo6_sendMessage);
}

void Heavy_SoundScraper::cVar_iJ3msAzO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_I6Gb70oW_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_61CX6xoZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_61CX6xoZ, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_l9fnkq1s, 0, m, &cDelay_l9fnkq1s_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_cCPK1SxE, 0, m, &sTabread_cCPK1SxE_sendMessage);
}

void Heavy_SoundScraper::cDelay_l9fnkq1s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_l9fnkq1s, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_cCPK1SxE, 0, m, &sTabread_cCPK1SxE_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_l9fnkq1s, 0, m, &cDelay_l9fnkq1s_sendMessage);
}

void Heavy_SoundScraper::sTabread_cCPK1SxE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_i8gtiPtD, HV_BINOP_SUBTRACT, 0, m, &cBinop_i8gtiPtD_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_RIyJRJRj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_wm8pgWfA, HV_BINOP_MAX, 0, m, &cBinop_wm8pgWfA_sendMessage);
}

void Heavy_SoundScraper::cBinop_1B4qpHo6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_RIyJRJRj, HV_BINOP_MULTIPLY, 0, m, &cBinop_RIyJRJRj_sendMessage);
}

void Heavy_SoundScraper::cBinop_n8owfffD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_JNo6ckbS_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_cCPK1SxE, 0, m, &sTabread_cCPK1SxE_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_HwoAXIHc_sendMessage);
}

void Heavy_SoundScraper::cSystem_YCus13jm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_i8gtiPtD, HV_BINOP_SUBTRACT, 1, m, &cBinop_i8gtiPtD_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_l9fnkq1s, 2, m, &cDelay_l9fnkq1s_sendMessage);
}

void Heavy_SoundScraper::cMsg_I6Gb70oW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_YCus13jm_sendMessage);
}

void Heavy_SoundScraper::cMsg_JNo6ckbS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_61CX6xoZ, 0, m, &cDelay_61CX6xoZ_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_l9fnkq1s, 0, m, &cDelay_l9fnkq1s_sendMessage);
}

void Heavy_SoundScraper::cMsg_eeh177Xw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_wm8pgWfA, HV_BINOP_MAX, 1, m, &cBinop_wm8pgWfA_sendMessage);
}

void Heavy_SoundScraper::cBinop_wm8pgWfA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_n8owfffD, HV_BINOP_SUBTRACT, 1, m, &cBinop_n8owfffD_sendMessage);
}

void Heavy_SoundScraper::cCast_HwoAXIHc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_61CX6xoZ, 0, m, &cDelay_61CX6xoZ_sendMessage);
}

void Heavy_SoundScraper::cBinop_0gYiTC2L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_61CX6xoZ, 2, m, &cDelay_61CX6xoZ_sendMessage);
}

void Heavy_SoundScraper::cBinop_i8gtiPtD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_0gYiTC2L_sendMessage);
}

void Heavy_SoundScraper::cCast_UDHUQgJR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_iJ3msAzO, 0, m, &cVar_iJ3msAzO_sendMessage);
  cMsg_u9dOb9jW_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_GBH0McQH, 0, m, &cTabhead_GBH0McQH_sendMessage);
}

void Heavy_SoundScraper::cMsg_uJoq1tDo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_OTOskf0K_sendMessage);
}

void Heavy_SoundScraper::cSystem_OTOskf0K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_OiNOoTVB_sendMessage);
}

void Heavy_SoundScraper::cDelay_ynSWo1uR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_ynSWo1uR, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Ogi5UdWM, 0, m, &cDelay_Ogi5UdWM_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ynSWo1uR, 0, m, &cDelay_ynSWo1uR_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_5wohD85C, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_Ogi5UdWM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Ogi5UdWM, m);
  cMsg_5wFsfeMc_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_BqZkqWt4_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_n4erVNH7_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_iWOUGZnZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_iNEEqg1L_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_X1sWepvN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_lCnryzns_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ynSWo1uR, 2, m, &cDelay_ynSWo1uR_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_jXxRlIsp_sendMessage);
}

void Heavy_SoundScraper::cMsg_iNEEqg1L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_X1sWepvN, 0, m, &hTable_X1sWepvN_sendMessage);
}

void Heavy_SoundScraper::cBinop_OiNOoTVB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 13.645f, 0, m, &cBinop_iWOUGZnZ_sendMessage);
}

void Heavy_SoundScraper::cMsg_5wFsfeMc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_X1sWepvN, 0, m, &hTable_X1sWepvN_sendMessage);
}

void Heavy_SoundScraper::cCast_jXxRlIsp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_ynSWo1uR, 0, m, &cDelay_ynSWo1uR_sendMessage);
}

void Heavy_SoundScraper::cMsg_lCnryzns_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_Ogi5UdWM, 2, m, &cDelay_Ogi5UdWM_sendMessage);
}

void Heavy_SoundScraper::cMsg_n4erVNH7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_5wohD85C, 1, m, NULL);
}

void Heavy_SoundScraper::cTabhead_mOIY8167_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_28eCfElO, HV_BINOP_SUBTRACT, 0, m, &cBinop_28eCfElO_sendMessage);
}

void Heavy_SoundScraper::cMsg_4FoeJHwA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_h523BuM8_sendMessage);
}

void Heavy_SoundScraper::cSystem_h523BuM8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_avIXoQkj_sendMessage);
}

void Heavy_SoundScraper::cVar_bFedv5Jg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_uCEeahM9_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_NFJIjzL1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_NFJIjzL1, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_JYOlSGNy, 0, m, &cDelay_JYOlSGNy_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_ZypL9G2b, 0, m, &sTabread_ZypL9G2b_sendMessage);
}

void Heavy_SoundScraper::cDelay_JYOlSGNy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_JYOlSGNy, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_ZypL9G2b, 0, m, &sTabread_ZypL9G2b_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_JYOlSGNy, 0, m, &cDelay_JYOlSGNy_sendMessage);
}

void Heavy_SoundScraper::sTabread_ZypL9G2b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_MbbwMyzh, HV_BINOP_SUBTRACT, 0, m, &cBinop_MbbwMyzh_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_vRxD0T0K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_0YHS0pEr, HV_BINOP_MAX, 0, m, &cBinop_0YHS0pEr_sendMessage);
}

void Heavy_SoundScraper::cBinop_avIXoQkj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_vRxD0T0K, HV_BINOP_MULTIPLY, 0, m, &cBinop_vRxD0T0K_sendMessage);
}

void Heavy_SoundScraper::cBinop_28eCfElO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_8Oknq4QZ_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_ZypL9G2b, 0, m, &sTabread_ZypL9G2b_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_1O0UU1xl_sendMessage);
}

void Heavy_SoundScraper::cSystem_ZD0ZuUQy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MbbwMyzh, HV_BINOP_SUBTRACT, 1, m, &cBinop_MbbwMyzh_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_JYOlSGNy, 2, m, &cDelay_JYOlSGNy_sendMessage);
}

void Heavy_SoundScraper::cMsg_uCEeahM9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ZD0ZuUQy_sendMessage);
}

void Heavy_SoundScraper::cMsg_8Oknq4QZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_NFJIjzL1, 0, m, &cDelay_NFJIjzL1_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_JYOlSGNy, 0, m, &cDelay_JYOlSGNy_sendMessage);
}

void Heavy_SoundScraper::cMsg_H2ASOmUL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_0YHS0pEr, HV_BINOP_MAX, 1, m, &cBinop_0YHS0pEr_sendMessage);
}

void Heavy_SoundScraper::cBinop_0YHS0pEr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_28eCfElO, HV_BINOP_SUBTRACT, 1, m, &cBinop_28eCfElO_sendMessage);
}

void Heavy_SoundScraper::cCast_1O0UU1xl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_NFJIjzL1, 0, m, &cDelay_NFJIjzL1_sendMessage);
}

void Heavy_SoundScraper::cBinop_rUqNvV18_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_NFJIjzL1, 2, m, &cDelay_NFJIjzL1_sendMessage);
}

void Heavy_SoundScraper::cBinop_MbbwMyzh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_rUqNvV18_sendMessage);
}

void Heavy_SoundScraper::cCast_Dz3dtVcy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_bFedv5Jg, 0, m, &cVar_bFedv5Jg_sendMessage);
  cMsg_4FoeJHwA_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_mOIY8167, 0, m, &cTabhead_mOIY8167_sendMessage);
}

void Heavy_SoundScraper::cMsg_70xFmzrz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_tUAXQRkS_sendMessage);
}

void Heavy_SoundScraper::cSystem_tUAXQRkS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_pZUe8bJa_sendMessage);
}

void Heavy_SoundScraper::cDelay_cjxk6vcy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_cjxk6vcy, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_OyJy4J4O, 0, m, &cDelay_OyJy4J4O_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_cjxk6vcy, 0, m, &cDelay_cjxk6vcy_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_xEqUPJcW, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_OyJy4J4O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_OyJy4J4O, m);
  cMsg_UeINpoAc_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_nGAw4Fe3_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_uqke1TjV_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_QH7yQ0Cr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_h2h2DJHD_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_caFOb0L8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_CZNmRDbk_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_cjxk6vcy, 2, m, &cDelay_cjxk6vcy_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_9IuFFANP_sendMessage);
}

void Heavy_SoundScraper::cMsg_h2h2DJHD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_caFOb0L8, 0, m, &hTable_caFOb0L8_sendMessage);
}

void Heavy_SoundScraper::cBinop_pZUe8bJa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 16.364f, 0, m, &cBinop_QH7yQ0Cr_sendMessage);
}

void Heavy_SoundScraper::cMsg_UeINpoAc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_caFOb0L8, 0, m, &hTable_caFOb0L8_sendMessage);
}

void Heavy_SoundScraper::cCast_9IuFFANP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_cjxk6vcy, 0, m, &cDelay_cjxk6vcy_sendMessage);
}

void Heavy_SoundScraper::cMsg_CZNmRDbk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_OyJy4J4O, 2, m, &cDelay_OyJy4J4O_sendMessage);
}

void Heavy_SoundScraper::cMsg_uqke1TjV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_xEqUPJcW, 1, m, NULL);
}

void Heavy_SoundScraper::cTabhead_Woe8xP8g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_yhElLTeN, HV_BINOP_SUBTRACT, 0, m, &cBinop_yhElLTeN_sendMessage);
}

void Heavy_SoundScraper::cMsg_io3vlpqK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_XWjCVc41_sendMessage);
}

void Heavy_SoundScraper::cSystem_XWjCVc41_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_V3VnMBWj_sendMessage);
}

void Heavy_SoundScraper::cVar_5EAwz1s1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_DYa9r4cs_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_bPizPluu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_bPizPluu, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_sr7vkyHL, 0, m, &cDelay_sr7vkyHL_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_hwttHFZi, 0, m, &sTabread_hwttHFZi_sendMessage);
}

void Heavy_SoundScraper::cDelay_sr7vkyHL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_sr7vkyHL, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_hwttHFZi, 0, m, &sTabread_hwttHFZi_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_sr7vkyHL, 0, m, &cDelay_sr7vkyHL_sendMessage);
}

void Heavy_SoundScraper::sTabread_hwttHFZi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_6tHsuZvD, HV_BINOP_SUBTRACT, 0, m, &cBinop_6tHsuZvD_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_pybcb7sV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_n4jsbmOF, HV_BINOP_MAX, 0, m, &cBinop_n4jsbmOF_sendMessage);
}

void Heavy_SoundScraper::cBinop_V3VnMBWj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_pybcb7sV, HV_BINOP_MULTIPLY, 0, m, &cBinop_pybcb7sV_sendMessage);
}

void Heavy_SoundScraper::cBinop_yhElLTeN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_hnJK3TZv_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_hwttHFZi, 0, m, &sTabread_hwttHFZi_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_y3zQZ0LA_sendMessage);
}

void Heavy_SoundScraper::cSystem_9RC35N1d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6tHsuZvD, HV_BINOP_SUBTRACT, 1, m, &cBinop_6tHsuZvD_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_sr7vkyHL, 2, m, &cDelay_sr7vkyHL_sendMessage);
}

void Heavy_SoundScraper::cMsg_DYa9r4cs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_9RC35N1d_sendMessage);
}

void Heavy_SoundScraper::cMsg_hnJK3TZv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_bPizPluu, 0, m, &cDelay_bPizPluu_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_sr7vkyHL, 0, m, &cDelay_sr7vkyHL_sendMessage);
}

void Heavy_SoundScraper::cMsg_4uxe1gFt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_n4jsbmOF, HV_BINOP_MAX, 1, m, &cBinop_n4jsbmOF_sendMessage);
}

void Heavy_SoundScraper::cBinop_n4jsbmOF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_yhElLTeN, HV_BINOP_SUBTRACT, 1, m, &cBinop_yhElLTeN_sendMessage);
}

void Heavy_SoundScraper::cCast_y3zQZ0LA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_bPizPluu, 0, m, &cDelay_bPizPluu_sendMessage);
}

void Heavy_SoundScraper::cBinop_TuugDfKQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_bPizPluu, 2, m, &cDelay_bPizPluu_sendMessage);
}

void Heavy_SoundScraper::cBinop_6tHsuZvD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_TuugDfKQ_sendMessage);
}

void Heavy_SoundScraper::cCast_wFrjI7D5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_5EAwz1s1, 0, m, &cVar_5EAwz1s1_sendMessage);
  cMsg_io3vlpqK_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_Woe8xP8g, 0, m, &cTabhead_Woe8xP8g_sendMessage);
}

void Heavy_SoundScraper::cMsg_ruJUcsa0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_3EQB27HB_sendMessage);
}

void Heavy_SoundScraper::cSystem_3EQB27HB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_VxeiWDVD_sendMessage);
}

void Heavy_SoundScraper::cDelay_5jUtUgIN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_5jUtUgIN, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Tc4xuv0o, 0, m, &cDelay_Tc4xuv0o_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_5jUtUgIN, 0, m, &cDelay_5jUtUgIN_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_1TF3Xi34, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_Tc4xuv0o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Tc4xuv0o, m);
  cMsg_yx2KEa4A_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_MwF2t1PU_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_wEq75rzy_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_S1cTYyEZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_EkdZ3Zej_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_UUU4p40c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Atq1FENJ_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_5jUtUgIN, 2, m, &cDelay_5jUtUgIN_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Nwt1oarV_sendMessage);
}

void Heavy_SoundScraper::cMsg_EkdZ3Zej_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_UUU4p40c, 0, m, &hTable_UUU4p40c_sendMessage);
}

void Heavy_SoundScraper::cBinop_VxeiWDVD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 19.392f, 0, m, &cBinop_S1cTYyEZ_sendMessage);
}

void Heavy_SoundScraper::cMsg_yx2KEa4A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_UUU4p40c, 0, m, &hTable_UUU4p40c_sendMessage);
}

void Heavy_SoundScraper::cCast_Nwt1oarV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_5jUtUgIN, 0, m, &cDelay_5jUtUgIN_sendMessage);
}

void Heavy_SoundScraper::cMsg_Atq1FENJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_Tc4xuv0o, 2, m, &cDelay_Tc4xuv0o_sendMessage);
}

void Heavy_SoundScraper::cMsg_wEq75rzy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_1TF3Xi34, 1, m, NULL);
}

void Heavy_SoundScraper::cTabhead_OPKyeqS7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_iluI5w0g, HV_BINOP_SUBTRACT, 0, m, &cBinop_iluI5w0g_sendMessage);
}

void Heavy_SoundScraper::cMsg_V7AO5G18_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_qEwBn3rQ_sendMessage);
}

void Heavy_SoundScraper::cSystem_qEwBn3rQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_iWLEs0R4_sendMessage);
}

void Heavy_SoundScraper::cVar_MWbeBsTD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_7NAkfTVk_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_Ce8iE1Eh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Ce8iE1Eh, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_H6WQVmxj, 0, m, &cDelay_H6WQVmxj_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_hvXwyfuS, 0, m, &sTabread_hvXwyfuS_sendMessage);
}

void Heavy_SoundScraper::cDelay_H6WQVmxj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_H6WQVmxj, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_hvXwyfuS, 0, m, &sTabread_hvXwyfuS_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_H6WQVmxj, 0, m, &cDelay_H6WQVmxj_sendMessage);
}

void Heavy_SoundScraper::sTabread_hvXwyfuS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_I6458TTN, HV_BINOP_SUBTRACT, 0, m, &cBinop_I6458TTN_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_KmvIB8Mx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_XNCCQXPH, HV_BINOP_MAX, 0, m, &cBinop_XNCCQXPH_sendMessage);
}

void Heavy_SoundScraper::cBinop_iWLEs0R4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_KmvIB8Mx, HV_BINOP_MULTIPLY, 0, m, &cBinop_KmvIB8Mx_sendMessage);
}

void Heavy_SoundScraper::cBinop_iluI5w0g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_QzW9tWUD_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_hvXwyfuS, 0, m, &sTabread_hvXwyfuS_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_hrSvQ02I_sendMessage);
}

void Heavy_SoundScraper::cSystem_6tnHLlAk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_I6458TTN, HV_BINOP_SUBTRACT, 1, m, &cBinop_I6458TTN_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_H6WQVmxj, 2, m, &cDelay_H6WQVmxj_sendMessage);
}

void Heavy_SoundScraper::cMsg_7NAkfTVk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_6tnHLlAk_sendMessage);
}

void Heavy_SoundScraper::cMsg_QzW9tWUD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_Ce8iE1Eh, 0, m, &cDelay_Ce8iE1Eh_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_H6WQVmxj, 0, m, &cDelay_H6WQVmxj_sendMessage);
}

void Heavy_SoundScraper::cMsg_PBEQeHYd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_XNCCQXPH, HV_BINOP_MAX, 1, m, &cBinop_XNCCQXPH_sendMessage);
}

void Heavy_SoundScraper::cBinop_XNCCQXPH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_iluI5w0g, HV_BINOP_SUBTRACT, 1, m, &cBinop_iluI5w0g_sendMessage);
}

void Heavy_SoundScraper::cCast_hrSvQ02I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Ce8iE1Eh, 0, m, &cDelay_Ce8iE1Eh_sendMessage);
}

void Heavy_SoundScraper::cBinop_9OcfnjpG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Ce8iE1Eh, 2, m, &cDelay_Ce8iE1Eh_sendMessage);
}

void Heavy_SoundScraper::cBinop_I6458TTN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_9OcfnjpG_sendMessage);
}

void Heavy_SoundScraper::cCast_K7ZjxMgl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_MWbeBsTD, 0, m, &cVar_MWbeBsTD_sendMessage);
  cMsg_V7AO5G18_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_OPKyeqS7, 0, m, &cTabhead_OPKyeqS7_sendMessage);
}

void Heavy_SoundScraper::cMsg_HuOuhHJA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_V0EwAtc3_sendMessage);
}

void Heavy_SoundScraper::cSystem_V0EwAtc3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_XUOVyR9l_sendMessage);
}

void Heavy_SoundScraper::cDelay_s1R1hExp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_s1R1hExp, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_uYjulRu6, 0, m, &cDelay_uYjulRu6_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_s1R1hExp, 0, m, &cDelay_s1R1hExp_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_65hrwXRR, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_uYjulRu6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_uYjulRu6, m);
  cMsg_XmtSQATx_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_EFuo36hm_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_eB3oWgIH_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_KNRTnWn0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_FTkLYCRV_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_8OBIMoeC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ATmOwJDr_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_s1R1hExp, 2, m, &cDelay_s1R1hExp_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Sjh2z8O2_sendMessage);
}

void Heavy_SoundScraper::cMsg_FTkLYCRV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_8OBIMoeC, 0, m, &hTable_8OBIMoeC_sendMessage);
}

void Heavy_SoundScraper::cBinop_XUOVyR9l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 25.796f, 0, m, &cBinop_KNRTnWn0_sendMessage);
}

void Heavy_SoundScraper::cMsg_XmtSQATx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_8OBIMoeC, 0, m, &hTable_8OBIMoeC_sendMessage);
}

void Heavy_SoundScraper::cCast_Sjh2z8O2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_s1R1hExp, 0, m, &cDelay_s1R1hExp_sendMessage);
}

void Heavy_SoundScraper::cMsg_ATmOwJDr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_uYjulRu6, 2, m, &cDelay_uYjulRu6_sendMessage);
}

void Heavy_SoundScraper::cMsg_eB3oWgIH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_65hrwXRR, 1, m, NULL);
}

void Heavy_SoundScraper::cTabhead_GAXQJEnH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_aE6bDREm, HV_BINOP_SUBTRACT, 0, m, &cBinop_aE6bDREm_sendMessage);
}

void Heavy_SoundScraper::cMsg_0Iq9JqYI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Ol9HRE1Z_sendMessage);
}

void Heavy_SoundScraper::cSystem_Ol9HRE1Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_DF1Bp4e3_sendMessage);
}

void Heavy_SoundScraper::cVar_K4ETKfTt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_33ytGC9R_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_8FnyJ1iH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_8FnyJ1iH, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_WmwEniCL, 0, m, &cDelay_WmwEniCL_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_6JoEa4Rx, 0, m, &sTabread_6JoEa4Rx_sendMessage);
}

void Heavy_SoundScraper::cDelay_WmwEniCL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_WmwEniCL, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_6JoEa4Rx, 0, m, &sTabread_6JoEa4Rx_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_WmwEniCL, 0, m, &cDelay_WmwEniCL_sendMessage);
}

void Heavy_SoundScraper::sTabread_6JoEa4Rx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_liAjgoXe, HV_BINOP_SUBTRACT, 0, m, &cBinop_liAjgoXe_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_mNbfKs66_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_rIcWaGAr, HV_BINOP_MAX, 0, m, &cBinop_rIcWaGAr_sendMessage);
}

void Heavy_SoundScraper::cBinop_DF1Bp4e3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_mNbfKs66, HV_BINOP_MULTIPLY, 0, m, &cBinop_mNbfKs66_sendMessage);
}

void Heavy_SoundScraper::cBinop_aE6bDREm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_HF4SF59K_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_6JoEa4Rx, 0, m, &sTabread_6JoEa4Rx_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_fenK5KCF_sendMessage);
}

void Heavy_SoundScraper::cSystem_AKeYde7F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_liAjgoXe, HV_BINOP_SUBTRACT, 1, m, &cBinop_liAjgoXe_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_WmwEniCL, 2, m, &cDelay_WmwEniCL_sendMessage);
}

void Heavy_SoundScraper::cMsg_33ytGC9R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_AKeYde7F_sendMessage);
}

void Heavy_SoundScraper::cMsg_HF4SF59K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_8FnyJ1iH, 0, m, &cDelay_8FnyJ1iH_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_WmwEniCL, 0, m, &cDelay_WmwEniCL_sendMessage);
}

void Heavy_SoundScraper::cMsg_OrUinj59_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_rIcWaGAr, HV_BINOP_MAX, 1, m, &cBinop_rIcWaGAr_sendMessage);
}

void Heavy_SoundScraper::cBinop_rIcWaGAr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_aE6bDREm, HV_BINOP_SUBTRACT, 1, m, &cBinop_aE6bDREm_sendMessage);
}

void Heavy_SoundScraper::cCast_fenK5KCF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_8FnyJ1iH, 0, m, &cDelay_8FnyJ1iH_sendMessage);
}

void Heavy_SoundScraper::cBinop_KKCHol03_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_8FnyJ1iH, 2, m, &cDelay_8FnyJ1iH_sendMessage);
}

void Heavy_SoundScraper::cBinop_liAjgoXe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_KKCHol03_sendMessage);
}

void Heavy_SoundScraper::cCast_HtVf5O1s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_K4ETKfTt, 0, m, &cVar_K4ETKfTt_sendMessage);
  cMsg_0Iq9JqYI_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_GAXQJEnH, 0, m, &cTabhead_GAXQJEnH_sendMessage);
}

void Heavy_SoundScraper::cMsg_mAhrk9cQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_zMLxijNg_sendMessage);
}

void Heavy_SoundScraper::cSystem_zMLxijNg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_4DsSa1aD_sendMessage);
}

void Heavy_SoundScraper::cDelay_Zy3ArC5r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Zy3ArC5r, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_VJCjXGVd, 0, m, &cDelay_VJCjXGVd_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Zy3ArC5r, 0, m, &cDelay_Zy3ArC5r_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_q1nfTchJ, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_VJCjXGVd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_VJCjXGVd, m);
  cMsg_rvB9eLSI_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_P9BAPlSF_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_1GXYDxqc_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_kEngkQF3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_EGftUm0w_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_eI9c7xE2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ZAGm4Ov5_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Zy3ArC5r, 2, m, &cDelay_Zy3ArC5r_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_zNJFbCcm_sendMessage);
}

void Heavy_SoundScraper::cMsg_EGftUm0w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_eI9c7xE2, 0, m, &hTable_eI9c7xE2_sendMessage);
}

void Heavy_SoundScraper::cBinop_4DsSa1aD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 43.5337f, 0, m, &cBinop_kEngkQF3_sendMessage);
}

void Heavy_SoundScraper::cMsg_rvB9eLSI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_eI9c7xE2, 0, m, &hTable_eI9c7xE2_sendMessage);
}

void Heavy_SoundScraper::cCast_zNJFbCcm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Zy3ArC5r, 0, m, &cDelay_Zy3ArC5r_sendMessage);
}

void Heavy_SoundScraper::cMsg_ZAGm4Ov5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_VJCjXGVd, 2, m, &cDelay_VJCjXGVd_sendMessage);
}

void Heavy_SoundScraper::cMsg_1GXYDxqc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_q1nfTchJ, 1, m, NULL);
}

void Heavy_SoundScraper::cTabhead_9kylz7eQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_KapXdUVY, HV_BINOP_SUBTRACT, 0, m, &cBinop_KapXdUVY_sendMessage);
}

void Heavy_SoundScraper::cMsg_Cvu1unzn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_oV1SUrnX_sendMessage);
}

void Heavy_SoundScraper::cSystem_oV1SUrnX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_aDkKgqk8_sendMessage);
}

void Heavy_SoundScraper::cVar_TMIyXNEM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Iy3bpgr0_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_7Lq1eEXe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_7Lq1eEXe, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Ie98y6HT, 0, m, &cDelay_Ie98y6HT_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_bYPtTgj3, 0, m, &sTabread_bYPtTgj3_sendMessage);
}

void Heavy_SoundScraper::cDelay_Ie98y6HT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Ie98y6HT, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_bYPtTgj3, 0, m, &sTabread_bYPtTgj3_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Ie98y6HT, 0, m, &cDelay_Ie98y6HT_sendMessage);
}

void Heavy_SoundScraper::sTabread_bYPtTgj3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_v4PJA7Zb, HV_BINOP_SUBTRACT, 0, m, &cBinop_v4PJA7Zb_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_k3txeQT5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_nWMSlIBL, HV_BINOP_MAX, 0, m, &cBinop_nWMSlIBL_sendMessage);
}

void Heavy_SoundScraper::cBinop_aDkKgqk8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_k3txeQT5, HV_BINOP_MULTIPLY, 0, m, &cBinop_k3txeQT5_sendMessage);
}

void Heavy_SoundScraper::cBinop_KapXdUVY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_bTqKyzKI_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_bYPtTgj3, 0, m, &sTabread_bYPtTgj3_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_oHlDO9Sm_sendMessage);
}

void Heavy_SoundScraper::cSystem_gHWYabpq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_v4PJA7Zb, HV_BINOP_SUBTRACT, 1, m, &cBinop_v4PJA7Zb_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Ie98y6HT, 2, m, &cDelay_Ie98y6HT_sendMessage);
}

void Heavy_SoundScraper::cMsg_Iy3bpgr0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_gHWYabpq_sendMessage);
}

void Heavy_SoundScraper::cMsg_bTqKyzKI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_7Lq1eEXe, 0, m, &cDelay_7Lq1eEXe_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Ie98y6HT, 0, m, &cDelay_Ie98y6HT_sendMessage);
}

void Heavy_SoundScraper::cMsg_6GBJUgrS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_nWMSlIBL, HV_BINOP_MAX, 1, m, &cBinop_nWMSlIBL_sendMessage);
}

void Heavy_SoundScraper::cBinop_nWMSlIBL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_KapXdUVY, HV_BINOP_SUBTRACT, 1, m, &cBinop_KapXdUVY_sendMessage);
}

void Heavy_SoundScraper::cCast_oHlDO9Sm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_7Lq1eEXe, 0, m, &cDelay_7Lq1eEXe_sendMessage);
}

void Heavy_SoundScraper::cBinop_cLX9jb35_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_7Lq1eEXe, 2, m, &cDelay_7Lq1eEXe_sendMessage);
}

void Heavy_SoundScraper::cBinop_v4PJA7Zb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_cLX9jb35_sendMessage);
}

void Heavy_SoundScraper::cCast_zjeiomOV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_TMIyXNEM, 0, m, &cVar_TMIyXNEM_sendMessage);
  cMsg_Cvu1unzn_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_9kylz7eQ, 0, m, &cTabhead_9kylz7eQ_sendMessage);
}

void Heavy_SoundScraper::cMsg_CzbKNESY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_thLVKD0A_sendMessage);
}

void Heavy_SoundScraper::cSystem_thLVKD0A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_JhZph4Ua_sendMessage);
}

void Heavy_SoundScraper::cDelay_RNZRVaiV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_RNZRVaiV, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_to4qf1lP, 0, m, &cDelay_to4qf1lP_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_RNZRVaiV, 0, m, &cDelay_RNZRVaiV_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_3OdrNL5D, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_to4qf1lP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_to4qf1lP, m);
  cMsg_4aWEOHu2_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_pRLd82WA_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_AbAIZWqp_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_dYJnoOCz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_OmnENJxD_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_Vl2XxejY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_jM2CDddd_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_RNZRVaiV, 2, m, &cDelay_RNZRVaiV_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Yv7aOc5Y_sendMessage);
}

void Heavy_SoundScraper::cMsg_OmnENJxD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_Vl2XxejY, 0, m, &hTable_Vl2XxejY_sendMessage);
}

void Heavy_SoundScraper::cBinop_JhZph4Ua_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 75.2546f, 0, m, &cBinop_dYJnoOCz_sendMessage);
}

void Heavy_SoundScraper::cMsg_4aWEOHu2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_Vl2XxejY, 0, m, &hTable_Vl2XxejY_sendMessage);
}

void Heavy_SoundScraper::cCast_Yv7aOc5Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_RNZRVaiV, 0, m, &cDelay_RNZRVaiV_sendMessage);
}

void Heavy_SoundScraper::cMsg_jM2CDddd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_to4qf1lP, 2, m, &cDelay_to4qf1lP_sendMessage);
}

void Heavy_SoundScraper::cMsg_AbAIZWqp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_3OdrNL5D, 1, m, NULL);
}

void Heavy_SoundScraper::cVar_olUdTNuo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_nTONyhq2, 0, m, &cVar_nTONyhq2_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_jsAL57BZ, 0, m, &cVar_jsAL57BZ_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_1JCAOllX, 0, m, &cVar_1JCAOllX_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_AwjOhgqW, 0, m, &cVar_AwjOhgqW_sendMessage);
}

void Heavy_SoundScraper::cVar_eSLj9Q2y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.01f, 0, m, &cBinop_PBT6ERAV_sendMessage);
}

void Heavy_SoundScraper::cPack_40qDVDwB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_glSWgFyi, 0, m, NULL);
}

void Heavy_SoundScraper::cVar_jsAL57BZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_mmzPTI9P, HV_BINOP_MULTIPLY, 0, m, &cBinop_mmzPTI9P_sendMessage);
}

void Heavy_SoundScraper::cMsg_cSiIM8Ri_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_MlAEuO5B_sendMessage);
}

void Heavy_SoundScraper::cSystem_MlAEuO5B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_HgYoAWcZ_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_mmzPTI9P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_7tJXXN5s_sendMessage);
}

void Heavy_SoundScraper::cBinop_Jfo8UUbY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_mmzPTI9P, HV_BINOP_MULTIPLY, 1, m, &cBinop_mmzPTI9P_sendMessage);
}

void Heavy_SoundScraper::cMsg_HgYoAWcZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_Jfo8UUbY_sendMessage);
}

void Heavy_SoundScraper::cBinop_7tJXXN5s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_S3H41bnx_sendMessage);
}

void Heavy_SoundScraper::cBinop_S3H41bnx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_Lm6STXwP_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_k5uaGEKM, m);
}

void Heavy_SoundScraper::cBinop_Lm6STXwP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_HavsYL9f, m);
}

void Heavy_SoundScraper::cVar_1JCAOllX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_GLfmJiS7, HV_BINOP_MULTIPLY, 0, m, &cBinop_GLfmJiS7_sendMessage);
}

void Heavy_SoundScraper::cMsg_L9uvvk40_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_wrVVW3pL_sendMessage);
}

void Heavy_SoundScraper::cSystem_wrVVW3pL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_53Ynwh3y_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_GLfmJiS7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_R3qxiQwp_sendMessage);
}

void Heavy_SoundScraper::cBinop_O64ZbUVd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_GLfmJiS7, HV_BINOP_MULTIPLY, 1, m, &cBinop_GLfmJiS7_sendMessage);
}

void Heavy_SoundScraper::cMsg_53Ynwh3y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_O64ZbUVd_sendMessage);
}

void Heavy_SoundScraper::cBinop_R3qxiQwp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_mabJkFWZ_sendMessage);
}

void Heavy_SoundScraper::cBinop_mabJkFWZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_58zO90ZQ_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_xod8zom1, m);
}

void Heavy_SoundScraper::cBinop_58zO90ZQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_aYIMPjPM, m);
}

void Heavy_SoundScraper::cVar_AwjOhgqW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_c2O730QV, HV_BINOP_MULTIPLY, 0, m, &cBinop_c2O730QV_sendMessage);
}

void Heavy_SoundScraper::cMsg_QNe66DAZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_HS7p1ZcU_sendMessage);
}

void Heavy_SoundScraper::cSystem_HS7p1ZcU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_8teSlqfQ_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_c2O730QV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_c4X3xLkM_sendMessage);
}

void Heavy_SoundScraper::cBinop_wJJPw82d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_c2O730QV, HV_BINOP_MULTIPLY, 1, m, &cBinop_c2O730QV_sendMessage);
}

void Heavy_SoundScraper::cMsg_8teSlqfQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_wJJPw82d_sendMessage);
}

void Heavy_SoundScraper::cBinop_c4X3xLkM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_CvVKEfnr_sendMessage);
}

void Heavy_SoundScraper::cBinop_CvVKEfnr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_MJ5hGdyx_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_06XvneXY, m);
}

void Heavy_SoundScraper::cBinop_MJ5hGdyx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_9sZMKgF4, m);
}

void Heavy_SoundScraper::cBinop_kWFyhfKQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_QncVoE9J, 0, m, &cPack_QncVoE9J_sendMessage);
}

void Heavy_SoundScraper::cMsg_sUXG5Pd4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 3000.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_olUdTNuo, 0, m, &cVar_olUdTNuo_sendMessage);
}

void Heavy_SoundScraper::cBinop_PBT6ERAV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_40qDVDwB, 0, m, &cPack_40qDVDwB_sendMessage);
}

void Heavy_SoundScraper::cBinop_OC8KP6NP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_egjSAywK, 0, m, &cPack_egjSAywK_sendMessage);
}

void Heavy_SoundScraper::cMsg_hP7iHCq9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ddnHI1Do_sendMessage);
}

void Heavy_SoundScraper::cSystem_ddnHI1Do_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_8V3DUvzN_sendMessage);
}

void Heavy_SoundScraper::cVar_RQaLlKs2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_4moomG7r_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSystem_vh99OXr4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_K8ULvuYo_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_t984n1aS, m);
}

void Heavy_SoundScraper::cBinop_8V3DUvzN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_EtKtBAFO, m);
}

void Heavy_SoundScraper::cMsg_4moomG7r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_vh99OXr4_sendMessage);
}

void Heavy_SoundScraper::cBinop_K8ULvuYo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_DuKdmKRX, m);
}

void Heavy_SoundScraper::cVar_3tw4OpaD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_7e6oKO6t, HV_BINOP_MULTIPLY, 0, m, &cBinop_7e6oKO6t_sendMessage);
}

void Heavy_SoundScraper::cMsg_oUydOvFz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_5PXgJdnB_sendMessage);
}

void Heavy_SoundScraper::cSystem_5PXgJdnB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ly5o2hva_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_7e6oKO6t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_ARdjDmVv_sendMessage);
}

void Heavy_SoundScraper::cBinop_RyVsPnIc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_7e6oKO6t, HV_BINOP_MULTIPLY, 1, m, &cBinop_7e6oKO6t_sendMessage);
}

void Heavy_SoundScraper::cMsg_ly5o2hva_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_RyVsPnIc_sendMessage);
}

void Heavy_SoundScraper::cBinop_ARdjDmVv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_2eLPzbzQ_sendMessage);
}

void Heavy_SoundScraper::cBinop_2eLPzbzQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_arkJDaFn_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_ENoVCC2J, m);
}

void Heavy_SoundScraper::cBinop_arkJDaFn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_LRNq5qN4, m);
}

void Heavy_SoundScraper::cBinop_kDZ1vEuS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, -1.0f, 0, m, &cBinop_fFYpJOMw_sendMessage);
}

void Heavy_SoundScraper::cBinop_fFYpJOMw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_cbs2aAnN, m);
}

void Heavy_SoundScraper::cBinop_jgPrCXzu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_LgMlvhGt_sendMessage);
}

void Heavy_SoundScraper::cBinop_LgMlvhGt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_0xsTbeYg_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_S5ceNc6R_sendMessage);
}

void Heavy_SoundScraper::cVar_RkW1iRG7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_uYi2cprt_sendMessage);
}

void Heavy_SoundScraper::cMsg_4EsIxroQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_c5gqGaiq_sendMessage);
}

void Heavy_SoundScraper::cSystem_c5gqGaiq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_cEmO8IDD, HV_BINOP_DIVIDE, 1, m, &cBinop_cEmO8IDD_sendMessage);
}

void Heavy_SoundScraper::cBinop_0xsTbeYg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_jfjVbZrh_sendMessage);
}

void Heavy_SoundScraper::cBinop_jfjVbZrh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_dyLctu6G, m);
}

void Heavy_SoundScraper::cMsg_XKD9KQKp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_fCvvXnic_sendMessage);
}

void Heavy_SoundScraper::cBinop_fCvvXnic_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_jgPrCXzu_sendMessage);
}

void Heavy_SoundScraper::cBinop_S5ceNc6R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_qch2Y6GQ, m);
}

void Heavy_SoundScraper::cBinop_uYi2cprt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_rWCQu2ft_sendMessage);
}

void Heavy_SoundScraper::cBinop_rWCQu2ft_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_cEmO8IDD, HV_BINOP_DIVIDE, 0, m, &cBinop_cEmO8IDD_sendMessage);
}

void Heavy_SoundScraper::cBinop_cEmO8IDD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_XKD9KQKp_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_AKnfDmur_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_SyuvUXJo_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_YTKVN9bm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ojuXCcKz_sendMessage);
}

void Heavy_SoundScraper::cSystem_ojuXCcKz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_fJYYSatn_sendMessage);
}

void Heavy_SoundScraper::cDelay_mMUpGRAU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_mMUpGRAU, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_l3shmK9h, 0, m, &cDelay_l3shmK9h_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_mMUpGRAU, 0, m, &cDelay_mMUpGRAU_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_Pb6uuJkx, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_l3shmK9h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_l3shmK9h, m);
  cMsg_RsKwIVwm_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_yIpoJHQy_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_aD8E5Ff9_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_Y3E77no3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ZRz5Snuz_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_Vs9lEBjn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_QDHTMgkR_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_mMUpGRAU, 2, m, &cDelay_mMUpGRAU_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_FKIggowL_sendMessage);
}

void Heavy_SoundScraper::cMsg_ZRz5Snuz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_Vs9lEBjn, 0, m, &hTable_Vs9lEBjn_sendMessage);
}

void Heavy_SoundScraper::cBinop_fJYYSatn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 500.0f, 0, m, &cBinop_Y3E77no3_sendMessage);
}

void Heavy_SoundScraper::cMsg_RsKwIVwm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_Vs9lEBjn, 0, m, &hTable_Vs9lEBjn_sendMessage);
}

void Heavy_SoundScraper::cCast_FKIggowL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_mMUpGRAU, 0, m, &cDelay_mMUpGRAU_sendMessage);
}

void Heavy_SoundScraper::cMsg_QDHTMgkR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_l3shmK9h, 2, m, &cDelay_l3shmK9h_sendMessage);
}

void Heavy_SoundScraper::cMsg_aD8E5Ff9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_Pb6uuJkx, 1, m, NULL);
}

void Heavy_SoundScraper::cMsg_9RFFDacD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cMsg_SyuvUXJo_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_SyuvUXJo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 20.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_2mLrveBd, 0, m, NULL);
}

void Heavy_SoundScraper::cPack_29XfAuyN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_tk8fsAw0, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_8oUduTPt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_OJbJtB0B_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_OwqYPTRt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_29XfAuyN, 0, m, &cPack_29XfAuyN_sendMessage);
}

void Heavy_SoundScraper::cMsg_Z1AxSLqo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 500.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_tk8fsAw0, 0, m, NULL);
}

void Heavy_SoundScraper::cMsg_EAFHDxRL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 500.0f);
  sVarf_onMessage(_c, &Context(_c)->sVarf_7lvNK8gW, m);
}

void Heavy_SoundScraper::cMsg_c34so8u0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.3f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_kDZ1vEuS_sendMessage);
}

void Heavy_SoundScraper::cVar_pFlPyHAq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_h4XWmhip_sendMessage);
}

void Heavy_SoundScraper::cBinop_h4XWmhip_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_pFlPyHAq, 1, m, &cVar_pFlPyHAq_sendMessage);
}

void Heavy_SoundScraper::cPack_sLD6VSmq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_PE54GZBr, 0, m, NULL);
}

void Heavy_SoundScraper::cSwitchcase_QlsArFiD_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_2ODEHdlV, 0, m, &cSlice_2ODEHdlV_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_W1fSSohl, 0, m, &cRandom_W1fSSohl_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_p3VPkJPm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_TnqNPAn4_sendMessage);
}

void Heavy_SoundScraper::cUnop_TnqNPAn4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 25.0f, 0, m, &cBinop_utE91h3f_sendMessage);
}

void Heavy_SoundScraper::cRandom_W1fSSohl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 30.0f, 0, m, &cBinop_p3VPkJPm_sendMessage);
}

void Heavy_SoundScraper::cSlice_2ODEHdlV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_W1fSSohl, 1, m, &cRandom_W1fSSohl_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSwitchcase_crHEFJ7N_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_9vtHRgTX, 0, m, &cSlice_9vtHRgTX_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_anyNpluQ, 0, m, &cRandom_anyNpluQ_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_9RSxBwpA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_NxAZpMJ1_sendMessage);
}

void Heavy_SoundScraper::cUnop_NxAZpMJ1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 10.0f, 0, m, &cBinop_CmeFaDsA_sendMessage);
}

void Heavy_SoundScraper::cRandom_anyNpluQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 40.0f, 0, m, &cBinop_9RSxBwpA_sendMessage);
}

void Heavy_SoundScraper::cSlice_9vtHRgTX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_anyNpluQ, 1, m, &cRandom_anyNpluQ_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSwitchcase_xyjCT36g_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_ehYYPh94, 0, m, &cSlice_ehYYPh94_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_GkNej76Y, 0, m, &cRandom_GkNej76Y_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_50DX56tC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_mOGCQdIY_sendMessage);
}

void Heavy_SoundScraper::cUnop_mOGCQdIY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_MHU7TsoO_sendMessage);
}

void Heavy_SoundScraper::cRandom_GkNej76Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 100.0f, 0, m, &cBinop_50DX56tC_sendMessage);
}

void Heavy_SoundScraper::cSlice_ehYYPh94_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_GkNej76Y, 1, m, &cRandom_GkNej76Y_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cPack_uOA5F3Gy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPrint_onMessage(_c, m, "SCRAPER_RESET");
}

void Heavy_SoundScraper::cBinop_utE91h3f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_lDEE3nid_sendMessage(_c, 0, m);
  cPack_onMessage(_c, &Context(_c)->cPack_uOA5F3Gy, 1, m, &cPack_uOA5F3Gy_sendMessage);
}

void Heavy_SoundScraper::cBinop_CmeFaDsA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_uc5IIrcR_sendMessage(_c, 0, m);
  cPack_onMessage(_c, &Context(_c)->cPack_uOA5F3Gy, 0, m, &cPack_uOA5F3Gy_sendMessage);
}

void Heavy_SoundScraper::cBinop_MHU7TsoO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_sAwgHwiG_sendMessage(_c, 0, m);
  cPack_onMessage(_c, &Context(_c)->cPack_uOA5F3Gy, 2, m, &cPack_uOA5F3Gy_sendMessage);
}

void Heavy_SoundScraper::cCast_tvnIJxdg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_crHEFJ7N_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_W2f1VAuJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_suAxpCEP_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_vHRz6WjI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_xyjCT36g_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_ZT1HN0xD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_QlsArFiD_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cMsg_suAxpCEP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSend_dNI33NYk_sendMessage(_c, 0, m);
  cPack_onMessage(_c, &Context(_c)->cPack_uOA5F3Gy, 3, m, &cPack_uOA5F3Gy_sendMessage);
}

void Heavy_SoundScraper::cSend_dNI33NYk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_fYbtdYAQ_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_sAwgHwiG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_DsOxX40y_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_uc5IIrcR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cSend_lDEE3nid_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_yKuRHk4T_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_kGooD0FO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_dg0Mu6Gt_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_4AY27DI0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_w6mU6KDZ_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_WG9fhHEz_sendMessage);
}

void Heavy_SoundScraper::cIf_cvgDPIIQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_yqDHk01Z_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 440.0f, 0, m, &cBinop_R9KCkgpm_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cUnop_O3ho8L44_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 12.0f, 0, m, &cBinop_4B5C8IcE_sendMessage);
}

void Heavy_SoundScraper::cBinop_R9KCkgpm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_LOG2, m, &cUnop_O3ho8L44_sendMessage);
}

void Heavy_SoundScraper::cBinop_4B5C8IcE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 69.0f, 0, m, &cBinop_EfM8OMma_sendMessage);
}

void Heavy_SoundScraper::cBinop_EfM8OMma_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_M80MQmAb, 0, m, &cVar_M80MQmAb_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_rJQyfo0R, HV_BINOP_SUBTRACT, 1, m, &cBinop_rJQyfo0R_sendMessage);
}

void Heavy_SoundScraper::cCast_w6mU6KDZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_yzEIshgT_sendMessage);
}

void Heavy_SoundScraper::cCast_WG9fhHEz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_cvgDPIIQ, 0, m, &cIf_cvgDPIIQ_sendMessage);
}

void Heavy_SoundScraper::cBinop_yzEIshgT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_cvgDPIIQ, 1, m, &cIf_cvgDPIIQ_sendMessage);
}

void Heavy_SoundScraper::cMsg_yqDHk01Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, -1500.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_M80MQmAb, 0, m, &cVar_M80MQmAb_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_rJQyfo0R, HV_BINOP_SUBTRACT, 1, m, &cBinop_rJQyfo0R_sendMessage);
}

void Heavy_SoundScraper::cVar_M80MQmAb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cCast_JsG36uhK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_rJQyfo0R, HV_BINOP_SUBTRACT, 0, m, &cBinop_rJQyfo0R_sendMessage);
}

void Heavy_SoundScraper::cBinop_2xrIyTtO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_kGooD0FO, 0, m, &cVar_kGooD0FO_sendMessage);
}

void Heavy_SoundScraper::cBinop_n0bkUSfw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_2xrIyTtO, HV_BINOP_ADD, 1, m, &cBinop_2xrIyTtO_sendMessage);
}

void Heavy_SoundScraper::cBinop_rJQyfo0R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_2xrIyTtO, HV_BINOP_ADD, 0, m, &cBinop_2xrIyTtO_sendMessage);
}

void Heavy_SoundScraper::cSend_dg0Mu6Gt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_jW0BSIiH_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_fbPFgG8O_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3F800000: { // "1.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_02amxWQc, 0, m, &cSlice_02amxWQc_sendMessage);
      break;
    }
    case 0x0: { // "0.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_2BuwMAsK, 0, m, &cSlice_2BuwMAsK_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cSlice_02amxWQc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Cm657kwa_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Cm657kwa_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_2BuwMAsK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_SgFEptS6_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_fYtiAieF_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_SgFEptS6_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_fYtiAieF_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cVar_Gg6rijWZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_U7y31pL0, HV_BINOP_MULTIPLY, 0, m, &cBinop_U7y31pL0_sendMessage);
}

void Heavy_SoundScraper::cMsg_vHqbUn1k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_JZFmX7QR_sendMessage);
}

void Heavy_SoundScraper::cSystem_JZFmX7QR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_PBmCWSk1_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_U7y31pL0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_kLQcP1Sx_sendMessage);
}

void Heavy_SoundScraper::cBinop_KsQzekK2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_U7y31pL0, HV_BINOP_MULTIPLY, 1, m, &cBinop_U7y31pL0_sendMessage);
}

void Heavy_SoundScraper::cMsg_PBmCWSk1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_KsQzekK2_sendMessage);
}

void Heavy_SoundScraper::cBinop_kLQcP1Sx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_CwNwcB1d_sendMessage);
}

void Heavy_SoundScraper::cBinop_CwNwcB1d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_O0pUVodL_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_pOB2J8iV, m);
}

void Heavy_SoundScraper::cBinop_O0pUVodL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_DGrLtH6g, m);
}

void Heavy_SoundScraper::cSlice_lkIyh1d5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSend_u5VyaAlU_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_HB6epsln_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSend_sK5FGYTs_sendMessage(_c, 0, m);
      cPrint_onMessage(_c, m, "SCRAPER_TAB");
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cMsg_1pqQZTXk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSend_G2LxHi4f_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_G2LxHi4f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_jW0BSIiH_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_GzkWkiHu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_DsOxX40y_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_DuAzdA1p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 5.0f);
  cSend_GzkWkiHu_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_uJFTeGbP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 44100.0f);
  cSend_anZSLPxu_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_anZSLPxu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cMsg_Tff7oeDH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSend_S3OQCo9J_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_S3OQCo9J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_UuGL7T2H_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_AWnjMoID_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_56YfstRe_sendMessage);
}

void Heavy_SoundScraper::cBinop_56YfstRe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_jz96V042_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_m3DamNWK_sendMessage);
}

void Heavy_SoundScraper::cVar_5xHICv36_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_8gF4UCV5_sendMessage);
}

void Heavy_SoundScraper::cMsg_aReGxXuR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_qqOLWZEF_sendMessage);
}

void Heavy_SoundScraper::cSystem_qqOLWZEF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ijhFmPJ9, HV_BINOP_DIVIDE, 1, m, &cBinop_ijhFmPJ9_sendMessage);
}

void Heavy_SoundScraper::cBinop_jz96V042_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_yjSlabMJ_sendMessage);
}

void Heavy_SoundScraper::cBinop_yjSlabMJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_h6JxsK9j, m);
}

void Heavy_SoundScraper::cMsg_zuBcugzt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_fXloOeUi_sendMessage);
}

void Heavy_SoundScraper::cBinop_fXloOeUi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_AWnjMoID_sendMessage);
}

void Heavy_SoundScraper::cBinop_m3DamNWK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_R5EWxVIc, m);
}

void Heavy_SoundScraper::cBinop_8gF4UCV5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_juqqHEKh_sendMessage);
}

void Heavy_SoundScraper::cBinop_juqqHEKh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ijhFmPJ9, HV_BINOP_DIVIDE, 0, m, &cBinop_ijhFmPJ9_sendMessage);
}

void Heavy_SoundScraper::cBinop_ijhFmPJ9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_zuBcugzt_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::sSample_uvES4F4q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_GULKZKTG, 0, m, &cVar_GULKZKTG_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_d07eZUvN_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_ACHBbY09_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_ACHBbY09_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_47y7V84o, 1, m, &cDelay_47y7V84o_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_qyih9BgA_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cDelay_47y7V84o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_47y7V84o, m);
  sSample_onMessage(_c, &Context(_c)->sSample_uvES4F4q, 1, m);
}

void Heavy_SoundScraper::cMsg_ACHBbY09_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_47y7V84o, 0, m, &cDelay_47y7V84o_sendMessage);
}

void Heavy_SoundScraper::cCast_qyih9BgA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_47y7V84o, 0, m, &cDelay_47y7V84o_sendMessage);
}

void Heavy_SoundScraper::cVar_GULKZKTG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPrint_onMessage(_c, m, "SCRAPER_SIG");
}

void Heavy_SoundScraper::cCast_ZTo6PjDR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sSample_onMessage(_c, &Context(_c)->sSample_uvES4F4q, 1, m);
}

void Heavy_SoundScraper::cSwitchcase_2CjnURVV_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_X3M93h4T_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_X3M93h4T_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_XsUg7GTr, 1, m, &cDelay_XsUg7GTr_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_7PSTukas_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cDelay_XsUg7GTr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_XsUg7GTr, m);
  sSample_onMessage(_c, &Context(_c)->sSample_uvES4F4q, 1, m);
}

void Heavy_SoundScraper::cMsg_X3M93h4T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_XsUg7GTr, 0, m, &cDelay_XsUg7GTr_sendMessage);
}

void Heavy_SoundScraper::cCast_7PSTukas_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_XsUg7GTr, 0, m, &cDelay_XsUg7GTr_sendMessage);
}

void Heavy_SoundScraper::cVar_DTpbSWDG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 44.1f, 0, m, &cBinop_C3HshOHe_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_ZCI6XWS0_sendMessage);
}

void Heavy_SoundScraper::cVar_2vwaBkTe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 44.1f, 0, m, &cBinop_QNRGHRZ2_sendMessage);
}

void Heavy_SoundScraper::cVar_R2CgXvGG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cExpr_onMessage(_c, &Context(_c)->cExpr_2jBKcYU2, 0, m, &cExpr_2jBKcYU2_sendMessage);
}

void Heavy_SoundScraper::cExpr_2jBKcYU2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_5je1f1ZB, HV_BINOP_DIVIDE, 0, m, &cBinop_5je1f1ZB_sendMessage);
}

float Heavy_SoundScraper::cExpr_2jBKcYU2_evaluate(const float* args) {
  	return hv_pow_f(2 , ((float)(args[0]))/1200);
}

void Heavy_SoundScraper::cVar_UMwRnK03_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_a7DCv1VX, 0, m);
}

void Heavy_SoundScraper::cMsg_jCdgkcIx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSend_nbiN65Rz_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_cQCyIJFJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSend_GznYmOnN_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_668YZlko_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 100.0f);
  cSend_K76EJZSv_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_nbiN65Rz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_CLqUCZ3N_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_GznYmOnN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_do9XHRQM_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_K76EJZSv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_2rJDeVKt_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_m36CtkJV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_DTpbSWDG, 0, m, &cVar_DTpbSWDG_sendMessage);
}

void Heavy_SoundScraper::cVar_2wqMA3Qb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_2vwaBkTe, 0, m, &cVar_2vwaBkTe_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_GhZLvw2Z_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_pYCeGFll, 0, m, &cSlice_pYCeGFll_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cVar_BvSLDSzN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_R0u8BlKf_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSystem_kfQ4jmmu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 2.0f, 0, m, &cBinop_5vWtnMVz_sendMessage);
}

void Heavy_SoundScraper::cBinop_5vWtnMVz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_tnfrMHs2, m);
}

void Heavy_SoundScraper::cMsg_R0u8BlKf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_kfQ4jmmu_sendMessage);
}

void Heavy_SoundScraper::cSlice_pYCeGFll_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sTabread_onMessage(_c, &Context(_c)->sTabread_ckBmIu1s, 1, m, NULL);
      sTabread_onMessage(_c, &Context(_c)->sTabread_ENryHyQb, 1, m, NULL);
      cVar_onMessage(_c, &Context(_c)->cVar_BvSLDSzN, 0, m, &cVar_BvSLDSzN_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSwitchcase_dS7SFl6g_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_MlzfkOd6, 0, m, &cSlice_MlzfkOd6_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cVar_hs3RJH8f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_6Qhoq3IB_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSystem_Tlmo4mRZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 2.0f, 0, m, &cBinop_tkjmyAxO_sendMessage);
}

void Heavy_SoundScraper::cBinop_tkjmyAxO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_2S2rbbGI, m);
}

void Heavy_SoundScraper::cMsg_6Qhoq3IB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Tlmo4mRZ_sendMessage);
}

void Heavy_SoundScraper::cSlice_MlzfkOd6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sTabread_onMessage(_c, &Context(_c)->sTabread_C9ecPpbq, 1, m, NULL);
      sTabread_onMessage(_c, &Context(_c)->sTabread_Th7thTkq, 1, m, NULL);
      cVar_onMessage(_c, &Context(_c)->cVar_hs3RJH8f, 0, m, &cVar_hs3RJH8f_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cCast_o9hYs7Wl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_5je1f1ZB, HV_BINOP_DIVIDE, 1, m, &cBinop_5je1f1ZB_sendMessage);
}

void Heavy_SoundScraper::cCast_Dc8zYbQN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_5je1f1ZB, HV_BINOP_DIVIDE, 0, m, &cBinop_5je1f1ZB_sendMessage);
}

void Heavy_SoundScraper::cBinop_5je1f1ZB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_UMwRnK03, 0, m, &cVar_UMwRnK03_sendMessage);
}

void Heavy_SoundScraper::cBinop_C3HshOHe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_7fEpMC6b_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_QNRGHRZ2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_PtH2KJAm_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_ZCI6XWS0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_7NNKmXVw_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_7NNKmXVw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_8ROaVYr0_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_7fEpMC6b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_m5hw2QJU_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_PtH2KJAm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_FX6TpWuY_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_uIXeIgVO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSwitchcase_dS7SFl6g_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cSend_Cu10YFdk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_pU9JNKCf_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_jl1AGciR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSwitchcase_GhZLvw2Z_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::hTable_ENQ9TLFR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cSend_XuhMGFSE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_if9dP39u_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_mhIFklNJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_UuGL7T2H_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_VXCMyf1c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_Zooi0MsG_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_nk869IN9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_pl4thiSB_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_r3g4EfU8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_fYbtdYAQ_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_wFFkaZIL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_7WGdK6i7_sendMessage);
}

void Heavy_SoundScraper::cBinop_7WGdK6i7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_sLD6VSmq, 0, m, &cPack_sLD6VSmq_sendMessage);
}

void Heavy_SoundScraper::cSend_chvq8Co6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_pl4thiSB_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_dqVM2dCJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_dFOpWous_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_6CuJ4iMm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_8uy8pCnV_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_Cm657kwa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_dqVM2dCJ_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_1GfYNNFV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cPrint_onMessage(_c, m, "SCRAPER_RUNNING");
  sVarf_onMessage(_c, &Context(_c)->sVarf_ui2z5bvS, m);
}

void Heavy_SoundScraper::cMsg_PKWmcieK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPrint_onMessage(_c, m, "SCRAPER_RUNNING");
  sVarf_onMessage(_c, &Context(_c)->sVarf_ui2z5bvS, m);
}

void Heavy_SoundScraper::cSend_sK5FGYTs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_KYtdp8Cr_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_u5VyaAlU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_WsASZSZc_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_fYtiAieF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_6CuJ4iMm_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_SgFEptS6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_chvq8Co6_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_OniMkjAW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_2vwaBkTe, 0, m, &cVar_2vwaBkTe_sendMessage);
}

void Heavy_SoundScraper::cBinop_so1f10Zy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_DTpbSWDG, 0, m, &cVar_DTpbSWDG_sendMessage);
}

void Heavy_SoundScraper::cBinop_Wz67Ylzr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cExpr_onMessage(_c, &Context(_c)->cExpr_2jBKcYU2, 0, m, &cExpr_2jBKcYU2_sendMessage);
}

void Heavy_SoundScraper::cReceive_xnnDkUgV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_U63jsgqi, 0, m, &cPack_U63jsgqi_sendMessage);
}

void Heavy_SoundScraper::cReceive_JaZN56v9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_U63jsgqi, 1, m, &cPack_U63jsgqi_sendMessage);
}

void Heavy_SoundScraper::cReceive_j1FDTCrp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPrint_onMessage(_c, m, "SET_TABLE");
  cSlice_onMessage(_c, &Context(_c)->cSlice_xH1PcvAO, 0, m, &cSlice_xH1PcvAO_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_uixhqqOG, 0, m, &cSlice_uixhqqOG_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_v4S319M7, 0, m, &cSlice_v4S319M7_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_qtZG4vQY, 0, m, &cSlice_qtZG4vQY_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_JpbPnq7o, 0, m, &cSlice_JpbPnq7o_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_TrBGFBQn, 0, m, &cSlice_TrBGFBQn_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_qBXnUcR4, 0, m, &cSlice_qBXnUcR4_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_cSjjEiCm, 0, m, &cSlice_cSjjEiCm_sendMessage);
  cSend_VXCMyf1c_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cReceive_COMiAszK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_mhIFklNJ_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cReceive_UO2GPTgP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_XuhMGFSE_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cReceive_a54R3rPR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_pFlPyHAq, 0, m, &cVar_pFlPyHAq_sendMessage);
  cSwitchcase_fbPFgG8O_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cReceive_imFvNAYz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_r3g4EfU8_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cReceive_RTjz4diq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_nk869IN9_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cReceive_VOzSTOIU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_uJoq1tDo_sendMessage(_c, 0, m);
  cMsg_70xFmzrz_sendMessage(_c, 0, m);
  cMsg_ruJUcsa0_sendMessage(_c, 0, m);
  cMsg_HuOuhHJA_sendMessage(_c, 0, m);
  cMsg_mAhrk9cQ_sendMessage(_c, 0, m);
  cMsg_CzbKNESY_sendMessage(_c, 0, m);
  cMsg_eacOvbsV_sendMessage(_c, 0, m);
  cMsg_PqSxkbUk_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_1OAzPySG, 0, m, &cVar_1OAzPySG_sendMessage);
  cMsg_taZczRJi_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_JFI1M2Kw, 0, m, &cVar_JFI1M2Kw_sendMessage);
  cMsg_U8SSk7at_sendMessage(_c, 0, m);
  cMsg_4CIbfUeX_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_iIjBEoKw, 0, m, &cVar_iIjBEoKw_sendMessage);
  cMsg_iyXPLXkX_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_9PxGGMkN, 0, m, &cVar_9PxGGMkN_sendMessage);
  cMsg_p0iVO1WG_sendMessage(_c, 0, m);
  cMsg_MMyqEwPY_sendMessage(_c, 0, m);
  cMsg_q1CxEIxM_sendMessage(_c, 0, m);
  cMsg_A0xPNonJ_sendMessage(_c, 0, m);
  cMsg_pmKKuiG2_sendMessage(_c, 0, m);
  cMsg_FF6JJ0Wk_sendMessage(_c, 0, m);
  cMsg_usvefzxV_sendMessage(_c, 0, m);
  cMsg_QbpKhrss_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_wuOfDgb2, 0, m, &cVar_wuOfDgb2_sendMessage);
  cMsg_WK9gnN8v_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_ODgcRrf1, 0, m, &cVar_ODgcRrf1_sendMessage);
  cMsg_19jH6Trp_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_v3sA9HUq, 0, m, &cVar_v3sA9HUq_sendMessage);
  cMsg_lxTkG8wj_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_Y04IlGaJ, 0, m, &cVar_Y04IlGaJ_sendMessage);
  cMsg_Icnhxqki_sendMessage(_c, 0, m);
  cMsg_mdNFQms4_sendMessage(_c, 0, m);
  cMsg_Lpm6xwJc_sendMessage(_c, 0, m);
  cMsg_Phe8aIXG_sendMessage(_c, 0, m);
  cMsg_yDzeGE5l_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_nTONyhq2, 0, m, &cVar_nTONyhq2_sendMessage);
  cMsg_cSiIM8Ri_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_jsAL57BZ, 0, m, &cVar_jsAL57BZ_sendMessage);
  cMsg_L9uvvk40_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_1JCAOllX, 0, m, &cVar_1JCAOllX_sendMessage);
  cMsg_QNe66DAZ_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_AwjOhgqW, 0, m, &cVar_AwjOhgqW_sendMessage);
  cMsg_oUydOvFz_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_3tw4OpaD, 0, m, &cVar_3tw4OpaD_sendMessage);
  cMsg_4EsIxroQ_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_RkW1iRG7, 0, m, &cVar_RkW1iRG7_sendMessage);
  cMsg_YTKVN9bm_sendMessage(_c, 0, m);
  cMsg_ufZfDLfL_sendMessage(_c, 0, m);
  cMsg_uXfJOiYb_sendMessage(_c, 0, m);
  cMsg_U6s41R8f_sendMessage(_c, 0, m);
  cMsg_oBZElT3B_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_8kmKr67X, 0, m, &cVar_8kmKr67X_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_k7NHxPuo, 0, m, &cVar_k7NHxPuo_sendMessage);
  cMsg_XC2gToZy_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_gssQJxMj, 0, m, &cVar_gssQJxMj_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_uG4H4pOF, 0, m, &cVar_uG4H4pOF_sendMessage);
  cMsg_jUoVoCca_sendMessage(_c, 0, m);
  cMsg_nX3FOewU_sendMessage(_c, 0, m);
  cMsg_Dxwepj2x_sendMessage(_c, 0, m);
  cMsg_vuOR1nI9_sendMessage(_c, 0, m);
  cMsg_Bk7KfjpK_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_5mTuFX24, 0, m, &cVar_5mTuFX24_sendMessage);
  cMsg_OPXwkZrk_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_zjrIYr3p, 0, m, &cVar_zjrIYr3p_sendMessage);
  cMsg_QD0FqzvJ_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_z6qTTlA4, 0, m, &cVar_z6qTTlA4_sendMessage);
  cMsg_xso9kqO8_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_aUBUF7A9, 0, m, &cVar_aUBUF7A9_sendMessage);
  cMsg_ecmgwB4s_sendMessage(_c, 0, m);
  cMsg_PXzTfySZ_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_qSxGogwg, 0, m, &cVar_qSxGogwg_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_2McqJ0E3, 0, m, &cVar_2McqJ0E3_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_Aa2xXIut, 0, m, &cVar_Aa2xXIut_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_xn9YB15O, 0, m, &cVar_xn9YB15O_sendMessage);
  cMsg_9RFFDacD_sendMessage(_c, 0, m);
  cMsg_jCdgkcIx_sendMessage(_c, 0, m);
  cMsg_cQCyIJFJ_sendMessage(_c, 0, m);
  cMsg_668YZlko_sendMessage(_c, 0, m);
  cMsg_mfocQWvH_sendMessage(_c, 0, m);
  cMsg_aR41c0G2_sendMessage(_c, 0, m);
  cMsg_ybGcBx0Q_sendMessage(_c, 0, m);
  cMsg_zFDBnSh6_sendMessage(_c, 0, m);
  cMsg_thE0RbRj_sendMessage(_c, 0, m);
  cMsg_aEuPwSz9_sendMessage(_c, 0, m);
  cMsg_YjglOL77_sendMessage(_c, 0, m);
  cMsg_vncNQ8U9_sendMessage(_c, 0, m);
  cMsg_H9otBfi4_sendMessage(_c, 0, m);
  cMsg_s8EpBLai_sendMessage(_c, 0, m);
  cMsg_gTjcSgzI_sendMessage(_c, 0, m);
  cMsg_4iFEUH0u_sendMessage(_c, 0, m);
  cMsg_SU1KdcCS_sendMessage(_c, 0, m);
  cMsg_L8QxHo68_sendMessage(_c, 0, m);
  cMsg_nHJrKpPh_sendMessage(_c, 0, m);
  cMsg_DpyvTY6G_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_k3N7iSoe, 0, m, &cVar_k3N7iSoe_sendMessage);
  cMsg_iE8iaihz_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_uHprLQ22, 0, m, &cVar_uHprLQ22_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_NDxUjmjF, 0, m, &cVar_NDxUjmjF_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_NEr1rfD8, 0, m, &cVar_NEr1rfD8_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_OJ2tXarU, 0, m, &cVar_OJ2tXarU_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_gCVVrHuG, 0, m, &cVar_gCVVrHuG_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_RJybhnyg, 0, m, &cVar_RJybhnyg_sendMessage);
  cMsg_EAFHDxRL_sendMessage(_c, 0, m);
  cMsg_c34so8u0_sendMessage(_c, 0, m);
  cMsg_vHqbUn1k_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_Gg6rijWZ, 0, m, &cVar_Gg6rijWZ_sendMessage);
  cMsg_1pqQZTXk_sendMessage(_c, 0, m);
  cMsg_DuAzdA1p_sendMessage(_c, 0, m);
  cMsg_uJFTeGbP_sendMessage(_c, 0, m);
  cMsg_Tff7oeDH_sendMessage(_c, 0, m);
  cMsg_aReGxXuR_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_5xHICv36, 0, m, &cVar_5xHICv36_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_StYoNaJd, 0, m, &cVar_StYoNaJd_sendMessage);
  cMsg_iYWKzmg2_sendMessage(_c, 0, m);
  cMsg_qQaRTtiV_sendMessage(_c, 0, m);
  cMsg_nd0bDNqv_sendMessage(_c, 0, m);
  cMsg_AXdQ2k8U_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_juT2JvKY, 0, m, &cVar_juT2JvKY_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_KMuYXZjJ, 0, m, &cVar_KMuYXZjJ_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_Xd4TaDWV, 0, m, &cVar_Xd4TaDWV_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_wMSka1wE, 0, m, &cVar_wMSka1wE_sendMessage);
  cMsg_y2jWBt42_sendMessage(_c, 0, m);
  cMsg_LZUpOBin_sendMessage(_c, 0, m);
  cSend_nk869IN9_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_J4eHOjeW, 0, m, &cVar_J4eHOjeW_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_33TIBgYM, 0, m, &cVar_33TIBgYM_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_zVNxjGY9, 0, m, &cVar_zVNxjGY9_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_ozAWR6jV, 0, m, &cVar_ozAWR6jV_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_rcjf3SDj, 0, m, &cVar_rcjf3SDj_sendMessage);
  cMsg_3P7YT8Zc_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_23iyp1fg, 0, m, &cVar_23iyp1fg_sendMessage);
  cMsg_r1eELBQX_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_e77iYaUb, 0, m, &cVar_e77iYaUb_sendMessage);
  cMsg_zWI3BuqO_sendMessage(_c, 0, m);
  cMsg_YqfLe7rH_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_DHRgYpdP, 0, m, &cVar_DHRgYpdP_sendMessage);
  cMsg_4jh3V1GP_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_qVF37Eil, 0, m, &cTabhead_qVF37Eil_sendMessage);
  cMsg_YI8gZmpw_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_t8P3L1EW, 0, m, &cVar_t8P3L1EW_sendMessage);
  cMsg_zcM9RDHG_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_oqVCEBbQ, 0, m, &cTabhead_oqVCEBbQ_sendMessage);
  cMsg_6Ykj3Diu_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_HqrDdm4K, 0, m, &cVar_HqrDdm4K_sendMessage);
  cMsg_nlnf2lHS_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_neDLBLlx, 0, m, &cTabhead_neDLBLlx_sendMessage);
  cMsg_RE2CU8P3_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_mlMz6f9p, 0, m, &cVar_mlMz6f9p_sendMessage);
  cMsg_KOwESreD_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_nmlLjw0L, 0, m, &cTabhead_nmlLjw0L_sendMessage);
  cMsg_nSFKb99m_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_oo9Oo4OI, 0, m, &cVar_oo9Oo4OI_sendMessage);
  cMsg_OixAgxhf_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_yGPTgMHi, 0, m, &cTabhead_yGPTgMHi_sendMessage);
  cMsg_SFZqwoCm_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_go6JxS6N, 0, m, &cVar_go6JxS6N_sendMessage);
  cMsg_1ulv16wd_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_2ogH3jPz, 0, m, &cTabhead_2ogH3jPz_sendMessage);
  cMsg_1vapgiEr_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_MCV48FmN, 0, m, &cVar_MCV48FmN_sendMessage);
  cMsg_gvw7QSx4_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_8TqEvFo9, 0, m, &cTabhead_8TqEvFo9_sendMessage);
  cMsg_xkbVPQEd_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_JoJFwX7x, 0, m, &cVar_JoJFwX7x_sendMessage);
  cMsg_Xi2p4KyA_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_ybSPns1X, 0, m, &cTabhead_ybSPns1X_sendMessage);
  cMsg_sRO0XvGq_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_ChpvNp45, 0, m, &cVar_ChpvNp45_sendMessage);
  cMsg_8PKHbAmK_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_7ssKdvOe, 0, m, &cTabhead_7ssKdvOe_sendMessage);
  cMsg_1il5XksI_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_tC7ToJhX, 0, m, &cVar_tC7ToJhX_sendMessage);
  cMsg_X5caIRDV_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_St48b3LR, 0, m, &cTabhead_St48b3LR_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_dTAAFNnq, 0, m, &cVar_dTAAFNnq_sendMessage);
  cMsg_hKLseir2_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_VyRXTWaQ, 0, m, &cVar_VyRXTWaQ_sendMessage);
  cMsg_2nE9OEwE_sendMessage(_c, 0, m);
  cMsg_NFVzouae_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_TyNcSDcn, 0, m, &cVar_TyNcSDcn_sendMessage);
  cMsg_TVKsxiXj_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_g3bDoRJh, 0, m, &cTabhead_g3bDoRJh_sendMessage);
  cMsg_89murrK3_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_tCr4Txa4, 0, m, &cVar_tCr4Txa4_sendMessage);
  cMsg_gDnNAJhh_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_SaueSYpz, 0, m, &cTabhead_SaueSYpz_sendMessage);
  cMsg_M62Si4Up_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_r7u0diin, 0, m, &cVar_r7u0diin_sendMessage);
  cMsg_HoXI0RmS_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_sGFhYcyg, 0, m, &cTabhead_sGFhYcyg_sendMessage);
  cMsg_rkYTYmS1_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_SzDT1Qtb, 0, m, &cVar_SzDT1Qtb_sendMessage);
  cMsg_0LlJPGBe_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_pHZ1ktCN, 0, m, &cTabhead_pHZ1ktCN_sendMessage);
  cMsg_eeh177Xw_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_iJ3msAzO, 0, m, &cVar_iJ3msAzO_sendMessage);
  cMsg_u9dOb9jW_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_GBH0McQH, 0, m, &cTabhead_GBH0McQH_sendMessage);
  cMsg_H2ASOmUL_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_bFedv5Jg, 0, m, &cVar_bFedv5Jg_sendMessage);
  cMsg_4FoeJHwA_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_mOIY8167, 0, m, &cTabhead_mOIY8167_sendMessage);
  cMsg_4uxe1gFt_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_5EAwz1s1, 0, m, &cVar_5EAwz1s1_sendMessage);
  cMsg_io3vlpqK_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_Woe8xP8g, 0, m, &cTabhead_Woe8xP8g_sendMessage);
  cMsg_PBEQeHYd_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_MWbeBsTD, 0, m, &cVar_MWbeBsTD_sendMessage);
  cMsg_V7AO5G18_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_OPKyeqS7, 0, m, &cTabhead_OPKyeqS7_sendMessage);
  cMsg_OrUinj59_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_K4ETKfTt, 0, m, &cVar_K4ETKfTt_sendMessage);
  cMsg_0Iq9JqYI_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_GAXQJEnH, 0, m, &cTabhead_GAXQJEnH_sendMessage);
  cMsg_6GBJUgrS_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_TMIyXNEM, 0, m, &cVar_TMIyXNEM_sendMessage);
  cMsg_Cvu1unzn_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_9kylz7eQ, 0, m, &cTabhead_9kylz7eQ_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_RQaLlKs2, 0, m, &cVar_RQaLlKs2_sendMessage);
  cMsg_hP7iHCq9_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_BvSLDSzN, 0, m, &cVar_BvSLDSzN_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_hs3RJH8f, 0, m, &cVar_hs3RJH8f_sendMessage);
}

void Heavy_SoundScraper::cReceive_u9IR7Pjw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_kAy81P4N, 0, m, &cVar_kAy81P4N_sendMessage);
}

void Heavy_SoundScraper::cReceive_OkGskKAJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_vsc7n5pZ_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_yPSiKuS7_sendMessage);
}

void Heavy_SoundScraper::cReceive_8D8z32Fi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_fWyob0BP, 1, m, &cVar_fWyob0BP_sendMessage);
}

void Heavy_SoundScraper::cReceive_dLBuuyyH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_d0IYt5DF, HV_BINOP_DIVIDE, 1, m, &cBinop_d0IYt5DF_sendMessage);
}

void Heavy_SoundScraper::cReceive_oCRfDneS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_CHTs94PA_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cReceive_C0f1lQ37_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_ELZ4wWIv_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cReceive_7izOKg0D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_e5BRQYoz_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cReceive_chC0fDsM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_rrmykqSu, 1, m, &cVar_rrmykqSu_sendMessage);
}

void Heavy_SoundScraper::cReceive_MGIpARuG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_ajkQXhqq, m);
}

void Heavy_SoundScraper::cReceive_51D9FzDZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_mroKF1MH, 0, m, NULL);
}

void Heavy_SoundScraper::cReceive_FqsruA17_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_im2TaAoE, 0, m, NULL);
}

void Heavy_SoundScraper::cReceive_veJrJ2vf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_U05yaoqV_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -10000.0f, 0, m, &cBinop_lsH4ypI4_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 10000.0f, 0, m, &cBinop_YM7Tq6a5_sendMessage);
}

void Heavy_SoundScraper::cReceive_3k6blV8A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_aRisPBxr_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_C9VowApn_sendMessage);
  sLine_onMessage(_c, &Context(_c)->sLine_mroKF1MH, 0, m, NULL);
}

void Heavy_SoundScraper::cReceive_EeyoHP8Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_uv0rJ7zX_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_3WeH5dYL_sendMessage);
  cPack_onMessage(_c, &Context(_c)->cPack_CsLjerEM, 1, m, &cPack_CsLjerEM_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Ctbd2VMg_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_5Jpx55lz_sendMessage);
}

void Heavy_SoundScraper::cReceive_EQm1ZcpX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_fNevwtaB, 1, m, &cPack_fNevwtaB_sendMessage);
}

void Heavy_SoundScraper::cReceive_oY8i2pLw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_dRJoBjiU, 1, m, &cVar_dRJoBjiU_sendMessage);
}

void Heavy_SoundScraper::cReceive_bj2r78Uf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_rs14SgKQ, HV_BINOP_DIVIDE, 1, m, &cBinop_rs14SgKQ_sendMessage);
}

void Heavy_SoundScraper::cReceive_spCWf3Qz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_XFXaSDTK_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cReceive_pmg97VVY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_26zRrYBF_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cReceive_BiwFDNsH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_t8Zz4frm_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cReceive_s2w97Arv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_py55N7Ov, 1, m, &cVar_py55N7Ov_sendMessage);
}

void Heavy_SoundScraper::cReceive_QnMQhgXf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_i5uSVJmz, m);
}

void Heavy_SoundScraper::cReceive_tKYFMlpy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_vUDsrQ3I, 0, m, NULL);
}

void Heavy_SoundScraper::cReceive_Z8qTBs1F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_Vy4vLllM, 0, m, NULL);
}

void Heavy_SoundScraper::cReceive_MzEKMcDD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_BydhZp18_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -10000.0f, 0, m, &cBinop_noThb7jC_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 10000.0f, 0, m, &cBinop_fZeP7CoA_sendMessage);
}

void Heavy_SoundScraper::cReceive_q7vHf6zg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Snvyherv_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_4p3sLUlq_sendMessage);
  sLine_onMessage(_c, &Context(_c)->sLine_vUDsrQ3I, 0, m, NULL);
}

void Heavy_SoundScraper::cReceive_5WsxjXS0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_HqRqtOEc_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_yW8kHc4M_sendMessage);
  cPack_onMessage(_c, &Context(_c)->cPack_mtB46fWX, 1, m, &cPack_mtB46fWX_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_khmHZvTM_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_jTP4r5QV_sendMessage);
}

void Heavy_SoundScraper::cReceive_IOBCdr60_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_fe8EG0PJ, 1, m, &cPack_fe8EG0PJ_sendMessage);
}

void Heavy_SoundScraper::cReceive_f2DNYbGG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_sqaPBYhh, 1, m, &cVar_sqaPBYhh_sendMessage);
}

void Heavy_SoundScraper::cReceive_kB9kdzJ2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6AC6W0C9, HV_BINOP_DIVIDE, 1, m, &cBinop_6AC6W0C9_sendMessage);
}

void Heavy_SoundScraper::cReceive_Typ4JIoB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_LR8eyBbn_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cReceive_38hDWPAm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_McP6xgQH_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cReceive_WmeGRCg4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_Iy2i0OXs_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cReceive_dV8bOv46_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_lZjdGFHS, 1, m, &cVar_lZjdGFHS_sendMessage);
}

void Heavy_SoundScraper::cReceive_6rMjBsDU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_dMM8Pk4r, m);
}

void Heavy_SoundScraper::cReceive_7xvPxd0G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_AC7yIQnV, 0, m, NULL);
}

void Heavy_SoundScraper::cReceive_K4HZG2wh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_JA9nCj39, 0, m, NULL);
}

void Heavy_SoundScraper::cReceive_7tK5H609_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_GekOn0DA_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -10000.0f, 0, m, &cBinop_nBDBdQ7z_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 10000.0f, 0, m, &cBinop_lLmlRGJT_sendMessage);
}

void Heavy_SoundScraper::cReceive_98xtv1B0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_MbhvY3nY_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_fJxHH2aO_sendMessage);
  sLine_onMessage(_c, &Context(_c)->sLine_AC7yIQnV, 0, m, NULL);
}

void Heavy_SoundScraper::cReceive_qtVcehxi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_rnvGNjWM_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_IuOfwuNr_sendMessage);
  cPack_onMessage(_c, &Context(_c)->cPack_9uoQwgtp, 1, m, &cPack_9uoQwgtp_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_N5UJvXxt_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_3DgKozhT_sendMessage);
}

void Heavy_SoundScraper::cReceive_YfEvkani_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_aRU3bjzn, 1, m, &cPack_aRU3bjzn_sendMessage);
}

void Heavy_SoundScraper::cReceive_EksLlOPh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_DF3DdT7c, 1, m, &cVar_DF3DdT7c_sendMessage);
}

void Heavy_SoundScraper::cReceive_cw4Jl4Ws_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_bBobFv06, HV_BINOP_DIVIDE, 1, m, &cBinop_bBobFv06_sendMessage);
}

void Heavy_SoundScraper::cReceive_KgXQczVj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_ZbzmPPhW_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cReceive_QDmKJtXm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_jaPQMPEN_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cReceive_xIDwRCR0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_cxlceXza_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cReceive_SZRranTr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_VRVw4P4A, 1, m, &cVar_VRVw4P4A_sendMessage);
}

void Heavy_SoundScraper::cReceive_S7bU7ctr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_Z6OROFjn, m);
}

void Heavy_SoundScraper::cReceive_AGQqEzBj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_HxdbGcMn, 0, m, NULL);
}

void Heavy_SoundScraper::cReceive_aU7J7wm9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_TtHVnNvD, 0, m, NULL);
}

void Heavy_SoundScraper::cReceive_V10EzN6A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_yEF5lsKN_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -10000.0f, 0, m, &cBinop_iOf7BHNE_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 10000.0f, 0, m, &cBinop_TQ5OZ7xK_sendMessage);
}

void Heavy_SoundScraper::cReceive_C3gkOwhg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_abiGYk8n_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_0PyL00ch_sendMessage);
  sLine_onMessage(_c, &Context(_c)->sLine_HxdbGcMn, 0, m, NULL);
}

void Heavy_SoundScraper::cReceive_Md0gFRwU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_UWq8Hgcz_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_BGtMrUyW_sendMessage);
  cPack_onMessage(_c, &Context(_c)->cPack_baUqD3UH, 1, m, &cPack_baUqD3UH_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_OVrB2bRg_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_SnOW4eiS_sendMessage);
}

void Heavy_SoundScraper::cReceive_njpx9hp5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_42rxGRaF, 1, m, &cPack_42rxGRaF_sendMessage);
}

void Heavy_SoundScraper::cReceive_L5xfvBzh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_5datEgv1, 0, m, &cVar_5datEgv1_sendMessage);
}

void Heavy_SoundScraper::cReceive_ovIkSJRX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_qAufY60n_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_z6VDUbXm_sendMessage);
}

void Heavy_SoundScraper::cReceive_UM8pxCIq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_SccN7krs, 0, m, &cVar_SccN7krs_sendMessage);
}

void Heavy_SoundScraper::cReceive_sQa0mp8d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_S4ifRtSb_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_9JrcGnF7_sendMessage);
}

void Heavy_SoundScraper::cReceive_lrj6wOD4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 2.0f, 0, m, &cBinop_ps1V98P9_sendMessage);
}

void Heavy_SoundScraper::cReceive_M17zPons_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_x2unxKzg, 0, m, &cVar_x2unxKzg_sendMessage);
}

void Heavy_SoundScraper::cReceive_lzK2PWxi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ceLXRUbZ_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_oUL6oxvc_sendMessage);
}

void Heavy_SoundScraper::cReceive_SDyRUZVe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_J5dGcJlH, 0, m, &cVar_J5dGcJlH_sendMessage);
}

void Heavy_SoundScraper::cReceive_SHAlY3PM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Fdbkz6PM_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_qKEobDGM_sendMessage);
}

void Heavy_SoundScraper::cReceive_pmgk8PyJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSlice_onMessage(_c, &Context(_c)->cSlice_w8Nr3ubL, 0, m, &cSlice_w8Nr3ubL_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_vTqCAAmK, 0, m, &cSlice_vTqCAAmK_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_13dGuUl1, 0, m, &cSlice_13dGuUl1_sendMessage);
}

void Heavy_SoundScraper::cReceive_x0bU9Pi4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPrint_onMessage(_c, m, "SOUND_CHOICE");
  cSwitchcase_yCiPtOun_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cReceive_5am08un8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_CZdKpDNj_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cReceive_R0NCyYvY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_OwUxuiHC_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_8J58vMYa_sendMessage);
  cPack_onMessage(_c, &Context(_c)->cPack_f73hkHp6, 0, m, &cPack_f73hkHp6_sendMessage);
}

void Heavy_SoundScraper::cReceive_GO7kADgY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_OwqYPTRt_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_8oUduTPt_sendMessage);
}

void Heavy_SoundScraper::cReceive_noM8Uo6S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 2.0f, 0, m, &cBinop_FdkNYIHd_sendMessage);
}

void Heavy_SoundScraper::cReceive_E26AmS55_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_44UXrCfW, 0, m, &cVar_44UXrCfW_sendMessage);
}

void Heavy_SoundScraper::cReceive_SPwDNL2J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_S5ZBzOlH_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_5kFKN3MW_sendMessage);
}

void Heavy_SoundScraper::cReceive_T8EaOrbu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 2.0f, 0, m, &cBinop_sI7jsqQP_sendMessage);
}

void Heavy_SoundScraper::cReceive_if9dP39u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_rJQyfo0R, HV_BINOP_SUBTRACT, 0, m, &cBinop_rJQyfo0R_sendMessage);
}

void Heavy_SoundScraper::cReceive_UuGL7T2H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_wFFkaZIL_sendMessage);
  cPrint_onMessage(_c, m, "SCRAPER_LEVEL");
  cVar_onMessage(_c, &Context(_c)->cVar_O8k01LXR, 0, m, &cVar_O8k01LXR_sendMessage);
}

void Heavy_SoundScraper::cReceive_Zooi0MsG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSlice_onMessage(_c, &Context(_c)->cSlice_lkIyh1d5, 0, m, &cSlice_lkIyh1d5_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_HB6epsln, 0, m, &cSlice_HB6epsln_sendMessage);
}

void Heavy_SoundScraper::cReceive_pl4thiSB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_W2f1VAuJ_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_vHRz6WjI_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ZT1HN0xD_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_tvnIJxdg_sendMessage);
}

void Heavy_SoundScraper::cReceive_fYbtdYAQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.25f, 0, m, &cBinop_n0bkUSfw_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_JsG36uhK_sendMessage);
}

void Heavy_SoundScraper::cReceive_DsOxX40y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 10.0f, 0, m, &cBinop_so1f10Zy_sendMessage);
}

void Heavy_SoundScraper::cReceive_yKuRHk4T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 10.0f, 0, m, &cBinop_OniMkjAW_sendMessage);
}

void Heavy_SoundScraper::cReceive_jW0BSIiH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPrint_onMessage(_c, m, "SCRAPER_TRANSPOSITION");
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 100.0f, 0, m, &cBinop_Wz67Ylzr_sendMessage);
}

void Heavy_SoundScraper::cReceive_WsASZSZc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_4AY27DI0, 0, m, &cVar_4AY27DI0_sendMessage);
}

void Heavy_SoundScraper::cReceive_dFOpWous_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_1GfYNNFV_sendMessage(_c, 0, m);
  cSwitchcase_d07eZUvN_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cReceive_8uy8pCnV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_PKWmcieK_sendMessage(_c, 0, m);
  cSwitchcase_2CjnURVV_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cReceive_KYtdp8Cr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_Cu10YFdk_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cReceive_CLqUCZ3N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_R2CgXvGG, 0, m, &cVar_R2CgXvGG_sendMessage);
}

void Heavy_SoundScraper::cReceive_do9XHRQM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_2wqMA3Qb, 0, m, &cVar_2wqMA3Qb_sendMessage);
}

void Heavy_SoundScraper::cReceive_2rJDeVKt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_m36CtkJV, 0, m, &cVar_m36CtkJV_sendMessage);
}

void Heavy_SoundScraper::cReceive_8ROaVYr0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_o9hYs7Wl_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Dc8zYbQN_sendMessage);
}

void Heavy_SoundScraper::cReceive_m5hw2QJU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_zvyJl14F, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_qFngxfzl, m);
}

void Heavy_SoundScraper::cReceive_FX6TpWuY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_KiC3yEXU, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_x5s3QE1H, m);
}

void Heavy_SoundScraper::cReceive_pU9JNKCf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_uIXeIgVO_sendMessage(_c, 0, m);
  cMsg_jl1AGciR_sendMessage(_c, 0, m);
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
    __hv_varread_f(&sVarf_ui2z5bvS, VOf(Bf0));
    __hv_varread_f(&sVarf_pOB2J8iV, VOf(Bf1));
    __hv_mul_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_DGrLtH6g, VOf(Bf0));
    __hv_rpole_f(&sRPole_zmgChI6k, VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_zvyJl14F, VOf(Bf1));
    __hv_varread_f(&sVarf_NXJI1ey2, VOf(Bf2));
    __hv_del1_f(&sDel1_hefnXSBE, VIf(Bf2), VOf(Bf3));
    __hv_lt_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_samphold_f(&sSamphold_EjWcv9KA, VIf(Bf1), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_NXJI1ey2, VOf(Bf1));
    __hv_var_k_f(VOf(Bf2), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_fma_f(VIf(Bf3), VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_KiC3yEXU, VOf(Bf1));
    __hv_varread_f(&sVarf_NXJI1ey2, VOf(Bf3));
    __hv_del1_f(&sDel1_sOqRqJ7B, VIf(Bf3), VOf(Bf4));
    __hv_lt_f(VIf(Bf3), VIf(Bf4), VOf(Bf4));
    __hv_samphold_f(&sSamphold_9QrdqH1g, VIf(Bf1), VIf(Bf4), VOf(Bf4));
    __hv_add_f(VIf(Bf2), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_2S2rbbGI, VOf(Bf2));
    __hv_min_f(VIf(Bf4), VIf(Bf2), VOf(Bf2));
    __hv_zero_f(VOf(Bf4));
    __hv_max_f(VIf(Bf2), VIf(Bf4), VOf(Bf4));
    __hv_floor_f(VIf(Bf4), VOf(Bf2));
    __hv_cast_fi(VIf(Bf2), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_C9ecPpbq, VIi(Bi1), VOf(Bf1));
    __hv_tabread_if(&sTabread_Th7thTkq, VIi(Bi0), VOf(Bf3));
    __hv_sub_f(VIf(Bf1), VIf(Bf3), VOf(Bf1));
    __hv_sub_f(VIf(Bf4), VIf(Bf2), VOf(Bf2));
    __hv_fma_f(VIf(Bf1), VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_NXJI1ey2, VOf(Bf2));
    __hv_var_k_f(VOf(Bf1), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf2), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_floor_f(VIf(Bf2), VOf(Bf1));
    __hv_sub_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf2), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_abs_f(VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf1), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf2), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_mul_f(VIf(Bf2), VIf(Bf2), VOf(Bf1));
    __hv_mul_f(VIf(Bf2), VIf(Bf1), VOf(Bf4));
    __hv_mul_f(VIf(Bf4), VIf(Bf1), VOf(Bf5));
    __hv_mul_f(VIf(Bf5), VIf(Bf1), VOf(Bf6));
    __hv_mul_f(VIf(Bf6), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf7), 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f);
    __hv_var_k_f(VOf(Bf8), 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f);
    __hv_var_k_f(VOf(Bf9), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf4), VIf(Bf9), VOf(Bf9));
    __hv_sub_f(VIf(Bf2), VIf(Bf9), VOf(Bf9));
    __hv_fma_f(VIf(Bf5), VIf(Bf8), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf8), 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f);
    __hv_mul_f(VIf(Bf6), VIf(Bf8), VOf(Bf8));
    __hv_sub_f(VIf(Bf9), VIf(Bf8), VOf(Bf8));
    __hv_fma_f(VIf(Bf1), VIf(Bf7), VIf(Bf8), VOf(Bf8));
    __hv_varread_f(&sVarf_qFngxfzl, VOf(Bf7));
    __hv_varread_f(&sVarf_Kb6VrfWt, VOf(Bf1));
    __hv_del1_f(&sDel1_X0OAmIMc, VIf(Bf1), VOf(Bf9));
    __hv_lt_f(VIf(Bf1), VIf(Bf9), VOf(Bf9));
    __hv_samphold_f(&sSamphold_RZftgFSf, VIf(Bf7), VIf(Bf9), VOf(Bf9));
    __hv_varread_f(&sVarf_Kb6VrfWt, VOf(Bf7));
    __hv_var_k_f(VOf(Bf1), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_fma_f(VIf(Bf9), VIf(Bf7), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_x5s3QE1H, VOf(Bf7));
    __hv_varread_f(&sVarf_Kb6VrfWt, VOf(Bf9));
    __hv_del1_f(&sDel1_Z7IpF8zq, VIf(Bf9), VOf(Bf6));
    __hv_lt_f(VIf(Bf9), VIf(Bf6), VOf(Bf6));
    __hv_samphold_f(&sSamphold_hilgfVnI, VIf(Bf7), VIf(Bf6), VOf(Bf6));
    __hv_add_f(VIf(Bf1), VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_tnfrMHs2, VOf(Bf1));
    __hv_min_f(VIf(Bf6), VIf(Bf1), VOf(Bf1));
    __hv_zero_f(VOf(Bf6));
    __hv_max_f(VIf(Bf1), VIf(Bf6), VOf(Bf6));
    __hv_floor_f(VIf(Bf6), VOf(Bf1));
    __hv_cast_fi(VIf(Bf1), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_ckBmIu1s, VIi(Bi1), VOf(Bf7));
    __hv_tabread_if(&sTabread_ENryHyQb, VIi(Bi0), VOf(Bf9));
    __hv_sub_f(VIf(Bf7), VIf(Bf9), VOf(Bf7));
    __hv_sub_f(VIf(Bf6), VIf(Bf1), VOf(Bf1));
    __hv_fma_f(VIf(Bf7), VIf(Bf1), VIf(Bf9), VOf(Bf9));
    __hv_varread_f(&sVarf_Kb6VrfWt, VOf(Bf1));
    __hv_var_k_f(VOf(Bf7), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf1), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf1), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf7), VIf(Bf1), VOf(Bf1));
    __hv_floor_f(VIf(Bf1), VOf(Bf7));
    __hv_sub_f(VIf(Bf1), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf1), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf7), VIf(Bf1), VOf(Bf1));
    __hv_abs_f(VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf7), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf1), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf1), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf7), VIf(Bf1), VOf(Bf1));
    __hv_mul_f(VIf(Bf1), VIf(Bf1), VOf(Bf7));
    __hv_mul_f(VIf(Bf1), VIf(Bf7), VOf(Bf6));
    __hv_mul_f(VIf(Bf6), VIf(Bf7), VOf(Bf5));
    __hv_mul_f(VIf(Bf5), VIf(Bf7), VOf(Bf2));
    __hv_mul_f(VIf(Bf2), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf4), 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f);
    __hv_var_k_f(VOf(Bf10), 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f);
    __hv_var_k_f(VOf(Bf11), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf6), VIf(Bf11), VOf(Bf11));
    __hv_sub_f(VIf(Bf1), VIf(Bf11), VOf(Bf11));
    __hv_fma_f(VIf(Bf5), VIf(Bf10), VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf10), 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f);
    __hv_mul_f(VIf(Bf2), VIf(Bf10), VOf(Bf10));
    __hv_sub_f(VIf(Bf11), VIf(Bf10), VOf(Bf10));
    __hv_fma_f(VIf(Bf7), VIf(Bf4), VIf(Bf10), VOf(Bf10));
    __hv_mul_f(VIf(Bf9), VIf(Bf10), VOf(Bf10));
    __hv_fma_f(VIf(Bf3), VIf(Bf8), VIf(Bf10), VOf(Bf10));
    __hv_phasor_k_f(&sPhasor_a7DCv1VX, VOf(Bf8));
    __hv_varwrite_f(&sVarf_NXJI1ey2, VIf(Bf8));
    __hv_var_k_f(VOf(Bf3), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_add_f(VIf(Bf8), VIf(Bf3), VOf(Bf3));
    __hv_floor_f(VIf(Bf3), VOf(Bf8));
    __hv_sub_f(VIf(Bf3), VIf(Bf8), VOf(Bf8));
    __hv_varwrite_f(&sVarf_Kb6VrfWt, VIf(Bf8));
    __hv_varread_f(&sVarf_R5EWxVIc, VOf(Bf8));
    __hv_rpole_f(&sRPole_34wQa56D, VIf(Bf10), VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf10), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_del1_f(&sDel1_k7HxwGom, VIf(Bf8), VOf(Bf3));
    __hv_mul_f(VIf(Bf3), VIf(Bf10), VOf(Bf10));
    __hv_sub_f(VIf(Bf8), VIf(Bf10), VOf(Bf10));
    __hv_varread_f(&sVarf_h6JxsK9j, VOf(Bf8));
    __hv_mul_f(VIf(Bf10), VIf(Bf8), VOf(Bf8));
    __hv_mul_f(VIf(Bf0), VIf(Bf8), VOf(Bf8));
    __hv_line_f(&sLine_PE54GZBr, VOf(Bf0));
    __hv_mul_f(VIf(Bf8), VIf(Bf0), VOf(Bf0));
    __hv_sample_f(this, &sSample_uvES4F4q, VIf(Bf8), &sSample_uvES4F4q_sendMessage);
    __hv_line_f(&sLine_mroKF1MH, VOf(Bf8));
    __hv_varread_f(&sVarf_5hl3G6sl, VOf(Bf10));
    __hv_min_f(VIf(Bf8), VIf(Bf10), VOf(Bf10));
    __hv_zero_f(VOf(Bf8));
    __hv_max_f(VIf(Bf10), VIf(Bf8), VOf(Bf8));
    __hv_floor_f(VIf(Bf8), VOf(Bf10));
    __hv_cast_fi(VIf(Bf10), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_KllqsCaA, VIi(Bi1), VOf(Bf3));
    __hv_tabread_if(&sTabread_8LcxcY9e, VIi(Bi0), VOf(Bf9));
    __hv_sub_f(VIf(Bf3), VIf(Bf9), VOf(Bf3));
    __hv_sub_f(VIf(Bf8), VIf(Bf10), VOf(Bf10));
    __hv_fma_f(VIf(Bf3), VIf(Bf10), VIf(Bf9), VOf(Bf9));
    __hv_line_f(&sLine_im2TaAoE, VOf(Bf10));
    __hv_mul_f(VIf(Bf9), VIf(Bf10), VOf(Bf10));
    __hv_line_f(&sLine_bCXr4EvD, VOf(Bf9));
    __hv_varread_f(&sVarf_ajkQXhqq, VOf(Bf3));
    __hv_mul_f(VIf(Bf9), VIf(Bf3), VOf(Bf3));
    __hv_mul_f(VIf(Bf10), VIf(Bf3), VOf(Bf3));
    __hv_line_f(&sLine_2dJXG7Q9, VOf(Bf10));
    __hv_mul_f(VIf(Bf3), VIf(Bf10), VOf(Bf10));
    __hv_line_f(&sLine_oDVE0pvn, VOf(Bf9));
    __hv_mul_f(VIf(Bf3), VIf(Bf9), VOf(Bf9));
    __hv_line_f(&sLine_vUDsrQ3I, VOf(Bf3));
    __hv_varread_f(&sVarf_WyRbmsYM, VOf(Bf8));
    __hv_min_f(VIf(Bf3), VIf(Bf8), VOf(Bf8));
    __hv_zero_f(VOf(Bf3));
    __hv_max_f(VIf(Bf8), VIf(Bf3), VOf(Bf3));
    __hv_floor_f(VIf(Bf3), VOf(Bf8));
    __hv_cast_fi(VIf(Bf8), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_VVNnBoCl, VIi(Bi1), VOf(Bf4));
    __hv_tabread_if(&sTabread_RKhlvguZ, VIi(Bi0), VOf(Bf7));
    __hv_sub_f(VIf(Bf4), VIf(Bf7), VOf(Bf4));
    __hv_sub_f(VIf(Bf3), VIf(Bf8), VOf(Bf8));
    __hv_fma_f(VIf(Bf4), VIf(Bf8), VIf(Bf7), VOf(Bf7));
    __hv_line_f(&sLine_Vy4vLllM, VOf(Bf8));
    __hv_mul_f(VIf(Bf7), VIf(Bf8), VOf(Bf8));
    __hv_line_f(&sLine_IvF9IHet, VOf(Bf7));
    __hv_varread_f(&sVarf_i5uSVJmz, VOf(Bf4));
    __hv_mul_f(VIf(Bf7), VIf(Bf4), VOf(Bf4));
    __hv_mul_f(VIf(Bf8), VIf(Bf4), VOf(Bf4));
    __hv_line_f(&sLine_hevpodVb, VOf(Bf8));
    __hv_mul_f(VIf(Bf4), VIf(Bf8), VOf(Bf8));
    __hv_line_f(&sLine_e3XeXHT4, VOf(Bf7));
    __hv_mul_f(VIf(Bf4), VIf(Bf7), VOf(Bf7));
    __hv_add_f(VIf(Bf10), VIf(Bf8), VOf(Bf8));
    __hv_line_f(&sLine_AC7yIQnV, VOf(Bf10));
    __hv_varread_f(&sVarf_5vbSjb3z, VOf(Bf4));
    __hv_min_f(VIf(Bf10), VIf(Bf4), VOf(Bf4));
    __hv_zero_f(VOf(Bf10));
    __hv_max_f(VIf(Bf4), VIf(Bf10), VOf(Bf10));
    __hv_floor_f(VIf(Bf10), VOf(Bf4));
    __hv_cast_fi(VIf(Bf4), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_teeVnAf5, VIi(Bi1), VOf(Bf3));
    __hv_tabread_if(&sTabread_e9K0lSYN, VIi(Bi0), VOf(Bf11));
    __hv_sub_f(VIf(Bf3), VIf(Bf11), VOf(Bf3));
    __hv_sub_f(VIf(Bf10), VIf(Bf4), VOf(Bf4));
    __hv_fma_f(VIf(Bf3), VIf(Bf4), VIf(Bf11), VOf(Bf11));
    __hv_line_f(&sLine_JA9nCj39, VOf(Bf4));
    __hv_mul_f(VIf(Bf11), VIf(Bf4), VOf(Bf4));
    __hv_line_f(&sLine_zrBuOQF3, VOf(Bf11));
    __hv_varread_f(&sVarf_dMM8Pk4r, VOf(Bf3));
    __hv_mul_f(VIf(Bf11), VIf(Bf3), VOf(Bf3));
    __hv_mul_f(VIf(Bf4), VIf(Bf3), VOf(Bf3));
    __hv_line_f(&sLine_GuV54yvL, VOf(Bf4));
    __hv_mul_f(VIf(Bf3), VIf(Bf4), VOf(Bf4));
    __hv_line_f(&sLine_2fh87dfQ, VOf(Bf11));
    __hv_mul_f(VIf(Bf3), VIf(Bf11), VOf(Bf11));
    __hv_add_f(VIf(Bf8), VIf(Bf4), VOf(Bf4));
    __hv_line_f(&sLine_HxdbGcMn, VOf(Bf8));
    __hv_varread_f(&sVarf_JWj8QhxO, VOf(Bf3));
    __hv_min_f(VIf(Bf8), VIf(Bf3), VOf(Bf3));
    __hv_zero_f(VOf(Bf8));
    __hv_max_f(VIf(Bf3), VIf(Bf8), VOf(Bf8));
    __hv_floor_f(VIf(Bf8), VOf(Bf3));
    __hv_cast_fi(VIf(Bf3), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_roJt7v8z, VIi(Bi1), VOf(Bf10));
    __hv_tabread_if(&sTabread_e2Vk1u9s, VIi(Bi0), VOf(Bf2));
    __hv_sub_f(VIf(Bf10), VIf(Bf2), VOf(Bf10));
    __hv_sub_f(VIf(Bf8), VIf(Bf3), VOf(Bf3));
    __hv_fma_f(VIf(Bf10), VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_line_f(&sLine_TtHVnNvD, VOf(Bf3));
    __hv_mul_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_line_f(&sLine_GY4Dkh1P, VOf(Bf2));
    __hv_varread_f(&sVarf_Z6OROFjn, VOf(Bf10));
    __hv_mul_f(VIf(Bf2), VIf(Bf10), VOf(Bf10));
    __hv_mul_f(VIf(Bf3), VIf(Bf10), VOf(Bf10));
    __hv_line_f(&sLine_Qjb9MdFa, VOf(Bf3));
    __hv_mul_f(VIf(Bf10), VIf(Bf3), VOf(Bf3));
    __hv_line_f(&sLine_P3JxrZ3P, VOf(Bf2));
    __hv_mul_f(VIf(Bf10), VIf(Bf2), VOf(Bf2));
    __hv_add_f(VIf(Bf4), VIf(Bf3), VOf(Bf3));
    __hv_add_f(VIf(Bf9), VIf(Bf7), VOf(Bf7));
    __hv_add_f(VIf(Bf7), VIf(Bf11), VOf(Bf11));
    __hv_add_f(VIf(Bf11), VIf(Bf2), VOf(Bf2));
    __hv_line_f(&sLine_5kqe3ww4, VOf(Bf11));
    __hv_mul_f(VIf(Bf3), VIf(Bf11), VOf(Bf3));
    __hv_mul_f(VIf(Bf2), VIf(Bf11), VOf(Bf11));
    __hv_line_f(&sLine_clyHWvTj, VOf(Bf2));
    __hv_mul_f(VIf(Bf0), VIf(Bf2), VOf(Bf2));
    __hv_add_f(VIf(Bf3), VIf(Bf2), VOf(Bf0));
    __hv_add_f(VIf(Bf11), VIf(Bf2), VOf(Bf11));
    __hv_line_f(&sLine_RKUx47KF, VOf(Bf7));
    __hv_mul_f(VIf(Bf0), VIf(Bf7), VOf(Bf0));
    __hv_mul_f(VIf(Bf11), VIf(Bf7), VOf(Bf7));
    __hv_add_f(VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_line_f(&sLine_G4tPG2mq, VOf(Bf3));
    __hv_mul_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_line_f(&sLine_uGff1jyA, VOf(Bf2));
    __hv_mul_f(VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_tabwrite_f(&sTabwrite_mqGmSwHE, VIf(Bf2));
    __hv_line_f(&sLine_C4j67utO, VOf(Bf2));
    __hv_phasor_f(&sPhasor_UBdDWePO, VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf11), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf2), VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf9), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf11), VIf(Bf9), VOf(Bf9));
    __hv_floor_f(VIf(Bf9), VOf(Bf11));
    __hv_sub_f(VIf(Bf9), VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf9), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf11), VIf(Bf9), VOf(Bf9));
    __hv_abs_f(VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf11), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf9), VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf9), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf11), VIf(Bf9), VOf(Bf9));
    __hv_mul_f(VIf(Bf9), VIf(Bf9), VOf(Bf11));
    __hv_mul_f(VIf(Bf9), VIf(Bf11), VOf(Bf4));
    __hv_mul_f(VIf(Bf4), VIf(Bf11), VOf(Bf10));
    __hv_mul_f(VIf(Bf10), VIf(Bf11), VOf(Bf8));
    __hv_mul_f(VIf(Bf8), VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf5), 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f);
    __hv_var_k_f(VOf(Bf1), 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f);
    __hv_var_k_f(VOf(Bf6), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf4), VIf(Bf6), VOf(Bf6));
    __hv_sub_f(VIf(Bf9), VIf(Bf6), VOf(Bf6));
    __hv_fma_f(VIf(Bf10), VIf(Bf1), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf1), 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f);
    __hv_mul_f(VIf(Bf8), VIf(Bf1), VOf(Bf1));
    __hv_sub_f(VIf(Bf6), VIf(Bf1), VOf(Bf1));
    __hv_fma_f(VIf(Bf11), VIf(Bf5), VIf(Bf1), VOf(Bf1));
    __hv_line_f(&sLine_NWaIhvDv, VOf(Bf5));
    __hv_line_f(&sLine_QVlR4es3, VOf(Bf11));
    __hv_fma_f(VIf(Bf2), VIf(Bf5), VIf(Bf11), VOf(Bf6));
    __hv_tabhead_f(&sTabhead_wmv56ULT, VOf(Bf8));
    __hv_var_k_f_r(VOf(Bf10), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf8), VIf(Bf10), VOf(Bf10));
    __hv_varread_f(&sVarf_Ftw3ql1o, VOf(Bf8));
    __hv_mul_f(VIf(Bf6), VIf(Bf8), VOf(Bf8));
    __hv_varread_f(&sVarf_e2Zzds5I, VOf(Bf6));
    __hv_min_f(VIf(Bf8), VIf(Bf6), VOf(Bf6));
    __hv_zero_f(VOf(Bf8));
    __hv_max_f(VIf(Bf6), VIf(Bf8), VOf(Bf8));
    __hv_sub_f(VIf(Bf10), VIf(Bf8), VOf(Bf8));
    __hv_floor_f(VIf(Bf8), VOf(Bf10));
    __hv_varread_f(&sVarf_loioO01H, VOf(Bf6));
    __hv_zero_f(VOf(Bf9));
    __hv_lt_f(VIf(Bf10), VIf(Bf9), VOf(Bf9));
    __hv_and_f(VIf(Bf6), VIf(Bf9), VOf(Bf9));
    __hv_add_f(VIf(Bf10), VIf(Bf9), VOf(Bf9));
    __hv_cast_fi(VIf(Bf9), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_t5rk7vDG, VIi(Bi1), VOf(Bf9));
    __hv_tabread_if(&sTabread_OAIFDd9S, VIi(Bi0), VOf(Bf6));
    __hv_sub_f(VIf(Bf9), VIf(Bf6), VOf(Bf9));
    __hv_sub_f(VIf(Bf8), VIf(Bf10), VOf(Bf10));
    __hv_fma_f(VIf(Bf9), VIf(Bf10), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf10), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_add_f(VIf(Bf2), VIf(Bf10), VOf(Bf10));
    __hv_floor_f(VIf(Bf10), VOf(Bf2));
    __hv_sub_f(VIf(Bf10), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf10), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf2), VIf(Bf10), VOf(Bf10));
    __hv_var_k_f(VOf(Bf9), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf10), VIf(Bf9), VOf(Bf9));
    __hv_floor_f(VIf(Bf9), VOf(Bf10));
    __hv_sub_f(VIf(Bf9), VIf(Bf10), VOf(Bf10));
    __hv_var_k_f(VOf(Bf9), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf10), VIf(Bf9), VOf(Bf9));
    __hv_abs_f(VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf10), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf9), VIf(Bf10), VOf(Bf10));
    __hv_var_k_f(VOf(Bf9), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf10), VIf(Bf9), VOf(Bf9));
    __hv_mul_f(VIf(Bf9), VIf(Bf9), VOf(Bf10));
    __hv_mul_f(VIf(Bf9), VIf(Bf10), VOf(Bf8));
    __hv_mul_f(VIf(Bf8), VIf(Bf10), VOf(Bf4));
    __hv_mul_f(VIf(Bf4), VIf(Bf10), VOf(Bf12));
    __hv_mul_f(VIf(Bf12), VIf(Bf10), VOf(Bf10));
    __hv_var_k_f(VOf(Bf13), 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f);
    __hv_var_k_f(VOf(Bf14), 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f);
    __hv_var_k_f(VOf(Bf15), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf8), VIf(Bf15), VOf(Bf15));
    __hv_sub_f(VIf(Bf9), VIf(Bf15), VOf(Bf15));
    __hv_fma_f(VIf(Bf4), VIf(Bf14), VIf(Bf15), VOf(Bf15));
    __hv_var_k_f(VOf(Bf14), 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f);
    __hv_mul_f(VIf(Bf12), VIf(Bf14), VOf(Bf14));
    __hv_sub_f(VIf(Bf15), VIf(Bf14), VOf(Bf14));
    __hv_fma_f(VIf(Bf10), VIf(Bf13), VIf(Bf14), VOf(Bf14));
    __hv_fma_f(VIf(Bf2), VIf(Bf5), VIf(Bf11), VOf(Bf11));
    __hv_tabhead_f(&sTabhead_V43ZtulN, VOf(Bf5));
    __hv_var_k_f_r(VOf(Bf2), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_atbmY5Dv, VOf(Bf5));
    __hv_mul_f(VIf(Bf11), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_h3K6ScRe, VOf(Bf11));
    __hv_min_f(VIf(Bf5), VIf(Bf11), VOf(Bf11));
    __hv_zero_f(VOf(Bf5));
    __hv_max_f(VIf(Bf11), VIf(Bf5), VOf(Bf5));
    __hv_sub_f(VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_floor_f(VIf(Bf5), VOf(Bf2));
    __hv_varread_f(&sVarf_6gTTdqqR, VOf(Bf11));
    __hv_zero_f(VOf(Bf13));
    __hv_lt_f(VIf(Bf2), VIf(Bf13), VOf(Bf13));
    __hv_and_f(VIf(Bf11), VIf(Bf13), VOf(Bf13));
    __hv_add_f(VIf(Bf2), VIf(Bf13), VOf(Bf13));
    __hv_cast_fi(VIf(Bf13), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_uXUnhsRm, VIi(Bi1), VOf(Bf13));
    __hv_tabread_if(&sTabread_8gv4Ce1N, VIi(Bi0), VOf(Bf11));
    __hv_sub_f(VIf(Bf13), VIf(Bf11), VOf(Bf13));
    __hv_sub_f(VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_fma_f(VIf(Bf13), VIf(Bf2), VIf(Bf11), VOf(Bf11));
    __hv_mul_f(VIf(Bf14), VIf(Bf11), VOf(Bf11));
    __hv_fma_f(VIf(Bf1), VIf(Bf6), VIf(Bf11), VOf(Bf11));
    __hv_varread_f(&sVarf_8VQ2N8Ei, VOf(Bf6));
    __hv_tabhead_f(&sTabhead_TTkKU5ki, VOf(Bf1));
    __hv_var_k_f_r(VOf(Bf14), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf1), VIf(Bf14), VOf(Bf14));
    __hv_varread_f(&sVarf_eGBesSoR, VOf(Bf1));
    __hv_mul_f(VIf(Bf6), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_xdWOs8ll, VOf(Bf6));
    __hv_min_f(VIf(Bf1), VIf(Bf6), VOf(Bf6));
    __hv_zero_f(VOf(Bf1));
    __hv_max_f(VIf(Bf6), VIf(Bf1), VOf(Bf1));
    __hv_sub_f(VIf(Bf14), VIf(Bf1), VOf(Bf1));
    __hv_floor_f(VIf(Bf1), VOf(Bf14));
    __hv_varread_f(&sVarf_IILCOUkj, VOf(Bf6));
    __hv_zero_f(VOf(Bf2));
    __hv_lt_f(VIf(Bf14), VIf(Bf2), VOf(Bf2));
    __hv_and_f(VIf(Bf6), VIf(Bf2), VOf(Bf2));
    __hv_add_f(VIf(Bf14), VIf(Bf2), VOf(Bf2));
    __hv_cast_fi(VIf(Bf2), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_QXCP1TNP, VIi(Bi1), VOf(Bf2));
    __hv_tabread_if(&sTabread_rRCO5RXp, VIi(Bi0), VOf(Bf6));
    __hv_sub_f(VIf(Bf2), VIf(Bf6), VOf(Bf2));
    __hv_sub_f(VIf(Bf1), VIf(Bf14), VOf(Bf14));
    __hv_fma_f(VIf(Bf2), VIf(Bf14), VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_toE901Wj, VOf(Bf14));
    __hv_rpole_f(&sRPole_GWyzCVDt, VIf(Bf6), VIf(Bf14), VOf(Bf14));
    __hv_var_k_f(VOf(Bf6), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_del1_f(&sDel1_vF2FTMWY, VIf(Bf14), VOf(Bf2));
    __hv_mul_f(VIf(Bf2), VIf(Bf6), VOf(Bf6));
    __hv_sub_f(VIf(Bf14), VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_5pgMUuSl, VOf(Bf14));
    __hv_mul_f(VIf(Bf6), VIf(Bf14), VOf(Bf14));
    __hv_varread_f(&sVarf_wg4UNVk3, VOf(Bf6));
    __hv_mul_f(VIf(Bf14), VIf(Bf6), VOf(Bf6));
    __hv_add_f(VIf(Bf11), VIf(Bf6), VOf(Bf14));
    __hv_line_f(&sLine_thLkgnxU, VOf(Bf2));
    __hv_varread_f(&sVarf_fEfALegh, VOf(Bf1));
    __hv_mul_f(VIf(Bf6), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_WWRtHYUq, VOf(Bf6));
    __hv_rpole_f(&sRPole_PfLVJPMS, VIf(Bf1), VIf(Bf6), VOf(Bf6));
    __hv_fma_f(VIf(Bf11), VIf(Bf2), VIf(Bf6), VOf(Bf6));
    __hv_tabwrite_f(&sTabwrite_8O0A9Pu4, VIf(Bf6));
    __hv_var_k_f(VOf(Bf6), 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f);
    __hv_mul_f(VIf(Bf14), VIf(Bf6), VOf(Bf6));
    __hv_tabread_f(&sTabread_dj81ruJi, VOf(Bf14));
    __hv_varread_f(&sVarf_icJKbmbr, VOf(Bf2));
    __hv_mul_f(VIf(Bf14), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_Ok1oEGU1, VOf(Bf11));
    __hv_rpole_f(&sRPole_4Fcgcwvj, VIf(Bf2), VIf(Bf11), VOf(Bf11));
    __hv_sub_f(VIf(Bf11), VIf(Bf14), VOf(Bf11));
    __hv_line_f(&sLine_yWjVeTiD, VOf(Bf2));
    __hv_fma_f(VIf(Bf11), VIf(Bf2), VIf(Bf14), VOf(Bf14));
    __hv_line_f(&sLine_a84zihT1, VOf(Bf11));
    __hv_tabread_f(&sTabread_b9g38sSt, VOf(Bf1));
    __hv_add_f(VIf(Bf3), VIf(Bf1), VOf(Bf13));
    __hv_tabread_f(&sTabread_CMXK6XqO, VOf(Bf5));
    __hv_add_f(VIf(Bf13), VIf(Bf5), VOf(Bf10));
    __hv_tabread_f(&sTabread_bghJeFu0, VOf(Bf15));
    __hv_add_f(VIf(Bf10), VIf(Bf15), VOf(Bf12));
    __hv_tabread_f(&sTabread_BxCiE5Lx, VOf(Bf4));
    __hv_add_f(VIf(Bf12), VIf(Bf4), VOf(Bf9));
    __hv_tabread_f(&sTabread_PLCfNsd5, VOf(Bf8));
    __hv_sub_f(VIf(Bf9), VIf(Bf8), VOf(Bf16));
    __hv_tabwrite_f(&sTabwrite_GVECn9lp, VIf(Bf16));
    __hv_sub_f(VIf(Bf12), VIf(Bf4), VOf(Bf4));
    __hv_tabwrite_f(&sTabwrite_YkTV5vwK, VIf(Bf4));
    __hv_sub_f(VIf(Bf10), VIf(Bf15), VOf(Bf15));
    __hv_tabwrite_f(&sTabwrite_S6pGnhqD, VIf(Bf15));
    __hv_sub_f(VIf(Bf13), VIf(Bf5), VOf(Bf5));
    __hv_tabwrite_f(&sTabwrite_i2nr6az6, VIf(Bf5));
    __hv_sub_f(VIf(Bf3), VIf(Bf1), VOf(Bf1));
    __hv_tabwrite_f(&sTabwrite_xOecdRP1, VIf(Bf1));
    __hv_tabwrite_f(&sTabwrite_Xtx7SXZE, VIf(Bf3));
    __hv_add_f(VIf(Bf9), VIf(Bf8), VOf(Bf8));
    __hv_tabread_f(&sTabread_3t5VJQw5, VOf(Bf9));
    __hv_fma_f(VIf(Bf14), VIf(Bf11), VIf(Bf8), VOf(Bf8));
    __hv_tabread_f(&sTabread_Jt2pjvQn, VOf(Bf14));
    __hv_varread_f(&sVarf_hmGj91V8, VOf(Bf1));
    __hv_mul_f(VIf(Bf14), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_6RiiC3ev, VOf(Bf5));
    __hv_rpole_f(&sRPole_AUJUXxKr, VIf(Bf1), VIf(Bf5), VOf(Bf5));
    __hv_sub_f(VIf(Bf5), VIf(Bf14), VOf(Bf5));
    __hv_fma_f(VIf(Bf5), VIf(Bf2), VIf(Bf14), VOf(Bf14));
    __hv_fma_f(VIf(Bf14), VIf(Bf11), VIf(Bf9), VOf(Bf9));
    __hv_add_f(VIf(Bf8), VIf(Bf9), VOf(Bf14));
    __hv_tabread_f(&sTabread_MC2Hs4Y3, VOf(Bf5));
    __hv_varread_f(&sVarf_DfDnxfV8, VOf(Bf1));
    __hv_mul_f(VIf(Bf5), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_hcGctyo5, VOf(Bf13));
    __hv_rpole_f(&sRPole_kjyzw8dg, VIf(Bf1), VIf(Bf13), VOf(Bf13));
    __hv_sub_f(VIf(Bf13), VIf(Bf5), VOf(Bf13));
    __hv_fma_f(VIf(Bf13), VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_mul_f(VIf(Bf5), VIf(Bf11), VOf(Bf5));
    __hv_tabread_f(&sTabread_EPo9lqrA, VOf(Bf13));
    __hv_varread_f(&sVarf_nHDVwMMM, VOf(Bf1));
    __hv_mul_f(VIf(Bf13), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_0DQyJA3b, VOf(Bf15));
    __hv_rpole_f(&sRPole_gJaRr4kH, VIf(Bf1), VIf(Bf15), VOf(Bf15));
    __hv_sub_f(VIf(Bf15), VIf(Bf13), VOf(Bf15));
    __hv_fma_f(VIf(Bf15), VIf(Bf2), VIf(Bf13), VOf(Bf13));
    __hv_mul_f(VIf(Bf13), VIf(Bf11), VOf(Bf11));
    __hv_add_f(VIf(Bf5), VIf(Bf11), VOf(Bf13));
    __hv_add_f(VIf(Bf14), VIf(Bf13), VOf(Bf2));
    __hv_tabwrite_f(&sTabwrite_eLj86jli, VIf(Bf2));
    __hv_sub_f(VIf(Bf8), VIf(Bf9), VOf(Bf2));
    __hv_sub_f(VIf(Bf5), VIf(Bf11), VOf(Bf15));
    __hv_add_f(VIf(Bf2), VIf(Bf15), VOf(Bf1));
    __hv_tabwrite_f(&sTabwrite_Ulp4BOlH, VIf(Bf1));
    __hv_sub_f(VIf(Bf14), VIf(Bf13), VOf(Bf13));
    __hv_tabwrite_f(&sTabwrite_X8BJe9P9, VIf(Bf13));
    __hv_sub_f(VIf(Bf2), VIf(Bf15), VOf(Bf15));
    __hv_tabwrite_f(&sTabwrite_Vjo3KuJ9, VIf(Bf15));
    __hv_line_f(&sLine_lmi7kD9G, VOf(Bf15));
    __hv_mul_f(VIf(Bf8), VIf(Bf15), VOf(Bf8));
    __hv_mul_f(VIf(Bf9), VIf(Bf15), VOf(Bf9));
    __hv_mul_f(VIf(Bf5), VIf(Bf15), VOf(Bf5));
    __hv_mul_f(VIf(Bf11), VIf(Bf15), VOf(Bf15));
    __hv_add_f(VIf(Bf6), VIf(Bf8), VOf(Bf8));
    __hv_line_f(&sLine_tk8fsAw0, VOf(Bf15));
    __hv_mul_f(VIf(Bf3), VIf(Bf15), VOf(Bf15));
    __hv_var_k_f(VOf(Bf3), 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f);
    __hv_mul_f(VIf(Bf15), VIf(Bf3), VOf(Bf3));
    __hv_tabwrite_f(&sTabwrite_PebHL3hD, VIf(Bf3));
    __hv_line_f(&sLine_87ldDbSW, VOf(Bf15));
    __hv_phasor_f(&sPhasor_7LdFZlRq, VIf(Bf15), VOf(Bf15));
    __hv_var_k_f(VOf(Bf5), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf15), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf11), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf5), VIf(Bf11), VOf(Bf11));
    __hv_floor_f(VIf(Bf11), VOf(Bf5));
    __hv_sub_f(VIf(Bf11), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf11), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf5), VIf(Bf11), VOf(Bf11));
    __hv_abs_f(VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf5), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf11), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf11), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf5), VIf(Bf11), VOf(Bf11));
    __hv_mul_f(VIf(Bf11), VIf(Bf11), VOf(Bf5));
    __hv_mul_f(VIf(Bf11), VIf(Bf5), VOf(Bf2));
    __hv_mul_f(VIf(Bf2), VIf(Bf5), VOf(Bf13));
    __hv_mul_f(VIf(Bf13), VIf(Bf5), VOf(Bf14));
    __hv_mul_f(VIf(Bf14), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf1), 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f);
    __hv_var_k_f(VOf(Bf10), 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f);
    __hv_var_k_f(VOf(Bf4), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf2), VIf(Bf4), VOf(Bf4));
    __hv_sub_f(VIf(Bf11), VIf(Bf4), VOf(Bf4));
    __hv_fma_f(VIf(Bf13), VIf(Bf10), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf10), 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f);
    __hv_mul_f(VIf(Bf14), VIf(Bf10), VOf(Bf10));
    __hv_sub_f(VIf(Bf4), VIf(Bf10), VOf(Bf10));
    __hv_fma_f(VIf(Bf5), VIf(Bf1), VIf(Bf10), VOf(Bf10));
    __hv_line_f(&sLine_YkiltBOq, VOf(Bf1));
    __hv_line_f(&sLine_jVKbQJy3, VOf(Bf5));
    __hv_fma_f(VIf(Bf15), VIf(Bf1), VIf(Bf5), VOf(Bf4));
    __hv_tabhead_f(&sTabhead_GsJWATQb, VOf(Bf14));
    __hv_var_k_f_r(VOf(Bf13), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf14), VIf(Bf13), VOf(Bf13));
    __hv_varread_f(&sVarf_kbdZGu1G, VOf(Bf14));
    __hv_mul_f(VIf(Bf4), VIf(Bf14), VOf(Bf14));
    __hv_varread_f(&sVarf_aMLcAFzq, VOf(Bf4));
    __hv_min_f(VIf(Bf14), VIf(Bf4), VOf(Bf4));
    __hv_zero_f(VOf(Bf14));
    __hv_max_f(VIf(Bf4), VIf(Bf14), VOf(Bf14));
    __hv_sub_f(VIf(Bf13), VIf(Bf14), VOf(Bf14));
    __hv_floor_f(VIf(Bf14), VOf(Bf13));
    __hv_varread_f(&sVarf_nQ4E3bwN, VOf(Bf4));
    __hv_zero_f(VOf(Bf11));
    __hv_lt_f(VIf(Bf13), VIf(Bf11), VOf(Bf11));
    __hv_and_f(VIf(Bf4), VIf(Bf11), VOf(Bf11));
    __hv_add_f(VIf(Bf13), VIf(Bf11), VOf(Bf11));
    __hv_cast_fi(VIf(Bf11), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_tWNEUtBl, VIi(Bi1), VOf(Bf11));
    __hv_tabread_if(&sTabread_ooGcIXkD, VIi(Bi0), VOf(Bf4));
    __hv_sub_f(VIf(Bf11), VIf(Bf4), VOf(Bf11));
    __hv_sub_f(VIf(Bf14), VIf(Bf13), VOf(Bf13));
    __hv_fma_f(VIf(Bf11), VIf(Bf13), VIf(Bf4), VOf(Bf4));
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
    __hv_mul_f(VIf(Bf14), VIf(Bf13), VOf(Bf2));
    __hv_mul_f(VIf(Bf2), VIf(Bf13), VOf(Bf12));
    __hv_mul_f(VIf(Bf12), VIf(Bf13), VOf(Bf13));
    __hv_var_k_f(VOf(Bf16), 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f);
    __hv_var_k_f(VOf(Bf17), 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f);
    __hv_var_k_f(VOf(Bf18), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf14), VIf(Bf18), VOf(Bf18));
    __hv_sub_f(VIf(Bf11), VIf(Bf18), VOf(Bf18));
    __hv_fma_f(VIf(Bf2), VIf(Bf17), VIf(Bf18), VOf(Bf18));
    __hv_var_k_f(VOf(Bf17), 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f);
    __hv_mul_f(VIf(Bf12), VIf(Bf17), VOf(Bf17));
    __hv_sub_f(VIf(Bf18), VIf(Bf17), VOf(Bf17));
    __hv_fma_f(VIf(Bf13), VIf(Bf16), VIf(Bf17), VOf(Bf17));
    __hv_fma_f(VIf(Bf15), VIf(Bf1), VIf(Bf5), VOf(Bf5));
    __hv_tabhead_f(&sTabhead_ZW0ght7z, VOf(Bf1));
    __hv_var_k_f_r(VOf(Bf15), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf1), VIf(Bf15), VOf(Bf15));
    __hv_varread_f(&sVarf_U7vX9PQx, VOf(Bf1));
    __hv_mul_f(VIf(Bf5), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_masf72jC, VOf(Bf5));
    __hv_min_f(VIf(Bf1), VIf(Bf5), VOf(Bf5));
    __hv_zero_f(VOf(Bf1));
    __hv_max_f(VIf(Bf5), VIf(Bf1), VOf(Bf1));
    __hv_sub_f(VIf(Bf15), VIf(Bf1), VOf(Bf1));
    __hv_floor_f(VIf(Bf1), VOf(Bf15));
    __hv_varread_f(&sVarf_pdQ3Ejpp, VOf(Bf5));
    __hv_zero_f(VOf(Bf16));
    __hv_lt_f(VIf(Bf15), VIf(Bf16), VOf(Bf16));
    __hv_and_f(VIf(Bf5), VIf(Bf16), VOf(Bf16));
    __hv_add_f(VIf(Bf15), VIf(Bf16), VOf(Bf16));
    __hv_cast_fi(VIf(Bf16), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_kaWIefkE, VIi(Bi1), VOf(Bf16));
    __hv_tabread_if(&sTabread_VJr9bQAJ, VIi(Bi0), VOf(Bf5));
    __hv_sub_f(VIf(Bf16), VIf(Bf5), VOf(Bf16));
    __hv_sub_f(VIf(Bf1), VIf(Bf15), VOf(Bf15));
    __hv_fma_f(VIf(Bf16), VIf(Bf15), VIf(Bf5), VOf(Bf5));
    __hv_mul_f(VIf(Bf17), VIf(Bf5), VOf(Bf5));
    __hv_fma_f(VIf(Bf10), VIf(Bf4), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_7lvNK8gW, VOf(Bf4));
    __hv_tabhead_f(&sTabhead_IxAWa6aV, VOf(Bf10));
    __hv_var_k_f_r(VOf(Bf17), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf10), VIf(Bf17), VOf(Bf17));
    __hv_varread_f(&sVarf_EtKtBAFO, VOf(Bf10));
    __hv_mul_f(VIf(Bf4), VIf(Bf10), VOf(Bf10));
    __hv_varread_f(&sVarf_DuKdmKRX, VOf(Bf4));
    __hv_min_f(VIf(Bf10), VIf(Bf4), VOf(Bf4));
    __hv_zero_f(VOf(Bf10));
    __hv_max_f(VIf(Bf4), VIf(Bf10), VOf(Bf10));
    __hv_sub_f(VIf(Bf17), VIf(Bf10), VOf(Bf10));
    __hv_floor_f(VIf(Bf10), VOf(Bf17));
    __hv_varread_f(&sVarf_t984n1aS, VOf(Bf4));
    __hv_zero_f(VOf(Bf15));
    __hv_lt_f(VIf(Bf17), VIf(Bf15), VOf(Bf15));
    __hv_and_f(VIf(Bf4), VIf(Bf15), VOf(Bf15));
    __hv_add_f(VIf(Bf17), VIf(Bf15), VOf(Bf15));
    __hv_cast_fi(VIf(Bf15), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_UauKCSGb, VIi(Bi1), VOf(Bf15));
    __hv_tabread_if(&sTabread_0QoJXrOz, VIi(Bi0), VOf(Bf4));
    __hv_sub_f(VIf(Bf15), VIf(Bf4), VOf(Bf15));
    __hv_sub_f(VIf(Bf10), VIf(Bf17), VOf(Bf17));
    __hv_fma_f(VIf(Bf15), VIf(Bf17), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_qch2Y6GQ, VOf(Bf17));
    __hv_rpole_f(&sRPole_2PhyP4MO, VIf(Bf4), VIf(Bf17), VOf(Bf17));
    __hv_var_k_f(VOf(Bf4), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_del1_f(&sDel1_mxNI4Q82, VIf(Bf17), VOf(Bf15));
    __hv_mul_f(VIf(Bf15), VIf(Bf4), VOf(Bf4));
    __hv_sub_f(VIf(Bf17), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_dyLctu6G, VOf(Bf17));
    __hv_mul_f(VIf(Bf4), VIf(Bf17), VOf(Bf17));
    __hv_varread_f(&sVarf_cbs2aAnN, VOf(Bf4));
    __hv_mul_f(VIf(Bf17), VIf(Bf4), VOf(Bf4));
    __hv_add_f(VIf(Bf5), VIf(Bf4), VOf(Bf17));
    __hv_line_f(&sLine_2mLrveBd, VOf(Bf15));
    __hv_varread_f(&sVarf_ENoVCC2J, VOf(Bf10));
    __hv_mul_f(VIf(Bf4), VIf(Bf10), VOf(Bf10));
    __hv_varread_f(&sVarf_LRNq5qN4, VOf(Bf4));
    __hv_rpole_f(&sRPole_ABwrgtIP, VIf(Bf10), VIf(Bf4), VOf(Bf4));
    __hv_fma_f(VIf(Bf5), VIf(Bf15), VIf(Bf4), VOf(Bf4));
    __hv_tabwrite_f(&sTabwrite_Pb6uuJkx, VIf(Bf4));
    __hv_add_f(VIf(Bf17), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_LQkF2yxi, VOf(Bf17));
    __hv_varread_f(&sVarf_bGXM7Urz, VOf(Bf4));
    __hv_mul_f(VIf(Bf17), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf17), 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f);
    __hv_max_f(VIf(Bf4), VIf(Bf17), VOf(Bf17));
    __hv_varread_f(&sVarf_lLuH2O4I, VOf(Bf4));
    __hv_min_f(VIf(Bf17), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_F9Kl3kXb, VOf(Bf15));
    __hv_mul_f(VIf(Bf4), VIf(Bf15), VOf(Bf15));
    __hv_mul_f(VIf(Bf3), VIf(Bf15), VOf(Bf3));
    __hv_varread_f(&sVarf_tcP5yXgU, VOf(Bf4));
    __hv_mul_f(VIf(Bf3), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf3), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_sub_f(VIf(Bf15), VIf(Bf3), VOf(Bf15));
    __hv_cos_f(VIf(Bf17), VOf(Bf17));
    __hv_mul_f(VIf(Bf15), VIf(Bf17), VOf(Bf5));
    __hv_mul_f(VIf(Bf17), VIf(Bf17), VOf(Bf17));
    __hv_sub_f(VIf(Bf3), VIf(Bf17), VOf(Bf17));
    __hv_zero_f(VOf(Bf3));
    __hv_gt_f(VIf(Bf17), VIf(Bf3), VOf(Bf3));
    __hv_sqrt_f(VIf(Bf17), VOf(Bf17));
    __hv_and_f(VIf(Bf3), VIf(Bf17), VOf(Bf17));
    __hv_mul_f(VIf(Bf15), VIf(Bf17), VOf(Bf17));
    __hv_cpole_f(&sCPole_5TaKkrQ5, VIf(Bf4), VIf(ZERO), VIf(Bf5), VIf(Bf17), VOf(Bf17), VOf(Bf5));
    __hv_varread_f(&sVarf_qXx3NkpA, VOf(Bf5));
    __hv_mul_f(VIf(Bf17), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_4eYiY0Fp, VOf(Bf17));
    __hv_rpole_f(&sRPole_BhlVStKK, VIf(Bf5), VIf(Bf17), VOf(Bf17));
    __hv_varread_f(&sVarf_4Aq5SqLC, VOf(Bf5));
    __hv_mul_f(VIf(Bf17), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_pm6SGIWw, VOf(Bf17));
    __hv_rpole_f(&sRPole_mNi4E67X, VIf(Bf5), VIf(Bf17), VOf(Bf17));
    __hv_varread_f(&sVarf_vRKr3pEf, VOf(Bf5));
    __hv_mul_f(VIf(Bf17), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_pnP15uQM, VOf(Bf17));
    __hv_rpole_f(&sRPole_pCzFsLOI, VIf(Bf5), VIf(Bf17), VOf(Bf17));
    __hv_tabread_f(&sTabread_RifD0f6y, VOf(Bf5));
    __hv_varread_f(&sVarf_UAknzTth, VOf(Bf4));
    __hv_mul_f(VIf(Bf5), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_3VKgAxzB, VOf(Bf15));
    __hv_rpole_f(&sRPole_gEGCTt1F, VIf(Bf4), VIf(Bf15), VOf(Bf15));
    __hv_sub_f(VIf(Bf15), VIf(Bf5), VOf(Bf15));
    __hv_line_f(&sLine_glSWgFyi, VOf(Bf4));
    __hv_fma_f(VIf(Bf15), VIf(Bf4), VIf(Bf5), VOf(Bf5));
    __hv_line_f(&sLine_zusUuoW7, VOf(Bf15));
    __hv_tabread_f(&sTabread_bYPtTgj3, VOf(Bf3));
    __hv_add_f(VIf(Bf17), VIf(Bf3), VOf(Bf10));
    __hv_tabread_f(&sTabread_6JoEa4Rx, VOf(Bf16));
    __hv_add_f(VIf(Bf10), VIf(Bf16), VOf(Bf1));
    __hv_tabread_f(&sTabread_hvXwyfuS, VOf(Bf13));
    __hv_add_f(VIf(Bf1), VIf(Bf13), VOf(Bf18));
    __hv_tabread_f(&sTabread_hwttHFZi, VOf(Bf12));
    __hv_add_f(VIf(Bf18), VIf(Bf12), VOf(Bf2));
    __hv_tabread_f(&sTabread_ZypL9G2b, VOf(Bf11));
    __hv_sub_f(VIf(Bf2), VIf(Bf11), VOf(Bf14));
    __hv_tabwrite_f(&sTabwrite_5wohD85C, VIf(Bf14));
    __hv_sub_f(VIf(Bf18), VIf(Bf12), VOf(Bf12));
    __hv_tabwrite_f(&sTabwrite_xEqUPJcW, VIf(Bf12));
    __hv_sub_f(VIf(Bf1), VIf(Bf13), VOf(Bf13));
    __hv_tabwrite_f(&sTabwrite_1TF3Xi34, VIf(Bf13));
    __hv_sub_f(VIf(Bf10), VIf(Bf16), VOf(Bf16));
    __hv_tabwrite_f(&sTabwrite_65hrwXRR, VIf(Bf16));
    __hv_sub_f(VIf(Bf17), VIf(Bf3), VOf(Bf3));
    __hv_tabwrite_f(&sTabwrite_q1nfTchJ, VIf(Bf3));
    __hv_tabwrite_f(&sTabwrite_3OdrNL5D, VIf(Bf17));
    __hv_add_f(VIf(Bf2), VIf(Bf11), VOf(Bf11));
    __hv_tabread_f(&sTabread_cCPK1SxE, VOf(Bf2));
    __hv_fma_f(VIf(Bf5), VIf(Bf15), VIf(Bf11), VOf(Bf11));
    __hv_tabread_f(&sTabread_3qjsq7ya, VOf(Bf5));
    __hv_varread_f(&sVarf_k5uaGEKM, VOf(Bf3));
    __hv_mul_f(VIf(Bf5), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_HavsYL9f, VOf(Bf16));
    __hv_rpole_f(&sRPole_oO0sNQsf, VIf(Bf3), VIf(Bf16), VOf(Bf16));
    __hv_sub_f(VIf(Bf16), VIf(Bf5), VOf(Bf16));
    __hv_fma_f(VIf(Bf16), VIf(Bf4), VIf(Bf5), VOf(Bf5));
    __hv_fma_f(VIf(Bf5), VIf(Bf15), VIf(Bf2), VOf(Bf2));
    __hv_add_f(VIf(Bf11), VIf(Bf2), VOf(Bf5));
    __hv_tabread_f(&sTabread_oVRZbKxD, VOf(Bf16));
    __hv_varread_f(&sVarf_xod8zom1, VOf(Bf3));
    __hv_mul_f(VIf(Bf16), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_aYIMPjPM, VOf(Bf10));
    __hv_rpole_f(&sRPole_JU8lSWfv, VIf(Bf3), VIf(Bf10), VOf(Bf10));
    __hv_sub_f(VIf(Bf10), VIf(Bf16), VOf(Bf10));
    __hv_fma_f(VIf(Bf10), VIf(Bf4), VIf(Bf16), VOf(Bf16));
    __hv_mul_f(VIf(Bf16), VIf(Bf15), VOf(Bf16));
    __hv_tabread_f(&sTabread_oaMZ0dHH, VOf(Bf10));
    __hv_varread_f(&sVarf_06XvneXY, VOf(Bf3));
    __hv_mul_f(VIf(Bf10), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_9sZMKgF4, VOf(Bf13));
    __hv_rpole_f(&sRPole_yqoCvbkZ, VIf(Bf3), VIf(Bf13), VOf(Bf13));
    __hv_sub_f(VIf(Bf13), VIf(Bf10), VOf(Bf13));
    __hv_fma_f(VIf(Bf13), VIf(Bf4), VIf(Bf10), VOf(Bf10));
    __hv_mul_f(VIf(Bf10), VIf(Bf15), VOf(Bf15));
    __hv_add_f(VIf(Bf16), VIf(Bf15), VOf(Bf10));
    __hv_add_f(VIf(Bf5), VIf(Bf10), VOf(Bf4));
    __hv_tabwrite_f(&sTabwrite_dvdnNiuf, VIf(Bf4));
    __hv_sub_f(VIf(Bf11), VIf(Bf2), VOf(Bf4));
    __hv_sub_f(VIf(Bf16), VIf(Bf15), VOf(Bf13));
    __hv_add_f(VIf(Bf4), VIf(Bf13), VOf(Bf3));
    __hv_tabwrite_f(&sTabwrite_fhb54cn5, VIf(Bf3));
    __hv_sub_f(VIf(Bf5), VIf(Bf10), VOf(Bf10));
    __hv_tabwrite_f(&sTabwrite_wGQCtqrr, VIf(Bf10));
    __hv_sub_f(VIf(Bf4), VIf(Bf13), VOf(Bf13));
    __hv_tabwrite_f(&sTabwrite_QTTuUDMa, VIf(Bf13));
    __hv_line_f(&sLine_HhK41dBC, VOf(Bf13));
    __hv_mul_f(VIf(Bf11), VIf(Bf13), VOf(Bf11));
    __hv_mul_f(VIf(Bf2), VIf(Bf13), VOf(Bf2));
    __hv_mul_f(VIf(Bf16), VIf(Bf13), VOf(Bf16));
    __hv_mul_f(VIf(Bf15), VIf(Bf13), VOf(Bf13));
    __hv_add_f(VIf(Bf17), VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf17), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf11), VIf(Bf17), VOf(Bf17));
    __hv_add_f(VIf(Bf8), VIf(Bf17), VOf(Bf8));
    __hv_add_f(VIf(Bf6), VIf(Bf9), VOf(Bf9));
    __hv_add_f(VIf(Bf9), VIf(Bf17), VOf(Bf17));
    __hv_line_f(&sLine_i5agM2D2, VOf(Bf9));
    __hv_mul_f(VIf(Bf8), VIf(Bf9), VOf(Bf8));
    __hv_mul_f(VIf(Bf17), VIf(Bf9), VOf(Bf9));
    __hv_add_f(VIf(Bf0), VIf(Bf8), VOf(Bf8));
    __hv_add_f(VIf(Bf7), VIf(Bf9), VOf(Bf9));
    __hv_line_f(&sLine_TWTetHHL, VOf(Bf7));
    __hv_mul_f(VIf(Bf8), VIf(Bf7), VOf(Bf8));
    __hv_mul_f(VIf(Bf9), VIf(Bf7), VOf(Bf7));
    __hv_add_f(VIf(Bf7), VIf(O1), VOf(O1));
    __hv_add_f(VIf(Bf8), VIf(O0), VOf(O0));

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

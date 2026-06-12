/** Copyright (c) 2026 Charles Martin. Generated from Pure Data by hvcc (https://github.com/Wasted-Audio/hvcc). */

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
  numBytes += sRPole_init(&sRPole_j0JbZtTr);
  numBytes += sPhasor_k_init(&sPhasor_8Ur4xh2K, 0.0f, sampleRate);
  numBytes += sDel1_init(&sDel1_0lZ8wKKw);
  numBytes += sSamphold_init(&sSamphold_QN7EbMMX);
  numBytes += sDel1_init(&sDel1_z460VTzG);
  numBytes += sSamphold_init(&sSamphold_wBWnNM8U);
  numBytes += sTabread_init(&sTabread_Bz8IQrUP, &hTable_adIMRuo0, false);
  numBytes += sTabread_init(&sTabread_MfTwMD66, &hTable_adIMRuo0, false);
  numBytes += sDel1_init(&sDel1_tRALRFZl);
  numBytes += sSamphold_init(&sSamphold_KXe9xik7);
  numBytes += sDel1_init(&sDel1_scwDdBXK);
  numBytes += sSamphold_init(&sSamphold_rlJsbykp);
  numBytes += sTabread_init(&sTabread_P5BLAPKi, &hTable_adIMRuo0, false);
  numBytes += sTabread_init(&sTabread_igOAoUWy, &hTable_adIMRuo0, false);
  numBytes += sRPole_init(&sRPole_7jcTZ8Y7);
  numBytes += sDel1_init(&sDel1_wINFFuV7);
  numBytes += sLine_init(&sLine_VgJS7kLS);
  numBytes += sSample_init(&sSample_ASCMEqPZ);
  numBytes += sLine_init(&sLine_cAPdStYy);
  numBytes += sTabread_init(&sTabread_bBKzDePT, &hTable_AKQw9gB5, false);
  numBytes += sTabread_init(&sTabread_TReXBIUJ, &hTable_AKQw9gB5, false);
  numBytes += sLine_init(&sLine_qm8yewgh);
  numBytes += sLine_init(&sLine_7wuBgJ5s);
  numBytes += sLine_init(&sLine_gVqws3WR);
  numBytes += sLine_init(&sLine_nsa1SCND);
  numBytes += sLine_init(&sLine_IB7l1ctW);
  numBytes += sTabread_init(&sTabread_61hRkCkk, &hTable_qTT30gQb, false);
  numBytes += sTabread_init(&sTabread_Dq51SkCT, &hTable_qTT30gQb, false);
  numBytes += sLine_init(&sLine_OhR0L8UX);
  numBytes += sLine_init(&sLine_O0ifSzPL);
  numBytes += sLine_init(&sLine_kpWJi41L);
  numBytes += sLine_init(&sLine_fa9VpVzC);
  numBytes += sLine_init(&sLine_QtVh0uKT);
  numBytes += sTabread_init(&sTabread_xvfKRRxx, &hTable_dqgidaqB, false);
  numBytes += sTabread_init(&sTabread_eAmx89Kq, &hTable_dqgidaqB, false);
  numBytes += sLine_init(&sLine_KRQa77bb);
  numBytes += sLine_init(&sLine_2P8mbY2y);
  numBytes += sLine_init(&sLine_N6lrmGJT);
  numBytes += sLine_init(&sLine_b2iW3hdu);
  numBytes += sLine_init(&sLine_VYGTLUEb);
  numBytes += sTabread_init(&sTabread_aqpc7o1W, &hTable_bkykhA3v, false);
  numBytes += sTabread_init(&sTabread_6uYUGrWc, &hTable_bkykhA3v, false);
  numBytes += sLine_init(&sLine_HIEYxg14);
  numBytes += sLine_init(&sLine_0dA8JbKr);
  numBytes += sLine_init(&sLine_iJIcUm7s);
  numBytes += sLine_init(&sLine_wKjUfunQ);
  numBytes += sLine_init(&sLine_nzETJbrO);
  numBytes += sLine_init(&sLine_QM37Rcsm);
  numBytes += sLine_init(&sLine_naTWa0RH);
  numBytes += sLine_init(&sLine_ZZKNZRLX);
  numBytes += sLine_init(&sLine_1gpI2VKu);
  numBytes += sLine_init(&sLine_0ZnGXISG);
  numBytes += sPhasor_init(&sPhasor_YshteAh0, sampleRate);
  numBytes += sLine_init(&sLine_6zA7jM3e);
  numBytes += sLine_init(&sLine_AV6C8lwf);
  numBytes += sTabhead_init(&sTabhead_TpMbhQ1X, &hTable_zlt5GtL1);
  numBytes += sTabread_init(&sTabread_f6cXPNu8, &hTable_zlt5GtL1, false);
  numBytes += sTabread_init(&sTabread_mxhuiuoL, &hTable_zlt5GtL1, false);
  numBytes += sTabhead_init(&sTabhead_kFx6KNgb, &hTable_zlt5GtL1);
  numBytes += sTabread_init(&sTabread_WSZyb2A2, &hTable_zlt5GtL1, false);
  numBytes += sTabread_init(&sTabread_rq9uXTGZ, &hTable_zlt5GtL1, false);
  numBytes += sTabwrite_init(&sTabwrite_68ZEmoet, &hTable_zlt5GtL1);
  numBytes += sLine_init(&sLine_JxCbhdLP);
  numBytes += sTabhead_init(&sTabhead_pi8hVpWZ, &hTable_TnZjyknh);
  numBytes += sTabread_init(&sTabread_zi5qKH5S, &hTable_TnZjyknh, false);
  numBytes += sTabread_init(&sTabread_EV9mrtn6, &hTable_TnZjyknh, false);
  numBytes += sRPole_init(&sRPole_mDpKj3Vn);
  numBytes += sDel1_init(&sDel1_YhQaLXkj);
  numBytes += sRPole_init(&sRPole_bL1DfBh9);
  numBytes += sTabwrite_init(&sTabwrite_fO5JNITB, &hTable_TnZjyknh);
  numBytes += sTabread_init(&sTabread_UMAlHkrX, &hTable_rQziADzR, true);
  numBytes += sRPole_init(&sRPole_Us9d778h);
  numBytes += sLine_init(&sLine_LW9JeSpj);
  numBytes += sLine_init(&sLine_KmqMAnhB);
  numBytes += sLine_init(&sLine_zd8iUYEN);
  numBytes += sTabread_init(&sTabread_Mf3ytb18, &hTable_sOQFACjd, true);
  numBytes += sRPole_init(&sRPole_veFf5zJg);
  numBytes += sTabread_init(&sTabread_v5M3Sot5, &hTable_amukS8d7, true);
  numBytes += sTabread_init(&sTabread_9oR6lA7J, &hTable_5Jlf3VuJ, true);
  numBytes += sTabwrite_init(&sTabwrite_KVJjR7db, &hTable_KTYymZwO);
  numBytes += sTabwrite_init(&sTabwrite_rYsjrFF2, &hTable_amukS8d7);
  numBytes += sTabread_init(&sTabread_xVPC2oxR, &hTable_N3IEEdKO, true);
  numBytes += sTabread_init(&sTabread_O6jFGsul, &hTable_KTYymZwO, true);
  numBytes += sTabread_init(&sTabread_NIIx5kU1, &hTable_9rKLAeez, true);
  numBytes += sTabread_init(&sTabread_AgyAQgdX, &hTable_il4LWkq0, true);
  numBytes += sTabwrite_init(&sTabwrite_Z9aUjTyP, &hTable_N3IEEdKO);
  numBytes += sTabwrite_init(&sTabwrite_IxL6w6Y4, &hTable_9rKLAeez);
  numBytes += sTabwrite_init(&sTabwrite_z6VSE2bb, &hTable_il4LWkq0);
  numBytes += sTabwrite_init(&sTabwrite_xAmeylLP, &hTable_5Jlf3VuJ);
  numBytes += sTabread_init(&sTabread_95dkUskH, &hTable_kUXFxfS9, true);
  numBytes += sRPole_init(&sRPole_wtHNLpvF);
  numBytes += sTabread_init(&sTabread_A7NRdDRo, &hTable_yD5jEq6S, true);
  numBytes += sRPole_init(&sRPole_55b4L959);
  numBytes += sTabwrite_init(&sTabwrite_tI1NGy9l, &hTable_sOQFACjd);
  numBytes += sTabwrite_init(&sTabwrite_FOWYkAfr, &hTable_yD5jEq6S);
  numBytes += sTabwrite_init(&sTabwrite_9qK970t4, &hTable_kUXFxfS9);
  numBytes += sTabwrite_init(&sTabwrite_PUK5OSPa, &hTable_rQziADzR);
  numBytes += sLine_init(&sLine_8gj0B0K3);
  numBytes += sTabwrite_init(&sTabwrite_M5vsPrLF, &hTable_xeiqziG1);
  numBytes += sLine_init(&sLine_cSvxiMqk);
  numBytes += sPhasor_init(&sPhasor_t8WTNE9t, sampleRate);
  numBytes += sLine_init(&sLine_w64ryzUm);
  numBytes += sLine_init(&sLine_qhyBzUUM);
  numBytes += sTabhead_init(&sTabhead_XfKTIjIk, &hTable_xeiqziG1);
  numBytes += sTabread_init(&sTabread_DOoKdRAh, &hTable_xeiqziG1, false);
  numBytes += sTabread_init(&sTabread_Oadm9wkv, &hTable_xeiqziG1, false);
  numBytes += sTabhead_init(&sTabhead_nM3OwlwO, &hTable_xeiqziG1);
  numBytes += sTabread_init(&sTabread_DLCdY9pw, &hTable_xeiqziG1, false);
  numBytes += sTabread_init(&sTabread_elfAU654, &hTable_xeiqziG1, false);
  numBytes += sTabhead_init(&sTabhead_PI9lMAug, &hTable_Bf8NPbuA);
  numBytes += sTabread_init(&sTabread_nrhM4q20, &hTable_Bf8NPbuA, false);
  numBytes += sTabread_init(&sTabread_GnS6mRac, &hTable_Bf8NPbuA, false);
  numBytes += sRPole_init(&sRPole_20ttpJ0R);
  numBytes += sDel1_init(&sDel1_tHRbrtx4);
  numBytes += sLine_init(&sLine_v8wXUZlu);
  numBytes += sRPole_init(&sRPole_V5SmtTvk);
  numBytes += sTabwrite_init(&sTabwrite_dW9XFL9Q, &hTable_Bf8NPbuA);
  numBytes += sCPole_init(&sCPole_v6gO6sOD);
  numBytes += sRPole_init(&sRPole_y4od3lLR);
  numBytes += sRPole_init(&sRPole_Gr7onzoU);
  numBytes += sRPole_init(&sRPole_BYP0Zdhu);
  numBytes += sTabread_init(&sTabread_zDIEk0mR, &hTable_RXQA5BSx, true);
  numBytes += sRPole_init(&sRPole_jaBpt9ud);
  numBytes += sLine_init(&sLine_uC2DT64B);
  numBytes += sLine_init(&sLine_uRHIqJbV);
  numBytes += sTabread_init(&sTabread_Y9CraDEf, &hTable_7LfxGM68, true);
  numBytes += sTabread_init(&sTabread_xXzVRiLA, &hTable_ed4dzP1v, true);
  numBytes += sTabread_init(&sTabread_nDccIDmw, &hTable_KHlQYXx9, true);
  numBytes += sTabread_init(&sTabread_fNPHlwMm, &hTable_Q5I7LvD0, true);
  numBytes += sTabread_init(&sTabread_O8Nzf9kN, &hTable_jySdBtVo, true);
  numBytes += sTabread_init(&sTabread_KTLNUQgj, &hTable_vassxs94, true);
  numBytes += sTabwrite_init(&sTabwrite_npESjic7, &hTable_7LfxGM68);
  numBytes += sTabwrite_init(&sTabwrite_UmNdxsVV, &hTable_ed4dzP1v);
  numBytes += sTabwrite_init(&sTabwrite_qgO6IXfk, &hTable_jySdBtVo);
  numBytes += sTabwrite_init(&sTabwrite_SEgP4thX, &hTable_Q5I7LvD0);
  numBytes += sTabwrite_init(&sTabwrite_h4UbNH6N, &hTable_KHlQYXx9);
  numBytes += sTabwrite_init(&sTabwrite_WNGsvgTv, &hTable_vassxs94);
  numBytes += sLine_init(&sLine_UaDf2nKt);
  numBytes += sTabread_init(&sTabread_287b4oh5, &hTable_YZR7BrKp, true);
  numBytes += sRPole_init(&sRPole_6QmZHFgI);
  numBytes += sTabread_init(&sTabread_fHBE5zox, &hTable_6RQ15tHQ, true);
  numBytes += sRPole_init(&sRPole_KnqFbkkZ);
  numBytes += sTabread_init(&sTabread_XgM7MCjD, &hTable_aFG3oJ94, true);
  numBytes += sRPole_init(&sRPole_lK7oXdFn);
  numBytes += sTabwrite_init(&sTabwrite_NiAwcgbj, &hTable_aFG3oJ94);
  numBytes += sTabwrite_init(&sTabwrite_bdfczrHz, &hTable_RXQA5BSx);
  numBytes += sTabwrite_init(&sTabwrite_eo3i8s4D, &hTable_YZR7BrKp);
  numBytes += sTabwrite_init(&sTabwrite_TvRTzorQ, &hTable_6RQ15tHQ);
  numBytes += sLine_init(&sLine_HUDYAN2U);
  numBytes += sLine_init(&sLine_xVktYncJ);
  numBytes += cVar_init_s(&cVar_MZyuKpsl, "floatatom");
  numBytes += cVar_init_f(&cVar_IBNg1qeo, 98.0f);
  numBytes += cIf_init(&cIf_K3Acz3SK, false);
  numBytes += cBinop_init(&cBinop_fzrQlUBr, 0.0f); // __pow
  numBytes += cPack_init(&cPack_JMWa4cFu, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_PPwh3jr2, 0.0f);
  numBytes += cRandom_init(&cRandom_82fhNWaF, 1479280588);
  numBytes += cSlice_init(&cSlice_u5imjPEP, 1, 1);
  numBytes += cBinop_init(&cBinop_f253eZ1l, 1.0f); // __pow
  numBytes += cRandom_init(&cRandom_3qs68nzi, 1107905724);
  numBytes += cSlice_init(&cSlice_kZN1w8N7, 1, 1);
  numBytes += cSlice_init(&cSlice_8a9gRL90, 1, 1);
  numBytes += cSlice_init(&cSlice_BT0HiEqz, 0, 1);
  numBytes += cPack_init(&cPack_MjBTWEfR, 2, 0.0f, 10.0f);
  numBytes += cPack_init(&cPack_tIvhH3p5, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_lCwYyBZF, 0.0f);
  numBytes += cDelay_init(this, &cDelay_5peHtRuo, 25.0f);
  numBytes += cVar_init_f(&cVar_XSnpUi0o, 0.0f);
  numBytes += sVarf_init(&sVarf_EIuT2fqi, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_GiN3QG1U, 1.0f);
  numBytes += cVar_init_f(&cVar_TjNMcqvZ, 0.0f);
  numBytes += cDelay_init(this, &cDelay_1qnhKvZ9, 2.0f);
  numBytes += cPack_init(&cPack_j8wxsOsu, 2, 0.0f, 2.0f);
  numBytes += cPack_init(&cPack_FYzMBkaY, 2, 0.0f, 0.0f);
  numBytes += cPack_init(&cPack_jKcCiv7a, 2, 0.0f, 4410000.0f);
  numBytes += cVar_init_f(&cVar_XqVNmeJ7, 1.0f);
  numBytes += cVar_init_s(&cVar_NZZWo5bx, "floatatom");
  numBytes += cVar_init_f(&cVar_RyS40cLD, 0.0f);
  numBytes += cVar_init_f(&cVar_jz3tGdki, 1.0f);
  numBytes += cBinop_init(&cBinop_2h47LjGu, 0.0f); // __div
  numBytes += cSlice_init(&cSlice_qcBgEtaq, 1, 1);
  numBytes += cSlice_init(&cSlice_9GeG4B5s, 0, 1);
  numBytes += cVar_init_s(&cVar_sTYvRhZ9, "1013_default");
  numBytes += cSlice_init(&cSlice_rmw4EA0j, 1, 1);
  numBytes += sVarf_init(&sVarf_HgSXPSnM, 0.0f, 0.0f, false);
  numBytes += cSlice_init(&cSlice_VHV4oP1k, 1, 1);
  numBytes += cSlice_init(&cSlice_mwUeFqx8, 0, 1);
  numBytes += cVar_init_s(&cVar_EqloIxkt, "floatatom");
  numBytes += cVar_init_s(&cVar_roaFw89G, "floatatom");
  numBytes += hTable_init(&hTable_AKQw9gB5, 1000);
  numBytes += cSlice_init(&cSlice_ubdBPvp7, 1, 1);
  numBytes += cSlice_init(&cSlice_Y32RxzaP, 0, 1);
  numBytes += cVar_init_f(&cVar_KXcAfqmU, 0.0f);
  numBytes += cPack_init(&cPack_2AeIl7oo, 2, 0.0f, 0.0f);
  numBytes += cBinop_init(&cBinop_C44j8RJg, 1.0f); // __mul
  numBytes += cBinop_init(&cBinop_NtklF6lA, 0.0f); // __div
  numBytes += cRandom_init(&cRandom_kwUSvw2u, -341142462);
  numBytes += cSlice_init(&cSlice_8EDJoabJ, 1, 1);
  numBytes += cBinop_init(&cBinop_Ppd5goO8, 1.0f); // __pow
  numBytes += cRandom_init(&cRandom_ZcejJIy1, -1035444672);
  numBytes += cSlice_init(&cSlice_QsoULHxF, 1, 1);
  numBytes += cSlice_init(&cSlice_5qKhvvY8, 1, 1);
  numBytes += cSlice_init(&cSlice_pfaPnV1i, 0, 1);
  numBytes += cPack_init(&cPack_32YTVbUD, 2, 0.0f, 10.0f);
  numBytes += cPack_init(&cPack_e5WkLpVn, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_3n85lNl6, 0.0f);
  numBytes += cDelay_init(this, &cDelay_XXe4aOsj, 25.0f);
  numBytes += cVar_init_f(&cVar_fuCyXzIE, 0.0f);
  numBytes += sVarf_init(&sVarf_3UEzL0uV, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_CuLuBKX3, 1.0f);
  numBytes += cVar_init_f(&cVar_2WqJlITT, 0.0f);
  numBytes += cDelay_init(this, &cDelay_tJ5A26Ex, 2.0f);
  numBytes += cPack_init(&cPack_bcYg07Ut, 2, 0.0f, 2.0f);
  numBytes += cPack_init(&cPack_f0L3zTiX, 2, 0.0f, 0.0f);
  numBytes += cPack_init(&cPack_5K877NH9, 2, 0.0f, 4410000.0f);
  numBytes += cVar_init_f(&cVar_L8oii4oq, 1.0f);
  numBytes += cVar_init_s(&cVar_DuQ4Co8P, "floatatom");
  numBytes += cVar_init_f(&cVar_CHWKAnDn, 0.0f);
  numBytes += cVar_init_f(&cVar_6qRZEOOM, 1.0f);
  numBytes += cBinop_init(&cBinop_PJW0hS1Y, 0.0f); // __div
  numBytes += cSlice_init(&cSlice_GkIAmfP8, 1, 1);
  numBytes += cSlice_init(&cSlice_5G7uBBwC, 0, 1);
  numBytes += cVar_init_s(&cVar_UyoDPMGJ, "1051_default");
  numBytes += cSlice_init(&cSlice_d3mfOe8P, 1, 1);
  numBytes += sVarf_init(&sVarf_bgDUH05l, 0.0f, 0.0f, false);
  numBytes += cSlice_init(&cSlice_SeWjqHEN, 1, 1);
  numBytes += cSlice_init(&cSlice_L70vIPrx, 0, 1);
  numBytes += cVar_init_s(&cVar_9zT65X1L, "floatatom");
  numBytes += cVar_init_s(&cVar_Ek55gQhE, "floatatom");
  numBytes += hTable_init(&hTable_qTT30gQb, 1000);
  numBytes += cSlice_init(&cSlice_hAc6aAxe, 1, 1);
  numBytes += cSlice_init(&cSlice_Nk0dsf1u, 0, 1);
  numBytes += cVar_init_f(&cVar_U4JpgUYy, 0.0f);
  numBytes += cPack_init(&cPack_jqVRSnP5, 2, 0.0f, 0.0f);
  numBytes += cBinop_init(&cBinop_7RNeH53b, 1.0f); // __mul
  numBytes += cBinop_init(&cBinop_LLQSv5U0, 0.0f); // __div
  numBytes += cRandom_init(&cRandom_giDhiHVP, 48424560);
  numBytes += cSlice_init(&cSlice_hRkciHrs, 1, 1);
  numBytes += cBinop_init(&cBinop_1fD3OqQY, 1.0f); // __pow
  numBytes += cRandom_init(&cRandom_NqAlEh4g, -408304770);
  numBytes += cSlice_init(&cSlice_be6oqhtN, 1, 1);
  numBytes += cSlice_init(&cSlice_6C9Y56FE, 1, 1);
  numBytes += cSlice_init(&cSlice_nWqnUC27, 0, 1);
  numBytes += cPack_init(&cPack_HHJNKIVQ, 2, 0.0f, 10.0f);
  numBytes += cPack_init(&cPack_WoUl5Yx9, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_48LijKnP, 0.0f);
  numBytes += cDelay_init(this, &cDelay_TN0k3zbQ, 25.0f);
  numBytes += cVar_init_f(&cVar_LMd39CXq, 0.0f);
  numBytes += sVarf_init(&sVarf_t5IYoLta, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_mncmhsWu, 1.0f);
  numBytes += cVar_init_f(&cVar_OC4NS0x6, 0.0f);
  numBytes += cDelay_init(this, &cDelay_sm6vop1m, 2.0f);
  numBytes += cPack_init(&cPack_mGtVf59g, 2, 0.0f, 2.0f);
  numBytes += cPack_init(&cPack_GBRJwljZ, 2, 0.0f, 0.0f);
  numBytes += cPack_init(&cPack_hsU2ZVWs, 2, 0.0f, 4410000.0f);
  numBytes += cVar_init_f(&cVar_7ILSpeEZ, 1.0f);
  numBytes += cVar_init_s(&cVar_xo4XpkPP, "floatatom");
  numBytes += cVar_init_f(&cVar_5eZ1CZic, 0.0f);
  numBytes += cVar_init_f(&cVar_dQ6Js9mW, 1.0f);
  numBytes += cBinop_init(&cBinop_58D7xTy2, 0.0f); // __div
  numBytes += cSlice_init(&cSlice_MqY07X5b, 1, 1);
  numBytes += cSlice_init(&cSlice_KtNQfHg4, 0, 1);
  numBytes += cVar_init_s(&cVar_LJONgNkw, "1089_default");
  numBytes += cSlice_init(&cSlice_0bUP7BVu, 1, 1);
  numBytes += sVarf_init(&sVarf_A6KZg1dy, 0.0f, 0.0f, false);
  numBytes += cSlice_init(&cSlice_9aEdFzKI, 1, 1);
  numBytes += cSlice_init(&cSlice_DR14GAwe, 0, 1);
  numBytes += cVar_init_s(&cVar_389VEx53, "floatatom");
  numBytes += cVar_init_s(&cVar_KLZkdgi7, "floatatom");
  numBytes += hTable_init(&hTable_dqgidaqB, 1000);
  numBytes += cSlice_init(&cSlice_YFizWWF7, 1, 1);
  numBytes += cSlice_init(&cSlice_QPio2HST, 0, 1);
  numBytes += cVar_init_f(&cVar_KSPhAnvf, 0.0f);
  numBytes += cPack_init(&cPack_WNx24O3v, 2, 0.0f, 0.0f);
  numBytes += cBinop_init(&cBinop_4MjNL4r0, 1.0f); // __mul
  numBytes += cBinop_init(&cBinop_Grfu0Ngg, 0.0f); // __div
  numBytes += cRandom_init(&cRandom_ED7Gc7D6, 1218905658);
  numBytes += cSlice_init(&cSlice_JBr92XSv, 1, 1);
  numBytes += cBinop_init(&cBinop_miWQIbJZ, 1.0f); // __pow
  numBytes += cRandom_init(&cRandom_Tcwnk59D, -844765408);
  numBytes += cSlice_init(&cSlice_vPtQRRQh, 1, 1);
  numBytes += cSlice_init(&cSlice_y01lKo1A, 1, 1);
  numBytes += cSlice_init(&cSlice_AwTrNThN, 0, 1);
  numBytes += cPack_init(&cPack_syicmNt1, 2, 0.0f, 10.0f);
  numBytes += cPack_init(&cPack_GTWpKLKc, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_RJx7ENeP, 0.0f);
  numBytes += cDelay_init(this, &cDelay_eAs8Zxr3, 25.0f);
  numBytes += cVar_init_f(&cVar_DLKm9DGg, 0.0f);
  numBytes += sVarf_init(&sVarf_xpi24x7y, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_enn6P9Y6, 1.0f);
  numBytes += cVar_init_f(&cVar_uaxbfDFT, 0.0f);
  numBytes += cDelay_init(this, &cDelay_BoWYccU7, 2.0f);
  numBytes += cPack_init(&cPack_SlB36N6g, 2, 0.0f, 2.0f);
  numBytes += cPack_init(&cPack_SqyneN7x, 2, 0.0f, 0.0f);
  numBytes += cPack_init(&cPack_0zjXZR82, 2, 0.0f, 4410000.0f);
  numBytes += cVar_init_f(&cVar_wY2x51Xz, 1.0f);
  numBytes += cVar_init_s(&cVar_PNeat1CU, "floatatom");
  numBytes += cVar_init_f(&cVar_wRCPAIcz, 0.0f);
  numBytes += cVar_init_f(&cVar_PZMNAqEr, 1.0f);
  numBytes += cBinop_init(&cBinop_Xak1JQ3h, 0.0f); // __div
  numBytes += cSlice_init(&cSlice_BzwFzVkh, 1, 1);
  numBytes += cSlice_init(&cSlice_OgHEb7k7, 0, 1);
  numBytes += cVar_init_s(&cVar_ZwMUgIzr, "1127_default");
  numBytes += cSlice_init(&cSlice_iA7e4URh, 1, 1);
  numBytes += sVarf_init(&sVarf_jIF40qTi, 0.0f, 0.0f, false);
  numBytes += cSlice_init(&cSlice_uCFw3d3O, 1, 1);
  numBytes += cSlice_init(&cSlice_SOSLB9w9, 0, 1);
  numBytes += cVar_init_s(&cVar_TnCsLt8s, "floatatom");
  numBytes += cVar_init_s(&cVar_mzdZbr49, "floatatom");
  numBytes += hTable_init(&hTable_bkykhA3v, 1000);
  numBytes += cSlice_init(&cSlice_QfiTVqux, 1, 1);
  numBytes += cSlice_init(&cSlice_GXEJBEBJ, 0, 1);
  numBytes += cVar_init_f(&cVar_16bc7eRS, 0.0f);
  numBytes += cPack_init(&cPack_oOdCKp9p, 2, 0.0f, 0.0f);
  numBytes += cBinop_init(&cBinop_MgYlK9We, 1.0f); // __mul
  numBytes += cBinop_init(&cBinop_yDNqQqM2, 0.0f); // __div
  numBytes += cVar_init_f(&cVar_Zn1ojjrH, 98.0f);
  numBytes += cIf_init(&cIf_RA7KvXe4, false);
  numBytes += cBinop_init(&cBinop_3HiO7cSt, 0.0f); // __pow
  numBytes += cPack_init(&cPack_vRGo39Wp, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_vKvuftOz, 0.0f);
  numBytes += cVar_init_f(&cVar_oPZ52NA3, 100.0f);
  numBytes += cIf_init(&cIf_SaUsJ7St, false);
  numBytes += cBinop_init(&cBinop_WiL0lRa1, 0.0f); // __pow
  numBytes += cPack_init(&cPack_qohOHo7T, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_gmMUMGJa, 0.0f);
  numBytes += cIf_init(&cIf_MRGtgAVW, false);
  numBytes += cVar_init_f(&cVar_2HkT7EA4, 97.0f);
  numBytes += cIf_init(&cIf_BCe4LD1P, false);
  numBytes += cBinop_init(&cBinop_E62IxLfI, 0.0f); // __pow
  numBytes += cPack_init(&cPack_SvkpEzkg, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_g2tD0tVi, 0.0f);
  numBytes += cVar_init_f(&cVar_6uEOTKW5, 97.0f);
  numBytes += cIf_init(&cIf_T59kyxne, false);
  numBytes += cBinop_init(&cBinop_hdAT2YoH, 0.0f); // __pow
  numBytes += cPack_init(&cPack_UrtS4zxp, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_id113mRK, 0.0f);
  numBytes += cPack_init(&cPack_IVZ00RuP, 2, 0.0f, 0.0f);
  numBytes += cSlice_init(&cSlice_tp36l5d9, 1, 1);
  numBytes += cSlice_init(&cSlice_3iNR7v2q, 0, 1);
  numBytes += cIf_init(&cIf_6rOONnze, false);
  numBytes += cIf_init(&cIf_gBDy3SwE, false);
  numBytes += cIf_init(&cIf_te413RcP, false);
  numBytes += cSlice_init(&cSlice_JsNDXk3i, 1, 1);
  numBytes += cSlice_init(&cSlice_j8g9TS4z, 0, 1);
  numBytes += cVar_init_f(&cVar_m8Ix3fHp, 0.0f);
  numBytes += cIf_init(&cIf_lSQrAVlP, false);
  numBytes += cPack_init(&cPack_9a733PFq, 2, 0.0f, 0.0f);
  numBytes += cSlice_init(&cSlice_xuydrICF, 1, -1);
  numBytes += cSlice_init(&cSlice_onIDdbjZ, 1, -1);
  numBytes += cSlice_init(&cSlice_1gy5ErY8, 1, -1);
  numBytes += cSlice_init(&cSlice_HqkuD6Lx, 1, -1);
  numBytes += cIf_init(&cIf_JocSBMRA, false);
  numBytes += cVar_init_f(&cVar_Gvx3wYfG, 1.0f);
  numBytes += cPack_init(&cPack_lA7P06zw, 3, 0.0f, 0.0f, 0.0f);
  numBytes += cVar_init_f(&cVar_TuXtPgx8, 0.0f);
  numBytes += hTable_init(&hTable_L5Asm0JQ, 36000);
  numBytes += hTable_init(&hTable_rwOMuyMM, 290000);
  numBytes += hTable_init(&hTable_SY2T5LAU, 288000);
  numBytes += hTable_init(&hTable_XZhy7ncS, 66000);
  numBytes += hTable_init(&hTable_ZnFQ5VXv, 25000);
  numBytes += hTable_init(&hTable_GoJVpFWT, 384000);
  numBytes += cSlice_init(&cSlice_UZOVBp1z, 2, 1);
  numBytes += cSlice_init(&cSlice_rutu4pRj, 1, 1);
  numBytes += cSlice_init(&cSlice_zCLfxfps, 0, 1);
  numBytes += cVar_init_f(&cVar_Majfm0GP, 0.0f);
  numBytes += cIf_init(&cIf_DWT53kAW, false);
  numBytes += cIf_init(&cIf_8IgWrNwI, false);
  numBytes += cIf_init(&cIf_6lhEfuBZ, false);
  numBytes += cIf_init(&cIf_n8BJSAmA, false);
  numBytes += cIf_init(&cIf_fsBm2IPb, false);
  numBytes += cBinop_init(&cBinop_ghFQYlsD, 0.0f); // __eq
  numBytes += cRandom_init(&cRandom_web4DBtt, -100515316);
  numBytes += cSlice_init(&cSlice_NrC9tRUh, 1, 1);
  numBytes += cRandom_init(&cRandom_rDm5AsVt, 358123132);
  numBytes += cSlice_init(&cSlice_zyB5iGBX, 1, 1);
  numBytes += cRandom_init(&cRandom_nspBAi22, 1752831495);
  numBytes += cSlice_init(&cSlice_OyLoHW9F, 1, 1);
  numBytes += cVar_init_s(&cVar_gY1fKd9A, "floatatom");
  numBytes += cPack_init(&cPack_wUQTNaBy, 2, 0.0f, 200.0f);
  numBytes += cPack_init(&cPack_uG1S7O8g, 2, 0.0f, 200.0f);
  numBytes += cVar_init_s(&cVar_5vS3geYi, "floatatom");
  numBytes += cDelay_init(this, &cDelay_sL1r7e6U, 0.0f);
  numBytes += cDelay_init(this, &cDelay_jDgXVZS6, 0.0f);
  numBytes += hTable_init(&hTable_zlt5GtL1, 256);
  numBytes += cVar_init_s(&cVar_lDaFAIiM, "del-1228-del");
  numBytes += sVarf_init(&sVarf_xUZp3MPJ, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_pymPXy7g, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_l3q2gskJ, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_YObsSk03, "del-1228-del");
  numBytes += sVarf_init(&sVarf_VPA9eOP7, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_JZG5yxNg, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_gj6OsYoC, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_3LyMW30U, 0.0f); // __div
  numBytes += cVar_init_s(&cVar_02AHW0Bq, "del-1257-del1");
  numBytes += sVarf_init(&sVarf_vqZaoEA2, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_BvHUiFWi, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_eOHSLqSm, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_8O9LuJpY, 10000.0f);
  numBytes += cBinop_init(&cBinop_tpsURXEj, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_dcmGhIc0, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_phgJDijJ, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_4hlqXWkV, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_LP6LfgeT, 10.0f);
  numBytes += cBinop_init(&cBinop_vF0MFQF5, 0.0f); // __div
  numBytes += sVarf_init(&sVarf_Rf6pjyZ3, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_ToE5dgSY, "floatatom");
  numBytes += sVarf_init(&sVarf_lm1HusbR, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_8gEUlKK0, 0.0f);
  numBytes += cDelay_init(this, &cDelay_9E0G1t33, 0.0f);
  numBytes += hTable_init(&hTable_TnZjyknh, 256);
  numBytes += sVarf_init(&sVarf_S5frDtKM, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_3fkpojuH, "floatatom");
  numBytes += cDelay_init(this, &cDelay_h8RoBNXp, 0.0f);
  numBytes += cVar_init_f(&cVar_UgLkOSfA, 20.0f);
  numBytes += cBinop_init(&cBinop_DNX0xulF, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_GfCKnBz5, 0.0f);
  numBytes += cSlice_init(&cSlice_4qt3HSST, 1, -1);
  numBytes += cSlice_init(&cSlice_MDlB0Uve, 1, -1);
  numBytes += cVar_init_f(&cVar_Xz5Bh72Y, 0.0f);
  numBytes += cVar_init_f(&cVar_wMvdCCPl, 20.0f);
  numBytes += cVar_init_f(&cVar_rEAPspkj, 0.0f);
  numBytes += cVar_init_f(&cVar_24AXcYGn, 0.0f);
  numBytes += cVar_init_f(&cVar_izcdXKzq, 0.0f);
  numBytes += cSlice_init(&cSlice_zRH4yHyo, 1, 1);
  numBytes += cSlice_init(&cSlice_iMw3JeXZ, 0, 1);
  numBytes += cBinop_init(&cBinop_JVHs3374, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_gAyoEMk9, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_BYwSiFqd, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_JIm1oOiy, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_yHzGJqcW, 20.0f); // __div
  numBytes += cBinop_init(&cBinop_bez6MEJQ, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_BFERekNs, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_5rP4odRF, 0.0f); // __sub
  numBytes += cVar_init_s(&cVar_sj0eyWaH, "floatatom");
  numBytes += cPack_init(&cPack_WcXObnvX, 2, 0.0f, 1000.0f);
  numBytes += cDelay_init(this, &cDelay_SWqSc0Mi, 0.0f);
  numBytes += cVar_init_f(&cVar_uhKWI9pg, 20.0f);
  numBytes += cBinop_init(&cBinop_WqQrj29e, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_vmVgUo89, 0.0f);
  numBytes += cSlice_init(&cSlice_VKfvcohg, 1, -1);
  numBytes += cSlice_init(&cSlice_Ts7aByXn, 1, -1);
  numBytes += cVar_init_f(&cVar_xWahpDBV, 0.0f);
  numBytes += cVar_init_f(&cVar_ZnO3YYb7, 20.0f);
  numBytes += cVar_init_f(&cVar_AYuVqWOR, 0.0f);
  numBytes += cVar_init_f(&cVar_f7zF4mz2, 0.0f);
  numBytes += cVar_init_f(&cVar_T6MbkFIw, 0.0f);
  numBytes += cSlice_init(&cSlice_Wg55a7ii, 1, 1);
  numBytes += cSlice_init(&cSlice_LNxXOEJe, 0, 1);
  numBytes += cBinop_init(&cBinop_hiFY5jud, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_LY9fZofX, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_9LoxOxwg, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_R0RVnxSW, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_E9HsfONy, 20.0f); // __div
  numBytes += cBinop_init(&cBinop_MYoPVutt, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_LqnklgtN, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_xzVUNQf1, 0.0f); // __sub
  numBytes += cPack_init(&cPack_XZZzNqh5, 2, 0.0f, 1000.0f);
  numBytes += cPack_init(&cPack_qcUSrU6Z, 2, 0.0f, 1000.0f);
  numBytes += cTabhead_init(&cTabhead_Ay9w28ta, &hTable_sOQFACjd);
  numBytes += cVar_init_s(&cVar_qN5QtCKP, "del-1318-del1");
  numBytes += cDelay_init(this, &cDelay_SuIHVgfJ, 58.6435f);
  numBytes += cDelay_init(this, &cDelay_ymHfVU7q, 0.0f);
  numBytes += cBinop_init(&cBinop_NzXum9ww, 58.6435f); // __mul
  numBytes += cBinop_init(&cBinop_BjnY4T2p, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_S9JTsZTG, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_CBh5T8lj, 0.0f); // __sub
  numBytes += cTabhead_init(&cTabhead_bsldNoGU, &hTable_kUXFxfS9);
  numBytes += cVar_init_s(&cVar_RkOG7nu9, "del-1318-del2");
  numBytes += cDelay_init(this, &cDelay_tcpHpV75, 69.4325f);
  numBytes += cDelay_init(this, &cDelay_ADk7FYJg, 0.0f);
  numBytes += cBinop_init(&cBinop_OVGgm29j, 69.4325f); // __mul
  numBytes += cBinop_init(&cBinop_LHeEEgBN, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_xZBMFHfM, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_EI15LN6J, 0.0f); // __sub
  numBytes += cTabhead_init(&cTabhead_MD15ck9x, &hTable_rQziADzR);
  numBytes += cVar_init_s(&cVar_jWsXkRIT, "del-1318-del3");
  numBytes += cDelay_init(this, &cDelay_wVPVkoPF, 74.5234f);
  numBytes += cDelay_init(this, &cDelay_AqjRr9T6, 0.0f);
  numBytes += cBinop_init(&cBinop_pcfCC84r, 74.5234f); // __mul
  numBytes += cBinop_init(&cBinop_sF4ENJM2, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_q29aaKXr, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_0PkkEWUW, 0.0f); // __sub
  numBytes += cTabhead_init(&cTabhead_po2Uy8VU, &hTable_yD5jEq6S);
  numBytes += cVar_init_s(&cVar_TfY1UwNu, "del-1318-del4");
  numBytes += cDelay_init(this, &cDelay_pMmJ1Df7, 86.1244f);
  numBytes += cDelay_init(this, &cDelay_Cj9J1iMM, 0.0f);
  numBytes += cBinop_init(&cBinop_DXjR5VWH, 86.1244f); // __mul
  numBytes += cBinop_init(&cBinop_I7QpVyNi, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_3cSSEd6Z, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_iQ4XrmSJ, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_dpHMaRhP, 0.0f);
  numBytes += cDelay_init(this, &cDelay_eDws7itv, 0.0f);
  numBytes += hTable_init(&hTable_sOQFACjd, 256);
  numBytes += cDelay_init(this, &cDelay_IIICVU7j, 0.0f);
  numBytes += cDelay_init(this, &cDelay_rojQnTDl, 0.0f);
  numBytes += hTable_init(&hTable_kUXFxfS9, 256);
  numBytes += cDelay_init(this, &cDelay_JjPn5IOz, 0.0f);
  numBytes += cDelay_init(this, &cDelay_aP3EnlNz, 0.0f);
  numBytes += hTable_init(&hTable_rQziADzR, 256);
  numBytes += cDelay_init(this, &cDelay_EGWAp475, 0.0f);
  numBytes += cDelay_init(this, &cDelay_t4wmRcyk, 0.0f);
  numBytes += hTable_init(&hTable_yD5jEq6S, 256);
  numBytes += cIf_init(&cIf_IvnndJbs, false);
  numBytes += cBinop_init(&cBinop_8tMHmxhJ, 0.0f); // __pow
  numBytes += cPack_init(&cPack_qr0uTD6a, 2, 0.0f, 30.0f);
  numBytes += cPack_init(&cPack_KIsxwZ1J, 2, 0.0f, 50.0f);
  numBytes += cVar_init_f(&cVar_4vurxjLg, 22050.0f);
  numBytes += cBinop_init(&cBinop_D4yvKrbp, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_rJYLNPto, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_5AQtq8SZ, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_8zmf3lwk, 95.0f);
  numBytes += cVar_init_f(&cVar_aVE88ycb, 90.0f);
  numBytes += cVar_init_f(&cVar_EHW2pJfr, 6000.0f);
  numBytes += cVar_init_f(&cVar_pb1QVppF, 60.0f);
  numBytes += cIf_init(&cIf_Th0OAbYU, false);
  numBytes += cTabhead_init(&cTabhead_h8J9M5Gk, &hTable_N3IEEdKO);
  numBytes += cVar_init_s(&cVar_qBNaUY0f, "del-1318-ref6");
  numBytes += cDelay_init(this, &cDelay_9uEjAW50, 13.645f);
  numBytes += cDelay_init(this, &cDelay_7i4fmIt3, 0.0f);
  numBytes += cBinop_init(&cBinop_oIgsgKG3, 13.645f); // __mul
  numBytes += cBinop_init(&cBinop_n6tFC0xQ, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_Mz76bQ0S, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_8SzqVjTS, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_KGSvr8CU, 0.0f);
  numBytes += cDelay_init(this, &cDelay_XBJx0zKQ, 0.0f);
  numBytes += hTable_init(&hTable_N3IEEdKO, 256);
  numBytes += cTabhead_init(&cTabhead_GiSLm0Ve, &hTable_il4LWkq0);
  numBytes += cVar_init_s(&cVar_Nn2QYeSd, "del-1318-ref5");
  numBytes += cDelay_init(this, &cDelay_mbFM2wzE, 16.364f);
  numBytes += cDelay_init(this, &cDelay_2la49ykd, 0.0f);
  numBytes += cBinop_init(&cBinop_NcSTL6If, 16.364f); // __mul
  numBytes += cBinop_init(&cBinop_3S0HTQWe, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_dn4S88k2, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_dPcUPzMT, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_ZI44pPse, 0.0f);
  numBytes += cDelay_init(this, &cDelay_FkFCpkOM, 0.0f);
  numBytes += hTable_init(&hTable_il4LWkq0, 256);
  numBytes += cTabhead_init(&cTabhead_jFneiBZ8, &hTable_9rKLAeez);
  numBytes += cVar_init_s(&cVar_cQfHPFbx, "del-1318-ref4");
  numBytes += cDelay_init(this, &cDelay_KLg3X0rz, 19.392f);
  numBytes += cDelay_init(this, &cDelay_JR5vGloY, 0.0f);
  numBytes += cBinop_init(&cBinop_Fxg7QNKn, 19.392f); // __mul
  numBytes += cBinop_init(&cBinop_nEBjSKLi, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_GuKsODtU, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_dClVABnj, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_dqi6WYq0, 0.0f);
  numBytes += cDelay_init(this, &cDelay_Knj7evc2, 0.0f);
  numBytes += hTable_init(&hTable_9rKLAeez, 256);
  numBytes += cTabhead_init(&cTabhead_238LxNEE, &hTable_KTYymZwO);
  numBytes += cVar_init_s(&cVar_uTpHW20o, "del-1318-ref3");
  numBytes += cDelay_init(this, &cDelay_Rgcc4RTY, 25.796f);
  numBytes += cDelay_init(this, &cDelay_otqKPZHd, 0.0f);
  numBytes += cBinop_init(&cBinop_gMStXXzI, 25.796f); // __mul
  numBytes += cBinop_init(&cBinop_fKzgxDLi, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_ELhLweBN, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_tWCQi8Gy, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_4sH5AWzX, 0.0f);
  numBytes += cDelay_init(this, &cDelay_4G3cDlx2, 0.0f);
  numBytes += hTable_init(&hTable_KTYymZwO, 256);
  numBytes += cTabhead_init(&cTabhead_Dmc8PtT0, &hTable_5Jlf3VuJ);
  numBytes += cVar_init_s(&cVar_6pBlUwqW, "del-1318-ref2");
  numBytes += cDelay_init(this, &cDelay_J4SKKNKl, 43.5337f);
  numBytes += cDelay_init(this, &cDelay_GqrbjDsV, 0.0f);
  numBytes += cBinop_init(&cBinop_DT5Fn2bd, 43.5337f); // __mul
  numBytes += cBinop_init(&cBinop_HL2myXQd, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_FGYiMKUs, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_u8Mls4kI, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_U43H4E6N, 0.0f);
  numBytes += cDelay_init(this, &cDelay_3YopkI0B, 0.0f);
  numBytes += hTable_init(&hTable_5Jlf3VuJ, 256);
  numBytes += cTabhead_init(&cTabhead_HKIPOkNn, &hTable_amukS8d7);
  numBytes += cVar_init_s(&cVar_tMoSExKz, "del-1318-ref1");
  numBytes += cDelay_init(this, &cDelay_tGccaxhl, 75.2546f);
  numBytes += cDelay_init(this, &cDelay_2hexzHdw, 0.0f);
  numBytes += cBinop_init(&cBinop_RS1dD6wF, 75.2546f); // __mul
  numBytes += cBinop_init(&cBinop_mVJUUq26, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_AufnJZYS, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_JeRy4QRV, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_kf0sMJ7C, 0.0f);
  numBytes += cDelay_init(this, &cDelay_MHDSXfwo, 0.0f);
  numBytes += hTable_init(&hTable_amukS8d7, 256);
  numBytes += cVar_init_f(&cVar_A5ugVD1y, 0.0f);
  numBytes += cVar_init_f(&cVar_ELbL87j9, 0.0f);
  numBytes += cPack_init(&cPack_g49bXLsX, 2, 0.0f, 50.0f);
  numBytes += cVar_init_f(&cVar_w9s8gsro, 22050.0f);
  numBytes += cBinop_init(&cBinop_8FJwXGk8, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_EdSrWJPJ, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_6GXKnDCJ, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_VMqS8U9a, 22050.0f);
  numBytes += cBinop_init(&cBinop_0dpQmVl7, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_XGtlPRgZ, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_khHH09UD, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_TbXZlErM, 22050.0f);
  numBytes += cBinop_init(&cBinop_Zf8XIbKC, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_HkIt0OkD, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_cMXIMxQ6, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_RWHaRdz0, 100.0f);
  numBytes += cIf_init(&cIf_vyUQpKzd, false);
  numBytes += cBinop_init(&cBinop_I2ENwsyn, 0.0f); // __pow
  numBytes += cPack_init(&cPack_UbYnhhcu, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_XHpwjSSN, 0.0f);
  numBytes += cIf_init(&cIf_qgkeLayB, false);
  numBytes += cIf_init(&cIf_TcceSJpW, false);
  numBytes += cDelay_init(this, &cDelay_00bfKwJX, 50.0f);
  numBytes += cVar_init_f(&cVar_eb8bh5Tb, 0.0f);
  numBytes += cVar_init_f(&cVar_yNkmr4rV, 12.0f);
  numBytes += cVar_init_s(&cVar_pYiV6Nwb, "floatatom");
  numBytes += cPack_init(&cPack_dp4DXsVD, 2, 0.0f, 200.0f);
  numBytes += cPack_init(&cPack_BfTeND35, 2, 0.0f, 200.0f);
  numBytes += cVar_init_s(&cVar_Z8uTrTks, "floatatom");
  numBytes += cDelay_init(this, &cDelay_XulUvEDr, 0.0f);
  numBytes += cDelay_init(this, &cDelay_xOKOV2RP, 0.0f);
  numBytes += hTable_init(&hTable_xeiqziG1, 256);
  numBytes += cVar_init_s(&cVar_bDdEds4R, "del-1436-del");
  numBytes += sVarf_init(&sVarf_C9TD0mPy, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_2LRolcvh, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_krc7fk4O, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_OsTtho3f, "del-1436-del");
  numBytes += sVarf_init(&sVarf_EiBAcfDc, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_p1jGECpz, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_ZSHKmGzo, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_9p5bqceG, 0.0f); // __div
  numBytes += cVar_init_f(&cVar_UwYm2B3w, 4720.0f);
  numBytes += cBinop_init(&cBinop_dYzXVGuk, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_Yh1CU5cO, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_kWAJOmwx, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_h9nbQXbI, 4720.0f);
  numBytes += cBinop_init(&cBinop_2HStWATz, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_g2lHkJLb, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_0T93HxmZ, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_6gGIbERR, 4720.0f);
  numBytes += cBinop_init(&cBinop_cmoWVJIv, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_DNLO2Q6E, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_Gcz4I6Xl, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_kTQEnTOC, 1.0f);
  numBytes += cIf_init(&cIf_ivMuJqsG, false);
  numBytes += sVarf_init(&sVarf_iYpB7zhT, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_JkevEWcv, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_gszK72BP, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_hs5c8nL0, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_bJgA5bbd, 4720.0f, 0.0f, false);
  numBytes += cTabhead_init(&cTabhead_6zhX7sLi, &hTable_RXQA5BSx);
  numBytes += cVar_init_s(&cVar_FRnRa57A, "del-1499-del1");
  numBytes += cDelay_init(this, &cDelay_47qGL36G, 58.6435f);
  numBytes += cDelay_init(this, &cDelay_EGy2SPYK, 0.0f);
  numBytes += cBinop_init(&cBinop_FOxlk4ls, 58.6435f); // __mul
  numBytes += cBinop_init(&cBinop_qGYudbvd, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_NmBa5KkM, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_y6IcNk58, 0.0f); // __sub
  numBytes += cTabhead_init(&cTabhead_yB2e39Ly, &hTable_6RQ15tHQ);
  numBytes += cVar_init_s(&cVar_TSmzWwYE, "del-1499-del2");
  numBytes += cDelay_init(this, &cDelay_2rktEiKe, 69.4325f);
  numBytes += cDelay_init(this, &cDelay_A9c8oUKr, 0.0f);
  numBytes += cBinop_init(&cBinop_MSUiSskw, 69.4325f); // __mul
  numBytes += cBinop_init(&cBinop_JQ8XH6mX, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_HmrFwopm, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_rnZmDjgm, 0.0f); // __sub
  numBytes += cTabhead_init(&cTabhead_YXrQA3J2, &hTable_aFG3oJ94);
  numBytes += cVar_init_s(&cVar_KgUstciN, "del-1499-del3");
  numBytes += cDelay_init(this, &cDelay_URspPdeT, 74.5234f);
  numBytes += cDelay_init(this, &cDelay_nZHNIorZ, 0.0f);
  numBytes += cBinop_init(&cBinop_MRJzFSvg, 74.5234f); // __mul
  numBytes += cBinop_init(&cBinop_RDsrnpUR, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_TtciRdhR, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_NG3d9ZnJ, 0.0f); // __sub
  numBytes += cTabhead_init(&cTabhead_Bnw0b04Z, &hTable_YZR7BrKp);
  numBytes += cVar_init_s(&cVar_hJUM360N, "del-1499-del4");
  numBytes += cDelay_init(this, &cDelay_mgXwiBoK, 86.1244f);
  numBytes += cDelay_init(this, &cDelay_vLcb7izi, 0.0f);
  numBytes += cBinop_init(&cBinop_GNUrXJ9X, 86.1244f); // __mul
  numBytes += cBinop_init(&cBinop_QPrQCP5y, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_22YsnUGx, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_RxJlMxmG, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_ytp7ZEuw, 0.0f);
  numBytes += cDelay_init(this, &cDelay_UZwrh0VI, 0.0f);
  numBytes += hTable_init(&hTable_RXQA5BSx, 256);
  numBytes += cDelay_init(this, &cDelay_d5wvg6tU, 0.0f);
  numBytes += cDelay_init(this, &cDelay_pmTy7lUW, 0.0f);
  numBytes += hTable_init(&hTable_6RQ15tHQ, 256);
  numBytes += cDelay_init(this, &cDelay_n0OB1FeM, 0.0f);
  numBytes += cDelay_init(this, &cDelay_c9saRde3, 0.0f);
  numBytes += hTable_init(&hTable_aFG3oJ94, 256);
  numBytes += cDelay_init(this, &cDelay_acmn9grK, 0.0f);
  numBytes += cDelay_init(this, &cDelay_Nk71rIHa, 0.0f);
  numBytes += hTable_init(&hTable_YZR7BrKp, 256);
  numBytes += cIf_init(&cIf_myXjAHwO, false);
  numBytes += cBinop_init(&cBinop_pWC2Hk8d, 0.0f); // __pow
  numBytes += cPack_init(&cPack_WxiN8UNo, 2, 0.0f, 30.0f);
  numBytes += cPack_init(&cPack_9tnPgoYv, 2, 0.0f, 50.0f);
  numBytes += cVar_init_f(&cVar_7zYxjbNP, 22050.0f);
  numBytes += cBinop_init(&cBinop_GhQk3VCt, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_0hSBxe28, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_YcnS4ewy, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_btS5VW3w, 100.0f);
  numBytes += cVar_init_f(&cVar_01PnFloa, 95.0f);
  numBytes += cVar_init_f(&cVar_Q68rrcEO, 14400.0f);
  numBytes += cVar_init_f(&cVar_ixLZUW9e, 60.0f);
  numBytes += cIf_init(&cIf_M3VNKe0r, false);
  numBytes += cTabhead_init(&cTabhead_4IJwIwRB, &hTable_vassxs94);
  numBytes += cVar_init_s(&cVar_qTOMUqko, "del-1499-ref6");
  numBytes += cDelay_init(this, &cDelay_Uoc7I2Qy, 13.645f);
  numBytes += cDelay_init(this, &cDelay_hGnCbDbN, 0.0f);
  numBytes += cBinop_init(&cBinop_EwnQNqi5, 13.645f); // __mul
  numBytes += cBinop_init(&cBinop_LR8ev6UM, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_Ora2jJZ1, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_mKnGw8Cb, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_M55PrVFx, 0.0f);
  numBytes += cDelay_init(this, &cDelay_wuuP7HUY, 0.0f);
  numBytes += hTable_init(&hTable_vassxs94, 256);
  numBytes += cTabhead_init(&cTabhead_ccb5gzCO, &hTable_jySdBtVo);
  numBytes += cVar_init_s(&cVar_YKuyqJkJ, "del-1499-ref5");
  numBytes += cDelay_init(this, &cDelay_TgQlUfGJ, 16.364f);
  numBytes += cDelay_init(this, &cDelay_3oeH2JBy, 0.0f);
  numBytes += cBinop_init(&cBinop_iufVIBxc, 16.364f); // __mul
  numBytes += cBinop_init(&cBinop_09UxVico, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_L7iCtTEe, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_ZQVRhEvd, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_WxrELUTQ, 0.0f);
  numBytes += cDelay_init(this, &cDelay_nTiAx3Z0, 0.0f);
  numBytes += hTable_init(&hTable_jySdBtVo, 256);
  numBytes += cTabhead_init(&cTabhead_RIhxzTXX, &hTable_Q5I7LvD0);
  numBytes += cVar_init_s(&cVar_4xtVoWQl, "del-1499-ref4");
  numBytes += cDelay_init(this, &cDelay_ia9QH5BZ, 19.392f);
  numBytes += cDelay_init(this, &cDelay_09LHT9W5, 0.0f);
  numBytes += cBinop_init(&cBinop_jiI111zV, 19.392f); // __mul
  numBytes += cBinop_init(&cBinop_1UigVVdD, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_gaKKwkFb, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_OrfZ4x0X, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_SIMNYWXy, 0.0f);
  numBytes += cDelay_init(this, &cDelay_dLmDm8cZ, 0.0f);
  numBytes += hTable_init(&hTable_Q5I7LvD0, 256);
  numBytes += cTabhead_init(&cTabhead_TNf1eExq, &hTable_KHlQYXx9);
  numBytes += cVar_init_s(&cVar_m3EZUm6A, "del-1499-ref3");
  numBytes += cDelay_init(this, &cDelay_ASYbIDGN, 25.796f);
  numBytes += cDelay_init(this, &cDelay_HxStVlIg, 0.0f);
  numBytes += cBinop_init(&cBinop_DQ4MuwHA, 25.796f); // __mul
  numBytes += cBinop_init(&cBinop_CYwbyEbL, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_4YXNhWpq, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_EbTason2, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_dzwLPIln, 0.0f);
  numBytes += cDelay_init(this, &cDelay_FtY8PYnt, 0.0f);
  numBytes += hTable_init(&hTable_KHlQYXx9, 256);
  numBytes += cTabhead_init(&cTabhead_akRr0TKx, &hTable_ed4dzP1v);
  numBytes += cVar_init_s(&cVar_Hz4wWSlG, "del-1499-ref2");
  numBytes += cDelay_init(this, &cDelay_5SF5c1Hw, 43.5337f);
  numBytes += cDelay_init(this, &cDelay_NbGYCTWS, 0.0f);
  numBytes += cBinop_init(&cBinop_IIySvyEu, 43.5337f); // __mul
  numBytes += cBinop_init(&cBinop_GRKCbLCV, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_iitru23p, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_0Xpe4POt, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_49X6shXY, 0.0f);
  numBytes += cDelay_init(this, &cDelay_LA1wd9KH, 0.0f);
  numBytes += hTable_init(&hTable_ed4dzP1v, 256);
  numBytes += cTabhead_init(&cTabhead_zgIRUxoj, &hTable_7LfxGM68);
  numBytes += cVar_init_s(&cVar_0Olyx67a, "del-1499-ref1");
  numBytes += cDelay_init(this, &cDelay_Uz12UbaY, 75.2546f);
  numBytes += cDelay_init(this, &cDelay_cC3ArdK1, 0.0f);
  numBytes += cBinop_init(&cBinop_5Ti2MG8l, 75.2546f); // __mul
  numBytes += cBinop_init(&cBinop_sIJAxyph, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_1JMoGwnu, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_iEojQvgv, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_tDqTr5Nd, 0.0f);
  numBytes += cDelay_init(this, &cDelay_ONIOIJpt, 0.0f);
  numBytes += hTable_init(&hTable_7LfxGM68, 256);
  numBytes += cVar_init_f(&cVar_yWYkELLa, 0.0f);
  numBytes += cVar_init_f(&cVar_fsUuWpD2, 0.0f);
  numBytes += cPack_init(&cPack_ezBvigzM, 2, 0.0f, 50.0f);
  numBytes += cVar_init_f(&cVar_FsHhjE6c, 22050.0f);
  numBytes += cBinop_init(&cBinop_aTXxggpL, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_dwUu67ZV, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_PmTLRsbz, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_MpIBnkWC, 22050.0f);
  numBytes += cBinop_init(&cBinop_h01BVglq, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_JXDtWNO1, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_Xpj6GjZf, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_YgoH762r, 22050.0f);
  numBytes += cBinop_init(&cBinop_z0DBgtW1, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_8luTeCv1, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_e1f2eTK1, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_1wlv4jAe, "del-1598-del1");
  numBytes += sVarf_init(&sVarf_3YLMKCtN, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_h9b0vrTz, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_HpEo7pyO, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_8thkYCby, 10000.0f);
  numBytes += cBinop_init(&cBinop_dst35s5q, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_ToQ7iRm0, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_VmXj2GYM, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_d18kc4ju, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_kFmB3ZJL, 10.0f);
  numBytes += cBinop_init(&cBinop_hJ41yyud, 0.0f); // __div
  numBytes += sVarf_init(&sVarf_aOyNmdiR, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_E2Te6apB, "floatatom");
  numBytes += sVarf_init(&sVarf_hmWBbNn7, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_E8pX8p1R, 0.0f);
  numBytes += cDelay_init(this, &cDelay_FgC9tAJs, 0.0f);
  numBytes += hTable_init(&hTable_Bf8NPbuA, 256);
  numBytes += sVarf_init(&sVarf_o6PpaNAI, 0.0f, 0.0f, false);
  numBytes += cPack_init(&cPack_hICvL53O, 2, 0.0f, 50.0f);
  numBytes += cVar_init_f(&cVar_L2jcM6y8, 1.0f);
  numBytes += cPack_init(&cPack_ay7lFJ2w, 2, 0.0f, 50.0f);
  numBytes += cRandom_init(&cRandom_J7tfB487, 20129892);
  numBytes += cSlice_init(&cSlice_XeyDd2ru, 1, 1);
  numBytes += cRandom_init(&cRandom_OyaBRWpn, -936999322);
  numBytes += cSlice_init(&cSlice_TyFfADbn, 1, 1);
  numBytes += cRandom_init(&cRandom_rljPhqci, 1098670691);
  numBytes += cSlice_init(&cSlice_VezPVhKA, 1, 1);
  numBytes += cPack_init(&cPack_WlmhFUbW, 4, 0.0f, 0.0f, 0.0f, 0.0f);
  numBytes += cVar_init_s(&cVar_Une0GPFu, "floatatom");
  numBytes += cVar_init_s(&cVar_sj8eJAp4, "floatatom");
  numBytes += cIf_init(&cIf_9sOuS4Oz, false);
  numBytes += cVar_init_s(&cVar_IecrjCGB, "floatatom");
  numBytes += cBinop_init(&cBinop_U8Ih02Gg, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_3Yz9bYNA, 72.07f); // __sub
  numBytes += cSlice_init(&cSlice_GASkMN1k, 1, -1);
  numBytes += cSlice_init(&cSlice_7S9RSbvK, 1, -1);
  numBytes += cVar_init_f(&cVar_IWPRAMQc, 5.0f);
  numBytes += cBinop_init(&cBinop_zxpxkyZX, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_LJNrNrgd, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_cVKoBcMM, 0.0f, 0.0f, false);
  numBytes += cSlice_init(&cSlice_UKaWzyTm, 1, 1);
  numBytes += cSlice_init(&cSlice_ywl0oAeO, 0, 1);
  numBytes += sVarf_init(&sVarf_riXES2ua, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_YLhzpjc3, 5.0f);
  numBytes += cBinop_init(&cBinop_e6PV01zX, 0.0f); // __div
  numBytes += sVarf_init(&sVarf_CwOYbibd, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_TmVT7cH2, 50.0f);
  numBytes += cVar_init_s(&cVar_hSX1EpJ3, "floatatom");
  numBytes += cDelay_init(this, &cDelay_QY0UbdAb, 350.0f);
  numBytes += cVar_init_s(&cVar_tJX4MQRi, "floatatom");
  numBytes += cVar_init_s(&cVar_0oEWHwnR, "floatatom");
  numBytes += cVar_init_s(&cVar_zIqdTANI, "floatatom");
  numBytes += cExpr_init(&cExpr_7E6tHPVK, &Heavy_SoundScraper::cExpr_7E6tHPVK_evaluate);
  numBytes += cVar_init_s(&cVar_0ui6xbPb, "floatatom");
  numBytes += cVar_init_f(&cVar_aT0m7Cx6, 0.0f);
  numBytes += cVar_init_f(&cVar_IzpMzzdU, 0.0f);
  numBytes += cVar_init_s(&cVar_BVhRq1tD, "1674_default");
  numBytes += cSlice_init(&cSlice_5eN5oJWM, 1, 1);
  numBytes += sVarf_init(&sVarf_1i3HKFFn, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_JiQ6bRd5, "1674_default");
  numBytes += cSlice_init(&cSlice_XbTlGqZD, 1, 1);
  numBytes += sVarf_init(&sVarf_pJMale4s, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_wurxiXrM, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_uvWzq1Ec, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_TB87PUyv, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_aEHBNCon, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_eaDVrtdO, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_w9M2pK8I, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_IATwDOb7, 0.0f); // __div
  numBytes += hTable_init(&hTable_adIMRuo0, 10000);
  numBytes += sVarf_init(&sVarf_sGelEI44, 0.0f, 0.0f, false);
  
  // schedule a message to trigger all loadbangs via the __hv_init receiver
  scheduleMessageForReceiver(0xCE5CC65B, msg_initWithBang(HV_MESSAGE_ON_STACK(1), 0));
}

Heavy_SoundScraper::~Heavy_SoundScraper() {
  cPack_free(&cPack_JMWa4cFu);
  cPack_free(&cPack_MjBTWEfR);
  cPack_free(&cPack_tIvhH3p5);
  cPack_free(&cPack_j8wxsOsu);
  cPack_free(&cPack_FYzMBkaY);
  cPack_free(&cPack_jKcCiv7a);
  hTable_free(&hTable_AKQw9gB5);
  cPack_free(&cPack_2AeIl7oo);
  cPack_free(&cPack_32YTVbUD);
  cPack_free(&cPack_e5WkLpVn);
  cPack_free(&cPack_bcYg07Ut);
  cPack_free(&cPack_f0L3zTiX);
  cPack_free(&cPack_5K877NH9);
  hTable_free(&hTable_qTT30gQb);
  cPack_free(&cPack_jqVRSnP5);
  cPack_free(&cPack_HHJNKIVQ);
  cPack_free(&cPack_WoUl5Yx9);
  cPack_free(&cPack_mGtVf59g);
  cPack_free(&cPack_GBRJwljZ);
  cPack_free(&cPack_hsU2ZVWs);
  hTable_free(&hTable_dqgidaqB);
  cPack_free(&cPack_WNx24O3v);
  cPack_free(&cPack_syicmNt1);
  cPack_free(&cPack_GTWpKLKc);
  cPack_free(&cPack_SlB36N6g);
  cPack_free(&cPack_SqyneN7x);
  cPack_free(&cPack_0zjXZR82);
  hTable_free(&hTable_bkykhA3v);
  cPack_free(&cPack_oOdCKp9p);
  cPack_free(&cPack_vRGo39Wp);
  cPack_free(&cPack_qohOHo7T);
  cPack_free(&cPack_SvkpEzkg);
  cPack_free(&cPack_UrtS4zxp);
  cPack_free(&cPack_IVZ00RuP);
  cPack_free(&cPack_9a733PFq);
  cPack_free(&cPack_lA7P06zw);
  hTable_free(&hTable_L5Asm0JQ);
  hTable_free(&hTable_rwOMuyMM);
  hTable_free(&hTable_SY2T5LAU);
  hTable_free(&hTable_XZhy7ncS);
  hTable_free(&hTable_ZnFQ5VXv);
  hTable_free(&hTable_GoJVpFWT);
  cPack_free(&cPack_wUQTNaBy);
  cPack_free(&cPack_uG1S7O8g);
  hTable_free(&hTable_zlt5GtL1);
  hTable_free(&hTable_TnZjyknh);
  cPack_free(&cPack_WcXObnvX);
  cPack_free(&cPack_XZZzNqh5);
  cPack_free(&cPack_qcUSrU6Z);
  hTable_free(&hTable_sOQFACjd);
  hTable_free(&hTable_kUXFxfS9);
  hTable_free(&hTable_rQziADzR);
  hTable_free(&hTable_yD5jEq6S);
  cPack_free(&cPack_qr0uTD6a);
  cPack_free(&cPack_KIsxwZ1J);
  hTable_free(&hTable_N3IEEdKO);
  hTable_free(&hTable_il4LWkq0);
  hTable_free(&hTable_9rKLAeez);
  hTable_free(&hTable_KTYymZwO);
  hTable_free(&hTable_5Jlf3VuJ);
  hTable_free(&hTable_amukS8d7);
  cPack_free(&cPack_g49bXLsX);
  cPack_free(&cPack_UbYnhhcu);
  cPack_free(&cPack_dp4DXsVD);
  cPack_free(&cPack_BfTeND35);
  hTable_free(&hTable_xeiqziG1);
  hTable_free(&hTable_RXQA5BSx);
  hTable_free(&hTable_6RQ15tHQ);
  hTable_free(&hTable_aFG3oJ94);
  hTable_free(&hTable_YZR7BrKp);
  cPack_free(&cPack_WxiN8UNo);
  cPack_free(&cPack_9tnPgoYv);
  hTable_free(&hTable_vassxs94);
  hTable_free(&hTable_jySdBtVo);
  hTable_free(&hTable_Q5I7LvD0);
  hTable_free(&hTable_KHlQYXx9);
  hTable_free(&hTable_ed4dzP1v);
  hTable_free(&hTable_7LfxGM68);
  cPack_free(&cPack_ezBvigzM);
  hTable_free(&hTable_Bf8NPbuA);
  cPack_free(&cPack_hICvL53O);
  cPack_free(&cPack_ay7lFJ2w);
  cPack_free(&cPack_WlmhFUbW);
  cExpr_free(&cExpr_7E6tHPVK);
  hTable_free(&hTable_adIMRuo0);
}

HvTable *Heavy_SoundScraper::getTableForHash(hv_uint32_t tableHash) {switch (tableHash) {
    case 0x58D371AD: return &hTable_AKQw9gB5; // 1013_default
    case 0x565019FD: return &hTable_qTT30gQb; // 1051_default
    case 0x262582C8: return &hTable_dqgidaqB; // 1089_default
    case 0x161BC6D4: return &hTable_bkykhA3v; // 1127_default
    case 0x9BCAD111: return &hTable_L5Asm0JQ; // bowl
    case 0x782CD90: return &hTable_rwOMuyMM; // crotale
    case 0x53C964B5: return &hTable_SY2T5LAU; // gong
    case 0xAC13AE99: return &hTable_XZhy7ncS; // marimba
    case 0x1FD931DF: return &hTable_ZnFQ5VXv; // xylo
    case 0x6F52CA74: return &hTable_GoJVpFWT; // almglocken
    case 0xE52DB2F5: return &hTable_zlt5GtL1; // del-1228-del
    case 0x7877CEE7: return &hTable_TnZjyknh; // del-1257-del1
    case 0xE3492292: return &hTable_sOQFACjd; // del-1318-del1
    case 0x2DF102BD: return &hTable_kUXFxfS9; // del-1318-del2
    case 0xEBD4F3B1: return &hTable_rQziADzR; // del-1318-del3
    case 0x447E84A6: return &hTable_yD5jEq6S; // del-1318-del4
    case 0xE998EFF7: return &hTable_N3IEEdKO; // del-1318-ref6
    case 0xD5FADC2B: return &hTable_il4LWkq0; // del-1318-ref5
    case 0x56C3B41A: return &hTable_9rKLAeez; // del-1318-ref4
    case 0x6832F2BA: return &hTable_KTYymZwO; // del-1318-ref3
    case 0x9EC1C279: return &hTable_5Jlf3VuJ; // del-1318-ref2
    case 0x4118789A: return &hTable_amukS8d7; // del-1318-ref1
    case 0x29E6AB85: return &hTable_xeiqziG1; // del-1436-del
    case 0xB9E5E01C: return &hTable_RXQA5BSx; // del-1499-del1
    case 0x63C2268: return &hTable_6RQ15tHQ; // del-1499-del2
    case 0xDBF320BC: return &hTable_aFG3oJ94; // del-1499-del3
    case 0x225643E: return &hTable_YZR7BrKp; // del-1499-del4
    case 0xB93A9FFB: return &hTable_vassxs94; // del-1499-ref6
    case 0xAD23DE07: return &hTable_jySdBtVo; // del-1499-ref5
    case 0x76D4D2B8: return &hTable_Q5I7LvD0; // del-1499-ref4
    case 0x93E20AE1: return &hTable_KHlQYXx9; // del-1499-ref3
    case 0x48A066F: return &hTable_ed4dzP1v; // del-1499-ref2
    case 0x73942DD6: return &hTable_7LfxGM68; // del-1499-ref1
    case 0x63F3A24F: return &hTable_Bf8NPbuA; // del-1598-del1
    case 0x93F54B3C: return &hTable_adIMRuo0; // 1674_default
    default: return nullptr;
  }
}

void Heavy_SoundScraper::scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) {
  switch (receiverHash) {
    case 0x676151E5: { // 1005-levelin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_5f3FvQpl_sendMessage);
      break;
    }
    case 0x4518BA34: { // 1005-levelout
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_q6o7mfie_sendMessage);
      break;
    }
    case 0xF2645EF2: { // 1013-cutoff
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_bcGB1aGC_sendMessage);
      break;
    }
    case 0x349D3D62: { // 1013-phase
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_PC7vIRkt_sendMessage);
      break;
    }
    case 0x6AE0114A: { // 1013-rel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_j108jHSS_sendMessage);
      break;
    }
    case 0x14D190E8: { // 1013-tableFreq
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_me6GXtaS_sendMessage);
      break;
    }
    case 0xC268AA1B: { // 1013-tableName
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_41RaPf9H_sendMessage);
      break;
    }
    case 0xE7AF8038: { // 1013-velocity
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_z6iEtg1P_sendMessage);
      break;
    }
    case 0x64DCFC2F: { // 1013-vol
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_5HY5fLM2_sendMessage);
      break;
    }
    case 0x76EF1A3A: { // 1051-cutoff
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_RT1zMGKA_sendMessage);
      break;
    }
    case 0x7AB5A036: { // 1051-phase
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_VzckN8pw_sendMessage);
      break;
    }
    case 0x729AEC23: { // 1051-rel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_KAf1xh4c_sendMessage);
      break;
    }
    case 0x78E1F133: { // 1051-tableFreq
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_5hQZcw1R_sendMessage);
      break;
    }
    case 0x6CE4754: { // 1051-tableName
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_2Rgd81on_sendMessage);
      break;
    }
    case 0xFD6A3B2A: { // 1051-velocity
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_TIg47hmJ_sendMessage);
      break;
    }
    case 0x6CE9CED9: { // 1051-vol
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_pJyJ8beI_sendMessage);
      break;
    }
    case 0xFA29A439: { // 1089-cutoff
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_CyRdbAJg_sendMessage);
      break;
    }
    case 0xAA863EF6: { // 1089-phase
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_zTsXD6YR_sendMessage);
      break;
    }
    case 0xAAA0A75E: { // 1089-rel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_dzV4DPcb_sendMessage);
      break;
    }
    case 0xCB432715: { // 1089-tableFreq
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_pwIe5pyd_sendMessage);
      break;
    }
    case 0xB7D5A2D4: { // 1089-tableName
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_sJLVG06s_sendMessage);
      break;
    }
    case 0xBBC64E67: { // 1089-velocity
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_FhL5QWRt_sendMessage);
      break;
    }
    case 0x720CB109: { // 1089-vol
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_ue79bHQD_sendMessage);
      break;
    }
    case 0x49109026: { // 1127-cutoff
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_RJ028IRF_sendMessage);
      break;
    }
    case 0x1ED22B32: { // 1127-phase
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_8ia9UA0J_sendMessage);
      break;
    }
    case 0xB70E01AA: { // 1127-rel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_r510TR8k_sendMessage);
      break;
    }
    case 0x47F0CA40: { // 1127-tableFreq
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_dA7RIHfw_sendMessage);
      break;
    }
    case 0x212E3ED2: { // 1127-tableName
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_WLjoD2qK_sendMessage);
      break;
    }
    case 0xD654287F: { // 1127-velocity
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_Ju1xS2TW_sendMessage);
      break;
    }
    case 0x4B190B33: { // 1127-vol
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_FGUdnHin_sendMessage);
      break;
    }
    case 0x1345C8C4: { // 1165-levelin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_mpWxdZ0C_sendMessage);
      break;
    }
    case 0x352D518B: { // 1165-levelout
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_H9uGa2DN_sendMessage);
      break;
    }
    case 0x1B80BC63: { // 1173-levelin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_kF0RAx1I_sendMessage);
      break;
    }
    case 0x85C9C328: { // 1173-levelout
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_KuzwHoLG_sendMessage);
      break;
    }
    case 0x7FA13EC5: { // 1183-levelin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_YzPn1YFy_sendMessage);
      break;
    }
    case 0xD9AC1997: { // 1183-levelout
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_C1lp9X1Z_sendMessage);
      break;
    }
    case 0xE3801E94: { // 1191-levelin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_Xk8uDKfY_sendMessage);
      break;
    }
    case 0x4DA02B5A: { // 1191-levelout
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_qRnOVDWs_sendMessage);
      break;
    }
    case 0x8DC08092: { // 1417-levelin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_gi3bKbGJ_sendMessage);
      break;
    }
    case 0xA51F5BFF: { // 1417-levelout
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_vcMb0WOz_sendMessage);
      break;
    }
    case 0x382EB97A: { // 1626-bend
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_viMpYEkR_sendMessage);
      break;
    }
    case 0xD613858: { // 1626-chunk-size
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_EZSbojeT_sendMessage);
      break;
    }
    case 0x2952A082: { // 1626-level
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_o8LH6hUa_sendMessage);
      break;
    }
    case 0xCC3056CB: { // 1626-loopstart
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_RUVe3pDV_sendMessage);
      break;
    }
    case 0x484C6410: { // 1626-pitch
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_hhNFlC8R_sendMessage);
      break;
    }
    case 0x83CDC26B: { // 1626-reset
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_MDy21nR2_sendMessage);
      break;
    }
    case 0xD475E50C: { // 1626-sample
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_SJ6Uh0vb_sendMessage);
      break;
    }
    case 0xAFE56AD8: { // 1626-sample-pitch
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_jMhwovL4_sendMessage);
      break;
    }
    case 0x739592F2: { // 1626-start
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_UdPOlQ82_sendMessage);
      break;
    }
    case 0x31B2C381: { // 1626-stop
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_i89foIcW_sendMessage);
      break;
    }
    case 0xD2002891: { // 1626-table
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_Do9nya8H_sendMessage);
      break;
    }
    case 0xEA3AE85E: { // 1626-transposition
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_t2ImK8S7_sendMessage);
      break;
    }
    case 0x692F7CB8: { // 1674-cents
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_iBd6GA39_sendMessage);
      break;
    }
    case 0x72CEA287: { // 1674-chunk-size
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_RoL1C3Kj_sendMessage);
      break;
    }
    case 0xA99117E0: { // 1674-chunk-size-samples
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_7EK9zeiH_sendMessage);
      break;
    }
    case 0xEA9C1FF4: { // 1674-read-point
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_JUsaRojU_sendMessage);
      break;
    }
    case 0x995DB636: { // 1674-read-pt
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_WM57f9yw_sendMessage);
      break;
    }
    case 0xD40026D1: { // 1674-size
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_Wd4NhQ0S_sendMessage);
      break;
    }
    case 0x2460F295: { // 1674-table
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_2UQQNm07_sendMessage);
      break;
    }
    case 0xCE5CC65B: { // __hv_init
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_tx2TCvlM_sendMessage);
      break;
    }
    case 0x67E37CA3: { // __hv_notein
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_j8Mz1NLg_sendMessage);
      break;
    }
    case 0x40AA4AF1: { // changesound
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_EEWf9xk7_sendMessage);
      break;
    }
    case 0xA41806F7: { // distortlevel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_WatQHk0Y_sendMessage);
      break;
    }
    case 0xFCD12E4C: { // mastervolume
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_mYumRgba_sendMessage);
      break;
    }
    case 0xEF5F3308: { // panTranslation
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_jlnIpbMW_sendMessage);
      break;
    }
    case 0x8B2148DD: { // pitch
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_fKOUPBDH_sendMessage);
      break;
    }
    case 0x4409C659: { // processeffects
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_KdXsCelA_sendMessage);
      break;
    }
    case 0x7B795C5A: { // resetsing
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_ZDc3behT_sendMessage);
      break;
    }
    case 0xA987B741: { // reverbvolume
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_Eklo03qa_sendMessage);
      break;
    }
    case 0x7FFAC478: { // sampleNameFreq
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_2ZtI90gj_sendMessage);
      break;
    }
    case 0x62D6FDDE: { // selectsound
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_JfpuuerB_sendMessage);
      break;
    }
    case 0x7AAE6786: { // sinPanAngle
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_zfd68FNh_sendMessage);
      break;
    }
    case 0x6731B2E0: { // sing
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_nsXxDOTw_sendMessage);
      break;
    }
    case 0x57292445: { // singlevel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_aEZ3Zkri_sendMessage);
      break;
    }
    case 0xC7DE3B07: { // singpitch
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_rRS6P44Y_sendMessage);
      break;
    }
    case 0x853B1BE7: { // velocity
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_jC4Mczgd_sendMessage);
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


void Heavy_SoundScraper::cReceive_2Rgd81on_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_U4JpgUYy, 1, m, &cVar_U4JpgUYy_sendMessage);
}

void Heavy_SoundScraper::cReceive_2UQQNm07_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_53DZ8J6A_sendMessage(_c, 0, m);
  cMsg_ui0jxnme_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cReceive_2ZtI90gj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPrint_onMessage(_c, m, "SET_TABLE");
  cSlice_onMessage(_c, &Context(_c)->cSlice_8a9gRL90, 0, m, &cSlice_8a9gRL90_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_BT0HiEqz, 0, m, &cSlice_BT0HiEqz_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_5qKhvvY8, 0, m, &cSlice_5qKhvvY8_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_pfaPnV1i, 0, m, &cSlice_pfaPnV1i_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_6C9Y56FE, 0, m, &cSlice_6C9Y56FE_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_nWqnUC27, 0, m, &cSlice_nWqnUC27_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_y01lKo1A, 0, m, &cSlice_y01lKo1A_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_AwTrNThN, 0, m, &cSlice_AwTrNThN_sendMessage);
  cSend_NDinRmyc_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cReceive_41RaPf9H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_KXcAfqmU, 1, m, &cVar_KXcAfqmU_sendMessage);
}

void Heavy_SoundScraper::cMsg_4QYcVSVZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSend_dJ6unXWg_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_DYbP67g4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_qRnOVDWs_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_id113mRK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_DYbP67g4_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_6uEOTKW5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_4QYcVSVZ_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_5IGkU8N8_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Eej5cfCi_sendMessage);
}

void Heavy_SoundScraper::cPack_UrtS4zxp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_QM37Rcsm, 0, m, NULL);
}

void Heavy_SoundScraper::cMsg_0jTb164h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_hdAT2YoH, HV_BINOP_POW, 0, m, &cBinop_hdAT2YoH_sendMessage);
}

void Heavy_SoundScraper::cBinop_4C68CTZJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_Jouqeh6Z_sendMessage);
}

void Heavy_SoundScraper::cCast_5IGkU8N8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_RNthU5G9_sendMessage);
}

void Heavy_SoundScraper::cCast_Eej5cfCi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_T59kyxne, 0, m, &cIf_T59kyxne_sendMessage);
}

void Heavy_SoundScraper::cBinop_Jouqeh6Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_hdAT2YoH, HV_BINOP_POW, 1, m, &cBinop_hdAT2YoH_sendMessage);
  cMsg_0jTb164h_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_RNthU5G9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_T59kyxne, 1, m, &cIf_T59kyxne_sendMessage);
}

void Heavy_SoundScraper::cIf_T59kyxne_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_Zwr6Hfpo_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_mgH5CSnn_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cMsg_Zwr6Hfpo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_UrtS4zxp, 0, m, &cPack_UrtS4zxp_sendMessage);
}

void Heavy_SoundScraper::cBinop_hdAT2YoH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_UrtS4zxp, 0, m, &cPack_UrtS4zxp_sendMessage);
}

void Heavy_SoundScraper::cBinop_mgH5CSnn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_4C68CTZJ_sendMessage);
}

void Heavy_SoundScraper::cSend_dJ6unXWg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_Xk8uDKfY_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cReceive_5HY5fLM2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_EIuT2fqi, m);
}

void Heavy_SoundScraper::cReceive_5f3FvQpl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_PPwh3jr2, 0, m, &cVar_PPwh3jr2_sendMessage);
}

void Heavy_SoundScraper::cReceive_5hQZcw1R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_LLQSv5U0, HV_BINOP_DIVIDE, 1, m, &cBinop_LLQSv5U0_sendMessage);
}

void Heavy_SoundScraper::cReceive_7EK9zeiH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_wurxiXrM, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_uvWzq1Ec, m);
}

void Heavy_SoundScraper::cMsg_21cYREHO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.15f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_WsWzdNjF_sendMessage);
}

void Heavy_SoundScraper::cBinop_4CiVB78z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 4.0f, 0, m, &cBinop_AFVWNj5e_sendMessage);
}

void Heavy_SoundScraper::cBinop_AFVWNj5e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_WcXObnvX, 0, m, &cPack_WcXObnvX_sendMessage);
}

void Heavy_SoundScraper::cBinop_EgR7aQyw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_4CiVB78z_sendMessage);
}

void Heavy_SoundScraper::cVar_3fkpojuH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cCast_NcKfd4xP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_Bdq0WgST_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cVar_sj0eyWaH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cPack_WcXObnvX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_zhZwLoax_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cPack_XZZzNqh5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_wa7M0Cv1_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_0JvXViD5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_3LyMW30U, HV_BINOP_DIVIDE, 0, m, &cBinop_3LyMW30U_sendMessage);
}

void Heavy_SoundScraper::cVar_YObsSk03_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_SMnvom2o_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_GKgeOSLt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_JZG5yxNg, m);
}

void Heavy_SoundScraper::cSystem_NKIP7EOa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_hfBwD0ul_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_VPA9eOP7, m);
}

void Heavy_SoundScraper::cMsg_SMnvom2o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_NKIP7EOa_sendMessage);
}

void Heavy_SoundScraper::cBinop_hfBwD0ul_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_gj6OsYoC, m);
}

void Heavy_SoundScraper::cMsg_1OPB8C3l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_AkD6AQBv_sendMessage);
}

void Heavy_SoundScraper::cSystem_AkD6AQBv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_GKgeOSLt_sendMessage);
}

void Heavy_SoundScraper::cBinop_3LyMW30U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_n4i9wjUG_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_MX3WAOkL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_3LyMW30U, HV_BINOP_DIVIDE, 1, m, &cBinop_3LyMW30U_sendMessage);
}

void Heavy_SoundScraper::cBinop_OsO9JWCJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_gvfGqYF2_sendMessage);
}

void Heavy_SoundScraper::cBinop_RpxN8fwg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.001f, 0, m, &cBinop_j5n1Hth5_sendMessage);
  cPack_onMessage(_c, &Context(_c)->cPack_wUQTNaBy, 0, m, &cPack_wUQTNaBy_sendMessage);
}

void Heavy_SoundScraper::cMsg_Sj0NUwr7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 100.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_gY1fKd9A, 0, m, &cVar_gY1fKd9A_sendMessage);
}

void Heavy_SoundScraper::cBinop_1HqYy2pn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_pymPXy7g, m);
}

void Heavy_SoundScraper::cSystem_BEh7nvID_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_LFX6ALvj_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_xUZp3MPJ, m);
}

void Heavy_SoundScraper::cBinop_LFX6ALvj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_l3q2gskJ, m);
}

void Heavy_SoundScraper::cSystem_Ub6hZTeD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_1HqYy2pn_sendMessage);
}

void Heavy_SoundScraper::cMsg_iQKVE74E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Ub6hZTeD_sendMessage);
}

void Heavy_SoundScraper::cMsg_iwbptpJ2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_BEh7nvID_sendMessage);
}

void Heavy_SoundScraper::cVar_lDaFAIiM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_iwbptpJ2_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_gvfGqYF2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_3LyMW30U, HV_BINOP_DIVIDE, 0, m, &cBinop_3LyMW30U_sendMessage);
}

void Heavy_SoundScraper::cBinop_j5n1Hth5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_MX3WAOkL_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_0JvXViD5_sendMessage);
}

void Heavy_SoundScraper::cMsg_jOZg8GKF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.5f);
  cVar_onMessage(_c, &Context(_c)->cVar_5vS3geYi, 0, m, &cVar_5vS3geYi_sendMessage);
}

void Heavy_SoundScraper::cMsg_n4i9wjUG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 30.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_0ZnGXISG, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_nNoHMgri_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 87.3365f, 0, m, &cBinop_zKYOzcca_sendMessage);
}

void Heavy_SoundScraper::cVar_gY1fKd9A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_RpxN8fwg_sendMessage);
}

void Heavy_SoundScraper::cBinop_t3FDN9s5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_uG1S7O8g, 0, m, &cPack_uG1S7O8g_sendMessage);
}

void Heavy_SoundScraper::cPack_uG1S7O8g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_AV6C8lwf, 0, m, NULL);
}

void Heavy_SoundScraper::cPack_wUQTNaBy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_6zA7jM3e, 0, m, NULL);
}

void Heavy_SoundScraper::cVar_5vS3geYi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.5f, 0, m, &cBinop_t3FDN9s5_sendMessage);
}

void Heavy_SoundScraper::cMsg_11fOa6ve_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_zlt5GtL1, 0, m, &hTable_zlt5GtL1_sendMessage);
}

void Heavy_SoundScraper::cMsg_FQkwkhHy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_zlt5GtL1, 0, m, &hTable_zlt5GtL1_sendMessage);
}

void Heavy_SoundScraper::cMsg_HrjqxjhO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_68ZEmoet, 1, m, NULL);
}

void Heavy_SoundScraper::cSwitchcase_VRPF9nBu_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_HrjqxjhO_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_WnjfZeMl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_11fOa6ve_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_YJTiMYJU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 5000.0f, 0, m, &cBinop_WnjfZeMl_sendMessage);
}

void Heavy_SoundScraper::cMsg_bV4kjYn9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_jDgXVZS6, 2, m, &cDelay_jDgXVZS6_sendMessage);
}

void Heavy_SoundScraper::cCast_iAHfQVk2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_sL1r7e6U, 0, m, &cDelay_sL1r7e6U_sendMessage);
}

void Heavy_SoundScraper::cMsg_E1XDLAi8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_YwXoKQlz_sendMessage);
}

void Heavy_SoundScraper::cSystem_YwXoKQlz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_YJTiMYJU_sendMessage);
}

void Heavy_SoundScraper::cDelay_jDgXVZS6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_jDgXVZS6, m);
  cMsg_FQkwkhHy_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_sL1r7e6U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_sL1r7e6U, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_jDgXVZS6, 0, m, &cDelay_jDgXVZS6_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_sL1r7e6U, 0, m, &cDelay_sL1r7e6U_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_68ZEmoet, 1, m, NULL);
}

void Heavy_SoundScraper::hTable_zlt5GtL1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_bV4kjYn9_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_sL1r7e6U, 2, m, &cDelay_sL1r7e6U_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_iAHfQVk2_sendMessage);
}

void Heavy_SoundScraper::cUnop_PJIYcAZu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_OsO9JWCJ_sendMessage);
}

void Heavy_SoundScraper::cBinop_zKYOzcca_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_EXP, m, &cUnop_PJIYcAZu_sendMessage);
}

void Heavy_SoundScraper::cBinop_3YbyLICf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_G4enNZXX_sendMessage);
}

void Heavy_SoundScraper::cUnop_G4enNZXX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_XZZzNqh5, 0, m, &cPack_XZZzNqh5_sendMessage);
}

void Heavy_SoundScraper::cSlice_OyLoHW9F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_nspBAi22, 1, m, &cRandom_nspBAi22_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSwitchcase_fgh7z5V9_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_OyLoHW9F, 0, m, &cSlice_OyLoHW9F_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_nspBAi22, 0, m, &cRandom_nspBAi22_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cRandom_nspBAi22_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 200.0f, 0, m, &cBinop_3YbyLICf_sendMessage);
}

void Heavy_SoundScraper::cCast_0JckHJRu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_3vMJ3ti6_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_rEAPspkj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_5rP4odRF, HV_BINOP_SUBTRACT, 1, m, &cBinop_5rP4odRF_sendMessage);
}

void Heavy_SoundScraper::cMsg_3vMJ3ti6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_vcB28aBV_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cVar_izcdXKzq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_JIm1oOiy, HV_BINOP_ADD, 0, m, &cBinop_JIm1oOiy_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_BFERekNs, HV_BINOP_ADD, 0, m, &cBinop_BFERekNs_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_sj0eyWaH, 0, m, &cVar_sj0eyWaH_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.05776f, 0, m, &cBinop_nNoHMgri_sendMessage);
}

void Heavy_SoundScraper::cBinop_5rP4odRF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_bez6MEJQ, HV_BINOP_DIVIDE, 0, m, &cBinop_bez6MEJQ_sendMessage);
}

void Heavy_SoundScraper::cMsg_7GkuHEDs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 20.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_gAyoEMk9, HV_BINOP_MULTIPLY, 0, m, &cBinop_gAyoEMk9_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_yHzGJqcW, HV_BINOP_DIVIDE, 1, m, &cBinop_yHzGJqcW_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_UgLkOSfA, 0, m, &cVar_UgLkOSfA_sendMessage);
}

void Heavy_SoundScraper::cVar_UgLkOSfA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_DNX0xulF, HV_BINOP_MULTIPLY, 0, m, &cBinop_DNX0xulF_sendMessage);
}

void Heavy_SoundScraper::cBinop_DNX0xulF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_coOqk6Hv_sendMessage);
}

void Heavy_SoundScraper::cMsg_Tmg1ZyNb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_h8RoBNXp, 0, m, &cDelay_h8RoBNXp_sendMessage);
}

void Heavy_SoundScraper::cBinop_coOqk6Hv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_h8RoBNXp, 2, m, &cDelay_h8RoBNXp_sendMessage);
}

void Heavy_SoundScraper::cDelay_h8RoBNXp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_h8RoBNXp, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_h8RoBNXp, 0, m, &cDelay_h8RoBNXp_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_GfCKnBz5, 0, m, &cVar_GfCKnBz5_sendMessage);
}

void Heavy_SoundScraper::cSystem_CicYzqYX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_stQyNYdN_sendMessage);
}

void Heavy_SoundScraper::cMsg_tEOBkZds_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_CicYzqYX_sendMessage);
}

void Heavy_SoundScraper::cBinop_stQyNYdN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_DNX0xulF, HV_BINOP_MULTIPLY, 1, m, &cBinop_DNX0xulF_sendMessage);
}

void Heavy_SoundScraper::cCast_XrLsB1HP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Tmg1ZyNb_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_h8RoBNXp, 0, m, &cDelay_h8RoBNXp_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_GfCKnBz5, 0, m, &cVar_GfCKnBz5_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_vcB28aBV_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cMsg_Tmg1ZyNb_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_Tmg1ZyNb_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_XrLsB1HP_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_83uf3TZ0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_BYwSiFqd, HV_BINOP_SUBTRACT, 1, m, &cBinop_BYwSiFqd_sendMessage);
}

void Heavy_SoundScraper::cMsg_6pwWbFDF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_UZP5YOBU_sendMessage);
}

void Heavy_SoundScraper::cSystem_UZP5YOBU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_gAyoEMk9, HV_BINOP_MULTIPLY, 1, m, &cBinop_gAyoEMk9_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_JVHs3374, HV_BINOP_MULTIPLY, 1, m, &cBinop_JVHs3374_sendMessage);
}

void Heavy_SoundScraper::cBinop_BFERekNs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_rEAPspkj, 0, m, &cVar_rEAPspkj_sendMessage);
}

void Heavy_SoundScraper::cBinop_BYwSiFqd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_GfCKnBz5, 1, m, &cVar_GfCKnBz5_sendMessage);
}

void Heavy_SoundScraper::cCast_GiHmVh9X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_i2sWEAqS_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_Iopt7YnK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_24AXcYGn, 0, m, &cVar_24AXcYGn_sendMessage);
}

void Heavy_SoundScraper::cBinop_JIm1oOiy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_izcdXKzq, 1, m, &cVar_izcdXKzq_sendMessage);
}

void Heavy_SoundScraper::cBinop_JVHs3374_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_pJnY0ooD_sendMessage);
}

void Heavy_SoundScraper::cCast_OnXbEHIO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_JVHs3374, HV_BINOP_MULTIPLY, 0, m, &cBinop_JVHs3374_sendMessage);
}

void Heavy_SoundScraper::cCast_SZLN7VJY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_5rP4odRF, HV_BINOP_SUBTRACT, 0, m, &cBinop_5rP4odRF_sendMessage);
}

void Heavy_SoundScraper::cCast_Q8GQi8Az_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_7GkuHEDs_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_wxEDt9Ux_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Q8GQi8Az_sendMessage);
      break;
    }
    default: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_gAyoEMk9, HV_BINOP_MULTIPLY, 0, m, &cBinop_gAyoEMk9_sendMessage);
      cBinop_onMessage(_c, &Context(_c)->cBinop_yHzGJqcW, HV_BINOP_DIVIDE, 1, m, &cBinop_yHzGJqcW_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_UgLkOSfA, 0, m, &cVar_UgLkOSfA_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cMsg_X7MhIFbv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_vcB28aBV_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_Z2zEx5te_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Xz5Bh72Y, 0, m, &cVar_Xz5Bh72Y_sendMessage);
}

void Heavy_SoundScraper::cCast_a74RPXwG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_24AXcYGn, 1, m, &cVar_24AXcYGn_sendMessage);
}

void Heavy_SoundScraper::cBinop_bez6MEJQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_BFERekNs, HV_BINOP_ADD, 1, m, &cBinop_BFERekNs_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_JIm1oOiy, HV_BINOP_ADD, 1, m, &cBinop_JIm1oOiy_sendMessage);
}

void Heavy_SoundScraper::cCast_SuYVfIub_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_GiHmVh9X_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Iopt7YnK_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_XHTKk4op_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_YHte8WpM_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_SuYVfIub_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_YHte8WpM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_izcdXKzq, 0, m, &cVar_izcdXKzq_sendMessage);
}

void Heavy_SoundScraper::cCast_d4SSKImG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_q6P4Fhjl_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_24AXcYGn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_izcdXKzq, 0, m, &cVar_izcdXKzq_sendMessage);
}

void Heavy_SoundScraper::cBinop_gAyoEMk9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_83uf3TZ0_sendMessage);
}

void Heavy_SoundScraper::cVar_Xz5Bh72Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_OnXbEHIO_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_u7QN2xJi_sendMessage);
}

void Heavy_SoundScraper::cMsg_i2sWEAqS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_vcB28aBV_onMessage(_c, NULL, 0, m, NULL);
  cBinop_onMessage(_c, &Context(_c)->cBinop_BFERekNs, HV_BINOP_ADD, 1, m, &cBinop_BFERekNs_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_JIm1oOiy, HV_BINOP_ADD, 1, m, &cBinop_JIm1oOiy_sendMessage);
}

void Heavy_SoundScraper::cSlice_4qt3HSST_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_3vMJ3ti6_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_3vMJ3ti6_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_MDlB0Uve_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_0JckHJRu_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_zLOIMMzk_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_0JckHJRu_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_zLOIMMzk_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSwitchcase_zhZwLoax_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cSlice_onMessage(_c, &Context(_c)->cSlice_4qt3HSST, 0, m, &cSlice_4qt3HSST_sendMessage);
      break;
    }
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_MDlB0Uve, 0, m, &cSlice_MDlB0Uve_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Z2zEx5te_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_zRH4yHyo, 0, m, &cSlice_zRH4yHyo_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_iMw3JeXZ, 0, m, &cSlice_iMw3JeXZ_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_pCdhdlef_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_d4SSKImG_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cVar_GfCKnBz5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_BYwSiFqd, HV_BINOP_SUBTRACT, 0, m, &cBinop_BYwSiFqd_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_LESS_THAN_EQL, 0.0f, 0, m, &cBinop_uZzF3Ixh_sendMessage);
}

void Heavy_SoundScraper::cSlice_iMw3JeXZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_a74RPXwG_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_SZLN7VJY_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_zRH4yHyo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_OnXbEHIO_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_u7QN2xJi_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cCast_pCdhdlef_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_X7MhIFbv_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_pJnY0ooD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_GfCKnBz5, 1, m, &cVar_GfCKnBz5_sendMessage);
}

void Heavy_SoundScraper::cMsg_q6P4Fhjl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_Xz5Bh72Y, 1, m, &cVar_Xz5Bh72Y_sendMessage);
}

void Heavy_SoundScraper::cCast_u7QN2xJi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_yHzGJqcW, HV_BINOP_DIVIDE, 0, m, &cBinop_yHzGJqcW_sendMessage);
}

void Heavy_SoundScraper::cBinop_uZzF3Ixh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_XHTKk4op_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cVar_wMvdCCPl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_wxEDt9Ux_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_yHzGJqcW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_bez6MEJQ, HV_BINOP_DIVIDE, 1, m, &cBinop_bez6MEJQ_sendMessage);
}

void Heavy_SoundScraper::cCast_zLOIMMzk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_zWOm0NvF_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_BFERekNs, HV_BINOP_ADD, 0, m, &cBinop_BFERekNs_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_izcdXKzq, 1, m, &cVar_izcdXKzq_sendMessage);
}

void Heavy_SoundScraper::cCast_zWOm0NvF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_i2sWEAqS_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_kY6DhUSe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_fgh7z5V9_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_3jqA1lV6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_S5frDtKM, m);
}

void Heavy_SoundScraper::cBinop_WsWzdNjF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, -1.0f, 0, m, &cBinop_3jqA1lV6_sendMessage);
}

void Heavy_SoundScraper::cMsg_29LIlaOf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cMsg_32B8qYsX_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_32B8qYsX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 20.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_JxCbhdLP, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_9GHlIlKa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_eOHSLqSm, m);
}

void Heavy_SoundScraper::cVar_02AHW0Bq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_XIEBpbZK_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_XIEBpbZK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_bi9h8UQd_sendMessage);
}

void Heavy_SoundScraper::cSystem_bi9h8UQd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_9GHlIlKa_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_vqZaoEA2, m);
}

void Heavy_SoundScraper::cSystem_go72n3cB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_wTGGx3a7_sendMessage);
}

void Heavy_SoundScraper::cMsg_r5QMKXHk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_go72n3cB_sendMessage);
}

void Heavy_SoundScraper::cBinop_wTGGx3a7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_BvHUiFWi, m);
}

void Heavy_SoundScraper::cMsg_6IzpFg3r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_fO5JNITB, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_8gEUlKK0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_8gEUlKK0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_9E0G1t33, 0, m, &cDelay_9E0G1t33_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_8gEUlKK0, 0, m, &cDelay_8gEUlKK0_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_fO5JNITB, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_9E0G1t33_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_9E0G1t33, m);
  cMsg_TSENKbWz_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_KB1XW69P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_8gEUlKK0, 0, m, &cDelay_8gEUlKK0_sendMessage);
}

void Heavy_SoundScraper::cMsg_TSENKbWz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_TnZjyknh, 0, m, &hTable_TnZjyknh_sendMessage);
}

void Heavy_SoundScraper::hTable_TnZjyknh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_VyRFaIWy_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_8gEUlKK0, 2, m, &cDelay_8gEUlKK0_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_KB1XW69P_sendMessage);
}

void Heavy_SoundScraper::cMsg_Tv8sv2VF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_TnZjyknh, 0, m, &hTable_TnZjyknh_sendMessage);
}

void Heavy_SoundScraper::cMsg_VyRFaIWy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_9E0G1t33, 2, m, &cDelay_9E0G1t33_sendMessage);
}

void Heavy_SoundScraper::cBinop_chdZhT2B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 200.0f, 0, m, &cBinop_iE7W71iG_sendMessage);
}

void Heavy_SoundScraper::cSystem_0B0Lib5T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_chdZhT2B_sendMessage);
}

void Heavy_SoundScraper::cMsg_SR7hPznG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_0B0Lib5T_sendMessage);
}

void Heavy_SoundScraper::cBinop_iE7W71iG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Tv8sv2VF_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_uKzYBkck_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_6IzpFg3r_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cVar_ToE5dgSY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_32B8qYsX_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_AyBSTvQl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_dcmGhIc0, m);
}

void Heavy_SoundScraper::cBinop_ORLQgjdS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_tpsURXEj, HV_BINOP_MULTIPLY, 1, m, &cBinop_tpsURXEj_sendMessage);
}

void Heavy_SoundScraper::cMsg_fVfsr6BU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_ORLQgjdS_sendMessage);
}

void Heavy_SoundScraper::cBinop_tpsURXEj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_lbIiWvQj_sendMessage);
}

void Heavy_SoundScraper::cSystem_LQVVX95x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_fVfsr6BU_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_Qfn39Lqf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_LQVVX95x_sendMessage);
}

void Heavy_SoundScraper::cVar_8O9LuJpY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_tpsURXEj, HV_BINOP_MULTIPLY, 0, m, &cBinop_tpsURXEj_sendMessage);
}

void Heavy_SoundScraper::cBinop_Z1nbb8tR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_AyBSTvQl_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_phgJDijJ, m);
}

void Heavy_SoundScraper::cBinop_lbIiWvQj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_Z1nbb8tR_sendMessage);
}

void Heavy_SoundScraper::cBinop_BCdM9s6b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_4hlqXWkV, m);
}

void Heavy_SoundScraper::cBinop_5vw9qF0Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_Ikzopo2u_sendMessage);
}

void Heavy_SoundScraper::cBinop_Ikzopo2u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_dPpdiuon_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_BCdM9s6b_sendMessage);
}

void Heavy_SoundScraper::cBinop_MKYi30Ru_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_YDIiTzgP_sendMessage);
}

void Heavy_SoundScraper::cBinop_S25VxXuR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_Rf6pjyZ3, m);
}

void Heavy_SoundScraper::cBinop_VTkRp2LD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_5vw9qF0Z_sendMessage);
}

void Heavy_SoundScraper::cBinop_YDIiTzgP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_vF0MFQF5, HV_BINOP_DIVIDE, 0, m, &cBinop_vF0MFQF5_sendMessage);
}

void Heavy_SoundScraper::cBinop_dPpdiuon_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_S25VxXuR_sendMessage);
}

void Heavy_SoundScraper::cVar_LP6LfgeT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_MKYi30Ru_sendMessage);
}

void Heavy_SoundScraper::cMsg_4w972H37_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Xy9VOMEQ_sendMessage);
}

void Heavy_SoundScraper::cSystem_Xy9VOMEQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_vF0MFQF5, HV_BINOP_DIVIDE, 1, m, &cBinop_vF0MFQF5_sendMessage);
}

void Heavy_SoundScraper::cMsg_tyHRiS7V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_VTkRp2LD_sendMessage);
}

void Heavy_SoundScraper::cBinop_vF0MFQF5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_tyHRiS7V_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_qcUSrU6Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_1gpI2VKu, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_9A748jNT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_7kq2ete8_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_t8LOSXak_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_9A748jNT_sendMessage);
      break;
    }
    default: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_LY9fZofX, HV_BINOP_MULTIPLY, 0, m, &cBinop_LY9fZofX_sendMessage);
      cBinop_onMessage(_c, &Context(_c)->cBinop_E9HsfONy, HV_BINOP_DIVIDE, 1, m, &cBinop_E9HsfONy_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_uhKWI9pg, 0, m, &cVar_uhKWI9pg_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_4XxHeB0G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_xWahpDBV, 0, m, &cVar_xWahpDBV_sendMessage);
}

void Heavy_SoundScraper::cMsg_7kq2ete8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 20.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_LY9fZofX, HV_BINOP_MULTIPLY, 0, m, &cBinop_LY9fZofX_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_E9HsfONy, HV_BINOP_DIVIDE, 1, m, &cBinop_E9HsfONy_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_uhKWI9pg, 0, m, &cVar_uhKWI9pg_sendMessage);
}

void Heavy_SoundScraper::cCast_7tS212Pu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_qlerrb7I_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_9LoxOxwg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_vmVgUo89, 1, m, &cVar_vmVgUo89_sendMessage);
}

void Heavy_SoundScraper::cVar_T6MbkFIw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_R0RVnxSW, HV_BINOP_ADD, 0, m, &cBinop_R0RVnxSW_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_LqnklgtN, HV_BINOP_ADD, 0, m, &cBinop_LqnklgtN_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_3fkpojuH, 0, m, &cVar_3fkpojuH_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_lm1HusbR, m);
}

void Heavy_SoundScraper::cBinop_BSZDvBMc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_vmVgUo89, 1, m, &cVar_vmVgUo89_sendMessage);
}

void Heavy_SoundScraper::cSlice_LNxXOEJe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_g98VX1mT_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_FTV48A85_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_Wg55a7ii_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_zFqHlvUz_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_BsAy2F7t_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cCast_BsAy2F7t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_E9HsfONy, HV_BINOP_DIVIDE, 0, m, &cBinop_E9HsfONy_sendMessage);
}

void Heavy_SoundScraper::cSlice_Ts7aByXn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_iOH8jAno_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Tfh3ugTx_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_iOH8jAno_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Tfh3ugTx_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_VKfvcohg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_u1yWyNXr_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_u1yWyNXr_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSwitchcase_wa7M0Cv1_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cSlice_onMessage(_c, &Context(_c)->cSlice_VKfvcohg, 0, m, &cSlice_VKfvcohg_sendMessage);
      break;
    }
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_Ts7aByXn, 0, m, &cSlice_Ts7aByXn_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_4XxHeB0G_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_Wg55a7ii, 0, m, &cSlice_Wg55a7ii_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_LNxXOEJe, 0, m, &cSlice_LNxXOEJe_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_lSi6P69n_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_lK794eo9_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_E9HsfONy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MYoPVutt, HV_BINOP_DIVIDE, 1, m, &cBinop_MYoPVutt_sendMessage);
}

void Heavy_SoundScraper::cCast_FTV48A85_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_xzVUNQf1, HV_BINOP_SUBTRACT, 0, m, &cBinop_xzVUNQf1_sendMessage);
}

void Heavy_SoundScraper::cBinop_LY9fZofX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_YMIrQnLm_sendMessage);
}

void Heavy_SoundScraper::cBinop_LqnklgtN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_AYuVqWOR, 0, m, &cVar_AYuVqWOR_sendMessage);
}

void Heavy_SoundScraper::cBinop_MYoPVutt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_LqnklgtN, HV_BINOP_ADD, 1, m, &cBinop_LqnklgtN_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_R0RVnxSW, HV_BINOP_ADD, 1, m, &cBinop_R0RVnxSW_sendMessage);
}

void Heavy_SoundScraper::cBinop_A2qdipWP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_SWqSc0Mi, 2, m, &cDelay_SWqSc0Mi_sendMessage);
}

void Heavy_SoundScraper::cCast_PPmf2KhU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_LMzhOrc9_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_SWqSc0Mi, 0, m, &cDelay_SWqSc0Mi_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_vmVgUo89, 0, m, &cVar_vmVgUo89_sendMessage);
}

void Heavy_SoundScraper::cBinop_KvFKyppH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_WqQrj29e, HV_BINOP_MULTIPLY, 1, m, &cBinop_WqQrj29e_sendMessage);
}

void Heavy_SoundScraper::cMsg_LMzhOrc9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_SWqSc0Mi, 0, m, &cDelay_SWqSc0Mi_sendMessage);
}

void Heavy_SoundScraper::cDelay_SWqSc0Mi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_SWqSc0Mi, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_SWqSc0Mi, 0, m, &cDelay_SWqSc0Mi_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_vmVgUo89, 0, m, &cVar_vmVgUo89_sendMessage);
}

void Heavy_SoundScraper::cBinop_WqQrj29e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_A2qdipWP_sendMessage);
}

void Heavy_SoundScraper::cVar_uhKWI9pg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_WqQrj29e, HV_BINOP_MULTIPLY, 0, m, &cBinop_WqQrj29e_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_v15NtXMm_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cMsg_LMzhOrc9_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_LMzhOrc9_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_PPmf2KhU_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cMsg_kKgj26mj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_xKIXZsDW_sendMessage);
}

void Heavy_SoundScraper::cSystem_xKIXZsDW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_KvFKyppH_sendMessage);
}

void Heavy_SoundScraper::cMsg_QO7efEPb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_xWahpDBV, 1, m, &cVar_xWahpDBV_sendMessage);
}

void Heavy_SoundScraper::cBinop_R0RVnxSW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_T6MbkFIw, 1, m, &cVar_T6MbkFIw_sendMessage);
}

void Heavy_SoundScraper::cVar_ZnO3YYb7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_t8LOSXak_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cVar_AYuVqWOR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_xzVUNQf1, HV_BINOP_SUBTRACT, 1, m, &cBinop_xzVUNQf1_sendMessage);
}

void Heavy_SoundScraper::cCast_Tfh3ugTx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_7tS212Pu_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_LqnklgtN, HV_BINOP_ADD, 0, m, &cBinop_LqnklgtN_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_T6MbkFIw, 1, m, &cVar_T6MbkFIw_sendMessage);
}

void Heavy_SoundScraper::cBinop_YMIrQnLm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_9LoxOxwg, HV_BINOP_SUBTRACT, 1, m, &cBinop_9LoxOxwg_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_BK4qaso8_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_QFhrvcEt_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_DZZmZTTi_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_DZZmZTTi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_jjMvDeh5_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_s8Pm7vIR_sendMessage);
}

void Heavy_SoundScraper::cCast_QFhrvcEt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_T6MbkFIw, 0, m, &cVar_T6MbkFIw_sendMessage);
}

void Heavy_SoundScraper::cCast_g98VX1mT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_f7zF4mz2, 1, m, &cVar_f7zF4mz2_sendMessage);
}

void Heavy_SoundScraper::cBinop_hiFY5jud_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_BSZDvBMc_sendMessage);
}

void Heavy_SoundScraper::cCast_iOH8jAno_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_u1yWyNXr_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_xWahpDBV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_zFqHlvUz_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_BsAy2F7t_sendMessage);
}

void Heavy_SoundScraper::cCast_jjMvDeh5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_qlerrb7I_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_lK794eo9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_QO7efEPb_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_lSi6P69n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_lmaPq03S_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_lmaPq03S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_v15NtXMm_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cVar_f7zF4mz2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_T6MbkFIw, 0, m, &cVar_T6MbkFIw_sendMessage);
}

void Heavy_SoundScraper::cVar_vmVgUo89_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_9LoxOxwg, HV_BINOP_SUBTRACT, 0, m, &cBinop_9LoxOxwg_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_LESS_THAN_EQL, 0.0f, 0, m, &cBinop_shArdhDY_sendMessage);
}

void Heavy_SoundScraper::cMsg_qlerrb7I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_v15NtXMm_onMessage(_c, NULL, 0, m, NULL);
  cBinop_onMessage(_c, &Context(_c)->cBinop_LqnklgtN, HV_BINOP_ADD, 1, m, &cBinop_LqnklgtN_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_R0RVnxSW, HV_BINOP_ADD, 1, m, &cBinop_R0RVnxSW_sendMessage);
}

void Heavy_SoundScraper::cCast_s8Pm7vIR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_f7zF4mz2, 0, m, &cVar_f7zF4mz2_sendMessage);
}

void Heavy_SoundScraper::cBinop_shArdhDY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_BK4qaso8_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cMsg_u1yWyNXr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_v15NtXMm_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cSystem_lyqlEnL0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_LY9fZofX, HV_BINOP_MULTIPLY, 1, m, &cBinop_LY9fZofX_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_hiFY5jud, HV_BINOP_MULTIPLY, 1, m, &cBinop_hiFY5jud_sendMessage);
}

void Heavy_SoundScraper::cMsg_mszd6exa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_lyqlEnL0_sendMessage);
}

void Heavy_SoundScraper::cBinop_xzVUNQf1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MYoPVutt, HV_BINOP_DIVIDE, 0, m, &cBinop_MYoPVutt_sendMessage);
}

void Heavy_SoundScraper::cCast_zFqHlvUz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_hiFY5jud, HV_BINOP_MULTIPLY, 0, m, &cBinop_hiFY5jud_sendMessage);
}

void Heavy_SoundScraper::cBinop_6tPPiVs4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_uTcHPrZn_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_Bdq0WgST_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_zyB5iGBX, 0, m, &cSlice_zyB5iGBX_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_rDm5AsVt, 0, m, &cRandom_rDm5AsVt_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cRandom_rDm5AsVt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 80.0f, 0, m, &cBinop_6tPPiVs4_sendMessage);
}

void Heavy_SoundScraper::cUnop_uTcHPrZn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 10.0f, 0, m, &cBinop_EgR7aQyw_sendMessage);
}

void Heavy_SoundScraper::cSlice_zyB5iGBX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_rDm5AsVt, 1, m, &cRandom_rDm5AsVt_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_3WLu8nqg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_jFpSjkXl_sendMessage);
}

void Heavy_SoundScraper::cMsg_AO1ilv7M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cMsg_pK6ib2I5_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_KmtnFRlu_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_iKxiqkmm_sendMessage);
}

void Heavy_SoundScraper::cBinop_KOpgzSlu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_pK6ib2I5_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_KmtnFRlu_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_iKxiqkmm_sendMessage);
}

void Heavy_SoundScraper::cBinop_QoyC2qAv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_KOpgzSlu_sendMessage);
}

void Heavy_SoundScraper::cCast_SqvdjTIO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_fzazrusm_sendMessage);
}

void Heavy_SoundScraper::cIf_TcceSJpW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_AO1ilv7M_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_LOG10, m, &cUnop_gkZkViIT_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_dWO77fxm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 100.0f, 0, m, &cBinop_QoyC2qAv_sendMessage);
}

void Heavy_SoundScraper::cBinop_fzazrusm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_TcceSJpW, 1, m, &cIf_TcceSJpW_sendMessage);
}

void Heavy_SoundScraper::cUnop_gkZkViIT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_dWO77fxm_sendMessage);
}

void Heavy_SoundScraper::cCast_x1HTqWzf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_TcceSJpW, 0, m, &cIf_TcceSJpW_sendMessage);
}

void Heavy_SoundScraper::cBinop_jFpSjkXl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_SqvdjTIO_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_x1HTqWzf_sendMessage);
}

void Heavy_SoundScraper::cBinop_6papvOzO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_qr0uTD6a, 0, m, &cPack_qr0uTD6a_sendMessage);
}

void Heavy_SoundScraper::cCast_2tfTFFNa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_QGBaQ4kR_sendMessage);
}

void Heavy_SoundScraper::cMsg_6jSAZUUK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_8tMHmxhJ, HV_BINOP_POW, 0, m, &cBinop_8tMHmxhJ_sendMessage);
}

void Heavy_SoundScraper::cMsg_6sv97Pn6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.125f, 0, m, &cBinop_6papvOzO_sendMessage);
}

void Heavy_SoundScraper::cBinop_8tMHmxhJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.125f, 0, m, &cBinop_6papvOzO_sendMessage);
}

void Heavy_SoundScraper::cIf_IvnndJbs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_6sv97Pn6_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_kvtMu9JI_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_QGBaQ4kR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_IvnndJbs, 1, m, &cIf_IvnndJbs_sendMessage);
}

void Heavy_SoundScraper::cCast_SSO3cT3p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_IvnndJbs, 0, m, &cIf_IvnndJbs_sendMessage);
}

void Heavy_SoundScraper::cBinop_kvtMu9JI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_x1IggyER_sendMessage);
}

void Heavy_SoundScraper::cBinop_mkXlsNcY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_8tMHmxhJ, HV_BINOP_POW, 1, m, &cBinop_8tMHmxhJ_sendMessage);
  cMsg_6jSAZUUK_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_x1IggyER_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_mkXlsNcY_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_AvnB5qO0_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_JPi9YWMY_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cMsg_BApdDvzh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_sOQFACjd, 0, m, &hTable_sOQFACjd_sendMessage);
}

void Heavy_SoundScraper::cMsg_JPi9YWMY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_tI1NGy9l, 1, m, NULL);
}

void Heavy_SoundScraper::cMsg_PviVOrJv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_eDws7itv, 2, m, &cDelay_eDws7itv_sendMessage);
}

void Heavy_SoundScraper::cMsg_WNL1KsJd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_sOQFACjd, 0, m, &hTable_sOQFACjd_sendMessage);
}

void Heavy_SoundScraper::cSystem_M5VfDX3q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_iVuTIRas_sendMessage);
}

void Heavy_SoundScraper::cMsg_cK6PJVWh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_M5VfDX3q_sendMessage);
}

void Heavy_SoundScraper::cDelay_dpHMaRhP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_dpHMaRhP, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_eDws7itv, 0, m, &cDelay_eDws7itv_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_dpHMaRhP, 0, m, &cDelay_dpHMaRhP_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_tI1NGy9l, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_eDws7itv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_eDws7itv, m);
  cMsg_WNL1KsJd_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_iVuTIRas_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 58.6435f, 0, m, &cBinop_lJnQ3c4Q_sendMessage);
}

void Heavy_SoundScraper::cBinop_lJnQ3c4Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_BApdDvzh_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_r31yL1xH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_dpHMaRhP, 0, m, &cDelay_dpHMaRhP_sendMessage);
}

void Heavy_SoundScraper::hTable_sOQFACjd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_PviVOrJv_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_dpHMaRhP, 2, m, &cDelay_dpHMaRhP_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_r31yL1xH_sendMessage);
}

void Heavy_SoundScraper::cBinop_97Vqbe7c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_KIsxwZ1J, 0, m, &cPack_KIsxwZ1J_sendMessage);
}

void Heavy_SoundScraper::cBinop_2mK0yV9t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_8HpyMCtP_sendMessage);
}

void Heavy_SoundScraper::cBinop_8HpyMCtP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_qL0OTM7u_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_5AQtq8SZ, m);
}

void Heavy_SoundScraper::cVar_4vurxjLg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_D4yvKrbp, HV_BINOP_MULTIPLY, 0, m, &cBinop_D4yvKrbp_sendMessage);
}

void Heavy_SoundScraper::cBinop_D4yvKrbp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_2mK0yV9t_sendMessage);
}

void Heavy_SoundScraper::cMsg_H3KGxhyd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_kCS2sOHu_sendMessage);
}

void Heavy_SoundScraper::cBinop_kCS2sOHu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_D4yvKrbp, HV_BINOP_MULTIPLY, 1, m, &cBinop_D4yvKrbp_sendMessage);
}

void Heavy_SoundScraper::cMsg_HvwSu4XL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_biJIdm5H_sendMessage);
}

void Heavy_SoundScraper::cSystem_biJIdm5H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_H3KGxhyd_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_qL0OTM7u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_rJYLNPto, m);
}

void Heavy_SoundScraper::cPack_KIsxwZ1J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_KmqMAnhB, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_NQJ6ZoM6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_Th0OAbYU, 1, m, &cIf_Th0OAbYU_sendMessage);
}

void Heavy_SoundScraper::cIf_Th0OAbYU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_cSd6gTbo_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cVar_onMessage(_c, &Context(_c)->cVar_A5ugVD1y, 0, m, &cVar_A5ugVD1y_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cCast_0hirUWhU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_RkOG7nu9, 0, m, &cVar_RkOG7nu9_sendMessage);
  cMsg_TUpLUGrK_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_bsldNoGU, 0, m, &cTabhead_bsldNoGU_sendMessage);
}

void Heavy_SoundScraper::cMsg_4v6OMUIw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_xZBMFHfM, HV_BINOP_MAX, 1, m, &cBinop_xZBMFHfM_sendMessage);
}

void Heavy_SoundScraper::sTabread_95dkUskH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_EI15LN6J, HV_BINOP_SUBTRACT, 0, m, &cBinop_EI15LN6J_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSystem_9QBtFkpz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_EI15LN6J, HV_BINOP_SUBTRACT, 1, m, &cBinop_EI15LN6J_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ADk7FYJg, 2, m, &cDelay_ADk7FYJg_sendMessage);
}

void Heavy_SoundScraper::cDelay_ADk7FYJg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_ADk7FYJg, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_95dkUskH, 0, m, &sTabread_95dkUskH_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ADk7FYJg, 0, m, &cDelay_ADk7FYJg_sendMessage);
}

void Heavy_SoundScraper::cBinop_EI15LN6J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_zUiLah7o_sendMessage);
}

void Heavy_SoundScraper::cBinop_LHeEEgBN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_XE8WwMMf_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_95dkUskH, 0, m, &sTabread_95dkUskH_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_fSMJ017l_sendMessage);
}

void Heavy_SoundScraper::cMsg_N4xjTIvI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_9QBtFkpz_sendMessage);
}

void Heavy_SoundScraper::cBinop_OVGgm29j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_xZBMFHfM, HV_BINOP_MAX, 0, m, &cBinop_xZBMFHfM_sendMessage);
}

void Heavy_SoundScraper::cVar_RkOG7nu9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_N4xjTIvI_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_XE8WwMMf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_tcpHpV75, 0, m, &cDelay_tcpHpV75_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ADk7FYJg, 0, m, &cDelay_ADk7FYJg_sendMessage);
}

void Heavy_SoundScraper::cTabhead_bsldNoGU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_LHeEEgBN, HV_BINOP_SUBTRACT, 0, m, &cBinop_LHeEEgBN_sendMessage);
}

void Heavy_SoundScraper::cCast_fSMJ017l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_tcpHpV75, 0, m, &cDelay_tcpHpV75_sendMessage);
}

void Heavy_SoundScraper::cBinop_j83WiwVQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_OVGgm29j, HV_BINOP_MULTIPLY, 0, m, &cBinop_OVGgm29j_sendMessage);
}

void Heavy_SoundScraper::cMsg_TUpLUGrK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_dR3Issgm_sendMessage);
}

void Heavy_SoundScraper::cSystem_dR3Issgm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_j83WiwVQ_sendMessage);
}

void Heavy_SoundScraper::cDelay_tcpHpV75_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_tcpHpV75, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ADk7FYJg, 0, m, &cDelay_ADk7FYJg_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_95dkUskH, 0, m, &sTabread_95dkUskH_sendMessage);
}

void Heavy_SoundScraper::cBinop_xZBMFHfM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_LHeEEgBN, HV_BINOP_SUBTRACT, 1, m, &cBinop_LHeEEgBN_sendMessage);
}

void Heavy_SoundScraper::cBinop_zUiLah7o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_tcpHpV75, 2, m, &cDelay_tcpHpV75_sendMessage);
}

void Heavy_SoundScraper::cBinop_7pzPBn0U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Zf8XIbKC, HV_BINOP_MULTIPLY, 1, m, &cBinop_Zf8XIbKC_sendMessage);
}

void Heavy_SoundScraper::cSystem_nVbthqFU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Ohb4dxFX_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_oLyqp723_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_nVbthqFU_sendMessage);
}

void Heavy_SoundScraper::cMsg_Ohb4dxFX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_7pzPBn0U_sendMessage);
}

void Heavy_SoundScraper::cBinop_Zf8XIbKC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_wlTj1r3f_sendMessage);
}

void Heavy_SoundScraper::cBinop_MmFxET5O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_dMm2NBcY_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_cMXIMxQ6, m);
}

void Heavy_SoundScraper::cBinop_wlTj1r3f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_MmFxET5O_sendMessage);
}

void Heavy_SoundScraper::cVar_TbXZlErM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Zf8XIbKC, HV_BINOP_MULTIPLY, 0, m, &cBinop_Zf8XIbKC_sendMessage);
}

void Heavy_SoundScraper::cBinop_dMm2NBcY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_HkIt0OkD, m);
}

void Heavy_SoundScraper::cBinop_EH60Ozpi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_yXI1BX5X_sendMessage);
}

void Heavy_SoundScraper::cBinop_yXI1BX5X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ELbL87j9, 0, m, &cVar_ELbL87j9_sendMessage);
}

void Heavy_SoundScraper::cVar_ELbL87j9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.01f, 0, m, &cBinop_ZXlbpmAy_sendMessage);
}

void Heavy_SoundScraper::cVar_aVE88ycb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 100.0f, 0, m, &cBinop_S97a2am2_sendMessage);
}

void Heavy_SoundScraper::cCast_4cVpYjLo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_EGWAp475, 0, m, &cDelay_EGWAp475_sendMessage);
}

void Heavy_SoundScraper::cDelay_EGWAp475_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_EGWAp475, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_t4wmRcyk, 0, m, &cDelay_t4wmRcyk_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_EGWAp475, 0, m, &cDelay_EGWAp475_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_FOWYkAfr, 1, m, NULL);
}

void Heavy_SoundScraper::cMsg_KNLgOMny_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_yD5jEq6S, 0, m, &hTable_yD5jEq6S_sendMessage);
}

void Heavy_SoundScraper::cMsg_3F3lBHb1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_5YO3SSRO_sendMessage);
}

void Heavy_SoundScraper::cSystem_5YO3SSRO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_Oi1Ufhs1_sendMessage);
}

void Heavy_SoundScraper::cBinop_Oi1Ufhs1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 86.1244f, 0, m, &cBinop_Vx8uFmq4_sendMessage);
}

void Heavy_SoundScraper::cBinop_Vx8uFmq4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_dIkB0qZx_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_ZycAtL5W_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_fV3JiwAZ_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cMsg_dIkB0qZx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_yD5jEq6S, 0, m, &hTable_yD5jEq6S_sendMessage);
}

void Heavy_SoundScraper::cMsg_fV3JiwAZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_FOWYkAfr, 1, m, NULL);
}

void Heavy_SoundScraper::cMsg_kOykDgdy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_t4wmRcyk, 2, m, &cDelay_t4wmRcyk_sendMessage);
}

void Heavy_SoundScraper::cDelay_t4wmRcyk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_t4wmRcyk, m);
  cMsg_KNLgOMny_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_yD5jEq6S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_kOykDgdy_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_EGWAp475, 2, m, &cDelay_EGWAp475_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_4cVpYjLo_sendMessage);
}

void Heavy_SoundScraper::cBinop_ZXlbpmAy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_g49bXLsX, 0, m, &cPack_g49bXLsX_sendMessage);
}

void Heavy_SoundScraper::cDelay_4G3cDlx2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_4G3cDlx2, m);
  cMsg_6GFjErHn_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_4sH5AWzX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_4sH5AWzX, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_4G3cDlx2, 0, m, &cDelay_4G3cDlx2_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_4sH5AWzX, 0, m, &cDelay_4sH5AWzX_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_KVJjR7db, 1, m, NULL);
}

void Heavy_SoundScraper::cMsg_6GFjErHn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_KTYymZwO, 0, m, &hTable_KTYymZwO_sendMessage);
}

void Heavy_SoundScraper::cMsg_6P5vl3Hr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_KTYymZwO, 0, m, &hTable_KTYymZwO_sendMessage);
}

void Heavy_SoundScraper::hTable_KTYymZwO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_U5rs5YGR_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_4sH5AWzX, 2, m, &cDelay_4sH5AWzX_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_VCACTapW_sendMessage);
}

void Heavy_SoundScraper::cBinop_QbyCwXpt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_6P5vl3Hr_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_RQwqhkkt_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_uRtsBgt3_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cMsg_U5rs5YGR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_4G3cDlx2, 2, m, &cDelay_4G3cDlx2_sendMessage);
}

void Heavy_SoundScraper::cCast_VCACTapW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_4sH5AWzX, 0, m, &cDelay_4sH5AWzX_sendMessage);
}

void Heavy_SoundScraper::cSystem_407qBpLq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_XLU2Xwbx_sendMessage);
}

void Heavy_SoundScraper::cMsg_brs7OAau_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_407qBpLq_sendMessage);
}

void Heavy_SoundScraper::cBinop_XLU2Xwbx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 25.796f, 0, m, &cBinop_QbyCwXpt_sendMessage);
}

void Heavy_SoundScraper::cMsg_uRtsBgt3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_KVJjR7db, 1, m, NULL);
}

void Heavy_SoundScraper::cBinop_3kUO64yL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_j2IO1XVu_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_6kxarfdK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_kf0sMJ7C, 0, m, &cDelay_kf0sMJ7C_sendMessage);
}

void Heavy_SoundScraper::cMsg_6l8gQ9R0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_rYsjrFF2, 1, m, NULL);
}

void Heavy_SoundScraper::cMsg_9EIoWekT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_MHDSXfwo, 2, m, &cDelay_MHDSXfwo_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_C5jO4OKu_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_6l8gQ9R0_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cMsg_CIeuzQ4i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_amukS8d7, 0, m, &hTable_amukS8d7_sendMessage);
}

void Heavy_SoundScraper::cMsg_MCS8zi8x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_zYWdeEVl_sendMessage);
}

void Heavy_SoundScraper::cSystem_zYWdeEVl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_aCwBEsL7_sendMessage);
}

void Heavy_SoundScraper::cDelay_MHDSXfwo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_MHDSXfwo, m);
  cMsg_CIeuzQ4i_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_aCwBEsL7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 75.2546f, 0, m, &cBinop_3kUO64yL_sendMessage);
}

void Heavy_SoundScraper::hTable_amukS8d7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_9EIoWekT_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_kf0sMJ7C, 2, m, &cDelay_kf0sMJ7C_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_6kxarfdK_sendMessage);
}

void Heavy_SoundScraper::cMsg_j2IO1XVu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_amukS8d7, 0, m, &hTable_amukS8d7_sendMessage);
}

void Heavy_SoundScraper::cDelay_kf0sMJ7C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_kf0sMJ7C, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_MHDSXfwo, 0, m, &cDelay_MHDSXfwo_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_kf0sMJ7C, 0, m, &cDelay_kf0sMJ7C_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_rYsjrFF2, 1, m, NULL);
}

void Heavy_SoundScraper::cTabhead_238LxNEE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_fKzgxDLi, HV_BINOP_SUBTRACT, 0, m, &cBinop_fKzgxDLi_sendMessage);
}

void Heavy_SoundScraper::cCast_2IQ4pNcG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Rgcc4RTY, 0, m, &cDelay_Rgcc4RTY_sendMessage);
}

void Heavy_SoundScraper::cBinop_ELhLweBN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_fKzgxDLi, HV_BINOP_SUBTRACT, 1, m, &cBinop_fKzgxDLi_sendMessage);
}

void Heavy_SoundScraper::cSystem_GzHvjv97_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_tWCQi8Gy, HV_BINOP_SUBTRACT, 1, m, &cBinop_tWCQi8Gy_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_otqKPZHd, 2, m, &cDelay_otqKPZHd_sendMessage);
}

void Heavy_SoundScraper::cBinop_HoqWlP8S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_gMStXXzI, HV_BINOP_MULTIPLY, 0, m, &cBinop_gMStXXzI_sendMessage);
}

void Heavy_SoundScraper::sTabread_O6jFGsul_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_tWCQi8Gy, HV_BINOP_SUBTRACT, 0, m, &cBinop_tWCQi8Gy_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cMsg_QG8NKBLQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_ELhLweBN, HV_BINOP_MAX, 1, m, &cBinop_ELhLweBN_sendMessage);
}

void Heavy_SoundScraper::cDelay_Rgcc4RTY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Rgcc4RTY, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_otqKPZHd, 0, m, &cDelay_otqKPZHd_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_O6jFGsul, 0, m, &sTabread_O6jFGsul_sendMessage);
}

void Heavy_SoundScraper::cCast_SY9tKhsl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_uTpHW20o, 0, m, &cVar_uTpHW20o_sendMessage);
  cMsg_nEg3xGhJ_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_238LxNEE, 0, m, &cTabhead_238LxNEE_sendMessage);
}

void Heavy_SoundScraper::cBinop_fKzgxDLi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_fhyD7HNc_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_O6jFGsul, 0, m, &sTabread_O6jFGsul_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_2IQ4pNcG_sendMessage);
}

void Heavy_SoundScraper::cMsg_fhyD7HNc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_Rgcc4RTY, 0, m, &cDelay_Rgcc4RTY_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_otqKPZHd, 0, m, &cDelay_otqKPZHd_sendMessage);
}

void Heavy_SoundScraper::cBinop_gMStXXzI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ELhLweBN, HV_BINOP_MAX, 0, m, &cBinop_ELhLweBN_sendMessage);
}

void Heavy_SoundScraper::cSystem_LZqhwFC8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_HoqWlP8S_sendMessage);
}

void Heavy_SoundScraper::cMsg_nEg3xGhJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_LZqhwFC8_sendMessage);
}

void Heavy_SoundScraper::cDelay_otqKPZHd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_otqKPZHd, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_O6jFGsul, 0, m, &sTabread_O6jFGsul_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_otqKPZHd, 0, m, &cDelay_otqKPZHd_sendMessage);
}

void Heavy_SoundScraper::cBinop_tWCQi8Gy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_zQyxLGBE_sendMessage);
}

void Heavy_SoundScraper::cVar_uTpHW20o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_wgg8oiEx_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_wgg8oiEx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_GzHvjv97_sendMessage);
}

void Heavy_SoundScraper::cBinop_zQyxLGBE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Rgcc4RTY, 2, m, &cDelay_Rgcc4RTY_sendMessage);
}

void Heavy_SoundScraper::cCast_9DhEmGRi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_KGSvr8CU, 0, m, &cDelay_KGSvr8CU_sendMessage);
}

void Heavy_SoundScraper::cMsg_F3k3QbJS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_Z9aUjTyP, 1, m, NULL);
}

void Heavy_SoundScraper::cMsg_JumJtWiX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_XBJx0zKQ, 2, m, &cDelay_XBJx0zKQ_sendMessage);
}

void Heavy_SoundScraper::cDelay_KGSvr8CU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_KGSvr8CU, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_XBJx0zKQ, 0, m, &cDelay_XBJx0zKQ_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_KGSvr8CU, 0, m, &cDelay_KGSvr8CU_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_Z9aUjTyP, 1, m, NULL);
}

void Heavy_SoundScraper::hTable_N3IEEdKO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_JumJtWiX_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_KGSvr8CU, 2, m, &cDelay_KGSvr8CU_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_9DhEmGRi_sendMessage);
}

void Heavy_SoundScraper::cMsg_QjzBFJvG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_N3IEEdKO, 0, m, &hTable_N3IEEdKO_sendMessage);
}

void Heavy_SoundScraper::cMsg_PdsKdVyn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_k3uAO84M_sendMessage);
}

void Heavy_SoundScraper::cSystem_k3uAO84M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_T9NsimJ8_sendMessage);
}

void Heavy_SoundScraper::cBinop_T9NsimJ8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 13.645f, 0, m, &cBinop_TsMeCJJj_sendMessage);
}

void Heavy_SoundScraper::cBinop_TsMeCJJj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_fEuYZbo8_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_VZIEFGgw_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_F3k3QbJS_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cDelay_XBJx0zKQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_XBJx0zKQ, m);
  cMsg_QjzBFJvG_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_fEuYZbo8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_N3IEEdKO, 0, m, &hTable_N3IEEdKO_sendMessage);
}

void Heavy_SoundScraper::cBinop_1WfFYHQW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_RS1dD6wF, HV_BINOP_MULTIPLY, 0, m, &cBinop_RS1dD6wF_sendMessage);
}

void Heavy_SoundScraper::cDelay_2hexzHdw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_2hexzHdw, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_v5M3Sot5, 0, m, &sTabread_v5M3Sot5_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_2hexzHdw, 0, m, &cDelay_2hexzHdw_sendMessage);
}

void Heavy_SoundScraper::cBinop_AufnJZYS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_mVJUUq26, HV_BINOP_SUBTRACT, 1, m, &cBinop_mVJUUq26_sendMessage);
}

void Heavy_SoundScraper::cTabhead_HKIPOkNn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_mVJUUq26, HV_BINOP_SUBTRACT, 0, m, &cBinop_mVJUUq26_sendMessage);
}

void Heavy_SoundScraper::cBinop_JeRy4QRV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_Skzrj1bk_sendMessage);
}

void Heavy_SoundScraper::cMsg_JfzrmqfD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_tGccaxhl, 0, m, &cDelay_tGccaxhl_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_2hexzHdw, 0, m, &cDelay_2hexzHdw_sendMessage);
}

void Heavy_SoundScraper::cSystem_OCOl9jhz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_JeRy4QRV, HV_BINOP_SUBTRACT, 1, m, &cBinop_JeRy4QRV_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_2hexzHdw, 2, m, &cDelay_2hexzHdw_sendMessage);
}

void Heavy_SoundScraper::cCast_PWEokKLX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_tMoSExKz, 0, m, &cVar_tMoSExKz_sendMessage);
  cMsg_LMOWpzuc_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_HKIPOkNn, 0, m, &cTabhead_HKIPOkNn_sendMessage);
}

void Heavy_SoundScraper::cBinop_RS1dD6wF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_AufnJZYS, HV_BINOP_MAX, 0, m, &cBinop_AufnJZYS_sendMessage);
}

void Heavy_SoundScraper::cBinop_Skzrj1bk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_tGccaxhl, 2, m, &cDelay_tGccaxhl_sendMessage);
}

void Heavy_SoundScraper::cCast_bFgpqR5N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_tGccaxhl, 0, m, &cDelay_tGccaxhl_sendMessage);
}

void Heavy_SoundScraper::cMsg_dOELEDhs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_OCOl9jhz_sendMessage);
}

void Heavy_SoundScraper::cMsg_fBmVL2JY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_AufnJZYS, HV_BINOP_MAX, 1, m, &cBinop_AufnJZYS_sendMessage);
}

void Heavy_SoundScraper::cMsg_LMOWpzuc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Pas39ZzD_sendMessage);
}

void Heavy_SoundScraper::cSystem_Pas39ZzD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_1WfFYHQW_sendMessage);
}

void Heavy_SoundScraper::cBinop_mVJUUq26_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_JfzrmqfD_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_v5M3Sot5, 0, m, &sTabread_v5M3Sot5_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_bFgpqR5N_sendMessage);
}

void Heavy_SoundScraper::cDelay_tGccaxhl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_tGccaxhl, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_2hexzHdw, 0, m, &cDelay_2hexzHdw_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_v5M3Sot5, 0, m, &sTabread_v5M3Sot5_sendMessage);
}

void Heavy_SoundScraper::cVar_tMoSExKz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_dOELEDhs_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::sTabread_v5M3Sot5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_JeRy4QRV, HV_BINOP_SUBTRACT, 0, m, &cBinop_JeRy4QRV_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cDelay_2la49ykd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_2la49ykd, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_AgyAQgdX, 0, m, &sTabread_AgyAQgdX_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_2la49ykd, 0, m, &cDelay_2la49ykd_sendMessage);
}

void Heavy_SoundScraper::cBinop_3S0HTQWe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_7qusWUFJ_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_AgyAQgdX, 0, m, &sTabread_AgyAQgdX_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_UiIZVEXg_sendMessage);
}

void Heavy_SoundScraper::cMsg_7qusWUFJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_mbFM2wzE, 0, m, &cDelay_mbFM2wzE_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_2la49ykd, 0, m, &cDelay_2la49ykd_sendMessage);
}

void Heavy_SoundScraper::sTabread_AgyAQgdX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_dPcUPzMT, HV_BINOP_SUBTRACT, 0, m, &cBinop_dPcUPzMT_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_ESjGaIKk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_mbFM2wzE, 2, m, &cDelay_mbFM2wzE_sendMessage);
}

void Heavy_SoundScraper::cMsg_FiECT7xg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_dn4S88k2, HV_BINOP_MAX, 1, m, &cBinop_dn4S88k2_sendMessage);
}

void Heavy_SoundScraper::cTabhead_GiSLm0Ve_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_3S0HTQWe, HV_BINOP_SUBTRACT, 0, m, &cBinop_3S0HTQWe_sendMessage);
}

void Heavy_SoundScraper::cSystem_JRTajrdJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_dPcUPzMT, HV_BINOP_SUBTRACT, 1, m, &cBinop_dPcUPzMT_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_2la49ykd, 2, m, &cDelay_2la49ykd_sendMessage);
}

void Heavy_SoundScraper::cBinop_NcSTL6If_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_dn4S88k2, HV_BINOP_MAX, 0, m, &cBinop_dn4S88k2_sendMessage);
}

void Heavy_SoundScraper::cVar_Nn2QYeSd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_RlPbsFdD_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_RlPbsFdD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_JRTajrdJ_sendMessage);
}

void Heavy_SoundScraper::cCast_UiIZVEXg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_mbFM2wzE, 0, m, &cDelay_mbFM2wzE_sendMessage);
}

void Heavy_SoundScraper::cMsg_B0taOGSw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_yTu1fMvI_sendMessage);
}

void Heavy_SoundScraper::cSystem_yTu1fMvI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_mwnNoMXW_sendMessage);
}

void Heavy_SoundScraper::cBinop_dPcUPzMT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_ESjGaIKk_sendMessage);
}

void Heavy_SoundScraper::cBinop_dn4S88k2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_3S0HTQWe, HV_BINOP_SUBTRACT, 1, m, &cBinop_3S0HTQWe_sendMessage);
}

void Heavy_SoundScraper::cDelay_mbFM2wzE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_mbFM2wzE, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_2la49ykd, 0, m, &cDelay_2la49ykd_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_AgyAQgdX, 0, m, &sTabread_AgyAQgdX_sendMessage);
}

void Heavy_SoundScraper::cBinop_mwnNoMXW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_NcSTL6If, HV_BINOP_MULTIPLY, 0, m, &cBinop_NcSTL6If_sendMessage);
}

void Heavy_SoundScraper::cCast_xkjga8iw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Nn2QYeSd, 0, m, &cVar_Nn2QYeSd_sendMessage);
  cMsg_B0taOGSw_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_GiSLm0Ve, 0, m, &cTabhead_GiSLm0Ve_sendMessage);
}

void Heavy_SoundScraper::cBinop_Cvtliz2t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Fxg7QNKn, HV_BINOP_MULTIPLY, 0, m, &cBinop_Fxg7QNKn_sendMessage);
}

void Heavy_SoundScraper::cBinop_Fxg7QNKn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_GuKsODtU, HV_BINOP_MAX, 0, m, &cBinop_GuKsODtU_sendMessage);
}

void Heavy_SoundScraper::cBinop_GuKsODtU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_nEBjSKLi, HV_BINOP_SUBTRACT, 1, m, &cBinop_nEBjSKLi_sendMessage);
}

void Heavy_SoundScraper::cSystem_HehHXfVk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_dClVABnj, HV_BINOP_SUBTRACT, 1, m, &cBinop_dClVABnj_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_JR5vGloY, 2, m, &cDelay_JR5vGloY_sendMessage);
}

void Heavy_SoundScraper::cDelay_JR5vGloY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_JR5vGloY, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_NIIx5kU1, 0, m, &sTabread_NIIx5kU1_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_JR5vGloY, 0, m, &cDelay_JR5vGloY_sendMessage);
}

void Heavy_SoundScraper::cDelay_KLg3X0rz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_KLg3X0rz, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_JR5vGloY, 0, m, &cDelay_JR5vGloY_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_NIIx5kU1, 0, m, &sTabread_NIIx5kU1_sendMessage);
}

void Heavy_SoundScraper::sTabread_NIIx5kU1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_dClVABnj, HV_BINOP_SUBTRACT, 0, m, &cBinop_dClVABnj_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSystem_2hNP4lA9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_Cvtliz2t_sendMessage);
}

void Heavy_SoundScraper::cMsg_zKlRJF1V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_2hNP4lA9_sendMessage);
}

void Heavy_SoundScraper::cCast_WQJF5CDF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_KLg3X0rz, 0, m, &cDelay_KLg3X0rz_sendMessage);
}

void Heavy_SoundScraper::cBinop_WnlrS3dP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_KLg3X0rz, 2, m, &cDelay_KLg3X0rz_sendMessage);
}

void Heavy_SoundScraper::cVar_cQfHPFbx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_pVSD1bKQ_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_dClVABnj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_WnlrS3dP_sendMessage);
}

void Heavy_SoundScraper::cMsg_dSdm6Hr6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_KLg3X0rz, 0, m, &cDelay_KLg3X0rz_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_JR5vGloY, 0, m, &cDelay_JR5vGloY_sendMessage);
}

void Heavy_SoundScraper::cTabhead_jFneiBZ8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_nEBjSKLi, HV_BINOP_SUBTRACT, 0, m, &cBinop_nEBjSKLi_sendMessage);
}

void Heavy_SoundScraper::cBinop_nEBjSKLi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_dSdm6Hr6_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_NIIx5kU1, 0, m, &sTabread_NIIx5kU1_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_WQJF5CDF_sendMessage);
}

void Heavy_SoundScraper::cMsg_pVSD1bKQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_HehHXfVk_sendMessage);
}

void Heavy_SoundScraper::cMsg_snxSGQG0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_GuKsODtU, HV_BINOP_MAX, 1, m, &cBinop_GuKsODtU_sendMessage);
}

void Heavy_SoundScraper::cCast_tQkRkM77_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_cQfHPFbx, 0, m, &cVar_cQfHPFbx_sendMessage);
  cMsg_zKlRJF1V_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_jFneiBZ8, 0, m, &cTabhead_jFneiBZ8_sendMessage);
}

void Heavy_SoundScraper::cBinop_1FXVvnZD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_kI7llMSj_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_9rKLAeez_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_gv4JSvvA_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_dqi6WYq0, 2, m, &cDelay_dqi6WYq0_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_op99vhXo_sendMessage);
}

void Heavy_SoundScraper::cMsg_EusnHKYo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_IxL6w6Y4, 1, m, NULL);
}

void Heavy_SoundScraper::cMsg_H5FzhGY8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_9rKLAeez, 0, m, &hTable_9rKLAeez_sendMessage);
}

void Heavy_SoundScraper::cDelay_Knj7evc2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Knj7evc2, m);
  cMsg_H5FzhGY8_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_NHCS4gsJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 19.392f, 0, m, &cBinop_1FXVvnZD_sendMessage);
}

void Heavy_SoundScraper::cSystem_YwouG0R1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_NHCS4gsJ_sendMessage);
}

void Heavy_SoundScraper::cMsg_mUI5nSUH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_YwouG0R1_sendMessage);
}

void Heavy_SoundScraper::cDelay_dqi6WYq0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_dqi6WYq0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Knj7evc2, 0, m, &cDelay_Knj7evc2_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_dqi6WYq0, 0, m, &cDelay_dqi6WYq0_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_IxL6w6Y4, 1, m, NULL);
}

void Heavy_SoundScraper::cSwitchcase_fNd4KKEa_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_EusnHKYo_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cMsg_gv4JSvvA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_Knj7evc2, 2, m, &cDelay_Knj7evc2_sendMessage);
}

void Heavy_SoundScraper::cMsg_kI7llMSj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_9rKLAeez, 0, m, &hTable_9rKLAeez_sendMessage);
}

void Heavy_SoundScraper::cCast_op99vhXo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_dqi6WYq0, 0, m, &cDelay_dqi6WYq0_sendMessage);
}

void Heavy_SoundScraper::cDelay_7i4fmIt3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_7i4fmIt3, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_xVPC2oxR, 0, m, &sTabread_xVPC2oxR_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_7i4fmIt3, 0, m, &cDelay_7i4fmIt3_sendMessage);
}

void Heavy_SoundScraper::cBinop_8SzqVjTS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_rEUZAGwQ_sendMessage);
}

void Heavy_SoundScraper::cDelay_9uEjAW50_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_9uEjAW50, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_7i4fmIt3, 0, m, &cDelay_7i4fmIt3_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_xVPC2oxR, 0, m, &sTabread_xVPC2oxR_sendMessage);
}

void Heavy_SoundScraper::cMsg_SHLVNZz5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_qLyovVfF_sendMessage);
}

void Heavy_SoundScraper::cSystem_qLyovVfF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_TNNpD3vO_sendMessage);
}

void Heavy_SoundScraper::cBinop_Mz76bQ0S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_n6tFC0xQ, HV_BINOP_SUBTRACT, 1, m, &cBinop_n6tFC0xQ_sendMessage);
}

void Heavy_SoundScraper::cMsg_PRyGPmKP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_9uEjAW50, 0, m, &cDelay_9uEjAW50_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_7i4fmIt3, 0, m, &cDelay_7i4fmIt3_sendMessage);
}

void Heavy_SoundScraper::cBinop_TNNpD3vO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_oIgsgKG3, HV_BINOP_MULTIPLY, 0, m, &cBinop_oIgsgKG3_sendMessage);
}

void Heavy_SoundScraper::cTabhead_h8J9M5Gk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_n6tFC0xQ, HV_BINOP_SUBTRACT, 0, m, &cBinop_n6tFC0xQ_sendMessage);
}

void Heavy_SoundScraper::cCast_ipJvfpuV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_qBNaUY0f, 0, m, &cVar_qBNaUY0f_sendMessage);
  cMsg_SHLVNZz5_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_h8J9M5Gk, 0, m, &cTabhead_h8J9M5Gk_sendMessage);
}

void Heavy_SoundScraper::cSystem_jkziZXQz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_8SzqVjTS, HV_BINOP_SUBTRACT, 1, m, &cBinop_8SzqVjTS_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_7i4fmIt3, 2, m, &cDelay_7i4fmIt3_sendMessage);
}

void Heavy_SoundScraper::cCast_kNB3513I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_9uEjAW50, 0, m, &cDelay_9uEjAW50_sendMessage);
}

void Heavy_SoundScraper::cMsg_m6umx7jZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_Mz76bQ0S, HV_BINOP_MAX, 1, m, &cBinop_Mz76bQ0S_sendMessage);
}

void Heavy_SoundScraper::cBinop_n6tFC0xQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_PRyGPmKP_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_xVPC2oxR, 0, m, &sTabread_xVPC2oxR_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_kNB3513I_sendMessage);
}

void Heavy_SoundScraper::cBinop_oIgsgKG3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Mz76bQ0S, HV_BINOP_MAX, 0, m, &cBinop_Mz76bQ0S_sendMessage);
}

void Heavy_SoundScraper::cMsg_ooBa481n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_jkziZXQz_sendMessage);
}

void Heavy_SoundScraper::cVar_qBNaUY0f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ooBa481n_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_rEUZAGwQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_9uEjAW50, 2, m, &cDelay_9uEjAW50_sendMessage);
}

void Heavy_SoundScraper::sTabread_xVPC2oxR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_8SzqVjTS, HV_BINOP_SUBTRACT, 0, m, &cBinop_8SzqVjTS_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSystem_m9H4Ho1w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_Uf1rOSSw_sendMessage);
}

void Heavy_SoundScraper::cMsg_qFduss71_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_m9H4Ho1w_sendMessage);
}

void Heavy_SoundScraper::cMsg_30eRlicE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_z6VSE2bb, 1, m, NULL);
}

void Heavy_SoundScraper::cSwitchcase_4Pi7QS5W_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_30eRlicE_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_BCgp2vql_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_ZI44pPse, 0, m, &cDelay_ZI44pPse_sendMessage);
}

void Heavy_SoundScraper::cDelay_FkFCpkOM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_FkFCpkOM, m);
  cMsg_RhAU7w7X_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_LNFQfVX9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_il4LWkq0, 0, m, &hTable_il4LWkq0_sendMessage);
}

void Heavy_SoundScraper::cMsg_RhAU7w7X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_il4LWkq0, 0, m, &hTable_il4LWkq0_sendMessage);
}

void Heavy_SoundScraper::cMsg_SDo1YFJ9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_FkFCpkOM, 2, m, &cDelay_FkFCpkOM_sendMessage);
}

void Heavy_SoundScraper::cBinop_Uf1rOSSw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 16.364f, 0, m, &cBinop_XzqLECX6_sendMessage);
}

void Heavy_SoundScraper::cBinop_XzqLECX6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_LNFQfVX9_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_ZI44pPse_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_ZI44pPse, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_FkFCpkOM, 0, m, &cDelay_FkFCpkOM_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ZI44pPse, 0, m, &cDelay_ZI44pPse_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_z6VSE2bb, 1, m, NULL);
}

void Heavy_SoundScraper::hTable_il4LWkq0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_SDo1YFJ9_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ZI44pPse, 2, m, &cDelay_ZI44pPse_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_BCgp2vql_sendMessage);
}

void Heavy_SoundScraper::cDelay_3YopkI0B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_3YopkI0B, m);
  cMsg_xEHefpAU_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_5Jlf3VuJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_98byR0lf_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_U43H4E6N, 2, m, &cDelay_U43H4E6N_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_VHxtdvz8_sendMessage);
}

void Heavy_SoundScraper::cBinop_8Te28Pwg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Yg2Vb7VG_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_98byR0lf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_3YopkI0B, 2, m, &cDelay_3YopkI0B_sendMessage);
}

void Heavy_SoundScraper::cBinop_BWDXJcrs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 43.5337f, 0, m, &cBinop_8Te28Pwg_sendMessage);
}

void Heavy_SoundScraper::cDelay_U43H4E6N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_U43H4E6N, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_3YopkI0B, 0, m, &cDelay_3YopkI0B_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_U43H4E6N, 0, m, &cDelay_U43H4E6N_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_xAmeylLP, 1, m, NULL);
}

void Heavy_SoundScraper::cCast_VHxtdvz8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_U43H4E6N, 0, m, &cDelay_U43H4E6N_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_WWble37M_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_iNSrJ8qJ_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cMsg_Yg2Vb7VG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_5Jlf3VuJ, 0, m, &hTable_5Jlf3VuJ_sendMessage);
}

void Heavy_SoundScraper::cSystem_PigJJcae_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_BWDXJcrs_sendMessage);
}

void Heavy_SoundScraper::cMsg_cx4h1U3y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_PigJJcae_sendMessage);
}

void Heavy_SoundScraper::cMsg_iNSrJ8qJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_xAmeylLP, 1, m, NULL);
}

void Heavy_SoundScraper::cMsg_xEHefpAU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_5Jlf3VuJ, 0, m, &hTable_5Jlf3VuJ_sendMessage);
}

void Heavy_SoundScraper::cMsg_3ig7Lm5k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_FGYiMKUs, HV_BINOP_MAX, 1, m, &cBinop_FGYiMKUs_sendMessage);
}

void Heavy_SoundScraper::cVar_6pBlUwqW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_o1WBAbIm_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_8L5yobrA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_DT5Fn2bd, HV_BINOP_MULTIPLY, 0, m, &cBinop_DT5Fn2bd_sendMessage);
}

void Heavy_SoundScraper::sTabread_9oR6lA7J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_u8Mls4kI, HV_BINOP_SUBTRACT, 0, m, &cBinop_u8Mls4kI_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_BvjRAvim_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_J4SKKNKl, 2, m, &cDelay_J4SKKNKl_sendMessage);
}

void Heavy_SoundScraper::cBinop_DT5Fn2bd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_FGYiMKUs, HV_BINOP_MAX, 0, m, &cBinop_FGYiMKUs_sendMessage);
}

void Heavy_SoundScraper::cTabhead_Dmc8PtT0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_HL2myXQd, HV_BINOP_SUBTRACT, 0, m, &cBinop_HL2myXQd_sendMessage);
}

void Heavy_SoundScraper::cBinop_FGYiMKUs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_HL2myXQd, HV_BINOP_SUBTRACT, 1, m, &cBinop_HL2myXQd_sendMessage);
}

void Heavy_SoundScraper::cDelay_GqrbjDsV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_GqrbjDsV, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_9oR6lA7J, 0, m, &sTabread_9oR6lA7J_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_GqrbjDsV, 0, m, &cDelay_GqrbjDsV_sendMessage);
}

void Heavy_SoundScraper::cCast_GxQaiVyt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_J4SKKNKl, 0, m, &cDelay_J4SKKNKl_sendMessage);
}

void Heavy_SoundScraper::cBinop_HL2myXQd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_zvJGv8QE_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_9oR6lA7J, 0, m, &sTabread_9oR6lA7J_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_GxQaiVyt_sendMessage);
}

void Heavy_SoundScraper::cDelay_J4SKKNKl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_J4SKKNKl, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_GqrbjDsV, 0, m, &cDelay_GqrbjDsV_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_9oR6lA7J, 0, m, &sTabread_9oR6lA7J_sendMessage);
}

void Heavy_SoundScraper::cSystem_Jy7Kx80v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_u8Mls4kI, HV_BINOP_SUBTRACT, 1, m, &cBinop_u8Mls4kI_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_GqrbjDsV, 2, m, &cDelay_GqrbjDsV_sendMessage);
}

void Heavy_SoundScraper::cSystem_Q2Ttx1T7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_8L5yobrA_sendMessage);
}

void Heavy_SoundScraper::cMsg_pXCGkRDP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Q2Ttx1T7_sendMessage);
}

void Heavy_SoundScraper::cCast_WXA40OOI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_6pBlUwqW, 0, m, &cVar_6pBlUwqW_sendMessage);
  cMsg_pXCGkRDP_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_Dmc8PtT0, 0, m, &cTabhead_Dmc8PtT0_sendMessage);
}

void Heavy_SoundScraper::cMsg_o1WBAbIm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Jy7Kx80v_sendMessage);
}

void Heavy_SoundScraper::cBinop_u8Mls4kI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_BvjRAvim_sendMessage);
}

void Heavy_SoundScraper::cMsg_zvJGv8QE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_J4SKKNKl, 0, m, &cDelay_J4SKKNKl_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_GqrbjDsV, 0, m, &cDelay_GqrbjDsV_sendMessage);
}

void Heavy_SoundScraper::cBinop_3cSSEd6Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_I7QpVyNi, HV_BINOP_SUBTRACT, 1, m, &cBinop_I7QpVyNi_sendMessage);
}

void Heavy_SoundScraper::sTabread_A7NRdDRo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_iQ4XrmSJ, HV_BINOP_SUBTRACT, 0, m, &cBinop_iQ4XrmSJ_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cMsg_BnZN7Zpa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_3cSSEd6Z, HV_BINOP_MAX, 1, m, &cBinop_3cSSEd6Z_sendMessage);
}

void Heavy_SoundScraper::cCast_BzaMu6CZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_TfY1UwNu, 0, m, &cVar_TfY1UwNu_sendMessage);
  cMsg_vDMwXiAF_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_po2Uy8VU, 0, m, &cTabhead_po2Uy8VU_sendMessage);
}

void Heavy_SoundScraper::cDelay_Cj9J1iMM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Cj9J1iMM, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_A7NRdDRo, 0, m, &sTabread_A7NRdDRo_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Cj9J1iMM, 0, m, &cDelay_Cj9J1iMM_sendMessage);
}

void Heavy_SoundScraper::cBinop_DXjR5VWH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_3cSSEd6Z, HV_BINOP_MAX, 0, m, &cBinop_3cSSEd6Z_sendMessage);
}

void Heavy_SoundScraper::cSystem_muWy6S2R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_cRHIu7p1_sendMessage);
}

void Heavy_SoundScraper::cMsg_vDMwXiAF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_muWy6S2R_sendMessage);
}

void Heavy_SoundScraper::cBinop_I7QpVyNi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_J7ZDY3O4_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_A7NRdDRo, 0, m, &sTabread_A7NRdDRo_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_cMXMugty_sendMessage);
}

void Heavy_SoundScraper::cMsg_J7ZDY3O4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_pMmJ1Df7, 0, m, &cDelay_pMmJ1Df7_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Cj9J1iMM, 0, m, &cDelay_Cj9J1iMM_sendMessage);
}

void Heavy_SoundScraper::cBinop_L9LOyyeZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_pMmJ1Df7, 2, m, &cDelay_pMmJ1Df7_sendMessage);
}

void Heavy_SoundScraper::cSystem_O1Zd7m3m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_iQ4XrmSJ, HV_BINOP_SUBTRACT, 1, m, &cBinop_iQ4XrmSJ_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Cj9J1iMM, 2, m, &cDelay_Cj9J1iMM_sendMessage);
}

void Heavy_SoundScraper::cMsg_S3mJ5GHO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_O1Zd7m3m_sendMessage);
}

void Heavy_SoundScraper::cVar_TfY1UwNu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_S3mJ5GHO_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_cMXMugty_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_pMmJ1Df7, 0, m, &cDelay_pMmJ1Df7_sendMessage);
}

void Heavy_SoundScraper::cBinop_cRHIu7p1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_DXjR5VWH, HV_BINOP_MULTIPLY, 0, m, &cBinop_DXjR5VWH_sendMessage);
}

void Heavy_SoundScraper::cBinop_iQ4XrmSJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_L9LOyyeZ_sendMessage);
}

void Heavy_SoundScraper::cDelay_pMmJ1Df7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_pMmJ1Df7, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Cj9J1iMM, 0, m, &cDelay_Cj9J1iMM_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_A7NRdDRo, 0, m, &sTabread_A7NRdDRo_sendMessage);
}

void Heavy_SoundScraper::cTabhead_po2Uy8VU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_I7QpVyNi, HV_BINOP_SUBTRACT, 0, m, &cBinop_I7QpVyNi_sendMessage);
}

void Heavy_SoundScraper::cMsg_cSd6gTbo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 3000.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_A5ugVD1y, 0, m, &cVar_A5ugVD1y_sendMessage);
}

void Heavy_SoundScraper::cMsg_D9snJVWn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_NSHiTy1f_sendMessage);
}

void Heavy_SoundScraper::cSystem_NSHiTy1f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_THE8zvck_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_8FJwXGk8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_43GFVIez_sendMessage);
}

void Heavy_SoundScraper::cMsg_THE8zvck_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_aAuETfT3_sendMessage);
}

void Heavy_SoundScraper::cBinop_aAuETfT3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_8FJwXGk8, HV_BINOP_MULTIPLY, 1, m, &cBinop_8FJwXGk8_sendMessage);
}

void Heavy_SoundScraper::cVar_w9s8gsro_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_8FJwXGk8, HV_BINOP_MULTIPLY, 0, m, &cBinop_8FJwXGk8_sendMessage);
}

void Heavy_SoundScraper::cBinop_43GFVIez_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_h8DevU5Z_sendMessage);
}

void Heavy_SoundScraper::cBinop_h8DevU5Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_zcTavk16_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_6GXKnDCJ, m);
}

void Heavy_SoundScraper::cBinop_zcTavk16_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_EdSrWJPJ, m);
}

void Heavy_SoundScraper::cPack_g49bXLsX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_LW9JeSpj, 0, m, NULL);
}

void Heavy_SoundScraper::cVar_pb1QVppF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 100.0f, 0, m, &cBinop_EH60Ozpi_sendMessage);
}

void Heavy_SoundScraper::cVar_A5ugVD1y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_4vurxjLg, 0, m, &cVar_4vurxjLg_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_w9s8gsro, 0, m, &cVar_w9s8gsro_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_VMqS8U9a, 0, m, &cVar_VMqS8U9a_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_TbXZlErM, 0, m, &cVar_TbXZlErM_sendMessage);
}

void Heavy_SoundScraper::cVar_8zmf3lwk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_2tfTFFNa_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_SSO3cT3p_sendMessage);
}

void Heavy_SoundScraper::cVar_VMqS8U9a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_0dpQmVl7, HV_BINOP_MULTIPLY, 0, m, &cBinop_0dpQmVl7_sendMessage);
}

void Heavy_SoundScraper::cBinop_R6n18KOG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_nzFy3HfZ_sendMessage);
}

void Heavy_SoundScraper::cBinop_nzFy3HfZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_GxIB6bcv_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_khHH09UD, m);
}

void Heavy_SoundScraper::cBinop_GxIB6bcv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_XGtlPRgZ, m);
}

void Heavy_SoundScraper::cBinop_0dpQmVl7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_R6n18KOG_sendMessage);
}

void Heavy_SoundScraper::cBinop_52ufnuVw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_0dpQmVl7, HV_BINOP_MULTIPLY, 1, m, &cBinop_0dpQmVl7_sendMessage);
}

void Heavy_SoundScraper::cMsg_ZQf6FPTW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_52ufnuVw_sendMessage);
}

void Heavy_SoundScraper::cMsg_IUMMFkIP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_NgzBXHDK_sendMessage);
}

void Heavy_SoundScraper::cSystem_NgzBXHDK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ZQf6FPTW_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_0PkkEWUW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_1Xi8yDH2_sendMessage);
}

void Heavy_SoundScraper::cMsg_0R1Knx8w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_OnXOGtNY_sendMessage);
}

void Heavy_SoundScraper::cBinop_1Xi8yDH2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_wVPVkoPF, 2, m, &cDelay_wVPVkoPF_sendMessage);
}

void Heavy_SoundScraper::cSystem_ClcVTFK7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_yBO9HRKL_sendMessage);
}

void Heavy_SoundScraper::cMsg_PBmfKnPV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ClcVTFK7_sendMessage);
}

void Heavy_SoundScraper::cDelay_AqjRr9T6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_AqjRr9T6, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_UMAlHkrX, 0, m, &sTabread_UMAlHkrX_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_AqjRr9T6, 0, m, &cDelay_AqjRr9T6_sendMessage);
}

void Heavy_SoundScraper::cCast_FzsrQbSV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_wVPVkoPF, 0, m, &cDelay_wVPVkoPF_sendMessage);
}

void Heavy_SoundScraper::cMsg_JeHx8xhJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_q29aaKXr, HV_BINOP_MAX, 1, m, &cBinop_q29aaKXr_sendMessage);
}

void Heavy_SoundScraper::cTabhead_MD15ck9x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_sF4ENJM2, HV_BINOP_SUBTRACT, 0, m, &cBinop_sF4ENJM2_sendMessage);
}

void Heavy_SoundScraper::cSystem_OnXOGtNY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_0PkkEWUW, HV_BINOP_SUBTRACT, 1, m, &cBinop_0PkkEWUW_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_AqjRr9T6, 2, m, &cDelay_AqjRr9T6_sendMessage);
}

void Heavy_SoundScraper::sTabread_UMAlHkrX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_0PkkEWUW, HV_BINOP_SUBTRACT, 0, m, &cBinop_0PkkEWUW_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cCast_arcJteX4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_jWsXkRIT, 0, m, &cVar_jWsXkRIT_sendMessage);
  cMsg_PBmfKnPV_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_MD15ck9x, 0, m, &cTabhead_MD15ck9x_sendMessage);
}

void Heavy_SoundScraper::cMsg_cHv3x7Xd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_wVPVkoPF, 0, m, &cDelay_wVPVkoPF_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_AqjRr9T6, 0, m, &cDelay_AqjRr9T6_sendMessage);
}

void Heavy_SoundScraper::cVar_jWsXkRIT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_0R1Knx8w_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_pcfCC84r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_q29aaKXr, HV_BINOP_MAX, 0, m, &cBinop_q29aaKXr_sendMessage);
}

void Heavy_SoundScraper::cBinop_q29aaKXr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_sF4ENJM2, HV_BINOP_SUBTRACT, 1, m, &cBinop_sF4ENJM2_sendMessage);
}

void Heavy_SoundScraper::cBinop_sF4ENJM2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_cHv3x7Xd_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_UMAlHkrX, 0, m, &sTabread_UMAlHkrX_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_FzsrQbSV_sendMessage);
}

void Heavy_SoundScraper::cDelay_wVPVkoPF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_wVPVkoPF, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_AqjRr9T6, 0, m, &cDelay_AqjRr9T6_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_UMAlHkrX, 0, m, &sTabread_UMAlHkrX_sendMessage);
}

void Heavy_SoundScraper::cBinop_yBO9HRKL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_pcfCC84r, HV_BINOP_MULTIPLY, 0, m, &cBinop_pcfCC84r_sendMessage);
}

void Heavy_SoundScraper::cBinop_6qPaJtU7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 200.0f, 0, m, &cBinop_97Vqbe7c_sendMessage);
}

void Heavy_SoundScraper::cBinop_S97a2am2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_6qPaJtU7_sendMessage);
}

void Heavy_SoundScraper::cMsg_3axR19W7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_S9JTsZTG, HV_BINOP_MAX, 1, m, &cBinop_S9JTsZTG_sendMessage);
}

void Heavy_SoundScraper::cCast_7gFXNw8h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_qN5QtCKP, 0, m, &cVar_qN5QtCKP_sendMessage);
  cMsg_eYXQ5pp9_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_Ay9w28ta, 0, m, &cTabhead_Ay9w28ta_sendMessage);
}

void Heavy_SoundScraper::cMsg_ATi4B5wq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_B7lNoczL_sendMessage);
}

void Heavy_SoundScraper::cTabhead_Ay9w28ta_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_BjnY4T2p, HV_BINOP_SUBTRACT, 0, m, &cBinop_BjnY4T2p_sendMessage);
}

void Heavy_SoundScraper::cSystem_B7lNoczL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_CBh5T8lj, HV_BINOP_SUBTRACT, 1, m, &cBinop_CBh5T8lj_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ymHfVU7q, 2, m, &cDelay_ymHfVU7q_sendMessage);
}

void Heavy_SoundScraper::cBinop_BjnY4T2p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_xQn0D6km_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_Mf3ytb18, 0, m, &sTabread_Mf3ytb18_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_WSYbd1r7_sendMessage);
}

void Heavy_SoundScraper::cBinop_CBh5T8lj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_JEmUlSr7_sendMessage);
}

void Heavy_SoundScraper::cBinop_JEmUlSr7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_SuIHVgfJ, 2, m, &cDelay_SuIHVgfJ_sendMessage);
}

void Heavy_SoundScraper::sTabread_Mf3ytb18_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_CBh5T8lj, HV_BINOP_SUBTRACT, 0, m, &cBinop_CBh5T8lj_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_NzXum9ww_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_S9JTsZTG, HV_BINOP_MAX, 0, m, &cBinop_S9JTsZTG_sendMessage);
}

void Heavy_SoundScraper::cBinop_S9JTsZTG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_BjnY4T2p, HV_BINOP_SUBTRACT, 1, m, &cBinop_BjnY4T2p_sendMessage);
}

void Heavy_SoundScraper::cDelay_SuIHVgfJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_SuIHVgfJ, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ymHfVU7q, 0, m, &cDelay_ymHfVU7q_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_Mf3ytb18, 0, m, &sTabread_Mf3ytb18_sendMessage);
}

void Heavy_SoundScraper::cCast_WSYbd1r7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_SuIHVgfJ, 0, m, &cDelay_SuIHVgfJ_sendMessage);
}

void Heavy_SoundScraper::cBinop_g4xXvYc6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_NzXum9ww, HV_BINOP_MULTIPLY, 0, m, &cBinop_NzXum9ww_sendMessage);
}

void Heavy_SoundScraper::cSystem_1tXXQCap_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_g4xXvYc6_sendMessage);
}

void Heavy_SoundScraper::cMsg_eYXQ5pp9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_1tXXQCap_sendMessage);
}

void Heavy_SoundScraper::cVar_qN5QtCKP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ATi4B5wq_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_xQn0D6km_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_SuIHVgfJ, 0, m, &cDelay_SuIHVgfJ_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ymHfVU7q, 0, m, &cDelay_ymHfVU7q_sendMessage);
}

void Heavy_SoundScraper::cDelay_ymHfVU7q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_ymHfVU7q, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_Mf3ytb18, 0, m, &sTabread_Mf3ytb18_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ymHfVU7q, 0, m, &cDelay_ymHfVU7q_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_14U4CHnS_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_spUPSbLx_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cMsg_3PJFmvdb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_kUXFxfS9, 0, m, &hTable_kUXFxfS9_sendMessage);
}

void Heavy_SoundScraper::cBinop_9kDMX69q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 69.4325f, 0, m, &cBinop_hF6qtUiu_sendMessage);
}

void Heavy_SoundScraper::cMsg_GJHlkGse_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_kUXFxfS9, 0, m, &hTable_kUXFxfS9_sendMessage);
}

void Heavy_SoundScraper::cMsg_GdRaLxL9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_rojQnTDl, 2, m, &cDelay_rojQnTDl_sendMessage);
}

void Heavy_SoundScraper::cDelay_IIICVU7j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_IIICVU7j, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_rojQnTDl, 0, m, &cDelay_rojQnTDl_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_IIICVU7j, 0, m, &cDelay_IIICVU7j_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_9qK970t4, 1, m, NULL);
}

void Heavy_SoundScraper::cBinop_hF6qtUiu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_GJHlkGse_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_kUXFxfS9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_GdRaLxL9_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_IIICVU7j, 2, m, &cDelay_IIICVU7j_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_tLHmnMAO_sendMessage);
}

void Heavy_SoundScraper::cDelay_rojQnTDl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_rojQnTDl, m);
  cMsg_3PJFmvdb_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_spUPSbLx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_9qK970t4, 1, m, NULL);
}

void Heavy_SoundScraper::cCast_tLHmnMAO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_IIICVU7j, 0, m, &cDelay_IIICVU7j_sendMessage);
}

void Heavy_SoundScraper::cSystem_3HCrObNu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_9kDMX69q_sendMessage);
}

void Heavy_SoundScraper::cMsg_IPuPfbdw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_3HCrObNu_sendMessage);
}

void Heavy_SoundScraper::cPack_qr0uTD6a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_zd8iUYEN, 0, m, NULL);
}

void Heavy_SoundScraper::cMsg_12fulvDw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_PUK5OSPa, 1, m, NULL);
}

void Heavy_SoundScraper::cMsg_nWLQXqJ2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ydPhC46D_sendMessage);
}

void Heavy_SoundScraper::cSystem_ydPhC46D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_l7k9z9Vd_sendMessage);
}

void Heavy_SoundScraper::cCast_HbylnVLv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_JjPn5IOz, 0, m, &cDelay_JjPn5IOz_sendMessage);
}

void Heavy_SoundScraper::cDelay_JjPn5IOz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_JjPn5IOz, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_aP3EnlNz, 0, m, &cDelay_aP3EnlNz_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_JjPn5IOz, 0, m, &cDelay_JjPn5IOz_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_PUK5OSPa, 1, m, NULL);
}

void Heavy_SoundScraper::cMsg_KjwZVBLL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_aP3EnlNz, 2, m, &cDelay_aP3EnlNz_sendMessage);
}

void Heavy_SoundScraper::cMsg_X4srZWbh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_rQziADzR, 0, m, &hTable_rQziADzR_sendMessage);
}

void Heavy_SoundScraper::cDelay_aP3EnlNz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_aP3EnlNz, m);
  cMsg_X4srZWbh_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_fAgNk4J8_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_12fulvDw_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cMsg_jhX5dFDR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_rQziADzR, 0, m, &hTable_rQziADzR_sendMessage);
}

void Heavy_SoundScraper::cBinop_l7k9z9Vd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 74.5234f, 0, m, &cBinop_x0L5ccDc_sendMessage);
}

void Heavy_SoundScraper::hTable_rQziADzR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_KjwZVBLL_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_JjPn5IOz, 2, m, &cDelay_JjPn5IOz_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_HbylnVLv_sendMessage);
}

void Heavy_SoundScraper::cBinop_x0L5ccDc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_jhX5dFDR_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_EHW2pJfr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_NQJ6ZoM6_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_Th0OAbYU, 0, m, &cIf_Th0OAbYU_sendMessage);
}

void Heavy_SoundScraper::cVar_XHpwjSSN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_3wtBBh7s_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_3wtBBh7s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_vcMb0WOz_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_RWHaRdz0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_pK6ib2I5_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_KmtnFRlu_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_iKxiqkmm_sendMessage);
}

void Heavy_SoundScraper::cPack_UbYnhhcu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_ZZKNZRLX, 0, m, NULL);
}

void Heavy_SoundScraper::cSend_ivbpaBxS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_gi3bKbGJ_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_I2ENwsyn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_UbYnhhcu, 0, m, &cPack_UbYnhhcu_sendMessage);
}

void Heavy_SoundScraper::cCast_KmtnFRlu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_WV8A1mpm_sendMessage);
}

void Heavy_SoundScraper::cMsg_RQIF9pvT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_I2ENwsyn, HV_BINOP_POW, 0, m, &cBinop_I2ENwsyn_sendMessage);
}

void Heavy_SoundScraper::cBinop_WV8A1mpm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_vyUQpKzd, 1, m, &cIf_vyUQpKzd_sendMessage);
}

void Heavy_SoundScraper::cBinop_XzZevGjy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_uD3XkntM_sendMessage);
}

void Heavy_SoundScraper::cMsg_blJZpUyG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_UbYnhhcu, 0, m, &cPack_UbYnhhcu_sendMessage);
}

void Heavy_SoundScraper::cCast_iKxiqkmm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_vyUQpKzd, 0, m, &cIf_vyUQpKzd_sendMessage);
}

void Heavy_SoundScraper::cBinop_ipSKlgrs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_XzZevGjy_sendMessage);
}

void Heavy_SoundScraper::cBinop_uD3XkntM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_I2ENwsyn, HV_BINOP_POW, 1, m, &cBinop_I2ENwsyn_sendMessage);
  cMsg_RQIF9pvT_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cIf_vyUQpKzd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_blJZpUyG_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_ipSKlgrs_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cMsg_pK6ib2I5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSend_ivbpaBxS_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_1eZbcsbi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_toR6irzf_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cMsg_3NtscPYZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 500.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_8gj0B0K3, 0, m, NULL);
}

void Heavy_SoundScraper::cMsg_6LtrH0tF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.3f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_pBpFjPk9_sendMessage);
}

void Heavy_SoundScraper::cCast_4XcB2edl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_9p5bqceG, HV_BINOP_DIVIDE, 1, m, &cBinop_9p5bqceG_sendMessage);
}

void Heavy_SoundScraper::cBinop_9p5bqceG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Tky2vR8S_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_BfTeND35_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_qhyBzUUM, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_CG0wZFS4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_ZhjAi2ej_sendMessage);
}

void Heavy_SoundScraper::cBinop_CMNOdsLc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_4XcB2edl_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_q8k15fnK_sendMessage);
}

void Heavy_SoundScraper::cBinop_DGYEBDpK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.001f, 0, m, &cBinop_CMNOdsLc_sendMessage);
  cPack_onMessage(_c, &Context(_c)->cPack_dp4DXsVD, 0, m, &cPack_dp4DXsVD_sendMessage);
}

void Heavy_SoundScraper::cBinop_DirdSHXo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_BfTeND35, 0, m, &cPack_BfTeND35_sendMessage);
}

void Heavy_SoundScraper::cMsg_Tky2vR8S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 30.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_cSvxiMqk, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_ZhjAi2ej_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_9p5bqceG, HV_BINOP_DIVIDE, 0, m, &cBinop_9p5bqceG_sendMessage);
}

void Heavy_SoundScraper::cBinop_OVJZFiO2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_ZSHKmGzo, m);
}

void Heavy_SoundScraper::cMsg_RnWaeGkw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_jrZYpSjt_sendMessage);
}

void Heavy_SoundScraper::cVar_OsTtho3f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_RnWaeGkw_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSystem_ALe7ZojB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_jfIzGcEn_sendMessage);
}

void Heavy_SoundScraper::cMsg_LZbQkNxW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ALe7ZojB_sendMessage);
}

void Heavy_SoundScraper::cBinop_jfIzGcEn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_p1jGECpz, m);
}

void Heavy_SoundScraper::cSystem_jrZYpSjt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_OVJZFiO2_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_EiBAcfDc, m);
}

void Heavy_SoundScraper::cVar_Z8uTrTks_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.5f, 0, m, &cBinop_DirdSHXo_sendMessage);
}

void Heavy_SoundScraper::cPack_dp4DXsVD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_w64ryzUm, 0, m, NULL);
}

void Heavy_SoundScraper::cMsg_eOKUIqlV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.5f);
  cVar_onMessage(_c, &Context(_c)->cVar_Z8uTrTks, 0, m, &cVar_Z8uTrTks_sendMessage);
}

void Heavy_SoundScraper::cBinop_fEqdfucC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 87.3365f, 0, m, &cBinop_ItDszn1u_sendMessage);
}

void Heavy_SoundScraper::cVar_pYiV6Nwb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_DGYEBDpK_sendMessage);
}

void Heavy_SoundScraper::cMsg_YgNzMhZe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_tbpIIGhY_sendMessage);
}

void Heavy_SoundScraper::cSystem_tbpIIGhY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_dY1aIbn8_sendMessage);
}

void Heavy_SoundScraper::cBinop_FkF7X4OI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_krc7fk4O, m);
}

void Heavy_SoundScraper::cMsg_LieiCtL9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_NZUTOy0x_sendMessage);
}

void Heavy_SoundScraper::cSystem_NZUTOy0x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_FkF7X4OI_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_C9TD0mPy, m);
}

void Heavy_SoundScraper::cBinop_dY1aIbn8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_2LRolcvh, m);
}

void Heavy_SoundScraper::cVar_bDdEds4R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_LieiCtL9_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_8z62mpxw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_k8AwyJ1I_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_JXVsuz09_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_gs8ZreSM_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cMsg_A2HeDVbs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_DcwzACOW_sendMessage);
}

void Heavy_SoundScraper::cSystem_DcwzACOW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_zd3dRFfn_sendMessage);
}

void Heavy_SoundScraper::cMsg_NJ9KnpUt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_xeiqziG1, 0, m, &hTable_xeiqziG1_sendMessage);
}

void Heavy_SoundScraper::cDelay_XulUvEDr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_XulUvEDr, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_xOKOV2RP, 0, m, &cDelay_xOKOV2RP_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_XulUvEDr, 0, m, &cDelay_XulUvEDr_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_M5vsPrLF, 1, m, NULL);
}

void Heavy_SoundScraper::cMsg_gs8ZreSM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_M5vsPrLF, 1, m, NULL);
}

void Heavy_SoundScraper::cMsg_k8AwyJ1I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_xeiqziG1, 0, m, &hTable_xeiqziG1_sendMessage);
}

void Heavy_SoundScraper::cMsg_l2En9LsM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_xOKOV2RP, 2, m, &cDelay_xOKOV2RP_sendMessage);
}

void Heavy_SoundScraper::cDelay_xOKOV2RP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_xOKOV2RP, m);
  cMsg_NJ9KnpUt_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_xdr0FEFS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_XulUvEDr, 0, m, &cDelay_XulUvEDr_sendMessage);
}

void Heavy_SoundScraper::hTable_xeiqziG1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_l2En9LsM_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_XulUvEDr, 2, m, &cDelay_XulUvEDr_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_xdr0FEFS_sendMessage);
}

void Heavy_SoundScraper::cBinop_zd3dRFfn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 5000.0f, 0, m, &cBinop_8z62mpxw_sendMessage);
}

void Heavy_SoundScraper::cMsg_lKx5SvJV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 100.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_pYiV6Nwb, 0, m, &cVar_pYiV6Nwb_sendMessage);
}

void Heavy_SoundScraper::cBinop_ItDszn1u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_EXP, m, &cUnop_Qa8LM4Kk_sendMessage);
}

void Heavy_SoundScraper::cUnop_Qa8LM4Kk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_CG0wZFS4_sendMessage);
}

void Heavy_SoundScraper::cCast_q8k15fnK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_9p5bqceG, HV_BINOP_DIVIDE, 0, m, &cBinop_9p5bqceG_sendMessage);
}

void Heavy_SoundScraper::cMsg_9ivztjgt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 500.0f);
  sVarf_onMessage(_c, &Context(_c)->sVarf_hmWBbNn7, m);
}

void Heavy_SoundScraper::cIf_M3VNKe0r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_XKyvDh8Z_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cVar_onMessage(_c, &Context(_c)->cVar_yWYkELLa, 0, m, &cVar_yWYkELLa_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_tH7aApmN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_M3VNKe0r, 1, m, &cIf_M3VNKe0r_sendMessage);
}

void Heavy_SoundScraper::cBinop_1QT8aL29_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_9tnPgoYv, 0, m, &cPack_9tnPgoYv_sendMessage);
}

void Heavy_SoundScraper::cVar_FsHhjE6c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_aTXxggpL, HV_BINOP_MULTIPLY, 0, m, &cBinop_aTXxggpL_sendMessage);
}

void Heavy_SoundScraper::cBinop_F2rMqRO1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_rCEWKSgd_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_PmTLRsbz, m);
}

void Heavy_SoundScraper::cBinop_LqP1XtAM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_F2rMqRO1_sendMessage);
}

void Heavy_SoundScraper::cBinop_rCEWKSgd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_dwUu67ZV, m);
}

void Heavy_SoundScraper::cSystem_0BFI24TH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_dEIWR7DB_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_lJVYKCT7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_0BFI24TH_sendMessage);
}

void Heavy_SoundScraper::cBinop_YINdk7b7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_aTXxggpL, HV_BINOP_MULTIPLY, 1, m, &cBinop_aTXxggpL_sendMessage);
}

void Heavy_SoundScraper::cBinop_aTXxggpL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_LqP1XtAM_sendMessage);
}

void Heavy_SoundScraper::cMsg_dEIWR7DB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_YINdk7b7_sendMessage);
}

void Heavy_SoundScraper::cVar_yWYkELLa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_7zYxjbNP, 0, m, &cVar_7zYxjbNP_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_FsHhjE6c, 0, m, &cVar_FsHhjE6c_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_MpIBnkWC, 0, m, &cVar_MpIBnkWC_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_YgoH762r, 0, m, &cVar_YgoH762r_sendMessage);
}

void Heavy_SoundScraper::cPack_9tnPgoYv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_uRHIqJbV, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_G4GRa0N1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_fsUuWpD2, 0, m, &cVar_fsUuWpD2_sendMessage);
}

void Heavy_SoundScraper::cBinop_iSXpFufk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_G4GRa0N1_sendMessage);
}

void Heavy_SoundScraper::cVar_01PnFloa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 100.0f, 0, m, &cBinop_5SWb0Lcg_sendMessage);
}

void Heavy_SoundScraper::cBinop_NlFqYNsI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_ack2j2Lk_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_e1f2eTK1, m);
}

void Heavy_SoundScraper::cBinop_m2se3naR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_NlFqYNsI_sendMessage);
}

void Heavy_SoundScraper::cVar_YgoH762r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_z0DBgtW1, HV_BINOP_MULTIPLY, 0, m, &cBinop_z0DBgtW1_sendMessage);
}

void Heavy_SoundScraper::cSystem_Q1F0td1q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_TToXvT2V_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_ewLfsmw4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Q1F0td1q_sendMessage);
}

void Heavy_SoundScraper::cBinop_4aU7Ni4v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_z0DBgtW1, HV_BINOP_MULTIPLY, 1, m, &cBinop_z0DBgtW1_sendMessage);
}

void Heavy_SoundScraper::cMsg_TToXvT2V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_4aU7Ni4v_sendMessage);
}

void Heavy_SoundScraper::cBinop_z0DBgtW1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_m2se3naR_sendMessage);
}

void Heavy_SoundScraper::cBinop_ack2j2Lk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_8luTeCv1, m);
}

void Heavy_SoundScraper::cDelay_47qGL36G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_47qGL36G, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_EGy2SPYK, 0, m, &cDelay_EGy2SPYK_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_zDIEk0mR, 0, m, &sTabread_zDIEk0mR_sendMessage);
}

void Heavy_SoundScraper::cTabhead_6zhX7sLi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_qGYudbvd, HV_BINOP_SUBTRACT, 0, m, &cBinop_qGYudbvd_sendMessage);
}

void Heavy_SoundScraper::cCast_7LPHN0NA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_47qGL36G, 0, m, &cDelay_47qGL36G_sendMessage);
}

void Heavy_SoundScraper::cDelay_EGy2SPYK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_EGy2SPYK, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_zDIEk0mR, 0, m, &sTabread_zDIEk0mR_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_EGy2SPYK, 0, m, &cDelay_EGy2SPYK_sendMessage);
}

void Heavy_SoundScraper::cBinop_FOxlk4ls_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_NmBa5KkM, HV_BINOP_MAX, 0, m, &cBinop_NmBa5KkM_sendMessage);
}

void Heavy_SoundScraper::cVar_FRnRa57A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_YXqGEjIK_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_jZcs1OLm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_xR7HV7wd_sendMessage);
}

void Heavy_SoundScraper::cSystem_xR7HV7wd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_NreiNAi5_sendMessage);
}

void Heavy_SoundScraper::cBinop_NmBa5KkM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_qGYudbvd, HV_BINOP_SUBTRACT, 1, m, &cBinop_qGYudbvd_sendMessage);
}

void Heavy_SoundScraper::cBinop_NreiNAi5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_FOxlk4ls, HV_BINOP_MULTIPLY, 0, m, &cBinop_FOxlk4ls_sendMessage);
}

void Heavy_SoundScraper::cMsg_YXqGEjIK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_yRjwNjQN_sendMessage);
}

void Heavy_SoundScraper::cBinop_i2ZOvpDX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_47qGL36G, 2, m, &cDelay_47qGL36G_sendMessage);
}

void Heavy_SoundScraper::cMsg_i6tzG4cg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_47qGL36G, 0, m, &cDelay_47qGL36G_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_EGy2SPYK, 0, m, &cDelay_EGy2SPYK_sendMessage);
}

void Heavy_SoundScraper::cMsg_l3aBboEX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_NmBa5KkM, HV_BINOP_MAX, 1, m, &cBinop_NmBa5KkM_sendMessage);
}

void Heavy_SoundScraper::cCast_m6Ye80po_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_FRnRa57A, 0, m, &cVar_FRnRa57A_sendMessage);
  cMsg_jZcs1OLm_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_6zhX7sLi, 0, m, &cTabhead_6zhX7sLi_sendMessage);
}

void Heavy_SoundScraper::cBinop_qGYudbvd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_i6tzG4cg_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_zDIEk0mR, 0, m, &sTabread_zDIEk0mR_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_7LPHN0NA_sendMessage);
}

void Heavy_SoundScraper::cBinop_y6IcNk58_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_i2ZOvpDX_sendMessage);
}

void Heavy_SoundScraper::cSystem_yRjwNjQN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_y6IcNk58, HV_BINOP_SUBTRACT, 1, m, &cBinop_y6IcNk58_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_EGy2SPYK, 2, m, &cDelay_EGy2SPYK_sendMessage);
}

void Heavy_SoundScraper::sTabread_zDIEk0mR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_y6IcNk58, HV_BINOP_SUBTRACT, 0, m, &cBinop_y6IcNk58_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cVar_7zYxjbNP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_GhQk3VCt, HV_BINOP_MULTIPLY, 0, m, &cBinop_GhQk3VCt_sendMessage);
}

void Heavy_SoundScraper::cBinop_GhQk3VCt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_zn77dMVa_sendMessage);
}

void Heavy_SoundScraper::cBinop_O3EQm0I5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_GhQk3VCt, HV_BINOP_MULTIPLY, 1, m, &cBinop_GhQk3VCt_sendMessage);
}

void Heavy_SoundScraper::cMsg_Y60javuc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_O3EQm0I5_sendMessage);
}

void Heavy_SoundScraper::cSystem_Rs7wEHiP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Y60javuc_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_dXr4jq2u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Rs7wEHiP_sendMessage);
}

void Heavy_SoundScraper::cBinop_fUdxjlVo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_0hSBxe28, m);
}

void Heavy_SoundScraper::cBinop_2oAftTkm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_fUdxjlVo_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_YcnS4ewy, m);
}

void Heavy_SoundScraper::cBinop_zn77dMVa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_2oAftTkm_sendMessage);
}

void Heavy_SoundScraper::cBinop_Jw7tbWWT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_ezBvigzM, 0, m, &cPack_ezBvigzM_sendMessage);
}

void Heavy_SoundScraper::cVar_fsUuWpD2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.01f, 0, m, &cBinop_Jw7tbWWT_sendMessage);
}

void Heavy_SoundScraper::cBinop_UXc6kaxb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_WxiN8UNo, 0, m, &cPack_WxiN8UNo_sendMessage);
}

void Heavy_SoundScraper::cPack_WxiN8UNo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_UaDf2nKt, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_22YsnUGx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_QPrQCP5y, HV_BINOP_SUBTRACT, 1, m, &cBinop_QPrQCP5y_sendMessage);
}

void Heavy_SoundScraper::sTabread_287b4oh5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_RxJlMxmG, HV_BINOP_SUBTRACT, 0, m, &cBinop_RxJlMxmG_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSystem_3bxNm4Ir_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_RxJlMxmG, HV_BINOP_SUBTRACT, 1, m, &cBinop_RxJlMxmG_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_vLcb7izi, 2, m, &cDelay_vLcb7izi_sendMessage);
}

void Heavy_SoundScraper::cBinop_51yGrh40_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_GNUrXJ9X, HV_BINOP_MULTIPLY, 0, m, &cBinop_GNUrXJ9X_sendMessage);
}

void Heavy_SoundScraper::cCast_A7ytY3qk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_hJUM360N, 0, m, &cVar_hJUM360N_sendMessage);
  cMsg_MxuQiGAF_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_Bnw0b04Z, 0, m, &cTabhead_Bnw0b04Z_sendMessage);
}

void Heavy_SoundScraper::cTabhead_Bnw0b04Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_QPrQCP5y, HV_BINOP_SUBTRACT, 0, m, &cBinop_QPrQCP5y_sendMessage);
}

void Heavy_SoundScraper::cBinop_CO7YXtmN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_mgXwiBoK, 2, m, &cDelay_mgXwiBoK_sendMessage);
}

void Heavy_SoundScraper::cBinop_GNUrXJ9X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_22YsnUGx, HV_BINOP_MAX, 0, m, &cBinop_22YsnUGx_sendMessage);
}

void Heavy_SoundScraper::cCast_GXgnaMbL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_mgXwiBoK, 0, m, &cDelay_mgXwiBoK_sendMessage);
}

void Heavy_SoundScraper::cMsg_JGUkR6QZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_mgXwiBoK, 0, m, &cDelay_mgXwiBoK_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_vLcb7izi, 0, m, &cDelay_vLcb7izi_sendMessage);
}

void Heavy_SoundScraper::cBinop_QPrQCP5y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_JGUkR6QZ_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_287b4oh5, 0, m, &sTabread_287b4oh5_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_GXgnaMbL_sendMessage);
}

void Heavy_SoundScraper::cBinop_RxJlMxmG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_CO7YXtmN_sendMessage);
}

void Heavy_SoundScraper::cMsg_bsCrqwau_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_3bxNm4Ir_sendMessage);
}

void Heavy_SoundScraper::cVar_hJUM360N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_bsCrqwau_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_mgXwiBoK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_mgXwiBoK, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_vLcb7izi, 0, m, &cDelay_vLcb7izi_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_287b4oh5, 0, m, &sTabread_287b4oh5_sendMessage);
}

void Heavy_SoundScraper::cSystem_Kt7kKPHH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_51yGrh40_sendMessage);
}

void Heavy_SoundScraper::cMsg_MxuQiGAF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Kt7kKPHH_sendMessage);
}

void Heavy_SoundScraper::cMsg_psluHfVQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_22YsnUGx, HV_BINOP_MAX, 1, m, &cBinop_22YsnUGx_sendMessage);
}

void Heavy_SoundScraper::cDelay_vLcb7izi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_vLcb7izi, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_287b4oh5, 0, m, &sTabread_287b4oh5_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_vLcb7izi, 0, m, &cDelay_vLcb7izi_sendMessage);
}

void Heavy_SoundScraper::cMsg_XKyvDh8Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 3000.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_yWYkELLa, 0, m, &cVar_yWYkELLa_sendMessage);
}

void Heavy_SoundScraper::cDelay_2rktEiKe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_2rktEiKe, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_A9c8oUKr, 0, m, &cDelay_A9c8oUKr_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_fHBE5zox, 0, m, &sTabread_fHBE5zox_sendMessage);
}

void Heavy_SoundScraper::cBinop_4obOa0kA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_2rktEiKe, 2, m, &cDelay_2rktEiKe_sendMessage);
}

void Heavy_SoundScraper::cMsg_9pCuWkDN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_HmrFwopm, HV_BINOP_MAX, 1, m, &cBinop_HmrFwopm_sendMessage);
}

void Heavy_SoundScraper::cDelay_A9c8oUKr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_A9c8oUKr, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_fHBE5zox, 0, m, &sTabread_fHBE5zox_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_A9c8oUKr, 0, m, &cDelay_A9c8oUKr_sendMessage);
}

void Heavy_SoundScraper::cBinop_GRC2Y3gO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MSUiSskw, HV_BINOP_MULTIPLY, 0, m, &cBinop_MSUiSskw_sendMessage);
}

void Heavy_SoundScraper::cBinop_HmrFwopm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_JQ8XH6mX, HV_BINOP_SUBTRACT, 1, m, &cBinop_JQ8XH6mX_sendMessage);
}

void Heavy_SoundScraper::cBinop_JQ8XH6mX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_wA9IjUay_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_fHBE5zox, 0, m, &sTabread_fHBE5zox_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_UXC71nrx_sendMessage);
}

void Heavy_SoundScraper::cMsg_JgcBfXCJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_XvEdNmLJ_sendMessage);
}

void Heavy_SoundScraper::cBinop_MSUiSskw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_HmrFwopm, HV_BINOP_MAX, 0, m, &cBinop_HmrFwopm_sendMessage);
}

void Heavy_SoundScraper::cVar_TSmzWwYE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_JgcBfXCJ_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_UXC71nrx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_2rktEiKe, 0, m, &cDelay_2rktEiKe_sendMessage);
}

void Heavy_SoundScraper::cSystem_XvEdNmLJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_rnZmDjgm, HV_BINOP_SUBTRACT, 1, m, &cBinop_rnZmDjgm_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_A9c8oUKr, 2, m, &cDelay_A9c8oUKr_sendMessage);
}

void Heavy_SoundScraper::cCast_YzDUtlvP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_TSmzWwYE, 0, m, &cVar_TSmzWwYE_sendMessage);
  cMsg_vfLLOk7l_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_yB2e39Ly, 0, m, &cTabhead_yB2e39Ly_sendMessage);
}

void Heavy_SoundScraper::sTabread_fHBE5zox_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_rnZmDjgm, HV_BINOP_SUBTRACT, 0, m, &cBinop_rnZmDjgm_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSystem_TRY8bBhd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_GRC2Y3gO_sendMessage);
}

void Heavy_SoundScraper::cMsg_vfLLOk7l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_TRY8bBhd_sendMessage);
}

void Heavy_SoundScraper::cBinop_rnZmDjgm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_4obOa0kA_sendMessage);
}

void Heavy_SoundScraper::cMsg_wA9IjUay_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_2rktEiKe, 0, m, &cDelay_2rktEiKe_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_A9c8oUKr, 0, m, &cDelay_A9c8oUKr_sendMessage);
}

void Heavy_SoundScraper::cTabhead_yB2e39Ly_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_JQ8XH6mX, HV_BINOP_SUBTRACT, 0, m, &cBinop_JQ8XH6mX_sendMessage);
}

void Heavy_SoundScraper::cMsg_NfdD8nG7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_NiAwcgbj, 1, m, NULL);
}

void Heavy_SoundScraper::cMsg_OnWEQSkE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_c9saRde3, 2, m, &cDelay_c9saRde3_sendMessage);
}

void Heavy_SoundScraper::cBinop_QDIp4Iwu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_oDnPJd23_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSystem_dapslZuc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_fcqIVbU1_sendMessage);
}

void Heavy_SoundScraper::cMsg_yBH3EFPG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_dapslZuc_sendMessage);
}

void Heavy_SoundScraper::hTable_aFG3oJ94_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_OnWEQSkE_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_n0OB1FeM, 2, m, &cDelay_n0OB1FeM_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_zfiHiOI9_sendMessage);
}

void Heavy_SoundScraper::cDelay_c9saRde3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_c9saRde3, m);
  cMsg_lTIl5zDB_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_fcqIVbU1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 74.5234f, 0, m, &cBinop_QDIp4Iwu_sendMessage);
}

void Heavy_SoundScraper::cMsg_lTIl5zDB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_aFG3oJ94, 0, m, &hTable_aFG3oJ94_sendMessage);
}

void Heavy_SoundScraper::cDelay_n0OB1FeM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_n0OB1FeM, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_c9saRde3, 0, m, &cDelay_c9saRde3_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_n0OB1FeM, 0, m, &cDelay_n0OB1FeM_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_NiAwcgbj, 1, m, NULL);
}

void Heavy_SoundScraper::cSwitchcase_nOtz2eXo_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_NfdD8nG7_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cMsg_oDnPJd23_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_aFG3oJ94, 0, m, &hTable_aFG3oJ94_sendMessage);
}

void Heavy_SoundScraper::cCast_zfiHiOI9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_n0OB1FeM, 0, m, &cDelay_n0OB1FeM_sendMessage);
}

void Heavy_SoundScraper::cBinop_4CYpXA4h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_8enFBRmX_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_46ESDs6G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ISAfihpm_sendMessage);
}

void Heavy_SoundScraper::cSystem_ISAfihpm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_jQ9otKxF_sendMessage);
}

void Heavy_SoundScraper::cMsg_8enFBRmX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_RXQA5BSx, 0, m, &hTable_RXQA5BSx_sendMessage);
}

void Heavy_SoundScraper::hTable_RXQA5BSx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ReMkE8IC_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ytp7ZEuw, 2, m, &cDelay_ytp7ZEuw_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_yS29xKCK_sendMessage);
}

void Heavy_SoundScraper::cMsg_ReMkE8IC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_UZwrh0VI, 2, m, &cDelay_UZwrh0VI_sendMessage);
}

void Heavy_SoundScraper::cMsg_SnZmM2PV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_bdfczrHz, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_UZwrh0VI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_UZwrh0VI, m);
  cMsg_kzb1znZ9_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_jQ9otKxF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 58.6435f, 0, m, &cBinop_4CYpXA4h_sendMessage);
}

void Heavy_SoundScraper::cMsg_kzb1znZ9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_RXQA5BSx, 0, m, &hTable_RXQA5BSx_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_mHZaPoep_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_SnZmM2PV_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_yS29xKCK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_ytp7ZEuw, 0, m, &cDelay_ytp7ZEuw_sendMessage);
}

void Heavy_SoundScraper::cDelay_ytp7ZEuw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_ytp7ZEuw, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_UZwrh0VI, 0, m, &cDelay_UZwrh0VI_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ytp7ZEuw, 0, m, &cDelay_ytp7ZEuw_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_bdfczrHz, 1, m, NULL);
}

void Heavy_SoundScraper::cPack_ezBvigzM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_uC2DT64B, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_9815Vous_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_acmn9grK, 0, m, &cDelay_acmn9grK_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_9O7pUmk8_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_EDIsnh81_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cMsg_EDIsnh81_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_eo3i8s4D, 1, m, NULL);
}

void Heavy_SoundScraper::cMsg_PjKkcAXP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Saa08CJo_sendMessage);
}

void Heavy_SoundScraper::cSystem_Saa08CJo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_W3w5S84k_sendMessage);
}

void Heavy_SoundScraper::cMsg_JqpBgyWy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_YZR7BrKp, 0, m, &hTable_YZR7BrKp_sendMessage);
}

void Heavy_SoundScraper::cDelay_Nk71rIHa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Nk71rIHa, m);
  cMsg_JqpBgyWy_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_P1fCc1Vj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_YZR7BrKp, 0, m, &hTable_YZR7BrKp_sendMessage);
}

void Heavy_SoundScraper::cBinop_W3w5S84k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 86.1244f, 0, m, &cBinop_xKn51pW0_sendMessage);
}

void Heavy_SoundScraper::hTable_YZR7BrKp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_e4gWCPnI_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_acmn9grK, 2, m, &cDelay_acmn9grK_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_9815Vous_sendMessage);
}

void Heavy_SoundScraper::cDelay_acmn9grK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_acmn9grK, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Nk71rIHa, 0, m, &cDelay_Nk71rIHa_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_acmn9grK, 0, m, &cDelay_acmn9grK_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_eo3i8s4D, 1, m, NULL);
}

void Heavy_SoundScraper::cMsg_e4gWCPnI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_Nk71rIHa, 2, m, &cDelay_Nk71rIHa_sendMessage);
}

void Heavy_SoundScraper::cBinop_xKn51pW0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_P1fCc1Vj_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_0Olyx67a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_U6f4JZzd_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_1BQbilMa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Uz12UbaY, 2, m, &cDelay_Uz12UbaY_sendMessage);
}

void Heavy_SoundScraper::cBinop_1JMoGwnu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_sIJAxyph, HV_BINOP_SUBTRACT, 1, m, &cBinop_sIJAxyph_sendMessage);
}

void Heavy_SoundScraper::cBinop_5Ti2MG8l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_1JMoGwnu, HV_BINOP_MAX, 0, m, &cBinop_1JMoGwnu_sendMessage);
}

void Heavy_SoundScraper::cMsg_5qRB83KQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_1JMoGwnu, HV_BINOP_MAX, 1, m, &cBinop_1JMoGwnu_sendMessage);
}

void Heavy_SoundScraper::cCast_EhlXxVVp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_0Olyx67a, 0, m, &cVar_0Olyx67a_sendMessage);
  cMsg_moX34wwg_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_zgIRUxoj, 0, m, &cTabhead_zgIRUxoj_sendMessage);
}

void Heavy_SoundScraper::cCast_EtnUnqG2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Uz12UbaY, 0, m, &cDelay_Uz12UbaY_sendMessage);
}

void Heavy_SoundScraper::cBinop_KVlSpyHI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_5Ti2MG8l, HV_BINOP_MULTIPLY, 0, m, &cBinop_5Ti2MG8l_sendMessage);
}

void Heavy_SoundScraper::cSystem_Qg7EGEI6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_iEojQvgv, HV_BINOP_SUBTRACT, 1, m, &cBinop_iEojQvgv_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_cC3ArdK1, 2, m, &cDelay_cC3ArdK1_sendMessage);
}

void Heavy_SoundScraper::cMsg_U6f4JZzd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Qg7EGEI6_sendMessage);
}

void Heavy_SoundScraper::cDelay_Uz12UbaY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Uz12UbaY, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_cC3ArdK1, 0, m, &cDelay_cC3ArdK1_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_Y9CraDEf, 0, m, &sTabread_Y9CraDEf_sendMessage);
}

void Heavy_SoundScraper::sTabread_Y9CraDEf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_iEojQvgv, HV_BINOP_SUBTRACT, 0, m, &cBinop_iEojQvgv_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cDelay_cC3ArdK1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_cC3ArdK1, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_Y9CraDEf, 0, m, &sTabread_Y9CraDEf_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_cC3ArdK1, 0, m, &cDelay_cC3ArdK1_sendMessage);
}

void Heavy_SoundScraper::cBinop_iEojQvgv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_1BQbilMa_sendMessage);
}

void Heavy_SoundScraper::cBinop_sIJAxyph_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_vcukulFG_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_Y9CraDEf, 0, m, &sTabread_Y9CraDEf_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_EtnUnqG2_sendMessage);
}

void Heavy_SoundScraper::cSystem_9tZlrvrI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_KVlSpyHI_sendMessage);
}

void Heavy_SoundScraper::cMsg_moX34wwg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_9tZlrvrI_sendMessage);
}

void Heavy_SoundScraper::cMsg_vcukulFG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_Uz12UbaY, 0, m, &cDelay_Uz12UbaY_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_cC3ArdK1, 0, m, &cDelay_cC3ArdK1_sendMessage);
}

void Heavy_SoundScraper::cTabhead_zgIRUxoj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_sIJAxyph, HV_BINOP_SUBTRACT, 0, m, &cBinop_sIJAxyph_sendMessage);
}

void Heavy_SoundScraper::cDelay_09LHT9W5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_09LHT9W5, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_fNPHlwMm, 0, m, &sTabread_fNPHlwMm_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_09LHT9W5, 0, m, &cDelay_09LHT9W5_sendMessage);
}

void Heavy_SoundScraper::cBinop_1UigVVdD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_c6Z8L98C_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_fNPHlwMm, 0, m, &sTabread_fNPHlwMm_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_EmGmlqHw_sendMessage);
}

void Heavy_SoundScraper::cVar_4xtVoWQl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_CscXJBCP_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSystem_h68kXxuc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_ky1DBcwB_sendMessage);
}

void Heavy_SoundScraper::cMsg_m3XYiIpc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_h68kXxuc_sendMessage);
}

void Heavy_SoundScraper::cSystem_BanL9KYI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_OrfZ4x0X, HV_BINOP_SUBTRACT, 1, m, &cBinop_OrfZ4x0X_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_09LHT9W5, 2, m, &cDelay_09LHT9W5_sendMessage);
}

void Heavy_SoundScraper::cMsg_CscXJBCP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_BanL9KYI_sendMessage);
}

void Heavy_SoundScraper::cCast_EmGmlqHw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_ia9QH5BZ, 0, m, &cDelay_ia9QH5BZ_sendMessage);
}

void Heavy_SoundScraper::cCast_LdqrfaOU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_4xtVoWQl, 0, m, &cVar_4xtVoWQl_sendMessage);
  cMsg_m3XYiIpc_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_RIhxzTXX, 0, m, &cTabhead_RIhxzTXX_sendMessage);
}

void Heavy_SoundScraper::cBinop_OrfZ4x0X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_P5sB6SzB_sendMessage);
}

void Heavy_SoundScraper::cBinop_P5sB6SzB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_ia9QH5BZ, 2, m, &cDelay_ia9QH5BZ_sendMessage);
}

void Heavy_SoundScraper::cTabhead_RIhxzTXX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_1UigVVdD, HV_BINOP_SUBTRACT, 0, m, &cBinop_1UigVVdD_sendMessage);
}

void Heavy_SoundScraper::cMsg_c6Z8L98C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_ia9QH5BZ, 0, m, &cDelay_ia9QH5BZ_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_09LHT9W5, 0, m, &cDelay_09LHT9W5_sendMessage);
}

void Heavy_SoundScraper::sTabread_fNPHlwMm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_OrfZ4x0X, HV_BINOP_SUBTRACT, 0, m, &cBinop_OrfZ4x0X_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_gaKKwkFb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_1UigVVdD, HV_BINOP_SUBTRACT, 1, m, &cBinop_1UigVVdD_sendMessage);
}

void Heavy_SoundScraper::cDelay_ia9QH5BZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_ia9QH5BZ, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_09LHT9W5, 0, m, &cDelay_09LHT9W5_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_fNPHlwMm, 0, m, &sTabread_fNPHlwMm_sendMessage);
}

void Heavy_SoundScraper::cBinop_jiI111zV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_gaKKwkFb, HV_BINOP_MAX, 0, m, &cBinop_gaKKwkFb_sendMessage);
}

void Heavy_SoundScraper::cBinop_ky1DBcwB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_jiI111zV, HV_BINOP_MULTIPLY, 0, m, &cBinop_jiI111zV_sendMessage);
}

void Heavy_SoundScraper::cMsg_xHzYMt2t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_gaKKwkFb, HV_BINOP_MAX, 1, m, &cBinop_gaKKwkFb_sendMessage);
}

void Heavy_SoundScraper::cBinop_43A9XlSl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_EwnQNqi5, HV_BINOP_MULTIPLY, 0, m, &cBinop_EwnQNqi5_sendMessage);
}

void Heavy_SoundScraper::cTabhead_4IJwIwRB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_LR8ev6UM, HV_BINOP_SUBTRACT, 0, m, &cBinop_LR8ev6UM_sendMessage);
}

void Heavy_SoundScraper::cMsg_BCqGYrTD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_lP9haw1E_sendMessage);
}

void Heavy_SoundScraper::cSystem_lP9haw1E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_43A9XlSl_sendMessage);
}

void Heavy_SoundScraper::cBinop_EwnQNqi5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Ora2jJZ1, HV_BINOP_MAX, 0, m, &cBinop_Ora2jJZ1_sendMessage);
}

void Heavy_SoundScraper::cMsg_GGx6ikvq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_Ora2jJZ1, HV_BINOP_MAX, 1, m, &cBinop_Ora2jJZ1_sendMessage);
}

void Heavy_SoundScraper::sTabread_KTLNUQgj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_mKnGw8Cb, HV_BINOP_SUBTRACT, 0, m, &cBinop_mKnGw8Cb_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_LR8ev6UM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_WAdi86UL_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_KTLNUQgj, 0, m, &sTabread_KTLNUQgj_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_tvn2TDl5_sendMessage);
}

void Heavy_SoundScraper::cCast_MZCVjXdJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_qTOMUqko, 0, m, &cVar_qTOMUqko_sendMessage);
  cMsg_BCqGYrTD_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_4IJwIwRB, 0, m, &cTabhead_4IJwIwRB_sendMessage);
}

void Heavy_SoundScraper::cBinop_Ora2jJZ1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_LR8ev6UM, HV_BINOP_SUBTRACT, 1, m, &cBinop_LR8ev6UM_sendMessage);
}

void Heavy_SoundScraper::cDelay_Uoc7I2Qy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Uoc7I2Qy, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_hGnCbDbN, 0, m, &cDelay_hGnCbDbN_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_KTLNUQgj, 0, m, &sTabread_KTLNUQgj_sendMessage);
}

void Heavy_SoundScraper::cMsg_WAdi86UL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_Uoc7I2Qy, 0, m, &cDelay_Uoc7I2Qy_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_hGnCbDbN, 0, m, &cDelay_hGnCbDbN_sendMessage);
}

void Heavy_SoundScraper::cDelay_hGnCbDbN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_hGnCbDbN, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_KTLNUQgj, 0, m, &sTabread_KTLNUQgj_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_hGnCbDbN, 0, m, &cDelay_hGnCbDbN_sendMessage);
}

void Heavy_SoundScraper::cMsg_ll84Ss8d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ok7LOd8a_sendMessage);
}

void Heavy_SoundScraper::cBinop_mKnGw8Cb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_r6KktnqJ_sendMessage);
}

void Heavy_SoundScraper::cSystem_ok7LOd8a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_mKnGw8Cb, HV_BINOP_SUBTRACT, 1, m, &cBinop_mKnGw8Cb_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_hGnCbDbN, 2, m, &cDelay_hGnCbDbN_sendMessage);
}

void Heavy_SoundScraper::cVar_qTOMUqko_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ll84Ss8d_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_r6KktnqJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Uoc7I2Qy, 2, m, &cDelay_Uoc7I2Qy_sendMessage);
}

void Heavy_SoundScraper::cCast_tvn2TDl5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Uoc7I2Qy, 0, m, &cDelay_Uoc7I2Qy_sendMessage);
}

void Heavy_SoundScraper::cMsg_0ZSTxzRK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_7LfxGM68, 0, m, &hTable_7LfxGM68_sendMessage);
}

void Heavy_SoundScraper::hTable_7LfxGM68_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_dikOhCD2_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_tDqTr5Nd, 2, m, &cDelay_tDqTr5Nd_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_jx1d3Jnl_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_KogQ6wz1_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_fruivyfO_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cDelay_ONIOIJpt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_ONIOIJpt, m);
  cMsg_0ZSTxzRK_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_Pbwk6IWK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_zv7mhpKo_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_Q5nzofJu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 75.2546f, 0, m, &cBinop_Pbwk6IWK_sendMessage);
}

void Heavy_SoundScraper::cSystem_G6cJdywd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_Q5nzofJu_sendMessage);
}

void Heavy_SoundScraper::cMsg_GQp6DQ0Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_G6cJdywd_sendMessage);
}

void Heavy_SoundScraper::cMsg_dikOhCD2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_ONIOIJpt, 2, m, &cDelay_ONIOIJpt_sendMessage);
}

void Heavy_SoundScraper::cMsg_fruivyfO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_npESjic7, 1, m, NULL);
}

void Heavy_SoundScraper::cCast_jx1d3Jnl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_tDqTr5Nd, 0, m, &cDelay_tDqTr5Nd_sendMessage);
}

void Heavy_SoundScraper::cDelay_tDqTr5Nd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_tDqTr5Nd, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ONIOIJpt, 0, m, &cDelay_ONIOIJpt_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_tDqTr5Nd, 0, m, &cDelay_tDqTr5Nd_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_npESjic7, 1, m, NULL);
}

void Heavy_SoundScraper::cMsg_zv7mhpKo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_7LfxGM68, 0, m, &hTable_7LfxGM68_sendMessage);
}

void Heavy_SoundScraper::cDelay_49X6shXY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_49X6shXY, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_LA1wd9KH, 0, m, &cDelay_LA1wd9KH_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_49X6shXY, 0, m, &cDelay_49X6shXY_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_UmNdxsVV, 1, m, NULL);
}

void Heavy_SoundScraper::cMsg_4ZF8jNMr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_ed4dzP1v, 0, m, &hTable_ed4dzP1v_sendMessage);
}

void Heavy_SoundScraper::cBinop_4jQgGCFm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_5zJYFlMM_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_5zJYFlMM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_ed4dzP1v, 0, m, &hTable_ed4dzP1v_sendMessage);
}

void Heavy_SoundScraper::cMsg_CvCFmPfC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_UmNdxsVV, 1, m, NULL);
}

void Heavy_SoundScraper::cMsg_HCWVwgrr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_LA1wd9KH, 2, m, &cDelay_LA1wd9KH_sendMessage);
}

void Heavy_SoundScraper::cCast_ItucHW2v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_49X6shXY, 0, m, &cDelay_49X6shXY_sendMessage);
}

void Heavy_SoundScraper::cDelay_LA1wd9KH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_LA1wd9KH, m);
  cMsg_4ZF8jNMr_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_ed4dzP1v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_HCWVwgrr_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_49X6shXY, 2, m, &cDelay_49X6shXY_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ItucHW2v_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_pU8dwqJs_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_CvCFmPfC_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cMsg_8ny13VLl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_9XMqheb4_sendMessage);
}

void Heavy_SoundScraper::cSystem_9XMqheb4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_wGBpLuCv_sendMessage);
}

void Heavy_SoundScraper::cBinop_wGBpLuCv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 43.5337f, 0, m, &cBinop_4jQgGCFm_sendMessage);
}

void Heavy_SoundScraper::cCast_93bz1ZK8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_WxrELUTQ, 0, m, &cDelay_WxrELUTQ_sendMessage);
}

void Heavy_SoundScraper::cMsg_Yd9Hf3lz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_vhxPDgNs_sendMessage);
}

void Heavy_SoundScraper::cSystem_vhxPDgNs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_RiOzlVjG_sendMessage);
}

void Heavy_SoundScraper::cBinop_RiOzlVjG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 16.364f, 0, m, &cBinop_ok05ptEh_sendMessage);
}

void Heavy_SoundScraper::cDelay_WxrELUTQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_WxrELUTQ, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_nTiAx3Z0, 0, m, &cDelay_nTiAx3Z0_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_WxrELUTQ, 0, m, &cDelay_WxrELUTQ_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_qgO6IXfk, 1, m, NULL);
}

void Heavy_SoundScraper::cMsg_X2nWfa1Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_jySdBtVo, 0, m, &hTable_jySdBtVo_sendMessage);
}

void Heavy_SoundScraper::cMsg_XVGjXlNp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_qgO6IXfk, 1, m, NULL);
}

void Heavy_SoundScraper::cMsg_c2jvN8v3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_nTiAx3Z0, 2, m, &cDelay_nTiAx3Z0_sendMessage);
}

void Heavy_SoundScraper::hTable_jySdBtVo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_c2jvN8v3_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_WxrELUTQ, 2, m, &cDelay_WxrELUTQ_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_93bz1ZK8_sendMessage);
}

void Heavy_SoundScraper::cMsg_mQFmUWTw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_jySdBtVo, 0, m, &hTable_jySdBtVo_sendMessage);
}

void Heavy_SoundScraper::cDelay_nTiAx3Z0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_nTiAx3Z0, m);
  cMsg_X2nWfa1Q_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_ok05ptEh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_mQFmUWTw_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_pGFGygOD_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_XVGjXlNp_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cMsg_5y0Nva8N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_cOvgzn7Q_sendMessage);
}

void Heavy_SoundScraper::cSystem_cOvgzn7Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_ck7qN6Qt_sendMessage);
}

void Heavy_SoundScraper::cMsg_72GARumQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_SEgP4thX, 1, m, NULL);
}

void Heavy_SoundScraper::cMsg_Mc6e8bXN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_Q5I7LvD0, 0, m, &hTable_Q5I7LvD0_sendMessage);
}

void Heavy_SoundScraper::hTable_Q5I7LvD0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_R1TDQnTO_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_SIMNYWXy, 2, m, &cDelay_SIMNYWXy_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Zx7vdi9s_sendMessage);
}

void Heavy_SoundScraper::cMsg_R1TDQnTO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_dLmDm8cZ, 2, m, &cDelay_dLmDm8cZ_sendMessage);
}

void Heavy_SoundScraper::cDelay_SIMNYWXy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_SIMNYWXy, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_dLmDm8cZ, 0, m, &cDelay_dLmDm8cZ_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_SIMNYWXy, 0, m, &cDelay_SIMNYWXy_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_SEgP4thX, 1, m, NULL);
}

void Heavy_SoundScraper::cBinop_XtCCIMgJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_tgIduLZN_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_Zx7vdi9s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_SIMNYWXy, 0, m, &cDelay_SIMNYWXy_sendMessage);
}

void Heavy_SoundScraper::cBinop_ck7qN6Qt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 19.392f, 0, m, &cBinop_XtCCIMgJ_sendMessage);
}

void Heavy_SoundScraper::cDelay_dLmDm8cZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_dLmDm8cZ, m);
  cMsg_Mc6e8bXN_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_dqPMsj5m_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_72GARumQ_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cMsg_tgIduLZN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_Q5I7LvD0, 0, m, &hTable_Q5I7LvD0_sendMessage);
}

void Heavy_SoundScraper::cSystem_4OGd9oUL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_EbTason2, HV_BINOP_SUBTRACT, 1, m, &cBinop_EbTason2_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_HxStVlIg, 2, m, &cDelay_HxStVlIg_sendMessage);
}

void Heavy_SoundScraper::cBinop_4YXNhWpq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_CYwbyEbL, HV_BINOP_SUBTRACT, 1, m, &cBinop_CYwbyEbL_sendMessage);
}

void Heavy_SoundScraper::cSystem_M34Jiqr9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_qq6K9PHv_sendMessage);
}

void Heavy_SoundScraper::cMsg_ulFj3abE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_M34Jiqr9_sendMessage);
}

void Heavy_SoundScraper::cDelay_ASYbIDGN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_ASYbIDGN, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_HxStVlIg, 0, m, &cDelay_HxStVlIg_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_nDccIDmw, 0, m, &sTabread_nDccIDmw_sendMessage);
}

void Heavy_SoundScraper::cBinop_CYwbyEbL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_saJPZPYh_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_nDccIDmw, 0, m, &sTabread_nDccIDmw_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_JQtnPmlz_sendMessage);
}

void Heavy_SoundScraper::cBinop_DQ4MuwHA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4YXNhWpq, HV_BINOP_MAX, 0, m, &cBinop_4YXNhWpq_sendMessage);
}

void Heavy_SoundScraper::cBinop_EbTason2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_IIS2nFeZ_sendMessage);
}

void Heavy_SoundScraper::cDelay_HxStVlIg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_HxStVlIg, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_nDccIDmw, 0, m, &sTabread_nDccIDmw_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_HxStVlIg, 0, m, &cDelay_HxStVlIg_sendMessage);
}

void Heavy_SoundScraper::cBinop_IIS2nFeZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_ASYbIDGN, 2, m, &cDelay_ASYbIDGN_sendMessage);
}

void Heavy_SoundScraper::cCast_JQtnPmlz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_ASYbIDGN, 0, m, &cDelay_ASYbIDGN_sendMessage);
}

void Heavy_SoundScraper::cTabhead_TNf1eExq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_CYwbyEbL, HV_BINOP_SUBTRACT, 0, m, &cBinop_CYwbyEbL_sendMessage);
}

void Heavy_SoundScraper::cCast_TsR2GQOE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_m3EZUm6A, 0, m, &cVar_m3EZUm6A_sendMessage);
  cMsg_ulFj3abE_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_TNf1eExq, 0, m, &cTabhead_TNf1eExq_sendMessage);
}

void Heavy_SoundScraper::cMsg_bdL5NQmx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_4YXNhWpq, HV_BINOP_MAX, 1, m, &cBinop_4YXNhWpq_sendMessage);
}

void Heavy_SoundScraper::cVar_m3EZUm6A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_oe79uwhZ_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::sTabread_nDccIDmw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_EbTason2, HV_BINOP_SUBTRACT, 0, m, &cBinop_EbTason2_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cMsg_oe79uwhZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_4OGd9oUL_sendMessage);
}

void Heavy_SoundScraper::cBinop_qq6K9PHv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_DQ4MuwHA, HV_BINOP_MULTIPLY, 0, m, &cBinop_DQ4MuwHA_sendMessage);
}

void Heavy_SoundScraper::cMsg_saJPZPYh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_ASYbIDGN, 0, m, &cDelay_ASYbIDGN_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_HxStVlIg, 0, m, &cDelay_HxStVlIg_sendMessage);
}

void Heavy_SoundScraper::cBinop_09UxVico_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_3slr9hG1_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_O8Nzf9kN, 0, m, &sTabread_O8Nzf9kN_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_iFdEsWYa_sendMessage);
}

void Heavy_SoundScraper::cSystem_2GC5qDE9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ZQVRhEvd, HV_BINOP_SUBTRACT, 1, m, &cBinop_ZQVRhEvd_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_3oeH2JBy, 2, m, &cDelay_3oeH2JBy_sendMessage);
}

void Heavy_SoundScraper::cDelay_3oeH2JBy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_3oeH2JBy, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_O8Nzf9kN, 0, m, &sTabread_O8Nzf9kN_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_3oeH2JBy, 0, m, &cDelay_3oeH2JBy_sendMessage);
}

void Heavy_SoundScraper::cMsg_3slr9hG1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_TgQlUfGJ, 0, m, &cDelay_TgQlUfGJ_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_3oeH2JBy, 0, m, &cDelay_3oeH2JBy_sendMessage);
}

void Heavy_SoundScraper::cSystem_qDXTL5sw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_iz7mYQDn_sendMessage);
}

void Heavy_SoundScraper::cMsg_tO5bbbTG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_qDXTL5sw_sendMessage);
}

void Heavy_SoundScraper::cBinop_L7iCtTEe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_09UxVico, HV_BINOP_SUBTRACT, 1, m, &cBinop_09UxVico_sendMessage);
}

void Heavy_SoundScraper::sTabread_O8Nzf9kN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_ZQVRhEvd, HV_BINOP_SUBTRACT, 0, m, &cBinop_ZQVRhEvd_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cMsg_QWylQbiQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_L7iCtTEe, HV_BINOP_MAX, 1, m, &cBinop_L7iCtTEe_sendMessage);
}

void Heavy_SoundScraper::cCast_RC1wuMh1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_YKuyqJkJ, 0, m, &cVar_YKuyqJkJ_sendMessage);
  cMsg_tO5bbbTG_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_ccb5gzCO, 0, m, &cTabhead_ccb5gzCO_sendMessage);
}

void Heavy_SoundScraper::cDelay_TgQlUfGJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_TgQlUfGJ, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_3oeH2JBy, 0, m, &cDelay_3oeH2JBy_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_O8Nzf9kN, 0, m, &sTabread_O8Nzf9kN_sendMessage);
}

void Heavy_SoundScraper::cVar_YKuyqJkJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_yAH7dtxy_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_ZQVRhEvd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_dPHgSIne_sendMessage);
}

void Heavy_SoundScraper::cTabhead_ccb5gzCO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_09UxVico, HV_BINOP_SUBTRACT, 0, m, &cBinop_09UxVico_sendMessage);
}

void Heavy_SoundScraper::cBinop_dPHgSIne_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_TgQlUfGJ, 2, m, &cDelay_TgQlUfGJ_sendMessage);
}

void Heavy_SoundScraper::cCast_iFdEsWYa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_TgQlUfGJ, 0, m, &cDelay_TgQlUfGJ_sendMessage);
}

void Heavy_SoundScraper::cBinop_iufVIBxc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_L7iCtTEe, HV_BINOP_MAX, 0, m, &cBinop_L7iCtTEe_sendMessage);
}

void Heavy_SoundScraper::cBinop_iz7mYQDn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_iufVIBxc, HV_BINOP_MULTIPLY, 0, m, &cBinop_iufVIBxc_sendMessage);
}

void Heavy_SoundScraper::cMsg_yAH7dtxy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_2GC5qDE9_sendMessage);
}

void Heavy_SoundScraper::cBinop_2b1NMNfW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_bO6IcRPn_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_FtY8PYnt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_FtY8PYnt, m);
  cMsg_qtmXJ6NO_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_HtY64ewu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_h4UbNH6N, 1, m, NULL);
}

void Heavy_SoundScraper::hTable_KHlQYXx9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_e5nC9XQl_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_dzwLPIln, 2, m, &cDelay_dzwLPIln_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_RWanfeAY_sendMessage);
}

void Heavy_SoundScraper::cCast_RWanfeAY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_dzwLPIln, 0, m, &cDelay_dzwLPIln_sendMessage);
}

void Heavy_SoundScraper::cMsg_bO6IcRPn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_KHlQYXx9, 0, m, &hTable_KHlQYXx9_sendMessage);
}

void Heavy_SoundScraper::cDelay_dzwLPIln_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_dzwLPIln, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_FtY8PYnt, 0, m, &cDelay_FtY8PYnt_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_dzwLPIln, 0, m, &cDelay_dzwLPIln_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_h4UbNH6N, 1, m, NULL);
}

void Heavy_SoundScraper::cMsg_e5nC9XQl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_FtY8PYnt, 2, m, &cDelay_FtY8PYnt_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_jUQdnW48_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_HtY64ewu_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_qAMdIR2B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 25.796f, 0, m, &cBinop_2b1NMNfW_sendMessage);
}

void Heavy_SoundScraper::cMsg_qtmXJ6NO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_KHlQYXx9, 0, m, &hTable_KHlQYXx9_sendMessage);
}

void Heavy_SoundScraper::cSystem_6gtqa92x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_qAMdIR2B_sendMessage);
}

void Heavy_SoundScraper::cMsg_azcWMMy8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_6gtqa92x_sendMessage);
}

void Heavy_SoundScraper::cBinop_0Xpe4POt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_Mh7qOlAm_sendMessage);
}

void Heavy_SoundScraper::cDelay_5SF5c1Hw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_5SF5c1Hw, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_NbGYCTWS, 0, m, &cDelay_NbGYCTWS_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_xXzVRiLA, 0, m, &sTabread_xXzVRiLA_sendMessage);
}

void Heavy_SoundScraper::cMsg_KriTvrTG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ow1xervc_sendMessage);
}

void Heavy_SoundScraper::cSystem_ow1xervc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_EpHDWzxq_sendMessage);
}

void Heavy_SoundScraper::cBinop_EpHDWzxq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_IIySvyEu, HV_BINOP_MULTIPLY, 0, m, &cBinop_IIySvyEu_sendMessage);
}

void Heavy_SoundScraper::cBinop_GRKCbLCV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_pYJ9MIiT_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_xXzVRiLA, 0, m, &sTabread_xXzVRiLA_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_gRxYPpxw_sendMessage);
}

void Heavy_SoundScraper::cVar_Hz4wWSlG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Z9giYb1b_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_IIySvyEu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_iitru23p, HV_BINOP_MAX, 0, m, &cBinop_iitru23p_sendMessage);
}

void Heavy_SoundScraper::cCast_MeAy33Eq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Hz4wWSlG, 0, m, &cVar_Hz4wWSlG_sendMessage);
  cMsg_KriTvrTG_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_akRr0TKx, 0, m, &cTabhead_akRr0TKx_sendMessage);
}

void Heavy_SoundScraper::cBinop_Mh7qOlAm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_5SF5c1Hw, 2, m, &cDelay_5SF5c1Hw_sendMessage);
}

void Heavy_SoundScraper::cDelay_NbGYCTWS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_NbGYCTWS, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_xXzVRiLA, 0, m, &sTabread_xXzVRiLA_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_NbGYCTWS, 0, m, &cDelay_NbGYCTWS_sendMessage);
}

void Heavy_SoundScraper::cSystem_Tm5B3KTB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_0Xpe4POt, HV_BINOP_SUBTRACT, 1, m, &cBinop_0Xpe4POt_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_NbGYCTWS, 2, m, &cDelay_NbGYCTWS_sendMessage);
}

void Heavy_SoundScraper::cMsg_YLgj1ukC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_iitru23p, HV_BINOP_MAX, 1, m, &cBinop_iitru23p_sendMessage);
}

void Heavy_SoundScraper::cMsg_Z9giYb1b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Tm5B3KTB_sendMessage);
}

void Heavy_SoundScraper::cTabhead_akRr0TKx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_GRKCbLCV, HV_BINOP_SUBTRACT, 0, m, &cBinop_GRKCbLCV_sendMessage);
}

void Heavy_SoundScraper::cCast_gRxYPpxw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_5SF5c1Hw, 0, m, &cDelay_5SF5c1Hw_sendMessage);
}

void Heavy_SoundScraper::cBinop_iitru23p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_GRKCbLCV, HV_BINOP_SUBTRACT, 1, m, &cBinop_GRKCbLCV_sendMessage);
}

void Heavy_SoundScraper::cMsg_pYJ9MIiT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_5SF5c1Hw, 0, m, &cDelay_5SF5c1Hw_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_NbGYCTWS, 0, m, &cDelay_NbGYCTWS_sendMessage);
}

void Heavy_SoundScraper::sTabread_xXzVRiLA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_0Xpe4POt, HV_BINOP_SUBTRACT, 0, m, &cBinop_0Xpe4POt_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_Dlbdddfj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 13.645f, 0, m, &cBinop_zdeDnjTG_sendMessage);
}

void Heavy_SoundScraper::cMsg_HEGB6Fy6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_vassxs94, 0, m, &hTable_vassxs94_sendMessage);
}

void Heavy_SoundScraper::cDelay_M55PrVFx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_M55PrVFx, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_wuuP7HUY, 0, m, &cDelay_wuuP7HUY_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_M55PrVFx, 0, m, &cDelay_M55PrVFx_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_WNGsvgTv, 1, m, NULL);
}

void Heavy_SoundScraper::cCast_WFP7txtm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_M55PrVFx, 0, m, &cDelay_M55PrVFx_sendMessage);
}

void Heavy_SoundScraper::cMsg_XtCvUX2A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_vassxs94, 0, m, &hTable_vassxs94_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_ati25Awg_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_f4adeBbk_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cMsg_f4adeBbk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_WNGsvgTv, 1, m, NULL);
}

void Heavy_SoundScraper::cMsg_AMwHTY0Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Lc8ZpzSp_sendMessage);
}

void Heavy_SoundScraper::cSystem_Lc8ZpzSp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_Dlbdddfj_sendMessage);
}

void Heavy_SoundScraper::cMsg_heY9xzxV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_wuuP7HUY, 2, m, &cDelay_wuuP7HUY_sendMessage);
}

void Heavy_SoundScraper::hTable_vassxs94_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_heY9xzxV_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_M55PrVFx, 2, m, &cDelay_M55PrVFx_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_WFP7txtm_sendMessage);
}

void Heavy_SoundScraper::cDelay_wuuP7HUY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_wuuP7HUY, m);
  cMsg_HEGB6Fy6_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_zdeDnjTG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_XtCvUX2A_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_5SWb0Lcg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_cGSNw4BF_sendMessage);
}

void Heavy_SoundScraper::cBinop_cGSNw4BF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 200.0f, 0, m, &cBinop_1QT8aL29_sendMessage);
}

void Heavy_SoundScraper::cVar_btS5VW3w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_YCzbv3a7_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_N688tfT5_sendMessage);
}

void Heavy_SoundScraper::cBinop_58JQAKg4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 69.4325f, 0, m, &cBinop_KXdM1b3s_sendMessage);
}

void Heavy_SoundScraper::hTable_6RQ15tHQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_8sswa6Qn_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_d5wvg6tU, 2, m, &cDelay_d5wvg6tU_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_avGm5jna_sendMessage);
}

void Heavy_SoundScraper::cSystem_AUPO4n6r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_58JQAKg4_sendMessage);
}

void Heavy_SoundScraper::cMsg_FWgGFZdU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_AUPO4n6r_sendMessage);
}

void Heavy_SoundScraper::cMsg_8sswa6Qn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_pmTy7lUW, 2, m, &cDelay_pmTy7lUW_sendMessage);
}

void Heavy_SoundScraper::cMsg_KEBsS6Pc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_TvRTzorQ, 1, m, NULL);
}

void Heavy_SoundScraper::cBinop_KXdM1b3s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ya0dsmAJ_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_avGm5jna_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_d5wvg6tU, 0, m, &cDelay_d5wvg6tU_sendMessage);
}

void Heavy_SoundScraper::cDelay_d5wvg6tU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_d5wvg6tU, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_pmTy7lUW, 0, m, &cDelay_pmTy7lUW_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_d5wvg6tU, 0, m, &cDelay_d5wvg6tU_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_TvRTzorQ, 1, m, NULL);
}

void Heavy_SoundScraper::cMsg_otgz6Kqu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_6RQ15tHQ, 0, m, &hTable_6RQ15tHQ_sendMessage);
}

void Heavy_SoundScraper::cDelay_pmTy7lUW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_pmTy7lUW, m);
  cMsg_otgz6Kqu_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_qyKoAYHf_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_KEBsS6Pc_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cMsg_ya0dsmAJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_6RQ15tHQ, 0, m, &hTable_6RQ15tHQ_sendMessage);
}

void Heavy_SoundScraper::cVar_Q68rrcEO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_tH7aApmN_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_M3VNKe0r, 0, m, &cIf_M3VNKe0r_sendMessage);
}

void Heavy_SoundScraper::cCast_3MPn0eo7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_KgUstciN, 0, m, &cVar_KgUstciN_sendMessage);
  cMsg_k3qhc7vf_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_YXrQA3J2, 0, m, &cTabhead_YXrQA3J2_sendMessage);
}

void Heavy_SoundScraper::cBinop_E2l5nDr2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MRJzFSvg, HV_BINOP_MULTIPLY, 0, m, &cBinop_MRJzFSvg_sendMessage);
}

void Heavy_SoundScraper::cMsg_HPjtQk1P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_URspPdeT, 0, m, &cDelay_URspPdeT_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_nZHNIorZ, 0, m, &cDelay_nZHNIorZ_sendMessage);
}

void Heavy_SoundScraper::cMsg_Icit5MbF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ZlTLysvX_sendMessage);
}

void Heavy_SoundScraper::cVar_KgUstciN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Icit5MbF_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_MRJzFSvg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_TtciRdhR, HV_BINOP_MAX, 0, m, &cBinop_TtciRdhR_sendMessage);
}

void Heavy_SoundScraper::cBinop_NG3d9ZnJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_qnDRqHnS_sendMessage);
}

void Heavy_SoundScraper::cBinop_RDsrnpUR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_HPjtQk1P_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_XgM7MCjD, 0, m, &sTabread_XgM7MCjD_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_UlHtggTQ_sendMessage);
}

void Heavy_SoundScraper::cBinop_TtciRdhR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_RDsrnpUR, HV_BINOP_SUBTRACT, 1, m, &cBinop_RDsrnpUR_sendMessage);
}

void Heavy_SoundScraper::cDelay_URspPdeT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_URspPdeT, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_nZHNIorZ, 0, m, &cDelay_nZHNIorZ_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_XgM7MCjD, 0, m, &sTabread_XgM7MCjD_sendMessage);
}

void Heavy_SoundScraper::cCast_UlHtggTQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_URspPdeT, 0, m, &cDelay_URspPdeT_sendMessage);
}

void Heavy_SoundScraper::sTabread_XgM7MCjD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_NG3d9ZnJ, HV_BINOP_SUBTRACT, 0, m, &cBinop_NG3d9ZnJ_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cTabhead_YXrQA3J2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_RDsrnpUR, HV_BINOP_SUBTRACT, 0, m, &cBinop_RDsrnpUR_sendMessage);
}

void Heavy_SoundScraper::cSystem_ZlTLysvX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_NG3d9ZnJ, HV_BINOP_SUBTRACT, 1, m, &cBinop_NG3d9ZnJ_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_nZHNIorZ, 2, m, &cDelay_nZHNIorZ_sendMessage);
}

void Heavy_SoundScraper::cMsg_iBbrZkJq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_TtciRdhR, HV_BINOP_MAX, 1, m, &cBinop_TtciRdhR_sendMessage);
}

void Heavy_SoundScraper::cDelay_nZHNIorZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_nZHNIorZ, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_XgM7MCjD, 0, m, &sTabread_XgM7MCjD_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_nZHNIorZ, 0, m, &cDelay_nZHNIorZ_sendMessage);
}

void Heavy_SoundScraper::cBinop_qnDRqHnS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_URspPdeT, 2, m, &cDelay_URspPdeT_sendMessage);
}

void Heavy_SoundScraper::cSystem_9nbcLdkc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_E2l5nDr2_sendMessage);
}

void Heavy_SoundScraper::cMsg_k3qhc7vf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_9nbcLdkc_sendMessage);
}

void Heavy_SoundScraper::cMsg_A2U3DdrV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_pWC2Hk8d, HV_BINOP_POW, 0, m, &cBinop_pWC2Hk8d_sendMessage);
}

void Heavy_SoundScraper::cBinop_L8mIvCl8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_myXjAHwO, 1, m, &cIf_myXjAHwO_sendMessage);
}

void Heavy_SoundScraper::cCast_N688tfT5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_myXjAHwO, 0, m, &cIf_myXjAHwO_sendMessage);
}

void Heavy_SoundScraper::cCast_YCzbv3a7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_L8mIvCl8_sendMessage);
}

void Heavy_SoundScraper::cMsg_gkmSejeE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.125f, 0, m, &cBinop_UXc6kaxb_sendMessage);
}

void Heavy_SoundScraper::cBinop_hiw2zq6K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_s2RqB4wl_sendMessage);
}

void Heavy_SoundScraper::cIf_myXjAHwO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_gkmSejeE_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_hiw2zq6K_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_pWC2Hk8d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.125f, 0, m, &cBinop_UXc6kaxb_sendMessage);
}

void Heavy_SoundScraper::cBinop_s2RqB4wl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_tmHbK2Ps_sendMessage);
}

void Heavy_SoundScraper::cBinop_tmHbK2Ps_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_pWC2Hk8d, HV_BINOP_POW, 1, m, &cBinop_pWC2Hk8d_sendMessage);
  cMsg_A2U3DdrV_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_ixLZUW9e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 100.0f, 0, m, &cBinop_iSXpFufk_sendMessage);
}

void Heavy_SoundScraper::cVar_MpIBnkWC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_h01BVglq, HV_BINOP_MULTIPLY, 0, m, &cBinop_h01BVglq_sendMessage);
}

void Heavy_SoundScraper::cBinop_DaHkZ5dF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_h01BVglq, HV_BINOP_MULTIPLY, 1, m, &cBinop_h01BVglq_sendMessage);
}

void Heavy_SoundScraper::cSystem_Mw2sEQbO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_pRwTbIoX_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_V282R6rK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Mw2sEQbO_sendMessage);
}

void Heavy_SoundScraper::cBinop_h01BVglq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_CgTz2pMU_sendMessage);
}

void Heavy_SoundScraper::cMsg_pRwTbIoX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_DaHkZ5dF_sendMessage);
}

void Heavy_SoundScraper::cBinop_CgTz2pMU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_JdwRblPa_sendMessage);
}

void Heavy_SoundScraper::cBinop_JdwRblPa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_YhdwsXqf_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_Xpj6GjZf, m);
}

void Heavy_SoundScraper::cBinop_YhdwsXqf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_JXDtWNO1, m);
}

void Heavy_SoundScraper::cDelay_00bfKwJX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_00bfKwJX, m);
  cMsg_3NtscPYZ_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_jP7uUh2Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_00bfKwJX, 0, m, &cDelay_00bfKwJX_sendMessage);
}

void Heavy_SoundScraper::cMsg_mdQmsWVH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_00bfKwJX, 0, m, &cDelay_00bfKwJX_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_toR6irzf_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_mdQmsWVH_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_mdQmsWVH_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_00bfKwJX, 1, m, &cDelay_00bfKwJX_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_jP7uUh2Q_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cVar_yNkmr4rV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.05776f, 0, m, &cBinop_fEqdfucC_sendMessage);
}

void Heavy_SoundScraper::cPack_hICvL53O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_8gj0B0K3, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_hVcQMAdy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_hICvL53O, 0, m, &cPack_hICvL53O_sendMessage);
}

void Heavy_SoundScraper::cVar_eb8bh5Tb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_hICvL53O, 0, m, &cPack_hICvL53O_sendMessage);
}

void Heavy_SoundScraper::cMsg_6Xw8jvRr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 20.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_v8wXUZlu, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_Lohgnt4I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_o6PpaNAI, m);
}

void Heavy_SoundScraper::cBinop_pBpFjPk9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, -1.0f, 0, m, &cBinop_Lohgnt4I_sendMessage);
}

void Heavy_SoundScraper::cVar_E2Te6apB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_6Xw8jvRr_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_3ZETouFG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_VM2Dv7WM_sendMessage);
}

void Heavy_SoundScraper::cBinop_CyBvpwzM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_h9b0vrTz, m);
}

void Heavy_SoundScraper::cSystem_VM2Dv7WM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_nUKnHWIX_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_3YLMKCtN, m);
}

void Heavy_SoundScraper::cVar_1wlv4jAe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_3ZETouFG_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_nUKnHWIX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_HpEo7pyO, m);
}

void Heavy_SoundScraper::cSystem_VjUOkNfE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_CyBvpwzM_sendMessage);
}

void Heavy_SoundScraper::cMsg_arWbJhlG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_VjUOkNfE_sendMessage);
}

void Heavy_SoundScraper::cBinop_1j0TwZna_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_fVyUmoby_sendMessage);
}

void Heavy_SoundScraper::cBinop_ESzkSyWI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_eqlxABbB_sendMessage);
}

void Heavy_SoundScraper::cBinop_S4W115Z8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_d18kc4ju, m);
}

void Heavy_SoundScraper::cBinop_XSLYdBna_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_aOyNmdiR, m);
}

void Heavy_SoundScraper::cBinop_YcP5whC6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_XSLYdBna_sendMessage);
}

void Heavy_SoundScraper::cBinop_4wYWZjmV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_YcP5whC6_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_S4W115Z8_sendMessage);
}

void Heavy_SoundScraper::cBinop_fVyUmoby_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_4wYWZjmV_sendMessage);
}

void Heavy_SoundScraper::cVar_kFmB3ZJL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_ESzkSyWI_sendMessage);
}

void Heavy_SoundScraper::cBinop_eqlxABbB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_hJ41yyud, HV_BINOP_DIVIDE, 0, m, &cBinop_hJ41yyud_sendMessage);
}

void Heavy_SoundScraper::cBinop_hJ41yyud_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_t3Rt5GNg_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSystem_KoYU4z7X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_hJ41yyud, HV_BINOP_DIVIDE, 1, m, &cBinop_hJ41yyud_sendMessage);
}

void Heavy_SoundScraper::cMsg_QVPGhvT7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_KoYU4z7X_sendMessage);
}

void Heavy_SoundScraper::cMsg_t3Rt5GNg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_1j0TwZna_sendMessage);
}

void Heavy_SoundScraper::cMsg_bHz7q75y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cMsg_6Xw8jvRr_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_0gVgvaAf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 500.0f, 0, m, &cBinop_kVrCvmNG_sendMessage);
}

void Heavy_SoundScraper::cMsg_2m3Q3ZsU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_dW9XFL9Q, 1, m, NULL);
}

void Heavy_SoundScraper::hTable_Bf8NPbuA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_zGPE9556_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_E8pX8p1R, 2, m, &cDelay_E8pX8p1R_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_j5P5Etez_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_DwKp1vqV_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_2m3Q3ZsU_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cDelay_E8pX8p1R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_E8pX8p1R, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_FgC9tAJs, 0, m, &cDelay_FgC9tAJs_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_E8pX8p1R, 0, m, &cDelay_E8pX8p1R_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_dW9XFL9Q, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_FgC9tAJs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_FgC9tAJs, m);
  cMsg_ZmvledNo_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_ZmvledNo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_Bf8NPbuA, 0, m, &hTable_Bf8NPbuA_sendMessage);
}

void Heavy_SoundScraper::cMsg_aTh5Iipb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_Bf8NPbuA, 0, m, &hTable_Bf8NPbuA_sendMessage);
}

void Heavy_SoundScraper::cCast_j5P5Etez_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_E8pX8p1R, 0, m, &cDelay_E8pX8p1R_sendMessage);
}

void Heavy_SoundScraper::cMsg_3XuyEAJV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_tP6MR5Rt_sendMessage);
}

void Heavy_SoundScraper::cSystem_tP6MR5Rt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_0gVgvaAf_sendMessage);
}

void Heavy_SoundScraper::cBinop_kVrCvmNG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_aTh5Iipb_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_zGPE9556_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_FgC9tAJs, 2, m, &cDelay_FgC9tAJs_sendMessage);
}

void Heavy_SoundScraper::cBinop_VcviOus8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_SvNCDnN6_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_VmXj2GYM, m);
}

void Heavy_SoundScraper::cBinop_oQwqtKJz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_VcviOus8_sendMessage);
}

void Heavy_SoundScraper::cBinop_SvNCDnN6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_ToQ7iRm0, m);
}

void Heavy_SoundScraper::cMsg_VDxtH6hS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_eA6s9mwy_sendMessage);
}

void Heavy_SoundScraper::cMsg_OGhYuQqG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_h72IJPvd_sendMessage);
}

void Heavy_SoundScraper::cSystem_h72IJPvd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_VDxtH6hS_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_dst35s5q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_oQwqtKJz_sendMessage);
}

void Heavy_SoundScraper::cBinop_eA6s9mwy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_dst35s5q, HV_BINOP_MULTIPLY, 1, m, &cBinop_dst35s5q_sendMessage);
}

void Heavy_SoundScraper::cVar_8thkYCby_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_dst35s5q, HV_BINOP_MULTIPLY, 0, m, &cBinop_dst35s5q_sendMessage);
}

void Heavy_SoundScraper::cCast_30tQoujw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.0f, 0, m, &cBinop_rPJtY3Av_sendMessage);
}

void Heavy_SoundScraper::cBinop_MMOLa641_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_tmJqOAeA_sendMessage);
}

void Heavy_SoundScraper::cBinop_tmJqOAeA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_Xtb8SrTU_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_Gcz4I6Xl, m);
}

void Heavy_SoundScraper::cBinop_Xtb8SrTU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_DNLO2Q6E, m);
}

void Heavy_SoundScraper::cMsg_7W9JkMDs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_V8K6U5W0_sendMessage);
}

void Heavy_SoundScraper::cBinop_V8K6U5W0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_cmoWVJIv, HV_BINOP_MULTIPLY, 1, m, &cBinop_cmoWVJIv_sendMessage);
}

void Heavy_SoundScraper::cBinop_cmoWVJIv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_MMOLa641_sendMessage);
}

void Heavy_SoundScraper::cMsg_oNST9V0A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_pclyTK01_sendMessage);
}

void Heavy_SoundScraper::cSystem_pclyTK01_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_7W9JkMDs_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_6gGIbERR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_cmoWVJIv, HV_BINOP_MULTIPLY, 0, m, &cBinop_cmoWVJIv_sendMessage);
}

void Heavy_SoundScraper::cVar_UwYm2B3w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_dYzXVGuk, HV_BINOP_MULTIPLY, 0, m, &cBinop_dYzXVGuk_sendMessage);
}

void Heavy_SoundScraper::cBinop_LPTJYrUI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_mz6JBFLg_sendMessage);
}

void Heavy_SoundScraper::cBinop_mz6JBFLg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_Kic1l2wI_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_kWAJOmwx, m);
}

void Heavy_SoundScraper::cBinop_Kic1l2wI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_Yh1CU5cO, m);
}

void Heavy_SoundScraper::cMsg_KMy9GpdV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_svZJianT_sendMessage);
}

void Heavy_SoundScraper::cSystem_svZJianT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_v5HeQKNL_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_7Xvxu4rE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_dYzXVGuk, HV_BINOP_MULTIPLY, 1, m, &cBinop_dYzXVGuk_sendMessage);
}

void Heavy_SoundScraper::cBinop_dYzXVGuk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_LPTJYrUI_sendMessage);
}

void Heavy_SoundScraper::cMsg_v5HeQKNL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_7Xvxu4rE_sendMessage);
}

void Heavy_SoundScraper::cBinop_LB2XcOiB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_h9nbQXbI, 0, m, &cVar_h9nbQXbI_sendMessage);
}

void Heavy_SoundScraper::cCast_N7qKqvxi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.0f, 0, m, &cBinop_c3Mwp4Ae_sendMessage);
}

void Heavy_SoundScraper::cBinop_c3Mwp4Ae_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_UwYm2B3w, 0, m, &cVar_UwYm2B3w_sendMessage);
}

void Heavy_SoundScraper::cCast_eT05Xfs4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.0f, 0, m, &cBinop_LB2XcOiB_sendMessage);
}

void Heavy_SoundScraper::cCast_iep9NulX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_bJgA5bbd, m);
}

void Heavy_SoundScraper::cBinop_0sv3ZQWJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_LxI1HyGl_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_kTQEnTOC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1e-05f, 0, m, &cBinop_G9n95322_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_ivMuJqsG, 0, m, &cIf_ivMuJqsG_sendMessage);
}

void Heavy_SoundScraper::cMsg_ivzwmUjH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_kwlF7ACw_sendMessage);
}

void Heavy_SoundScraper::cSystem_kwlF7ACw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_dTMKA3fO_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_LxI1HyGl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_mW4j32GD_sendMessage);
}

void Heavy_SoundScraper::cBinop_Mw9ow1oD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_iYpB7zhT, m);
}

void Heavy_SoundScraper::cBinop_G9n95322_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_ivMuJqsG, 1, m, &cIf_ivMuJqsG_sendMessage);
}

void Heavy_SoundScraper::cIf_ivMuJqsG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_vbNyBh3P_sendMessage(_c, 0, m);
      cMsg_ZA4zOFPD_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_VhMHnWWh_sendMessage(_c, 0, m);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_uzWSdlxG_sendMessage);
      sVarf_onMessage(_c, &Context(_c)->sVarf_hs5c8nL0, m);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cMsg_VhMHnWWh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_l4kk134f_sendMessage);
}

void Heavy_SoundScraper::cMsg_ZA4zOFPD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, -1.0f);
  sVarf_onMessage(_c, &Context(_c)->sVarf_JkevEWcv, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_hs5c8nL0, m);
}

void Heavy_SoundScraper::cMsg_dTMKA3fO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_Mw9ow1oD_sendMessage);
}

void Heavy_SoundScraper::cBinop_l4kk134f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_JkevEWcv, m);
}

void Heavy_SoundScraper::cBinop_mW4j32GD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_gszK72BP, m);
}

void Heavy_SoundScraper::cBinop_uzWSdlxG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_vPzzhTE8_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_vPzzhTE8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_0sv3ZQWJ_sendMessage);
}

void Heavy_SoundScraper::cMsg_vbNyBh3P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_uzWSdlxG_sendMessage);
}

void Heavy_SoundScraper::cBinop_2HStWATz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_RQHZL2VS_sendMessage);
}

void Heavy_SoundScraper::cMsg_P9rxUXcZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_hezYtxLh_sendMessage);
}

void Heavy_SoundScraper::cSystem_hezYtxLh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_TmBUKM5C_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_TmBUKM5C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_sGAyQg1E_sendMessage);
}

void Heavy_SoundScraper::cBinop_sGAyQg1E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_2HStWATz, HV_BINOP_MULTIPLY, 1, m, &cBinop_2HStWATz_sendMessage);
}

void Heavy_SoundScraper::cBinop_MTZX9EJ5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_RhqldvPb_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_0T93HxmZ, m);
}

void Heavy_SoundScraper::cBinop_RQHZL2VS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_MTZX9EJ5_sendMessage);
}

void Heavy_SoundScraper::cBinop_RhqldvPb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_g2lHkJLb, m);
}

void Heavy_SoundScraper::cVar_h9nbQXbI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_2HStWATz, HV_BINOP_MULTIPLY, 0, m, &cBinop_2HStWATz_sendMessage);
}

void Heavy_SoundScraper::cBinop_rPJtY3Av_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_6gGIbERR, 0, m, &cVar_6gGIbERR_sendMessage);
}

void Heavy_SoundScraper::cBinop_0KdTGCJk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Y8Q2VQj4_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_4sIYZMJp_sendMessage);
}

void Heavy_SoundScraper::cBinop_R3byJKy5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_0KdTGCJk_sendMessage);
}

void Heavy_SoundScraper::cCast_4sIYZMJp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_qgkeLayB, 0, m, &cIf_qgkeLayB_sendMessage);
}

void Heavy_SoundScraper::cBinop_CWRhSFBx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_CzleO8Qy_sendMessage);
}

void Heavy_SoundScraper::cBinop_CzleO8Qy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_8zmf3lwk, 0, m, &cVar_8zmf3lwk_sendMessage);
}

void Heavy_SoundScraper::cMsg_UkHLErmq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_8zmf3lwk, 0, m, &cVar_8zmf3lwk_sendMessage);
}

void Heavy_SoundScraper::cCast_Y8Q2VQj4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_bcR7beex_sendMessage);
}

void Heavy_SoundScraper::cUnop_YJmhcxIZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_xxk6bUbD_sendMessage);
}

void Heavy_SoundScraper::cBinop_bcR7beex_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_qgkeLayB, 1, m, &cIf_qgkeLayB_sendMessage);
}

void Heavy_SoundScraper::cIf_qgkeLayB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_UkHLErmq_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_LOG10, m, &cUnop_YJmhcxIZ_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_xxk6bUbD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 100.0f, 0, m, &cBinop_CWRhSFBx_sendMessage);
}

void Heavy_SoundScraper::cReceive_8ia9UA0J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_VYGTLUEb, 0, m, NULL);
  cPrint_onMessage(_c, m, "TABLEPLAYER_PHASE");
  cSlice_onMessage(_c, &Context(_c)->cSlice_uCFw3d3O, 0, m, &cSlice_uCFw3d3O_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_SOSLB9w9, 0, m, &cSlice_SOSLB9w9_sendMessage);
}

void Heavy_SoundScraper::cVar_MZyuKpsl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::hTable_GoJVpFWT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::hTable_L5Asm0JQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::hTable_SY2T5LAU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::hTable_XZhy7ncS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::hTable_ZnFQ5VXv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::hTable_rwOMuyMM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cSend_7yUBE6lU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_C1lp9X1Z_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_I7jeegSh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_YzPn1YFy_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_g2tD0tVi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_7yUBE6lU_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_5d4tbG8C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_E62IxLfI, HV_BINOP_POW, 1, m, &cBinop_E62IxLfI_sendMessage);
  cMsg_ZeAtRi5b_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cIf_BCe4LD1P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_EIDmJWYE_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_fHjSv7P0_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_E62IxLfI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_SvkpEzkg, 0, m, &cPack_SvkpEzkg_sendMessage);
}

void Heavy_SoundScraper::cMsg_EIDmJWYE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_SvkpEzkg, 0, m, &cPack_SvkpEzkg_sendMessage);
}

void Heavy_SoundScraper::cCast_G2xu6mmc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_ZcyNCAM4_sendMessage);
}

void Heavy_SoundScraper::cBinop_ZcyNCAM4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_BCe4LD1P, 1, m, &cIf_BCe4LD1P_sendMessage);
}

void Heavy_SoundScraper::cMsg_ZeAtRi5b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_E62IxLfI, HV_BINOP_POW, 0, m, &cBinop_E62IxLfI_sendMessage);
}

void Heavy_SoundScraper::cBinop_fHjSv7P0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_qkC9uy0h_sendMessage);
}

void Heavy_SoundScraper::cBinop_qkC9uy0h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_5d4tbG8C_sendMessage);
}

void Heavy_SoundScraper::cCast_rM3gjqCZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_BCe4LD1P, 0, m, &cIf_BCe4LD1P_sendMessage);
}

void Heavy_SoundScraper::cMsg_QmRPbkHJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSend_I7jeegSh_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_SvkpEzkg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_nzETJbrO, 0, m, NULL);
}

void Heavy_SoundScraper::cVar_2HkT7EA4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_QmRPbkHJ_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_G2xu6mmc_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_rM3gjqCZ_sendMessage);
}

void Heavy_SoundScraper::cReceive_C1lp9X1Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_G2xu6mmc_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_rM3gjqCZ_sendMessage);
}

void Heavy_SoundScraper::cReceive_CyRdbAJg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_KRQa77bb, 0, m, NULL);
  cPrint_onMessage(_c, m, "TABLEPLAYER_CUTOFF");
}

void Heavy_SoundScraper::cReceive_Do9nya8H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_b6xvQooS_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cReceive_EEWf9xk7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_cS0XuRV6_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cReceive_EZSbojeT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 10.0f, 0, m, &cBinop_Ieib1wKz_sendMessage);
}

void Heavy_SoundScraper::cReceive_Eklo03qa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 2.0f, 0, m, &cBinop_R3byJKy5_sendMessage);
}

void Heavy_SoundScraper::cReceive_FGUdnHin_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_xpi24x7y, m);
}

void Heavy_SoundScraper::cReceive_FhL5QWRt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_NHbGz78k_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cReceive_H9uGa2DN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_RH0tEmei_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_IU0YaDfn_sendMessage);
}

void Heavy_SoundScraper::cReceive_JUsaRojU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_IzpMzzdU, 0, m, &cVar_IzpMzzdU_sendMessage);
}

void Heavy_SoundScraper::cReceive_JfpuuerB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPrint_onMessage(_c, m, "SOUND_CHOICE");
  cSwitchcase_OlWp75wO_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cReceive_Ju1xS2TW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_lzgTWItE_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cReceive_KAf1xh4c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_3n85lNl6, 1, m, &cVar_3n85lNl6_sendMessage);
}

void Heavy_SoundScraper::cReceive_KdXsCelA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 2.0f, 0, m, &cBinop_3WLu8nqg_sendMessage);
}

void Heavy_SoundScraper::cReceive_KuzwHoLG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_mlL2eYQA_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_GvTDKCNU_sendMessage);
}

void Heavy_SoundScraper::cReceive_MDy21nR2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_dRkzStc1_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_MoUbWGXF_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Fa7CGMtR_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_nB8zyn4R_sendMessage);
}

void Heavy_SoundScraper::cReceive_PC7vIRkt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_cAPdStYy, 0, m, NULL);
  cPrint_onMessage(_c, m, "TABLEPLAYER_PHASE");
  cSlice_onMessage(_c, &Context(_c)->cSlice_VHV4oP1k, 0, m, &cSlice_VHV4oP1k_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_mwUeFqx8, 0, m, &cSlice_mwUeFqx8_sendMessage);
}

void Heavy_SoundScraper::cVar_oPZ52NA3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_9jt7KXfg_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_mlL2eYQA_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_GvTDKCNU_sendMessage);
}

void Heavy_SoundScraper::cMsg_05msPNT8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_WiL0lRa1, HV_BINOP_POW, 0, m, &cBinop_WiL0lRa1_sendMessage);
}

void Heavy_SoundScraper::cMsg_Ax8KtI1r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_qohOHo7T, 0, m, &cPack_qohOHo7T_sendMessage);
}

void Heavy_SoundScraper::cBinop_FhaVGDRA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_WiL0lRa1, HV_BINOP_POW, 1, m, &cBinop_WiL0lRa1_sendMessage);
  cMsg_05msPNT8_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_GvTDKCNU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_SaUsJ7St, 0, m, &cIf_SaUsJ7St_sendMessage);
}

void Heavy_SoundScraper::cIf_SaUsJ7St_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_Ax8KtI1r_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_fnWnKPoD_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_SetbxVoN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_FhaVGDRA_sendMessage);
}

void Heavy_SoundScraper::cBinop_WiL0lRa1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_qohOHo7T, 0, m, &cPack_qohOHo7T_sendMessage);
}

void Heavy_SoundScraper::cBinop_fnWnKPoD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_SetbxVoN_sendMessage);
}

void Heavy_SoundScraper::cCast_mlL2eYQA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_valWFdTL_sendMessage);
}

void Heavy_SoundScraper::cBinop_valWFdTL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_SaUsJ7St, 1, m, &cIf_SaUsJ7St_sendMessage);
}

void Heavy_SoundScraper::cSend_7uXBdYhH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_KuzwHoLG_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_9jt7KXfg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSend_IVw5NeCf_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_IVw5NeCf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_kF0RAx1I_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_gmMUMGJa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_7uXBdYhH_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_qohOHo7T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_xVktYncJ, 0, m, NULL);
}

void Heavy_SoundScraper::cReceive_RJ028IRF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_HIEYxg14, 0, m, NULL);
  cPrint_onMessage(_c, m, "TABLEPLAYER_CUTOFF");
}

void Heavy_SoundScraper::cReceive_RT1zMGKA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_OhR0L8UX, 0, m, NULL);
  cPrint_onMessage(_c, m, "TABLEPLAYER_CUTOFF");
}

void Heavy_SoundScraper::cReceive_RUVe3pDV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 10.0f, 0, m, &cBinop_31yCYjXr_sendMessage);
}

void Heavy_SoundScraper::cReceive_RoL1C3Kj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_PEcK7y0d_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_BkkUCsw0_sendMessage);
}

void Heavy_SoundScraper::cSend_9bzJQt9S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_5f3FvQpl_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_IBNg1qeo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_OJILvvIa_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_PF6hsemO_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_bg5dMEaN_sendMessage);
}

void Heavy_SoundScraper::cPack_JMWa4cFu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_naTWa0RH, 0, m, NULL);
}

void Heavy_SoundScraper::cMsg_OJILvvIa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSend_9bzJQt9S_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_BWYDpnlV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_e5YXrsnt_sendMessage);
}

void Heavy_SoundScraper::cBinop_FpzUiI39_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_BWYDpnlV_sendMessage);
}

void Heavy_SoundScraper::cMsg_ImFlOMh4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_JMWa4cFu, 0, m, &cPack_JMWa4cFu_sendMessage);
}

void Heavy_SoundScraper::cIf_K3Acz3SK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_ImFlOMh4_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_FpzUiI39_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cCast_PF6hsemO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_Q2Ea7NBs_sendMessage);
}

void Heavy_SoundScraper::cBinop_Q2Ea7NBs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_K3Acz3SK, 1, m, &cIf_K3Acz3SK_sendMessage);
}

void Heavy_SoundScraper::cMsg_T4gOq49j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_fzrQlUBr, HV_BINOP_POW, 0, m, &cBinop_fzrQlUBr_sendMessage);
}

void Heavy_SoundScraper::cCast_bg5dMEaN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_K3Acz3SK, 0, m, &cIf_K3Acz3SK_sendMessage);
}

void Heavy_SoundScraper::cBinop_e5YXrsnt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_fzrQlUBr, HV_BINOP_POW, 1, m, &cBinop_fzrQlUBr_sendMessage);
  cMsg_T4gOq49j_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_fzrQlUBr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_JMWa4cFu, 0, m, &cPack_JMWa4cFu_sendMessage);
}

void Heavy_SoundScraper::cSend_ZkF7p7zP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_q6o7mfie_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_PPwh3jr2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_ZkF7p7zP_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cReceive_SJ6Uh0vb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSlice_onMessage(_c, &Context(_c)->cSlice_UKaWzyTm, 0, m, &cSlice_UKaWzyTm_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_ywl0oAeO, 0, m, &cSlice_ywl0oAeO_sendMessage);
}

void Heavy_SoundScraper::cBinop_0goEnjha_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_9QMiBk7R_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_uXds3GAT_sendMessage);
}

void Heavy_SoundScraper::cBinop_5KkNz9hd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_0goEnjha_sendMessage);
}

void Heavy_SoundScraper::cBinop_3jV8t8rT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_9jt7KXfg_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_mlL2eYQA_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_GvTDKCNU_sendMessage);
}

void Heavy_SoundScraper::cCast_9QMiBk7R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_Lc80FH3Y_sendMessage);
}

void Heavy_SoundScraper::cBinop_Lc80FH3Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_MRGtgAVW, 1, m, &cIf_MRGtgAVW_sendMessage);
}

void Heavy_SoundScraper::cIf_MRGtgAVW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_YAsDIvI6_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_LOG10, m, &cUnop_xUy7xUMU_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_VPfHdar0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 100.0f, 0, m, &cBinop_ex0pWH5s_sendMessage);
}

void Heavy_SoundScraper::cMsg_YAsDIvI6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cMsg_9jt7KXfg_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_mlL2eYQA_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_GvTDKCNU_sendMessage);
}

void Heavy_SoundScraper::cBinop_ex0pWH5s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_3jV8t8rT_sendMessage);
}

void Heavy_SoundScraper::cCast_uXds3GAT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_MRGtgAVW, 0, m, &cIf_MRGtgAVW_sendMessage);
}

void Heavy_SoundScraper::cUnop_xUy7xUMU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_VPfHdar0_sendMessage);
}

void Heavy_SoundScraper::cReceive_TIg47hmJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_vXq9ty0r_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cReceive_UdPOlQ82_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_F2XDIkNh_sendMessage(_c, 0, m);
  cSwitchcase_yJOjuJ77_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cReceive_VzckN8pw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_IB7l1ctW, 0, m, NULL);
  cPrint_onMessage(_c, m, "TABLEPLAYER_PHASE");
  cSlice_onMessage(_c, &Context(_c)->cSlice_SeWjqHEN, 0, m, &cSlice_SeWjqHEN_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_L70vIPrx, 0, m, &cSlice_L70vIPrx_sendMessage);
}

void Heavy_SoundScraper::cReceive_WLjoD2qK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_16bc7eRS, 1, m, &cVar_16bc7eRS_sendMessage);
}

void Heavy_SoundScraper::cReceive_WM57f9yw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_TB87PUyv, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_aEHBNCon, m);
}

void Heavy_SoundScraper::cReceive_WatQHk0Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_kY6DhUSe_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_NcKfd4xP_sendMessage);
  cPack_onMessage(_c, &Context(_c)->cPack_qcUSrU6Z, 0, m, &cPack_qcUSrU6Z_sendMessage);
}

void Heavy_SoundScraper::cReceive_Wd4NhQ0S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_aT0m7Cx6, 0, m, &cVar_aT0m7Cx6_sendMessage);
}

void Heavy_SoundScraper::cReceive_Xk8uDKfY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_id113mRK, 0, m, &cVar_id113mRK_sendMessage);
}

void Heavy_SoundScraper::cUnop_Dm15jdar_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_9QPEkCU1_sendMessage);
}

void Heavy_SoundScraper::cSlice_NrC9tRUh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_web4DBtt, 1, m, &cRandom_web4DBtt_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSwitchcase_cS0XuRV6_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_NrC9tRUh, 0, m, &cSlice_NrC9tRUh_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_web4DBtt, 0, m, &cRandom_web4DBtt_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_rFTggjPm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_Dm15jdar_sendMessage);
}

void Heavy_SoundScraper::cRandom_web4DBtt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 5.0f, 0, m, &cBinop_rFTggjPm_sendMessage);
}

void Heavy_SoundScraper::cMsg_41kwLY1E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "marimba");
  msg_setFloat(m, 1, 264.0f);
  cSend_itiqMOM6_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_4qvcCp2s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "xylo");
  msg_setFloat(m, 1, 2116.9f);
  cSend_itiqMOM6_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_5EgQ3TUu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_MBahhtxZ_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_FaTxCQFd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_4qvcCp2s_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_Iycc6Hb7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Cl9CNQxI_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_JGpdoCai_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_MO6aNndp_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_Mqan02oo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_41kwLY1E_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_OlWp75wO_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x40000000: { // "2.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Iycc6Hb7_sendMessage);
      break;
    }
    case 0x40400000: { // "3.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_JGpdoCai_sendMessage);
      break;
    }
    case 0x40800000: { // "4.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_5EgQ3TUu_sendMessage);
      break;
    }
    case 0x40A00000: { // "5.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_pperUyEz_sendMessage);
      break;
    }
    case 0x40C00000: { // "6.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Mqan02oo_sendMessage);
      break;
    }
    case 0x40E00000: { // "7.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_FaTxCQFd_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_pperUyEz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_rW2aJlLj_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_9QPEkCU1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPrint_onMessage(_c, m, "SOUND_CHOICE");
  cSwitchcase_OlWp75wO_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cMsg_Cl9CNQxI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "almglocken");
  msg_setFloat(m, 1, 262.6f);
  cSend_itiqMOM6_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_MBahhtxZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "crotale");
  msg_setFloat(m, 1, 1058.39f);
  cSend_itiqMOM6_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_MO6aNndp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "gong");
  msg_setFloat(m, 1, 179.88f);
  cSend_itiqMOM6_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_itiqMOM6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_2ZtI90gj_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_rW2aJlLj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "bowl");
  msg_setFloat(m, 1, 705.52f);
  cSend_itiqMOM6_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cReceive_YzPn1YFy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_g2tD0tVi, 0, m, &cVar_g2tD0tVi_sendMessage);
}

void Heavy_SoundScraper::cReceive_ZDc3behT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_K68lKhS2_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cReceive_aEZ3Zkri_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_Ji6gv0SC_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cReceive_bcGB1aGC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_qm8yewgh, 0, m, NULL);
  cPrint_onMessage(_c, m, "TABLEPLAYER_CUTOFF");
}

void Heavy_SoundScraper::cReceive_dA7RIHfw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_yDNqQqM2, HV_BINOP_DIVIDE, 1, m, &cBinop_yDNqQqM2_sendMessage);
}

void Heavy_SoundScraper::cReceive_dzV4DPcb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_48LijKnP, 1, m, &cVar_48LijKnP_sendMessage);
}

void Heavy_SoundScraper::cCast_1zJ53JCY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_oOdCKp9p, 0, m, &cPack_oOdCKp9p_sendMessage);
}

void Heavy_SoundScraper::cVar_16bc7eRS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_oOdCKp9p, 1, m, &cPack_oOdCKp9p_sendMessage);
}

void Heavy_SoundScraper::cCast_SJpHuEE2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_16bc7eRS, 0, m, &cVar_16bc7eRS_sendMessage);
}

void Heavy_SoundScraper::cPack_oOdCKp9p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Y3fYBJlC_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_nf29zP9d_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_BzwFzVkh, 0, m, &cSlice_BzwFzVkh_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_OgHEb7k7, 0, m, &cSlice_OgHEb7k7_sendMessage);
  cPrint_onMessage(_c, m, "TABLEPLAYER_COMMAND");
}

void Heavy_SoundScraper::cSlice_AwTrNThN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSend_ZNxmoVhg_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_y01lKo1A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSend_iOKitXNS_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_7Z4Qgs9V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.4f, 0, m, &cBinop_wtzCY1uX_sendMessage);
}

void Heavy_SoundScraper::cPack_0zjXZR82_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_qrMOoCPx_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_1gQyYqzw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_wY2x51Xz, 0, m, &cVar_wY2x51Xz_sendMessage);
}

void Heavy_SoundScraper::cCast_9m8oiw6a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_POgWkKRP_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cVar_wY2x51Xz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_SqyneN7x, 0, m, &cPack_SqyneN7x_sendMessage);
}

void Heavy_SoundScraper::cVar_wRCPAIcz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Xak1JQ3h, HV_BINOP_DIVIDE, 1, m, &cBinop_Xak1JQ3h_sendMessage);
}

void Heavy_SoundScraper::cCast_Lvfl5GiO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_wRCPAIcz, 0, m, &cVar_wRCPAIcz_sendMessage);
}

void Heavy_SoundScraper::cVar_PZMNAqEr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Xak1JQ3h, HV_BINOP_DIVIDE, 0, m, &cBinop_Xak1JQ3h_sendMessage);
}

void Heavy_SoundScraper::cCast_TSNdKbFA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_wRCPAIcz, 0, m, &cVar_wRCPAIcz_sendMessage);
}

void Heavy_SoundScraper::cCast_djBf59PH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_PZMNAqEr, 0, m, &cVar_PZMNAqEr_sendMessage);
}

void Heavy_SoundScraper::cCast_oVgw9WAp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_PZMNAqEr, 0, m, &cVar_PZMNAqEr_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_ujeYymWn_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0xFFFFFFFF: { // "bang"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Lvfl5GiO_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_oVgw9WAp_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_TSNdKbFA_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_djBf59PH_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_DxxEZwY6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_uaxbfDFT, 0, m, &cVar_uaxbfDFT_sendMessage);
}

void Heavy_SoundScraper::cCast_HHcoJe3O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cSend_HiKwxUu3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_8ia9UA0J_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_KiHdtdqp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 44100.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 100.0f, 0, m, &cBinop_mKIAIItc_sendMessage);
}

void Heavy_SoundScraper::cVar_enn6P9Y6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 100000.0f, 0, m, &cBinop_s2aQkuD9_sendMessage);
}

void Heavy_SoundScraper::cVar_uaxbfDFT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_ujeYymWn_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cPack_SlB36N6g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_to4NMEwm_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_SqyneN7x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_hLqjjijD_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_Xak1JQ3h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_enn6P9Y6, 0, m, &cVar_enn6P9Y6_sendMessage);
}

void Heavy_SoundScraper::cMsg_0GRO5kiV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_BoWYccU7, 0, m, &cDelay_BoWYccU7_sendMessage);
}

void Heavy_SoundScraper::cDelay_BoWYccU7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_BoWYccU7, m);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_DxxEZwY6_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_1gQyYqzw_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_POgWkKRP_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_0GRO5kiV_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_0GRO5kiV_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_BoWYccU7, 1, m, &cDelay_BoWYccU7_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_zQDJR3OR_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_zQDJR3OR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_BoWYccU7, 0, m, &cDelay_BoWYccU7_sendMessage);
}

void Heavy_SoundScraper::cSend_hLqjjijD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_RJ028IRF_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_hjwmKCDm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_xV2cKn6q_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_9m8oiw6a_sendMessage);
}

void Heavy_SoundScraper::cBinop_mKIAIItc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_0zjXZR82, 1, m, &cPack_0zjXZR82_sendMessage);
}

void Heavy_SoundScraper::cCast_qSs8Y3sG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_uaxbfDFT, 1, m, &cVar_uaxbfDFT_sendMessage);
}

void Heavy_SoundScraper::cMsg_qrMOoCPx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 0.0f);
  cSend_HiKwxUu3_sendMessage(_c, 0, m);
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 1);
  msg_setElementToFrom(m, 1, n, 0);
  cSend_HiKwxUu3_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_s2aQkuD9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_0zjXZR82, 0, m, &cPack_0zjXZR82_sendMessage);
}

void Heavy_SoundScraper::cSend_to4NMEwm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_RJ028IRF_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_PNeat1CU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cCast_xV2cKn6q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_SlB36N6g, 0, m, &cPack_SlB36N6g_sendMessage);
}

void Heavy_SoundScraper::cBinop_5a5WVVoY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_jIF40qTi, m);
}

void Heavy_SoundScraper::cSwitchcase_8zxSnp7m_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_iA7e4URh, 0, m, &cSlice_iA7e4URh_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cMsg_E9EESRdV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_RwMl1jN5_sendMessage);
}

void Heavy_SoundScraper::cSystem_RwMl1jN5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 2.0f, 0, m, &cBinop_5a5WVVoY_sendMessage);
}

void Heavy_SoundScraper::cVar_ZwMUgIzr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_E9EESRdV_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSlice_iA7e4URh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sTabread_onMessage(_c, &Context(_c)->sTabread_aqpc7o1W, 1, m, NULL);
      sTabread_onMessage(_c, &Context(_c)->sTabread_6uYUGrWc, 1, m, NULL);
      cVar_onMessage(_c, &Context(_c)->cVar_ZwMUgIzr, 0, m, &cVar_ZwMUgIzr_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cMsg_PqQTTnlG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSwitchcase_8zxSnp7m_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cSlice_BzwFzVkh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_PqQTTnlG_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_OgHEb7k7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_HHcoJe3O_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_qSs8Y3sG_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_hjwmKCDm_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_PNeat1CU, 0, m, &cVar_PNeat1CU_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cVar_mzdZbr49_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::hTable_bkykhA3v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cBinop_jXIZLaVa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_TnCsLt8s, 0, m, &cVar_TnCsLt8s_sendMessage);
}

void Heavy_SoundScraper::cVar_TnCsLt8s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cSlice_SOSLB9w9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 44100.0f, 0, m, &cBinop_vUt3abmG_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_uCFw3d3O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_jXIZLaVa_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_vUt3abmG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_mzdZbr49, 0, m, &cVar_mzdZbr49_sendMessage);
}

void Heavy_SoundScraper::cSend_BXXOqjmp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_Ju1xS2TW_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_4mlQGE2G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_QQtVEHLI_sendMessage);
}

void Heavy_SoundScraper::cRandom_ED7Gc7D6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_4mlQGE2G_sendMessage);
}

void Heavy_SoundScraper::cSlice_JBr92XSv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_ED7Gc7D6, 1, m, &cRandom_ED7Gc7D6_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSwitchcase_Lubx0cB7_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_JBr92XSv, 0, m, &cSlice_JBr92XSv_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_ED7Gc7D6, 0, m, &cRandom_ED7Gc7D6_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cUnop_QQtVEHLI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_7Z4Qgs9V_sendMessage);
}

void Heavy_SoundScraper::cCast_YgwQD2mt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cUnop_9tVFSV5F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_qqFT9wmO_sendMessage);
}

void Heavy_SoundScraper::cRandom_Tcwnk59D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 15.0f, 0, m, &cBinop_YttXSjgB_sendMessage);
}

void Heavy_SoundScraper::cBinop_YttXSjgB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_9tVFSV5F_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_ZHZrqayz_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_vPtQRRQh, 0, m, &cSlice_vPtQRRQh_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_Tcwnk59D, 0, m, &cRandom_Tcwnk59D_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cSlice_vPtQRRQh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_Tcwnk59D, 1, m, &cRandom_Tcwnk59D_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSend_9ZCPUS1n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cCast_9f4NnvVA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_URVh5iIh_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_D2mqMoBp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_RJx7ENeP, 0, m, &cVar_RJx7ENeP_sendMessage);
}

void Heavy_SoundScraper::cVar_DLKm9DGg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_iiSpjXuD_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_IYCAhXAn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_FGUdnHin_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_UASSaKr9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_xxTsk9LZ_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_HA1o2xNl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_eAs8Zxr3, 0, m, &cDelay_eAs8Zxr3_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_URVh5iIh_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_HA1o2xNl_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_HA1o2xNl_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_eAs8Zxr3, 1, m, &cDelay_eAs8Zxr3_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_mihMMqE2_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cDelay_eAs8Zxr3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_eAs8Zxr3, m);
  cVar_onMessage(_c, &Context(_c)->cVar_DLKm9DGg, 0, m, &cVar_DLKm9DGg_sendMessage);
}

void Heavy_SoundScraper::cCast_mihMMqE2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_eAs8Zxr3, 0, m, &cDelay_eAs8Zxr3_sendMessage);
}

void Heavy_SoundScraper::cVar_RJx7ENeP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_UASSaKr9_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_m7aLwn1C_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_9f4NnvVA_sendMessage);
}

void Heavy_SoundScraper::cSend_caXpuYsq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_r510TR8k_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_dsq8jUOc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 25.0f);
  cSend_9ZCPUS1n_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_iiSpjXuD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 0);
  sLine_onMessage(_c, &Context(_c)->sLine_0dA8JbKr, 0, m, NULL);
}

void Heavy_SoundScraper::cSend_lzgTWItE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_FGUdnHin_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_m7aLwn1C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_DLKm9DGg, 1, m, &cVar_DLKm9DGg_sendMessage);
}

void Heavy_SoundScraper::cMsg_sbOsQGX8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 4000.0f);
  cSend_caXpuYsq_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_xmtLeHkx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSend_IYCAhXAn_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_xxTsk9LZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 25.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_0dA8JbKr, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_MgYlK9We_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_SJpHuEE2_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_1zJ53JCY_sendMessage);
}

void Heavy_SoundScraper::cBinop_6Jo5QUR3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_miWQIbJZ, HV_BINOP_POW, 1, m, &cBinop_miWQIbJZ_sendMessage);
  cMsg_cv3n2bE1_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_D426Jifn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_6Jo5QUR3_sendMessage);
}

void Heavy_SoundScraper::cMsg_cv3n2bE1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_miWQIbJZ, HV_BINOP_POW, 0, m, &cBinop_miWQIbJZ_sendMessage);
}

void Heavy_SoundScraper::cBinop_i4DLWeZ5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_yDNqQqM2, HV_BINOP_DIVIDE, 0, m, &cBinop_yDNqQqM2_sendMessage);
}

void Heavy_SoundScraper::cBinop_miWQIbJZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_i4DLWeZ5_sendMessage);
}

void Heavy_SoundScraper::cCast_QfYRZAAt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_ZHZrqayz_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_SG2bcSnR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_BXXOqjmp_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_Y3fYBJlC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_Lubx0cB7_onMessage(_c, NULL, 0, m, NULL);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_YgwQD2mt_sendMessage);
}

void Heavy_SoundScraper::cSend_ZNxmoVhg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_WLjoD2qK_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_D1Ze6WXd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_jkvAnIqU_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_SIN, m, &cUnop_YeVgUD1O_sendMessage);
}

void Heavy_SoundScraper::cPack_GTWpKLKc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_wKjUfunQ, 0, m, NULL);
}

void Heavy_SoundScraper::cUnop_jkvAnIqU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_GTWpKLKc, 0, m, &cPack_GTWpKLKc_sendMessage);
}

void Heavy_SoundScraper::cMsg_me5ISvt5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.5f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_D1Ze6WXd_sendMessage);
}

void Heavy_SoundScraper::cPack_syicmNt1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_iJIcUm7s, 0, m, NULL);
}

void Heavy_SoundScraper::cUnop_YeVgUD1O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_syicmNt1, 0, m, &cPack_syicmNt1_sendMessage);
}

void Heavy_SoundScraper::cSend_iOKitXNS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_dA7RIHfw_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_nf29zP9d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_D2mqMoBp_sendMessage);
}

void Heavy_SoundScraper::cSlice_GXEJBEBJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_QfYRZAAt_sendMessage);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_D426Jifn_sendMessage);
      cPrint_onMessage(_c, m, "PERCSAMPLER_NOTE");
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_QfiTVqux_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 127.0f, 0, m, &cBinop_SG2bcSnR_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_qqFT9wmO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.99f, 0, m, &cBinop_siRS5Xy6_sendMessage);
}

void Heavy_SoundScraper::cBinop_siRS5Xy6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MgYlK9We, HV_BINOP_MULTIPLY, 1, m, &cBinop_MgYlK9We_sendMessage);
}

void Heavy_SoundScraper::cBinop_wtzCY1uX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_D1Ze6WXd_sendMessage);
}

void Heavy_SoundScraper::cBinop_yDNqQqM2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MgYlK9We, HV_BINOP_MULTIPLY, 0, m, &cBinop_MgYlK9We_sendMessage);
}

void Heavy_SoundScraper::cSend_0D2kpuST_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_41RaPf9H_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_Bu4DfUSD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.4f, 0, m, &cBinop_NqTOrbfD_sendMessage);
}

void Heavy_SoundScraper::cBinop_C44j8RJg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_VQPLPN2T_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ZCwEjOv8_sendMessage);
}

void Heavy_SoundScraper::cCast_DIJs7fzR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_SJPwmyYX_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_GwyReTK2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_HCWRmhFz_onMessage(_c, NULL, 0, m, NULL);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_AnEFSGuF_sendMessage);
}

void Heavy_SoundScraper::cUnop_c3iMbzeS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_tIvhH3p5, 0, m, &cPack_tIvhH3p5_sendMessage);
}

void Heavy_SoundScraper::cPack_MjBTWEfR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_nsa1SCND, 0, m, NULL);
}

void Heavy_SoundScraper::cMsg_XbU0e5cR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.5f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_ezK46nqC_sendMessage);
}

void Heavy_SoundScraper::cUnop_AaA9U5uC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_MjBTWEfR, 0, m, &cPack_MjBTWEfR_sendMessage);
}

void Heavy_SoundScraper::cBinop_ezK46nqC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_c3iMbzeS_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_SIN, m, &cUnop_AaA9U5uC_sendMessage);
}

void Heavy_SoundScraper::cPack_tIvhH3p5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_gVqws3WR, 0, m, NULL);
}

void Heavy_SoundScraper::cMsg_9CxTfRj8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSwitchcase_ikjnkobH_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::hTable_AKQw9gB5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cBinop_3XlUCyj6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_HgSXPSnM, m);
}

void Heavy_SoundScraper::cSystem_VAPRDG9Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 2.0f, 0, m, &cBinop_3XlUCyj6_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_ikjnkobH_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_rmw4EA0j, 0, m, &cSlice_rmw4EA0j_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cSlice_rmw4EA0j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sTabread_onMessage(_c, &Context(_c)->sTabread_bBKzDePT, 1, m, NULL);
      sTabread_onMessage(_c, &Context(_c)->sTabread_TReXBIUJ, 1, m, NULL);
      cVar_onMessage(_c, &Context(_c)->cVar_sTYvRhZ9, 0, m, &cVar_sTYvRhZ9_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cMsg_rp4aa40z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_VAPRDG9Z_sendMessage);
}

void Heavy_SoundScraper::cVar_sTYvRhZ9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_rp4aa40z_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_Hd8hM02e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_roaFw89G, 0, m, &cVar_roaFw89G_sendMessage);
}

void Heavy_SoundScraper::cCast_1115YzV3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_XqVNmeJ7, 0, m, &cVar_XqVNmeJ7_sendMessage);
}

void Heavy_SoundScraper::cBinop_1UxLhA9z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_jKcCiv7a, 0, m, &cPack_jKcCiv7a_sendMessage);
}

void Heavy_SoundScraper::cBinop_2h47LjGu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_GiN3QG1U, 0, m, &cVar_GiN3QG1U_sendMessage);
}

void Heavy_SoundScraper::cVar_XqVNmeJ7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_FYzMBkaY, 0, m, &cPack_FYzMBkaY_sendMessage);
}

void Heavy_SoundScraper::cCast_9zhNSftQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_AQ3aaPPE_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_FnRHGmvv_sendMessage);
}

void Heavy_SoundScraper::cCast_AQ3aaPPE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_j8wxsOsu, 0, m, &cPack_j8wxsOsu_sendMessage);
}

void Heavy_SoundScraper::cVar_TjNMcqvZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_ZL0ffJl0_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_DuquqJOg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_TjNMcqvZ, 0, m, &cVar_TjNMcqvZ_sendMessage);
}

void Heavy_SoundScraper::cPack_FYzMBkaY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_HVo32Nnw_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_FnRHGmvv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_qRRLSX7s_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cSend_HVo32Nnw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_bcGB1aGC_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_GiN3QG1U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 100000.0f, 0, m, &cBinop_1UxLhA9z_sendMessage);
}

void Heavy_SoundScraper::cCast_3cUzpd2y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_RyS40cLD, 0, m, &cVar_RyS40cLD_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_ZL0ffJl0_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0xFFFFFFFF: { // "bang"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_3cUzpd2y_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_z1SsqQq5_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_nb6VTrFm_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_lT3yyo1g_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cVar_jz3tGdki_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_2h47LjGu, HV_BINOP_DIVIDE, 0, m, &cBinop_2h47LjGu_sendMessage);
}

void Heavy_SoundScraper::cCast_lT3yyo1g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_jz3tGdki, 0, m, &cVar_jz3tGdki_sendMessage);
}

void Heavy_SoundScraper::cVar_RyS40cLD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_2h47LjGu, HV_BINOP_DIVIDE, 1, m, &cBinop_2h47LjGu_sendMessage);
}

void Heavy_SoundScraper::cCast_nb6VTrFm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_RyS40cLD, 0, m, &cVar_RyS40cLD_sendMessage);
}

void Heavy_SoundScraper::cCast_z1SsqQq5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_jz3tGdki, 0, m, &cVar_jz3tGdki_sendMessage);
}

void Heavy_SoundScraper::cMsg_Kgr6aHNB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 0.0f);
  cSend_SZlyNABT_sendMessage(_c, 0, m);
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 1);
  msg_setElementToFrom(m, 1, n, 0);
  cSend_SZlyNABT_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_MIpmAbms_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_bcGB1aGC_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_SZlyNABT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_PC7vIRkt_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_Yk3n9uoQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 44100.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 100.0f, 0, m, &cBinop_d7xusZhg_sendMessage);
}

void Heavy_SoundScraper::cDelay_1qnhKvZ9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_1qnhKvZ9, m);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_DuquqJOg_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_1115YzV3_sendMessage);
}

void Heavy_SoundScraper::cCast_l0iyJSRM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_1qnhKvZ9, 0, m, &cDelay_1qnhKvZ9_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_qRRLSX7s_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_v5MSEa5l_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_v5MSEa5l_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_1qnhKvZ9, 1, m, &cDelay_1qnhKvZ9_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_l0iyJSRM_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cMsg_v5MSEa5l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_1qnhKvZ9, 0, m, &cDelay_1qnhKvZ9_sendMessage);
}

void Heavy_SoundScraper::cBinop_d7xusZhg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_jKcCiv7a, 1, m, &cPack_jKcCiv7a_sendMessage);
}

void Heavy_SoundScraper::cPack_j8wxsOsu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_MIpmAbms_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_jKcCiv7a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Kgr6aHNB_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_NZZWo5bx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cCast_xZ3h0xCV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_TjNMcqvZ, 1, m, &cVar_TjNMcqvZ_sendMessage);
}

void Heavy_SoundScraper::cCast_znGAkzjR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cBinop_dJXlauGI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_EqloIxkt, 0, m, &cVar_EqloIxkt_sendMessage);
}

void Heavy_SoundScraper::cVar_EqloIxkt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cVar_roaFw89G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cSlice_VHV4oP1k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_dJXlauGI_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_mwUeFqx8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 44100.0f, 0, m, &cBinop_Hd8hM02e_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_9GeG4B5s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_znGAkzjR_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_xZ3h0xCV_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_9zhNSftQ_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_NZZWo5bx, 0, m, &cVar_NZZWo5bx_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_qcBgEtaq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_9CxTfRj8_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_NqTOrbfD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_ezK46nqC_sendMessage);
}

void Heavy_SoundScraper::cBinop_NtklF6lA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_C44j8RJg, HV_BINOP_MULTIPLY, 0, m, &cBinop_C44j8RJg_sendMessage);
}

void Heavy_SoundScraper::cVar_KXcAfqmU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_2AeIl7oo, 1, m, &cPack_2AeIl7oo_sendMessage);
}

void Heavy_SoundScraper::cPack_2AeIl7oo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_GwyReTK2_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_iWvALRp0_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_qcBgEtaq, 0, m, &cSlice_qcBgEtaq_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_9GeG4B5s, 0, m, &cSlice_9GeG4B5s_sendMessage);
  cPrint_onMessage(_c, m, "TABLEPLAYER_COMMAND");
}

void Heavy_SoundScraper::cCast_VQPLPN2T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_KXcAfqmU, 0, m, &cVar_KXcAfqmU_sendMessage);
}

void Heavy_SoundScraper::cCast_ZCwEjOv8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_2AeIl7oo, 0, m, &cPack_2AeIl7oo_sendMessage);
}

void Heavy_SoundScraper::cSend_Sui3wf8E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_me6GXtaS_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_1ufanUhg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_NtklF6lA, HV_BINOP_DIVIDE, 0, m, &cBinop_NtklF6lA_sendMessage);
}

void Heavy_SoundScraper::cBinop_BHxpRmB8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_f253eZ1l, HV_BINOP_POW, 1, m, &cBinop_f253eZ1l_sendMessage);
  cMsg_MUthzqlo_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_Bs7MqkEk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_BHxpRmB8_sendMessage);
}

void Heavy_SoundScraper::cMsg_MUthzqlo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_f253eZ1l, HV_BINOP_POW, 0, m, &cBinop_f253eZ1l_sendMessage);
}

void Heavy_SoundScraper::cBinop_f253eZ1l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_1ufanUhg_sendMessage);
}

void Heavy_SoundScraper::cSend_XqozhxqE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_z6iEtg1P_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSlice_Y32RxzaP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_DIJs7fzR_sendMessage);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_Bs7MqkEk_sendMessage);
      cPrint_onMessage(_c, m, "PERCSAMPLER_NOTE");
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_ubdBPvp7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 127.0f, 0, m, &cBinop_hfbH4B17_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cRandom_82fhNWaF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_b2BDuKG9_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_HCWRmhFz_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_u5imjPEP, 0, m, &cSlice_u5imjPEP_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_82fhNWaF, 0, m, &cRandom_82fhNWaF_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cUnop_Y94JPdTL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_Bu4DfUSD_sendMessage);
}

void Heavy_SoundScraper::cBinop_b2BDuKG9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_Y94JPdTL_sendMessage);
}

void Heavy_SoundScraper::cSlice_u5imjPEP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_82fhNWaF, 1, m, &cRandom_82fhNWaF_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_aAcUWa8w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.99f, 0, m, &cBinop_dfqwTHm9_sendMessage);
}

void Heavy_SoundScraper::cMsg_5rrwxNbA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 4000.0f);
  cSend_gNspD6OU_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_67wbfJ2g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_XSnpUi0o, 1, m, &cVar_XSnpUi0o_sendMessage);
}

void Heavy_SoundScraper::cVar_lCwYyBZF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_bjFuMym0_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_67wbfJ2g_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_K1iTqUaI_sendMessage);
}

void Heavy_SoundScraper::cMsg_CJNK44x7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 25.0f);
  cSend_cjLnMgKR_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_5peHtRuo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_5peHtRuo, m);
  cVar_onMessage(_c, &Context(_c)->cVar_XSnpUi0o, 0, m, &cVar_XSnpUi0o_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_PrhVKwoR_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_qyTvtMHX_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_qyTvtMHX_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_5peHtRuo, 1, m, &cDelay_5peHtRuo_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_nwVQZ7Iz_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_nwVQZ7Iz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_5peHtRuo, 0, m, &cDelay_5peHtRuo_sendMessage);
}

void Heavy_SoundScraper::cMsg_qyTvtMHX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_5peHtRuo, 0, m, &cDelay_5peHtRuo_sendMessage);
}

void Heavy_SoundScraper::cCast_K1iTqUaI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_PrhVKwoR_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cSend_QV33UwVu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_5HY5fLM2_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_WXnUNTtm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_5HY5fLM2_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_aJbMkgtr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSend_QV33UwVu_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_bjFuMym0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_poDeI2Li_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_cjLnMgKR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cMsg_eKFpH9a2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 0);
  sLine_onMessage(_c, &Context(_c)->sLine_7wuBgJ5s, 0, m, NULL);
}

void Heavy_SoundScraper::cSend_gNspD6OU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_j108jHSS_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_XSnpUi0o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_eKFpH9a2_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_poDeI2Li_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 25.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_7wuBgJ5s, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_wuaCmp1g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_lCwYyBZF, 0, m, &cVar_lCwYyBZF_sendMessage);
}

void Heavy_SoundScraper::cBinop_dfqwTHm9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_C44j8RJg, HV_BINOP_MULTIPLY, 1, m, &cBinop_C44j8RJg_sendMessage);
}

void Heavy_SoundScraper::cSlice_8a9gRL90_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSend_Sui3wf8E_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_BT0HiEqz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSend_0D2kpuST_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_hfbH4B17_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_XqozhxqE_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_iWvALRp0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_wuaCmp1g_sendMessage);
}

void Heavy_SoundScraper::cCast_AnEFSGuF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cRandom_3qs68nzi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 15.0f, 0, m, &cBinop_OZKxp9pw_sendMessage);
}

void Heavy_SoundScraper::cUnop_E5MjjYrs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_aAcUWa8w_sendMessage);
}

void Heavy_SoundScraper::cBinop_OZKxp9pw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_E5MjjYrs_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_SJPwmyYX_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_kZN1w8N7, 0, m, &cSlice_kZN1w8N7_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_3qs68nzi, 0, m, &cRandom_3qs68nzi_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cSlice_kZN1w8N7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_3qs68nzi, 1, m, &cRandom_3qs68nzi_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cReceive_fKOUPBDH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_IVZ00RuP, 0, m, &cPack_IVZ00RuP_sendMessage);
}

void Heavy_SoundScraper::cReceive_gi3bKbGJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_XHpwjSSN, 0, m, &cVar_XHpwjSSN_sendMessage);
}

void Heavy_SoundScraper::cBinop_0N43JE7z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_SJXx81kb_sendMessage);
}

void Heavy_SoundScraper::cCast_1G8QLz2k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_fQgV9Mao_sendMessage);
}

void Heavy_SoundScraper::cBinop_4rBvr7Uc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_7RNeH53b, HV_BINOP_MULTIPLY, 1, m, &cBinop_7RNeH53b_sendMessage);
}

void Heavy_SoundScraper::cSlice_Nk0dsf1u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_BIXZnmg1_sendMessage);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_iNvifLt4_sendMessage);
      cPrint_onMessage(_c, m, "PERCSAMPLER_NOTE");
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_hAc6aAxe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 127.0f, 0, m, &cBinop_7mt73e01_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_7RNeH53b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_X0noFfe2_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_rLXr4Edz_sendMessage);
}

void Heavy_SoundScraper::cBinop_7mt73e01_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_gjO95SUi_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_BIXZnmg1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_o0Lq7fcj_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cSwitchcase_1HRfmt7H_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_8EDJoabJ, 0, m, &cSlice_8EDJoabJ_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_kwUSvw2u, 0, m, &cRandom_kwUSvw2u_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cSlice_8EDJoabJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_kwUSvw2u, 1, m, &cRandom_kwUSvw2u_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cUnop_FS4owC4a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_SDREH4oa_sendMessage);
}

void Heavy_SoundScraper::cBinop_d7B4bXi2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_FS4owC4a_sendMessage);
}

void Heavy_SoundScraper::cRandom_kwUSvw2u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_d7B4bXi2_sendMessage);
}

void Heavy_SoundScraper::cSlice_QsoULHxF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_ZcejJIy1, 1, m, &cRandom_ZcejJIy1_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cRandom_ZcejJIy1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 15.0f, 0, m, &cBinop_yXJmAi9R_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_o0Lq7fcj_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_QsoULHxF, 0, m, &cSlice_QsoULHxF_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_ZcejJIy1, 0, m, &cRandom_ZcejJIy1_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_yXJmAi9R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_znEJCKP6_sendMessage);
}

void Heavy_SoundScraper::cUnop_znEJCKP6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_WWTSImWG_sendMessage);
}

void Heavy_SoundScraper::cBinop_LLQSv5U0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_7RNeH53b, HV_BINOP_MULTIPLY, 0, m, &cBinop_7RNeH53b_sendMessage);
}

void Heavy_SoundScraper::cMsg_1Q0fc1xd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 0);
  sLine_onMessage(_c, &Context(_c)->sLine_O0ifSzPL, 0, m, NULL);
}

void Heavy_SoundScraper::cMsg_2r46FSc4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 4000.0f);
  cSend_zbJngBFJ_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_3XAlCAba_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_pJyJ8beI_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_8W3wifGY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_fuCyXzIE, 1, m, &cVar_fuCyXzIE_sendMessage);
}

void Heavy_SoundScraper::cCast_90btGSnx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_WBu661zv_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_fuCyXzIE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_1Q0fc1xd_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_JRc8LTmf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSend_3XAlCAba_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_3n85lNl6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_90btGSnx_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_8W3wifGY_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_qimXY1rv_sendMessage);
}

void Heavy_SoundScraper::cMsg_WBu661zv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 25.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_O0ifSzPL, 0, m, NULL);
}

void Heavy_SoundScraper::cSwitchcase_1fKEsrqn_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_E2D4TpTa_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_E2D4TpTa_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_XXe4aOsj, 1, m, &cDelay_XXe4aOsj_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_SMf3xEQ5_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cMsg_E2D4TpTa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_XXe4aOsj, 0, m, &cDelay_XXe4aOsj_sendMessage);
}

void Heavy_SoundScraper::cCast_SMf3xEQ5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_XXe4aOsj, 0, m, &cDelay_XXe4aOsj_sendMessage);
}

void Heavy_SoundScraper::cDelay_XXe4aOsj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_XXe4aOsj, m);
  cVar_onMessage(_c, &Context(_c)->cVar_fuCyXzIE, 0, m, &cVar_fuCyXzIE_sendMessage);
}

void Heavy_SoundScraper::cCast_fQgV9Mao_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_3n85lNl6, 0, m, &cVar_3n85lNl6_sendMessage);
}

void Heavy_SoundScraper::cSend_n1drs6ME_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cMsg_omqBk88d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 25.0f);
  cSend_n1drs6ME_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_qimXY1rv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_1fKEsrqn_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cSend_vXq9ty0r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_pJyJ8beI_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_zbJngBFJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_KAf1xh4c_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_Ek55gQhE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cMsg_84t5uMf7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSwitchcase_1KbJyb9h_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cVar_L8oii4oq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_f0L3zTiX, 0, m, &cPack_f0L3zTiX_sendMessage);
}

void Heavy_SoundScraper::cPack_5K877NH9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_bDdiAUpi_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_ATyiAS9b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_6qRZEOOM, 0, m, &cVar_6qRZEOOM_sendMessage);
}

void Heavy_SoundScraper::cVar_6qRZEOOM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_PJW0hS1Y, HV_BINOP_DIVIDE, 0, m, &cBinop_PJW0hS1Y_sendMessage);
}

void Heavy_SoundScraper::cCast_P20QSp83_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_6qRZEOOM, 0, m, &cVar_6qRZEOOM_sendMessage);
}

void Heavy_SoundScraper::cVar_CHWKAnDn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_PJW0hS1Y, HV_BINOP_DIVIDE, 1, m, &cBinop_PJW0hS1Y_sendMessage);
}

void Heavy_SoundScraper::cCast_iiTUjhp9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_CHWKAnDn, 0, m, &cVar_CHWKAnDn_sendMessage);
}

void Heavy_SoundScraper::cCast_mVivvAP5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_CHWKAnDn, 0, m, &cVar_CHWKAnDn_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_r1PszvVU_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0xFFFFFFFF: { // "bang"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_mVivvAP5_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_P20QSp83_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_iiTUjhp9_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ATyiAS9b_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_8YVWemzl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cMsg_8cj8AfBJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 44100.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 100.0f, 0, m, &cBinop_bcA4id0C_sendMessage);
}

void Heavy_SoundScraper::cCast_8lrd54HH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_2WqJlITT, 1, m, &cVar_2WqJlITT_sendMessage);
}

void Heavy_SoundScraper::cCast_E4u2AgAz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_Syd36h5d_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_HWyBuD8F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_RWK9duXY_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_E4u2AgAz_sendMessage);
}

void Heavy_SoundScraper::cCast_KV1fbE36_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_2WqJlITT, 0, m, &cVar_2WqJlITT_sendMessage);
}

void Heavy_SoundScraper::cVar_2WqJlITT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_r1PszvVU_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_PJW0hS1Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_CuLuBKX3, 0, m, &cVar_CuLuBKX3_sendMessage);
}

void Heavy_SoundScraper::cCast_RWK9duXY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_bcYg07Ut, 0, m, &cPack_bcYg07Ut_sendMessage);
}

void Heavy_SoundScraper::cVar_CuLuBKX3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 100000.0f, 0, m, &cBinop_uuI8AlL4_sendMessage);
}

void Heavy_SoundScraper::cVar_DuQ4Co8P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cMsg_bDdiAUpi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 0.0f);
  cSend_qQh6LlcC_sendMessage(_c, 0, m);
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 1);
  msg_setElementToFrom(m, 1, n, 0);
  cSend_qQh6LlcC_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_bcA4id0C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_5K877NH9, 1, m, &cPack_5K877NH9_sendMessage);
}

void Heavy_SoundScraper::cPack_bcYg07Ut_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_ln4JGEOJ_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_f0L3zTiX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_xdeW7YyO_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_ln4JGEOJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_RT1zMGKA_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_Syd36h5d_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_stZaYNFS_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_stZaYNFS_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_tJ5A26Ex, 1, m, &cDelay_tJ5A26Ex_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_tukvbl1d_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cMsg_stZaYNFS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_tJ5A26Ex, 0, m, &cDelay_tJ5A26Ex_sendMessage);
}

void Heavy_SoundScraper::cDelay_tJ5A26Ex_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_tJ5A26Ex, m);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_KV1fbE36_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_pihpntGc_sendMessage);
}

void Heavy_SoundScraper::cCast_tukvbl1d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_tJ5A26Ex, 0, m, &cDelay_tJ5A26Ex_sendMessage);
}

void Heavy_SoundScraper::cCast_pihpntGc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_L8oii4oq, 0, m, &cVar_L8oii4oq_sendMessage);
}

void Heavy_SoundScraper::cSend_qQh6LlcC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_VzckN8pw_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_uuI8AlL4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_5K877NH9, 0, m, &cPack_5K877NH9_sendMessage);
}

void Heavy_SoundScraper::cSend_xdeW7YyO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_RT1zMGKA_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_1KbJyb9h_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_d3mfOe8P, 0, m, &cSlice_d3mfOe8P_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cMsg_SYuu5iYJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_bgOC2cQW_sendMessage);
}

void Heavy_SoundScraper::cVar_UyoDPMGJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_SYuu5iYJ_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSystem_bgOC2cQW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 2.0f, 0, m, &cBinop_wKa03XuD_sendMessage);
}

void Heavy_SoundScraper::cSlice_d3mfOe8P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sTabread_onMessage(_c, &Context(_c)->sTabread_61hRkCkk, 1, m, NULL);
      sTabread_onMessage(_c, &Context(_c)->sTabread_Dq51SkCT, 1, m, NULL);
      cVar_onMessage(_c, &Context(_c)->cVar_UyoDPMGJ, 0, m, &cVar_UyoDPMGJ_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_wKa03XuD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_bgDUH05l, m);
}

void Heavy_SoundScraper::cBinop_C95KwuAg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_9zT65X1L, 0, m, &cVar_9zT65X1L_sendMessage);
}

void Heavy_SoundScraper::cBinop_IQg9xqrX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Ek55gQhE, 0, m, &cVar_Ek55gQhE_sendMessage);
}

void Heavy_SoundScraper::cVar_9zT65X1L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cSlice_L70vIPrx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 44100.0f, 0, m, &cBinop_IQg9xqrX_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_SeWjqHEN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_C95KwuAg_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_5G7uBBwC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_8YVWemzl_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_8lrd54HH_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_HWyBuD8F_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_DuQ4Co8P, 0, m, &cVar_DuQ4Co8P_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_GkIAmfP8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_84t5uMf7_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::hTable_qTT30gQb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cBinop_SDREH4oa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.4f, 0, m, &cBinop_0N43JE7z_sendMessage);
}

void Heavy_SoundScraper::cPack_32YTVbUD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_kpWJi41L, 0, m, NULL);
}

void Heavy_SoundScraper::cUnop_a5WxHAhH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_32YTVbUD, 0, m, &cPack_32YTVbUD_sendMessage);
}

void Heavy_SoundScraper::cMsg_Ppkwuftz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.5f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_SJXx81kb_sendMessage);
}

void Heavy_SoundScraper::cUnop_q8u6ZIF4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_e5WkLpVn, 0, m, &cPack_e5WkLpVn_sendMessage);
}

void Heavy_SoundScraper::cBinop_SJXx81kb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_q8u6ZIF4_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_SIN, m, &cUnop_a5WxHAhH_sendMessage);
}

void Heavy_SoundScraper::cPack_e5WkLpVn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_fa9VpVzC, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_WWTSImWG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.99f, 0, m, &cBinop_4rBvr7Uc_sendMessage);
}

void Heavy_SoundScraper::cSend_ckz66LTI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_5hQZcw1R_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_gjO95SUi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_TIg47hmJ_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_X0noFfe2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_U4JpgUYy, 0, m, &cVar_U4JpgUYy_sendMessage);
}

void Heavy_SoundScraper::cVar_U4JpgUYy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_jqVRSnP5, 1, m, &cPack_jqVRSnP5_sendMessage);
}

void Heavy_SoundScraper::cPack_jqVRSnP5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_iVcBj2d4_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_1G8QLz2k_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_GkIAmfP8, 0, m, &cSlice_GkIAmfP8_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_5G7uBBwC, 0, m, &cSlice_5G7uBBwC_sendMessage);
  cPrint_onMessage(_c, m, "TABLEPLAYER_COMMAND");
}

void Heavy_SoundScraper::cCast_rLXr4Edz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_jqVRSnP5, 0, m, &cPack_jqVRSnP5_sendMessage);
}

void Heavy_SoundScraper::cCast_iVcBj2d4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_1HRfmt7H_onMessage(_c, NULL, 0, m, NULL);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_vEtCiE0s_sendMessage);
}

void Heavy_SoundScraper::cBinop_64xRwxyY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_LLQSv5U0, HV_BINOP_DIVIDE, 0, m, &cBinop_LLQSv5U0_sendMessage);
}

void Heavy_SoundScraper::cBinop_Ppd5goO8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_64xRwxyY_sendMessage);
}

void Heavy_SoundScraper::cBinop_iNvifLt4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_mq5joYsZ_sendMessage);
}

void Heavy_SoundScraper::cBinop_mq5joYsZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Ppd5goO8, HV_BINOP_POW, 1, m, &cBinop_Ppd5goO8_sendMessage);
  cMsg_zaKDLKho_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_zaKDLKho_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_Ppd5goO8, HV_BINOP_POW, 0, m, &cBinop_Ppd5goO8_sendMessage);
}

void Heavy_SoundScraper::cSlice_5qKhvvY8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSend_ckz66LTI_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_pfaPnV1i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSend_uXD6tslV_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cCast_vEtCiE0s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cSend_uXD6tslV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_2Rgd81on_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cReceive_hhNFlC8R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_3Yz9bYNA, HV_BINOP_SUBTRACT, 0, m, &cBinop_3Yz9bYNA_sendMessage);
}

void Heavy_SoundScraper::cReceive_i89foIcW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_N9GYmeX7_sendMessage(_c, 0, m);
  cSwitchcase_vzL8Ewdk_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cReceive_iBd6GA39_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_zIqdTANI, 0, m, &cVar_zIqdTANI_sendMessage);
}

void Heavy_SoundScraper::cSend_JpkyQM6K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_mpWxdZ0C_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_bfS7EC1Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_H9uGa2DN_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_by5Gs2rE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSend_JpkyQM6K_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_3HiO7cSt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_vRGo39Wp, 0, m, &cPack_vRGo39Wp_sendMessage);
}

void Heavy_SoundScraper::cBinop_6dHVvDyN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_RA7KvXe4, 1, m, &cIf_RA7KvXe4_sendMessage);
}

void Heavy_SoundScraper::cCast_IU0YaDfn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_RA7KvXe4, 0, m, &cIf_RA7KvXe4_sendMessage);
}

void Heavy_SoundScraper::cBinop_IgfylhRP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_3HiO7cSt, HV_BINOP_POW, 1, m, &cBinop_3HiO7cSt_sendMessage);
  cMsg_PCkC4yJ9_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_KkRg0DLp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_ZloLYCGC_sendMessage);
}

void Heavy_SoundScraper::cMsg_PCkC4yJ9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_3HiO7cSt, HV_BINOP_POW, 0, m, &cBinop_3HiO7cSt_sendMessage);
}

void Heavy_SoundScraper::cIf_RA7KvXe4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_gkYZLs8V_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_KkRg0DLp_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cCast_RH0tEmei_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_6dHVvDyN_sendMessage);
}

void Heavy_SoundScraper::cBinop_ZloLYCGC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_IgfylhRP_sendMessage);
}

void Heavy_SoundScraper::cMsg_gkYZLs8V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_vRGo39Wp, 0, m, &cPack_vRGo39Wp_sendMessage);
}

void Heavy_SoundScraper::cVar_vKvuftOz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_bfS7EC1Q_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_Zn1ojjrH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_by5Gs2rE_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_RH0tEmei_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_IU0YaDfn_sendMessage);
}

void Heavy_SoundScraper::cPack_vRGo39Wp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_HUDYAN2U, 0, m, NULL);
}

void Heavy_SoundScraper::cReceive_j108jHSS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_lCwYyBZF, 1, m, &cVar_lCwYyBZF_sendMessage);
}

void Heavy_SoundScraper::cReceive_j8Mz1NLg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSlice_onMessage(_c, &Context(_c)->cSlice_UZOVBp1z, 0, m, &cSlice_UZOVBp1z_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_rutu4pRj, 0, m, &cSlice_rutu4pRj_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_zCLfxfps, 0, m, &cSlice_zCLfxfps_sendMessage);
}

void Heavy_SoundScraper::cReceive_jC4Mczgd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_IVZ00RuP, 1, m, &cPack_IVZ00RuP_sendMessage);
}

void Heavy_SoundScraper::cReceive_jMhwovL4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_sj8eJAp4, 0, m, &cVar_sj8eJAp4_sendMessage);
}

void Heavy_SoundScraper::cMsg_gRVzueCM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cSend_s7XorbYO_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_s7XorbYO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_JfpuuerB_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_2GtQHjks_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_6lhEfuBZ, 1, m, &cIf_6lhEfuBZ_sendMessage);
}

void Heavy_SoundScraper::cIf_fsBm2IPb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSend_7uiDpFd4_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cCast_5Pwk6Bki_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_8IgWrNwI, 1, m, &cIf_8IgWrNwI_sendMessage);
}

void Heavy_SoundScraper::cBinop_AszExoYR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ghFQYlsD, HV_BINOP_EQ, 0, m, &cBinop_ghFQYlsD_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_Puh9jqA5_sendMessage);
}

void Heavy_SoundScraper::cIf_8IgWrNwI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSend_paZvFr1u_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cUnop_8pKouf3R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_wo4DGSH0_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_ghFQYlsD, HV_BINOP_EQ, 1, m, &cBinop_ghFQYlsD_sendMessage);
}

void Heavy_SoundScraper::cVar_Majfm0GP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_Dtw77kAZ_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_DWT53kAW, 0, m, &cIf_DWT53kAW_sendMessage);
}

void Heavy_SoundScraper::cIf_DWT53kAW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_8pKouf3R_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_wH18cWvJ_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_Dtw77kAZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_DWT53kAW, 1, m, &cIf_DWT53kAW_sendMessage);
}

void Heavy_SoundScraper::cUnop_wH18cWvJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_wo4DGSH0_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_ghFQYlsD, HV_BINOP_EQ, 1, m, &cBinop_ghFQYlsD_sendMessage);
}

void Heavy_SoundScraper::cBinop_Puh9jqA5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_ghvXpne5_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cIf_6lhEfuBZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSend_7uiDpFd4_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cIf_n8BJSAmA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSend_paZvFr1u_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cCast_fjKmw1qu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_fsBm2IPb, 1, m, &cIf_fsBm2IPb_sendMessage);
}

void Heavy_SoundScraper::cBinop_ghFQYlsD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_5Pwk6Bki_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_fjKmw1qu_sendMessage);
}

void Heavy_SoundScraper::cCast_k6tYWv31_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_n8BJSAmA, 1, m, &cIf_n8BJSAmA_sendMessage);
}

void Heavy_SoundScraper::cSlice_UZOVBp1z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_AszExoYR_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_rutu4pRj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cIf_onMessage(_c, &Context(_c)->cIf_n8BJSAmA, 0, m, &cIf_n8BJSAmA_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_8IgWrNwI, 0, m, &cIf_8IgWrNwI_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_zCLfxfps_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cIf_onMessage(_c, &Context(_c)->cIf_fsBm2IPb, 0, m, &cIf_fsBm2IPb_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_6lhEfuBZ, 0, m, &cIf_6lhEfuBZ_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_wo4DGSH0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_k6tYWv31_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_2GtQHjks_sendMessage);
}

void Heavy_SoundScraper::cSend_7uiDpFd4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_fKOUPBDH_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_ghvXpne5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cSend_paZvFr1u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_jC4Mczgd_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cReceive_jlnIpbMW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_hVcQMAdy_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_1eZbcsbi_sendMessage);
}

void Heavy_SoundScraper::cReceive_kF0RAx1I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_gmMUMGJa, 0, m, &cVar_gmMUMGJa_sendMessage);
}

void Heavy_SoundScraper::cMsg_6pUjozXE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_l8cNHrsG_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cSlice_1gy5ErY8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_YFizWWF7, 0, m, &cSlice_YFizWWF7_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_QPio2HST, 0, m, &cSlice_QPio2HST_sendMessage);
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_YFizWWF7, 0, m, &cSlice_YFizWWF7_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_QPio2HST, 0, m, &cSlice_QPio2HST_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_HqkuD6Lx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_QfiTVqux, 0, m, &cSlice_QfiTVqux_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_GXEJBEBJ, 0, m, &cSlice_GXEJBEBJ_sendMessage);
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_QfiTVqux, 0, m, &cSlice_QfiTVqux_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_GXEJBEBJ, 0, m, &cSlice_GXEJBEBJ_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSwitchcase_JDlFSiEE_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_xuydrICF, 0, m, &cSlice_xuydrICF_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_onIDdbjZ, 0, m, &cSlice_onIDdbjZ_sendMessage);
      break;
    }
    case 0x40000000: { // "2.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_1gy5ErY8, 0, m, &cSlice_1gy5ErY8_sendMessage);
      break;
    }
    case 0x40400000: { // "3.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_HqkuD6Lx, 0, m, &cSlice_HqkuD6Lx_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cSlice_onIDdbjZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_hAc6aAxe, 0, m, &cSlice_hAc6aAxe_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_Nk0dsf1u, 0, m, &cSlice_Nk0dsf1u_sendMessage);
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_hAc6aAxe, 0, m, &cSlice_hAc6aAxe_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_Nk0dsf1u, 0, m, &cSlice_Nk0dsf1u_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_xuydrICF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_ubdBPvp7, 0, m, &cSlice_ubdBPvp7_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_Y32RxzaP, 0, m, &cSlice_Y32RxzaP_sendMessage);
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_ubdBPvp7, 0, m, &cSlice_ubdBPvp7_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_Y32RxzaP, 0, m, &cSlice_Y32RxzaP_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cPack_IVZ00RuP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_JocSBMRA, 0, m, &cIf_JocSBMRA_sendMessage);
}

void Heavy_SoundScraper::cCast_Kd8cOL0a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_TuXtPgx8, 0, m, &cVar_TuXtPgx8_sendMessage);
}

void Heavy_SoundScraper::cIf_JocSBMRA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_JsNDXk3i, 0, m, &cSlice_JsNDXk3i_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_j8g9TS4z, 0, m, &cSlice_j8g9TS4z_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_lSQrAVlP, 0, m, &cIf_lSQrAVlP_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cCast_TqEc0I18_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_gU56DZxO_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSwitchcase_l8cNHrsG_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_TqEc0I18_sendMessage);
      break;
    }
    default: {
      cMsg_kGiuDpyt_sendMessage(_c, 0, m);
      break;
    }
  }
}

void Heavy_SoundScraper::cMsg_gU56DZxO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_Gvx3wYfG, 0, m, &cVar_Gvx3wYfG_sendMessage);
}

void Heavy_SoundScraper::cMsg_kGiuDpyt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_Gvx3wYfG, 0, m, &cVar_Gvx3wYfG_sendMessage);
}

void Heavy_SoundScraper::cBinop_FPB4l5cu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Gvx3wYfG, 1, m, &cVar_Gvx3wYfG_sendMessage);
}

void Heavy_SoundScraper::cVar_Gvx3wYfG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_FPB4l5cu_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_JocSBMRA, 1, m, &cIf_JocSBMRA_sendMessage);
}

void Heavy_SoundScraper::cVar_TuXtPgx8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_lA7P06zw, 0, m, &cPack_lA7P06zw_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_YdePOomD_sendMessage);
}

void Heavy_SoundScraper::cBinop_YdePOomD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MOD_BIPOLAR, 4.0f, 0, m, &cBinop_l2aq8nF3_sendMessage);
}

void Heavy_SoundScraper::cBinop_4Sx7CBu4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_6rOONnze, 1, m, &cIf_6rOONnze_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_gBDy3SwE, 1, m, &cIf_gBDy3SwE_sendMessage);
}

void Heavy_SoundScraper::cPack_9a733PFq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_te413RcP, 0, m, &cIf_te413RcP_sendMessage);
}

void Heavy_SoundScraper::cCast_DTT88hSh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_9a733PFq, 0, m, &cPack_9a733PFq_sendMessage);
}

void Heavy_SoundScraper::cIf_te413RcP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_tp36l5d9, 0, m, &cSlice_tp36l5d9_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_3iNR7v2q, 0, m, &cSlice_3iNR7v2q_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cCast_NhP4EV7m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_m8Ix3fHp, 0, m, &cVar_m8Ix3fHp_sendMessage);
}

void Heavy_SoundScraper::cCast_NyfBHUVc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_WhViqqNR_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_OBJl1JQ9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_m8Ix3fHp, 1, m, &cVar_m8Ix3fHp_sendMessage);
}

void Heavy_SoundScraper::cMsg_WhViqqNR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_m8Ix3fHp, 1, m, &cVar_m8Ix3fHp_sendMessage);
}

void Heavy_SoundScraper::cIf_lSQrAVlP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_tp36l5d9, 0, m, &cSlice_tp36l5d9_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_3iNR7v2q, 0, m, &cSlice_3iNR7v2q_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cVar_m8Ix3fHp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_lSQrAVlP, 1, m, &cIf_lSQrAVlP_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_if5HjkQK_sendMessage);
}

void Heavy_SoundScraper::cBinop_if5HjkQK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_te413RcP, 1, m, &cIf_te413RcP_sendMessage);
}

void Heavy_SoundScraper::cSlice_3iNR7v2q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cIf_onMessage(_c, &Context(_c)->cIf_6rOONnze, 0, m, &cIf_6rOONnze_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_tp36l5d9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_qjwdR5zu_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_wxX3AjuN_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_JsNDXk3i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_OBJl1JQ9_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_j8g9TS4z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_NhP4EV7m_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_DTT88hSh_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_NyfBHUVc_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cCast_qjwdR5zu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_NEQ, 0.0f, 0, m, &cBinop_4Sx7CBu4_sendMessage);
}

void Heavy_SoundScraper::cIf_6rOONnze_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_qAWX7df8_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Kd8cOL0a_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cCast_wxX3AjuN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_gBDy3SwE, 0, m, &cIf_gBDy3SwE_sendMessage);
}

void Heavy_SoundScraper::cIf_gBDy3SwE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cPack_onMessage(_c, &Context(_c)->cPack_lA7P06zw, 2, m, &cPack_lA7P06zw_sendMessage);
      cPack_onMessage(_c, &Context(_c)->cPack_9a733PFq, 1, m, &cPack_9a733PFq_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_l2aq8nF3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_TuXtPgx8, 1, m, &cVar_TuXtPgx8_sendMessage);
}

void Heavy_SoundScraper::cPack_lA7P06zw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_JDlFSiEE_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_qAWX7df8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_lA7P06zw, 1, m, &cPack_lA7P06zw_sendMessage);
}

void Heavy_SoundScraper::cSend_0vJoTVKz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_i89foIcW_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_1FOJ7tkc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_viMpYEkR_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_3Yz9bYNA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_U8Ih02Gg, HV_BINOP_ADD, 0, m, &cBinop_U8Ih02Gg_sendMessage);
}

void Heavy_SoundScraper::cBinop_3cMEi2Kg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_U8Ih02Gg, HV_BINOP_ADD, 1, m, &cBinop_U8Ih02Gg_sendMessage);
}

void Heavy_SoundScraper::cVar_IecrjCGB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cBinop_U8Ih02Gg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Une0GPFu, 0, m, &cVar_Une0GPFu_sendMessage);
}

void Heavy_SoundScraper::cSend_cxHYCmBj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_t2ImK8S7_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_sj8eJAp4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_BuVjOa4L_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_tnKTLXoz_sendMessage);
}

void Heavy_SoundScraper::cIf_9sOuS4Oz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_D4crHq4S_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 440.0f, 0, m, &cBinop_mKP0Rp6l_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_ANR1epit_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_IecrjCGB, 0, m, &cVar_IecrjCGB_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_3Yz9bYNA, HV_BINOP_SUBTRACT, 1, m, &cBinop_3Yz9bYNA_sendMessage);
}

void Heavy_SoundScraper::cCast_BuVjOa4L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_Hc4sMo5r_sendMessage);
}

void Heavy_SoundScraper::cMsg_D4crHq4S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, -1500.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_IecrjCGB, 0, m, &cVar_IecrjCGB_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_3Yz9bYNA, HV_BINOP_SUBTRACT, 1, m, &cBinop_3Yz9bYNA_sendMessage);
}

void Heavy_SoundScraper::cUnop_GDrZLmfU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 12.0f, 0, m, &cBinop_JYstxLBV_sendMessage);
}

void Heavy_SoundScraper::cBinop_Hc4sMo5r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_9sOuS4Oz, 1, m, &cIf_9sOuS4Oz_sendMessage);
}

void Heavy_SoundScraper::cBinop_JYstxLBV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 69.0f, 0, m, &cBinop_ANR1epit_sendMessage);
}

void Heavy_SoundScraper::cBinop_mKP0Rp6l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_LOG2, m, &cUnop_GDrZLmfU_sendMessage);
}

void Heavy_SoundScraper::cCast_tnKTLXoz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_9sOuS4Oz, 0, m, &cIf_9sOuS4Oz_sendMessage);
}

void Heavy_SoundScraper::cCast_jwQ1Cmvw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_3Yz9bYNA, HV_BINOP_SUBTRACT, 0, m, &cBinop_3Yz9bYNA_sendMessage);
}

void Heavy_SoundScraper::cVar_Une0GPFu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_cxHYCmBj_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_cbRKxpD7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sSample_onMessage(_c, &Context(_c)->sSample_ASCMEqPZ, 1, m);
}

void Heavy_SoundScraper::cBinop_31yCYjXr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_0oEWHwnR, 0, m, &cVar_0oEWHwnR_sendMessage);
}

void Heavy_SoundScraper::cSend_3uHv8BM0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_MDy21nR2_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_5CWMsfoE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_QY0UbdAb, 0, m, &cDelay_QY0UbdAb_sendMessage);
}

void Heavy_SoundScraper::cDelay_QY0UbdAb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_QY0UbdAb, m);
  sSample_onMessage(_c, &Context(_c)->sSample_ASCMEqPZ, 1, m);
}

void Heavy_SoundScraper::cMsg_c1Pj56ph_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_QY0UbdAb, 0, m, &cDelay_QY0UbdAb_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_vzL8Ewdk_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_c1Pj56ph_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_c1Pj56ph_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_QY0UbdAb, 1, m, &cDelay_QY0UbdAb_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_5CWMsfoE_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_SHNEdT7B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_TmVT7cH2, 0, m, &cDelay_TmVT7cH2_sendMessage);
}

void Heavy_SoundScraper::cDelay_TmVT7cH2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_TmVT7cH2, m);
  sSample_onMessage(_c, &Context(_c)->sSample_ASCMEqPZ, 1, m);
}

void Heavy_SoundScraper::cMsg_aOEeM4kS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_TmVT7cH2, 0, m, &cDelay_TmVT7cH2_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_yJOjuJ77_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_aOEeM4kS_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_aOEeM4kS_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_TmVT7cH2, 1, m, &cDelay_TmVT7cH2_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_SHNEdT7B_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_AdRNxfXG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_3uHv8BM0_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_0taoIiC2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cUnop_7H9D1jAN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_HHH0pgpv_sendMessage);
}

void Heavy_SoundScraper::cBinop_I4cTZBTF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_7H9D1jAN_sendMessage);
}

void Heavy_SoundScraper::cSlice_VezPVhKA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_rljPhqci, 1, m, &cRandom_rljPhqci_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSwitchcase_pbBsjPQm_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_VezPVhKA, 0, m, &cSlice_VezPVhKA_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_rljPhqci, 0, m, &cRandom_rljPhqci_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cRandom_rljPhqci_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 100.0f, 0, m, &cBinop_I4cTZBTF_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_5U7ahLbS_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_TyFfADbn, 0, m, &cSlice_TyFfADbn_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_OyaBRWpn, 0, m, &cRandom_OyaBRWpn_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cRandom_OyaBRWpn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 40.0f, 0, m, &cBinop_d79fOUSQ_sendMessage);
}

void Heavy_SoundScraper::cSlice_TyFfADbn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_OyaBRWpn, 1, m, &cRandom_OyaBRWpn_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cUnop_ZZqo5AYi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 10.0f, 0, m, &cBinop_ruOZJcg1_sendMessage);
}

void Heavy_SoundScraper::cBinop_d79fOUSQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_ZZqo5AYi_sendMessage);
}

void Heavy_SoundScraper::cCast_Fa7CGMtR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_kuDYbjOo_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_HHH0pgpv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_K0ba2nC0_sendMessage(_c, 0, m);
  cPack_onMessage(_c, &Context(_c)->cPack_WlmhFUbW, 2, m, &cPack_WlmhFUbW_sendMessage);
}

void Heavy_SoundScraper::cSend_K0ba2nC0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_EZSbojeT_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_MoUbWGXF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_pbBsjPQm_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cPack_WlmhFUbW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPrint_onMessage(_c, m, "SCRAPER_RESET");
}

void Heavy_SoundScraper::cSend_cdOF4MiC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_viMpYEkR_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_dRkzStc1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ifcYMbe1_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cRandom_J7tfB487_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 30.0f, 0, m, &cBinop_QlxecXfc_sendMessage);
}

void Heavy_SoundScraper::cBinop_QlxecXfc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_Vt8jAfTz_sendMessage);
}

void Heavy_SoundScraper::cUnop_Vt8jAfTz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 25.0f, 0, m, &cBinop_oUYHEdeb_sendMessage);
}

void Heavy_SoundScraper::cSlice_XeyDd2ru_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_J7tfB487, 1, m, &cRandom_J7tfB487_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSwitchcase_kuDYbjOo_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_XeyDd2ru, 0, m, &cSlice_XeyDd2ru_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_J7tfB487, 0, m, &cRandom_J7tfB487_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cMsg_ifcYMbe1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSend_cdOF4MiC_sendMessage(_c, 0, m);
  cPack_onMessage(_c, &Context(_c)->cPack_WlmhFUbW, 3, m, &cPack_WlmhFUbW_sendMessage);
}

void Heavy_SoundScraper::cCast_nB8zyn4R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_5U7ahLbS_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_oUYHEdeb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_zwPgNfZq_sendMessage(_c, 0, m);
  cPack_onMessage(_c, &Context(_c)->cPack_WlmhFUbW, 1, m, &cPack_WlmhFUbW_sendMessage);
}

void Heavy_SoundScraper::cBinop_ruOZJcg1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_0taoIiC2_sendMessage(_c, 0, m);
  cPack_onMessage(_c, &Context(_c)->cPack_WlmhFUbW, 0, m, &cPack_WlmhFUbW_sendMessage);
}

void Heavy_SoundScraper::cSend_zwPgNfZq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_RUVe3pDV_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_L2jcM6y8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_u0WLPROZ_sendMessage);
}

void Heavy_SoundScraper::cBinop_u0WLPROZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_L2jcM6y8, 1, m, &cVar_L2jcM6y8_sendMessage);
}

void Heavy_SoundScraper::cMsg_F2XDIkNh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cPrint_onMessage(_c, m, "SCRAPER_RUNNING");
  sVarf_onMessage(_c, &Context(_c)->sVarf_sGelEI44, m);
}

void Heavy_SoundScraper::cCast_Fd5o81zJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_eh3c83PG_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_Ieib1wKz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_tJX4MQRi, 0, m, &cVar_tJX4MQRi_sendMessage);
}

void Heavy_SoundScraper::cMsg_1nzjyNj3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 44100.0f);
  cSend_i6UauzHH_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_70E9SST3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_o8LH6hUa_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_MQXUDQT9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSend_70E9SST3_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_Yrtk5C9y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSend_ym2vO4mX_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_eKc86o7b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_EZSbojeT_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_i6UauzHH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cMsg_sn0r72Gx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 5.0f);
  cSend_eKc86o7b_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_ym2vO4mX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_t2ImK8S7_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_Ji6gv0SC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_o8LH6hUa_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_K68lKhS2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_MDy21nR2_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSlice_7S9RSbvK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_AdRNxfXG_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_dVJuwuOA_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_AdRNxfXG_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_dVJuwuOA_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSwitchcase_AI8GgFli_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3F800000: { // "1.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_GASkMN1k, 0, m, &cSlice_GASkMN1k_sendMessage);
      break;
    }
    case 0x0: { // "0.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_7S9RSbvK, 0, m, &cSlice_7S9RSbvK_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cSlice_GASkMN1k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Fd5o81zJ_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Fd5o81zJ_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cMsg_N9GYmeX7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPrint_onMessage(_c, m, "SCRAPER_RUNNING");
  sVarf_onMessage(_c, &Context(_c)->sVarf_sGelEI44, m);
}

void Heavy_SoundScraper::cSend_NDinRmyc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_SJ6Uh0vb_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::sSample_ASCMEqPZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_hSX1EpJ3, 0, m, &cVar_hSX1EpJ3_sendMessage);
}

void Heavy_SoundScraper::cSend_SKm5mvnu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_hhNFlC8R_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_QNTNBb7M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_lEjFGiEC_sendMessage);
}

void Heavy_SoundScraper::cMsg_7GK3b8EH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_jHxaDnBq_sendMessage);
}

void Heavy_SoundScraper::cSystem_jHxaDnBq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_QNTNBb7M_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_lEjFGiEC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_zxpxkyZX, HV_BINOP_MULTIPLY, 1, m, &cBinop_zxpxkyZX_sendMessage);
}

void Heavy_SoundScraper::cBinop_zxpxkyZX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_W3l05oTe_sendMessage);
}

void Heavy_SoundScraper::cBinop_W3l05oTe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_w30cdhzP_sendMessage);
}

void Heavy_SoundScraper::cBinop_w30cdhzP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_nTmJt8R7_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_cVKoBcMM, m);
}

void Heavy_SoundScraper::cVar_IWPRAMQc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_zxpxkyZX, HV_BINOP_MULTIPLY, 0, m, &cBinop_zxpxkyZX_sendMessage);
}

void Heavy_SoundScraper::cBinop_nTmJt8R7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_LJNrNrgd, m);
}

void Heavy_SoundScraper::cBinop_aAjotN9W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_ay7lFJ2w, 0, m, &cPack_ay7lFJ2w_sendMessage);
}

void Heavy_SoundScraper::cPack_ay7lFJ2w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_VgJS7kLS, 0, m, NULL);
}

void Heavy_SoundScraper::cSystem_44PskMYu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 2.0f, 0, m, &cBinop_JeO8wv4O_sendMessage);
}

void Heavy_SoundScraper::cMsg_46AxoJJ1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_44PskMYu_sendMessage);
}

void Heavy_SoundScraper::cSlice_5eN5oJWM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sTabread_onMessage(_c, &Context(_c)->sTabread_P5BLAPKi, 1, m, NULL);
      sTabread_onMessage(_c, &Context(_c)->sTabread_igOAoUWy, 1, m, NULL);
      cVar_onMessage(_c, &Context(_c)->cVar_BVhRq1tD, 0, m, &cVar_BVhRq1tD_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cVar_BVhRq1tD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_46AxoJJ1_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_JeO8wv4O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_1i3HKFFn, m);
}

void Heavy_SoundScraper::cSwitchcase_tGXsCiA9_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_5eN5oJWM, 0, m, &cSlice_5eN5oJWM_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cSend_0d0FHQc3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_WM57f9yw_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_53DZ8J6A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSwitchcase_fEhXSlcL_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_8cIgAeXS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_pJMale4s, m);
}

void Heavy_SoundScraper::cMsg_AwbkDAjm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_XIPRJDIF_sendMessage);
}

void Heavy_SoundScraper::cVar_JiQ6bRd5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_AwbkDAjm_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSystem_XIPRJDIF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 2.0f, 0, m, &cBinop_8cIgAeXS_sendMessage);
}

void Heavy_SoundScraper::cSlice_XbTlGqZD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sTabread_onMessage(_c, &Context(_c)->sTabread_Bz8IQrUP, 1, m, NULL);
      sTabread_onMessage(_c, &Context(_c)->sTabread_MfTwMD66, 1, m, NULL);
      cVar_onMessage(_c, &Context(_c)->cVar_JiQ6bRd5, 0, m, &cVar_JiQ6bRd5_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSwitchcase_fEhXSlcL_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_XbTlGqZD, 0, m, &cSlice_XbTlGqZD_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cExpr_7E6tHPVK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_IATwDOb7, HV_BINOP_DIVIDE, 0, m, &cBinop_IATwDOb7_sendMessage);
}

float Heavy_SoundScraper::cExpr_7E6tHPVK_evaluate(const float* args) {
  	return hv_pow_f(2 , ((float)(args[0]))/1200);
}

void Heavy_SoundScraper::cCast_BkkUCsw0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_IATwDOb7, HV_BINOP_DIVIDE, 0, m, &cBinop_IATwDOb7_sendMessage);
}

void Heavy_SoundScraper::cBinop_Dqs77xgM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_MREAUVJW_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_IATwDOb7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_0ui6xbPb, 0, m, &cVar_0ui6xbPb_sendMessage);
}

void Heavy_SoundScraper::cSend_MREAUVJW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_RoL1C3Kj_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_PEcK7y0d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_IATwDOb7, HV_BINOP_DIVIDE, 1, m, &cBinop_IATwDOb7_sendMessage);
}

void Heavy_SoundScraper::cVar_zIqdTANI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cExpr_onMessage(_c, &Context(_c)->cExpr_7E6tHPVK, 0, m, &cExpr_7E6tHPVK_sendMessage);
}

void Heavy_SoundScraper::cBinop_RPjk0Dgz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_0d0FHQc3_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_YOsnolnC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_aL4CHNQ9_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_aL4CHNQ9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_7EK9zeiH_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_adIMRuo0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cSend_b6xvQooS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_2UQQNm07_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_tJX4MQRi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 44.1f, 0, m, &cBinop_YOsnolnC_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_Dqs77xgM_sendMessage);
}

void Heavy_SoundScraper::cVar_aT0m7Cx6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_tJX4MQRi, 0, m, &cVar_tJX4MQRi_sendMessage);
}

void Heavy_SoundScraper::cMsg_VAZU6Xmk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSend_zk6BIYaA_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_WUNf45qr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 100.0f);
  cSend_uVRsK4De_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_gpSWUIja_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSend_xu9bgdvu_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_uVRsK4De_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_Wd4NhQ0S_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_xu9bgdvu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_JUsaRojU_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_zk6BIYaA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_iBd6GA39_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_0oEWHwnR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 44.1f, 0, m, &cBinop_RPjk0Dgz_sendMessage);
}

void Heavy_SoundScraper::cMsg_ui0jxnme_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSwitchcase_tGXsCiA9_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cVar_0ui6xbPb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_8Ur4xh2K, 0, m);
}

void Heavy_SoundScraper::cVar_IzpMzzdU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_0oEWHwnR, 0, m, &cVar_0oEWHwnR_sendMessage);
}

void Heavy_SoundScraper::cCast_dVJuwuOA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_0vJoTVKz_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_eh3c83PG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_UdPOlQ82_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_hSX1EpJ3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPrint_onMessage(_c, m, "SCRAPER_SIG");
}

void Heavy_SoundScraper::cSystem_5B0KaNW3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_e6PV01zX, HV_BINOP_DIVIDE, 1, m, &cBinop_e6PV01zX_sendMessage);
}

void Heavy_SoundScraper::cMsg_8QjFuyS6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_5B0KaNW3_sendMessage);
}

void Heavy_SoundScraper::cBinop_7ykyqEz3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_RuEG0lVD_sendMessage);
}

void Heavy_SoundScraper::cVar_YLhzpjc3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_ezCYhhbS_sendMessage);
}

void Heavy_SoundScraper::cBinop_RuEG0lVD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_n7Zc3SxW_sendMessage);
}

void Heavy_SoundScraper::cBinop_n7Zc3SxW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_z9CKtwAU_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_qJ7Q5vPw_sendMessage);
}

void Heavy_SoundScraper::cBinop_bYhnFsRU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_CwOYbibd, m);
}

void Heavy_SoundScraper::cBinop_e6PV01zX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_slvKFEkf_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_ezCYhhbS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_xlcIy2it_sendMessage);
}

void Heavy_SoundScraper::cBinop_qJ7Q5vPw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_riXES2ua, m);
}

void Heavy_SoundScraper::cMsg_slvKFEkf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_7ykyqEz3_sendMessage);
}

void Heavy_SoundScraper::cBinop_xlcIy2it_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_e6PV01zX, HV_BINOP_DIVIDE, 0, m, &cBinop_e6PV01zX_sendMessage);
}

void Heavy_SoundScraper::cBinop_z9CKtwAU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_bYhnFsRU_sendMessage);
}

void Heavy_SoundScraper::cSend_nVIVW9ZY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_jMhwovL4_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_p9Q784Je_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_aAjotN9W_sendMessage);
}

void Heavy_SoundScraper::cBinop_rrfp8pgZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cExpr_onMessage(_c, &Context(_c)->cExpr_7E6tHPVK, 0, m, &cExpr_7E6tHPVK_sendMessage);
}

void Heavy_SoundScraper::cSend_tsVaYaSp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_Do9nya8H_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSlice_UKaWzyTm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSend_nVIVW9ZY_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_ywl0oAeO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSend_tsVaYaSp_sendMessage(_c, 0, m);
      cPrint_onMessage(_c, m, "SCRAPER_TAB");
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cReceive_mYumRgba_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 2.0f, 0, m, &cBinop_5KkNz9hd_sendMessage);
}

void Heavy_SoundScraper::cReceive_me6GXtaS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_NtklF6lA, HV_BINOP_DIVIDE, 1, m, &cBinop_NtklF6lA_sendMessage);
}

void Heavy_SoundScraper::cReceive_mpWxdZ0C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_vKvuftOz, 0, m, &cVar_vKvuftOz_sendMessage);
}

void Heavy_SoundScraper::cReceive_nsXxDOTw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_L2jcM6y8, 0, m, &cVar_L2jcM6y8_sendMessage);
  cSwitchcase_AI8GgFli_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cReceive_o8LH6hUa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_p9Q784Je_sendMessage);
  cPrint_onMessage(_c, m, "SCRAPER_LEVEL");
  cVar_onMessage(_c, &Context(_c)->cVar_MZyuKpsl, 0, m, &cVar_MZyuKpsl_sendMessage);
}

void Heavy_SoundScraper::cReceive_pJyJ8beI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_3UEzL0uV, m);
}

void Heavy_SoundScraper::cReceive_pwIe5pyd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Grfu0Ngg, HV_BINOP_DIVIDE, 1, m, &cBinop_Grfu0Ngg_sendMessage);
}

void Heavy_SoundScraper::cReceive_q6o7mfie_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_PF6hsemO_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_bg5dMEaN_sendMessage);
}

void Heavy_SoundScraper::cReceive_qRnOVDWs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_5IGkU8N8_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Eej5cfCi_sendMessage);
}

void Heavy_SoundScraper::cReceive_r510TR8k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_RJx7ENeP, 1, m, &cVar_RJx7ENeP_sendMessage);
}

void Heavy_SoundScraper::cReceive_rRS6P44Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_SKm5mvnu_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cReceive_sJLVG06s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_KSPhAnvf, 1, m, &cVar_KSPhAnvf_sendMessage);
}

void Heavy_SoundScraper::cReceive_t2ImK8S7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPrint_onMessage(_c, m, "SCRAPER_TRANSPOSITION");
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 100.0f, 0, m, &cBinop_rrfp8pgZ_sendMessage);
}

void Heavy_SoundScraper::cReceive_tx2TCvlM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_AMwHTY0Q_sendMessage(_c, 0, m);
  cMsg_Yd9Hf3lz_sendMessage(_c, 0, m);
  cMsg_5y0Nva8N_sendMessage(_c, 0, m);
  cMsg_azcWMMy8_sendMessage(_c, 0, m);
  cMsg_8ny13VLl_sendMessage(_c, 0, m);
  cMsg_GQp6DQ0Y_sendMessage(_c, 0, m);
  cMsg_E1XDLAi8_sendMessage(_c, 0, m);
  cMsg_Qfn39Lqf_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_8O9LuJpY, 0, m, &cVar_8O9LuJpY_sendMessage);
  cMsg_4w972H37_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_LP6LfgeT, 0, m, &cVar_LP6LfgeT_sendMessage);
  cMsg_SR7hPznG_sendMessage(_c, 0, m);
  cMsg_tEOBkZds_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_UgLkOSfA, 0, m, &cVar_UgLkOSfA_sendMessage);
  cMsg_kKgj26mj_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_uhKWI9pg, 0, m, &cVar_uhKWI9pg_sendMessage);
  cMsg_PdsKdVyn_sendMessage(_c, 0, m);
  cMsg_qFduss71_sendMessage(_c, 0, m);
  cMsg_mUI5nSUH_sendMessage(_c, 0, m);
  cMsg_brs7OAau_sendMessage(_c, 0, m);
  cMsg_cx4h1U3y_sendMessage(_c, 0, m);
  cMsg_MCS8zi8x_sendMessage(_c, 0, m);
  cMsg_A2HeDVbs_sendMessage(_c, 0, m);
  cMsg_KMy9GpdV_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_UwYm2B3w, 0, m, &cVar_UwYm2B3w_sendMessage);
  cMsg_P9rxUXcZ_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_h9nbQXbI, 0, m, &cVar_h9nbQXbI_sendMessage);
  cMsg_oNST9V0A_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_6gGIbERR, 0, m, &cVar_6gGIbERR_sendMessage);
  cMsg_ivzwmUjH_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_kTQEnTOC, 0, m, &cVar_kTQEnTOC_sendMessage);
  cMsg_46ESDs6G_sendMessage(_c, 0, m);
  cMsg_FWgGFZdU_sendMessage(_c, 0, m);
  cMsg_yBH3EFPG_sendMessage(_c, 0, m);
  cMsg_PjKkcAXP_sendMessage(_c, 0, m);
  cMsg_dXr4jq2u_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_7zYxjbNP, 0, m, &cVar_7zYxjbNP_sendMessage);
  cMsg_lJVYKCT7_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_FsHhjE6c, 0, m, &cVar_FsHhjE6c_sendMessage);
  cMsg_V282R6rK_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_MpIBnkWC, 0, m, &cVar_MpIBnkWC_sendMessage);
  cMsg_ewLfsmw4_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_YgoH762r, 0, m, &cVar_YgoH762r_sendMessage);
  cMsg_OGhYuQqG_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_8thkYCby, 0, m, &cVar_8thkYCby_sendMessage);
  cMsg_QVPGhvT7_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_kFmB3ZJL, 0, m, &cVar_kFmB3ZJL_sendMessage);
  cMsg_3XuyEAJV_sendMessage(_c, 0, m);
  cMsg_Yk3n9uoQ_sendMessage(_c, 0, m);
  cMsg_8cj8AfBJ_sendMessage(_c, 0, m);
  cMsg_usmO66Dg_sendMessage(_c, 0, m);
  cMsg_KiHdtdqp_sendMessage(_c, 0, m);
  cMsg_Sj0NUwr7_sendMessage(_c, 0, m);
  cMsg_jOZg8GKF_sendMessage(_c, 0, m);
  cMsg_29LIlaOf_sendMessage(_c, 0, m);
  cMsg_6pwWbFDF_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_rEAPspkj, 0, m, &cVar_rEAPspkj_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_wMvdCCPl, 0, m, &cVar_wMvdCCPl_sendMessage);
  cMsg_mszd6exa_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_AYuVqWOR, 0, m, &cVar_AYuVqWOR_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_ZnO3YYb7, 0, m, &cVar_ZnO3YYb7_sendMessage);
  cMsg_cK6PJVWh_sendMessage(_c, 0, m);
  cMsg_IPuPfbdw_sendMessage(_c, 0, m);
  cMsg_nWLQXqJ2_sendMessage(_c, 0, m);
  cMsg_3F3lBHb1_sendMessage(_c, 0, m);
  cMsg_HvwSu4XL_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_4vurxjLg, 0, m, &cVar_4vurxjLg_sendMessage);
  cMsg_D9snJVWn_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_w9s8gsro, 0, m, &cVar_w9s8gsro_sendMessage);
  cMsg_IUMMFkIP_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_VMqS8U9a, 0, m, &cVar_VMqS8U9a_sendMessage);
  cMsg_oLyqp723_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_TbXZlErM, 0, m, &cVar_TbXZlErM_sendMessage);
  cMsg_lKx5SvJV_sendMessage(_c, 0, m);
  cMsg_eOKUIqlV_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_btS5VW3w, 0, m, &cVar_btS5VW3w_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_01PnFloa, 0, m, &cVar_01PnFloa_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_Q68rrcEO, 0, m, &cVar_Q68rrcEO_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_ixLZUW9e, 0, m, &cVar_ixLZUW9e_sendMessage);
  cMsg_bHz7q75y_sendMessage(_c, 0, m);
  cMsg_VAZU6Xmk_sendMessage(_c, 0, m);
  cMsg_gpSWUIja_sendMessage(_c, 0, m);
  cMsg_WUNf45qr_sendMessage(_c, 0, m);
  cMsg_XbU0e5cR_sendMessage(_c, 0, m);
  cMsg_CJNK44x7_sendMessage(_c, 0, m);
  cMsg_5rrwxNbA_sendMessage(_c, 0, m);
  cMsg_aJbMkgtr_sendMessage(_c, 0, m);
  cMsg_Ppkwuftz_sendMessage(_c, 0, m);
  cMsg_omqBk88d_sendMessage(_c, 0, m);
  cMsg_2r46FSc4_sendMessage(_c, 0, m);
  cMsg_JRc8LTmf_sendMessage(_c, 0, m);
  cMsg_yirNRKnr_sendMessage(_c, 0, m);
  cMsg_pwFS074N_sendMessage(_c, 0, m);
  cMsg_RlHAjnoq_sendMessage(_c, 0, m);
  cMsg_AxRzuf7e_sendMessage(_c, 0, m);
  cMsg_me5ISvt5_sendMessage(_c, 0, m);
  cMsg_dsq8jUOc_sendMessage(_c, 0, m);
  cMsg_sbOsQGX8_sendMessage(_c, 0, m);
  cMsg_xmtLeHkx_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_Majfm0GP, 0, m, &cVar_Majfm0GP_sendMessage);
  cMsg_21cYREHO_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_8zmf3lwk, 0, m, &cVar_8zmf3lwk_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_aVE88ycb, 0, m, &cVar_aVE88ycb_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_EHW2pJfr, 0, m, &cVar_EHW2pJfr_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_pb1QVppF, 0, m, &cVar_pb1QVppF_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_RWHaRdz0, 0, m, &cVar_RWHaRdz0_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_yNkmr4rV, 0, m, &cVar_yNkmr4rV_sendMessage);
  cMsg_9ivztjgt_sendMessage(_c, 0, m);
  cMsg_6LtrH0tF_sendMessage(_c, 0, m);
  cMsg_7GK3b8EH_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_IWPRAMQc, 0, m, &cVar_IWPRAMQc_sendMessage);
  cMsg_Yrtk5C9y_sendMessage(_c, 0, m);
  cMsg_sn0r72Gx_sendMessage(_c, 0, m);
  cMsg_1nzjyNj3_sendMessage(_c, 0, m);
  cMsg_MQXUDQT9_sendMessage(_c, 0, m);
  cMsg_8QjFuyS6_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_YLhzpjc3, 0, m, &cVar_YLhzpjc3_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_IBNg1qeo, 0, m, &cVar_IBNg1qeo_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_Zn1ojjrH, 0, m, &cVar_Zn1ojjrH_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_oPZ52NA3, 0, m, &cVar_oPZ52NA3_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_2HkT7EA4, 0, m, &cVar_2HkT7EA4_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_6uEOTKW5, 0, m, &cVar_6uEOTKW5_sendMessage);
  cMsg_6pUjozXE_sendMessage(_c, 0, m);
  cMsg_gRVzueCM_sendMessage(_c, 0, m);
  cSend_K68lKhS2_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_sTYvRhZ9, 0, m, &cVar_sTYvRhZ9_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_UyoDPMGJ, 0, m, &cVar_UyoDPMGJ_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_LJONgNkw, 0, m, &cVar_LJONgNkw_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_ZwMUgIzr, 0, m, &cVar_ZwMUgIzr_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_lDaFAIiM, 0, m, &cVar_lDaFAIiM_sendMessage);
  cMsg_iQKVE74E_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_YObsSk03, 0, m, &cVar_YObsSk03_sendMessage);
  cMsg_1OPB8C3l_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_02AHW0Bq, 0, m, &cVar_02AHW0Bq_sendMessage);
  cMsg_r5QMKXHk_sendMessage(_c, 0, m);
  cMsg_3axR19W7_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_qN5QtCKP, 0, m, &cVar_qN5QtCKP_sendMessage);
  cMsg_eYXQ5pp9_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_Ay9w28ta, 0, m, &cTabhead_Ay9w28ta_sendMessage);
  cMsg_4v6OMUIw_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_RkOG7nu9, 0, m, &cVar_RkOG7nu9_sendMessage);
  cMsg_TUpLUGrK_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_bsldNoGU, 0, m, &cTabhead_bsldNoGU_sendMessage);
  cMsg_JeHx8xhJ_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_jWsXkRIT, 0, m, &cVar_jWsXkRIT_sendMessage);
  cMsg_PBmfKnPV_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_MD15ck9x, 0, m, &cTabhead_MD15ck9x_sendMessage);
  cMsg_BnZN7Zpa_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_TfY1UwNu, 0, m, &cVar_TfY1UwNu_sendMessage);
  cMsg_vDMwXiAF_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_po2Uy8VU, 0, m, &cTabhead_po2Uy8VU_sendMessage);
  cMsg_m6umx7jZ_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_qBNaUY0f, 0, m, &cVar_qBNaUY0f_sendMessage);
  cMsg_SHLVNZz5_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_h8J9M5Gk, 0, m, &cTabhead_h8J9M5Gk_sendMessage);
  cMsg_FiECT7xg_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_Nn2QYeSd, 0, m, &cVar_Nn2QYeSd_sendMessage);
  cMsg_B0taOGSw_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_GiSLm0Ve, 0, m, &cTabhead_GiSLm0Ve_sendMessage);
  cMsg_snxSGQG0_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_cQfHPFbx, 0, m, &cVar_cQfHPFbx_sendMessage);
  cMsg_zKlRJF1V_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_jFneiBZ8, 0, m, &cTabhead_jFneiBZ8_sendMessage);
  cMsg_QG8NKBLQ_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_uTpHW20o, 0, m, &cVar_uTpHW20o_sendMessage);
  cMsg_nEg3xGhJ_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_238LxNEE, 0, m, &cTabhead_238LxNEE_sendMessage);
  cMsg_3ig7Lm5k_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_6pBlUwqW, 0, m, &cVar_6pBlUwqW_sendMessage);
  cMsg_pXCGkRDP_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_Dmc8PtT0, 0, m, &cTabhead_Dmc8PtT0_sendMessage);
  cMsg_fBmVL2JY_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_tMoSExKz, 0, m, &cVar_tMoSExKz_sendMessage);
  cMsg_LMOWpzuc_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_HKIPOkNn, 0, m, &cTabhead_HKIPOkNn_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_bDdEds4R, 0, m, &cVar_bDdEds4R_sendMessage);
  cMsg_YgNzMhZe_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_OsTtho3f, 0, m, &cVar_OsTtho3f_sendMessage);
  cMsg_LZbQkNxW_sendMessage(_c, 0, m);
  cMsg_l3aBboEX_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_FRnRa57A, 0, m, &cVar_FRnRa57A_sendMessage);
  cMsg_jZcs1OLm_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_6zhX7sLi, 0, m, &cTabhead_6zhX7sLi_sendMessage);
  cMsg_9pCuWkDN_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_TSmzWwYE, 0, m, &cVar_TSmzWwYE_sendMessage);
  cMsg_vfLLOk7l_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_yB2e39Ly, 0, m, &cTabhead_yB2e39Ly_sendMessage);
  cMsg_iBbrZkJq_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_KgUstciN, 0, m, &cVar_KgUstciN_sendMessage);
  cMsg_k3qhc7vf_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_YXrQA3J2, 0, m, &cTabhead_YXrQA3J2_sendMessage);
  cMsg_psluHfVQ_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_hJUM360N, 0, m, &cVar_hJUM360N_sendMessage);
  cMsg_MxuQiGAF_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_Bnw0b04Z, 0, m, &cTabhead_Bnw0b04Z_sendMessage);
  cMsg_GGx6ikvq_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_qTOMUqko, 0, m, &cVar_qTOMUqko_sendMessage);
  cMsg_BCqGYrTD_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_4IJwIwRB, 0, m, &cTabhead_4IJwIwRB_sendMessage);
  cMsg_QWylQbiQ_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_YKuyqJkJ, 0, m, &cVar_YKuyqJkJ_sendMessage);
  cMsg_tO5bbbTG_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_ccb5gzCO, 0, m, &cTabhead_ccb5gzCO_sendMessage);
  cMsg_xHzYMt2t_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_4xtVoWQl, 0, m, &cVar_4xtVoWQl_sendMessage);
  cMsg_m3XYiIpc_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_RIhxzTXX, 0, m, &cTabhead_RIhxzTXX_sendMessage);
  cMsg_bdL5NQmx_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_m3EZUm6A, 0, m, &cVar_m3EZUm6A_sendMessage);
  cMsg_ulFj3abE_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_TNf1eExq, 0, m, &cTabhead_TNf1eExq_sendMessage);
  cMsg_YLgj1ukC_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_Hz4wWSlG, 0, m, &cVar_Hz4wWSlG_sendMessage);
  cMsg_KriTvrTG_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_akRr0TKx, 0, m, &cTabhead_akRr0TKx_sendMessage);
  cMsg_5qRB83KQ_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_0Olyx67a, 0, m, &cVar_0Olyx67a_sendMessage);
  cMsg_moX34wwg_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_zgIRUxoj, 0, m, &cTabhead_zgIRUxoj_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_1wlv4jAe, 0, m, &cVar_1wlv4jAe_sendMessage);
  cMsg_arWbJhlG_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_BVhRq1tD, 0, m, &cVar_BVhRq1tD_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_JiQ6bRd5, 0, m, &cVar_JiQ6bRd5_sendMessage);
}

void Heavy_SoundScraper::cReceive_ue79bHQD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_t5IYoLta, m);
}

void Heavy_SoundScraper::cBinop_4MjNL4r0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_YsGQXf8I_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Ccent5HC_sendMessage);
}

void Heavy_SoundScraper::cCast_rH3tCYIv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cVar_KSPhAnvf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_WNx24O3v, 1, m, &cPack_WNx24O3v_sendMessage);
}

void Heavy_SoundScraper::cCast_Ccent5HC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_WNx24O3v, 0, m, &cPack_WNx24O3v_sendMessage);
}

void Heavy_SoundScraper::cPack_WNx24O3v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Nj6DFvLz_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ipJqZGMy_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_MqY07X5b, 0, m, &cSlice_MqY07X5b_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_KtNQfHg4, 0, m, &cSlice_KtNQfHg4_sendMessage);
  cPrint_onMessage(_c, m, "TABLEPLAYER_COMMAND");
}

void Heavy_SoundScraper::cCast_YsGQXf8I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_KSPhAnvf, 0, m, &cVar_KSPhAnvf_sendMessage);
}

void Heavy_SoundScraper::cMsg_AxRzuf7e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSend_sqsw2EZT_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_L8EjcMWz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_m0jn3s0L_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_NHbGz78k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_ue79bHQD_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_OTsyF41f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_dzV4DPcb_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_RlHAjnoq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 4000.0f);
  cSend_OTsyF41f_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_UJKdA943_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_LMd39CXq, 1, m, &cVar_LMd39CXq_sendMessage);
}

void Heavy_SoundScraper::cDelay_TN0k3zbQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_TN0k3zbQ, m);
  cVar_onMessage(_c, &Context(_c)->cVar_LMd39CXq, 0, m, &cVar_LMd39CXq_sendMessage);
}

void Heavy_SoundScraper::cCast_WkLBgba0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_TN0k3zbQ, 0, m, &cDelay_TN0k3zbQ_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_klUTrmZ8_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_rgW0CU60_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_rgW0CU60_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_TN0k3zbQ, 1, m, &cDelay_TN0k3zbQ_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_WkLBgba0_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cMsg_rgW0CU60_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_TN0k3zbQ, 0, m, &cDelay_TN0k3zbQ_sendMessage);
}

void Heavy_SoundScraper::cVar_48LijKnP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_L8EjcMWz_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_UJKdA943_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_kEJJAuR9_sendMessage);
}

void Heavy_SoundScraper::cCast_dRWbWHQR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_48LijKnP, 0, m, &cVar_48LijKnP_sendMessage);
}

void Heavy_SoundScraper::cVar_LMd39CXq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_uwVSXi1B_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_kEJJAuR9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_klUTrmZ8_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cMsg_m0jn3s0L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 25.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_2P8mbY2y, 0, m, NULL);
}

void Heavy_SoundScraper::cMsg_pwFS074N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 25.0f);
  cSend_vRWNT9iK_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_sqsw2EZT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_ue79bHQD_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_uwVSXi1B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 0);
  sLine_onMessage(_c, &Context(_c)->sLine_2P8mbY2y, 0, m, NULL);
}

void Heavy_SoundScraper::cSend_vRWNT9iK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cUnop_B3v7faAs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_pZ4BZ6UO_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_bZMkvl4z_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_hRkciHrs, 0, m, &cSlice_hRkciHrs_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_giDhiHVP, 0, m, &cRandom_giDhiHVP_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cRandom_giDhiHVP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_hYE2jt41_sendMessage);
}

void Heavy_SoundScraper::cSlice_hRkciHrs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_giDhiHVP, 1, m, &cRandom_giDhiHVP_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_hYE2jt41_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_B3v7faAs_sendMessage);
}

void Heavy_SoundScraper::cBinop_Grfu0Ngg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4MjNL4r0, HV_BINOP_MULTIPLY, 0, m, &cBinop_4MjNL4r0_sendMessage);
}

void Heavy_SoundScraper::cSlice_QPio2HST_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_cOg55uJD_sendMessage);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_9BfSbfVA_sendMessage);
      cPrint_onMessage(_c, m, "PERCSAMPLER_NOTE");
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_YFizWWF7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 127.0f, 0, m, &cBinop_Pje2F57r_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cUnop_1earnbJr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_N8pmwXwC_sendMessage);
}

void Heavy_SoundScraper::cRandom_NqAlEh4g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 15.0f, 0, m, &cBinop_PpQkn2Vn_sendMessage);
}

void Heavy_SoundScraper::cBinop_PpQkn2Vn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_1earnbJr_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_ZoXcx7Gq_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_be6oqhtN, 0, m, &cSlice_be6oqhtN_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_NqAlEh4g, 0, m, &cRandom_NqAlEh4g_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cSlice_be6oqhtN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_NqAlEh4g, 1, m, &cRandom_NqAlEh4g_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_9QL17Sxq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_389VEx53, 0, m, &cVar_389VEx53_sendMessage);
}

void Heavy_SoundScraper::cSlice_0bUP7BVu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sTabread_onMessage(_c, &Context(_c)->sTabread_xvfKRRxx, 1, m, NULL);
      sTabread_onMessage(_c, &Context(_c)->sTabread_eAmx89Kq, 1, m, NULL);
      cVar_onMessage(_c, &Context(_c)->cVar_LJONgNkw, 0, m, &cVar_LJONgNkw_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSystem_IgIk2IkY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 2.0f, 0, m, &cBinop_v9Gjd9o4_sendMessage);
}

void Heavy_SoundScraper::cVar_LJONgNkw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_YB4Ilcxk_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_YB4Ilcxk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_IgIk2IkY_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_Zjn1HlMi_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_0bUP7BVu, 0, m, &cSlice_0bUP7BVu_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_v9Gjd9o4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_A6KZg1dy, m);
}

void Heavy_SoundScraper::cSlice_9aEdFzKI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_9QL17Sxq_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_DR14GAwe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 44100.0f, 0, m, &cBinop_wFZuWykC_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_KtNQfHg4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_yBohUrD3_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_q1EmrL66_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_jipezGi1_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_xo4XpkPP, 0, m, &cVar_xo4XpkPP_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_MqY07X5b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_rqBTySv7_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cVar_389VEx53_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::hTable_dqgidaqB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cVar_KLZkdgi7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cMsg_rqBTySv7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSwitchcase_Zjn1HlMi_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_wFZuWykC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_KLZkdgi7, 0, m, &cVar_KLZkdgi7_sendMessage);
}

void Heavy_SoundScraper::cVar_mncmhsWu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 100000.0f, 0, m, &cBinop_zldvKZTW_sendMessage);
}

void Heavy_SoundScraper::cBinop_58D7xTy2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_mncmhsWu, 0, m, &cVar_mncmhsWu_sendMessage);
}

void Heavy_SoundScraper::cCast_KxDKiHt2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_sm6vop1m, 0, m, &cDelay_sm6vop1m_sendMessage);
}

void Heavy_SoundScraper::cMsg_i5X1itQb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_sm6vop1m, 0, m, &cDelay_sm6vop1m_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_mvQgS1rF_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_i5X1itQb_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_i5X1itQb_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_sm6vop1m, 1, m, &cDelay_sm6vop1m_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_KxDKiHt2_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cDelay_sm6vop1m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_sm6vop1m, m);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_LVyDya7h_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_NEMF1j2L_sendMessage);
}

void Heavy_SoundScraper::cVar_xo4XpkPP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cPack_GBRJwljZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_ivzfRKZ7_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_GVhrsp57_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_zTsXD6YR_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_IIsOyJhJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 0.0f);
  cSend_GVhrsp57_sendMessage(_c, 0, m);
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 1);
  msg_setElementToFrom(m, 1, n, 0);
  cSend_GVhrsp57_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_KpnaiOas_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_CyRdbAJg_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_LVyDya7h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_OC4NS0x6, 0, m, &cVar_OC4NS0x6_sendMessage);
}

void Heavy_SoundScraper::cCast_NEMF1j2L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_7ILSpeEZ, 0, m, &cVar_7ILSpeEZ_sendMessage);
}

void Heavy_SoundScraper::cCast_ORab0XlS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_mGtVf59g, 0, m, &cPack_mGtVf59g_sendMessage);
}

void Heavy_SoundScraper::cCast_IbtYV3Po_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_5eZ1CZic, 0, m, &cVar_5eZ1CZic_sendMessage);
}

void Heavy_SoundScraper::cVar_5eZ1CZic_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_58D7xTy2, HV_BINOP_DIVIDE, 1, m, &cBinop_58D7xTy2_sendMessage);
}

void Heavy_SoundScraper::cSwitchcase_U6Cak3ak_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0xFFFFFFFF: { // "bang"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_uRwM9GNm_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ffLmpw6C_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_IbtYV3Po_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_o9cWFQb6_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_ffLmpw6C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_dQ6Js9mW, 0, m, &cVar_dQ6Js9mW_sendMessage);
}

void Heavy_SoundScraper::cVar_dQ6Js9mW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_58D7xTy2, HV_BINOP_DIVIDE, 0, m, &cBinop_58D7xTy2_sendMessage);
}

void Heavy_SoundScraper::cCast_o9cWFQb6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_dQ6Js9mW, 0, m, &cVar_dQ6Js9mW_sendMessage);
}

void Heavy_SoundScraper::cCast_uRwM9GNm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_5eZ1CZic, 0, m, &cVar_5eZ1CZic_sendMessage);
}

void Heavy_SoundScraper::cPack_hsU2ZVWs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_IIsOyJhJ_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_ivzfRKZ7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_CyRdbAJg_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_jipezGi1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ORab0XlS_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_q9qq7oTQ_sendMessage);
}

void Heavy_SoundScraper::cVar_7ILSpeEZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_GBRJwljZ, 0, m, &cPack_GBRJwljZ_sendMessage);
}

void Heavy_SoundScraper::cPack_mGtVf59g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_KpnaiOas_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_q1EmrL66_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_OC4NS0x6, 1, m, &cVar_OC4NS0x6_sendMessage);
}

void Heavy_SoundScraper::cCast_q9qq7oTQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_mvQgS1rF_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_sY69BtZq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_hsU2ZVWs, 1, m, &cPack_hsU2ZVWs_sendMessage);
}

void Heavy_SoundScraper::cMsg_usmO66Dg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 44100.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 100.0f, 0, m, &cBinop_sY69BtZq_sendMessage);
}

void Heavy_SoundScraper::cCast_yBohUrD3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cVar_OC4NS0x6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_U6Cak3ak_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_zldvKZTW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_hsU2ZVWs, 0, m, &cPack_hsU2ZVWs_sendMessage);
}

void Heavy_SoundScraper::cBinop_N8pmwXwC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.99f, 0, m, &cBinop_cnfmS3IJ_sendMessage);
}

void Heavy_SoundScraper::cSend_NG1rA9r2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_sJLVG06s_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_Nj6DFvLz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_bZMkvl4z_onMessage(_c, NULL, 0, m, NULL);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_rH3tCYIv_sendMessage);
}

void Heavy_SoundScraper::cBinop_1fD3OqQY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_3yu34DfP_sendMessage);
}

void Heavy_SoundScraper::cBinop_3yu34DfP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Grfu0Ngg, HV_BINOP_DIVIDE, 0, m, &cBinop_Grfu0Ngg_sendMessage);
}

void Heavy_SoundScraper::cBinop_9BfSbfVA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_no5oSF1E_sendMessage);
}

void Heavy_SoundScraper::cMsg_WA1JyZAo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_1fD3OqQY, HV_BINOP_POW, 0, m, &cBinop_1fD3OqQY_sendMessage);
}

void Heavy_SoundScraper::cBinop_no5oSF1E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_1fD3OqQY, HV_BINOP_POW, 1, m, &cBinop_1fD3OqQY_sendMessage);
  cMsg_WA1JyZAo_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_Pje2F57r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_lhwRxwnY_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_PoHqV3UQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_W6oieqmz_sendMessage);
}

void Heavy_SoundScraper::cCast_cOg55uJD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_ZoXcx7Gq_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_cnfmS3IJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4MjNL4r0, HV_BINOP_MULTIPLY, 1, m, &cBinop_4MjNL4r0_sendMessage);
}

void Heavy_SoundScraper::cSlice_6C9Y56FE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSend_mo6EloTV_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_nWqnUC27_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSend_NG1rA9r2_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cCast_ipJqZGMy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_dRWbWHQR_sendMessage);
}

void Heavy_SoundScraper::cSend_lhwRxwnY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_FhL5QWRt_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_mo6EloTV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_pwIe5pyd_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_pZ4BZ6UO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.4f, 0, m, &cBinop_PoHqV3UQ_sendMessage);
}

void Heavy_SoundScraper::cUnop_lPZzq55l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_WoUl5Yx9, 0, m, &cPack_WoUl5Yx9_sendMessage);
}

void Heavy_SoundScraper::cUnop_YtDZdiwl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_HHJNKIVQ, 0, m, &cPack_HHJNKIVQ_sendMessage);
}

void Heavy_SoundScraper::cPack_HHJNKIVQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_N6lrmGJT, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_W6oieqmz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_lPZzq55l_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_SIN, m, &cUnop_YtDZdiwl_sendMessage);
}

void Heavy_SoundScraper::cPack_WoUl5Yx9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_b2iW3hdu, 0, m, NULL);
}

void Heavy_SoundScraper::cMsg_yirNRKnr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.5f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_W6oieqmz_sendMessage);
}

void Heavy_SoundScraper::cReceive_vcMb0WOz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_KmtnFRlu_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_iKxiqkmm_sendMessage);
}

void Heavy_SoundScraper::cReceive_viMpYEkR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.25f, 0, m, &cBinop_3cMEi2Kg_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_jwQ1Cmvw_sendMessage);
}

void Heavy_SoundScraper::cReceive_z6iEtg1P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_WXnUNTtm_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cReceive_zTsXD6YR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_QtVh0uKT, 0, m, NULL);
  cPrint_onMessage(_c, m, "TABLEPLAYER_PHASE");
  cSlice_onMessage(_c, &Context(_c)->cSlice_9aEdFzKI, 0, m, &cSlice_9aEdFzKI_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_DR14GAwe, 0, m, &cSlice_DR14GAwe_sendMessage);
}

void Heavy_SoundScraper::cReceive_zfd68FNh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_1FOJ7tkc_sendMessage(_c, 0, m);
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
  hv_bufferf_t Bf0, Bf1, Bf2, Bf3, Bf4, Bf5, Bf6, Bf7, Bf8, Bf9, Bf10, Bf11, Bf12, Bf13, Bf14, Bf15, Bf16, Bf17, Bf18, Bf19;
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
    __hv_varread_f(&sVarf_sGelEI44, VOf(Bf0));
    __hv_varread_f(&sVarf_cVKoBcMM, VOf(Bf1));
    __hv_mul_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_LJNrNrgd, VOf(Bf0));
    __hv_rpole_f(&sRPole_j0JbZtTr, VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_phasor_k_f(&sPhasor_8Ur4xh2K, VOf(Bf1));
    __hv_var_k_f(VOf(Bf2), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_add_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_floor_f(VIf(Bf2), VOf(Bf3));
    __hv_sub_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_varwrite_f(&sVarf_w9M2pK8I, VIf(Bf3));
    __hv_varwrite_f(&sVarf_eaDVrtdO, VIf(Bf1));
    __hv_varread_f(&sVarf_wurxiXrM, VOf(Bf1));
    __hv_varread_f(&sVarf_eaDVrtdO, VOf(Bf3));
    __hv_del1_f(&sDel1_0lZ8wKKw, VIf(Bf3), VOf(Bf2));
    __hv_lt_f(VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_samphold_f(&sSamphold_QN7EbMMX, VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_eaDVrtdO, VOf(Bf1));
    __hv_var_k_f(VOf(Bf3), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_fma_f(VIf(Bf2), VIf(Bf1), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_TB87PUyv, VOf(Bf1));
    __hv_varread_f(&sVarf_eaDVrtdO, VOf(Bf2));
    __hv_del1_f(&sDel1_z460VTzG, VIf(Bf2), VOf(Bf4));
    __hv_lt_f(VIf(Bf2), VIf(Bf4), VOf(Bf4));
    __hv_samphold_f(&sSamphold_wBWnNM8U, VIf(Bf1), VIf(Bf4), VOf(Bf4));
    __hv_add_f(VIf(Bf3), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_pJMale4s, VOf(Bf3));
    __hv_min_f(VIf(Bf4), VIf(Bf3), VOf(Bf3));
    __hv_zero_f(VOf(Bf4));
    __hv_max_f(VIf(Bf3), VIf(Bf4), VOf(Bf4));
    __hv_floor_f(VIf(Bf4), VOf(Bf3));
    __hv_cast_fi(VIf(Bf3), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_Bz8IQrUP, VIi(Bi1), VOf(Bf1));
    __hv_tabread_if(&sTabread_MfTwMD66, VIi(Bi0), VOf(Bf2));
    __hv_sub_f(VIf(Bf1), VIf(Bf2), VOf(Bf1));
    __hv_sub_f(VIf(Bf4), VIf(Bf3), VOf(Bf3));
    __hv_fma_f(VIf(Bf1), VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_eaDVrtdO, VOf(Bf3));
    __hv_var_k_f(VOf(Bf1), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf3), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf3), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf1), VIf(Bf3), VOf(Bf3));
    __hv_floor_f(VIf(Bf3), VOf(Bf1));
    __hv_sub_f(VIf(Bf3), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf3), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf1), VIf(Bf3), VOf(Bf3));
    __hv_abs_f(VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf1), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf3), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf3), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf1), VIf(Bf3), VOf(Bf3));
    __hv_mul_f(VIf(Bf3), VIf(Bf3), VOf(Bf1));
    __hv_mul_f(VIf(Bf3), VIf(Bf1), VOf(Bf4));
    __hv_mul_f(VIf(Bf4), VIf(Bf1), VOf(Bf5));
    __hv_mul_f(VIf(Bf5), VIf(Bf1), VOf(Bf6));
    __hv_mul_f(VIf(Bf6), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf7), 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f);
    __hv_var_k_f(VOf(Bf8), 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f);
    __hv_var_k_f(VOf(Bf9), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf4), VIf(Bf9), VOf(Bf9));
    __hv_sub_f(VIf(Bf3), VIf(Bf9), VOf(Bf9));
    __hv_fma_f(VIf(Bf5), VIf(Bf8), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf8), 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f);
    __hv_mul_f(VIf(Bf6), VIf(Bf8), VOf(Bf8));
    __hv_sub_f(VIf(Bf9), VIf(Bf8), VOf(Bf8));
    __hv_fma_f(VIf(Bf1), VIf(Bf7), VIf(Bf8), VOf(Bf8));
    __hv_varread_f(&sVarf_uvWzq1Ec, VOf(Bf7));
    __hv_varread_f(&sVarf_w9M2pK8I, VOf(Bf1));
    __hv_del1_f(&sDel1_tRALRFZl, VIf(Bf1), VOf(Bf9));
    __hv_lt_f(VIf(Bf1), VIf(Bf9), VOf(Bf9));
    __hv_samphold_f(&sSamphold_KXe9xik7, VIf(Bf7), VIf(Bf9), VOf(Bf9));
    __hv_varread_f(&sVarf_w9M2pK8I, VOf(Bf7));
    __hv_var_k_f(VOf(Bf1), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_fma_f(VIf(Bf9), VIf(Bf7), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_aEHBNCon, VOf(Bf7));
    __hv_varread_f(&sVarf_w9M2pK8I, VOf(Bf9));
    __hv_del1_f(&sDel1_scwDdBXK, VIf(Bf9), VOf(Bf6));
    __hv_lt_f(VIf(Bf9), VIf(Bf6), VOf(Bf6));
    __hv_samphold_f(&sSamphold_rlJsbykp, VIf(Bf7), VIf(Bf6), VOf(Bf6));
    __hv_add_f(VIf(Bf1), VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_1i3HKFFn, VOf(Bf1));
    __hv_min_f(VIf(Bf6), VIf(Bf1), VOf(Bf1));
    __hv_zero_f(VOf(Bf6));
    __hv_max_f(VIf(Bf1), VIf(Bf6), VOf(Bf6));
    __hv_floor_f(VIf(Bf6), VOf(Bf1));
    __hv_cast_fi(VIf(Bf1), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_P5BLAPKi, VIi(Bi1), VOf(Bf7));
    __hv_tabread_if(&sTabread_igOAoUWy, VIi(Bi0), VOf(Bf9));
    __hv_sub_f(VIf(Bf7), VIf(Bf9), VOf(Bf7));
    __hv_sub_f(VIf(Bf6), VIf(Bf1), VOf(Bf1));
    __hv_fma_f(VIf(Bf7), VIf(Bf1), VIf(Bf9), VOf(Bf9));
    __hv_varread_f(&sVarf_w9M2pK8I, VOf(Bf1));
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
    __hv_mul_f(VIf(Bf5), VIf(Bf7), VOf(Bf3));
    __hv_mul_f(VIf(Bf3), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf4), 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f);
    __hv_var_k_f(VOf(Bf10), 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f);
    __hv_var_k_f(VOf(Bf11), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf6), VIf(Bf11), VOf(Bf11));
    __hv_sub_f(VIf(Bf1), VIf(Bf11), VOf(Bf11));
    __hv_fma_f(VIf(Bf5), VIf(Bf10), VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf10), 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f);
    __hv_mul_f(VIf(Bf3), VIf(Bf10), VOf(Bf10));
    __hv_sub_f(VIf(Bf11), VIf(Bf10), VOf(Bf10));
    __hv_fma_f(VIf(Bf7), VIf(Bf4), VIf(Bf10), VOf(Bf10));
    __hv_mul_f(VIf(Bf9), VIf(Bf10), VOf(Bf10));
    __hv_fma_f(VIf(Bf2), VIf(Bf8), VIf(Bf10), VOf(Bf10));
    __hv_varread_f(&sVarf_riXES2ua, VOf(Bf8));
    __hv_rpole_f(&sRPole_7jcTZ8Y7, VIf(Bf10), VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf10), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_del1_f(&sDel1_wINFFuV7, VIf(Bf8), VOf(Bf2));
    __hv_mul_f(VIf(Bf2), VIf(Bf10), VOf(Bf10));
    __hv_sub_f(VIf(Bf8), VIf(Bf10), VOf(Bf10));
    __hv_varread_f(&sVarf_CwOYbibd, VOf(Bf8));
    __hv_mul_f(VIf(Bf10), VIf(Bf8), VOf(Bf8));
    __hv_mul_f(VIf(Bf0), VIf(Bf8), VOf(Bf8));
    __hv_line_f(&sLine_VgJS7kLS, VOf(Bf0));
    __hv_mul_f(VIf(Bf8), VIf(Bf0), VOf(Bf0));
    __hv_sample_f(this, &sSample_ASCMEqPZ, VIf(Bf8), &sSample_ASCMEqPZ_sendMessage);
    __hv_line_f(&sLine_cAPdStYy, VOf(Bf8));
    __hv_varread_f(&sVarf_HgSXPSnM, VOf(Bf10));
    __hv_min_f(VIf(Bf8), VIf(Bf10), VOf(Bf10));
    __hv_zero_f(VOf(Bf8));
    __hv_max_f(VIf(Bf10), VIf(Bf8), VOf(Bf8));
    __hv_floor_f(VIf(Bf8), VOf(Bf10));
    __hv_cast_fi(VIf(Bf10), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_bBKzDePT, VIi(Bi1), VOf(Bf2));
    __hv_tabread_if(&sTabread_TReXBIUJ, VIi(Bi0), VOf(Bf9));
    __hv_sub_f(VIf(Bf2), VIf(Bf9), VOf(Bf2));
    __hv_sub_f(VIf(Bf8), VIf(Bf10), VOf(Bf10));
    __hv_fma_f(VIf(Bf2), VIf(Bf10), VIf(Bf9), VOf(Bf9));
    __hv_line_f(&sLine_qm8yewgh, VOf(Bf10));
    __hv_mul_f(VIf(Bf9), VIf(Bf10), VOf(Bf10));
    __hv_line_f(&sLine_7wuBgJ5s, VOf(Bf9));
    __hv_varread_f(&sVarf_EIuT2fqi, VOf(Bf2));
    __hv_mul_f(VIf(Bf9), VIf(Bf2), VOf(Bf2));
    __hv_mul_f(VIf(Bf10), VIf(Bf2), VOf(Bf2));
    __hv_line_f(&sLine_gVqws3WR, VOf(Bf10));
    __hv_mul_f(VIf(Bf2), VIf(Bf10), VOf(Bf10));
    __hv_line_f(&sLine_nsa1SCND, VOf(Bf9));
    __hv_mul_f(VIf(Bf2), VIf(Bf9), VOf(Bf9));
    __hv_line_f(&sLine_IB7l1ctW, VOf(Bf2));
    __hv_varread_f(&sVarf_bgDUH05l, VOf(Bf8));
    __hv_min_f(VIf(Bf2), VIf(Bf8), VOf(Bf8));
    __hv_zero_f(VOf(Bf2));
    __hv_max_f(VIf(Bf8), VIf(Bf2), VOf(Bf2));
    __hv_floor_f(VIf(Bf2), VOf(Bf8));
    __hv_cast_fi(VIf(Bf8), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_61hRkCkk, VIi(Bi1), VOf(Bf4));
    __hv_tabread_if(&sTabread_Dq51SkCT, VIi(Bi0), VOf(Bf7));
    __hv_sub_f(VIf(Bf4), VIf(Bf7), VOf(Bf4));
    __hv_sub_f(VIf(Bf2), VIf(Bf8), VOf(Bf8));
    __hv_fma_f(VIf(Bf4), VIf(Bf8), VIf(Bf7), VOf(Bf7));
    __hv_line_f(&sLine_OhR0L8UX, VOf(Bf8));
    __hv_mul_f(VIf(Bf7), VIf(Bf8), VOf(Bf8));
    __hv_line_f(&sLine_O0ifSzPL, VOf(Bf7));
    __hv_varread_f(&sVarf_3UEzL0uV, VOf(Bf4));
    __hv_mul_f(VIf(Bf7), VIf(Bf4), VOf(Bf4));
    __hv_mul_f(VIf(Bf8), VIf(Bf4), VOf(Bf4));
    __hv_line_f(&sLine_kpWJi41L, VOf(Bf8));
    __hv_mul_f(VIf(Bf4), VIf(Bf8), VOf(Bf8));
    __hv_line_f(&sLine_fa9VpVzC, VOf(Bf7));
    __hv_mul_f(VIf(Bf4), VIf(Bf7), VOf(Bf7));
    __hv_add_f(VIf(Bf10), VIf(Bf7), VOf(Bf7));
    __hv_line_f(&sLine_QtVh0uKT, VOf(Bf10));
    __hv_varread_f(&sVarf_A6KZg1dy, VOf(Bf4));
    __hv_min_f(VIf(Bf10), VIf(Bf4), VOf(Bf4));
    __hv_zero_f(VOf(Bf10));
    __hv_max_f(VIf(Bf4), VIf(Bf10), VOf(Bf10));
    __hv_floor_f(VIf(Bf10), VOf(Bf4));
    __hv_cast_fi(VIf(Bf4), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_xvfKRRxx, VIi(Bi1), VOf(Bf2));
    __hv_tabread_if(&sTabread_eAmx89Kq, VIi(Bi0), VOf(Bf11));
    __hv_sub_f(VIf(Bf2), VIf(Bf11), VOf(Bf2));
    __hv_sub_f(VIf(Bf10), VIf(Bf4), VOf(Bf4));
    __hv_fma_f(VIf(Bf2), VIf(Bf4), VIf(Bf11), VOf(Bf11));
    __hv_line_f(&sLine_KRQa77bb, VOf(Bf4));
    __hv_mul_f(VIf(Bf11), VIf(Bf4), VOf(Bf4));
    __hv_line_f(&sLine_2P8mbY2y, VOf(Bf11));
    __hv_varread_f(&sVarf_t5IYoLta, VOf(Bf2));
    __hv_mul_f(VIf(Bf11), VIf(Bf2), VOf(Bf2));
    __hv_mul_f(VIf(Bf4), VIf(Bf2), VOf(Bf2));
    __hv_line_f(&sLine_N6lrmGJT, VOf(Bf4));
    __hv_mul_f(VIf(Bf2), VIf(Bf4), VOf(Bf4));
    __hv_line_f(&sLine_b2iW3hdu, VOf(Bf11));
    __hv_mul_f(VIf(Bf2), VIf(Bf11), VOf(Bf11));
    __hv_add_f(VIf(Bf7), VIf(Bf11), VOf(Bf11));
    __hv_line_f(&sLine_VYGTLUEb, VOf(Bf7));
    __hv_varread_f(&sVarf_jIF40qTi, VOf(Bf2));
    __hv_min_f(VIf(Bf7), VIf(Bf2), VOf(Bf2));
    __hv_zero_f(VOf(Bf7));
    __hv_max_f(VIf(Bf2), VIf(Bf7), VOf(Bf7));
    __hv_floor_f(VIf(Bf7), VOf(Bf2));
    __hv_cast_fi(VIf(Bf2), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_aqpc7o1W, VIi(Bi1), VOf(Bf10));
    __hv_tabread_if(&sTabread_6uYUGrWc, VIi(Bi0), VOf(Bf3));
    __hv_sub_f(VIf(Bf10), VIf(Bf3), VOf(Bf10));
    __hv_sub_f(VIf(Bf7), VIf(Bf2), VOf(Bf2));
    __hv_fma_f(VIf(Bf10), VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_line_f(&sLine_HIEYxg14, VOf(Bf2));
    __hv_mul_f(VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_line_f(&sLine_0dA8JbKr, VOf(Bf3));
    __hv_varread_f(&sVarf_xpi24x7y, VOf(Bf10));
    __hv_mul_f(VIf(Bf3), VIf(Bf10), VOf(Bf10));
    __hv_mul_f(VIf(Bf2), VIf(Bf10), VOf(Bf10));
    __hv_line_f(&sLine_iJIcUm7s, VOf(Bf2));
    __hv_mul_f(VIf(Bf10), VIf(Bf2), VOf(Bf2));
    __hv_line_f(&sLine_wKjUfunQ, VOf(Bf3));
    __hv_mul_f(VIf(Bf10), VIf(Bf3), VOf(Bf3));
    __hv_add_f(VIf(Bf11), VIf(Bf3), VOf(Bf3));
    __hv_add_f(VIf(Bf9), VIf(Bf8), VOf(Bf8));
    __hv_add_f(VIf(Bf8), VIf(Bf4), VOf(Bf4));
    __hv_add_f(VIf(Bf4), VIf(Bf2), VOf(Bf2));
    __hv_line_f(&sLine_nzETJbrO, VOf(Bf4));
    __hv_mul_f(VIf(Bf2), VIf(Bf4), VOf(Bf2));
    __hv_mul_f(VIf(Bf3), VIf(Bf4), VOf(Bf4));
    __hv_line_f(&sLine_QM37Rcsm, VOf(Bf3));
    __hv_mul_f(VIf(Bf0), VIf(Bf3), VOf(Bf3));
    __hv_add_f(VIf(Bf4), VIf(Bf3), VOf(Bf0));
    __hv_add_f(VIf(Bf2), VIf(Bf3), VOf(Bf2));
    __hv_line_f(&sLine_naTWa0RH, VOf(Bf8));
    __hv_mul_f(VIf(Bf0), VIf(Bf8), VOf(Bf0));
    __hv_mul_f(VIf(Bf2), VIf(Bf8), VOf(Bf8));
    __hv_add_f(VIf(Bf4), VIf(Bf3), VOf(Bf3));
    __hv_line_f(&sLine_ZZKNZRLX, VOf(Bf4));
    __hv_mul_f(VIf(Bf3), VIf(Bf4), VOf(Bf4));
    __hv_line_f(&sLine_1gpI2VKu, VOf(Bf3));
    __hv_mul_f(VIf(Bf4), VIf(Bf3), VOf(Bf3));
    __hv_line_f(&sLine_0ZnGXISG, VOf(Bf2));
    __hv_phasor_f(&sPhasor_YshteAh0, VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf9), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf2), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf11), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf9), VIf(Bf11), VOf(Bf11));
    __hv_floor_f(VIf(Bf11), VOf(Bf9));
    __hv_sub_f(VIf(Bf11), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf11), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf9), VIf(Bf11), VOf(Bf11));
    __hv_abs_f(VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf9), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf11), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf11), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf9), VIf(Bf11), VOf(Bf11));
    __hv_mul_f(VIf(Bf11), VIf(Bf11), VOf(Bf9));
    __hv_mul_f(VIf(Bf11), VIf(Bf9), VOf(Bf10));
    __hv_mul_f(VIf(Bf10), VIf(Bf9), VOf(Bf7));
    __hv_mul_f(VIf(Bf7), VIf(Bf9), VOf(Bf5));
    __hv_mul_f(VIf(Bf5), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf1), 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f);
    __hv_var_k_f(VOf(Bf6), 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f);
    __hv_var_k_f(VOf(Bf12), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf10), VIf(Bf12), VOf(Bf12));
    __hv_sub_f(VIf(Bf11), VIf(Bf12), VOf(Bf12));
    __hv_fma_f(VIf(Bf7), VIf(Bf6), VIf(Bf12), VOf(Bf12));
    __hv_var_k_f(VOf(Bf6), 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f);
    __hv_mul_f(VIf(Bf5), VIf(Bf6), VOf(Bf6));
    __hv_sub_f(VIf(Bf12), VIf(Bf6), VOf(Bf6));
    __hv_fma_f(VIf(Bf9), VIf(Bf1), VIf(Bf6), VOf(Bf6));
    __hv_line_f(&sLine_6zA7jM3e, VOf(Bf1));
    __hv_line_f(&sLine_AV6C8lwf, VOf(Bf9));
    __hv_fma_f(VIf(Bf2), VIf(Bf1), VIf(Bf9), VOf(Bf12));
    __hv_tabhead_f(&sTabhead_TpMbhQ1X, VOf(Bf5));
    __hv_var_k_f_r(VOf(Bf7), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf5), VIf(Bf7), VOf(Bf7));
    __hv_varread_f(&sVarf_pymPXy7g, VOf(Bf5));
    __hv_mul_f(VIf(Bf12), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_l3q2gskJ, VOf(Bf12));
    __hv_min_f(VIf(Bf5), VIf(Bf12), VOf(Bf12));
    __hv_zero_f(VOf(Bf5));
    __hv_max_f(VIf(Bf12), VIf(Bf5), VOf(Bf5));
    __hv_sub_f(VIf(Bf7), VIf(Bf5), VOf(Bf5));
    __hv_floor_f(VIf(Bf5), VOf(Bf7));
    __hv_varread_f(&sVarf_xUZp3MPJ, VOf(Bf12));
    __hv_zero_f(VOf(Bf11));
    __hv_lt_f(VIf(Bf7), VIf(Bf11), VOf(Bf11));
    __hv_and_f(VIf(Bf12), VIf(Bf11), VOf(Bf11));
    __hv_add_f(VIf(Bf7), VIf(Bf11), VOf(Bf11));
    __hv_cast_fi(VIf(Bf11), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_f6cXPNu8, VIi(Bi1), VOf(Bf11));
    __hv_tabread_if(&sTabread_mxhuiuoL, VIi(Bi0), VOf(Bf12));
    __hv_sub_f(VIf(Bf11), VIf(Bf12), VOf(Bf11));
    __hv_sub_f(VIf(Bf5), VIf(Bf7), VOf(Bf7));
    __hv_fma_f(VIf(Bf11), VIf(Bf7), VIf(Bf12), VOf(Bf12));
    __hv_var_k_f(VOf(Bf7), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_add_f(VIf(Bf2), VIf(Bf7), VOf(Bf7));
    __hv_floor_f(VIf(Bf7), VOf(Bf2));
    __hv_sub_f(VIf(Bf7), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf7), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf2), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf11), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf7), VIf(Bf11), VOf(Bf11));
    __hv_floor_f(VIf(Bf11), VOf(Bf7));
    __hv_sub_f(VIf(Bf11), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf11), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf7), VIf(Bf11), VOf(Bf11));
    __hv_abs_f(VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf7), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf11), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf11), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf7), VIf(Bf11), VOf(Bf11));
    __hv_mul_f(VIf(Bf11), VIf(Bf11), VOf(Bf7));
    __hv_mul_f(VIf(Bf11), VIf(Bf7), VOf(Bf5));
    __hv_mul_f(VIf(Bf5), VIf(Bf7), VOf(Bf10));
    __hv_mul_f(VIf(Bf10), VIf(Bf7), VOf(Bf13));
    __hv_mul_f(VIf(Bf13), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf14), 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f);
    __hv_var_k_f(VOf(Bf15), 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f);
    __hv_var_k_f(VOf(Bf16), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf5), VIf(Bf16), VOf(Bf16));
    __hv_sub_f(VIf(Bf11), VIf(Bf16), VOf(Bf16));
    __hv_fma_f(VIf(Bf10), VIf(Bf15), VIf(Bf16), VOf(Bf16));
    __hv_var_k_f(VOf(Bf15), 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f);
    __hv_mul_f(VIf(Bf13), VIf(Bf15), VOf(Bf15));
    __hv_sub_f(VIf(Bf16), VIf(Bf15), VOf(Bf15));
    __hv_fma_f(VIf(Bf7), VIf(Bf14), VIf(Bf15), VOf(Bf15));
    __hv_fma_f(VIf(Bf2), VIf(Bf1), VIf(Bf9), VOf(Bf9));
    __hv_tabhead_f(&sTabhead_kFx6KNgb, VOf(Bf1));
    __hv_var_k_f_r(VOf(Bf2), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_JZG5yxNg, VOf(Bf1));
    __hv_mul_f(VIf(Bf9), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_gj6OsYoC, VOf(Bf9));
    __hv_min_f(VIf(Bf1), VIf(Bf9), VOf(Bf9));
    __hv_zero_f(VOf(Bf1));
    __hv_max_f(VIf(Bf9), VIf(Bf1), VOf(Bf1));
    __hv_sub_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_floor_f(VIf(Bf1), VOf(Bf2));
    __hv_varread_f(&sVarf_VPA9eOP7, VOf(Bf9));
    __hv_zero_f(VOf(Bf14));
    __hv_lt_f(VIf(Bf2), VIf(Bf14), VOf(Bf14));
    __hv_and_f(VIf(Bf9), VIf(Bf14), VOf(Bf14));
    __hv_add_f(VIf(Bf2), VIf(Bf14), VOf(Bf14));
    __hv_cast_fi(VIf(Bf14), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_WSZyb2A2, VIi(Bi1), VOf(Bf14));
    __hv_tabread_if(&sTabread_rq9uXTGZ, VIi(Bi0), VOf(Bf9));
    __hv_sub_f(VIf(Bf14), VIf(Bf9), VOf(Bf14));
    __hv_sub_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_fma_f(VIf(Bf14), VIf(Bf2), VIf(Bf9), VOf(Bf9));
    __hv_mul_f(VIf(Bf15), VIf(Bf9), VOf(Bf9));
    __hv_fma_f(VIf(Bf6), VIf(Bf12), VIf(Bf9), VOf(Bf9));
    __hv_tabwrite_f(&sTabwrite_68ZEmoet, VIf(Bf3));
    __hv_line_f(&sLine_JxCbhdLP, VOf(Bf3));
    __hv_varread_f(&sVarf_lm1HusbR, VOf(Bf12));
    __hv_tabhead_f(&sTabhead_pi8hVpWZ, VOf(Bf6));
    __hv_var_k_f_r(VOf(Bf15), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf6), VIf(Bf15), VOf(Bf15));
    __hv_varread_f(&sVarf_BvHUiFWi, VOf(Bf6));
    __hv_mul_f(VIf(Bf12), VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_eOHSLqSm, VOf(Bf12));
    __hv_min_f(VIf(Bf6), VIf(Bf12), VOf(Bf12));
    __hv_zero_f(VOf(Bf6));
    __hv_max_f(VIf(Bf12), VIf(Bf6), VOf(Bf6));
    __hv_sub_f(VIf(Bf15), VIf(Bf6), VOf(Bf6));
    __hv_floor_f(VIf(Bf6), VOf(Bf15));
    __hv_varread_f(&sVarf_vqZaoEA2, VOf(Bf12));
    __hv_zero_f(VOf(Bf2));
    __hv_lt_f(VIf(Bf15), VIf(Bf2), VOf(Bf2));
    __hv_and_f(VIf(Bf12), VIf(Bf2), VOf(Bf2));
    __hv_add_f(VIf(Bf15), VIf(Bf2), VOf(Bf2));
    __hv_cast_fi(VIf(Bf2), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_zi5qKH5S, VIi(Bi1), VOf(Bf2));
    __hv_tabread_if(&sTabread_EV9mrtn6, VIi(Bi0), VOf(Bf12));
    __hv_sub_f(VIf(Bf2), VIf(Bf12), VOf(Bf2));
    __hv_sub_f(VIf(Bf6), VIf(Bf15), VOf(Bf15));
    __hv_fma_f(VIf(Bf2), VIf(Bf15), VIf(Bf12), VOf(Bf12));
    __hv_varread_f(&sVarf_4hlqXWkV, VOf(Bf15));
    __hv_rpole_f(&sRPole_mDpKj3Vn, VIf(Bf12), VIf(Bf15), VOf(Bf15));
    __hv_var_k_f(VOf(Bf12), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_del1_f(&sDel1_YhQaLXkj, VIf(Bf15), VOf(Bf2));
    __hv_mul_f(VIf(Bf2), VIf(Bf12), VOf(Bf12));
    __hv_sub_f(VIf(Bf15), VIf(Bf12), VOf(Bf12));
    __hv_varread_f(&sVarf_Rf6pjyZ3, VOf(Bf15));
    __hv_mul_f(VIf(Bf12), VIf(Bf15), VOf(Bf15));
    __hv_varread_f(&sVarf_S5frDtKM, VOf(Bf12));
    __hv_mul_f(VIf(Bf15), VIf(Bf12), VOf(Bf12));
    __hv_varread_f(&sVarf_phgJDijJ, VOf(Bf15));
    __hv_mul_f(VIf(Bf12), VIf(Bf15), VOf(Bf15));
    __hv_varread_f(&sVarf_dcmGhIc0, VOf(Bf2));
    __hv_rpole_f(&sRPole_bL1DfBh9, VIf(Bf15), VIf(Bf2), VOf(Bf2));
    __hv_fma_f(VIf(Bf9), VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_tabwrite_f(&sTabwrite_fO5JNITB, VIf(Bf2));
    __hv_add_f(VIf(Bf9), VIf(Bf12), VOf(Bf12));
    __hv_var_k_f(VOf(Bf9), 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f);
    __hv_mul_f(VIf(Bf12), VIf(Bf9), VOf(Bf9));
    __hv_tabread_f(&sTabread_UMAlHkrX, VOf(Bf12));
    __hv_varread_f(&sVarf_khHH09UD, VOf(Bf2));
    __hv_mul_f(VIf(Bf12), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_XGtlPRgZ, VOf(Bf3));
    __hv_rpole_f(&sRPole_Us9d778h, VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_sub_f(VIf(Bf3), VIf(Bf12), VOf(Bf3));
    __hv_line_f(&sLine_LW9JeSpj, VOf(Bf2));
    __hv_fma_f(VIf(Bf3), VIf(Bf2), VIf(Bf12), VOf(Bf12));
    __hv_line_f(&sLine_KmqMAnhB, VOf(Bf3));
    __hv_mul_f(VIf(Bf12), VIf(Bf3), VOf(Bf12));
    __hv_line_f(&sLine_zd8iUYEN, VOf(Bf15));
    __hv_mul_f(VIf(Bf12), VIf(Bf15), VOf(Bf6));
    __hv_tabread_f(&sTabread_Mf3ytb18, VOf(Bf14));
    __hv_varread_f(&sVarf_5AQtq8SZ, VOf(Bf1));
    __hv_mul_f(VIf(Bf14), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_rJYLNPto, VOf(Bf7));
    __hv_rpole_f(&sRPole_veFf5zJg, VIf(Bf1), VIf(Bf7), VOf(Bf7));
    __hv_sub_f(VIf(Bf7), VIf(Bf14), VOf(Bf7));
    __hv_fma_f(VIf(Bf7), VIf(Bf2), VIf(Bf14), VOf(Bf14));
    __hv_tabread_f(&sTabread_v5M3Sot5, VOf(Bf7));
    __hv_add_f(VIf(Bf4), VIf(Bf7), VOf(Bf1));
    __hv_tabread_f(&sTabread_9oR6lA7J, VOf(Bf16));
    __hv_sub_f(VIf(Bf1), VIf(Bf16), VOf(Bf13));
    __hv_tabwrite_f(&sTabwrite_KVJjR7db, VIf(Bf13));
    __hv_tabwrite_f(&sTabwrite_rYsjrFF2, VIf(Bf4));
    __hv_tabread_f(&sTabread_xVPC2oxR, VOf(Bf13));
    __hv_add_f(VIf(Bf1), VIf(Bf16), VOf(Bf16));
    __hv_tabread_f(&sTabread_O6jFGsul, VOf(Bf1));
    __hv_add_f(VIf(Bf16), VIf(Bf1), VOf(Bf10));
    __hv_tabread_f(&sTabread_NIIx5kU1, VOf(Bf11));
    __hv_add_f(VIf(Bf10), VIf(Bf11), VOf(Bf5));
    __hv_tabread_f(&sTabread_AgyAQgdX, VOf(Bf17));
    __hv_sub_f(VIf(Bf5), VIf(Bf17), VOf(Bf18));
    __hv_tabwrite_f(&sTabwrite_Z9aUjTyP, VIf(Bf18));
    __hv_sub_f(VIf(Bf16), VIf(Bf1), VOf(Bf1));
    __hv_tabwrite_f(&sTabwrite_IxL6w6Y4, VIf(Bf1));
    __hv_sub_f(VIf(Bf10), VIf(Bf11), VOf(Bf11));
    __hv_tabwrite_f(&sTabwrite_z6VSE2bb, VIf(Bf11));
    __hv_add_f(VIf(Bf5), VIf(Bf17), VOf(Bf17));
    __hv_sub_f(VIf(Bf4), VIf(Bf7), VOf(Bf7));
    __hv_tabwrite_f(&sTabwrite_xAmeylLP, VIf(Bf7));
    __hv_fma_f(VIf(Bf14), VIf(Bf3), VIf(Bf17), VOf(Bf17));
    __hv_tabread_f(&sTabread_95dkUskH, VOf(Bf14));
    __hv_varread_f(&sVarf_6GXKnDCJ, VOf(Bf7));
    __hv_mul_f(VIf(Bf14), VIf(Bf7), VOf(Bf7));
    __hv_varread_f(&sVarf_EdSrWJPJ, VOf(Bf5));
    __hv_rpole_f(&sRPole_wtHNLpvF, VIf(Bf7), VIf(Bf5), VOf(Bf5));
    __hv_sub_f(VIf(Bf5), VIf(Bf14), VOf(Bf5));
    __hv_fma_f(VIf(Bf5), VIf(Bf2), VIf(Bf14), VOf(Bf14));
    __hv_fma_f(VIf(Bf14), VIf(Bf3), VIf(Bf13), VOf(Bf13));
    __hv_add_f(VIf(Bf17), VIf(Bf13), VOf(Bf14));
    __hv_tabread_f(&sTabread_A7NRdDRo, VOf(Bf5));
    __hv_varread_f(&sVarf_cMXIMxQ6, VOf(Bf7));
    __hv_mul_f(VIf(Bf5), VIf(Bf7), VOf(Bf7));
    __hv_varread_f(&sVarf_HkIt0OkD, VOf(Bf11));
    __hv_rpole_f(&sRPole_55b4L959, VIf(Bf7), VIf(Bf11), VOf(Bf11));
    __hv_sub_f(VIf(Bf11), VIf(Bf5), VOf(Bf11));
    __hv_fma_f(VIf(Bf11), VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_mul_f(VIf(Bf5), VIf(Bf3), VOf(Bf3));
    __hv_add_f(VIf(Bf12), VIf(Bf3), VOf(Bf5));
    __hv_add_f(VIf(Bf14), VIf(Bf5), VOf(Bf2));
    __hv_tabwrite_f(&sTabwrite_tI1NGy9l, VIf(Bf2));
    __hv_mul_f(VIf(Bf13), VIf(Bf15), VOf(Bf2));
    __hv_mul_f(VIf(Bf3), VIf(Bf15), VOf(Bf11));
    __hv_mul_f(VIf(Bf17), VIf(Bf15), VOf(Bf15));
    __hv_sub_f(VIf(Bf17), VIf(Bf13), VOf(Bf13));
    __hv_sub_f(VIf(Bf12), VIf(Bf3), VOf(Bf3));
    __hv_sub_f(VIf(Bf13), VIf(Bf3), VOf(Bf12));
    __hv_tabwrite_f(&sTabwrite_FOWYkAfr, VIf(Bf12));
    __hv_add_f(VIf(Bf13), VIf(Bf3), VOf(Bf3));
    __hv_tabwrite_f(&sTabwrite_9qK970t4, VIf(Bf3));
    __hv_sub_f(VIf(Bf14), VIf(Bf5), VOf(Bf5));
    __hv_tabwrite_f(&sTabwrite_PUK5OSPa, VIf(Bf5));
    __hv_add_f(VIf(Bf9), VIf(Bf2), VOf(Bf2));
    __hv_line_f(&sLine_8gj0B0K3, VOf(Bf11));
    __hv_mul_f(VIf(Bf4), VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf4), 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f);
    __hv_mul_f(VIf(Bf11), VIf(Bf4), VOf(Bf4));
    __hv_tabwrite_f(&sTabwrite_M5vsPrLF, VIf(Bf4));
    __hv_line_f(&sLine_cSvxiMqk, VOf(Bf11));
    __hv_phasor_f(&sPhasor_t8WTNE9t, VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf6), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf11), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf5), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf6), VIf(Bf5), VOf(Bf5));
    __hv_floor_f(VIf(Bf5), VOf(Bf6));
    __hv_sub_f(VIf(Bf5), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf5), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf6), VIf(Bf5), VOf(Bf5));
    __hv_abs_f(VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf6), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf5), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf5), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf6), VIf(Bf5), VOf(Bf5));
    __hv_mul_f(VIf(Bf5), VIf(Bf5), VOf(Bf6));
    __hv_mul_f(VIf(Bf5), VIf(Bf6), VOf(Bf14));
    __hv_mul_f(VIf(Bf14), VIf(Bf6), VOf(Bf3));
    __hv_mul_f(VIf(Bf3), VIf(Bf6), VOf(Bf13));
    __hv_mul_f(VIf(Bf13), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf12), 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f);
    __hv_var_k_f(VOf(Bf17), 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f);
    __hv_var_k_f(VOf(Bf7), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf14), VIf(Bf7), VOf(Bf7));
    __hv_sub_f(VIf(Bf5), VIf(Bf7), VOf(Bf7));
    __hv_fma_f(VIf(Bf3), VIf(Bf17), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf17), 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f);
    __hv_mul_f(VIf(Bf13), VIf(Bf17), VOf(Bf17));
    __hv_sub_f(VIf(Bf7), VIf(Bf17), VOf(Bf17));
    __hv_fma_f(VIf(Bf6), VIf(Bf12), VIf(Bf17), VOf(Bf17));
    __hv_line_f(&sLine_w64ryzUm, VOf(Bf12));
    __hv_line_f(&sLine_qhyBzUUM, VOf(Bf6));
    __hv_fma_f(VIf(Bf11), VIf(Bf12), VIf(Bf6), VOf(Bf7));
    __hv_tabhead_f(&sTabhead_XfKTIjIk, VOf(Bf13));
    __hv_var_k_f_r(VOf(Bf3), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf13), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_2LRolcvh, VOf(Bf13));
    __hv_mul_f(VIf(Bf7), VIf(Bf13), VOf(Bf13));
    __hv_varread_f(&sVarf_krc7fk4O, VOf(Bf7));
    __hv_min_f(VIf(Bf13), VIf(Bf7), VOf(Bf7));
    __hv_zero_f(VOf(Bf13));
    __hv_max_f(VIf(Bf7), VIf(Bf13), VOf(Bf13));
    __hv_sub_f(VIf(Bf3), VIf(Bf13), VOf(Bf13));
    __hv_floor_f(VIf(Bf13), VOf(Bf3));
    __hv_varread_f(&sVarf_C9TD0mPy, VOf(Bf7));
    __hv_zero_f(VOf(Bf5));
    __hv_lt_f(VIf(Bf3), VIf(Bf5), VOf(Bf5));
    __hv_and_f(VIf(Bf7), VIf(Bf5), VOf(Bf5));
    __hv_add_f(VIf(Bf3), VIf(Bf5), VOf(Bf5));
    __hv_cast_fi(VIf(Bf5), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_DOoKdRAh, VIi(Bi1), VOf(Bf5));
    __hv_tabread_if(&sTabread_Oadm9wkv, VIi(Bi0), VOf(Bf7));
    __hv_sub_f(VIf(Bf5), VIf(Bf7), VOf(Bf5));
    __hv_sub_f(VIf(Bf13), VIf(Bf3), VOf(Bf3));
    __hv_fma_f(VIf(Bf5), VIf(Bf3), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf3), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_add_f(VIf(Bf11), VIf(Bf3), VOf(Bf3));
    __hv_floor_f(VIf(Bf3), VOf(Bf11));
    __hv_sub_f(VIf(Bf3), VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf3), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf11), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf5), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf3), VIf(Bf5), VOf(Bf5));
    __hv_floor_f(VIf(Bf5), VOf(Bf3));
    __hv_sub_f(VIf(Bf5), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf5), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf3), VIf(Bf5), VOf(Bf5));
    __hv_abs_f(VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf3), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf5), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf5), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf3), VIf(Bf5), VOf(Bf5));
    __hv_mul_f(VIf(Bf5), VIf(Bf5), VOf(Bf3));
    __hv_mul_f(VIf(Bf5), VIf(Bf3), VOf(Bf13));
    __hv_mul_f(VIf(Bf13), VIf(Bf3), VOf(Bf14));
    __hv_mul_f(VIf(Bf14), VIf(Bf3), VOf(Bf10));
    __hv_mul_f(VIf(Bf10), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf1), 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f);
    __hv_var_k_f(VOf(Bf16), 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f);
    __hv_var_k_f(VOf(Bf18), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf13), VIf(Bf18), VOf(Bf18));
    __hv_sub_f(VIf(Bf5), VIf(Bf18), VOf(Bf18));
    __hv_fma_f(VIf(Bf14), VIf(Bf16), VIf(Bf18), VOf(Bf18));
    __hv_var_k_f(VOf(Bf16), 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f);
    __hv_mul_f(VIf(Bf10), VIf(Bf16), VOf(Bf16));
    __hv_sub_f(VIf(Bf18), VIf(Bf16), VOf(Bf16));
    __hv_fma_f(VIf(Bf3), VIf(Bf1), VIf(Bf16), VOf(Bf16));
    __hv_fma_f(VIf(Bf11), VIf(Bf12), VIf(Bf6), VOf(Bf6));
    __hv_tabhead_f(&sTabhead_nM3OwlwO, VOf(Bf12));
    __hv_var_k_f_r(VOf(Bf11), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf12), VIf(Bf11), VOf(Bf11));
    __hv_varread_f(&sVarf_p1jGECpz, VOf(Bf12));
    __hv_mul_f(VIf(Bf6), VIf(Bf12), VOf(Bf12));
    __hv_varread_f(&sVarf_ZSHKmGzo, VOf(Bf6));
    __hv_min_f(VIf(Bf12), VIf(Bf6), VOf(Bf6));
    __hv_zero_f(VOf(Bf12));
    __hv_max_f(VIf(Bf6), VIf(Bf12), VOf(Bf12));
    __hv_sub_f(VIf(Bf11), VIf(Bf12), VOf(Bf12));
    __hv_floor_f(VIf(Bf12), VOf(Bf11));
    __hv_varread_f(&sVarf_EiBAcfDc, VOf(Bf6));
    __hv_zero_f(VOf(Bf1));
    __hv_lt_f(VIf(Bf11), VIf(Bf1), VOf(Bf1));
    __hv_and_f(VIf(Bf6), VIf(Bf1), VOf(Bf1));
    __hv_add_f(VIf(Bf11), VIf(Bf1), VOf(Bf1));
    __hv_cast_fi(VIf(Bf1), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_DLCdY9pw, VIi(Bi1), VOf(Bf1));
    __hv_tabread_if(&sTabread_elfAU654, VIi(Bi0), VOf(Bf6));
    __hv_sub_f(VIf(Bf1), VIf(Bf6), VOf(Bf1));
    __hv_sub_f(VIf(Bf12), VIf(Bf11), VOf(Bf11));
    __hv_fma_f(VIf(Bf1), VIf(Bf11), VIf(Bf6), VOf(Bf6));
    __hv_mul_f(VIf(Bf16), VIf(Bf6), VOf(Bf6));
    __hv_fma_f(VIf(Bf17), VIf(Bf7), VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_hmWBbNn7, VOf(Bf7));
    __hv_tabhead_f(&sTabhead_PI9lMAug, VOf(Bf17));
    __hv_var_k_f_r(VOf(Bf16), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf17), VIf(Bf16), VOf(Bf16));
    __hv_varread_f(&sVarf_h9b0vrTz, VOf(Bf17));
    __hv_mul_f(VIf(Bf7), VIf(Bf17), VOf(Bf17));
    __hv_varread_f(&sVarf_HpEo7pyO, VOf(Bf7));
    __hv_min_f(VIf(Bf17), VIf(Bf7), VOf(Bf7));
    __hv_zero_f(VOf(Bf17));
    __hv_max_f(VIf(Bf7), VIf(Bf17), VOf(Bf17));
    __hv_sub_f(VIf(Bf16), VIf(Bf17), VOf(Bf17));
    __hv_floor_f(VIf(Bf17), VOf(Bf16));
    __hv_varread_f(&sVarf_3YLMKCtN, VOf(Bf7));
    __hv_zero_f(VOf(Bf11));
    __hv_lt_f(VIf(Bf16), VIf(Bf11), VOf(Bf11));
    __hv_and_f(VIf(Bf7), VIf(Bf11), VOf(Bf11));
    __hv_add_f(VIf(Bf16), VIf(Bf11), VOf(Bf11));
    __hv_cast_fi(VIf(Bf11), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_nrhM4q20, VIi(Bi1), VOf(Bf11));
    __hv_tabread_if(&sTabread_GnS6mRac, VIi(Bi0), VOf(Bf7));
    __hv_sub_f(VIf(Bf11), VIf(Bf7), VOf(Bf11));
    __hv_sub_f(VIf(Bf17), VIf(Bf16), VOf(Bf16));
    __hv_fma_f(VIf(Bf11), VIf(Bf16), VIf(Bf7), VOf(Bf7));
    __hv_varread_f(&sVarf_d18kc4ju, VOf(Bf16));
    __hv_rpole_f(&sRPole_20ttpJ0R, VIf(Bf7), VIf(Bf16), VOf(Bf16));
    __hv_var_k_f(VOf(Bf7), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_del1_f(&sDel1_tHRbrtx4, VIf(Bf16), VOf(Bf11));
    __hv_mul_f(VIf(Bf11), VIf(Bf7), VOf(Bf7));
    __hv_sub_f(VIf(Bf16), VIf(Bf7), VOf(Bf7));
    __hv_varread_f(&sVarf_aOyNmdiR, VOf(Bf16));
    __hv_mul_f(VIf(Bf7), VIf(Bf16), VOf(Bf16));
    __hv_varread_f(&sVarf_o6PpaNAI, VOf(Bf7));
    __hv_mul_f(VIf(Bf16), VIf(Bf7), VOf(Bf7));
    __hv_add_f(VIf(Bf6), VIf(Bf7), VOf(Bf16));
    __hv_line_f(&sLine_v8wXUZlu, VOf(Bf11));
    __hv_varread_f(&sVarf_VmXj2GYM, VOf(Bf17));
    __hv_mul_f(VIf(Bf7), VIf(Bf17), VOf(Bf17));
    __hv_varread_f(&sVarf_ToQ7iRm0, VOf(Bf7));
    __hv_rpole_f(&sRPole_V5SmtTvk, VIf(Bf17), VIf(Bf7), VOf(Bf7));
    __hv_fma_f(VIf(Bf6), VIf(Bf11), VIf(Bf7), VOf(Bf7));
    __hv_tabwrite_f(&sTabwrite_dW9XFL9Q, VIf(Bf7));
    __hv_add_f(VIf(Bf16), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_bJgA5bbd, VOf(Bf16));
    __hv_varread_f(&sVarf_iYpB7zhT, VOf(Bf7));
    __hv_mul_f(VIf(Bf16), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf16), 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f);
    __hv_max_f(VIf(Bf7), VIf(Bf16), VOf(Bf16));
    __hv_varread_f(&sVarf_hs5c8nL0, VOf(Bf7));
    __hv_min_f(VIf(Bf16), VIf(Bf7), VOf(Bf7));
    __hv_varread_f(&sVarf_JkevEWcv, VOf(Bf11));
    __hv_mul_f(VIf(Bf7), VIf(Bf11), VOf(Bf11));
    __hv_mul_f(VIf(Bf4), VIf(Bf11), VOf(Bf4));
    __hv_varread_f(&sVarf_gszK72BP, VOf(Bf7));
    __hv_mul_f(VIf(Bf4), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf4), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_sub_f(VIf(Bf11), VIf(Bf4), VOf(Bf11));
    __hv_cos_f(VIf(Bf16), VOf(Bf16));
    __hv_mul_f(VIf(Bf11), VIf(Bf16), VOf(Bf6));
    __hv_mul_f(VIf(Bf16), VIf(Bf16), VOf(Bf16));
    __hv_sub_f(VIf(Bf4), VIf(Bf16), VOf(Bf16));
    __hv_zero_f(VOf(Bf4));
    __hv_gt_f(VIf(Bf16), VIf(Bf4), VOf(Bf4));
    __hv_sqrt_f(VIf(Bf16), VOf(Bf16));
    __hv_and_f(VIf(Bf4), VIf(Bf16), VOf(Bf16));
    __hv_mul_f(VIf(Bf11), VIf(Bf16), VOf(Bf16));
    __hv_cpole_f(&sCPole_v6gO6sOD, VIf(Bf7), VIf(ZERO), VIf(Bf6), VIf(Bf16), VOf(Bf16), VOf(Bf6));
    __hv_varread_f(&sVarf_kWAJOmwx, VOf(Bf6));
    __hv_mul_f(VIf(Bf16), VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_Yh1CU5cO, VOf(Bf16));
    __hv_rpole_f(&sRPole_y4od3lLR, VIf(Bf6), VIf(Bf16), VOf(Bf16));
    __hv_varread_f(&sVarf_0T93HxmZ, VOf(Bf6));
    __hv_mul_f(VIf(Bf16), VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_g2lHkJLb, VOf(Bf16));
    __hv_rpole_f(&sRPole_Gr7onzoU, VIf(Bf6), VIf(Bf16), VOf(Bf16));
    __hv_varread_f(&sVarf_Gcz4I6Xl, VOf(Bf6));
    __hv_mul_f(VIf(Bf16), VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_DNLO2Q6E, VOf(Bf16));
    __hv_rpole_f(&sRPole_BYP0Zdhu, VIf(Bf6), VIf(Bf16), VOf(Bf16));
    __hv_tabread_f(&sTabread_zDIEk0mR, VOf(Bf6));
    __hv_varread_f(&sVarf_YcnS4ewy, VOf(Bf7));
    __hv_mul_f(VIf(Bf6), VIf(Bf7), VOf(Bf7));
    __hv_varread_f(&sVarf_0hSBxe28, VOf(Bf11));
    __hv_rpole_f(&sRPole_jaBpt9ud, VIf(Bf7), VIf(Bf11), VOf(Bf11));
    __hv_sub_f(VIf(Bf11), VIf(Bf6), VOf(Bf11));
    __hv_line_f(&sLine_uC2DT64B, VOf(Bf7));
    __hv_fma_f(VIf(Bf11), VIf(Bf7), VIf(Bf6), VOf(Bf6));
    __hv_line_f(&sLine_uRHIqJbV, VOf(Bf11));
    __hv_tabread_f(&sTabread_Y9CraDEf, VOf(Bf4));
    __hv_add_f(VIf(Bf16), VIf(Bf4), VOf(Bf17));
    __hv_tabread_f(&sTabread_xXzVRiLA, VOf(Bf1));
    __hv_add_f(VIf(Bf17), VIf(Bf1), VOf(Bf12));
    __hv_tabread_f(&sTabread_nDccIDmw, VOf(Bf3));
    __hv_add_f(VIf(Bf12), VIf(Bf3), VOf(Bf18));
    __hv_tabread_f(&sTabread_fNPHlwMm, VOf(Bf10));
    __hv_add_f(VIf(Bf18), VIf(Bf10), VOf(Bf14));
    __hv_tabread_f(&sTabread_O8Nzf9kN, VOf(Bf5));
    __hv_add_f(VIf(Bf14), VIf(Bf5), VOf(Bf13));
    __hv_tabread_f(&sTabread_KTLNUQgj, VOf(Bf19));
    __hv_tabwrite_f(&sTabwrite_npESjic7, VIf(Bf16));
    __hv_sub_f(VIf(Bf16), VIf(Bf4), VOf(Bf4));
    __hv_tabwrite_f(&sTabwrite_UmNdxsVV, VIf(Bf4));
    __hv_sub_f(VIf(Bf18), VIf(Bf10), VOf(Bf10));
    __hv_tabwrite_f(&sTabwrite_qgO6IXfk, VIf(Bf10));
    __hv_sub_f(VIf(Bf12), VIf(Bf3), VOf(Bf3));
    __hv_tabwrite_f(&sTabwrite_SEgP4thX, VIf(Bf3));
    __hv_sub_f(VIf(Bf17), VIf(Bf1), VOf(Bf1));
    __hv_tabwrite_f(&sTabwrite_h4UbNH6N, VIf(Bf1));
    __hv_sub_f(VIf(Bf14), VIf(Bf5), VOf(Bf5));
    __hv_tabwrite_f(&sTabwrite_WNGsvgTv, VIf(Bf5));
    __hv_fma_f(VIf(Bf6), VIf(Bf11), VIf(Bf13), VOf(Bf13));
    __hv_line_f(&sLine_UaDf2nKt, VOf(Bf6));
    __hv_mul_f(VIf(Bf13), VIf(Bf6), VOf(Bf5));
    __hv_tabread_f(&sTabread_287b4oh5, VOf(Bf14));
    __hv_varread_f(&sVarf_e1f2eTK1, VOf(Bf1));
    __hv_mul_f(VIf(Bf14), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_8luTeCv1, VOf(Bf17));
    __hv_rpole_f(&sRPole_6QmZHFgI, VIf(Bf1), VIf(Bf17), VOf(Bf17));
    __hv_sub_f(VIf(Bf17), VIf(Bf14), VOf(Bf17));
    __hv_fma_f(VIf(Bf17), VIf(Bf7), VIf(Bf14), VOf(Bf14));
    __hv_mul_f(VIf(Bf14), VIf(Bf11), VOf(Bf14));
    __hv_mul_f(VIf(Bf14), VIf(Bf6), VOf(Bf17));
    __hv_tabread_f(&sTabread_fHBE5zox, VOf(Bf1));
    __hv_varread_f(&sVarf_PmTLRsbz, VOf(Bf3));
    __hv_mul_f(VIf(Bf1), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_dwUu67ZV, VOf(Bf12));
    __hv_rpole_f(&sRPole_KnqFbkkZ, VIf(Bf3), VIf(Bf12), VOf(Bf12));
    __hv_sub_f(VIf(Bf12), VIf(Bf1), VOf(Bf12));
    __hv_fma_f(VIf(Bf12), VIf(Bf7), VIf(Bf1), VOf(Bf1));
    __hv_fma_f(VIf(Bf1), VIf(Bf11), VIf(Bf19), VOf(Bf19));
    __hv_mul_f(VIf(Bf19), VIf(Bf6), VOf(Bf1));
    __hv_tabread_f(&sTabread_XgM7MCjD, VOf(Bf12));
    __hv_varread_f(&sVarf_Xpj6GjZf, VOf(Bf3));
    __hv_mul_f(VIf(Bf12), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_JXDtWNO1, VOf(Bf10));
    __hv_rpole_f(&sRPole_lK7oXdFn, VIf(Bf3), VIf(Bf10), VOf(Bf10));
    __hv_sub_f(VIf(Bf10), VIf(Bf12), VOf(Bf10));
    __hv_fma_f(VIf(Bf10), VIf(Bf7), VIf(Bf12), VOf(Bf12));
    __hv_mul_f(VIf(Bf12), VIf(Bf11), VOf(Bf11));
    __hv_mul_f(VIf(Bf11), VIf(Bf6), VOf(Bf6));
    __hv_add_f(VIf(Bf13), VIf(Bf19), VOf(Bf12));
    __hv_add_f(VIf(Bf11), VIf(Bf14), VOf(Bf7));
    __hv_sub_f(VIf(Bf12), VIf(Bf7), VOf(Bf10));
    __hv_tabwrite_f(&sTabwrite_NiAwcgbj, VIf(Bf10));
    __hv_add_f(VIf(Bf12), VIf(Bf7), VOf(Bf7));
    __hv_tabwrite_f(&sTabwrite_bdfczrHz, VIf(Bf7));
    __hv_sub_f(VIf(Bf13), VIf(Bf19), VOf(Bf19));
    __hv_sub_f(VIf(Bf11), VIf(Bf14), VOf(Bf14));
    __hv_sub_f(VIf(Bf19), VIf(Bf14), VOf(Bf11));
    __hv_tabwrite_f(&sTabwrite_eo3i8s4D, VIf(Bf11));
    __hv_add_f(VIf(Bf19), VIf(Bf14), VOf(Bf14));
    __hv_tabwrite_f(&sTabwrite_TvRTzorQ, VIf(Bf14));
    __hv_add_f(VIf(Bf16), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf16), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf5), VIf(Bf16), VOf(Bf16));
    __hv_add_f(VIf(Bf2), VIf(Bf16), VOf(Bf2));
    __hv_add_f(VIf(Bf9), VIf(Bf15), VOf(Bf15));
    __hv_add_f(VIf(Bf15), VIf(Bf16), VOf(Bf16));
    __hv_line_f(&sLine_HUDYAN2U, VOf(Bf15));
    __hv_mul_f(VIf(Bf16), VIf(Bf15), VOf(Bf16));
    __hv_mul_f(VIf(Bf2), VIf(Bf15), VOf(Bf15));
    __hv_add_f(VIf(Bf0), VIf(Bf16), VOf(Bf16));
    __hv_add_f(VIf(Bf8), VIf(Bf15), VOf(Bf15));
    __hv_line_f(&sLine_xVktYncJ, VOf(Bf8));
    __hv_mul_f(VIf(Bf16), VIf(Bf8), VOf(Bf16));
    __hv_mul_f(VIf(Bf15), VIf(Bf8), VOf(Bf8));
    __hv_add_f(VIf(Bf8), VIf(O1), VOf(O1));
    __hv_add_f(VIf(Bf16), VIf(O0), VOf(O0));

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

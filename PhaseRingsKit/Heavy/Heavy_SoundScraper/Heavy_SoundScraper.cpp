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
  numBytes += sPhasor_k_init(&sPhasor_iMoLKRsm, 0.0f, sampleRate);
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
  numBytes += sPhasor_init(&sPhasor_gvfGqYF2, sampleRate);
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
  numBytes += sPhasor_init(&sPhasor_ZhjAi2ej, sampleRate);
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
  numBytes += cBinop_init(&cBinop_T4gOq49j, 0.0f); // __pow
  numBytes += cPack_init(&cPack_JMWa4cFu, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_PPwh3jr2, 0.0f);
  numBytes += cRandom_init(&cRandom_Y94JPdTL, 1479280588);
  numBytes += cSlice_init(&cSlice_82fhNWaF, 1, 1);
  numBytes += cBinop_init(&cBinop_BHxpRmB8, 1.0f); // __pow
  numBytes += cRandom_init(&cRandom_E5MjjYrs, 1107905724);
  numBytes += cSlice_init(&cSlice_3qs68nzi, 1, 1);
  numBytes += cSlice_init(&cSlice_GwyReTK2, 1, 1);
  numBytes += cSlice_init(&cSlice_8a9gRL90, 0, 1);
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
  numBytes += cBinop_init(&cBinop_nb6VTrFm, 0.0f); // __div
  numBytes += cSlice_init(&cSlice_bIRRz79x, 1, 1);
  numBytes += cSlice_init(&cSlice_qcBgEtaq, 0, 1);
  numBytes += cVar_init_s(&cVar_sTYvRhZ9, "1013_default");
  numBytes += cSlice_init(&cSlice_rp4aa40z, 1, 1);
  numBytes += sVarf_init(&sVarf_HgSXPSnM, 0.0f, 0.0f, false);
  numBytes += cSlice_init(&cSlice_BcSVFyaO, 1, 1);
  numBytes += cSlice_init(&cSlice_VHV4oP1k, 0, 1);
  numBytes += cVar_init_s(&cVar_EqloIxkt, "floatatom");
  numBytes += cVar_init_s(&cVar_roaFw89G, "floatatom");
  numBytes += hTable_init(&hTable_AKQw9gB5, 1000);
  numBytes += cSlice_init(&cSlice_Hd8hM02e, 1, 1);
  numBytes += cSlice_init(&cSlice_ubdBPvp7, 0, 1);
  numBytes += cVar_init_f(&cVar_KXcAfqmU, 0.0f);
  numBytes += cPack_init(&cPack_2AeIl7oo, 2, 0.0f, 0.0f);
  numBytes += cBinop_init(&cBinop_MUthzqlo, 1.0f); // __mul
  numBytes += cBinop_init(&cBinop_dFGGLTVi, 0.0f); // __div
  numBytes += cRandom_init(&cRandom_FS4owC4a, -341142462);
  numBytes += cSlice_init(&cSlice_kwUSvw2u, 1, 1);
  numBytes += cBinop_init(&cBinop_mq5joYsZ, 1.0f); // __pow
  numBytes += cRandom_init(&cRandom_znEJCKP6, -1035444672);
  numBytes += cSlice_init(&cSlice_ZcejJIy1, 1, 1);
  numBytes += cSlice_init(&cSlice_iVcBj2d4, 1, 1);
  numBytes += cSlice_init(&cSlice_5qKhvvY8, 0, 1);
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
  numBytes += cBinop_init(&cBinop_iiTUjhp9, 0.0f); // __div
  numBytes += cSlice_init(&cSlice_Uyt9Kp3d, 1, 1);
  numBytes += cSlice_init(&cSlice_GkIAmfP8, 0, 1);
  numBytes += cVar_init_s(&cVar_UyoDPMGJ, "1051_default");
  numBytes += cSlice_init(&cSlice_SYuu5iYJ, 1, 1);
  numBytes += sVarf_init(&sVarf_bgDUH05l, 0.0f, 0.0f, false);
  numBytes += cSlice_init(&cSlice_kdQjtT8p, 1, 1);
  numBytes += cSlice_init(&cSlice_SeWjqHEN, 0, 1);
  numBytes += cVar_init_s(&cVar_9zT65X1L, "floatatom");
  numBytes += cVar_init_s(&cVar_Ek55gQhE, "floatatom");
  numBytes += hTable_init(&hTable_qTT30gQb, 1000);
  numBytes += cSlice_init(&cSlice_IQg9xqrX, 1, 1);
  numBytes += cSlice_init(&cSlice_hAc6aAxe, 0, 1);
  numBytes += cVar_init_f(&cVar_U4JpgUYy, 0.0f);
  numBytes += cPack_init(&cPack_jqVRSnP5, 2, 0.0f, 0.0f);
  numBytes += cBinop_init(&cBinop_zaKDLKho, 1.0f); // __mul
  numBytes += cBinop_init(&cBinop_4Zy7imgy, 0.0f); // __div
  numBytes += cRandom_init(&cRandom_B3v7faAs, 48424560);
  numBytes += cSlice_init(&cSlice_giDhiHVP, 1, 1);
  numBytes += cBinop_init(&cBinop_no5oSF1E, 1.0f); // __pow
  numBytes += cRandom_init(&cRandom_1earnbJr, -408304770);
  numBytes += cSlice_init(&cSlice_NqAlEh4g, 1, 1);
  numBytes += cSlice_init(&cSlice_Nj6DFvLz, 1, 1);
  numBytes += cSlice_init(&cSlice_6C9Y56FE, 0, 1);
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
  numBytes += cBinop_init(&cBinop_IbtYV3Po, 0.0f); // __div
  numBytes += cSlice_init(&cSlice_R1uawaao, 1, 1);
  numBytes += cSlice_init(&cSlice_MqY07X5b, 0, 1);
  numBytes += cVar_init_s(&cVar_LJONgNkw, "1089_default");
  numBytes += cSlice_init(&cSlice_YB4Ilcxk, 1, 1);
  numBytes += sVarf_init(&sVarf_A6KZg1dy, 0.0f, 0.0f, false);
  numBytes += cSlice_init(&cSlice_Sai3hU5Y, 1, 1);
  numBytes += cSlice_init(&cSlice_9aEdFzKI, 0, 1);
  numBytes += cVar_init_s(&cVar_389VEx53, "floatatom");
  numBytes += cVar_init_s(&cVar_KLZkdgi7, "floatatom");
  numBytes += hTable_init(&hTable_dqgidaqB, 1000);
  numBytes += cSlice_init(&cSlice_wFZuWykC, 1, 1);
  numBytes += cSlice_init(&cSlice_YFizWWF7, 0, 1);
  numBytes += cVar_init_f(&cVar_KSPhAnvf, 0.0f);
  numBytes += cPack_init(&cPack_WNx24O3v, 2, 0.0f, 0.0f);
  numBytes += cBinop_init(&cBinop_WA1JyZAo, 1.0f); // __mul
  numBytes += cBinop_init(&cBinop_aMSLNb5u, 0.0f); // __div
  numBytes += cRandom_init(&cRandom_QQtVEHLI, 1218905658);
  numBytes += cSlice_init(&cSlice_ED7Gc7D6, 1, 1);
  numBytes += cBinop_init(&cBinop_6Jo5QUR3, 1.0f); // __pow
  numBytes += cRandom_init(&cRandom_9tVFSV5F, -844765408);
  numBytes += cSlice_init(&cSlice_Tcwnk59D, 1, 1);
  numBytes += cSlice_init(&cSlice_Y3fYBJlC, 1, 1);
  numBytes += cSlice_init(&cSlice_y01lKo1A, 0, 1);
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
  numBytes += cBinop_init(&cBinop_TSNdKbFA, 0.0f); // __div
  numBytes += cSlice_init(&cSlice_dMloV94d, 1, 1);
  numBytes += cSlice_init(&cSlice_BzwFzVkh, 0, 1);
  numBytes += cVar_init_s(&cVar_ZwMUgIzr, "1127_default");
  numBytes += cSlice_init(&cSlice_E9EESRdV, 1, 1);
  numBytes += sVarf_init(&sVarf_jIF40qTi, 0.0f, 0.0f, false);
  numBytes += cSlice_init(&cSlice_nl2XhuQl, 1, 1);
  numBytes += cSlice_init(&cSlice_uCFw3d3O, 0, 1);
  numBytes += cVar_init_s(&cVar_TnCsLt8s, "floatatom");
  numBytes += cVar_init_s(&cVar_mzdZbr49, "floatatom");
  numBytes += hTable_init(&hTable_bkykhA3v, 1000);
  numBytes += cSlice_init(&cSlice_vUt3abmG, 1, 1);
  numBytes += cSlice_init(&cSlice_QfiTVqux, 0, 1);
  numBytes += cVar_init_f(&cVar_16bc7eRS, 0.0f);
  numBytes += cPack_init(&cPack_oOdCKp9p, 2, 0.0f, 0.0f);
  numBytes += cBinop_init(&cBinop_cv3n2bE1, 1.0f); // __mul
  numBytes += cBinop_init(&cBinop_LcMyXhPg, 0.0f); // __div
  numBytes += cVar_init_f(&cVar_Zn1ojjrH, 98.0f);
  numBytes += cIf_init(&cIf_RA7KvXe4, false);
  numBytes += cBinop_init(&cBinop_PCkC4yJ9, 0.0f); // __pow
  numBytes += cPack_init(&cPack_vRGo39Wp, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_vKvuftOz, 0.0f);
  numBytes += cVar_init_f(&cVar_oPZ52NA3, 100.0f);
  numBytes += cIf_init(&cIf_SaUsJ7St, false);
  numBytes += cBinop_init(&cBinop_05msPNT8, 0.0f); // __pow
  numBytes += cPack_init(&cPack_qohOHo7T, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_gmMUMGJa, 0.0f);
  numBytes += cIf_init(&cIf_MRGtgAVW, false);
  numBytes += cVar_init_f(&cVar_2HkT7EA4, 97.0f);
  numBytes += cIf_init(&cIf_BCe4LD1P, false);
  numBytes += cBinop_init(&cBinop_ZeAtRi5b, 0.0f); // __pow
  numBytes += cPack_init(&cPack_SvkpEzkg, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_g2tD0tVi, 0.0f);
  numBytes += cVar_init_f(&cVar_6uEOTKW5, 97.0f);
  numBytes += cIf_init(&cIf_T59kyxne, false);
  numBytes += cBinop_init(&cBinop_0jTb164h, 0.0f); // __pow
  numBytes += cPack_init(&cPack_UrtS4zxp, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_id113mRK, 0.0f);
  numBytes += cPack_init(&cPack_IVZ00RuP, 2, 0.0f, 0.0f);
  numBytes += cSlice_init(&cSlice_0dnQNxrx, 1, 1);
  numBytes += cSlice_init(&cSlice_tp36l5d9, 0, 1);
  numBytes += cIf_init(&cIf_3iNR7v2q, false);
  numBytes += cIf_init(&cIf_4Sx7CBu4, false);
  numBytes += cIf_init(&cIf_gBDy3SwE, false);
  numBytes += cSlice_init(&cSlice_qjwdR5zu, 1, 1);
  numBytes += cSlice_init(&cSlice_JsNDXk3i, 0, 1);
  numBytes += cVar_init_f(&cVar_m8Ix3fHp, 0.0f);
  numBytes += cIf_init(&cIf_OBJl1JQ9, false);
  numBytes += cPack_init(&cPack_9a733PFq, 2, 0.0f, 0.0f);
  numBytes += cSlice_init(&cSlice_l2aq8nF3, 1, -1);
  numBytes += cSlice_init(&cSlice_xuydrICF, 1, -1);
  numBytes += cSlice_init(&cSlice_onIDdbjZ, 1, -1);
  numBytes += cSlice_init(&cSlice_1gy5ErY8, 1, -1);
  numBytes += cIf_init(&cIf_kGiuDpyt, false);
  numBytes += cVar_init_f(&cVar_Gvx3wYfG, 1.0f);
  numBytes += cPack_init(&cPack_lA7P06zw, 3, 0.0f, 0.0f, 0.0f);
  numBytes += cVar_init_f(&cVar_TuXtPgx8, 0.0f);
  numBytes += hTable_init(&hTable_L5Asm0JQ, 36000);
  numBytes += hTable_init(&hTable_rwOMuyMM, 290000);
  numBytes += hTable_init(&hTable_SY2T5LAU, 288000);
  numBytes += hTable_init(&hTable_XZhy7ncS, 66000);
  numBytes += hTable_init(&hTable_ZnFQ5VXv, 25000);
  numBytes += hTable_init(&hTable_GoJVpFWT, 384000);
  numBytes += cSlice_init(&cSlice_Y4hxMcna, 2, 1);
  numBytes += cSlice_init(&cSlice_UZOVBp1z, 1, 1);
  numBytes += cSlice_init(&cSlice_rutu4pRj, 0, 1);
  numBytes += cVar_init_f(&cVar_Majfm0GP, 0.0f);
  numBytes += cIf_init(&cIf_yYNfatI5, false);
  numBytes += cIf_init(&cIf_Dtw77kAZ, false);
  numBytes += cIf_init(&cIf_8IgWrNwI, false);
  numBytes += cIf_init(&cIf_6lhEfuBZ, false);
  numBytes += cIf_init(&cIf_AszExoYR, false);
  numBytes += cBinop_init(&cBinop_wo4DGSH0, 0.0f); // __eq
  numBytes += cRandom_init(&cRandom_Dm15jdar, -100515316);
  numBytes += cSlice_init(&cSlice_web4DBtt, 1, 1);
  numBytes += cRandom_init(&cRandom_uTcHPrZn, 358123132);
  numBytes += cSlice_init(&cSlice_rDm5AsVt, 1, 1);
  numBytes += cRandom_init(&cRandom_G4enNZXX, 1752831495);
  numBytes += cSlice_init(&cSlice_nspBAi22, 1, 1);
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
  numBytes += cBinop_init(&cBinop_zKYOzcca, 0.0f); // __div
  numBytes += cVar_init_s(&cVar_02AHW0Bq, "del-1257-del1");
  numBytes += sVarf_init(&sVarf_vqZaoEA2, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_BvHUiFWi, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_eOHSLqSm, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_8O9LuJpY, 10000.0f);
  numBytes += cBinop_init(&cBinop_LQVVX95x, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_dcmGhIc0, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_phgJDijJ, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_4hlqXWkV, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_LP6LfgeT, 10.0f);
  numBytes += cBinop_init(&cBinop_YDIiTzgP, 0.0f); // __div
  numBytes += sVarf_init(&sVarf_Rf6pjyZ3, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_ToE5dgSY, "floatatom");
  numBytes += sVarf_init(&sVarf_lm1HusbR, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_8gEUlKK0, 0.0f);
  numBytes += cDelay_init(this, &cDelay_9E0G1t33, 0.0f);
  numBytes += hTable_init(&hTable_TnZjyknh, 256);
  numBytes += sVarf_init(&sVarf_gJI5XJwD, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_3fkpojuH, "floatatom");
  numBytes += cDelay_init(this, &cDelay_h8RoBNXp, 0.0f);
  numBytes += cVar_init_f(&cVar_UgLkOSfA, 20.0f);
  numBytes += cBinop_init(&cBinop_stQyNYdN, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_GfCKnBz5, 0.0f);
  numBytes += cSlice_init(&cSlice_BFERekNs, 1, -1);
  numBytes += cSlice_init(&cSlice_4qt3HSST, 1, -1);
  numBytes += cVar_init_f(&cVar_Xz5Bh72Y, 0.0f);
  numBytes += cVar_init_f(&cVar_wMvdCCPl, 20.0f);
  numBytes += cVar_init_f(&cVar_rEAPspkj, 0.0f);
  numBytes += cVar_init_f(&cVar_24AXcYGn, 0.0f);
  numBytes += cVar_init_f(&cVar_izcdXKzq, 0.0f);
  numBytes += cSlice_init(&cSlice_zWOm0NvF, 1, 1);
  numBytes += cSlice_init(&cSlice_zRH4yHyo, 0, 1);
  numBytes += cBinop_init(&cBinop_pJnY0ooD, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_e9vwzbnU, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_83uf3TZ0, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_uZzF3Ixh, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_JIm1oOiy, 20.0f); // __div
  numBytes += cBinop_init(&cBinop_yHzGJqcW, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_GiHmVh9X, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_0JckHJRu, 0.0f); // __sub
  numBytes += cVar_init_s(&cVar_sj0eyWaH, "floatatom");
  numBytes += cPack_init(&cPack_WcXObnvX, 2, 0.0f, 1000.0f);
  numBytes += cDelay_init(this, &cDelay_SWqSc0Mi, 0.0f);
  numBytes += cVar_init_f(&cVar_uhKWI9pg, 20.0f);
  numBytes += cBinop_init(&cBinop_KvFKyppH, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_vmVgUo89, 0.0f);
  numBytes += cSlice_init(&cSlice_LqnklgtN, 1, -1);
  numBytes += cSlice_init(&cSlice_VKfvcohg, 1, -1);
  numBytes += cVar_init_f(&cVar_xWahpDBV, 0.0f);
  numBytes += cVar_init_f(&cVar_ZnO3YYb7, 20.0f);
  numBytes += cVar_init_f(&cVar_AYuVqWOR, 0.0f);
  numBytes += cVar_init_f(&cVar_f7zF4mz2, 0.0f);
  numBytes += cVar_init_f(&cVar_T6MbkFIw, 0.0f);
  numBytes += cSlice_init(&cSlice_7tS212Pu, 1, 1);
  numBytes += cSlice_init(&cSlice_Wg55a7ii, 0, 1);
  numBytes += cBinop_init(&cBinop_BSZDvBMc, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_l2GRtja7, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_YMIrQnLm, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_shArdhDY, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_R0RVnxSW, 20.0f); // __div
  numBytes += cBinop_init(&cBinop_E9HsfONy, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_jjMvDeh5, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_iOH8jAno, 0.0f); // __sub
  numBytes += cPack_init(&cPack_XZZzNqh5, 2, 0.0f, 1000.0f);
  numBytes += cPack_init(&cPack_qcUSrU6Z, 2, 0.0f, 1000.0f);
  numBytes += cTabhead_init(&cTabhead_Ay9w28ta, &hTable_sOQFACjd);
  numBytes += cVar_init_s(&cVar_qN5QtCKP, "del-1318-del1");
  numBytes += cDelay_init(this, &cDelay_SuIHVgfJ, 58.6435f);
  numBytes += cDelay_init(this, &cDelay_ymHfVU7q, 0.0f);
  numBytes += cBinop_init(&cBinop_1tXXQCap, 58.6435f); // __mul
  numBytes += cBinop_init(&cBinop_g4xXvYc6, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_3axR19W7, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_JEmUlSr7, 0.0f); // __sub
  numBytes += cTabhead_init(&cTabhead_bsldNoGU, &hTable_kUXFxfS9);
  numBytes += cVar_init_s(&cVar_RkOG7nu9, "del-1318-del2");
  numBytes += cDelay_init(this, &cDelay_tcpHpV75, 69.4325f);
  numBytes += cDelay_init(this, &cDelay_ADk7FYJg, 0.0f);
  numBytes += cBinop_init(&cBinop_dR3Issgm, 69.4325f); // __mul
  numBytes += cBinop_init(&cBinop_j83WiwVQ, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_4v6OMUIw, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_zUiLah7o, 0.0f); // __sub
  numBytes += cTabhead_init(&cTabhead_MD15ck9x, &hTable_rQziADzR);
  numBytes += cVar_init_s(&cVar_jWsXkRIT, "del-1318-del3");
  numBytes += cDelay_init(this, &cDelay_wVPVkoPF, 74.5234f);
  numBytes += cDelay_init(this, &cDelay_AqjRr9T6, 0.0f);
  numBytes += cBinop_init(&cBinop_ClcVTFK7, 74.5234f); // __mul
  numBytes += cBinop_init(&cBinop_yBO9HRKL, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_JeHx8xhJ, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_1Xi8yDH2, 0.0f); // __sub
  numBytes += cTabhead_init(&cTabhead_po2Uy8VU, &hTable_yD5jEq6S);
  numBytes += cVar_init_s(&cVar_TfY1UwNu, "del-1318-del4");
  numBytes += cDelay_init(this, &cDelay_pMmJ1Df7, 86.1244f);
  numBytes += cDelay_init(this, &cDelay_Cj9J1iMM, 0.0f);
  numBytes += cBinop_init(&cBinop_muWy6S2R, 86.1244f); // __mul
  numBytes += cBinop_init(&cBinop_cRHIu7p1, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_BnZN7Zpa, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_L9LOyyeZ, 0.0f); // __sub
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
  numBytes += cBinop_init(&cBinop_6jSAZUUK, 0.0f); // __pow
  numBytes += cPack_init(&cPack_qr0uTD6a, 2, 0.0f, 30.0f);
  numBytes += cPack_init(&cPack_KIsxwZ1J, 2, 0.0f, 50.0f);
  numBytes += cVar_init_f(&cVar_4vurxjLg, 22050.0f);
  numBytes += cBinop_init(&cBinop_biJIdm5H, 0.0f); // __mul
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
  numBytes += cBinop_init(&cBinop_qLyovVfF, 13.645f); // __mul
  numBytes += cBinop_init(&cBinop_TNNpD3vO, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_m6umx7jZ, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_rEUZAGwQ, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_KGSvr8CU, 0.0f);
  numBytes += cDelay_init(this, &cDelay_XBJx0zKQ, 0.0f);
  numBytes += hTable_init(&hTable_N3IEEdKO, 256);
  numBytes += cTabhead_init(&cTabhead_GiSLm0Ve, &hTable_il4LWkq0);
  numBytes += cVar_init_s(&cVar_Nn2QYeSd, "del-1318-ref5");
  numBytes += cDelay_init(this, &cDelay_mbFM2wzE, 16.364f);
  numBytes += cDelay_init(this, &cDelay_2la49ykd, 0.0f);
  numBytes += cBinop_init(&cBinop_yTu1fMvI, 16.364f); // __mul
  numBytes += cBinop_init(&cBinop_mwnNoMXW, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_FiECT7xg, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_ESjGaIKk, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_ZI44pPse, 0.0f);
  numBytes += cDelay_init(this, &cDelay_FkFCpkOM, 0.0f);
  numBytes += hTable_init(&hTable_il4LWkq0, 256);
  numBytes += cTabhead_init(&cTabhead_jFneiBZ8, &hTable_9rKLAeez);
  numBytes += cVar_init_s(&cVar_cQfHPFbx, "del-1318-ref4");
  numBytes += cDelay_init(this, &cDelay_KLg3X0rz, 19.392f);
  numBytes += cDelay_init(this, &cDelay_JR5vGloY, 0.0f);
  numBytes += cBinop_init(&cBinop_2hNP4lA9, 19.392f); // __mul
  numBytes += cBinop_init(&cBinop_Cvtliz2t, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_snxSGQG0, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_WnlrS3dP, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_dqi6WYq0, 0.0f);
  numBytes += cDelay_init(this, &cDelay_Knj7evc2, 0.0f);
  numBytes += hTable_init(&hTable_9rKLAeez, 256);
  numBytes += cTabhead_init(&cTabhead_238LxNEE, &hTable_KTYymZwO);
  numBytes += cVar_init_s(&cVar_uTpHW20o, "del-1318-ref3");
  numBytes += cDelay_init(this, &cDelay_Rgcc4RTY, 25.796f);
  numBytes += cDelay_init(this, &cDelay_otqKPZHd, 0.0f);
  numBytes += cBinop_init(&cBinop_LZqhwFC8, 25.796f); // __mul
  numBytes += cBinop_init(&cBinop_HoqWlP8S, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_QG8NKBLQ, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_zQyxLGBE, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_4sH5AWzX, 0.0f);
  numBytes += cDelay_init(this, &cDelay_4G3cDlx2, 0.0f);
  numBytes += hTable_init(&hTable_KTYymZwO, 256);
  numBytes += cTabhead_init(&cTabhead_Dmc8PtT0, &hTable_5Jlf3VuJ);
  numBytes += cVar_init_s(&cVar_6pBlUwqW, "del-1318-ref2");
  numBytes += cDelay_init(this, &cDelay_J4SKKNKl, 43.5337f);
  numBytes += cDelay_init(this, &cDelay_GqrbjDsV, 0.0f);
  numBytes += cBinop_init(&cBinop_Q2Ttx1T7, 43.5337f); // __mul
  numBytes += cBinop_init(&cBinop_8L5yobrA, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_3ig7Lm5k, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_BvjRAvim, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_U43H4E6N, 0.0f);
  numBytes += cDelay_init(this, &cDelay_3YopkI0B, 0.0f);
  numBytes += hTable_init(&hTable_5Jlf3VuJ, 256);
  numBytes += cTabhead_init(&cTabhead_HKIPOkNn, &hTable_amukS8d7);
  numBytes += cVar_init_s(&cVar_tMoSExKz, "del-1318-ref1");
  numBytes += cDelay_init(this, &cDelay_tGccaxhl, 75.2546f);
  numBytes += cDelay_init(this, &cDelay_2hexzHdw, 0.0f);
  numBytes += cBinop_init(&cBinop_Pas39ZzD, 75.2546f); // __mul
  numBytes += cBinop_init(&cBinop_1WfFYHQW, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_fBmVL2JY, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_Skzrj1bk, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_kf0sMJ7C, 0.0f);
  numBytes += cDelay_init(this, &cDelay_MHDSXfwo, 0.0f);
  numBytes += hTable_init(&hTable_amukS8d7, 256);
  numBytes += cVar_init_f(&cVar_A5ugVD1y, 0.0f);
  numBytes += cVar_init_f(&cVar_ELbL87j9, 0.0f);
  numBytes += cPack_init(&cPack_g49bXLsX, 2, 0.0f, 50.0f);
  numBytes += cVar_init_f(&cVar_w9s8gsro, 22050.0f);
  numBytes += cBinop_init(&cBinop_NSHiTy1f, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_EdSrWJPJ, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_6GXKnDCJ, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_VMqS8U9a, 22050.0f);
  numBytes += cBinop_init(&cBinop_NgzBXHDK, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_XGtlPRgZ, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_khHH09UD, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_TbXZlErM, 22050.0f);
  numBytes += cBinop_init(&cBinop_nVbthqFU, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_HkIt0OkD, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_cMXIMxQ6, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_RWHaRdz0, 100.0f);
  numBytes += cIf_init(&cIf_vyUQpKzd, false);
  numBytes += cBinop_init(&cBinop_RQIF9pvT, 0.0f); // __pow
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
  numBytes += cBinop_init(&cBinop_ItDszn1u, 0.0f); // __div
  numBytes += cVar_init_f(&cVar_UwYm2B3w, 4720.0f);
  numBytes += cBinop_init(&cBinop_svZJianT, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_Yh1CU5cO, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_kWAJOmwx, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_h9nbQXbI, 4720.0f);
  numBytes += cBinop_init(&cBinop_hezYtxLh, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_g2lHkJLb, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_0T93HxmZ, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_6gGIbERR, 4720.0f);
  numBytes += cBinop_init(&cBinop_pclyTK01, 0.0f); // __mul
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
  numBytes += cBinop_init(&cBinop_xR7HV7wd, 58.6435f); // __mul
  numBytes += cBinop_init(&cBinop_NreiNAi5, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_l3aBboEX, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_i2ZOvpDX, 0.0f); // __sub
  numBytes += cTabhead_init(&cTabhead_yB2e39Ly, &hTable_6RQ15tHQ);
  numBytes += cVar_init_s(&cVar_TSmzWwYE, "del-1499-del2");
  numBytes += cDelay_init(this, &cDelay_2rktEiKe, 69.4325f);
  numBytes += cDelay_init(this, &cDelay_A9c8oUKr, 0.0f);
  numBytes += cBinop_init(&cBinop_TRY8bBhd, 69.4325f); // __mul
  numBytes += cBinop_init(&cBinop_GRC2Y3gO, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_9pCuWkDN, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_4obOa0kA, 0.0f); // __sub
  numBytes += cTabhead_init(&cTabhead_YXrQA3J2, &hTable_aFG3oJ94);
  numBytes += cVar_init_s(&cVar_KgUstciN, "del-1499-del3");
  numBytes += cDelay_init(this, &cDelay_URspPdeT, 74.5234f);
  numBytes += cDelay_init(this, &cDelay_nZHNIorZ, 0.0f);
  numBytes += cBinop_init(&cBinop_9nbcLdkc, 74.5234f); // __mul
  numBytes += cBinop_init(&cBinop_E2l5nDr2, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_iBbrZkJq, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_qnDRqHnS, 0.0f); // __sub
  numBytes += cTabhead_init(&cTabhead_Bnw0b04Z, &hTable_YZR7BrKp);
  numBytes += cVar_init_s(&cVar_hJUM360N, "del-1499-del4");
  numBytes += cDelay_init(this, &cDelay_mgXwiBoK, 86.1244f);
  numBytes += cDelay_init(this, &cDelay_vLcb7izi, 0.0f);
  numBytes += cBinop_init(&cBinop_Kt7kKPHH, 86.1244f); // __mul
  numBytes += cBinop_init(&cBinop_51yGrh40, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_psluHfVQ, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_CO7YXtmN, 0.0f); // __sub
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
  numBytes += cBinop_init(&cBinop_A2U3DdrV, 0.0f); // __pow
  numBytes += cPack_init(&cPack_WxiN8UNo, 2, 0.0f, 30.0f);
  numBytes += cPack_init(&cPack_9tnPgoYv, 2, 0.0f, 50.0f);
  numBytes += cVar_init_f(&cVar_7zYxjbNP, 22050.0f);
  numBytes += cBinop_init(&cBinop_Rs7wEHiP, 0.0f); // __mul
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
  numBytes += cBinop_init(&cBinop_lP9haw1E, 13.645f); // __mul
  numBytes += cBinop_init(&cBinop_43A9XlSl, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_GGx6ikvq, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_r6KktnqJ, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_M55PrVFx, 0.0f);
  numBytes += cDelay_init(this, &cDelay_wuuP7HUY, 0.0f);
  numBytes += hTable_init(&hTable_vassxs94, 256);
  numBytes += cTabhead_init(&cTabhead_ccb5gzCO, &hTable_jySdBtVo);
  numBytes += cVar_init_s(&cVar_YKuyqJkJ, "del-1499-ref5");
  numBytes += cDelay_init(this, &cDelay_TgQlUfGJ, 16.364f);
  numBytes += cDelay_init(this, &cDelay_3oeH2JBy, 0.0f);
  numBytes += cBinop_init(&cBinop_qDXTL5sw, 16.364f); // __mul
  numBytes += cBinop_init(&cBinop_iz7mYQDn, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_QWylQbiQ, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_dPHgSIne, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_WxrELUTQ, 0.0f);
  numBytes += cDelay_init(this, &cDelay_nTiAx3Z0, 0.0f);
  numBytes += hTable_init(&hTable_jySdBtVo, 256);
  numBytes += cTabhead_init(&cTabhead_RIhxzTXX, &hTable_Q5I7LvD0);
  numBytes += cVar_init_s(&cVar_4xtVoWQl, "del-1499-ref4");
  numBytes += cDelay_init(this, &cDelay_ia9QH5BZ, 19.392f);
  numBytes += cDelay_init(this, &cDelay_09LHT9W5, 0.0f);
  numBytes += cBinop_init(&cBinop_h68kXxuc, 19.392f); // __mul
  numBytes += cBinop_init(&cBinop_ky1DBcwB, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_xHzYMt2t, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_P5sB6SzB, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_SIMNYWXy, 0.0f);
  numBytes += cDelay_init(this, &cDelay_dLmDm8cZ, 0.0f);
  numBytes += hTable_init(&hTable_Q5I7LvD0, 256);
  numBytes += cTabhead_init(&cTabhead_TNf1eExq, &hTable_KHlQYXx9);
  numBytes += cVar_init_s(&cVar_m3EZUm6A, "del-1499-ref3");
  numBytes += cDelay_init(this, &cDelay_ASYbIDGN, 25.796f);
  numBytes += cDelay_init(this, &cDelay_HxStVlIg, 0.0f);
  numBytes += cBinop_init(&cBinop_M34Jiqr9, 25.796f); // __mul
  numBytes += cBinop_init(&cBinop_qq6K9PHv, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_bdL5NQmx, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_IIS2nFeZ, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_dzwLPIln, 0.0f);
  numBytes += cDelay_init(this, &cDelay_FtY8PYnt, 0.0f);
  numBytes += hTable_init(&hTable_KHlQYXx9, 256);
  numBytes += cTabhead_init(&cTabhead_akRr0TKx, &hTable_ed4dzP1v);
  numBytes += cVar_init_s(&cVar_Hz4wWSlG, "del-1499-ref2");
  numBytes += cDelay_init(this, &cDelay_5SF5c1Hw, 43.5337f);
  numBytes += cDelay_init(this, &cDelay_NbGYCTWS, 0.0f);
  numBytes += cBinop_init(&cBinop_ow1xervc, 43.5337f); // __mul
  numBytes += cBinop_init(&cBinop_EpHDWzxq, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_YLgj1ukC, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_Mh7qOlAm, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_49X6shXY, 0.0f);
  numBytes += cDelay_init(this, &cDelay_LA1wd9KH, 0.0f);
  numBytes += hTable_init(&hTable_ed4dzP1v, 256);
  numBytes += cTabhead_init(&cTabhead_zgIRUxoj, &hTable_7LfxGM68);
  numBytes += cVar_init_s(&cVar_0Olyx67a, "del-1499-ref1");
  numBytes += cDelay_init(this, &cDelay_Uz12UbaY, 75.2546f);
  numBytes += cDelay_init(this, &cDelay_cC3ArdK1, 0.0f);
  numBytes += cBinop_init(&cBinop_9tZlrvrI, 75.2546f); // __mul
  numBytes += cBinop_init(&cBinop_KVlSpyHI, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_5qRB83KQ, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_1BQbilMa, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_tDqTr5Nd, 0.0f);
  numBytes += cDelay_init(this, &cDelay_ONIOIJpt, 0.0f);
  numBytes += hTable_init(&hTable_7LfxGM68, 256);
  numBytes += cVar_init_f(&cVar_yWYkELLa, 0.0f);
  numBytes += cVar_init_f(&cVar_fsUuWpD2, 0.0f);
  numBytes += cPack_init(&cPack_ezBvigzM, 2, 0.0f, 50.0f);
  numBytes += cVar_init_f(&cVar_FsHhjE6c, 22050.0f);
  numBytes += cBinop_init(&cBinop_0BFI24TH, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_dwUu67ZV, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_PmTLRsbz, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_MpIBnkWC, 22050.0f);
  numBytes += cBinop_init(&cBinop_Mw2sEQbO, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_JXDtWNO1, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_Xpj6GjZf, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_YgoH762r, 22050.0f);
  numBytes += cBinop_init(&cBinop_Q1F0td1q, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_8luTeCv1, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_e1f2eTK1, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_1wlv4jAe, "del-1598-del1");
  numBytes += sVarf_init(&sVarf_3YLMKCtN, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_h9b0vrTz, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_HpEo7pyO, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_8thkYCby, 10000.0f);
  numBytes += cBinop_init(&cBinop_h72IJPvd, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_ToQ7iRm0, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_VmXj2GYM, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_d18kc4ju, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_kFmB3ZJL, 10.0f);
  numBytes += cBinop_init(&cBinop_eqlxABbB, 0.0f); // __div
  numBytes += sVarf_init(&sVarf_aOyNmdiR, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_E2Te6apB, "floatatom");
  numBytes += sVarf_init(&sVarf_hmWBbNn7, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_E8pX8p1R, 0.0f);
  numBytes += cDelay_init(this, &cDelay_FgC9tAJs, 0.0f);
  numBytes += hTable_init(&hTable_Bf8NPbuA, 256);
  numBytes += sVarf_init(&sVarf_QS92CIuz, 0.0f, 0.0f, false);
  numBytes += cPack_init(&cPack_hICvL53O, 2, 0.0f, 50.0f);
  numBytes += cVar_init_f(&cVar_L2jcM6y8, 1.0f);
  numBytes += cPack_init(&cPack_ay7lFJ2w, 2, 0.0f, 50.0f);
  numBytes += cRandom_init(&cRandom_Vt8jAfTz, 20129892);
  numBytes += cSlice_init(&cSlice_J7tfB487, 1, 1);
  numBytes += cRandom_init(&cRandom_ZZqo5AYi, -936999322);
  numBytes += cSlice_init(&cSlice_OyaBRWpn, 1, 1);
  numBytes += cRandom_init(&cRandom_7H9D1jAN, 1098670691);
  numBytes += cSlice_init(&cSlice_rljPhqci, 1, 1);
  numBytes += cPack_init(&cPack_WlmhFUbW, 4, 0.0f, 0.0f, 0.0f, 0.0f);
  numBytes += cVar_init_s(&cVar_Une0GPFu, "floatatom");
  numBytes += cVar_init_s(&cVar_sj8eJAp4, "floatatom");
  numBytes += cIf_init(&cIf_9sOuS4Oz, false);
  numBytes += cVar_init_s(&cVar_IecrjCGB, "floatatom");
  numBytes += cBinop_init(&cBinop_jwQ1Cmvw, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_D4crHq4S, 72.07f); // __sub
  numBytes += cSlice_init(&cSlice_0vJoTVKz, 1, -1);
  numBytes += cSlice_init(&cSlice_GASkMN1k, 1, -1);
  numBytes += cVar_init_f(&cVar_IWPRAMQc, 5.0f);
  numBytes += cBinop_init(&cBinop_jHxaDnBq, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_LJNrNrgd, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_cVKoBcMM, 0.0f, 0.0f, false);
  numBytes += cSlice_init(&cSlice_tsVaYaSp, 1, 1);
  numBytes += cSlice_init(&cSlice_UKaWzyTm, 0, 1);
  numBytes += sVarf_init(&sVarf_riXES2ua, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_YLhzpjc3, 5.0f);
  numBytes += cBinop_init(&cBinop_xlcIy2it, 0.0f); // __div
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
  numBytes += cSlice_init(&cSlice_46AxoJJ1, 1, 1);
  numBytes += sVarf_init(&sVarf_1i3HKFFn, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_JiQ6bRd5, "1674_default");
  numBytes += cSlice_init(&cSlice_AwbkDAjm, 1, 1);
  numBytes += sVarf_init(&sVarf_pJMale4s, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_wurxiXrM, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_uvWzq1Ec, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_TB87PUyv, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_aEHBNCon, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_sGelEI44, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_VFVTKNfL, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_PEcK7y0d, 0.0f); // __div
  numBytes += hTable_init(&hTable_adIMRuo0, 10000);
  numBytes += sVarf_init(&sVarf_GVIy0hBU, 0.0f, 0.0f, false);
  
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
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_ZDc3behT_sendMessage);
      break;
    }
    case 0x4518BA34: { // 1005-levelout
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_tx2TCvlM_sendMessage);
      break;
    }
    case 0xF2645EF2: { // 1013-cutoff
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_5HY5fLM2_sendMessage);
      break;
    }
    case 0x349D3D62: { // 1013-phase
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_j108jHSS_sendMessage);
      break;
    }
    case 0x6AE0114A: { // 1013-rel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_me6GXtaS_sendMessage);
      break;
    }
    case 0x14D190E8: { // 1013-tableFreq
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_q6o7mfie_sendMessage);
      break;
    }
    case 0xC268AA1B: { // 1013-tableName
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_5f3FvQpl_sendMessage);
      break;
    }
    case 0xE7AF8038: { // 1013-velocity
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_41RaPf9H_sendMessage);
      break;
    }
    case 0x64DCFC2F: { // 1013-vol
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_z6iEtg1P_sendMessage);
      break;
    }
    case 0x76EF1A3A: { // 1051-cutoff
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_pJyJ8beI_sendMessage);
      break;
    }
    case 0x7AB5A036: { // 1051-phase
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_KAf1xh4c_sendMessage);
      break;
    }
    case 0x729AEC23: { // 1051-rel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_5hQZcw1R_sendMessage);
      break;
    }
    case 0x78E1F133: { // 1051-tableFreq
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_bcGB1aGC_sendMessage);
      break;
    }
    case 0x6CE4754: { // 1051-tableName
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_PC7vIRkt_sendMessage);
      break;
    }
    case 0xFD6A3B2A: { // 1051-velocity
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_2Rgd81on_sendMessage);
      break;
    }
    case 0x6CE9CED9: { // 1051-vol
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_TIg47hmJ_sendMessage);
      break;
    }
    case 0xFA29A439: { // 1089-cutoff
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_ue79bHQD_sendMessage);
      break;
    }
    case 0xAA863EF6: { // 1089-phase
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_dzV4DPcb_sendMessage);
      break;
    }
    case 0xAAA0A75E: { // 1089-rel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_pwIe5pyd_sendMessage);
      break;
    }
    case 0xCB432715: { // 1089-tableFreq
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_RT1zMGKA_sendMessage);
      break;
    }
    case 0xB7D5A2D4: { // 1089-tableName
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_VzckN8pw_sendMessage);
      break;
    }
    case 0xBBC64E67: { // 1089-velocity
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_sJLVG06s_sendMessage);
      break;
    }
    case 0x720CB109: { // 1089-vol
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_FhL5QWRt_sendMessage);
      break;
    }
    case 0x49109026: { // 1127-cutoff
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_FGUdnHin_sendMessage);
      break;
    }
    case 0x1ED22B32: { // 1127-phase
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_r510TR8k_sendMessage);
      break;
    }
    case 0xB70E01AA: { // 1127-rel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_dA7RIHfw_sendMessage);
      break;
    }
    case 0x47F0CA40: { // 1127-tableFreq
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_CyRdbAJg_sendMessage);
      break;
    }
    case 0x212E3ED2: { // 1127-tableName
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_zTsXD6YR_sendMessage);
      break;
    }
    case 0xD654287F: { // 1127-velocity
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_WLjoD2qK_sendMessage);
      break;
    }
    case 0x4B190B33: { // 1127-vol
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_Ju1xS2TW_sendMessage);
      break;
    }
    case 0x1345C8C4: { // 1165-levelin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_8ia9UA0J_sendMessage);
      break;
    }
    case 0x352D518B: { // 1165-levelout
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_RJ028IRF_sendMessage);
      break;
    }
    case 0x1B80BC63: { // 1173-levelin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_mpWxdZ0C_sendMessage);
      break;
    }
    case 0x85C9C328: { // 1173-levelout
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_H9uGa2DN_sendMessage);
      break;
    }
    case 0x7FA13EC5: { // 1183-levelin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_KuzwHoLG_sendMessage);
      break;
    }
    case 0xD9AC1997: { // 1183-levelout
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_mYumRgba_sendMessage);
      break;
    }
    case 0xE3801E94: { // 1191-levelin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_YzPn1YFy_sendMessage);
      break;
    }
    case 0x4DA02B5A: { // 1191-levelout
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_C1lp9X1Z_sendMessage);
      break;
    }
    case 0x8DC08092: { // 1417-levelin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_jlnIpbMW_sendMessage);
      break;
    }
    case 0xA51F5BFF: { // 1417-levelout
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_Eklo03qa_sendMessage);
      break;
    }
    case 0x382EB97A: { // 1626-bend
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_SJ6Uh0vb_sendMessage);
      break;
    }
    case 0xD613858: { // 1626-chunk-size
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_MDy21nR2_sendMessage);
      break;
    }
    case 0x2952A082: { // 1626-level
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_KdXsCelA_sendMessage);
      break;
    }
    case 0xCC3056CB: { // 1626-loopstart
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_viMpYEkR_sendMessage);
      break;
    }
    case 0x484C6410: { // 1626-pitch
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_vcMb0WOz_sendMessage);
      break;
    }
    case 0x83CDC26B: { // 1626-reset
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_o8LH6hUa_sendMessage);
      break;
    }
    case 0xD475E50C: { // 1626-sample
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_hhNFlC8R_sendMessage);
      break;
    }
    case 0xAFE56AD8: { // 1626-sample-pitch
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_RUVe3pDV_sendMessage);
      break;
    }
    case 0x739592F2: { // 1626-start
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_t2ImK8S7_sendMessage);
      break;
    }
    case 0x31B2C381: { // 1626-stop
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_jMhwovL4_sendMessage);
      break;
    }
    case 0xD2002891: { // 1626-table
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_UdPOlQ82_sendMessage);
      break;
    }
    case 0xEA3AE85E: { // 1626-transposition
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_EZSbojeT_sendMessage);
      break;
    }
    case 0x692F7CB8: { // 1674-cents
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_i89foIcW_sendMessage);
      break;
    }
    case 0x72CEA287: { // 1674-chunk-size
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_JUsaRojU_sendMessage);
      break;
    }
    case 0xA99117E0: { // 1674-chunk-size-samples
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_Wd4NhQ0S_sendMessage);
      break;
    }
    case 0xEA9C1FF4: { // 1674-read-point
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_Do9nya8H_sendMessage);
      break;
    }
    case 0x995DB636: { // 1674-read-pt
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_RoL1C3Kj_sendMessage);
      break;
    }
    case 0xD40026D1: { // 1674-size
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_iBd6GA39_sendMessage);
      break;
    }
    case 0x2460F295: { // 1674-table
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_7EK9zeiH_sendMessage);
      break;
    }
    case 0xCE5CC65B: { // __hv_init
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_zfd68FNh_sendMessage);
      break;
    }
    case 0x67E37CA3: { // __hv_notein
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_Xk8uDKfY_sendMessage);
      break;
    }
    case 0x40AA4AF1: { // changesound
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_j8Mz1NLg_sendMessage);
      break;
    }
    case 0xA41806F7: { // distortlevel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_JfpuuerB_sendMessage);
      break;
    }
    case 0xFCD12E4C: { // mastervolume
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_kF0RAx1I_sendMessage);
      break;
    }
    case 0xEF5F3308: { // panTranslation
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_EEWf9xk7_sendMessage);
      break;
    }
    case 0x8B2148DD: { // pitch
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_br9NnjpD_sendMessage);
      break;
    }
    case 0x4409C659: { // processeffects
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_gi3bKbGJ_sendMessage);
      break;
    }
    case 0x7B795C5A: { // resetsing
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_nsXxDOTw_sendMessage);
      break;
    }
    case 0xA987B741: { // reverbvolume
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_WatQHk0Y_sendMessage);
      break;
    }
    case 0x7FFAC478: { // sampleNameFreq
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_fKOUPBDH_sendMessage);
      break;
    }
    case 0x62D6FDDE: { // selectsound
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_qRnOVDWs_sendMessage);
      break;
    }
    case 0x7AAE6786: { // sinPanAngle
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_rRS6P44Y_sendMessage);
      break;
    }
    case 0x6731B2E0: { // sing
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_aEZ3Zkri_sendMessage);
      break;
    }
    case 0x57292445: { // singlevel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_jC4Mczgd_sendMessage);
      break;
    }
    case 0xC7DE3B07: { // singpitch
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_2ZtI90gj_sendMessage);
      break;
    }
    case 0x853B1BE7: { // velocity
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_FeOwgZiZ_sendMessage);
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
  cSend_JRc8LTmf_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cReceive_2ZtI90gj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_nYYVQKjy_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cReceive_41RaPf9H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_aJbMkgtr_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_id113mRK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_l6I4zd3I_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_Jouqeh6Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_YzPn1YFy_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_KzReA7xH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSend_Jouqeh6Z_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_6uEOTKW5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_KzReA7xH_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Eej5cfCi_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_4C68CTZJ_sendMessage);
}

void Heavy_SoundScraper::cPack_UrtS4zxp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_QM37Rcsm, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_0jTb164h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_UrtS4zxp, 0, m, &cPack_UrtS4zxp_sendMessage);
}

void Heavy_SoundScraper::cCast_4C68CTZJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_T59kyxne, 0, m, &cIf_T59kyxne_sendMessage);
}

void Heavy_SoundScraper::cMsg_4QYcVSVZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_0jTb164h, HV_BINOP_POW, 0, m, &cBinop_0jTb164h_sendMessage);
}

void Heavy_SoundScraper::cBinop_5IGkU8N8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_T59kyxne, 1, m, &cIf_T59kyxne_sendMessage);
}

void Heavy_SoundScraper::cCast_Eej5cfCi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_5IGkU8N8_sendMessage);
}

void Heavy_SoundScraper::cBinop_RNthU5G9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_hdAT2YoH_sendMessage);
}

void Heavy_SoundScraper::cIf_T59kyxne_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_mgH5CSnn_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_RNthU5G9_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_Zwr6Hfpo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_0jTb164h, HV_BINOP_POW, 1, m, &cBinop_0jTb164h_sendMessage);
  cMsg_4QYcVSVZ_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_hdAT2YoH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_Zwr6Hfpo_sendMessage);
}

void Heavy_SoundScraper::cMsg_mgH5CSnn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_UrtS4zxp, 0, m, &cPack_UrtS4zxp_sendMessage);
}

void Heavy_SoundScraper::cSend_l6I4zd3I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_C1lp9X1Z_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cReceive_5HY5fLM2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_qm8yewgh, 0, m, NULL);
  cPrint_onMessage(_c, m, "TABLEPLAYER_CUTOFF");
}

void Heavy_SoundScraper::cReceive_5f3FvQpl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_KXcAfqmU, 1, m, &cVar_KXcAfqmU_sendMessage);
}

void Heavy_SoundScraper::cReceive_5hQZcw1R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_3n85lNl6, 1, m, &cVar_3n85lNl6_sendMessage);
}

void Heavy_SoundScraper::cReceive_7EK9zeiH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_3Y39AZ0e_sendMessage(_c, 0, m);
  cMsg_8oPoycfA_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_4CiVB78z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_WcXObnvX, 0, m, &cPack_WcXObnvX_sendMessage);
}

void Heavy_SoundScraper::cBinop_CbckDMR8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 4.0f, 0, m, &cBinop_4CiVB78z_sendMessage);
}

void Heavy_SoundScraper::cVar_3fkpojuH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cCast_NcKfd4xP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_fgh7z5V9_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cVar_sj0eyWaH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cCast_OyLoHW9F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_Bdq0WgST_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cMsg_UFkvbtYD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.15f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_QKeJjtvr_sendMessage);
}

void Heavy_SoundScraper::cPack_WcXObnvX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_zhZwLoax_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cPack_XZZzNqh5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_wa7M0Cv1_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_0JvXViD5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_zKYOzcca, HV_BINOP_DIVIDE, 1, m, &cBinop_zKYOzcca_sendMessage);
}

void Heavy_SoundScraper::cCast_27ZJ2wY9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_zKYOzcca, HV_BINOP_DIVIDE, 0, m, &cBinop_zKYOzcca_sendMessage);
}

void Heavy_SoundScraper::cSystem_AkD6AQBv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_yAX56Pd9_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_VPA9eOP7, m);
}

void Heavy_SoundScraper::cBinop_BYScuqZB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_JZG5yxNg, m);
}

void Heavy_SoundScraper::cVar_YObsSk03_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_gjxfcIYu_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_gjxfcIYu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_AkD6AQBv_sendMessage);
}

void Heavy_SoundScraper::cSystem_1OPB8C3l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_BYScuqZB_sendMessage);
}

void Heavy_SoundScraper::cMsg_SeMT4tjI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_1OPB8C3l_sendMessage);
}

void Heavy_SoundScraper::cBinop_yAX56Pd9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_gj6OsYoC, m);
}

void Heavy_SoundScraper::cBinop_3LyMW30U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_0JvXViD5_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_27ZJ2wY9_sendMessage);
}

void Heavy_SoundScraper::cBinop_OsO9JWCJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 87.3365f, 0, m, &cBinop_XQezQsN3_sendMessage);
}

void Heavy_SoundScraper::cMsg_Sj0NUwr7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.5f);
  cVar_onMessage(_c, &Context(_c)->cVar_5vS3geYi, 0, m, &cVar_5vS3geYi_sendMessage);
}

void Heavy_SoundScraper::cMsg_MEzGKBmE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Ub6hZTeD_sendMessage);
}

void Heavy_SoundScraper::cSystem_Ub6hZTeD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_oLEqnRxi_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_xUZp3MPJ, m);
}

void Heavy_SoundScraper::cMsg_KhCtoqD1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_iQKVE74E_sendMessage);
}

void Heavy_SoundScraper::cSystem_iQKVE74E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_kMQHZoc2_sendMessage);
}

void Heavy_SoundScraper::cVar_lDaFAIiM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_MEzGKBmE_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_kMQHZoc2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_pymPXy7g, m);
}

void Heavy_SoundScraper::cBinop_oLEqnRxi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_l3q2gskJ, m);
}

void Heavy_SoundScraper::cBinop_YshteAh0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_uG1S7O8g, 0, m, &cPack_uG1S7O8g_sendMessage);
}

void Heavy_SoundScraper::cMsg_Zi5lNQLi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 100.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_gY1fKd9A, 0, m, &cVar_gY1fKd9A_sendMessage);
}

void Heavy_SoundScraper::cBinop_eAv98oF6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_nNoHMgri_sendMessage);
}

void Heavy_SoundScraper::cMsg_jOZg8GKF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 30.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_0ZnGXISG, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_nNoHMgri_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_zKYOzcca, HV_BINOP_DIVIDE, 0, m, &cBinop_zKYOzcca_sendMessage);
}

void Heavy_SoundScraper::cVar_gY1fKd9A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_t3FDN9s5_sendMessage);
}

void Heavy_SoundScraper::cBinop_t3FDN9s5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.001f, 0, m, &cBinop_3LyMW30U_sendMessage);
  cPack_onMessage(_c, &Context(_c)->cPack_wUQTNaBy, 0, m, &cPack_wUQTNaBy_sendMessage);
}

void Heavy_SoundScraper::cPack_uG1S7O8g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_AV6C8lwf, 0, m, NULL);
}

void Heavy_SoundScraper::cPack_wUQTNaBy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_6zA7jM3e, 0, m, NULL);
}

void Heavy_SoundScraper::cVar_5vS3geYi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.5f, 0, m, &cBinop_YshteAh0_sendMessage);
}

void Heavy_SoundScraper::cBinop_11fOa6ve_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 5000.0f, 0, m, &cBinop_YwXoKQlz_sendMessage);
}

void Heavy_SoundScraper::cCast_FQkwkhHy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_sL1r7e6U, 0, m, &cDelay_sL1r7e6U_sendMessage);
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
      cMsg_bV4kjYn9_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_YwXoKQlz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_YwaGFhUc_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_YwaGFhUc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_zlt5GtL1, 0, m, &hTable_zlt5GtL1_sendMessage);
}

void Heavy_SoundScraper::cMsg_bV4kjYn9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_68ZEmoet, 1, m, NULL);
}

void Heavy_SoundScraper::cMsg_iAHfQVk2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_jDgXVZS6, 2, m, &cDelay_jDgXVZS6_sendMessage);
}

void Heavy_SoundScraper::cSystem_E1XDLAi8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_11fOa6ve_sendMessage);
}

void Heavy_SoundScraper::cMsg_RpxN8fwg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_E1XDLAi8_sendMessage);
}

void Heavy_SoundScraper::cDelay_jDgXVZS6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_jDgXVZS6, m);
  cMsg_oO3Ayabh_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_oO3Ayabh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_zlt5GtL1, 0, m, &hTable_zlt5GtL1_sendMessage);
}

void Heavy_SoundScraper::cDelay_sL1r7e6U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_sL1r7e6U, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_jDgXVZS6, 0, m, &cDelay_jDgXVZS6_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_sL1r7e6U, 0, m, &cDelay_sL1r7e6U_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_68ZEmoet, 1, m, NULL);
}

void Heavy_SoundScraper::hTable_zlt5GtL1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_iAHfQVk2_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_sL1r7e6U, 2, m, &cDelay_sL1r7e6U_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_FQkwkhHy_sendMessage);
}

void Heavy_SoundScraper::cUnop_PJIYcAZu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_eAv98oF6_sendMessage);
}

void Heavy_SoundScraper::cBinop_XQezQsN3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_EXP, m, &cUnop_PJIYcAZu_sendMessage);
}

void Heavy_SoundScraper::cBinop_zKYOzcca_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_jOZg8GKF_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cUnop_3YbyLICf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_XZZzNqh5, 0, m, &cPack_XZZzNqh5_sendMessage);
}

void Heavy_SoundScraper::cBinop_EgR7aQyw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_3YbyLICf_sendMessage);
}

void Heavy_SoundScraper::cRandom_G4enNZXX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 200.0f, 0, m, &cBinop_EgR7aQyw_sendMessage);
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
      cSlice_onMessage(_c, &Context(_c)->cSlice_nspBAi22, 0, m, &cSlice_nspBAi22_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_G4enNZXX, 0, m, &cRandom_G4enNZXX_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cSlice_nspBAi22_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_G4enNZXX, 1, m, &cRandom_G4enNZXX_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_0JckHJRu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_yHzGJqcW, HV_BINOP_DIVIDE, 0, m, &cBinop_yHzGJqcW_sendMessage);
}

void Heavy_SoundScraper::cVar_rEAPspkj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_0JckHJRu, HV_BINOP_SUBTRACT, 1, m, &cBinop_0JckHJRu_sendMessage);
}

void Heavy_SoundScraper::cMsg_3vMJ3ti6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_Xz5Bh72Y, 1, m, &cVar_Xz5Bh72Y_sendMessage);
}

void Heavy_SoundScraper::cVar_izcdXKzq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_uZzF3Ixh, HV_BINOP_ADD, 0, m, &cBinop_uZzF3Ixh_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_GiHmVh9X, HV_BINOP_ADD, 0, m, &cBinop_GiHmVh9X_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_sj0eyWaH, 0, m, &cVar_sj0eyWaH_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.05776f, 0, m, &cBinop_OsO9JWCJ_sendMessage);
}

void Heavy_SoundScraper::cCast_5rP4odRF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_X7MhIFbv_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_7GkuHEDs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_5rP4odRF_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_GiHmVh9X, HV_BINOP_ADD, 0, m, &cBinop_GiHmVh9X_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_izcdXKzq, 1, m, &cVar_izcdXKzq_sendMessage);
}

void Heavy_SoundScraper::cVar_UgLkOSfA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_stQyNYdN, HV_BINOP_MULTIPLY, 0, m, &cBinop_stQyNYdN_sendMessage);
}

void Heavy_SoundScraper::cBinop_CicYzqYX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_stQyNYdN, HV_BINOP_MULTIPLY, 1, m, &cBinop_stQyNYdN_sendMessage);
}

void Heavy_SoundScraper::cMsg_JVHs3374_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_h8RoBNXp, 0, m, &cDelay_h8RoBNXp_sendMessage);
}

void Heavy_SoundScraper::cBinop_Tmg1ZyNb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_h8RoBNXp, 2, m, &cDelay_h8RoBNXp_sendMessage);
}

void Heavy_SoundScraper::cDelay_h8RoBNXp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_h8RoBNXp, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_h8RoBNXp, 0, m, &cDelay_h8RoBNXp_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_GfCKnBz5, 0, m, &cVar_GfCKnBz5_sendMessage);
}

void Heavy_SoundScraper::cMsg_coOqk6Hv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_tEOBkZds_sendMessage);
}

void Heavy_SoundScraper::cSystem_tEOBkZds_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_CicYzqYX_sendMessage);
}

void Heavy_SoundScraper::cBinop_stQyNYdN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_Tmg1ZyNb_sendMessage);
}

void Heavy_SoundScraper::cCast_XrLsB1HP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_JVHs3374_sendMessage(_c, 0, m);
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
      cMsg_JVHs3374_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_JVHs3374_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_XrLsB1HP_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_83uf3TZ0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_GfCKnBz5, 1, m, &cVar_GfCKnBz5_sendMessage);
}

void Heavy_SoundScraper::cMsg_21cYREHO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_6pwWbFDF_sendMessage);
}

void Heavy_SoundScraper::cSystem_6pwWbFDF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_e9vwzbnU, HV_BINOP_MULTIPLY, 1, m, &cBinop_e9vwzbnU_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_pJnY0ooD, HV_BINOP_MULTIPLY, 1, m, &cBinop_pJnY0ooD_sendMessage);
}

void Heavy_SoundScraper::cMsg_BYwSiFqd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_vcB28aBV_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_GiHmVh9X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_rEAPspkj, 0, m, &cVar_rEAPspkj_sendMessage);
}

void Heavy_SoundScraper::cCast_Iopt7YnK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_X7MhIFbv_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_JIm1oOiy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_yHzGJqcW, HV_BINOP_DIVIDE, 1, m, &cBinop_yHzGJqcW_sendMessage);
}

void Heavy_SoundScraper::cMsg_MDlB0Uve_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_vcB28aBV_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_OnXbEHIO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_0JckHJRu, HV_BINOP_SUBTRACT, 0, m, &cBinop_0JckHJRu_sendMessage);
}

void Heavy_SoundScraper::cCast_SZLN7VJY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_24AXcYGn, 1, m, &cVar_24AXcYGn_sendMessage);
}

void Heavy_SoundScraper::cCast_Q8GQi8Az_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_q6P4Fhjl_sendMessage(_c, 0, m);
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
      cBinop_onMessage(_c, &Context(_c)->cBinop_e9vwzbnU, HV_BINOP_MULTIPLY, 0, m, &cBinop_e9vwzbnU_sendMessage);
      cBinop_onMessage(_c, &Context(_c)->cBinop_JIm1oOiy, HV_BINOP_DIVIDE, 1, m, &cBinop_JIm1oOiy_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_UgLkOSfA, 0, m, &cVar_UgLkOSfA_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_UZP5YOBU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_GfCKnBz5, 1, m, &cVar_GfCKnBz5_sendMessage);
}

void Heavy_SoundScraper::cMsg_X7MhIFbv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_vcB28aBV_onMessage(_c, NULL, 0, m, NULL);
  cBinop_onMessage(_c, &Context(_c)->cBinop_GiHmVh9X, HV_BINOP_ADD, 1, m, &cBinop_GiHmVh9X_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_uZzF3Ixh, HV_BINOP_ADD, 1, m, &cBinop_uZzF3Ixh_sendMessage);
}

void Heavy_SoundScraper::cCast_a74RPXwG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_24AXcYGn, 0, m, &cVar_24AXcYGn_sendMessage);
}

void Heavy_SoundScraper::cCast_bez6MEJQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_JIm1oOiy, HV_BINOP_DIVIDE, 0, m, &cBinop_JIm1oOiy_sendMessage);
}

void Heavy_SoundScraper::cCast_SuYVfIub_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Iopt7YnK_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_a74RPXwG_sendMessage);
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
  cMsg_BYwSiFqd_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_e9vwzbnU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_gAyoEMk9_sendMessage);
}

void Heavy_SoundScraper::cVar_24AXcYGn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_izcdXKzq, 0, m, &cVar_izcdXKzq_sendMessage);
}

void Heavy_SoundScraper::cBinop_gAyoEMk9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_83uf3TZ0, HV_BINOP_SUBTRACT, 1, m, &cBinop_83uf3TZ0_sendMessage);
}

void Heavy_SoundScraper::cVar_Xz5Bh72Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_u7QN2xJi_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_bez6MEJQ_sendMessage);
}

void Heavy_SoundScraper::cBinop_i2sWEAqS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_XHTKk4op_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_iMw3JeXZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_3vMJ3ti6_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSlice_4qt3HSST_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_zLOIMMzk_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_7GkuHEDs_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_zLOIMMzk_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_7GkuHEDs_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_BFERekNs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_MDlB0Uve_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_MDlB0Uve_sendMessage(_c, 0, m);
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
      cSlice_onMessage(_c, &Context(_c)->cSlice_BFERekNs, 0, m, &cSlice_BFERekNs_sendMessage);
      break;
    }
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_4qt3HSST, 0, m, &cSlice_4qt3HSST_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_pCdhdlef_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_zWOm0NvF, 0, m, &cSlice_zWOm0NvF_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_zRH4yHyo, 0, m, &cSlice_zRH4yHyo_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_d4SSKImG_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_iMw3JeXZ_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cVar_GfCKnBz5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_83uf3TZ0, HV_BINOP_SUBTRACT, 0, m, &cBinop_83uf3TZ0_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_LESS_THAN_EQL, 0.0f, 0, m, &cBinop_i2sWEAqS_sendMessage);
}

void Heavy_SoundScraper::cSlice_zRH4yHyo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_SZLN7VJY_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_OnXbEHIO_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_zWOm0NvF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_u7QN2xJi_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_bez6MEJQ_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cCast_pCdhdlef_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Xz5Bh72Y, 0, m, &cVar_Xz5Bh72Y_sendMessage);
}

void Heavy_SoundScraper::cBinop_pJnY0ooD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_UZP5YOBU_sendMessage);
}

void Heavy_SoundScraper::cMsg_q6P4Fhjl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 20.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_e9vwzbnU, HV_BINOP_MULTIPLY, 0, m, &cBinop_e9vwzbnU_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_JIm1oOiy, HV_BINOP_DIVIDE, 1, m, &cBinop_JIm1oOiy_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_UgLkOSfA, 0, m, &cVar_UgLkOSfA_sendMessage);
}

void Heavy_SoundScraper::cCast_u7QN2xJi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_pJnY0ooD, HV_BINOP_MULTIPLY, 0, m, &cBinop_pJnY0ooD_sendMessage);
}

void Heavy_SoundScraper::cBinop_uZzF3Ixh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_izcdXKzq, 1, m, &cVar_izcdXKzq_sendMessage);
}

void Heavy_SoundScraper::cVar_wMvdCCPl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_wxEDt9Ux_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_yHzGJqcW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_GiHmVh9X, HV_BINOP_ADD, 1, m, &cBinop_GiHmVh9X_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_uZzF3Ixh, HV_BINOP_ADD, 1, m, &cBinop_uZzF3Ixh_sendMessage);
}

void Heavy_SoundScraper::cCast_zLOIMMzk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_MDlB0Uve_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_QKeJjtvr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, -1.0f, 0, m, &cBinop_WsWzdNjF_sendMessage);
}

void Heavy_SoundScraper::cBinop_WsWzdNjF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_gJI5XJwD, m);
}

void Heavy_SoundScraper::cVar_02AHW0Bq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_mmnyt39j_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_XJwhKb1l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_BvHUiFWi, m);
}

void Heavy_SoundScraper::cSystem_go72n3cB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_ywh5Astp_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_vqZaoEA2, m);
}

void Heavy_SoundScraper::cMsg_mmnyt39j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_go72n3cB_sendMessage);
}

void Heavy_SoundScraper::cSystem_r5QMKXHk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_XJwhKb1l_sendMessage);
}

void Heavy_SoundScraper::cMsg_w4V5NSG4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_r5QMKXHk_sendMessage);
}

void Heavy_SoundScraper::cBinop_ywh5Astp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_eOHSLqSm, m);
}

void Heavy_SoundScraper::cBinop_0B0Lib5T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_tq2zCPOa_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_8gEUlKK0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_8gEUlKK0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_9E0G1t33, 0, m, &cDelay_9E0G1t33_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_8gEUlKK0, 0, m, &cDelay_8gEUlKK0_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_fO5JNITB, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_9E0G1t33_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_9E0G1t33, m);
  cMsg_uPF21F3t_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_KB1XW69P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_9E0G1t33, 2, m, &cDelay_9E0G1t33_sendMessage);
}

void Heavy_SoundScraper::cCast_TSENKbWz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_8gEUlKK0, 0, m, &cDelay_8gEUlKK0_sendMessage);
}

void Heavy_SoundScraper::hTable_TnZjyknh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_KB1XW69P_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_8gEUlKK0, 2, m, &cDelay_8gEUlKK0_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_TSENKbWz_sendMessage);
}

void Heavy_SoundScraper::cBinop_Tv8sv2VF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 200.0f, 0, m, &cBinop_0B0Lib5T_sendMessage);
}

void Heavy_SoundScraper::cMsg_VyRFaIWy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_fO5JNITB, 1, m, NULL);
}

void Heavy_SoundScraper::cMsg_EW9QKgcB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_SR7hPznG_sendMessage);
}

void Heavy_SoundScraper::cSystem_SR7hPznG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_Tv8sv2VF_sendMessage);
}

void Heavy_SoundScraper::cMsg_tq2zCPOa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_TnZjyknh, 0, m, &hTable_TnZjyknh_sendMessage);
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
      cMsg_VyRFaIWy_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cMsg_uPF21F3t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_TnZjyknh, 0, m, &hTable_TnZjyknh_sendMessage);
}

void Heavy_SoundScraper::cMsg_OxLBFjtH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 20.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_JxCbhdLP, 0, m, NULL);
}

void Heavy_SoundScraper::cVar_ToE5dgSY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_OxLBFjtH_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_LQVVX95x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_NabON11v_sendMessage);
}

void Heavy_SoundScraper::cMsg_ORLQgjdS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_tpsURXEj_sendMessage);
}

void Heavy_SoundScraper::cBinop_tpsURXEj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_LQVVX95x, HV_BINOP_MULTIPLY, 1, m, &cBinop_LQVVX95x_sendMessage);
}

void Heavy_SoundScraper::cMsg_Q2XDi7go_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Qfn39Lqf_sendMessage);
}

void Heavy_SoundScraper::cSystem_Qfn39Lqf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ORLQgjdS_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_Z1nbb8tR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_dcmGhIc0, m);
}

void Heavy_SoundScraper::cVar_8O9LuJpY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_LQVVX95x, HV_BINOP_MULTIPLY, 0, m, &cBinop_LQVVX95x_sendMessage);
}

void Heavy_SoundScraper::cBinop_NabON11v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_lbIiWvQj_sendMessage);
}

void Heavy_SoundScraper::cBinop_lbIiWvQj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_Z1nbb8tR_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_phgJDijJ, m);
}

void Heavy_SoundScraper::cBinop_32B8qYsX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_dPpdiuon_sendMessage);
}

void Heavy_SoundScraper::cBinop_BCdM9s6b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_Xy9VOMEQ_sendMessage);
}

void Heavy_SoundScraper::cBinop_5vw9qF0Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_32B8qYsX_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_HoklGSkr_sendMessage);
}

void Heavy_SoundScraper::cBinop_VTkRp2LD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_5vw9qF0Z_sendMessage);
}

void Heavy_SoundScraper::cBinop_HoklGSkr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_4hlqXWkV, m);
}

void Heavy_SoundScraper::cBinop_Xy9VOMEQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_YDIiTzgP, HV_BINOP_DIVIDE, 0, m, &cBinop_YDIiTzgP_sendMessage);
}

void Heavy_SoundScraper::cBinop_YDIiTzgP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_hwhHDvGW_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_dPpdiuon_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_Rf6pjyZ3, m);
}

void Heavy_SoundScraper::cMsg_hwhHDvGW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_tyHRiS7V_sendMessage);
}

void Heavy_SoundScraper::cVar_LP6LfgeT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_BCdM9s6b_sendMessage);
}

void Heavy_SoundScraper::cSystem_4w972H37_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_YDIiTzgP, HV_BINOP_DIVIDE, 1, m, &cBinop_YDIiTzgP_sendMessage);
}

void Heavy_SoundScraper::cMsg_MKYi30Ru_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_4w972H37_sendMessage);
}

void Heavy_SoundScraper::cBinop_tyHRiS7V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_VTkRp2LD_sendMessage);
}

void Heavy_SoundScraper::cMsg_xUbeWThw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cMsg_OxLBFjtH_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_qcUSrU6Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_1gpI2VKu, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_9A748jNT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_QO7efEPb_sendMessage(_c, 0, m);
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
      cBinop_onMessage(_c, &Context(_c)->cBinop_l2GRtja7, HV_BINOP_MULTIPLY, 0, m, &cBinop_l2GRtja7_sendMessage);
      cBinop_onMessage(_c, &Context(_c)->cBinop_R0RVnxSW, HV_BINOP_DIVIDE, 1, m, &cBinop_R0RVnxSW_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_uhKWI9pg, 0, m, &cVar_uhKWI9pg_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_7kq2ete8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_xzVUNQf1_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_jjMvDeh5, HV_BINOP_ADD, 0, m, &cBinop_jjMvDeh5_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_T6MbkFIw, 1, m, &cVar_T6MbkFIw_sendMessage);
}

void Heavy_SoundScraper::cMsg_9LoxOxwg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_v15NtXMm_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cVar_T6MbkFIw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_shArdhDY, HV_BINOP_ADD, 0, m, &cBinop_shArdhDY_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_jjMvDeh5, HV_BINOP_ADD, 0, m, &cBinop_jjMvDeh5_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_3fkpojuH, 0, m, &cVar_3fkpojuH_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_lm1HusbR, m);
}

void Heavy_SoundScraper::cBinop_BSZDvBMc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_lyqlEnL0_sendMessage);
}

void Heavy_SoundScraper::cSlice_7tS212Pu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_BsAy2F7t_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_MYoPVutt_sendMessage);
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
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_FTV48A85_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_zFqHlvUz_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cCast_BsAy2F7t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_BSZDvBMc, HV_BINOP_MULTIPLY, 0, m, &cBinop_BSZDvBMc_sendMessage);
}

void Heavy_SoundScraper::cSlice_LqnklgtN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_Ts7aByXn_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_Ts7aByXn_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_VKfvcohg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Tfh3ugTx_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_7kq2ete8_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Tfh3ugTx_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_7kq2ete8_sendMessage);
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
      cSlice_onMessage(_c, &Context(_c)->cSlice_LqnklgtN, 0, m, &cSlice_LqnklgtN_sendMessage);
      break;
    }
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_VKfvcohg, 0, m, &cSlice_VKfvcohg_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_lSi6P69n_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_7tS212Pu, 0, m, &cSlice_7tS212Pu_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_Wg55a7ii, 0, m, &cSlice_Wg55a7ii_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_lK794eo9_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_LNxXOEJe_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_E9HsfONy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_jjMvDeh5, HV_BINOP_ADD, 1, m, &cBinop_jjMvDeh5_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_shArdhDY, HV_BINOP_ADD, 1, m, &cBinop_shArdhDY_sendMessage);
}

void Heavy_SoundScraper::cCast_FTV48A85_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_f7zF4mz2, 1, m, &cVar_f7zF4mz2_sendMessage);
}

void Heavy_SoundScraper::cCast_LNxXOEJe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_u1yWyNXr_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_LY9fZofX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_YMIrQnLm, HV_BINOP_SUBTRACT, 1, m, &cBinop_YMIrQnLm_sendMessage);
}

void Heavy_SoundScraper::cCast_MYoPVutt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_R0RVnxSW, HV_BINOP_DIVIDE, 0, m, &cBinop_R0RVnxSW_sendMessage);
}

void Heavy_SoundScraper::cCast_PPmf2KhU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_hiFY5jud_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_SWqSc0Mi, 0, m, &cDelay_SWqSc0Mi_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_vmVgUo89, 0, m, &cVar_vmVgUo89_sendMessage);
}

void Heavy_SoundScraper::cBinop_KvFKyppH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_LMzhOrc9_sendMessage);
}

void Heavy_SoundScraper::cBinop_LMzhOrc9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_SWqSc0Mi, 2, m, &cDelay_SWqSc0Mi_sendMessage);
}

void Heavy_SoundScraper::cDelay_SWqSc0Mi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_SWqSc0Mi, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_SWqSc0Mi, 0, m, &cDelay_SWqSc0Mi_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_vmVgUo89, 0, m, &cVar_vmVgUo89_sendMessage);
}

void Heavy_SoundScraper::cVar_uhKWI9pg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_KvFKyppH, HV_BINOP_MULTIPLY, 0, m, &cBinop_KvFKyppH_sendMessage);
}

void Heavy_SoundScraper::cMsg_hiFY5jud_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_SWqSc0Mi, 0, m, &cDelay_SWqSc0Mi_sendMessage);
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
      cMsg_hiFY5jud_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_hiFY5jud_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_PPmf2KhU_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_xKIXZsDW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_KvFKyppH, HV_BINOP_MULTIPLY, 1, m, &cBinop_KvFKyppH_sendMessage);
}

void Heavy_SoundScraper::cMsg_A2qdipWP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_kKgj26mj_sendMessage);
}

void Heavy_SoundScraper::cSystem_kKgj26mj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_xKIXZsDW_sendMessage);
}

void Heavy_SoundScraper::cMsg_QO7efEPb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 20.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_l2GRtja7, HV_BINOP_MULTIPLY, 0, m, &cBinop_l2GRtja7_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_R0RVnxSW, HV_BINOP_DIVIDE, 1, m, &cBinop_R0RVnxSW_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_uhKWI9pg, 0, m, &cVar_uhKWI9pg_sendMessage);
}

void Heavy_SoundScraper::cBinop_R0RVnxSW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_E9HsfONy, HV_BINOP_DIVIDE, 1, m, &cBinop_E9HsfONy_sendMessage);
}

void Heavy_SoundScraper::cVar_ZnO3YYb7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_t8LOSXak_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cVar_AYuVqWOR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_iOH8jAno, HV_BINOP_SUBTRACT, 1, m, &cBinop_iOH8jAno_sendMessage);
}

void Heavy_SoundScraper::cCast_Tfh3ugTx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Ts7aByXn_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_Ts7aByXn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_v15NtXMm_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_YMIrQnLm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_vmVgUo89, 1, m, &cVar_vmVgUo89_sendMessage);
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
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_s8Pm7vIR_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_g98VX1mT_sendMessage);
}

void Heavy_SoundScraper::cCast_QFhrvcEt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_T6MbkFIw, 0, m, &cVar_T6MbkFIw_sendMessage);
}

void Heavy_SoundScraper::cCast_g98VX1mT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_f7zF4mz2, 0, m, &cVar_f7zF4mz2_sendMessage);
}

void Heavy_SoundScraper::cBinop_iOH8jAno_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_E9HsfONy, HV_BINOP_DIVIDE, 0, m, &cBinop_E9HsfONy_sendMessage);
}

void Heavy_SoundScraper::cVar_xWahpDBV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_BsAy2F7t_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_MYoPVutt_sendMessage);
}

void Heavy_SoundScraper::cBinop_jjMvDeh5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_AYuVqWOR, 0, m, &cVar_AYuVqWOR_sendMessage);
}

void Heavy_SoundScraper::cBinop_l2GRtja7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_LY9fZofX_sendMessage);
}

void Heavy_SoundScraper::cCast_lK794eo9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_9LoxOxwg_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_lSi6P69n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_xWahpDBV, 0, m, &cVar_xWahpDBV_sendMessage);
}

void Heavy_SoundScraper::cMsg_lmaPq03S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_v15NtXMm_onMessage(_c, NULL, 0, m, NULL);
  cBinop_onMessage(_c, &Context(_c)->cBinop_jjMvDeh5, HV_BINOP_ADD, 1, m, &cBinop_jjMvDeh5_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_shArdhDY, HV_BINOP_ADD, 1, m, &cBinop_shArdhDY_sendMessage);
}

void Heavy_SoundScraper::cBinop_lyqlEnL0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_vmVgUo89, 1, m, &cVar_vmVgUo89_sendMessage);
}

void Heavy_SoundScraper::cVar_f7zF4mz2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_T6MbkFIw, 0, m, &cVar_T6MbkFIw_sendMessage);
}

void Heavy_SoundScraper::cVar_vmVgUo89_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_YMIrQnLm, HV_BINOP_SUBTRACT, 0, m, &cBinop_YMIrQnLm_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_LESS_THAN_EQL, 0.0f, 0, m, &cBinop_qlerrb7I_sendMessage);
}

void Heavy_SoundScraper::cBinop_qlerrb7I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_BK4qaso8_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_s8Pm7vIR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_lmaPq03S_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_shArdhDY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_T6MbkFIw, 1, m, &cVar_T6MbkFIw_sendMessage);
}

void Heavy_SoundScraper::cMsg_u1yWyNXr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_xWahpDBV, 1, m, &cVar_xWahpDBV_sendMessage);
}

void Heavy_SoundScraper::cSystem_mszd6exa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_l2GRtja7, HV_BINOP_MULTIPLY, 1, m, &cBinop_l2GRtja7_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_BSZDvBMc, HV_BINOP_MULTIPLY, 1, m, &cBinop_BSZDvBMc_sendMessage);
}

void Heavy_SoundScraper::cMsg_yqNnWETm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_mszd6exa_sendMessage);
}

void Heavy_SoundScraper::cCast_xzVUNQf1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_lmaPq03S_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_zFqHlvUz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_iOH8jAno, HV_BINOP_SUBTRACT, 0, m, &cBinop_iOH8jAno_sendMessage);
}

void Heavy_SoundScraper::cUnop_6tPPiVs4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 10.0f, 0, m, &cBinop_zyB5iGBX_sendMessage);
}

void Heavy_SoundScraper::cBinop_AFVWNj5e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_6tPPiVs4_sendMessage);
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
      cSlice_onMessage(_c, &Context(_c)->cSlice_rDm5AsVt, 0, m, &cSlice_rDm5AsVt_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_uTcHPrZn, 0, m, &cRandom_uTcHPrZn_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cSlice_rDm5AsVt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_uTcHPrZn, 1, m, &cRandom_uTcHPrZn_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cRandom_uTcHPrZn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 80.0f, 0, m, &cBinop_AFVWNj5e_sendMessage);
}

void Heavy_SoundScraper::cBinop_zyB5iGBX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_CbckDMR8_sendMessage);
}

void Heavy_SoundScraper::cBinop_AO1ilv7M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 100.0f, 0, m, &cBinop_dWO77fxm_sendMessage);
}

void Heavy_SoundScraper::cBinop_KOpgzSlu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_TcceSJpW, 1, m, &cIf_TcceSJpW_sendMessage);
}

void Heavy_SoundScraper::cBinop_QoyC2qAv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_AsD9WQLh_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_iKxiqkmm_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_XzZevGjy_sendMessage);
}

void Heavy_SoundScraper::cCast_R3byJKy5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_TcceSJpW, 0, m, &cIf_TcceSJpW_sendMessage);
}

void Heavy_SoundScraper::cMsg_SqvdjTIO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cMsg_AsD9WQLh_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_iKxiqkmm_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_XzZevGjy_sendMessage);
}

void Heavy_SoundScraper::cIf_TcceSJpW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_SqvdjTIO_sendMessage(_c, 0, m);
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
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_QoyC2qAv_sendMessage);
}

void Heavy_SoundScraper::cUnop_gkZkViIT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_AO1ilv7M_sendMessage);
}

void Heavy_SoundScraper::cCast_x1HTqWzf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_KOpgzSlu_sendMessage);
}

void Heavy_SoundScraper::cBinop_fzazrusm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_x1HTqWzf_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_R3byJKy5_sendMessage);
}

void Heavy_SoundScraper::cBinop_jFpSjkXl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_fzazrusm_sendMessage);
}

void Heavy_SoundScraper::cBinop_6l8gQ9R0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_g49bXLsX, 0, m, &cPack_g49bXLsX_sendMessage);
}

void Heavy_SoundScraper::cBinop_2tfTFFNa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_IvnndJbs, 1, m, &cIf_IvnndJbs_sendMessage);
}

void Heavy_SoundScraper::cBinop_6jSAZUUK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.125f, 0, m, &cBinop_BXf3gGB2_sendMessage);
}

void Heavy_SoundScraper::cBinop_6sv97Pn6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6jSAZUUK, HV_BINOP_POW, 1, m, &cBinop_6jSAZUUK_sendMessage);
  cMsg_fV3JiwAZ_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_8tMHmxhJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_6sv97Pn6_sendMessage);
}

void Heavy_SoundScraper::cIf_IvnndJbs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_kvtMu9JI_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_QGBaQ4kR_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_QGBaQ4kR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_8tMHmxhJ_sendMessage);
}

void Heavy_SoundScraper::cCast_SSO3cT3p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_2tfTFFNa_sendMessage);
}

void Heavy_SoundScraper::cMsg_fV3JiwAZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_6jSAZUUK, HV_BINOP_POW, 0, m, &cBinop_6jSAZUUK_sendMessage);
}

void Heavy_SoundScraper::cMsg_kvtMu9JI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.125f, 0, m, &cBinop_BXf3gGB2_sendMessage);
}

void Heavy_SoundScraper::cCast_x1IggyER_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_IvnndJbs, 0, m, &cIf_IvnndJbs_sendMessage);
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
      cMsg_PviVOrJv_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_BApdDvzh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 58.6435f, 0, m, &cBinop_M5VfDX3q_sendMessage);
}

void Heavy_SoundScraper::cBinop_M5VfDX3q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_SkHBIxuB_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_PviVOrJv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_tI1NGy9l, 1, m, NULL);
}

void Heavy_SoundScraper::cMsg_SkHBIxuB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_sOQFACjd, 0, m, &hTable_sOQFACjd_sendMessage);
}

void Heavy_SoundScraper::cCast_WNL1KsJd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_dpHMaRhP, 0, m, &cDelay_dpHMaRhP_sendMessage);
}

void Heavy_SoundScraper::cMsg_R2lAHbnV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_cK6PJVWh_sendMessage);
}

void Heavy_SoundScraper::cSystem_cK6PJVWh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_BApdDvzh_sendMessage);
}

void Heavy_SoundScraper::cDelay_dpHMaRhP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_dpHMaRhP, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_eDws7itv, 0, m, &cDelay_eDws7itv_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_dpHMaRhP, 0, m, &cDelay_dpHMaRhP_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_tI1NGy9l, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_eDws7itv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_eDws7itv, m);
  cMsg_wBfaLUl9_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_r31yL1xH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_eDws7itv, 2, m, &cDelay_eDws7itv_sendMessage);
}

void Heavy_SoundScraper::hTable_sOQFACjd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_r31yL1xH_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_dpHMaRhP, 2, m, &cDelay_dpHMaRhP_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_WNL1KsJd_sendMessage);
}

void Heavy_SoundScraper::cMsg_wBfaLUl9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_sOQFACjd, 0, m, &hTable_sOQFACjd_sendMessage);
}

void Heavy_SoundScraper::cBinop_BXf3gGB2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_qr0uTD6a, 0, m, &cPack_qr0uTD6a_sendMessage);
}

void Heavy_SoundScraper::cBinop_2mK0yV9t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_8HpyMCtP_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_5AQtq8SZ, m);
}

void Heavy_SoundScraper::cBinop_oPTmTd9l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_2mK0yV9t_sendMessage);
}

void Heavy_SoundScraper::cBinop_8HpyMCtP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_rJYLNPto, m);
}

void Heavy_SoundScraper::cVar_4vurxjLg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_biJIdm5H, HV_BINOP_MULTIPLY, 0, m, &cBinop_biJIdm5H_sendMessage);
}

void Heavy_SoundScraper::cBinop_D4yvKrbp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_biJIdm5H, HV_BINOP_MULTIPLY, 1, m, &cBinop_biJIdm5H_sendMessage);
}

void Heavy_SoundScraper::cBinop_biJIdm5H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_oPTmTd9l_sendMessage);
}

void Heavy_SoundScraper::cMsg_kCS2sOHu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_D4yvKrbp_sendMessage);
}

void Heavy_SoundScraper::cMsg_0JdY56Zn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_HvwSu4XL_sendMessage);
}

void Heavy_SoundScraper::cSystem_HvwSu4XL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_kCS2sOHu_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_KIsxwZ1J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_KmqMAnhB, 0, m, NULL);
}

void Heavy_SoundScraper::cMsg_NQJ6ZoM6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 3000.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_A5ugVD1y, 0, m, &cVar_A5ugVD1y_sendMessage);
}

void Heavy_SoundScraper::cIf_Th0OAbYU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_NQJ6ZoM6_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cVar_onMessage(_c, &Context(_c)->cVar_A5ugVD1y, 0, m, &cVar_A5ugVD1y_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_xvcGTgrh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_Th0OAbYU, 1, m, &cIf_Th0OAbYU_sendMessage);
}

void Heavy_SoundScraper::cBinop_4v6OMUIw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_j83WiwVQ, HV_BINOP_SUBTRACT, 1, m, &cBinop_j83WiwVQ_sendMessage);
}

void Heavy_SoundScraper::sTabread_95dkUskH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_zUiLah7o, HV_BINOP_SUBTRACT, 0, m, &cBinop_zUiLah7o_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cMsg_9QBtFkpz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_LHeEEgBN_sendMessage);
}

void Heavy_SoundScraper::cDelay_ADk7FYJg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_ADk7FYJg, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_95dkUskH, 0, m, &sTabread_95dkUskH_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ADk7FYJg, 0, m, &cDelay_ADk7FYJg_sendMessage);
}

void Heavy_SoundScraper::cCast_EI15LN6J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_RkOG7nu9, 0, m, &cVar_RkOG7nu9_sendMessage);
  cMsg_7gFXNw8h_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_bsldNoGU, 0, m, &cTabhead_bsldNoGU_sendMessage);
}

void Heavy_SoundScraper::cSystem_LHeEEgBN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_zUiLah7o, HV_BINOP_SUBTRACT, 1, m, &cBinop_zUiLah7o_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ADk7FYJg, 2, m, &cDelay_ADk7FYJg_sendMessage);
}

void Heavy_SoundScraper::cMsg_N4xjTIvI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_tcpHpV75, 0, m, &cDelay_tcpHpV75_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ADk7FYJg, 0, m, &cDelay_ADk7FYJg_sendMessage);
}

void Heavy_SoundScraper::cBinop_OVGgm29j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_dR3Issgm, HV_BINOP_MULTIPLY, 0, m, &cBinop_dR3Issgm_sendMessage);
}

void Heavy_SoundScraper::cVar_RkOG7nu9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_9QBtFkpz_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cTabhead_bsldNoGU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_j83WiwVQ, HV_BINOP_SUBTRACT, 0, m, &cBinop_j83WiwVQ_sendMessage);
}

void Heavy_SoundScraper::cBinop_dR3Issgm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4v6OMUIw, HV_BINOP_MAX, 0, m, &cBinop_4v6OMUIw_sendMessage);
}

void Heavy_SoundScraper::cBinop_fSMJ017l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_tcpHpV75, 2, m, &cDelay_tcpHpV75_sendMessage);
}

void Heavy_SoundScraper::cBinop_j83WiwVQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_N4xjTIvI_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_95dkUskH, 0, m, &sTabread_95dkUskH_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_xZBMFHfM_sendMessage);
}

void Heavy_SoundScraper::cMsg_7gFXNw8h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_TUpLUGrK_sendMessage);
}

void Heavy_SoundScraper::cSystem_TUpLUGrK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_OVGgm29j_sendMessage);
}

void Heavy_SoundScraper::cDelay_tcpHpV75_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_tcpHpV75, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ADk7FYJg, 0, m, &cDelay_ADk7FYJg_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_95dkUskH, 0, m, &sTabread_95dkUskH_sendMessage);
}

void Heavy_SoundScraper::cMsg_ulUdFhXJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_4v6OMUIw, HV_BINOP_MAX, 1, m, &cBinop_4v6OMUIw_sendMessage);
}

void Heavy_SoundScraper::cCast_xZBMFHfM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_tcpHpV75, 0, m, &cDelay_tcpHpV75_sendMessage);
}

void Heavy_SoundScraper::cBinop_zUiLah7o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_fSMJ017l_sendMessage);
}

void Heavy_SoundScraper::cBinop_MmFxET5O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_HkIt0OkD, m);
}

void Heavy_SoundScraper::cMsg_7pzPBn0U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_Zf8XIbKC_sendMessage);
}

void Heavy_SoundScraper::cMsg_0q9DEeWE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_oLyqp723_sendMessage);
}

void Heavy_SoundScraper::cSystem_oLyqp723_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_7pzPBn0U_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_Zf8XIbKC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_nVbthqFU, HV_BINOP_MULTIPLY, 1, m, &cBinop_nVbthqFU_sendMessage);
}

void Heavy_SoundScraper::cBinop_nVbthqFU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_OZUViTCM_sendMessage);
}

void Heavy_SoundScraper::cBinop_OZUViTCM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_wlTj1r3f_sendMessage);
}

void Heavy_SoundScraper::cBinop_wlTj1r3f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_MmFxET5O_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_cMXIMxQ6, m);
}

void Heavy_SoundScraper::cVar_TbXZlErM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_nVbthqFU, HV_BINOP_MULTIPLY, 0, m, &cBinop_nVbthqFU_sendMessage);
}

void Heavy_SoundScraper::cBinop_EH60Ozpi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ELbL87j9, 0, m, &cVar_ELbL87j9_sendMessage);
}

void Heavy_SoundScraper::cBinop_cSd6gTbo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_EH60Ozpi_sendMessage);
}

void Heavy_SoundScraper::cVar_ELbL87j9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.01f, 0, m, &cBinop_6l8gQ9R0_sendMessage);
}

void Heavy_SoundScraper::cVar_aVE88ycb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 100.0f, 0, m, &cBinop_97Vqbe7c_sendMessage);
}

void Heavy_SoundScraper::cMsg_4cVpYjLo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_t4wmRcyk, 2, m, &cDelay_t4wmRcyk_sendMessage);
}

void Heavy_SoundScraper::cBinop_5YO3SSRO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_7cdUX4Hn_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_7cdUX4Hn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_yD5jEq6S, 0, m, &hTable_yD5jEq6S_sendMessage);
}

void Heavy_SoundScraper::cMsg_DiGPtKNE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_yD5jEq6S, 0, m, &hTable_yD5jEq6S_sendMessage);
}

void Heavy_SoundScraper::cDelay_EGWAp475_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_EGWAp475, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_t4wmRcyk, 0, m, &cDelay_t4wmRcyk_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_EGWAp475, 0, m, &cDelay_EGWAp475_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_FOWYkAfr, 1, m, NULL);
}

void Heavy_SoundScraper::cCast_KNLgOMny_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_EGWAp475, 0, m, &cDelay_EGWAp475_sendMessage);
}

void Heavy_SoundScraper::cMsg_12fulvDw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_3F3lBHb1_sendMessage);
}

void Heavy_SoundScraper::cSystem_3F3lBHb1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_dIkB0qZx_sendMessage);
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
      cMsg_kOykDgdy_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_dIkB0qZx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 86.1244f, 0, m, &cBinop_5YO3SSRO_sendMessage);
}

void Heavy_SoundScraper::cMsg_kOykDgdy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_FOWYkAfr, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_t4wmRcyk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_t4wmRcyk, m);
  cMsg_DiGPtKNE_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_yD5jEq6S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_4cVpYjLo_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_EGWAp475, 2, m, &cDelay_EGWAp475_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_KNLgOMny_sendMessage);
}

void Heavy_SoundScraper::cBinop_407qBpLq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_BuZxgp01_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_4G3cDlx2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_4G3cDlx2, m);
  cMsg_Dtt3tvSP_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_4sH5AWzX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_4sH5AWzX, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_4G3cDlx2, 0, m, &cDelay_4G3cDlx2_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_4sH5AWzX, 0, m, &cDelay_4sH5AWzX_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_KVJjR7db, 1, m, NULL);
}

void Heavy_SoundScraper::cCast_6GFjErHn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_4sH5AWzX, 0, m, &cDelay_4sH5AWzX_sendMessage);
}

void Heavy_SoundScraper::cBinop_6P5vl3Hr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 25.796f, 0, m, &cBinop_407qBpLq_sendMessage);
}

void Heavy_SoundScraper::cMsg_BuZxgp01_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_KTYymZwO, 0, m, &hTable_KTYymZwO_sendMessage);
}

void Heavy_SoundScraper::cMsg_Dtt3tvSP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_KTYymZwO, 0, m, &hTable_KTYymZwO_sendMessage);
}

void Heavy_SoundScraper::hTable_KTYymZwO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_VCACTapW_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_4sH5AWzX, 2, m, &cDelay_4sH5AWzX_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_6GFjErHn_sendMessage);
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
      cMsg_U5rs5YGR_sendMessage(_c, 0, m);
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
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_KVJjR7db, 1, m, NULL);
}

void Heavy_SoundScraper::cMsg_VCACTapW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_4G3cDlx2, 2, m, &cDelay_4G3cDlx2_sendMessage);
}

void Heavy_SoundScraper::cMsg_SY9tKhsl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_brs7OAau_sendMessage);
}

void Heavy_SoundScraper::cSystem_brs7OAau_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_6P5vl3Hr_sendMessage);
}

void Heavy_SoundScraper::cMsg_6kxarfdK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_MHDSXfwo, 2, m, &cDelay_MHDSXfwo_sendMessage);
}

void Heavy_SoundScraper::cMsg_9EIoWekT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_rYsjrFF2, 1, m, NULL);
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
      cMsg_9EIoWekT_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_CIeuzQ4i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_kf0sMJ7C, 0, m, &cDelay_kf0sMJ7C_sendMessage);
}

void Heavy_SoundScraper::cSystem_MCS8zi8x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_j2IO1XVu_sendMessage);
}

void Heavy_SoundScraper::cMsg_kg5dYE5P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_MCS8zi8x_sendMessage);
}

void Heavy_SoundScraper::cDelay_MHDSXfwo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_MHDSXfwo, m);
  cMsg_Z5VV9jsY_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_O473cBaw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_amukS8d7, 0, m, &hTable_amukS8d7_sendMessage);
}

void Heavy_SoundScraper::cMsg_Z5VV9jsY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_amukS8d7, 0, m, &hTable_amukS8d7_sendMessage);
}

void Heavy_SoundScraper::hTable_amukS8d7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_6kxarfdK_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_kf0sMJ7C, 2, m, &cDelay_kf0sMJ7C_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_CIeuzQ4i_sendMessage);
}

void Heavy_SoundScraper::cBinop_j2IO1XVu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 75.2546f, 0, m, &cBinop_zYWdeEVl_sendMessage);
}

void Heavy_SoundScraper::cDelay_kf0sMJ7C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_kf0sMJ7C, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_MHDSXfwo, 0, m, &cDelay_MHDSXfwo_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_kf0sMJ7C, 0, m, &cDelay_kf0sMJ7C_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_rYsjrFF2, 1, m, NULL);
}

void Heavy_SoundScraper::cBinop_zYWdeEVl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_O473cBaw_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cTabhead_238LxNEE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_HoqWlP8S, HV_BINOP_SUBTRACT, 0, m, &cBinop_HoqWlP8S_sendMessage);
}

void Heavy_SoundScraper::cBinop_2IQ4pNcG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Rgcc4RTY, 2, m, &cDelay_Rgcc4RTY_sendMessage);
}

void Heavy_SoundScraper::cCast_ELhLweBN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Rgcc4RTY, 0, m, &cDelay_Rgcc4RTY_sendMessage);
}

void Heavy_SoundScraper::cMsg_GzHvjv97_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_fKzgxDLi_sendMessage);
}

void Heavy_SoundScraper::cBinop_HoqWlP8S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_wgg8oiEx_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_O6jFGsul, 0, m, &sTabread_O6jFGsul_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ELhLweBN_sendMessage);
}

void Heavy_SoundScraper::cBinop_LZqhwFC8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_QG8NKBLQ, HV_BINOP_MAX, 0, m, &cBinop_QG8NKBLQ_sendMessage);
}

void Heavy_SoundScraper::sTabread_O6jFGsul_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_zQyxLGBE, HV_BINOP_SUBTRACT, 0, m, &cBinop_zQyxLGBE_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_QG8NKBLQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_HoqWlP8S, HV_BINOP_SUBTRACT, 1, m, &cBinop_HoqWlP8S_sendMessage);
}

void Heavy_SoundScraper::cDelay_Rgcc4RTY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Rgcc4RTY, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_otqKPZHd, 0, m, &cDelay_otqKPZHd_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_O6jFGsul, 0, m, &sTabread_O6jFGsul_sendMessage);
}

void Heavy_SoundScraper::cMsg_aAJKAjk9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_QG8NKBLQ, HV_BINOP_MAX, 1, m, &cBinop_QG8NKBLQ_sendMessage);
}

void Heavy_SoundScraper::cSystem_fKzgxDLi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_zQyxLGBE, HV_BINOP_SUBTRACT, 1, m, &cBinop_zQyxLGBE_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_otqKPZHd, 2, m, &cDelay_otqKPZHd_sendMessage);
}

void Heavy_SoundScraper::cBinop_gMStXXzI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_LZqhwFC8, HV_BINOP_MULTIPLY, 0, m, &cBinop_LZqhwFC8_sendMessage);
}

void Heavy_SoundScraper::cMsg_EusnHKYo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_nEg3xGhJ_sendMessage);
}

void Heavy_SoundScraper::cSystem_nEg3xGhJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_gMStXXzI_sendMessage);
}

void Heavy_SoundScraper::cDelay_otqKPZHd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_otqKPZHd, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_O6jFGsul, 0, m, &sTabread_O6jFGsul_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_otqKPZHd, 0, m, &cDelay_otqKPZHd_sendMessage);
}

void Heavy_SoundScraper::cCast_tWCQi8Gy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_uTpHW20o, 0, m, &cVar_uTpHW20o_sendMessage);
  cMsg_EusnHKYo_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_238LxNEE, 0, m, &cTabhead_238LxNEE_sendMessage);
}

void Heavy_SoundScraper::cVar_uTpHW20o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_GzHvjv97_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_wgg8oiEx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_Rgcc4RTY, 0, m, &cDelay_Rgcc4RTY_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_otqKPZHd, 0, m, &cDelay_otqKPZHd_sendMessage);
}

void Heavy_SoundScraper::cBinop_zQyxLGBE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_2IQ4pNcG_sendMessage);
}

void Heavy_SoundScraper::cMsg_9DhEmGRi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_XBJx0zKQ, 2, m, &cDelay_XBJx0zKQ_sendMessage);
}

void Heavy_SoundScraper::cMsg_I5fAbdj7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_N3IEEdKO, 0, m, &hTable_N3IEEdKO_sendMessage);
}

void Heavy_SoundScraper::cMsg_JumJtWiX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_Z9aUjTyP, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_KGSvr8CU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_KGSvr8CU, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_XBJx0zKQ, 0, m, &cDelay_XBJx0zKQ_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_KGSvr8CU, 0, m, &cDelay_KGSvr8CU_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_Z9aUjTyP, 1, m, NULL);
}

void Heavy_SoundScraper::hTable_N3IEEdKO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_9DhEmGRi_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_KGSvr8CU, 2, m, &cDelay_KGSvr8CU_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_QjzBFJvG_sendMessage);
}

void Heavy_SoundScraper::cCast_QjzBFJvG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_KGSvr8CU, 0, m, &cDelay_KGSvr8CU_sendMessage);
}

void Heavy_SoundScraper::cSystem_PdsKdVyn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_fEuYZbo8_sendMessage);
}

void Heavy_SoundScraper::cMsg_ipJvfpuV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_PdsKdVyn_sendMessage);
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
      cMsg_JumJtWiX_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cDelay_XBJx0zKQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_XBJx0zKQ, m);
  cMsg_Y8Drs0t6_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_Y8Drs0t6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_N3IEEdKO, 0, m, &hTable_N3IEEdKO_sendMessage);
}

void Heavy_SoundScraper::cBinop_fEuYZbo8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 13.645f, 0, m, &cBinop_k3uAO84M_sendMessage);
}

void Heavy_SoundScraper::cBinop_k3uAO84M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_I5fAbdj7_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_1WfFYHQW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_dOELEDhs_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_v5M3Sot5, 0, m, &sTabread_v5M3Sot5_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_AufnJZYS_sendMessage);
}

void Heavy_SoundScraper::cDelay_2hexzHdw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_2hexzHdw, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_v5M3Sot5, 0, m, &sTabread_v5M3Sot5_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_2hexzHdw, 0, m, &cDelay_2hexzHdw_sendMessage);
}

void Heavy_SoundScraper::cMsg_AVK3Y51G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_fBmVL2JY, HV_BINOP_MAX, 1, m, &cBinop_fBmVL2JY_sendMessage);
}

void Heavy_SoundScraper::cCast_AufnJZYS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_tGccaxhl, 0, m, &cDelay_tGccaxhl_sendMessage);
}

void Heavy_SoundScraper::cTabhead_HKIPOkNn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_1WfFYHQW, HV_BINOP_SUBTRACT, 0, m, &cBinop_1WfFYHQW_sendMessage);
}

void Heavy_SoundScraper::cCast_JeRy4QRV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_tMoSExKz, 0, m, &cVar_tMoSExKz_sendMessage);
  cMsg_iNSrJ8qJ_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_HKIPOkNn, 0, m, &cTabhead_HKIPOkNn_sendMessage);
}

void Heavy_SoundScraper::cMsg_OCOl9jhz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_mVJUUq26_sendMessage);
}

void Heavy_SoundScraper::cBinop_Pas39ZzD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_fBmVL2JY, HV_BINOP_MAX, 0, m, &cBinop_fBmVL2JY_sendMessage);
}

void Heavy_SoundScraper::cBinop_RS1dD6wF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Pas39ZzD, HV_BINOP_MULTIPLY, 0, m, &cBinop_Pas39ZzD_sendMessage);
}

void Heavy_SoundScraper::cBinop_Skzrj1bk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_bFgpqR5N_sendMessage);
}

void Heavy_SoundScraper::cBinop_bFgpqR5N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_tGccaxhl, 2, m, &cDelay_tGccaxhl_sendMessage);
}

void Heavy_SoundScraper::cMsg_dOELEDhs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_tGccaxhl, 0, m, &cDelay_tGccaxhl_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_2hexzHdw, 0, m, &cDelay_2hexzHdw_sendMessage);
}

void Heavy_SoundScraper::cBinop_fBmVL2JY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_1WfFYHQW, HV_BINOP_SUBTRACT, 1, m, &cBinop_1WfFYHQW_sendMessage);
}

void Heavy_SoundScraper::cSystem_LMOWpzuc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_RS1dD6wF_sendMessage);
}

void Heavy_SoundScraper::cMsg_iNSrJ8qJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_LMOWpzuc_sendMessage);
}

void Heavy_SoundScraper::cSystem_mVJUUq26_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Skzrj1bk, HV_BINOP_SUBTRACT, 1, m, &cBinop_Skzrj1bk_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_2hexzHdw, 2, m, &cDelay_2hexzHdw_sendMessage);
}

void Heavy_SoundScraper::cDelay_tGccaxhl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_tGccaxhl, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_2hexzHdw, 0, m, &cDelay_2hexzHdw_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_v5M3Sot5, 0, m, &sTabread_v5M3Sot5_sendMessage);
}

void Heavy_SoundScraper::cVar_tMoSExKz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_OCOl9jhz_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::sTabread_v5M3Sot5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_Skzrj1bk, HV_BINOP_SUBTRACT, 0, m, &cBinop_Skzrj1bk_sendMessage);
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

void Heavy_SoundScraper::cSystem_3S0HTQWe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ESjGaIKk, HV_BINOP_SUBTRACT, 1, m, &cBinop_ESjGaIKk_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_2la49ykd, 2, m, &cDelay_2la49ykd_sendMessage);
}

void Heavy_SoundScraper::sTabread_AgyAQgdX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_ESjGaIKk, HV_BINOP_SUBTRACT, 0, m, &cBinop_ESjGaIKk_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_ESjGaIKk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_UiIZVEXg_sendMessage);
}

void Heavy_SoundScraper::cMsg_EbgzOxpE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_FiECT7xg, HV_BINOP_MAX, 1, m, &cBinop_FiECT7xg_sendMessage);
}

void Heavy_SoundScraper::cBinop_FiECT7xg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_mwnNoMXW, HV_BINOP_SUBTRACT, 1, m, &cBinop_mwnNoMXW_sendMessage);
}

void Heavy_SoundScraper::cTabhead_GiSLm0Ve_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_mwnNoMXW, HV_BINOP_SUBTRACT, 0, m, &cBinop_mwnNoMXW_sendMessage);
}

void Heavy_SoundScraper::cMsg_JRTajrdJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_3S0HTQWe_sendMessage);
}

void Heavy_SoundScraper::cBinop_NcSTL6If_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_yTu1fMvI, HV_BINOP_MULTIPLY, 0, m, &cBinop_yTu1fMvI_sendMessage);
}

void Heavy_SoundScraper::cVar_Nn2QYeSd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_JRTajrdJ_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_RlPbsFdD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_mbFM2wzE, 0, m, &cDelay_mbFM2wzE_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_2la49ykd, 0, m, &cDelay_2la49ykd_sendMessage);
}

void Heavy_SoundScraper::cBinop_UiIZVEXg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_mbFM2wzE, 2, m, &cDelay_mbFM2wzE_sendMessage);
}

void Heavy_SoundScraper::cSystem_B0taOGSw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_NcSTL6If_sendMessage);
}

void Heavy_SoundScraper::cMsg_F3k3QbJS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_B0taOGSw_sendMessage);
}

void Heavy_SoundScraper::cCast_dPcUPzMT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Nn2QYeSd, 0, m, &cVar_Nn2QYeSd_sendMessage);
  cMsg_F3k3QbJS_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_GiSLm0Ve, 0, m, &cTabhead_GiSLm0Ve_sendMessage);
}

void Heavy_SoundScraper::cCast_dn4S88k2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_mbFM2wzE, 0, m, &cDelay_mbFM2wzE_sendMessage);
}

void Heavy_SoundScraper::cDelay_mbFM2wzE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_mbFM2wzE, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_2la49ykd, 0, m, &cDelay_2la49ykd_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_AgyAQgdX, 0, m, &sTabread_AgyAQgdX_sendMessage);
}

void Heavy_SoundScraper::cBinop_mwnNoMXW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_RlPbsFdD_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_AgyAQgdX, 0, m, &sTabread_AgyAQgdX_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_dn4S88k2_sendMessage);
}

void Heavy_SoundScraper::cBinop_yTu1fMvI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_FiECT7xg, HV_BINOP_MAX, 0, m, &cBinop_FiECT7xg_sendMessage);
}

void Heavy_SoundScraper::cBinop_2hNP4lA9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_snxSGQG0, HV_BINOP_MAX, 0, m, &cBinop_snxSGQG0_sendMessage);
}

void Heavy_SoundScraper::cBinop_Cvtliz2t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_pVSD1bKQ_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_NIIx5kU1, 0, m, &sTabread_NIIx5kU1_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_GuKsODtU_sendMessage);
}

void Heavy_SoundScraper::cBinop_Fxg7QNKn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_2hNP4lA9, HV_BINOP_MULTIPLY, 0, m, &cBinop_2hNP4lA9_sendMessage);
}

void Heavy_SoundScraper::cCast_GuKsODtU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_KLg3X0rz, 0, m, &cDelay_KLg3X0rz_sendMessage);
}

void Heavy_SoundScraper::cMsg_HehHXfVk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_nEBjSKLi_sendMessage);
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
      cBinop_onMessage(_c, &Context(_c)->cBinop_WnlrS3dP, HV_BINOP_SUBTRACT, 0, m, &cBinop_WnlrS3dP_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cMsg_30eRlicE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_zKlRJF1V_sendMessage);
}

void Heavy_SoundScraper::cSystem_zKlRJF1V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_Fxg7QNKn_sendMessage);
}

void Heavy_SoundScraper::cBinop_WQJF5CDF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_KLg3X0rz, 2, m, &cDelay_KLg3X0rz_sendMessage);
}

void Heavy_SoundScraper::cBinop_WnlrS3dP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_WQJF5CDF_sendMessage);
}

void Heavy_SoundScraper::cVar_cQfHPFbx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_HehHXfVk_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_dClVABnj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_cQfHPFbx, 0, m, &cVar_cQfHPFbx_sendMessage);
  cMsg_30eRlicE_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_jFneiBZ8, 0, m, &cTabhead_jFneiBZ8_sendMessage);
}

void Heavy_SoundScraper::cMsg_fwnrGLb9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_snxSGQG0, HV_BINOP_MAX, 1, m, &cBinop_snxSGQG0_sendMessage);
}

void Heavy_SoundScraper::cTabhead_jFneiBZ8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Cvtliz2t, HV_BINOP_SUBTRACT, 0, m, &cBinop_Cvtliz2t_sendMessage);
}

void Heavy_SoundScraper::cSystem_nEBjSKLi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_WnlrS3dP, HV_BINOP_SUBTRACT, 1, m, &cBinop_WnlrS3dP_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_JR5vGloY, 2, m, &cDelay_JR5vGloY_sendMessage);
}

void Heavy_SoundScraper::cMsg_pVSD1bKQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_KLg3X0rz, 0, m, &cDelay_KLg3X0rz_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_JR5vGloY, 0, m, &cDelay_JR5vGloY_sendMessage);
}

void Heavy_SoundScraper::cBinop_snxSGQG0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Cvtliz2t, HV_BINOP_SUBTRACT, 1, m, &cBinop_Cvtliz2t_sendMessage);
}

void Heavy_SoundScraper::hTable_9rKLAeez_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_op99vhXo_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_dqi6WYq0, 2, m, &cDelay_dqi6WYq0_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_H5FzhGY8_sendMessage);
}

void Heavy_SoundScraper::cMsg_BYJFqe9K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_9rKLAeez, 0, m, &hTable_9rKLAeez_sendMessage);
}

void Heavy_SoundScraper::cCast_H5FzhGY8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_dqi6WYq0, 0, m, &cDelay_dqi6WYq0_sendMessage);
}

void Heavy_SoundScraper::cDelay_Knj7evc2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Knj7evc2, m);
  cMsg_QyBT0mzm_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_QyBT0mzm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_9rKLAeez, 0, m, &hTable_9rKLAeez_sendMessage);
}

void Heavy_SoundScraper::cBinop_YwouG0R1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_BYJFqe9K_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSystem_mUI5nSUH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_kI7llMSj_sendMessage);
}

void Heavy_SoundScraper::cMsg_tQkRkM77_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_mUI5nSUH_sendMessage);
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
      cMsg_gv4JSvvA_sendMessage(_c, 0, m);
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
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_IxL6w6Y4, 1, m, NULL);
}

void Heavy_SoundScraper::cBinop_kI7llMSj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 19.392f, 0, m, &cBinop_YwouG0R1_sendMessage);
}

void Heavy_SoundScraper::cMsg_op99vhXo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_Knj7evc2, 2, m, &cDelay_Knj7evc2_sendMessage);
}

void Heavy_SoundScraper::cDelay_7i4fmIt3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_7i4fmIt3, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_xVPC2oxR, 0, m, &sTabread_xVPC2oxR_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_7i4fmIt3, 0, m, &cDelay_7i4fmIt3_sendMessage);
}

void Heavy_SoundScraper::cCast_8SzqVjTS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_qBNaUY0f, 0, m, &cVar_qBNaUY0f_sendMessage);
  cMsg_yXI1BX5X_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_h8J9M5Gk, 0, m, &cTabhead_h8J9M5Gk_sendMessage);
}

void Heavy_SoundScraper::cDelay_9uEjAW50_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_9uEjAW50, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_7i4fmIt3, 0, m, &cDelay_7i4fmIt3_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_xVPC2oxR, 0, m, &sTabread_xVPC2oxR_sendMessage);
}

void Heavy_SoundScraper::cSystem_SHLVNZz5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_oIgsgKG3_sendMessage);
}

void Heavy_SoundScraper::cMsg_yXI1BX5X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_SHLVNZz5_sendMessage);
}

void Heavy_SoundScraper::cCast_Mz76bQ0S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_9uEjAW50, 0, m, &cDelay_9uEjAW50_sendMessage);
}

void Heavy_SoundScraper::cBinop_TNNpD3vO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ooBa481n_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_xVPC2oxR, 0, m, &sTabread_xVPC2oxR_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Mz76bQ0S_sendMessage);
}

void Heavy_SoundScraper::cMsg_WxKgCjWu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_m6umx7jZ, HV_BINOP_MAX, 1, m, &cBinop_m6umx7jZ_sendMessage);
}

void Heavy_SoundScraper::cTabhead_h8J9M5Gk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_TNNpD3vO, HV_BINOP_SUBTRACT, 0, m, &cBinop_TNNpD3vO_sendMessage);
}

void Heavy_SoundScraper::cMsg_jkziZXQz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_n6tFC0xQ_sendMessage);
}

void Heavy_SoundScraper::cBinop_kNB3513I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_9uEjAW50, 2, m, &cDelay_9uEjAW50_sendMessage);
}

void Heavy_SoundScraper::cBinop_m6umx7jZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_TNNpD3vO, HV_BINOP_SUBTRACT, 1, m, &cBinop_TNNpD3vO_sendMessage);
}

void Heavy_SoundScraper::cSystem_n6tFC0xQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_rEUZAGwQ, HV_BINOP_SUBTRACT, 1, m, &cBinop_rEUZAGwQ_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_7i4fmIt3, 2, m, &cDelay_7i4fmIt3_sendMessage);
}

void Heavy_SoundScraper::cBinop_oIgsgKG3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_qLyovVfF, HV_BINOP_MULTIPLY, 0, m, &cBinop_qLyovVfF_sendMessage);
}

void Heavy_SoundScraper::cMsg_ooBa481n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_9uEjAW50, 0, m, &cDelay_9uEjAW50_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_7i4fmIt3, 0, m, &cDelay_7i4fmIt3_sendMessage);
}

void Heavy_SoundScraper::cVar_qBNaUY0f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_jkziZXQz_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_qLyovVfF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_m6umx7jZ, HV_BINOP_MAX, 0, m, &cBinop_m6umx7jZ_sendMessage);
}

void Heavy_SoundScraper::cBinop_rEUZAGwQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_kNB3513I_sendMessage);
}

void Heavy_SoundScraper::sTabread_xVPC2oxR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_rEUZAGwQ, HV_BINOP_SUBTRACT, 0, m, &cBinop_rEUZAGwQ_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSystem_qFduss71_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_LNFQfVX9_sendMessage);
}

void Heavy_SoundScraper::cMsg_xkjga8iw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_qFduss71_sendMessage);
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
      cMsg_SDo1YFJ9_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cMsg_BCgp2vql_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_FkFCpkOM, 2, m, &cDelay_FkFCpkOM_sendMessage);
}

void Heavy_SoundScraper::cDelay_FkFCpkOM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_FkFCpkOM, m);
  cMsg_ks0vLBKF_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_LNFQfVX9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 16.364f, 0, m, &cBinop_m9H4Ho1w_sendMessage);
}

void Heavy_SoundScraper::cCast_RhAU7w7X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_ZI44pPse, 0, m, &cDelay_ZI44pPse_sendMessage);
}

void Heavy_SoundScraper::cMsg_SDo1YFJ9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_z6VSE2bb, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_ZI44pPse_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_ZI44pPse, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_FkFCpkOM, 0, m, &cDelay_FkFCpkOM_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ZI44pPse, 0, m, &cDelay_ZI44pPse_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_z6VSE2bb, 1, m, NULL);
}

void Heavy_SoundScraper::hTable_il4LWkq0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_BCgp2vql_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ZI44pPse, 2, m, &cDelay_ZI44pPse_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_RhAU7w7X_sendMessage);
}

void Heavy_SoundScraper::cMsg_ks0vLBKF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_il4LWkq0, 0, m, &hTable_il4LWkq0_sendMessage);
}

void Heavy_SoundScraper::cBinop_m9H4Ho1w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_nriNIk02_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_nriNIk02_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_il4LWkq0, 0, m, &hTable_il4LWkq0_sendMessage);
}

void Heavy_SoundScraper::cDelay_3YopkI0B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_3YopkI0B, m);
  cMsg_YDmH9oUS_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_5Jlf3VuJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_VHxtdvz8_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_U43H4E6N, 2, m, &cDelay_U43H4E6N_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_xEHefpAU_sendMessage);
}

void Heavy_SoundScraper::cMsg_98byR0lf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_xAmeylLP, 1, m, NULL);
}

void Heavy_SoundScraper::cMsg_IxUjDnYW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_5Jlf3VuJ, 0, m, &hTable_5Jlf3VuJ_sendMessage);
}

void Heavy_SoundScraper::cBinop_PigJJcae_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_IxUjDnYW_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_U43H4E6N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_U43H4E6N, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_3YopkI0B, 0, m, &cDelay_3YopkI0B_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_U43H4E6N, 0, m, &cDelay_U43H4E6N_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_xAmeylLP, 1, m, NULL);
}

void Heavy_SoundScraper::cMsg_VHxtdvz8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_3YopkI0B, 2, m, &cDelay_3YopkI0B_sendMessage);
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
      cMsg_98byR0lf_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cMsg_YDmH9oUS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_5Jlf3VuJ, 0, m, &hTable_5Jlf3VuJ_sendMessage);
}

void Heavy_SoundScraper::cBinop_Yg2Vb7VG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 43.5337f, 0, m, &cBinop_PigJJcae_sendMessage);
}

void Heavy_SoundScraper::cMsg_WXA40OOI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_cx4h1U3y_sendMessage);
}

void Heavy_SoundScraper::cSystem_cx4h1U3y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_Yg2Vb7VG_sendMessage);
}

void Heavy_SoundScraper::cCast_xEHefpAU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_U43H4E6N, 0, m, &cDelay_U43H4E6N_sendMessage);
}

void Heavy_SoundScraper::cBinop_3ig7Lm5k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_8L5yobrA, HV_BINOP_SUBTRACT, 1, m, &cBinop_8L5yobrA_sendMessage);
}

void Heavy_SoundScraper::cVar_6pBlUwqW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Jy7Kx80v_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_8L5yobrA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_o1WBAbIm_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_9oR6lA7J, 0, m, &sTabread_9oR6lA7J_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_FGYiMKUs_sendMessage);
}

void Heavy_SoundScraper::sTabread_9oR6lA7J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_BvjRAvim, HV_BINOP_SUBTRACT, 0, m, &cBinop_BvjRAvim_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_BvjRAvim_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_GxQaiVyt_sendMessage);
}

void Heavy_SoundScraper::cBinop_DT5Fn2bd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Q2Ttx1T7, HV_BINOP_MULTIPLY, 0, m, &cBinop_Q2Ttx1T7_sendMessage);
}

void Heavy_SoundScraper::cTabhead_Dmc8PtT0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_8L5yobrA, HV_BINOP_SUBTRACT, 0, m, &cBinop_8L5yobrA_sendMessage);
}

void Heavy_SoundScraper::cCast_FGYiMKUs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_J4SKKNKl, 0, m, &cDelay_J4SKKNKl_sendMessage);
}

void Heavy_SoundScraper::cDelay_GqrbjDsV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_GqrbjDsV, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_9oR6lA7J, 0, m, &sTabread_9oR6lA7J_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_GqrbjDsV, 0, m, &cDelay_GqrbjDsV_sendMessage);
}

void Heavy_SoundScraper::cBinop_GxQaiVyt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_J4SKKNKl, 2, m, &cDelay_J4SKKNKl_sendMessage);
}

void Heavy_SoundScraper::cSystem_HL2myXQd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_BvjRAvim, HV_BINOP_SUBTRACT, 1, m, &cBinop_BvjRAvim_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_GqrbjDsV, 2, m, &cDelay_GqrbjDsV_sendMessage);
}

void Heavy_SoundScraper::cDelay_J4SKKNKl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_J4SKKNKl, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_GqrbjDsV, 0, m, &cDelay_GqrbjDsV_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_9oR6lA7J, 0, m, &sTabread_9oR6lA7J_sendMessage);
}

void Heavy_SoundScraper::cMsg_JqCkyDT1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_3ig7Lm5k, HV_BINOP_MAX, 1, m, &cBinop_3ig7Lm5k_sendMessage);
}

void Heavy_SoundScraper::cMsg_Jy7Kx80v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_HL2myXQd_sendMessage);
}

void Heavy_SoundScraper::cBinop_Q2Ttx1T7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_3ig7Lm5k, HV_BINOP_MAX, 0, m, &cBinop_3ig7Lm5k_sendMessage);
}

void Heavy_SoundScraper::cSystem_pXCGkRDP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_DT5Fn2bd_sendMessage);
}

void Heavy_SoundScraper::cMsg_uRtsBgt3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_pXCGkRDP_sendMessage);
}

void Heavy_SoundScraper::cMsg_o1WBAbIm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_J4SKKNKl, 0, m, &cDelay_J4SKKNKl_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_GqrbjDsV, 0, m, &cDelay_GqrbjDsV_sendMessage);
}

void Heavy_SoundScraper::cCast_u8Mls4kI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_6pBlUwqW, 0, m, &cVar_6pBlUwqW_sendMessage);
  cMsg_uRtsBgt3_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_Dmc8PtT0, 0, m, &cTabhead_Dmc8PtT0_sendMessage);
}

void Heavy_SoundScraper::cCast_3cSSEd6Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_pMmJ1Df7, 0, m, &cDelay_pMmJ1Df7_sendMessage);
}

void Heavy_SoundScraper::sTabread_A7NRdDRo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_L9LOyyeZ, HV_BINOP_SUBTRACT, 0, m, &cBinop_L9LOyyeZ_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_BnZN7Zpa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_cRHIu7p1, HV_BINOP_SUBTRACT, 1, m, &cBinop_cRHIu7p1_sendMessage);
}

void Heavy_SoundScraper::cDelay_Cj9J1iMM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Cj9J1iMM, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_A7NRdDRo, 0, m, &sTabread_A7NRdDRo_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Cj9J1iMM, 0, m, &cDelay_Cj9J1iMM_sendMessage);
}

void Heavy_SoundScraper::cBinop_DXjR5VWH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_muWy6S2R, HV_BINOP_MULTIPLY, 0, m, &cBinop_muWy6S2R_sendMessage);
}

void Heavy_SoundScraper::cMsg_arcJteX4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_vDMwXiAF_sendMessage);
}

void Heavy_SoundScraper::cSystem_vDMwXiAF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_DXjR5VWH_sendMessage);
}

void Heavy_SoundScraper::cSystem_I7QpVyNi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_L9LOyyeZ, HV_BINOP_SUBTRACT, 1, m, &cBinop_L9LOyyeZ_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Cj9J1iMM, 2, m, &cDelay_Cj9J1iMM_sendMessage);
}

void Heavy_SoundScraper::cBinop_L9LOyyeZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_cMXMugty_sendMessage);
}

void Heavy_SoundScraper::cMsg_O1Zd7m3m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_I7QpVyNi_sendMessage);
}

void Heavy_SoundScraper::cMsg_S3mJ5GHO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_pMmJ1Df7, 0, m, &cDelay_pMmJ1Df7_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Cj9J1iMM, 0, m, &cDelay_Cj9J1iMM_sendMessage);
}

void Heavy_SoundScraper::cVar_TfY1UwNu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_O1Zd7m3m_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_cMXMugty_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_pMmJ1Df7, 2, m, &cDelay_pMmJ1Df7_sendMessage);
}

void Heavy_SoundScraper::cBinop_cRHIu7p1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_S3mJ5GHO_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_A7NRdDRo, 0, m, &sTabread_A7NRdDRo_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_3cSSEd6Z_sendMessage);
}

void Heavy_SoundScraper::cCast_iQ4XrmSJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_TfY1UwNu, 0, m, &cVar_TfY1UwNu_sendMessage);
  cMsg_arcJteX4_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_po2Uy8VU, 0, m, &cTabhead_po2Uy8VU_sendMessage);
}

void Heavy_SoundScraper::cBinop_muWy6S2R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_BnZN7Zpa, HV_BINOP_MAX, 0, m, &cBinop_BnZN7Zpa_sendMessage);
}

void Heavy_SoundScraper::cDelay_pMmJ1Df7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_pMmJ1Df7, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Cj9J1iMM, 0, m, &cDelay_Cj9J1iMM_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_A7NRdDRo, 0, m, &sTabread_A7NRdDRo_sendMessage);
}

void Heavy_SoundScraper::cTabhead_po2Uy8VU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_cRHIu7p1, HV_BINOP_SUBTRACT, 0, m, &cBinop_cRHIu7p1_sendMessage);
}

void Heavy_SoundScraper::cMsg_z6duwO18_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_BnZN7Zpa, HV_BINOP_MAX, 1, m, &cBinop_BnZN7Zpa_sendMessage);
}

void Heavy_SoundScraper::cSystem_D9snJVWn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_aAuETfT3_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_psdgXSjI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_D9snJVWn_sendMessage);
}

void Heavy_SoundScraper::cBinop_8FJwXGk8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_NSHiTy1f, HV_BINOP_MULTIPLY, 1, m, &cBinop_NSHiTy1f_sendMessage);
}

void Heavy_SoundScraper::cBinop_NSHiTy1f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_xwOoW7j6_sendMessage);
}

void Heavy_SoundScraper::cMsg_aAuETfT3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_8FJwXGk8_sendMessage);
}

void Heavy_SoundScraper::cVar_w9s8gsro_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_NSHiTy1f, HV_BINOP_MULTIPLY, 0, m, &cBinop_NSHiTy1f_sendMessage);
}

void Heavy_SoundScraper::cBinop_h8DevU5Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_EdSrWJPJ, m);
}

void Heavy_SoundScraper::cBinop_43GFVIez_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_h8DevU5Z_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_6GXKnDCJ, m);
}

void Heavy_SoundScraper::cBinop_xwOoW7j6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_43GFVIez_sendMessage);
}

void Heavy_SoundScraper::cPack_g49bXLsX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_LW9JeSpj, 0, m, NULL);
}

void Heavy_SoundScraper::cVar_pb1QVppF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 100.0f, 0, m, &cBinop_cSd6gTbo_sendMessage);
}

void Heavy_SoundScraper::cVar_A5ugVD1y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_4vurxjLg, 0, m, &cVar_4vurxjLg_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_w9s8gsro, 0, m, &cVar_w9s8gsro_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_VMqS8U9a, 0, m, &cVar_VMqS8U9a_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_TbXZlErM, 0, m, &cVar_TbXZlErM_sendMessage);
}

void Heavy_SoundScraper::cVar_8zmf3lwk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_SSO3cT3p_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_x1IggyER_sendMessage);
}

void Heavy_SoundScraper::cVar_VMqS8U9a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_NgzBXHDK, HV_BINOP_MULTIPLY, 0, m, &cBinop_NgzBXHDK_sendMessage);
}

void Heavy_SoundScraper::cBinop_R6n18KOG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_nzFy3HfZ_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_khHH09UD, m);
}

void Heavy_SoundScraper::cBinop_vTJ3WHEo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_R6n18KOG_sendMessage);
}

void Heavy_SoundScraper::cBinop_nzFy3HfZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_XGtlPRgZ, m);
}

void Heavy_SoundScraper::cBinop_0dpQmVl7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_NgzBXHDK, HV_BINOP_MULTIPLY, 1, m, &cBinop_NgzBXHDK_sendMessage);
}

void Heavy_SoundScraper::cMsg_52ufnuVw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_0dpQmVl7_sendMessage);
}

void Heavy_SoundScraper::cBinop_NgzBXHDK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_vTJ3WHEo_sendMessage);
}

void Heavy_SoundScraper::cSystem_IUMMFkIP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_52ufnuVw_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_mcBW05Sm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_IUMMFkIP_sendMessage);
}

void Heavy_SoundScraper::cBinop_mkXlsNcY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_KIsxwZ1J, 0, m, &cPack_KIsxwZ1J_sendMessage);
}

void Heavy_SoundScraper::cCast_0PkkEWUW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_jWsXkRIT, 0, m, &cVar_jWsXkRIT_sendMessage);
  cMsg_0hirUWhU_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_MD15ck9x, 0, m, &cTabhead_MD15ck9x_sendMessage);
}

void Heavy_SoundScraper::cMsg_0R1Knx8w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_wVPVkoPF, 0, m, &cDelay_wVPVkoPF_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_AqjRr9T6, 0, m, &cDelay_AqjRr9T6_sendMessage);
}

void Heavy_SoundScraper::cBinop_1Xi8yDH2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_FzsrQbSV_sendMessage);
}

void Heavy_SoundScraper::cMsg_0hirUWhU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_PBmfKnPV_sendMessage);
}

void Heavy_SoundScraper::cSystem_PBmfKnPV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_pcfCC84r_sendMessage);
}

void Heavy_SoundScraper::cDelay_AqjRr9T6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_AqjRr9T6, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_UMAlHkrX, 0, m, &sTabread_UMAlHkrX_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_AqjRr9T6, 0, m, &cDelay_AqjRr9T6_sendMessage);
}

void Heavy_SoundScraper::cBinop_ClcVTFK7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_JeHx8xhJ, HV_BINOP_MAX, 0, m, &cBinop_JeHx8xhJ_sendMessage);
}

void Heavy_SoundScraper::cBinop_FzsrQbSV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_wVPVkoPF, 2, m, &cDelay_wVPVkoPF_sendMessage);
}

void Heavy_SoundScraper::cBinop_JeHx8xhJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_yBO9HRKL, HV_BINOP_SUBTRACT, 1, m, &cBinop_yBO9HRKL_sendMessage);
}

void Heavy_SoundScraper::cTabhead_MD15ck9x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_yBO9HRKL, HV_BINOP_SUBTRACT, 0, m, &cBinop_yBO9HRKL_sendMessage);
}

void Heavy_SoundScraper::cMsg_OnXOGtNY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_sF4ENJM2_sendMessage);
}

void Heavy_SoundScraper::sTabread_UMAlHkrX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_1Xi8yDH2, HV_BINOP_SUBTRACT, 0, m, &cBinop_1Xi8yDH2_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cMsg_UvrPLWhF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_JeHx8xhJ, HV_BINOP_MAX, 1, m, &cBinop_JeHx8xhJ_sendMessage);
}

void Heavy_SoundScraper::cVar_jWsXkRIT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_OnXOGtNY_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_pcfCC84r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ClcVTFK7, HV_BINOP_MULTIPLY, 0, m, &cBinop_ClcVTFK7_sendMessage);
}

void Heavy_SoundScraper::cCast_q29aaKXr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_wVPVkoPF, 0, m, &cDelay_wVPVkoPF_sendMessage);
}

void Heavy_SoundScraper::cSystem_sF4ENJM2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_1Xi8yDH2, HV_BINOP_SUBTRACT, 1, m, &cBinop_1Xi8yDH2_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_AqjRr9T6, 2, m, &cDelay_AqjRr9T6_sendMessage);
}

void Heavy_SoundScraper::cDelay_wVPVkoPF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_wVPVkoPF, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_AqjRr9T6, 0, m, &cDelay_AqjRr9T6_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_UMAlHkrX, 0, m, &sTabread_UMAlHkrX_sendMessage);
}

void Heavy_SoundScraper::cBinop_yBO9HRKL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_0R1Knx8w_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_UMAlHkrX, 0, m, &sTabread_UMAlHkrX_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_q29aaKXr_sendMessage);
}

void Heavy_SoundScraper::cBinop_97Vqbe7c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_S97a2am2_sendMessage);
}

void Heavy_SoundScraper::cBinop_S97a2am2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 200.0f, 0, m, &cBinop_mkXlsNcY_sendMessage);
}

void Heavy_SoundScraper::cBinop_1tXXQCap_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_3axR19W7, HV_BINOP_MAX, 0, m, &cBinop_3axR19W7_sendMessage);
}

void Heavy_SoundScraper::cBinop_3axR19W7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_g4xXvYc6, HV_BINOP_SUBTRACT, 1, m, &cBinop_g4xXvYc6_sendMessage);
}

void Heavy_SoundScraper::cMsg_ATi4B5wq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_SuIHVgfJ, 0, m, &cDelay_SuIHVgfJ_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ymHfVU7q, 0, m, &cDelay_ymHfVU7q_sendMessage);
}

void Heavy_SoundScraper::cTabhead_Ay9w28ta_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_g4xXvYc6, HV_BINOP_SUBTRACT, 0, m, &cBinop_g4xXvYc6_sendMessage);
}

void Heavy_SoundScraper::cMsg_B7lNoczL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_BjnY4T2p_sendMessage);
}

void Heavy_SoundScraper::cSystem_BjnY4T2p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_JEmUlSr7, HV_BINOP_SUBTRACT, 1, m, &cBinop_JEmUlSr7_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ymHfVU7q, 2, m, &cDelay_ymHfVU7q_sendMessage);
}

void Heavy_SoundScraper::cCast_CBh5T8lj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_qN5QtCKP, 0, m, &cVar_qN5QtCKP_sendMessage);
  cMsg_VHvSO52y_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_Ay9w28ta, 0, m, &cTabhead_Ay9w28ta_sendMessage);
}

void Heavy_SoundScraper::cBinop_JEmUlSr7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_WSYbd1r7_sendMessage);
}

void Heavy_SoundScraper::cMsg_M3QYutbA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_3axR19W7, HV_BINOP_MAX, 1, m, &cBinop_3axR19W7_sendMessage);
}

void Heavy_SoundScraper::sTabread_Mf3ytb18_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_JEmUlSr7, HV_BINOP_SUBTRACT, 0, m, &cBinop_JEmUlSr7_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_NzXum9ww_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_1tXXQCap, HV_BINOP_MULTIPLY, 0, m, &cBinop_1tXXQCap_sendMessage);
}

void Heavy_SoundScraper::cCast_S9JTsZTG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_SuIHVgfJ, 0, m, &cDelay_SuIHVgfJ_sendMessage);
}

void Heavy_SoundScraper::cDelay_SuIHVgfJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_SuIHVgfJ, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ymHfVU7q, 0, m, &cDelay_ymHfVU7q_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_Mf3ytb18, 0, m, &sTabread_Mf3ytb18_sendMessage);
}

void Heavy_SoundScraper::cBinop_WSYbd1r7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_SuIHVgfJ, 2, m, &cDelay_SuIHVgfJ_sendMessage);
}

void Heavy_SoundScraper::cBinop_g4xXvYc6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ATi4B5wq_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_Mf3ytb18, 0, m, &sTabread_Mf3ytb18_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_S9JTsZTG_sendMessage);
}

void Heavy_SoundScraper::cMsg_VHvSO52y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_eYXQ5pp9_sendMessage);
}

void Heavy_SoundScraper::cSystem_eYXQ5pp9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_NzXum9ww_sendMessage);
}

void Heavy_SoundScraper::cVar_qN5QtCKP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_B7lNoczL_sendMessage(_c, 0, m);
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
      cMsg_GdRaLxL9_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_3HCrObNu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_mzMLKJUO_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_3PJFmvdb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_IIICVU7j, 0, m, &cDelay_IIICVU7j_sendMessage);
}

void Heavy_SoundScraper::cBinop_GJHlkGse_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 69.4325f, 0, m, &cBinop_3HCrObNu_sendMessage);
}

void Heavy_SoundScraper::cMsg_GdRaLxL9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_9qK970t4, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_IIICVU7j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_IIICVU7j, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_rojQnTDl, 0, m, &cDelay_rojQnTDl_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_IIICVU7j, 0, m, &cDelay_IIICVU7j_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_9qK970t4, 1, m, NULL);
}

void Heavy_SoundScraper::hTable_kUXFxfS9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_tLHmnMAO_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_IIICVU7j, 2, m, &cDelay_IIICVU7j_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_3PJFmvdb_sendMessage);
}

void Heavy_SoundScraper::cMsg_mzMLKJUO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_kUXFxfS9, 0, m, &hTable_kUXFxfS9_sendMessage);
}

void Heavy_SoundScraper::cMsg_nSEOksCu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_kUXFxfS9, 0, m, &hTable_kUXFxfS9_sendMessage);
}

void Heavy_SoundScraper::cDelay_rojQnTDl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_rojQnTDl, m);
  cMsg_nSEOksCu_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_tLHmnMAO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_rojQnTDl, 2, m, &cDelay_rojQnTDl_sendMessage);
}

void Heavy_SoundScraper::cSystem_IPuPfbdw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_GJHlkGse_sendMessage);
}

void Heavy_SoundScraper::cMsg_JPi9YWMY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_IPuPfbdw_sendMessage);
}

void Heavy_SoundScraper::cPack_qr0uTD6a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_zd8iUYEN, 0, m, NULL);
}

void Heavy_SoundScraper::cSystem_nWLQXqJ2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_jhX5dFDR_sendMessage);
}

void Heavy_SoundScraper::cMsg_spUPSbLx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_nWLQXqJ2_sendMessage);
}

void Heavy_SoundScraper::cMsg_HbylnVLv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_aP3EnlNz, 2, m, &cDelay_aP3EnlNz_sendMessage);
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
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_PUK5OSPa, 1, m, NULL);
}

void Heavy_SoundScraper::cCast_X4srZWbh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_JjPn5IOz, 0, m, &cDelay_JjPn5IOz_sendMessage);
}

void Heavy_SoundScraper::cDelay_aP3EnlNz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_aP3EnlNz, m);
  cMsg_siEj6nhf_sendMessage(_c, 0, m);
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
      cMsg_KjwZVBLL_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_jhX5dFDR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 74.5234f, 0, m, &cBinop_ydPhC46D_sendMessage);
}

void Heavy_SoundScraper::hTable_rQziADzR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_HbylnVLv_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_JjPn5IOz, 2, m, &cDelay_JjPn5IOz_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_X4srZWbh_sendMessage);
}

void Heavy_SoundScraper::cMsg_siEj6nhf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_rQziADzR, 0, m, &hTable_rQziADzR_sendMessage);
}

void Heavy_SoundScraper::cBinop_ydPhC46D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_z9vzd6Ts_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_z9vzd6Ts_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_rQziADzR, 0, m, &hTable_rQziADzR_sendMessage);
}

void Heavy_SoundScraper::cVar_EHW2pJfr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_xvcGTgrh_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_Th0OAbYU, 0, m, &cIf_Th0OAbYU_sendMessage);
}

void Heavy_SoundScraper::cVar_XHpwjSSN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_VvVZpyji_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_RWHaRdz0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_AsD9WQLh_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_iKxiqkmm_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_XzZevGjy_sendMessage);
}

void Heavy_SoundScraper::cMsg_AsD9WQLh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSend_uD3XkntM_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_UbYnhhcu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_ZZKNZRLX, 0, m, NULL);
}

void Heavy_SoundScraper::cSend_VvVZpyji_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_Eklo03qa_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_I2ENwsyn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_blJZpUyG_sendMessage);
}

void Heavy_SoundScraper::cBinop_KmtnFRlu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_vyUQpKzd, 1, m, &cIf_vyUQpKzd_sendMessage);
}

void Heavy_SoundScraper::cBinop_RQIF9pvT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_UbYnhhcu, 0, m, &cPack_UbYnhhcu_sendMessage);
}

void Heavy_SoundScraper::cBinop_WV8A1mpm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_I2ENwsyn_sendMessage);
}

void Heavy_SoundScraper::cCast_XzZevGjy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_vyUQpKzd, 0, m, &cIf_vyUQpKzd_sendMessage);
}

void Heavy_SoundScraper::cBinop_blJZpUyG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_RQIF9pvT, HV_BINOP_POW, 1, m, &cBinop_RQIF9pvT_sendMessage);
  cMsg_pK6ib2I5_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_iKxiqkmm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_KmtnFRlu_sendMessage);
}

void Heavy_SoundScraper::cMsg_ipSKlgrs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_UbYnhhcu, 0, m, &cPack_UbYnhhcu_sendMessage);
}

void Heavy_SoundScraper::cMsg_pK6ib2I5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_RQIF9pvT, HV_BINOP_POW, 0, m, &cBinop_RQIF9pvT_sendMessage);
}

void Heavy_SoundScraper::cIf_vyUQpKzd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_ipSKlgrs_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_WV8A1mpm_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSend_uD3XkntM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_jlnIpbMW_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_1eZbcsbi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_hICvL53O, 0, m, &cPack_hICvL53O_sendMessage);
}

void Heavy_SoundScraper::cCast_6ZJMZDJW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ItDszn1u, HV_BINOP_DIVIDE, 0, m, &cBinop_ItDszn1u_sendMessage);
}

void Heavy_SoundScraper::cMsg_899dCYGS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 100.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_pYiV6Nwb, 0, m, &cVar_pYiV6Nwb_sendMessage);
}

void Heavy_SoundScraper::cBinop_93TfI35w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_fEqdfucC_sendMessage);
}

void Heavy_SoundScraper::cBinop_9p5bqceG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_q8k15fnK_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_6ZJMZDJW_sendMessage);
}

void Heavy_SoundScraper::cPack_BfTeND35_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_qhyBzUUM, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_CG0wZFS4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 87.3365f, 0, m, &cBinop_HptlCMEL_sendMessage);
}

void Heavy_SoundScraper::cBinop_DirdSHXo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.001f, 0, m, &cBinop_9p5bqceG_sendMessage);
  cPack_onMessage(_c, &Context(_c)->cPack_dp4DXsVD, 0, m, &cPack_dp4DXsVD_sendMessage);
}

void Heavy_SoundScraper::cBinop_ItDszn1u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_eOKUIqlV_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSystem_ALe7ZojB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_QrLiEZcZ_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_EiBAcfDc, m);
}

void Heavy_SoundScraper::cMsg_Eut0jGmw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ALe7ZojB_sendMessage);
}

void Heavy_SoundScraper::cBinop_QrLiEZcZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_ZSHKmGzo, m);
}

void Heavy_SoundScraper::cVar_OsTtho3f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Eut0jGmw_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_64NZTOML_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_LZbQkNxW_sendMessage);
}

void Heavy_SoundScraper::cSystem_LZbQkNxW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_nivVNDEV_sendMessage);
}

void Heavy_SoundScraper::cBinop_nivVNDEV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_p1jGECpz, m);
}

void Heavy_SoundScraper::cVar_Z8uTrTks_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.5f, 0, m, &cBinop_t8WTNE9t_sendMessage);
}

void Heavy_SoundScraper::cPack_dp4DXsVD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_w64ryzUm, 0, m, NULL);
}

void Heavy_SoundScraper::cMsg_eOKUIqlV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 30.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_cSvxiMqk, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_fEqdfucC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ItDszn1u, HV_BINOP_DIVIDE, 0, m, &cBinop_ItDszn1u_sendMessage);
}

void Heavy_SoundScraper::cVar_pYiV6Nwb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_DirdSHXo_sendMessage);
}

void Heavy_SoundScraper::cMsg_AQ6SM33L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_YgNzMhZe_sendMessage);
}

void Heavy_SoundScraper::cSystem_YgNzMhZe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_GIAYxKKz_sendMessage);
}

void Heavy_SoundScraper::cBinop_GIAYxKKz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_2LRolcvh, m);
}

void Heavy_SoundScraper::cBinop_Z2DLbpH9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_krc7fk4O, m);
}

void Heavy_SoundScraper::cMsg_rFv6MvVK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_tbpIIGhY_sendMessage);
}

void Heavy_SoundScraper::cSystem_tbpIIGhY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_Z2DLbpH9_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_C9TD0mPy, m);
}

void Heavy_SoundScraper::cVar_bDdEds4R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_rFv6MvVK_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_1Py2yTMC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_xeiqziG1, 0, m, &hTable_xeiqziG1_sendMessage);
}

void Heavy_SoundScraper::cBinop_DcwzACOW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_UWvx9csx_sendMessage(_c, 0, m);
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
      cMsg_l2En9LsM_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cSystem_A2HeDVbs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_k8AwyJ1I_sendMessage);
}

void Heavy_SoundScraper::cMsg_DGYEBDpK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_A2HeDVbs_sendMessage);
}

void Heavy_SoundScraper::cCast_NJ9KnpUt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_XulUvEDr, 0, m, &cDelay_XulUvEDr_sendMessage);
}

void Heavy_SoundScraper::cMsg_UWvx9csx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_xeiqziG1, 0, m, &hTable_xeiqziG1_sendMessage);
}

void Heavy_SoundScraper::cDelay_XulUvEDr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_XulUvEDr, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_xOKOV2RP, 0, m, &cDelay_xOKOV2RP_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_XulUvEDr, 0, m, &cDelay_XulUvEDr_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_M5vsPrLF, 1, m, NULL);
}

void Heavy_SoundScraper::cBinop_k8AwyJ1I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 5000.0f, 0, m, &cBinop_DcwzACOW_sendMessage);
}

void Heavy_SoundScraper::cMsg_l2En9LsM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_M5vsPrLF, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_xOKOV2RP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_xOKOV2RP, m);
  cMsg_1Py2yTMC_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_xdr0FEFS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_xOKOV2RP, 2, m, &cDelay_xOKOV2RP_sendMessage);
}

void Heavy_SoundScraper::hTable_xeiqziG1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_xdr0FEFS_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_XulUvEDr, 2, m, &cDelay_XulUvEDr_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_NJ9KnpUt_sendMessage);
}

void Heavy_SoundScraper::cMsg_lKx5SvJV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.5f);
  cVar_onMessage(_c, &Context(_c)->cVar_Z8uTrTks, 0, m, &cVar_Z8uTrTks_sendMessage);
}

void Heavy_SoundScraper::cBinop_HptlCMEL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_EXP, m, &cUnop_Qa8LM4Kk_sendMessage);
}

void Heavy_SoundScraper::cUnop_Qa8LM4Kk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_93TfI35w_sendMessage);
}

void Heavy_SoundScraper::cCast_q8k15fnK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ItDszn1u, HV_BINOP_DIVIDE, 1, m, &cBinop_ItDszn1u_sendMessage);
}

void Heavy_SoundScraper::cBinop_t8WTNE9t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_BfTeND35, 0, m, &cPack_BfTeND35_sendMessage);
}

void Heavy_SoundScraper::cMsg_9ivztjgt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.3f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_JGRCYHPf_sendMessage);
}

void Heavy_SoundScraper::cCast_BRYOudv7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_toR6irzf_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cMsg_DomcrxPs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 500.0f);
  sVarf_onMessage(_c, &Context(_c)->sVarf_hmWBbNn7, m);
}

void Heavy_SoundScraper::cIf_M3VNKe0r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_tH7aApmN_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cVar_onMessage(_c, &Context(_c)->cVar_yWYkELLa, 0, m, &cVar_yWYkELLa_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_ezv0befZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_M3VNKe0r, 1, m, &cIf_M3VNKe0r_sendMessage);
}

void Heavy_SoundScraper::cVar_FsHhjE6c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_0BFI24TH, HV_BINOP_MULTIPLY, 0, m, &cBinop_0BFI24TH_sendMessage);
}

void Heavy_SoundScraper::cBinop_LqP1XtAM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_F2rMqRO1_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_PmTLRsbz, m);
}

void Heavy_SoundScraper::cBinop_qVpHGGcj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_LqP1XtAM_sendMessage);
}

void Heavy_SoundScraper::cBinop_F2rMqRO1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_dwUu67ZV, m);
}

void Heavy_SoundScraper::cBinop_0BFI24TH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_qVpHGGcj_sendMessage);
}

void Heavy_SoundScraper::cMsg_M6uo1BvO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_lJVYKCT7_sendMessage);
}

void Heavy_SoundScraper::cSystem_lJVYKCT7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_YINdk7b7_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_YINdk7b7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_aTXxggpL_sendMessage);
}

void Heavy_SoundScraper::cBinop_aTXxggpL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_0BFI24TH, HV_BINOP_MULTIPLY, 1, m, &cBinop_0BFI24TH_sendMessage);
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

void Heavy_SoundScraper::cBinop_XKyvDh8Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_iSXpFufk_sendMessage);
}

void Heavy_SoundScraper::cBinop_iSXpFufk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_fsUuWpD2, 0, m, &cVar_fsUuWpD2_sendMessage);
}

void Heavy_SoundScraper::cVar_01PnFloa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 100.0f, 0, m, &cBinop_1QT8aL29_sendMessage);
}

void Heavy_SoundScraper::cBinop_eW62c3Lj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_m2se3naR_sendMessage);
}

void Heavy_SoundScraper::cBinop_m2se3naR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_NlFqYNsI_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_e1f2eTK1, m);
}

void Heavy_SoundScraper::cVar_YgoH762r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Q1F0td1q, HV_BINOP_MULTIPLY, 0, m, &cBinop_Q1F0td1q_sendMessage);
}

void Heavy_SoundScraper::cBinop_NlFqYNsI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_8luTeCv1, m);
}

void Heavy_SoundScraper::cMsg_IDFC5Zjl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ewLfsmw4_sendMessage);
}

void Heavy_SoundScraper::cSystem_ewLfsmw4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_4aU7Ni4v_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_4aU7Ni4v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_z0DBgtW1_sendMessage);
}

void Heavy_SoundScraper::cBinop_Q1F0td1q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_eW62c3Lj_sendMessage);
}

void Heavy_SoundScraper::cBinop_z0DBgtW1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Q1F0td1q, HV_BINOP_MULTIPLY, 1, m, &cBinop_Q1F0td1q_sendMessage);
}

void Heavy_SoundScraper::cDelay_47qGL36G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_47qGL36G, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_EGy2SPYK, 0, m, &cDelay_EGy2SPYK_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_zDIEk0mR, 0, m, &sTabread_zDIEk0mR_sendMessage);
}

void Heavy_SoundScraper::cTabhead_6zhX7sLi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_NreiNAi5, HV_BINOP_SUBTRACT, 0, m, &cBinop_NreiNAi5_sendMessage);
}

void Heavy_SoundScraper::cBinop_7LPHN0NA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_47qGL36G, 2, m, &cDelay_47qGL36G_sendMessage);
}

void Heavy_SoundScraper::cDelay_EGy2SPYK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_EGy2SPYK, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_zDIEk0mR, 0, m, &sTabread_zDIEk0mR_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_EGy2SPYK, 0, m, &cDelay_EGy2SPYK_sendMessage);
}

void Heavy_SoundScraper::cBinop_FOxlk4ls_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_xR7HV7wd, HV_BINOP_MULTIPLY, 0, m, &cBinop_xR7HV7wd_sendMessage);
}

void Heavy_SoundScraper::cVar_FRnRa57A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_yRjwNjQN_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_KhoufUiL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_jZcs1OLm_sendMessage);
}

void Heavy_SoundScraper::cSystem_jZcs1OLm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_FOxlk4ls_sendMessage);
}

void Heavy_SoundScraper::cCast_NmBa5KkM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_47qGL36G, 0, m, &cDelay_47qGL36G_sendMessage);
}

void Heavy_SoundScraper::cBinop_NreiNAi5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_YXqGEjIK_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_zDIEk0mR, 0, m, &sTabread_zDIEk0mR_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_NmBa5KkM_sendMessage);
}

void Heavy_SoundScraper::cMsg_Ooqb3idw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_l3aBboEX, HV_BINOP_MAX, 1, m, &cBinop_l3aBboEX_sendMessage);
}

void Heavy_SoundScraper::cMsg_YXqGEjIK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_47qGL36G, 0, m, &cDelay_47qGL36G_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_EGy2SPYK, 0, m, &cDelay_EGy2SPYK_sendMessage);
}

void Heavy_SoundScraper::cBinop_i2ZOvpDX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_7LPHN0NA_sendMessage);
}

void Heavy_SoundScraper::cBinop_l3aBboEX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_NreiNAi5, HV_BINOP_SUBTRACT, 1, m, &cBinop_NreiNAi5_sendMessage);
}

void Heavy_SoundScraper::cSystem_qGYudbvd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_i2ZOvpDX, HV_BINOP_SUBTRACT, 1, m, &cBinop_i2ZOvpDX_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_EGy2SPYK, 2, m, &cDelay_EGy2SPYK_sendMessage);
}

void Heavy_SoundScraper::cBinop_xR7HV7wd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_l3aBboEX, HV_BINOP_MAX, 0, m, &cBinop_l3aBboEX_sendMessage);
}

void Heavy_SoundScraper::cCast_y6IcNk58_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_FRnRa57A, 0, m, &cVar_FRnRa57A_sendMessage);
  cMsg_KhoufUiL_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_6zhX7sLi, 0, m, &cTabhead_6zhX7sLi_sendMessage);
}

void Heavy_SoundScraper::cMsg_yRjwNjQN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_qGYudbvd_sendMessage);
}

void Heavy_SoundScraper::sTabread_zDIEk0mR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_i2ZOvpDX, HV_BINOP_SUBTRACT, 0, m, &cBinop_i2ZOvpDX_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_2oAftTkm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_0hSBxe28, m);
}

void Heavy_SoundScraper::cVar_7zYxjbNP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Rs7wEHiP, HV_BINOP_MULTIPLY, 0, m, &cBinop_Rs7wEHiP_sendMessage);
}

void Heavy_SoundScraper::cBinop_GhQk3VCt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Rs7wEHiP, HV_BINOP_MULTIPLY, 1, m, &cBinop_Rs7wEHiP_sendMessage);
}

void Heavy_SoundScraper::cMsg_O3EQm0I5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_GhQk3VCt_sendMessage);
}

void Heavy_SoundScraper::cBinop_Rs7wEHiP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_1hjFNufp_sendMessage);
}

void Heavy_SoundScraper::cMsg_80okK5TI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_dXr4jq2u_sendMessage);
}

void Heavy_SoundScraper::cSystem_dXr4jq2u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_O3EQm0I5_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_1hjFNufp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_zn77dMVa_sendMessage);
}

void Heavy_SoundScraper::cBinop_zn77dMVa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_2oAftTkm_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_YcnS4ewy, m);
}

void Heavy_SoundScraper::cVar_fsUuWpD2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.01f, 0, m, &cBinop_fruivyfO_sendMessage);
}

void Heavy_SoundScraper::cPack_WxiN8UNo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_UaDf2nKt, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_22YsnUGx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_mgXwiBoK, 0, m, &cDelay_mgXwiBoK_sendMessage);
}

void Heavy_SoundScraper::sTabread_287b4oh5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_CO7YXtmN, HV_BINOP_SUBTRACT, 0, m, &cBinop_CO7YXtmN_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cMsg_3bxNm4Ir_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_QPrQCP5y_sendMessage);
}

void Heavy_SoundScraper::cBinop_51yGrh40_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_bsCrqwau_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_287b4oh5, 0, m, &sTabread_287b4oh5_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_22YsnUGx_sendMessage);
}

void Heavy_SoundScraper::cTabhead_Bnw0b04Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_51yGrh40, HV_BINOP_SUBTRACT, 0, m, &cBinop_51yGrh40_sendMessage);
}

void Heavy_SoundScraper::cBinop_CO7YXtmN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_GXgnaMbL_sendMessage);
}

void Heavy_SoundScraper::cMsg_E9eaimzv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_psluHfVQ, HV_BINOP_MAX, 1, m, &cBinop_psluHfVQ_sendMessage);
}

void Heavy_SoundScraper::cBinop_GNUrXJ9X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Kt7kKPHH, HV_BINOP_MULTIPLY, 0, m, &cBinop_Kt7kKPHH_sendMessage);
}

void Heavy_SoundScraper::cBinop_GXgnaMbL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_mgXwiBoK, 2, m, &cDelay_mgXwiBoK_sendMessage);
}

void Heavy_SoundScraper::cBinop_Kt7kKPHH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_psluHfVQ, HV_BINOP_MAX, 0, m, &cBinop_psluHfVQ_sendMessage);
}

void Heavy_SoundScraper::cSystem_QPrQCP5y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_CO7YXtmN, HV_BINOP_SUBTRACT, 1, m, &cBinop_CO7YXtmN_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_vLcb7izi, 2, m, &cDelay_vLcb7izi_sendMessage);
}

void Heavy_SoundScraper::cCast_RxJlMxmG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_hJUM360N, 0, m, &cVar_hJUM360N_sendMessage);
  cMsg_3MPn0eo7_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_Bnw0b04Z, 0, m, &cTabhead_Bnw0b04Z_sendMessage);
}

void Heavy_SoundScraper::cMsg_bsCrqwau_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_mgXwiBoK, 0, m, &cDelay_mgXwiBoK_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_vLcb7izi, 0, m, &cDelay_vLcb7izi_sendMessage);
}

void Heavy_SoundScraper::cVar_hJUM360N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_3bxNm4Ir_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_mgXwiBoK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_mgXwiBoK, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_vLcb7izi, 0, m, &cDelay_vLcb7izi_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_287b4oh5, 0, m, &sTabread_287b4oh5_sendMessage);
}

void Heavy_SoundScraper::cMsg_3MPn0eo7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_MxuQiGAF_sendMessage);
}

void Heavy_SoundScraper::cSystem_MxuQiGAF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_GNUrXJ9X_sendMessage);
}

void Heavy_SoundScraper::cBinop_psluHfVQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_51yGrh40, HV_BINOP_SUBTRACT, 1, m, &cBinop_51yGrh40_sendMessage);
}

void Heavy_SoundScraper::cDelay_vLcb7izi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_vLcb7izi, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_287b4oh5, 0, m, &sTabread_287b4oh5_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_vLcb7izi, 0, m, &cDelay_vLcb7izi_sendMessage);
}

void Heavy_SoundScraper::cBinop_ZCy1SdKQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_WxiN8UNo, 0, m, &cPack_WxiN8UNo_sendMessage);
}

void Heavy_SoundScraper::cDelay_2rktEiKe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_2rktEiKe, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_A9c8oUKr, 0, m, &cDelay_A9c8oUKr_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_fHBE5zox, 0, m, &sTabread_fHBE5zox_sendMessage);
}

void Heavy_SoundScraper::cBinop_4obOa0kA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_UXC71nrx_sendMessage);
}

void Heavy_SoundScraper::cBinop_9pCuWkDN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_GRC2Y3gO, HV_BINOP_SUBTRACT, 1, m, &cBinop_GRC2Y3gO_sendMessage);
}

void Heavy_SoundScraper::cDelay_A9c8oUKr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_A9c8oUKr, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_fHBE5zox, 0, m, &sTabread_fHBE5zox_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_A9c8oUKr, 0, m, &cDelay_A9c8oUKr_sendMessage);
}

void Heavy_SoundScraper::cBinop_GRC2Y3gO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_JgcBfXCJ_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_fHBE5zox, 0, m, &sTabread_fHBE5zox_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_HmrFwopm_sendMessage);
}

void Heavy_SoundScraper::cCast_HmrFwopm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_2rktEiKe, 0, m, &cDelay_2rktEiKe_sendMessage);
}

void Heavy_SoundScraper::cSystem_JQ8XH6mX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4obOa0kA, HV_BINOP_SUBTRACT, 1, m, &cBinop_4obOa0kA_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_A9c8oUKr, 2, m, &cDelay_A9c8oUKr_sendMessage);
}

void Heavy_SoundScraper::cMsg_JgcBfXCJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_2rktEiKe, 0, m, &cDelay_2rktEiKe_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_A9c8oUKr, 0, m, &cDelay_A9c8oUKr_sendMessage);
}

void Heavy_SoundScraper::cBinop_MSUiSskw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_TRY8bBhd, HV_BINOP_MULTIPLY, 0, m, &cBinop_TRY8bBhd_sendMessage);
}

void Heavy_SoundScraper::cBinop_TRY8bBhd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_9pCuWkDN, HV_BINOP_MAX, 0, m, &cBinop_9pCuWkDN_sendMessage);
}

void Heavy_SoundScraper::cVar_TSmzWwYE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_XvEdNmLJ_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_UXC71nrx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_2rktEiKe, 2, m, &cDelay_2rktEiKe_sendMessage);
}

void Heavy_SoundScraper::cMsg_XvEdNmLJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_JQ8XH6mX_sendMessage);
}

void Heavy_SoundScraper::sTabread_fHBE5zox_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_4obOa0kA, HV_BINOP_SUBTRACT, 0, m, &cBinop_4obOa0kA_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cMsg_m6Ye80po_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_vfLLOk7l_sendMessage);
}

void Heavy_SoundScraper::cSystem_vfLLOk7l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_MSUiSskw_sendMessage);
}

void Heavy_SoundScraper::cMsg_oW5fYvH2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_9pCuWkDN, HV_BINOP_MAX, 1, m, &cBinop_9pCuWkDN_sendMessage);
}

void Heavy_SoundScraper::cCast_rnZmDjgm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_TSmzWwYE, 0, m, &cVar_TSmzWwYE_sendMessage);
  cMsg_m6Ye80po_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_yB2e39Ly, 0, m, &cTabhead_yB2e39Ly_sendMessage);
}

void Heavy_SoundScraper::cTabhead_yB2e39Ly_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_GRC2Y3gO, HV_BINOP_SUBTRACT, 0, m, &cBinop_GRC2Y3gO_sendMessage);
}

void Heavy_SoundScraper::cMsg_OnWEQSkE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_NiAwcgbj, 1, m, NULL);
}

void Heavy_SoundScraper::cMsg_KEBsS6Pc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_yBH3EFPG_sendMessage);
}

void Heavy_SoundScraper::cSystem_yBH3EFPG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_oDnPJd23_sendMessage);
}

void Heavy_SoundScraper::hTable_aFG3oJ94_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_zfiHiOI9_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_n0OB1FeM, 2, m, &cDelay_n0OB1FeM_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_lTIl5zDB_sendMessage);
}

void Heavy_SoundScraper::cDelay_c9saRde3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_c9saRde3, m);
  cMsg_ftxiSCA7_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_dapslZuc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_uRHcBY22_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_ftxiSCA7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_aFG3oJ94, 0, m, &hTable_aFG3oJ94_sendMessage);
}

void Heavy_SoundScraper::cCast_lTIl5zDB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_n0OB1FeM, 0, m, &cDelay_n0OB1FeM_sendMessage);
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
      cMsg_OnWEQSkE_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_oDnPJd23_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 74.5234f, 0, m, &cBinop_dapslZuc_sendMessage);
}

void Heavy_SoundScraper::cMsg_uRHcBY22_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_aFG3oJ94, 0, m, &hTable_aFG3oJ94_sendMessage);
}

void Heavy_SoundScraper::cMsg_zfiHiOI9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_c9saRde3, 2, m, &cDelay_c9saRde3_sendMessage);
}

void Heavy_SoundScraper::cSystem_46ESDs6G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_8enFBRmX_sendMessage);
}

void Heavy_SoundScraper::cMsg_6SkPfNfE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_46ESDs6G_sendMessage);
}

void Heavy_SoundScraper::cBinop_8enFBRmX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 58.6435f, 0, m, &cBinop_ISAfihpm_sendMessage);
}

void Heavy_SoundScraper::cBinop_ISAfihpm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_SC8WdhTw_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_RXQA5BSx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_yS29xKCK_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ytp7ZEuw, 2, m, &cDelay_ytp7ZEuw_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_kzb1znZ9_sendMessage);
}

void Heavy_SoundScraper::cMsg_ReMkE8IC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_bdfczrHz, 1, m, NULL);
}

void Heavy_SoundScraper::cMsg_SC8WdhTw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_RXQA5BSx, 0, m, &hTable_RXQA5BSx_sendMessage);
}

void Heavy_SoundScraper::cDelay_UZwrh0VI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_UZwrh0VI, m);
  cMsg_ideLj0nv_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_ideLj0nv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_RXQA5BSx, 0, m, &hTable_RXQA5BSx_sendMessage);
}

void Heavy_SoundScraper::cCast_kzb1znZ9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_ytp7ZEuw, 0, m, &cDelay_ytp7ZEuw_sendMessage);
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
      cMsg_ReMkE8IC_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cMsg_yS29xKCK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_UZwrh0VI, 2, m, &cDelay_UZwrh0VI_sendMessage);
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

void Heavy_SoundScraper::cMsg_9815Vous_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_Nk71rIHa, 2, m, &cDelay_Nk71rIHa_sendMessage);
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
      cMsg_e4gWCPnI_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cMsg_NfdD8nG7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_PjKkcAXP_sendMessage);
}

void Heavy_SoundScraper::cSystem_PjKkcAXP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_P1fCc1Vj_sendMessage);
}

void Heavy_SoundScraper::cCast_JqpBgyWy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_acmn9grK, 0, m, &cDelay_acmn9grK_sendMessage);
}

void Heavy_SoundScraper::cDelay_Nk71rIHa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Nk71rIHa, m);
  cMsg_vRcJne3E_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_P1fCc1Vj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 86.1244f, 0, m, &cBinop_Saa08CJo_sendMessage);
}

void Heavy_SoundScraper::cBinop_Saa08CJo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_VmeQIre4_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_VmeQIre4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_YZR7BrKp, 0, m, &hTable_YZR7BrKp_sendMessage);
}

void Heavy_SoundScraper::hTable_YZR7BrKp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_9815Vous_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_acmn9grK, 2, m, &cDelay_acmn9grK_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_JqpBgyWy_sendMessage);
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
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_eo3i8s4D, 1, m, NULL);
}

void Heavy_SoundScraper::cMsg_vRcJne3E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_YZR7BrKp, 0, m, &hTable_YZR7BrKp_sendMessage);
}

void Heavy_SoundScraper::cBinop_fruivyfO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_ezBvigzM, 0, m, &cPack_ezBvigzM_sendMessage);
}

void Heavy_SoundScraper::cVar_0Olyx67a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Qg7EGEI6_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_1BQbilMa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_EtnUnqG2_sendMessage);
}

void Heavy_SoundScraper::cCast_1JMoGwnu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Uz12UbaY, 0, m, &cDelay_Uz12UbaY_sendMessage);
}

void Heavy_SoundScraper::cBinop_5Ti2MG8l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_9tZlrvrI, HV_BINOP_MULTIPLY, 0, m, &cBinop_9tZlrvrI_sendMessage);
}

void Heavy_SoundScraper::cBinop_5qRB83KQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_KVlSpyHI, HV_BINOP_SUBTRACT, 1, m, &cBinop_KVlSpyHI_sendMessage);
}

void Heavy_SoundScraper::cBinop_9tZlrvrI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_5qRB83KQ, HV_BINOP_MAX, 0, m, &cBinop_5qRB83KQ_sendMessage);
}

void Heavy_SoundScraper::cBinop_EtnUnqG2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Uz12UbaY, 2, m, &cDelay_Uz12UbaY_sendMessage);
}

void Heavy_SoundScraper::cBinop_KVlSpyHI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_U6f4JZzd_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_Y9CraDEf, 0, m, &sTabread_Y9CraDEf_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_1JMoGwnu_sendMessage);
}

void Heavy_SoundScraper::cMsg_Qg7EGEI6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_sIJAxyph_sendMessage);
}

void Heavy_SoundScraper::cMsg_U6f4JZzd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_Uz12UbaY, 0, m, &cDelay_Uz12UbaY_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_cC3ArdK1, 0, m, &cDelay_cC3ArdK1_sendMessage);
}

void Heavy_SoundScraper::cDelay_Uz12UbaY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Uz12UbaY, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_cC3ArdK1, 0, m, &cDelay_cC3ArdK1_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_Y9CraDEf, 0, m, &sTabread_Y9CraDEf_sendMessage);
}

void Heavy_SoundScraper::cMsg_Wlg3wsfs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_5qRB83KQ, HV_BINOP_MAX, 1, m, &cBinop_5qRB83KQ_sendMessage);
}

void Heavy_SoundScraper::sTabread_Y9CraDEf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_1BQbilMa, HV_BINOP_SUBTRACT, 0, m, &cBinop_1BQbilMa_sendMessage);
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

void Heavy_SoundScraper::cCast_iEojQvgv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_0Olyx67a, 0, m, &cVar_0Olyx67a_sendMessage);
  cMsg_CvCFmPfC_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_zgIRUxoj, 0, m, &cTabhead_zgIRUxoj_sendMessage);
}

void Heavy_SoundScraper::cSystem_sIJAxyph_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_1BQbilMa, HV_BINOP_SUBTRACT, 1, m, &cBinop_1BQbilMa_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_cC3ArdK1, 2, m, &cDelay_cC3ArdK1_sendMessage);
}

void Heavy_SoundScraper::cMsg_CvCFmPfC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_moX34wwg_sendMessage);
}

void Heavy_SoundScraper::cSystem_moX34wwg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_5Ti2MG8l_sendMessage);
}

void Heavy_SoundScraper::cTabhead_zgIRUxoj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_KVlSpyHI, HV_BINOP_SUBTRACT, 0, m, &cBinop_KVlSpyHI_sendMessage);
}

void Heavy_SoundScraper::cDelay_09LHT9W5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_09LHT9W5, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_fNPHlwMm, 0, m, &sTabread_fNPHlwMm_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_09LHT9W5, 0, m, &cDelay_09LHT9W5_sendMessage);
}

void Heavy_SoundScraper::cSystem_1UigVVdD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_P5sB6SzB, HV_BINOP_SUBTRACT, 1, m, &cBinop_P5sB6SzB_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_09LHT9W5, 2, m, &cDelay_09LHT9W5_sendMessage);
}

void Heavy_SoundScraper::cMsg_3ATMhcD7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_xHzYMt2t, HV_BINOP_MAX, 1, m, &cBinop_xHzYMt2t_sendMessage);
}

void Heavy_SoundScraper::cVar_4xtVoWQl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_BanL9KYI_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_XVGjXlNp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_m3XYiIpc_sendMessage);
}

void Heavy_SoundScraper::cSystem_m3XYiIpc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_jiI111zV_sendMessage);
}

void Heavy_SoundScraper::cMsg_BanL9KYI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_1UigVVdD_sendMessage);
}

void Heavy_SoundScraper::cMsg_CscXJBCP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_ia9QH5BZ, 0, m, &cDelay_ia9QH5BZ_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_09LHT9W5, 0, m, &cDelay_09LHT9W5_sendMessage);
}

void Heavy_SoundScraper::cBinop_EmGmlqHw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_ia9QH5BZ, 2, m, &cDelay_ia9QH5BZ_sendMessage);
}

void Heavy_SoundScraper::cCast_OrfZ4x0X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_4xtVoWQl, 0, m, &cVar_4xtVoWQl_sendMessage);
  cMsg_XVGjXlNp_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_RIhxzTXX, 0, m, &cTabhead_RIhxzTXX_sendMessage);
}

void Heavy_SoundScraper::cBinop_P5sB6SzB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_EmGmlqHw_sendMessage);
}

void Heavy_SoundScraper::cTabhead_RIhxzTXX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ky1DBcwB, HV_BINOP_SUBTRACT, 0, m, &cBinop_ky1DBcwB_sendMessage);
}

void Heavy_SoundScraper::sTabread_fNPHlwMm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_P5sB6SzB, HV_BINOP_SUBTRACT, 0, m, &cBinop_P5sB6SzB_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cCast_gaKKwkFb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_ia9QH5BZ, 0, m, &cDelay_ia9QH5BZ_sendMessage);
}

void Heavy_SoundScraper::cBinop_h68kXxuc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_xHzYMt2t, HV_BINOP_MAX, 0, m, &cBinop_xHzYMt2t_sendMessage);
}

void Heavy_SoundScraper::cDelay_ia9QH5BZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_ia9QH5BZ, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_09LHT9W5, 0, m, &cDelay_09LHT9W5_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_fNPHlwMm, 0, m, &sTabread_fNPHlwMm_sendMessage);
}

void Heavy_SoundScraper::cBinop_jiI111zV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_h68kXxuc, HV_BINOP_MULTIPLY, 0, m, &cBinop_h68kXxuc_sendMessage);
}

void Heavy_SoundScraper::cBinop_ky1DBcwB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_CscXJBCP_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_fNPHlwMm, 0, m, &sTabread_fNPHlwMm_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_gaKKwkFb_sendMessage);
}

void Heavy_SoundScraper::cBinop_xHzYMt2t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ky1DBcwB, HV_BINOP_SUBTRACT, 1, m, &cBinop_ky1DBcwB_sendMessage);
}

void Heavy_SoundScraper::cBinop_43A9XlSl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ll84Ss8d_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_KTLNUQgj, 0, m, &sTabread_KTLNUQgj_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Ora2jJZ1_sendMessage);
}

void Heavy_SoundScraper::cTabhead_4IJwIwRB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_43A9XlSl, HV_BINOP_SUBTRACT, 0, m, &cBinop_43A9XlSl_sendMessage);
}

void Heavy_SoundScraper::cSystem_BCqGYrTD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_EwnQNqi5_sendMessage);
}

void Heavy_SoundScraper::cMsg_G4GRa0N1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_BCqGYrTD_sendMessage);
}

void Heavy_SoundScraper::cBinop_EwnQNqi5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_lP9haw1E, HV_BINOP_MULTIPLY, 0, m, &cBinop_lP9haw1E_sendMessage);
}

void Heavy_SoundScraper::cBinop_GGx6ikvq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_43A9XlSl, HV_BINOP_SUBTRACT, 1, m, &cBinop_43A9XlSl_sendMessage);
}

void Heavy_SoundScraper::cMsg_HhO1IhnH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_GGx6ikvq, HV_BINOP_MAX, 1, m, &cBinop_GGx6ikvq_sendMessage);
}

void Heavy_SoundScraper::sTabread_KTLNUQgj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_r6KktnqJ, HV_BINOP_SUBTRACT, 0, m, &cBinop_r6KktnqJ_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSystem_LR8ev6UM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_r6KktnqJ, HV_BINOP_SUBTRACT, 1, m, &cBinop_r6KktnqJ_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_hGnCbDbN, 2, m, &cDelay_hGnCbDbN_sendMessage);
}

void Heavy_SoundScraper::cCast_Ora2jJZ1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Uoc7I2Qy, 0, m, &cDelay_Uoc7I2Qy_sendMessage);
}

void Heavy_SoundScraper::cDelay_Uoc7I2Qy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Uoc7I2Qy, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_hGnCbDbN, 0, m, &cDelay_hGnCbDbN_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_KTLNUQgj, 0, m, &sTabread_KTLNUQgj_sendMessage);
}

void Heavy_SoundScraper::cDelay_hGnCbDbN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_hGnCbDbN, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_KTLNUQgj, 0, m, &sTabread_KTLNUQgj_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_hGnCbDbN, 0, m, &cDelay_hGnCbDbN_sendMessage);
}

void Heavy_SoundScraper::cBinop_lP9haw1E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_GGx6ikvq, HV_BINOP_MAX, 0, m, &cBinop_GGx6ikvq_sendMessage);
}

void Heavy_SoundScraper::cMsg_ll84Ss8d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_Uoc7I2Qy, 0, m, &cDelay_Uoc7I2Qy_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_hGnCbDbN, 0, m, &cDelay_hGnCbDbN_sendMessage);
}

void Heavy_SoundScraper::cCast_mKnGw8Cb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_qTOMUqko, 0, m, &cVar_qTOMUqko_sendMessage);
  cMsg_G4GRa0N1_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_4IJwIwRB, 0, m, &cTabhead_4IJwIwRB_sendMessage);
}

void Heavy_SoundScraper::cMsg_ok7LOd8a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_LR8ev6UM_sendMessage);
}

void Heavy_SoundScraper::cVar_qTOMUqko_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ok7LOd8a_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_r6KktnqJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_tvn2TDl5_sendMessage);
}

void Heavy_SoundScraper::cBinop_tvn2TDl5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Uoc7I2Qy, 2, m, &cDelay_Uoc7I2Qy_sendMessage);
}

void Heavy_SoundScraper::cCast_0ZSTxzRK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_tDqTr5Nd, 0, m, &cDelay_tDqTr5Nd_sendMessage);
}

void Heavy_SoundScraper::cMsg_5pB4Pzn2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_7LfxGM68, 0, m, &hTable_7LfxGM68_sendMessage);
}

void Heavy_SoundScraper::hTable_7LfxGM68_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_jx1d3Jnl_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_tDqTr5Nd, 2, m, &cDelay_tDqTr5Nd_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_0ZSTxzRK_sendMessage);
}

void Heavy_SoundScraper::cBinop_G6cJdywd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_pfTVnwqe_sendMessage(_c, 0, m);
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
      cMsg_dikOhCD2_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cDelay_ONIOIJpt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_ONIOIJpt, m);
  cMsg_5pB4Pzn2_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSystem_GQp6DQ0Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_zv7mhpKo_sendMessage);
}

void Heavy_SoundScraper::cMsg_ZzVCQfLU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_GQp6DQ0Y_sendMessage);
}

void Heavy_SoundScraper::cMsg_dikOhCD2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_npESjic7, 1, m, NULL);
}

void Heavy_SoundScraper::cMsg_jx1d3Jnl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_ONIOIJpt, 2, m, &cDelay_ONIOIJpt_sendMessage);
}

void Heavy_SoundScraper::cMsg_pfTVnwqe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_7LfxGM68, 0, m, &hTable_7LfxGM68_sendMessage);
}

void Heavy_SoundScraper::cDelay_tDqTr5Nd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_tDqTr5Nd, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ONIOIJpt, 0, m, &cDelay_ONIOIJpt_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_tDqTr5Nd, 0, m, &cDelay_tDqTr5Nd_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_npESjic7, 1, m, NULL);
}

void Heavy_SoundScraper::cBinop_zv7mhpKo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 75.2546f, 0, m, &cBinop_G6cJdywd_sendMessage);
}

void Heavy_SoundScraper::cDelay_49X6shXY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_49X6shXY, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_LA1wd9KH, 0, m, &cDelay_LA1wd9KH_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_49X6shXY, 0, m, &cDelay_49X6shXY_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_UmNdxsVV, 1, m, NULL);
}

void Heavy_SoundScraper::cCast_4ZF8jNMr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_49X6shXY, 0, m, &cDelay_49X6shXY_sendMessage);
}

void Heavy_SoundScraper::cBinop_5zJYFlMM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 43.5337f, 0, m, &cBinop_9XMqheb4_sendMessage);
}

void Heavy_SoundScraper::cBinop_9XMqheb4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_BilP4Qzp_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_BilP4Qzp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_ed4dzP1v, 0, m, &hTable_ed4dzP1v_sendMessage);
}

void Heavy_SoundScraper::cMsg_HCWVwgrr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_UmNdxsVV, 1, m, NULL);
}

void Heavy_SoundScraper::cMsg_ItucHW2v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_LA1wd9KH, 2, m, &cDelay_LA1wd9KH_sendMessage);
}

void Heavy_SoundScraper::cDelay_LA1wd9KH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_LA1wd9KH, m);
  cMsg_beofWh8Q_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_beofWh8Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_ed4dzP1v, 0, m, &hTable_ed4dzP1v_sendMessage);
}

void Heavy_SoundScraper::hTable_ed4dzP1v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ItucHW2v_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_49X6shXY, 2, m, &cDelay_49X6shXY_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_4ZF8jNMr_sendMessage);
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
      cMsg_HCWVwgrr_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cSystem_8ny13VLl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_5zJYFlMM_sendMessage);
}

void Heavy_SoundScraper::cMsg_MeAy33Eq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_8ny13VLl_sendMessage);
}

void Heavy_SoundScraper::cMsg_0I6VU4kC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_jySdBtVo, 0, m, &hTable_jySdBtVo_sendMessage);
}

void Heavy_SoundScraper::cMsg_93bz1ZK8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_nTiAx3Z0, 2, m, &cDelay_nTiAx3Z0_sendMessage);
}

void Heavy_SoundScraper::cMsg_OpLGXlqw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_jySdBtVo, 0, m, &hTable_jySdBtVo_sendMessage);
}

void Heavy_SoundScraper::cMsg_RC1wuMh1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Yd9Hf3lz_sendMessage);
}

void Heavy_SoundScraper::cSystem_Yd9Hf3lz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_mQFmUWTw_sendMessage);
}

void Heavy_SoundScraper::cDelay_WxrELUTQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_WxrELUTQ, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_nTiAx3Z0, 0, m, &cDelay_nTiAx3Z0_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_WxrELUTQ, 0, m, &cDelay_WxrELUTQ_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_qgO6IXfk, 1, m, NULL);
}

void Heavy_SoundScraper::cCast_X2nWfa1Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_WxrELUTQ, 0, m, &cDelay_WxrELUTQ_sendMessage);
}

void Heavy_SoundScraper::cMsg_c2jvN8v3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_qgO6IXfk, 1, m, NULL);
}

void Heavy_SoundScraper::hTable_jySdBtVo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_93bz1ZK8_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_WxrELUTQ, 2, m, &cDelay_WxrELUTQ_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_X2nWfa1Q_sendMessage);
}

void Heavy_SoundScraper::cBinop_mQFmUWTw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 16.364f, 0, m, &cBinop_vhxPDgNs_sendMessage);
}

void Heavy_SoundScraper::cDelay_nTiAx3Z0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_nTiAx3Z0, m);
  cMsg_OpLGXlqw_sendMessage(_c, 0, m);
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
      cMsg_c2jvN8v3_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_vhxPDgNs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_0I6VU4kC_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSystem_5y0Nva8N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_tgIduLZN_sendMessage);
}

void Heavy_SoundScraper::cMsg_LdqrfaOU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_5y0Nva8N_sendMessage);
}

void Heavy_SoundScraper::cMsg_DUE60xXY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_Q5I7LvD0, 0, m, &hTable_Q5I7LvD0_sendMessage);
}

void Heavy_SoundScraper::cCast_Mc6e8bXN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_SIMNYWXy, 0, m, &cDelay_SIMNYWXy_sendMessage);
}

void Heavy_SoundScraper::hTable_Q5I7LvD0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Zx7vdi9s_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_SIMNYWXy, 2, m, &cDelay_SIMNYWXy_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Mc6e8bXN_sendMessage);
}

void Heavy_SoundScraper::cMsg_R1TDQnTO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_SEgP4thX, 1, m, NULL);
}

void Heavy_SoundScraper::cDelay_SIMNYWXy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_SIMNYWXy, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_dLmDm8cZ, 0, m, &cDelay_dLmDm8cZ_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_SIMNYWXy, 0, m, &cDelay_SIMNYWXy_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_SEgP4thX, 1, m, NULL);
}

void Heavy_SoundScraper::cMsg_Zx7vdi9s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_dLmDm8cZ, 2, m, &cDelay_dLmDm8cZ_sendMessage);
}

void Heavy_SoundScraper::cBinop_cOvgzn7Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_DUE60xXY_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_dLmDm8cZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_dLmDm8cZ, m);
  cMsg_r1IjXcxu_sendMessage(_c, 0, m);
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
      cMsg_R1TDQnTO_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cMsg_r1IjXcxu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_Q5I7LvD0, 0, m, &hTable_Q5I7LvD0_sendMessage);
}

void Heavy_SoundScraper::cBinop_tgIduLZN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 19.392f, 0, m, &cBinop_cOvgzn7Q_sendMessage);
}

void Heavy_SoundScraper::cMsg_4OGd9oUL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_CYwbyEbL_sendMessage);
}

void Heavy_SoundScraper::cCast_4YXNhWpq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_ASYbIDGN, 0, m, &cDelay_ASYbIDGN_sendMessage);
}

void Heavy_SoundScraper::cMsg_72GARumQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ulFj3abE_sendMessage);
}

void Heavy_SoundScraper::cSystem_ulFj3abE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_DQ4MuwHA_sendMessage);
}

void Heavy_SoundScraper::cDelay_ASYbIDGN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_ASYbIDGN, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_HxStVlIg, 0, m, &cDelay_HxStVlIg_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_nDccIDmw, 0, m, &sTabread_nDccIDmw_sendMessage);
}

void Heavy_SoundScraper::cSystem_CYwbyEbL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_IIS2nFeZ, HV_BINOP_SUBTRACT, 1, m, &cBinop_IIS2nFeZ_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_HxStVlIg, 2, m, &cDelay_HxStVlIg_sendMessage);
}

void Heavy_SoundScraper::cBinop_DQ4MuwHA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_M34Jiqr9, HV_BINOP_MULTIPLY, 0, m, &cBinop_M34Jiqr9_sendMessage);
}

void Heavy_SoundScraper::cCast_EbTason2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_m3EZUm6A, 0, m, &cVar_m3EZUm6A_sendMessage);
  cMsg_72GARumQ_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_TNf1eExq, 0, m, &cTabhead_TNf1eExq_sendMessage);
}

void Heavy_SoundScraper::cDelay_HxStVlIg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_HxStVlIg, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_nDccIDmw, 0, m, &sTabread_nDccIDmw_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_HxStVlIg, 0, m, &cDelay_HxStVlIg_sendMessage);
}

void Heavy_SoundScraper::cBinop_IIS2nFeZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_JQtnPmlz_sendMessage);
}

void Heavy_SoundScraper::cBinop_JQtnPmlz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_ASYbIDGN, 2, m, &cDelay_ASYbIDGN_sendMessage);
}

void Heavy_SoundScraper::cBinop_M34Jiqr9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_bdL5NQmx, HV_BINOP_MAX, 0, m, &cBinop_bdL5NQmx_sendMessage);
}

void Heavy_SoundScraper::cMsg_S4gbTVyH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_bdL5NQmx, HV_BINOP_MAX, 1, m, &cBinop_bdL5NQmx_sendMessage);
}

void Heavy_SoundScraper::cTabhead_TNf1eExq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_qq6K9PHv, HV_BINOP_SUBTRACT, 0, m, &cBinop_qq6K9PHv_sendMessage);
}

void Heavy_SoundScraper::cBinop_bdL5NQmx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_qq6K9PHv, HV_BINOP_SUBTRACT, 1, m, &cBinop_qq6K9PHv_sendMessage);
}

void Heavy_SoundScraper::cVar_m3EZUm6A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_4OGd9oUL_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::sTabread_nDccIDmw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_IIS2nFeZ, HV_BINOP_SUBTRACT, 0, m, &cBinop_IIS2nFeZ_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cMsg_oe79uwhZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_ASYbIDGN, 0, m, &cDelay_ASYbIDGN_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_HxStVlIg, 0, m, &cDelay_HxStVlIg_sendMessage);
}

void Heavy_SoundScraper::cBinop_qq6K9PHv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_oe79uwhZ_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_nDccIDmw, 0, m, &sTabread_nDccIDmw_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_4YXNhWpq_sendMessage);
}

void Heavy_SoundScraper::cSystem_09UxVico_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_dPHgSIne, HV_BINOP_SUBTRACT, 1, m, &cBinop_dPHgSIne_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_3oeH2JBy, 2, m, &cDelay_3oeH2JBy_sendMessage);
}

void Heavy_SoundScraper::cMsg_2GC5qDE9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_09UxVico_sendMessage);
}

void Heavy_SoundScraper::cDelay_3oeH2JBy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_3oeH2JBy, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_O8Nzf9kN, 0, m, &sTabread_O8Nzf9kN_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_3oeH2JBy, 0, m, &cDelay_3oeH2JBy_sendMessage);
}

void Heavy_SoundScraper::cMsg_9eil7gp7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_QWylQbiQ, HV_BINOP_MAX, 1, m, &cBinop_QWylQbiQ_sendMessage);
}

void Heavy_SoundScraper::cMsg_f4adeBbk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_tO5bbbTG_sendMessage);
}

void Heavy_SoundScraper::cSystem_tO5bbbTG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_iufVIBxc_sendMessage);
}

void Heavy_SoundScraper::cCast_L7iCtTEe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_TgQlUfGJ, 0, m, &cDelay_TgQlUfGJ_sendMessage);
}

void Heavy_SoundScraper::sTabread_O8Nzf9kN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_dPHgSIne, HV_BINOP_SUBTRACT, 0, m, &cBinop_dPHgSIne_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_QWylQbiQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_iz7mYQDn, HV_BINOP_SUBTRACT, 1, m, &cBinop_iz7mYQDn_sendMessage);
}

void Heavy_SoundScraper::cDelay_TgQlUfGJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_TgQlUfGJ, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_3oeH2JBy, 0, m, &cDelay_3oeH2JBy_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_O8Nzf9kN, 0, m, &sTabread_O8Nzf9kN_sendMessage);
}

void Heavy_SoundScraper::cVar_YKuyqJkJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_2GC5qDE9_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_ZQVRhEvd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_YKuyqJkJ, 0, m, &cVar_YKuyqJkJ_sendMessage);
  cMsg_f4adeBbk_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_ccb5gzCO, 0, m, &cTabhead_ccb5gzCO_sendMessage);
}

void Heavy_SoundScraper::cTabhead_ccb5gzCO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_iz7mYQDn, HV_BINOP_SUBTRACT, 0, m, &cBinop_iz7mYQDn_sendMessage);
}

void Heavy_SoundScraper::cBinop_dPHgSIne_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_iFdEsWYa_sendMessage);
}

void Heavy_SoundScraper::cBinop_iFdEsWYa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_TgQlUfGJ, 2, m, &cDelay_TgQlUfGJ_sendMessage);
}

void Heavy_SoundScraper::cBinop_iufVIBxc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_qDXTL5sw, HV_BINOP_MULTIPLY, 0, m, &cBinop_qDXTL5sw_sendMessage);
}

void Heavy_SoundScraper::cBinop_iz7mYQDn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_yAH7dtxy_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_O8Nzf9kN, 0, m, &sTabread_O8Nzf9kN_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_L7iCtTEe_sendMessage);
}

void Heavy_SoundScraper::cBinop_qDXTL5sw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_QWylQbiQ, HV_BINOP_MAX, 0, m, &cBinop_QWylQbiQ_sendMessage);
}

void Heavy_SoundScraper::cMsg_yAH7dtxy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_TgQlUfGJ, 0, m, &cDelay_TgQlUfGJ_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_3oeH2JBy, 0, m, &cDelay_3oeH2JBy_sendMessage);
}

void Heavy_SoundScraper::cBinop_6gtqa92x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_qoGHzXoH_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_FtY8PYnt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_FtY8PYnt, m);
  cMsg_wPwewbN1_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_KHlQYXx9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_RWanfeAY_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_dzwLPIln, 2, m, &cDelay_dzwLPIln_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_qtmXJ6NO_sendMessage);
}

void Heavy_SoundScraper::cMsg_RWanfeAY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_FtY8PYnt, 2, m, &cDelay_FtY8PYnt_sendMessage);
}

void Heavy_SoundScraper::cBinop_bO6IcRPn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 25.796f, 0, m, &cBinop_6gtqa92x_sendMessage);
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
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_h4UbNH6N, 1, m, NULL);
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
      cMsg_e5nC9XQl_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cMsg_qoGHzXoH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_KHlQYXx9, 0, m, &hTable_KHlQYXx9_sendMessage);
}

void Heavy_SoundScraper::cCast_qtmXJ6NO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_dzwLPIln, 0, m, &cDelay_dzwLPIln_sendMessage);
}

void Heavy_SoundScraper::cMsg_wPwewbN1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_KHlQYXx9, 0, m, &hTable_KHlQYXx9_sendMessage);
}

void Heavy_SoundScraper::cMsg_TsR2GQOE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_azcWMMy8_sendMessage);
}

void Heavy_SoundScraper::cSystem_azcWMMy8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_bO6IcRPn_sendMessage);
}

void Heavy_SoundScraper::cCast_0Xpe4POt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Hz4wWSlG, 0, m, &cVar_Hz4wWSlG_sendMessage);
  cMsg_HtY64ewu_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_akRr0TKx, 0, m, &cTabhead_akRr0TKx_sendMessage);
}

void Heavy_SoundScraper::cDelay_5SF5c1Hw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_5SF5c1Hw, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_NbGYCTWS, 0, m, &cDelay_NbGYCTWS_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_xXzVRiLA, 0, m, &sTabread_xXzVRiLA_sendMessage);
}

void Heavy_SoundScraper::cMsg_HtY64ewu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_KriTvrTG_sendMessage);
}

void Heavy_SoundScraper::cSystem_KriTvrTG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_IIySvyEu_sendMessage);
}

void Heavy_SoundScraper::cBinop_EpHDWzxq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Z9giYb1b_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_xXzVRiLA, 0, m, &sTabread_xXzVRiLA_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_iitru23p_sendMessage);
}

void Heavy_SoundScraper::cSystem_GRKCbLCV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Mh7qOlAm, HV_BINOP_SUBTRACT, 1, m, &cBinop_Mh7qOlAm_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_NbGYCTWS, 2, m, &cDelay_NbGYCTWS_sendMessage);
}

void Heavy_SoundScraper::cVar_Hz4wWSlG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Tm5B3KTB_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_IIySvyEu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ow1xervc, HV_BINOP_MULTIPLY, 0, m, &cBinop_ow1xervc_sendMessage);
}

void Heavy_SoundScraper::cBinop_Mh7qOlAm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_gRxYPpxw_sendMessage);
}

void Heavy_SoundScraper::cDelay_NbGYCTWS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_NbGYCTWS, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_xXzVRiLA, 0, m, &sTabread_xXzVRiLA_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_NbGYCTWS, 0, m, &cDelay_NbGYCTWS_sendMessage);
}

void Heavy_SoundScraper::cMsg_Tm5B3KTB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_GRKCbLCV_sendMessage);
}

void Heavy_SoundScraper::cBinop_YLgj1ukC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_EpHDWzxq, HV_BINOP_SUBTRACT, 1, m, &cBinop_EpHDWzxq_sendMessage);
}

void Heavy_SoundScraper::cMsg_Z9giYb1b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_5SF5c1Hw, 0, m, &cDelay_5SF5c1Hw_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_NbGYCTWS, 0, m, &cDelay_NbGYCTWS_sendMessage);
}

void Heavy_SoundScraper::cTabhead_akRr0TKx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_EpHDWzxq, HV_BINOP_SUBTRACT, 0, m, &cBinop_EpHDWzxq_sendMessage);
}

void Heavy_SoundScraper::cBinop_gRxYPpxw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_5SF5c1Hw, 2, m, &cDelay_5SF5c1Hw_sendMessage);
}

void Heavy_SoundScraper::cCast_iitru23p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_5SF5c1Hw, 0, m, &cDelay_5SF5c1Hw_sendMessage);
}

void Heavy_SoundScraper::cBinop_ow1xervc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_YLgj1ukC, HV_BINOP_MAX, 0, m, &cBinop_YLgj1ukC_sendMessage);
}

void Heavy_SoundScraper::cMsg_vCO0xInk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_YLgj1ukC, HV_BINOP_MAX, 1, m, &cBinop_YLgj1ukC_sendMessage);
}

void Heavy_SoundScraper::sTabread_xXzVRiLA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_Mh7qOlAm, HV_BINOP_SUBTRACT, 0, m, &cBinop_Mh7qOlAm_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cMsg_0gInztJv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_vassxs94, 0, m, &hTable_vassxs94_sendMessage);
}

void Heavy_SoundScraper::cMsg_6fmSi1Uw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_vassxs94, 0, m, &hTable_vassxs94_sendMessage);
}

void Heavy_SoundScraper::cCast_HEGB6Fy6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_M55PrVFx, 0, m, &cDelay_M55PrVFx_sendMessage);
}

void Heavy_SoundScraper::cBinop_Lc8ZpzSp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_0gInztJv_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_M55PrVFx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_M55PrVFx, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_wuuP7HUY, 0, m, &cDelay_wuuP7HUY_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_M55PrVFx, 0, m, &cDelay_M55PrVFx_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_WNGsvgTv, 1, m, NULL);
}

void Heavy_SoundScraper::cMsg_WFP7txtm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_wuuP7HUY, 2, m, &cDelay_wuuP7HUY_sendMessage);
}

void Heavy_SoundScraper::cBinop_XtCvUX2A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 13.645f, 0, m, &cBinop_Lc8ZpzSp_sendMessage);
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
      cMsg_heY9xzxV_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cSystem_AMwHTY0Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_XtCvUX2A_sendMessage);
}

void Heavy_SoundScraper::cMsg_MZCVjXdJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_AMwHTY0Q_sendMessage);
}

void Heavy_SoundScraper::cMsg_heY9xzxV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_WNGsvgTv, 1, m, NULL);
}

void Heavy_SoundScraper::hTable_vassxs94_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_WFP7txtm_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_M55PrVFx, 2, m, &cDelay_M55PrVFx_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_HEGB6Fy6_sendMessage);
}

void Heavy_SoundScraper::cDelay_wuuP7HUY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_wuuP7HUY, m);
  cMsg_6fmSi1Uw_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_1QT8aL29_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_5SWb0Lcg_sendMessage);
}

void Heavy_SoundScraper::cBinop_5SWb0Lcg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 200.0f, 0, m, &cBinop_tmHbK2Ps_sendMessage);
}

void Heavy_SoundScraper::cVar_btS5VW3w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_N688tfT5_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_s2RqB4wl_sendMessage);
}

void Heavy_SoundScraper::hTable_6RQ15tHQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_avGm5jna_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_d5wvg6tU, 2, m, &cDelay_d5wvg6tU_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_otgz6Kqu_sendMessage);
}

void Heavy_SoundScraper::cSystem_FWgGFZdU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_ya0dsmAJ_sendMessage);
}

void Heavy_SoundScraper::cMsg_SnZmM2PV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_FWgGFZdU_sendMessage);
}

void Heavy_SoundScraper::cMsg_8sswa6Qn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_TvRTzorQ, 1, m, NULL);
}

void Heavy_SoundScraper::cBinop_AUPO4n6r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_xf9XyDP2_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_avGm5jna_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_pmTy7lUW, 2, m, &cDelay_pmTy7lUW_sendMessage);
}

void Heavy_SoundScraper::cDelay_d5wvg6tU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_d5wvg6tU, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_pmTy7lUW, 0, m, &cDelay_pmTy7lUW_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_d5wvg6tU, 0, m, &cDelay_d5wvg6tU_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_TvRTzorQ, 1, m, NULL);
}

void Heavy_SoundScraper::cCast_otgz6Kqu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_d5wvg6tU, 0, m, &cDelay_d5wvg6tU_sendMessage);
}

void Heavy_SoundScraper::cDelay_pmTy7lUW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_pmTy7lUW, m);
  cMsg_wMEgt5My_sendMessage(_c, 0, m);
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
      cMsg_8sswa6Qn_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cMsg_wMEgt5My_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_6RQ15tHQ, 0, m, &hTable_6RQ15tHQ_sendMessage);
}

void Heavy_SoundScraper::cMsg_xf9XyDP2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_6RQ15tHQ, 0, m, &hTable_6RQ15tHQ_sendMessage);
}

void Heavy_SoundScraper::cBinop_ya0dsmAJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 69.4325f, 0, m, &cBinop_AUPO4n6r_sendMessage);
}

void Heavy_SoundScraper::cVar_Q68rrcEO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_ezv0befZ_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_M3VNKe0r, 0, m, &cIf_M3VNKe0r_sendMessage);
}

void Heavy_SoundScraper::cBinop_9nbcLdkc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_iBbrZkJq, HV_BINOP_MAX, 0, m, &cBinop_iBbrZkJq_sendMessage);
}

void Heavy_SoundScraper::cBinop_E2l5nDr2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Icit5MbF_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_XgM7MCjD, 0, m, &sTabread_XgM7MCjD_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_TtciRdhR_sendMessage);
}

void Heavy_SoundScraper::cMsg_Icit5MbF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_URspPdeT, 0, m, &cDelay_URspPdeT_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_nZHNIorZ, 0, m, &cDelay_nZHNIorZ_sendMessage);
}

void Heavy_SoundScraper::cVar_KgUstciN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ZlTLysvX_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_LPyHGKIm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_iBbrZkJq, HV_BINOP_MAX, 1, m, &cBinop_iBbrZkJq_sendMessage);
}

void Heavy_SoundScraper::cBinop_MRJzFSvg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_9nbcLdkc, HV_BINOP_MULTIPLY, 0, m, &cBinop_9nbcLdkc_sendMessage);
}

void Heavy_SoundScraper::cCast_NG3d9ZnJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_KgUstciN, 0, m, &cVar_KgUstciN_sendMessage);
  cMsg_YzDUtlvP_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_YXrQA3J2, 0, m, &cTabhead_YXrQA3J2_sendMessage);
}

void Heavy_SoundScraper::cSystem_RDsrnpUR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_qnDRqHnS, HV_BINOP_SUBTRACT, 1, m, &cBinop_qnDRqHnS_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_nZHNIorZ, 2, m, &cDelay_nZHNIorZ_sendMessage);
}

void Heavy_SoundScraper::cCast_TtciRdhR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_URspPdeT, 0, m, &cDelay_URspPdeT_sendMessage);
}

void Heavy_SoundScraper::cDelay_URspPdeT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_URspPdeT, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_nZHNIorZ, 0, m, &cDelay_nZHNIorZ_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_XgM7MCjD, 0, m, &sTabread_XgM7MCjD_sendMessage);
}

void Heavy_SoundScraper::cBinop_UlHtggTQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_URspPdeT, 2, m, &cDelay_URspPdeT_sendMessage);
}

void Heavy_SoundScraper::sTabread_XgM7MCjD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_qnDRqHnS, HV_BINOP_SUBTRACT, 0, m, &cBinop_qnDRqHnS_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cTabhead_YXrQA3J2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_E2l5nDr2, HV_BINOP_SUBTRACT, 0, m, &cBinop_E2l5nDr2_sendMessage);
}

void Heavy_SoundScraper::cMsg_ZlTLysvX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_RDsrnpUR_sendMessage);
}

void Heavy_SoundScraper::cBinop_iBbrZkJq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_E2l5nDr2, HV_BINOP_SUBTRACT, 1, m, &cBinop_E2l5nDr2_sendMessage);
}

void Heavy_SoundScraper::cDelay_nZHNIorZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_nZHNIorZ, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_XgM7MCjD, 0, m, &sTabread_XgM7MCjD_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_nZHNIorZ, 0, m, &cDelay_nZHNIorZ_sendMessage);
}

void Heavy_SoundScraper::cBinop_qnDRqHnS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_UlHtggTQ_sendMessage);
}

void Heavy_SoundScraper::cMsg_YzDUtlvP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_k3qhc7vf_sendMessage);
}

void Heavy_SoundScraper::cSystem_k3qhc7vf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_MRJzFSvg_sendMessage);
}

void Heavy_SoundScraper::cBinop_A2U3DdrV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.125f, 0, m, &cBinop_ZCy1SdKQ_sendMessage);
}

void Heavy_SoundScraper::cMsg_EDIsnh81_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_A2U3DdrV, HV_BINOP_POW, 0, m, &cBinop_A2U3DdrV_sendMessage);
}

void Heavy_SoundScraper::cBinop_L8mIvCl8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_pWC2Hk8d_sendMessage);
}

void Heavy_SoundScraper::cCast_N688tfT5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_YCzbv3a7_sendMessage);
}

void Heavy_SoundScraper::cBinop_YCzbv3a7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_myXjAHwO, 1, m, &cIf_myXjAHwO_sendMessage);
}

void Heavy_SoundScraper::cBinop_gkmSejeE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_A2U3DdrV, HV_BINOP_POW, 1, m, &cBinop_A2U3DdrV_sendMessage);
  cMsg_EDIsnh81_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_hiw2zq6K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.125f, 0, m, &cBinop_ZCy1SdKQ_sendMessage);
}

void Heavy_SoundScraper::cIf_myXjAHwO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_hiw2zq6K_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_L8mIvCl8_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_pWC2Hk8d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_gkmSejeE_sendMessage);
}

void Heavy_SoundScraper::cCast_s2RqB4wl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_myXjAHwO, 0, m, &cIf_myXjAHwO_sendMessage);
}

void Heavy_SoundScraper::cMsg_tH7aApmN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 3000.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_yWYkELLa, 0, m, &cVar_yWYkELLa_sendMessage);
}

void Heavy_SoundScraper::cBinop_tmHbK2Ps_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_9tnPgoYv, 0, m, &cPack_9tnPgoYv_sendMessage);
}

void Heavy_SoundScraper::cVar_ixLZUW9e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 100.0f, 0, m, &cBinop_XKyvDh8Z_sendMessage);
}

void Heavy_SoundScraper::cVar_MpIBnkWC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Mw2sEQbO, HV_BINOP_MULTIPLY, 0, m, &cBinop_Mw2sEQbO_sendMessage);
}

void Heavy_SoundScraper::cBinop_JdwRblPa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_JXDtWNO1, m);
}

void Heavy_SoundScraper::cMsg_DaHkZ5dF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_h01BVglq_sendMessage);
}

void Heavy_SoundScraper::cBinop_Mw2sEQbO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_w46NqHVU_sendMessage);
}

void Heavy_SoundScraper::cMsg_5JsLif86_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_V282R6rK_sendMessage);
}

void Heavy_SoundScraper::cSystem_V282R6rK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_DaHkZ5dF_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_h01BVglq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Mw2sEQbO, HV_BINOP_MULTIPLY, 1, m, &cBinop_Mw2sEQbO_sendMessage);
}

void Heavy_SoundScraper::cBinop_CgTz2pMU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_JdwRblPa_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_Xpj6GjZf, m);
}

void Heavy_SoundScraper::cBinop_w46NqHVU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_CgTz2pMU_sendMessage);
}

void Heavy_SoundScraper::cDelay_00bfKwJX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_00bfKwJX, m);
  cMsg_hVcQMAdy_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_3NtscPYZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_00bfKwJX, 0, m, &cDelay_00bfKwJX_sendMessage);
}

void Heavy_SoundScraper::cCast_mdQmsWVH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
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
      cMsg_3NtscPYZ_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_3NtscPYZ_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_00bfKwJX, 1, m, &cDelay_00bfKwJX_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_mdQmsWVH_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cVar_yNkmr4rV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.05776f, 0, m, &cBinop_CG0wZFS4_sendMessage);
}

void Heavy_SoundScraper::cPack_hICvL53O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_8gj0B0K3, 0, m, NULL);
}

void Heavy_SoundScraper::cMsg_hVcQMAdy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 500.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_8gj0B0K3, 0, m, NULL);
}

void Heavy_SoundScraper::cVar_eb8bh5Tb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_hICvL53O, 0, m, &cPack_hICvL53O_sendMessage);
}

void Heavy_SoundScraper::cMsg_7JWbtEUh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cMsg_AIEqCPWU_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_AIEqCPWU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 20.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_v8wXUZlu, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_JGRCYHPf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, -1.0f, 0, m, &cBinop_pBpFjPk9_sendMessage);
}

void Heavy_SoundScraper::cBinop_pBpFjPk9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_QS92CIuz, m);
}

void Heavy_SoundScraper::cVar_E2Te6apB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_AIEqCPWU_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_7Iwq6luR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_h9b0vrTz, m);
}

void Heavy_SoundScraper::cSystem_VjUOkNfE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_aLPpM77H_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_3YLMKCtN, m);
}

void Heavy_SoundScraper::cBinop_aLPpM77H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_HpEo7pyO, m);
}

void Heavy_SoundScraper::cMsg_fY6fg01R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_VjUOkNfE_sendMessage);
}

void Heavy_SoundScraper::cVar_1wlv4jAe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_fY6fg01R_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_OVfVAfdk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_arWbJhlG_sendMessage);
}

void Heavy_SoundScraper::cSystem_arWbJhlG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_7Iwq6luR_sendMessage);
}

void Heavy_SoundScraper::cBinop_6Xw8jvRr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_YcP5whC6_sendMessage);
}

void Heavy_SoundScraper::cBinop_CUz3265g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_d18kc4ju, m);
}

void Heavy_SoundScraper::cBinop_KoYU4z7X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_eqlxABbB, HV_BINOP_DIVIDE, 0, m, &cBinop_eqlxABbB_sendMessage);
}

void Heavy_SoundScraper::cBinop_S4W115Z8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_KoYU4z7X_sendMessage);
}

void Heavy_SoundScraper::cBinop_YcP5whC6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_aOyNmdiR, m);
}

void Heavy_SoundScraper::cBinop_1j0TwZna_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_fVyUmoby_sendMessage);
}

void Heavy_SoundScraper::cBinop_fVyUmoby_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_6Xw8jvRr_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_CUz3265g_sendMessage);
}

void Heavy_SoundScraper::cVar_kFmB3ZJL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_S4W115Z8_sendMessage);
}

void Heavy_SoundScraper::cBinop_eqlxABbB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ppCawPAG_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_ESzkSyWI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_QVPGhvT7_sendMessage);
}

void Heavy_SoundScraper::cSystem_QVPGhvT7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_eqlxABbB, HV_BINOP_DIVIDE, 1, m, &cBinop_eqlxABbB_sendMessage);
}

void Heavy_SoundScraper::cMsg_ppCawPAG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_t3Rt5GNg_sendMessage);
}

void Heavy_SoundScraper::cBinop_t3Rt5GNg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_1j0TwZna_sendMessage);
}

void Heavy_SoundScraper::hTable_Bf8NPbuA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_j5P5Etez_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_E8pX8p1R, 2, m, &cDelay_E8pX8p1R_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ZmvledNo_sendMessage);
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
      cMsg_zGPE9556_sendMessage(_c, 0, m);
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
  cMsg_PTgl4Ofz_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_PTgl4Ofz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_Bf8NPbuA, 0, m, &hTable_Bf8NPbuA_sendMessage);
}

void Heavy_SoundScraper::cCast_ZmvledNo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_E8pX8p1R, 0, m, &cDelay_E8pX8p1R_sendMessage);
}

void Heavy_SoundScraper::cBinop_aTh5Iipb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 500.0f, 0, m, &cBinop_tP6MR5Rt_sendMessage);
}

void Heavy_SoundScraper::cMsg_j5P5Etez_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_FgC9tAJs, 2, m, &cDelay_FgC9tAJs_sendMessage);
}

void Heavy_SoundScraper::cSystem_3XuyEAJV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_aTh5Iipb_sendMessage);
}

void Heavy_SoundScraper::cMsg_ae7kdqUJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_3XuyEAJV_sendMessage);
}

void Heavy_SoundScraper::cBinop_tP6MR5Rt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_y5eBd0dY_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_y5eBd0dY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_Bf8NPbuA, 0, m, &hTable_Bf8NPbuA_sendMessage);
}

void Heavy_SoundScraper::cMsg_zGPE9556_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_dW9XFL9Q, 1, m, NULL);
}

void Heavy_SoundScraper::cBinop_iWTFkthf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_oQwqtKJz_sendMessage);
}

void Heavy_SoundScraper::cBinop_oQwqtKJz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_VcviOus8_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_VmXj2GYM, m);
}

void Heavy_SoundScraper::cBinop_VcviOus8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_ToQ7iRm0, m);
}

void Heavy_SoundScraper::cSystem_OGhYuQqG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_eA6s9mwy_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_oahx4dw0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_OGhYuQqG_sendMessage);
}

void Heavy_SoundScraper::cBinop_dst35s5q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_h72IJPvd, HV_BINOP_MULTIPLY, 1, m, &cBinop_h72IJPvd_sendMessage);
}

void Heavy_SoundScraper::cMsg_eA6s9mwy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_dst35s5q_sendMessage);
}

void Heavy_SoundScraper::cBinop_h72IJPvd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_iWTFkthf_sendMessage);
}

void Heavy_SoundScraper::cVar_8thkYCby_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_h72IJPvd, HV_BINOP_MULTIPLY, 0, m, &cBinop_h72IJPvd_sendMessage);
}

void Heavy_SoundScraper::cBinop_AhpIUprY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_MMOLa641_sendMessage);
}

void Heavy_SoundScraper::cBinop_MMOLa641_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_tmJqOAeA_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_Gcz4I6Xl, m);
}

void Heavy_SoundScraper::cMsg_V8K6U5W0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_cmoWVJIv_sendMessage);
}

void Heavy_SoundScraper::cBinop_cmoWVJIv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_pclyTK01, HV_BINOP_MULTIPLY, 1, m, &cBinop_pclyTK01_sendMessage);
}

void Heavy_SoundScraper::cBinop_pclyTK01_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_AhpIUprY_sendMessage);
}

void Heavy_SoundScraper::cMsg_5hyFNydj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_oNST9V0A_sendMessage);
}

void Heavy_SoundScraper::cSystem_oNST9V0A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_V8K6U5W0_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_6gGIbERR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_pclyTK01, HV_BINOP_MULTIPLY, 0, m, &cBinop_pclyTK01_sendMessage);
}

void Heavy_SoundScraper::cBinop_tmJqOAeA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_DNLO2Q6E, m);
}

void Heavy_SoundScraper::cVar_UwYm2B3w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_svZJianT, HV_BINOP_MULTIPLY, 0, m, &cBinop_svZJianT_sendMessage);
}

void Heavy_SoundScraper::cBinop_LPTJYrUI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_mz6JBFLg_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_kWAJOmwx, m);
}

void Heavy_SoundScraper::cBinop_MDr4RZ6v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_LPTJYrUI_sendMessage);
}

void Heavy_SoundScraper::cBinop_mz6JBFLg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_Yh1CU5cO, m);
}

void Heavy_SoundScraper::cMsg_8K9NIuUt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_KMy9GpdV_sendMessage);
}

void Heavy_SoundScraper::cSystem_KMy9GpdV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_7Xvxu4rE_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_7Xvxu4rE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_dYzXVGuk_sendMessage);
}

void Heavy_SoundScraper::cBinop_dYzXVGuk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_svZJianT, HV_BINOP_MULTIPLY, 1, m, &cBinop_svZJianT_sendMessage);
}

void Heavy_SoundScraper::cBinop_svZJianT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_MDr4RZ6v_sendMessage);
}

void Heavy_SoundScraper::cBinop_LB2XcOiB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_UwYm2B3w, 0, m, &cVar_UwYm2B3w_sendMessage);
}

void Heavy_SoundScraper::cCast_N7qKqvxi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.0f, 0, m, &cBinop_Tky2vR8S_sendMessage);
}

void Heavy_SoundScraper::cBinop_Tky2vR8S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_h9nbQXbI, 0, m, &cVar_h9nbQXbI_sendMessage);
}

void Heavy_SoundScraper::cBinop_c3Mwp4Ae_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_6gGIbERR, 0, m, &cVar_6gGIbERR_sendMessage);
}

void Heavy_SoundScraper::cCast_eT05Xfs4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.0f, 0, m, &cBinop_c3Mwp4Ae_sendMessage);
}

void Heavy_SoundScraper::cCast_iep9NulX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.0f, 0, m, &cBinop_LB2XcOiB_sendMessage);
}

void Heavy_SoundScraper::cMsg_0sv3ZQWJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_LxI1HyGl_sendMessage);
}

void Heavy_SoundScraper::cVar_kTQEnTOC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1e-05f, 0, m, &cBinop_ZA4zOFPD_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_ivMuJqsG, 0, m, &cIf_ivMuJqsG_sendMessage);
}

void Heavy_SoundScraper::cSystem_ivzwmUjH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_i8d8BEPv_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_mW4j32GD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ivzwmUjH_sendMessage);
}

void Heavy_SoundScraper::cMsg_CHjq4USC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, -1.0f);
  sVarf_onMessage(_c, &Context(_c)->sVarf_JkevEWcv, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_hs5c8nL0, m);
}

void Heavy_SoundScraper::cMsg_DxMYHb9u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_VhMHnWWh_sendMessage);
}

void Heavy_SoundScraper::cBinop_LxI1HyGl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_gszK72BP, m);
}

void Heavy_SoundScraper::cBinop_ZA4zOFPD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_ivMuJqsG, 1, m, &cIf_ivMuJqsG_sendMessage);
}

void Heavy_SoundScraper::cIf_ivMuJqsG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_S6OqbTal_sendMessage(_c, 0, m);
      cMsg_CHjq4USC_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_DxMYHb9u_sendMessage(_c, 0, m);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_l4kk134f_sendMessage);
      sVarf_onMessage(_c, &Context(_c)->sVarf_hs5c8nL0, m);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cMsg_S6OqbTal_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_l4kk134f_sendMessage);
}

void Heavy_SoundScraper::cBinop_VhMHnWWh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_JkevEWcv, m);
}

void Heavy_SoundScraper::cMsg_i8d8BEPv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_kwlF7ACw_sendMessage);
}

void Heavy_SoundScraper::cBinop_kwlF7ACw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_iYpB7zhT, m);
}

void Heavy_SoundScraper::cBinop_l4kk134f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_uzWSdlxG_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_uzWSdlxG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_vPzzhTE8_sendMessage);
}

void Heavy_SoundScraper::cBinop_vPzzhTE8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_0sv3ZQWJ_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_2HStWATz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_hezYtxLh, HV_BINOP_MULTIPLY, 1, m, &cBinop_hezYtxLh_sendMessage);
}

void Heavy_SoundScraper::cMsg_GWlpQv24_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_P9rxUXcZ_sendMessage);
}

void Heavy_SoundScraper::cSystem_P9rxUXcZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_sGAyQg1E_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_hezYtxLh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_Ya5zT841_sendMessage);
}

void Heavy_SoundScraper::cMsg_sGAyQg1E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_2HStWATz_sendMessage);
}

void Heavy_SoundScraper::cBinop_RQHZL2VS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_MTZX9EJ5_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_0T93HxmZ, m);
}

void Heavy_SoundScraper::cBinop_Ya5zT841_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_RQHZL2VS_sendMessage);
}

void Heavy_SoundScraper::cBinop_MTZX9EJ5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_g2lHkJLb, m);
}

void Heavy_SoundScraper::cVar_h9nbQXbI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_hezYtxLh, HV_BINOP_MULTIPLY, 0, m, &cBinop_hezYtxLh_sendMessage);
}

void Heavy_SoundScraper::cCast_rPJtY3Av_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_bJgA5bbd, m);
}

void Heavy_SoundScraper::cBinop_0KdTGCJk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_bcR7beex_sendMessage);
}

void Heavy_SoundScraper::cBinop_bcR7beex_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_4sIYZMJp_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_rgtzVtD7_sendMessage);
}

void Heavy_SoundScraper::cCast_4sIYZMJp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_CzleO8Qy_sendMessage);
}

void Heavy_SoundScraper::cBinop_CWRhSFBx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_8zmf3lwk, 0, m, &cVar_8zmf3lwk_sendMessage);
}

void Heavy_SoundScraper::cBinop_CzleO8Qy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_qgkeLayB, 1, m, &cIf_qgkeLayB_sendMessage);
}

void Heavy_SoundScraper::cBinop_UkHLErmq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 100.0f, 0, m, &cBinop_xxk6bUbD_sendMessage);
}

void Heavy_SoundScraper::cMsg_Y8Q2VQj4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_8zmf3lwk, 0, m, &cVar_8zmf3lwk_sendMessage);
}

void Heavy_SoundScraper::cUnop_YJmhcxIZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_UkHLErmq_sendMessage);
}

void Heavy_SoundScraper::cIf_qgkeLayB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_Y8Q2VQj4_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_LOG10, m, &cUnop_YJmhcxIZ_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cCast_rgtzVtD7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_qgkeLayB, 0, m, &cIf_qgkeLayB_sendMessage);
}

void Heavy_SoundScraper::cBinop_xxk6bUbD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_CWRhSFBx_sendMessage);
}

void Heavy_SoundScraper::cReceive_8ia9UA0J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_vKvuftOz, 0, m, &cVar_vKvuftOz_sendMessage);
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

void Heavy_SoundScraper::cSend_5d4tbG8C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_KuzwHoLG_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_g2tD0tVi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_j1fug81B_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cIf_BCe4LD1P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_fHjSv7P0_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_ZcyNCAM4_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_E62IxLfI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_EIDmJWYE_sendMessage);
}

void Heavy_SoundScraper::cBinop_EIDmJWYE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ZeAtRi5b, HV_BINOP_POW, 1, m, &cBinop_ZeAtRi5b_sendMessage);
  cMsg_QmRPbkHJ_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_G2xu6mmc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_BCe4LD1P, 1, m, &cIf_BCe4LD1P_sendMessage);
}

void Heavy_SoundScraper::cMsg_QmRPbkHJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_ZeAtRi5b, HV_BINOP_POW, 0, m, &cBinop_ZeAtRi5b_sendMessage);
}

void Heavy_SoundScraper::cBinop_ZcyNCAM4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_E62IxLfI_sendMessage);
}

void Heavy_SoundScraper::cBinop_ZeAtRi5b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_SvkpEzkg, 0, m, &cPack_SvkpEzkg_sendMessage);
}

void Heavy_SoundScraper::cMsg_fHjSv7P0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_SvkpEzkg, 0, m, &cPack_SvkpEzkg_sendMessage);
}

void Heavy_SoundScraper::cCast_qkC9uy0h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_BCe4LD1P, 0, m, &cIf_BCe4LD1P_sendMessage);
}

void Heavy_SoundScraper::cCast_rM3gjqCZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_G2xu6mmc_sendMessage);
}

void Heavy_SoundScraper::cPack_SvkpEzkg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_nzETJbrO, 0, m, NULL);
}

void Heavy_SoundScraper::cSend_j1fug81B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_mYumRgba_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_2HkT7EA4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_xGAAWTZd_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_rM3gjqCZ_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_qkC9uy0h_sendMessage);
}

void Heavy_SoundScraper::cMsg_xGAAWTZd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSend_5d4tbG8C_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cReceive_C1lp9X1Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Eej5cfCi_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_4C68CTZJ_sendMessage);
}

void Heavy_SoundScraper::cReceive_CyRdbAJg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_LcMyXhPg, HV_BINOP_DIVIDE, 1, m, &cBinop_LcMyXhPg_sendMessage);
}

void Heavy_SoundScraper::cReceive_Do9nya8H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_IzpMzzdU, 0, m, &cVar_IzpMzzdU_sendMessage);
}

void Heavy_SoundScraper::cReceive_EEWf9xk7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_1eZbcsbi_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_BRYOudv7_sendMessage);
}

void Heavy_SoundScraper::cReceive_EZSbojeT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPrint_onMessage(_c, m, "SCRAPER_TRANSPOSITION");
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 100.0f, 0, m, &cBinop_Ieib1wKz_sendMessage);
}

void Heavy_SoundScraper::cReceive_Eklo03qa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_iKxiqkmm_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_XzZevGjy_sendMessage);
}

void Heavy_SoundScraper::cReceive_FGUdnHin_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_HIEYxg14, 0, m, NULL);
  cPrint_onMessage(_c, m, "TABLEPLAYER_CUTOFF");
}

void Heavy_SoundScraper::cReceive_FeOwgZiZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_IVZ00RuP, 1, m, &cPack_IVZ00RuP_sendMessage);
}

void Heavy_SoundScraper::cReceive_FhL5QWRt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_t5IYoLta, m);
}

void Heavy_SoundScraper::cReceive_H9uGa2DN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_GvTDKCNU_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_SetbxVoN_sendMessage);
}

void Heavy_SoundScraper::cReceive_JUsaRojU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_BkkUCsw0_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_FQduMCqN_sendMessage);
}

void Heavy_SoundScraper::cReceive_JfpuuerB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_NcKfd4xP_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_OyLoHW9F_sendMessage);
  cPack_onMessage(_c, &Context(_c)->cPack_qcUSrU6Z, 0, m, &cPack_qcUSrU6Z_sendMessage);
}

void Heavy_SoundScraper::cReceive_Ju1xS2TW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_xpi24x7y, m);
}

void Heavy_SoundScraper::cReceive_KAf1xh4c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_IB7l1ctW, 0, m, NULL);
  cPrint_onMessage(_c, m, "TABLEPLAYER_PHASE");
  cSlice_onMessage(_c, &Context(_c)->cSlice_kdQjtT8p, 0, m, &cSlice_kdQjtT8p_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_SeWjqHEN, 0, m, &cSlice_SeWjqHEN_sendMessage);
}

void Heavy_SoundScraper::cReceive_KdXsCelA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_1FOJ7tkc_sendMessage);
  cPrint_onMessage(_c, m, "SCRAPER_LEVEL");
  cVar_onMessage(_c, &Context(_c)->cVar_MZyuKpsl, 0, m, &cVar_MZyuKpsl_sendMessage);
}

void Heavy_SoundScraper::cReceive_KuzwHoLG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_g2tD0tVi, 0, m, &cVar_g2tD0tVi_sendMessage);
}

void Heavy_SoundScraper::cReceive_MDy21nR2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 10.0f, 0, m, &cBinop_0DhjWYMR_sendMessage);
}

void Heavy_SoundScraper::cReceive_PC7vIRkt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_U4JpgUYy, 1, m, &cVar_U4JpgUYy_sendMessage);
}

void Heavy_SoundScraper::cVar_oPZ52NA3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_CLNEn0DC_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_GvTDKCNU_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_SetbxVoN_sendMessage);
}

void Heavy_SoundScraper::cBinop_05msPNT8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_qohOHo7T, 0, m, &cPack_qohOHo7T_sendMessage);
}

void Heavy_SoundScraper::cMsg_9jt7KXfg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_05msPNT8, HV_BINOP_POW, 0, m, &cBinop_05msPNT8_sendMessage);
}

void Heavy_SoundScraper::cBinop_Ax8KtI1r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_05msPNT8, HV_BINOP_POW, 1, m, &cBinop_05msPNT8_sendMessage);
  cMsg_9jt7KXfg_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_GvTDKCNU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_mlL2eYQA_sendMessage);
}

void Heavy_SoundScraper::cIf_SaUsJ7St_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_fnWnKPoD_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_valWFdTL_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cCast_SetbxVoN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_SaUsJ7St, 0, m, &cIf_SaUsJ7St_sendMessage);
}

void Heavy_SoundScraper::cBinop_WiL0lRa1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_Ax8KtI1r_sendMessage);
}

void Heavy_SoundScraper::cMsg_fnWnKPoD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_qohOHo7T, 0, m, &cPack_qohOHo7T_sendMessage);
}

void Heavy_SoundScraper::cBinop_mlL2eYQA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_SaUsJ7St, 1, m, &cIf_SaUsJ7St_sendMessage);
}

void Heavy_SoundScraper::cBinop_valWFdTL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_WiL0lRa1_sendMessage);
}

void Heavy_SoundScraper::cMsg_CLNEn0DC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSend_FhaVGDRA_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_FhaVGDRA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_mpWxdZ0C_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_Fy40hcar_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_H9uGa2DN_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_gmMUMGJa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_Fy40hcar_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_qohOHo7T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_xVktYncJ, 0, m, NULL);
}

void Heavy_SoundScraper::cReceive_RJ028IRF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_IU0YaDfn_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ZloLYCGC_sendMessage);
}

void Heavy_SoundScraper::cReceive_RT1zMGKA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_aMSLNb5u, HV_BINOP_DIVIDE, 1, m, &cBinop_aMSLNb5u_sendMessage);
}

void Heavy_SoundScraper::cReceive_RUVe3pDV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_sj8eJAp4, 0, m, &cVar_sj8eJAp4_sendMessage);
}

void Heavy_SoundScraper::cReceive_RoL1C3Kj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_TB87PUyv, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_aEHBNCon, m);
}

void Heavy_SoundScraper::cVar_IBNg1qeo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_u6OuWBFc_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_bg5dMEaN_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_BWYDpnlV_sendMessage);
}

void Heavy_SoundScraper::cPack_JMWa4cFu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_naTWa0RH, 0, m, NULL);
}

void Heavy_SoundScraper::cSend_PtBwy0z9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_tx2TCvlM_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_BWYDpnlV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_K3Acz3SK, 0, m, &cIf_K3Acz3SK_sendMessage);
}

void Heavy_SoundScraper::cMsg_FpzUiI39_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_JMWa4cFu, 0, m, &cPack_JMWa4cFu_sendMessage);
}

void Heavy_SoundScraper::cBinop_ImFlOMh4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_T4gOq49j, HV_BINOP_POW, 1, m, &cBinop_T4gOq49j_sendMessage);
  cMsg_OJILvvIa_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cIf_K3Acz3SK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_FpzUiI39_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_Q2Ea7NBs_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cMsg_OJILvvIa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_T4gOq49j, HV_BINOP_POW, 0, m, &cBinop_T4gOq49j_sendMessage);
}

void Heavy_SoundScraper::cBinop_PF6hsemO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_K3Acz3SK, 1, m, &cIf_K3Acz3SK_sendMessage);
}

void Heavy_SoundScraper::cBinop_Q2Ea7NBs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_fzrQlUBr_sendMessage);
}

void Heavy_SoundScraper::cBinop_T4gOq49j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_JMWa4cFu, 0, m, &cPack_JMWa4cFu_sendMessage);
}

void Heavy_SoundScraper::cCast_bg5dMEaN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_PF6hsemO_sendMessage);
}

void Heavy_SoundScraper::cBinop_fzrQlUBr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_ImFlOMh4_sendMessage);
}

void Heavy_SoundScraper::cSend_e5YXrsnt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_ZDc3behT_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_PPwh3jr2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_PtBwy0z9_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_u6OuWBFc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSend_e5YXrsnt_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cReceive_SJ6Uh0vb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.25f, 0, m, &cBinop_U8Ih02Gg_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_MoU2NjSk_sendMessage);
}

void Heavy_SoundScraper::cBinop_0goEnjha_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_Lc80FH3Y_sendMessage);
}

void Heavy_SoundScraper::cBinop_Lc80FH3Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_uXds3GAT_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_LmBqKizT_sendMessage);
}

void Heavy_SoundScraper::cBinop_3jV8t8rT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_MRGtgAVW, 1, m, &cIf_MRGtgAVW_sendMessage);
}

void Heavy_SoundScraper::cMsg_9QMiBk7R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cMsg_CLNEn0DC_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_GvTDKCNU_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_SetbxVoN_sendMessage);
}

void Heavy_SoundScraper::cCast_LmBqKizT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_MRGtgAVW, 0, m, &cIf_MRGtgAVW_sendMessage);
}

void Heavy_SoundScraper::cIf_MRGtgAVW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_9QMiBk7R_sendMessage(_c, 0, m);
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
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_ex0pWH5s_sendMessage);
}

void Heavy_SoundScraper::cBinop_YAsDIvI6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 100.0f, 0, m, &cBinop_VPfHdar0_sendMessage);
}

void Heavy_SoundScraper::cBinop_ex0pWH5s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_CLNEn0DC_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_GvTDKCNU_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_SetbxVoN_sendMessage);
}

void Heavy_SoundScraper::cCast_uXds3GAT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_3jV8t8rT_sendMessage);
}

void Heavy_SoundScraper::cUnop_xUy7xUMU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_YAsDIvI6_sendMessage);
}

void Heavy_SoundScraper::cReceive_TIg47hmJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_3UEzL0uV, m);
}

void Heavy_SoundScraper::cReceive_UdPOlQ82_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_53DZ8J6A_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cReceive_VzckN8pw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_KSPhAnvf, 1, m, &cVar_KSPhAnvf_sendMessage);
}

void Heavy_SoundScraper::cReceive_WLjoD2qK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_xmtLeHkx_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cReceive_WatQHk0Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 2.0f, 0, m, &cBinop_0KdTGCJk_sendMessage);
}

void Heavy_SoundScraper::cReceive_Wd4NhQ0S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_wurxiXrM, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_uvWzq1Ec, m);
}

void Heavy_SoundScraper::cReceive_Xk8uDKfY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSlice_onMessage(_c, &Context(_c)->cSlice_Y4hxMcna, 0, m, &cSlice_Y4hxMcna_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_UZOVBp1z, 0, m, &cSlice_UZOVBp1z_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_rutu4pRj, 0, m, &cSlice_rutu4pRj_sendMessage);
}

void Heavy_SoundScraper::cBinop_Cl9CNQxI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_rFTggjPm_sendMessage);
}

void Heavy_SoundScraper::cRandom_Dm15jdar_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 5.0f, 0, m, &cBinop_Cl9CNQxI_sendMessage);
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
      cSlice_onMessage(_c, &Context(_c)->cSlice_web4DBtt, 0, m, &cSlice_web4DBtt_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_Dm15jdar, 0, m, &cRandom_Dm15jdar_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cUnop_rFTggjPm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_waOYHeqF_sendMessage);
}

void Heavy_SoundScraper::cSlice_web4DBtt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_Dm15jdar, 1, m, &cRandom_Dm15jdar_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cMsg_41kwLY1E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "xylo");
  msg_setFloat(m, 1, 2116.9f);
  cSend_MO6aNndp_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_5EgQ3TUu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_itiqMOM6_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_FaTxCQFd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_41kwLY1E_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_Iycc6Hb7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_YMW8cxOT_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_JGpdoCai_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_rW2aJlLj_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_Mqan02oo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_gRVzueCM_sendMessage(_c, 0, m);
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
  cMsg_Zm3KhUrS_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_MO6aNndp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_fKOUPBDH_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_YMW8cxOT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "almglocken");
  msg_setFloat(m, 1, 262.6f);
  cSend_MO6aNndp_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_Zm3KhUrS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "bowl");
  msg_setFloat(m, 1, 705.52f);
  cSend_MO6aNndp_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_gRVzueCM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "marimba");
  msg_setFloat(m, 1, 264.0f);
  cSend_MO6aNndp_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_itiqMOM6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "crotale");
  msg_setFloat(m, 1, 1058.39f);
  cSend_MO6aNndp_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_rW2aJlLj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "gong");
  msg_setFloat(m, 1, 179.88f);
  cSend_MO6aNndp_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_waOYHeqF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPrint_onMessage(_c, m, "SOUND_CHOICE");
  cSwitchcase_OlWp75wO_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cReceive_YzPn1YFy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_id113mRK, 0, m, &cVar_id113mRK_sendMessage);
}

void Heavy_SoundScraper::cReceive_ZDc3behT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_PPwh3jr2, 0, m, &cVar_PPwh3jr2_sendMessage);
}

void Heavy_SoundScraper::cReceive_aEZ3Zkri_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_L2jcM6y8, 0, m, &cVar_L2jcM6y8_sendMessage);
  cSwitchcase_AI8GgFli_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cReceive_bcGB1aGC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4Zy7imgy, HV_BINOP_DIVIDE, 1, m, &cBinop_4Zy7imgy_sendMessage);
}

void Heavy_SoundScraper::cReceive_br9NnjpD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_IVZ00RuP, 0, m, &cPack_IVZ00RuP_sendMessage);
}

void Heavy_SoundScraper::cReceive_dA7RIHfw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_RJx7ENeP, 1, m, &cVar_RJx7ENeP_sendMessage);
}

void Heavy_SoundScraper::cReceive_dzV4DPcb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_QtVh0uKT, 0, m, NULL);
  cPrint_onMessage(_c, m, "TABLEPLAYER_PHASE");
  cSlice_onMessage(_c, &Context(_c)->cSlice_Sai3hU5Y, 0, m, &cSlice_Sai3hU5Y_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_9aEdFzKI, 0, m, &cSlice_9aEdFzKI_sendMessage);
}

void Heavy_SoundScraper::cCast_1zJ53JCY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_16bc7eRS, 0, m, &cVar_16bc7eRS_sendMessage);
}

void Heavy_SoundScraper::cVar_16bc7eRS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_oOdCKp9p, 1, m, &cPack_oOdCKp9p_sendMessage);
}

void Heavy_SoundScraper::cCast_Nm2VDzII_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_oOdCKp9p, 0, m, &cPack_oOdCKp9p_sendMessage);
}

void Heavy_SoundScraper::cPack_oOdCKp9p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_nf29zP9d_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_QfYRZAAt_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_dMloV94d, 0, m, &cSlice_dMloV94d_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_BzwFzVkh, 0, m, &cSlice_BzwFzVkh_sendMessage);
  cPrint_onMessage(_c, m, "TABLEPLAYER_COMMAND");
}

void Heavy_SoundScraper::cSlice_Y3fYBJlC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
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
      cSend_AwTrNThN_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cPack_0zjXZR82_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_mKIAIItc_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_1gQyYqzw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_uaxbfDFT, 0, m, &cVar_uaxbfDFT_sendMessage);
}

void Heavy_SoundScraper::cCast_9m8oiw6a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_SlB36N6g, 0, m, &cPack_SlB36N6g_sendMessage);
}

void Heavy_SoundScraper::cVar_wY2x51Xz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_SqyneN7x, 0, m, &cPack_SqyneN7x_sendMessage);
}

void Heavy_SoundScraper::cVar_wRCPAIcz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_TSNdKbFA, HV_BINOP_DIVIDE, 1, m, &cBinop_TSNdKbFA_sendMessage);
}

void Heavy_SoundScraper::cCast_HHcoJe3O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_PZMNAqEr, 0, m, &cVar_PZMNAqEr_sendMessage);
}

void Heavy_SoundScraper::cCast_Lvfl5GiO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_PZMNAqEr, 0, m, &cVar_PZMNAqEr_sendMessage);
}

void Heavy_SoundScraper::cVar_PZMNAqEr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_TSNdKbFA, HV_BINOP_DIVIDE, 0, m, &cBinop_TSNdKbFA_sendMessage);
}

void Heavy_SoundScraper::cCast_djBf59PH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_wRCPAIcz, 0, m, &cVar_wRCPAIcz_sendMessage);
}

void Heavy_SoundScraper::cCast_oVgw9WAp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_wRCPAIcz, 0, m, &cVar_wRCPAIcz_sendMessage);
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
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_oVgw9WAp_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_HHcoJe3O_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_djBf59PH_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Lvfl5GiO_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cSend_DxxEZwY6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_r510TR8k_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_HiKwxUu3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_FGUdnHin_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_enn6P9Y6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 100000.0f, 0, m, &cBinop_xV2cKn6q_sendMessage);
}

void Heavy_SoundScraper::cVar_uaxbfDFT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_ujeYymWn_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cPack_SlB36N6g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_hLqjjijD_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_SqyneN7x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_HiKwxUu3_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_SyJC0SQG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_wY2x51Xz, 0, m, &cVar_wY2x51Xz_sendMessage);
}

void Heavy_SoundScraper::cBinop_TSNdKbFA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_enn6P9Y6, 0, m, &cVar_enn6P9Y6_sendMessage);
}

void Heavy_SoundScraper::cCast_0GRO5kiV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_BoWYccU7, 0, m, &cDelay_BoWYccU7_sendMessage);
}

void Heavy_SoundScraper::cDelay_BoWYccU7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_BoWYccU7, m);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_1gQyYqzw_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_SyJC0SQG_sendMessage);
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
      cMsg_s2aQkuD9_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_s2aQkuD9_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_BoWYccU7, 1, m, &cDelay_BoWYccU7_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_0GRO5kiV_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cMsg_s2aQkuD9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_BoWYccU7, 0, m, &cDelay_BoWYccU7_sendMessage);
}

void Heavy_SoundScraper::cSend_hLqjjijD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_FGUdnHin_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_hjwmKCDm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_uaxbfDFT, 1, m, &cVar_uaxbfDFT_sendMessage);
}

void Heavy_SoundScraper::cMsg_mKIAIItc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 0.0f);
  cSend_DxxEZwY6_sendMessage(_c, 0, m);
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 1);
  msg_setElementToFrom(m, 1, n, 0);
  cSend_DxxEZwY6_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_qSs8Y3sG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cCast_qrMOoCPx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_9m8oiw6a_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_to4NMEwm_sendMessage);
}

void Heavy_SoundScraper::cCast_to4NMEwm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_POgWkKRP_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cVar_PNeat1CU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cBinop_xV2cKn6q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_0zjXZR82, 0, m, &cPack_0zjXZR82_sendMessage);
}

void Heavy_SoundScraper::cMsg_xmwFF0MV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 44100.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 100.0f, 0, m, &cBinop_zQDJR3OR_sendMessage);
}

void Heavy_SoundScraper::cBinop_zQDJR3OR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_0zjXZR82, 1, m, &cPack_0zjXZR82_sendMessage);
}

void Heavy_SoundScraper::cBinop_1qSUQFL4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_jIF40qTi, m);
}

void Heavy_SoundScraper::cSystem_4nALlFI5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 2.0f, 0, m, &cBinop_1qSUQFL4_sendMessage);
}

void Heavy_SoundScraper::cMsg_5a5WVVoY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_4nALlFI5_sendMessage);
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
      cSlice_onMessage(_c, &Context(_c)->cSlice_E9EESRdV, 0, m, &cSlice_E9EESRdV_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cSlice_E9EESRdV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
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

void Heavy_SoundScraper::cVar_ZwMUgIzr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_5a5WVVoY_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_OgHEb7k7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
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
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_qSs8Y3sG_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_hjwmKCDm_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_qrMOoCPx_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_PNeat1CU, 0, m, &cVar_PNeat1CU_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_dMloV94d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_OgHEb7k7_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_SOSLB9w9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_TnCsLt8s, 0, m, &cVar_TnCsLt8s_sendMessage);
}

void Heavy_SoundScraper::cVar_mzdZbr49_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::hTable_bkykhA3v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cBinop_jXIZLaVa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_mzdZbr49, 0, m, &cVar_mzdZbr49_sendMessage);
}

void Heavy_SoundScraper::cVar_TnCsLt8s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cSlice_nl2XhuQl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_SOSLB9w9_sendMessage);
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
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 44100.0f, 0, m, &cBinop_jXIZLaVa_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_ATW5secV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_yDNqQqM2_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_AwTrNThN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_zTsXD6YR_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cUnop_4mlQGE2G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_zLVv9BmV_sendMessage);
}

void Heavy_SoundScraper::cBinop_7Z4Qgs9V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_4mlQGE2G_sendMessage);
}

void Heavy_SoundScraper::cSlice_ED7Gc7D6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_QQtVEHLI, 1, m, &cRandom_QQtVEHLI_sendMessage);
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
      cSlice_onMessage(_c, &Context(_c)->cSlice_ED7Gc7D6, 0, m, &cSlice_ED7Gc7D6_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_QQtVEHLI, 0, m, &cRandom_QQtVEHLI_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cRandom_QQtVEHLI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_7Z4Qgs9V_sendMessage);
}

void Heavy_SoundScraper::cCast_YgwQD2mt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cRandom_9tVFSV5F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 15.0f, 0, m, &cBinop_qqFT9wmO_sendMessage);
}

void Heavy_SoundScraper::cSlice_Tcwnk59D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_9tVFSV5F, 1, m, &cRandom_9tVFSV5F_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cUnop_YttXSjgB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_MgYlK9We_sendMessage);
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
      cSlice_onMessage(_c, &Context(_c)->cSlice_Tcwnk59D, 0, m, &cSlice_Tcwnk59D_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_9tVFSV5F, 0, m, &cRandom_9tVFSV5F_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_qqFT9wmO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_YttXSjgB_sendMessage);
}

void Heavy_SoundScraper::cBinop_JBr92XSv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_09egX2x5_sendMessage);
}

void Heavy_SoundScraper::cBinop_LcMyXhPg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_cv3n2bE1, HV_BINOP_MULTIPLY, 0, m, &cBinop_cv3n2bE1_sendMessage);
}

void Heavy_SoundScraper::cSend_9ZCPUS1n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_dA7RIHfw_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_9f4NnvVA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_DLKm9DGg, 1, m, &cVar_DLKm9DGg_sendMessage);
}

void Heavy_SoundScraper::cVar_DLKm9DGg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_xxTsk9LZ_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_IYCAhXAn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSend_sbOsQGX8_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_HA1o2xNl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_eAs8Zxr3, 0, m, &cDelay_eAs8Zxr3_sendMessage);
}

void Heavy_SoundScraper::cMsg_NQQ74D4c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
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
      cMsg_NQQ74D4c_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_NQQ74D4c_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_eAs8Zxr3, 1, m, &cDelay_eAs8Zxr3_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_HA1o2xNl_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cDelay_eAs8Zxr3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_eAs8Zxr3, m);
  cVar_onMessage(_c, &Context(_c)->cVar_DLKm9DGg, 0, m, &cVar_DLKm9DGg_sendMessage);
}

void Heavy_SoundScraper::cVar_RJx7ENeP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_m7aLwn1C_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_9f4NnvVA_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_iiSpjXuD_sendMessage);
}

void Heavy_SoundScraper::cMsg_caXpuYsq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 25.0f);
  cSend_jaq7UoDM_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_dsq8jUOc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 4000.0f);
  cSend_9ZCPUS1n_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_iiSpjXuD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_URVh5iIh_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cSend_jaq7UoDM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cCast_m7aLwn1C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_mihMMqE2_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_mihMMqE2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 25.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_0dA8JbKr, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_r051JzLh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_RJx7ENeP, 0, m, &cVar_RJx7ENeP_sendMessage);
}

void Heavy_SoundScraper::cSend_sbOsQGX8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_Ju1xS2TW_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_xmtLeHkx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_Ju1xS2TW_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_xxTsk9LZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 0);
  sLine_onMessage(_c, &Context(_c)->sLine_0dA8JbKr, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_MgYlK9We_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.99f, 0, m, &cBinop_vPtQRRQh_sendMessage);
}

void Heavy_SoundScraper::cBinop_6Jo5QUR3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_SG2bcSnR_sendMessage);
}

void Heavy_SoundScraper::cBinop_D426Jifn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6Jo5QUR3, HV_BINOP_POW, 1, m, &cBinop_6Jo5QUR3_sendMessage);
  cMsg_miWQIbJZ_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_SG2bcSnR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_LcMyXhPg, HV_BINOP_DIVIDE, 0, m, &cBinop_LcMyXhPg_sendMessage);
}

void Heavy_SoundScraper::cBinop_i4DLWeZ5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_D426Jifn_sendMessage);
}

void Heavy_SoundScraper::cMsg_miWQIbJZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_6Jo5QUR3, HV_BINOP_POW, 0, m, &cBinop_6Jo5QUR3_sendMessage);
}

void Heavy_SoundScraper::cCast_QfYRZAAt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_r051JzLh_sendMessage);
}

void Heavy_SoundScraper::cSend_ZNxmoVhg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_CyRdbAJg_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_cv3n2bE1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_1zJ53JCY_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Nm2VDzII_sendMessage);
}

void Heavy_SoundScraper::cBinop_09egX2x5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_jkvAnIqU_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_SIN, m, &cUnop_YeVgUD1O_sendMessage);
}

void Heavy_SoundScraper::cPack_GTWpKLKc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_wKjUfunQ, 0, m, NULL);
}

void Heavy_SoundScraper::cUnop_jkvAnIqU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_GTWpKLKc, 0, m, &cPack_GTWpKLKc_sendMessage);
}

void Heavy_SoundScraper::cMsg_dgppUsZb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.5f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_09egX2x5_sendMessage);
}

void Heavy_SoundScraper::cPack_syicmNt1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_iJIcUm7s, 0, m, NULL);
}

void Heavy_SoundScraper::cUnop_YeVgUD1O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_syicmNt1, 0, m, &cPack_syicmNt1_sendMessage);
}

void Heavy_SoundScraper::cCast_nf29zP9d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_Lubx0cB7_onMessage(_c, NULL, 0, m, NULL);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_YgwQD2mt_sendMessage);
}

void Heavy_SoundScraper::cSlice_QfiTVqux_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_siRS5Xy6_sendMessage);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_i4DLWeZ5_sendMessage);
      cPrint_onMessage(_c, m, "PERCSAMPLER_NOTE");
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_vUt3abmG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 127.0f, 0, m, &cBinop_ATW5secV_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cCast_siRS5Xy6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_ZHZrqayz_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_vPtQRRQh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_cv3n2bE1, HV_BINOP_MULTIPLY, 1, m, &cBinop_cv3n2bE1_sendMessage);
}

void Heavy_SoundScraper::cSend_yDNqQqM2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_WLjoD2qK_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_zLVv9BmV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.4f, 0, m, &cBinop_JBr92XSv_sendMessage);
}

void Heavy_SoundScraper::cSend_0D2kpuST_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_q6o7mfie_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_ATi9TEdf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_NtklF6lA_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_BT0HiEqz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_5f3FvQpl_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_C44j8RJg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.99f, 0, m, &cBinop_kZN1w8N7_sendMessage);
}

void Heavy_SoundScraper::cCast_DIJs7fzR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_8tM3GqzD_sendMessage);
}

void Heavy_SoundScraper::cBinop_3ZOWsDhU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_c3iMbzeS_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_SIN, m, &cUnop_AaA9U5uC_sendMessage);
}

void Heavy_SoundScraper::cUnop_c3iMbzeS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_tIvhH3p5, 0, m, &cPack_tIvhH3p5_sendMessage);
}

void Heavy_SoundScraper::cPack_MjBTWEfR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_nsa1SCND, 0, m, NULL);
}

void Heavy_SoundScraper::cMsg_Rlngzr2V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.5f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_3ZOWsDhU_sendMessage);
}

void Heavy_SoundScraper::cUnop_AaA9U5uC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_MjBTWEfR, 0, m, &cPack_MjBTWEfR_sendMessage);
}

void Heavy_SoundScraper::cPack_tIvhH3p5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_gVqws3WR, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_MUthzqlo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ZCwEjOv8_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_mCwWjVxC_sendMessage);
}

void Heavy_SoundScraper::cMsg_9GeG4B5s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSwitchcase_ikjnkobH_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::hTable_AKQw9gB5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cMsg_3XlUCyj6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_m8tkTnxv_sendMessage);
}

void Heavy_SoundScraper::cBinop_bkE8MJkt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_HgSXPSnM, m);
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
      cSlice_onMessage(_c, &Context(_c)->cSlice_rp4aa40z, 0, m, &cSlice_rp4aa40z_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cSystem_m8tkTnxv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 2.0f, 0, m, &cBinop_bkE8MJkt_sendMessage);
}

void Heavy_SoundScraper::cSlice_rp4aa40z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
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

void Heavy_SoundScraper::cVar_sTYvRhZ9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_3XlUCyj6_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_1115YzV3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_TjNMcqvZ, 0, m, &cVar_TjNMcqvZ_sendMessage);
}

void Heavy_SoundScraper::cVar_XqVNmeJ7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_FYzMBkaY, 0, m, &cPack_FYzMBkaY_sendMessage);
}

void Heavy_SoundScraper::cCast_9zhNSftQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_TjNMcqvZ, 1, m, &cVar_TjNMcqvZ_sendMessage);
}

void Heavy_SoundScraper::cBinop_AQ3aaPPE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_jKcCiv7a, 0, m, &cPack_jKcCiv7a_sendMessage);
}

void Heavy_SoundScraper::cVar_TjNMcqvZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_ZL0ffJl0_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_DEuc7UtW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_XqVNmeJ7, 0, m, &cVar_XqVNmeJ7_sendMessage);
}

void Heavy_SoundScraper::cSend_DuquqJOg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_j108jHSS_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_FYzMBkaY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_SZlyNABT_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_FnRHGmvv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_j8wxsOsu, 0, m, &cPack_j8wxsOsu_sendMessage);
}

void Heavy_SoundScraper::cSend_HVo32Nnw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_5HY5fLM2_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_GiN3QG1U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 100000.0f, 0, m, &cBinop_AQ3aaPPE_sendMessage);
}

void Heavy_SoundScraper::cCast_3cUzpd2y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_jz3tGdki, 0, m, &cVar_jz3tGdki_sendMessage);
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
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_z1SsqQq5_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_znGAkzjR_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_lT3yyo1g_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_3cUzpd2y_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cVar_jz3tGdki_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_nb6VTrFm, HV_BINOP_DIVIDE, 0, m, &cBinop_nb6VTrFm_sendMessage);
}

void Heavy_SoundScraper::cCast_lT3yyo1g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_RyS40cLD, 0, m, &cVar_RyS40cLD_sendMessage);
}

void Heavy_SoundScraper::cVar_RyS40cLD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_nb6VTrFm, HV_BINOP_DIVIDE, 1, m, &cBinop_nb6VTrFm_sendMessage);
}

void Heavy_SoundScraper::cCast_z1SsqQq5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_RyS40cLD, 0, m, &cVar_RyS40cLD_sendMessage);
}

void Heavy_SoundScraper::cCast_znGAkzjR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_jz3tGdki, 0, m, &cVar_jz3tGdki_sendMessage);
}

void Heavy_SoundScraper::cCast_Kgr6aHNB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_FnRHGmvv_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_MIpmAbms_sendMessage);
}

void Heavy_SoundScraper::cCast_MIpmAbms_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_qRRLSX7s_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cSend_SZlyNABT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_5HY5fLM2_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_1UxLhA9z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_1qnhKvZ9, 0, m, &cDelay_1qnhKvZ9_sendMessage);
}

void Heavy_SoundScraper::cDelay_1qnhKvZ9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_1qnhKvZ9, m);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_1115YzV3_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_DEuc7UtW_sendMessage);
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
      cMsg_1UxLhA9z_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_1UxLhA9z_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_1qnhKvZ9, 1, m, &cDelay_1qnhKvZ9_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_v5MSEa5l_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_v5MSEa5l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_1qnhKvZ9, 0, m, &cDelay_1qnhKvZ9_sendMessage);
}

void Heavy_SoundScraper::cMsg_cKRqcgtb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 44100.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 100.0f, 0, m, &cBinop_l0iyJSRM_sendMessage);
}

void Heavy_SoundScraper::cMsg_d7xusZhg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 0.0f);
  cSend_DuquqJOg_sendMessage(_c, 0, m);
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 1);
  msg_setElementToFrom(m, 1, n, 0);
  cSend_DuquqJOg_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_j8wxsOsu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_HVo32Nnw_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_jKcCiv7a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_d7xusZhg_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_l0iyJSRM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_jKcCiv7a, 1, m, &cPack_jKcCiv7a_sendMessage);
}

void Heavy_SoundScraper::cBinop_nb6VTrFm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_GiN3QG1U, 0, m, &cVar_GiN3QG1U_sendMessage);
}

void Heavy_SoundScraper::cVar_NZZWo5bx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cCast_xZ3h0xCV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cBinop_dJXlauGI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_roaFw89G, 0, m, &cVar_roaFw89G_sendMessage);
}

void Heavy_SoundScraper::cVar_EqloIxkt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cVar_roaFw89G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cSlice_BcSVFyaO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_mwUeFqx8_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_VHV4oP1k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 44100.0f, 0, m, &cBinop_dJXlauGI_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_mwUeFqx8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_EqloIxkt, 0, m, &cVar_EqloIxkt_sendMessage);
}

void Heavy_SoundScraper::cSlice_bIRRz79x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_9GeG4B5s_sendMessage(_c, 0, m);
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
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_xZ3h0xCV_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_9zhNSftQ_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Kgr6aHNB_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_NZZWo5bx, 0, m, &cVar_NZZWo5bx_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSend_NtklF6lA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_41RaPf9H_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_KXcAfqmU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_2AeIl7oo, 1, m, &cPack_2AeIl7oo_sendMessage);
}

void Heavy_SoundScraper::cPack_2AeIl7oo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_iWvALRp0_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_DIJs7fzR_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_bIRRz79x, 0, m, &cSlice_bIRRz79x_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_qcBgEtaq, 0, m, &cSlice_qcBgEtaq_sendMessage);
  cPrint_onMessage(_c, m, "TABLEPLAYER_COMMAND");
}

void Heavy_SoundScraper::cCast_ZCwEjOv8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_KXcAfqmU, 0, m, &cVar_KXcAfqmU_sendMessage);
}

void Heavy_SoundScraper::cCast_mCwWjVxC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_2AeIl7oo, 0, m, &cPack_2AeIl7oo_sendMessage);
}

void Heavy_SoundScraper::cBinop_1ufanUhg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_Bs7MqkEk_sendMessage);
}

void Heavy_SoundScraper::cBinop_BHxpRmB8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_hfbH4B17_sendMessage);
}

void Heavy_SoundScraper::cBinop_Bs7MqkEk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_BHxpRmB8, HV_BINOP_POW, 1, m, &cBinop_BHxpRmB8_sendMessage);
  cMsg_f253eZ1l_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_f253eZ1l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_BHxpRmB8, HV_BINOP_POW, 0, m, &cBinop_BHxpRmB8_sendMessage);
}

void Heavy_SoundScraper::cBinop_hfbH4B17_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_dFGGLTVi, HV_BINOP_DIVIDE, 0, m, &cBinop_dFGGLTVi_sendMessage);
}

void Heavy_SoundScraper::cSlice_Hd8hM02e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 127.0f, 0, m, &cBinop_ATi9TEdf_sendMessage);
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
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_dfqwTHm9_sendMessage);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_1ufanUhg_sendMessage);
      cPrint_onMessage(_c, m, "PERCSAMPLER_NOTE");
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_82fhNWaF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_Y94JPdTL, 1, m, &cRandom_Y94JPdTL_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_Bu4DfUSD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_b2BDuKG9_sendMessage);
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
      cSlice_onMessage(_c, &Context(_c)->cSlice_82fhNWaF, 0, m, &cSlice_82fhNWaF_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_Y94JPdTL, 0, m, &cRandom_Y94JPdTL_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cRandom_Y94JPdTL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_Bu4DfUSD_sendMessage);
}

void Heavy_SoundScraper::cUnop_b2BDuKG9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_uy9W0ihE_sendMessage);
}

void Heavy_SoundScraper::cSend_5rrwxNbA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_z6iEtg1P_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_67wbfJ2g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_nwVQZ7Iz_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_7RN2VUle_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cVar_lCwYyBZF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_67wbfJ2g_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_K1iTqUaI_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_eKFpH9a2_sendMessage);
}

void Heavy_SoundScraper::cCast_8tM3GqzD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_lCwYyBZF, 0, m, &cVar_lCwYyBZF_sendMessage);
}

void Heavy_SoundScraper::cMsg_CJNK44x7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 4000.0f);
  cSend_cjLnMgKR_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_5peHtRuo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_5peHtRuo, m);
  cVar_onMessage(_c, &Context(_c)->cVar_XSnpUi0o, 0, m, &cVar_XSnpUi0o_sendMessage);
}

void Heavy_SoundScraper::cMsg_NjAhlDw2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_5peHtRuo, 0, m, &cDelay_5peHtRuo_sendMessage);
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
      cMsg_NjAhlDw2_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_NjAhlDw2_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_5peHtRuo, 1, m, &cDelay_5peHtRuo_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_qyTvtMHX_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_qyTvtMHX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_5peHtRuo, 0, m, &cDelay_5peHtRuo_sendMessage);
}

void Heavy_SoundScraper::cCast_K1iTqUaI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_XSnpUi0o, 1, m, &cVar_XSnpUi0o_sendMessage);
}

void Heavy_SoundScraper::cMsg_QV33UwVu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSend_5rrwxNbA_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_aJbMkgtr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_z6iEtg1P_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_cjLnMgKR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_me6GXtaS_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_eKFpH9a2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_PrhVKwoR_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cMsg_gNspD6OU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 25.0f);
  cSend_7RN2VUle_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_XSnpUi0o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_poDeI2Li_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_nwVQZ7Iz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 25.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_7wuBgJ5s, 0, m, NULL);
}

void Heavy_SoundScraper::cMsg_poDeI2Li_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 0);
  sLine_onMessage(_c, &Context(_c)->sLine_7wuBgJ5s, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_dFGGLTVi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MUthzqlo, HV_BINOP_MULTIPLY, 0, m, &cBinop_MUthzqlo_sendMessage);
}

void Heavy_SoundScraper::cCast_dfqwTHm9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_SJPwmyYX_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cSlice_8a9gRL90_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSend_BT0HiEqz_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_GwyReTK2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
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

void Heavy_SoundScraper::cCast_iWvALRp0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_HCWRmhFz_onMessage(_c, NULL, 0, m, NULL);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_AnEFSGuF_sendMessage);
}

void Heavy_SoundScraper::cBinop_kZN1w8N7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MUthzqlo, HV_BINOP_MULTIPLY, 1, m, &cBinop_MUthzqlo_sendMessage);
}

void Heavy_SoundScraper::cCast_AnEFSGuF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cSlice_3qs68nzi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_E5MjjYrs, 1, m, &cRandom_E5MjjYrs_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cRandom_E5MjjYrs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 15.0f, 0, m, &cBinop_aAcUWa8w_sendMessage);
}

void Heavy_SoundScraper::cUnop_OZKxp9pw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_C44j8RJg_sendMessage);
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
      cSlice_onMessage(_c, &Context(_c)->cSlice_3qs68nzi, 0, m, &cSlice_3qs68nzi_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_E5MjjYrs, 0, m, &cRandom_E5MjjYrs_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_aAcUWa8w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_OZKxp9pw_sendMessage);
}

void Heavy_SoundScraper::cBinop_u5imjPEP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_3ZOWsDhU_sendMessage);
}

void Heavy_SoundScraper::cBinop_uy9W0ihE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.4f, 0, m, &cBinop_u5imjPEP_sendMessage);
}

void Heavy_SoundScraper::cReceive_fKOUPBDH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPrint_onMessage(_c, m, "SET_TABLE");
  cSlice_onMessage(_c, &Context(_c)->cSlice_GwyReTK2, 0, m, &cSlice_GwyReTK2_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_8a9gRL90, 0, m, &cSlice_8a9gRL90_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_iVcBj2d4, 0, m, &cSlice_iVcBj2d4_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_5qKhvvY8, 0, m, &cSlice_5qKhvvY8_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_Nj6DFvLz, 0, m, &cSlice_Nj6DFvLz_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_6C9Y56FE, 0, m, &cSlice_6C9Y56FE_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_Y3fYBJlC, 0, m, &cSlice_Y3fYBJlC_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_y01lKo1A, 0, m, &cSlice_y01lKo1A_sendMessage);
  cSend_Ji6gv0SC_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cReceive_gi3bKbGJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 2.0f, 0, m, &cBinop_jFpSjkXl_sendMessage);
}

void Heavy_SoundScraper::cCast_1G8QLz2k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_1HRfmt7H_onMessage(_c, NULL, 0, m, NULL);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_vEtCiE0s_sendMessage);
}

void Heavy_SoundScraper::cBinop_4Zy7imgy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_zaKDLKho, HV_BINOP_MULTIPLY, 0, m, &cBinop_zaKDLKho_sendMessage);
}

void Heavy_SoundScraper::cCast_4rBvr7Uc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_o0Lq7fcj_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cSlice_IQg9xqrX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 127.0f, 0, m, &cBinop_eYfmPTZr_sendMessage);
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
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_4rBvr7Uc_sendMessage);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_64xRwxyY_sendMessage);
      cPrint_onMessage(_c, m, "PERCSAMPLER_NOTE");
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_7RNeH53b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.99f, 0, m, &cBinop_QsoULHxF_sendMessage);
}

void Heavy_SoundScraper::cBinop_8EDJoabJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_wm7JtPMK_sendMessage);
}

void Heavy_SoundScraper::cCast_BIXZnmg1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_8DnEodvj_sendMessage);
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
      cSlice_onMessage(_c, &Context(_c)->cSlice_kwUSvw2u, 0, m, &cSlice_kwUSvw2u_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_FS4owC4a, 0, m, &cRandom_FS4owC4a_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cRandom_FS4owC4a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_SDREH4oa_sendMessage);
}

void Heavy_SoundScraper::cBinop_SDREH4oa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_d7B4bXi2_sendMessage);
}

void Heavy_SoundScraper::cUnop_d7B4bXi2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_UwHC7l98_sendMessage);
}

void Heavy_SoundScraper::cSlice_kwUSvw2u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_FS4owC4a, 1, m, &cRandom_FS4owC4a_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_WWTSImWG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_yXJmAi9R_sendMessage);
}

void Heavy_SoundScraper::cSlice_ZcejJIy1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_znEJCKP6, 1, m, &cRandom_znEJCKP6_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
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
      cSlice_onMessage(_c, &Context(_c)->cSlice_ZcejJIy1, 0, m, &cSlice_ZcejJIy1_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_znEJCKP6, 0, m, &cRandom_znEJCKP6_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cUnop_yXJmAi9R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_7RNeH53b_sendMessage);
}

void Heavy_SoundScraper::cRandom_znEJCKP6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 15.0f, 0, m, &cBinop_WWTSImWG_sendMessage);
}

void Heavy_SoundScraper::cSend_LLQSv5U0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_2Rgd81on_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_1Q0fc1xd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_1fKEsrqn_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cSend_2r46FSc4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_TIg47hmJ_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_3XAlCAba_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSend_2r46FSc4_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_8DnEodvj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_3n85lNl6, 0, m, &cVar_3n85lNl6_sendMessage);
}

void Heavy_SoundScraper::cCast_8W3wifGY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_SMf3xEQ5_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_fuCyXzIE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_WBu661zv_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_JRc8LTmf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_TIg47hmJ_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_3n85lNl6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_8W3wifGY_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_qimXY1rv_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_1Q0fc1xd_sendMessage);
}

void Heavy_SoundScraper::cMsg_SMf3xEQ5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 25.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_O0ifSzPL, 0, m, NULL);
}

void Heavy_SoundScraper::cMsg_WBu661zv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 0);
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
      cMsg_Cw7wEHKg_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_Cw7wEHKg_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_XXe4aOsj, 1, m, &cDelay_XXe4aOsj_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_E2D4TpTa_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cMsg_Cw7wEHKg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_XXe4aOsj, 0, m, &cDelay_XXe4aOsj_sendMessage);
}

void Heavy_SoundScraper::cCast_E2D4TpTa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_XXe4aOsj, 0, m, &cDelay_XXe4aOsj_sendMessage);
}

void Heavy_SoundScraper::cDelay_XXe4aOsj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_XXe4aOsj, m);
  cVar_onMessage(_c, &Context(_c)->cVar_fuCyXzIE, 0, m, &cVar_fuCyXzIE_sendMessage);
}

void Heavy_SoundScraper::cSend_kG80vQei_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cSend_n1drs6ME_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_5hQZcw1R_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_omqBk88d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 4000.0f);
  cSend_n1drs6ME_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_qimXY1rv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_fuCyXzIE, 1, m, &cVar_fuCyXzIE_sendMessage);
}

void Heavy_SoundScraper::cMsg_zbJngBFJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 25.0f);
  cSend_kG80vQei_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_Ek55gQhE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cMsg_5G7uBBwC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
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
  cMsg_bcA4id0C_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_8YVWemzl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_6qRZEOOM, 0, m, &cVar_6qRZEOOM_sendMessage);
}

void Heavy_SoundScraper::cCast_ATyiAS9b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_CHWKAnDn, 0, m, &cVar_CHWKAnDn_sendMessage);
}

void Heavy_SoundScraper::cVar_6qRZEOOM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_iiTUjhp9, HV_BINOP_DIVIDE, 0, m, &cBinop_iiTUjhp9_sendMessage);
}

void Heavy_SoundScraper::cCast_P20QSp83_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_CHWKAnDn, 0, m, &cVar_CHWKAnDn_sendMessage);
}

void Heavy_SoundScraper::cVar_CHWKAnDn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_iiTUjhp9, HV_BINOP_DIVIDE, 1, m, &cBinop_iiTUjhp9_sendMessage);
}

void Heavy_SoundScraper::cCast_mVivvAP5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_6qRZEOOM, 0, m, &cVar_6qRZEOOM_sendMessage);
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
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_P20QSp83_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_8YVWemzl_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ATyiAS9b_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_mVivvAP5_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_8lrd54HH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cCast_CQJYYjjP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_L8oii4oq, 0, m, &cVar_L8oii4oq_sendMessage);
}

void Heavy_SoundScraper::cCast_E4u2AgAz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_bcYg07Ut, 0, m, &cPack_bcYg07Ut_sendMessage);
}

void Heavy_SoundScraper::cCast_HWyBuD8F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_2WqJlITT, 1, m, &cVar_2WqJlITT_sendMessage);
}

void Heavy_SoundScraper::cSend_KV1fbE36_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_KAf1xh4c_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_LRZqPo9X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 44100.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 100.0f, 0, m, &cBinop_tukvbl1d_sendMessage);
}

void Heavy_SoundScraper::cVar_2WqJlITT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_r1PszvVU_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_RWK9duXY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_5K877NH9, 0, m, &cPack_5K877NH9_sendMessage);
}

void Heavy_SoundScraper::cVar_CuLuBKX3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 100000.0f, 0, m, &cBinop_RWK9duXY_sendMessage);
}

void Heavy_SoundScraper::cVar_DuQ4Co8P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cCast_bDdiAUpi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_E4u2AgAz_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ln4JGEOJ_sendMessage);
}

void Heavy_SoundScraper::cMsg_bcA4id0C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 0.0f);
  cSend_KV1fbE36_sendMessage(_c, 0, m);
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 1);
  msg_setElementToFrom(m, 1, n, 0);
  cSend_KV1fbE36_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_bcYg07Ut_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_xdeW7YyO_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_f0L3zTiX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_qQh6LlcC_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_iiTUjhp9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_CuLuBKX3, 0, m, &cVar_CuLuBKX3_sendMessage);
}

void Heavy_SoundScraper::cCast_ln4JGEOJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_Syd36h5d_onMessage(_c, NULL, 0, m, NULL);
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
      cMsg_uuI8AlL4_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_uuI8AlL4_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_tJ5A26Ex, 1, m, &cDelay_tJ5A26Ex_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_stZaYNFS_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_stZaYNFS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_tJ5A26Ex, 0, m, &cDelay_tJ5A26Ex_sendMessage);
}

void Heavy_SoundScraper::cDelay_tJ5A26Ex_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_tJ5A26Ex, m);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_pihpntGc_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_CQJYYjjP_sendMessage);
}

void Heavy_SoundScraper::cMsg_uuI8AlL4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_tJ5A26Ex, 0, m, &cDelay_tJ5A26Ex_sendMessage);
}

void Heavy_SoundScraper::cCast_pihpntGc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_2WqJlITT, 0, m, &cVar_2WqJlITT_sendMessage);
}

void Heavy_SoundScraper::cSend_qQh6LlcC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_pJyJ8beI_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_tukvbl1d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_5K877NH9, 1, m, &cPack_5K877NH9_sendMessage);
}

void Heavy_SoundScraper::cSend_xdeW7YyO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_pJyJ8beI_sendMessage(_c, 0, m);
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
      cSlice_onMessage(_c, &Context(_c)->cSlice_SYuu5iYJ, 0, m, &cSlice_SYuu5iYJ_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cSlice_SYuu5iYJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
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

void Heavy_SoundScraper::cVar_UyoDPMGJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_wKa03XuD_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSystem_V9AclM2w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 2.0f, 0, m, &cBinop_kJbUExuH_sendMessage);
}

void Heavy_SoundScraper::cBinop_kJbUExuH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_bgDUH05l, m);
}

void Heavy_SoundScraper::cMsg_wKa03XuD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_V9AclM2w_sendMessage);
}

void Heavy_SoundScraper::cBinop_C95KwuAg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Ek55gQhE, 0, m, &cVar_Ek55gQhE_sendMessage);
}

void Heavy_SoundScraper::cBinop_L70vIPrx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_9zT65X1L, 0, m, &cVar_9zT65X1L_sendMessage);
}

void Heavy_SoundScraper::cVar_9zT65X1L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cSlice_SeWjqHEN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 44100.0f, 0, m, &cBinop_C95KwuAg_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_kdQjtT8p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_L70vIPrx_sendMessage);
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
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_8lrd54HH_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_HWyBuD8F_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_bDdiAUpi_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_DuQ4Co8P, 0, m, &cVar_DuQ4Co8P_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_Uyt9Kp3d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_5G7uBBwC_sendMessage(_c, 0, m);
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

void Heavy_SoundScraper::cBinop_QsoULHxF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_zaKDLKho, HV_BINOP_MULTIPLY, 1, m, &cBinop_zaKDLKho_sendMessage);
}

void Heavy_SoundScraper::cPack_32YTVbUD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_kpWJi41L, 0, m, NULL);
}

void Heavy_SoundScraper::cUnop_a5WxHAhH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_32YTVbUD, 0, m, &cPack_32YTVbUD_sendMessage);
}

void Heavy_SoundScraper::cMsg_I80szfDg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.5f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_wm7JtPMK_sendMessage);
}

void Heavy_SoundScraper::cUnop_q8u6ZIF4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_e5WkLpVn, 0, m, &cPack_e5WkLpVn_sendMessage);
}

void Heavy_SoundScraper::cPack_e5WkLpVn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_fa9VpVzC, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_wm7JtPMK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_q8u6ZIF4_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_SIN, m, &cUnop_a5WxHAhH_sendMessage);
}

void Heavy_SoundScraper::cBinop_UwHC7l98_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.4f, 0, m, &cBinop_8EDJoabJ_sendMessage);
}

void Heavy_SoundScraper::cBinop_eYfmPTZr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_LLQSv5U0_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_gjWlTd1g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_jqVRSnP5, 0, m, &cPack_jqVRSnP5_sendMessage);
}

void Heavy_SoundScraper::cVar_U4JpgUYy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_jqVRSnP5, 1, m, &cPack_jqVRSnP5_sendMessage);
}

void Heavy_SoundScraper::cPack_jqVRSnP5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_1G8QLz2k_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_BIXZnmg1_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_Uyt9Kp3d, 0, m, &cSlice_Uyt9Kp3d_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_GkIAmfP8, 0, m, &cSlice_GkIAmfP8_sendMessage);
  cPrint_onMessage(_c, m, "TABLEPLAYER_COMMAND");
}

void Heavy_SoundScraper::cCast_rLXr4Edz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_U4JpgUYy, 0, m, &cVar_U4JpgUYy_sendMessage);
}

void Heavy_SoundScraper::cBinop_64xRwxyY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_iNvifLt4_sendMessage);
}

void Heavy_SoundScraper::cBinop_7mt73e01_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4Zy7imgy, HV_BINOP_DIVIDE, 0, m, &cBinop_4Zy7imgy_sendMessage);
}

void Heavy_SoundScraper::cMsg_Ppd5goO8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_mq5joYsZ, HV_BINOP_POW, 0, m, &cBinop_mq5joYsZ_sendMessage);
}

void Heavy_SoundScraper::cBinop_iNvifLt4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_mq5joYsZ, HV_BINOP_POW, 1, m, &cBinop_mq5joYsZ_sendMessage);
  cMsg_Ppd5goO8_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_mq5joYsZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_7mt73e01_sendMessage);
}

void Heavy_SoundScraper::cSend_pfaPnV1i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_PC7vIRkt_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSlice_5qKhvvY8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSend_pfaPnV1i_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_iVcBj2d4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
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
  cReceive_bcGB1aGC_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_zaKDLKho_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_rLXr4Edz_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_gjWlTd1g_sendMessage);
}

void Heavy_SoundScraper::cReceive_hhNFlC8R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSlice_onMessage(_c, &Context(_c)->cSlice_tsVaYaSp, 0, m, &cSlice_tsVaYaSp_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_UKaWzyTm, 0, m, &cSlice_UKaWzyTm_sendMessage);
}

void Heavy_SoundScraper::cReceive_i89foIcW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_zIqdTANI, 0, m, &cVar_zIqdTANI_sendMessage);
}

void Heavy_SoundScraper::cReceive_iBd6GA39_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_aT0m7Cx6, 0, m, &cVar_aT0m7Cx6_sendMessage);
}

void Heavy_SoundScraper::cSend_IgfylhRP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_8ia9UA0J_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_VpBFxQUK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_RJ028IRF_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_3HiO7cSt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_gkYZLs8V_sendMessage);
}

void Heavy_SoundScraper::cBinop_6dHVvDyN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_3HiO7cSt_sendMessage);
}

void Heavy_SoundScraper::cCast_IU0YaDfn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_RH0tEmei_sendMessage);
}

void Heavy_SoundScraper::cMsg_KkRg0DLp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_vRGo39Wp, 0, m, &cPack_vRGo39Wp_sendMessage);
}

void Heavy_SoundScraper::cBinop_PCkC4yJ9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_vRGo39Wp, 0, m, &cPack_vRGo39Wp_sendMessage);
}

void Heavy_SoundScraper::cIf_RA7KvXe4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_KkRg0DLp_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_6dHVvDyN_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_RH0tEmei_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_RA7KvXe4, 1, m, &cIf_RA7KvXe4_sendMessage);
}

void Heavy_SoundScraper::cCast_ZloLYCGC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_RA7KvXe4, 0, m, &cIf_RA7KvXe4_sendMessage);
}

void Heavy_SoundScraper::cMsg_by5Gs2rE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_PCkC4yJ9, HV_BINOP_POW, 0, m, &cBinop_PCkC4yJ9_sendMessage);
}

void Heavy_SoundScraper::cBinop_gkYZLs8V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_PCkC4yJ9, HV_BINOP_POW, 1, m, &cBinop_PCkC4yJ9_sendMessage);
  cMsg_by5Gs2rE_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_vKvuftOz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_VpBFxQUK_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_Zn1ojjrH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_zfpMRGbO_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_IU0YaDfn_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ZloLYCGC_sendMessage);
}

void Heavy_SoundScraper::cPack_vRGo39Wp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_HUDYAN2U, 0, m, NULL);
}

void Heavy_SoundScraper::cMsg_zfpMRGbO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSend_IgfylhRP_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cReceive_j108jHSS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_cAPdStYy, 0, m, NULL);
  cPrint_onMessage(_c, m, "TABLEPLAYER_PHASE");
  cSlice_onMessage(_c, &Context(_c)->cSlice_BcSVFyaO, 0, m, &cSlice_BcSVFyaO_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_VHV4oP1k, 0, m, &cSlice_VHV4oP1k_sendMessage);
}

void Heavy_SoundScraper::cReceive_j8Mz1NLg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_cS0XuRV6_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cReceive_jC4Mczgd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_GrNtTg0B_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cReceive_jMhwovL4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_F2XDIkNh_sendMessage(_c, 0, m);
  cSwitchcase_vzL8Ewdk_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cSend_ITbRU55N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_qRnOVDWs_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_s7XorbYO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cSend_ITbRU55N_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_2GtQHjks_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_6lhEfuBZ, 1, m, &cIf_6lhEfuBZ_sendMessage);
}

void Heavy_SoundScraper::cIf_AszExoYR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSend_Puh9jqA5_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cCast_5Pwk6Bki_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_8IgWrNwI, 1, m, &cIf_8IgWrNwI_sendMessage);
}

void Heavy_SoundScraper::cIf_Dtw77kAZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
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

void Heavy_SoundScraper::cUnop_8pKouf3R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_fsBm2IPb_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_wo4DGSH0, HV_BINOP_EQ, 1, m, &cBinop_wo4DGSH0_sendMessage);
}

void Heavy_SoundScraper::cVar_Majfm0GP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_DWT53kAW_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_yYNfatI5, 0, m, &cIf_yYNfatI5_sendMessage);
}

void Heavy_SoundScraper::cBinop_DWT53kAW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_yYNfatI5, 1, m, &cIf_yYNfatI5_sendMessage);
}

void Heavy_SoundScraper::cUnop_wH18cWvJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_fsBm2IPb_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_wo4DGSH0, HV_BINOP_EQ, 1, m, &cBinop_wo4DGSH0_sendMessage);
}

void Heavy_SoundScraper::cIf_yYNfatI5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
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

void Heavy_SoundScraper::cIf_8IgWrNwI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSend_Puh9jqA5_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
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

void Heavy_SoundScraper::cCast_fjKmw1qu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_Dtw77kAZ, 1, m, &cIf_Dtw77kAZ_sendMessage);
}

void Heavy_SoundScraper::cBinop_fsBm2IPb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_2GtQHjks_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_5Pwk6Bki_sendMessage);
}

void Heavy_SoundScraper::cCast_ghFQYlsD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_AszExoYR, 1, m, &cIf_AszExoYR_sendMessage);
}

void Heavy_SoundScraper::cBinop_hHsgWtJ6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_paZvFr1u_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSlice_UZOVBp1z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cIf_onMessage(_c, &Context(_c)->cIf_6lhEfuBZ, 0, m, &cIf_6lhEfuBZ_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_Dtw77kAZ, 0, m, &cIf_Dtw77kAZ_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_Y4hxMcna_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_n8BJSAmA_sendMessage);
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
      cIf_onMessage(_c, &Context(_c)->cIf_AszExoYR, 0, m, &cIf_AszExoYR_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_8IgWrNwI, 0, m, &cIf_8IgWrNwI_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_n8BJSAmA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_wo4DGSH0, HV_BINOP_EQ, 0, m, &cBinop_wo4DGSH0_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_hHsgWtJ6_sendMessage);
}

void Heavy_SoundScraper::cBinop_wo4DGSH0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_fjKmw1qu_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ghFQYlsD_sendMessage);
}

void Heavy_SoundScraper::cSend_7uiDpFd4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_FeOwgZiZ_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_Puh9jqA5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_br9NnjpD_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_paZvFr1u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cReceive_jlnIpbMW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_XHpwjSSN, 0, m, &cVar_XHpwjSSN_sendMessage);
}

void Heavy_SoundScraper::cReceive_kF0RAx1I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 2.0f, 0, m, &cBinop_0goEnjha_sendMessage);
}

void Heavy_SoundScraper::cCast_6pUjozXE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_TuXtPgx8, 0, m, &cVar_TuXtPgx8_sendMessage);
}

void Heavy_SoundScraper::cSlice_1gy5ErY8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_vUt3abmG, 0, m, &cSlice_vUt3abmG_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_QfiTVqux, 0, m, &cSlice_QfiTVqux_sendMessage);
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_vUt3abmG, 0, m, &cSlice_vUt3abmG_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_QfiTVqux, 0, m, &cSlice_QfiTVqux_sendMessage);
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
      cSlice_onMessage(_c, &Context(_c)->cSlice_l2aq8nF3, 0, m, &cSlice_l2aq8nF3_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_xuydrICF, 0, m, &cSlice_xuydrICF_sendMessage);
      break;
    }
    case 0x40000000: { // "2.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_onIDdbjZ, 0, m, &cSlice_onIDdbjZ_sendMessage);
      break;
    }
    case 0x40400000: { // "3.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_1gy5ErY8, 0, m, &cSlice_1gy5ErY8_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cSlice_l2aq8nF3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_Hd8hM02e, 0, m, &cSlice_Hd8hM02e_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_ubdBPvp7, 0, m, &cSlice_ubdBPvp7_sendMessage);
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_Hd8hM02e, 0, m, &cSlice_Hd8hM02e_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_ubdBPvp7, 0, m, &cSlice_ubdBPvp7_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_onIDdbjZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_wFZuWykC, 0, m, &cSlice_wFZuWykC_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_YFizWWF7, 0, m, &cSlice_YFizWWF7_sendMessage);
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_wFZuWykC, 0, m, &cSlice_wFZuWykC_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_YFizWWF7, 0, m, &cSlice_YFizWWF7_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_xuydrICF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_IQg9xqrX, 0, m, &cSlice_IQg9xqrX_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_hAc6aAxe, 0, m, &cSlice_hAc6aAxe_sendMessage);
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_IQg9xqrX, 0, m, &cSlice_IQg9xqrX_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_hAc6aAxe, 0, m, &cSlice_hAc6aAxe_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cPack_IVZ00RuP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_kGiuDpyt, 0, m, &cIf_kGiuDpyt_sendMessage);
}

void Heavy_SoundScraper::cCast_Kd8cOL0a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_lA7P06zw, 1, m, &cPack_lA7P06zw_sendMessage);
}

void Heavy_SoundScraper::cMsg_HqkuD6Lx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_Gvx3wYfG, 0, m, &cVar_Gvx3wYfG_sendMessage);
}

void Heavy_SoundScraper::cIf_kGiuDpyt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_qjwdR5zu, 0, m, &cSlice_qjwdR5zu_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_JsNDXk3i, 0, m, &cSlice_JsNDXk3i_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_OBJl1JQ9, 0, m, &cIf_OBJl1JQ9_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cCast_TqEc0I18_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_HqkuD6Lx_sendMessage(_c, 0, m);
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
      cMsg_gU56DZxO_sendMessage(_c, 0, m);
      break;
    }
  }
}

void Heavy_SoundScraper::cMsg_gU56DZxO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_Gvx3wYfG, 0, m, &cVar_Gvx3wYfG_sendMessage);
}

void Heavy_SoundScraper::cBinop_JocSBMRA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Gvx3wYfG, 1, m, &cVar_Gvx3wYfG_sendMessage);
}

void Heavy_SoundScraper::cVar_Gvx3wYfG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_JocSBMRA_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_kGiuDpyt, 1, m, &cIf_kGiuDpyt_sendMessage);
}

void Heavy_SoundScraper::cMsg_QXSo6FKJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_l8cNHrsG_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cVar_TuXtPgx8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_lA7P06zw, 0, m, &cPack_lA7P06zw_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_if5HjkQK_sendMessage);
}

void Heavy_SoundScraper::cBinop_YdePOomD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_TuXtPgx8, 1, m, &cVar_TuXtPgx8_sendMessage);
}

void Heavy_SoundScraper::cBinop_6rOONnze_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_3iNR7v2q, 1, m, &cIf_3iNR7v2q_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_4Sx7CBu4, 1, m, &cIf_4Sx7CBu4_sendMessage);
}

void Heavy_SoundScraper::cPack_9a733PFq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_gBDy3SwE, 0, m, &cIf_gBDy3SwE_sendMessage);
}

void Heavy_SoundScraper::cCast_DTT88hSh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_m8Ix3fHp, 0, m, &cVar_m8Ix3fHp_sendMessage);
}

void Heavy_SoundScraper::cIf_gBDy3SwE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_0dnQNxrx, 0, m, &cSlice_0dnQNxrx_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_tp36l5d9, 0, m, &cSlice_tp36l5d9_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_NhP4EV7m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_gBDy3SwE, 1, m, &cIf_gBDy3SwE_sendMessage);
}

void Heavy_SoundScraper::cCast_NyfBHUVc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_9a733PFq, 0, m, &cPack_9a733PFq_sendMessage);
}

void Heavy_SoundScraper::cMsg_WhViqqNR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_m8Ix3fHp, 1, m, &cVar_m8Ix3fHp_sendMessage);
}

void Heavy_SoundScraper::cIf_OBJl1JQ9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_0dnQNxrx, 0, m, &cSlice_0dnQNxrx_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_tp36l5d9, 0, m, &cSlice_tp36l5d9_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cVar_m8Ix3fHp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_OBJl1JQ9, 1, m, &cIf_OBJl1JQ9_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_NhP4EV7m_sendMessage);
}

void Heavy_SoundScraper::cMsg_j8g9TS4z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_m8Ix3fHp, 1, m, &cVar_m8Ix3fHp_sendMessage);
}

void Heavy_SoundScraper::cSlice_0dnQNxrx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_wxX3AjuN_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_te413RcP_sendMessage);
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
      cIf_onMessage(_c, &Context(_c)->cIf_3iNR7v2q, 0, m, &cIf_3iNR7v2q_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cCast_lSQrAVlP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_j8g9TS4z_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSlice_JsNDXk3i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_DTT88hSh_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_NyfBHUVc_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_lSQrAVlP_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_qjwdR5zu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_WhViqqNR_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cCast_te413RcP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_4Sx7CBu4, 0, m, &cIf_4Sx7CBu4_sendMessage);
}

void Heavy_SoundScraper::cIf_3iNR7v2q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Kd8cOL0a_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_6pUjozXE_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cCast_wxX3AjuN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_NEQ, 0.0f, 0, m, &cBinop_6rOONnze_sendMessage);
}

void Heavy_SoundScraper::cIf_4Sx7CBu4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
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

void Heavy_SoundScraper::cBinop_if5HjkQK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MOD_BIPOLAR, 4.0f, 0, m, &cBinop_YdePOomD_sendMessage);
}

void Heavy_SoundScraper::cPack_lA7P06zw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_JDlFSiEE_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_0DhjWYMR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_tJX4MQRi, 0, m, &cVar_tJX4MQRi_sendMessage);
}

void Heavy_SoundScraper::cBinop_1FOJ7tkc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_p9Q784Je_sendMessage);
}

void Heavy_SoundScraper::cSend_1hiJY9Wh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_UdPOlQ82_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_D4crHq4S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_jwQ1Cmvw, HV_BINOP_ADD, 0, m, &cBinop_jwQ1Cmvw_sendMessage);
}

void Heavy_SoundScraper::cSend_FILHcXut_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_EZSbojeT_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_MoU2NjSk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_D4crHq4S, HV_BINOP_SUBTRACT, 0, m, &cBinop_D4crHq4S_sendMessage);
}

void Heavy_SoundScraper::cVar_IecrjCGB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cBinop_U8Ih02Gg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_jwQ1Cmvw, HV_BINOP_ADD, 1, m, &cBinop_jwQ1Cmvw_sendMessage);
}

void Heavy_SoundScraper::cVar_sj8eJAp4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_tnKTLXoz_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ANR1epit_sendMessage);
}

void Heavy_SoundScraper::cBinop_3cMEi2Kg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_LOG2, m, &cUnop_GDrZLmfU_sendMessage);
}

void Heavy_SoundScraper::cIf_9sOuS4Oz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_Hc4sMo5r_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 440.0f, 0, m, &cBinop_3cMEi2Kg_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cCast_ANR1epit_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_9sOuS4Oz, 0, m, &cIf_9sOuS4Oz_sendMessage);
}

void Heavy_SoundScraper::cBinop_BuVjOa4L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_9sOuS4Oz, 1, m, &cIf_9sOuS4Oz_sendMessage);
}

void Heavy_SoundScraper::cUnop_GDrZLmfU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 12.0f, 0, m, &cBinop_mKP0Rp6l_sendMessage);
}

void Heavy_SoundScraper::cMsg_Hc4sMo5r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, -1500.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_IecrjCGB, 0, m, &cVar_IecrjCGB_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_D4crHq4S, HV_BINOP_SUBTRACT, 1, m, &cBinop_D4crHq4S_sendMessage);
}

void Heavy_SoundScraper::cBinop_JYstxLBV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_IecrjCGB, 0, m, &cVar_IecrjCGB_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_D4crHq4S, HV_BINOP_SUBTRACT, 1, m, &cBinop_D4crHq4S_sendMessage);
}

void Heavy_SoundScraper::cBinop_mKP0Rp6l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 69.0f, 0, m, &cBinop_JYstxLBV_sendMessage);
}

void Heavy_SoundScraper::cCast_tnKTLXoz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_BuVjOa4L_sendMessage);
}

void Heavy_SoundScraper::cBinop_jwQ1Cmvw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Une0GPFu, 0, m, &cVar_Une0GPFu_sendMessage);
}

void Heavy_SoundScraper::cVar_Une0GPFu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_FILHcXut_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_cbRKxpD7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sSample_onMessage(_c, &Context(_c)->sSample_ASCMEqPZ, 1, m);
}

void Heavy_SoundScraper::cDelay_QY0UbdAb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_QY0UbdAb, m);
  sSample_onMessage(_c, &Context(_c)->sSample_ASCMEqPZ, 1, m);
}

void Heavy_SoundScraper::cCast_c1Pj56ph_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_QY0UbdAb, 0, m, &cDelay_QY0UbdAb_sendMessage);
}

void Heavy_SoundScraper::cMsg_jA6TpJgL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
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
      cMsg_jA6TpJgL_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_jA6TpJgL_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_QY0UbdAb, 1, m, &cDelay_QY0UbdAb_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_c1Pj56ph_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cMsg_4zE54m2R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cPrint_onMessage(_c, m, "SCRAPER_RUNNING");
  sVarf_onMessage(_c, &Context(_c)->sVarf_GVIy0hBU, m);
}

void Heavy_SoundScraper::cMsg_C0zxCxUj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_TmVT7cH2, 0, m, &cDelay_TmVT7cH2_sendMessage);
}

void Heavy_SoundScraper::cDelay_TmVT7cH2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_TmVT7cH2, m);
  sSample_onMessage(_c, &Context(_c)->sSample_ASCMEqPZ, 1, m);
}

void Heavy_SoundScraper::cCast_aOEeM4kS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
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
      cMsg_C0zxCxUj_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_C0zxCxUj_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_TmVT7cH2, 1, m, &cDelay_TmVT7cH2_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_aOEeM4kS_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_7S9RSbvK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_ggccvMw2_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_0taoIiC2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_viMpYEkR_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_2VNMDn0i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_SJ6Uh0vb_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cRandom_7H9D1jAN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 100.0f, 0, m, &cBinop_ruOZJcg1_sendMessage);
}

void Heavy_SoundScraper::cUnop_I4cTZBTF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_VezPVhKA_sendMessage);
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
      cSlice_onMessage(_c, &Context(_c)->cSlice_rljPhqci, 0, m, &cSlice_rljPhqci_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_7H9D1jAN, 0, m, &cRandom_7H9D1jAN_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cSlice_rljPhqci_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_7H9D1jAN, 1, m, &cRandom_7H9D1jAN_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cBinop_ruOZJcg1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_I4cTZBTF_sendMessage);
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
      cSlice_onMessage(_c, &Context(_c)->cSlice_OyaBRWpn, 0, m, &cSlice_OyaBRWpn_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_ZZqo5AYi, 0, m, &cRandom_ZZqo5AYi_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cSlice_OyaBRWpn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_ZZqo5AYi, 1, m, &cRandom_ZZqo5AYi_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cRandom_ZZqo5AYi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 40.0f, 0, m, &cBinop_oUYHEdeb_sendMessage);
}

void Heavy_SoundScraper::cUnop_d79fOUSQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 10.0f, 0, m, &cBinop_TyFfADbn_sendMessage);
}

void Heavy_SoundScraper::cBinop_oUYHEdeb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_d79fOUSQ_sendMessage);
}

void Heavy_SoundScraper::cCast_Fa7CGMtR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_pbBsjPQm_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_HHH0pgpv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_5U7ahLbS_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cSend_K0ba2nC0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cCast_MoUbWGXF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_dRkzStc1_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_TyFfADbn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_K0ba2nC0_sendMessage(_c, 0, m);
  cPack_onMessage(_c, &Context(_c)->cPack_WlmhFUbW, 0, m, &cPack_WlmhFUbW_sendMessage);
}

void Heavy_SoundScraper::cBinop_VezPVhKA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_cdOF4MiC_sendMessage(_c, 0, m);
  cPack_onMessage(_c, &Context(_c)->cPack_WlmhFUbW, 2, m, &cPack_WlmhFUbW_sendMessage);
}

void Heavy_SoundScraper::cPack_WlmhFUbW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPrint_onMessage(_c, m, "SCRAPER_RESET");
}

void Heavy_SoundScraper::cBinop_XeyDd2ru_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_0taoIiC2_sendMessage(_c, 0, m);
  cPack_onMessage(_c, &Context(_c)->cPack_WlmhFUbW, 1, m, &cPack_WlmhFUbW_sendMessage);
}

void Heavy_SoundScraper::cSend_cdOF4MiC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_MDy21nR2_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_dRkzStc1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSend_2VNMDn0i_sendMessage(_c, 0, m);
  cPack_onMessage(_c, &Context(_c)->cPack_WlmhFUbW, 3, m, &cPack_WlmhFUbW_sendMessage);
}

void Heavy_SoundScraper::cBinop_3uHv8BM0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_QlxecXfc_sendMessage);
}

void Heavy_SoundScraper::cSlice_J7tfB487_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_Vt8jAfTz, 1, m, &cRandom_Vt8jAfTz_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cUnop_QlxecXfc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 25.0f, 0, m, &cBinop_XeyDd2ru_sendMessage);
}

void Heavy_SoundScraper::cRandom_Vt8jAfTz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 30.0f, 0, m, &cBinop_3uHv8BM0_sendMessage);
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
      cSlice_onMessage(_c, &Context(_c)->cSlice_J7tfB487, 0, m, &cSlice_J7tfB487_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_Vt8jAfTz, 0, m, &cRandom_Vt8jAfTz_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_nB8zyn4R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_kuDYbjOo_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_LlRTWEcn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_L2jcM6y8, 1, m, &cVar_L2jcM6y8_sendMessage);
}

void Heavy_SoundScraper::cVar_L2jcM6y8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_LlRTWEcn_sendMessage);
}

void Heavy_SoundScraper::cMsg_F2XDIkNh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPrint_onMessage(_c, m, "SCRAPER_RUNNING");
  sVarf_onMessage(_c, &Context(_c)->sVarf_GVIy0hBU, m);
}

void Heavy_SoundScraper::cSend_GrNtTg0B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_KdXsCelA_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_Ieib1wKz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cExpr_onMessage(_c, &Context(_c)->cExpr_7E6tHPVK, 0, m, &cExpr_7E6tHPVK_sendMessage);
}

void Heavy_SoundScraper::cMsg_G8IHhmK8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSend_Yrtk5C9y_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_MQXUDQT9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_KdXsCelA_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_MSo8HhWm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cSend_UvK9rPQ1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_MDy21nR2_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_Yrtk5C9y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_EZSbojeT_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_eKc86o7b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 5.0f);
  cSend_UvK9rPQ1_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_sn0r72Gx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 44100.0f);
  cSend_MSo8HhWm_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_zG38yWnf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSend_MQXUDQT9_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_Ji6gv0SC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_hhNFlC8R_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_K68lKhS2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_SJ6Uh0vb_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSlice_0vJoTVKz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_7S9RSbvK_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_7S9RSbvK_sendMessage);
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
      cSlice_onMessage(_c, &Context(_c)->cSlice_0vJoTVKz, 0, m, &cSlice_0vJoTVKz_sendMessage);
      break;
    }
    case 0x0: { // "0.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_GASkMN1k, 0, m, &cSlice_GASkMN1k_sendMessage);
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
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_dVJuwuOA_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_bNvj1ULc_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_dVJuwuOA_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_bNvj1ULc_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSend_NDinRmyc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_o8LH6hUa_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::sSample_ASCMEqPZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_hSX1EpJ3, 0, m, &cVar_hSX1EpJ3_sendMessage);
}

void Heavy_SoundScraper::cSystem_7GK3b8EH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_lEjFGiEC_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_f0QedGcd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_7GK3b8EH_sendMessage);
}

void Heavy_SoundScraper::cBinop_jHxaDnBq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_k9PO1ian_sendMessage);
}

void Heavy_SoundScraper::cMsg_lEjFGiEC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_zxpxkyZX_sendMessage);
}

void Heavy_SoundScraper::cBinop_zxpxkyZX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_jHxaDnBq, HV_BINOP_MULTIPLY, 1, m, &cBinop_jHxaDnBq_sendMessage);
}

void Heavy_SoundScraper::cBinop_W3l05oTe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_w30cdhzP_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_cVKoBcMM, m);
}

void Heavy_SoundScraper::cBinop_k9PO1ian_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_W3l05oTe_sendMessage);
}

void Heavy_SoundScraper::cVar_IWPRAMQc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_jHxaDnBq, HV_BINOP_MULTIPLY, 0, m, &cBinop_jHxaDnBq_sendMessage);
}

void Heavy_SoundScraper::cBinop_w30cdhzP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_LJNrNrgd, m);
}

void Heavy_SoundScraper::cSend_WOU6a94W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_o8LH6hUa_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cPack_ay7lFJ2w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_VgJS7kLS, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_bNvj1ULc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_eh3c83PG_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_2Ao0APRz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_1i3HKFFn, m);
}

void Heavy_SoundScraper::cSlice_46AxoJJ1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
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

void Heavy_SoundScraper::cSystem_A9zKGw3W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 2.0f, 0, m, &cBinop_2Ao0APRz_sendMessage);
}

void Heavy_SoundScraper::cVar_BVhRq1tD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_JeO8wv4O_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_JeO8wv4O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_A9zKGw3W_sendMessage);
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
      cSlice_onMessage(_c, &Context(_c)->cSlice_46AxoJJ1, 0, m, &cSlice_46AxoJJ1_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cMsg_3Y39AZ0e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSwitchcase_fEhXSlcL_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cSend_53DZ8J6A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_7EK9zeiH_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_8cIgAeXS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_PuLPoyHN_sendMessage);
}

void Heavy_SoundScraper::cSlice_AwbkDAjm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
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

void Heavy_SoundScraper::cVar_JiQ6bRd5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_8cIgAeXS_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSystem_PuLPoyHN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 2.0f, 0, m, &cBinop_aXMssrko_sendMessage);
}

void Heavy_SoundScraper::cBinop_aXMssrko_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_pJMale4s, m);
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
      cSlice_onMessage(_c, &Context(_c)->cSlice_AwbkDAjm, 0, m, &cSlice_AwbkDAjm_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cExpr_7E6tHPVK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_PEcK7y0d, HV_BINOP_DIVIDE, 0, m, &cBinop_PEcK7y0d_sendMessage);
}

float Heavy_SoundScraper::cExpr_7E6tHPVK_evaluate(const float* args) {
  	return hv_pow_f(2 , ((float)(args[0]))/1200);
}

void Heavy_SoundScraper::cMsg_8oPoycfA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSwitchcase_tGXsCiA9_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cCast_BkkUCsw0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_PEcK7y0d, HV_BINOP_DIVIDE, 1, m, &cBinop_PEcK7y0d_sendMessage);
}

void Heavy_SoundScraper::cCast_FQduMCqN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_PEcK7y0d, HV_BINOP_DIVIDE, 0, m, &cBinop_PEcK7y0d_sendMessage);
}

void Heavy_SoundScraper::cSend_MREAUVJW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_Wd4NhQ0S_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_PEcK7y0d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_0ui6xbPb, 0, m, &cVar_0ui6xbPb_sendMessage);
}

void Heavy_SoundScraper::cVar_zIqdTANI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cExpr_onMessage(_c, &Context(_c)->cExpr_7E6tHPVK, 0, m, &cExpr_7E6tHPVK_sendMessage);
}

void Heavy_SoundScraper::cBinop_RPjk0Dgz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_uVRsK4De_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_YOsnolnC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_aL4CHNQ9_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_aL4CHNQ9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_RoL1C3Kj_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::hTable_adIMRuo0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cVar_tJX4MQRi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 44.1f, 0, m, &cBinop_yHTd244B_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_RPjk0Dgz_sendMessage);
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

void Heavy_SoundScraper::cSend_WUNf45qr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_i89foIcW_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_X2ickPLt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSend_WUNf45qr_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_gpSWUIja_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 100.0f);
  cSend_xu9bgdvu_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_xu9bgdvu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_iBd6GA39_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_zk6BIYaA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_Do9nya8H_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_0oEWHwnR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 44.1f, 0, m, &cBinop_YOsnolnC_sendMessage);
}

void Heavy_SoundScraper::cSend_uVRsK4De_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_JUsaRojU_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_0ui6xbPb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_iMoLKRsm, 0, m);
}

void Heavy_SoundScraper::cVar_IzpMzzdU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_0oEWHwnR, 0, m, &cVar_0oEWHwnR_sendMessage);
}

void Heavy_SoundScraper::cBinop_yHTd244B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_MREAUVJW_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_dVJuwuOA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_WOU6a94W_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_eh3c83PG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_jMhwovL4_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_ggccvMw2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_t2ImK8S7_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_hSX1EpJ3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPrint_onMessage(_c, m, "SCRAPER_SIG");
}

void Heavy_SoundScraper::cSystem_8QjFuyS6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_xlcIy2it, HV_BINOP_DIVIDE, 1, m, &cBinop_xlcIy2it_sendMessage);
}

void Heavy_SoundScraper::cMsg_ezCYhhbS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_8QjFuyS6_sendMessage);
}

void Heavy_SoundScraper::cBinop_5B0KaNW3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_xlcIy2it, HV_BINOP_DIVIDE, 0, m, &cBinop_xlcIy2it_sendMessage);
}

void Heavy_SoundScraper::cBinop_68r0KC5q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_riXES2ua, m);
}

void Heavy_SoundScraper::cBinop_8XV4gloF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_z9CKtwAU_sendMessage);
}

void Heavy_SoundScraper::cVar_YLhzpjc3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_qJ7Q5vPw_sendMessage);
}

void Heavy_SoundScraper::cBinop_7ykyqEz3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_RuEG0lVD_sendMessage);
}

void Heavy_SoundScraper::cBinop_RuEG0lVD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_8XV4gloF_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_68r0KC5q_sendMessage);
}

void Heavy_SoundScraper::cMsg_kuEEWMVX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_slvKFEkf_sendMessage);
}

void Heavy_SoundScraper::cBinop_qJ7Q5vPw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_5B0KaNW3_sendMessage);
}

void Heavy_SoundScraper::cBinop_slvKFEkf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_7ykyqEz3_sendMessage);
}

void Heavy_SoundScraper::cBinop_xlcIy2it_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_kuEEWMVX_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_z9CKtwAU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_CwOYbibd, m);
}

void Heavy_SoundScraper::cSend_nYYVQKjy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_vcMb0WOz_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_p9Q784Je_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_ay7lFJ2w, 0, m, &cPack_ay7lFJ2w_sendMessage);
}

void Heavy_SoundScraper::cSend_ywl0oAeO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_RUVe3pDV_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSlice_UKaWzyTm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSend_1hiJY9Wh_sendMessage(_c, 0, m);
      cPrint_onMessage(_c, m, "SCRAPER_TAB");
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_tsVaYaSp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSend_ywl0oAeO_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cReceive_mYumRgba_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_rM3gjqCZ_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_qkC9uy0h_sendMessage);
}

void Heavy_SoundScraper::cReceive_me6GXtaS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_lCwYyBZF, 1, m, &cVar_lCwYyBZF_sendMessage);
}

void Heavy_SoundScraper::cReceive_mpWxdZ0C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_gmMUMGJa, 0, m, &cVar_gmMUMGJa_sendMessage);
}

void Heavy_SoundScraper::cReceive_nsXxDOTw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_NDinRmyc_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cReceive_o8LH6hUa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_MoUbWGXF_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Fa7CGMtR_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_nB8zyn4R_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_HHH0pgpv_sendMessage);
}

void Heavy_SoundScraper::cReceive_pJyJ8beI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_OhR0L8UX, 0, m, NULL);
  cPrint_onMessage(_c, m, "TABLEPLAYER_CUTOFF");
}

void Heavy_SoundScraper::cReceive_pwIe5pyd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_48LijKnP, 1, m, &cVar_48LijKnP_sendMessage);
}

void Heavy_SoundScraper::cReceive_q6o7mfie_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_dFGGLTVi, HV_BINOP_DIVIDE, 1, m, &cBinop_dFGGLTVi_sendMessage);
}

void Heavy_SoundScraper::cReceive_qRnOVDWs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPrint_onMessage(_c, m, "SOUND_CHOICE");
  cSwitchcase_OlWp75wO_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cReceive_r510TR8k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_VYGTLUEb, 0, m, NULL);
  cPrint_onMessage(_c, m, "TABLEPLAYER_PHASE");
  cSlice_onMessage(_c, &Context(_c)->cSlice_nl2XhuQl, 0, m, &cSlice_nl2XhuQl_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_uCFw3d3O, 0, m, &cSlice_uCFw3d3O_sendMessage);
}

void Heavy_SoundScraper::cReceive_rRS6P44Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_K68lKhS2_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cReceive_sJLVG06s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_AxRzuf7e_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cReceive_t2ImK8S7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_4zE54m2R_sendMessage(_c, 0, m);
  cSwitchcase_yJOjuJ77_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cReceive_tx2TCvlM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_bg5dMEaN_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_BWYDpnlV_sendMessage);
}

void Heavy_SoundScraper::cReceive_ue79bHQD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_KRQa77bb, 0, m, NULL);
  cPrint_onMessage(_c, m, "TABLEPLAYER_CUTOFF");
}

void Heavy_SoundScraper::cBinop_4MjNL4r0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.99f, 0, m, &cBinop_be6oqhtN_sendMessage);
}

void Heavy_SoundScraper::cCast_rH3tCYIv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cVar_KSPhAnvf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_WNx24O3v, 1, m, &cPack_WNx24O3v_sendMessage);
}

void Heavy_SoundScraper::cCast_8OkOraZK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_WNx24O3v, 0, m, &cPack_WNx24O3v_sendMessage);
}

void Heavy_SoundScraper::cCast_Ccent5HC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_KSPhAnvf, 0, m, &cVar_KSPhAnvf_sendMessage);
}

void Heavy_SoundScraper::cPack_WNx24O3v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ipJqZGMy_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_cOg55uJD_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_R1uawaao, 0, m, &cSlice_R1uawaao_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_MqY07X5b, 0, m, &cSlice_MqY07X5b_sendMessage);
  cPrint_onMessage(_c, m, "TABLEPLAYER_COMMAND");
}

void Heavy_SoundScraper::cSend_AxRzuf7e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_FhL5QWRt_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_OTsyF41f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 25.0f);
  cSend_PSPF92vu_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_OUxS27Up_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_48LijKnP, 0, m, &cVar_48LijKnP_sendMessage);
}

void Heavy_SoundScraper::cSend_PSPF92vu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cSend_RlHAjnoq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_FhL5QWRt_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_UJKdA943_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_WkLBgba0_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cDelay_TN0k3zbQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_TN0k3zbQ, m);
  cVar_onMessage(_c, &Context(_c)->cVar_LMd39CXq, 0, m, &cVar_LMd39CXq_sendMessage);
}

void Heavy_SoundScraper::cMsg_gDbLMSEB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
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
      cMsg_gDbLMSEB_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_gDbLMSEB_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_TN0k3zbQ, 1, m, &cDelay_TN0k3zbQ_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_rgW0CU60_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_rgW0CU60_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_TN0k3zbQ, 0, m, &cDelay_TN0k3zbQ_sendMessage);
}

void Heavy_SoundScraper::cMsg_WkLBgba0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 25.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_2P8mbY2y, 0, m, NULL);
}

void Heavy_SoundScraper::cVar_48LijKnP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_UJKdA943_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_kEJJAuR9_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_uwVSXi1B_sendMessage);
}

void Heavy_SoundScraper::cVar_LMd39CXq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_m0jn3s0L_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_kEJJAuR9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_LMd39CXq, 1, m, &cVar_LMd39CXq_sendMessage);
}

void Heavy_SoundScraper::cMsg_m0jn3s0L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 0);
  sLine_onMessage(_c, &Context(_c)->sLine_2P8mbY2y, 0, m, NULL);
}

void Heavy_SoundScraper::cMsg_pwFS074N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 4000.0f);
  cSend_vRWNT9iK_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_sqsw2EZT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSend_RlHAjnoq_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_uwVSXi1B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_klUTrmZ8_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cSend_vRWNT9iK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_pwIe5pyd_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cRandom_B3v7faAs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_pZ4BZ6UO_sendMessage);
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
      cSlice_onMessage(_c, &Context(_c)->cSlice_giDhiHVP, 0, m, &cSlice_giDhiHVP_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_B3v7faAs, 0, m, &cRandom_B3v7faAs_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cSlice_giDhiHVP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_B3v7faAs, 1, m, &cRandom_B3v7faAs_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cUnop_hYE2jt41_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_K5LR0nmw_sendMessage);
}

void Heavy_SoundScraper::cBinop_pZ4BZ6UO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_hYE2jt41_sendMessage);
}

void Heavy_SoundScraper::cSend_Grfu0Ngg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_sJLVG06s_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSlice_YFizWWF7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_cnfmS3IJ_sendMessage);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_3yu34DfP_sendMessage);
      cPrint_onMessage(_c, m, "PERCSAMPLER_NOTE");
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_wFZuWykC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 127.0f, 0, m, &cBinop_vxyreL0j_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cRandom_1earnbJr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 15.0f, 0, m, &cBinop_N8pmwXwC_sendMessage);
}

void Heavy_SoundScraper::cBinop_N8pmwXwC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_PpQkn2Vn_sendMessage);
}

void Heavy_SoundScraper::cSlice_NqAlEh4g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_1earnbJr, 1, m, &cRandom_1earnbJr_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cUnop_PpQkn2Vn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_4MjNL4r0_sendMessage);
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
      cSlice_onMessage(_c, &Context(_c)->cSlice_NqAlEh4g, 0, m, &cSlice_NqAlEh4g_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_1earnbJr, 0, m, &cRandom_1earnbJr_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cBinop_K5LR0nmw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.4f, 0, m, &cBinop_hRkciHrs_sendMessage);
}

void Heavy_SoundScraper::cBinop_9QL17Sxq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_KLZkdgi7, 0, m, &cVar_KLZkdgi7_sendMessage);
}

void Heavy_SoundScraper::cBinop_DR14GAwe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_389VEx53, 0, m, &cVar_389VEx53_sendMessage);
}

void Heavy_SoundScraper::cBinop_6F176PMn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_A6KZg1dy, m);
}

void Heavy_SoundScraper::cVar_LJONgNkw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_v9Gjd9o4_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSlice_YB4Ilcxk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
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
      cSlice_onMessage(_c, &Context(_c)->cSlice_YB4Ilcxk, 0, m, &cSlice_YB4Ilcxk_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_SoundScraper::cSystem_lHovu4AG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 2.0f, 0, m, &cBinop_6F176PMn_sendMessage);
}

void Heavy_SoundScraper::cMsg_v9Gjd9o4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_lHovu4AG_sendMessage);
}

void Heavy_SoundScraper::cMsg_KtNQfHg4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSwitchcase_Zjn1HlMi_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cSlice_9aEdFzKI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 44100.0f, 0, m, &cBinop_9QL17Sxq_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_Sai3hU5Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_DR14GAwe_sendMessage);
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
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_q1EmrL66_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_jipezGi1_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_IIsOyJhJ_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_xo4XpkPP, 0, m, &cVar_xo4XpkPP_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_R1uawaao_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_KtNQfHg4_sendMessage(_c, 0, m);
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

void Heavy_SoundScraper::cCast_0LaYx6XK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_7ILSpeEZ, 0, m, &cVar_7ILSpeEZ_sendMessage);
}

void Heavy_SoundScraper::cVar_mncmhsWu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 100000.0f, 0, m, &cBinop_ORab0XlS_sendMessage);
}

void Heavy_SoundScraper::cMsg_3z2QaTYr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 44100.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 100.0f, 0, m, &cBinop_KxDKiHt2_sendMessage);
}

void Heavy_SoundScraper::cCast_i5X1itQb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
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
      cMsg_zldvKZTW_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_zldvKZTW_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_sm6vop1m, 1, m, &cDelay_sm6vop1m_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_i5X1itQb_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cDelay_sm6vop1m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_sm6vop1m, m);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_NEMF1j2L_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_0LaYx6XK_sendMessage);
}

void Heavy_SoundScraper::cMsg_zldvKZTW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_sm6vop1m, 0, m, &cDelay_sm6vop1m_sendMessage);
}

void Heavy_SoundScraper::cVar_xo4XpkPP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cPack_GBRJwljZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_GVhrsp57_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_GVhrsp57_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_ue79bHQD_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_IIsOyJhJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_q9qq7oTQ_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_KpnaiOas_sendMessage);
}

void Heavy_SoundScraper::cBinop_IbtYV3Po_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_mncmhsWu, 0, m, &cVar_mncmhsWu_sendMessage);
}

void Heavy_SoundScraper::cCast_KpnaiOas_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_mvQgS1rF_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_KxDKiHt2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_hsU2ZVWs, 1, m, &cPack_hsU2ZVWs_sendMessage);
}

void Heavy_SoundScraper::cSend_LVyDya7h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_dzV4DPcb_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_NEMF1j2L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_OC4NS0x6, 0, m, &cVar_OC4NS0x6_sendMessage);
}

void Heavy_SoundScraper::cBinop_ORab0XlS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_hsU2ZVWs, 0, m, &cPack_hsU2ZVWs_sendMessage);
}

void Heavy_SoundScraper::cVar_5eZ1CZic_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_IbtYV3Po, HV_BINOP_DIVIDE, 1, m, &cBinop_IbtYV3Po_sendMessage);
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
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ffLmpw6C_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_yBohUrD3_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_o9cWFQb6_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_uRwM9GNm_sendMessage);
      break;
    }
  }
}

void Heavy_SoundScraper::cCast_ffLmpw6C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_5eZ1CZic, 0, m, &cVar_5eZ1CZic_sendMessage);
}

void Heavy_SoundScraper::cVar_dQ6Js9mW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_IbtYV3Po, HV_BINOP_DIVIDE, 0, m, &cBinop_IbtYV3Po_sendMessage);
}

void Heavy_SoundScraper::cCast_o9cWFQb6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_5eZ1CZic, 0, m, &cVar_5eZ1CZic_sendMessage);
}

void Heavy_SoundScraper::cCast_uRwM9GNm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_dQ6Js9mW, 0, m, &cVar_dQ6Js9mW_sendMessage);
}

void Heavy_SoundScraper::cCast_yBohUrD3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_dQ6Js9mW, 0, m, &cVar_dQ6Js9mW_sendMessage);
}

void Heavy_SoundScraper::cPack_hsU2ZVWs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_sY69BtZq_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cSend_ivzfRKZ7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_ue79bHQD_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_jipezGi1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_OC4NS0x6, 1, m, &cVar_OC4NS0x6_sendMessage);
}

void Heavy_SoundScraper::cVar_7ILSpeEZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_GBRJwljZ, 0, m, &cPack_GBRJwljZ_sendMessage);
}

void Heavy_SoundScraper::cPack_mGtVf59g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_ivzfRKZ7_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cCast_q1EmrL66_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_SoundScraper::cCast_q9qq7oTQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_mGtVf59g, 0, m, &cPack_mGtVf59g_sendMessage);
}

void Heavy_SoundScraper::cMsg_sY69BtZq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 0.0f);
  cSend_LVyDya7h_sendMessage(_c, 0, m);
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 1);
  msg_setElementToFrom(m, 1, n, 0);
  cSend_LVyDya7h_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cVar_OC4NS0x6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_U6Cak3ak_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cSend_NG1rA9r2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_RT1zMGKA_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cMsg_1fD3OqQY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_no5oSF1E, HV_BINOP_POW, 0, m, &cBinop_no5oSF1E_sendMessage);
}

void Heavy_SoundScraper::cBinop_3yu34DfP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_9BfSbfVA_sendMessage);
}

void Heavy_SoundScraper::cBinop_9BfSbfVA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_no5oSF1E, HV_BINOP_POW, 1, m, &cBinop_no5oSF1E_sendMessage);
  cMsg_1fD3OqQY_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cBinop_Pje2F57r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_aMSLNb5u, HV_BINOP_DIVIDE, 0, m, &cBinop_aMSLNb5u_sendMessage);
}

void Heavy_SoundScraper::cBinop_no5oSF1E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_Pje2F57r_sendMessage);
}

void Heavy_SoundScraper::cBinop_WA1JyZAo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Ccent5HC_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_8OkOraZK_sendMessage);
}

void Heavy_SoundScraper::cBinop_aMSLNb5u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_WA1JyZAo, HV_BINOP_MULTIPLY, 0, m, &cBinop_WA1JyZAo_sendMessage);
}

void Heavy_SoundScraper::cBinop_be6oqhtN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_WA1JyZAo, HV_BINOP_MULTIPLY, 1, m, &cBinop_WA1JyZAo_sendMessage);
}

void Heavy_SoundScraper::cCast_cOg55uJD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_OUxS27Up_sendMessage);
}

void Heavy_SoundScraper::cCast_cnfmS3IJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_ZoXcx7Gq_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_SoundScraper::cSlice_6C9Y56FE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSend_nWqnUC27_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_SoundScraper::cSlice_Nj6DFvLz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
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

void Heavy_SoundScraper::cBinop_hRkciHrs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_l9G5C1pI_sendMessage);
}

void Heavy_SoundScraper::cCast_ipJqZGMy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_bZMkvl4z_onMessage(_c, NULL, 0, m, NULL);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_rH3tCYIv_sendMessage);
}

void Heavy_SoundScraper::cSend_nWqnUC27_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_VzckN8pw_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cUnop_lPZzq55l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_WoUl5Yx9, 0, m, &cPack_WoUl5Yx9_sendMessage);
}

void Heavy_SoundScraper::cUnop_YtDZdiwl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_HHJNKIVQ, 0, m, &cPack_HHJNKIVQ_sendMessage);
}

void Heavy_SoundScraper::cMsg_BdqdGDli_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.5f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_l9G5C1pI_sendMessage);
}

void Heavy_SoundScraper::cPack_HHJNKIVQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_N6lrmGJT, 0, m, NULL);
}

void Heavy_SoundScraper::cPack_WoUl5Yx9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_b2iW3hdu, 0, m, NULL);
}

void Heavy_SoundScraper::cBinop_l9G5C1pI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_lPZzq55l_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_SIN, m, &cUnop_YtDZdiwl_sendMessage);
}

void Heavy_SoundScraper::cBinop_vxyreL0j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_Grfu0Ngg_sendMessage(_c, 0, m);
}

void Heavy_SoundScraper::cReceive_vcMb0WOz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_D4crHq4S, HV_BINOP_SUBTRACT, 0, m, &cBinop_D4crHq4S_sendMessage);
}

void Heavy_SoundScraper::cReceive_viMpYEkR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_0oEWHwnR, 0, m, &cVar_0oEWHwnR_sendMessage);
}

void Heavy_SoundScraper::cReceive_z6iEtg1P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_EIuT2fqi, m);
}

void Heavy_SoundScraper::cReceive_zTsXD6YR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_16bc7eRS, 1, m, &cVar_16bc7eRS_sendMessage);
}

void Heavy_SoundScraper::cReceive_zfd68FNh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_MZCVjXdJ_sendMessage(_c, 0, m);
  cMsg_RC1wuMh1_sendMessage(_c, 0, m);
  cMsg_LdqrfaOU_sendMessage(_c, 0, m);
  cMsg_TsR2GQOE_sendMessage(_c, 0, m);
  cMsg_MeAy33Eq_sendMessage(_c, 0, m);
  cMsg_ZzVCQfLU_sendMessage(_c, 0, m);
  cMsg_RpxN8fwg_sendMessage(_c, 0, m);
  cMsg_Q2XDi7go_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_8O9LuJpY, 0, m, &cVar_8O9LuJpY_sendMessage);
  cMsg_MKYi30Ru_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_LP6LfgeT, 0, m, &cVar_LP6LfgeT_sendMessage);
  cMsg_EW9QKgcB_sendMessage(_c, 0, m);
  cMsg_coOqk6Hv_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_UgLkOSfA, 0, m, &cVar_UgLkOSfA_sendMessage);
  cMsg_A2qdipWP_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_uhKWI9pg, 0, m, &cVar_uhKWI9pg_sendMessage);
  cMsg_ipJvfpuV_sendMessage(_c, 0, m);
  cMsg_xkjga8iw_sendMessage(_c, 0, m);
  cMsg_tQkRkM77_sendMessage(_c, 0, m);
  cMsg_SY9tKhsl_sendMessage(_c, 0, m);
  cMsg_WXA40OOI_sendMessage(_c, 0, m);
  cMsg_kg5dYE5P_sendMessage(_c, 0, m);
  cMsg_DGYEBDpK_sendMessage(_c, 0, m);
  cMsg_8K9NIuUt_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_UwYm2B3w, 0, m, &cVar_UwYm2B3w_sendMessage);
  cMsg_GWlpQv24_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_h9nbQXbI, 0, m, &cVar_h9nbQXbI_sendMessage);
  cMsg_5hyFNydj_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_6gGIbERR, 0, m, &cVar_6gGIbERR_sendMessage);
  cMsg_mW4j32GD_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_kTQEnTOC, 0, m, &cVar_kTQEnTOC_sendMessage);
  cMsg_6SkPfNfE_sendMessage(_c, 0, m);
  cMsg_SnZmM2PV_sendMessage(_c, 0, m);
  cMsg_KEBsS6Pc_sendMessage(_c, 0, m);
  cMsg_NfdD8nG7_sendMessage(_c, 0, m);
  cMsg_80okK5TI_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_7zYxjbNP, 0, m, &cVar_7zYxjbNP_sendMessage);
  cMsg_M6uo1BvO_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_FsHhjE6c, 0, m, &cVar_FsHhjE6c_sendMessage);
  cMsg_5JsLif86_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_MpIBnkWC, 0, m, &cVar_MpIBnkWC_sendMessage);
  cMsg_IDFC5Zjl_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_YgoH762r, 0, m, &cVar_YgoH762r_sendMessage);
  cMsg_oahx4dw0_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_8thkYCby, 0, m, &cVar_8thkYCby_sendMessage);
  cMsg_ESzkSyWI_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_kFmB3ZJL, 0, m, &cVar_kFmB3ZJL_sendMessage);
  cMsg_ae7kdqUJ_sendMessage(_c, 0, m);
  cMsg_cKRqcgtb_sendMessage(_c, 0, m);
  cMsg_LRZqPo9X_sendMessage(_c, 0, m);
  cMsg_3z2QaTYr_sendMessage(_c, 0, m);
  cMsg_xmwFF0MV_sendMessage(_c, 0, m);
  cMsg_Zi5lNQLi_sendMessage(_c, 0, m);
  cMsg_Sj0NUwr7_sendMessage(_c, 0, m);
  cMsg_xUbeWThw_sendMessage(_c, 0, m);
  cMsg_21cYREHO_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_rEAPspkj, 0, m, &cVar_rEAPspkj_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_wMvdCCPl, 0, m, &cVar_wMvdCCPl_sendMessage);
  cMsg_yqNnWETm_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_AYuVqWOR, 0, m, &cVar_AYuVqWOR_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_ZnO3YYb7, 0, m, &cVar_ZnO3YYb7_sendMessage);
  cMsg_R2lAHbnV_sendMessage(_c, 0, m);
  cMsg_JPi9YWMY_sendMessage(_c, 0, m);
  cMsg_spUPSbLx_sendMessage(_c, 0, m);
  cMsg_12fulvDw_sendMessage(_c, 0, m);
  cMsg_0JdY56Zn_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_4vurxjLg, 0, m, &cVar_4vurxjLg_sendMessage);
  cMsg_psdgXSjI_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_w9s8gsro, 0, m, &cVar_w9s8gsro_sendMessage);
  cMsg_mcBW05Sm_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_VMqS8U9a, 0, m, &cVar_VMqS8U9a_sendMessage);
  cMsg_0q9DEeWE_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_TbXZlErM, 0, m, &cVar_TbXZlErM_sendMessage);
  cMsg_899dCYGS_sendMessage(_c, 0, m);
  cMsg_lKx5SvJV_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_btS5VW3w, 0, m, &cVar_btS5VW3w_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_01PnFloa, 0, m, &cVar_01PnFloa_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_Q68rrcEO, 0, m, &cVar_Q68rrcEO_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_ixLZUW9e, 0, m, &cVar_ixLZUW9e_sendMessage);
  cMsg_7JWbtEUh_sendMessage(_c, 0, m);
  cMsg_X2ickPLt_sendMessage(_c, 0, m);
  cMsg_VAZU6Xmk_sendMessage(_c, 0, m);
  cMsg_gpSWUIja_sendMessage(_c, 0, m);
  cMsg_Rlngzr2V_sendMessage(_c, 0, m);
  cMsg_gNspD6OU_sendMessage(_c, 0, m);
  cMsg_CJNK44x7_sendMessage(_c, 0, m);
  cMsg_QV33UwVu_sendMessage(_c, 0, m);
  cMsg_I80szfDg_sendMessage(_c, 0, m);
  cMsg_zbJngBFJ_sendMessage(_c, 0, m);
  cMsg_omqBk88d_sendMessage(_c, 0, m);
  cMsg_3XAlCAba_sendMessage(_c, 0, m);
  cMsg_BdqdGDli_sendMessage(_c, 0, m);
  cMsg_OTsyF41f_sendMessage(_c, 0, m);
  cMsg_pwFS074N_sendMessage(_c, 0, m);
  cMsg_sqsw2EZT_sendMessage(_c, 0, m);
  cMsg_dgppUsZb_sendMessage(_c, 0, m);
  cMsg_caXpuYsq_sendMessage(_c, 0, m);
  cMsg_dsq8jUOc_sendMessage(_c, 0, m);
  cMsg_IYCAhXAn_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_Majfm0GP, 0, m, &cVar_Majfm0GP_sendMessage);
  cMsg_UFkvbtYD_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_8zmf3lwk, 0, m, &cVar_8zmf3lwk_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_aVE88ycb, 0, m, &cVar_aVE88ycb_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_EHW2pJfr, 0, m, &cVar_EHW2pJfr_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_pb1QVppF, 0, m, &cVar_pb1QVppF_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_RWHaRdz0, 0, m, &cVar_RWHaRdz0_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_yNkmr4rV, 0, m, &cVar_yNkmr4rV_sendMessage);
  cMsg_DomcrxPs_sendMessage(_c, 0, m);
  cMsg_9ivztjgt_sendMessage(_c, 0, m);
  cMsg_f0QedGcd_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_IWPRAMQc, 0, m, &cVar_IWPRAMQc_sendMessage);
  cMsg_G8IHhmK8_sendMessage(_c, 0, m);
  cMsg_eKc86o7b_sendMessage(_c, 0, m);
  cMsg_sn0r72Gx_sendMessage(_c, 0, m);
  cMsg_zG38yWnf_sendMessage(_c, 0, m);
  cMsg_ezCYhhbS_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_YLhzpjc3, 0, m, &cVar_YLhzpjc3_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_IBNg1qeo, 0, m, &cVar_IBNg1qeo_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_Zn1ojjrH, 0, m, &cVar_Zn1ojjrH_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_oPZ52NA3, 0, m, &cVar_oPZ52NA3_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_2HkT7EA4, 0, m, &cVar_2HkT7EA4_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_6uEOTKW5, 0, m, &cVar_6uEOTKW5_sendMessage);
  cMsg_QXSo6FKJ_sendMessage(_c, 0, m);
  cMsg_s7XorbYO_sendMessage(_c, 0, m);
  cSend_NDinRmyc_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_sTYvRhZ9, 0, m, &cVar_sTYvRhZ9_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_UyoDPMGJ, 0, m, &cVar_UyoDPMGJ_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_LJONgNkw, 0, m, &cVar_LJONgNkw_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_ZwMUgIzr, 0, m, &cVar_ZwMUgIzr_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_lDaFAIiM, 0, m, &cVar_lDaFAIiM_sendMessage);
  cMsg_KhCtoqD1_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_YObsSk03, 0, m, &cVar_YObsSk03_sendMessage);
  cMsg_SeMT4tjI_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_02AHW0Bq, 0, m, &cVar_02AHW0Bq_sendMessage);
  cMsg_w4V5NSG4_sendMessage(_c, 0, m);
  cMsg_M3QYutbA_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_qN5QtCKP, 0, m, &cVar_qN5QtCKP_sendMessage);
  cMsg_VHvSO52y_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_Ay9w28ta, 0, m, &cTabhead_Ay9w28ta_sendMessage);
  cMsg_ulUdFhXJ_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_RkOG7nu9, 0, m, &cVar_RkOG7nu9_sendMessage);
  cMsg_7gFXNw8h_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_bsldNoGU, 0, m, &cTabhead_bsldNoGU_sendMessage);
  cMsg_UvrPLWhF_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_jWsXkRIT, 0, m, &cVar_jWsXkRIT_sendMessage);
  cMsg_0hirUWhU_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_MD15ck9x, 0, m, &cTabhead_MD15ck9x_sendMessage);
  cMsg_z6duwO18_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_TfY1UwNu, 0, m, &cVar_TfY1UwNu_sendMessage);
  cMsg_arcJteX4_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_po2Uy8VU, 0, m, &cTabhead_po2Uy8VU_sendMessage);
  cMsg_WxKgCjWu_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_qBNaUY0f, 0, m, &cVar_qBNaUY0f_sendMessage);
  cMsg_yXI1BX5X_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_h8J9M5Gk, 0, m, &cTabhead_h8J9M5Gk_sendMessage);
  cMsg_EbgzOxpE_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_Nn2QYeSd, 0, m, &cVar_Nn2QYeSd_sendMessage);
  cMsg_F3k3QbJS_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_GiSLm0Ve, 0, m, &cTabhead_GiSLm0Ve_sendMessage);
  cMsg_fwnrGLb9_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_cQfHPFbx, 0, m, &cVar_cQfHPFbx_sendMessage);
  cMsg_30eRlicE_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_jFneiBZ8, 0, m, &cTabhead_jFneiBZ8_sendMessage);
  cMsg_aAJKAjk9_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_uTpHW20o, 0, m, &cVar_uTpHW20o_sendMessage);
  cMsg_EusnHKYo_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_238LxNEE, 0, m, &cTabhead_238LxNEE_sendMessage);
  cMsg_JqCkyDT1_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_6pBlUwqW, 0, m, &cVar_6pBlUwqW_sendMessage);
  cMsg_uRtsBgt3_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_Dmc8PtT0, 0, m, &cTabhead_Dmc8PtT0_sendMessage);
  cMsg_AVK3Y51G_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_tMoSExKz, 0, m, &cVar_tMoSExKz_sendMessage);
  cMsg_iNSrJ8qJ_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_HKIPOkNn, 0, m, &cTabhead_HKIPOkNn_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_bDdEds4R, 0, m, &cVar_bDdEds4R_sendMessage);
  cMsg_AQ6SM33L_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_OsTtho3f, 0, m, &cVar_OsTtho3f_sendMessage);
  cMsg_64NZTOML_sendMessage(_c, 0, m);
  cMsg_Ooqb3idw_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_FRnRa57A, 0, m, &cVar_FRnRa57A_sendMessage);
  cMsg_KhoufUiL_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_6zhX7sLi, 0, m, &cTabhead_6zhX7sLi_sendMessage);
  cMsg_oW5fYvH2_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_TSmzWwYE, 0, m, &cVar_TSmzWwYE_sendMessage);
  cMsg_m6Ye80po_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_yB2e39Ly, 0, m, &cTabhead_yB2e39Ly_sendMessage);
  cMsg_LPyHGKIm_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_KgUstciN, 0, m, &cVar_KgUstciN_sendMessage);
  cMsg_YzDUtlvP_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_YXrQA3J2, 0, m, &cTabhead_YXrQA3J2_sendMessage);
  cMsg_E9eaimzv_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_hJUM360N, 0, m, &cVar_hJUM360N_sendMessage);
  cMsg_3MPn0eo7_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_Bnw0b04Z, 0, m, &cTabhead_Bnw0b04Z_sendMessage);
  cMsg_HhO1IhnH_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_qTOMUqko, 0, m, &cVar_qTOMUqko_sendMessage);
  cMsg_G4GRa0N1_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_4IJwIwRB, 0, m, &cTabhead_4IJwIwRB_sendMessage);
  cMsg_9eil7gp7_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_YKuyqJkJ, 0, m, &cVar_YKuyqJkJ_sendMessage);
  cMsg_f4adeBbk_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_ccb5gzCO, 0, m, &cTabhead_ccb5gzCO_sendMessage);
  cMsg_3ATMhcD7_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_4xtVoWQl, 0, m, &cVar_4xtVoWQl_sendMessage);
  cMsg_XVGjXlNp_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_RIhxzTXX, 0, m, &cTabhead_RIhxzTXX_sendMessage);
  cMsg_S4gbTVyH_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_m3EZUm6A, 0, m, &cVar_m3EZUm6A_sendMessage);
  cMsg_72GARumQ_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_TNf1eExq, 0, m, &cTabhead_TNf1eExq_sendMessage);
  cMsg_vCO0xInk_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_Hz4wWSlG, 0, m, &cVar_Hz4wWSlG_sendMessage);
  cMsg_HtY64ewu_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_akRr0TKx, 0, m, &cTabhead_akRr0TKx_sendMessage);
  cMsg_Wlg3wsfs_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_0Olyx67a, 0, m, &cVar_0Olyx67a_sendMessage);
  cMsg_CvCFmPfC_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_zgIRUxoj, 0, m, &cTabhead_zgIRUxoj_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_1wlv4jAe, 0, m, &cVar_1wlv4jAe_sendMessage);
  cMsg_OVfVAfdk_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_BVhRq1tD, 0, m, &cVar_BVhRq1tD_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_JiQ6bRd5, 0, m, &cVar_JiQ6bRd5_sendMessage);
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
    __hv_varread_f(&sVarf_GVIy0hBU, VOf(Bf0));
    __hv_varread_f(&sVarf_cVKoBcMM, VOf(Bf1));
    __hv_mul_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_LJNrNrgd, VOf(Bf0));
    __hv_rpole_f(&sRPole_j0JbZtTr, VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_phasor_k_f(&sPhasor_iMoLKRsm, VOf(Bf1));
    __hv_varwrite_f(&sVarf_sGelEI44, VIf(Bf1));
    __hv_varread_f(&sVarf_wurxiXrM, VOf(Bf2));
    __hv_varread_f(&sVarf_sGelEI44, VOf(Bf3));
    __hv_del1_f(&sDel1_0lZ8wKKw, VIf(Bf3), VOf(Bf4));
    __hv_lt_f(VIf(Bf3), VIf(Bf4), VOf(Bf4));
    __hv_samphold_f(&sSamphold_QN7EbMMX, VIf(Bf2), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_sGelEI44, VOf(Bf2));
    __hv_var_k_f(VOf(Bf3), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_fma_f(VIf(Bf4), VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_TB87PUyv, VOf(Bf2));
    __hv_varread_f(&sVarf_sGelEI44, VOf(Bf4));
    __hv_del1_f(&sDel1_z460VTzG, VIf(Bf4), VOf(Bf5));
    __hv_lt_f(VIf(Bf4), VIf(Bf5), VOf(Bf5));
    __hv_samphold_f(&sSamphold_wBWnNM8U, VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_add_f(VIf(Bf3), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_pJMale4s, VOf(Bf3));
    __hv_min_f(VIf(Bf5), VIf(Bf3), VOf(Bf3));
    __hv_zero_f(VOf(Bf5));
    __hv_max_f(VIf(Bf3), VIf(Bf5), VOf(Bf5));
    __hv_floor_f(VIf(Bf5), VOf(Bf3));
    __hv_cast_fi(VIf(Bf3), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_Bz8IQrUP, VIi(Bi1), VOf(Bf2));
    __hv_tabread_if(&sTabread_MfTwMD66, VIi(Bi0), VOf(Bf4));
    __hv_sub_f(VIf(Bf2), VIf(Bf4), VOf(Bf2));
    __hv_sub_f(VIf(Bf5), VIf(Bf3), VOf(Bf3));
    __hv_fma_f(VIf(Bf2), VIf(Bf3), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_sGelEI44, VOf(Bf3));
    __hv_var_k_f(VOf(Bf2), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf3), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_floor_f(VIf(Bf3), VOf(Bf2));
    __hv_sub_f(VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf3), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_abs_f(VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf2), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf3), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_mul_f(VIf(Bf3), VIf(Bf3), VOf(Bf2));
    __hv_mul_f(VIf(Bf3), VIf(Bf2), VOf(Bf5));
    __hv_mul_f(VIf(Bf5), VIf(Bf2), VOf(Bf6));
    __hv_mul_f(VIf(Bf6), VIf(Bf2), VOf(Bf7));
    __hv_mul_f(VIf(Bf7), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf8), 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f);
    __hv_var_k_f(VOf(Bf9), 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f);
    __hv_var_k_f(VOf(Bf10), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf5), VIf(Bf10), VOf(Bf10));
    __hv_sub_f(VIf(Bf3), VIf(Bf10), VOf(Bf10));
    __hv_fma_f(VIf(Bf6), VIf(Bf9), VIf(Bf10), VOf(Bf10));
    __hv_var_k_f(VOf(Bf9), 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f);
    __hv_mul_f(VIf(Bf7), VIf(Bf9), VOf(Bf9));
    __hv_sub_f(VIf(Bf10), VIf(Bf9), VOf(Bf9));
    __hv_fma_f(VIf(Bf2), VIf(Bf8), VIf(Bf9), VOf(Bf9));
    __hv_varread_f(&sVarf_uvWzq1Ec, VOf(Bf8));
    __hv_varread_f(&sVarf_VFVTKNfL, VOf(Bf2));
    __hv_del1_f(&sDel1_tRALRFZl, VIf(Bf2), VOf(Bf10));
    __hv_lt_f(VIf(Bf2), VIf(Bf10), VOf(Bf10));
    __hv_samphold_f(&sSamphold_KXe9xik7, VIf(Bf8), VIf(Bf10), VOf(Bf10));
    __hv_varread_f(&sVarf_VFVTKNfL, VOf(Bf8));
    __hv_var_k_f(VOf(Bf2), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_fma_f(VIf(Bf10), VIf(Bf8), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_aEHBNCon, VOf(Bf8));
    __hv_varread_f(&sVarf_VFVTKNfL, VOf(Bf10));
    __hv_del1_f(&sDel1_scwDdBXK, VIf(Bf10), VOf(Bf7));
    __hv_lt_f(VIf(Bf10), VIf(Bf7), VOf(Bf7));
    __hv_samphold_f(&sSamphold_rlJsbykp, VIf(Bf8), VIf(Bf7), VOf(Bf7));
    __hv_add_f(VIf(Bf2), VIf(Bf7), VOf(Bf7));
    __hv_varread_f(&sVarf_1i3HKFFn, VOf(Bf2));
    __hv_min_f(VIf(Bf7), VIf(Bf2), VOf(Bf2));
    __hv_zero_f(VOf(Bf7));
    __hv_max_f(VIf(Bf2), VIf(Bf7), VOf(Bf7));
    __hv_floor_f(VIf(Bf7), VOf(Bf2));
    __hv_cast_fi(VIf(Bf2), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_P5BLAPKi, VIi(Bi1), VOf(Bf8));
    __hv_tabread_if(&sTabread_igOAoUWy, VIi(Bi0), VOf(Bf10));
    __hv_sub_f(VIf(Bf8), VIf(Bf10), VOf(Bf8));
    __hv_sub_f(VIf(Bf7), VIf(Bf2), VOf(Bf2));
    __hv_fma_f(VIf(Bf8), VIf(Bf2), VIf(Bf10), VOf(Bf10));
    __hv_varread_f(&sVarf_VFVTKNfL, VOf(Bf2));
    __hv_var_k_f(VOf(Bf8), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf2), VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf2), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf8), VIf(Bf2), VOf(Bf2));
    __hv_floor_f(VIf(Bf2), VOf(Bf8));
    __hv_sub_f(VIf(Bf2), VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf2), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf8), VIf(Bf2), VOf(Bf2));
    __hv_abs_f(VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf8), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf2), VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf2), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf8), VIf(Bf2), VOf(Bf2));
    __hv_mul_f(VIf(Bf2), VIf(Bf2), VOf(Bf8));
    __hv_mul_f(VIf(Bf2), VIf(Bf8), VOf(Bf7));
    __hv_mul_f(VIf(Bf7), VIf(Bf8), VOf(Bf6));
    __hv_mul_f(VIf(Bf6), VIf(Bf8), VOf(Bf3));
    __hv_mul_f(VIf(Bf3), VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf5), 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f);
    __hv_var_k_f(VOf(Bf11), 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f);
    __hv_var_k_f(VOf(Bf12), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf7), VIf(Bf12), VOf(Bf12));
    __hv_sub_f(VIf(Bf2), VIf(Bf12), VOf(Bf12));
    __hv_fma_f(VIf(Bf6), VIf(Bf11), VIf(Bf12), VOf(Bf12));
    __hv_var_k_f(VOf(Bf11), 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f);
    __hv_mul_f(VIf(Bf3), VIf(Bf11), VOf(Bf11));
    __hv_sub_f(VIf(Bf12), VIf(Bf11), VOf(Bf11));
    __hv_fma_f(VIf(Bf8), VIf(Bf5), VIf(Bf11), VOf(Bf11));
    __hv_mul_f(VIf(Bf10), VIf(Bf11), VOf(Bf11));
    __hv_fma_f(VIf(Bf4), VIf(Bf9), VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf9), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_add_f(VIf(Bf1), VIf(Bf9), VOf(Bf9));
    __hv_floor_f(VIf(Bf9), VOf(Bf1));
    __hv_sub_f(VIf(Bf9), VIf(Bf1), VOf(Bf1));
    __hv_varwrite_f(&sVarf_VFVTKNfL, VIf(Bf1));
    __hv_varread_f(&sVarf_riXES2ua, VOf(Bf1));
    __hv_rpole_f(&sRPole_7jcTZ8Y7, VIf(Bf11), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf11), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_del1_f(&sDel1_wINFFuV7, VIf(Bf1), VOf(Bf9));
    __hv_mul_f(VIf(Bf9), VIf(Bf11), VOf(Bf11));
    __hv_sub_f(VIf(Bf1), VIf(Bf11), VOf(Bf11));
    __hv_varread_f(&sVarf_CwOYbibd, VOf(Bf1));
    __hv_mul_f(VIf(Bf11), VIf(Bf1), VOf(Bf1));
    __hv_mul_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_line_f(&sLine_VgJS7kLS, VOf(Bf0));
    __hv_mul_f(VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_sample_f(this, &sSample_ASCMEqPZ, VIf(Bf1), &sSample_ASCMEqPZ_sendMessage);
    __hv_line_f(&sLine_cAPdStYy, VOf(Bf1));
    __hv_varread_f(&sVarf_HgSXPSnM, VOf(Bf11));
    __hv_min_f(VIf(Bf1), VIf(Bf11), VOf(Bf11));
    __hv_zero_f(VOf(Bf1));
    __hv_max_f(VIf(Bf11), VIf(Bf1), VOf(Bf1));
    __hv_floor_f(VIf(Bf1), VOf(Bf11));
    __hv_cast_fi(VIf(Bf11), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_bBKzDePT, VIi(Bi1), VOf(Bf9));
    __hv_tabread_if(&sTabread_TReXBIUJ, VIi(Bi0), VOf(Bf4));
    __hv_sub_f(VIf(Bf9), VIf(Bf4), VOf(Bf9));
    __hv_sub_f(VIf(Bf1), VIf(Bf11), VOf(Bf11));
    __hv_fma_f(VIf(Bf9), VIf(Bf11), VIf(Bf4), VOf(Bf4));
    __hv_line_f(&sLine_qm8yewgh, VOf(Bf11));
    __hv_mul_f(VIf(Bf4), VIf(Bf11), VOf(Bf11));
    __hv_line_f(&sLine_7wuBgJ5s, VOf(Bf4));
    __hv_varread_f(&sVarf_EIuT2fqi, VOf(Bf9));
    __hv_mul_f(VIf(Bf4), VIf(Bf9), VOf(Bf9));
    __hv_mul_f(VIf(Bf11), VIf(Bf9), VOf(Bf9));
    __hv_line_f(&sLine_gVqws3WR, VOf(Bf11));
    __hv_mul_f(VIf(Bf9), VIf(Bf11), VOf(Bf11));
    __hv_line_f(&sLine_nsa1SCND, VOf(Bf4));
    __hv_mul_f(VIf(Bf9), VIf(Bf4), VOf(Bf4));
    __hv_line_f(&sLine_IB7l1ctW, VOf(Bf9));
    __hv_varread_f(&sVarf_bgDUH05l, VOf(Bf1));
    __hv_min_f(VIf(Bf9), VIf(Bf1), VOf(Bf1));
    __hv_zero_f(VOf(Bf9));
    __hv_max_f(VIf(Bf1), VIf(Bf9), VOf(Bf9));
    __hv_floor_f(VIf(Bf9), VOf(Bf1));
    __hv_cast_fi(VIf(Bf1), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_61hRkCkk, VIi(Bi1), VOf(Bf10));
    __hv_tabread_if(&sTabread_Dq51SkCT, VIi(Bi0), VOf(Bf5));
    __hv_sub_f(VIf(Bf10), VIf(Bf5), VOf(Bf10));
    __hv_sub_f(VIf(Bf9), VIf(Bf1), VOf(Bf1));
    __hv_fma_f(VIf(Bf10), VIf(Bf1), VIf(Bf5), VOf(Bf5));
    __hv_line_f(&sLine_OhR0L8UX, VOf(Bf1));
    __hv_mul_f(VIf(Bf5), VIf(Bf1), VOf(Bf1));
    __hv_line_f(&sLine_O0ifSzPL, VOf(Bf5));
    __hv_varread_f(&sVarf_3UEzL0uV, VOf(Bf10));
    __hv_mul_f(VIf(Bf5), VIf(Bf10), VOf(Bf10));
    __hv_mul_f(VIf(Bf1), VIf(Bf10), VOf(Bf10));
    __hv_line_f(&sLine_kpWJi41L, VOf(Bf1));
    __hv_mul_f(VIf(Bf10), VIf(Bf1), VOf(Bf1));
    __hv_line_f(&sLine_fa9VpVzC, VOf(Bf5));
    __hv_mul_f(VIf(Bf10), VIf(Bf5), VOf(Bf5));
    __hv_add_f(VIf(Bf11), VIf(Bf5), VOf(Bf5));
    __hv_line_f(&sLine_QtVh0uKT, VOf(Bf11));
    __hv_varread_f(&sVarf_A6KZg1dy, VOf(Bf10));
    __hv_min_f(VIf(Bf11), VIf(Bf10), VOf(Bf10));
    __hv_zero_f(VOf(Bf11));
    __hv_max_f(VIf(Bf10), VIf(Bf11), VOf(Bf11));
    __hv_floor_f(VIf(Bf11), VOf(Bf10));
    __hv_cast_fi(VIf(Bf10), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_xvfKRRxx, VIi(Bi1), VOf(Bf9));
    __hv_tabread_if(&sTabread_eAmx89Kq, VIi(Bi0), VOf(Bf8));
    __hv_sub_f(VIf(Bf9), VIf(Bf8), VOf(Bf9));
    __hv_sub_f(VIf(Bf11), VIf(Bf10), VOf(Bf10));
    __hv_fma_f(VIf(Bf9), VIf(Bf10), VIf(Bf8), VOf(Bf8));
    __hv_line_f(&sLine_KRQa77bb, VOf(Bf10));
    __hv_mul_f(VIf(Bf8), VIf(Bf10), VOf(Bf10));
    __hv_line_f(&sLine_2P8mbY2y, VOf(Bf8));
    __hv_varread_f(&sVarf_t5IYoLta, VOf(Bf9));
    __hv_mul_f(VIf(Bf8), VIf(Bf9), VOf(Bf9));
    __hv_mul_f(VIf(Bf10), VIf(Bf9), VOf(Bf9));
    __hv_line_f(&sLine_N6lrmGJT, VOf(Bf10));
    __hv_mul_f(VIf(Bf9), VIf(Bf10), VOf(Bf10));
    __hv_line_f(&sLine_b2iW3hdu, VOf(Bf8));
    __hv_mul_f(VIf(Bf9), VIf(Bf8), VOf(Bf8));
    __hv_add_f(VIf(Bf5), VIf(Bf8), VOf(Bf8));
    __hv_line_f(&sLine_VYGTLUEb, VOf(Bf5));
    __hv_varread_f(&sVarf_jIF40qTi, VOf(Bf9));
    __hv_min_f(VIf(Bf5), VIf(Bf9), VOf(Bf9));
    __hv_zero_f(VOf(Bf5));
    __hv_max_f(VIf(Bf9), VIf(Bf5), VOf(Bf5));
    __hv_floor_f(VIf(Bf5), VOf(Bf9));
    __hv_cast_fi(VIf(Bf9), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_aqpc7o1W, VIi(Bi1), VOf(Bf11));
    __hv_tabread_if(&sTabread_6uYUGrWc, VIi(Bi0), VOf(Bf12));
    __hv_sub_f(VIf(Bf11), VIf(Bf12), VOf(Bf11));
    __hv_sub_f(VIf(Bf5), VIf(Bf9), VOf(Bf9));
    __hv_fma_f(VIf(Bf11), VIf(Bf9), VIf(Bf12), VOf(Bf12));
    __hv_line_f(&sLine_HIEYxg14, VOf(Bf9));
    __hv_mul_f(VIf(Bf12), VIf(Bf9), VOf(Bf9));
    __hv_line_f(&sLine_0dA8JbKr, VOf(Bf12));
    __hv_varread_f(&sVarf_xpi24x7y, VOf(Bf11));
    __hv_mul_f(VIf(Bf12), VIf(Bf11), VOf(Bf11));
    __hv_mul_f(VIf(Bf9), VIf(Bf11), VOf(Bf11));
    __hv_line_f(&sLine_iJIcUm7s, VOf(Bf9));
    __hv_mul_f(VIf(Bf11), VIf(Bf9), VOf(Bf9));
    __hv_line_f(&sLine_wKjUfunQ, VOf(Bf12));
    __hv_mul_f(VIf(Bf11), VIf(Bf12), VOf(Bf12));
    __hv_add_f(VIf(Bf8), VIf(Bf12), VOf(Bf12));
    __hv_add_f(VIf(Bf4), VIf(Bf1), VOf(Bf1));
    __hv_add_f(VIf(Bf1), VIf(Bf10), VOf(Bf10));
    __hv_add_f(VIf(Bf10), VIf(Bf9), VOf(Bf9));
    __hv_line_f(&sLine_nzETJbrO, VOf(Bf10));
    __hv_mul_f(VIf(Bf9), VIf(Bf10), VOf(Bf9));
    __hv_mul_f(VIf(Bf12), VIf(Bf10), VOf(Bf10));
    __hv_line_f(&sLine_QM37Rcsm, VOf(Bf12));
    __hv_mul_f(VIf(Bf0), VIf(Bf12), VOf(Bf12));
    __hv_add_f(VIf(Bf10), VIf(Bf12), VOf(Bf0));
    __hv_add_f(VIf(Bf9), VIf(Bf12), VOf(Bf9));
    __hv_line_f(&sLine_naTWa0RH, VOf(Bf1));
    __hv_mul_f(VIf(Bf0), VIf(Bf1), VOf(Bf0));
    __hv_mul_f(VIf(Bf9), VIf(Bf1), VOf(Bf1));
    __hv_add_f(VIf(Bf10), VIf(Bf12), VOf(Bf12));
    __hv_line_f(&sLine_ZZKNZRLX, VOf(Bf10));
    __hv_mul_f(VIf(Bf12), VIf(Bf10), VOf(Bf10));
    __hv_line_f(&sLine_1gpI2VKu, VOf(Bf12));
    __hv_mul_f(VIf(Bf10), VIf(Bf12), VOf(Bf12));
    __hv_line_f(&sLine_0ZnGXISG, VOf(Bf9));
    __hv_phasor_f(&sPhasor_gvfGqYF2, VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf4), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf9), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf8), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf4), VIf(Bf8), VOf(Bf8));
    __hv_floor_f(VIf(Bf8), VOf(Bf4));
    __hv_sub_f(VIf(Bf8), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf8), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf4), VIf(Bf8), VOf(Bf8));
    __hv_abs_f(VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf4), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf8), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf8), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf4), VIf(Bf8), VOf(Bf8));
    __hv_mul_f(VIf(Bf8), VIf(Bf8), VOf(Bf4));
    __hv_mul_f(VIf(Bf8), VIf(Bf4), VOf(Bf11));
    __hv_mul_f(VIf(Bf11), VIf(Bf4), VOf(Bf5));
    __hv_mul_f(VIf(Bf5), VIf(Bf4), VOf(Bf3));
    __hv_mul_f(VIf(Bf3), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf6), 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f);
    __hv_var_k_f(VOf(Bf2), 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f);
    __hv_var_k_f(VOf(Bf7), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf11), VIf(Bf7), VOf(Bf7));
    __hv_sub_f(VIf(Bf8), VIf(Bf7), VOf(Bf7));
    __hv_fma_f(VIf(Bf5), VIf(Bf2), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf2), 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f);
    __hv_mul_f(VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_sub_f(VIf(Bf7), VIf(Bf2), VOf(Bf2));
    __hv_fma_f(VIf(Bf4), VIf(Bf6), VIf(Bf2), VOf(Bf2));
    __hv_line_f(&sLine_6zA7jM3e, VOf(Bf6));
    __hv_line_f(&sLine_AV6C8lwf, VOf(Bf4));
    __hv_fma_f(VIf(Bf9), VIf(Bf6), VIf(Bf4), VOf(Bf7));
    __hv_tabhead_f(&sTabhead_TpMbhQ1X, VOf(Bf3));
    __hv_var_k_f_r(VOf(Bf5), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf3), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_pymPXy7g, VOf(Bf3));
    __hv_mul_f(VIf(Bf7), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_l3q2gskJ, VOf(Bf7));
    __hv_min_f(VIf(Bf3), VIf(Bf7), VOf(Bf7));
    __hv_zero_f(VOf(Bf3));
    __hv_max_f(VIf(Bf7), VIf(Bf3), VOf(Bf3));
    __hv_sub_f(VIf(Bf5), VIf(Bf3), VOf(Bf3));
    __hv_floor_f(VIf(Bf3), VOf(Bf5));
    __hv_varread_f(&sVarf_xUZp3MPJ, VOf(Bf7));
    __hv_zero_f(VOf(Bf8));
    __hv_lt_f(VIf(Bf5), VIf(Bf8), VOf(Bf8));
    __hv_and_f(VIf(Bf7), VIf(Bf8), VOf(Bf8));
    __hv_add_f(VIf(Bf5), VIf(Bf8), VOf(Bf8));
    __hv_cast_fi(VIf(Bf8), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_f6cXPNu8, VIi(Bi1), VOf(Bf8));
    __hv_tabread_if(&sTabread_mxhuiuoL, VIi(Bi0), VOf(Bf7));
    __hv_sub_f(VIf(Bf8), VIf(Bf7), VOf(Bf8));
    __hv_sub_f(VIf(Bf3), VIf(Bf5), VOf(Bf5));
    __hv_fma_f(VIf(Bf8), VIf(Bf5), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf5), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_add_f(VIf(Bf9), VIf(Bf5), VOf(Bf5));
    __hv_floor_f(VIf(Bf5), VOf(Bf9));
    __hv_sub_f(VIf(Bf5), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf5), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf9), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf8), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf5), VIf(Bf8), VOf(Bf8));
    __hv_floor_f(VIf(Bf8), VOf(Bf5));
    __hv_sub_f(VIf(Bf8), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf8), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf5), VIf(Bf8), VOf(Bf8));
    __hv_abs_f(VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf5), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf8), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf8), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf5), VIf(Bf8), VOf(Bf8));
    __hv_mul_f(VIf(Bf8), VIf(Bf8), VOf(Bf5));
    __hv_mul_f(VIf(Bf8), VIf(Bf5), VOf(Bf3));
    __hv_mul_f(VIf(Bf3), VIf(Bf5), VOf(Bf11));
    __hv_mul_f(VIf(Bf11), VIf(Bf5), VOf(Bf13));
    __hv_mul_f(VIf(Bf13), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf14), 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f);
    __hv_var_k_f(VOf(Bf15), 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f);
    __hv_var_k_f(VOf(Bf16), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf3), VIf(Bf16), VOf(Bf16));
    __hv_sub_f(VIf(Bf8), VIf(Bf16), VOf(Bf16));
    __hv_fma_f(VIf(Bf11), VIf(Bf15), VIf(Bf16), VOf(Bf16));
    __hv_var_k_f(VOf(Bf15), 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f);
    __hv_mul_f(VIf(Bf13), VIf(Bf15), VOf(Bf15));
    __hv_sub_f(VIf(Bf16), VIf(Bf15), VOf(Bf15));
    __hv_fma_f(VIf(Bf5), VIf(Bf14), VIf(Bf15), VOf(Bf15));
    __hv_fma_f(VIf(Bf9), VIf(Bf6), VIf(Bf4), VOf(Bf4));
    __hv_tabhead_f(&sTabhead_kFx6KNgb, VOf(Bf6));
    __hv_var_k_f_r(VOf(Bf9), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf6), VIf(Bf9), VOf(Bf9));
    __hv_varread_f(&sVarf_JZG5yxNg, VOf(Bf6));
    __hv_mul_f(VIf(Bf4), VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_gj6OsYoC, VOf(Bf4));
    __hv_min_f(VIf(Bf6), VIf(Bf4), VOf(Bf4));
    __hv_zero_f(VOf(Bf6));
    __hv_max_f(VIf(Bf4), VIf(Bf6), VOf(Bf6));
    __hv_sub_f(VIf(Bf9), VIf(Bf6), VOf(Bf6));
    __hv_floor_f(VIf(Bf6), VOf(Bf9));
    __hv_varread_f(&sVarf_VPA9eOP7, VOf(Bf4));
    __hv_zero_f(VOf(Bf14));
    __hv_lt_f(VIf(Bf9), VIf(Bf14), VOf(Bf14));
    __hv_and_f(VIf(Bf4), VIf(Bf14), VOf(Bf14));
    __hv_add_f(VIf(Bf9), VIf(Bf14), VOf(Bf14));
    __hv_cast_fi(VIf(Bf14), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_WSZyb2A2, VIi(Bi1), VOf(Bf14));
    __hv_tabread_if(&sTabread_rq9uXTGZ, VIi(Bi0), VOf(Bf4));
    __hv_sub_f(VIf(Bf14), VIf(Bf4), VOf(Bf14));
    __hv_sub_f(VIf(Bf6), VIf(Bf9), VOf(Bf9));
    __hv_fma_f(VIf(Bf14), VIf(Bf9), VIf(Bf4), VOf(Bf4));
    __hv_mul_f(VIf(Bf15), VIf(Bf4), VOf(Bf4));
    __hv_fma_f(VIf(Bf2), VIf(Bf7), VIf(Bf4), VOf(Bf4));
    __hv_tabwrite_f(&sTabwrite_68ZEmoet, VIf(Bf12));
    __hv_line_f(&sLine_JxCbhdLP, VOf(Bf12));
    __hv_varread_f(&sVarf_lm1HusbR, VOf(Bf7));
    __hv_tabhead_f(&sTabhead_pi8hVpWZ, VOf(Bf2));
    __hv_var_k_f_r(VOf(Bf15), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf2), VIf(Bf15), VOf(Bf15));
    __hv_varread_f(&sVarf_BvHUiFWi, VOf(Bf2));
    __hv_mul_f(VIf(Bf7), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_eOHSLqSm, VOf(Bf7));
    __hv_min_f(VIf(Bf2), VIf(Bf7), VOf(Bf7));
    __hv_zero_f(VOf(Bf2));
    __hv_max_f(VIf(Bf7), VIf(Bf2), VOf(Bf2));
    __hv_sub_f(VIf(Bf15), VIf(Bf2), VOf(Bf2));
    __hv_floor_f(VIf(Bf2), VOf(Bf15));
    __hv_varread_f(&sVarf_vqZaoEA2, VOf(Bf7));
    __hv_zero_f(VOf(Bf9));
    __hv_lt_f(VIf(Bf15), VIf(Bf9), VOf(Bf9));
    __hv_and_f(VIf(Bf7), VIf(Bf9), VOf(Bf9));
    __hv_add_f(VIf(Bf15), VIf(Bf9), VOf(Bf9));
    __hv_cast_fi(VIf(Bf9), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_zi5qKH5S, VIi(Bi1), VOf(Bf9));
    __hv_tabread_if(&sTabread_EV9mrtn6, VIi(Bi0), VOf(Bf7));
    __hv_sub_f(VIf(Bf9), VIf(Bf7), VOf(Bf9));
    __hv_sub_f(VIf(Bf2), VIf(Bf15), VOf(Bf15));
    __hv_fma_f(VIf(Bf9), VIf(Bf15), VIf(Bf7), VOf(Bf7));
    __hv_varread_f(&sVarf_4hlqXWkV, VOf(Bf15));
    __hv_rpole_f(&sRPole_mDpKj3Vn, VIf(Bf7), VIf(Bf15), VOf(Bf15));
    __hv_var_k_f(VOf(Bf7), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_del1_f(&sDel1_YhQaLXkj, VIf(Bf15), VOf(Bf9));
    __hv_mul_f(VIf(Bf9), VIf(Bf7), VOf(Bf7));
    __hv_sub_f(VIf(Bf15), VIf(Bf7), VOf(Bf7));
    __hv_varread_f(&sVarf_Rf6pjyZ3, VOf(Bf15));
    __hv_mul_f(VIf(Bf7), VIf(Bf15), VOf(Bf15));
    __hv_varread_f(&sVarf_gJI5XJwD, VOf(Bf7));
    __hv_mul_f(VIf(Bf15), VIf(Bf7), VOf(Bf7));
    __hv_varread_f(&sVarf_phgJDijJ, VOf(Bf15));
    __hv_mul_f(VIf(Bf7), VIf(Bf15), VOf(Bf15));
    __hv_varread_f(&sVarf_dcmGhIc0, VOf(Bf9));
    __hv_rpole_f(&sRPole_bL1DfBh9, VIf(Bf15), VIf(Bf9), VOf(Bf9));
    __hv_fma_f(VIf(Bf4), VIf(Bf12), VIf(Bf9), VOf(Bf9));
    __hv_tabwrite_f(&sTabwrite_fO5JNITB, VIf(Bf9));
    __hv_add_f(VIf(Bf4), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf4), 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f);
    __hv_mul_f(VIf(Bf7), VIf(Bf4), VOf(Bf4));
    __hv_tabread_f(&sTabread_UMAlHkrX, VOf(Bf7));
    __hv_varread_f(&sVarf_khHH09UD, VOf(Bf9));
    __hv_mul_f(VIf(Bf7), VIf(Bf9), VOf(Bf9));
    __hv_varread_f(&sVarf_XGtlPRgZ, VOf(Bf12));
    __hv_rpole_f(&sRPole_Us9d778h, VIf(Bf9), VIf(Bf12), VOf(Bf12));
    __hv_sub_f(VIf(Bf12), VIf(Bf7), VOf(Bf12));
    __hv_line_f(&sLine_LW9JeSpj, VOf(Bf9));
    __hv_fma_f(VIf(Bf12), VIf(Bf9), VIf(Bf7), VOf(Bf7));
    __hv_line_f(&sLine_KmqMAnhB, VOf(Bf12));
    __hv_mul_f(VIf(Bf7), VIf(Bf12), VOf(Bf7));
    __hv_line_f(&sLine_zd8iUYEN, VOf(Bf15));
    __hv_mul_f(VIf(Bf7), VIf(Bf15), VOf(Bf2));
    __hv_tabread_f(&sTabread_Mf3ytb18, VOf(Bf14));
    __hv_varread_f(&sVarf_5AQtq8SZ, VOf(Bf6));
    __hv_mul_f(VIf(Bf14), VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_rJYLNPto, VOf(Bf5));
    __hv_rpole_f(&sRPole_veFf5zJg, VIf(Bf6), VIf(Bf5), VOf(Bf5));
    __hv_sub_f(VIf(Bf5), VIf(Bf14), VOf(Bf5));
    __hv_fma_f(VIf(Bf5), VIf(Bf9), VIf(Bf14), VOf(Bf14));
    __hv_tabread_f(&sTabread_v5M3Sot5, VOf(Bf5));
    __hv_add_f(VIf(Bf10), VIf(Bf5), VOf(Bf6));
    __hv_tabread_f(&sTabread_9oR6lA7J, VOf(Bf16));
    __hv_sub_f(VIf(Bf6), VIf(Bf16), VOf(Bf13));
    __hv_tabwrite_f(&sTabwrite_KVJjR7db, VIf(Bf13));
    __hv_tabwrite_f(&sTabwrite_rYsjrFF2, VIf(Bf10));
    __hv_tabread_f(&sTabread_xVPC2oxR, VOf(Bf13));
    __hv_add_f(VIf(Bf6), VIf(Bf16), VOf(Bf16));
    __hv_tabread_f(&sTabread_O6jFGsul, VOf(Bf6));
    __hv_add_f(VIf(Bf16), VIf(Bf6), VOf(Bf11));
    __hv_tabread_f(&sTabread_NIIx5kU1, VOf(Bf8));
    __hv_add_f(VIf(Bf11), VIf(Bf8), VOf(Bf3));
    __hv_tabread_f(&sTabread_AgyAQgdX, VOf(Bf17));
    __hv_sub_f(VIf(Bf3), VIf(Bf17), VOf(Bf18));
    __hv_tabwrite_f(&sTabwrite_Z9aUjTyP, VIf(Bf18));
    __hv_sub_f(VIf(Bf16), VIf(Bf6), VOf(Bf6));
    __hv_tabwrite_f(&sTabwrite_IxL6w6Y4, VIf(Bf6));
    __hv_sub_f(VIf(Bf11), VIf(Bf8), VOf(Bf8));
    __hv_tabwrite_f(&sTabwrite_z6VSE2bb, VIf(Bf8));
    __hv_add_f(VIf(Bf3), VIf(Bf17), VOf(Bf17));
    __hv_sub_f(VIf(Bf10), VIf(Bf5), VOf(Bf5));
    __hv_tabwrite_f(&sTabwrite_xAmeylLP, VIf(Bf5));
    __hv_fma_f(VIf(Bf14), VIf(Bf12), VIf(Bf17), VOf(Bf17));
    __hv_tabread_f(&sTabread_95dkUskH, VOf(Bf14));
    __hv_varread_f(&sVarf_6GXKnDCJ, VOf(Bf5));
    __hv_mul_f(VIf(Bf14), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_EdSrWJPJ, VOf(Bf3));
    __hv_rpole_f(&sRPole_wtHNLpvF, VIf(Bf5), VIf(Bf3), VOf(Bf3));
    __hv_sub_f(VIf(Bf3), VIf(Bf14), VOf(Bf3));
    __hv_fma_f(VIf(Bf3), VIf(Bf9), VIf(Bf14), VOf(Bf14));
    __hv_fma_f(VIf(Bf14), VIf(Bf12), VIf(Bf13), VOf(Bf13));
    __hv_add_f(VIf(Bf17), VIf(Bf13), VOf(Bf14));
    __hv_tabread_f(&sTabread_A7NRdDRo, VOf(Bf3));
    __hv_varread_f(&sVarf_cMXIMxQ6, VOf(Bf5));
    __hv_mul_f(VIf(Bf3), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_HkIt0OkD, VOf(Bf8));
    __hv_rpole_f(&sRPole_55b4L959, VIf(Bf5), VIf(Bf8), VOf(Bf8));
    __hv_sub_f(VIf(Bf8), VIf(Bf3), VOf(Bf8));
    __hv_fma_f(VIf(Bf8), VIf(Bf9), VIf(Bf3), VOf(Bf3));
    __hv_mul_f(VIf(Bf3), VIf(Bf12), VOf(Bf12));
    __hv_add_f(VIf(Bf7), VIf(Bf12), VOf(Bf3));
    __hv_add_f(VIf(Bf14), VIf(Bf3), VOf(Bf9));
    __hv_tabwrite_f(&sTabwrite_tI1NGy9l, VIf(Bf9));
    __hv_mul_f(VIf(Bf13), VIf(Bf15), VOf(Bf9));
    __hv_mul_f(VIf(Bf12), VIf(Bf15), VOf(Bf8));
    __hv_mul_f(VIf(Bf17), VIf(Bf15), VOf(Bf15));
    __hv_sub_f(VIf(Bf17), VIf(Bf13), VOf(Bf13));
    __hv_sub_f(VIf(Bf7), VIf(Bf12), VOf(Bf12));
    __hv_sub_f(VIf(Bf13), VIf(Bf12), VOf(Bf7));
    __hv_tabwrite_f(&sTabwrite_FOWYkAfr, VIf(Bf7));
    __hv_add_f(VIf(Bf13), VIf(Bf12), VOf(Bf12));
    __hv_tabwrite_f(&sTabwrite_9qK970t4, VIf(Bf12));
    __hv_sub_f(VIf(Bf14), VIf(Bf3), VOf(Bf3));
    __hv_tabwrite_f(&sTabwrite_PUK5OSPa, VIf(Bf3));
    __hv_add_f(VIf(Bf4), VIf(Bf9), VOf(Bf9));
    __hv_line_f(&sLine_8gj0B0K3, VOf(Bf8));
    __hv_mul_f(VIf(Bf10), VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf10), 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f);
    __hv_mul_f(VIf(Bf8), VIf(Bf10), VOf(Bf10));
    __hv_tabwrite_f(&sTabwrite_M5vsPrLF, VIf(Bf10));
    __hv_line_f(&sLine_cSvxiMqk, VOf(Bf8));
    __hv_phasor_f(&sPhasor_ZhjAi2ej, VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf2), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf8), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf3), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_floor_f(VIf(Bf3), VOf(Bf2));
    __hv_sub_f(VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf3), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_abs_f(VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf2), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf3), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_mul_f(VIf(Bf3), VIf(Bf3), VOf(Bf2));
    __hv_mul_f(VIf(Bf3), VIf(Bf2), VOf(Bf14));
    __hv_mul_f(VIf(Bf14), VIf(Bf2), VOf(Bf12));
    __hv_mul_f(VIf(Bf12), VIf(Bf2), VOf(Bf13));
    __hv_mul_f(VIf(Bf13), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf7), 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f);
    __hv_var_k_f(VOf(Bf17), 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f);
    __hv_var_k_f(VOf(Bf5), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf14), VIf(Bf5), VOf(Bf5));
    __hv_sub_f(VIf(Bf3), VIf(Bf5), VOf(Bf5));
    __hv_fma_f(VIf(Bf12), VIf(Bf17), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf17), 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f);
    __hv_mul_f(VIf(Bf13), VIf(Bf17), VOf(Bf17));
    __hv_sub_f(VIf(Bf5), VIf(Bf17), VOf(Bf17));
    __hv_fma_f(VIf(Bf2), VIf(Bf7), VIf(Bf17), VOf(Bf17));
    __hv_line_f(&sLine_w64ryzUm, VOf(Bf7));
    __hv_line_f(&sLine_qhyBzUUM, VOf(Bf2));
    __hv_fma_f(VIf(Bf8), VIf(Bf7), VIf(Bf2), VOf(Bf5));
    __hv_tabhead_f(&sTabhead_XfKTIjIk, VOf(Bf13));
    __hv_var_k_f_r(VOf(Bf12), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf13), VIf(Bf12), VOf(Bf12));
    __hv_varread_f(&sVarf_2LRolcvh, VOf(Bf13));
    __hv_mul_f(VIf(Bf5), VIf(Bf13), VOf(Bf13));
    __hv_varread_f(&sVarf_krc7fk4O, VOf(Bf5));
    __hv_min_f(VIf(Bf13), VIf(Bf5), VOf(Bf5));
    __hv_zero_f(VOf(Bf13));
    __hv_max_f(VIf(Bf5), VIf(Bf13), VOf(Bf13));
    __hv_sub_f(VIf(Bf12), VIf(Bf13), VOf(Bf13));
    __hv_floor_f(VIf(Bf13), VOf(Bf12));
    __hv_varread_f(&sVarf_C9TD0mPy, VOf(Bf5));
    __hv_zero_f(VOf(Bf3));
    __hv_lt_f(VIf(Bf12), VIf(Bf3), VOf(Bf3));
    __hv_and_f(VIf(Bf5), VIf(Bf3), VOf(Bf3));
    __hv_add_f(VIf(Bf12), VIf(Bf3), VOf(Bf3));
    __hv_cast_fi(VIf(Bf3), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_DOoKdRAh, VIi(Bi1), VOf(Bf3));
    __hv_tabread_if(&sTabread_Oadm9wkv, VIi(Bi0), VOf(Bf5));
    __hv_sub_f(VIf(Bf3), VIf(Bf5), VOf(Bf3));
    __hv_sub_f(VIf(Bf13), VIf(Bf12), VOf(Bf12));
    __hv_fma_f(VIf(Bf3), VIf(Bf12), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf12), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_add_f(VIf(Bf8), VIf(Bf12), VOf(Bf12));
    __hv_floor_f(VIf(Bf12), VOf(Bf8));
    __hv_sub_f(VIf(Bf12), VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf12), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf8), VIf(Bf12), VOf(Bf12));
    __hv_var_k_f(VOf(Bf3), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf12), VIf(Bf3), VOf(Bf3));
    __hv_floor_f(VIf(Bf3), VOf(Bf12));
    __hv_sub_f(VIf(Bf3), VIf(Bf12), VOf(Bf12));
    __hv_var_k_f(VOf(Bf3), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf12), VIf(Bf3), VOf(Bf3));
    __hv_abs_f(VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf12), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf3), VIf(Bf12), VOf(Bf12));
    __hv_var_k_f(VOf(Bf3), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf12), VIf(Bf3), VOf(Bf3));
    __hv_mul_f(VIf(Bf3), VIf(Bf3), VOf(Bf12));
    __hv_mul_f(VIf(Bf3), VIf(Bf12), VOf(Bf13));
    __hv_mul_f(VIf(Bf13), VIf(Bf12), VOf(Bf14));
    __hv_mul_f(VIf(Bf14), VIf(Bf12), VOf(Bf11));
    __hv_mul_f(VIf(Bf11), VIf(Bf12), VOf(Bf12));
    __hv_var_k_f(VOf(Bf6), 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f);
    __hv_var_k_f(VOf(Bf16), 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f);
    __hv_var_k_f(VOf(Bf18), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf13), VIf(Bf18), VOf(Bf18));
    __hv_sub_f(VIf(Bf3), VIf(Bf18), VOf(Bf18));
    __hv_fma_f(VIf(Bf14), VIf(Bf16), VIf(Bf18), VOf(Bf18));
    __hv_var_k_f(VOf(Bf16), 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f);
    __hv_mul_f(VIf(Bf11), VIf(Bf16), VOf(Bf16));
    __hv_sub_f(VIf(Bf18), VIf(Bf16), VOf(Bf16));
    __hv_fma_f(VIf(Bf12), VIf(Bf6), VIf(Bf16), VOf(Bf16));
    __hv_fma_f(VIf(Bf8), VIf(Bf7), VIf(Bf2), VOf(Bf2));
    __hv_tabhead_f(&sTabhead_nM3OwlwO, VOf(Bf7));
    __hv_var_k_f_r(VOf(Bf8), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf7), VIf(Bf8), VOf(Bf8));
    __hv_varread_f(&sVarf_p1jGECpz, VOf(Bf7));
    __hv_mul_f(VIf(Bf2), VIf(Bf7), VOf(Bf7));
    __hv_varread_f(&sVarf_ZSHKmGzo, VOf(Bf2));
    __hv_min_f(VIf(Bf7), VIf(Bf2), VOf(Bf2));
    __hv_zero_f(VOf(Bf7));
    __hv_max_f(VIf(Bf2), VIf(Bf7), VOf(Bf7));
    __hv_sub_f(VIf(Bf8), VIf(Bf7), VOf(Bf7));
    __hv_floor_f(VIf(Bf7), VOf(Bf8));
    __hv_varread_f(&sVarf_EiBAcfDc, VOf(Bf2));
    __hv_zero_f(VOf(Bf6));
    __hv_lt_f(VIf(Bf8), VIf(Bf6), VOf(Bf6));
    __hv_and_f(VIf(Bf2), VIf(Bf6), VOf(Bf6));
    __hv_add_f(VIf(Bf8), VIf(Bf6), VOf(Bf6));
    __hv_cast_fi(VIf(Bf6), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_DLCdY9pw, VIi(Bi1), VOf(Bf6));
    __hv_tabread_if(&sTabread_elfAU654, VIi(Bi0), VOf(Bf2));
    __hv_sub_f(VIf(Bf6), VIf(Bf2), VOf(Bf6));
    __hv_sub_f(VIf(Bf7), VIf(Bf8), VOf(Bf8));
    __hv_fma_f(VIf(Bf6), VIf(Bf8), VIf(Bf2), VOf(Bf2));
    __hv_mul_f(VIf(Bf16), VIf(Bf2), VOf(Bf2));
    __hv_fma_f(VIf(Bf17), VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_hmWBbNn7, VOf(Bf5));
    __hv_tabhead_f(&sTabhead_PI9lMAug, VOf(Bf17));
    __hv_var_k_f_r(VOf(Bf16), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf17), VIf(Bf16), VOf(Bf16));
    __hv_varread_f(&sVarf_h9b0vrTz, VOf(Bf17));
    __hv_mul_f(VIf(Bf5), VIf(Bf17), VOf(Bf17));
    __hv_varread_f(&sVarf_HpEo7pyO, VOf(Bf5));
    __hv_min_f(VIf(Bf17), VIf(Bf5), VOf(Bf5));
    __hv_zero_f(VOf(Bf17));
    __hv_max_f(VIf(Bf5), VIf(Bf17), VOf(Bf17));
    __hv_sub_f(VIf(Bf16), VIf(Bf17), VOf(Bf17));
    __hv_floor_f(VIf(Bf17), VOf(Bf16));
    __hv_varread_f(&sVarf_3YLMKCtN, VOf(Bf5));
    __hv_zero_f(VOf(Bf8));
    __hv_lt_f(VIf(Bf16), VIf(Bf8), VOf(Bf8));
    __hv_and_f(VIf(Bf5), VIf(Bf8), VOf(Bf8));
    __hv_add_f(VIf(Bf16), VIf(Bf8), VOf(Bf8));
    __hv_cast_fi(VIf(Bf8), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_nrhM4q20, VIi(Bi1), VOf(Bf8));
    __hv_tabread_if(&sTabread_GnS6mRac, VIi(Bi0), VOf(Bf5));
    __hv_sub_f(VIf(Bf8), VIf(Bf5), VOf(Bf8));
    __hv_sub_f(VIf(Bf17), VIf(Bf16), VOf(Bf16));
    __hv_fma_f(VIf(Bf8), VIf(Bf16), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_d18kc4ju, VOf(Bf16));
    __hv_rpole_f(&sRPole_20ttpJ0R, VIf(Bf5), VIf(Bf16), VOf(Bf16));
    __hv_var_k_f(VOf(Bf5), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_del1_f(&sDel1_tHRbrtx4, VIf(Bf16), VOf(Bf8));
    __hv_mul_f(VIf(Bf8), VIf(Bf5), VOf(Bf5));
    __hv_sub_f(VIf(Bf16), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_aOyNmdiR, VOf(Bf16));
    __hv_mul_f(VIf(Bf5), VIf(Bf16), VOf(Bf16));
    __hv_varread_f(&sVarf_QS92CIuz, VOf(Bf5));
    __hv_mul_f(VIf(Bf16), VIf(Bf5), VOf(Bf5));
    __hv_add_f(VIf(Bf2), VIf(Bf5), VOf(Bf16));
    __hv_line_f(&sLine_v8wXUZlu, VOf(Bf8));
    __hv_varread_f(&sVarf_VmXj2GYM, VOf(Bf17));
    __hv_mul_f(VIf(Bf5), VIf(Bf17), VOf(Bf17));
    __hv_varread_f(&sVarf_ToQ7iRm0, VOf(Bf5));
    __hv_rpole_f(&sRPole_V5SmtTvk, VIf(Bf17), VIf(Bf5), VOf(Bf5));
    __hv_fma_f(VIf(Bf2), VIf(Bf8), VIf(Bf5), VOf(Bf5));
    __hv_tabwrite_f(&sTabwrite_dW9XFL9Q, VIf(Bf5));
    __hv_add_f(VIf(Bf16), VIf(Bf10), VOf(Bf10));
    __hv_varread_f(&sVarf_bJgA5bbd, VOf(Bf16));
    __hv_varread_f(&sVarf_iYpB7zhT, VOf(Bf5));
    __hv_mul_f(VIf(Bf16), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf16), 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f);
    __hv_max_f(VIf(Bf5), VIf(Bf16), VOf(Bf16));
    __hv_varread_f(&sVarf_hs5c8nL0, VOf(Bf5));
    __hv_min_f(VIf(Bf16), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_JkevEWcv, VOf(Bf8));
    __hv_mul_f(VIf(Bf5), VIf(Bf8), VOf(Bf8));
    __hv_mul_f(VIf(Bf10), VIf(Bf8), VOf(Bf10));
    __hv_varread_f(&sVarf_gszK72BP, VOf(Bf5));
    __hv_mul_f(VIf(Bf10), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf10), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_sub_f(VIf(Bf8), VIf(Bf10), VOf(Bf8));
    __hv_cos_f(VIf(Bf16), VOf(Bf16));
    __hv_mul_f(VIf(Bf8), VIf(Bf16), VOf(Bf2));
    __hv_mul_f(VIf(Bf16), VIf(Bf16), VOf(Bf16));
    __hv_sub_f(VIf(Bf10), VIf(Bf16), VOf(Bf16));
    __hv_zero_f(VOf(Bf10));
    __hv_gt_f(VIf(Bf16), VIf(Bf10), VOf(Bf10));
    __hv_sqrt_f(VIf(Bf16), VOf(Bf16));
    __hv_and_f(VIf(Bf10), VIf(Bf16), VOf(Bf16));
    __hv_mul_f(VIf(Bf8), VIf(Bf16), VOf(Bf16));
    __hv_cpole_f(&sCPole_v6gO6sOD, VIf(Bf5), VIf(ZERO), VIf(Bf2), VIf(Bf16), VOf(Bf16), VOf(Bf2));
    __hv_varread_f(&sVarf_kWAJOmwx, VOf(Bf2));
    __hv_mul_f(VIf(Bf16), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_Yh1CU5cO, VOf(Bf16));
    __hv_rpole_f(&sRPole_y4od3lLR, VIf(Bf2), VIf(Bf16), VOf(Bf16));
    __hv_varread_f(&sVarf_0T93HxmZ, VOf(Bf2));
    __hv_mul_f(VIf(Bf16), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_g2lHkJLb, VOf(Bf16));
    __hv_rpole_f(&sRPole_Gr7onzoU, VIf(Bf2), VIf(Bf16), VOf(Bf16));
    __hv_varread_f(&sVarf_Gcz4I6Xl, VOf(Bf2));
    __hv_mul_f(VIf(Bf16), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_DNLO2Q6E, VOf(Bf16));
    __hv_rpole_f(&sRPole_BYP0Zdhu, VIf(Bf2), VIf(Bf16), VOf(Bf16));
    __hv_tabread_f(&sTabread_zDIEk0mR, VOf(Bf2));
    __hv_varread_f(&sVarf_YcnS4ewy, VOf(Bf5));
    __hv_mul_f(VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_0hSBxe28, VOf(Bf8));
    __hv_rpole_f(&sRPole_jaBpt9ud, VIf(Bf5), VIf(Bf8), VOf(Bf8));
    __hv_sub_f(VIf(Bf8), VIf(Bf2), VOf(Bf8));
    __hv_line_f(&sLine_uC2DT64B, VOf(Bf5));
    __hv_fma_f(VIf(Bf8), VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_line_f(&sLine_uRHIqJbV, VOf(Bf8));
    __hv_tabread_f(&sTabread_Y9CraDEf, VOf(Bf10));
    __hv_add_f(VIf(Bf16), VIf(Bf10), VOf(Bf17));
    __hv_tabread_f(&sTabread_xXzVRiLA, VOf(Bf6));
    __hv_add_f(VIf(Bf17), VIf(Bf6), VOf(Bf7));
    __hv_tabread_f(&sTabread_nDccIDmw, VOf(Bf12));
    __hv_add_f(VIf(Bf7), VIf(Bf12), VOf(Bf18));
    __hv_tabread_f(&sTabread_fNPHlwMm, VOf(Bf11));
    __hv_add_f(VIf(Bf18), VIf(Bf11), VOf(Bf14));
    __hv_tabread_f(&sTabread_O8Nzf9kN, VOf(Bf3));
    __hv_add_f(VIf(Bf14), VIf(Bf3), VOf(Bf13));
    __hv_tabread_f(&sTabread_KTLNUQgj, VOf(Bf19));
    __hv_tabwrite_f(&sTabwrite_npESjic7, VIf(Bf16));
    __hv_sub_f(VIf(Bf16), VIf(Bf10), VOf(Bf10));
    __hv_tabwrite_f(&sTabwrite_UmNdxsVV, VIf(Bf10));
    __hv_sub_f(VIf(Bf18), VIf(Bf11), VOf(Bf11));
    __hv_tabwrite_f(&sTabwrite_qgO6IXfk, VIf(Bf11));
    __hv_sub_f(VIf(Bf7), VIf(Bf12), VOf(Bf12));
    __hv_tabwrite_f(&sTabwrite_SEgP4thX, VIf(Bf12));
    __hv_sub_f(VIf(Bf17), VIf(Bf6), VOf(Bf6));
    __hv_tabwrite_f(&sTabwrite_h4UbNH6N, VIf(Bf6));
    __hv_sub_f(VIf(Bf14), VIf(Bf3), VOf(Bf3));
    __hv_tabwrite_f(&sTabwrite_WNGsvgTv, VIf(Bf3));
    __hv_fma_f(VIf(Bf2), VIf(Bf8), VIf(Bf13), VOf(Bf13));
    __hv_line_f(&sLine_UaDf2nKt, VOf(Bf2));
    __hv_mul_f(VIf(Bf13), VIf(Bf2), VOf(Bf3));
    __hv_tabread_f(&sTabread_287b4oh5, VOf(Bf14));
    __hv_varread_f(&sVarf_e1f2eTK1, VOf(Bf6));
    __hv_mul_f(VIf(Bf14), VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_8luTeCv1, VOf(Bf17));
    __hv_rpole_f(&sRPole_6QmZHFgI, VIf(Bf6), VIf(Bf17), VOf(Bf17));
    __hv_sub_f(VIf(Bf17), VIf(Bf14), VOf(Bf17));
    __hv_fma_f(VIf(Bf17), VIf(Bf5), VIf(Bf14), VOf(Bf14));
    __hv_mul_f(VIf(Bf14), VIf(Bf8), VOf(Bf14));
    __hv_mul_f(VIf(Bf14), VIf(Bf2), VOf(Bf17));
    __hv_tabread_f(&sTabread_fHBE5zox, VOf(Bf6));
    __hv_varread_f(&sVarf_PmTLRsbz, VOf(Bf12));
    __hv_mul_f(VIf(Bf6), VIf(Bf12), VOf(Bf12));
    __hv_varread_f(&sVarf_dwUu67ZV, VOf(Bf7));
    __hv_rpole_f(&sRPole_KnqFbkkZ, VIf(Bf12), VIf(Bf7), VOf(Bf7));
    __hv_sub_f(VIf(Bf7), VIf(Bf6), VOf(Bf7));
    __hv_fma_f(VIf(Bf7), VIf(Bf5), VIf(Bf6), VOf(Bf6));
    __hv_fma_f(VIf(Bf6), VIf(Bf8), VIf(Bf19), VOf(Bf19));
    __hv_mul_f(VIf(Bf19), VIf(Bf2), VOf(Bf6));
    __hv_tabread_f(&sTabread_XgM7MCjD, VOf(Bf7));
    __hv_varread_f(&sVarf_Xpj6GjZf, VOf(Bf12));
    __hv_mul_f(VIf(Bf7), VIf(Bf12), VOf(Bf12));
    __hv_varread_f(&sVarf_JXDtWNO1, VOf(Bf11));
    __hv_rpole_f(&sRPole_lK7oXdFn, VIf(Bf12), VIf(Bf11), VOf(Bf11));
    __hv_sub_f(VIf(Bf11), VIf(Bf7), VOf(Bf11));
    __hv_fma_f(VIf(Bf11), VIf(Bf5), VIf(Bf7), VOf(Bf7));
    __hv_mul_f(VIf(Bf7), VIf(Bf8), VOf(Bf8));
    __hv_mul_f(VIf(Bf8), VIf(Bf2), VOf(Bf2));
    __hv_add_f(VIf(Bf13), VIf(Bf19), VOf(Bf7));
    __hv_add_f(VIf(Bf8), VIf(Bf14), VOf(Bf5));
    __hv_sub_f(VIf(Bf7), VIf(Bf5), VOf(Bf11));
    __hv_tabwrite_f(&sTabwrite_NiAwcgbj, VIf(Bf11));
    __hv_add_f(VIf(Bf7), VIf(Bf5), VOf(Bf5));
    __hv_tabwrite_f(&sTabwrite_bdfczrHz, VIf(Bf5));
    __hv_sub_f(VIf(Bf13), VIf(Bf19), VOf(Bf19));
    __hv_sub_f(VIf(Bf8), VIf(Bf14), VOf(Bf14));
    __hv_sub_f(VIf(Bf19), VIf(Bf14), VOf(Bf8));
    __hv_tabwrite_f(&sTabwrite_eo3i8s4D, VIf(Bf8));
    __hv_add_f(VIf(Bf19), VIf(Bf14), VOf(Bf14));
    __hv_tabwrite_f(&sTabwrite_TvRTzorQ, VIf(Bf14));
    __hv_add_f(VIf(Bf16), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf16), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf3), VIf(Bf16), VOf(Bf16));
    __hv_add_f(VIf(Bf9), VIf(Bf16), VOf(Bf9));
    __hv_add_f(VIf(Bf4), VIf(Bf15), VOf(Bf15));
    __hv_add_f(VIf(Bf15), VIf(Bf16), VOf(Bf16));
    __hv_line_f(&sLine_HUDYAN2U, VOf(Bf15));
    __hv_mul_f(VIf(Bf16), VIf(Bf15), VOf(Bf16));
    __hv_mul_f(VIf(Bf9), VIf(Bf15), VOf(Bf15));
    __hv_add_f(VIf(Bf0), VIf(Bf16), VOf(Bf16));
    __hv_add_f(VIf(Bf1), VIf(Bf15), VOf(Bf15));
    __hv_line_f(&sLine_xVktYncJ, VOf(Bf1));
    __hv_mul_f(VIf(Bf16), VIf(Bf1), VOf(Bf16));
    __hv_mul_f(VIf(Bf15), VIf(Bf1), VOf(Bf1));
    __hv_add_f(VIf(Bf16), VIf(O0), VOf(O0));
    __hv_add_f(VIf(Bf1), VIf(O1), VOf(O1));

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

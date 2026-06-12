/** Copyright (c) 2026 Charles Martin. Generated from Pure Data by hvcc (https://github.com/Wasted-Audio/hvcc). */

#include "Heavy_CircleStrings.hpp"

#include <new>

#define Context(_c) static_cast<Heavy_CircleStrings *>(_c)


/*
 * C Functions
 */

extern "C" {
  HV_EXPORT HeavyContextInterface *hv_CircleStrings_new(double sampleRate) {
    // allocate aligned memory
    void *ptr = hv_malloc(sizeof(Heavy_CircleStrings));
    // ensure non-null
    if (!ptr) return nullptr;
    // call constructor
    new(ptr) Heavy_CircleStrings(sampleRate);
    return Context(ptr);
  }

  HV_EXPORT HeavyContextInterface *hv_CircleStrings_new_with_options(double sampleRate,
      int poolKb, int inQueueKb, int outQueueKb) {
    // allocate aligned memory
    void *ptr = hv_malloc(sizeof(Heavy_CircleStrings));
    // ensure non-null
    if (!ptr) return nullptr;
    // call constructor
    new(ptr) Heavy_CircleStrings(sampleRate, poolKb, inQueueKb, outQueueKb);
    return Context(ptr);
  }

  HV_EXPORT void hv_CircleStrings_free(HeavyContextInterface *instance) {
    // call destructor
    Context(instance)->~Heavy_CircleStrings();
    // free memory
    hv_free(instance);
  }
} // extern "C"







/*
 * Class Functions
 */

Heavy_CircleStrings::Heavy_CircleStrings(double sampleRate, int poolKb, int inQueueKb, int outQueueKb)
    : HeavyContext(sampleRate, poolKb, inQueueKb, outQueueKb) {
  numBytes += sLine_init(&sLine_0dsQpGnI);
  numBytes += sTabread_init(&sTabread_1tQpuqYU, &hTable_NqN4qTjS, true);
  numBytes += sRPole_init(&sRPole_nZHNIorZ);
  numBytes += sTabwrite_init(&sTabwrite_AS9KWVri, &hTable_NqN4qTjS);
  numBytes += sLine_init(&sLine_N1ASNuL6);
  numBytes += sLine_init(&sLine_RXQA5BSx);
  numBytes += sLine_init(&sLine_5DPgijNj);
  numBytes += sLine_init(&sLine_HKrXiEjG);
  numBytes += sPhasor_k_init(&sPhasor_PjKkcAXP, 0.0f, sampleRate);
  numBytes += sLine_init(&sLine_8g7E35J1);
  numBytes += sLine_init(&sLine_ed4dzP1v);
  numBytes += sTabread_init(&sTabread_AYMBNEnS, &hTable_eT9j3lOK, true);
  numBytes += sRPole_init(&sRPole_9J5euM6E);
  numBytes += sTabwrite_init(&sTabwrite_x3Kglaaa, &hTable_eT9j3lOK);
  numBytes += sLine_init(&sLine_hjd1HFtZ);
  numBytes += sLine_init(&sLine_a5hEGEQa);
  numBytes += sLine_init(&sLine_cC3ArdK1);
  numBytes += sPhasor_k_init(&sPhasor_1JMoGwnu, 0.0f, sampleRate);
  numBytes += sTabread_init(&sTabread_mUArOlqK, &hTable_O3JTekn1, true);
  numBytes += sRPole_init(&sRPole_O8wFlPH1);
  numBytes += sLine_init(&sLine_GG7pXXXs);
  numBytes += sTabwrite_init(&sTabwrite_P8WT8aZo, &hTable_O3JTekn1);
  numBytes += sLine_init(&sLine_x3o5SAqa);
  numBytes += sLine_init(&sLine_PLMvWoaK);
  numBytes += sLine_init(&sLine_qkVQcUvG);
  numBytes += sPhasor_k_init(&sPhasor_eqlxABbB, 0.0f, sampleRate);
  numBytes += sLine_init(&sLine_8GBw3dsw);
  numBytes += sPhasor_k_init(&sPhasor_OJjQyx7F, 0.0f, sampleRate);
  numBytes += sTabread_init(&sTabread_kZm1Pjc9, &hTable_cbRKxpD7, true);
  numBytes += sRPole_init(&sRPole_mAE5DoaE);
  numBytes += sLine_init(&sLine_SSzBTeHO);
  numBytes += sTabwrite_init(&sTabwrite_hSX1EpJ3, &hTable_cbRKxpD7);
  numBytes += sLine_init(&sLine_0cjuLgBk);
  numBytes += sLine_init(&sLine_i3VseCms);
  numBytes += sLine_init(&sLine_hq14cxp6);
  numBytes += sLine_init(&sLine_MfDGS6MN);
  numBytes += sLine_init(&sLine_1nmIr3hl);
  numBytes += sTabread_init(&sTabread_OhUPHtZ3, &hTable_PIdkt3iU, true);
  numBytes += sRPole_init(&sRPole_Ihd8rU1e);
  numBytes += sLine_init(&sLine_mkZIaKBk);
  numBytes += sTabwrite_init(&sTabwrite_pU5PGFkG, &hTable_PIdkt3iU);
  numBytes += sLine_init(&sLine_gvPUKwRU);
  numBytes += sLine_init(&sLine_2qlKKPT3);
  numBytes += sRPole_init(&sRPole_3htiXeUO);
  numBytes += sDel1_init(&sDel1_NbBqDxzq);
  numBytes += sLine_init(&sLine_wurxiXrM);
  numBytes += sLine_init(&sLine_b0UNseK8);
  numBytes += sLine_init(&sLine_7GaOmHfc);
  numBytes += sTabread_init(&sTabread_b9nxvE9s, &hTable_sJEcXIKJ, true);
  numBytes += sRPole_init(&sRPole_7AyEZaBn);
  numBytes += sLine_init(&sLine_XmeLOi76);
  numBytes += sLine_init(&sLine_5WnsI5MA);
  numBytes += sTabread_init(&sTabread_JEHCJVUT, &hTable_FjgILMCU, true);
  numBytes += sTabwrite_init(&sTabwrite_cL0rvWDe, &hTable_YgeTeMXQ);
  numBytes += sTabread_init(&sTabread_Ek55gQhE, &hTable_YgeTeMXQ, true);
  numBytes += sTabread_init(&sTabread_by9PCdOX, &hTable_wWU6EClR, true);
  numBytes += sTabread_init(&sTabread_VKRaAijF, &hTable_CuyGdw13, true);
  numBytes += sTabread_init(&sTabread_zRa3O3dH, &hTable_jjcyPKhQ, true);
  numBytes += sTabwrite_init(&sTabwrite_Y52mdAky, &hTable_SCpCTX5W);
  numBytes += sTabwrite_init(&sTabwrite_DuQ4Co8P, &hTable_CuyGdw13);
  numBytes += sTabwrite_init(&sTabwrite_Xj1WGi8h, &hTable_jjcyPKhQ);
  numBytes += sTabwrite_init(&sTabwrite_1KVHmk1a, &hTable_wWU6EClR);
  numBytes += sTabread_init(&sTabread_RkVpHXtZ, &hTable_SCpCTX5W, true);
  numBytes += sTabwrite_init(&sTabwrite_htQtLxlX, &hTable_FjgILMCU);
  numBytes += sLine_init(&sLine_H36ceoic);
  numBytes += sTabread_init(&sTabread_lpFoi13r, &hTable_5CJjcOLl, true);
  numBytes += sRPole_init(&sRPole_GBRJwljZ);
  numBytes += sTabread_init(&sTabread_P9dCtjVF, &hTable_H8kRmOwO, true);
  numBytes += sRPole_init(&sRPole_hwVyjtZq);
  numBytes += sTabread_init(&sTabread_K6hA9yka, &hTable_kORp847N, true);
  numBytes += sRPole_init(&sRPole_DKKp7zqJ);
  numBytes += sTabwrite_init(&sTabwrite_YIMyWBrt, &hTable_H8kRmOwO);
  numBytes += sTabwrite_init(&sTabwrite_5auDYJV3, &hTable_kORp847N);
  numBytes += sTabwrite_init(&sTabwrite_jz3tGdki, &hTable_5CJjcOLl);
  numBytes += sTabwrite_init(&sTabwrite_VY1RJkTf, &hTable_sJEcXIKJ);
  numBytes += sLine_init(&sLine_R8giMv5K);
  numBytes += sTabwrite_init(&sTabwrite_jaHDe3AO, &hTable_tnW6ADwC);
  numBytes += sLine_init(&sLine_jNEN2L4y);
  numBytes += sPhasor_init(&sPhasor_xuydrICF, sampleRate);
  numBytes += sLine_init(&sLine_Zjs9FqzT);
  numBytes += sLine_init(&sLine_g7UWYirp);
  numBytes += sTabhead_init(&sTabhead_MJNcxjkw, &hTable_tnW6ADwC);
  numBytes += sTabread_init(&sTabread_DAvt7Xs9, &hTable_tnW6ADwC, false);
  numBytes += sTabread_init(&sTabread_uBVkCRiQ, &hTable_tnW6ADwC, false);
  numBytes += sTabhead_init(&sTabhead_P90BFdv5, &hTable_tnW6ADwC);
  numBytes += sTabread_init(&sTabread_Y2FvOduF, &hTable_tnW6ADwC, false);
  numBytes += sTabread_init(&sTabread_xPOC5ef1, &hTable_tnW6ADwC, false);
  numBytes += sTabhead_init(&sTabhead_GqodT2DX, &hTable_B9HtbLqp);
  numBytes += sTabread_init(&sTabread_IfLLKxc9, &hTable_B9HtbLqp, false);
  numBytes += sTabread_init(&sTabread_XHTKk4op, &hTable_B9HtbLqp, false);
  numBytes += sRPole_init(&sRPole_4FUA4WJu);
  numBytes += sDel1_init(&sDel1_hNYaEDYq);
  numBytes += sLine_init(&sLine_ZCy7aZjx);
  numBytes += sRPole_init(&sRPole_24AXcYGn);
  numBytes += sTabwrite_init(&sTabwrite_BK4qaso8, &hTable_B9HtbLqp);
  numBytes += sCPole_init(&sCPole_iqvBhV3z);
  numBytes += sRPole_init(&sRPole_OmZlCCDo);
  numBytes += sRPole_init(&sRPole_nNEt7LWg);
  numBytes += sRPole_init(&sRPole_vRGo39Wp);
  numBytes += sTabread_init(&sTabread_WNNBKTF8, &hTable_3uLj1yGs, true);
  numBytes += sRPole_init(&sRPole_ttbo967F);
  numBytes += sLine_init(&sLine_ocji4mRy);
  numBytes += sLine_init(&sLine_42h5BQS2);
  numBytes += sTabread_init(&sTabread_zi5qKH5S, &hTable_ol9BBsMZ, true);
  numBytes += sTabread_init(&sTabread_1zWfMPeG, &hTable_gj6OsYoC, true);
  numBytes += sTabread_init(&sTabread_FN8gdmh3, &hTable_jGl7FP1w, true);
  numBytes += sTabread_init(&sTabread_txETd8q3, &hTable_4R7EzTqJ, true);
  numBytes += sTabwrite_init(&sTabwrite_hN8OanlT, &hTable_GitsKUSa);
  numBytes += sTabwrite_init(&sTabwrite_eOHSLqSm, &hTable_ol9BBsMZ);
  numBytes += sTabread_init(&sTabread_SjcvtXmp, &hTable_GitsKUSa, true);
  numBytes += sTabwrite_init(&sTabwrite_5C2xIvT6, &hTable_pVu6zRuu);
  numBytes += sTabread_init(&sTabread_npp0Yaeg, &hTable_pVu6zRuu, true);
  numBytes += sTabwrite_init(&sTabwrite_8oJgR4mO, &hTable_4R7EzTqJ);
  numBytes += sTabwrite_init(&sTabwrite_Z48GzA0g, &hTable_gj6OsYoC);
  numBytes += sTabwrite_init(&sTabwrite_ObU7iS8U, &hTable_jGl7FP1w);
  numBytes += sTabread_init(&sTabread_0FiP8cTk, &hTable_EB9IrNc4, true);
  numBytes += sRPole_init(&sRPole_zXUnGHfu);
  numBytes += sTabread_init(&sTabread_dcr34w93, &hTable_lA7P06zw, true);
  numBytes += sRPole_init(&sRPole_NAZn8suV);
  numBytes += sTabread_init(&sTabread_VTNOHwN0, &hTable_4ntfDiqh, true);
  numBytes += sRPole_init(&sRPole_94OnbUXN);
  numBytes += sTabwrite_init(&sTabwrite_ThO1TOwi, &hTable_EB9IrNc4);
  numBytes += sLine_init(&sLine_712JpkDm);
  numBytes += sTabwrite_init(&sTabwrite_dYe953Jv, &hTable_lA7P06zw);
  numBytes += sTabwrite_init(&sTabwrite_0cKRKTGy, &hTable_4ntfDiqh);
  numBytes += sTabwrite_init(&sTabwrite_9a733PFq, &hTable_3uLj1yGs);
  numBytes += sLine_init(&sLine_hCMeY2uX);
  numBytes += sLine_init(&sLine_fAgNk4J8);
  numBytes += sPhasor_init(&sPhasor_r445JHJI, sampleRate);
  numBytes += sLine_init(&sLine_sTc6BqLx);
  numBytes += sLine_init(&sLine_qcUSrU6Z);
  numBytes += sTabhead_init(&sTabhead_4RtWN2Qt, &hTable_AqjRr9T6);
  numBytes += sTabread_init(&sTabread_in0hzmeX, &hTable_AqjRr9T6, false);
  numBytes += sTabread_init(&sTabread_7BO4rV4o, &hTable_AqjRr9T6, false);
  numBytes += sTabhead_init(&sTabhead_14U4CHnS, &hTable_AqjRr9T6);
  numBytes += sTabread_init(&sTabread_h0wsmpkg, &hTable_AqjRr9T6, false);
  numBytes += sTabread_init(&sTabread_WAwZ9L2D, &hTable_AqjRr9T6, false);
  numBytes += sTabwrite_init(&sTabwrite_3GxKA1rk, &hTable_AqjRr9T6);
  numBytes += sLine_init(&sLine_Ym6UThys);
  numBytes += sTabhead_init(&sTabhead_q7maaBgK, &hTable_JrchviHR);
  numBytes += sTabread_init(&sTabread_IvnndJbs, &hTable_JrchviHR, false);
  numBytes += sTabread_init(&sTabread_OThuKwfY, &hTable_JrchviHR, false);
  numBytes += sRPole_init(&sRPole_7i4fmIt3);
  numBytes += sDel1_init(&sDel1_JJHQ6Y0n);
  numBytes += sRPole_init(&sRPole_SogwJHsO);
  numBytes += sTabwrite_init(&sTabwrite_KGSvr8CU, &hTable_JrchviHR);
  numBytes += sLine_init(&sLine_RbG2TLPM);
  numBytes += sLine_init(&sLine_PiSlEksa);
  numBytes += cSlice_init(&cSlice_d7xusZhg, 2, 1);
  numBytes += cSlice_init(&cSlice_Kgr6aHNB, 1, 1);
  numBytes += cSlice_init(&cSlice_9zhNSftQ, 0, 1);
  numBytes += cVar_init_f(&cVar_p2n5RL08, 0.0f);
  numBytes += cIf_init(&cIf_znGAkzjR, false);
  numBytes += cIf_init(&cIf_3cUzpd2y, false);
  numBytes += cIf_init(&cIf_lT3yyo1g, false);
  numBytes += cIf_init(&cIf_nb6VTrFm, false);
  numBytes += cIf_init(&cIf_cKRqcgtb, false);
  numBytes += cBinop_init(&cBinop_mufoUR7L, 0.0f); // __eq
  numBytes += cTabhead_init(&cTabhead_ltGKqveF, &hTable_sJEcXIKJ);
  numBytes += cVar_init_s(&cVar_NsY2i96y, "del-1011-del1");
  numBytes += cDelay_init(this, &cDelay_Zs6V39RZ, 58.6435f);
  numBytes += cDelay_init(this, &cDelay_5b8HQKK4, 0.0f);
  numBytes += cBinop_init(&cBinop_BcSVFyaO, 58.6435f); // __mul
  numBytes += cBinop_init(&cBinop_mwUeFqx8, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_ZCwEjOv8, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_SDREH4oa, 0.0f); // __sub
  numBytes += cTabhead_init(&cTabhead_LfgILtky, &hTable_H8kRmOwO);
  numBytes += cVar_init_s(&cVar_Blp9Dv7H, "del-1011-del2");
  numBytes += cDelay_init(this, &cDelay_jwDOOfEW, 69.4325f);
  numBytes += cDelay_init(this, &cDelay_FW9oIWzr, 0.0f);
  numBytes += cBinop_init(&cBinop_8EDJoabJ, 69.4325f); // __mul
  numBytes += cBinop_init(&cBinop_eYfmPTZr, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_zaKDLKho, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_yXJmAi9R, 0.0f); // __sub
  numBytes += cTabhead_init(&cTabhead_4a2HeR3f, &hTable_5CJjcOLl);
  numBytes += cVar_init_s(&cVar_loNtNfT3, "del-1011-del3");
  numBytes += cDelay_init(this, &cDelay_GWsX44wA, 74.5234f);
  numBytes += cDelay_init(this, &cDelay_cdkwasPa, 0.0f);
  numBytes += cBinop_init(&cBinop_4rBvr7Uc, 74.5234f); // __mul
  numBytes += cBinop_init(&cBinop_1G8QLz2k, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_4Zy7imgy, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_wm7JtPMK, 0.0f); // __sub
  numBytes += cTabhead_init(&cTabhead_NIYmTsXC, &hTable_kORp847N);
  numBytes += cVar_init_s(&cVar_iWnY6XFK, "del-1011-del4");
  numBytes += cDelay_init(this, &cDelay_XSnpUi0o, 86.1244f);
  numBytes += cDelay_init(this, &cDelay_PkQ4FZ9V, 0.0f);
  numBytes += cBinop_init(&cBinop_I80szfDg, 86.1244f); // __mul
  numBytes += cBinop_init(&cBinop_8DnEodvj, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_2r46FSc4, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_vXq9ty0r, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_qRRLSX7s, 0.0f);
  numBytes += cDelay_init(this, &cDelay_j8wxsOsu, 0.0f);
  numBytes += hTable_init(&hTable_sJEcXIKJ, 256);
  numBytes += cDelay_init(this, &cDelay_KCpVTC3G, 0.0f);
  numBytes += cDelay_init(this, &cDelay_RyS40cLD, 0.0f);
  numBytes += hTable_init(&hTable_H8kRmOwO, 256);
  numBytes += cDelay_init(this, &cDelay_DHkTv6Pi, 0.0f);
  numBytes += cDelay_init(this, &cDelay_cAPdStYy, 0.0f);
  numBytes += hTable_init(&hTable_5CJjcOLl, 256);
  numBytes += cDelay_init(this, &cDelay_9pwok4AD, 0.0f);
  numBytes += cDelay_init(this, &cDelay_BK6RvTp7, 0.0f);
  numBytes += hTable_init(&hTable_kORp847N, 256);
  numBytes += cIf_init(&cIf_nwiihNwk, false);
  numBytes += cBinop_init(&cBinop_8laCWeg3, 0.0f); // __pow
  numBytes += cPack_init(&cPack_ikjnkobH, 2, 0.0f, 30.0f);
  numBytes += cPack_init(&cPack_i0Fw54NV, 2, 0.0f, 50.0f);
  numBytes += cVar_init_f(&cVar_6y7ZfPLz, 22050.0f);
  numBytes += cBinop_init(&cBinop_C95KwuAg, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_Vl79vFoh, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_wTx0vRDP, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_grbSjNXQ, 95.0f);
  numBytes += cVar_init_f(&cVar_v003oDpw, 90.0f);
  numBytes += cVar_init_f(&cVar_1HRfmt7H, 6000.0f);
  numBytes += cVar_init_f(&cVar_WR1HmUul, 60.0f);
  numBytes += cIf_init(&cIf_93bL39Gx, false);
  numBytes += cTabhead_init(&cTabhead_bO3qviwg, &hTable_SCpCTX5W);
  numBytes += cVar_init_s(&cVar_Jw3CfAGI, "del-1011-ref6");
  numBytes += cDelay_init(this, &cDelay_1AhfLDul, 13.645f);
  numBytes += cDelay_init(this, &cDelay_Tp24SHiq, 0.0f);
  numBytes += cBinop_init(&cBinop_WA1JyZAo, 13.645f); // __mul
  numBytes += cBinop_init(&cBinop_N8pmwXwC, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_cOg55uJD, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_6C9Y56FE, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_tGPSqibE, 0.0f);
  numBytes += cDelay_init(this, &cDelay_BnqGkGiZ, 0.0f);
  numBytes += hTable_init(&hTable_SCpCTX5W, 256);
  numBytes += cTabhead_init(&cTabhead_9QxNZraR, &hTable_jjcyPKhQ);
  numBytes += cVar_init_s(&cVar_mTdviuQV, "del-1011-ref5");
  numBytes += cDelay_init(this, &cDelay_rFEM6vr5, 16.364f);
  numBytes += cDelay_init(this, &cDelay_Q08XYhLX, 0.0f);
  numBytes += cBinop_init(&cBinop_PSPF92vu, 16.364f); // __mul
  numBytes += cBinop_init(&cBinop_OTsyF41f, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_mvQBI5qV, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_WkLBgba0, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_Q5NDGwoX, 0.0f);
  numBytes += cDelay_init(this, &cDelay_AaZPXpPP, 0.0f);
  numBytes += hTable_init(&hTable_jjcyPKhQ, 256);
  numBytes += cTabhead_init(&cTabhead_3OjGBzpx, &hTable_CuyGdw13);
  numBytes += cVar_init_s(&cVar_0u2RV7S3, "del-1011-ref4");
  numBytes += cDelay_init(this, &cDelay_Syd36h5d, 19.392f);
  numBytes += cDelay_init(this, &cDelay_fGb2QLGv, 0.0f);
  numBytes += cBinop_init(&cBinop_zldvKZTW, 19.392f); // __mul
  numBytes += cBinop_init(&cBinop_KxDKiHt2, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_ffLmpw6C, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_IbtYV3Po, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_CHWKAnDn, 0.0f);
  numBytes += cDelay_init(this, &cDelay_HONBMz3P, 0.0f);
  numBytes += hTable_init(&hTable_CuyGdw13, 256);
  numBytes += cTabhead_init(&cTabhead_Nh0FxNNP, &hTable_wWU6EClR);
  numBytes += cVar_init_s(&cVar_EKfRxP7g, "del-1011-ref3");
  numBytes += cDelay_init(this, &cDelay_gFpHcb3T, 25.796f);
  numBytes += cDelay_init(this, &cDelay_Hk9FP7Op, 0.0f);
  numBytes += cBinop_init(&cBinop_D9DIelR2, 25.796f); // __mul
  numBytes += cBinop_init(&cBinop_SoHFXhRG, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_6F176PMn, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_0bUP7BVu, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_8ZH2SyPE, 0.0f);
  numBytes += cDelay_init(this, &cDelay_CzagagvU, 0.0f);
  numBytes += hTable_init(&hTable_wWU6EClR, 256);
  numBytes += cTabhead_init(&cTabhead_UyoDPMGJ, &hTable_YgeTeMXQ);
  numBytes += cVar_init_s(&cVar_FiQfUHSQ, "del-1011-ref2");
  numBytes += cDelay_init(this, &cDelay_8JzNrnfB, 43.5337f);
  numBytes += cDelay_init(this, &cDelay_ecfwyPAy, 0.0f);
  numBytes += cBinop_init(&cBinop_7Z4Qgs9V, 43.5337f); // __mul
  numBytes += cBinop_init(&cBinop_QQtVEHLI, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_i4DLWeZ5, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_miWQIbJZ, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_kIgi2xU2, 0.0f);
  numBytes += cDelay_init(this, &cDelay_s8wGxbaa, 0.0f);
  numBytes += hTable_init(&hTable_YgeTeMXQ, 256);
  numBytes += cTabhead_init(&cTabhead_wZzXg9rX, &hTable_FjgILMCU);
  numBytes += cVar_init_s(&cVar_PIW25mD4, "del-1011-ref1");
  numBytes += cDelay_init(this, &cDelay_IQCLN9v9, 75.2546f);
  numBytes += cDelay_init(this, &cDelay_O56yWMaQ, 0.0f);
  numBytes += cBinop_init(&cBinop_iOKitXNS, 75.2546f); // __mul
  numBytes += cBinop_init(&cBinop_yDNqQqM2, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_dgppUsZb, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_D2mqMoBp, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_utv2W3am, 0.0f);
  numBytes += cDelay_init(this, &cDelay_5gsfKLgn, 0.0f);
  numBytes += hTable_init(&hTable_FjgILMCU, 256);
  numBytes += cVar_init_f(&cVar_CBgxWohu, 0.0f);
  numBytes += cVar_init_f(&cVar_y3AuMYvo, 0.0f);
  numBytes += cPack_init(&cPack_WoUl5Yx9, 2, 0.0f, 50.0f);
  numBytes += cVar_init_f(&cVar_B9lh18dH, 22050.0f);
  numBytes += cBinop_init(&cBinop_mKIAIItc, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_WG3C307I, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_860e0l7y, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_KAwev9r0, 22050.0f);
  numBytes += cBinop_init(&cBinop_KRp8pmio, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_9OHNYlIA, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_lF5sp862, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_xo4XpkPP, 22050.0f);
  numBytes += cBinop_init(&cBinop_iA7e4URh, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_U6Cak3ak, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_q9SGrCCg, 0.0f, 0.0f, false);
  numBytes += cIf_init(&cIf_C1Nlw5Ns, false);
  numBytes += cDelay_init(this, &cDelay_qDqClzAx, 50.0f);
  numBytes += cVar_init_f(&cVar_A6KZg1dy, 0.0f);
  numBytes += cVar_init_f(&cVar_qb95DYXu, 12.0f);
  numBytes += cVar_init_s(&cVar_KLZkdgi7, "floatatom");
  numBytes += cPack_init(&cPack_J8JZdbvU, 2, 0.0f, 200.0f);
  numBytes += cPack_init(&cPack_Bm2na9Hr, 2, 0.0f, 200.0f);
  numBytes += cVar_init_s(&cVar_YcguvhNs, "floatatom");
  numBytes += cDelay_init(this, &cDelay_sPflUa3J, 0.0f);
  numBytes += cDelay_init(this, &cDelay_hr8blEMd, 0.0f);
  numBytes += hTable_init(&hTable_tnW6ADwC, 256);
  numBytes += cVar_init_s(&cVar_SQmYneZy, "del-1118-del");
  numBytes += sVarf_init(&sVarf_SjQDEIQP, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_uaxbfDFT, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_a8pHdRg6, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_1RvtilXu, "del-1118-del");
  numBytes += sVarf_init(&sVarf_PZMNAqEr, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_NVI6Rosk, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_p7m8FVpp, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_SetbxVoN, 0.0f); // __div
  numBytes += cVar_init_f(&cVar_f9KMTLD9, 4720.0f);
  numBytes += cBinop_init(&cBinop_s5UZrpvX, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_bsg0dBcj, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_ShZv1Lle, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_Fg3xBIla, 4720.0f);
  numBytes += cBinop_init(&cBinop_TptFb9TS, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_aUz0qpbc, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_SYo7JBP8, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_iAkocxD1, 4720.0f);
  numBytes += cBinop_init(&cBinop_0YvZBbQL, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_M7lbaMq5, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_1xlzEFn0, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_AMuFTtd3, 1.0f);
  numBytes += cIf_init(&cIf_Q3VbGReb, false);
  numBytes += sVarf_init(&sVarf_gc3U5FB3, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_try9M9ry, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_LjOibelc, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_u3MxHD1B, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_skOQJWLV, 4720.0f, 0.0f, false);
  numBytes += cTabhead_init(&cTabhead_P3wS8A0I, &hTable_3uLj1yGs);
  numBytes += cVar_init_s(&cVar_X9zKhtxI, "del-1181-del1");
  numBytes += cDelay_init(this, &cDelay_JyssfCSo, 58.6435f);
  numBytes += cDelay_init(this, &cDelay_BqXxqAAL, 0.0f);
  numBytes += cBinop_init(&cBinop_PXFF8jUh, 58.6435f); // __mul
  numBytes += cBinop_init(&cBinop_awJtMi5f, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_MEzGKBmE, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_bQmEHkS3, 0.0f); // __sub
  numBytes += cTabhead_init(&cTabhead_25RelK01, &hTable_EB9IrNc4);
  numBytes += cVar_init_s(&cVar_cbViQofB, "del-1181-del2");
  numBytes += cDelay_init(this, &cDelay_iTXLVM62, 69.4325f);
  numBytes += cDelay_init(this, &cDelay_pihtF4GQ, 0.0f);
  numBytes += cBinop_init(&cBinop_dw3iN5tH, 69.4325f); // __mul
  numBytes += cBinop_init(&cBinop_B7xEYXrU, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_NKIP7EOa, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_zR9EQkhP, 0.0f); // __sub
  numBytes += cTabhead_init(&cTabhead_HiWl0REH, &hTable_lA7P06zw);
  numBytes += cVar_init_s(&cVar_CmamotMH, "del-1181-del3");
  numBytes += cDelay_init(this, &cDelay_kfFWMzzl, 74.5234f);
  numBytes += cDelay_init(this, &cDelay_IVZ00RuP, 0.0f);
  numBytes += cBinop_init(&cBinop_BYScuqZB, 74.5234f); // __mul
  numBytes += cBinop_init(&cBinop_gjxfcIYu, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_6vXGL26j, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_29D7opEz, 0.0f); // __sub
  numBytes += cTabhead_init(&cTabhead_6yp286bY, &hTable_4ntfDiqh);
  numBytes += cVar_init_s(&cVar_58IFI2fq, "del-1181-del4");
  numBytes += cDelay_init(this, &cDelay_nkhruJbv, 86.1244f);
  numBytes += cDelay_init(this, &cDelay_u6b8GX5M, 0.0f);
  numBytes += cBinop_init(&cBinop_jOZg8GKF, 86.1244f); // __mul
  numBytes += cBinop_init(&cBinop_w4V5NSG4, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_pQQ01gwp, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_KfXKcftt, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_YCkBOnJH, 0.0f);
  numBytes += cDelay_init(this, &cDelay_kLk2DX0g, 0.0f);
  numBytes += hTable_init(&hTable_3uLj1yGs, 256);
  numBytes += cDelay_init(this, &cDelay_opGfbWxa, 0.0f);
  numBytes += cDelay_init(this, &cDelay_yvYu2VI0, 0.0f);
  numBytes += hTable_init(&hTable_EB9IrNc4, 256);
  numBytes += cDelay_init(this, &cDelay_TuXtPgx8, 0.0f);
  numBytes += cDelay_init(this, &cDelay_rwOMuyMM, 0.0f);
  numBytes += hTable_init(&hTable_lA7P06zw, 256);
  numBytes += cDelay_init(this, &cDelay_AOmra5OL, 0.0f);
  numBytes += cDelay_init(this, &cDelay_BWObrq2f, 0.0f);
  numBytes += hTable_init(&hTable_4ntfDiqh, 256);
  numBytes += cIf_init(&cIf_iAvcC65A, false);
  numBytes += cBinop_init(&cBinop_PbTS2Ewa, 0.0f); // __pow
  numBytes += cPack_init(&cPack_X0Iep43f, 2, 0.0f, 30.0f);
  numBytes += cPack_init(&cPack_MlACp4XR, 2, 0.0f, 50.0f);
  numBytes += cVar_init_f(&cVar_b5xo0pt9, 22050.0f);
  numBytes += cBinop_init(&cBinop_iE7W71iG, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_rDMUqotd, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_dd13PCu6, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_lJepFRYJ, 100.0f);
  numBytes += cVar_init_f(&cVar_pperUyEz, 95.0f);
  numBytes += cVar_init_f(&cVar_rKRrml5M, 14400.0f);
  numBytes += cVar_init_f(&cVar_Aq4Yg5j6, 60.0f);
  numBytes += cIf_init(&cIf_vPLNdTco, false);
  numBytes += cTabhead_init(&cTabhead_wfU15qxn, &hTable_pVu6zRuu);
  numBytes += cVar_init_s(&cVar_8l70VoDY, "del-1181-ref6");
  numBytes += cDelay_init(this, &cDelay_ZSUDazh3, 13.645f);
  numBytes += cDelay_init(this, &cDelay_ZHoK3by3, 0.0f);
  numBytes += cBinop_init(&cBinop_DNX0xulF, 13.645f); // __mul
  numBytes += cBinop_init(&cBinop_gAyoEMk9, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_JIm1oOiy, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_u7QN2xJi, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_MpVWtaZl, 0.0f);
  numBytes += cDelay_init(this, &cDelay_riC9r37s, 0.0f);
  numBytes += hTable_init(&hTable_pVu6zRuu, 256);
  numBytes += cTabhead_init(&cTabhead_yFuq8aMY, &hTable_GitsKUSa);
  numBytes += cVar_init_s(&cVar_6fo4mxtY, "del-1181-ref5");
  numBytes += cDelay_init(this, &cDelay_sYDF6GMc, 16.364f);
  numBytes += cDelay_init(this, &cDelay_A7fLHo8f, 0.0f);
  numBytes += cBinop_init(&cBinop_zWOm0NvF, 16.364f); // __mul
  numBytes += cBinop_init(&cBinop_iMw3JeXZ, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_lyqlEnL0, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_LMzhOrc9, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_EZO2ulb3, 0.0f);
  numBytes += cDelay_init(this, &cDelay_0Xil5ykm, 0.0f);
  numBytes += hTable_init(&hTable_GitsKUSa, 256);
  numBytes += cTabhead_init(&cTabhead_7KT9OKCK, &hTable_4R7EzTqJ);
  numBytes += cVar_init_s(&cVar_uWoGdxz8, "del-1181-ref4");
  numBytes += cDelay_init(this, &cDelay_AbpexQkF, 19.392f);
  numBytes += cDelay_init(this, &cDelay_iBt5GdZD, 0.0f);
  numBytes += cBinop_init(&cBinop_MYoPVutt, 19.392f); // __mul
  numBytes += cBinop_init(&cBinop_zFqHlvUz, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_VKfvcohg, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_QO7efEPb, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_vxe9ASrU, 0.0f);
  numBytes += cDelay_init(this, &cDelay_rfudklBv, 0.0f);
  numBytes += hTable_init(&hTable_4R7EzTqJ, 256);
  numBytes += cTabhead_init(&cTabhead_VRPF9nBu, &hTable_jGl7FP1w);
  numBytes += cVar_init_s(&cVar_qvgNlC3p, "del-1181-ref3");
  numBytes += cDelay_init(this, &cDelay_mgCSkaRN, 25.796f);
  numBytes += cDelay_init(this, &cDelay_gAE6182y, 0.0f);
  numBytes += cBinop_init(&cBinop_5Ii7hl0X, 25.796f); // __mul
  numBytes += cBinop_init(&cBinop_sPFRkvK8, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_IFEzmF3u, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_eYXQ5pp9, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_AsP7uNbU, 0.0f);
  numBytes += cDelay_init(this, &cDelay_l3q2gskJ, 0.0f);
  numBytes += hTable_init(&hTable_jGl7FP1w, 256);
  numBytes += cTabhead_init(&cTabhead_1cNTgzpa, &hTable_gj6OsYoC);
  numBytes += cVar_init_s(&cVar_DRyTmypg, "del-1181-ref2");
  numBytes += cDelay_init(this, &cDelay_ZAde0uvt, 43.5337f);
  numBytes += cDelay_init(this, &cDelay_A2RYvPhE, 0.0f);
  numBytes += cBinop_init(&cBinop_TUpLUGrK, 43.5337f); // __mul
  numBytes += cBinop_init(&cBinop_OVGgm29j, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_ulUdFhXJ, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_fSMJ017l, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_WpqKENNZ, 0.0f);
  numBytes += cDelay_init(this, &cDelay_0ZnGXISG, 0.0f);
  numBytes += hTable_init(&hTable_gj6OsYoC, 256);
  numBytes += cTabhead_init(&cTabhead_uXyHDKNL, &hTable_ol9BBsMZ);
  numBytes += cVar_init_s(&cVar_uqKw2Zl3, "del-1181-ref1");
  numBytes += cDelay_init(this, &cDelay_yR5V08aK, 75.2546f);
  numBytes += cDelay_init(this, &cDelay_wBJ2wuYL, 0.0f);
  numBytes += cBinop_init(&cBinop_FzsrQbSV, 75.2546f); // __mul
  numBytes += cBinop_init(&cBinop_0PkkEWUW, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_I7QpVyNi, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_J7ZDY3O4, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_8O9LuJpY, 0.0f);
  numBytes += cDelay_init(this, &cDelay_0Nvf26kC, 0.0f);
  numBytes += hTable_init(&hTable_ol9BBsMZ, 256);
  numBytes += cVar_init_f(&cVar_pAcmyTme, 0.0f);
  numBytes += cVar_init_f(&cVar_jxvmbT3n, 0.0f);
  numBytes += cPack_init(&cPack_nnJOliZ3, 2, 0.0f, 50.0f);
  numBytes += cVar_init_f(&cVar_Pr8OI5bX, 22050.0f);
  numBytes += cBinop_init(&cBinop_GdRaLxL9, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_31CMeTHu, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_ai1jlsln, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_LP6LfgeT, 22050.0f);
  numBytes += cBinop_init(&cBinop_dIkB0qZx, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_ytLJqOZ1, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_fO5JNITB, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_8gEUlKK0, 22050.0f);
  numBytes += cBinop_init(&cBinop_S97a2am2, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_yozXBuwp, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_7ceypeny, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_IGYRqCHB, "del-1280-del1");
  numBytes += sVarf_init(&sVarf_IK0GYyj3, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_EdYNnOyL, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_rlBUEcPD, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_2BrxM752, 10000.0f);
  numBytes += cBinop_init(&cBinop_9DhEmGRi, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_wxEDt9Ux, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_vRSPZDVu, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_tFkk8usR, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_Aif40NUS, 10.0f);
  numBytes += cBinop_init(&cBinop_snxSGQG0, 0.0f); // __div
  numBytes += sVarf_init(&sVarf_bialIhQG, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_qUYSyPZN, "floatatom");
  numBytes += sVarf_init(&sVarf_cLYSr7VT, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_4vUxNJI0, 0.0f);
  numBytes += cDelay_init(this, &cDelay_DbKD5tga, 0.0f);
  numBytes += hTable_init(&hTable_B9HtbLqp, 256);
  numBytes += sVarf_init(&sVarf_FiECT7xg, 0.0f, 0.0f, false);
  numBytes += cPack_init(&cPack_oxCIdad0, 2, 0.0f, 50.0f);
  numBytes += cRandom_init(&cRandom_fKzgxDLi, 1479280588);
  numBytes += cSlice_init(&cSlice_GzHvjv97, 1, 1);
  numBytes += cRandom_init(&cRandom_QG8NKBLQ, 1107905724);
  numBytes += cSlice_init(&cSlice_ELhLweBN, 1, 1);
  numBytes += cVar_init_s(&cVar_cSpdssHy, "floatatom");
  numBytes += cPack_init(&cPack_BeuYz5E4, 2, 0.0f, 200.0f);
  numBytes += cPack_init(&cPack_CiXymxDq, 2, 0.0f, 200.0f);
  numBytes += cVar_init_s(&cVar_Yuro5TVF, "floatatom");
  numBytes += cDelay_init(this, &cDelay_Zsz4O5GY, 0.0f);
  numBytes += cDelay_init(this, &cDelay_R7yBtNwC, 0.0f);
  numBytes += hTable_init(&hTable_AqjRr9T6, 256);
  numBytes += cVar_init_s(&cVar_vt9w4O4j, "del-1311-del");
  numBytes += sVarf_init(&sVarf_W11bjtXS, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_dpHMaRhP, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_dkYaFM5l, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_rojQnTDl, "del-1311-del");
  numBytes += sVarf_init(&sVarf_spQtVZmT, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_ck3bw49y, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_JjPn5IOz, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_QbyCwXpt, 0.0f); // __div
  numBytes += cVar_init_s(&cVar_5dA5ApPk, "del-1340-del1");
  numBytes += sVarf_init(&sVarf_bIrObFVg, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_wg5Ri9dn, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_c4leJELR, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_7bCdvUh8, 10000.0f);
  numBytes += cBinop_init(&cBinop_1eZbcsbi, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_2VhQ4WkQ, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_icAuhuKv, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_RQZ3wiSK, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_1NcaJMVb, 10.0f);
  numBytes += cBinop_init(&cBinop_X201DATz, 0.0f); // __div
  numBytes += sVarf_init(&sVarf_NSwYS34I, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_Z9aUjTyP, "floatatom");
  numBytes += sVarf_init(&sVarf_N3IEEdKO, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_gvmCffhO, 0.0f);
  numBytes += cDelay_init(this, &cDelay_nB1GMieL, 0.0f);
  numBytes += hTable_init(&hTable_JrchviHR, 256);
  numBytes += sVarf_init(&sVarf_CSoM9oba, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_JwBexB85, "floatatom");
  numBytes += cDelay_init(this, &cDelay_il4LWkq0, 0.0f);
  numBytes += cVar_init_f(&cVar_gnDhbVDa, 20.0f);
  numBytes += cBinop_init(&cBinop_doMSd0Oj, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_Yi2fYugt, 0.0f);
  numBytes += cSlice_init(&cSlice_t8WTNE9t, 1, -1);
  numBytes += cSlice_init(&cSlice_DirdSHXo, 1, -1);
  numBytes += cVar_init_f(&cVar_6rLWcSea, 0.0f);
  numBytes += cVar_init_f(&cVar_238LxNEE, 20.0f);
  numBytes += cVar_init_f(&cVar_Yh1dqw45, 0.0f);
  numBytes += cVar_init_f(&cVar_62CevhwS, 0.0f);
  numBytes += cVar_init_f(&cVar_VBDFD3YF, 0.0f);
  numBytes += cSlice_init(&cSlice_1Py2yTMC, 1, 1);
  numBytes += cSlice_init(&cSlice_NJ9KnpUt, 0, 1);
  numBytes += cBinop_init(&cBinop_8XHN97hN, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_6ZJMZDJW, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_4XcB2edl, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_aXleD2RC, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_QZpIx2bq, 20.0f); // __div
  numBytes += cBinop_init(&cBinop_ZjcSTAe1, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_ZhjAi2ej, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_k8AwyJ1I, 0.0f); // __sub
  numBytes += cVar_init_s(&cVar_RQwqhkkt, "floatatom");
  numBytes += cPack_init(&cPack_Dmc8PtT0, 2, 0.0f, 1000.0f);
  numBytes += cDelay_init(this, &cDelay_fcdgcocD, 0.0f);
  numBytes += cVar_init_f(&cVar_HAXQFBT5, 20.0f);
  numBytes += cBinop_init(&cBinop_GIAYxKKz, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_76coh6S2, 0.0f);
  numBytes += cSlice_init(&cSlice_cv3N4r9v, 1, -1);
  numBytes += cSlice_init(&cSlice_znm6BWKu, 1, -1);
  numBytes += cVar_init_f(&cVar_ldkkKk4Z, 0.0f);
  numBytes += cVar_init_f(&cVar_J3MpXBud, 20.0f);
  numBytes += cVar_init_f(&cVar_eP92M7yI, 0.0f);
  numBytes += cVar_init_f(&cVar_aHM5gk3P, 0.0f);
  numBytes += cVar_init_f(&cVar_MHDSXfwo, 0.0f);
  numBytes += cSlice_init(&cSlice_RnWaeGkw, 1, 1);
  numBytes += cSlice_init(&cSlice_ku6PHOvt, 0, 1);
  numBytes += cBinop_init(&cBinop_3gKYUMQj, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_rFv6MvVK, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_b9sOQFW1, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_zFNBDphz, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_7lfxwfbV, 20.0f); // __div
  numBytes += cBinop_init(&cBinop_fDYrPmO6, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_jrZYpSjt, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_jfIzGcEn, 0.0f); // __sub
  numBytes += cPack_init(&cPack_NtnZNmNh, 2, 0.0f, 1000.0f);
  numBytes += cPack_init(&cPack_iufSNh34, 2, 0.0f, 1000.0f);
  numBytes += sVarf_init(&sVarf_iTQ4HjJE, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_jiPKR3cA, 5.0f);
  numBytes += cBinop_init(&cBinop_LPTJYrUI, 0.0f); // __div
  numBytes += sVarf_init(&sVarf_5VoUMfdc, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_7mffYINl, "floatatom");
  numBytes += cIf_init(&cIf_TbXZlErM, false);
  numBytes += cIf_init(&cIf_YVE7kUDu, false);
  numBytes += cIf_init(&cIf_Vm0EydV4, false);
  numBytes += cIf_init(&cIf_n9cLGTFg, false);
  numBytes += cRandom_init(&cRandom_5hyFNydj, -341142462);
  numBytes += cSlice_init(&cSlice_oNST9V0A, 1, 1);
  numBytes += sVari_init(&sVari_kCCmHSeE, 0, 0, false);
  numBytes += cTabhead_init(&cTabhead_nsk9h2Kd, &hTable_PIdkt3iU);
  numBytes += cVar_init_s(&cVar_1pKxZobp, "del-1418-delay");
  numBytes += cDelay_init(this, &cDelay_fb0luNIj, 12.0f);
  numBytes += cDelay_init(this, &cDelay_ZiHqnTvy, 0.0f);
  numBytes += cBinop_init(&cBinop_Xtb8SrTU, 12.0f); // __mul
  numBytes += cBinop_init(&cBinop_DxMYHb9u, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_LxI1HyGl, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_kwlF7ACw, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_5RfiQwE1, 1.0f); // __pow
  numBytes += cVar_init_s(&cVar_23FcSf5Q, "floatatom");
  numBytes += cDelay_init(this, &cDelay_fCvW9xy6, 5.0f);
  numBytes += cVar_init_f(&cVar_TLSoiMLz, 3800.0f);
  numBytes += cBinop_init(&cBinop_Gbk1u9VD, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_C0bo0SDW, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_pYiV6Nwb, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_oU5jd6Mx, 0.0f);
  numBytes += cDelay_init(this, &cDelay_c2YzKxNd, 0.0f);
  numBytes += hTable_init(&hTable_PIdkt3iU, 256);
  numBytes += cBinop_init(&cBinop_dkNKq0h2, 0.0f); // __div
  numBytes += sVarf_init(&sVarf_r00vRbTY, 0.999f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_iiz5HAMK, 1.0f);
  numBytes += cDelay_init(this, &cDelay_cQJWnIZi, 0.0f);
  numBytes += cVar_init_f(&cVar_ncAXTAcc, 2000.0f);
  numBytes += cBinop_init(&cBinop_qGYudbvd, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_nBGSYJ0W, 60.0f);
  numBytes += cRandom_init(&cRandom_Ooqb3idw, -1035444672);
  numBytes += cSlice_init(&cSlice_l3aBboEX, 1, 1);
  numBytes += cVar_init_f(&cVar_9gJUbDqP, 0.0f);
  numBytes += cIf_init(&cIf_EOLlZAv8, false);
  numBytes += cIf_init(&cIf_w1bg1GGg, false);
  numBytes += cIf_init(&cIf_GfX4fkhS, false);
  numBytes += cIf_init(&cIf_JXVsuz09, false);
  numBytes += cPack_init(&cPack_ghqsILSs, 2, 0.0f, 50.0f);
  numBytes += cPack_init(&cPack_HGvb5mmk, 2, 0.0f, 80.0f);
  numBytes += cVar_init_s(&cVar_er8X9uCw, "floatatom");
  numBytes += cRandom_init(&cRandom_4obOa0kA, 48424560);
  numBytes += cSlice_init(&cSlice_rnZmDjgm, 1, 1);
  numBytes += cVar_init_s(&cVar_DOoKdRAh, "floatatom");
  numBytes += cVar_init_f(&cVar_bEmZWMZJ, 1.0f);
  numBytes += cVar_init_f(&cVar_lTeED9sX, 0.0f);
  numBytes += cVar_init_f(&cVar_mE9m3qhV, 0.0f);
  numBytes += cRandom_init(&cRandom_qnDRqHnS, -408304770);
  numBytes += cSlice_init(&cSlice_NG3d9ZnJ, 1, 1);
  numBytes += cRandom_init(&cRandom_GXgnaMbL, 1218905658);
  numBytes += cSlice_init(&cSlice_CO7YXtmN, 1, 1);
  numBytes += cRandom_init(&cRandom_ISAfihpm, -844765408);
  numBytes += cSlice_init(&cSlice_4CYpXA4h, 1, 1);
  numBytes += cBinop_init(&cBinop_ReMkE8IC, 1.0f); // __pow
  numBytes += cRandom_init(&cRandom_ya0dsmAJ, -100515316);
  numBytes += cSlice_init(&cSlice_58JQAKg4, 1, 1);
  numBytes += cPack_init(&cPack_woqQOB8x, 2, 0.0f, 50.0f);
  numBytes += cVar_init_s(&cVar_UXqANjUW, "floatatom");
  numBytes += cVar_init_s(&cVar_fIVeAPPf, "floatatom");
  numBytes += cVar_init_f(&cVar_nwh7cDmd, 0.0f);
  numBytes += cVar_init_s(&cVar_Gcz4I6Xl, "floatatom");
  numBytes += cVar_init_s(&cVar_Nx51nojH, "floatatom");
  numBytes += cVar_init_s(&cVar_KiuVBcpA, "floatatom");
  numBytes += cDelay_init(this, &cDelay_JANSOnlJ, 25.0f);
  numBytes += cVar_init_f(&cVar_6JnFojfR, 0.0f);
  numBytes += sVarf_init(&sVarf_VpW71EE8, 0.0f, 0.0f, false);
  numBytes += cRandom_init(&cRandom_ezv0befZ, 358123132);
  numBytes += cSlice_init(&cSlice_tH7aApmN, 1, 1);
  numBytes += sVari_init(&sVari_Pl0G6DD1, 0, 0, false);
  numBytes += cTabhead_init(&cTabhead_QUWzboGU, &hTable_NqN4qTjS);
  numBytes += cVar_init_s(&cVar_zasTGQFk, "del-1497-delay");
  numBytes += cDelay_init(this, &cDelay_wVxklsR1, 12.0f);
  numBytes += cDelay_init(this, &cDelay_WGkBvFeS, 0.0f);
  numBytes += cBinop_init(&cBinop_ll84Ss8d, 12.0f); // __mul
  numBytes += cBinop_init(&cBinop_HhO1IhnH, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_MZCVjXdJ, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_zdeDnjTG, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_heY9xzxV, 1.0f); // __pow
  numBytes += cVar_init_s(&cVar_9NsMQHyl, "floatatom");
  numBytes += cDelay_init(this, &cDelay_3ERgKFp7, 5.0f);
  numBytes += cVar_init_f(&cVar_Zt6Bf1nD, 3800.0f);
  numBytes += cBinop_init(&cBinop_ZQVRhEvd, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_NbRmEjXa, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_ysw4IKAR, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_X4OqYBKs, 0.0f);
  numBytes += cDelay_init(this, &cDelay_x4KOE3cV, 0.0f);
  numBytes += hTable_init(&hTable_NqN4qTjS, 256);
  numBytes += cBinop_init(&cBinop_qDXTL5sw, 0.0f); // __div
  numBytes += sVarf_init(&sVarf_09UxVico, 0.999f, 0.0f, false);
  numBytes += cPack_init(&cPack_f5mAjVXp, 2, 0.0f, 10.0f);
  numBytes += cPack_init(&cPack_adNYKezK, 2, 0.0f, 10.0f);
  numBytes += cSlice_init(&cSlice_XtCCIMgJ, 1, 1);
  numBytes += cSlice_init(&cSlice_DUE60xXY, 0, 1);
  numBytes += cBinop_init(&cBinop_FWgGFZdU, 1.0f); // __mul
  numBytes += cVar_init_f(&cVar_R3BZRvfh, 98.0f);
  numBytes += cIf_init(&cIf_aFG3oJ94, false);
  numBytes += cBinop_init(&cBinop_R1TDQnTO, 0.0f); // __pow
  numBytes += cPack_init(&cPack_n0OB1FeM, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_nOtz2eXo, 0.0f);
  numBytes += cVar_init_f(&cVar_d5hYptRh, 98.0f);
  numBytes += cIf_init(&cIf_mmDIZt5G, false);
  numBytes += cBinop_init(&cBinop_azcWMMy8, 0.0f); // __pow
  numBytes += cPack_init(&cPack_9tnPgoYv, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_R43hpoGw, 0.0f);
  numBytes += cRandom_init(&cRandom_GRKCbLCV, 1752831495);
  numBytes += cSlice_init(&cSlice_Tm5B3KTB, 1, 1);
  numBytes += cBinop_init(&cBinop_Mh7qOlAm, 1.0f); // __pow
  numBytes += cRandom_init(&cRandom_BilP4Qzp, 20129892);
  numBytes += cSlice_init(&cSlice_5zJYFlMM, 1, 1);
  numBytes += cPack_init(&cPack_z8IefsVX, 2, 0.0f, 50.0f);
  numBytes += cVar_init_s(&cVar_OFphgir9, "floatatom");
  numBytes += cVar_init_s(&cVar_EiQTMZfM, "floatatom");
  numBytes += cVar_init_f(&cVar_hGnCbDbN, 0.0f);
  numBytes += cVar_init_s(&cVar_W1FCX2at, "floatatom");
  numBytes += cVar_init_s(&cVar_GAvKpMNZ, "floatatom");
  numBytes += cVar_init_s(&cVar_CP2DBLnH, "floatatom");
  numBytes += cDelay_init(this, &cDelay_yvob4Z2A, 25.0f);
  numBytes += cVar_init_f(&cVar_5VVWbTi9, 0.0f);
  numBytes += sVarf_init(&sVarf_glQhg9bG, 0.0f, 0.0f, false);
  numBytes += cRandom_init(&cRandom_LqP1XtAM, -936999322);
  numBytes += cSlice_init(&cSlice_F2rMqRO1, 1, 1);
  numBytes += sVari_init(&sVari_VvwsZqxY, 0, 0, false);
  numBytes += cTabhead_init(&cTabhead_i1iEfi1f, &hTable_eT9j3lOK);
  numBytes += cVar_init_s(&cVar_bFg0Fpz2, "del-1564-delay");
  numBytes += cDelay_init(this, &cDelay_SgxA1ZC2, 12.0f);
  numBytes += cDelay_init(this, &cDelay_cLjXDcCl, 0.0f);
  numBytes += cBinop_init(&cBinop_h01BVglq, 12.0f); // __mul
  numBytes += cBinop_init(&cBinop_pRwTbIoX, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_YhdwsXqf, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_0w2XLgLu, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_4aU7Ni4v, 1.0f); // __pow
  numBytes += cVar_init_s(&cVar_WZwcOsYa, "floatatom");
  numBytes += cDelay_init(this, &cDelay_XMhCPqQn, 5.0f);
  numBytes += cVar_init_f(&cVar_h4UbNH6N, 3800.0f);
  numBytes += cBinop_init(&cBinop_DomcrxPs, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_8Hv6YLUP, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_Hz4wWSlG, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_GsSS5z2N, 0.0f);
  numBytes += cDelay_init(this, &cDelay_xXzVRiLA, 0.0f);
  numBytes += hTable_init(&hTable_eT9j3lOK, 256);
  numBytes += cBinop_init(&cBinop_1dr157Qn, 0.0f); // __div
  numBytes += sVarf_init(&sVarf_NlFqYNsI, 0.999f, 0.0f, false);
  numBytes += cPack_init(&cPack_Uz12UbaY, 2, 0.0f, 10.0f);
  numBytes += cPack_init(&cPack_G6fIXAry, 2, 0.0f, 10.0f);
  numBytes += cSlice_init(&cSlice_dst35s5q, 1, 1);
  numBytes += cSlice_init(&cSlice_eA6s9mwy, 0, 1);
  numBytes += cBinop_init(&cBinop_MeAy33Eq, 1.0f); // __mul
  numBytes += cRandom_init(&cRandom_iWTFkthf, 1098670691);
  numBytes += cSlice_init(&cSlice_oQwqtKJz, 1, 1);
  numBytes += cBinop_init(&cBinop_JGRCYHPf, 1.0f); // __pow
  numBytes += cRandom_init(&cRandom_6Xw8jvRr, 508390969);
  numBytes += cSlice_init(&cSlice_YcP5whC6, 1, 1);
  numBytes += cPack_init(&cPack_XmgDJbQN, 2, 0.0f, 50.0f);
  numBytes += cVar_init_s(&cVar_bMo7sptF, "floatatom");
  numBytes += cVar_init_s(&cVar_n2HO47KA, "floatatom");
  numBytes += cVar_init_f(&cVar_ggHtLBX3, 0.0f);
  numBytes += cVar_init_s(&cVar_dYBoEfrx, "floatatom");
  numBytes += cVar_init_s(&cVar_j4nRoqpA, "floatatom");
  numBytes += cVar_init_s(&cVar_k1l8Y0p1, "floatatom");
  numBytes += cDelay_init(this, &cDelay_8j3KsQL7, 25.0f);
  numBytes += cVar_init_f(&cVar_rRzZCgAG, 0.0f);
  numBytes += sVarf_init(&sVarf_GClz2FXh, 0.0f, 0.0f, false);
  numBytes += cRandom_init(&cRandom_TyFfADbn, -1071567103);
  numBytes += cSlice_init(&cSlice_ruOZJcg1, 1, 1);
  numBytes += sVari_init(&sVari_0hXYUTZf, 0, 0, false);
  numBytes += cTabhead_init(&cTabhead_qLswlBtL, &hTable_O3JTekn1);
  numBytes += cVar_init_s(&cVar_6KcFhRxf, "del-1615-delay");
  numBytes += cDelay_init(this, &cDelay_pW10xPPi, 12.0f);
  numBytes += cDelay_init(this, &cDelay_eW4R0HAr, 0.0f);
  numBytes += cBinop_init(&cBinop_ifcYMbe1, 12.0f); // __mul
  numBytes += cBinop_init(&cBinop_cdOF4MiC, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_U8Ih02Gg, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_JYstxLBV, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_PuXKH1Ux, 1.0f); // __pow
  numBytes += cVar_init_s(&cVar_qqwJdVRt, "floatatom");
  numBytes += cDelay_init(this, &cDelay_hACHniE7, 5.0f);
  numBytes += cVar_init_f(&cVar_ToQ7iRm0, 3800.0f);
  numBytes += cBinop_init(&cBinop_lEjFGiEC, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_LnaqLmTh, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_ZnRuqqxT, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_f5RVO8IR, 0.0f);
  numBytes += cDelay_init(this, &cDelay_bPHKzllz, 0.0f);
  numBytes += hTable_init(&hTable_O3JTekn1, 256);
  numBytes += cBinop_init(&cBinop_cxHYCmBj, 0.0f); // __div
  numBytes += sVarf_init(&sVarf_0vJoTVKz, 0.999f, 0.0f, false);
  numBytes += cPack_init(&cPack_E2Te6apB, 2, 0.0f, 10.0f);
  numBytes += cPack_init(&cPack_LYILugvs, 2, 0.0f, 10.0f);
  numBytes += cSlice_init(&cSlice_8XV4gloF, 1, 1);
  numBytes += cSlice_init(&cSlice_z9CKtwAU, 0, 1);
  numBytes += cBinop_init(&cBinop_Lohgnt4I, 1.0f); // __mul
  numBytes += cRandom_init(&cRandom_7ykyqEz3, 1759846769);
  numBytes += cSlice_init(&cSlice_RuEG0lVD, 1, 1);
  numBytes += cBinop_init(&cBinop_68r0KC5q, 1.0f); // __pow
  numBytes += cRandom_init(&cRandom_e6PV01zX, 2073547830);
  numBytes += cSlice_init(&cSlice_C7I0Td3E, 1, 1);
  numBytes += cPack_init(&cPack_hLWTNQsl, 2, 0.0f, 50.0f);
  numBytes += cVar_init_s(&cVar_BaGdM4qH, "floatatom");
  numBytes += cVar_init_s(&cVar_urvmPGFa, "floatatom");
  numBytes += cVar_init_f(&cVar_S5GgStLj, 0.0f);
  numBytes += cVar_init_s(&cVar_4EPkCYO2, "floatatom");
  numBytes += cVar_init_s(&cVar_9sOuS4Oz, "floatatom");
  numBytes += cVar_init_s(&cVar_7zvZCtdY, "floatatom");
  numBytes += cDelay_init(this, &cDelay_TeJWlABt, 25.0f);
  numBytes += cVar_init_f(&cVar_Ivxh18KH, 0.0f);
  numBytes += sVarf_init(&sVarf_RovwkIw2, 0.0f, 0.0f, false);
  numBytes += cRandom_init(&cRandom_7e2Xs53q, 1332372883);
  numBytes += cSlice_init(&cSlice_IvX8qen2, 1, 1);
  numBytes += sVari_init(&sVari_bCTGNkeS, 0, 0, false);
  numBytes += cTabhead_init(&cTabhead_GkyoYgi9, &hTable_cbRKxpD7);
  numBytes += cVar_init_s(&cVar_dU4OaLNw, "del-1666-delay");
  numBytes += cDelay_init(this, &cDelay_jwCjPNLR, 12.0f);
  numBytes += cDelay_init(this, &cDelay_hx3o5pIP, 0.0f);
  numBytes += cBinop_init(&cBinop_vgjuqOgJ, 12.0f); // __mul
  numBytes += cBinop_init(&cBinop_MzoCxi9O, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_RkPZOlLn, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_S6IOuzSE, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_DNPkBXdg, 1.0f); // __pow
  numBytes += cVar_init_s(&cVar_jTUi3JbN, "floatatom");
  numBytes += cDelay_init(this, &cDelay_eLvUhqLn, 5.0f);
  numBytes += cVar_init_f(&cVar_7jcTZ8Y7, 3800.0f);
  numBytes += cBinop_init(&cBinop_MREAUVJW, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_ASCMEqPZ, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_CAuXHeFu, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_eh1caV5Q, 0.0f);
  numBytes += cDelay_init(this, &cDelay_M9Ko9qZd, 0.0f);
  numBytes += hTable_init(&hTable_cbRKxpD7, 256);
  numBytes += cBinop_init(&cBinop_PxGu9dBh, 0.0f); // __div
  numBytes += sVarf_init(&sVarf_RPjk0Dgz, 0.999f, 0.0f, false);
  numBytes += cPack_init(&cPack_CGWss5JJ, 2, 0.0f, 10.0f);
  numBytes += cPack_init(&cPack_0lZ8wKKw, 2, 0.0f, 10.0f);
  numBytes += cSlice_init(&cSlice_8cIgAeXS, 1, 1);
  numBytes += cSlice_init(&cSlice_AwbkDAjm, 0, 1);
  numBytes += cBinop_init(&cBinop_ezCYhhbS, 1.0f); // __mul
  numBytes += cVar_init_f(&cVar_TZe0Xq0A, 100.0f);
  numBytes += cIf_init(&cIf_l1V304Fe, false);
  numBytes += cBinop_init(&cBinop_3Y39AZ0e, 0.0f); // __pow
  numBytes += cPack_init(&cPack_qzGAhwZb, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_M14zQcnZ, 0.0f);
  numBytes += cVar_init_f(&cVar_DvQkykCf, 100.0f);
  numBytes += cIf_init(&cIf_6XlQC6QE, false);
  numBytes += cBinop_init(&cBinop_0DhjWYMR, 0.0f); // __pow
  numBytes += cPack_init(&cPack_c4OhMovz, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_qCp5kXVB, 0.0f);
  numBytes += cVar_init_f(&cVar_Jk41NPa6, 98.0f);
  numBytes += cIf_init(&cIf_cpzsusVR, false);
  numBytes += cBinop_init(&cBinop_AGWGY107, 0.0f); // __pow
  numBytes += cPack_init(&cPack_zWCt3tMm, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_D5m1z7gq, 0.0f);
  numBytes += cIf_init(&cIf_mJ4uoAG3, false);
  numBytes += cIf_init(&cIf_oHYbKeSH, false);
  numBytes += cVar_init_f(&cVar_3vk2LYXU, 89.0f);
  numBytes += cIf_init(&cIf_sNLX0V7N, false);
  numBytes += cBinop_init(&cBinop_9A90cFAE, 0.0f); // __pow
  numBytes += cPack_init(&cPack_adIMRuo0, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_R9h1RyvC, 0.0f);
  numBytes += cPack_init(&cPack_ActXizl2, 2, 0.0f, 0.0f);
  numBytes += cSlice_init(&cSlice_lJwNwUiB, 1, 1);
  numBytes += cSlice_init(&cSlice_QbXbPL6l, 0, 1);
  numBytes += cIf_init(&cIf_gfUkXK8K, false);
  numBytes += cIf_init(&cIf_jEWICWZ8, false);
  numBytes += cIf_init(&cIf_EvXCM6O2, false);
  numBytes += cSlice_init(&cSlice_0fPpwafF, 1, 1);
  numBytes += cSlice_init(&cSlice_br9NnjpD, 0, 1);
  numBytes += cVar_init_f(&cVar_FpzUiI39, 0.0f);
  numBytes += cIf_init(&cIf_jC4Mczgd, false);
  numBytes += cPack_init(&cPack_u5imjPEP, 2, 0.0f, 0.0f);
  numBytes += cSlice_init(&cSlice_tx2TCvlM, 1, -1);
  numBytes += cSlice_init(&cSlice_5f3FvQpl, 1, -1);
  numBytes += cSlice_init(&cSlice_q6o7mfie, 1, -1);
  numBytes += cSlice_init(&cSlice_41RaPf9H, 1, -1);
  numBytes += cIf_init(&cIf_j108jHSS, false);
  numBytes += cVar_init_f(&cVar_qyTvtMHX, 1.0f);
  numBytes += cPack_init(&cPack_1115YzV3, 3, 0.0f, 0.0f, 0.0f);
  numBytes += cVar_init_f(&cVar_HVo32Nnw, 0.0f);
  
  // schedule a message to trigger all loadbangs via the __hv_init receiver
  scheduleMessageForReceiver(0xCE5CC65B, msg_initWithBang(HV_MESSAGE_ON_STACK(1), 0));
}

Heavy_CircleStrings::~Heavy_CircleStrings() {
  hTable_free(&hTable_sJEcXIKJ);
  hTable_free(&hTable_H8kRmOwO);
  hTable_free(&hTable_5CJjcOLl);
  hTable_free(&hTable_kORp847N);
  cPack_free(&cPack_ikjnkobH);
  cPack_free(&cPack_i0Fw54NV);
  hTable_free(&hTable_SCpCTX5W);
  hTable_free(&hTable_jjcyPKhQ);
  hTable_free(&hTable_CuyGdw13);
  hTable_free(&hTable_wWU6EClR);
  hTable_free(&hTable_YgeTeMXQ);
  hTable_free(&hTable_FjgILMCU);
  cPack_free(&cPack_WoUl5Yx9);
  cPack_free(&cPack_J8JZdbvU);
  cPack_free(&cPack_Bm2na9Hr);
  hTable_free(&hTable_tnW6ADwC);
  hTable_free(&hTable_3uLj1yGs);
  hTable_free(&hTable_EB9IrNc4);
  hTable_free(&hTable_lA7P06zw);
  hTable_free(&hTable_4ntfDiqh);
  cPack_free(&cPack_X0Iep43f);
  cPack_free(&cPack_MlACp4XR);
  hTable_free(&hTable_pVu6zRuu);
  hTable_free(&hTable_GitsKUSa);
  hTable_free(&hTable_4R7EzTqJ);
  hTable_free(&hTable_jGl7FP1w);
  hTable_free(&hTable_gj6OsYoC);
  hTable_free(&hTable_ol9BBsMZ);
  cPack_free(&cPack_nnJOliZ3);
  hTable_free(&hTable_B9HtbLqp);
  cPack_free(&cPack_oxCIdad0);
  cPack_free(&cPack_BeuYz5E4);
  cPack_free(&cPack_CiXymxDq);
  hTable_free(&hTable_AqjRr9T6);
  hTable_free(&hTable_JrchviHR);
  cPack_free(&cPack_Dmc8PtT0);
  cPack_free(&cPack_NtnZNmNh);
  cPack_free(&cPack_iufSNh34);
  hTable_free(&hTable_PIdkt3iU);
  cPack_free(&cPack_ghqsILSs);
  cPack_free(&cPack_HGvb5mmk);
  cPack_free(&cPack_woqQOB8x);
  hTable_free(&hTable_NqN4qTjS);
  cPack_free(&cPack_f5mAjVXp);
  cPack_free(&cPack_adNYKezK);
  cPack_free(&cPack_n0OB1FeM);
  cPack_free(&cPack_9tnPgoYv);
  cPack_free(&cPack_z8IefsVX);
  hTable_free(&hTable_eT9j3lOK);
  cPack_free(&cPack_Uz12UbaY);
  cPack_free(&cPack_G6fIXAry);
  cPack_free(&cPack_XmgDJbQN);
  hTable_free(&hTable_O3JTekn1);
  cPack_free(&cPack_E2Te6apB);
  cPack_free(&cPack_LYILugvs);
  cPack_free(&cPack_hLWTNQsl);
  hTable_free(&hTable_cbRKxpD7);
  cPack_free(&cPack_CGWss5JJ);
  cPack_free(&cPack_0lZ8wKKw);
  cPack_free(&cPack_qzGAhwZb);
  cPack_free(&cPack_c4OhMovz);
  cPack_free(&cPack_zWCt3tMm);
  cPack_free(&cPack_adIMRuo0);
  cPack_free(&cPack_ActXizl2);
  cPack_free(&cPack_u5imjPEP);
  cPack_free(&cPack_1115YzV3);
}

HvTable *Heavy_CircleStrings::getTableForHash(hv_uint32_t tableHash) {switch (tableHash) {
    case 0xCA4BE954: return &hTable_sJEcXIKJ; // del-1011-del1
    case 0x244CE923: return &hTable_H8kRmOwO; // del-1011-del2
    case 0xBF68886F: return &hTable_5CJjcOLl; // del-1011-del3
    case 0x55632928: return &hTable_kORp847N; // del-1011-del4
    case 0x96995032: return &hTable_SCpCTX5W; // del-1011-ref6
    case 0xBDA899C7: return &hTable_jjcyPKhQ; // del-1011-ref5
    case 0xC66C0031: return &hTable_CuyGdw13; // del-1011-ref4
    case 0x87263188: return &hTable_wWU6EClR; // del-1011-ref3
    case 0xABC596E9: return &hTable_YgeTeMXQ; // del-1011-ref2
    case 0x4E55A0D9: return &hTable_FjgILMCU; // del-1011-ref1
    case 0x1F09EB02: return &hTable_tnW6ADwC; // del-1118-del
    case 0xB5F303E3: return &hTable_3uLj1yGs; // del-1181-del1
    case 0x6E18225F: return &hTable_EB9IrNc4; // del-1181-del2
    case 0x272AEAC5: return &hTable_lA7P06zw; // del-1181-del3
    case 0x1EF3B8AB: return &hTable_4ntfDiqh; // del-1181-del4
    case 0x908630F0: return &hTable_pVu6zRuu; // del-1181-ref6
    case 0x571D5EBB: return &hTable_GitsKUSa; // del-1181-ref5
    case 0xCD1DF3EE: return &hTable_4R7EzTqJ; // del-1181-ref4
    case 0x32F70D4: return &hTable_jGl7FP1w; // del-1181-ref3
    case 0x2649C1A0: return &hTable_gj6OsYoC; // del-1181-ref2
    case 0x2A4E9F1A: return &hTable_ol9BBsMZ; // del-1181-ref1
    case 0xCDA70ACE: return &hTable_B9HtbLqp; // del-1280-del1
    case 0x1880FCC4: return &hTable_AqjRr9T6; // del-1311-del
    case 0xDA0DD3E: return &hTable_JrchviHR; // del-1340-del1
    case 0xF059E6C5: return &hTable_PIdkt3iU; // del-1418-delay
    case 0x1B841D52: return &hTable_NqN4qTjS; // del-1497-delay
    case 0xDDCE7CE3: return &hTable_eT9j3lOK; // del-1564-delay
    case 0x267B6FA5: return &hTable_O3JTekn1; // del-1615-delay
    case 0xA939BCAF: return &hTable_cbRKxpD7; // del-1666-delay
    default: return nullptr;
  }
}

void Heavy_CircleStrings::scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) {
  switch (receiverHash) {
    case 0xE9CDF196: { // 1474-att
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_zLyeXm6k_sendMessage);
      break;
    }
    case 0x318534AD: { // 1474-envrel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_YORauOUd_sendMessage);
      break;
    }
    case 0x73BE02B2: { // 1474-envvol
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_DAVY7esw_sendMessage);
      break;
    }
    case 0x20FBEFA2: { // 1474-index
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_OsuELRwl_sendMessage);
      break;
    }
    case 0xB3D2781B: { // 1474-rel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_JE74ThFn_sendMessage);
      break;
    }
    case 0xEB419491: { // 1474-vel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_4QONnjek_sendMessage);
      break;
    }
    case 0x287969C8: { // 1525-levelin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_idSlIBqh_sendMessage);
      break;
    }
    case 0xF758C0B7: { // 1525-levelout
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_YBKV6ZZ2_sendMessage);
      break;
    }
    case 0xEC622ADF: { // 1533-levelin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_mMi3D1gg_sendMessage);
      break;
    }
    case 0x706EBE7F: { // 1533-levelout
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_2STqfbKn_sendMessage);
      break;
    }
    case 0x961222E8: { // 1541-att
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_rNZIgAjR_sendMessage);
      break;
    }
    case 0x5DFAB282: { // 1541-envrel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_XsxvudCG_sendMessage);
      break;
    }
    case 0xA73CF987: { // 1541-envvol
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_Doeln2j3_sendMessage);
      break;
    }
    case 0xDE176410: { // 1541-index
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_N06e9h3s_sendMessage);
      break;
    }
    case 0x8027D6B0: { // 1541-rel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_Ugl1BgiH_sendMessage);
      break;
    }
    case 0x5F30AB7: { // 1541-vel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_Q3DzEQIL_sendMessage);
      break;
    }
    case 0xDAF501EE: { // 1592-att
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_DBoGnCsS_sendMessage);
      break;
    }
    case 0x97DF0634: { // 1592-envrel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_mcCQqEOf_sendMessage);
      break;
    }
    case 0xED939F1D: { // 1592-envvol
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_SUCZCmyy_sendMessage);
      break;
    }
    case 0x6824A5FB: { // 1592-index
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_8cLqJVy5_sendMessage);
      break;
    }
    case 0xD73B2171: { // 1592-rel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_7wiN3w9z_sendMessage);
      break;
    }
    case 0x42AF91EE: { // 1592-vel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_UX34zg3Z_sendMessage);
      break;
    }
    case 0xA1F992A3: { // 1643-att
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_dTyUmKL6_sendMessage);
      break;
    }
    case 0x3A383FAD: { // 1643-envrel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_jeJ3Yki8_sendMessage);
      break;
    }
    case 0x5381C841: { // 1643-envvol
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_uQCN2ilN_sendMessage);
      break;
    }
    case 0x17698774: { // 1643-index
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_4X3I590h_sendMessage);
      break;
    }
    case 0xB064A0B2: { // 1643-rel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_tAY3cULM_sendMessage);
      break;
    }
    case 0x48B0D745: { // 1643-vel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_v3oGutji_sendMessage);
      break;
    }
    case 0xA97D2594: { // 1694-levelin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_i0dzePDj_sendMessage);
      break;
    }
    case 0x17BA9CFD: { // 1694-levelout
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_leJv0l1q_sendMessage);
      break;
    }
    case 0x563C50D1: { // 1702-levelin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_ZTsVfkF6_sendMessage);
      break;
    }
    case 0x50C55BB2: { // 1702-levelout
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_Ziy08ppj_sendMessage);
      break;
    }
    case 0x60821E7E: { // 1710-levelin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_hGREsWNt_sendMessage);
      break;
    }
    case 0x2917EC99: { // 1710-levelout
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_fQU4WAVA_sendMessage);
      break;
    }
    case 0xA773C924: { // 1722-levelin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_tD3huP1Y_sendMessage);
      break;
    }
    case 0xCA11C605: { // 1722-levelout
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_mPRPHvhT_sendMessage);
      break;
    }
    case 0xCE5CC65B: { // __hv_init
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_6OanoQT2_sendMessage);
      break;
    }
    case 0x67E37CA3: { // __hv_notein
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_6Zz4f0iD_sendMessage);
      break;
    }
    case 0x40AA4AF1: { // changesound
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_AfQgtSeE_sendMessage);
      break;
    }
    case 0xA41806F7: { // distortlevel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_Axu1m9Vg_sendMessage);
      break;
    }
    case 0xFCD12E4C: { // mastervolume
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_UuV7deFy_sendMessage);
      break;
    }
    case 0xEF5F3308: { // panTranslation
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_Gy7xm3tI_sendMessage);
      break;
    }
    case 0x58FBFA93: { // phaseFreq
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_s43HyO1s_sendMessage);
      break;
    }
    case 0x8B2148DD: { // pitch
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_VeAdaoIm_sendMessage);
      break;
    }
    case 0x4409C659: { // processeffects
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_mQWbbmW2_sendMessage);
      break;
    }
    case 0x7B795C5A: { // resetsing
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_Kg61wDyb_sendMessage);
      break;
    }
    case 0xA987B741: { // reverbvolume
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_rqpQvU8y_sendMessage);
      break;
    }
    case 0x7AAE6786: { // sinPanAngle
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_4eSUgyq3_sendMessage);
      break;
    }
    case 0x6731B2E0: { // sing
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_NaXnfwrH_sendMessage);
      break;
    }
    case 0x57292445: { // singlevel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_n50No16t_sendMessage);
      break;
    }
    case 0xC7DE3B07: { // singpitch
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_MIOk4mXq_sendMessage);
      break;
    }
    case 0x4E809B1C: { // testbutton
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_wsW31huh_sendMessage);
      break;
    }
    case 0x853B1BE7: { // velocity
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_tzbko9pQ_sendMessage);
      break;
    }
    default: return;
  }
}

int Heavy_CircleStrings::getParameterInfo(int index, HvParameterInfo *info) {
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


void Heavy_CircleStrings::cBinop_3MPn0eo7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_er8X9uCw, 0, m, &cVar_er8X9uCw_sendMessage);
}

void Heavy_CircleStrings::cMsg_51yGrh40_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 127.0f);
  cSend_MRJzFSvg_sendMessage(_c, 0, m);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1.28f, 0, m, &cBinop_YzDUtlvP_sendMessage);
}

void Heavy_CircleStrings::cSend_9nbcLdkc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_VeAdaoIm_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_GNUrXJ9X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 64.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_er8X9uCw, 0, m, &cVar_er8X9uCw_sendMessage);
}

void Heavy_CircleStrings::cSend_HPjtQk1P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_Gy7xm3tI_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_Icit5MbF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.8f);
  cSend_HPjtQk1P_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_Kt7kKPHH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_51yGrh40_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_LPyHGKIm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSend_HPjtQk1P_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_MRJzFSvg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_tzbko9pQ_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_MxuQiGAF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_GNUrXJ9X_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_Fwp5NakA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_iBbrZkJq_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_RDsrnpUR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_MIOk4mXq_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cVar_lTeED9sX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cSwitchcase_1L5gV5YN_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_rnZmDjgm, 0, m, &cSlice_rnZmDjgm_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_4obOa0kA, 0, m, &cRandom_4obOa0kA_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cRandom_4obOa0kA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 128.0f, 0, m, &cBinop_HmrFwopm_sendMessage);
}

void Heavy_CircleStrings::cBinop_HmrFwopm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_UXC71nrx_sendMessage);
}

void Heavy_CircleStrings::cUnop_UXC71nrx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1.28f, 0, m, &cBinop_YzDUtlvP_sendMessage);
  cSend_MRJzFSvg_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSlice_rnZmDjgm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_4obOa0kA, 1, m, &cRandom_4obOa0kA_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_YzDUtlvP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_DOoKdRAh, 0, m, &cVar_DOoKdRAh_sendMessage);
}

void Heavy_CircleStrings::cVar_er8X9uCw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_9nbcLdkc_sendMessage(_c, 0, m);
  cSend_RDsrnpUR_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cVar_DOoKdRAh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_k3qhc7vf_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_MAg1alTP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cSlice_NG3d9ZnJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_qnDRqHnS, 1, m, &cRandom_qnDRqHnS_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cSwitchcase_PJTrQiIn_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_NG3d9ZnJ, 0, m, &cSlice_NG3d9ZnJ_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_qnDRqHnS, 0, m, &cRandom_qnDRqHnS_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_TtciRdhR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_UlHtggTQ_sendMessage);
}

void Heavy_CircleStrings::cUnop_UlHtggTQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 20.0f, 0, m, &cBinop_3MPn0eo7_sendMessage);
}

void Heavy_CircleStrings::cRandom_qnDRqHnS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 100.0f, 0, m, &cBinop_TtciRdhR_sendMessage);
}

void Heavy_CircleStrings::cSend_iBbrZkJq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_AfQgtSeE_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_k3qhc7vf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_n50No16t_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_12dR74WD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_1L5gV5YN_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_PJTrQiIn_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cVar_mE9m3qhV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cCast_tG1TWvka_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Kt7kKPHH_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_MxuQiGAF_sendMessage);
}

void Heavy_CircleStrings::cBinop_ZlTLysvX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_bEmZWMZJ, 1, m, &cVar_bEmZWMZJ_sendMessage);
}

void Heavy_CircleStrings::cVar_bEmZWMZJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_ZlTLysvX_sendMessage);
}

void Heavy_CircleStrings::cReceive_2STqfbKn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_qoGHzXoH_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_2b1NMNfW_sendMessage);
}

void Heavy_CircleStrings::cBinop_3bxNm4Ir_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_JGUkR6QZ_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cReceive_4QONnjek_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_YCzbv3a7_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_Gcz4I6Xl, 0, m, &cVar_Gcz4I6Xl_sendMessage);
}

void Heavy_CircleStrings::cReceive_4X3I590h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_hLWTNQsl, 0, m, &cPack_hLWTNQsl_sendMessage);
}

void Heavy_CircleStrings::cReceive_4eSUgyq3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 100.0f, 0, m, &cBinop_GWlpQv24_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_JQ8XH6mX_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_GfX4fkhS, 0, m, &cIf_GfX4fkhS_sendMessage);
}

void Heavy_CircleStrings::cReceive_6OanoQT2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_NG1rA9r2_sendMessage(_c, 0, m);
  cMsg_uwVSXi1B_sendMessage(_c, 0, m);
  cMsg_3z2QaTYr_sendMessage(_c, 0, m);
  cMsg_VRZkqbbs_sendMessage(_c, 0, m);
  cMsg_MgYlK9We_sendMessage(_c, 0, m);
  cMsg_mihMMqE2_sendMessage(_c, 0, m);
  cMsg_SZLN7VJY_sendMessage(_c, 0, m);
  cMsg_kKgj26mj_sendMessage(_c, 0, m);
  cMsg_Tfh3ugTx_sendMessage(_c, 0, m);
  cMsg_NzXum9ww_sendMessage(_c, 0, m);
  cMsg_EI15LN6J_sendMessage(_c, 0, m);
  cMsg_lJnQ3c4Q_sendMessage(_c, 0, m);
  cMsg_SMf3xEQ5_sendMessage(_c, 0, m);
  cMsg_xdeW7YyO_sendMessage(_c, 0, m);
  cMsg_8YVWemzl_sendMessage(_c, 0, m);
  cMsg_jcNCDCLa_sendMessage(_c, 0, m);
  cMsg_SeWjqHEN_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_6y7ZfPLz, 0, m, &cVar_6y7ZfPLz_sendMessage);
  cMsg_0GRO5kiV_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_B9lh18dH, 0, m, &cVar_B9lh18dH_sendMessage);
  cMsg_PUoqs3IV_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_KAwev9r0, 0, m, &cVar_KAwev9r0_sendMessage);
  cMsg_5a5WVVoY_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_xo4XpkPP, 0, m, &cVar_xo4XpkPP_sendMessage);
  cMsg_HqkuD6Lx_sendMessage(_c, 0, m);
  cMsg_NcKfd4xP_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_f9KMTLD9, 0, m, &cVar_f9KMTLD9_sendMessage);
  cMsg_MzGqcph5_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_Fg3xBIla, 0, m, &cVar_Fg3xBIla_sendMessage);
  cMsg_88KB4mBa_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_iAkocxD1, 0, m, &cVar_iAkocxD1_sendMessage);
  cMsg_MsB7RNEz_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_AMuFTtd3, 0, m, &cVar_AMuFTtd3_sendMessage);
  cMsg_XIEBpbZK_sendMessage(_c, 0, m);
  cMsg_Q2XDi7go_sendMessage(_c, 0, m);
  cMsg_AyBSTvQl_sendMessage(_c, 0, m);
  cMsg_32B8qYsX_sendMessage(_c, 0, m);
  cMsg_SR7hPznG_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_b5xo0pt9, 0, m, &cVar_b5xo0pt9_sendMessage);
  cMsg_3PJFmvdb_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_Pr8OI5bX, 0, m, &cVar_Pr8OI5bX_sendMessage);
  cMsg_Vx8uFmq4_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_LP6LfgeT, 0, m, &cVar_LP6LfgeT_sendMessage);
  cMsg_mkXlsNcY_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_8gEUlKK0, 0, m, &cVar_8gEUlKK0_sendMessage);
  cMsg_Y8Drs0t6_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_2BrxM752, 0, m, &cVar_2BrxM752_sendMessage);
  cMsg_pVSD1bKQ_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_Aif40NUS, 0, m, &cVar_Aif40NUS_sendMessage);
  cMsg_tQkRkM77_sendMessage(_c, 0, m);
  cMsg_D9snJVWn_sendMessage(_c, 0, m);
  cMsg_3WLu8nqg_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_7bCdvUh8, 0, m, &cVar_7bCdvUh8_sendMessage);
  cMsg_hkzAoPV4_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_1NcaJMVb, 0, m, &cVar_1NcaJMVb_sendMessage);
  cMsg_sKGp46Oq_sendMessage(_c, 0, m);
  cMsg_p6kZOPxX_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_gnDhbVDa, 0, m, &cVar_gnDhbVDa_sendMessage);
  cMsg_5YNTznFC_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_HAXQFBT5, 0, m, &cVar_HAXQFBT5_sendMessage);
  cSwitchcase_VCnxqSqb_onMessage(_c, NULL, 0, m, NULL);
  cMsg_Y8iOGIR7_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_TLSoiMLz, 0, m, &cVar_TLSoiMLz_sendMessage);
  cMsg_iBAHMjl4_sendMessage(_c, 0, m);
  cSwitchcase_ivMuJqsG_onMessage(_c, NULL, 0, m, NULL);
  cMsg_iFdEsWYa_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_Zt6Bf1nD, 0, m, &cVar_Zt6Bf1nD_sendMessage);
  cMsg_c2jvN8v3_sendMessage(_c, 0, m);
  cSwitchcase_8XkhPJjg_onMessage(_c, NULL, 0, m, NULL);
  cMsg_UXc6kaxb_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_h4UbNH6N, 0, m, &cVar_h4UbNH6N_sendMessage);
  cMsg_NTx1L2QY_sendMessage(_c, 0, m);
  cSwitchcase_6QmZHFgI_onMessage(_c, NULL, 0, m, NULL);
  cMsg_jHxaDnBq_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_ToQ7iRm0, 0, m, &cVar_ToQ7iRm0_sendMessage);
  cMsg_N9GYmeX7_sendMessage(_c, 0, m);
  cSwitchcase_NfQZvcVn_onMessage(_c, NULL, 0, m, NULL);
  cMsg_xu9bgdvu_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_7jcTZ8Y7, 0, m, &cVar_7jcTZ8Y7_sendMessage);
  cMsg_ww2CwSLM_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_grbSjNXQ, 0, m, &cVar_grbSjNXQ_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_v003oDpw, 0, m, &cVar_v003oDpw_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_1HRfmt7H, 0, m, &cVar_1HRfmt7H_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_WR1HmUul, 0, m, &cVar_WR1HmUul_sendMessage);
  cMsg_4CiVB78z_sendMessage(_c, 0, m);
  cMsg_AFVWNj5e_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_lJepFRYJ, 0, m, &cVar_lJepFRYJ_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_pperUyEz, 0, m, &cVar_pperUyEz_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_rKRrml5M, 0, m, &cVar_rKRrml5M_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_Aq4Yg5j6, 0, m, &cVar_Aq4Yg5j6_sendMessage);
  cMsg_xkjga8iw_sendMessage(_c, 0, m);
  cMsg_iKxiqkmm_sendMessage(_c, 0, m);
  cMsg_KmtnFRlu_sendMessage(_c, 0, m);
  cMsg_HDbXQ0jY_sendMessage(_c, 0, m);
  cMsg_qe3nonpr_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_Yh1dqw45, 0, m, &cVar_Yh1dqw45_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_238LxNEE, 0, m, &cVar_238LxNEE_sendMessage);
  cMsg_YgNzMhZe_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_eP92M7yI, 0, m, &cVar_eP92M7yI_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_J3MpXBud, 0, m, &cVar_J3MpXBud_sendMessage);
  cMsg_uzWvTynq_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_jiPKR3cA, 0, m, &cVar_jiPKR3cA_sendMessage);
  cMsg_xR7HV7wd_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_ncAXTAcc, 0, m, &cVar_ncAXTAcc_sendMessage);
  cMsg_EDIsnh81_sendMessage(_c, 0, m);
  cMsg_A2U3DdrV_sendMessage(_c, 0, m);
  cMsg_pWC2Hk8d_sendMessage(_c, 0, m);
  cMsg_P5sB6SzB_sendMessage(_c, 0, m);
  cMsg_QiyW5DFV_sendMessage(_c, 0, m);
  cMsg_bdjPGV80_sendMessage(_c, 0, m);
  cMsg_cHMLO2GH_sendMessage(_c, 0, m);
  cMsg_PVRoS2GR_sendMessage(_c, 0, m);
  cMsg_aTh5Iipb_sendMessage(_c, 0, m);
  cMsg_0gVgvaAf_sendMessage(_c, 0, m);
  cMsg_PTgl4Ofz_sendMessage(_c, 0, m);
  cMsg_MSo8HhWm_sendMessage(_c, 0, m);
  cMsg_YQhzhVXG_sendMessage(_c, 0, m);
  cMsg_OKNyVD4M_sendMessage(_c, 0, m);
  cMsg_LHH35Ght_sendMessage(_c, 0, m);
  cMsg_EMQW30Ti_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_p2n5RL08, 0, m, &cVar_p2n5RL08_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_qb95DYXu, 0, m, &cVar_qb95DYXu_sendMessage);
  cMsg_QuKgyp3j_sendMessage(_c, 0, m);
  cMsg_xvcGTgrh_sendMessage(_c, 0, m);
  cMsg_0va9TJKo_sendMessage(_c, 0, m);
  cMsg_5asCEX9U_sendMessage(_c, 0, m);
  cMsg_xHzYMt2t_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_R3BZRvfh, 0, m, &cVar_R3BZRvfh_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_d5hYptRh, 0, m, &cVar_d5hYptRh_sendMessage);
  cMsg_dEIWR7DB_sendMessage(_c, 0, m);
  cMsg_JnicZYUM_sendMessage(_c, 0, m);
  cMsg_oUYHEdeb_sendMessage(_c, 0, m);
  cMsg_eKc86o7b_sendMessage(_c, 0, m);
  cMsg_8Ur4xh2K_sendMessage(_c, 0, m);
  cMsg_QnhqZtEq_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_TZe0Xq0A, 0, m, &cVar_TZe0Xq0A_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_DvQkykCf, 0, m, &cVar_DvQkykCf_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_Jk41NPa6, 0, m, &cVar_Jk41NPa6_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_3vk2LYXU, 0, m, &cVar_3vk2LYXU_sendMessage);
  cMsg_bcGB1aGC_sendMessage(_c, 0, m);
  cSwitchcase_AVShmggN_onMessage(_c, NULL, 0, m, NULL);
  cMsg_mCwWjVxC_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_NsY2i96y, 0, m, &cVar_NsY2i96y_sendMessage);
  cMsg_bNylbiLP_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_ltGKqveF, 0, m, &cTabhead_ltGKqveF_sendMessage);
  cMsg_Ppd5goO8_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_Blp9Dv7H, 0, m, &cVar_Blp9Dv7H_sendMessage);
  cMsg_FS4owC4a_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_LfgILtky, 0, m, &cTabhead_LfgILtky_sendMessage);
  cMsg_ckz66LTI_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_loNtNfT3, 0, m, &cVar_loNtNfT3_sendMessage);
  cMsg_ZcejJIy1_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_4a2HeR3f, 0, m, &cTabhead_4a2HeR3f_sendMessage);
  cMsg_omqBk88d_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_iWnY6XFK, 0, m, &cVar_iWnY6XFK_sendMessage);
  cMsg_xC88pWif_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_NIYmTsXC, 0, m, &cTabhead_NIYmTsXC_sendMessage);
  cMsg_cnfmS3IJ_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_Jw3CfAGI, 0, m, &cVar_Jw3CfAGI_sendMessage);
  cMsg_no5oSF1E_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_bO3qviwg, 0, m, &cTabhead_bO3qviwg_sendMessage);
  cMsg_NHbGz78k_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_mTdviuQV, 0, m, &cVar_mTdviuQV_sendMessage);
  cMsg_OUxS27Up_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_9QxNZraR, 0, m, &cTabhead_9QxNZraR_sendMessage);
  cMsg_yBohUrD3_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_0u2RV7S3, 0, m, &cVar_0u2RV7S3_sendMessage);
  cMsg_q9qq7oTQ_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_3OjGBzpx, 0, m, &cTabhead_3OjGBzpx_sendMessage);
  cMsg_IgIk2IkY_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_EKfRxP7g, 0, m, &cVar_EKfRxP7g_sendMessage);
  cMsg_rqBTySv7_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_Nh0FxNNP, 0, m, &cTabhead_Nh0FxNNP_sendMessage);
  cMsg_SG2bcSnR_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_FiQfUHSQ, 0, m, &cVar_FiQfUHSQ_sendMessage);
  cMsg_YsGQXf8I_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_UyoDPMGJ, 0, m, &cTabhead_UyoDPMGJ_sendMessage);
  cMsg_uBVfidci_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_PIW25mD4, 0, m, &cVar_PIW25mD4_sendMessage);
  cMsg_AwTrNThN_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_wZzXg9rX, 0, m, &cTabhead_wZzXg9rX_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_SQmYneZy, 0, m, &cVar_SQmYneZy_sendMessage);
  cMsg_XJu9k75n_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_1RvtilXu, 0, m, &cVar_1RvtilXu_sendMessage);
  cMsg_ghvXpne5_sendMessage(_c, 0, m);
  cMsg_1HqYy2pn_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_X9zKhtxI, 0, m, &cVar_X9zKhtxI_sendMessage);
  cMsg_Ub6hZTeD_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_P3wS8A0I, 0, m, &cTabhead_P3wS8A0I_sendMessage);
  cMsg_AkD6AQBv_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_cbViQofB, 0, m, &cVar_cbViQofB_sendMessage);
  cMsg_LFX6ALvj_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_25RelK01, 0, m, &cTabhead_25RelK01_sendMessage);
  cMsg_hfBwD0ul_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_CmamotMH, 0, m, &cVar_CmamotMH_sendMessage);
  cMsg_gArjzwDG_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_HiWl0REH, 0, m, &cTabhead_HiWl0REH_sendMessage);
  cMsg_LMATvgMi_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_58IFI2fq, 0, m, &cVar_58IFI2fq_sendMessage);
  cMsg_Zi5lNQLi_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_6yp286bY, 0, m, &cTabhead_6yp286bY_sendMessage);
  cMsg_uZzF3Ixh_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_8l70VoDY, 0, m, &cVar_8l70VoDY_sendMessage);
  cMsg_CicYzqYX_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_wfU15qxn, 0, m, &cTabhead_wfU15qxn_sendMessage);
  cMsg_mszd6exa_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_6fo4mxtY, 0, m, &cVar_6fo4mxtY_sendMessage);
  cMsg_0JckHJRu_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_yFuq8aMY, 0, m, &cTabhead_yFuq8aMY_sendMessage);
  cMsg_LqnklgtN_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_uWoGdxz8, 0, m, &cVar_uWoGdxz8_sendMessage);
  cMsg_R0RVnxSW_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_7KT9OKCK, 0, m, &cTabhead_7KT9OKCK_sendMessage);
  cMsg_2pmToXM2_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_qvgNlC3p, 0, m, &cVar_qvgNlC3p_sendMessage);
  cMsg_0sNdwc3J_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_VRPF9nBu, 0, m, &cTabhead_VRPF9nBu_sendMessage);
  cMsg_XE8WwMMf_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_DRyTmypg, 0, m, &cVar_DRyTmypg_sendMessage);
  cMsg_CBh5T8lj_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_1cNTgzpa, 0, m, &cTabhead_1cNTgzpa_sendMessage);
  cMsg_cRHIu7p1_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_uqKw2Zl3, 0, m, &cVar_uqKw2Zl3_sendMessage);
  cMsg_JeHx8xhJ_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_uXyHDKNL, 0, m, &cTabhead_uXyHDKNL_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_IGYRqCHB, 0, m, &cVar_IGYRqCHB_sendMessage);
  cMsg_cSd6gTbo_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_vt9w4O4j, 0, m, &cVar_vt9w4O4j_sendMessage);
  cMsg_pbzo3fNU_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_rojQnTDl, 0, m, &cVar_rojQnTDl_sendMessage);
  cMsg_Zf8XIbKC_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_5dA5ApPk, 0, m, &cVar_5dA5ApPk_sendMessage);
  cMsg_blJZpUyG_sendMessage(_c, 0, m);
  cMsg_0sv3ZQWJ_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_1pKxZobp, 0, m, &cVar_1pKxZobp_sendMessage);
  cMsg_MMOLa641_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_nsk9h2Kd, 0, m, &cTabhead_nsk9h2Kd_sendMessage);
  cMsg_mKnGw8Cb_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_zasTGQFk, 0, m, &cVar_zasTGQFk_sendMessage);
  cMsg_LR8ev6UM_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_QUWzboGU, 0, m, &cTabhead_QUWzboGU_sendMessage);
  cMsg_JdwRblPa_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_bFg0Fpz2, 0, m, &cVar_bFg0Fpz2_sendMessage);
  cMsg_V282R6rK_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_i1iEfi1f, 0, m, &cTabhead_i1iEfi1f_sendMessage);
  cMsg_jwQ1Cmvw_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_6KcFhRxf, 0, m, &cVar_6KcFhRxf_sendMessage);
  cMsg_MoUbWGXF_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_qLswlBtL, 0, m, &cTabhead_qLswlBtL_sendMessage);
  cMsg_R2XJ3ffu_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_dU4OaLNw, 0, m, &cVar_dU4OaLNw_sendMessage);
  cMsg_dzkYAGAu_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_GkyoYgi9, 0, m, &cTabhead_GkyoYgi9_sendMessage);
}

void Heavy_CircleStrings::cUnop_22YsnUGx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 50.0f, 0, m, &cBinop_3bxNm4Ir_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_AVShmggN_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_CO7YXtmN, 0, m, &cSlice_CO7YXtmN_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_GXgnaMbL, 0, m, &cRandom_GXgnaMbL_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cSlice_CO7YXtmN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_GXgnaMbL, 1, m, &cRandom_GXgnaMbL_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cRandom_GXgnaMbL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 200.0f, 0, m, &cBinop_psluHfVQ_sendMessage);
}

void Heavy_CircleStrings::cBinop_psluHfVQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_22YsnUGx_sendMessage);
}

void Heavy_CircleStrings::cReceive_6Zz4f0iD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSlice_onMessage(_c, &Context(_c)->cSlice_d7xusZhg, 0, m, &cSlice_d7xusZhg_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_Kgr6aHNB, 0, m, &cSlice_Kgr6aHNB_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_9zhNSftQ, 0, m, &cSlice_9zhNSftQ_sendMessage);
}

void Heavy_CircleStrings::cVar_D5m1z7gq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_U8err9rx_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_U8err9rx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_fQU4WAVA_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_fCqbcVOf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_hGREsWNt_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_8FTdvsGE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_zWCt3tMm, 0, m, &cPack_zWCt3tMm_sendMessage);
}

void Heavy_CircleStrings::cBinop_AGWGY107_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_zWCt3tMm, 0, m, &cPack_zWCt3tMm_sendMessage);
}

void Heavy_CircleStrings::cBinop_SAkxLgGH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_cpzsusVR, 1, m, &cIf_cpzsusVR_sendMessage);
}

void Heavy_CircleStrings::cCast_U4Z28gM9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_SAkxLgGH_sendMessage);
}

void Heavy_CircleStrings::cIf_cpzsusVR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_8FTdvsGE_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_lRjOJbFe_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_dZabcMR0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_AGWGY107, HV_BINOP_POW, 1, m, &cBinop_AGWGY107_sendMessage);
  cMsg_ethuIGfa_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_ethuIGfa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_AGWGY107, HV_BINOP_POW, 0, m, &cBinop_AGWGY107_sendMessage);
}

void Heavy_CircleStrings::cCast_i80OCOSd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_cpzsusVR, 0, m, &cIf_cpzsusVR_sendMessage);
}

void Heavy_CircleStrings::cBinop_lRjOJbFe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_xiaNwBBx_sendMessage);
}

void Heavy_CircleStrings::cBinop_xiaNwBBx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_dZabcMR0_sendMessage);
}

void Heavy_CircleStrings::cVar_Jk41NPa6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_zrA2ZjTq_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_U4Z28gM9_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_i80OCOSd_sendMessage);
}

void Heavy_CircleStrings::cPack_zWCt3tMm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_RbG2TLPM, 0, m, NULL);
}

void Heavy_CircleStrings::cMsg_zrA2ZjTq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSend_fCqbcVOf_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_2oAftTkm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_JE74ThFn_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_35RX8IrZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.4f, 0, m, &cBinop_SC8WdhTw_sendMessage);
}

void Heavy_CircleStrings::cUnop_46ESDs6G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_35RX8IrZ_sendMessage);
}

void Heavy_CircleStrings::cSlice_4CYpXA4h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_ISAfihpm, 1, m, &cRandom_ISAfihpm_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_6SkPfNfE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_46ESDs6G_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_BIu3T5ZU_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_4CYpXA4h, 0, m, &cSlice_4CYpXA4h_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_ISAfihpm, 0, m, &cRandom_ISAfihpm_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cRandom_ISAfihpm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_6SkPfNfE_sendMessage);
}

void Heavy_CircleStrings::cBinop_ReMkE8IC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_ideLj0nv_sendMessage);
}

void Heavy_CircleStrings::cMsg_SnZmM2PV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_ReMkE8IC, HV_BINOP_POW, 0, m, &cBinop_ReMkE8IC_sendMessage);
}

void Heavy_CircleStrings::cBinop_ideLj0nv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_FWgGFZdU, HV_BINOP_MULTIPLY, 0, m, &cBinop_FWgGFZdU_sendMessage);
}

void Heavy_CircleStrings::cBinop_kzb1znZ9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_yS29xKCK_sendMessage);
}

void Heavy_CircleStrings::cBinop_yS29xKCK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ReMkE8IC, HV_BINOP_POW, 1, m, &cBinop_ReMkE8IC_sendMessage);
  cMsg_SnZmM2PV_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_5asCEX9U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 200.0f);
  cSend_2oAftTkm_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cVar_UXqANjUW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_P1fCc1Vj_sendMessage);
}

void Heavy_CircleStrings::cSend_1QT8aL29_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_DAVY7esw_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_80okK5TI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 25.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_N1ASNuL6, 0, m, NULL);
}

void Heavy_CircleStrings::cCast_9815Vous_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_nwh7cDmd, 0, m, &cVar_nwh7cDmd_sendMessage);
}

void Heavy_CircleStrings::cVar_6JnFojfR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_dXr4jq2u_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_A2U3DdrV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 4000.0f);
  cSend_tmHbK2Ps_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_EDIsnh81_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 25.0f);
  cSend_gkmSejeE_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_5SWb0Lcg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_JANSOnlJ, 0, m, &cDelay_JANSOnlJ_sendMessage);
}

void Heavy_CircleStrings::cDelay_JANSOnlJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_JANSOnlJ, m);
  cVar_onMessage(_c, &Context(_c)->cVar_6JnFojfR, 0, m, &cVar_6JnFojfR_sendMessage);
}

void Heavy_CircleStrings::cCast_cGSNw4BF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_JANSOnlJ, 0, m, &cDelay_JANSOnlJ_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_vlK4gxBH_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_5SWb0Lcg_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_5SWb0Lcg_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_JANSOnlJ, 1, m, &cDelay_JANSOnlJ_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_cGSNw4BF_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cVar_Nx51nojH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cCast_GhQk3VCt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_6JnFojfR, 1, m, &cVar_6JnFojfR_sendMessage);
}

void Heavy_CircleStrings::cSend_N688tfT5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cCast_O3EQm0I5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_80okK5TI_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_Rs7wEHiP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_vlK4gxBH_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cVar_KiuVBcpA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cSend_YCzbv3a7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_DAVY7esw_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cVar_Gcz4I6Xl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cVar_nwh7cDmd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_O3EQm0I5_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_GhQk3VCt_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Rs7wEHiP_sendMessage);
}

void Heavy_CircleStrings::cMsg_dXr4jq2u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 0);
  sLine_onMessage(_c, &Context(_c)->sLine_N1ASNuL6, 0, m, NULL);
}

void Heavy_CircleStrings::cSend_gkmSejeE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cMsg_pWC2Hk8d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSend_1QT8aL29_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_s2RqB4wl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_YORauOUd_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_tmHbK2Ps_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_YORauOUd_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSlice_58JQAKg4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_ya0dsmAJ, 1, m, &cRandom_ya0dsmAJ_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_KXdM1b3s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_xf9XyDP2_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_roB2yjcv_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_58JQAKg4, 0, m, &cSlice_58JQAKg4_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_ya0dsmAJ, 0, m, &cRandom_ya0dsmAJ_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cUnop_xf9XyDP2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_AUPO4n6r_sendMessage);
}

void Heavy_CircleStrings::cRandom_ya0dsmAJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 15.0f, 0, m, &cBinop_KXdM1b3s_sendMessage);
}

void Heavy_CircleStrings::cCast_8sswa6Qn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_BIu3T5ZU_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cBinop_AUPO4n6r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.99f, 0, m, &cBinop_wMEgt5My_sendMessage);
}

void Heavy_CircleStrings::cBinop_FWgGFZdU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_8sswa6Qn_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_avGm5jna_sendMessage);
}

void Heavy_CircleStrings::cVar_fIVeAPPf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_PjKkcAXP, 0, m);
}

void Heavy_CircleStrings::cCast_3slr9hG1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_qDXTL5sw, HV_BINOP_DIVIDE, 1, m, &cBinop_qDXTL5sw_sendMessage);
}

void Heavy_CircleStrings::cMsg_43A9XlSl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 1.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_0dsQpGnI, 0, m, NULL);
}

void Heavy_CircleStrings::cCast_Dlbdddfj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_lsONVYeS_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cMsg_EwnQNqi5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 1.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_0dsQpGnI, 0, m, NULL);
}

void Heavy_CircleStrings::cVar_9NsMQHyl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_HEGB6Fy6_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Dlbdddfj_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_XtCvUX2A_sendMessage);
}

void Heavy_CircleStrings::cBinop_6fmSi1Uw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_3slr9hG1_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_yAH7dtxy_sendMessage);
}

void Heavy_CircleStrings::cBinop_HEGB6Fy6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_WFP7txtm_sendMessage);
}

void Heavy_CircleStrings::cBinop_WFP7txtm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_heY9xzxV, HV_BINOP_POW, 1, m, &cBinop_heY9xzxV_sendMessage);
  cMsg_f4adeBbk_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_f4adeBbk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_heY9xzxV, HV_BINOP_POW, 0, m, &cBinop_heY9xzxV_sendMessage);
}

void Heavy_CircleStrings::cBinop_heY9xzxV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_6fmSi1Uw_sendMessage);
}

void Heavy_CircleStrings::cCast_XtCvUX2A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_EwnQNqi5_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_1AkMogXY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_7eziuokA_sendMessage);
}

void Heavy_CircleStrings::cUnop_7eziuokA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_XKyvDh8Z_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cRandom_ezv0befZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8388610.0f, 0, m, &cBinop_1AkMogXY_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_ivMuJqsG_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_tH7aApmN, 0, m, &cSlice_tH7aApmN_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_ezv0befZ, 0, m, &cRandom_ezv0befZ_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cSlice_tH7aApmN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_ezv0befZ, 1, m, &cRandom_ezv0befZ_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cMsg_XKyvDh8Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 1.0f);
  sVari_onMessage(_c, &Context(_c)->sVari_Pl0G6DD1, m);
}

void Heavy_CircleStrings::cMsg_3ATMhcD7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_AS9KWVri, 1, m, NULL);
}

void Heavy_CircleStrings::cMsg_BanL9KYI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_NqN4qTjS, 0, m, &hTable_NqN4qTjS_sendMessage);
}

void Heavy_CircleStrings::cCast_CscXJBCP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_X4OqYBKs, 0, m, &cDelay_X4OqYBKs_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_FBWVCv29_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_3ATMhcD7_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::hTable_NqN4qTjS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_c6Z8L98C_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_X4OqYBKs, 2, m, &cDelay_X4OqYBKs_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_CscXJBCP_sendMessage);
}

void Heavy_CircleStrings::cSystem_XVGjXlNp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_ky1DBcwB_sendMessage);
}

void Heavy_CircleStrings::cMsg_c2jvN8v3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_XVGjXlNp_sendMessage);
}

void Heavy_CircleStrings::cDelay_X4OqYBKs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_X4OqYBKs, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_x4KOE3cV, 0, m, &cDelay_x4KOE3cV_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_X4OqYBKs, 0, m, &cDelay_X4OqYBKs_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_AS9KWVri, 1, m, NULL);
}

void Heavy_CircleStrings::cMsg_c6Z8L98C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_x4KOE3cV, 2, m, &cDelay_x4KOE3cV_sendMessage);
}

void Heavy_CircleStrings::cMsg_jiI111zV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_NqN4qTjS, 0, m, &hTable_NqN4qTjS_sendMessage);
}

void Heavy_CircleStrings::cBinop_ky1DBcwB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 200.0f, 0, m, &cBinop_m3XYiIpc_sendMessage);
}

void Heavy_CircleStrings::cBinop_m3XYiIpc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_jiI111zV_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_x4KOE3cV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_x4KOE3cV, m);
  cMsg_BanL9KYI_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_0gInztJv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_zasTGQFk, 0, m, &cVar_zasTGQFk_sendMessage);
  cMsg_LR8ev6UM_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_QUWzboGU, 0, m, &cTabhead_QUWzboGU_sendMessage);
}

void Heavy_CircleStrings::sTabread_1tQpuqYU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_zdeDnjTG, HV_BINOP_SUBTRACT, 0, m, &cBinop_zdeDnjTG_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cMsg_LR8ev6UM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ok7LOd8a_sendMessage);
}

void Heavy_CircleStrings::cSystem_ok7LOd8a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_WAdi86UL_sendMessage);
}

void Heavy_CircleStrings::cCast_AMwHTY0Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_wVxklsR1, 0, m, &cDelay_wVxklsR1_sendMessage);
}

void Heavy_CircleStrings::cSystem_GGx6ikvq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_zdeDnjTG, HV_BINOP_SUBTRACT, 1, m, &cBinop_zdeDnjTG_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_WGkBvFeS, 2, m, &cDelay_WGkBvFeS_sendMessage);
}

void Heavy_CircleStrings::cBinop_HhO1IhnH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_tvn2TDl5_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_1tQpuqYU, 0, m, &sTabread_1tQpuqYU_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_AMwHTY0Q_sendMessage);
}

void Heavy_CircleStrings::cBinop_Lc8ZpzSp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_wVxklsR1, 2, m, &cDelay_wVxklsR1_sendMessage);
}

void Heavy_CircleStrings::cBinop_MZCVjXdJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_HhO1IhnH, HV_BINOP_SUBTRACT, 1, m, &cBinop_HhO1IhnH_sendMessage);
}

void Heavy_CircleStrings::cMsg_Ora2jJZ1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_GGx6ikvq_sendMessage);
}

void Heavy_CircleStrings::cTabhead_QUWzboGU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_HhO1IhnH, HV_BINOP_SUBTRACT, 0, m, &cBinop_HhO1IhnH_sendMessage);
}

void Heavy_CircleStrings::cBinop_WAdi86UL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ll84Ss8d, HV_BINOP_MULTIPLY, 0, m, &cBinop_ll84Ss8d_sendMessage);
}

void Heavy_CircleStrings::cDelay_WGkBvFeS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_WGkBvFeS, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_1tQpuqYU, 0, m, &sTabread_1tQpuqYU_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_WGkBvFeS, 0, m, &cDelay_WGkBvFeS_sendMessage);
}

void Heavy_CircleStrings::cBinop_ll84Ss8d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MZCVjXdJ, HV_BINOP_MAX, 0, m, &cBinop_MZCVjXdJ_sendMessage);
}

void Heavy_CircleStrings::cMsg_mKnGw8Cb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_MZCVjXdJ, HV_BINOP_MAX, 1, m, &cBinop_MZCVjXdJ_sendMessage);
}

void Heavy_CircleStrings::cMsg_tvn2TDl5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_wVxklsR1, 0, m, &cDelay_wVxklsR1_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_WGkBvFeS, 0, m, &cDelay_WGkBvFeS_sendMessage);
}

void Heavy_CircleStrings::cDelay_wVxklsR1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_wVxklsR1, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_WGkBvFeS, 0, m, &cDelay_WGkBvFeS_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_1tQpuqYU, 0, m, &sTabread_1tQpuqYU_sendMessage);
}

void Heavy_CircleStrings::cVar_zasTGQFk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Ora2jJZ1_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_zdeDnjTG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_Lc8ZpzSp_sendMessage);
}

void Heavy_CircleStrings::cDelay_3ERgKFp7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_3ERgKFp7, m);
  cMsg_43A9XlSl_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_9eil7gp7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_3ERgKFp7, 0, m, &cDelay_3ERgKFp7_sendMessage);
}

void Heavy_CircleStrings::cCast_QWylQbiQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_3ERgKFp7, 0, m, &cDelay_3ERgKFp7_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_lsONVYeS_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_9eil7gp7_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_9eil7gp7_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_3ERgKFp7, 1, m, &cDelay_3ERgKFp7_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_QWylQbiQ_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cMsg_iufVIBxc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1000.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_qDXTL5sw, HV_BINOP_DIVIDE, 0, m, &cBinop_qDXTL5sw_sendMessage);
}

void Heavy_CircleStrings::cBinop_qDXTL5sw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ll84Ss8d, HV_BINOP_MULTIPLY, 1, m, &cBinop_ll84Ss8d_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_0gInztJv_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_3ERgKFp7, 1, m, &cDelay_3ERgKFp7_sendMessage);
}

void Heavy_CircleStrings::cMsg_tO5bbbTG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 60.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_HEGB6Fy6_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Dlbdddfj_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_XtCvUX2A_sendMessage);
}

void Heavy_CircleStrings::cBinop_OpLGXlqw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_NbRmEjXa, m);
}

void Heavy_CircleStrings::cVar_Zt6Bf1nD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ZQVRhEvd, HV_BINOP_MULTIPLY, 0, m, &cBinop_ZQVRhEvd_sendMessage);
}

void Heavy_CircleStrings::cBinop_RC1wuMh1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ZQVRhEvd, HV_BINOP_MULTIPLY, 1, m, &cBinop_ZQVRhEvd_sendMessage);
}

void Heavy_CircleStrings::cMsg_Yd9Hf3lz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_RC1wuMh1_sendMessage);
}

void Heavy_CircleStrings::cBinop_ZQVRhEvd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_mQFmUWTw_sendMessage);
}

void Heavy_CircleStrings::cSystem_dPHgSIne_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Yd9Hf3lz_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_iFdEsWYa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_dPHgSIne_sendMessage);
}

void Heavy_CircleStrings::cBinop_RiOzlVjG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_OpLGXlqw_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_ysw4IKAR, m);
}

void Heavy_CircleStrings::cBinop_mQFmUWTw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_RiOzlVjG_sendMessage);
}

void Heavy_CircleStrings::cCast_yAH7dtxy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_iufVIBxc_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSlice_DUE60xXY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_cOvgzn7Q_sendMessage);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_kzb1znZ9_sendMessage);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_HEGB6Fy6_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Dlbdddfj_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_XtCvUX2A_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cSlice_XtCCIMgJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 127.0f, 0, m, &cBinop_jQ9otKxF_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_P1fCc1Vj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_woqQOB8x, 0, m, &cPack_woqQOB8x_sendMessage);
}

void Heavy_CircleStrings::cBinop_SC8WdhTw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_EmGmlqHw_sendMessage);
}

void Heavy_CircleStrings::cSend_W3w5S84k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_OsuELRwl_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_avGm5jna_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_9815Vous_sendMessage);
}

void Heavy_CircleStrings::cCast_cOvgzn7Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_roB2yjcv_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cBinop_jQ9otKxF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_otgz6Kqu_sendMessage(_c, 0, m);
  cSend_W3w5S84k_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_otgz6Kqu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_4QONnjek_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_EmGmlqHw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_287b4oh5_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_SIN, m, &cUnop_bdfczrHz_sendMessage);
}

void Heavy_CircleStrings::cUnop_287b4oh5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_adNYKezK, 0, m, &cPack_adNYKezK_sendMessage);
}

void Heavy_CircleStrings::cUnop_bdfczrHz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_f5mAjVXp, 0, m, &cPack_f5mAjVXp_sendMessage);
}

void Heavy_CircleStrings::cMsg_P5sB6SzB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.5f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_EmGmlqHw_sendMessage);
}

void Heavy_CircleStrings::cPack_adNYKezK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_5DPgijNj, 0, m, NULL);
}

void Heavy_CircleStrings::cPack_f5mAjVXp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_RXQA5BSx, 0, m, NULL);
}

void Heavy_CircleStrings::cBinop_wMEgt5My_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_FWgGFZdU, HV_BINOP_MULTIPLY, 1, m, &cBinop_FWgGFZdU_sendMessage);
}

void Heavy_CircleStrings::cPack_woqQOB8x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_HKrXiEjG, 0, m, NULL);
}

void Heavy_CircleStrings::cMsg_xHzYMt2t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.999f);
  sVarf_onMessage(_c, &Context(_c)->sVarf_09UxVico, m);
}

void Heavy_CircleStrings::cReceive_7wiN3w9z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_ZmvledNo_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_k1l8Y0p1, 0, m, &cVar_k1l8Y0p1_sendMessage);
}

void Heavy_CircleStrings::cReceive_8cLqJVy5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_XmgDJbQN, 0, m, &cPack_XmgDJbQN_sendMessage);
}

void Heavy_CircleStrings::cSend_9CxTfRj8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cSend_9GeG4B5s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_tzbko9pQ_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_A7ytY3qk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_AVShmggN_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cReceive_AfQgtSeE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_A7ytY3qk_sendMessage);
}

void Heavy_CircleStrings::cReceive_Axu1m9Vg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_zQyxLGBE_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_2IQ4pNcG_sendMessage);
  cPack_onMessage(_c, &Context(_c)->cPack_iufSNh34, 0, m, &cPack_iufSNh34_sendMessage);
}

void Heavy_CircleStrings::cVar_Ivxh18KH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Gqb4NuEw_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cVar_9sOuS4Oz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cSend_4iNdWl7o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_jeJ3Yki8_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_6i4qVsL8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_S5GgStLj, 0, m, &cVar_S5GgStLj_sendMessage);
}

void Heavy_CircleStrings::cSend_6osw1DIC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_uQCN2ilN_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_8lIMZeDQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Ivxh18KH, 1, m, &cVar_Ivxh18KH_sendMessage);
}

void Heavy_CircleStrings::cCast_90f1g3Mk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_WU0lzJ2I_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_Gqb4NuEw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 0);
  sLine_onMessage(_c, &Context(_c)->sLine_0cjuLgBk, 0, m, NULL);
}

void Heavy_CircleStrings::cVar_7zvZCtdY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cMsg_LHH35Ght_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSend_6osw1DIC_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_O6UGWhxF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cMsg_OKNyVD4M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 4000.0f);
  cSend_ivlGhNCu_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_WHoiFDIR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cMsg_WU0lzJ2I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 25.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_0cjuLgBk, 0, m, NULL);
}

void Heavy_CircleStrings::cVar_S5GgStLj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_90f1g3Mk_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_8lIMZeDQ_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_mMvHFHKF_sendMessage);
}

void Heavy_CircleStrings::cMsg_YQhzhVXG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 25.0f);
  cSend_WHoiFDIR_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cVar_4EPkCYO2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cSend_ivlGhNCu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_jeJ3Yki8_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_AI8GgFli_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_xmx1x5YO_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_xmx1x5YO_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_TeJWlABt, 1, m, &cDelay_TeJWlABt_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_RNtaVbKd_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cCast_RNtaVbKd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_TeJWlABt, 0, m, &cDelay_TeJWlABt_sendMessage);
}

void Heavy_CircleStrings::cDelay_TeJWlABt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_TeJWlABt, m);
  cVar_onMessage(_c, &Context(_c)->cVar_Ivxh18KH, 0, m, &cVar_Ivxh18KH_sendMessage);
}

void Heavy_CircleStrings::cMsg_xmx1x5YO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_TeJWlABt, 0, m, &cDelay_TeJWlABt_sendMessage);
}

void Heavy_CircleStrings::cCast_mMvHFHKF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_AI8GgFli_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cSend_wOvvQsvc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_uQCN2ilN_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_8QjFuyS6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.99f, 0, m, &cBinop_bNvj1ULc_sendMessage);
}

void Heavy_CircleStrings::cMsg_8Ur4xh2K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 200.0f);
  cSend_vD7dMJL3_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_AdRNxfXG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_6i4qVsL8_sendMessage);
}

void Heavy_CircleStrings::cBinop_BkkUCsw0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_hLWTNQsl, 0, m, &cPack_hLWTNQsl_sendMessage);
}

void Heavy_CircleStrings::cBinop_5B0KaNW3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_xlcIy2it_sendMessage);
}

void Heavy_CircleStrings::cSlice_C7I0Td3E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_e6PV01zX, 1, m, &cRandom_e6PV01zX_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cRandom_e6PV01zX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 15.0f, 0, m, &cBinop_5B0KaNW3_sendMessage);
}

void Heavy_CircleStrings::cUnop_xlcIy2it_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_8QjFuyS6_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_ypIkSp7P_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_C7I0Td3E, 0, m, &cSlice_C7I0Td3E_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_e6PV01zX, 0, m, &cRandom_e6PV01zX_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cRandom_7ykyqEz3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_kuEEWMVX_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_AKEPXtcb_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_RuEG0lVD, 0, m, &cSlice_RuEG0lVD_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_7ykyqEz3, 0, m, &cRandom_7ykyqEz3_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cSlice_RuEG0lVD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_7ykyqEz3, 1, m, &cRandom_7ykyqEz3_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_kuEEWMVX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_slvKFEkf_sendMessage);
}

void Heavy_CircleStrings::cUnop_slvKFEkf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_bYhnFsRU_sendMessage);
}

void Heavy_CircleStrings::cBinop_dmbuknoi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_RWJqM0wJ_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_CAuXHeFu, m);
}

void Heavy_CircleStrings::cBinop_iapaANdL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_dmbuknoi_sendMessage);
}

void Heavy_CircleStrings::cBinop_RWJqM0wJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_ASCMEqPZ, m);
}

void Heavy_CircleStrings::cVar_7jcTZ8Y7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MREAUVJW, HV_BINOP_MULTIPLY, 0, m, &cBinop_MREAUVJW_sendMessage);
}

void Heavy_CircleStrings::cMsg_0d0FHQc3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_aL4CHNQ9_sendMessage);
}

void Heavy_CircleStrings::cSystem_uVRsK4De_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_0d0FHQc3_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_xu9bgdvu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_uVRsK4De_sendMessage);
}

void Heavy_CircleStrings::cBinop_MREAUVJW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_iapaANdL_sendMessage);
}

void Heavy_CircleStrings::cBinop_aL4CHNQ9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MREAUVJW, HV_BINOP_MULTIPLY, 1, m, &cBinop_MREAUVJW_sendMessage);
}

void Heavy_CircleStrings::cBinop_36G3uVNc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_ZUMUp6TO_sendMessage);
}

void Heavy_CircleStrings::cRandom_7e2Xs53q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8388610.0f, 0, m, &cBinop_36G3uVNc_sendMessage);
}

void Heavy_CircleStrings::cSlice_IvX8qen2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_7e2Xs53q, 1, m, &cRandom_7e2Xs53q_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cSwitchcase_NfQZvcVn_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_IvX8qen2, 0, m, &cSlice_IvX8qen2_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_7e2Xs53q, 0, m, &cRandom_7e2Xs53q_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cUnop_ZUMUp6TO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_RrSlRz6F_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_RrSlRz6F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 1.0f);
  sVari_onMessage(_c, &Context(_c)->sVari_bCTGNkeS, m);
}

void Heavy_CircleStrings::cCast_DEyPt9Xl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_AuO5f10C_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cCast_IcAxjBN8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_IhgJXAW6_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_IhgJXAW6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 1.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_SSzBTeHO, 0, m, NULL);
}

void Heavy_CircleStrings::cMsg_JXDDkd1p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 1.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_SSzBTeHO, 0, m, NULL);
}

void Heavy_CircleStrings::cBinop_PxGu9dBh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_vgjuqOgJ, HV_BINOP_MULTIPLY, 1, m, &cBinop_vgjuqOgJ_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_tLQ57cvP_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_eLvUhqLn, 1, m, &cDelay_eLvUhqLn_sendMessage);
}

void Heavy_CircleStrings::cCast_VAZU6Xmk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_PxGu9dBh, HV_BINOP_DIVIDE, 1, m, &cBinop_PxGu9dBh_sendMessage);
}

void Heavy_CircleStrings::cCast_X2ickPLt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_yHTd244B_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_ZuN6sSpo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 60.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_MWu7LmJq_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_DEyPt9Xl_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_IcAxjBN8_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_AuO5f10C_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_gpSWUIja_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_gpSWUIja_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_eLvUhqLn, 1, m, &cDelay_eLvUhqLn_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_WUNf45qr_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cCast_WUNf45qr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_eLvUhqLn, 0, m, &cDelay_eLvUhqLn_sendMessage);
}

void Heavy_CircleStrings::cDelay_eLvUhqLn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_eLvUhqLn, m);
  cMsg_JXDDkd1p_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_gpSWUIja_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_eLvUhqLn, 0, m, &cDelay_eLvUhqLn_sendMessage);
}

void Heavy_CircleStrings::cMsg_2Ao0APRz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_cbRKxpD7, 0, m, &hTable_cbRKxpD7_sendMessage);
}

void Heavy_CircleStrings::cMsg_5eN5oJWM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_cbRKxpD7, 0, m, &hTable_cbRKxpD7_sendMessage);
}

void Heavy_CircleStrings::cBinop_A9zKGw3W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_2Ao0APRz_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_JeO8wv4O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 200.0f, 0, m, &cBinop_A9zKGw3W_sendMessage);
}

void Heavy_CircleStrings::cDelay_M9Ko9qZd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_M9Ko9qZd, m);
  cMsg_5eN5oJWM_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_RGLHZEzN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_hSX1EpJ3, 1, m, NULL);
}

void Heavy_CircleStrings::cMsg_c3E9ZBeK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_M9Ko9qZd, 2, m, &cDelay_M9Ko9qZd_sendMessage);
}

void Heavy_CircleStrings::hTable_cbRKxpD7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_c3E9ZBeK_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_eh1caV5Q, 2, m, &cDelay_eh1caV5Q_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_jFgDKB2q_sendMessage);
}

void Heavy_CircleStrings::cSystem_qLiLNlhq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_JeO8wv4O_sendMessage);
}

void Heavy_CircleStrings::cMsg_ww2CwSLM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_qLiLNlhq_sendMessage);
}

void Heavy_CircleStrings::cDelay_eh1caV5Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_eh1caV5Q, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_M9Ko9qZd, 0, m, &cDelay_M9Ko9qZd_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_eh1caV5Q, 0, m, &cDelay_eh1caV5Q_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_hSX1EpJ3, 1, m, NULL);
}

void Heavy_CircleStrings::cCast_jFgDKB2q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_eh1caV5Q, 0, m, &cDelay_eh1caV5Q_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_ovoxmz8y_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_RGLHZEzN_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cVar_jTUi3JbN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_MWu7LmJq_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_DEyPt9Xl_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_IcAxjBN8_sendMessage);
}

void Heavy_CircleStrings::cMsg_5IWgotkJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_XbmZh7TA_sendMessage);
}

void Heavy_CircleStrings::cCast_7wvwmS9r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_jwCjPNLR, 0, m, &cDelay_jwCjPNLR_sendMessage);
}

void Heavy_CircleStrings::cTabhead_GkyoYgi9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MzoCxi9O, HV_BINOP_SUBTRACT, 0, m, &cBinop_MzoCxi9O_sendMessage);
}

void Heavy_CircleStrings::cBinop_MzoCxi9O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_bEsWLUyt_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_kZm1Pjc9, 0, m, &sTabread_kZm1Pjc9_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_7wvwmS9r_sendMessage);
}

void Heavy_CircleStrings::cBinop_Ob2ny5BA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_vgjuqOgJ, HV_BINOP_MULTIPLY, 0, m, &cBinop_vgjuqOgJ_sendMessage);
}

void Heavy_CircleStrings::cMsg_R2XJ3ffu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_RkPZOlLn, HV_BINOP_MAX, 1, m, &cBinop_RkPZOlLn_sendMessage);
}

void Heavy_CircleStrings::cBinop_RkPZOlLn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MzoCxi9O, HV_BINOP_SUBTRACT, 1, m, &cBinop_MzoCxi9O_sendMessage);
}

void Heavy_CircleStrings::cBinop_S6IOuzSE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_bxhxqn6j_sendMessage);
}

void Heavy_CircleStrings::cSystem_XbmZh7TA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_S6IOuzSE, HV_BINOP_SUBTRACT, 1, m, &cBinop_S6IOuzSE_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_hx3o5pIP, 2, m, &cDelay_hx3o5pIP_sendMessage);
}

void Heavy_CircleStrings::cMsg_bEsWLUyt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_jwCjPNLR, 0, m, &cDelay_jwCjPNLR_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_hx3o5pIP, 0, m, &cDelay_hx3o5pIP_sendMessage);
}

void Heavy_CircleStrings::cBinop_bxhxqn6j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_jwCjPNLR, 2, m, &cDelay_jwCjPNLR_sendMessage);
}

void Heavy_CircleStrings::cVar_dU4OaLNw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_5IWgotkJ_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_hx3o5pIP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_hx3o5pIP, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_kZm1Pjc9, 0, m, &sTabread_kZm1Pjc9_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_hx3o5pIP, 0, m, &cDelay_hx3o5pIP_sendMessage);
}

void Heavy_CircleStrings::cDelay_jwCjPNLR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_jwCjPNLR, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_hx3o5pIP, 0, m, &cDelay_hx3o5pIP_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_kZm1Pjc9, 0, m, &sTabread_kZm1Pjc9_sendMessage);
}

void Heavy_CircleStrings::sTabread_kZm1Pjc9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_S6IOuzSE, HV_BINOP_SUBTRACT, 0, m, &cBinop_S6IOuzSE_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cCast_tLQ57cvP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_dU4OaLNw, 0, m, &cVar_dU4OaLNw_sendMessage);
  cMsg_dzkYAGAu_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_GkyoYgi9, 0, m, &cTabhead_GkyoYgi9_sendMessage);
}

void Heavy_CircleStrings::cBinop_vgjuqOgJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_RkPZOlLn, HV_BINOP_MAX, 0, m, &cBinop_RkPZOlLn_sendMessage);
}

void Heavy_CircleStrings::cMsg_dzkYAGAu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_yHp3okfe_sendMessage);
}

void Heavy_CircleStrings::cSystem_yHp3okfe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_Ob2ny5BA_sendMessage);
}

void Heavy_CircleStrings::cBinop_5DYETMC6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_DNPkBXdg, HV_BINOP_POW, 1, m, &cBinop_DNPkBXdg_sendMessage);
  cMsg_WbJg88Fs_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_DNPkBXdg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_Rjv3b7wZ_sendMessage);
}

void Heavy_CircleStrings::cBinop_MWu7LmJq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_5DYETMC6_sendMessage);
}

void Heavy_CircleStrings::cBinop_Rjv3b7wZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_VAZU6Xmk_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_X2ickPLt_sendMessage);
}

void Heavy_CircleStrings::cMsg_WbJg88Fs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_DNPkBXdg, HV_BINOP_POW, 0, m, &cBinop_DNPkBXdg_sendMessage);
}

void Heavy_CircleStrings::cMsg_yHTd244B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1000.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_PxGu9dBh, HV_BINOP_DIVIDE, 0, m, &cBinop_PxGu9dBh_sendMessage);
}

void Heavy_CircleStrings::cSend_PEcK7y0d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_4X3I590h_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_68r0KC5q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_GgM9B4jF_sendMessage);
}

void Heavy_CircleStrings::cBinop_GgM9B4jF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ezCYhhbS, HV_BINOP_MULTIPLY, 0, m, &cBinop_ezCYhhbS_sendMessage);
}

void Heavy_CircleStrings::cBinop_iDqNu9aU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_68r0KC5q, HV_BINOP_POW, 1, m, &cBinop_68r0KC5q_sendMessage);
  cMsg_qJ7Q5vPw_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_jWb9ZCZm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_iDqNu9aU_sendMessage);
}

void Heavy_CircleStrings::cMsg_qJ7Q5vPw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_68r0KC5q, HV_BINOP_POW, 0, m, &cBinop_68r0KC5q_sendMessage);
}

void Heavy_CircleStrings::cMsg_QnhqZtEq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.999f);
  sVarf_onMessage(_c, &Context(_c)->sVarf_RPjk0Dgz, m);
}

void Heavy_CircleStrings::cSlice_8cIgAeXS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 127.0f, 0, m, &cBinop_hup7RgDl_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cSlice_AwbkDAjm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_aXMssrko_sendMessage);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_jWb9ZCZm_sendMessage);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_MWu7LmJq_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_DEyPt9Xl_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_IcAxjBN8_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cVar_BaGdM4qH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_BkkUCsw0_sendMessage);
}

void Heavy_CircleStrings::cCast_aXMssrko_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_ypIkSp7P_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cBinop_bNvj1ULc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ezCYhhbS, HV_BINOP_MULTIPLY, 1, m, &cBinop_ezCYhhbS_sendMessage);
}

void Heavy_CircleStrings::cBinop_bYhnFsRU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.4f, 0, m, &cBinop_n7Zc3SxW_sendMessage);
}

void Heavy_CircleStrings::cSend_dVJuwuOA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_v3oGutji_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_ezCYhhbS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_lqpAh4II_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_AdRNxfXG_sendMessage);
}

void Heavy_CircleStrings::cPack_hLWTNQsl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_MfDGS6MN, 0, m, NULL);
}

void Heavy_CircleStrings::cPack_0lZ8wKKw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_hq14cxp6, 0, m, NULL);
}

void Heavy_CircleStrings::cUnop_hkf8ZyWo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_CGWss5JJ, 0, m, &cPack_CGWss5JJ_sendMessage);
}

void Heavy_CircleStrings::cPack_CGWss5JJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_i3VseCms, 0, m, NULL);
}

void Heavy_CircleStrings::cMsg_EMQW30Ti_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.5f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_XNYq2siA_sendMessage);
}

void Heavy_CircleStrings::cUnop_3IR9uSWD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_0lZ8wKKw, 0, m, &cPack_0lZ8wKKw_sendMessage);
}

void Heavy_CircleStrings::cBinop_XNYq2siA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_3IR9uSWD_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_SIN, m, &cUnop_hkf8ZyWo_sendMessage);
}

void Heavy_CircleStrings::cBinop_hup7RgDl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_dVJuwuOA_sendMessage(_c, 0, m);
  cSend_PEcK7y0d_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_lqpAh4II_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_AKEPXtcb_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cBinop_n7Zc3SxW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_XNYq2siA_sendMessage);
}

void Heavy_CircleStrings::cSend_vD7dMJL3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_tAY3cULM_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cVar_urvmPGFa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_OJjQyx7F, 0, m);
}

void Heavy_CircleStrings::cReceive_DAVY7esw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_VpW71EE8, m);
}

void Heavy_CircleStrings::cReceive_DBoGnCsS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_j5P5Etez_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_j4nRoqpA, 0, m, &cVar_j4nRoqpA_sendMessage);
}

void Heavy_CircleStrings::cReceive_Doeln2j3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_glQhg9bG, m);
}

void Heavy_CircleStrings::cPack_9tnPgoYv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_b0UNseK8, 0, m, NULL);
}

void Heavy_CircleStrings::cMsg_EbTason2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSend_RWanfeAY_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_HtY64ewu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_2STqfbKn_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cVar_d5hYptRh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_EbTason2_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_qoGHzXoH_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_2b1NMNfW_sendMessage);
}

void Heavy_CircleStrings::cSend_RWanfeAY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_mMi3D1gg_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cVar_R43hpoGw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_HtY64ewu_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_2b1NMNfW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_mmDIZt5G, 0, m, &cIf_mmDIZt5G_sendMessage);
}

void Heavy_CircleStrings::cBinop_6gtqa92x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_qtmXJ6NO_sendMessage);
}

void Heavy_CircleStrings::cMsg_TsR2GQOE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_azcWMMy8, HV_BINOP_POW, 0, m, &cBinop_azcWMMy8_sendMessage);
}

void Heavy_CircleStrings::cBinop_azcWMMy8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_9tnPgoYv, 0, m, &cPack_9tnPgoYv_sendMessage);
}

void Heavy_CircleStrings::cBinop_bO6IcRPn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_mmDIZt5G, 1, m, &cIf_mmDIZt5G_sendMessage);
}

void Heavy_CircleStrings::cIf_mmDIZt5G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_wPwewbN1_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_qAMdIR2B_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_qAMdIR2B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_6gtqa92x_sendMessage);
}

void Heavy_CircleStrings::cCast_qoGHzXoH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_bO6IcRPn_sendMessage);
}

void Heavy_CircleStrings::cBinop_qtmXJ6NO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_azcWMMy8, HV_BINOP_POW, 1, m, &cBinop_azcWMMy8_sendMessage);
  cMsg_TsR2GQOE_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_wPwewbN1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_9tnPgoYv, 0, m, &cPack_9tnPgoYv_sendMessage);
}

void Heavy_CircleStrings::cBinop_2h47LjGu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_mufoUR7L, HV_BINOP_EQ, 0, m, &cBinop_mufoUR7L_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_bIRRz79x_sendMessage);
}

void Heavy_CircleStrings::cCast_8ar6QPV4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_cKRqcgtb, 1, m, &cIf_cKRqcgtb_sendMessage);
}

void Heavy_CircleStrings::cIf_cKRqcgtb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSend_qcBgEtaq_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cIf_3cUzpd2y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSend_9GeG4B5s_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cIf_lT3yyo1g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSend_qcBgEtaq_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cUnop_1Khzfx1h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_Yk3n9uoQ_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_mufoUR7L, HV_BINOP_EQ, 1, m, &cBinop_mufoUR7L_sendMessage);
}

void Heavy_CircleStrings::cVar_p2n5RL08_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_z1SsqQq5_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_znGAkzjR, 0, m, &cIf_znGAkzjR_sendMessage);
}

void Heavy_CircleStrings::cUnop_cMbm9lTh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_Yk3n9uoQ_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_mufoUR7L, HV_BINOP_EQ, 1, m, &cBinop_mufoUR7L_sendMessage);
}

void Heavy_CircleStrings::cBinop_z1SsqQq5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_znGAkzjR, 1, m, &cIf_znGAkzjR_sendMessage);
}

void Heavy_CircleStrings::cIf_znGAkzjR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_cMbm9lTh_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_1Khzfx1h_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cCast_Yi8UkOy6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_3cUzpd2y, 1, m, &cIf_3cUzpd2y_sendMessage);
}

void Heavy_CircleStrings::cBinop_Yk3n9uoQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_n4lI5xzO_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_e6NJyAcp_sendMessage);
}

void Heavy_CircleStrings::cBinop_bIRRz79x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_9CxTfRj8_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_e6NJyAcp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_lT3yyo1g, 1, m, &cIf_lT3yyo1g_sendMessage);
}

void Heavy_CircleStrings::cBinop_mufoUR7L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Yi8UkOy6_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_8ar6QPV4_sendMessage);
}

void Heavy_CircleStrings::cCast_n4lI5xzO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_nb6VTrFm, 1, m, &cIf_nb6VTrFm_sendMessage);
}

void Heavy_CircleStrings::cIf_nb6VTrFm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSend_9GeG4B5s_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cSlice_9zhNSftQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cIf_onMessage(_c, &Context(_c)->cIf_cKRqcgtb, 0, m, &cIf_cKRqcgtb_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_lT3yyo1g, 0, m, &cIf_lT3yyo1g_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cSlice_Kgr6aHNB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cIf_onMessage(_c, &Context(_c)->cIf_nb6VTrFm, 0, m, &cIf_nb6VTrFm_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_3cUzpd2y, 0, m, &cIf_3cUzpd2y_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cSlice_d7xusZhg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_2h47LjGu_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cReceive_Gy7xm3tI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_VpBFxQUK_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_JpkyQM6K_sendMessage);
}

void Heavy_CircleStrings::cBinop_0DhjWYMR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_c4OhMovz, 0, m, &cPack_c4OhMovz_sendMessage);
}

void Heavy_CircleStrings::cBinop_31yCYjXr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_RLFI5dQZ_sendMessage);
}

void Heavy_CircleStrings::cIf_6XlQC6QE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_KUPFdFbp_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_c7yszGlg_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cCast_Ieib1wKz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_6XlQC6QE, 0, m, &cIf_6XlQC6QE_sendMessage);
}

void Heavy_CircleStrings::cMsg_KUPFdFbp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_c4OhMovz, 0, m, &cPack_c4OhMovz_sendMessage);
}

void Heavy_CircleStrings::cBinop_RLFI5dQZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_0DhjWYMR, HV_BINOP_POW, 1, m, &cBinop_0DhjWYMR_sendMessage);
  cMsg_RyTfGja8_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_RyTfGja8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_0DhjWYMR, HV_BINOP_POW, 0, m, &cBinop_0DhjWYMR_sendMessage);
}

void Heavy_CircleStrings::cBinop_c7yszGlg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_31yCYjXr_sendMessage);
}

void Heavy_CircleStrings::cCast_czoTbpnJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_rrfp8pgZ_sendMessage);
}

void Heavy_CircleStrings::cBinop_rrfp8pgZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_6XlQC6QE, 1, m, &cIf_6XlQC6QE_sendMessage);
}

void Heavy_CircleStrings::cVar_qCp5kXVB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_iEVYCCyb_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_6o1NmhGr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSend_LzMCK6hO_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_LzMCK6hO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_ZTsVfkF6_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cVar_DvQkykCf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_6o1NmhGr_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_czoTbpnJ_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Ieib1wKz_sendMessage);
}

void Heavy_CircleStrings::cPack_c4OhMovz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_PiSlEksa, 0, m, NULL);
}

void Heavy_CircleStrings::cSend_iEVYCCyb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_Ziy08ppj_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cReceive_JE74ThFn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_s2RqB4wl_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_KiuVBcpA, 0, m, &cVar_KiuVBcpA_sendMessage);
}

void Heavy_CircleStrings::cSend_JGUkR6QZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_s43HyO1s_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cReceive_Kg61wDyb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cReceive_MIOk4mXq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_nBGSYJ0W, 1, m, &cVar_nBGSYJ0W_sendMessage);
}

void Heavy_CircleStrings::cReceive_N06e9h3s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_z8IefsVX, 0, m, &cPack_z8IefsVX_sendMessage);
}

void Heavy_CircleStrings::cReceive_NaXnfwrH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_iiz5HAMK, 0, m, &cVar_iiz5HAMK_sendMessage);
  cPack_onMessage(_c, &Context(_c)->cPack_ghqsILSs, 0, m, &cPack_ghqsILSs_sendMessage);
}

void Heavy_CircleStrings::cReceive_OsuELRwl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_woqQOB8x, 0, m, &cPack_woqQOB8x_sendMessage);
}

void Heavy_CircleStrings::cReceive_Q3DzEQIL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_GQp6DQ0Y_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_W1FCX2at, 0, m, &cVar_W1FCX2at_sendMessage);
}

void Heavy_CircleStrings::cReceive_SUCZCmyy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_GClz2FXh, m);
}

void Heavy_CircleStrings::cReceive_UX34zg3Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_zGPE9556_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_dYBoEfrx, 0, m, &cVar_dYBoEfrx_sendMessage);
}

void Heavy_CircleStrings::cReceive_Ugl1BgiH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_7hU28yzh_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_CP2DBLnH, 0, m, &cVar_CP2DBLnH_sendMessage);
}

void Heavy_CircleStrings::cReceive_UuV7deFy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 2.0f, 0, m, &cBinop_bS4JAPIz_sendMessage);
}

void Heavy_CircleStrings::cReceive_VeAdaoIm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_ActXizl2, 0, m, &cPack_ActXizl2_sendMessage);
}

void Heavy_CircleStrings::cReceive_XsxvudCG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_hGnCbDbN, 1, m, &cVar_hGnCbDbN_sendMessage);
}

void Heavy_CircleStrings::cCast_1j0TwZna_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_rAF2r9pj_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cBinop_2CBW0Tk2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_ppCawPAG_sendMessage(_c, 0, m);
  cSend_ae7kdqUJ_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_1nzjyNj3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_SEu0htSN_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_SIN, m, &cUnop_DcWkxrwC_sendMessage);
}

void Heavy_CircleStrings::cPack_E2Te6apB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_PLMvWoaK, 0, m, NULL);
}

void Heavy_CircleStrings::cUnop_SEu0htSN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_LYILugvs, 0, m, &cPack_LYILugvs_sendMessage);
}

void Heavy_CircleStrings::cPack_LYILugvs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_qkVQcUvG, 0, m, NULL);
}

void Heavy_CircleStrings::cMsg_MSo8HhWm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.5f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_1nzjyNj3_sendMessage);
}

void Heavy_CircleStrings::cUnop_DcWkxrwC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_E2Te6apB, 0, m, &cPack_E2Te6apB_sendMessage);
}

void Heavy_CircleStrings::cCast_70E9SST3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_DtPhvPah_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cBinop_7JWbtEUh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.99f, 0, m, &cBinop_XSLYdBna_sendMessage);
}

void Heavy_CircleStrings::cRandom_6Xw8jvRr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 15.0f, 0, m, &cBinop_bHz7q75y_sendMessage);
}

void Heavy_CircleStrings::cUnop_AIEqCPWU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_7JWbtEUh_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_DtPhvPah_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_YcP5whC6, 0, m, &cSlice_YcP5whC6_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_6Xw8jvRr, 0, m, &cRandom_6Xw8jvRr_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cSlice_YcP5whC6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_6Xw8jvRr, 1, m, &cRandom_6Xw8jvRr_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_bHz7q75y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_AIEqCPWU_sendMessage);
}

void Heavy_CircleStrings::cSend_J7tfB487_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_7wiN3w9z_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_0gVgvaAf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 4000.0f);
  cSend_nYYVQKjy_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_1FOJ7tkc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_rRzZCgAG, 1, m, &cVar_rRzZCgAG_sendMessage);
}

void Heavy_CircleStrings::cVar_ggHtLBX3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_p9Q784Je_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_1FOJ7tkc_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_K68lKhS2_sendMessage);
}

void Heavy_CircleStrings::cVar_dYBoEfrx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cMsg_Ji6gv0SC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 25.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_x3o5SAqa, 0, m, NULL);
}

void Heavy_CircleStrings::cCast_K68lKhS2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_fVtlpXqV_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cVar_j4nRoqpA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cVar_rRzZCgAG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_NDinRmyc_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_NDinRmyc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 0);
  sLine_onMessage(_c, &Context(_c)->sLine_x3o5SAqa, 0, m, NULL);
}

void Heavy_CircleStrings::cMsg_PTgl4Ofz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSend_SKm5mvnu_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_SKm5mvnu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_SUCZCmyy_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cVar_k1l8Y0p1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cSend_ZmvledNo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_mcCQqEOf_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_8j3KsQL7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_8j3KsQL7, m);
  cVar_onMessage(_c, &Context(_c)->cVar_rRzZCgAG, 0, m, &cVar_rRzZCgAG_sendMessage);
}

void Heavy_CircleStrings::cMsg_B9twmMz5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_8j3KsQL7, 0, m, &cDelay_8j3KsQL7_sendMessage);
}

void Heavy_CircleStrings::cCast_GrNtTg0B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_8j3KsQL7, 0, m, &cDelay_8j3KsQL7_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_fVtlpXqV_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_B9twmMz5_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_B9twmMz5_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_8j3KsQL7, 1, m, &cDelay_8j3KsQL7_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_GrNtTg0B_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cMsg_aTh5Iipb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 25.0f);
  cSend_u0WLPROZ_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_j5P5Etez_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cCast_kVrCvmNG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ggHtLBX3, 0, m, &cVar_ggHtLBX3_sendMessage);
}

void Heavy_CircleStrings::cSend_nYYVQKjy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_mcCQqEOf_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_p9Q784Je_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Ji6gv0SC_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_u0WLPROZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cSend_zGPE9556_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_SUCZCmyy_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_Lohgnt4I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_1j0TwZna_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_t3Rt5GNg_sendMessage);
}

void Heavy_CircleStrings::cVar_n2HO47KA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_eqlxABbB, 0, m);
}

void Heavy_CircleStrings::cBinop_VDxtH6hS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.4f, 0, m, &cBinop_VcviOus8_sendMessage);
}

void Heavy_CircleStrings::cBinop_VcviOus8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_1nzjyNj3_sendMessage);
}

void Heavy_CircleStrings::cBinop_XSLYdBna_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Lohgnt4I, HV_BINOP_MULTIPLY, 1, m, &cBinop_Lohgnt4I_sendMessage);
}

void Heavy_CircleStrings::cPack_XmgDJbQN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_8GBw3dsw, 0, m, NULL);
}

void Heavy_CircleStrings::cVar_ToQ7iRm0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_lEjFGiEC, HV_BINOP_MULTIPLY, 0, m, &cBinop_lEjFGiEC_sendMessage);
}

void Heavy_CircleStrings::cMsg_jHxaDnBq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_zxpxkyZX_sendMessage);
}

void Heavy_CircleStrings::cSystem_zxpxkyZX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_XsWBN3nS_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_QNTNBb7M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_lEjFGiEC, HV_BINOP_MULTIPLY, 1, m, &cBinop_lEjFGiEC_sendMessage);
}

void Heavy_CircleStrings::cMsg_XsWBN3nS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_QNTNBb7M_sendMessage);
}

void Heavy_CircleStrings::cBinop_lEjFGiEC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_w30cdhzP_sendMessage);
}

void Heavy_CircleStrings::cBinop_jB6lpTcA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_LnaqLmTh, m);
}

void Heavy_CircleStrings::cBinop_nTmJt8R7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_jB6lpTcA_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_ZnRuqqxT, m);
}

void Heavy_CircleStrings::cBinop_w30cdhzP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_nTmJt8R7_sendMessage);
}

void Heavy_CircleStrings::cCast_7S9RSbvK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ggccvMw2_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_BuVjOa4L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_Xaucsfru_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cSwitchcase_Xaucsfru_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_smhIyQh1_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_smhIyQh1_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_hACHniE7, 1, m, &cDelay_hACHniE7_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_f0QedGcd_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cCast_f0QedGcd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_hACHniE7, 0, m, &cDelay_hACHniE7_sendMessage);
}

void Heavy_CircleStrings::cDelay_hACHniE7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_hACHniE7, m);
  cMsg_Fa7CGMtR_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_smhIyQh1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_hACHniE7, 0, m, &cDelay_hACHniE7_sendMessage);
}

void Heavy_CircleStrings::cMsg_FILHcXut_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 60.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_D4crHq4S_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_BuVjOa4L_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_tnKTLXoz_sendMessage);
}

void Heavy_CircleStrings::cMsg_Fa7CGMtR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 1.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_GG7pXXXs, 0, m, NULL);
}

void Heavy_CircleStrings::cCast_Fd5o81zJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_cxHYCmBj, HV_BINOP_DIVIDE, 1, m, &cBinop_cxHYCmBj_sendMessage);
}

void Heavy_CircleStrings::cBinop_1hiJY9Wh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_UKaWzyTm_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_N9GYmeX7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_uKVPTZCB_sendMessage);
}

void Heavy_CircleStrings::cSystem_uKVPTZCB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_ywl0oAeO_sendMessage);
}

void Heavy_CircleStrings::cMsg_G8IHhmK8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_O3JTekn1, 0, m, &hTable_O3JTekn1_sendMessage);
}

void Heavy_CircleStrings::hTable_O3JTekn1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ym2vO4mX_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_f5RVO8IR, 2, m, &cDelay_f5RVO8IR_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Yrtk5C9y_sendMessage);
}

void Heavy_CircleStrings::cMsg_UKaWzyTm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_O3JTekn1, 0, m, &hTable_O3JTekn1_sendMessage);
}

void Heavy_CircleStrings::cMsg_UvK9rPQ1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_P8WT8aZo, 1, m, NULL);
}

void Heavy_CircleStrings::cCast_Yrtk5C9y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_f5RVO8IR, 0, m, &cDelay_f5RVO8IR_sendMessage);
}

void Heavy_CircleStrings::cDelay_bPHKzllz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_bPHKzllz, m);
  cMsg_G8IHhmK8_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_f5RVO8IR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_f5RVO8IR, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_bPHKzllz, 0, m, &cDelay_bPHKzllz_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_f5RVO8IR, 0, m, &cDelay_f5RVO8IR_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_P8WT8aZo, 1, m, NULL);
}

void Heavy_CircleStrings::cSwitchcase_pfRY3RTe_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_UvK9rPQ1_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cMsg_ym2vO4mX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_bPHKzllz, 2, m, &cDelay_bPHKzllz_sendMessage);
}

void Heavy_CircleStrings::cBinop_ywl0oAeO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 200.0f, 0, m, &cBinop_1hiJY9Wh_sendMessage);
}

void Heavy_CircleStrings::cMsg_I4cTZBTF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 1.0f);
  sVari_onMessage(_c, &Context(_c)->sVari_0hXYUTZf, m);
}

void Heavy_CircleStrings::cSwitchcase_6QmZHFgI_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_ruOZJcg1, 0, m, &cSlice_ruOZJcg1_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_TyFfADbn, 0, m, &cRandom_TyFfADbn_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cUnop_OyaBRWpn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_I4cTZBTF_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cRandom_TyFfADbn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8388610.0f, 0, m, &cBinop_ZZqo5AYi_sendMessage);
}

void Heavy_CircleStrings::cBinop_ZZqo5AYi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_OyaBRWpn_sendMessage);
}

void Heavy_CircleStrings::cSlice_ruOZJcg1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_TyFfADbn, 1, m, &cRandom_TyFfADbn_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_3Yz9bYNA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_PuXKH1Ux, HV_BINOP_POW, 1, m, &cBinop_PuXKH1Ux_sendMessage);
  cMsg_pCHbK4hC_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_D4crHq4S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_3Yz9bYNA_sendMessage);
}

void Heavy_CircleStrings::cBinop_Hc4sMo5r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Fd5o81zJ_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_7S9RSbvK_sendMessage);
}

void Heavy_CircleStrings::cBinop_PuXKH1Ux_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_Hc4sMo5r_sendMessage);
}

void Heavy_CircleStrings::cMsg_pCHbK4hC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_PuXKH1Ux, HV_BINOP_POW, 0, m, &cBinop_PuXKH1Ux_sendMessage);
}

void Heavy_CircleStrings::cBinop_cxHYCmBj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ifcYMbe1, HV_BINOP_MULTIPLY, 1, m, &cBinop_ifcYMbe1_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ANR1epit_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_hACHniE7, 1, m, &cDelay_hACHniE7_sendMessage);
}

void Heavy_CircleStrings::cMsg_ggccvMw2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1000.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_cxHYCmBj, HV_BINOP_DIVIDE, 0, m, &cBinop_cxHYCmBj_sendMessage);
}

void Heavy_CircleStrings::cMsg_nB8zyn4R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 1.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_GG7pXXXs, 0, m, NULL);
}

void Heavy_CircleStrings::cCast_tnKTLXoz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_nB8zyn4R_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_0taoIiC2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_K0ba2nC0_sendMessage);
}

void Heavy_CircleStrings::cBinop_2VNMDn0i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ifcYMbe1, HV_BINOP_MULTIPLY, 0, m, &cBinop_ifcYMbe1_sendMessage);
}

void Heavy_CircleStrings::cCast_3cMEi2Kg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_pW10xPPi, 0, m, &cDelay_pW10xPPi_sendMessage);
}

void Heavy_CircleStrings::cVar_6KcFhRxf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_0taoIiC2_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_ANR1epit_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_6KcFhRxf, 0, m, &cVar_6KcFhRxf_sendMessage);
  cMsg_MoUbWGXF_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_qLswlBtL, 0, m, &cTabhead_qLswlBtL_sendMessage);
}

void Heavy_CircleStrings::cBinop_JYstxLBV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_mKP0Rp6l_sendMessage);
}

void Heavy_CircleStrings::cSystem_K0ba2nC0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_JYstxLBV, HV_BINOP_SUBTRACT, 1, m, &cBinop_JYstxLBV_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_eW4R0HAr, 2, m, &cDelay_eW4R0HAr_sendMessage);
}

void Heavy_CircleStrings::cBinop_U8Ih02Gg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_cdOF4MiC, HV_BINOP_SUBTRACT, 1, m, &cBinop_cdOF4MiC_sendMessage);
}

void Heavy_CircleStrings::cBinop_cdOF4MiC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_zwPgNfZq_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_mUArOlqK, 0, m, &sTabread_mUArOlqK_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_3cMEi2Kg_sendMessage);
}

void Heavy_CircleStrings::cMsg_MoUbWGXF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_dRkzStc1_sendMessage);
}

void Heavy_CircleStrings::cSystem_dRkzStc1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_2VNMDn0i_sendMessage);
}

void Heavy_CircleStrings::cDelay_eW4R0HAr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_eW4R0HAr, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_mUArOlqK, 0, m, &sTabread_mUArOlqK_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_eW4R0HAr, 0, m, &cDelay_eW4R0HAr_sendMessage);
}

void Heavy_CircleStrings::cBinop_ifcYMbe1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_U8Ih02Gg, HV_BINOP_MAX, 0, m, &cBinop_U8Ih02Gg_sendMessage);
}

void Heavy_CircleStrings::cMsg_jwQ1Cmvw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_U8Ih02Gg, HV_BINOP_MAX, 1, m, &cBinop_U8Ih02Gg_sendMessage);
}

void Heavy_CircleStrings::cBinop_mKP0Rp6l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_pW10xPPi, 2, m, &cDelay_pW10xPPi_sendMessage);
}

void Heavy_CircleStrings::sTabread_mUArOlqK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_JYstxLBV, HV_BINOP_SUBTRACT, 0, m, &cBinop_JYstxLBV_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cDelay_pW10xPPi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_pW10xPPi, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_eW4R0HAr, 0, m, &cDelay_eW4R0HAr_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_mUArOlqK, 0, m, &sTabread_mUArOlqK_sendMessage);
}

void Heavy_CircleStrings::cTabhead_qLswlBtL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_cdOF4MiC, HV_BINOP_SUBTRACT, 0, m, &cBinop_cdOF4MiC_sendMessage);
}

void Heavy_CircleStrings::cMsg_zwPgNfZq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_pW10xPPi, 0, m, &cDelay_pW10xPPi_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_eW4R0HAr, 0, m, &cDelay_eW4R0HAr_sendMessage);
}

void Heavy_CircleStrings::cVar_qqwJdVRt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_D4crHq4S_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_BuVjOa4L_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_tnKTLXoz_sendMessage);
}

void Heavy_CircleStrings::cSend_ae7kdqUJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_8cLqJVy5_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_eKc86o7b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.999f);
  sVarf_onMessage(_c, &Context(_c)->sVarf_0vJoTVKz, m);
}

void Heavy_CircleStrings::cSlice_8XV4gloF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 127.0f, 0, m, &cBinop_2CBW0Tk2_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cSlice_z9CKtwAU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_70E9SST3_sendMessage);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_QS92CIuz_sendMessage);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_D4crHq4S_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_BuVjOa4L_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_tnKTLXoz_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_kaWA0k3x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_XmgDJbQN, 0, m, &cPack_XmgDJbQN_sendMessage);
}

void Heavy_CircleStrings::cBinop_JGRCYHPf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_TU4x3khE_sendMessage);
}

void Heavy_CircleStrings::cBinop_QS92CIuz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_o6PpaNAI_sendMessage);
}

void Heavy_CircleStrings::cBinop_TU4x3khE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Lohgnt4I, HV_BINOP_MULTIPLY, 0, m, &cBinop_Lohgnt4I_sendMessage);
}

void Heavy_CircleStrings::cBinop_o6PpaNAI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_JGRCYHPf, HV_BINOP_POW, 1, m, &cBinop_JGRCYHPf_sendMessage);
  cMsg_pBpFjPk9_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_pBpFjPk9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_JGRCYHPf, HV_BINOP_POW, 0, m, &cBinop_JGRCYHPf_sendMessage);
}

void Heavy_CircleStrings::cMsg_oUYHEdeb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 200.0f);
  cSend_J7tfB487_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_ppCawPAG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_UX34zg3Z_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_SKKq1JqQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_l7WeYRmB_sendMessage);
}

void Heavy_CircleStrings::cRandom_iWTFkthf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_SKKq1JqQ_sendMessage);
}

void Heavy_CircleStrings::cUnop_l7WeYRmB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_VDxtH6hS_sendMessage);
}

void Heavy_CircleStrings::cSlice_oQwqtKJz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_iWTFkthf, 1, m, &cRandom_iWTFkthf_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cSwitchcase_rAF2r9pj_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_oQwqtKJz, 0, m, &cSlice_oQwqtKJz_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_iWTFkthf, 0, m, &cRandom_iWTFkthf_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cCast_t3Rt5GNg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_kVrCvmNG_sendMessage);
}

void Heavy_CircleStrings::cVar_bMo7sptF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_kaWA0k3x_sendMessage);
}

void Heavy_CircleStrings::cReceive_YBKV6ZZ2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_M34Jiqr9_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ulFj3abE_sendMessage);
}

void Heavy_CircleStrings::cReceive_YORauOUd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_nwh7cDmd, 1, m, &cVar_nwh7cDmd_sendMessage);
}

void Heavy_CircleStrings::cReceive_ZTsVfkF6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_qCp5kXVB, 0, m, &cVar_qCp5kXVB_sendMessage);
}

void Heavy_CircleStrings::cReceive_Ziy08ppj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_czoTbpnJ_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Ieib1wKz_sendMessage);
}

void Heavy_CircleStrings::cReceive_dTyUmKL6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_O6UGWhxF_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_9sOuS4Oz, 0, m, &cVar_9sOuS4Oz_sendMessage);
}

void Heavy_CircleStrings::cBinop_1gy5ErY8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.001f, 0, m, &cBinop_GvTDKCNU_sendMessage);
  cPack_onMessage(_c, &Context(_c)->cPack_J8JZdbvU, 0, m, &cPack_J8JZdbvU_sendMessage);
}

void Heavy_CircleStrings::cMsg_4CiVB78z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 100.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_KLZkdgi7, 0, m, &cVar_KLZkdgi7_sendMessage);
}

void Heavy_CircleStrings::cMsg_6tPPiVs4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 30.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_jNEN2L4y, 0, m, NULL);
}

void Heavy_CircleStrings::cMsg_AFVWNj5e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.5f);
  cVar_onMessage(_c, &Context(_c)->cVar_YcguvhNs, 0, m, &cVar_YcguvhNs_sendMessage);
}

void Heavy_CircleStrings::cVar_YcguvhNs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.5f, 0, m, &cBinop_onIDdbjZ_sendMessage);
}

void Heavy_CircleStrings::cUnop_UZjcaiy0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_if5HjkQK_sendMessage);
}

void Heavy_CircleStrings::cBinop_WiL0lRa1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_EXP, m, &cUnop_UZjcaiy0_sendMessage);
}

void Heavy_CircleStrings::cPack_Bm2na9Hr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_g7UWYirp, 0, m, NULL);
}

void Heavy_CircleStrings::cBinop_GvTDKCNU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_te413RcP_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_gBDy3SwE_sendMessage);
}

void Heavy_CircleStrings::cPack_J8JZdbvU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_Zjs9FqzT, 0, m, NULL);
}

void Heavy_CircleStrings::cMsg_HqkuD6Lx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_gU56DZxO_sendMessage);
}

void Heavy_CircleStrings::cSystem_gU56DZxO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_QXSo6FKJ_sendMessage);
}

void Heavy_CircleStrings::cMsg_50Qv2AIq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_hr8blEMd, 2, m, &cDelay_hr8blEMd_sendMessage);
}

void Heavy_CircleStrings::cMsg_FPB4l5cu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_tnW6ADwC, 0, m, &hTable_tnW6ADwC_sendMessage);
}

void Heavy_CircleStrings::cMsg_Kd8cOL0a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_tnW6ADwC, 0, m, &hTable_tnW6ADwC_sendMessage);
}

void Heavy_CircleStrings::cBinop_QXSo6FKJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 5000.0f, 0, m, &cBinop_kGiuDpyt_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_QbdZCFvj_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_dX0Wdxdk_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cMsg_dX0Wdxdk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_jaHDe3AO, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_hr8blEMd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_hr8blEMd, m);
  cMsg_Kd8cOL0a_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_kGiuDpyt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_FPB4l5cu_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_qAWX7df8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_sPflUa3J, 0, m, &cDelay_sPflUa3J_sendMessage);
}

void Heavy_CircleStrings::cDelay_sPflUa3J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_sPflUa3J, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_hr8blEMd, 0, m, &cDelay_hr8blEMd_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_sPflUa3J, 0, m, &cDelay_sPflUa3J_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_jaHDe3AO, 1, m, NULL);
}

void Heavy_CircleStrings::hTable_tnW6ADwC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_50Qv2AIq_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_sPflUa3J, 2, m, &cDelay_sPflUa3J_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_qAWX7df8_sendMessage);
}

void Heavy_CircleStrings::cBinop_SetbxVoN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_6tPPiVs4_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_YdePOomD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 87.3365f, 0, m, &cBinop_WiL0lRa1_sendMessage);
}

void Heavy_CircleStrings::cCast_gBDy3SwE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_SetbxVoN, HV_BINOP_DIVIDE, 0, m, &cBinop_SetbxVoN_sendMessage);
}

void Heavy_CircleStrings::cBinop_if5HjkQK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_l2aq8nF3_sendMessage);
}

void Heavy_CircleStrings::cBinop_l2aq8nF3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_SetbxVoN, HV_BINOP_DIVIDE, 0, m, &cBinop_SetbxVoN_sendMessage);
}

void Heavy_CircleStrings::cVar_KLZkdgi7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_1gy5ErY8_sendMessage);
}

void Heavy_CircleStrings::cBinop_onIDdbjZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_Bm2na9Hr, 0, m, &cPack_Bm2na9Hr_sendMessage);
}

void Heavy_CircleStrings::cBinop_6lhEfuBZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_uaxbfDFT, m);
}

void Heavy_CircleStrings::cMsg_AszExoYR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Y4hxMcna_sendMessage);
}

void Heavy_CircleStrings::cMsg_XJu9k75n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_kWuy4BN8_sendMessage);
}

void Heavy_CircleStrings::cSystem_kWuy4BN8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_6lhEfuBZ_sendMessage);
}

void Heavy_CircleStrings::cVar_SQmYneZy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_AszExoYR_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSystem_Y4hxMcna_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_fjKmw1qu_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_SjQDEIQP, m);
}

void Heavy_CircleStrings::cBinop_fjKmw1qu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_a8pHdRg6, m);
}

void Heavy_CircleStrings::cCast_te413RcP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_SetbxVoN, HV_BINOP_DIVIDE, 1, m, &cBinop_SetbxVoN_sendMessage);
}

void Heavy_CircleStrings::cSystem_ITbRU55N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_itiqMOM6_sendMessage);
}

void Heavy_CircleStrings::cMsg_ghvXpne5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ITbRU55N_sendMessage);
}

void Heavy_CircleStrings::cBinop_itiqMOM6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_NVI6Rosk, m);
}

void Heavy_CircleStrings::cVar_1RvtilXu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_waOYHeqF_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_rFTggjPm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_p7m8FVpp, m);
}

void Heavy_CircleStrings::cSystem_s7XorbYO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_rFTggjPm_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_PZMNAqEr, m);
}

void Heavy_CircleStrings::cMsg_waOYHeqF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_s7XorbYO_sendMessage);
}

void Heavy_CircleStrings::cCast_3YbyLICf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.0f, 0, m, &cBinop_rDm5AsVt_sendMessage);
}

void Heavy_CircleStrings::cMsg_095wVwXQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_wy6POAbD_sendMessage);
}

void Heavy_CircleStrings::cMsg_0JvXViD5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_WTaKHD3o_sendMessage);
}

void Heavy_CircleStrings::cIf_Q3VbGReb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_0JvXViD5_sendMessage(_c, 0, m);
      cMsg_ebxfkhqp_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_5MqZjCNj_sendMessage(_c, 0, m);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_WTaKHD3o_sendMessage);
      sVarf_onMessage(_c, &Context(_c)->sVarf_u3MxHD1B, m);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_oHSKHBWc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_Q3VbGReb, 1, m, &cIf_Q3VbGReb_sendMessage);
}

void Heavy_CircleStrings::cMsg_5MqZjCNj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_Bzfl9u96_sendMessage);
}

void Heavy_CircleStrings::cBinop_Bzfl9u96_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_try9M9ry, m);
}

void Heavy_CircleStrings::cMsg_EJwHy2lc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_L3kgoQlT_sendMessage);
}

void Heavy_CircleStrings::cMsg_K40Zj5Ga_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_swFLVWuT_sendMessage);
}

void Heavy_CircleStrings::cBinop_L3kgoQlT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_LjOibelc, m);
}

void Heavy_CircleStrings::cVar_AMuFTtd3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1e-05f, 0, m, &cBinop_oHSKHBWc_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_Q3VbGReb, 0, m, &cIf_Q3VbGReb_sendMessage);
}

void Heavy_CircleStrings::cBinop_WTaKHD3o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_095wVwXQ_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_ebxfkhqp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, -1.0f);
  sVarf_onMessage(_c, &Context(_c)->sVarf_try9M9ry, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_u3MxHD1B, m);
}

void Heavy_CircleStrings::cMsg_MsB7RNEz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_eirjZr3s_sendMessage);
}

void Heavy_CircleStrings::cSystem_eirjZr3s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_K40Zj5Ga_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_swFLVWuT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_gc3U5FB3, m);
}

void Heavy_CircleStrings::cBinop_wy6POAbD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_EJwHy2lc_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_EgR7aQyw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_skOQJWLV, m);
}

void Heavy_CircleStrings::cCast_G4enNZXX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.0f, 0, m, &cBinop_uTcHPrZn_sendMessage);
}

void Heavy_CircleStrings::cBinop_H47Xoozb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_aUz0qpbc, m);
}

void Heavy_CircleStrings::cBinop_Vmm7Wi9B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_j5zyOgSC_sendMessage);
}

void Heavy_CircleStrings::cBinop_j5zyOgSC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_H47Xoozb_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_SYo7JBP8, m);
}

void Heavy_CircleStrings::cBinop_2rtNKmHh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_TptFb9TS, HV_BINOP_MULTIPLY, 1, m, &cBinop_TptFb9TS_sendMessage);
}

void Heavy_CircleStrings::cMsg_89Y0qi5S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_2rtNKmHh_sendMessage);
}

void Heavy_CircleStrings::cSystem_7p3b329t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_89Y0qi5S_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_MzGqcph5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_7p3b329t_sendMessage);
}

void Heavy_CircleStrings::cBinop_TptFb9TS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_Vmm7Wi9B_sendMessage);
}

void Heavy_CircleStrings::cVar_Fg3xBIla_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_TptFb9TS, HV_BINOP_MULTIPLY, 0, m, &cBinop_TptFb9TS_sendMessage);
}

void Heavy_CircleStrings::cCast_nspBAi22_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.0f, 0, m, &cBinop_zyB5iGBX_sendMessage);
}

void Heavy_CircleStrings::cBinop_rDm5AsVt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_f9KMTLD9, 0, m, &cVar_f9KMTLD9_sendMessage);
}

void Heavy_CircleStrings::cBinop_2RUV3WZL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_z8bvsrEq_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_ShZv1Lle, m);
}

void Heavy_CircleStrings::cBinop_KUpx3UdS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_2RUV3WZL_sendMessage);
}

void Heavy_CircleStrings::cBinop_JxPNQRyU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_s5UZrpvX, HV_BINOP_MULTIPLY, 1, m, &cBinop_s5UZrpvX_sendMessage);
}

void Heavy_CircleStrings::cMsg_XQezQsN3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_JxPNQRyU_sendMessage);
}

void Heavy_CircleStrings::cBinop_s5UZrpvX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_KUpx3UdS_sendMessage);
}

void Heavy_CircleStrings::cMsg_NcKfd4xP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_kY6DhUSe_sendMessage);
}

void Heavy_CircleStrings::cSystem_kY6DhUSe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_XQezQsN3_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cVar_f9KMTLD9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_s5UZrpvX, HV_BINOP_MULTIPLY, 0, m, &cBinop_s5UZrpvX_sendMessage);
}

void Heavy_CircleStrings::cBinop_z8bvsrEq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_bsg0dBcj, m);
}

void Heavy_CircleStrings::cBinop_6e7V5BTV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_M7lbaMq5, m);
}

void Heavy_CircleStrings::cBinop_0YvZBbQL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_EHLtzLOc_sendMessage);
}

void Heavy_CircleStrings::cMsg_QU6FQE0w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_i2yWZzL0_sendMessage);
}

void Heavy_CircleStrings::cMsg_88KB4mBa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_RVApxjGd_sendMessage);
}

void Heavy_CircleStrings::cSystem_RVApxjGd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_QU6FQE0w_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_i2yWZzL0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_0YvZBbQL, HV_BINOP_MULTIPLY, 1, m, &cBinop_0YvZBbQL_sendMessage);
}

void Heavy_CircleStrings::cBinop_2okz0DiV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_6e7V5BTV_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_1xlzEFn0, m);
}

void Heavy_CircleStrings::cBinop_EHLtzLOc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_2okz0DiV_sendMessage);
}

void Heavy_CircleStrings::cVar_iAkocxD1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_0YvZBbQL, HV_BINOP_MULTIPLY, 0, m, &cBinop_0YvZBbQL_sendMessage);
}

void Heavy_CircleStrings::cBinop_uTcHPrZn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Fg3xBIla, 0, m, &cVar_Fg3xBIla_sendMessage);
}

void Heavy_CircleStrings::cBinop_zyB5iGBX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_iAkocxD1, 0, m, &cVar_iAkocxD1_sendMessage);
}

void Heavy_CircleStrings::cVar_qb95DYXu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.05776f, 0, m, &cBinop_YdePOomD_sendMessage);
}

void Heavy_CircleStrings::cCast_JpkyQM6K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_80GY7huL_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cVar_6fo4mxtY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_pCdhdlef_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_A2qdipWP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_6fo4mxtY, 0, m, &cVar_6fo4mxtY_sendMessage);
  cMsg_0JckHJRu_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_yFuq8aMY, 0, m, &cTabhead_yFuq8aMY_sendMessage);
}

void Heavy_CircleStrings::cDelay_A7fLHo8f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_A7fLHo8f, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_SjcvtXmp, 0, m, &sTabread_SjcvtXmp_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_A7fLHo8f, 0, m, &cDelay_A7fLHo8f_sendMessage);
}

void Heavy_CircleStrings::cCast_BSZDvBMc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_sYDF6GMc, 0, m, &cDelay_sYDF6GMc_sendMessage);
}

void Heavy_CircleStrings::cBinop_LMzhOrc9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_hiFY5jud_sendMessage);
}

void Heavy_CircleStrings::sTabread_SjcvtXmp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_LMzhOrc9, HV_BINOP_SUBTRACT, 0, m, &cBinop_LMzhOrc9_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cMsg_Z2zEx5te_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_sYDF6GMc, 0, m, &cDelay_sYDF6GMc_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_A7fLHo8f, 0, m, &cDelay_A7fLHo8f_sendMessage);
}

void Heavy_CircleStrings::cSystem_d4SSKImG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_LMzhOrc9, HV_BINOP_SUBTRACT, 1, m, &cBinop_LMzhOrc9_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_A7fLHo8f, 2, m, &cDelay_A7fLHo8f_sendMessage);
}

void Heavy_CircleStrings::cBinop_hiFY5jud_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_sYDF6GMc, 2, m, &cDelay_sYDF6GMc_sendMessage);
}

void Heavy_CircleStrings::cBinop_iMw3JeXZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Z2zEx5te_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_SjcvtXmp, 0, m, &sTabread_SjcvtXmp_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_BSZDvBMc_sendMessage);
}

void Heavy_CircleStrings::cMsg_0JckHJRu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_5rP4odRF_sendMessage);
}

void Heavy_CircleStrings::cSystem_5rP4odRF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_zRH4yHyo_sendMessage);
}

void Heavy_CircleStrings::cBinop_lyqlEnL0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_iMw3JeXZ, HV_BINOP_SUBTRACT, 1, m, &cBinop_iMw3JeXZ_sendMessage);
}

void Heavy_CircleStrings::cMsg_mszd6exa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_lyqlEnL0, HV_BINOP_MAX, 1, m, &cBinop_lyqlEnL0_sendMessage);
}

void Heavy_CircleStrings::cMsg_pCdhdlef_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_d4SSKImG_sendMessage);
}

void Heavy_CircleStrings::cDelay_sYDF6GMc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_sYDF6GMc, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_A7fLHo8f, 0, m, &cDelay_A7fLHo8f_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_SjcvtXmp, 0, m, &sTabread_SjcvtXmp_sendMessage);
}

void Heavy_CircleStrings::cTabhead_yFuq8aMY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_iMw3JeXZ, HV_BINOP_SUBTRACT, 0, m, &cBinop_iMw3JeXZ_sendMessage);
}

void Heavy_CircleStrings::cBinop_zRH4yHyo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_zWOm0NvF, HV_BINOP_MULTIPLY, 0, m, &cBinop_zWOm0NvF_sendMessage);
}

void Heavy_CircleStrings::cBinop_zWOm0NvF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_lyqlEnL0, HV_BINOP_MAX, 0, m, &cBinop_lyqlEnL0_sendMessage);
}

void Heavy_CircleStrings::cDelay_0Xil5ykm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_0Xil5ykm, m);
  cMsg_9LoxOxwg_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_9LoxOxwg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_GitsKUSa, 0, m, &hTable_GitsKUSa_sendMessage);
}

void Heavy_CircleStrings::cDelay_EZO2ulb3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_EZO2ulb3, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_0Xil5ykm, 0, m, &cDelay_0Xil5ykm_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_EZO2ulb3, 0, m, &cDelay_EZO2ulb3_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_hN8OanlT, 1, m, NULL);
}

void Heavy_CircleStrings::hTable_GitsKUSa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_qlerrb7I_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_EZO2ulb3, 2, m, &cDelay_EZO2ulb3_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_lmaPq03S_sendMessage);
}

void Heavy_CircleStrings::cMsg_kKgj26mj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_xKIXZsDW_sendMessage);
}

void Heavy_CircleStrings::cSystem_xKIXZsDW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_LY9fZofX_sendMessage);
}

void Heavy_CircleStrings::cBinop_KvFKyppH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_l2GRtja7_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_LY9fZofX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 16.364f, 0, m, &cBinop_KvFKyppH_sendMessage);
}

void Heavy_CircleStrings::cMsg_l2GRtja7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_GitsKUSa, 0, m, &hTable_GitsKUSa_sendMessage);
}

void Heavy_CircleStrings::cCast_lmaPq03S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_EZO2ulb3, 0, m, &cDelay_EZO2ulb3_sendMessage);
}

void Heavy_CircleStrings::cMsg_qlerrb7I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_0Xil5ykm, 2, m, &cDelay_0Xil5ykm_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_rrXMAmef_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_shArdhDY_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cMsg_shArdhDY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_hN8OanlT, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_0Nvf26kC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_0Nvf26kC, m);
  cMsg_PviVOrJv_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_2BrDd1Iv_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_3HCrObNu_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cMsg_3HCrObNu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_eOHSLqSm, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_8O9LuJpY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_8O9LuJpY, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_0Nvf26kC, 0, m, &cDelay_0Nvf26kC_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_8O9LuJpY, 0, m, &cDelay_8O9LuJpY_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_eOHSLqSm, 1, m, NULL);
}

void Heavy_CircleStrings::cBinop_BApdDvzh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_wBfaLUl9_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_IPuPfbdw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_0Nvf26kC, 2, m, &cDelay_0Nvf26kC_sendMessage);
}

void Heavy_CircleStrings::cCast_JPi9YWMY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_8O9LuJpY, 0, m, &cDelay_8O9LuJpY_sendMessage);
}

void Heavy_CircleStrings::cMsg_PviVOrJv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_ol9BBsMZ, 0, m, &hTable_ol9BBsMZ_sendMessage);
}

void Heavy_CircleStrings::cSystem_SkHBIxuB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_WNL1KsJd_sendMessage);
}

void Heavy_CircleStrings::cMsg_lJnQ3c4Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_SkHBIxuB_sendMessage);
}

void Heavy_CircleStrings::cBinop_WNL1KsJd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 75.2546f, 0, m, &cBinop_BApdDvzh_sendMessage);
}

void Heavy_CircleStrings::hTable_ol9BBsMZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_IPuPfbdw_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_8O9LuJpY, 2, m, &cDelay_8O9LuJpY_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_JPi9YWMY_sendMessage);
}

void Heavy_CircleStrings::cMsg_wBfaLUl9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_ol9BBsMZ, 0, m, &hTable_ol9BBsMZ_sendMessage);
}

void Heavy_CircleStrings::cTabhead_7KT9OKCK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_zFqHlvUz, HV_BINOP_SUBTRACT, 0, m, &cBinop_zFqHlvUz_sendMessage);
}

void Heavy_CircleStrings::cCast_7kq2ete8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_uWoGdxz8, 0, m, &cVar_uWoGdxz8_sendMessage);
  cMsg_R0RVnxSW_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_7KT9OKCK, 0, m, &cTabhead_7KT9OKCK_sendMessage);
}

void Heavy_CircleStrings::cDelay_AbpexQkF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_AbpexQkF, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_iBt5GdZD, 0, m, &cDelay_iBt5GdZD_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_txETd8q3, 0, m, &sTabread_txETd8q3_sendMessage);
}

void Heavy_CircleStrings::cBinop_BsAy2F7t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MYoPVutt, HV_BINOP_MULTIPLY, 0, m, &cBinop_MYoPVutt_sendMessage);
}

void Heavy_CircleStrings::cSystem_FTV48A85_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_QO7efEPb, HV_BINOP_SUBTRACT, 1, m, &cBinop_QO7efEPb_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_iBt5GdZD, 2, m, &cDelay_iBt5GdZD_sendMessage);
}

void Heavy_CircleStrings::cSystem_E9HsfONy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_BsAy2F7t_sendMessage);
}

void Heavy_CircleStrings::cMsg_R0RVnxSW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_E9HsfONy_sendMessage);
}

void Heavy_CircleStrings::cMsg_LqnklgtN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_VKfvcohg, HV_BINOP_MAX, 1, m, &cBinop_VKfvcohg_sendMessage);
}

void Heavy_CircleStrings::cBinop_MYoPVutt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_VKfvcohg, HV_BINOP_MAX, 0, m, &cBinop_VKfvcohg_sendMessage);
}

void Heavy_CircleStrings::cBinop_QO7efEPb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_u1yWyNXr_sendMessage);
}

void Heavy_CircleStrings::cCast_Ts7aByXn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_AbpexQkF, 0, m, &cDelay_AbpexQkF_sendMessage);
}

void Heavy_CircleStrings::cBinop_VKfvcohg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_zFqHlvUz, HV_BINOP_SUBTRACT, 1, m, &cBinop_zFqHlvUz_sendMessage);
}

void Heavy_CircleStrings::cMsg_g98VX1mT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_FTV48A85_sendMessage);
}

void Heavy_CircleStrings::cDelay_iBt5GdZD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_iBt5GdZD, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_txETd8q3, 0, m, &sTabread_txETd8q3_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_iBt5GdZD, 0, m, &cDelay_iBt5GdZD_sendMessage);
}

void Heavy_CircleStrings::cMsg_s8Pm7vIR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_AbpexQkF, 0, m, &cDelay_AbpexQkF_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_iBt5GdZD, 0, m, &cDelay_iBt5GdZD_sendMessage);
}

void Heavy_CircleStrings::sTabread_txETd8q3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_QO7efEPb, HV_BINOP_SUBTRACT, 0, m, &cBinop_QO7efEPb_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_u1yWyNXr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_AbpexQkF, 2, m, &cDelay_AbpexQkF_sendMessage);
}

void Heavy_CircleStrings::cVar_uWoGdxz8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_g98VX1mT_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_zFqHlvUz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_s8Pm7vIR_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_txETd8q3, 0, m, &sTabread_txETd8q3_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Ts7aByXn_sendMessage);
}

void Heavy_CircleStrings::cMsg_3vMJ3ti6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_pVu6zRuu, 0, m, &hTable_pVu6zRuu_sendMessage);
}

void Heavy_CircleStrings::cBinop_4qt3HSST_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 13.645f, 0, m, &cBinop_Iopt7YnK_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_5vS3geYi_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_zLOIMMzk_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cMsg_7GkuHEDs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_riC9r37s, 2, m, &cDelay_riC9r37s_sendMessage);
}

void Heavy_CircleStrings::cMsg_BFERekNs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_pVu6zRuu, 0, m, &hTable_pVu6zRuu_sendMessage);
}

void Heavy_CircleStrings::cBinop_Iopt7YnK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_BFERekNs_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_MpVWtaZl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_MpVWtaZl, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_riC9r37s, 0, m, &cDelay_riC9r37s_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_MpVWtaZl, 0, m, &cDelay_MpVWtaZl_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_5C2xIvT6, 1, m, NULL);
}

void Heavy_CircleStrings::hTable_pVu6zRuu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_7GkuHEDs_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_MpVWtaZl, 2, m, &cDelay_MpVWtaZl_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_q6P4Fhjl_sendMessage);
}

void Heavy_CircleStrings::cCast_q6P4Fhjl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_MpVWtaZl, 0, m, &cDelay_MpVWtaZl_sendMessage);
}

void Heavy_CircleStrings::cDelay_riC9r37s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_riC9r37s, m);
  cMsg_3vMJ3ti6_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_SZLN7VJY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_a74RPXwG_sendMessage);
}

void Heavy_CircleStrings::cSystem_a74RPXwG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_4qt3HSST_sendMessage);
}

void Heavy_CircleStrings::cMsg_zLOIMMzk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_5C2xIvT6, 1, m, NULL);
}

void Heavy_CircleStrings::cCast_1tXXQCap_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_qvgNlC3p, 0, m, &cVar_qvgNlC3p_sendMessage);
  cMsg_0sNdwc3J_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_VRPF9nBu, 0, m, &cTabhead_VRPF9nBu_sendMessage);
}

void Heavy_CircleStrings::cMsg_2pmToXM2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_IFEzmF3u, HV_BINOP_MAX, 1, m, &cBinop_IFEzmF3u_sendMessage);
}

void Heavy_CircleStrings::cMsg_3kxcDX7E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_mgCSkaRN, 0, m, &cDelay_mgCSkaRN_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_gAE6182y, 0, m, &cDelay_gAE6182y_sendMessage);
}

void Heavy_CircleStrings::cCast_4tBwaIK5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_mgCSkaRN, 0, m, &cDelay_mgCSkaRN_sendMessage);
}

void Heavy_CircleStrings::cBinop_5Ii7hl0X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_IFEzmF3u, HV_BINOP_MAX, 0, m, &cBinop_IFEzmF3u_sendMessage);
}

void Heavy_CircleStrings::sTabread_FN8gdmh3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_eYXQ5pp9, HV_BINOP_SUBTRACT, 0, m, &cBinop_eYXQ5pp9_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_IFEzmF3u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_sPFRkvK8, HV_BINOP_SUBTRACT, 1, m, &cBinop_sPFRkvK8_sendMessage);
}

void Heavy_CircleStrings::cBinop_RmskBJ9y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_5Ii7hl0X, HV_BINOP_MULTIPLY, 0, m, &cBinop_5Ii7hl0X_sendMessage);
}

void Heavy_CircleStrings::cBinop_VHvSO52y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_mgCSkaRN, 2, m, &cDelay_mgCSkaRN_sendMessage);
}

void Heavy_CircleStrings::cTabhead_VRPF9nBu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_sPFRkvK8, HV_BINOP_SUBTRACT, 0, m, &cBinop_sPFRkvK8_sendMessage);
}

void Heavy_CircleStrings::cMsg_0sNdwc3J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_r9l0OfEj_sendMessage);
}

void Heavy_CircleStrings::cSystem_r9l0OfEj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_RmskBJ9y_sendMessage);
}

void Heavy_CircleStrings::cBinop_eYXQ5pp9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_VHvSO52y_sendMessage);
}

void Heavy_CircleStrings::cDelay_gAE6182y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_gAE6182y, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_FN8gdmh3, 0, m, &sTabread_FN8gdmh3_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_gAE6182y, 0, m, &cDelay_gAE6182y_sendMessage);
}

void Heavy_CircleStrings::cDelay_mgCSkaRN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_mgCSkaRN, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_gAE6182y, 0, m, &cDelay_gAE6182y_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_FN8gdmh3, 0, m, &sTabread_FN8gdmh3_sendMessage);
}

void Heavy_CircleStrings::cVar_qvgNlC3p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_v9HM9LiG_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSystem_qyuwtcDV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_eYXQ5pp9, HV_BINOP_SUBTRACT, 1, m, &cBinop_eYXQ5pp9_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_gAE6182y, 2, m, &cDelay_gAE6182y_sendMessage);
}

void Heavy_CircleStrings::cBinop_sPFRkvK8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_3kxcDX7E_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_FN8gdmh3, 0, m, &sTabread_FN8gdmh3_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_4tBwaIK5_sendMessage);
}

void Heavy_CircleStrings::cMsg_v9HM9LiG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_qyuwtcDV_sendMessage);
}

void Heavy_CircleStrings::hTable_4R7EzTqJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_9jiRiswY_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_vxe9ASrU, 2, m, &cDelay_vxe9ASrU_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_4XxHeB0G_sendMessage);
}

void Heavy_CircleStrings::cCast_4XxHeB0G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_vxe9ASrU, 0, m, &cDelay_vxe9ASrU_sendMessage);
}

void Heavy_CircleStrings::cMsg_74Im5Epj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_8oJgR4mO, 1, m, NULL);
}

void Heavy_CircleStrings::cMsg_9jiRiswY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_rfudklBv, 2, m, &cDelay_rfudklBv_sendMessage);
}

void Heavy_CircleStrings::cMsg_Tfh3ugTx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_iOH8jAno_sendMessage);
}

void Heavy_CircleStrings::cSystem_iOH8jAno_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_LNxXOEJe_sendMessage);
}

void Heavy_CircleStrings::cBinop_LNxXOEJe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 19.392f, 0, m, &cBinop_xzVUNQf1_sendMessage);
}

void Heavy_CircleStrings::cMsg_Wg55a7ii_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_4R7EzTqJ, 0, m, &hTable_4R7EzTqJ_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_e1KLwPMv_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_74Im5Epj_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cMsg_lSi6P69n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_4R7EzTqJ, 0, m, &hTable_4R7EzTqJ_sendMessage);
}

void Heavy_CircleStrings::cDelay_rfudklBv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_rfudklBv, m);
  cMsg_lSi6P69n_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_vxe9ASrU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_vxe9ASrU, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_rfudklBv, 0, m, &cDelay_rfudklBv_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_vxe9ASrU, 0, m, &cDelay_vxe9ASrU_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_8oJgR4mO, 1, m, NULL);
}

void Heavy_CircleStrings::cBinop_xzVUNQf1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Wg55a7ii_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_0R1Knx8w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_WpqKENNZ, 0, m, &cDelay_WpqKENNZ_sendMessage);
}

void Heavy_CircleStrings::cDelay_0ZnGXISG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_0ZnGXISG, m);
  cMsg_OnXOGtNY_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_OnXOGtNY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_gj6OsYoC, 0, m, &hTable_gj6OsYoC_sendMessage);
}

void Heavy_CircleStrings::cBinop_PBmfKnPV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_pcfCC84r_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_UvrPLWhF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_Z48GzA0g, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_WpqKENNZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_WpqKENNZ, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_0ZnGXISG, 0, m, &cDelay_0ZnGXISG_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_WpqKENNZ, 0, m, &cDelay_WpqKENNZ_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_Z48GzA0g, 1, m, NULL);
}

void Heavy_CircleStrings::cMsg_cHv3x7Xd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_0ZnGXISG, 2, m, &cDelay_0ZnGXISG_sendMessage);
}

void Heavy_CircleStrings::hTable_gj6OsYoC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_cHv3x7Xd_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_WpqKENNZ, 2, m, &cDelay_WpqKENNZ_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_0R1Knx8w_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_pY6hmGDi_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_UvrPLWhF_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cMsg_pcfCC84r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_gj6OsYoC, 0, m, &hTable_gj6OsYoC_sendMessage);
}

void Heavy_CircleStrings::cSystem_0hirUWhU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_yBO9HRKL_sendMessage);
}

void Heavy_CircleStrings::cMsg_EI15LN6J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_0hirUWhU_sendMessage);
}

void Heavy_CircleStrings::cBinop_yBO9HRKL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 43.5337f, 0, m, &cBinop_PBmfKnPV_sendMessage);
}

void Heavy_CircleStrings::cMsg_3axR19W7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_jGl7FP1w, 0, m, &hTable_jGl7FP1w_sendMessage);
}

void Heavy_CircleStrings::cMsg_ATi4B5wq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_jGl7FP1w, 0, m, &hTable_jGl7FP1w_sendMessage);
}

void Heavy_CircleStrings::cDelay_AsP7uNbU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_AsP7uNbU, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_l3q2gskJ, 0, m, &cDelay_l3q2gskJ_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_AsP7uNbU, 0, m, &cDelay_AsP7uNbU_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_ObU7iS8U, 1, m, NULL);
}

void Heavy_CircleStrings::cBinop_BjnY4T2p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ATi4B5wq_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_JEmUlSr7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_ObU7iS8U, 1, m, NULL);
}

void Heavy_CircleStrings::cMsg_NzXum9ww_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_g4xXvYc6_sendMessage);
}

void Heavy_CircleStrings::cSystem_g4xXvYc6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_xQn0D6km_sendMessage);
}

void Heavy_CircleStrings::cCast_S9JTsZTG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_AsP7uNbU, 0, m, &cDelay_AsP7uNbU_sendMessage);
}

void Heavy_CircleStrings::cMsg_WSYbd1r7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_l3q2gskJ, 2, m, &cDelay_l3q2gskJ_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_fUf5But6_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_JEmUlSr7_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::hTable_jGl7FP1w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_WSYbd1r7_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_AsP7uNbU, 2, m, &cDelay_AsP7uNbU_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_S9JTsZTG_sendMessage);
}

void Heavy_CircleStrings::cDelay_l3q2gskJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_l3q2gskJ, m);
  cMsg_3axR19W7_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_xQn0D6km_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 25.796f, 0, m, &cBinop_BjnY4T2p_sendMessage);
}

void Heavy_CircleStrings::cSystem_83uf3TZ0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_u7QN2xJi, HV_BINOP_SUBTRACT, 1, m, &cBinop_u7QN2xJi_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ZHoK3by3, 2, m, &cDelay_ZHoK3by3_sendMessage);
}

void Heavy_CircleStrings::cVar_8l70VoDY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_BYwSiFqd_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_BYwSiFqd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_83uf3TZ0_sendMessage);
}

void Heavy_CircleStrings::cBinop_DNX0xulF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_JIm1oOiy, HV_BINOP_MAX, 0, m, &cBinop_JIm1oOiy_sendMessage);
}

void Heavy_CircleStrings::cBinop_JIm1oOiy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_gAyoEMk9, HV_BINOP_SUBTRACT, 1, m, &cBinop_gAyoEMk9_sendMessage);
}

void Heavy_CircleStrings::cMsg_CicYzqYX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_stQyNYdN_sendMessage);
}

void Heavy_CircleStrings::cSystem_stQyNYdN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_e9vwzbnU_sendMessage);
}

void Heavy_CircleStrings::cCast_OnXbEHIO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_8l70VoDY, 0, m, &cVar_8l70VoDY_sendMessage);
  cMsg_CicYzqYX_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_wfU15qxn, 0, m, &cTabhead_wfU15qxn_sendMessage);
}

void Heavy_CircleStrings::cMsg_X7MhIFbv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_ZSUDazh3, 0, m, &cDelay_ZSUDazh3_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ZHoK3by3, 0, m, &cDelay_ZHoK3by3_sendMessage);
}

void Heavy_CircleStrings::cDelay_ZHoK3by3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_ZHoK3by3, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_npp0Yaeg, 0, m, &sTabread_npp0Yaeg_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ZHoK3by3, 0, m, &cDelay_ZHoK3by3_sendMessage);
}

void Heavy_CircleStrings::cDelay_ZSUDazh3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_ZSUDazh3, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ZHoK3by3, 0, m, &cDelay_ZHoK3by3_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_npp0Yaeg, 0, m, &sTabread_npp0Yaeg_sendMessage);
}

void Heavy_CircleStrings::cBinop_bez6MEJQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_ZSUDazh3, 2, m, &cDelay_ZSUDazh3_sendMessage);
}

void Heavy_CircleStrings::cBinop_e9vwzbnU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_DNX0xulF, HV_BINOP_MULTIPLY, 0, m, &cBinop_DNX0xulF_sendMessage);
}

void Heavy_CircleStrings::cBinop_gAyoEMk9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_X7MhIFbv_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_npp0Yaeg, 0, m, &sTabread_npp0Yaeg_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_yHzGJqcW_sendMessage);
}

void Heavy_CircleStrings::sTabread_npp0Yaeg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_u7QN2xJi, HV_BINOP_SUBTRACT, 0, m, &cBinop_u7QN2xJi_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_u7QN2xJi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_bez6MEJQ_sendMessage);
}

void Heavy_CircleStrings::cMsg_uZzF3Ixh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_JIm1oOiy, HV_BINOP_MAX, 1, m, &cBinop_JIm1oOiy_sendMessage);
}

void Heavy_CircleStrings::cTabhead_wfU15qxn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_gAyoEMk9, HV_BINOP_SUBTRACT, 0, m, &cBinop_gAyoEMk9_sendMessage);
}

void Heavy_CircleStrings::cCast_yHzGJqcW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_ZSUDazh3, 0, m, &cDelay_ZSUDazh3_sendMessage);
}

void Heavy_CircleStrings::cBinop_0PkkEWUW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_muWy6S2R_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_zi5qKH5S, 0, m, &sTabread_zi5qKH5S_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_O1Zd7m3m_sendMessage);
}

void Heavy_CircleStrings::cBinop_1Xi8yDH2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_FzsrQbSV, HV_BINOP_MULTIPLY, 0, m, &cBinop_FzsrQbSV_sendMessage);
}

void Heavy_CircleStrings::cBinop_FzsrQbSV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_I7QpVyNi, HV_BINOP_MAX, 0, m, &cBinop_I7QpVyNi_sendMessage);
}

void Heavy_CircleStrings::cBinop_I7QpVyNi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_0PkkEWUW, HV_BINOP_SUBTRACT, 1, m, &cBinop_0PkkEWUW_sendMessage);
}

void Heavy_CircleStrings::cBinop_J7ZDY3O4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_S3mJ5GHO_sendMessage);
}

void Heavy_CircleStrings::cCast_O1Zd7m3m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_yR5V08aK, 0, m, &cDelay_yR5V08aK_sendMessage);
}

void Heavy_CircleStrings::cBinop_S3mJ5GHO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_yR5V08aK, 2, m, &cDelay_yR5V08aK_sendMessage);
}

void Heavy_CircleStrings::cSystem_arcJteX4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_J7ZDY3O4, HV_BINOP_SUBTRACT, 1, m, &cBinop_J7ZDY3O4_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_wBJ2wuYL, 2, m, &cDelay_wBJ2wuYL_sendMessage);
}

void Heavy_CircleStrings::cMsg_cRHIu7p1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_I7QpVyNi, HV_BINOP_MAX, 1, m, &cBinop_I7QpVyNi_sendMessage);
}

void Heavy_CircleStrings::cMsg_muWy6S2R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_yR5V08aK, 0, m, &cDelay_yR5V08aK_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_wBJ2wuYL, 0, m, &cDelay_wBJ2wuYL_sendMessage);
}

void Heavy_CircleStrings::cMsg_JeHx8xhJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_q29aaKXr_sendMessage);
}

void Heavy_CircleStrings::cSystem_q29aaKXr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_1Xi8yDH2_sendMessage);
}

void Heavy_CircleStrings::cTabhead_uXyHDKNL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_0PkkEWUW, HV_BINOP_SUBTRACT, 0, m, &cBinop_0PkkEWUW_sendMessage);
}

void Heavy_CircleStrings::cVar_uqKw2Zl3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_vDMwXiAF_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_vDMwXiAF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_arcJteX4_sendMessage);
}

void Heavy_CircleStrings::cDelay_wBJ2wuYL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_wBJ2wuYL, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_zi5qKH5S, 0, m, &sTabread_zi5qKH5S_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_wBJ2wuYL, 0, m, &cDelay_wBJ2wuYL_sendMessage);
}

void Heavy_CircleStrings::cDelay_yR5V08aK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_yR5V08aK, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_wBJ2wuYL, 0, m, &cDelay_wBJ2wuYL_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_zi5qKH5S, 0, m, &sTabread_zi5qKH5S_sendMessage);
}

void Heavy_CircleStrings::cCast_z6duwO18_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_uqKw2Zl3, 0, m, &cVar_uqKw2Zl3_sendMessage);
  cMsg_JeHx8xhJ_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_uXyHDKNL, 0, m, &cTabhead_uXyHDKNL_sendMessage);
}

void Heavy_CircleStrings::sTabread_zi5qKH5S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_J7ZDY3O4, HV_BINOP_SUBTRACT, 0, m, &cBinop_J7ZDY3O4_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cTabhead_1cNTgzpa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_OVGgm29j, HV_BINOP_SUBTRACT, 0, m, &cBinop_OVGgm29j_sendMessage);
}

void Heavy_CircleStrings::sTabread_1zWfMPeG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_fSMJ017l, HV_BINOP_SUBTRACT, 0, m, &cBinop_fSMJ017l_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cCast_4v6OMUIw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_ZAde0uvt, 0, m, &cDelay_ZAde0uvt_sendMessage);
}

void Heavy_CircleStrings::cMsg_9QBtFkpz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_ZAde0uvt, 0, m, &cDelay_ZAde0uvt_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_A2RYvPhE, 0, m, &cDelay_A2RYvPhE_sendMessage);
}

void Heavy_CircleStrings::cDelay_A2RYvPhE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_A2RYvPhE, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_1zWfMPeG, 0, m, &sTabread_1zWfMPeG_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_A2RYvPhE, 0, m, &cDelay_A2RYvPhE_sendMessage);
}

void Heavy_CircleStrings::cVar_DRyTmypg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_LHeEEgBN_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_LHeEEgBN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_j83WiwVQ_sendMessage);
}

void Heavy_CircleStrings::cBinop_OVGgm29j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_9QBtFkpz_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_1zWfMPeG, 0, m, &sTabread_1zWfMPeG_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_4v6OMUIw_sendMessage);
}

void Heavy_CircleStrings::cBinop_TUpLUGrK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ulUdFhXJ, HV_BINOP_MAX, 0, m, &cBinop_ulUdFhXJ_sendMessage);
}

void Heavy_CircleStrings::cMsg_XE8WwMMf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_ulUdFhXJ, HV_BINOP_MAX, 1, m, &cBinop_ulUdFhXJ_sendMessage);
}

void Heavy_CircleStrings::cDelay_ZAde0uvt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_ZAde0uvt, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_A2RYvPhE, 0, m, &cDelay_A2RYvPhE_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_1zWfMPeG, 0, m, &sTabread_1zWfMPeG_sendMessage);
}

void Heavy_CircleStrings::cBinop_dR3Issgm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_TUpLUGrK, HV_BINOP_MULTIPLY, 0, m, &cBinop_TUpLUGrK_sendMessage);
}

void Heavy_CircleStrings::cBinop_fSMJ017l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_xZBMFHfM_sendMessage);
}

void Heavy_CircleStrings::cSystem_j83WiwVQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_fSMJ017l, HV_BINOP_SUBTRACT, 1, m, &cBinop_fSMJ017l_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_A2RYvPhE, 2, m, &cDelay_A2RYvPhE_sendMessage);
}

void Heavy_CircleStrings::cSystem_7gFXNw8h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_dR3Issgm_sendMessage);
}

void Heavy_CircleStrings::cMsg_CBh5T8lj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_7gFXNw8h_sendMessage);
}

void Heavy_CircleStrings::cBinop_ulUdFhXJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_OVGgm29j, HV_BINOP_SUBTRACT, 1, m, &cBinop_OVGgm29j_sendMessage);
}

void Heavy_CircleStrings::cBinop_xZBMFHfM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_ZAde0uvt, 2, m, &cDelay_ZAde0uvt_sendMessage);
}

void Heavy_CircleStrings::cCast_zUiLah7o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_DRyTmypg, 0, m, &cVar_DRyTmypg_sendMessage);
  cMsg_CBh5T8lj_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_1cNTgzpa, 0, m, &cTabhead_1cNTgzpa_sendMessage);
}

void Heavy_CircleStrings::cBinop_jhX5dFDR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_l7k9z9Vd_sendMessage);
}

void Heavy_CircleStrings::cBinop_l7k9z9Vd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_siEj6nhf_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_ai1jlsln, m);
}

void Heavy_CircleStrings::cBinop_GdRaLxL9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_jhX5dFDR_sendMessage);
}

void Heavy_CircleStrings::cMsg_3PJFmvdb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_tLHmnMAO_sendMessage);
}

void Heavy_CircleStrings::cSystem_tLHmnMAO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_nWLQXqJ2_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_nWLQXqJ2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_spUPSbLx_sendMessage);
}

void Heavy_CircleStrings::cBinop_spUPSbLx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_GdRaLxL9, HV_BINOP_MULTIPLY, 1, m, &cBinop_GdRaLxL9_sendMessage);
}

void Heavy_CircleStrings::cVar_Pr8OI5bX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_GdRaLxL9, HV_BINOP_MULTIPLY, 0, m, &cBinop_GdRaLxL9_sendMessage);
}

void Heavy_CircleStrings::cBinop_siEj6nhf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_31CMeTHu, m);
}

void Heavy_CircleStrings::cBinop_coOqk6Hv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_tEOBkZds_sendMessage);
}

void Heavy_CircleStrings::cBinop_tEOBkZds_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_jxvmbT3n, 0, m, &cVar_jxvmbT3n_sendMessage);
}

void Heavy_CircleStrings::cVar_Aq4Yg5j6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 100.0f, 0, m, &cBinop_coOqk6Hv_sendMessage);
}

void Heavy_CircleStrings::cMsg_1HqYy2pn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_MEzGKBmE, HV_BINOP_MAX, 1, m, &cBinop_MEzGKBmE_sendMessage);
}

void Heavy_CircleStrings::cDelay_BqXxqAAL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_BqXxqAAL, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_WNNBKTF8, 0, m, &sTabread_WNNBKTF8_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_BqXxqAAL, 0, m, &cDelay_BqXxqAAL_sendMessage);
}

void Heavy_CircleStrings::cDelay_JyssfCSo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_JyssfCSo, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_BqXxqAAL, 0, m, &cDelay_BqXxqAAL_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_WNNBKTF8, 0, m, &sTabread_WNNBKTF8_sendMessage);
}

void Heavy_CircleStrings::cBinop_MEzGKBmE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_awJtMi5f, HV_BINOP_SUBTRACT, 1, m, &cBinop_awJtMi5f_sendMessage);
}

void Heavy_CircleStrings::cMsg_NZOhvBHS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_X6muOth1_sendMessage);
}

void Heavy_CircleStrings::cTabhead_P3wS8A0I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_awJtMi5f, HV_BINOP_SUBTRACT, 0, m, &cBinop_awJtMi5f_sendMessage);
}

void Heavy_CircleStrings::cBinop_PXFF8jUh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MEzGKBmE, HV_BINOP_MAX, 0, m, &cBinop_MEzGKBmE_sendMessage);
}

void Heavy_CircleStrings::sTabread_WNNBKTF8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_bQmEHkS3, HV_BINOP_SUBTRACT, 0, m, &cBinop_bQmEHkS3_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cSystem_X6muOth1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_bQmEHkS3, HV_BINOP_SUBTRACT, 1, m, &cBinop_bQmEHkS3_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_BqXxqAAL, 2, m, &cDelay_BqXxqAAL_sendMessage);
}

void Heavy_CircleStrings::cVar_X9zKhtxI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_NZOhvBHS_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_XvcAeCln_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_JyssfCSo, 2, m, &cDelay_JyssfCSo_sendMessage);
}

void Heavy_CircleStrings::cBinop_awJtMi5f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_r8D2hWo4_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_WNNBKTF8, 0, m, &sTabread_WNNBKTF8_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_iwbptpJ2_sendMessage);
}

void Heavy_CircleStrings::cBinop_bQmEHkS3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_XvcAeCln_sendMessage);
}

void Heavy_CircleStrings::cCast_iwbptpJ2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_JyssfCSo, 0, m, &cDelay_JyssfCSo_sendMessage);
}

void Heavy_CircleStrings::cBinop_kRYjVfhM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_PXFF8jUh, HV_BINOP_MULTIPLY, 0, m, &cBinop_PXFF8jUh_sendMessage);
}

void Heavy_CircleStrings::cCast_oLEqnRxi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_X9zKhtxI, 0, m, &cVar_X9zKhtxI_sendMessage);
  cMsg_Ub6hZTeD_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_P3wS8A0I, 0, m, &cTabhead_P3wS8A0I_sendMessage);
}

void Heavy_CircleStrings::cMsg_r8D2hWo4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_JyssfCSo, 0, m, &cDelay_JyssfCSo_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_BqXxqAAL, 0, m, &cDelay_BqXxqAAL_sendMessage);
}

void Heavy_CircleStrings::cSystem_BEh7nvID_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_kRYjVfhM_sendMessage);
}

void Heavy_CircleStrings::cMsg_Ub6hZTeD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_BEh7nvID_sendMessage);
}

void Heavy_CircleStrings::hTable_EB9IrNc4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_lbIiWvQj_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_opGfbWxa, 2, m, &cDelay_opGfbWxa_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_NabON11v_sendMessage);
}

void Heavy_CircleStrings::cMsg_KZlqbbt0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_EB9IrNc4, 0, m, &hTable_EB9IrNc4_sendMessage);
}

void Heavy_CircleStrings::cBinop_LQVVX95x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ORLQgjdS_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_NabON11v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_opGfbWxa, 0, m, &cDelay_opGfbWxa_sendMessage);
}

void Heavy_CircleStrings::cMsg_ORLQgjdS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_EB9IrNc4, 0, m, &hTable_EB9IrNc4_sendMessage);
}

void Heavy_CircleStrings::cMsg_Q2XDi7go_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Qfn39Lqf_sendMessage);
}

void Heavy_CircleStrings::cSystem_Qfn39Lqf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_fVfsr6BU_sendMessage);
}

void Heavy_CircleStrings::cMsg_Z1nbb8tR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_ThO1TOwi, 1, m, NULL);
}

void Heavy_CircleStrings::cBinop_fVfsr6BU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 69.4325f, 0, m, &cBinop_LQVVX95x_sendMessage);
}

void Heavy_CircleStrings::cMsg_lbIiWvQj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_yvYu2VI0, 2, m, &cDelay_yvYu2VI0_sendMessage);
}

void Heavy_CircleStrings::cDelay_opGfbWxa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_opGfbWxa, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_yvYu2VI0, 0, m, &cDelay_yvYu2VI0_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_opGfbWxa, 0, m, &cDelay_opGfbWxa_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_ThO1TOwi, 1, m, NULL);
}

void Heavy_CircleStrings::cSwitchcase_otaQ9aZ6_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_Z1nbb8tR_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cDelay_yvYu2VI0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_yvYu2VI0, m);
  cMsg_KZlqbbt0_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cVar_rKRrml5M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_JVHs3374_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_vPLNdTco, 0, m, &cIf_vPLNdTco_sendMessage);
}

void Heavy_CircleStrings::cBinop_8tMHmxhJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_ytLJqOZ1, m);
}

void Heavy_CircleStrings::cBinop_6jSAZUUK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_8tMHmxhJ_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_fO5JNITB, m);
}

void Heavy_CircleStrings::cBinop_fV3JiwAZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_6jSAZUUK_sendMessage);
}

void Heavy_CircleStrings::cSystem_7cdUX4Hn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_DiGPtKNE_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_Vx8uFmq4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_7cdUX4Hn_sendMessage);
}

void Heavy_CircleStrings::cMsg_DiGPtKNE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_Oi1Ufhs1_sendMessage);
}

void Heavy_CircleStrings::cBinop_Oi1Ufhs1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_dIkB0qZx, HV_BINOP_MULTIPLY, 1, m, &cBinop_dIkB0qZx_sendMessage);
}

void Heavy_CircleStrings::cBinop_dIkB0qZx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_fV3JiwAZ_sendMessage);
}

void Heavy_CircleStrings::cVar_LP6LfgeT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_dIkB0qZx, HV_BINOP_MULTIPLY, 0, m, &cBinop_dIkB0qZx_sendMessage);
}

void Heavy_CircleStrings::cVar_lJepFRYJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_MKYi30Ru_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_BCdM9s6b_sendMessage);
}

void Heavy_CircleStrings::cMsg_1KD7b47b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_SMnvom2o_sendMessage);
}

void Heavy_CircleStrings::cBinop_29D7opEz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_NXnCyZ5Y_sendMessage);
}

void Heavy_CircleStrings::cBinop_6vXGL26j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_gjxfcIYu, HV_BINOP_SUBTRACT, 1, m, &cBinop_gjxfcIYu_sendMessage);
}

void Heavy_CircleStrings::cBinop_BYScuqZB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6vXGL26j, HV_BINOP_MAX, 0, m, &cBinop_6vXGL26j_sendMessage);
}

void Heavy_CircleStrings::cVar_CmamotMH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_1KD7b47b_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_GKgeOSLt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_BYScuqZB, HV_BINOP_MULTIPLY, 0, m, &cBinop_BYScuqZB_sendMessage);
}

void Heavy_CircleStrings::cTabhead_HiWl0REH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_gjxfcIYu, HV_BINOP_SUBTRACT, 0, m, &cBinop_gjxfcIYu_sendMessage);
}

void Heavy_CircleStrings::cDelay_IVZ00RuP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_IVZ00RuP, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_dcr34w93, 0, m, &sTabread_dcr34w93_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_IVZ00RuP, 0, m, &cDelay_IVZ00RuP_sendMessage);
}

void Heavy_CircleStrings::cCast_JaJAqPJ1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_kfFWMzzl, 0, m, &cDelay_kfFWMzzl_sendMessage);
}

void Heavy_CircleStrings::cSystem_X9zhl6kx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_GKgeOSLt_sendMessage);
}

void Heavy_CircleStrings::cMsg_gArjzwDG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_X9zhl6kx_sendMessage);
}

void Heavy_CircleStrings::cBinop_NXnCyZ5Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_kfFWMzzl, 2, m, &cDelay_kfFWMzzl_sendMessage);
}

void Heavy_CircleStrings::cSystem_SMnvom2o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_29D7opEz, HV_BINOP_SUBTRACT, 1, m, &cBinop_29D7opEz_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_IVZ00RuP, 2, m, &cDelay_IVZ00RuP_sendMessage);
}

void Heavy_CircleStrings::cMsg_byZAZmX0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_kfFWMzzl, 0, m, &cDelay_kfFWMzzl_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_IVZ00RuP, 0, m, &cDelay_IVZ00RuP_sendMessage);
}

void Heavy_CircleStrings::sTabread_dcr34w93_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_29D7opEz, HV_BINOP_SUBTRACT, 0, m, &cBinop_29D7opEz_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_gjxfcIYu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_byZAZmX0_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_dcr34w93, 0, m, &sTabread_dcr34w93_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_JaJAqPJ1_sendMessage);
}

void Heavy_CircleStrings::cMsg_hfBwD0ul_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_6vXGL26j, HV_BINOP_MAX, 1, m, &cBinop_6vXGL26j_sendMessage);
}

void Heavy_CircleStrings::cDelay_kfFWMzzl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_kfFWMzzl, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_IVZ00RuP, 0, m, &cDelay_IVZ00RuP_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_dcr34w93, 0, m, &sTabread_dcr34w93_sendMessage);
}

void Heavy_CircleStrings::cCast_qnUvXyt6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_CmamotMH, 0, m, &cVar_CmamotMH_sendMessage);
  cMsg_gArjzwDG_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_HiWl0REH, 0, m, &cTabhead_HiWl0REH_sendMessage);
}

void Heavy_CircleStrings::cPack_MlACp4XR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_42h5BQS2, 0, m, NULL);
}

void Heavy_CircleStrings::cVar_pperUyEz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 100.0f, 0, m, &cBinop_BgwRB1bh_sendMessage);
}

void Heavy_CircleStrings::cMsg_Tmg1ZyNb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 3000.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_pAcmyTme, 0, m, &cVar_pAcmyTme_sendMessage);
}

void Heavy_CircleStrings::cBinop_JVHs3374_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_vPLNdTco, 1, m, &cIf_vPLNdTco_sendMessage);
}

void Heavy_CircleStrings::cIf_vPLNdTco_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_Tmg1ZyNb_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cVar_onMessage(_c, &Context(_c)->cVar_pAcmyTme, 0, m, &cVar_pAcmyTme_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cPack_X0Iep43f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_712JpkDm, 0, m, NULL);
}

void Heavy_CircleStrings::cMsg_29LIlaOf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_rwOMuyMM, 2, m, &cDelay_rwOMuyMM_sendMessage);
}

void Heavy_CircleStrings::cMsg_3jqA1lV6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_lA7P06zw, 0, m, &hTable_lA7P06zw_sendMessage);
}

void Heavy_CircleStrings::cBinop_432Dk4Bc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_S5frDtKM_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_AyBSTvQl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_eUadoWDE_sendMessage);
}

void Heavy_CircleStrings::cSystem_eUadoWDE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_QKeJjtvr_sendMessage);
}

void Heavy_CircleStrings::cMsg_OxLBFjtH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_dYe953Jv, 1, m, NULL);
}

void Heavy_CircleStrings::cBinop_QKeJjtvr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 74.5234f, 0, m, &cBinop_432Dk4Bc_sendMessage);
}

void Heavy_CircleStrings::cMsg_S5frDtKM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_lA7P06zw, 0, m, &hTable_lA7P06zw_sendMessage);
}

void Heavy_CircleStrings::cDelay_TuXtPgx8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_TuXtPgx8, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_rwOMuyMM, 0, m, &cDelay_rwOMuyMM_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_TuXtPgx8, 0, m, &cDelay_TuXtPgx8_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_dYe953Jv, 1, m, NULL);
}

void Heavy_CircleStrings::cSwitchcase_ZnFQ5VXv_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_OxLBFjtH_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::hTable_lA7P06zw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_29LIlaOf_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_TuXtPgx8, 2, m, &cDelay_TuXtPgx8_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_xUbeWThw_sendMessage);
}

void Heavy_CircleStrings::cDelay_rwOMuyMM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_rwOMuyMM, m);
  cMsg_3jqA1lV6_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_xUbeWThw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_TuXtPgx8, 0, m, &cDelay_TuXtPgx8_sendMessage);
}

void Heavy_CircleStrings::cVar_pAcmyTme_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_b5xo0pt9, 0, m, &cVar_b5xo0pt9_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_Pr8OI5bX, 0, m, &cVar_Pr8OI5bX_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_LP6LfgeT, 0, m, &cVar_LP6LfgeT_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_8gEUlKK0, 0, m, &cVar_8gEUlKK0_sendMessage);
}

void Heavy_CircleStrings::cBinop_BgwRB1bh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_MOQyvpVD_sendMessage);
}

void Heavy_CircleStrings::cBinop_MOQyvpVD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 200.0f, 0, m, &cBinop_fqpPVyly_sendMessage);
}

void Heavy_CircleStrings::cVar_jxvmbT3n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.01f, 0, m, &cBinop_hF6qtUiu_sendMessage);
}

void Heavy_CircleStrings::cBinop_fqpPVyly_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_MlACp4XR, 0, m, &cPack_MlACp4XR_sendMessage);
}

void Heavy_CircleStrings::cBinop_hF6qtUiu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_nnJOliZ3, 0, m, &cPack_nnJOliZ3_sendMessage);
}

void Heavy_CircleStrings::sTabread_0FiP8cTk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_zR9EQkhP, HV_BINOP_SUBTRACT, 0, m, &cBinop_zR9EQkhP_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cTabhead_25RelK01_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_B7xEYXrU, HV_BINOP_SUBTRACT, 0, m, &cBinop_B7xEYXrU_sendMessage);
}

void Heavy_CircleStrings::cMsg_AkD6AQBv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_NKIP7EOa, HV_BINOP_MAX, 1, m, &cBinop_NKIP7EOa_sendMessage);
}

void Heavy_CircleStrings::cBinop_B7xEYXrU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_SeMT4tjI_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_0FiP8cTk, 0, m, &sTabread_0FiP8cTk_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_bi1g41X8_sendMessage);
}

void Heavy_CircleStrings::cSystem_DxncaxJs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_zR9EQkhP, HV_BINOP_SUBTRACT, 1, m, &cBinop_zR9EQkhP_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_pihtF4GQ, 2, m, &cDelay_pihtF4GQ_sendMessage);
}

void Heavy_CircleStrings::cBinop_NKIP7EOa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_B7xEYXrU, HV_BINOP_SUBTRACT, 1, m, &cBinop_B7xEYXrU_sendMessage);
}

void Heavy_CircleStrings::cBinop_QtAaF8GU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_iTXLVM62, 2, m, &cDelay_iTXLVM62_sendMessage);
}

void Heavy_CircleStrings::cCast_S3oSG0AV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_cbViQofB, 0, m, &cVar_cbViQofB_sendMessage);
  cMsg_LFX6ALvj_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_25RelK01, 0, m, &cTabhead_25RelK01_sendMessage);
}

void Heavy_CircleStrings::cMsg_SeMT4tjI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_iTXLVM62, 0, m, &cDelay_iTXLVM62_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_pihtF4GQ, 0, m, &cDelay_pihtF4GQ_sendMessage);
}

void Heavy_CircleStrings::cCast_bi1g41X8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_iTXLVM62, 0, m, &cDelay_iTXLVM62_sendMessage);
}

void Heavy_CircleStrings::cVar_cbViQofB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_v3ofwXQv_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_dw3iN5tH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_NKIP7EOa, HV_BINOP_MAX, 0, m, &cBinop_NKIP7EOa_sendMessage);
}

void Heavy_CircleStrings::cDelay_iTXLVM62_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_iTXLVM62, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_pihtF4GQ, 0, m, &cDelay_pihtF4GQ_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_0FiP8cTk, 0, m, &sTabread_0FiP8cTk_sendMessage);
}

void Heavy_CircleStrings::cSystem_06LFsMo9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_zi8joUav_sendMessage);
}

void Heavy_CircleStrings::cMsg_LFX6ALvj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_06LFsMo9_sendMessage);
}

void Heavy_CircleStrings::cDelay_pihtF4GQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_pihtF4GQ, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_0FiP8cTk, 0, m, &sTabread_0FiP8cTk_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_pihtF4GQ, 0, m, &cDelay_pihtF4GQ_sendMessage);
}

void Heavy_CircleStrings::cMsg_v3ofwXQv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_DxncaxJs_sendMessage);
}

void Heavy_CircleStrings::cBinop_zR9EQkhP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_QtAaF8GU_sendMessage);
}

void Heavy_CircleStrings::cBinop_zi8joUav_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_dw3iN5tH, HV_BINOP_MULTIPLY, 0, m, &cBinop_dw3iN5tH_sendMessage);
}

void Heavy_CircleStrings::cBinop_MNudm50C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_yozXBuwp, m);
}

void Heavy_CircleStrings::cVar_8gEUlKK0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_S97a2am2, HV_BINOP_MULTIPLY, 0, m, &cBinop_S97a2am2_sendMessage);
}

void Heavy_CircleStrings::cBinop_H3KGxhyd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_MNudm50C_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_7ceypeny, m);
}

void Heavy_CircleStrings::cBinop_kCS2sOHu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_H3KGxhyd_sendMessage);
}

void Heavy_CircleStrings::cMsg_0JdY56Zn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_6qPaJtU7_sendMessage);
}

void Heavy_CircleStrings::cBinop_6qPaJtU7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_S97a2am2, HV_BINOP_MULTIPLY, 1, m, &cBinop_S97a2am2_sendMessage);
}

void Heavy_CircleStrings::cSystem_97Vqbe7c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_0JdY56Zn_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_mkXlsNcY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_97Vqbe7c_sendMessage);
}

void Heavy_CircleStrings::cBinop_S97a2am2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_kCS2sOHu_sendMessage);
}

void Heavy_CircleStrings::hTable_4ntfDiqh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_iduPjlsA_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_AOmra5OL, 2, m, &cDelay_AOmra5OL_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_z887Guf5_sendMessage);
}

void Heavy_CircleStrings::cDelay_AOmra5OL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_AOmra5OL, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_BWObrq2f, 0, m, &cDelay_BWObrq2f_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_AOmra5OL, 0, m, &cDelay_AOmra5OL_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_0cKRKTGy, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_BWObrq2f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_BWObrq2f, m);
  cMsg_Ikzopo2u_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_Ikzopo2u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_4ntfDiqh, 0, m, &hTable_4ntfDiqh_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_Majfm0GP_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_MfuI8cIc_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cMsg_MfuI8cIc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_0cKRKTGy, 1, m, NULL);
}

void Heavy_CircleStrings::cBinop_S25VxXuR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_tyHRiS7V_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_VTkRp2LD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 86.1244f, 0, m, &cBinop_S25VxXuR_sendMessage);
}

void Heavy_CircleStrings::cMsg_iduPjlsA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_BWObrq2f, 2, m, &cDelay_BWObrq2f_sendMessage);
}

void Heavy_CircleStrings::cMsg_32B8qYsX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_dPpdiuon_sendMessage);
}

void Heavy_CircleStrings::cSystem_dPpdiuon_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_VTkRp2LD_sendMessage);
}

void Heavy_CircleStrings::cMsg_tyHRiS7V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_4ntfDiqh, 0, m, &hTable_4ntfDiqh_sendMessage);
}

void Heavy_CircleStrings::cCast_z887Guf5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_AOmra5OL, 0, m, &cDelay_AOmra5OL_sendMessage);
}

void Heavy_CircleStrings::cVar_58IFI2fq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_go72n3cB_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cTabhead_6yp286bY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_w4V5NSG4, HV_BINOP_SUBTRACT, 0, m, &cBinop_w4V5NSG4_sendMessage);
}

void Heavy_CircleStrings::cCast_IjUpociI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_nkhruJbv, 0, m, &cDelay_nkhruJbv_sendMessage);
}

void Heavy_CircleStrings::cBinop_KfXKcftt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_sixAVXL2_sendMessage);
}

void Heavy_CircleStrings::cMsg_LMATvgMi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_pQQ01gwp, HV_BINOP_MAX, 1, m, &cBinop_pQQ01gwp_sendMessage);
}

void Heavy_CircleStrings::sTabread_VTNOHwN0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_KfXKcftt, HV_BINOP_SUBTRACT, 0, m, &cBinop_KfXKcftt_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cCast_XJwhKb1l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_58IFI2fq, 0, m, &cVar_58IFI2fq_sendMessage);
  cMsg_Zi5lNQLi_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_6yp286bY, 0, m, &cTabhead_6yp286bY_sendMessage);
}

void Heavy_CircleStrings::cMsg_bi9h8UQd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_nkhruJbv, 0, m, &cDelay_nkhruJbv_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_u6b8GX5M, 0, m, &cDelay_u6b8GX5M_sendMessage);
}

void Heavy_CircleStrings::cMsg_go72n3cB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_r5QMKXHk_sendMessage);
}

void Heavy_CircleStrings::cSystem_Sj0NUwr7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_n4i9wjUG_sendMessage);
}

void Heavy_CircleStrings::cMsg_Zi5lNQLi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Sj0NUwr7_sendMessage);
}

void Heavy_CircleStrings::cBinop_jOZg8GKF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_pQQ01gwp, HV_BINOP_MAX, 0, m, &cBinop_pQQ01gwp_sendMessage);
}

void Heavy_CircleStrings::cBinop_n4i9wjUG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_jOZg8GKF, HV_BINOP_MULTIPLY, 0, m, &cBinop_jOZg8GKF_sendMessage);
}

void Heavy_CircleStrings::cDelay_nkhruJbv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_nkhruJbv, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_u6b8GX5M, 0, m, &cDelay_u6b8GX5M_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_VTNOHwN0, 0, m, &sTabread_VTNOHwN0_sendMessage);
}

void Heavy_CircleStrings::cBinop_pQQ01gwp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_w4V5NSG4, HV_BINOP_SUBTRACT, 1, m, &cBinop_w4V5NSG4_sendMessage);
}

void Heavy_CircleStrings::cSystem_r5QMKXHk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_KfXKcftt, HV_BINOP_SUBTRACT, 1, m, &cBinop_KfXKcftt_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_u6b8GX5M, 2, m, &cDelay_u6b8GX5M_sendMessage);
}

void Heavy_CircleStrings::cBinop_sixAVXL2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_nkhruJbv, 2, m, &cDelay_nkhruJbv_sendMessage);
}

void Heavy_CircleStrings::cDelay_u6b8GX5M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_u6b8GX5M, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_VTNOHwN0, 0, m, &sTabread_VTNOHwN0_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_u6b8GX5M, 0, m, &cDelay_u6b8GX5M_sendMessage);
}

void Heavy_CircleStrings::cBinop_w4V5NSG4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_bi9h8UQd_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_VTNOHwN0, 0, m, &sTabread_VTNOHwN0_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_IjUpociI_sendMessage);
}

void Heavy_CircleStrings::cBinop_6IzpFg3r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_rDMUqotd, m);
}

void Heavy_CircleStrings::cVar_b5xo0pt9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_iE7W71iG, HV_BINOP_MULTIPLY, 0, m, &cBinop_iE7W71iG_sendMessage);
}

void Heavy_CircleStrings::cMsg_Tv8sv2VF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_tq2zCPOa_sendMessage);
}

void Heavy_CircleStrings::cSystem_0B0Lib5T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Tv8sv2VF_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_SR7hPznG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_0B0Lib5T_sendMessage);
}

void Heavy_CircleStrings::cBinop_iE7W71iG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_KB1XW69P_sendMessage);
}

void Heavy_CircleStrings::cBinop_tq2zCPOa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_iE7W71iG, HV_BINOP_MULTIPLY, 1, m, &cBinop_iE7W71iG_sendMessage);
}

void Heavy_CircleStrings::cBinop_KB1XW69P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_VyRFaIWy_sendMessage);
}

void Heavy_CircleStrings::cBinop_VyRFaIWy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_6IzpFg3r_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_dd13PCu6, m);
}

void Heavy_CircleStrings::cPack_nnJOliZ3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_ocji4mRy, 0, m, NULL);
}

void Heavy_CircleStrings::cBinop_4w972H37_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_iAvcC65A, 1, m, &cIf_iAvcC65A_sendMessage);
}

void Heavy_CircleStrings::cCast_BCdM9s6b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_iAvcC65A, 0, m, &cIf_iAvcC65A_sendMessage);
}

void Heavy_CircleStrings::cBinop_HoklGSkr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_vF0MFQF5_sendMessage);
}

void Heavy_CircleStrings::cCast_MKYi30Ru_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_4w972H37_sendMessage);
}

void Heavy_CircleStrings::cBinop_PbTS2Ewa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.125f, 0, m, &cBinop_uPTwLSrX_sendMessage);
}

void Heavy_CircleStrings::cBinop_Xy9VOMEQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_HoklGSkr_sendMessage);
}

void Heavy_CircleStrings::cMsg_YDIiTzgP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.125f, 0, m, &cBinop_uPTwLSrX_sendMessage);
}

void Heavy_CircleStrings::cIf_iAvcC65A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_YDIiTzgP_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_Xy9VOMEQ_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cMsg_jd0QSfwR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_PbTS2Ewa, HV_BINOP_POW, 0, m, &cBinop_PbTS2Ewa_sendMessage);
}

void Heavy_CircleStrings::cBinop_vF0MFQF5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_PbTS2Ewa, HV_BINOP_POW, 1, m, &cBinop_PbTS2Ewa_sendMessage);
  cMsg_jd0QSfwR_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_uPTwLSrX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_X0Iep43f, 0, m, &cPack_X0Iep43f_sendMessage);
}

void Heavy_CircleStrings::cCast_042yoXJ3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_YCkBOnJH, 0, m, &cDelay_YCkBOnJH_sendMessage);
}

void Heavy_CircleStrings::hTable_3uLj1yGs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_oct3CGxy_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_YCkBOnJH, 2, m, &cDelay_YCkBOnJH_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_042yoXJ3_sendMessage);
}

void Heavy_CircleStrings::cMsg_9GHlIlKa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_3uLj1yGs, 0, m, &hTable_3uLj1yGs_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_HYMCHgz1_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_mBu9oTLu_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cDelay_YCkBOnJH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_YCkBOnJH, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_kLk2DX0g, 0, m, &cDelay_kLk2DX0g_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_YCkBOnJH, 0, m, &cDelay_YCkBOnJH_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_9a733PFq, 1, m, NULL);
}

void Heavy_CircleStrings::cBinop_bMr6R5go_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 58.6435f, 0, m, &cBinop_grkTr9eY_sendMessage);
}

void Heavy_CircleStrings::cMsg_XIEBpbZK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_poRBq8Yk_sendMessage);
}

void Heavy_CircleStrings::cSystem_poRBq8Yk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_bMr6R5go_sendMessage);
}

void Heavy_CircleStrings::cBinop_grkTr9eY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_9GHlIlKa_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_kLk2DX0g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_kLk2DX0g, m);
  cMsg_r6nXlxRF_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_mBu9oTLu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_9a733PFq, 1, m, NULL);
}

void Heavy_CircleStrings::cMsg_oct3CGxy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_kLk2DX0g, 2, m, &cDelay_kLk2DX0g_sendMessage);
}

void Heavy_CircleStrings::cMsg_r6nXlxRF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_3uLj1yGs, 0, m, &hTable_3uLj1yGs_sendMessage);
}

void Heavy_CircleStrings::cMsg_QuKgyp3j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 500.0f);
  sVarf_onMessage(_c, &Context(_c)->sVarf_cLYSr7VT, m);
}

void Heavy_CircleStrings::cVar_A6KZg1dy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_oxCIdad0, 0, m, &cPack_oxCIdad0_sendMessage);
}

void Heavy_CircleStrings::cCast_VpBFxQUK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_oxCIdad0, 0, m, &cPack_oxCIdad0_sendMessage);
}

void Heavy_CircleStrings::cMsg_bfS7EC1Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 500.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_R8giMv5K, 0, m, NULL);
}

void Heavy_CircleStrings::cSwitchcase_80GY7huL_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_Zd4DJRXy_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_Zd4DJRXy_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_qDqClzAx, 1, m, &cDelay_qDqClzAx_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ADgGe3Om_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cCast_ADgGe3Om_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_qDqClzAx, 0, m, &cDelay_qDqClzAx_sendMessage);
}

void Heavy_CircleStrings::cMsg_Zd4DJRXy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_qDqClzAx, 0, m, &cDelay_qDqClzAx_sendMessage);
}

void Heavy_CircleStrings::cDelay_qDqClzAx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_qDqClzAx, m);
  cMsg_bfS7EC1Q_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cPack_oxCIdad0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_R8giMv5K, 0, m, NULL);
}

void Heavy_CircleStrings::cBinop_ESjGaIKk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_FiECT7xg, m);
}

void Heavy_CircleStrings::cBinop_UiIZVEXg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, -1.0f, 0, m, &cBinop_ESjGaIKk_sendMessage);
}

void Heavy_CircleStrings::cVar_qUYSyPZN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_m9H4Ho1w_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_8SzqVjTS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_rlBUEcPD, m);
}

void Heavy_CircleStrings::cBinop_PRyGPmKP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_EdYNnOyL, m);
}

void Heavy_CircleStrings::cSystem_EH60Ozpi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_PRyGPmKP_sendMessage);
}

void Heavy_CircleStrings::cMsg_cSd6gTbo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_EH60Ozpi_sendMessage);
}

void Heavy_CircleStrings::cMsg_m6umx7jZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_yXI1BX5X_sendMessage);
}

void Heavy_CircleStrings::cSystem_yXI1BX5X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_8SzqVjTS_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_IK0GYyj3, m);
}

void Heavy_CircleStrings::cVar_IGYRqCHB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_m6umx7jZ_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSystem_dSdm6Hr6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_snxSGQG0, HV_BINOP_DIVIDE, 1, m, &cBinop_snxSGQG0_sendMessage);
}

void Heavy_CircleStrings::cMsg_pVSD1bKQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_dSdm6Hr6_sendMessage);
}

void Heavy_CircleStrings::cBinop_HehHXfVk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_fwnrGLb9_sendMessage);
}

void Heavy_CircleStrings::cVar_Aif40NUS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_HehHXfVk_sendMessage);
}

void Heavy_CircleStrings::cMsg_Uf1rOSSw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_ks0vLBKF_sendMessage);
}

void Heavy_CircleStrings::cBinop_XzqLECX6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_nriNIk02_sendMessage);
}

void Heavy_CircleStrings::cBinop_fwnrGLb9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_snxSGQG0, HV_BINOP_DIVIDE, 0, m, &cBinop_snxSGQG0_sendMessage);
}

void Heavy_CircleStrings::cBinop_ks0vLBKF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_RhAU7w7X_sendMessage);
}

void Heavy_CircleStrings::cBinop_BCgp2vql_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_XzqLECX6_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_nEBjSKLi_sendMessage);
}

void Heavy_CircleStrings::cBinop_RhAU7w7X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_BCgp2vql_sendMessage);
}

void Heavy_CircleStrings::cBinop_nEBjSKLi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_tFkk8usR, m);
}

void Heavy_CircleStrings::cBinop_nriNIk02_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_bialIhQG, m);
}

void Heavy_CircleStrings::cBinop_snxSGQG0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Uf1rOSSw_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cVar_2BrxM752_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_9DhEmGRi, HV_BINOP_MULTIPLY, 0, m, &cBinop_9DhEmGRi_sendMessage);
}

void Heavy_CircleStrings::cBinop_JRTajrdJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_wxEDt9Ux, m);
}

void Heavy_CircleStrings::cBinop_3S0HTQWe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_JRTajrdJ_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_vRSPZDVu, m);
}

void Heavy_CircleStrings::cBinop_mwnNoMXW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_3S0HTQWe_sendMessage);
}

void Heavy_CircleStrings::cBinop_9DhEmGRi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_mwnNoMXW_sendMessage);
}

void Heavy_CircleStrings::cMsg_F3k3QbJS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_JumJtWiX_sendMessage);
}

void Heavy_CircleStrings::cSystem_QjzBFJvG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_F3k3QbJS_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_Y8Drs0t6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_QjzBFJvG_sendMessage);
}

void Heavy_CircleStrings::cBinop_JumJtWiX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_9DhEmGRi, HV_BINOP_MULTIPLY, 1, m, &cBinop_9DhEmGRi_sendMessage);
}

void Heavy_CircleStrings::cDelay_4vUxNJI0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_4vUxNJI0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_DbKD5tga, 0, m, &cDelay_DbKD5tga_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_4vUxNJI0, 0, m, &cDelay_4vUxNJI0_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_BK4qaso8, 1, m, NULL);
}

void Heavy_CircleStrings::hTable_B9HtbLqp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_op99vhXo_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_4vUxNJI0, 2, m, &cDelay_4vUxNJI0_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_H5FzhGY8_sendMessage);
}

void Heavy_CircleStrings::cMsg_BYJFqe9K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_B9HtbLqp, 0, m, &hTable_B9HtbLqp_sendMessage);
}

void Heavy_CircleStrings::cDelay_DbKD5tga_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_DbKD5tga, m);
  cMsg_QyBT0mzm_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSystem_mUI5nSUH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_kI7llMSj_sendMessage);
}

void Heavy_CircleStrings::cMsg_tQkRkM77_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_mUI5nSUH_sendMessage);
}

void Heavy_CircleStrings::cCast_H5FzhGY8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_4vUxNJI0, 0, m, &cDelay_4vUxNJI0_sendMessage);
}

void Heavy_CircleStrings::cMsg_QyBT0mzm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_B9HtbLqp, 0, m, &hTable_B9HtbLqp_sendMessage);
}

void Heavy_CircleStrings::cBinop_YwouG0R1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_BYJFqe9K_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_gv4JSvvA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_BK4qaso8, 1, m, NULL);
}

void Heavy_CircleStrings::cBinop_kI7llMSj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 500.0f, 0, m, &cBinop_YwouG0R1_sendMessage);
}

void Heavy_CircleStrings::cMsg_op99vhXo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_DbKD5tga, 2, m, &cDelay_DbKD5tga_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_wa7M0Cv1_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
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

void Heavy_CircleStrings::cMsg_m9H4Ho1w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 20.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_ZCy7aZjx, 0, m, NULL);
}

void Heavy_CircleStrings::cMsg_xkjga8iw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cMsg_m9H4Ho1w_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_xvcGTgrh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.3f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_UiIZVEXg_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_FtGrQpE9_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_l3aBboEX, 0, m, &cSlice_l3aBboEX_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_Ooqb3idw, 0, m, &cRandom_Ooqb3idw_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cRandom_Ooqb3idw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 25.0f, 0, m, &cBinop_YXqGEjIK_sendMessage);
}

void Heavy_CircleStrings::cBinop_YXqGEjIK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_i6tzG4cg_sendMessage);
}

void Heavy_CircleStrings::cUnop_i6tzG4cg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 40.0f, 0, m, &cBinop_NmBa5KkM_sendMessage);
}

void Heavy_CircleStrings::cSlice_l3aBboEX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_Ooqb3idw, 1, m, &cRandom_Ooqb3idw_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_7LPHN0NA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_r00vRbTY, m);
}

void Heavy_CircleStrings::cBinop_7Xvxu4rE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_iTQ4HjJE, m);
}

void Heavy_CircleStrings::cBinop_N7qKqvxi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_eOKUIqlV_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_7Xvxu4rE_sendMessage);
}

void Heavy_CircleStrings::cBinop_iep9NulX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_N7qKqvxi_sendMessage);
}

void Heavy_CircleStrings::cBinop_LPTJYrUI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_c3Mwp4Ae_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_MDr4RZ6v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_LPTJYrUI, HV_BINOP_DIVIDE, 0, m, &cBinop_LPTJYrUI_sendMessage);
}

void Heavy_CircleStrings::cVar_jiPKR3cA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_v5HeQKNL_sendMessage);
}

void Heavy_CircleStrings::cBinop_Tky2vR8S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_5VoUMfdc, m);
}

void Heavy_CircleStrings::cSystem_N2oaa2E2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_LPTJYrUI, HV_BINOP_DIVIDE, 1, m, &cBinop_LPTJYrUI_sendMessage);
}

void Heavy_CircleStrings::cMsg_uzWvTynq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_N2oaa2E2_sendMessage);
}

void Heavy_CircleStrings::cMsg_c3Mwp4Ae_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_rPJtY3Av_sendMessage);
}

void Heavy_CircleStrings::cBinop_eOKUIqlV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_Tky2vR8S_sendMessage);
}

void Heavy_CircleStrings::cBinop_rPJtY3Av_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_iep9NulX_sendMessage);
}

void Heavy_CircleStrings::cBinop_v5HeQKNL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_MDr4RZ6v_sendMessage);
}

void Heavy_CircleStrings::cBinop_GRC2Y3gO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2200.0f, 0, m, &cBinop_MSUiSskw_sendMessage);
}

void Heavy_CircleStrings::cBinop_GWlpQv24_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_7mffYINl, 0, m, &cVar_7mffYINl_sendMessage);
}

void Heavy_CircleStrings::cPack_HGvb5mmk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_gvPUKwRU, 0, m, NULL);
}

void Heavy_CircleStrings::cMsg_JgcBfXCJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 4600.0f, 0, m, &cBinop_GRC2Y3gO_sendMessage);
}

void Heavy_CircleStrings::cIf_GfX4fkhS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 0.0f, 0, m, &cBinop_XvEdNmLJ_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_JXVsuz09, 0, m, &cIf_JXVsuz09_sendMessage);
      break;
    }
    case 1: {
      cMsg_JgcBfXCJ_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_JQ8XH6mX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_GfX4fkhS, 1, m, &cIf_GfX4fkhS_sendMessage);
}

void Heavy_CircleStrings::cIf_JXVsuz09_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_wA9IjUay_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 4600.0f, 0, m, &cBinop_GRC2Y3gO_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_XvEdNmLJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_JXVsuz09, 1, m, &cIf_JXVsuz09_sendMessage);
}

void Heavy_CircleStrings::cMsg_wA9IjUay_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 4600.0f, 0, m, &cBinop_GRC2Y3gO_sendMessage);
}

void Heavy_CircleStrings::cVar_nBGSYJ0W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_i8d8BEPv_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_qJIErgYV_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_s5j2oaLL_sendMessage);
}

void Heavy_CircleStrings::cBinop_MSUiSskw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_TLSoiMLz, 0, m, &cVar_TLSoiMLz_sendMessage);
}

void Heavy_CircleStrings::cBinop_NmBa5KkM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ncAXTAcc, 0, m, &cVar_ncAXTAcc_sendMessage);
}

void Heavy_CircleStrings::cBinop_TmBUKM5C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5f, 0, m, &cBinop_jTtQz9C9_sendMessage);
}

void Heavy_CircleStrings::cVar_7mffYINl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cMsg_KhoufUiL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_cQJWnIZi, 0, m, &cDelay_cQJWnIZi_sendMessage);
}

void Heavy_CircleStrings::cBinop_NreiNAi5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_qGYudbvd, HV_BINOP_MULTIPLY, 1, m, &cBinop_qGYudbvd_sendMessage);
}

void Heavy_CircleStrings::cCast_OpfW3Uly_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_KhoufUiL_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_cQJWnIZi, 0, m, &cDelay_cQJWnIZi_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_nBGSYJ0W, 0, m, &cVar_nBGSYJ0W_sendMessage);
  cSwitchcase_FtGrQpE9_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cDelay_cQJWnIZi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_cQJWnIZi, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_cQJWnIZi, 0, m, &cDelay_cQJWnIZi_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_nBGSYJ0W, 0, m, &cVar_nBGSYJ0W_sendMessage);
  cSwitchcase_FtGrQpE9_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cBinop_jZcs1OLm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_cQJWnIZi, 2, m, &cDelay_cQJWnIZi_sendMessage);
}

void Heavy_CircleStrings::cBinop_qGYudbvd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_jZcs1OLm_sendMessage);
}

void Heavy_CircleStrings::cSystem_FOxlk4ls_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_NreiNAi5_sendMessage);
}

void Heavy_CircleStrings::cMsg_xR7HV7wd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_FOxlk4ls_sendMessage);
}

void Heavy_CircleStrings::cVar_ncAXTAcc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_qGYudbvd, HV_BINOP_MULTIPLY, 0, m, &cBinop_qGYudbvd_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_yK7BW9Y6_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cMsg_KhoufUiL_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_KhoufUiL_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_OpfW3Uly_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_L8uHQv9I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_iiz5HAMK, 1, m, &cVar_iiz5HAMK_sendMessage);
}

void Heavy_CircleStrings::cVar_iiz5HAMK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_L8uHQv9I_sendMessage);
  cSwitchcase_yK7BW9Y6_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cMsg_AhpIUprY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 1.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_mkZIaKBk, 0, m, NULL);
}

void Heavy_CircleStrings::cCast_CHjq4USC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_dkNKq0h2, HV_BINOP_DIVIDE, 1, m, &cBinop_dkNKq0h2_sendMessage);
}

void Heavy_CircleStrings::cMsg_JO08UsvO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 1.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_mkZIaKBk, 0, m, NULL);
}

void Heavy_CircleStrings::cBinop_blPzZN2h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_pambKDL3_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_pYiV6Nwb, m);
}

void Heavy_CircleStrings::cBinop_kh08Rvqn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_blPzZN2h_sendMessage);
}

void Heavy_CircleStrings::cVar_TLSoiMLz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Gbk1u9VD, HV_BINOP_MULTIPLY, 0, m, &cBinop_Gbk1u9VD_sendMessage);
}

void Heavy_CircleStrings::cBinop_pambKDL3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_C0bo0SDW, m);
}

void Heavy_CircleStrings::cMsg_5KQ84O11_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_j3rWS8M4_sendMessage);
}

void Heavy_CircleStrings::cBinop_Gbk1u9VD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_kh08Rvqn_sendMessage);
}

void Heavy_CircleStrings::cMsg_Y8iOGIR7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_a4GvtXTh_sendMessage);
}

void Heavy_CircleStrings::cSystem_a4GvtXTh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_5KQ84O11_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_j3rWS8M4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Gbk1u9VD, HV_BINOP_MULTIPLY, 1, m, &cBinop_Gbk1u9VD_sendMessage);
}

void Heavy_CircleStrings::cMsg_Qyw2nrct_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 60.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_i8d8BEPv_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_qJIErgYV_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_s5j2oaLL_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_3OAFQk3D_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_ZA4zOFPD_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_ZA4zOFPD_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_fCvW9xy6, 1, m, &cDelay_fCvW9xy6_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_G9n95322_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cCast_G9n95322_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_fCvW9xy6, 0, m, &cDelay_fCvW9xy6_sendMessage);
}

void Heavy_CircleStrings::cMsg_ZA4zOFPD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_fCvW9xy6, 0, m, &cDelay_fCvW9xy6_sendMessage);
}

void Heavy_CircleStrings::cDelay_fCvW9xy6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_fCvW9xy6, m);
  cMsg_AhpIUprY_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_0sv3ZQWJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_LxI1HyGl, HV_BINOP_MAX, 1, m, &cBinop_LxI1HyGl_sendMessage);
}

void Heavy_CircleStrings::cVar_1pKxZobp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_l4kk134f_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_DxMYHb9u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_uzWSdlxG_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_OhUPHtZ3, 0, m, &sTabread_OhUPHtZ3_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_mW4j32GD_sendMessage);
}

void Heavy_CircleStrings::cBinop_IIjeAaMu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Xtb8SrTU, HV_BINOP_MULTIPLY, 0, m, &cBinop_Xtb8SrTU_sendMessage);
}

void Heavy_CircleStrings::cBinop_LxI1HyGl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_DxMYHb9u, HV_BINOP_SUBTRACT, 1, m, &cBinop_DxMYHb9u_sendMessage);
}

void Heavy_CircleStrings::cCast_Mw9ow1oD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_1pKxZobp, 0, m, &cVar_1pKxZobp_sendMessage);
  cMsg_MMOLa641_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_nsk9h2Kd, 0, m, &cTabhead_nsk9h2Kd_sendMessage);
}

void Heavy_CircleStrings::sTabread_OhUPHtZ3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_kwlF7ACw, HV_BINOP_SUBTRACT, 0, m, &cBinop_kwlF7ACw_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cSystem_VhMHnWWh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_kwlF7ACw, HV_BINOP_SUBTRACT, 1, m, &cBinop_kwlF7ACw_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ZiHqnTvy, 2, m, &cDelay_ZiHqnTvy_sendMessage);
}

void Heavy_CircleStrings::cBinop_Xtb8SrTU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_LxI1HyGl, HV_BINOP_MAX, 0, m, &cBinop_LxI1HyGl_sendMessage);
}

void Heavy_CircleStrings::cDelay_ZiHqnTvy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_ZiHqnTvy, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_OhUPHtZ3, 0, m, &sTabread_OhUPHtZ3_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ZiHqnTvy, 0, m, &cDelay_ZiHqnTvy_sendMessage);
}

void Heavy_CircleStrings::cMsg_MMOLa641_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_tmJqOAeA_sendMessage);
}

void Heavy_CircleStrings::cSystem_tmJqOAeA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_IIjeAaMu_sendMessage);
}

void Heavy_CircleStrings::cDelay_fb0luNIj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_fb0luNIj, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ZiHqnTvy, 0, m, &cDelay_ZiHqnTvy_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_OhUPHtZ3, 0, m, &sTabread_OhUPHtZ3_sendMessage);
}

void Heavy_CircleStrings::cBinop_ivzwmUjH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_fb0luNIj, 2, m, &cDelay_fb0luNIj_sendMessage);
}

void Heavy_CircleStrings::cBinop_kwlF7ACw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_ivzwmUjH_sendMessage);
}

void Heavy_CircleStrings::cMsg_l4kk134f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_VhMHnWWh_sendMessage);
}

void Heavy_CircleStrings::cCast_mW4j32GD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_fb0luNIj, 0, m, &cDelay_fb0luNIj_sendMessage);
}

void Heavy_CircleStrings::cTabhead_nsk9h2Kd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_DxMYHb9u, HV_BINOP_SUBTRACT, 0, m, &cBinop_DxMYHb9u_sendMessage);
}

void Heavy_CircleStrings::cMsg_uzWSdlxG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_fb0luNIj, 0, m, &cDelay_fb0luNIj_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ZiHqnTvy, 0, m, &cDelay_ZiHqnTvy_sendMessage);
}

void Heavy_CircleStrings::cMsg_ay4T2RzG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1000.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_dkNKq0h2, HV_BINOP_DIVIDE, 0, m, &cBinop_dkNKq0h2_sendMessage);
}

void Heavy_CircleStrings::cVar_23FcSf5Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_i8d8BEPv_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_qJIErgYV_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_s5j2oaLL_sendMessage);
}

void Heavy_CircleStrings::cBinop_dkNKq0h2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Xtb8SrTU, HV_BINOP_MULTIPLY, 1, m, &cBinop_Xtb8SrTU_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Mw9ow1oD_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_fCvW9xy6, 1, m, &cDelay_fCvW9xy6_sendMessage);
}

void Heavy_CircleStrings::cBinop_4T83xkJj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_crFQcUvm_sendMessage);
}

void Heavy_CircleStrings::cRandom_5hyFNydj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8388610.0f, 0, m, &cBinop_4T83xkJj_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_VCnxqSqb_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_oNST9V0A, 0, m, &cSlice_oNST9V0A_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_5hyFNydj, 0, m, &cRandom_5hyFNydj_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cUnop_crFQcUvm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_pclyTK01_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSlice_oNST9V0A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_5hyFNydj, 1, m, &cRandom_5hyFNydj_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cMsg_pclyTK01_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 1.0f);
  sVari_onMessage(_c, &Context(_c)->sVari_kCCmHSeE, m);
}

void Heavy_CircleStrings::cCast_qJIErgYV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_3OAFQk3D_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cCast_s5j2oaLL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_JO08UsvO_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_0S8ec24c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_c2YzKxNd, 2, m, &cDelay_c2YzKxNd_sendMessage);
}

void Heavy_CircleStrings::cMsg_HMBhXlP0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_PIdkt3iU, 0, m, &hTable_PIdkt3iU_sendMessage);
}

void Heavy_CircleStrings::cBinop_N6EoBZYV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 200.0f, 0, m, &cBinop_QG3PqHNA_sendMessage);
}

void Heavy_CircleStrings::hTable_PIdkt3iU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_0S8ec24c_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_oU5jd6Mx, 2, m, &cDelay_oU5jd6Mx_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_wuqSEbyh_sendMessage);
}

void Heavy_CircleStrings::cBinop_QG3PqHNA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_HMBhXlP0_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_bBy8CBzL_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_jewghHGe_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cDelay_c2YzKxNd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_c2YzKxNd, m);
  cMsg_chJvLUmq_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_chJvLUmq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_PIdkt3iU, 0, m, &hTable_PIdkt3iU_sendMessage);
}

void Heavy_CircleStrings::cMsg_jewghHGe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_pU5PGFkG, 1, m, NULL);
}

void Heavy_CircleStrings::cMsg_iBAHMjl4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_u2wf5iuC_sendMessage);
}

void Heavy_CircleStrings::cSystem_u2wf5iuC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_N6EoBZYV_sendMessage);
}

void Heavy_CircleStrings::cDelay_oU5jd6Mx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_oU5jd6Mx, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_c2YzKxNd, 0, m, &cDelay_c2YzKxNd_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_oU5jd6Mx, 0, m, &cDelay_oU5jd6Mx_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_pU5PGFkG, 1, m, NULL);
}

void Heavy_CircleStrings::cCast_wuqSEbyh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_oU5jd6Mx, 0, m, &cDelay_oU5jd6Mx_sendMessage);
}

void Heavy_CircleStrings::cBinop_5RfiQwE1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_KMsF0pMJ_sendMessage);
}

void Heavy_CircleStrings::cBinop_KMsF0pMJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_CHjq4USC_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_vbNyBh3P_sendMessage);
}

void Heavy_CircleStrings::cMsg_ZtzlVAqz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_5RfiQwE1, HV_BINOP_POW, 0, m, &cBinop_5RfiQwE1_sendMessage);
}

void Heavy_CircleStrings::cBinop_dTMKA3fO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_5RfiQwE1, HV_BINOP_POW, 1, m, &cBinop_5RfiQwE1_sendMessage);
  cMsg_ZtzlVAqz_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_i8d8BEPv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_dTMKA3fO_sendMessage);
}

void Heavy_CircleStrings::cCast_vbNyBh3P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ay4T2RzG_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cIf_Vm0EydV4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 0.0f, 0, m, &cBinop_Ya5zT841_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_n9cLGTFg, 0, m, &cIf_n9cLGTFg_sendMessage);
      break;
    }
    case 1: {
      cMsg_RQHZL2VS_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_uC8YrlIw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_Vm0EydV4, 1, m, &cIf_Vm0EydV4_sendMessage);
}

void Heavy_CircleStrings::cMsg_MTZX9EJ5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_HGvb5mmk, 0, m, &cPack_HGvb5mmk_sendMessage);
}

void Heavy_CircleStrings::cMsg_RQHZL2VS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_HGvb5mmk, 0, m, &cPack_HGvb5mmk_sendMessage);
}

void Heavy_CircleStrings::cBinop_Ya5zT841_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_n9cLGTFg, 1, m, &cIf_n9cLGTFg_sendMessage);
}

void Heavy_CircleStrings::cIf_n9cLGTFg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_MTZX9EJ5_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cPack_onMessage(_c, &Context(_c)->cPack_HGvb5mmk, 0, m, &cPack_HGvb5mmk_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cIf_EOLlZAv8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, -1.0f, 0, m, &cBinop_vfLLOk7l_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_w1bg1GGg, 0, m, &cIf_w1bg1GGg_sendMessage);
      break;
    }
    case 1: {
      cMsg_m6Ye80po_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_y6IcNk58_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_EOLlZAv8, 1, m, &cIf_EOLlZAv8_sendMessage);
}

void Heavy_CircleStrings::cMsg_TRY8bBhd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, -1.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.049f, 0, m, &cBinop_i2ZOvpDX_sendMessage);
}

void Heavy_CircleStrings::cMsg_m6Ye80po_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.049f, 0, m, &cBinop_i2ZOvpDX_sendMessage);
}

void Heavy_CircleStrings::cBinop_vfLLOk7l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_w1bg1GGg, 1, m, &cIf_w1bg1GGg_sendMessage);
}

void Heavy_CircleStrings::cIf_w1bg1GGg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_TRY8bBhd_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.049f, 0, m, &cBinop_i2ZOvpDX_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cPack_ghqsILSs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_2qlKKPT3, 0, m, NULL);
}

void Heavy_CircleStrings::cBinop_i2ZOvpDX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.95f, 0, m, &cBinop_7LPHN0NA_sendMessage);
}

void Heavy_CircleStrings::cBinop_jTtQz9C9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_uC8YrlIw_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_Vm0EydV4, 0, m, &cIf_Vm0EydV4_sendMessage);
}

void Heavy_CircleStrings::cMsg_2HStWATz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.2f, 0, m, &cBinop_TmBUKM5C_sendMessage);
}

void Heavy_CircleStrings::cBinop_P9rxUXcZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_TbXZlErM, 1, m, &cIf_TbXZlErM_sendMessage);
}

void Heavy_CircleStrings::cIf_TbXZlErM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 0.0f, 0, m, &cBinop_hezYtxLh_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_YVE7kUDu, 0, m, &cIf_YVE7kUDu_sendMessage);
      break;
    }
    case 1: {
      cMsg_2HStWATz_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cMsg_sGAyQg1E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.2f, 0, m, &cBinop_TmBUKM5C_sendMessage);
}

void Heavy_CircleStrings::cIf_YVE7kUDu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_sGAyQg1E_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.2f, 0, m, &cBinop_TmBUKM5C_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_hezYtxLh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_YVE7kUDu, 1, m, &cIf_YVE7kUDu_sendMessage);
}

void Heavy_CircleStrings::cVar_9gJUbDqP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cBinop_9A90cFAE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_adIMRuo0, 0, m, &cPack_adIMRuo0_sendMessage);
}

void Heavy_CircleStrings::cBinop_ENinJNlJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_nEL19zFx_sendMessage);
}

void Heavy_CircleStrings::cMsg_GmsD7IcC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_adIMRuo0, 0, m, &cPack_adIMRuo0_sendMessage);
}

void Heavy_CircleStrings::cCast_TkiVwixQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_sNLX0V7N, 0, m, &cIf_sNLX0V7N_sendMessage);
}

void Heavy_CircleStrings::cBinop_VHgqMYDt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_ENinJNlJ_sendMessage);
}

void Heavy_CircleStrings::cMsg_f8OeQBW8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_9A90cFAE, HV_BINOP_POW, 0, m, &cBinop_9A90cFAE_sendMessage);
}

void Heavy_CircleStrings::cBinop_nEL19zFx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_9A90cFAE, HV_BINOP_POW, 1, m, &cBinop_9A90cFAE_sendMessage);
  cMsg_f8OeQBW8_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cIf_sNLX0V7N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_GmsD7IcC_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_VHgqMYDt_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_tN9q5Yl6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_sNLX0V7N, 1, m, &cIf_sNLX0V7N_sendMessage);
}

void Heavy_CircleStrings::cCast_xN9sRxKx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_tN9q5Yl6_sendMessage);
}

void Heavy_CircleStrings::cSend_XgUIjavV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_mPRPHvhT_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cPack_adIMRuo0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_wurxiXrM, 0, m, NULL);
}

void Heavy_CircleStrings::cVar_3vk2LYXU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_fh6dLlpv_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_xN9sRxKx_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_TkiVwixQ_sendMessage);
}

void Heavy_CircleStrings::cMsg_fh6dLlpv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSend_iAwddms6_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_iAwddms6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_tD3huP1Y_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cVar_R9h1RyvC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_XgUIjavV_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cReceive_fQU4WAVA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_U4Z28gM9_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_i80OCOSd_sendMessage);
}

void Heavy_CircleStrings::cReceive_hGREsWNt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_D5m1z7gq, 0, m, &cVar_D5m1z7gq_sendMessage);
}

void Heavy_CircleStrings::cReceive_i0dzePDj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_M14zQcnZ, 0, m, &cVar_M14zQcnZ_sendMessage);
}

void Heavy_CircleStrings::cReceive_idSlIBqh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_nOtz2eXo, 0, m, &cVar_nOtz2eXo_sendMessage);
}

void Heavy_CircleStrings::cBinop_1dH5Msc2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_GzRS7d5J_sendMessage);
}

void Heavy_CircleStrings::cBinop_GzRS7d5J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_6o1NmhGr_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_czoTbpnJ_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Ieib1wKz_sendMessage);
}

void Heavy_CircleStrings::cCast_HnGtWMRi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_oHYbKeSH, 0, m, &cIf_oHYbKeSH_sendMessage);
}

void Heavy_CircleStrings::cBinop_gfMUhRsI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 100.0f, 0, m, &cBinop_1dH5Msc2_sendMessage);
}

void Heavy_CircleStrings::cUnop_lEyFGHS6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_gfMUhRsI_sendMessage);
}

void Heavy_CircleStrings::cMsg_mKtMf8gj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cMsg_6o1NmhGr_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_czoTbpnJ_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Ieib1wKz_sendMessage);
}

void Heavy_CircleStrings::cCast_mb2F1pBu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_tdC4qODl_sendMessage);
}

void Heavy_CircleStrings::cIf_oHYbKeSH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_mKtMf8gj_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_LOG10, m, &cUnop_lEyFGHS6_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_tdC4qODl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_oHYbKeSH, 1, m, &cIf_oHYbKeSH_sendMessage);
}

void Heavy_CircleStrings::cBinop_WuLPZ9Os_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_mb2F1pBu_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_HnGtWMRi_sendMessage);
}

void Heavy_CircleStrings::cBinop_bS4JAPIz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_WuLPZ9Os_sendMessage);
}

void Heavy_CircleStrings::cReceive_jeJ3Yki8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_S5GgStLj, 1, m, &cVar_S5GgStLj_sendMessage);
}

void Heavy_CircleStrings::cCast_4ZF8jNMr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_2EzFcBEY_sendMessage);
}

void Heavy_CircleStrings::cSend_5NvOYSa0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_N06e9h3s_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_8ny13VLl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.99f, 0, m, &cBinop_wGBpLuCv_sendMessage);
}

void Heavy_CircleStrings::cCast_2EzFcBEY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_hGnCbDbN, 0, m, &cVar_hGnCbDbN_sendMessage);
}

void Heavy_CircleStrings::cVar_CP2DBLnH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cSend_7hU28yzh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_XsxvudCG_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cVar_W1FCX2at_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cVar_GAvKpMNZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cVar_hGnCbDbN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_RVCIesSe_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Jw7tbWWT_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_fruivyfO_sendMessage);
}

void Heavy_CircleStrings::cSend_GQp6DQ0Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_Doeln2j3_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_Jw7tbWWT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_5VVWbTi9, 1, m, &cVar_5VVWbTi9_sendMessage);
}

void Heavy_CircleStrings::cSend_Q5nzofJu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_Doeln2j3_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_QiyW5DFV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 25.0f);
  cSend_pfTVnwqe_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_RVCIesSe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_jx1d3Jnl_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cVar_5VVWbTi9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_dikOhCD2_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_0ZSTxzRK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_yvob4Z2A, 0, m, &cDelay_yvob4Z2A_sendMessage);
}

void Heavy_CircleStrings::cMsg_5pB4Pzn2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_yvob4Z2A, 0, m, &cDelay_yvob4Z2A_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_P6GWwhRW_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_5pB4Pzn2_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_5pB4Pzn2_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_yvob4Z2A, 1, m, &cDelay_yvob4Z2A_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_0ZSTxzRK_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cDelay_yvob4Z2A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_yvob4Z2A, m);
  cVar_onMessage(_c, &Context(_c)->cVar_5VVWbTi9, 0, m, &cVar_5VVWbTi9_sendMessage);
}

void Heavy_CircleStrings::cSend_ZzVCQfLU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cMsg_bdjPGV80_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 4000.0f);
  cSend_zv7mhpKo_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_cHMLO2GH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSend_Q5nzofJu_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_dikOhCD2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 0);
  sLine_onMessage(_c, &Context(_c)->sLine_hjd1HFtZ, 0, m, NULL);
}

void Heavy_CircleStrings::cCast_fruivyfO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_P6GWwhRW_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cMsg_jx1d3Jnl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 25.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_hjd1HFtZ, 0, m, NULL);
}

void Heavy_CircleStrings::cSend_pfTVnwqe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cSend_zv7mhpKo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_XsxvudCG_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_EhlXxVVp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_z8IefsVX, 0, m, &cPack_z8IefsVX_sendMessage);
}

void Heavy_CircleStrings::cPack_G6fIXAry_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_cC3ArdK1, 0, m, NULL);
}

void Heavy_CircleStrings::cMsg_PVRoS2GR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.5f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_vBV4fd5p_sendMessage);
}

void Heavy_CircleStrings::cPack_Uz12UbaY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_a5hEGEQa, 0, m, NULL);
}

void Heavy_CircleStrings::cUnop_56nHgQbZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_G6fIXAry, 0, m, &cPack_G6fIXAry_sendMessage);
}

void Heavy_CircleStrings::cBinop_vBV4fd5p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_56nHgQbZ_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_SIN, m, &cUnop_os7LMkPF_sendMessage);
}

void Heavy_CircleStrings::cUnop_os7LMkPF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_Uz12UbaY, 0, m, &cPack_Uz12UbaY_sendMessage);
}

void Heavy_CircleStrings::cCast_ItucHW2v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_STDyVeGJ_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cMsg_JnicZYUM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.999f);
  sVarf_onMessage(_c, &Context(_c)->sVarf_NlFqYNsI, m);
}

void Heavy_CircleStrings::cVar_OFphgir9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_EhlXxVVp_sendMessage);
}

void Heavy_CircleStrings::cBinop_MeAy33Eq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ItucHW2v_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_4ZF8jNMr_sendMessage);
}

void Heavy_CircleStrings::cBinop_1dr157Qn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_h01BVglq, HV_BINOP_MULTIPLY, 1, m, &cBinop_h01BVglq_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_yR5KNq7T_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_XMhCPqQn, 1, m, &cDelay_XMhCPqQn_sendMessage);
}

void Heavy_CircleStrings::cCast_2d6WwaW4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_HqUPHlid_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_74ykNvae_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_8Hv6YLUP, m);
}

void Heavy_CircleStrings::cMsg_6LtrH0tF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_9ivztjgt_sendMessage);
}

void Heavy_CircleStrings::cBinop_9ivztjgt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_DomcrxPs, HV_BINOP_MULTIPLY, 1, m, &cBinop_DomcrxPs_sendMessage);
}

void Heavy_CircleStrings::cMsg_UXc6kaxb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_XLoEvUdk_sendMessage);
}

void Heavy_CircleStrings::cSystem_XLoEvUdk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_6LtrH0tF_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_DomcrxPs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_VM2Dv7WM_sendMessage);
}

void Heavy_CircleStrings::cBinop_VM2Dv7WM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_ggrdk30x_sendMessage);
}

void Heavy_CircleStrings::cBinop_ggrdk30x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_74ykNvae_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_Hz4wWSlG, m);
}

void Heavy_CircleStrings::cVar_h4UbNH6N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_DomcrxPs, HV_BINOP_MULTIPLY, 0, m, &cBinop_DomcrxPs_sendMessage);
}

void Heavy_CircleStrings::cMsg_5JsLif86_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 1.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_ed4dzP1v, 0, m, NULL);
}

void Heavy_CircleStrings::cBinop_3ZETouFG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 200.0f, 0, m, &cBinop_7Iwq6luR_sendMessage);
}

void Heavy_CircleStrings::cBinop_7Iwq6luR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_fY6fg01R_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_GsSS5z2N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_GsSS5z2N, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_xXzVRiLA, 0, m, &cDelay_xXzVRiLA_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_GsSS5z2N, 0, m, &cDelay_GsSS5z2N_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_x3Kglaaa, 1, m, NULL);
}

void Heavy_CircleStrings::cCast_aLPpM77H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_GsSS5z2N, 0, m, &cDelay_GsSS5z2N_sendMessage);
}

void Heavy_CircleStrings::cMsg_aRNCQqx8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_x3Kglaaa, 1, m, NULL);
}

void Heavy_CircleStrings::hTable_eT9j3lOK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_nUKnHWIX_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_GsSS5z2N, 2, m, &cDelay_GsSS5z2N_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_aLPpM77H_sendMessage);
}

void Heavy_CircleStrings::cMsg_fY6fg01R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_eT9j3lOK, 0, m, &hTable_eT9j3lOK_sendMessage);
}

void Heavy_CircleStrings::cMsg_nUKnHWIX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_xXzVRiLA, 2, m, &cDelay_xXzVRiLA_sendMessage);
}

void Heavy_CircleStrings::cMsg_pDqBSmLB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_eT9j3lOK, 0, m, &hTable_eT9j3lOK_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_v50DLbIe_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_aRNCQqx8_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cMsg_NTx1L2QY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_m2Npa3lc_sendMessage);
}

void Heavy_CircleStrings::cSystem_m2Npa3lc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_3ZETouFG_sendMessage);
}

void Heavy_CircleStrings::cDelay_xXzVRiLA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_xXzVRiLA, m);
  cMsg_pDqBSmLB_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_HqUPHlid_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 1.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_ed4dzP1v, 0, m, NULL);
}

void Heavy_CircleStrings::cCast_IDFC5Zjl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_z1vDHkuf_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cBinop_0w2XLgLu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_Gyis8ISf_sendMessage);
}

void Heavy_CircleStrings::cMsg_9LBDfYSl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_oX4kyFUI_sendMessage);
}

void Heavy_CircleStrings::sTabread_AYMBNEnS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_0w2XLgLu, HV_BINOP_SUBTRACT, 0, m, &cBinop_0w2XLgLu_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_DaHkZ5dF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_h01BVglq, HV_BINOP_MULTIPLY, 0, m, &cBinop_h01BVglq_sendMessage);
}

void Heavy_CircleStrings::cBinop_Gyis8ISf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_SgxA1ZC2, 2, m, &cDelay_SgxA1ZC2_sendMessage);
}

void Heavy_CircleStrings::cMsg_JdwRblPa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_YhdwsXqf, HV_BINOP_MAX, 1, m, &cBinop_YhdwsXqf_sendMessage);
}

void Heavy_CircleStrings::cSystem_Mw2sEQbO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_DaHkZ5dF_sendMessage);
}

void Heavy_CircleStrings::cMsg_V282R6rK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Mw2sEQbO_sendMessage);
}

void Heavy_CircleStrings::cDelay_SgxA1ZC2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_SgxA1ZC2, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_cLjXDcCl, 0, m, &cDelay_cLjXDcCl_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_AYMBNEnS, 0, m, &sTabread_AYMBNEnS_sendMessage);
}

void Heavy_CircleStrings::cBinop_YhdwsXqf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_pRwTbIoX, HV_BINOP_SUBTRACT, 1, m, &cBinop_pRwTbIoX_sendMessage);
}

void Heavy_CircleStrings::cVar_bFg0Fpz2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_9LBDfYSl_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_cLjXDcCl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_cLjXDcCl, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_AYMBNEnS, 0, m, &sTabread_AYMBNEnS_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_cLjXDcCl, 0, m, &cDelay_cLjXDcCl_sendMessage);
}

void Heavy_CircleStrings::cCast_dcWe0CGv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_SgxA1ZC2, 0, m, &cDelay_SgxA1ZC2_sendMessage);
}

void Heavy_CircleStrings::cBinop_h01BVglq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_YhdwsXqf, HV_BINOP_MAX, 0, m, &cBinop_YhdwsXqf_sendMessage);
}

void Heavy_CircleStrings::cTabhead_i1iEfi1f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_pRwTbIoX, HV_BINOP_SUBTRACT, 0, m, &cBinop_pRwTbIoX_sendMessage);
}

void Heavy_CircleStrings::cSystem_oX4kyFUI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_0w2XLgLu, HV_BINOP_SUBTRACT, 1, m, &cBinop_0w2XLgLu_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_cLjXDcCl, 2, m, &cDelay_cLjXDcCl_sendMessage);
}

void Heavy_CircleStrings::cBinop_pRwTbIoX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_w46NqHVU_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_AYMBNEnS, 0, m, &sTabread_AYMBNEnS_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_dcWe0CGv_sendMessage);
}

void Heavy_CircleStrings::cMsg_w46NqHVU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_SgxA1ZC2, 0, m, &cDelay_SgxA1ZC2_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_cLjXDcCl, 0, m, &cDelay_cLjXDcCl_sendMessage);
}

void Heavy_CircleStrings::cCast_yR5KNq7T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_bFg0Fpz2, 0, m, &cVar_bFg0Fpz2_sendMessage);
  cMsg_V282R6rK_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_i1iEfi1f, 0, m, &cTabhead_i1iEfi1f_sendMessage);
}

void Heavy_CircleStrings::cCast_JSnN7Gla_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_eW62c3Lj_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_aRcvNtFK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_1dr157Qn, HV_BINOP_DIVIDE, 1, m, &cBinop_1dr157Qn_sendMessage);
}

void Heavy_CircleStrings::cMsg_eW62c3Lj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1000.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_1dr157Qn, HV_BINOP_DIVIDE, 0, m, &cBinop_1dr157Qn_sendMessage);
}

void Heavy_CircleStrings::cCast_Nr9CNViH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_XMhCPqQn, 0, m, &cDelay_XMhCPqQn_sendMessage);
}

void Heavy_CircleStrings::cDelay_XMhCPqQn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_XMhCPqQn, m);
  cMsg_5JsLif86_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_v2Hc1D2U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_XMhCPqQn, 0, m, &cDelay_XMhCPqQn_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_z1vDHkuf_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_v2Hc1D2U_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_v2Hc1D2U_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_XMhCPqQn, 1, m, &cDelay_XMhCPqQn_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Nr9CNViH_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cMsg_iFqHe36F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 60.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_Q1F0td1q_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_IDFC5Zjl_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_2d6WwaW4_sendMessage);
}

void Heavy_CircleStrings::cBinop_4aU7Ni4v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_ewLfsmw4_sendMessage);
}

void Heavy_CircleStrings::cBinop_Q1F0td1q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_z0DBgtW1_sendMessage);
}

void Heavy_CircleStrings::cMsg_TToXvT2V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_4aU7Ni4v, HV_BINOP_POW, 0, m, &cBinop_4aU7Ni4v_sendMessage);
}

void Heavy_CircleStrings::cBinop_ewLfsmw4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_aRcvNtFK_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_JSnN7Gla_sendMessage);
}

void Heavy_CircleStrings::cBinop_z0DBgtW1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4aU7Ni4v, HV_BINOP_POW, 1, m, &cBinop_4aU7Ni4v_sendMessage);
  cMsg_TToXvT2V_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cVar_WZwcOsYa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_Q1F0td1q_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_IDFC5Zjl_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_2d6WwaW4_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_8XkhPJjg_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_F2rMqRO1, 0, m, &cSlice_F2rMqRO1_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_LqP1XtAM, 0, m, &cRandom_LqP1XtAM_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cSlice_F2rMqRO1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_LqP1XtAM, 1, m, &cRandom_LqP1XtAM_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cRandom_LqP1XtAM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8388610.0f, 0, m, &cBinop_kcUGPtUh_sendMessage);
}

void Heavy_CircleStrings::cBinop_kcUGPtUh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_qVpHGGcj_sendMessage);
}

void Heavy_CircleStrings::cUnop_qVpHGGcj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_rCEWKSgd_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_rCEWKSgd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 1.0f);
  sVari_onMessage(_c, &Context(_c)->sVari_VvwsZqxY, m);
}

void Heavy_CircleStrings::cMsg_0Xpe4POt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_Mh7qOlAm, HV_BINOP_POW, 0, m, &cBinop_Mh7qOlAm_sendMessage);
}

void Heavy_CircleStrings::cBinop_Mh7qOlAm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_YLgj1ukC_sendMessage);
}

void Heavy_CircleStrings::cBinop_YLgj1ukC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MeAy33Eq, HV_BINOP_MULTIPLY, 0, m, &cBinop_MeAy33Eq_sendMessage);
}

void Heavy_CircleStrings::cBinop_gRxYPpxw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Mh7qOlAm, HV_BINOP_POW, 1, m, &cBinop_Mh7qOlAm_sendMessage);
  cMsg_0Xpe4POt_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_iitru23p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_gRxYPpxw_sendMessage);
}

void Heavy_CircleStrings::cBinop_Z9giYb1b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_vBV4fd5p_sendMessage);
}

void Heavy_CircleStrings::cSend_aTXxggpL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_Ugl1BgiH_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_beofWh8Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_Q3DzEQIL_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_dEIWR7DB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 200.0f);
  cSend_aTXxggpL_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_h72IJPvd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_PiOKx4mX_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cBinop_ow1xervc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.4f, 0, m, &cBinop_Z9giYb1b_sendMessage);
}

void Heavy_CircleStrings::cUnop_EpHDWzxq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_ow1xervc_sendMessage);
}

void Heavy_CircleStrings::cRandom_GRKCbLCV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_IIySvyEu_sendMessage);
}

void Heavy_CircleStrings::cBinop_IIySvyEu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_EpHDWzxq_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_STDyVeGJ_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_Tm5B3KTB, 0, m, &cSlice_Tm5B3KTB_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_GRKCbLCV, 0, m, &cRandom_GRKCbLCV_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cSlice_Tm5B3KTB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_GRKCbLCV, 1, m, &cRandom_GRKCbLCV_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_vCO0xInk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_beofWh8Q_sendMessage(_c, 0, m);
  cSend_5NvOYSa0_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_wGBpLuCv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MeAy33Eq, HV_BINOP_MULTIPLY, 1, m, &cBinop_MeAy33Eq_sendMessage);
}

void Heavy_CircleStrings::cVar_EiQTMZfM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_1JMoGwnu, 0, m);
}

void Heavy_CircleStrings::cSlice_dst35s5q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 127.0f, 0, m, &cBinop_vCO0xInk_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cSlice_eA6s9mwy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_h72IJPvd_sendMessage);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_iitru23p_sendMessage);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_Q1F0td1q_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_IDFC5Zjl_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_2d6WwaW4_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cUnop_4jQgGCFm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_8ny13VLl_sendMessage);
}

void Heavy_CircleStrings::cSlice_5zJYFlMM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_BilP4Qzp, 1, m, &cRandom_BilP4Qzp_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_9XMqheb4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_4jQgGCFm_sendMessage);
}

void Heavy_CircleStrings::cRandom_BilP4Qzp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 15.0f, 0, m, &cBinop_9XMqheb4_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_PiOKx4mX_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_5zJYFlMM, 0, m, &cSlice_5zJYFlMM_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_BilP4Qzp, 0, m, &cRandom_BilP4Qzp_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cPack_z8IefsVX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_8g7E35J1, 0, m, NULL);
}

void Heavy_CircleStrings::cCast_4eqw9mjd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_Y5RI0Hxf_sendMessage);
}

void Heavy_CircleStrings::cBinop_GRbPnKFf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_OpNfVZha_sendMessage);
}

void Heavy_CircleStrings::cCast_J9snrAaQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_mJ4uoAG3, 0, m, &cIf_mJ4uoAG3_sendMessage);
}

void Heavy_CircleStrings::cMsg_KMPOYpJ7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cMsg_99XjTham_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_8oPoycfA_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_b6xvQooS_sendMessage);
}

void Heavy_CircleStrings::cBinop_OpNfVZha_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_99XjTham_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_8oPoycfA_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_b6xvQooS_sendMessage);
}

void Heavy_CircleStrings::cBinop_Y5RI0Hxf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_mJ4uoAG3, 1, m, &cIf_mJ4uoAG3_sendMessage);
}

void Heavy_CircleStrings::cIf_mJ4uoAG3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_KMPOYpJ7_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_LOG10, m, &cUnop_yeWF24VB_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_oDKsnQmL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 100.0f, 0, m, &cBinop_GRbPnKFf_sendMessage);
}

void Heavy_CircleStrings::cUnop_yeWF24VB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_oDKsnQmL_sendMessage);
}

void Heavy_CircleStrings::cBinop_eGIgT6XA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_p9R4vfAY_sendMessage);
}

void Heavy_CircleStrings::cBinop_p9R4vfAY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_4eqw9mjd_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_J9snrAaQ_sendMessage);
}

void Heavy_CircleStrings::cReceive_leJv0l1q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_8oPoycfA_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_b6xvQooS_sendMessage);
}

void Heavy_CircleStrings::cReceive_mMi3D1gg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_R43hpoGw, 0, m, &cVar_R43hpoGw_sendMessage);
}

void Heavy_CircleStrings::cReceive_mPRPHvhT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_xN9sRxKx_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_TkiVwixQ_sendMessage);
}

void Heavy_CircleStrings::cReceive_mQWbbmW2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 2.0f, 0, m, &cBinop_eGIgT6XA_sendMessage);
}

void Heavy_CircleStrings::cReceive_mcCQqEOf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ggHtLBX3, 1, m, &cVar_ggHtLBX3_sendMessage);
}

void Heavy_CircleStrings::cReceive_n50No16t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_P9rxUXcZ_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_TbXZlErM, 0, m, &cIf_TbXZlErM_sendMessage);
}

void Heavy_CircleStrings::cIf_j108jHSS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_0fPpwafF, 0, m, &cSlice_0fPpwafF_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_br9NnjpD, 0, m, &cSlice_br9NnjpD_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_jC4Mczgd, 0, m, &cIf_jC4Mczgd_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_5HY5fLM2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_qyTvtMHX, 1, m, &cVar_qyTvtMHX_sendMessage);
}

void Heavy_CircleStrings::cVar_qyTvtMHX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_5HY5fLM2_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_j108jHSS, 1, m, &cIf_j108jHSS_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_3ZOWsDhU_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_HDL3ryem_sendMessage);
      break;
    }
    default: {
      cMsg_z6iEtg1P_sendMessage(_c, 0, m);
      break;
    }
  }
}

void Heavy_CircleStrings::cCast_HDL3ryem_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_me6GXtaS_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_me6GXtaS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_qyTvtMHX, 0, m, &cVar_qyTvtMHX_sendMessage);
}

void Heavy_CircleStrings::cMsg_z6iEtg1P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_qyTvtMHX, 0, m, &cVar_qyTvtMHX_sendMessage);
}

void Heavy_CircleStrings::cPack_1115YzV3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_OZKxp9pw_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cCast_2Rgd81on_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_HVo32Nnw, 0, m, &cVar_HVo32Nnw_sendMessage);
}

void Heavy_CircleStrings::cCast_5hQZcw1R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_1115YzV3, 1, m, &cPack_1115YzV3_sendMessage);
}

void Heavy_CircleStrings::cPack_ActXizl2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_j108jHSS, 0, m, &cIf_j108jHSS_sendMessage);
}

void Heavy_CircleStrings::cSlice_41RaPf9H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_dst35s5q, 0, m, &cSlice_dst35s5q_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_eA6s9mwy, 0, m, &cSlice_eA6s9mwy_sendMessage);
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_dst35s5q, 0, m, &cSlice_dst35s5q_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_eA6s9mwy, 0, m, &cSlice_eA6s9mwy_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cSlice_5f3FvQpl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_8XV4gloF, 0, m, &cSlice_8XV4gloF_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_z9CKtwAU, 0, m, &cSlice_z9CKtwAU_sendMessage);
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_8XV4gloF, 0, m, &cSlice_8XV4gloF_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_z9CKtwAU, 0, m, &cSlice_z9CKtwAU_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cSwitchcase_OZKxp9pw_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_tx2TCvlM, 0, m, &cSlice_tx2TCvlM_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_5f3FvQpl, 0, m, &cSlice_5f3FvQpl_sendMessage);
      break;
    }
    case 0x40000000: { // "2.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_q6o7mfie, 0, m, &cSlice_q6o7mfie_sendMessage);
      break;
    }
    case 0x40400000: { // "3.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_41RaPf9H, 0, m, &cSlice_41RaPf9H_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cSlice_q6o7mfie_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_8cIgAeXS, 0, m, &cSlice_8cIgAeXS_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_AwbkDAjm, 0, m, &cSlice_AwbkDAjm_sendMessage);
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_8cIgAeXS, 0, m, &cSlice_8cIgAeXS_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_AwbkDAjm, 0, m, &cSlice_AwbkDAjm_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cSlice_tx2TCvlM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_XtCCIMgJ, 0, m, &cSlice_XtCCIMgJ_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_DUE60xXY, 0, m, &cSlice_DUE60xXY_sendMessage);
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_XtCCIMgJ, 0, m, &cSlice_XtCCIMgJ_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_DUE60xXY, 0, m, &cSlice_DUE60xXY_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cVar_HVo32Nnw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_1115YzV3, 0, m, &cPack_1115YzV3_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_zfd68FNh_sendMessage);
}

void Heavy_CircleStrings::cBinop_ZDc3behT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_HVo32Nnw, 1, m, &cVar_HVo32Nnw_sendMessage);
}

void Heavy_CircleStrings::cMsg_bcGB1aGC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_3ZOWsDhU_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cCast_2ZtI90gj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_FeOwgZiZ_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cIf_gfUkXK8K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_5hQZcw1R_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_2Rgd81on_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cIf_EvXCM6O2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_lJwNwUiB, 0, m, &cSlice_lJwNwUiB_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_QbXbPL6l, 0, m, &cSlice_QbXbPL6l_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cCast_CBb8Fg3s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_NEQ, 0.0f, 0, m, &cBinop_irxajxsH_sendMessage);
}

void Heavy_CircleStrings::cMsg_FeOwgZiZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_FpzUiI39, 1, m, &cVar_FpzUiI39_sendMessage);
}

void Heavy_CircleStrings::cIf_jEWICWZ8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cPack_onMessage(_c, &Context(_c)->cPack_1115YzV3, 2, m, &cPack_1115YzV3_sendMessage);
      cPack_onMessage(_c, &Context(_c)->cPack_u5imjPEP, 1, m, &cPack_u5imjPEP_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cCast_KvHwX2xN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_jEWICWZ8, 0, m, &cIf_jEWICWZ8_sendMessage);
}

void Heavy_CircleStrings::cVar_FpzUiI39_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_jC4Mczgd, 1, m, &cIf_jC4Mczgd_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_nsXxDOTw_sendMessage);
}

void Heavy_CircleStrings::cCast_aEZ3Zkri_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_u5imjPEP, 0, m, &cPack_u5imjPEP_sendMessage);
}

void Heavy_CircleStrings::cSlice_QbXbPL6l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cIf_onMessage(_c, &Context(_c)->cIf_gfUkXK8K, 0, m, &cIf_gfUkXK8K_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cSlice_lJwNwUiB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_CBb8Fg3s_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_KvHwX2xN_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cMsg_fKOUPBDH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_FpzUiI39, 1, m, &cVar_FpzUiI39_sendMessage);
}

void Heavy_CircleStrings::cBinop_irxajxsH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_gfUkXK8K, 1, m, &cIf_gfUkXK8K_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_jEWICWZ8, 1, m, &cIf_jEWICWZ8_sendMessage);
}

void Heavy_CircleStrings::cBinop_nsXxDOTw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_EvXCM6O2, 1, m, &cIf_EvXCM6O2_sendMessage);
}

void Heavy_CircleStrings::cCast_rRS6P44Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_FpzUiI39, 0, m, &cVar_FpzUiI39_sendMessage);
}

void Heavy_CircleStrings::cPack_u5imjPEP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_EvXCM6O2, 0, m, &cIf_EvXCM6O2_sendMessage);
}

void Heavy_CircleStrings::cSlice_0fPpwafF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_fKOUPBDH_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cSlice_br9NnjpD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_rRS6P44Y_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_aEZ3Zkri_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_2ZtI90gj_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cIf_jC4Mczgd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_lJwNwUiB, 0, m, &cSlice_lJwNwUiB_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_QbXbPL6l, 0, m, &cSlice_QbXbPL6l_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_zfd68FNh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MOD_BIPOLAR, 4.0f, 0, m, &cBinop_ZDc3behT_sendMessage);
}

void Heavy_CircleStrings::cMsg_0va9TJKo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.15f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_nzGgo9XU_sendMessage);
}

void Heavy_CircleStrings::cCast_2IQ4pNcG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_t8LOSXak_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cSlice_ELhLweBN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_QG8NKBLQ, 1, m, &cRandom_QG8NKBLQ_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cRandom_QG8NKBLQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 200.0f, 0, m, &cBinop_fhyD7HNc_sendMessage);
}

void Heavy_CircleStrings::cUnop_aAJKAjk9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_NtnZNmNh, 0, m, &cPack_NtnZNmNh_sendMessage);
}

void Heavy_CircleStrings::cBinop_fhyD7HNc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_aAJKAjk9_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_pwjST8Iy_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_ELhLweBN, 0, m, &cSlice_ELhLweBN_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_QG8NKBLQ, 0, m, &cRandom_QG8NKBLQ_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cPack_Dmc8PtT0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_9rKLAeez_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cBinop_LZqhwFC8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_Dmc8PtT0, 0, m, &cPack_Dmc8PtT0_sendMessage);
}

void Heavy_CircleStrings::cPack_NtnZNmNh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_UigTb4y6_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cCast_19MtzG5q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Eut0jGmw_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_jrZYpSjt, HV_BINOP_ADD, 0, m, &cBinop_jrZYpSjt_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_MHDSXfwo, 1, m, &cVar_MHDSXfwo_sendMessage);
}

void Heavy_CircleStrings::cBinop_3gKYUMQj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_NZUTOy0x_sendMessage);
}

void Heavy_CircleStrings::cVar_MHDSXfwo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_zFNBDphz, HV_BINOP_ADD, 0, m, &cBinop_zFNBDphz_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_jrZYpSjt, HV_BINOP_ADD, 0, m, &cBinop_jrZYpSjt_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_JwBexB85, 0, m, &cVar_JwBexB85_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_N3IEEdKO, m);
}

void Heavy_CircleStrings::cCast_64NZTOML_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_aHM5gk3P, 1, m, &cVar_aHM5gk3P_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_AZbLhYIe_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cMsg_PES1jBNz_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_PES1jBNz_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_axnJFXHD_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_CAD8cIyT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_fcdgcocD, 2, m, &cDelay_fcdgcocD_sendMessage);
}

void Heavy_CircleStrings::cBinop_GIAYxKKz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_CAD8cIyT_sendMessage);
}

void Heavy_CircleStrings::cCast_axnJFXHD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_PES1jBNz_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_fcdgcocD, 0, m, &cDelay_fcdgcocD_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_76coh6S2, 0, m, &cVar_76coh6S2_sendMessage);
}

void Heavy_CircleStrings::cMsg_PES1jBNz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_fcdgcocD, 0, m, &cDelay_fcdgcocD_sendMessage);
}

void Heavy_CircleStrings::cBinop_ZiEnNeAD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_GIAYxKKz, HV_BINOP_MULTIPLY, 1, m, &cBinop_GIAYxKKz_sendMessage);
}

void Heavy_CircleStrings::cDelay_fcdgcocD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_fcdgcocD, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_fcdgcocD, 0, m, &cDelay_fcdgcocD_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_76coh6S2, 0, m, &cVar_76coh6S2_sendMessage);
}

void Heavy_CircleStrings::cVar_HAXQFBT5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_GIAYxKKz, HV_BINOP_MULTIPLY, 0, m, &cBinop_GIAYxKKz_sendMessage);
}

void Heavy_CircleStrings::cMsg_5YNTznFC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_chfYwyVx_sendMessage);
}

void Heavy_CircleStrings::cSystem_chfYwyVx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_ZiEnNeAD_sendMessage);
}

void Heavy_CircleStrings::cBinop_7lfxwfbV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_fDYrPmO6, HV_BINOP_DIVIDE, 1, m, &cBinop_fDYrPmO6_sendMessage);
}

void Heavy_CircleStrings::cCast_ALe7ZojB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Z2DLbpH9_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_UigTb4y6_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cSlice_onMessage(_c, &Context(_c)->cSlice_cv3N4r9v, 0, m, &cSlice_cv3N4r9v_sendMessage);
      break;
    }
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_znm6BWKu, 0, m, &cSlice_znm6BWKu_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_OVJZFiO2_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_RnWaeGkw, 0, m, &cSlice_RnWaeGkw_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_ku6PHOvt, 0, m, &cSlice_ku6PHOvt_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_QrLiEZcZ_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_DfufxNZa_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cSlice_cv3N4r9v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_mPrT36qF_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_mPrT36qF_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cSlice_znm6BWKu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_nivVNDEV_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_19MtzG5q_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_nivVNDEV_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_19MtzG5q_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cVar_76coh6S2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_b9sOQFW1, HV_BINOP_SUBTRACT, 0, m, &cBinop_b9sOQFW1_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_LESS_THAN_EQL, 0.0f, 0, m, &cBinop_FkF7X4OI_sendMessage);
}

void Heavy_CircleStrings::cMsg_C1fMbftk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 20.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_rFv6MvVK, HV_BINOP_MULTIPLY, 0, m, &cBinop_rFv6MvVK_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_7lfxwfbV, HV_BINOP_DIVIDE, 1, m, &cBinop_7lfxwfbV_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_HAXQFBT5, 0, m, &cVar_HAXQFBT5_sendMessage);
}

void Heavy_CircleStrings::cCast_DfufxNZa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_p5MKmmfg_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_Eut0jGmw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Z2DLbpH9_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_FkF7X4OI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_WCF3NmtJ_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cVar_eP92M7yI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_jfIzGcEn, HV_BINOP_SUBTRACT, 1, m, &cBinop_jfIzGcEn_sendMessage);
}

void Heavy_CircleStrings::cCast_LZbQkNxW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_aHM5gk3P, 0, m, &cVar_aHM5gk3P_sendMessage);
}

void Heavy_CircleStrings::cBinop_LieiCtL9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_b9sOQFW1, HV_BINOP_SUBTRACT, 1, m, &cBinop_b9sOQFW1_sendMessage);
}

void Heavy_CircleStrings::cBinop_NZUTOy0x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_76coh6S2, 1, m, &cVar_76coh6S2_sendMessage);
}

void Heavy_CircleStrings::cCast_OVJZFiO2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ldkkKk4Z, 0, m, &cVar_ldkkKk4Z_sendMessage);
}

void Heavy_CircleStrings::cCast_QrLiEZcZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_wQmW9iku_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_ArNlzdTb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ALe7ZojB_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_LZbQkNxW_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_WCF3NmtJ_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_lrhBwL4E_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ArNlzdTb_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cCast_lrhBwL4E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_MHDSXfwo, 0, m, &cVar_MHDSXfwo_sendMessage);
}

void Heavy_CircleStrings::cMsg_Z2DLbpH9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_AZbLhYIe_onMessage(_c, NULL, 0, m, NULL);
  cBinop_onMessage(_c, &Context(_c)->cBinop_jrZYpSjt, HV_BINOP_ADD, 1, m, &cBinop_jrZYpSjt_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_zFNBDphz, HV_BINOP_ADD, 1, m, &cBinop_zFNBDphz_sendMessage);
}

void Heavy_CircleStrings::cCast_armelQe2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_jfIzGcEn, HV_BINOP_SUBTRACT, 0, m, &cBinop_jfIzGcEn_sendMessage);
}

void Heavy_CircleStrings::cBinop_b9sOQFW1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_76coh6S2, 1, m, &cVar_76coh6S2_sendMessage);
}

void Heavy_CircleStrings::cBinop_fDYrPmO6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_jrZYpSjt, HV_BINOP_ADD, 1, m, &cBinop_jrZYpSjt_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_zFNBDphz, HV_BINOP_ADD, 1, m, &cBinop_zFNBDphz_sendMessage);
}

void Heavy_CircleStrings::cMsg_YgNzMhZe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_tbpIIGhY_sendMessage);
}

void Heavy_CircleStrings::cSystem_tbpIIGhY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_rFv6MvVK, HV_BINOP_MULTIPLY, 1, m, &cBinop_rFv6MvVK_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_3gKYUMQj, HV_BINOP_MULTIPLY, 1, m, &cBinop_3gKYUMQj_sendMessage);
}

void Heavy_CircleStrings::cBinop_jfIzGcEn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_fDYrPmO6, HV_BINOP_DIVIDE, 0, m, &cBinop_fDYrPmO6_sendMessage);
}

void Heavy_CircleStrings::cBinop_jrZYpSjt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_eP92M7yI, 0, m, &cVar_eP92M7yI_sendMessage);
}

void Heavy_CircleStrings::cVar_aHM5gk3P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_MHDSXfwo, 0, m, &cVar_MHDSXfwo_sendMessage);
}

void Heavy_CircleStrings::cMsg_mPrT36qF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_AZbLhYIe_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cCast_nivVNDEV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_mPrT36qF_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_p5MKmmfg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_ldkkKk4Z, 1, m, &cVar_ldkkKk4Z_sendMessage);
}

void Heavy_CircleStrings::cVar_ldkkKk4Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_sSG2sUZE_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_qMNGaEC0_sendMessage);
}

void Heavy_CircleStrings::cCast_qMNGaEC0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_7lfxwfbV, HV_BINOP_DIVIDE, 0, m, &cBinop_7lfxwfbV_sendMessage);
}

void Heavy_CircleStrings::cBinop_rFv6MvVK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_LieiCtL9_sendMessage);
}

void Heavy_CircleStrings::cCast_sSG2sUZE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_3gKYUMQj, HV_BINOP_MULTIPLY, 0, m, &cBinop_3gKYUMQj_sendMessage);
}

void Heavy_CircleStrings::cSlice_RnWaeGkw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_sSG2sUZE_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_qMNGaEC0_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cSlice_ku6PHOvt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_64NZTOML_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_armelQe2_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cCast_kzeQGEWX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_C1fMbftk_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_rYsjrFF2_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_kzeQGEWX_sendMessage);
      break;
    }
    default: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_rFv6MvVK, HV_BINOP_MULTIPLY, 0, m, &cBinop_rFv6MvVK_sendMessage);
      cBinop_onMessage(_c, &Context(_c)->cBinop_7lfxwfbV, HV_BINOP_DIVIDE, 1, m, &cBinop_7lfxwfbV_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_HAXQFBT5, 0, m, &cVar_HAXQFBT5_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cMsg_wQmW9iku_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_AZbLhYIe_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cVar_J3MpXBud_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_rYsjrFF2_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cBinop_zFNBDphz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_MHDSXfwo, 1, m, &cVar_MHDSXfwo_sendMessage);
}

void Heavy_CircleStrings::cBinop_2p8eiQpT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_CiXymxDq, 0, m, &cPack_CiXymxDq_sendMessage);
}

void Heavy_CircleStrings::cVar_cSpdssHy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_psdgXSjI_sendMessage);
}

void Heavy_CircleStrings::cBinop_6l8gQ9R0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_Q4k2LpRl_sendMessage);
}

void Heavy_CircleStrings::cPack_BeuYz5E4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_sTc6BqLx, 0, m, NULL);
}

void Heavy_CircleStrings::cBinop_BuZxgp01_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_kg5dYE5P_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ygaebOYh_sendMessage);
}

void Heavy_CircleStrings::cPack_CiXymxDq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_qcUSrU6Z, 0, m, NULL);
}

void Heavy_CircleStrings::cCast_43GFVIez_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Zsz4O5GY, 0, m, &cDelay_Zsz4O5GY_sendMessage);
}

void Heavy_CircleStrings::cBinop_8FJwXGk8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_THE8zvck_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_AqjRr9T6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_h8DevU5Z_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Zsz4O5GY, 2, m, &cDelay_Zsz4O5GY_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_43GFVIez_sendMessage);
}

void Heavy_CircleStrings::cMsg_D9snJVWn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_NSHiTy1f_sendMessage);
}

void Heavy_CircleStrings::cSystem_NSHiTy1f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_zgd5MBmG_sendMessage);
}

void Heavy_CircleStrings::cDelay_R7yBtNwC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_R7yBtNwC, m);
  cMsg_xwOoW7j6_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_THE8zvck_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_AqjRr9T6, 0, m, &hTable_AqjRr9T6_sendMessage);
}

void Heavy_CircleStrings::cDelay_Zsz4O5GY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Zsz4O5GY, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_R7yBtNwC, 0, m, &cDelay_R7yBtNwC_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Zsz4O5GY, 0, m, &cDelay_Zsz4O5GY_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_3GxKA1rk, 1, m, NULL);
}

void Heavy_CircleStrings::cMsg_h8DevU5Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_R7yBtNwC, 2, m, &cDelay_R7yBtNwC_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_qmgdAHw2_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_zcTavk16_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cMsg_xwOoW7j6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_AqjRr9T6, 0, m, &hTable_AqjRr9T6_sendMessage);
}

void Heavy_CircleStrings::cMsg_zcTavk16_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_3GxKA1rk, 1, m, NULL);
}

void Heavy_CircleStrings::cBinop_zgd5MBmG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 5000.0f, 0, m, &cBinop_8FJwXGk8_sendMessage);
}

void Heavy_CircleStrings::cBinop_407qBpLq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_EXP, m, &cUnop_GPZEpgmW_sendMessage);
}

void Heavy_CircleStrings::cUnop_GPZEpgmW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_6l8gQ9R0_sendMessage);
}

void Heavy_CircleStrings::cMsg_KmtnFRlu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.5f);
  cVar_onMessage(_c, &Context(_c)->cVar_Yuro5TVF, 0, m, &cVar_Yuro5TVF_sendMessage);
}

void Heavy_CircleStrings::cBinop_Q4k2LpRl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_QbyCwXpt, HV_BINOP_DIVIDE, 0, m, &cBinop_QbyCwXpt_sendMessage);
}

void Heavy_CircleStrings::cBinop_QbyCwXpt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_WV8A1mpm_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_WV8A1mpm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 30.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_fAgNk4J8, 0, m, NULL);
}

void Heavy_CircleStrings::cBinop_ZXlbpmAy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 87.3365f, 0, m, &cBinop_407qBpLq_sendMessage);
}

void Heavy_CircleStrings::cMsg_iKxiqkmm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 100.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_cSpdssHy, 0, m, &cVar_cSpdssHy_sendMessage);
}

void Heavy_CircleStrings::cSystem_Ohb4dxFX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_ZEQhUT0Z_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_spQtVZmT, m);
}

void Heavy_CircleStrings::cBinop_Qtn5eL32_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_ck3bw49y, m);
}

void Heavy_CircleStrings::cBinop_ZEQhUT0Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_JjPn5IOz, m);
}

void Heavy_CircleStrings::cSystem_7pzPBn0U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_Qtn5eL32_sendMessage);
}

void Heavy_CircleStrings::cMsg_Zf8XIbKC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_7pzPBn0U_sendMessage);
}

void Heavy_CircleStrings::cMsg_hqgUmkVo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Ohb4dxFX_sendMessage);
}

void Heavy_CircleStrings::cVar_rojQnTDl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_hqgUmkVo_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_kg5dYE5P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_QbyCwXpt, HV_BINOP_DIVIDE, 1, m, &cBinop_QbyCwXpt_sendMessage);
}

void Heavy_CircleStrings::cBinop_8kC8iy6a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_dpHMaRhP, m);
}

void Heavy_CircleStrings::cSystem_A7mX1ZgR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_GdTvmoLO_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_W11bjtXS, m);
}

void Heavy_CircleStrings::cVar_vt9w4O4j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_vTJ3WHEo_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_pbzo3fNU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_wbvrvopX_sendMessage);
}

void Heavy_CircleStrings::cSystem_wbvrvopX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_8kC8iy6a_sendMessage);
}

void Heavy_CircleStrings::cBinop_GdTvmoLO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_dkYaFM5l, m);
}

void Heavy_CircleStrings::cMsg_vTJ3WHEo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_A7mX1ZgR_sendMessage);
}

void Heavy_CircleStrings::cBinop_psdgXSjI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.001f, 0, m, &cBinop_BuZxgp01_sendMessage);
  cPack_onMessage(_c, &Context(_c)->cPack_BeuYz5E4, 0, m, &cPack_BeuYz5E4_sendMessage);
}

void Heavy_CircleStrings::cVar_Yuro5TVF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.5f, 0, m, &cBinop_2p8eiQpT_sendMessage);
}

void Heavy_CircleStrings::cCast_ygaebOYh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_QbyCwXpt, HV_BINOP_DIVIDE, 0, m, &cBinop_QbyCwXpt_sendMessage);
}

void Heavy_CircleStrings::cBinop_4R64yKcd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_RQZ3wiSK, m);
}

void Heavy_CircleStrings::cBinop_8GoZ6z8r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_dxrFx7YW_sendMessage);
}

void Heavy_CircleStrings::cBinop_9zHwUC2m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_X201DATz, HV_BINOP_DIVIDE, 0, m, &cBinop_X201DATz_sendMessage);
}

void Heavy_CircleStrings::cBinop_NFeWEHoB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_Pv7G27AF_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_4R64yKcd_sendMessage);
}

void Heavy_CircleStrings::cBinop_dxrFx7YW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_NFeWEHoB_sendMessage);
}

void Heavy_CircleStrings::cBinop_Pv7G27AF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_k1SKX6aO_sendMessage);
}

void Heavy_CircleStrings::cBinop_X201DATz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_q5CxM0qO_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_k1SKX6aO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_NSwYS34I, m);
}

void Heavy_CircleStrings::cVar_1NcaJMVb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_v2VMq5Sg_sendMessage);
}

void Heavy_CircleStrings::cMsg_q5CxM0qO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_8GoZ6z8r_sendMessage);
}

void Heavy_CircleStrings::cBinop_v2VMq5Sg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_9zHwUC2m_sendMessage);
}

void Heavy_CircleStrings::cSystem_fO7cTKzD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_X201DATz, HV_BINOP_DIVIDE, 1, m, &cBinop_X201DATz_sendMessage);
}

void Heavy_CircleStrings::cMsg_hkzAoPV4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_fO7cTKzD_sendMessage);
}

void Heavy_CircleStrings::cMsg_4SGU8R8p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_JrchviHR, 0, m, &hTable_JrchviHR_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_5ZS2JAh9_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_paBinoEr_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_9YTau6XD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 200.0f, 0, m, &cBinop_gaisByIG_sendMessage);
}

void Heavy_CircleStrings::cCast_AOSLM6jA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_gvmCffhO, 0, m, &cDelay_gvmCffhO_sendMessage);
}

void Heavy_CircleStrings::cMsg_BESXMmVO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_nB1GMieL, 2, m, &cDelay_nB1GMieL_sendMessage);
}

void Heavy_CircleStrings::hTable_JrchviHR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_BESXMmVO_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_gvmCffhO, 2, m, &cDelay_gvmCffhO_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_AOSLM6jA_sendMessage);
}

void Heavy_CircleStrings::cSystem_1EKsOIxg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_9YTau6XD_sendMessage);
}

void Heavy_CircleStrings::cMsg_sKGp46Oq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_1EKsOIxg_sendMessage);
}

void Heavy_CircleStrings::cBinop_gaisByIG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_4SGU8R8p_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_gvmCffhO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_gvmCffhO, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_nB1GMieL, 0, m, &cDelay_nB1GMieL_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_gvmCffhO, 0, m, &cDelay_gvmCffhO_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_KGSvr8CU, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_nB1GMieL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_nB1GMieL, m);
  cMsg_nJ0ljWw2_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_nJ0ljWw2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_JrchviHR, 0, m, &hTable_JrchviHR_sendMessage);
}

void Heavy_CircleStrings::cMsg_paBinoEr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_KGSvr8CU, 1, m, NULL);
}

void Heavy_CircleStrings::cBinop_Fajl8BNj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_CSoM9oba, m);
}

void Heavy_CircleStrings::cBinop_nzGgo9XU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, -1.0f, 0, m, &cBinop_Fajl8BNj_sendMessage);
}

void Heavy_CircleStrings::cMsg_CWVyibBw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 20.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_Ym6UThys, 0, m, NULL);
}

void Heavy_CircleStrings::cMsg_HDbXQ0jY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cMsg_CWVyibBw_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_CzleO8Qy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ivbpaBxS_sendMessage);
}

void Heavy_CircleStrings::cVar_5dA5ApPk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_CzleO8Qy_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSystem_ivbpaBxS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_x1HTqWzf_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_bIrObFVg, m);
}

void Heavy_CircleStrings::cMsg_blJZpUyG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_uD3XkntM_sendMessage);
}

void Heavy_CircleStrings::cSystem_uD3XkntM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_xxk6bUbD_sendMessage);
}

void Heavy_CircleStrings::cBinop_x1HTqWzf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_c4leJELR, m);
}

void Heavy_CircleStrings::cBinop_xxk6bUbD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_wg5Ri9dn, m);
}

void Heavy_CircleStrings::cVar_7bCdvUh8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_1eZbcsbi, HV_BINOP_MULTIPLY, 0, m, &cBinop_1eZbcsbi_sendMessage);
}

void Heavy_CircleStrings::cBinop_HptlCMEL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_2VhQ4WkQ, m);
}

void Heavy_CircleStrings::cBinop_pB8V7HyR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_v150O8Xv_sendMessage);
}

void Heavy_CircleStrings::cBinop_v150O8Xv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_HptlCMEL_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_icAuhuKv, m);
}

void Heavy_CircleStrings::cBinop_1eZbcsbi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_pB8V7HyR_sendMessage);
}

void Heavy_CircleStrings::cMsg_3NtscPYZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_hVcQMAdy_sendMessage);
}

void Heavy_CircleStrings::cMsg_3WLu8nqg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_BRYOudv7_sendMessage);
}

void Heavy_CircleStrings::cSystem_BRYOudv7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_3NtscPYZ_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_hVcQMAdy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_1eZbcsbi, HV_BINOP_MULTIPLY, 1, m, &cBinop_1eZbcsbi_sendMessage);
}

void Heavy_CircleStrings::cVar_Z9aUjTyP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_CWVyibBw_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSlice_GzHvjv97_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_fKzgxDLi, 1, m, &cRandom_fKzgxDLi_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cUnop_HoqWlP8S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 10.0f, 0, m, &cBinop_wgg8oiEx_sendMessage);
}

void Heavy_CircleStrings::cRandom_fKzgxDLi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 80.0f, 0, m, &cBinop_gMStXXzI_sendMessage);
}

void Heavy_CircleStrings::cBinop_gMStXXzI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_HoqWlP8S_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_t8LOSXak_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_GzHvjv97, 0, m, &cSlice_GzHvjv97_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_fKzgxDLi, 0, m, &cRandom_fKzgxDLi_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cVar_JwBexB85_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cBinop_4XcB2edl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Yi2fYugt, 1, m, &cVar_Yi2fYugt_sendMessage);
}

void Heavy_CircleStrings::cBinop_5fi3gNGf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_Ffz6FoaU_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cBinop_6ZJMZDJW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_q8k15fnK_sendMessage);
}

void Heavy_CircleStrings::cBinop_8XHN97hN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_fTIETjRa_sendMessage);
}

void Heavy_CircleStrings::cCast_8z62mpxw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_zd3dRFfn_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_ZhjAi2ej, HV_BINOP_ADD, 0, m, &cBinop_ZhjAi2ej_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_VBDFD3YF, 1, m, &cVar_VBDFD3YF_sendMessage);
}

void Heavy_CircleStrings::cCast_93TfI35w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_62CevhwS, 1, m, &cVar_62CevhwS_sendMessage);
}

void Heavy_CircleStrings::cCast_gIMeKO4M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_DcwzACOW_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_yHBH9t7p_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_gIMeKO4M_sendMessage);
      break;
    }
    default: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_6ZJMZDJW, HV_BINOP_MULTIPLY, 0, m, &cBinop_6ZJMZDJW_sendMessage);
      cBinop_onMessage(_c, &Context(_c)->cBinop_QZpIx2bq, HV_BINOP_DIVIDE, 1, m, &cBinop_QZpIx2bq_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_gnDhbVDa, 0, m, &cVar_gnDhbVDa_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cMsg_A2HeDVbs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_6rLWcSea, 1, m, &cVar_6rLWcSea_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_9rKLAeez_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cSlice_onMessage(_c, &Context(_c)->cSlice_t8WTNE9t, 0, m, &cSlice_t8WTNE9t_sendMessage);
      break;
    }
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_DirdSHXo, 0, m, &cSlice_DirdSHXo_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_gs8ZreSM_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_1Py2yTMC, 0, m, &cSlice_1Py2yTMC_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_NJ9KnpUt, 0, m, &cSlice_NJ9KnpUt_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_l2En9LsM_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_xdr0FEFS_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cSlice_DirdSHXo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_UWvx9csx_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_8z62mpxw_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_UWvx9csx_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_8z62mpxw_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cSlice_t8WTNE9t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_DGYEBDpK_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_DGYEBDpK_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cCast_CG0wZFS4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_62CevhwS, 0, m, &cVar_62CevhwS_sendMessage);
}

void Heavy_CircleStrings::cMsg_DGYEBDpK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_tJi19fBP_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cMsg_DcwzACOW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 20.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_6ZJMZDJW, HV_BINOP_MULTIPLY, 0, m, &cBinop_6ZJMZDJW_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_QZpIx2bq, HV_BINOP_DIVIDE, 1, m, &cBinop_QZpIx2bq_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_gnDhbVDa, 0, m, &cVar_gnDhbVDa_sendMessage);
}

void Heavy_CircleStrings::cVar_238LxNEE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_yHBH9t7p_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cMsg_FLOpf3IZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_tJi19fBP_onMessage(_c, NULL, 0, m, NULL);
  cBinop_onMessage(_c, &Context(_c)->cBinop_ZhjAi2ej, HV_BINOP_ADD, 1, m, &cBinop_ZhjAi2ej_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_aXleD2RC, HV_BINOP_ADD, 1, m, &cBinop_aXleD2RC_sendMessage);
}

void Heavy_CircleStrings::cCast_IBWKmbCT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_k8AwyJ1I, HV_BINOP_SUBTRACT, 0, m, &cBinop_k8AwyJ1I_sendMessage);
}

void Heavy_CircleStrings::cCast_30MPfuEc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_fEqdfucC_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_CG0wZFS4_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_Ffz6FoaU_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_xZ2WvPm3_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_30MPfuEc_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cCast_xZ2WvPm3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_VBDFD3YF, 0, m, &cVar_VBDFD3YF_sendMessage);
}

void Heavy_CircleStrings::cVar_Yi2fYugt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4XcB2edl, HV_BINOP_SUBTRACT, 0, m, &cBinop_4XcB2edl_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_LESS_THAN_EQL, 0.0f, 0, m, &cBinop_5fi3gNGf_sendMessage);
}

void Heavy_CircleStrings::cVar_6rLWcSea_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_UvVdZMhk_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Ll9GNorC_sendMessage);
}

void Heavy_CircleStrings::cCast_Ll9GNorC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_QZpIx2bq, HV_BINOP_DIVIDE, 0, m, &cBinop_QZpIx2bq_sendMessage);
}

void Heavy_CircleStrings::cBinop_QZpIx2bq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ZjcSTAe1, HV_BINOP_DIVIDE, 1, m, &cBinop_ZjcSTAe1_sendMessage);
}

void Heavy_CircleStrings::cVar_62CevhwS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_VBDFD3YF, 0, m, &cVar_VBDFD3YF_sendMessage);
}

void Heavy_CircleStrings::cCast_UWvx9csx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_DGYEBDpK_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_UvVdZMhk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_8XHN97hN, HV_BINOP_MULTIPLY, 0, m, &cBinop_8XHN97hN_sendMessage);
}

void Heavy_CircleStrings::cBinop_ZhjAi2ej_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Yh1dqw45, 0, m, &cVar_Yh1dqw45_sendMessage);
}

void Heavy_CircleStrings::cBinop_ZjcSTAe1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ZhjAi2ej, HV_BINOP_ADD, 1, m, &cBinop_ZhjAi2ej_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_aXleD2RC, HV_BINOP_ADD, 1, m, &cBinop_aXleD2RC_sendMessage);
}

void Heavy_CircleStrings::cVar_VBDFD3YF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_aXleD2RC, HV_BINOP_ADD, 0, m, &cBinop_aXleD2RC_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_ZhjAi2ej, HV_BINOP_ADD, 0, m, &cBinop_ZhjAi2ej_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_RQwqhkkt, 0, m, &cVar_RQwqhkkt_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.05776f, 0, m, &cBinop_ZXlbpmAy_sendMessage);
}

void Heavy_CircleStrings::cSystem_Uw7s1faH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6ZJMZDJW, HV_BINOP_MULTIPLY, 1, m, &cBinop_6ZJMZDJW_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_8XHN97hN, HV_BINOP_MULTIPLY, 1, m, &cBinop_8XHN97hN_sendMessage);
}

void Heavy_CircleStrings::cMsg_qe3nonpr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Uw7s1faH_sendMessage);
}

void Heavy_CircleStrings::cBinop_aXleD2RC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_VBDFD3YF, 1, m, &cVar_VBDFD3YF_sendMessage);
}

void Heavy_CircleStrings::cMsg_btcvyUQn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_tJi19fBP_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cCast_fEqdfucC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_FLOpf3IZ_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_fTIETjRa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Yi2fYugt, 1, m, &cVar_Yi2fYugt_sendMessage);
}

void Heavy_CircleStrings::cCast_gs8ZreSM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_6rLWcSea, 0, m, &cVar_6rLWcSea_sendMessage);
}

void Heavy_CircleStrings::cBinop_k8AwyJ1I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ZjcSTAe1, HV_BINOP_DIVIDE, 0, m, &cBinop_ZjcSTAe1_sendMessage);
}

void Heavy_CircleStrings::cSlice_1Py2yTMC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_UvVdZMhk_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Ll9GNorC_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cSlice_NJ9KnpUt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_93TfI35w_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_IBWKmbCT_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cCast_l2En9LsM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_btcvyUQn_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_q8k15fnK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4XcB2edl, HV_BINOP_SUBTRACT, 1, m, &cBinop_4XcB2edl_sendMessage);
}

void Heavy_CircleStrings::cVar_Yh1dqw45_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_k8AwyJ1I, HV_BINOP_SUBTRACT, 1, m, &cBinop_k8AwyJ1I_sendMessage);
}

void Heavy_CircleStrings::cCast_xdr0FEFS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_A2HeDVbs_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_J6MEm3ou_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_il4LWkq0, 0, m, &cDelay_il4LWkq0_sendMessage);
}

void Heavy_CircleStrings::cVar_gnDhbVDa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_doMSd0Oj, HV_BINOP_MULTIPLY, 0, m, &cBinop_doMSd0Oj_sendMessage);
}

void Heavy_CircleStrings::cCast_ZI44pPse_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_J6MEm3ou_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_il4LWkq0, 0, m, &cDelay_il4LWkq0_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_Yi2fYugt, 0, m, &cVar_Yi2fYugt_sendMessage);
}

void Heavy_CircleStrings::cBinop_YKTeX6kT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_il4LWkq0, 2, m, &cDelay_il4LWkq0_sendMessage);
}

void Heavy_CircleStrings::cBinop_doMSd0Oj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_YKTeX6kT_sendMessage);
}

void Heavy_CircleStrings::cSystem_djbOKddh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_yCjIpHmn_sendMessage);
}

void Heavy_CircleStrings::cMsg_p6kZOPxX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_djbOKddh_sendMessage);
}

void Heavy_CircleStrings::cDelay_il4LWkq0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_il4LWkq0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_il4LWkq0, 0, m, &cDelay_il4LWkq0_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_Yi2fYugt, 0, m, &cVar_Yi2fYugt_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_tJi19fBP_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cMsg_J6MEm3ou_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_J6MEm3ou_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ZI44pPse_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_yCjIpHmn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_doMSd0Oj, HV_BINOP_MULTIPLY, 1, m, &cBinop_doMSd0Oj_sendMessage);
}

void Heavy_CircleStrings::cCast_zd3dRFfn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_FLOpf3IZ_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cPack_iufSNh34_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_hCMeY2uX, 0, m, NULL);
}

void Heavy_CircleStrings::cBinop_nEg3xGhJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 4.0f, 0, m, &cBinop_LZqhwFC8_sendMessage);
}

void Heavy_CircleStrings::cBinop_wgg8oiEx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_nEg3xGhJ_sendMessage);
}

void Heavy_CircleStrings::cCast_zQyxLGBE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_pwjST8Iy_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cVar_RQwqhkkt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cSend_qcBgEtaq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_VeAdaoIm_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cReceive_rNZIgAjR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_ZzVCQfLU_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_GAvKpMNZ, 0, m, &cVar_GAvKpMNZ_sendMessage);
}

void Heavy_CircleStrings::cReceive_rqpQvU8y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 2.0f, 0, m, &cBinop_6dHVvDyN_sendMessage);
}

void Heavy_CircleStrings::cReceive_s43HyO1s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_fIVeAPPf, 0, m, &cVar_fIVeAPPf_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_EiQTMZfM, 0, m, &cVar_EiQTMZfM_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_n2HO47KA, 0, m, &cVar_n2HO47KA_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_urvmPGFa, 0, m, &cVar_urvmPGFa_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_y6IcNk58_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_EOLlZAv8, 0, m, &cIf_EOLlZAv8_sendMessage);
}

void Heavy_CircleStrings::cReceive_tAY3cULM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_4iNdWl7o_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_7zvZCtdY, 0, m, &cVar_7zvZCtdY_sendMessage);
}

void Heavy_CircleStrings::cReceive_tD3huP1Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_R9h1RyvC, 0, m, &cVar_R9h1RyvC_sendMessage);
}

void Heavy_CircleStrings::cReceive_tzbko9pQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_ActXizl2, 1, m, &cPack_ActXizl2_sendMessage);
}

void Heavy_CircleStrings::cReceive_uQCN2ilN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_RovwkIw2, m);
}

void Heavy_CircleStrings::cBinop_4OGd9oUL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_R1TDQnTO, HV_BINOP_POW, 1, m, &cBinop_R1TDQnTO_sendMessage);
  cMsg_Zx7vdi9s_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_72GARumQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_4OGd9oUL_sendMessage);
}

void Heavy_CircleStrings::cMsg_CYwbyEbL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_n0OB1FeM, 0, m, &cPack_n0OB1FeM_sendMessage);
}

void Heavy_CircleStrings::cBinop_DQ4MuwHA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_aFG3oJ94, 1, m, &cIf_aFG3oJ94_sendMessage);
}

void Heavy_CircleStrings::cCast_M34Jiqr9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_DQ4MuwHA_sendMessage);
}

void Heavy_CircleStrings::cBinop_R1TDQnTO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_n0OB1FeM, 0, m, &cPack_n0OB1FeM_sendMessage);
}

void Heavy_CircleStrings::cMsg_Zx7vdi9s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_R1TDQnTO, HV_BINOP_POW, 0, m, &cBinop_R1TDQnTO_sendMessage);
}

void Heavy_CircleStrings::cIf_aFG3oJ94_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_CYwbyEbL_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_qq6K9PHv_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_qq6K9PHv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_72GARumQ_sendMessage);
}

void Heavy_CircleStrings::cCast_ulFj3abE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_aFG3oJ94, 0, m, &cIf_aFG3oJ94_sendMessage);
}

void Heavy_CircleStrings::cVar_R3BZRvfh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Mc6e8bXN_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_M34Jiqr9_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ulFj3abE_sendMessage);
}

void Heavy_CircleStrings::cMsg_Mc6e8bXN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSend_oe79uwhZ_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_S4gbTVyH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_YBKV6ZZ2_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cVar_nOtz2eXo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_S4gbTVyH_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cPack_n0OB1FeM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_1nmIr3hl, 0, m, NULL);
}

void Heavy_CircleStrings::cSend_oe79uwhZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_idSlIBqh_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cReceive_v3oGutji_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_wOvvQsvc_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_4EPkCYO2, 0, m, &cVar_4EPkCYO2_sendMessage);
}

void Heavy_CircleStrings::cBinop_6dHVvDyN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_RH0tEmei_sendMessage);
}

void Heavy_CircleStrings::cBinop_3HiO7cSt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_ZloLYCGC_sendMessage);
}

void Heavy_CircleStrings::cIf_C1Nlw5Ns_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_by5Gs2rE_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_LOG10, m, &cUnop_SqFaCkpw_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_IU0YaDfn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_C1Nlw5Ns, 1, m, &cIf_C1Nlw5Ns_sendMessage);
}

void Heavy_CircleStrings::cBinop_PCkC4yJ9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 100.0f, 0, m, &cBinop_3HiO7cSt_sendMessage);
}

void Heavy_CircleStrings::cUnop_SqFaCkpw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_PCkC4yJ9_sendMessage);
}

void Heavy_CircleStrings::cCast_XkpfIO9r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_C1Nlw5Ns, 0, m, &cIf_C1Nlw5Ns_sendMessage);
}

void Heavy_CircleStrings::cBinop_ZloLYCGC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_grbSjNXQ, 0, m, &cVar_grbSjNXQ_sendMessage);
}

void Heavy_CircleStrings::cMsg_by5Gs2rE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_grbSjNXQ, 0, m, &cVar_grbSjNXQ_sendMessage);
}

void Heavy_CircleStrings::cCast_zfpMRGbO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_IU0YaDfn_sendMessage);
}

void Heavy_CircleStrings::cBinop_RH0tEmei_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_zfpMRGbO_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_XkpfIO9r_sendMessage);
}

void Heavy_CircleStrings::cBinop_3yu34DfP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_9BfSbfVA_sendMessage);
}

void Heavy_CircleStrings::cBinop_9BfSbfVA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_y3AuMYvo, 0, m, &cVar_y3AuMYvo_sendMessage);
}

void Heavy_CircleStrings::cMsg_bNylbiLP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_nc5IodC2_sendMessage);
}

void Heavy_CircleStrings::cSystem_nc5IodC2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_VHV4oP1k_sendMessage);
}

void Heavy_CircleStrings::cDelay_5b8HQKK4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_5b8HQKK4, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_b9nxvE9s, 0, m, &sTabread_b9nxvE9s_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_5b8HQKK4, 0, m, &cDelay_5b8HQKK4_sendMessage);
}

void Heavy_CircleStrings::cBinop_BcSVFyaO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ZCwEjOv8, HV_BINOP_MAX, 0, m, &cBinop_ZCwEjOv8_sendMessage);
}

void Heavy_CircleStrings::cMsg_Hd8hM02e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_dJXlauGI_sendMessage);
}

void Heavy_CircleStrings::cVar_NsY2i96y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Hd8hM02e_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_SDREH4oa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_UwHC7l98_sendMessage);
}

void Heavy_CircleStrings::cBinop_UwHC7l98_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Zs6V39RZ, 2, m, &cDelay_Zs6V39RZ_sendMessage);
}

void Heavy_CircleStrings::cBinop_VHV4oP1k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_BcSVFyaO, HV_BINOP_MULTIPLY, 0, m, &cBinop_BcSVFyaO_sendMessage);
}

void Heavy_CircleStrings::cCast_VQPLPN2T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Zs6V39RZ, 0, m, &cDelay_Zs6V39RZ_sendMessage);
}

void Heavy_CircleStrings::cBinop_ZCwEjOv8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_mwUeFqx8, HV_BINOP_SUBTRACT, 1, m, &cBinop_mwUeFqx8_sendMessage);
}

void Heavy_CircleStrings::cDelay_Zs6V39RZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Zs6V39RZ, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_5b8HQKK4, 0, m, &cDelay_5b8HQKK4_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_b9nxvE9s, 0, m, &sTabread_b9nxvE9s_sendMessage);
}

void Heavy_CircleStrings::sTabread_b9nxvE9s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_SDREH4oa, HV_BINOP_SUBTRACT, 0, m, &cBinop_SDREH4oa_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cCast_d7B4bXi2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_NsY2i96y, 0, m, &cVar_NsY2i96y_sendMessage);
  cMsg_bNylbiLP_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_ltGKqveF, 0, m, &cTabhead_ltGKqveF_sendMessage);
}

void Heavy_CircleStrings::cSystem_dJXlauGI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_SDREH4oa, HV_BINOP_SUBTRACT, 1, m, &cBinop_SDREH4oa_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_5b8HQKK4, 2, m, &cDelay_5b8HQKK4_sendMessage);
}

void Heavy_CircleStrings::cTabhead_ltGKqveF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_mwUeFqx8, HV_BINOP_SUBTRACT, 0, m, &cBinop_mwUeFqx8_sendMessage);
}

void Heavy_CircleStrings::cMsg_mCwWjVxC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_ZCwEjOv8, HV_BINOP_MAX, 1, m, &cBinop_ZCwEjOv8_sendMessage);
}

void Heavy_CircleStrings::cBinop_mwUeFqx8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ubdBPvp7_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_b9nxvE9s, 0, m, &sTabread_b9nxvE9s_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_VQPLPN2T_sendMessage);
}

void Heavy_CircleStrings::cMsg_ubdBPvp7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_Zs6V39RZ, 0, m, &cDelay_Zs6V39RZ_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_5b8HQKK4, 0, m, &cDelay_5b8HQKK4_sendMessage);
}

void Heavy_CircleStrings::cBinop_Tn42qLDm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_kBRGOmSe_sendMessage);
}

void Heavy_CircleStrings::cBinop_kBRGOmSe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 200.0f, 0, m, &cBinop_Vs8eTpBv_sendMessage);
}

void Heavy_CircleStrings::cVar_B9lh18dH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_mKIAIItc, HV_BINOP_MULTIPLY, 0, m, &cBinop_mKIAIItc_sendMessage);
}

void Heavy_CircleStrings::cMsg_0GRO5kiV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_zQDJR3OR_sendMessage);
}

void Heavy_CircleStrings::cSystem_zQDJR3OR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_hjwmKCDm_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_hjwmKCDm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_qrMOoCPx_sendMessage);
}

void Heavy_CircleStrings::cBinop_mKIAIItc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_Lvfl5GiO_sendMessage);
}

void Heavy_CircleStrings::cBinop_qrMOoCPx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_mKIAIItc, HV_BINOP_MULTIPLY, 1, m, &cBinop_mKIAIItc_sendMessage);
}

void Heavy_CircleStrings::cBinop_TSNdKbFA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_WG3C307I, m);
}

void Heavy_CircleStrings::cBinop_Lvfl5GiO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_djBf59PH_sendMessage);
}

void Heavy_CircleStrings::cBinop_djBf59PH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_TSNdKbFA_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_860e0l7y, m);
}

void Heavy_CircleStrings::cBinop_2r46FSc4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_8DnEodvj, HV_BINOP_SUBTRACT, 1, m, &cBinop_8DnEodvj_sendMessage);
}

void Heavy_CircleStrings::cCast_3XAlCAba_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_XSnpUi0o, 0, m, &cDelay_XSnpUi0o_sendMessage);
}

void Heavy_CircleStrings::cBinop_8DnEodvj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_n1drs6ME_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_K6hA9yka, 0, m, &sTabread_K6hA9yka_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_3XAlCAba_sendMessage);
}

void Heavy_CircleStrings::cSystem_MW5IAokN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_Ppkwuftz_sendMessage);
}

void Heavy_CircleStrings::cMsg_xC88pWif_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_MW5IAokN_sendMessage);
}

void Heavy_CircleStrings::cBinop_I80szfDg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_2r46FSc4, HV_BINOP_MAX, 0, m, &cBinop_2r46FSc4_sendMessage);
}

void Heavy_CircleStrings::cBinop_JRc8LTmf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_XSnpUi0o, 2, m, &cDelay_XSnpUi0o_sendMessage);
}

void Heavy_CircleStrings::sTabread_K6hA9yka_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_vXq9ty0r, HV_BINOP_SUBTRACT, 0, m, &cBinop_vXq9ty0r_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cTabhead_NIYmTsXC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_8DnEodvj, HV_BINOP_SUBTRACT, 0, m, &cBinop_8DnEodvj_sendMessage);
}

void Heavy_CircleStrings::cDelay_PkQ4FZ9V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_PkQ4FZ9V, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_K6hA9yka, 0, m, &sTabread_K6hA9yka_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_PkQ4FZ9V, 0, m, &cDelay_PkQ4FZ9V_sendMessage);
}

void Heavy_CircleStrings::cBinop_Ppkwuftz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_I80szfDg, HV_BINOP_MULTIPLY, 0, m, &cBinop_I80szfDg_sendMessage);
}

void Heavy_CircleStrings::cDelay_XSnpUi0o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_XSnpUi0o, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_PkQ4FZ9V, 0, m, &cDelay_PkQ4FZ9V_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_K6hA9yka, 0, m, &sTabread_K6hA9yka_sendMessage);
}

void Heavy_CircleStrings::cSystem_fQgV9Mao_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_vXq9ty0r, HV_BINOP_SUBTRACT, 1, m, &cBinop_vXq9ty0r_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_PkQ4FZ9V, 2, m, &cDelay_PkQ4FZ9V_sendMessage);
}

void Heavy_CircleStrings::cVar_iWnY6XFK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_kG80vQei_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_kG80vQei_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_fQgV9Mao_sendMessage);
}

void Heavy_CircleStrings::cMsg_n1drs6ME_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_XSnpUi0o, 0, m, &cDelay_XSnpUi0o_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_PkQ4FZ9V, 0, m, &cDelay_PkQ4FZ9V_sendMessage);
}

void Heavy_CircleStrings::cMsg_omqBk88d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_2r46FSc4, HV_BINOP_MAX, 1, m, &cBinop_2r46FSc4_sendMessage);
}

void Heavy_CircleStrings::cCast_u5Iwv7FZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_iWnY6XFK, 0, m, &cVar_iWnY6XFK_sendMessage);
  cMsg_xC88pWif_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_NIYmTsXC, 0, m, &cTabhead_NIYmTsXC_sendMessage);
}

void Heavy_CircleStrings::cBinop_vXq9ty0r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_JRc8LTmf_sendMessage);
}

void Heavy_CircleStrings::cVar_CBgxWohu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_6y7ZfPLz, 0, m, &cVar_6y7ZfPLz_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_B9lh18dH, 0, m, &cVar_B9lh18dH_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_KAwev9r0, 0, m, &cVar_KAwev9r0_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_xo4XpkPP, 0, m, &cVar_xo4XpkPP_sendMessage);
}

void Heavy_CircleStrings::cVar_y3AuMYvo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.01f, 0, m, &cBinop_hLqjjijD_sendMessage);
}

void Heavy_CircleStrings::cBinop_IEpfh73H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_ikjnkobH, 0, m, &cPack_ikjnkobH_sendMessage);
}

void Heavy_CircleStrings::cBinop_Qgqe23Pc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_9OHNYlIA, m);
}

void Heavy_CircleStrings::cBinop_7f8gGDlg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_Mlc3oq4I_sendMessage);
}

void Heavy_CircleStrings::cBinop_Mlc3oq4I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_Qgqe23Pc_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_lF5sp862, m);
}

void Heavy_CircleStrings::cMsg_BzwFzVkh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_dMloV94d_sendMessage);
}

void Heavy_CircleStrings::cBinop_KRp8pmio_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_7f8gGDlg_sendMessage);
}

void Heavy_CircleStrings::cBinop_dMloV94d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_KRp8pmio, HV_BINOP_MULTIPLY, 1, m, &cBinop_KRp8pmio_sendMessage);
}

void Heavy_CircleStrings::cSystem_6pvHdymV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_BzwFzVkh_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_PUoqs3IV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_6pvHdymV_sendMessage);
}

void Heavy_CircleStrings::cVar_KAwev9r0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_KRp8pmio, HV_BINOP_MULTIPLY, 0, m, &cBinop_KRp8pmio_sendMessage);
}

void Heavy_CircleStrings::cMsg_Pje2F57r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 3000.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_CBgxWohu, 0, m, &cVar_CBgxWohu_sendMessage);
}

void Heavy_CircleStrings::cMsg_8lrd54HH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_YIMyWBrt, 1, m, NULL);
}

void Heavy_CircleStrings::cBinop_E4u2AgAz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_uuI8AlL4_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_H8kRmOwO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_HWyBuD8F_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_KCpVTC3G, 2, m, &cDelay_KCpVTC3G_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_bDdiAUpi_sendMessage);
}

void Heavy_CircleStrings::cMsg_HWyBuD8F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_RyS40cLD, 2, m, &cDelay_RyS40cLD_sendMessage);
}

void Heavy_CircleStrings::cDelay_KCpVTC3G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_KCpVTC3G, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_RyS40cLD, 0, m, &cDelay_RyS40cLD_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_KCpVTC3G, 0, m, &cDelay_KCpVTC3G_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_YIMyWBrt, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_RyS40cLD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_RyS40cLD, m);
  cMsg_bcA4id0C_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_bDdiAUpi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_KCpVTC3G, 0, m, &cDelay_KCpVTC3G_sendMessage);
}

void Heavy_CircleStrings::cMsg_bcA4id0C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_H8kRmOwO, 0, m, &hTable_H8kRmOwO_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_fK3wxaem_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_8lrd54HH_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cSystem_ln4JGEOJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_stZaYNFS_sendMessage);
}

void Heavy_CircleStrings::cMsg_xdeW7YyO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ln4JGEOJ_sendMessage);
}

void Heavy_CircleStrings::cBinop_stZaYNFS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 69.4325f, 0, m, &cBinop_E4u2AgAz_sendMessage);
}

void Heavy_CircleStrings::cMsg_uuI8AlL4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_H8kRmOwO, 0, m, &hTable_H8kRmOwO_sendMessage);
}

void Heavy_CircleStrings::cBinop_Vs8eTpBv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_i0Fw54NV, 0, m, &cPack_i0Fw54NV_sendMessage);
}

void Heavy_CircleStrings::cPack_WoUl5Yx9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_XmeLOi76, 0, m, NULL);
}

void Heavy_CircleStrings::cBinop_1XTcn22c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_d3mfOe8P_sendMessage);
}

void Heavy_CircleStrings::cBinop_8laCWeg3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.125f, 0, m, &cBinop_IEpfh73H_sendMessage);
}

void Heavy_CircleStrings::cMsg_GUKfx5dt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_8laCWeg3, HV_BINOP_POW, 0, m, &cBinop_8laCWeg3_sendMessage);
}

void Heavy_CircleStrings::cMsg_SYuu5iYJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.125f, 0, m, &cBinop_IEpfh73H_sendMessage);
}

void Heavy_CircleStrings::cCast_V9AclM2w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_nwiihNwk, 0, m, &cIf_nwiihNwk_sendMessage);
}

void Heavy_CircleStrings::cCast_bgOC2cQW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_kJbUExuH_sendMessage);
}

void Heavy_CircleStrings::cBinop_d3mfOe8P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_8laCWeg3, HV_BINOP_POW, 1, m, &cBinop_8laCWeg3_sendMessage);
  cMsg_GUKfx5dt_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_kJbUExuH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_nwiihNwk, 1, m, &cIf_nwiihNwk_sendMessage);
}

void Heavy_CircleStrings::cIf_nwiihNwk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_SYuu5iYJ_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_wKa03XuD_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_wKa03XuD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_1XTcn22c_sendMessage);
}

void Heavy_CircleStrings::cMsg_QfYRZAAt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_YgeTeMXQ, 0, m, &hTable_YgeTeMXQ_sendMessage);
}

void Heavy_CircleStrings::cMsg_Tcwnk59D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_YgeTeMXQ, 0, m, &hTable_YgeTeMXQ_sendMessage);
}

void Heavy_CircleStrings::cMsg_Y3fYBJlC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_s8wGxbaa, 2, m, &cDelay_s8wGxbaa_sendMessage);
}

void Heavy_CircleStrings::hTable_YgeTeMXQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Y3fYBJlC_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_kIgi2xU2, 2, m, &cDelay_kIgi2xU2_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_nf29zP9d_sendMessage);
}

void Heavy_CircleStrings::cBinop_YttXSjgB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Tcwnk59D_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_MgYlK9We_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_qqFT9wmO_sendMessage);
}

void Heavy_CircleStrings::cSystem_qqFT9wmO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_vPtQRRQh_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_ir9q0i3c_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_y01lKo1A_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cDelay_kIgi2xU2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_kIgi2xU2, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_s8wGxbaa, 0, m, &cDelay_s8wGxbaa_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_kIgi2xU2, 0, m, &cDelay_kIgi2xU2_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_cL0rvWDe, 1, m, NULL);
}

void Heavy_CircleStrings::cCast_nf29zP9d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_kIgi2xU2, 0, m, &cDelay_kIgi2xU2_sendMessage);
}

void Heavy_CircleStrings::cDelay_s8wGxbaa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_s8wGxbaa, m);
  cMsg_QfYRZAAt_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_vPtQRRQh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 43.5337f, 0, m, &cBinop_YttXSjgB_sendMessage);
}

void Heavy_CircleStrings::cMsg_y01lKo1A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_cL0rvWDe, 1, m, NULL);
}

void Heavy_CircleStrings::cMsg_BdqdGDli_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_BnqGkGiZ, 2, m, &cDelay_BnqGkGiZ_sendMessage);
}

void Heavy_CircleStrings::cDelay_BnqGkGiZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_BnqGkGiZ, m);
  cMsg_adt5ayG8_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_NG1rA9r2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_mo6EloTV_sendMessage);
}

void Heavy_CircleStrings::cSystem_mo6EloTV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_l9G5C1pI_sendMessage);
}

void Heavy_CircleStrings::hTable_SCpCTX5W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_BdqdGDli_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_tGPSqibE, 2, m, &cDelay_tGPSqibE_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_W9EtX7dS_sendMessage);
}

void Heavy_CircleStrings::cCast_W9EtX7dS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_tGPSqibE, 0, m, &cDelay_tGPSqibE_sendMessage);
}

void Heavy_CircleStrings::cBinop_aMSLNb5u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_lhwRxwnY_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_adt5ayG8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_SCpCTX5W, 0, m, &hTable_SCpCTX5W_sendMessage);
}

void Heavy_CircleStrings::cBinop_l9G5C1pI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 13.645f, 0, m, &cBinop_aMSLNb5u_sendMessage);
}

void Heavy_CircleStrings::cMsg_lhwRxwnY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_SCpCTX5W, 0, m, &hTable_SCpCTX5W_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_tD6PHdYU_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_yirNRKnr_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cDelay_tGPSqibE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_tGPSqibE, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_BnqGkGiZ, 0, m, &cDelay_BnqGkGiZ_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_tGPSqibE, 0, m, &cDelay_tGPSqibE_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_Y52mdAky, 1, m, NULL);
}

void Heavy_CircleStrings::cMsg_yirNRKnr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_Y52mdAky, 1, m, NULL);
}

void Heavy_CircleStrings::cTabhead_9QxNZraR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_OTsyF41f, HV_BINOP_SUBTRACT, 0, m, &cBinop_OTsyF41f_sendMessage);
}

void Heavy_CircleStrings::cMsg_NHbGz78k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_mvQBI5qV, HV_BINOP_MAX, 1, m, &cBinop_mvQBI5qV_sendMessage);
}

void Heavy_CircleStrings::cBinop_OTsyF41f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_sqsw2EZT_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_zRa3O3dH, 0, m, &sTabread_zRa3O3dH_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_gDbLMSEB_sendMessage);
}

void Heavy_CircleStrings::cBinop_PSPF92vu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_mvQBI5qV, HV_BINOP_MAX, 0, m, &cBinop_mvQBI5qV_sendMessage);
}

void Heavy_CircleStrings::cDelay_Q08XYhLX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Q08XYhLX, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_zRa3O3dH, 0, m, &sTabread_zRa3O3dH_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Q08XYhLX, 0, m, &cDelay_Q08XYhLX_sendMessage);
}

void Heavy_CircleStrings::cMsg_OUxS27Up_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_dRWbWHQR_sendMessage);
}

void Heavy_CircleStrings::cSystem_dRWbWHQR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_vRWNT9iK_sendMessage);
}

void Heavy_CircleStrings::cMsg_RlHAjnoq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_pwFS074N_sendMessage);
}

void Heavy_CircleStrings::cBinop_WkLBgba0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_rgW0CU60_sendMessage);
}

void Heavy_CircleStrings::cCast_gDbLMSEB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_rFEM6vr5, 0, m, &cDelay_rFEM6vr5_sendMessage);
}

void Heavy_CircleStrings::cCast_m0jn3s0L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_mTdviuQV, 0, m, &cVar_mTdviuQV_sendMessage);
  cMsg_OUxS27Up_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_9QxNZraR, 0, m, &cTabhead_9QxNZraR_sendMessage);
}

void Heavy_CircleStrings::cVar_mTdviuQV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_RlHAjnoq_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_mvQBI5qV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_OTsyF41f, HV_BINOP_SUBTRACT, 1, m, &cBinop_OTsyF41f_sendMessage);
}

void Heavy_CircleStrings::cSystem_pwFS074N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_WkLBgba0, HV_BINOP_SUBTRACT, 1, m, &cBinop_WkLBgba0_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Q08XYhLX, 2, m, &cDelay_Q08XYhLX_sendMessage);
}

void Heavy_CircleStrings::cDelay_rFEM6vr5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_rFEM6vr5, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Q08XYhLX, 0, m, &cDelay_Q08XYhLX_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_zRa3O3dH, 0, m, &sTabread_zRa3O3dH_sendMessage);
}

void Heavy_CircleStrings::cBinop_rgW0CU60_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_rFEM6vr5, 2, m, &cDelay_rFEM6vr5_sendMessage);
}

void Heavy_CircleStrings::cMsg_sqsw2EZT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_rFEM6vr5, 0, m, &cDelay_rFEM6vr5_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Q08XYhLX, 0, m, &cDelay_Q08XYhLX_sendMessage);
}

void Heavy_CircleStrings::cBinop_vRWNT9iK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_PSPF92vu, HV_BINOP_MULTIPLY, 0, m, &cBinop_PSPF92vu_sendMessage);
}

void Heavy_CircleStrings::sTabread_zRa3O3dH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_WkLBgba0, HV_BINOP_SUBTRACT, 0, m, &cBinop_WkLBgba0_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_0bUP7BVu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_YB4Ilcxk_sendMessage);
}

void Heavy_CircleStrings::cBinop_6F176PMn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_SoHFXhRG, HV_BINOP_SUBTRACT, 1, m, &cBinop_SoHFXhRG_sendMessage);
}

void Heavy_CircleStrings::cBinop_D9DIelR2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6F176PMn, HV_BINOP_MAX, 0, m, &cBinop_6F176PMn_sendMessage);
}

void Heavy_CircleStrings::cVar_EKfRxP7g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_iDuPVdNL_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_Hk9FP7Op_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Hk9FP7Op, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_by9PCdOX, 0, m, &sTabread_by9PCdOX_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Hk9FP7Op, 0, m, &cDelay_Hk9FP7Op_sendMessage);
}

void Heavy_CircleStrings::cMsg_IgIk2IkY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_6F176PMn, HV_BINOP_MAX, 1, m, &cBinop_6F176PMn_sendMessage);
}

void Heavy_CircleStrings::cSystem_NVPcICtK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_0bUP7BVu, HV_BINOP_SUBTRACT, 1, m, &cBinop_0bUP7BVu_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Hk9FP7Op, 2, m, &cDelay_Hk9FP7Op_sendMessage);
}

void Heavy_CircleStrings::cTabhead_Nh0FxNNP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_SoHFXhRG, HV_BINOP_SUBTRACT, 0, m, &cBinop_SoHFXhRG_sendMessage);
}

void Heavy_CircleStrings::cBinop_QtSnYzLF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_D9DIelR2, HV_BINOP_MULTIPLY, 0, m, &cBinop_D9DIelR2_sendMessage);
}

void Heavy_CircleStrings::cMsg_SkPunxAe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_gFpHcb3T, 0, m, &cDelay_gFpHcb3T_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Hk9FP7Op, 0, m, &cDelay_Hk9FP7Op_sendMessage);
}

void Heavy_CircleStrings::cBinop_SoHFXhRG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_SkPunxAe_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_by9PCdOX, 0, m, &sTabread_by9PCdOX_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_v9Gjd9o4_sendMessage);
}

void Heavy_CircleStrings::cBinop_YB4Ilcxk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_gFpHcb3T, 2, m, &cDelay_gFpHcb3T_sendMessage);
}

void Heavy_CircleStrings::cCast_ZuFN01Qg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_EKfRxP7g, 0, m, &cVar_EKfRxP7g_sendMessage);
  cMsg_rqBTySv7_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_Nh0FxNNP, 0, m, &cTabhead_Nh0FxNNP_sendMessage);
}

void Heavy_CircleStrings::sTabread_by9PCdOX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_0bUP7BVu, HV_BINOP_SUBTRACT, 0, m, &cBinop_0bUP7BVu_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cSystem_DSGeNqGe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_QtSnYzLF_sendMessage);
}

void Heavy_CircleStrings::cMsg_rqBTySv7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_DSGeNqGe_sendMessage);
}

void Heavy_CircleStrings::cDelay_gFpHcb3T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_gFpHcb3T, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Hk9FP7Op, 0, m, &cDelay_Hk9FP7Op_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_by9PCdOX, 0, m, &sTabread_by9PCdOX_sendMessage);
}

void Heavy_CircleStrings::cMsg_iDuPVdNL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_NVPcICtK_sendMessage);
}

void Heavy_CircleStrings::cCast_v9Gjd9o4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_gFpHcb3T, 0, m, &cDelay_gFpHcb3T_sendMessage);
}

void Heavy_CircleStrings::cVar_0u2RV7S3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_IIsOyJhJ_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cTabhead_3OjGBzpx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_KxDKiHt2, HV_BINOP_SUBTRACT, 0, m, &cBinop_KxDKiHt2_sendMessage);
}

void Heavy_CircleStrings::cCast_58D7xTy2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_0u2RV7S3, 0, m, &cVar_0u2RV7S3_sendMessage);
  cMsg_q9qq7oTQ_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_3OjGBzpx, 0, m, &cTabhead_3OjGBzpx_sendMessage);
}

void Heavy_CircleStrings::cMsg_IIsOyJhJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_sY69BtZq_sendMessage);
}

void Heavy_CircleStrings::cBinop_IbtYV3Po_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_o9cWFQb6_sendMessage);
}

void Heavy_CircleStrings::cBinop_KxDKiHt2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_jipezGi1_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_VKRaAijF, 0, m, &sTabread_VKRaAijF_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_uRwM9GNm_sendMessage);
}

void Heavy_CircleStrings::cDelay_Syd36h5d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Syd36h5d, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_fGb2QLGv, 0, m, &cDelay_fGb2QLGv_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_VKRaAijF, 0, m, &sTabread_VKRaAijF_sendMessage);
}

void Heavy_CircleStrings::sTabread_VKRaAijF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_IbtYV3Po, HV_BINOP_SUBTRACT, 0, m, &cBinop_IbtYV3Po_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cDelay_fGb2QLGv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_fGb2QLGv, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_VKRaAijF, 0, m, &sTabread_VKRaAijF_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_fGb2QLGv, 0, m, &cDelay_fGb2QLGv_sendMessage);
}

void Heavy_CircleStrings::cBinop_ffLmpw6C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_KxDKiHt2, HV_BINOP_SUBTRACT, 1, m, &cBinop_KxDKiHt2_sendMessage);
}

void Heavy_CircleStrings::cBinop_i5X1itQb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_zldvKZTW, HV_BINOP_MULTIPLY, 0, m, &cBinop_zldvKZTW_sendMessage);
}

void Heavy_CircleStrings::cMsg_jipezGi1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_Syd36h5d, 0, m, &cDelay_Syd36h5d_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_fGb2QLGv, 0, m, &cDelay_fGb2QLGv_sendMessage);
}

void Heavy_CircleStrings::cBinop_o9cWFQb6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Syd36h5d, 2, m, &cDelay_Syd36h5d_sendMessage);
}

void Heavy_CircleStrings::cSystem_sY69BtZq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_IbtYV3Po, HV_BINOP_SUBTRACT, 1, m, &cBinop_IbtYV3Po_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_fGb2QLGv, 2, m, &cDelay_fGb2QLGv_sendMessage);
}

void Heavy_CircleStrings::cCast_uRwM9GNm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Syd36h5d, 0, m, &cDelay_Syd36h5d_sendMessage);
}

void Heavy_CircleStrings::cMsg_yBohUrD3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_ffLmpw6C, HV_BINOP_MAX, 1, m, &cBinop_ffLmpw6C_sendMessage);
}

void Heavy_CircleStrings::cSystem_ORab0XlS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_i5X1itQb_sendMessage);
}

void Heavy_CircleStrings::cMsg_q9qq7oTQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ORab0XlS_sendMessage);
}

void Heavy_CircleStrings::cBinop_zldvKZTW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ffLmpw6C, HV_BINOP_MAX, 0, m, &cBinop_ffLmpw6C_sendMessage);
}

void Heavy_CircleStrings::cMsg_6bkVM1yt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_CuyGdw13, 0, m, &hTable_CuyGdw13_sendMessage);
}

void Heavy_CircleStrings::cDelay_CHWKAnDn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_CHWKAnDn, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_HONBMz3P, 0, m, &cDelay_HONBMz3P_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_CHWKAnDn, 0, m, &cDelay_CHWKAnDn_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_DuQ4Co8P, 1, m, NULL);
}

void Heavy_CircleStrings::hTable_CuyGdw13_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_MqY07X5b_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_CHWKAnDn, 2, m, &cDelay_CHWKAnDn_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_R1uawaao_sendMessage);
}

void Heavy_CircleStrings::cBinop_Gnuw3zEv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_6bkVM1yt_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_HONBMz3P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_HONBMz3P, m);
  cMsg_cIK67BWw_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_KtNQfHg4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_DuQ4Co8P, 1, m, NULL);
}

void Heavy_CircleStrings::cMsg_MqY07X5b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_HONBMz3P, 2, m, &cDelay_HONBMz3P_sendMessage);
}

void Heavy_CircleStrings::cMsg_3z2QaTYr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_usmO66Dg_sendMessage);
}

void Heavy_CircleStrings::cSystem_usmO66Dg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_z5RHvbPg_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_PcmCnHRn_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_KtNQfHg4_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cCast_R1uawaao_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_CHWKAnDn, 0, m, &cDelay_CHWKAnDn_sendMessage);
}

void Heavy_CircleStrings::cMsg_cIK67BWw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_CuyGdw13, 0, m, &hTable_CuyGdw13_sendMessage);
}

void Heavy_CircleStrings::cBinop_z5RHvbPg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 19.392f, 0, m, &cBinop_Gnuw3zEv_sendMessage);
}

void Heavy_CircleStrings::cBinop_0LaYx6XK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 16.364f, 0, m, &cBinop_UJKdA943_sendMessage);
}

void Heavy_CircleStrings::cSystem_kEJJAuR9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_0LaYx6XK_sendMessage);
}

void Heavy_CircleStrings::cMsg_uwVSXi1B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_kEJJAuR9_sendMessage);
}

void Heavy_CircleStrings::cDelay_AaZPXpPP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_AaZPXpPP, m);
  cMsg_LVyDya7h_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_EHQ7k1yS_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_KpnaiOas_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cCast_GVhrsp57_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Q5NDGwoX, 0, m, &cDelay_Q5NDGwoX_sendMessage);
}

void Heavy_CircleStrings::cMsg_JeWe56UJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_jjcyPKhQ, 0, m, &hTable_jjcyPKhQ_sendMessage);
}

void Heavy_CircleStrings::cMsg_KpnaiOas_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_Xj1WGi8h, 1, m, NULL);
}

void Heavy_CircleStrings::cMsg_LVyDya7h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_jjcyPKhQ, 0, m, &hTable_jjcyPKhQ_sendMessage);
}

void Heavy_CircleStrings::cDelay_Q5NDGwoX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Q5NDGwoX, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_AaZPXpPP, 0, m, &cDelay_AaZPXpPP_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Q5NDGwoX, 0, m, &cDelay_Q5NDGwoX_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_Xj1WGi8h, 1, m, NULL);
}

void Heavy_CircleStrings::cBinop_UJKdA943_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_JeWe56UJ_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_ivzfRKZ7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_AaZPXpPP, 2, m, &cDelay_AaZPXpPP_sendMessage);
}

void Heavy_CircleStrings::hTable_jjcyPKhQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ivzfRKZ7_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Q5NDGwoX, 2, m, &cDelay_Q5NDGwoX_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_GVhrsp57_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_61hRkCkk_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_Ccent5HC_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cMsg_8OkOraZK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_CzagagvU, 2, m, &cDelay_CzagagvU_sendMessage);
}

void Heavy_CircleStrings::cDelay_8ZH2SyPE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_8ZH2SyPE, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_CzagagvU, 0, m, &cDelay_CzagagvU_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_8ZH2SyPE, 0, m, &cDelay_8ZH2SyPE_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_1KVHmk1a, 1, m, NULL);
}

void Heavy_CircleStrings::cBinop_9QL17Sxq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 25.796f, 0, m, &cBinop_Sai3hU5Y_sendMessage);
}

void Heavy_CircleStrings::cMsg_Ccent5HC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_1KVHmk1a, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_CzagagvU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_CzagagvU, m);
  cMsg_YFizWWF7_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_DR14GAwe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_wWU6EClR, 0, m, &hTable_wWU6EClR_sendMessage);
}

void Heavy_CircleStrings::cCast_QPio2HST_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_8ZH2SyPE, 0, m, &cDelay_8ZH2SyPE_sendMessage);
}

void Heavy_CircleStrings::cBinop_Sai3hU5Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_DR14GAwe_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_YFizWWF7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_wWU6EClR, 0, m, &hTable_wWU6EClR_sendMessage);
}

void Heavy_CircleStrings::cMsg_VRZkqbbs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_qODW8Edw_sendMessage);
}

void Heavy_CircleStrings::cSystem_qODW8Edw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_9QL17Sxq_sendMessage);
}

void Heavy_CircleStrings::hTable_wWU6EClR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_8OkOraZK_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_8ZH2SyPE, 2, m, &cDelay_8ZH2SyPE_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_QPio2HST_sendMessage);
}

void Heavy_CircleStrings::cMsg_YsGQXf8I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_zLVv9BmV_sendMessage);
}

void Heavy_CircleStrings::cSystem_zLVv9BmV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_4mlQGE2G_sendMessage);
}

void Heavy_CircleStrings::cBinop_4mlQGE2G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_7Z4Qgs9V, HV_BINOP_MULTIPLY, 0, m, &cBinop_7Z4Qgs9V_sendMessage);
}

void Heavy_CircleStrings::cBinop_6Jo5QUR3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_8JzNrnfB, 2, m, &cDelay_8JzNrnfB_sendMessage);
}

void Heavy_CircleStrings::cBinop_7Z4Qgs9V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_i4DLWeZ5, HV_BINOP_MAX, 0, m, &cBinop_i4DLWeZ5_sendMessage);
}

void Heavy_CircleStrings::cDelay_8JzNrnfB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_8JzNrnfB, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ecfwyPAy, 0, m, &cDelay_ecfwyPAy_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_Ek55gQhE, 0, m, &sTabread_Ek55gQhE_sendMessage);
}

void Heavy_CircleStrings::cCast_D426Jifn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_8JzNrnfB, 0, m, &cDelay_8JzNrnfB_sendMessage);
}

void Heavy_CircleStrings::cSystem_ED7Gc7D6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_miWQIbJZ, HV_BINOP_SUBTRACT, 1, m, &cBinop_miWQIbJZ_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ecfwyPAy, 2, m, &cDelay_ecfwyPAy_sendMessage);
}

void Heavy_CircleStrings::sTabread_Ek55gQhE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_miWQIbJZ, HV_BINOP_SUBTRACT, 0, m, &cBinop_miWQIbJZ_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cVar_FiQfUHSQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_JBr92XSv_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_JBr92XSv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ED7Gc7D6_sendMessage);
}

void Heavy_CircleStrings::cBinop_QQtVEHLI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_wtzCY1uX_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_Ek55gQhE, 0, m, &sTabread_Ek55gQhE_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_D426Jifn_sendMessage);
}

void Heavy_CircleStrings::cMsg_SG2bcSnR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_i4DLWeZ5, HV_BINOP_MAX, 1, m, &cBinop_i4DLWeZ5_sendMessage);
}

void Heavy_CircleStrings::cTabhead_UyoDPMGJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_QQtVEHLI, HV_BINOP_SUBTRACT, 0, m, &cBinop_QQtVEHLI_sendMessage);
}

void Heavy_CircleStrings::cCast_cv3n2bE1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_FiQfUHSQ, 0, m, &cVar_FiQfUHSQ_sendMessage);
  cMsg_YsGQXf8I_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_UyoDPMGJ, 0, m, &cTabhead_UyoDPMGJ_sendMessage);
}

void Heavy_CircleStrings::cDelay_ecfwyPAy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_ecfwyPAy, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_Ek55gQhE, 0, m, &sTabread_Ek55gQhE_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ecfwyPAy, 0, m, &cDelay_ecfwyPAy_sendMessage);
}

void Heavy_CircleStrings::cBinop_i4DLWeZ5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_QQtVEHLI, HV_BINOP_SUBTRACT, 1, m, &cBinop_QQtVEHLI_sendMessage);
}

void Heavy_CircleStrings::cBinop_miWQIbJZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_6Jo5QUR3_sendMessage);
}

void Heavy_CircleStrings::cMsg_wtzCY1uX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_8JzNrnfB, 0, m, &cDelay_8JzNrnfB_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ecfwyPAy, 0, m, &cDelay_ecfwyPAy_sendMessage);
}

void Heavy_CircleStrings::cMsg_09egX2x5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_BXXOqjmp_sendMessage);
}

void Heavy_CircleStrings::cMsg_AwTrNThN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ZNxmoVhg_sendMessage);
}

void Heavy_CircleStrings::cSystem_ZNxmoVhg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_LcMyXhPg_sendMessage);
}

void Heavy_CircleStrings::cSystem_BXXOqjmp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_D2mqMoBp, HV_BINOP_SUBTRACT, 1, m, &cBinop_D2mqMoBp_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_O56yWMaQ, 2, m, &cDelay_O56yWMaQ_sendMessage);
}

void Heavy_CircleStrings::cMsg_D1Ze6WXd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_IQCLN9v9, 0, m, &cDelay_IQCLN9v9_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_O56yWMaQ, 0, m, &cDelay_O56yWMaQ_sendMessage);
}

void Heavy_CircleStrings::cBinop_D2mqMoBp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_r051JzLh_sendMessage);
}

void Heavy_CircleStrings::cDelay_IQCLN9v9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_IQCLN9v9, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_O56yWMaQ, 0, m, &cDelay_O56yWMaQ_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_JEHCJVUT, 0, m, &sTabread_JEHCJVUT_sendMessage);
}

void Heavy_CircleStrings::sTabread_JEHCJVUT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_D2mqMoBp, HV_BINOP_SUBTRACT, 0, m, &cBinop_D2mqMoBp_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_LcMyXhPg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_iOKitXNS, HV_BINOP_MULTIPLY, 0, m, &cBinop_iOKitXNS_sendMessage);
}

void Heavy_CircleStrings::cDelay_O56yWMaQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_O56yWMaQ, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_JEHCJVUT, 0, m, &sTabread_JEHCJVUT_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_O56yWMaQ, 0, m, &cDelay_O56yWMaQ_sendMessage);
}

void Heavy_CircleStrings::cVar_PIW25mD4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_09egX2x5_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_dgppUsZb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_yDNqQqM2, HV_BINOP_SUBTRACT, 1, m, &cBinop_yDNqQqM2_sendMessage);
}

void Heavy_CircleStrings::cBinop_iOKitXNS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_dgppUsZb, HV_BINOP_MAX, 0, m, &cBinop_dgppUsZb_sendMessage);
}

void Heavy_CircleStrings::cCast_jaq7UoDM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_PIW25mD4, 0, m, &cVar_PIW25mD4_sendMessage);
  cMsg_AwTrNThN_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_wZzXg9rX, 0, m, &cTabhead_wZzXg9rX_sendMessage);
}

void Heavy_CircleStrings::cCast_me5ISvt5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_IQCLN9v9, 0, m, &cDelay_IQCLN9v9_sendMessage);
}

void Heavy_CircleStrings::cBinop_r051JzLh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_IQCLN9v9, 2, m, &cDelay_IQCLN9v9_sendMessage);
}

void Heavy_CircleStrings::cMsg_uBVfidci_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_dgppUsZb, HV_BINOP_MAX, 1, m, &cBinop_dgppUsZb_sendMessage);
}

void Heavy_CircleStrings::cTabhead_wZzXg9rX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_yDNqQqM2, HV_BINOP_SUBTRACT, 0, m, &cBinop_yDNqQqM2_sendMessage);
}

void Heavy_CircleStrings::cBinop_yDNqQqM2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_D1Ze6WXd_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_JEHCJVUT, 0, m, &sTabread_JEHCJVUT_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_me5ISvt5_sendMessage);
}

void Heavy_CircleStrings::cDelay_1AhfLDul_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_1AhfLDul, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Tp24SHiq, 0, m, &cDelay_Tp24SHiq_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_RkVpHXtZ, 0, m, &sTabread_RkVpHXtZ_sendMessage);
}

void Heavy_CircleStrings::cMsg_1earnbJr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_PpQkn2Vn_sendMessage);
}

void Heavy_CircleStrings::cBinop_4MjNL4r0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_WA1JyZAo, HV_BINOP_MULTIPLY, 0, m, &cBinop_WA1JyZAo_sendMessage);
}

void Heavy_CircleStrings::cBinop_6C9Y56FE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_Nj6DFvLz_sendMessage);
}

void Heavy_CircleStrings::cVar_Jw3CfAGI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_1earnbJr_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_N8pmwXwC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_NqAlEh4g_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_RkVpHXtZ, 0, m, &sTabread_RkVpHXtZ_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ipJqZGMy_sendMessage);
}

void Heavy_CircleStrings::cSystem_1fD3OqQY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_4MjNL4r0_sendMessage);
}

void Heavy_CircleStrings::cMsg_no5oSF1E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_1fD3OqQY_sendMessage);
}

void Heavy_CircleStrings::cBinop_Nj6DFvLz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_1AhfLDul, 2, m, &cDelay_1AhfLDul_sendMessage);
}

void Heavy_CircleStrings::cMsg_NqAlEh4g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_1AhfLDul, 0, m, &cDelay_1AhfLDul_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Tp24SHiq, 0, m, &cDelay_Tp24SHiq_sendMessage);
}

void Heavy_CircleStrings::cSystem_PpQkn2Vn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6C9Y56FE, HV_BINOP_SUBTRACT, 1, m, &cBinop_6C9Y56FE_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Tp24SHiq, 2, m, &cDelay_Tp24SHiq_sendMessage);
}

void Heavy_CircleStrings::sTabread_RkVpHXtZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_6C9Y56FE, HV_BINOP_SUBTRACT, 0, m, &cBinop_6C9Y56FE_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cDelay_Tp24SHiq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Tp24SHiq, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_RkVpHXtZ, 0, m, &sTabread_RkVpHXtZ_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Tp24SHiq, 0, m, &cDelay_Tp24SHiq_sendMessage);
}

void Heavy_CircleStrings::cBinop_WA1JyZAo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_cOg55uJD, HV_BINOP_MAX, 0, m, &cBinop_cOg55uJD_sendMessage);
}

void Heavy_CircleStrings::cTabhead_bO3qviwg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_N8pmwXwC, HV_BINOP_SUBTRACT, 0, m, &cBinop_N8pmwXwC_sendMessage);
}

void Heavy_CircleStrings::cBinop_cOg55uJD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_N8pmwXwC, HV_BINOP_SUBTRACT, 1, m, &cBinop_N8pmwXwC_sendMessage);
}

void Heavy_CircleStrings::cMsg_cnfmS3IJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_cOg55uJD, HV_BINOP_MAX, 1, m, &cBinop_cOg55uJD_sendMessage);
}

void Heavy_CircleStrings::cCast_ipJqZGMy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_1AhfLDul, 0, m, &cDelay_1AhfLDul_sendMessage);
}

void Heavy_CircleStrings::cCast_nWqnUC27_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Jw3CfAGI, 0, m, &cVar_Jw3CfAGI_sendMessage);
  cMsg_no5oSF1E_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_bO3qviwg, 0, m, &cTabhead_bO3qviwg_sendMessage);
}

void Heavy_CircleStrings::cCast_1gQyYqzw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_utv2W3am, 0, m, &cDelay_utv2W3am_sendMessage);
}

void Heavy_CircleStrings::cDelay_5gsfKLgn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_5gsfKLgn, m);
  cMsg_SyJC0SQG_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_DxxEZwY6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_5gsfKLgn, 2, m, &cDelay_5gsfKLgn_sendMessage);
}

void Heavy_CircleStrings::hTable_FjgILMCU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_DxxEZwY6_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_utv2W3am, 2, m, &cDelay_utv2W3am_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_1gQyYqzw_sendMessage);
}

void Heavy_CircleStrings::cMsg_HiKwxUu3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_htQtLxlX, 1, m, NULL);
}

void Heavy_CircleStrings::cMsg_SyJC0SQG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_FjgILMCU, 0, m, &hTable_FjgILMCU_sendMessage);
}

void Heavy_CircleStrings::cBinop_UASSaKr9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 75.2546f, 0, m, &cBinop_iiSpjXuD_sendMessage);
}

void Heavy_CircleStrings::cMsg_mihMMqE2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_xxTsk9LZ_sendMessage);
}

void Heavy_CircleStrings::cSystem_xxTsk9LZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_UASSaKr9_sendMessage);
}

void Heavy_CircleStrings::cBinop_iiSpjXuD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_m7aLwn1C_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_lPZzq55l_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_HiKwxUu3_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cMsg_m7aLwn1C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_FjgILMCU, 0, m, &hTable_FjgILMCU_sendMessage);
}

void Heavy_CircleStrings::cDelay_utv2W3am_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_utv2W3am, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_5gsfKLgn, 0, m, &cDelay_5gsfKLgn_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_utv2W3am, 0, m, &cDelay_utv2W3am_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_htQtLxlX, 1, m, NULL);
}

void Heavy_CircleStrings::cBinop_5G7uBBwC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 86.1244f, 0, m, &cBinop_bcQoE42i_sendMessage);
}

void Heavy_CircleStrings::cDelay_9pwok4AD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_9pwok4AD, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_BK6RvTp7, 0, m, &cDelay_BK6RvTp7_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_9pwok4AD, 0, m, &cDelay_9pwok4AD_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_5auDYJV3, 1, m, NULL);
}

void Heavy_CircleStrings::cMsg_9wlJhcS6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_5auDYJV3, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_BK6RvTp7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_BK6RvTp7, m);
  cMsg_fFH97gwZ_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_BpEyo6zp_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_9wlJhcS6_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cMsg_GkIAmfP8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_kORp847N, 0, m, &hTable_kORp847N_sendMessage);
}

void Heavy_CircleStrings::cMsg_S3EzNmf7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_BK6RvTp7, 2, m, &cDelay_BK6RvTp7_sendMessage);
}

void Heavy_CircleStrings::cMsg_jcNCDCLa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_wBz9wSoS_sendMessage);
}

void Heavy_CircleStrings::cSystem_wBz9wSoS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_5G7uBBwC_sendMessage);
}

void Heavy_CircleStrings::cBinop_bcQoE42i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_GkIAmfP8_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_eHOrNmVO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_9pwok4AD, 0, m, &cDelay_9pwok4AD_sendMessage);
}

void Heavy_CircleStrings::cMsg_fFH97gwZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_kORp847N, 0, m, &hTable_kORp847N_sendMessage);
}

void Heavy_CircleStrings::hTable_kORp847N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_S3EzNmf7_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_9pwok4AD, 2, m, &cDelay_9pwok4AD_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_eHOrNmVO_sendMessage);
}

void Heavy_CircleStrings::cBinop_1G8QLz2k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_pfaPnV1i_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_lpFoi13r, 0, m, &sTabread_lpFoi13r_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_LLQSv5U0_sendMessage);
}

void Heavy_CircleStrings::cBinop_4Zy7imgy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_1G8QLz2k, HV_BINOP_SUBTRACT, 1, m, &cBinop_1G8QLz2k_sendMessage);
}

void Heavy_CircleStrings::cTabhead_4a2HeR3f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_1G8QLz2k, HV_BINOP_SUBTRACT, 0, m, &cBinop_1G8QLz2k_sendMessage);
}

void Heavy_CircleStrings::cBinop_4rBvr7Uc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4Zy7imgy, HV_BINOP_MAX, 0, m, &cBinop_4Zy7imgy_sendMessage);
}

void Heavy_CircleStrings::cMsg_5qKhvvY8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_iVcBj2d4_sendMessage);
}

void Heavy_CircleStrings::cBinop_BIXZnmg1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4rBvr7Uc, HV_BINOP_MULTIPLY, 0, m, &cBinop_4rBvr7Uc_sendMessage);
}

void Heavy_CircleStrings::cDelay_GWsX44wA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_GWsX44wA, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_cdkwasPa, 0, m, &cDelay_cdkwasPa_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_lpFoi13r, 0, m, &sTabread_lpFoi13r_sendMessage);
}

void Heavy_CircleStrings::cCast_LLQSv5U0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_GWsX44wA, 0, m, &cDelay_GWsX44wA_sendMessage);
}

void Heavy_CircleStrings::cSystem_QsoULHxF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_BIXZnmg1_sendMessage);
}

void Heavy_CircleStrings::cMsg_ZcejJIy1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_QsoULHxF_sendMessage);
}

void Heavy_CircleStrings::cCast_SJXx81kb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_loNtNfT3, 0, m, &cVar_loNtNfT3_sendMessage);
  cMsg_ZcejJIy1_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_4a2HeR3f, 0, m, &cTabhead_4a2HeR3f_sendMessage);
}

void Heavy_CircleStrings::cDelay_cdkwasPa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_cdkwasPa, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_lpFoi13r, 0, m, &sTabread_lpFoi13r_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_cdkwasPa, 0, m, &cDelay_cdkwasPa_sendMessage);
}

void Heavy_CircleStrings::cMsg_ckz66LTI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_4Zy7imgy, HV_BINOP_MAX, 1, m, &cBinop_4Zy7imgy_sendMessage);
}

void Heavy_CircleStrings::cBinop_gjO95SUi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_GWsX44wA, 2, m, &cDelay_GWsX44wA_sendMessage);
}

void Heavy_CircleStrings::cSystem_iVcBj2d4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_wm7JtPMK, HV_BINOP_SUBTRACT, 1, m, &cBinop_wm7JtPMK_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_cdkwasPa, 2, m, &cDelay_cdkwasPa_sendMessage);
}

void Heavy_CircleStrings::cVar_loNtNfT3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_5qKhvvY8_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::sTabread_lpFoi13r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_wm7JtPMK, HV_BINOP_SUBTRACT, 0, m, &cBinop_wm7JtPMK_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cMsg_pfaPnV1i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_GWsX44wA, 0, m, &cDelay_GWsX44wA_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_cdkwasPa, 0, m, &cDelay_cdkwasPa_sendMessage);
}

void Heavy_CircleStrings::cBinop_wm7JtPMK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_gjO95SUi_sendMessage);
}

void Heavy_CircleStrings::cVar_WR1HmUul_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 100.0f, 0, m, &cBinop_3yu34DfP_sendMessage);
}

void Heavy_CircleStrings::cBinop_hLqjjijD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_WoUl5Yx9, 0, m, &cPack_WoUl5Yx9_sendMessage);
}

void Heavy_CircleStrings::cPack_i0Fw54NV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_5WnsI5MA, 0, m, NULL);
}

void Heavy_CircleStrings::cVar_grbSjNXQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_bgOC2cQW_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_V9AclM2w_sendMessage);
}

void Heavy_CircleStrings::hTable_5CJjcOLl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ThGNXxTN_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_DHkTv6Pi, 2, m, &cDelay_DHkTv6Pi_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_PgvUywTr_sendMessage);
}

void Heavy_CircleStrings::cMsg_8YVWemzl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_P20QSp83_sendMessage);
}

void Heavy_CircleStrings::cSystem_P20QSp83_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_PJW0hS1Y_sendMessage);
}

void Heavy_CircleStrings::cMsg_6QqHrUGU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_jz3tGdki, 1, m, NULL);
}

void Heavy_CircleStrings::cMsg_8cj8AfBJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_5CJjcOLl, 0, m, &hTable_5CJjcOLl_sendMessage);
}

void Heavy_CircleStrings::cDelay_DHkTv6Pi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_DHkTv6Pi, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_cAPdStYy, 0, m, &cDelay_cAPdStYy_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_DHkTv6Pi, 0, m, &cDelay_DHkTv6Pi_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_jz3tGdki, 1, m, NULL);
}

void Heavy_CircleStrings::cSwitchcase_M5NWqRtK_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_6QqHrUGU_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_PJW0hS1Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 74.5234f, 0, m, &cBinop_mVivvAP5_sendMessage);
}

void Heavy_CircleStrings::cCast_PgvUywTr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_DHkTv6Pi, 0, m, &cDelay_DHkTv6Pi_sendMessage);
}

void Heavy_CircleStrings::cMsg_ThGNXxTN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_cAPdStYy, 2, m, &cDelay_cAPdStYy_sendMessage);
}

void Heavy_CircleStrings::cDelay_cAPdStYy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_cAPdStYy, m);
  cMsg_8cj8AfBJ_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_iiTUjhp9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_5CJjcOLl, 0, m, &hTable_5CJjcOLl_sendMessage);
}

void Heavy_CircleStrings::cBinop_mVivvAP5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_iiTUjhp9_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cVar_xo4XpkPP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_iA7e4URh, HV_BINOP_MULTIPLY, 0, m, &cBinop_iA7e4URh_sendMessage);
}

void Heavy_CircleStrings::cBinop_SOSLB9w9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_jXIZLaVa_sendMessage);
}

void Heavy_CircleStrings::cBinop_jXIZLaVa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_vUt3abmG_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_q9SGrCCg, m);
}

void Heavy_CircleStrings::cBinop_XtTMydPJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_iA7e4URh, HV_BINOP_MULTIPLY, 1, m, &cBinop_iA7e4URh_sendMessage);
}

void Heavy_CircleStrings::cBinop_iA7e4URh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_SOSLB9w9_sendMessage);
}

void Heavy_CircleStrings::cMsg_o6dkto4r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_XtTMydPJ_sendMessage);
}

void Heavy_CircleStrings::cMsg_5a5WVVoY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_E9EESRdV_sendMessage);
}

void Heavy_CircleStrings::cSystem_E9EESRdV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_o6dkto4r_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_vUt3abmG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_U6Cak3ak, m);
}

void Heavy_CircleStrings::cPack_ikjnkobH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_H36ceoic, 0, m, NULL);
}

void Heavy_CircleStrings::cBinop_1Q0fc1xd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_8W3wifGY_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_8UE68Q0Q_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_qQh6LlcC_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cMsg_8W3wifGY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_sJEcXIKJ, 0, m, &hTable_sJEcXIKJ_sendMessage);
}

void Heavy_CircleStrings::cBinop_90btGSnx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 58.6435f, 0, m, &cBinop_1Q0fc1xd_sendMessage);
}

void Heavy_CircleStrings::cMsg_SMf3xEQ5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_WBu661zv_sendMessage);
}

void Heavy_CircleStrings::cSystem_WBu661zv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_90btGSnx_sendMessage);
}

void Heavy_CircleStrings::cMsg_CQJYYjjP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_sJEcXIKJ, 0, m, &hTable_sJEcXIKJ_sendMessage);
}

void Heavy_CircleStrings::cMsg_KV1fbE36_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_j8wxsOsu, 2, m, &cDelay_j8wxsOsu_sendMessage);
}

void Heavy_CircleStrings::cDelay_j8wxsOsu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_j8wxsOsu, m);
  cMsg_CQJYYjjP_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_pihpntGc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_qRRLSX7s, 0, m, &cDelay_qRRLSX7s_sendMessage);
}

void Heavy_CircleStrings::cMsg_qQh6LlcC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_VY1RJkTf, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_qRRLSX7s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_qRRLSX7s, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_j8wxsOsu, 0, m, &cDelay_j8wxsOsu_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_qRRLSX7s, 0, m, &cDelay_qRRLSX7s_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_VY1RJkTf, 1, m, NULL);
}

void Heavy_CircleStrings::hTable_sJEcXIKJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_KV1fbE36_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_qRRLSX7s, 2, m, &cDelay_qRRLSX7s_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_pihpntGc_sendMessage);
}

void Heavy_CircleStrings::cBinop_0N43JE7z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_8EDJoabJ, HV_BINOP_MULTIPLY, 0, m, &cBinop_8EDJoabJ_sendMessage);
}

void Heavy_CircleStrings::cMsg_FS4owC4a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_kwUSvw2u_sendMessage);
}

void Heavy_CircleStrings::cSystem_kwUSvw2u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_0N43JE7z_sendMessage);
}

void Heavy_CircleStrings::cMsg_64xRwxyY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_7mt73e01_sendMessage);
}

void Heavy_CircleStrings::cCast_7RNeH53b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_jwDOOfEW, 0, m, &cDelay_jwDOOfEW_sendMessage);
}

void Heavy_CircleStrings::cSystem_7mt73e01_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_yXJmAi9R, HV_BINOP_SUBTRACT, 1, m, &cBinop_yXJmAi9R_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_FW9oIWzr, 2, m, &cDelay_FW9oIWzr_sendMessage);
}

void Heavy_CircleStrings::cBinop_8EDJoabJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_zaKDLKho, HV_BINOP_MAX, 0, m, &cBinop_zaKDLKho_sendMessage);
}

void Heavy_CircleStrings::cVar_Blp9Dv7H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_64xRwxyY_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_FW9oIWzr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_FW9oIWzr, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_P9dCtjVF, 0, m, &sTabread_P9dCtjVF_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_FW9oIWzr, 0, m, &cDelay_FW9oIWzr_sendMessage);
}

void Heavy_CircleStrings::cTabhead_LfgILtky_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_eYfmPTZr, HV_BINOP_SUBTRACT, 0, m, &cBinop_eYfmPTZr_sendMessage);
}

void Heavy_CircleStrings::sTabread_P9dCtjVF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_yXJmAi9R, HV_BINOP_SUBTRACT, 0, m, &cBinop_yXJmAi9R_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cMsg_Ppd5goO8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_zaKDLKho, HV_BINOP_MAX, 1, m, &cBinop_zaKDLKho_sendMessage);
}

void Heavy_CircleStrings::cBinop_WWTSImWG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_jwDOOfEW, 2, m, &cDelay_jwDOOfEW_sendMessage);
}

void Heavy_CircleStrings::cBinop_eYfmPTZr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_iNvifLt4_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_P9dCtjVF, 0, m, &sTabread_P9dCtjVF_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_7RNeH53b_sendMessage);
}

void Heavy_CircleStrings::cMsg_iNvifLt4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_jwDOOfEW, 0, m, &cDelay_jwDOOfEW_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_FW9oIWzr, 0, m, &cDelay_FW9oIWzr_sendMessage);
}

void Heavy_CircleStrings::cDelay_jwDOOfEW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_jwDOOfEW, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_FW9oIWzr, 0, m, &cDelay_FW9oIWzr_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_P9dCtjVF, 0, m, &sTabread_P9dCtjVF_sendMessage);
}

void Heavy_CircleStrings::cBinop_yXJmAi9R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_WWTSImWG_sendMessage);
}

void Heavy_CircleStrings::cBinop_zaKDLKho_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_eYfmPTZr, HV_BINOP_SUBTRACT, 1, m, &cBinop_eYfmPTZr_sendMessage);
}

void Heavy_CircleStrings::cCast_znEJCKP6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Blp9Dv7H, 0, m, &cVar_Blp9Dv7H_sendMessage);
  cMsg_FS4owC4a_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_LfgILtky, 0, m, &cTabhead_LfgILtky_sendMessage);
}

void Heavy_CircleStrings::cVar_1HRfmt7H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_vxyreL0j_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_93bL39Gx, 0, m, &cIf_93bL39Gx_sendMessage);
}

void Heavy_CircleStrings::cVar_v003oDpw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 100.0f, 0, m, &cBinop_Tn42qLDm_sendMessage);
}

void Heavy_CircleStrings::cBinop_K5LR0nmw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_pZ4BZ6UO_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_wTx0vRDP, m);
}

void Heavy_CircleStrings::cBinop_X0noFfe2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_K5LR0nmw_sendMessage);
}

void Heavy_CircleStrings::cBinop_C95KwuAg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_X0noFfe2_sendMessage);
}

void Heavy_CircleStrings::cBinop_IQg9xqrX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_C95KwuAg, HV_BINOP_MULTIPLY, 1, m, &cBinop_C95KwuAg_sendMessage);
}

void Heavy_CircleStrings::cSystem_L70vIPrx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_hAc6aAxe_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_SeWjqHEN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_L70vIPrx_sendMessage);
}

void Heavy_CircleStrings::cMsg_hAc6aAxe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_IQg9xqrX_sendMessage);
}

void Heavy_CircleStrings::cVar_6y7ZfPLz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_C95KwuAg, HV_BINOP_MULTIPLY, 0, m, &cBinop_C95KwuAg_sendMessage);
}

void Heavy_CircleStrings::cBinop_pZ4BZ6UO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_Vl79vFoh, m);
}

void Heavy_CircleStrings::cIf_93bL39Gx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_Pje2F57r_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cVar_onMessage(_c, &Context(_c)->cVar_CBgxWohu, 0, m, &cVar_CBgxWohu_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_vxyreL0j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_93bL39Gx, 1, m, &cIf_93bL39Gx_sendMessage);
}

void Heavy_CircleStrings::cMsg_99XjTham_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSend_reSHTbtE_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cVar_TZe0Xq0A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_99XjTham_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_8oPoycfA_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_b6xvQooS_sendMessage);
}

void Heavy_CircleStrings::cBinop_3Y39AZ0e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_qzGAhwZb, 0, m, &cPack_qzGAhwZb_sendMessage);
}

void Heavy_CircleStrings::cBinop_53DZ8J6A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_TPvyPlNn_sendMessage);
}

void Heavy_CircleStrings::cCast_8oPoycfA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_ui0jxnme_sendMessage);
}

void Heavy_CircleStrings::cMsg_RoYOqO1a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_qzGAhwZb, 0, m, &cPack_qzGAhwZb_sendMessage);
}

void Heavy_CircleStrings::cBinop_TPvyPlNn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_3Y39AZ0e, HV_BINOP_POW, 1, m, &cBinop_3Y39AZ0e_sendMessage);
  cMsg_isE7xVCj_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_Uy5A0Auq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_53DZ8J6A_sendMessage);
}

void Heavy_CircleStrings::cCast_b6xvQooS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_l1V304Fe, 0, m, &cIf_l1V304Fe_sendMessage);
}

void Heavy_CircleStrings::cMsg_isE7xVCj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_3Y39AZ0e, HV_BINOP_POW, 0, m, &cBinop_3Y39AZ0e_sendMessage);
}

void Heavy_CircleStrings::cIf_l1V304Fe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_RoYOqO1a_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_Uy5A0Auq_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_ui0jxnme_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_l1V304Fe, 1, m, &cIf_l1V304Fe_sendMessage);
}

void Heavy_CircleStrings::cVar_M14zQcnZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_xdcJpDxs_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cPack_qzGAhwZb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_7GaOmHfc, 0, m, NULL);
}

void Heavy_CircleStrings::cSend_reSHTbtE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_i0dzePDj_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_xdcJpDxs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_leJv0l1q_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cReceive_wsW31huh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_12dR74WD_sendMessage);
}

void Heavy_CircleStrings::cReceive_zLyeXm6k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_N688tfT5_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_Nx51nojH, 0, m, &cVar_Nx51nojH_sendMessage);
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

int Heavy_CircleStrings::process(float **inputBuffers, float **outputBuffers, int n) {
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
    __hv_line_f(&sLine_0dsQpGnI, VOf(Bf0));
    __hv_varread_i(&sVari_Pl0G6DD1, VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 16807, 16807, 16807, 16807, 16807, 16807, 16807, 16807);
    __hv_mul_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_varwrite_i(&sVari_Pl0G6DD1, VIi(Bi1));
    __hv_cast_if(VIi(Bi1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf2), 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f);
    __hv_mul_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_tabread_f(&sTabread_1tQpuqYU, VOf(Bf1));
    __hv_varread_f(&sVarf_ysw4IKAR, VOf(Bf3));
    __hv_mul_f(VIf(Bf1), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_NbRmEjXa, VOf(Bf1));
    __hv_rpole_f(&sRPole_nZHNIorZ, VIf(Bf3), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_09UxVico, VOf(Bf3));
    __hv_mul_f(VIf(Bf1), VIf(Bf3), VOf(Bf3));
    __hv_fma_f(VIf(Bf0), VIf(Bf2), VIf(Bf3), VOf(Bf2));
    __hv_tabwrite_f(&sTabwrite_AS9KWVri, VIf(Bf2));
    __hv_line_f(&sLine_N1ASNuL6, VOf(Bf2));
    __hv_varread_f(&sVarf_VpW71EE8, VOf(Bf0));
    __hv_mul_f(VIf(Bf2), VIf(Bf0), VOf(Bf0));
    __hv_mul_f(VIf(Bf3), VIf(Bf0), VOf(Bf0));
    __hv_line_f(&sLine_RXQA5BSx, VOf(Bf3));
    __hv_mul_f(VIf(Bf0), VIf(Bf3), VOf(Bf3));
    __hv_line_f(&sLine_5DPgijNj, VOf(Bf2));
    __hv_mul_f(VIf(Bf0), VIf(Bf2), VOf(Bf2));
    __hv_line_f(&sLine_HKrXiEjG, VOf(Bf0));
    __hv_phasor_k_f(&sPhasor_PjKkcAXP, VOf(Bf0));
    __hv_var_k_f(VOf(Bf1), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_abs_f(VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf0), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf1), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_mul_f(VIf(Bf1), VIf(Bf1), VOf(Bf0));
    __hv_mul_f(VIf(Bf1), VIf(Bf0), VOf(Bf4));
    __hv_mul_f(VIf(Bf4), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf5), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf6), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf4), VIf(Bf6), VIf(Bf1), VOf(Bf1));
    __hv_fma_f(VIf(Bf0), VIf(Bf5), VIf(Bf1), VOf(Bf1));
    __hv_line_f(&sLine_8g7E35J1, VOf(Bf1));
    __hv_line_f(&sLine_ed4dzP1v, VOf(Bf1));
    __hv_varread_i(&sVari_VvwsZqxY, VOi(Bi1));
    __hv_var_k_i(VOi(Bi0), 16807, 16807, 16807, 16807, 16807, 16807, 16807, 16807);
    __hv_mul_i(VIi(Bi1), VIi(Bi0), VOi(Bi0));
    __hv_cast_if(VIi(Bi0), VOf(Bf5));
    __hv_var_k_f(VOf(Bf0), 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f);
    __hv_mul_f(VIf(Bf5), VIf(Bf0), VOf(Bf0));
    __hv_varwrite_i(&sVari_VvwsZqxY, VIi(Bi0));
    __hv_tabread_f(&sTabread_AYMBNEnS, VOf(Bf5));
    __hv_varread_f(&sVarf_Hz4wWSlG, VOf(Bf6));
    __hv_mul_f(VIf(Bf5), VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_8Hv6YLUP, VOf(Bf5));
    __hv_rpole_f(&sRPole_9J5euM6E, VIf(Bf6), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_NlFqYNsI, VOf(Bf6));
    __hv_mul_f(VIf(Bf5), VIf(Bf6), VOf(Bf6));
    __hv_fma_f(VIf(Bf1), VIf(Bf0), VIf(Bf6), VOf(Bf0));
    __hv_tabwrite_f(&sTabwrite_x3Kglaaa, VIf(Bf0));
    __hv_line_f(&sLine_hjd1HFtZ, VOf(Bf0));
    __hv_varread_f(&sVarf_glQhg9bG, VOf(Bf1));
    __hv_mul_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_mul_f(VIf(Bf6), VIf(Bf1), VOf(Bf1));
    __hv_line_f(&sLine_a5hEGEQa, VOf(Bf6));
    __hv_mul_f(VIf(Bf1), VIf(Bf6), VOf(Bf6));
    __hv_line_f(&sLine_cC3ArdK1, VOf(Bf0));
    __hv_mul_f(VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_phasor_k_f(&sPhasor_1JMoGwnu, VOf(Bf1));
    __hv_var_k_f(VOf(Bf5), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf1), VIf(Bf5), VOf(Bf5));
    __hv_abs_f(VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf1), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf5), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf5), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf1), VIf(Bf5), VOf(Bf5));
    __hv_mul_f(VIf(Bf5), VIf(Bf5), VOf(Bf1));
    __hv_mul_f(VIf(Bf5), VIf(Bf1), VOf(Bf4));
    __hv_mul_f(VIf(Bf4), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf7), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf8), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf4), VIf(Bf8), VIf(Bf5), VOf(Bf5));
    __hv_fma_f(VIf(Bf1), VIf(Bf7), VIf(Bf5), VOf(Bf5));
    __hv_add_f(VIf(Bf2), VIf(Bf0), VOf(Bf0));
    __hv_tabread_f(&sTabread_mUArOlqK, VOf(Bf2));
    __hv_varread_f(&sVarf_ZnRuqqxT, VOf(Bf5));
    __hv_mul_f(VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_LnaqLmTh, VOf(Bf2));
    __hv_rpole_f(&sRPole_O8wFlPH1, VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_0vJoTVKz, VOf(Bf5));
    __hv_mul_f(VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_line_f(&sLine_GG7pXXXs, VOf(Bf2));
    __hv_varread_i(&sVari_0hXYUTZf, VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 16807, 16807, 16807, 16807, 16807, 16807, 16807, 16807);
    __hv_mul_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_cast_if(VIi(Bi1), VOf(Bf7));
    __hv_var_k_f(VOf(Bf1), 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f);
    __hv_mul_f(VIf(Bf7), VIf(Bf1), VOf(Bf1));
    __hv_varwrite_i(&sVari_0hXYUTZf, VIi(Bi1));
    __hv_fma_f(VIf(Bf2), VIf(Bf1), VIf(Bf5), VOf(Bf1));
    __hv_tabwrite_f(&sTabwrite_P8WT8aZo, VIf(Bf1));
    __hv_line_f(&sLine_x3o5SAqa, VOf(Bf1));
    __hv_varread_f(&sVarf_GClz2FXh, VOf(Bf2));
    __hv_mul_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_mul_f(VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_line_f(&sLine_PLMvWoaK, VOf(Bf5));
    __hv_mul_f(VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_line_f(&sLine_qkVQcUvG, VOf(Bf1));
    __hv_mul_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_phasor_k_f(&sPhasor_eqlxABbB, VOf(Bf2));
    __hv_var_k_f(VOf(Bf7), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf2), VIf(Bf7), VOf(Bf7));
    __hv_abs_f(VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf2), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf7), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf7), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf2), VIf(Bf7), VOf(Bf7));
    __hv_mul_f(VIf(Bf7), VIf(Bf7), VOf(Bf2));
    __hv_mul_f(VIf(Bf7), VIf(Bf2), VOf(Bf8));
    __hv_mul_f(VIf(Bf8), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf4), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf9), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf8), VIf(Bf9), VIf(Bf7), VOf(Bf7));
    __hv_fma_f(VIf(Bf2), VIf(Bf4), VIf(Bf7), VOf(Bf7));
    __hv_line_f(&sLine_8GBw3dsw, VOf(Bf7));
    __hv_add_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_phasor_k_f(&sPhasor_OJjQyx7F, VOf(Bf0));
    __hv_var_k_f(VOf(Bf7), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf0), VIf(Bf7), VOf(Bf7));
    __hv_abs_f(VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf0), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf7), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf7), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf0), VIf(Bf7), VOf(Bf7));
    __hv_mul_f(VIf(Bf7), VIf(Bf7), VOf(Bf0));
    __hv_mul_f(VIf(Bf7), VIf(Bf0), VOf(Bf4));
    __hv_mul_f(VIf(Bf4), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf2), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf9), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf4), VIf(Bf9), VIf(Bf7), VOf(Bf7));
    __hv_fma_f(VIf(Bf0), VIf(Bf2), VIf(Bf7), VOf(Bf7));
    __hv_tabread_f(&sTabread_kZm1Pjc9, VOf(Bf7));
    __hv_varread_f(&sVarf_CAuXHeFu, VOf(Bf2));
    __hv_mul_f(VIf(Bf7), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_ASCMEqPZ, VOf(Bf7));
    __hv_rpole_f(&sRPole_mAE5DoaE, VIf(Bf2), VIf(Bf7), VOf(Bf7));
    __hv_varread_f(&sVarf_RPjk0Dgz, VOf(Bf2));
    __hv_mul_f(VIf(Bf7), VIf(Bf2), VOf(Bf2));
    __hv_line_f(&sLine_SSzBTeHO, VOf(Bf7));
    __hv_varread_i(&sVari_bCTGNkeS, VOi(Bi1));
    __hv_var_k_i(VOi(Bi0), 16807, 16807, 16807, 16807, 16807, 16807, 16807, 16807);
    __hv_mul_i(VIi(Bi1), VIi(Bi0), VOi(Bi0));
    __hv_varwrite_i(&sVari_bCTGNkeS, VIi(Bi0));
    __hv_cast_if(VIi(Bi0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf9), 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f);
    __hv_mul_f(VIf(Bf0), VIf(Bf9), VOf(Bf9));
    __hv_fma_f(VIf(Bf7), VIf(Bf9), VIf(Bf2), VOf(Bf9));
    __hv_tabwrite_f(&sTabwrite_hSX1EpJ3, VIf(Bf9));
    __hv_line_f(&sLine_0cjuLgBk, VOf(Bf9));
    __hv_varread_f(&sVarf_RovwkIw2, VOf(Bf7));
    __hv_mul_f(VIf(Bf9), VIf(Bf7), VOf(Bf7));
    __hv_mul_f(VIf(Bf2), VIf(Bf7), VOf(Bf7));
    __hv_line_f(&sLine_i3VseCms, VOf(Bf2));
    __hv_mul_f(VIf(Bf7), VIf(Bf2), VOf(Bf2));
    __hv_line_f(&sLine_hq14cxp6, VOf(Bf9));
    __hv_mul_f(VIf(Bf7), VIf(Bf9), VOf(Bf9));
    __hv_line_f(&sLine_MfDGS6MN, VOf(Bf7));
    __hv_add_f(VIf(Bf1), VIf(Bf9), VOf(Bf9));
    __hv_add_f(VIf(Bf3), VIf(Bf6), VOf(Bf6));
    __hv_add_f(VIf(Bf6), VIf(Bf5), VOf(Bf5));
    __hv_add_f(VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_line_f(&sLine_1nmIr3hl, VOf(Bf5));
    __hv_mul_f(VIf(Bf2), VIf(Bf5), VOf(Bf2));
    __hv_mul_f(VIf(Bf9), VIf(Bf5), VOf(Bf5));
    __hv_tabread_f(&sTabread_OhUPHtZ3, VOf(Bf9));
    __hv_varread_f(&sVarf_pYiV6Nwb, VOf(Bf6));
    __hv_mul_f(VIf(Bf9), VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_C0bo0SDW, VOf(Bf9));
    __hv_rpole_f(&sRPole_Ihd8rU1e, VIf(Bf6), VIf(Bf9), VOf(Bf9));
    __hv_varread_f(&sVarf_r00vRbTY, VOf(Bf6));
    __hv_mul_f(VIf(Bf9), VIf(Bf6), VOf(Bf6));
    __hv_line_f(&sLine_mkZIaKBk, VOf(Bf9));
    __hv_varread_i(&sVari_kCCmHSeE, VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 16807, 16807, 16807, 16807, 16807, 16807, 16807, 16807);
    __hv_mul_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_varwrite_i(&sVari_kCCmHSeE, VIi(Bi1));
    __hv_cast_if(VIi(Bi1), VOf(Bf3));
    __hv_var_k_f(VOf(Bf1), 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f);
    __hv_mul_f(VIf(Bf3), VIf(Bf1), VOf(Bf1));
    __hv_fma_f(VIf(Bf9), VIf(Bf1), VIf(Bf6), VOf(Bf1));
    __hv_tabwrite_f(&sTabwrite_pU5PGFkG, VIf(Bf1));
    __hv_line_f(&sLine_gvPUKwRU, VOf(Bf1));
    __hv_mul_f(VIf(Bf6), VIf(Bf1), VOf(Bf1));
    __hv_line_f(&sLine_2qlKKPT3, VOf(Bf6));
    __hv_mul_f(VIf(Bf1), VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_iTQ4HjJE, VOf(Bf1));
    __hv_rpole_f(&sRPole_3htiXeUO, VIf(Bf6), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf6), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_del1_f(&sDel1_NbBqDxzq, VIf(Bf1), VOf(Bf9));
    __hv_mul_f(VIf(Bf9), VIf(Bf6), VOf(Bf6));
    __hv_sub_f(VIf(Bf1), VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_5VoUMfdc, VOf(Bf1));
    __hv_mul_f(VIf(Bf6), VIf(Bf1), VOf(Bf1));
    __hv_line_f(&sLine_wurxiXrM, VOf(Bf6));
    __hv_mul_f(VIf(Bf1), VIf(Bf6), VOf(Bf6));
    __hv_add_f(VIf(Bf5), VIf(Bf6), VOf(Bf5));
    __hv_add_f(VIf(Bf2), VIf(Bf6), VOf(Bf1));
    __hv_line_f(&sLine_b0UNseK8, VOf(Bf9));
    __hv_mul_f(VIf(Bf1), VIf(Bf9), VOf(Bf1));
    __hv_mul_f(VIf(Bf5), VIf(Bf9), VOf(Bf9));
    __hv_add_f(VIf(Bf2), VIf(Bf6), VOf(Bf6));
    __hv_line_f(&sLine_7GaOmHfc, VOf(Bf2));
    __hv_mul_f(VIf(Bf6), VIf(Bf2), VOf(Bf2));
    __hv_tabread_f(&sTabread_b9nxvE9s, VOf(Bf6));
    __hv_varread_f(&sVarf_wTx0vRDP, VOf(Bf5));
    __hv_mul_f(VIf(Bf6), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_Vl79vFoh, VOf(Bf3));
    __hv_rpole_f(&sRPole_7AyEZaBn, VIf(Bf5), VIf(Bf3), VOf(Bf3));
    __hv_sub_f(VIf(Bf3), VIf(Bf6), VOf(Bf3));
    __hv_line_f(&sLine_XmeLOi76, VOf(Bf5));
    __hv_fma_f(VIf(Bf3), VIf(Bf5), VIf(Bf6), VOf(Bf6));
    __hv_line_f(&sLine_5WnsI5MA, VOf(Bf3));
    __hv_tabread_f(&sTabread_JEHCJVUT, VOf(Bf7));
    __hv_sub_f(VIf(Bf2), VIf(Bf7), VOf(Bf0));
    __hv_tabwrite_f(&sTabwrite_cL0rvWDe, VIf(Bf0));
    __hv_add_f(VIf(Bf2), VIf(Bf7), VOf(Bf7));
    __hv_tabread_f(&sTabread_Ek55gQhE, VOf(Bf0));
    __hv_add_f(VIf(Bf7), VIf(Bf0), VOf(Bf4));
    __hv_tabread_f(&sTabread_by9PCdOX, VOf(Bf8));
    __hv_add_f(VIf(Bf4), VIf(Bf8), VOf(Bf10));
    __hv_tabread_f(&sTabread_VKRaAijF, VOf(Bf11));
    __hv_add_f(VIf(Bf10), VIf(Bf11), VOf(Bf12));
    __hv_tabread_f(&sTabread_zRa3O3dH, VOf(Bf13));
    __hv_sub_f(VIf(Bf12), VIf(Bf13), VOf(Bf14));
    __hv_tabwrite_f(&sTabwrite_Y52mdAky, VIf(Bf14));
    __hv_add_f(VIf(Bf12), VIf(Bf13), VOf(Bf13));
    __hv_sub_f(VIf(Bf4), VIf(Bf8), VOf(Bf8));
    __hv_tabwrite_f(&sTabwrite_DuQ4Co8P, VIf(Bf8));
    __hv_sub_f(VIf(Bf10), VIf(Bf11), VOf(Bf11));
    __hv_tabwrite_f(&sTabwrite_Xj1WGi8h, VIf(Bf11));
    __hv_sub_f(VIf(Bf7), VIf(Bf0), VOf(Bf0));
    __hv_tabwrite_f(&sTabwrite_1KVHmk1a, VIf(Bf0));
    __hv_tabread_f(&sTabread_RkVpHXtZ, VOf(Bf0));
    __hv_tabwrite_f(&sTabwrite_htQtLxlX, VIf(Bf2));
    __hv_fma_f(VIf(Bf6), VIf(Bf3), VIf(Bf13), VOf(Bf13));
    __hv_line_f(&sLine_H36ceoic, VOf(Bf6));
    __hv_mul_f(VIf(Bf13), VIf(Bf6), VOf(Bf7));
    __hv_tabread_f(&sTabread_lpFoi13r, VOf(Bf11));
    __hv_varread_f(&sVarf_lF5sp862, VOf(Bf10));
    __hv_mul_f(VIf(Bf11), VIf(Bf10), VOf(Bf10));
    __hv_varread_f(&sVarf_9OHNYlIA, VOf(Bf8));
    __hv_rpole_f(&sRPole_GBRJwljZ, VIf(Bf10), VIf(Bf8), VOf(Bf8));
    __hv_sub_f(VIf(Bf8), VIf(Bf11), VOf(Bf8));
    __hv_fma_f(VIf(Bf8), VIf(Bf5), VIf(Bf11), VOf(Bf11));
    __hv_mul_f(VIf(Bf11), VIf(Bf3), VOf(Bf11));
    __hv_mul_f(VIf(Bf11), VIf(Bf6), VOf(Bf8));
    __hv_tabread_f(&sTabread_P9dCtjVF, VOf(Bf10));
    __hv_varread_f(&sVarf_860e0l7y, VOf(Bf4));
    __hv_mul_f(VIf(Bf10), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_WG3C307I, VOf(Bf12));
    __hv_rpole_f(&sRPole_hwVyjtZq, VIf(Bf4), VIf(Bf12), VOf(Bf12));
    __hv_sub_f(VIf(Bf12), VIf(Bf10), VOf(Bf12));
    __hv_fma_f(VIf(Bf12), VIf(Bf5), VIf(Bf10), VOf(Bf10));
    __hv_fma_f(VIf(Bf10), VIf(Bf3), VIf(Bf0), VOf(Bf0));
    __hv_sub_f(VIf(Bf13), VIf(Bf0), VOf(Bf10));
    __hv_tabread_f(&sTabread_K6hA9yka, VOf(Bf12));
    __hv_varread_f(&sVarf_q9SGrCCg, VOf(Bf4));
    __hv_mul_f(VIf(Bf12), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_U6Cak3ak, VOf(Bf14));
    __hv_rpole_f(&sRPole_DKKp7zqJ, VIf(Bf4), VIf(Bf14), VOf(Bf14));
    __hv_sub_f(VIf(Bf14), VIf(Bf12), VOf(Bf14));
    __hv_fma_f(VIf(Bf14), VIf(Bf5), VIf(Bf12), VOf(Bf12));
    __hv_mul_f(VIf(Bf12), VIf(Bf3), VOf(Bf3));
    __hv_sub_f(VIf(Bf11), VIf(Bf3), VOf(Bf12));
    __hv_add_f(VIf(Bf10), VIf(Bf12), VOf(Bf5));
    __hv_tabwrite_f(&sTabwrite_YIMyWBrt, VIf(Bf5));
    __hv_sub_f(VIf(Bf10), VIf(Bf12), VOf(Bf12));
    __hv_tabwrite_f(&sTabwrite_5auDYJV3, VIf(Bf12));
    __hv_add_f(VIf(Bf13), VIf(Bf0), VOf(Bf13));
    __hv_add_f(VIf(Bf11), VIf(Bf3), VOf(Bf11));
    __hv_sub_f(VIf(Bf13), VIf(Bf11), VOf(Bf12));
    __hv_tabwrite_f(&sTabwrite_jz3tGdki, VIf(Bf12));
    __hv_mul_f(VIf(Bf3), VIf(Bf6), VOf(Bf3));
    __hv_mul_f(VIf(Bf0), VIf(Bf6), VOf(Bf6));
    __hv_add_f(VIf(Bf13), VIf(Bf11), VOf(Bf11));
    __hv_tabwrite_f(&sTabwrite_VY1RJkTf, VIf(Bf11));
    __hv_line_f(&sLine_R8giMv5K, VOf(Bf3));
    __hv_mul_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf8), 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f);
    __hv_mul_f(VIf(Bf3), VIf(Bf8), VOf(Bf8));
    __hv_tabwrite_f(&sTabwrite_jaHDe3AO, VIf(Bf8));
    __hv_line_f(&sLine_jNEN2L4y, VOf(Bf3));
    __hv_phasor_f(&sPhasor_xuydrICF, VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf11), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf3), VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf13), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf11), VIf(Bf13), VOf(Bf13));
    __hv_floor_f(VIf(Bf13), VOf(Bf11));
    __hv_sub_f(VIf(Bf13), VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf13), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf11), VIf(Bf13), VOf(Bf13));
    __hv_abs_f(VIf(Bf13), VOf(Bf13));
    __hv_var_k_f(VOf(Bf11), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf13), VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf13), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf11), VIf(Bf13), VOf(Bf13));
    __hv_mul_f(VIf(Bf13), VIf(Bf13), VOf(Bf11));
    __hv_mul_f(VIf(Bf13), VIf(Bf11), VOf(Bf0));
    __hv_mul_f(VIf(Bf0), VIf(Bf11), VOf(Bf12));
    __hv_mul_f(VIf(Bf12), VIf(Bf11), VOf(Bf10));
    __hv_mul_f(VIf(Bf10), VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf5), 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f);
    __hv_var_k_f(VOf(Bf14), 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f);
    __hv_var_k_f(VOf(Bf4), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf0), VIf(Bf4), VOf(Bf4));
    __hv_sub_f(VIf(Bf13), VIf(Bf4), VOf(Bf4));
    __hv_fma_f(VIf(Bf12), VIf(Bf14), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf14), 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f);
    __hv_mul_f(VIf(Bf10), VIf(Bf14), VOf(Bf14));
    __hv_sub_f(VIf(Bf4), VIf(Bf14), VOf(Bf14));
    __hv_fma_f(VIf(Bf11), VIf(Bf5), VIf(Bf14), VOf(Bf14));
    __hv_line_f(&sLine_Zjs9FqzT, VOf(Bf5));
    __hv_line_f(&sLine_g7UWYirp, VOf(Bf11));
    __hv_fma_f(VIf(Bf3), VIf(Bf5), VIf(Bf11), VOf(Bf4));
    __hv_tabhead_f(&sTabhead_MJNcxjkw, VOf(Bf10));
    __hv_var_k_f_r(VOf(Bf12), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf10), VIf(Bf12), VOf(Bf12));
    __hv_varread_f(&sVarf_uaxbfDFT, VOf(Bf10));
    __hv_mul_f(VIf(Bf4), VIf(Bf10), VOf(Bf10));
    __hv_varread_f(&sVarf_a8pHdRg6, VOf(Bf4));
    __hv_min_f(VIf(Bf10), VIf(Bf4), VOf(Bf4));
    __hv_zero_f(VOf(Bf10));
    __hv_max_f(VIf(Bf4), VIf(Bf10), VOf(Bf10));
    __hv_sub_f(VIf(Bf12), VIf(Bf10), VOf(Bf10));
    __hv_floor_f(VIf(Bf10), VOf(Bf12));
    __hv_varread_f(&sVarf_SjQDEIQP, VOf(Bf4));
    __hv_zero_f(VOf(Bf13));
    __hv_lt_f(VIf(Bf12), VIf(Bf13), VOf(Bf13));
    __hv_and_f(VIf(Bf4), VIf(Bf13), VOf(Bf13));
    __hv_add_f(VIf(Bf12), VIf(Bf13), VOf(Bf13));
    __hv_cast_fi(VIf(Bf13), VOi(Bi1));
    __hv_var_k_i(VOi(Bi0), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi1), VIi(Bi0), VOi(Bi0));
    __hv_tabread_if(&sTabread_DAvt7Xs9, VIi(Bi0), VOf(Bf13));
    __hv_tabread_if(&sTabread_uBVkCRiQ, VIi(Bi1), VOf(Bf4));
    __hv_sub_f(VIf(Bf13), VIf(Bf4), VOf(Bf13));
    __hv_sub_f(VIf(Bf10), VIf(Bf12), VOf(Bf12));
    __hv_fma_f(VIf(Bf13), VIf(Bf12), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf12), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_add_f(VIf(Bf3), VIf(Bf12), VOf(Bf12));
    __hv_floor_f(VIf(Bf12), VOf(Bf3));
    __hv_sub_f(VIf(Bf12), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf12), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf3), VIf(Bf12), VOf(Bf12));
    __hv_var_k_f(VOf(Bf13), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf12), VIf(Bf13), VOf(Bf13));
    __hv_floor_f(VIf(Bf13), VOf(Bf12));
    __hv_sub_f(VIf(Bf13), VIf(Bf12), VOf(Bf12));
    __hv_var_k_f(VOf(Bf13), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf12), VIf(Bf13), VOf(Bf13));
    __hv_abs_f(VIf(Bf13), VOf(Bf13));
    __hv_var_k_f(VOf(Bf12), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf13), VIf(Bf12), VOf(Bf12));
    __hv_var_k_f(VOf(Bf13), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf12), VIf(Bf13), VOf(Bf13));
    __hv_mul_f(VIf(Bf13), VIf(Bf13), VOf(Bf12));
    __hv_mul_f(VIf(Bf13), VIf(Bf12), VOf(Bf10));
    __hv_mul_f(VIf(Bf10), VIf(Bf12), VOf(Bf0));
    __hv_mul_f(VIf(Bf0), VIf(Bf12), VOf(Bf15));
    __hv_mul_f(VIf(Bf15), VIf(Bf12), VOf(Bf12));
    __hv_var_k_f(VOf(Bf16), 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f);
    __hv_var_k_f(VOf(Bf17), 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f);
    __hv_var_k_f(VOf(Bf18), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf10), VIf(Bf18), VOf(Bf18));
    __hv_sub_f(VIf(Bf13), VIf(Bf18), VOf(Bf18));
    __hv_fma_f(VIf(Bf0), VIf(Bf17), VIf(Bf18), VOf(Bf18));
    __hv_var_k_f(VOf(Bf17), 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f);
    __hv_mul_f(VIf(Bf15), VIf(Bf17), VOf(Bf17));
    __hv_sub_f(VIf(Bf18), VIf(Bf17), VOf(Bf17));
    __hv_fma_f(VIf(Bf12), VIf(Bf16), VIf(Bf17), VOf(Bf17));
    __hv_fma_f(VIf(Bf3), VIf(Bf5), VIf(Bf11), VOf(Bf11));
    __hv_tabhead_f(&sTabhead_P90BFdv5, VOf(Bf5));
    __hv_var_k_f_r(VOf(Bf3), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf5), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_NVI6Rosk, VOf(Bf5));
    __hv_mul_f(VIf(Bf11), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_p7m8FVpp, VOf(Bf11));
    __hv_min_f(VIf(Bf5), VIf(Bf11), VOf(Bf11));
    __hv_zero_f(VOf(Bf5));
    __hv_max_f(VIf(Bf11), VIf(Bf5), VOf(Bf5));
    __hv_sub_f(VIf(Bf3), VIf(Bf5), VOf(Bf5));
    __hv_floor_f(VIf(Bf5), VOf(Bf3));
    __hv_varread_f(&sVarf_PZMNAqEr, VOf(Bf11));
    __hv_zero_f(VOf(Bf16));
    __hv_lt_f(VIf(Bf3), VIf(Bf16), VOf(Bf16));
    __hv_and_f(VIf(Bf11), VIf(Bf16), VOf(Bf16));
    __hv_add_f(VIf(Bf3), VIf(Bf16), VOf(Bf16));
    __hv_cast_fi(VIf(Bf16), VOi(Bi1));
    __hv_var_k_i(VOi(Bi0), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi1), VIi(Bi0), VOi(Bi0));
    __hv_tabread_if(&sTabread_Y2FvOduF, VIi(Bi0), VOf(Bf16));
    __hv_tabread_if(&sTabread_xPOC5ef1, VIi(Bi1), VOf(Bf11));
    __hv_sub_f(VIf(Bf16), VIf(Bf11), VOf(Bf16));
    __hv_sub_f(VIf(Bf5), VIf(Bf3), VOf(Bf3));
    __hv_fma_f(VIf(Bf16), VIf(Bf3), VIf(Bf11), VOf(Bf11));
    __hv_mul_f(VIf(Bf17), VIf(Bf11), VOf(Bf11));
    __hv_fma_f(VIf(Bf14), VIf(Bf4), VIf(Bf11), VOf(Bf11));
    __hv_varread_f(&sVarf_cLYSr7VT, VOf(Bf4));
    __hv_tabhead_f(&sTabhead_GqodT2DX, VOf(Bf14));
    __hv_var_k_f_r(VOf(Bf17), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf14), VIf(Bf17), VOf(Bf17));
    __hv_varread_f(&sVarf_EdYNnOyL, VOf(Bf14));
    __hv_mul_f(VIf(Bf4), VIf(Bf14), VOf(Bf14));
    __hv_varread_f(&sVarf_rlBUEcPD, VOf(Bf4));
    __hv_min_f(VIf(Bf14), VIf(Bf4), VOf(Bf4));
    __hv_zero_f(VOf(Bf14));
    __hv_max_f(VIf(Bf4), VIf(Bf14), VOf(Bf14));
    __hv_sub_f(VIf(Bf17), VIf(Bf14), VOf(Bf14));
    __hv_floor_f(VIf(Bf14), VOf(Bf17));
    __hv_varread_f(&sVarf_IK0GYyj3, VOf(Bf4));
    __hv_zero_f(VOf(Bf3));
    __hv_lt_f(VIf(Bf17), VIf(Bf3), VOf(Bf3));
    __hv_and_f(VIf(Bf4), VIf(Bf3), VOf(Bf3));
    __hv_add_f(VIf(Bf17), VIf(Bf3), VOf(Bf3));
    __hv_cast_fi(VIf(Bf3), VOi(Bi1));
    __hv_var_k_i(VOi(Bi0), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi1), VIi(Bi0), VOi(Bi0));
    __hv_tabread_if(&sTabread_IfLLKxc9, VIi(Bi0), VOf(Bf3));
    __hv_tabread_if(&sTabread_XHTKk4op, VIi(Bi1), VOf(Bf4));
    __hv_sub_f(VIf(Bf3), VIf(Bf4), VOf(Bf3));
    __hv_sub_f(VIf(Bf14), VIf(Bf17), VOf(Bf17));
    __hv_fma_f(VIf(Bf3), VIf(Bf17), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_tFkk8usR, VOf(Bf17));
    __hv_rpole_f(&sRPole_4FUA4WJu, VIf(Bf4), VIf(Bf17), VOf(Bf17));
    __hv_var_k_f(VOf(Bf4), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_del1_f(&sDel1_hNYaEDYq, VIf(Bf17), VOf(Bf3));
    __hv_mul_f(VIf(Bf3), VIf(Bf4), VOf(Bf4));
    __hv_sub_f(VIf(Bf17), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_bialIhQG, VOf(Bf17));
    __hv_mul_f(VIf(Bf4), VIf(Bf17), VOf(Bf17));
    __hv_varread_f(&sVarf_FiECT7xg, VOf(Bf4));
    __hv_mul_f(VIf(Bf17), VIf(Bf4), VOf(Bf4));
    __hv_add_f(VIf(Bf11), VIf(Bf4), VOf(Bf17));
    __hv_line_f(&sLine_ZCy7aZjx, VOf(Bf3));
    __hv_varread_f(&sVarf_vRSPZDVu, VOf(Bf14));
    __hv_mul_f(VIf(Bf4), VIf(Bf14), VOf(Bf14));
    __hv_varread_f(&sVarf_wxEDt9Ux, VOf(Bf4));
    __hv_rpole_f(&sRPole_24AXcYGn, VIf(Bf14), VIf(Bf4), VOf(Bf4));
    __hv_fma_f(VIf(Bf11), VIf(Bf3), VIf(Bf4), VOf(Bf4));
    __hv_tabwrite_f(&sTabwrite_BK4qaso8, VIf(Bf4));
    __hv_add_f(VIf(Bf17), VIf(Bf8), VOf(Bf8));
    __hv_varread_f(&sVarf_skOQJWLV, VOf(Bf17));
    __hv_varread_f(&sVarf_gc3U5FB3, VOf(Bf4));
    __hv_mul_f(VIf(Bf17), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf17), 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f);
    __hv_max_f(VIf(Bf4), VIf(Bf17), VOf(Bf17));
    __hv_varread_f(&sVarf_u3MxHD1B, VOf(Bf4));
    __hv_min_f(VIf(Bf17), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_try9M9ry, VOf(Bf3));
    __hv_mul_f(VIf(Bf4), VIf(Bf3), VOf(Bf3));
    __hv_mul_f(VIf(Bf8), VIf(Bf3), VOf(Bf8));
    __hv_varread_f(&sVarf_LjOibelc, VOf(Bf4));
    __hv_mul_f(VIf(Bf8), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf8), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_sub_f(VIf(Bf3), VIf(Bf8), VOf(Bf3));
    __hv_cos_f(VIf(Bf17), VOf(Bf17));
    __hv_mul_f(VIf(Bf3), VIf(Bf17), VOf(Bf11));
    __hv_mul_f(VIf(Bf17), VIf(Bf17), VOf(Bf17));
    __hv_sub_f(VIf(Bf8), VIf(Bf17), VOf(Bf17));
    __hv_zero_f(VOf(Bf8));
    __hv_gt_f(VIf(Bf17), VIf(Bf8), VOf(Bf8));
    __hv_sqrt_f(VIf(Bf17), VOf(Bf17));
    __hv_and_f(VIf(Bf8), VIf(Bf17), VOf(Bf17));
    __hv_mul_f(VIf(Bf3), VIf(Bf17), VOf(Bf17));
    __hv_cpole_f(&sCPole_iqvBhV3z, VIf(Bf4), VIf(ZERO), VIf(Bf11), VIf(Bf17), VOf(Bf17), VOf(Bf11));
    __hv_varread_f(&sVarf_ShZv1Lle, VOf(Bf11));
    __hv_mul_f(VIf(Bf17), VIf(Bf11), VOf(Bf11));
    __hv_varread_f(&sVarf_bsg0dBcj, VOf(Bf17));
    __hv_rpole_f(&sRPole_OmZlCCDo, VIf(Bf11), VIf(Bf17), VOf(Bf17));
    __hv_varread_f(&sVarf_SYo7JBP8, VOf(Bf11));
    __hv_mul_f(VIf(Bf17), VIf(Bf11), VOf(Bf11));
    __hv_varread_f(&sVarf_aUz0qpbc, VOf(Bf17));
    __hv_rpole_f(&sRPole_nNEt7LWg, VIf(Bf11), VIf(Bf17), VOf(Bf17));
    __hv_varread_f(&sVarf_1xlzEFn0, VOf(Bf11));
    __hv_mul_f(VIf(Bf17), VIf(Bf11), VOf(Bf11));
    __hv_varread_f(&sVarf_M7lbaMq5, VOf(Bf17));
    __hv_rpole_f(&sRPole_vRGo39Wp, VIf(Bf11), VIf(Bf17), VOf(Bf17));
    __hv_tabread_f(&sTabread_WNNBKTF8, VOf(Bf11));
    __hv_varread_f(&sVarf_dd13PCu6, VOf(Bf4));
    __hv_mul_f(VIf(Bf11), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_rDMUqotd, VOf(Bf3));
    __hv_rpole_f(&sRPole_ttbo967F, VIf(Bf4), VIf(Bf3), VOf(Bf3));
    __hv_sub_f(VIf(Bf3), VIf(Bf11), VOf(Bf3));
    __hv_line_f(&sLine_ocji4mRy, VOf(Bf4));
    __hv_fma_f(VIf(Bf3), VIf(Bf4), VIf(Bf11), VOf(Bf11));
    __hv_line_f(&sLine_42h5BQS2, VOf(Bf3));
    __hv_tabread_f(&sTabread_zi5qKH5S, VOf(Bf8));
    __hv_add_f(VIf(Bf17), VIf(Bf8), VOf(Bf14));
    __hv_tabread_f(&sTabread_1zWfMPeG, VOf(Bf16));
    __hv_add_f(VIf(Bf14), VIf(Bf16), VOf(Bf5));
    __hv_tabread_f(&sTabread_FN8gdmh3, VOf(Bf12));
    __hv_add_f(VIf(Bf5), VIf(Bf12), VOf(Bf18));
    __hv_tabread_f(&sTabread_txETd8q3, VOf(Bf15));
    __hv_sub_f(VIf(Bf18), VIf(Bf15), VOf(Bf0));
    __hv_tabwrite_f(&sTabwrite_hN8OanlT, VIf(Bf0));
    __hv_tabwrite_f(&sTabwrite_eOHSLqSm, VIf(Bf17));
    __hv_add_f(VIf(Bf18), VIf(Bf15), VOf(Bf15));
    __hv_tabread_f(&sTabread_SjcvtXmp, VOf(Bf18));
    __hv_sub_f(VIf(Bf15), VIf(Bf18), VOf(Bf0));
    __hv_tabwrite_f(&sTabwrite_5C2xIvT6, VIf(Bf0));
    __hv_add_f(VIf(Bf15), VIf(Bf18), VOf(Bf18));
    __hv_tabread_f(&sTabread_npp0Yaeg, VOf(Bf15));
    __hv_sub_f(VIf(Bf5), VIf(Bf12), VOf(Bf12));
    __hv_tabwrite_f(&sTabwrite_8oJgR4mO, VIf(Bf12));
    __hv_sub_f(VIf(Bf17), VIf(Bf8), VOf(Bf8));
    __hv_tabwrite_f(&sTabwrite_Z48GzA0g, VIf(Bf8));
    __hv_sub_f(VIf(Bf14), VIf(Bf16), VOf(Bf16));
    __hv_tabwrite_f(&sTabwrite_ObU7iS8U, VIf(Bf16));
    __hv_fma_f(VIf(Bf11), VIf(Bf3), VIf(Bf18), VOf(Bf18));
    __hv_tabread_f(&sTabread_0FiP8cTk, VOf(Bf11));
    __hv_varread_f(&sVarf_ai1jlsln, VOf(Bf16));
    __hv_mul_f(VIf(Bf11), VIf(Bf16), VOf(Bf16));
    __hv_varread_f(&sVarf_31CMeTHu, VOf(Bf14));
    __hv_rpole_f(&sRPole_zXUnGHfu, VIf(Bf16), VIf(Bf14), VOf(Bf14));
    __hv_sub_f(VIf(Bf14), VIf(Bf11), VOf(Bf14));
    __hv_fma_f(VIf(Bf14), VIf(Bf4), VIf(Bf11), VOf(Bf11));
    __hv_fma_f(VIf(Bf11), VIf(Bf3), VIf(Bf15), VOf(Bf15));
    __hv_sub_f(VIf(Bf18), VIf(Bf15), VOf(Bf11));
    __hv_tabread_f(&sTabread_dcr34w93, VOf(Bf14));
    __hv_varread_f(&sVarf_fO5JNITB, VOf(Bf16));
    __hv_mul_f(VIf(Bf14), VIf(Bf16), VOf(Bf16));
    __hv_varread_f(&sVarf_ytLJqOZ1, VOf(Bf8));
    __hv_rpole_f(&sRPole_NAZn8suV, VIf(Bf16), VIf(Bf8), VOf(Bf8));
    __hv_sub_f(VIf(Bf8), VIf(Bf14), VOf(Bf8));
    __hv_fma_f(VIf(Bf8), VIf(Bf4), VIf(Bf14), VOf(Bf14));
    __hv_mul_f(VIf(Bf14), VIf(Bf3), VOf(Bf14));
    __hv_tabread_f(&sTabread_VTNOHwN0, VOf(Bf8));
    __hv_varread_f(&sVarf_7ceypeny, VOf(Bf16));
    __hv_mul_f(VIf(Bf8), VIf(Bf16), VOf(Bf16));
    __hv_varread_f(&sVarf_yozXBuwp, VOf(Bf12));
    __hv_rpole_f(&sRPole_94OnbUXN, VIf(Bf16), VIf(Bf12), VOf(Bf12));
    __hv_sub_f(VIf(Bf12), VIf(Bf8), VOf(Bf12));
    __hv_fma_f(VIf(Bf12), VIf(Bf4), VIf(Bf8), VOf(Bf8));
    __hv_mul_f(VIf(Bf8), VIf(Bf3), VOf(Bf3));
    __hv_sub_f(VIf(Bf14), VIf(Bf3), VOf(Bf8));
    __hv_add_f(VIf(Bf11), VIf(Bf8), VOf(Bf4));
    __hv_tabwrite_f(&sTabwrite_ThO1TOwi, VIf(Bf4));
    __hv_line_f(&sLine_712JpkDm, VOf(Bf4));
    __hv_mul_f(VIf(Bf18), VIf(Bf4), VOf(Bf12));
    __hv_add_f(VIf(Bf18), VIf(Bf15), VOf(Bf18));
    __hv_add_f(VIf(Bf14), VIf(Bf3), VOf(Bf16));
    __hv_sub_f(VIf(Bf18), VIf(Bf16), VOf(Bf5));
    __hv_tabwrite_f(&sTabwrite_dYe953Jv, VIf(Bf5));
    __hv_mul_f(VIf(Bf3), VIf(Bf4), VOf(Bf3));
    __hv_mul_f(VIf(Bf14), VIf(Bf4), VOf(Bf14));
    __hv_mul_f(VIf(Bf15), VIf(Bf4), VOf(Bf4));
    __hv_sub_f(VIf(Bf11), VIf(Bf8), VOf(Bf8));
    __hv_tabwrite_f(&sTabwrite_0cKRKTGy, VIf(Bf8));
    __hv_add_f(VIf(Bf18), VIf(Bf16), VOf(Bf16));
    __hv_tabwrite_f(&sTabwrite_9a733PFq, VIf(Bf16));
    __hv_add_f(VIf(Bf17), VIf(Bf12), VOf(Bf12));
    __hv_var_k_f(VOf(Bf17), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf12), VIf(Bf17), VOf(Bf17));
    __hv_add_f(VIf(Bf7), VIf(Bf17), VOf(Bf7));
    __hv_line_f(&sLine_hCMeY2uX, VOf(Bf12));
    __hv_mul_f(VIf(Bf2), VIf(Bf12), VOf(Bf12));
    __hv_line_f(&sLine_fAgNk4J8, VOf(Bf2));
    __hv_phasor_f(&sPhasor_r445JHJI, VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf3), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf14), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf3), VIf(Bf14), VOf(Bf14));
    __hv_floor_f(VIf(Bf14), VOf(Bf3));
    __hv_sub_f(VIf(Bf14), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf14), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf3), VIf(Bf14), VOf(Bf14));
    __hv_abs_f(VIf(Bf14), VOf(Bf14));
    __hv_var_k_f(VOf(Bf3), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf14), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf14), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf3), VIf(Bf14), VOf(Bf14));
    __hv_mul_f(VIf(Bf14), VIf(Bf14), VOf(Bf3));
    __hv_mul_f(VIf(Bf14), VIf(Bf3), VOf(Bf4));
    __hv_mul_f(VIf(Bf4), VIf(Bf3), VOf(Bf16));
    __hv_mul_f(VIf(Bf16), VIf(Bf3), VOf(Bf18));
    __hv_mul_f(VIf(Bf18), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf8), 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f);
    __hv_var_k_f(VOf(Bf11), 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f);
    __hv_var_k_f(VOf(Bf15), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf4), VIf(Bf15), VOf(Bf15));
    __hv_sub_f(VIf(Bf14), VIf(Bf15), VOf(Bf15));
    __hv_fma_f(VIf(Bf16), VIf(Bf11), VIf(Bf15), VOf(Bf15));
    __hv_var_k_f(VOf(Bf11), 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f);
    __hv_mul_f(VIf(Bf18), VIf(Bf11), VOf(Bf11));
    __hv_sub_f(VIf(Bf15), VIf(Bf11), VOf(Bf11));
    __hv_fma_f(VIf(Bf3), VIf(Bf8), VIf(Bf11), VOf(Bf11));
    __hv_line_f(&sLine_sTc6BqLx, VOf(Bf8));
    __hv_line_f(&sLine_qcUSrU6Z, VOf(Bf3));
    __hv_fma_f(VIf(Bf2), VIf(Bf8), VIf(Bf3), VOf(Bf15));
    __hv_tabhead_f(&sTabhead_4RtWN2Qt, VOf(Bf18));
    __hv_var_k_f_r(VOf(Bf16), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf18), VIf(Bf16), VOf(Bf16));
    __hv_varread_f(&sVarf_dpHMaRhP, VOf(Bf18));
    __hv_mul_f(VIf(Bf15), VIf(Bf18), VOf(Bf18));
    __hv_varread_f(&sVarf_dkYaFM5l, VOf(Bf15));
    __hv_min_f(VIf(Bf18), VIf(Bf15), VOf(Bf15));
    __hv_zero_f(VOf(Bf18));
    __hv_max_f(VIf(Bf15), VIf(Bf18), VOf(Bf18));
    __hv_sub_f(VIf(Bf16), VIf(Bf18), VOf(Bf18));
    __hv_floor_f(VIf(Bf18), VOf(Bf16));
    __hv_varread_f(&sVarf_W11bjtXS, VOf(Bf15));
    __hv_zero_f(VOf(Bf14));
    __hv_lt_f(VIf(Bf16), VIf(Bf14), VOf(Bf14));
    __hv_and_f(VIf(Bf15), VIf(Bf14), VOf(Bf14));
    __hv_add_f(VIf(Bf16), VIf(Bf14), VOf(Bf14));
    __hv_cast_fi(VIf(Bf14), VOi(Bi1));
    __hv_var_k_i(VOi(Bi0), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi1), VIi(Bi0), VOi(Bi0));
    __hv_tabread_if(&sTabread_in0hzmeX, VIi(Bi0), VOf(Bf14));
    __hv_tabread_if(&sTabread_7BO4rV4o, VIi(Bi1), VOf(Bf15));
    __hv_sub_f(VIf(Bf14), VIf(Bf15), VOf(Bf14));
    __hv_sub_f(VIf(Bf18), VIf(Bf16), VOf(Bf16));
    __hv_fma_f(VIf(Bf14), VIf(Bf16), VIf(Bf15), VOf(Bf15));
    __hv_var_k_f(VOf(Bf16), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_add_f(VIf(Bf2), VIf(Bf16), VOf(Bf16));
    __hv_floor_f(VIf(Bf16), VOf(Bf2));
    __hv_sub_f(VIf(Bf16), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf16), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf2), VIf(Bf16), VOf(Bf16));
    __hv_var_k_f(VOf(Bf14), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf16), VIf(Bf14), VOf(Bf14));
    __hv_floor_f(VIf(Bf14), VOf(Bf16));
    __hv_sub_f(VIf(Bf14), VIf(Bf16), VOf(Bf16));
    __hv_var_k_f(VOf(Bf14), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf16), VIf(Bf14), VOf(Bf14));
    __hv_abs_f(VIf(Bf14), VOf(Bf14));
    __hv_var_k_f(VOf(Bf16), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf14), VIf(Bf16), VOf(Bf16));
    __hv_var_k_f(VOf(Bf14), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf16), VIf(Bf14), VOf(Bf14));
    __hv_mul_f(VIf(Bf14), VIf(Bf14), VOf(Bf16));
    __hv_mul_f(VIf(Bf14), VIf(Bf16), VOf(Bf18));
    __hv_mul_f(VIf(Bf18), VIf(Bf16), VOf(Bf4));
    __hv_mul_f(VIf(Bf4), VIf(Bf16), VOf(Bf5));
    __hv_mul_f(VIf(Bf5), VIf(Bf16), VOf(Bf16));
    __hv_var_k_f(VOf(Bf0), 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f);
    __hv_var_k_f(VOf(Bf13), 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f);
    __hv_var_k_f(VOf(Bf10), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf18), VIf(Bf10), VOf(Bf10));
    __hv_sub_f(VIf(Bf14), VIf(Bf10), VOf(Bf10));
    __hv_fma_f(VIf(Bf4), VIf(Bf13), VIf(Bf10), VOf(Bf10));
    __hv_var_k_f(VOf(Bf13), 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f);
    __hv_mul_f(VIf(Bf5), VIf(Bf13), VOf(Bf13));
    __hv_sub_f(VIf(Bf10), VIf(Bf13), VOf(Bf13));
    __hv_fma_f(VIf(Bf16), VIf(Bf0), VIf(Bf13), VOf(Bf13));
    __hv_fma_f(VIf(Bf2), VIf(Bf8), VIf(Bf3), VOf(Bf3));
    __hv_tabhead_f(&sTabhead_14U4CHnS, VOf(Bf8));
    __hv_var_k_f_r(VOf(Bf2), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf8), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_ck3bw49y, VOf(Bf8));
    __hv_mul_f(VIf(Bf3), VIf(Bf8), VOf(Bf8));
    __hv_varread_f(&sVarf_JjPn5IOz, VOf(Bf3));
    __hv_min_f(VIf(Bf8), VIf(Bf3), VOf(Bf3));
    __hv_zero_f(VOf(Bf8));
    __hv_max_f(VIf(Bf3), VIf(Bf8), VOf(Bf8));
    __hv_sub_f(VIf(Bf2), VIf(Bf8), VOf(Bf8));
    __hv_floor_f(VIf(Bf8), VOf(Bf2));
    __hv_varread_f(&sVarf_spQtVZmT, VOf(Bf3));
    __hv_zero_f(VOf(Bf0));
    __hv_lt_f(VIf(Bf2), VIf(Bf0), VOf(Bf0));
    __hv_and_f(VIf(Bf3), VIf(Bf0), VOf(Bf0));
    __hv_add_f(VIf(Bf2), VIf(Bf0), VOf(Bf0));
    __hv_cast_fi(VIf(Bf0), VOi(Bi1));
    __hv_var_k_i(VOi(Bi0), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi1), VIi(Bi0), VOi(Bi0));
    __hv_tabread_if(&sTabread_h0wsmpkg, VIi(Bi0), VOf(Bf0));
    __hv_tabread_if(&sTabread_WAwZ9L2D, VIi(Bi1), VOf(Bf3));
    __hv_sub_f(VIf(Bf0), VIf(Bf3), VOf(Bf0));
    __hv_sub_f(VIf(Bf8), VIf(Bf2), VOf(Bf2));
    __hv_fma_f(VIf(Bf0), VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_mul_f(VIf(Bf13), VIf(Bf3), VOf(Bf3));
    __hv_fma_f(VIf(Bf11), VIf(Bf15), VIf(Bf3), VOf(Bf3));
    __hv_tabwrite_f(&sTabwrite_3GxKA1rk, VIf(Bf12));
    __hv_line_f(&sLine_Ym6UThys, VOf(Bf12));
    __hv_varread_f(&sVarf_N3IEEdKO, VOf(Bf15));
    __hv_tabhead_f(&sTabhead_q7maaBgK, VOf(Bf11));
    __hv_var_k_f_r(VOf(Bf13), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf11), VIf(Bf13), VOf(Bf13));
    __hv_varread_f(&sVarf_wg5Ri9dn, VOf(Bf11));
    __hv_mul_f(VIf(Bf15), VIf(Bf11), VOf(Bf11));
    __hv_varread_f(&sVarf_c4leJELR, VOf(Bf15));
    __hv_min_f(VIf(Bf11), VIf(Bf15), VOf(Bf15));
    __hv_zero_f(VOf(Bf11));
    __hv_max_f(VIf(Bf15), VIf(Bf11), VOf(Bf11));
    __hv_sub_f(VIf(Bf13), VIf(Bf11), VOf(Bf11));
    __hv_floor_f(VIf(Bf11), VOf(Bf13));
    __hv_varread_f(&sVarf_bIrObFVg, VOf(Bf15));
    __hv_zero_f(VOf(Bf2));
    __hv_lt_f(VIf(Bf13), VIf(Bf2), VOf(Bf2));
    __hv_and_f(VIf(Bf15), VIf(Bf2), VOf(Bf2));
    __hv_add_f(VIf(Bf13), VIf(Bf2), VOf(Bf2));
    __hv_cast_fi(VIf(Bf2), VOi(Bi1));
    __hv_var_k_i(VOi(Bi0), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi1), VIi(Bi0), VOi(Bi0));
    __hv_tabread_if(&sTabread_IvnndJbs, VIi(Bi0), VOf(Bf2));
    __hv_tabread_if(&sTabread_OThuKwfY, VIi(Bi1), VOf(Bf15));
    __hv_sub_f(VIf(Bf2), VIf(Bf15), VOf(Bf2));
    __hv_sub_f(VIf(Bf11), VIf(Bf13), VOf(Bf13));
    __hv_fma_f(VIf(Bf2), VIf(Bf13), VIf(Bf15), VOf(Bf15));
    __hv_varread_f(&sVarf_RQZ3wiSK, VOf(Bf13));
    __hv_rpole_f(&sRPole_7i4fmIt3, VIf(Bf15), VIf(Bf13), VOf(Bf13));
    __hv_var_k_f(VOf(Bf15), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_del1_f(&sDel1_JJHQ6Y0n, VIf(Bf13), VOf(Bf2));
    __hv_mul_f(VIf(Bf2), VIf(Bf15), VOf(Bf15));
    __hv_sub_f(VIf(Bf13), VIf(Bf15), VOf(Bf15));
    __hv_varread_f(&sVarf_NSwYS34I, VOf(Bf13));
    __hv_mul_f(VIf(Bf15), VIf(Bf13), VOf(Bf13));
    __hv_varread_f(&sVarf_CSoM9oba, VOf(Bf15));
    __hv_mul_f(VIf(Bf13), VIf(Bf15), VOf(Bf15));
    __hv_varread_f(&sVarf_icAuhuKv, VOf(Bf13));
    __hv_mul_f(VIf(Bf15), VIf(Bf13), VOf(Bf13));
    __hv_varread_f(&sVarf_2VhQ4WkQ, VOf(Bf2));
    __hv_rpole_f(&sRPole_SogwJHsO, VIf(Bf13), VIf(Bf2), VOf(Bf2));
    __hv_fma_f(VIf(Bf3), VIf(Bf12), VIf(Bf2), VOf(Bf2));
    __hv_tabwrite_f(&sTabwrite_KGSvr8CU, VIf(Bf2));
    __hv_add_f(VIf(Bf3), VIf(Bf15), VOf(Bf15));
    __hv_var_k_f(VOf(Bf3), 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f);
    __hv_mul_f(VIf(Bf15), VIf(Bf3), VOf(Bf3));
    __hv_add_f(VIf(Bf7), VIf(Bf3), VOf(Bf7));
    __hv_add_f(VIf(Bf6), VIf(Bf17), VOf(Bf17));
    __hv_add_f(VIf(Bf17), VIf(Bf3), VOf(Bf3));
    __hv_line_f(&sLine_RbG2TLPM, VOf(Bf17));
    __hv_mul_f(VIf(Bf3), VIf(Bf17), VOf(Bf3));
    __hv_mul_f(VIf(Bf7), VIf(Bf17), VOf(Bf17));
    __hv_add_f(VIf(Bf9), VIf(Bf17), VOf(Bf17));
    __hv_add_f(VIf(Bf1), VIf(Bf3), VOf(Bf3));
    __hv_line_f(&sLine_PiSlEksa, VOf(Bf1));
    __hv_mul_f(VIf(Bf3), VIf(Bf1), VOf(Bf3));
    __hv_mul_f(VIf(Bf17), VIf(Bf1), VOf(Bf1));
    __hv_add_f(VIf(Bf3), VIf(O1), VOf(O1));
    __hv_add_f(VIf(Bf1), VIf(O0), VOf(O0));

    // save output vars to output buffer
    __hv_store_f(outputBuffers[0]+n, VIf(O0));
    __hv_store_f(outputBuffers[1]+n, VIf(O1));
  }

  blockStartTimestamp = nextBlock;

  return n4; // return the number of frames processed

}

int Heavy_CircleStrings::processInline(float *inputBuffers, float *outputBuffers, int n4) {
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

int Heavy_CircleStrings::processInlineInterleaved(float *inputBuffers, float *outputBuffers, int n4) {
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

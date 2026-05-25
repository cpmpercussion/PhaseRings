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
  numBytes += sTabread_init(&sTabread_Jg3NAmnX, &hTable_CgtUdKbt, true);
  numBytes += sRPole_init(&sRPole_L4pw2rd9);
  numBytes += sLine_init(&sLine_XWWDuggY);
  numBytes += sTabwrite_init(&sTabwrite_qojkXJOH, &hTable_CgtUdKbt);
  numBytes += sLine_init(&sLine_y4A9Rpld);
  numBytes += sLine_init(&sLine_5QXNhSok);
  numBytes += sLine_init(&sLine_3ILYiCrq);
  numBytes += sPhasor_k_init(&sPhasor_UpxD1uhe, 0.0f, sampleRate);
  numBytes += sLine_init(&sLine_zQZ2LjM8);
  numBytes += sTabread_init(&sTabread_uz45IUr4, &hTable_pAWAx67h, true);
  numBytes += sRPole_init(&sRPole_h9VJRh0E);
  numBytes += sLine_init(&sLine_H0Shf6Kn);
  numBytes += sTabwrite_init(&sTabwrite_nJP4myYz, &hTable_pAWAx67h);
  numBytes += sLine_init(&sLine_T2nrutbX);
  numBytes += sLine_init(&sLine_OaYhTckm);
  numBytes += sLine_init(&sLine_JzK53Cnd);
  numBytes += sPhasor_k_init(&sPhasor_wQ7iei15, 0.0f, sampleRate);
  numBytes += sLine_init(&sLine_J7fLbiEL);
  numBytes += sTabread_init(&sTabread_5NVipHqQ, &hTable_GeWiHfXt, true);
  numBytes += sRPole_init(&sRPole_BsDIu7qo);
  numBytes += sLine_init(&sLine_s5nMQdih);
  numBytes += sTabwrite_init(&sTabwrite_sWDwFtRq, &hTable_GeWiHfXt);
  numBytes += sLine_init(&sLine_8pq58Ush);
  numBytes += sLine_init(&sLine_bgzodf4K);
  numBytes += sLine_init(&sLine_U1ABC4bt);
  numBytes += sPhasor_k_init(&sPhasor_5yq7vD4E, 0.0f, sampleRate);
  numBytes += sLine_init(&sLine_Tqa1nXEJ);
  numBytes += sTabread_init(&sTabread_CLSQbzjP, &hTable_ecnrv29S, true);
  numBytes += sRPole_init(&sRPole_hDDoj1Qp);
  numBytes += sLine_init(&sLine_7pC7DypZ);
  numBytes += sTabwrite_init(&sTabwrite_cZ9dGKFv, &hTable_ecnrv29S);
  numBytes += sLine_init(&sLine_VOaxQqv5);
  numBytes += sLine_init(&sLine_yhuFmEbj);
  numBytes += sLine_init(&sLine_ax8jUcg3);
  numBytes += sPhasor_k_init(&sPhasor_ylmnYws2, 0.0f, sampleRate);
  numBytes += sLine_init(&sLine_nENENln6);
  numBytes += sLine_init(&sLine_sSDYtBHt);
  numBytes += sTabread_init(&sTabread_fX1QVVSX, &hTable_QGCM5bjp, true);
  numBytes += sRPole_init(&sRPole_KsJ4z6WV);
  numBytes += sLine_init(&sLine_3L017wBY);
  numBytes += sTabwrite_init(&sTabwrite_XARTVQyO, &hTable_QGCM5bjp);
  numBytes += sLine_init(&sLine_ShN6x0iS);
  numBytes += sLine_init(&sLine_8Y4DxCb4);
  numBytes += sRPole_init(&sRPole_rBsPYpaz);
  numBytes += sDel1_init(&sDel1_GiygMIoK);
  numBytes += sLine_init(&sLine_NrKZS8CR);
  numBytes += sLine_init(&sLine_HjQedXwF);
  numBytes += sLine_init(&sLine_KbMDzRgq);
  numBytes += sTabread_init(&sTabread_R2nhUQCO, &hTable_62hDuIO0, true);
  numBytes += sRPole_init(&sRPole_d4ZFwnlm);
  numBytes += sLine_init(&sLine_r1mxZfA7);
  numBytes += sLine_init(&sLine_xU0GRrnN);
  numBytes += sTabread_init(&sTabread_6VyhQ8l7, &hTable_bcdDm4fS, true);
  numBytes += sTabread_init(&sTabread_etC13G1g, &hTable_KuGU5Jpc, true);
  numBytes += sTabread_init(&sTabread_ezpmAwAi, &hTable_Rfr27aWp, true);
  numBytes += sTabread_init(&sTabread_yJRpdmxp, &hTable_d6NDtEiX, true);
  numBytes += sTabread_init(&sTabread_lPXorp1b, &hTable_UDmNhHRL, true);
  numBytes += sTabwrite_init(&sTabwrite_frPCoSZ3, &hTable_MDyfFE7k);
  numBytes += sTabwrite_init(&sTabwrite_dyRlqrv2, &hTable_UDmNhHRL);
  numBytes += sTabwrite_init(&sTabwrite_EEcxaAkq, &hTable_d6NDtEiX);
  numBytes += sTabwrite_init(&sTabwrite_ZGT5NuOT, &hTable_Rfr27aWp);
  numBytes += sTabwrite_init(&sTabwrite_CoTpm3wp, &hTable_KuGU5Jpc);
  numBytes += sTabwrite_init(&sTabwrite_SPOqW7ds, &hTable_bcdDm4fS);
  numBytes += sTabread_init(&sTabread_NQu5hP1y, &hTable_MDyfFE7k, true);
  numBytes += sTabread_init(&sTabread_RZSGtOPH, &hTable_ic2BCxPF, true);
  numBytes += sRPole_init(&sRPole_xdDbEPUX);
  numBytes += sTabread_init(&sTabread_gZHpBzAs, &hTable_a0KlujJP, true);
  numBytes += sRPole_init(&sRPole_EBUvXHUp);
  numBytes += sTabread_init(&sTabread_piljFgdR, &hTable_NozjZiDX, true);
  numBytes += sRPole_init(&sRPole_yLCqpiyJ);
  numBytes += sTabwrite_init(&sTabwrite_IqaXUoUH, &hTable_62hDuIO0);
  numBytes += sTabwrite_init(&sTabwrite_vCdB43tf, &hTable_ic2BCxPF);
  numBytes += sTabwrite_init(&sTabwrite_rgXxbEN7, &hTable_a0KlujJP);
  numBytes += sTabwrite_init(&sTabwrite_INPjIsYP, &hTable_NozjZiDX);
  numBytes += sLine_init(&sLine_Dm7v1JWx);
  numBytes += sLine_init(&sLine_mBKP8IzG);
  numBytes += sTabwrite_init(&sTabwrite_mBOpqpai, &hTable_lolUrs0K);
  numBytes += sLine_init(&sLine_pNzIvBl4);
  numBytes += sPhasor_init(&sPhasor_4sp13981, sampleRate);
  numBytes += sLine_init(&sLine_2pwa6h8r);
  numBytes += sLine_init(&sLine_txO1buxi);
  numBytes += sTabhead_init(&sTabhead_pieJMk3j, &hTable_lolUrs0K);
  numBytes += sTabread_init(&sTabread_1xNWoshy, &hTable_lolUrs0K, false);
  numBytes += sTabread_init(&sTabread_V7wWabam, &hTable_lolUrs0K, false);
  numBytes += sTabhead_init(&sTabhead_5FhunfAy, &hTable_lolUrs0K);
  numBytes += sTabread_init(&sTabread_zYoSW3Am, &hTable_lolUrs0K, false);
  numBytes += sTabread_init(&sTabread_DGbMPWUr, &hTable_lolUrs0K, false);
  numBytes += sTabhead_init(&sTabhead_VwavwnRe, &hTable_PPlwW0wY);
  numBytes += sTabread_init(&sTabread_wZmuTPIq, &hTable_PPlwW0wY, false);
  numBytes += sTabread_init(&sTabread_UhXcrMiE, &hTable_PPlwW0wY, false);
  numBytes += sRPole_init(&sRPole_VVbRVl4k);
  numBytes += sDel1_init(&sDel1_jbqDqc8e);
  numBytes += sLine_init(&sLine_xUxIeTT1);
  numBytes += sRPole_init(&sRPole_aCj21o4k);
  numBytes += sTabwrite_init(&sTabwrite_A8RyULfA, &hTable_PPlwW0wY);
  numBytes += sCPole_init(&sCPole_gCtJVn8z);
  numBytes += sRPole_init(&sRPole_5Ej1x3Nf);
  numBytes += sRPole_init(&sRPole_6UjMlbez);
  numBytes += sRPole_init(&sRPole_yZIb4Lo3);
  numBytes += sTabread_init(&sTabread_OIwQQ3dw, &hTable_693LwEav, true);
  numBytes += sRPole_init(&sRPole_iTiV8VDs);
  numBytes += sLine_init(&sLine_VFA3AXed);
  numBytes += sLine_init(&sLine_zLBDCZPF);
  numBytes += sTabread_init(&sTabread_gukZNESn, &hTable_fyDX5noA, true);
  numBytes += sTabread_init(&sTabread_mKGscUIs, &hTable_5ijKsCE4, true);
  numBytes += sTabread_init(&sTabread_CIoSnsxn, &hTable_GJF7fb4n, true);
  numBytes += sTabread_init(&sTabread_tvRNOEqN, &hTable_pJEI10v8, true);
  numBytes += sTabread_init(&sTabread_jxb9fImF, &hTable_ChiS8qHr, true);
  numBytes += sTabwrite_init(&sTabwrite_CQI1TuKu, &hTable_6V7bd8B9);
  numBytes += sTabwrite_init(&sTabwrite_c3IJh3wS, &hTable_ChiS8qHr);
  numBytes += sTabwrite_init(&sTabwrite_GQeBmJcI, &hTable_pJEI10v8);
  numBytes += sTabwrite_init(&sTabwrite_vx2e8AGE, &hTable_GJF7fb4n);
  numBytes += sTabwrite_init(&sTabwrite_5aCN7SnC, &hTable_5ijKsCE4);
  numBytes += sTabwrite_init(&sTabwrite_VhBxg0Z2, &hTable_fyDX5noA);
  numBytes += sTabread_init(&sTabread_8kp3W93J, &hTable_6V7bd8B9, true);
  numBytes += sTabread_init(&sTabread_jeL93fIW, &hTable_mIJTHwRg, true);
  numBytes += sRPole_init(&sRPole_iCXdsLGN);
  numBytes += sTabread_init(&sTabread_wMzD5ysK, &hTable_HwCmPlvs, true);
  numBytes += sRPole_init(&sRPole_OYRK8Iyg);
  numBytes += sTabread_init(&sTabread_JeA8qHeQ, &hTable_Nvcb34fO, true);
  numBytes += sRPole_init(&sRPole_tPnNZ60H);
  numBytes += sTabwrite_init(&sTabwrite_YwUS7cjj, &hTable_693LwEav);
  numBytes += sTabwrite_init(&sTabwrite_b7qgbpFi, &hTable_mIJTHwRg);
  numBytes += sTabwrite_init(&sTabwrite_B5qVsWWH, &hTable_HwCmPlvs);
  numBytes += sTabwrite_init(&sTabwrite_QO4KkM4X, &hTable_Nvcb34fO);
  numBytes += sLine_init(&sLine_sx57kZpT);
  numBytes += sLine_init(&sLine_gAF7LBmc);
  numBytes += sTabwrite_init(&sTabwrite_FmCqbKUF, &hTable_7jsQ9opx);
  numBytes += sLine_init(&sLine_8e8ExncG);
  numBytes += sPhasor_init(&sPhasor_vBCtyhJ5, sampleRate);
  numBytes += sLine_init(&sLine_3qmmioih);
  numBytes += sLine_init(&sLine_1y3L0Pq6);
  numBytes += sTabhead_init(&sTabhead_t6cLCSzm, &hTable_7jsQ9opx);
  numBytes += sTabread_init(&sTabread_6pVlLsJ5, &hTable_7jsQ9opx, false);
  numBytes += sTabread_init(&sTabread_vkfiQeHh, &hTable_7jsQ9opx, false);
  numBytes += sTabhead_init(&sTabhead_uGnMe1Qx, &hTable_7jsQ9opx);
  numBytes += sTabread_init(&sTabread_DOrFKgN0, &hTable_7jsQ9opx, false);
  numBytes += sTabread_init(&sTabread_Q1yDLO8h, &hTable_7jsQ9opx, false);
  numBytes += sTabhead_init(&sTabhead_lMHjt8tV, &hTable_x7yW6Isu);
  numBytes += sTabread_init(&sTabread_pBz64i4z, &hTable_x7yW6Isu, false);
  numBytes += sTabread_init(&sTabread_4ZpF1ZQS, &hTable_x7yW6Isu, false);
  numBytes += sRPole_init(&sRPole_EXNlqRDk);
  numBytes += sDel1_init(&sDel1_16leHbnf);
  numBytes += sLine_init(&sLine_0AJz5Y1w);
  numBytes += sRPole_init(&sRPole_c9WrJ54V);
  numBytes += sTabwrite_init(&sTabwrite_mBAjwpGT, &hTable_x7yW6Isu);
  numBytes += sLine_init(&sLine_5izOkr9E);
  numBytes += sLine_init(&sLine_LkKfPvRR);
  numBytes += cSlice_init(&cSlice_4CQFOYWS, 2, 1);
  numBytes += cSlice_init(&cSlice_ItLuudPt, 1, 1);
  numBytes += cSlice_init(&cSlice_m0ZXlN5E, 0, 1);
  numBytes += cVar_init_f(&cVar_fUDhmIEA, 0.0f);
  numBytes += cIf_init(&cIf_6KO4fxbH, false);
  numBytes += cIf_init(&cIf_IPLmrg3G, false);
  numBytes += cIf_init(&cIf_83rTHMfq, false);
  numBytes += cIf_init(&cIf_uprOBJVX, false);
  numBytes += cIf_init(&cIf_JqI8TfzU, false);
  numBytes += cBinop_init(&cBinop_VC9ZhJL5, 0.0f); // __eq
  numBytes += cTabhead_init(&cTabhead_k99OEdhR, &hTable_62hDuIO0);
  numBytes += cVar_init_s(&cVar_l9At09eB, "del-1011-del1");
  numBytes += cDelay_init(this, &cDelay_xeYkwa81, 58.6435f);
  numBytes += cDelay_init(this, &cDelay_JOX96AWh, 0.0f);
  numBytes += cBinop_init(&cBinop_Dgp3LCjN, 58.6435f); // __mul
  numBytes += cBinop_init(&cBinop_InXP8p9K, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_BEuewHj0, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_hCg53tHS, 0.0f); // __sub
  numBytes += cTabhead_init(&cTabhead_V60sfg3B, &hTable_ic2BCxPF);
  numBytes += cVar_init_s(&cVar_lccHhdAk, "del-1011-del2");
  numBytes += cDelay_init(this, &cDelay_VShIEnYr, 69.4325f);
  numBytes += cDelay_init(this, &cDelay_ftuCjdpO, 0.0f);
  numBytes += cBinop_init(&cBinop_J1Yk88eC, 69.4325f); // __mul
  numBytes += cBinop_init(&cBinop_A6mUlUPV, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_PqxXzQPB, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_WCbsk20x, 0.0f); // __sub
  numBytes += cTabhead_init(&cTabhead_Hgm0S4ZL, &hTable_a0KlujJP);
  numBytes += cVar_init_s(&cVar_zdthsmSI, "del-1011-del3");
  numBytes += cDelay_init(this, &cDelay_3mIdcFP8, 74.5234f);
  numBytes += cDelay_init(this, &cDelay_3BybnsYh, 0.0f);
  numBytes += cBinop_init(&cBinop_oIbxo1rt, 74.5234f); // __mul
  numBytes += cBinop_init(&cBinop_6mApdeW8, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_AXtvflEv, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_6MzhhNyW, 0.0f); // __sub
  numBytes += cTabhead_init(&cTabhead_xpLrQIFc, &hTable_NozjZiDX);
  numBytes += cVar_init_s(&cVar_kkbVxf51, "del-1011-del4");
  numBytes += cDelay_init(this, &cDelay_e2mk3JmM, 86.1244f);
  numBytes += cDelay_init(this, &cDelay_seUecXvb, 0.0f);
  numBytes += cBinop_init(&cBinop_WhZvdGYh, 86.1244f); // __mul
  numBytes += cBinop_init(&cBinop_beWTQVa2, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_hDGdOb8e, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_kqdDtq9I, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_ycCaMdEp, 0.0f);
  numBytes += cDelay_init(this, &cDelay_Y6FjtKcR, 0.0f);
  numBytes += hTable_init(&hTable_62hDuIO0, 256);
  numBytes += cDelay_init(this, &cDelay_fURKbCBq, 0.0f);
  numBytes += cDelay_init(this, &cDelay_2ifWIAsw, 0.0f);
  numBytes += hTable_init(&hTable_ic2BCxPF, 256);
  numBytes += cDelay_init(this, &cDelay_ipCbEJIw, 0.0f);
  numBytes += cDelay_init(this, &cDelay_Q5Ghcj2P, 0.0f);
  numBytes += hTable_init(&hTable_a0KlujJP, 256);
  numBytes += cDelay_init(this, &cDelay_fzHSqhUd, 0.0f);
  numBytes += cDelay_init(this, &cDelay_MjcLHBAo, 0.0f);
  numBytes += hTable_init(&hTable_NozjZiDX, 256);
  numBytes += cIf_init(&cIf_Lbbr0aJB, false);
  numBytes += cBinop_init(&cBinop_PMicCRzf, 0.0f); // __pow
  numBytes += cPack_init(&cPack_f89bIcHb, 2, 0.0f, 30.0f);
  numBytes += cPack_init(&cPack_IMHAk3xx, 2, 0.0f, 50.0f);
  numBytes += cVar_init_f(&cVar_Cpd1irMP, 22050.0f);
  numBytes += cBinop_init(&cBinop_eDb4Vw1s, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_kZCD107q, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_Ay061GBp, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_Wk4Ut97v, 95.0f);
  numBytes += cVar_init_f(&cVar_POglyt9T, 90.0f);
  numBytes += cVar_init_f(&cVar_q537VAx5, 6000.0f);
  numBytes += cVar_init_f(&cVar_aW7RwTuh, 60.0f);
  numBytes += cIf_init(&cIf_Uar8IAEc, false);
  numBytes += cTabhead_init(&cTabhead_W12nQhiI, &hTable_MDyfFE7k);
  numBytes += cVar_init_s(&cVar_BdefvVic, "del-1011-ref6");
  numBytes += cDelay_init(this, &cDelay_teCwDox1, 13.645f);
  numBytes += cDelay_init(this, &cDelay_35ZbNYTe, 0.0f);
  numBytes += cBinop_init(&cBinop_MLOcEGeD, 13.645f); // __mul
  numBytes += cBinop_init(&cBinop_9suFUNsd, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_YWI1gBaK, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_AAncTKcn, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_8M1fqqGX, 0.0f);
  numBytes += cDelay_init(this, &cDelay_dqUKsgez, 0.0f);
  numBytes += hTable_init(&hTable_MDyfFE7k, 256);
  numBytes += cTabhead_init(&cTabhead_pFDGeXDK, &hTable_UDmNhHRL);
  numBytes += cVar_init_s(&cVar_jYPWt4j5, "del-1011-ref5");
  numBytes += cDelay_init(this, &cDelay_cAjjYTAd, 16.364f);
  numBytes += cDelay_init(this, &cDelay_WK7cBIkV, 0.0f);
  numBytes += cBinop_init(&cBinop_GWklnQoo, 16.364f); // __mul
  numBytes += cBinop_init(&cBinop_caRpDJL5, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_Dp3QFw5T, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_YlLBoPVj, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_5NCkIlAO, 0.0f);
  numBytes += cDelay_init(this, &cDelay_1FCU5FtI, 0.0f);
  numBytes += hTable_init(&hTable_UDmNhHRL, 256);
  numBytes += cTabhead_init(&cTabhead_SJU0AhS9, &hTable_d6NDtEiX);
  numBytes += cVar_init_s(&cVar_6RaAIoMM, "del-1011-ref4");
  numBytes += cDelay_init(this, &cDelay_Ra3EwIrS, 19.392f);
  numBytes += cDelay_init(this, &cDelay_Zdqypl3Q, 0.0f);
  numBytes += cBinop_init(&cBinop_mFexVCMv, 19.392f); // __mul
  numBytes += cBinop_init(&cBinop_q8G36MYb, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_g7OjrY6Z, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_PO94euK0, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_mBEraUQY, 0.0f);
  numBytes += cDelay_init(this, &cDelay_b5rA6Ok7, 0.0f);
  numBytes += hTable_init(&hTable_d6NDtEiX, 256);
  numBytes += cTabhead_init(&cTabhead_RjkRPhh7, &hTable_Rfr27aWp);
  numBytes += cVar_init_s(&cVar_rSqpGWhk, "del-1011-ref3");
  numBytes += cDelay_init(this, &cDelay_zCKPFSaT, 25.796f);
  numBytes += cDelay_init(this, &cDelay_gMysgU3O, 0.0f);
  numBytes += cBinop_init(&cBinop_pSk6ZQDh, 25.796f); // __mul
  numBytes += cBinop_init(&cBinop_RYpawCal, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_QIfY8q4O, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_FDFK0hjD, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_0PivsHSF, 0.0f);
  numBytes += cDelay_init(this, &cDelay_9dikc2t3, 0.0f);
  numBytes += hTable_init(&hTable_Rfr27aWp, 256);
  numBytes += cTabhead_init(&cTabhead_IDWB45r9, &hTable_KuGU5Jpc);
  numBytes += cVar_init_s(&cVar_7zeNrBua, "del-1011-ref2");
  numBytes += cDelay_init(this, &cDelay_ZEeFLkqp, 43.5337f);
  numBytes += cDelay_init(this, &cDelay_UYMMXjtm, 0.0f);
  numBytes += cBinop_init(&cBinop_sS1sypQH, 43.5337f); // __mul
  numBytes += cBinop_init(&cBinop_U69frbgf, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_auaUy3C1, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_2uOy5l0S, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_ijqxhDxI, 0.0f);
  numBytes += cDelay_init(this, &cDelay_cmxuNVEJ, 0.0f);
  numBytes += hTable_init(&hTable_KuGU5Jpc, 256);
  numBytes += cTabhead_init(&cTabhead_8wBSygWM, &hTable_bcdDm4fS);
  numBytes += cVar_init_s(&cVar_mSWPORcU, "del-1011-ref1");
  numBytes += cDelay_init(this, &cDelay_sIbDxW4h, 75.2546f);
  numBytes += cDelay_init(this, &cDelay_alYA2iHS, 0.0f);
  numBytes += cBinop_init(&cBinop_BDvBEZDy, 75.2546f); // __mul
  numBytes += cBinop_init(&cBinop_FB5UBd4T, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_9AQzGy4Y, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_aK7KnSMd, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_8qLrD0hh, 0.0f);
  numBytes += cDelay_init(this, &cDelay_854wOtGx, 0.0f);
  numBytes += hTable_init(&hTable_bcdDm4fS, 256);
  numBytes += cVar_init_f(&cVar_uOkPvVs3, 0.0f);
  numBytes += cVar_init_f(&cVar_wHlgybfY, 0.0f);
  numBytes += cPack_init(&cPack_1Sx0Kv6j, 2, 0.0f, 50.0f);
  numBytes += cVar_init_f(&cVar_HnAqA7yD, 22050.0f);
  numBytes += cBinop_init(&cBinop_Rn2sqEfs, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_TvRuAm6w, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_G1n7slCX, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_xCK4ZhN0, 22050.0f);
  numBytes += cBinop_init(&cBinop_unLTGUPq, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_grSayqOn, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_GyyKHMIl, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_SjAvNGPm, 22050.0f);
  numBytes += cBinop_init(&cBinop_D6w9o1j3, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_nhH1AUje, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_t7Y9nR5L, 0.0f, 0.0f, false);
  numBytes += cIf_init(&cIf_rz6Zb8BJ, false);
  numBytes += cDelay_init(this, &cDelay_QLShzJlS, 50.0f);
  numBytes += cVar_init_f(&cVar_Mn0n43Rb, 0.0f);
  numBytes += cVar_init_f(&cVar_O8ScjlCf, 12.0f);
  numBytes += cVar_init_s(&cVar_RixifLWy, "floatatom");
  numBytes += cPack_init(&cPack_nuZVo1Wl, 2, 0.0f, 200.0f);
  numBytes += cPack_init(&cPack_L6PZHb9X, 2, 0.0f, 200.0f);
  numBytes += cVar_init_s(&cVar_qeaeQjYg, "floatatom");
  numBytes += cDelay_init(this, &cDelay_Rqe1Qiyh, 0.0f);
  numBytes += cDelay_init(this, &cDelay_OX134EPe, 0.0f);
  numBytes += hTable_init(&hTable_lolUrs0K, 256);
  numBytes += cVar_init_s(&cVar_TD1mAJWS, "del-1118-del");
  numBytes += sVarf_init(&sVarf_rsAhOaTe, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_mZ8IKVM3, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_s6Oie7e9, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_Zhuzvvft, "del-1118-del");
  numBytes += sVarf_init(&sVarf_R0yv6RKX, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_FuNqBcWG, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_vc7mgObN, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_3b9OMNhm, 0.0f); // __div
  numBytes += cVar_init_f(&cVar_6xH2yGXb, 4720.0f);
  numBytes += cBinop_init(&cBinop_3sO952Su, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_VKAgcFB1, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_xY3ipPOC, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_9J7oUWi4, 4720.0f);
  numBytes += cBinop_init(&cBinop_CEAZgqVl, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_42IxV9sU, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_rhjM9usw, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_M60VxuUX, 4720.0f);
  numBytes += cBinop_init(&cBinop_q2OVagHu, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_6LGAkaPh, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_XYMdoB53, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_xVJJAgrn, 1.0f);
  numBytes += cIf_init(&cIf_76xFv2h9, false);
  numBytes += sVarf_init(&sVarf_q4lDNi3b, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_OYbaVLUb, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_naCcrDP3, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_0GIWISEr, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_DooJ3X7R, 4720.0f, 0.0f, false);
  numBytes += cTabhead_init(&cTabhead_lfZwwRrn, &hTable_693LwEav);
  numBytes += cVar_init_s(&cVar_fRj7lVHS, "del-1181-del1");
  numBytes += cDelay_init(this, &cDelay_KWAtcvFr, 58.6435f);
  numBytes += cDelay_init(this, &cDelay_I1EgURsV, 0.0f);
  numBytes += cBinop_init(&cBinop_Zv2mcQ9q, 58.6435f); // __mul
  numBytes += cBinop_init(&cBinop_lQ9n4GZv, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_FZGof6DW, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_4XPErmtq, 0.0f); // __sub
  numBytes += cTabhead_init(&cTabhead_K0nzYXXe, &hTable_mIJTHwRg);
  numBytes += cVar_init_s(&cVar_eM0boj18, "del-1181-del2");
  numBytes += cDelay_init(this, &cDelay_xpi6LQ2X, 69.4325f);
  numBytes += cDelay_init(this, &cDelay_IlT7Ycnh, 0.0f);
  numBytes += cBinop_init(&cBinop_K8rFSn1o, 69.4325f); // __mul
  numBytes += cBinop_init(&cBinop_IKazAdga, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_MAzLQRKt, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_ET19GtZP, 0.0f); // __sub
  numBytes += cTabhead_init(&cTabhead_L330esLI, &hTable_HwCmPlvs);
  numBytes += cVar_init_s(&cVar_41BEFoI6, "del-1181-del3");
  numBytes += cDelay_init(this, &cDelay_0cOCR6F4, 74.5234f);
  numBytes += cDelay_init(this, &cDelay_1YOKVVtr, 0.0f);
  numBytes += cBinop_init(&cBinop_jCrRIllh, 74.5234f); // __mul
  numBytes += cBinop_init(&cBinop_awuFFQSn, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_dqXiqPdo, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_qtBMjrNr, 0.0f); // __sub
  numBytes += cTabhead_init(&cTabhead_mRXnhi5H, &hTable_Nvcb34fO);
  numBytes += cVar_init_s(&cVar_TY5wzbag, "del-1181-del4");
  numBytes += cDelay_init(this, &cDelay_8C9ZpkVN, 86.1244f);
  numBytes += cDelay_init(this, &cDelay_tdlUIyX3, 0.0f);
  numBytes += cBinop_init(&cBinop_FHFew95o, 86.1244f); // __mul
  numBytes += cBinop_init(&cBinop_xL3KSUwA, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_C4ssS6ES, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_K42iHF9V, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_vbs1uMWO, 0.0f);
  numBytes += cDelay_init(this, &cDelay_OMVRptgi, 0.0f);
  numBytes += hTable_init(&hTable_693LwEav, 256);
  numBytes += cDelay_init(this, &cDelay_KpovV8l8, 0.0f);
  numBytes += cDelay_init(this, &cDelay_JJjGgun6, 0.0f);
  numBytes += hTable_init(&hTable_mIJTHwRg, 256);
  numBytes += cDelay_init(this, &cDelay_aYggH9o9, 0.0f);
  numBytes += cDelay_init(this, &cDelay_Birk0J5t, 0.0f);
  numBytes += hTable_init(&hTable_HwCmPlvs, 256);
  numBytes += cDelay_init(this, &cDelay_UamJl6lY, 0.0f);
  numBytes += cDelay_init(this, &cDelay_fIsziUV5, 0.0f);
  numBytes += hTable_init(&hTable_Nvcb34fO, 256);
  numBytes += cIf_init(&cIf_BLW1ihiA, false);
  numBytes += cBinop_init(&cBinop_tY2j4yCd, 0.0f); // __pow
  numBytes += cPack_init(&cPack_U6eEgHtR, 2, 0.0f, 30.0f);
  numBytes += cPack_init(&cPack_FiHZCJ7s, 2, 0.0f, 50.0f);
  numBytes += cVar_init_f(&cVar_VBjv806w, 22050.0f);
  numBytes += cBinop_init(&cBinop_SlxoWoyF, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_HUDZZt7U, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_dWmr1V6v, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_GLnzeSRQ, 100.0f);
  numBytes += cVar_init_f(&cVar_xc7L7wV4, 95.0f);
  numBytes += cVar_init_f(&cVar_5LelctpU, 14400.0f);
  numBytes += cVar_init_f(&cVar_W49KAy3V, 60.0f);
  numBytes += cIf_init(&cIf_CfhnhkEf, false);
  numBytes += cTabhead_init(&cTabhead_aIAprJqe, &hTable_6V7bd8B9);
  numBytes += cVar_init_s(&cVar_PpCeroRQ, "del-1181-ref6");
  numBytes += cDelay_init(this, &cDelay_Bc5eXcN4, 13.645f);
  numBytes += cDelay_init(this, &cDelay_ANRjOF91, 0.0f);
  numBytes += cBinop_init(&cBinop_jxJ34OLN, 13.645f); // __mul
  numBytes += cBinop_init(&cBinop_7g3sT9hm, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_2rThSboU, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_1JgpeFcH, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_oQIUHSX5, 0.0f);
  numBytes += cDelay_init(this, &cDelay_W6efCIBv, 0.0f);
  numBytes += hTable_init(&hTable_6V7bd8B9, 256);
  numBytes += cTabhead_init(&cTabhead_LJ1K4BM0, &hTable_ChiS8qHr);
  numBytes += cVar_init_s(&cVar_2bYgkoWy, "del-1181-ref5");
  numBytes += cDelay_init(this, &cDelay_YBkOGA0G, 16.364f);
  numBytes += cDelay_init(this, &cDelay_nu2y5iPL, 0.0f);
  numBytes += cBinop_init(&cBinop_A3aYv7Q3, 16.364f); // __mul
  numBytes += cBinop_init(&cBinop_EsHNret5, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_7BcOj0eP, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_azf4Ft1H, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_0ZrsnBXx, 0.0f);
  numBytes += cDelay_init(this, &cDelay_Zd6dBhc1, 0.0f);
  numBytes += hTable_init(&hTable_ChiS8qHr, 256);
  numBytes += cTabhead_init(&cTabhead_U4zTwJnH, &hTable_pJEI10v8);
  numBytes += cVar_init_s(&cVar_6hSfbrPG, "del-1181-ref4");
  numBytes += cDelay_init(this, &cDelay_LTYYipcg, 19.392f);
  numBytes += cDelay_init(this, &cDelay_2tlt5Tqq, 0.0f);
  numBytes += cBinop_init(&cBinop_u4qa68MB, 19.392f); // __mul
  numBytes += cBinop_init(&cBinop_33c2MSaH, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_vEzo8Vxs, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_ppYU6i7Z, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_CYynC8qf, 0.0f);
  numBytes += cDelay_init(this, &cDelay_YlL83GjJ, 0.0f);
  numBytes += hTable_init(&hTable_pJEI10v8, 256);
  numBytes += cTabhead_init(&cTabhead_LeFC9cFs, &hTable_GJF7fb4n);
  numBytes += cVar_init_s(&cVar_MqDPT2RA, "del-1181-ref3");
  numBytes += cDelay_init(this, &cDelay_pAjHkumq, 25.796f);
  numBytes += cDelay_init(this, &cDelay_uZ7Bsc2D, 0.0f);
  numBytes += cBinop_init(&cBinop_dGEFcDQ5, 25.796f); // __mul
  numBytes += cBinop_init(&cBinop_nTIjcDIx, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_j1uUrmRd, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_kKJfzpiX, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_6DRglWmE, 0.0f);
  numBytes += cDelay_init(this, &cDelay_2cVqcYx1, 0.0f);
  numBytes += hTable_init(&hTable_GJF7fb4n, 256);
  numBytes += cTabhead_init(&cTabhead_aP34WzdI, &hTable_5ijKsCE4);
  numBytes += cVar_init_s(&cVar_XjRxuH4R, "del-1181-ref2");
  numBytes += cDelay_init(this, &cDelay_sIWIpZnh, 43.5337f);
  numBytes += cDelay_init(this, &cDelay_SB7OOGXK, 0.0f);
  numBytes += cBinop_init(&cBinop_lR41tlTg, 43.5337f); // __mul
  numBytes += cBinop_init(&cBinop_4raMJCcP, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_c1knj7qf, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_Ycq0Ji5M, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_hJijPeeD, 0.0f);
  numBytes += cDelay_init(this, &cDelay_axVWNkiI, 0.0f);
  numBytes += hTable_init(&hTable_5ijKsCE4, 256);
  numBytes += cTabhead_init(&cTabhead_wFy48l8R, &hTable_fyDX5noA);
  numBytes += cVar_init_s(&cVar_piYaJnlH, "del-1181-ref1");
  numBytes += cDelay_init(this, &cDelay_BKFRlsec, 75.2546f);
  numBytes += cDelay_init(this, &cDelay_zf55GMUc, 0.0f);
  numBytes += cBinop_init(&cBinop_ScEyYj1b, 75.2546f); // __mul
  numBytes += cBinop_init(&cBinop_oQc0gkbR, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_P39qmOhJ, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_R0Gygysl, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_wGyKGDwC, 0.0f);
  numBytes += cDelay_init(this, &cDelay_8kS0NbW0, 0.0f);
  numBytes += hTable_init(&hTable_fyDX5noA, 256);
  numBytes += cVar_init_f(&cVar_9uERaytd, 0.0f);
  numBytes += cVar_init_f(&cVar_S43alZiX, 0.0f);
  numBytes += cPack_init(&cPack_YUG6igGk, 2, 0.0f, 50.0f);
  numBytes += cVar_init_f(&cVar_c4ndmtKo, 22050.0f);
  numBytes += cBinop_init(&cBinop_JfG0H3Ja, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_4kqT8FwB, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_umxtjKmp, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_zoAiLxe5, 22050.0f);
  numBytes += cBinop_init(&cBinop_GGLEQjZJ, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_aDMvFOc4, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_nTtCLfpd, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_IYbZH8FJ, 22050.0f);
  numBytes += cBinop_init(&cBinop_PKzFFIW1, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_IOQX6Vkx, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_TQmuGjOM, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_zdRc1MtI, "del-1280-del1");
  numBytes += sVarf_init(&sVarf_ts9piLeS, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_J7ubcf1q, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_0NHdwa0u, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_FMsMNLX8, 10000.0f);
  numBytes += cBinop_init(&cBinop_1ub0ChQu, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_jglJru0z, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_3He9rWm4, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_6FyEoIpK, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_s5lWnt7x, 10.0f);
  numBytes += cBinop_init(&cBinop_YCx3vYz1, 0.0f); // __div
  numBytes += sVarf_init(&sVarf_0ro2gKY6, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_7YBH2mnI, "floatatom");
  numBytes += sVarf_init(&sVarf_qTGt7ieI, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_WzVliaRN, 0.0f);
  numBytes += cDelay_init(this, &cDelay_LiCm9JlR, 0.0f);
  numBytes += hTable_init(&hTable_PPlwW0wY, 256);
  numBytes += sVarf_init(&sVarf_le8NBeiN, 0.0f, 0.0f, false);
  numBytes += cPack_init(&cPack_9yqCXNnu, 2, 0.0f, 50.0f);
  numBytes += cRandom_init(&cRandom_nw4OIwAd, 1131613867);
  numBytes += cSlice_init(&cSlice_PHVruyi8, 1, 1);
  numBytes += cRandom_init(&cRandom_DIkLfxNx, 88033357);
  numBytes += cSlice_init(&cSlice_umNgdQMK, 1, 1);
  numBytes += cVar_init_s(&cVar_dHcGBwCr, "floatatom");
  numBytes += cPack_init(&cPack_iWA2L3Rc, 2, 0.0f, 200.0f);
  numBytes += cPack_init(&cPack_bgIgn5yg, 2, 0.0f, 200.0f);
  numBytes += cVar_init_s(&cVar_yOhHCP0t, "floatatom");
  numBytes += cDelay_init(this, &cDelay_O2Tzblq5, 0.0f);
  numBytes += cDelay_init(this, &cDelay_vuhaYkiM, 0.0f);
  numBytes += hTable_init(&hTable_7jsQ9opx, 256);
  numBytes += cVar_init_s(&cVar_rpEvAsq0, "del-1311-del");
  numBytes += sVarf_init(&sVarf_kBeeHRFJ, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_QzoTxFn1, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_TvuZAr7q, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_KmuDXz2l, "del-1311-del");
  numBytes += sVarf_init(&sVarf_ZUGw0L1t, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_4oenKeRe, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_KDd8cxnP, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_pFy6wCm7, 0.0f); // __div
  numBytes += cVar_init_s(&cVar_9f9UlSz2, "del-1340-del1");
  numBytes += sVarf_init(&sVarf_n6ffOqUb, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_NkKeq4SG, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_9Jh147To, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_PZGlDA4M, 10000.0f);
  numBytes += cBinop_init(&cBinop_ErtoGu4C, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_J7Mm7ASH, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_YoVv5H5i, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_W1ALPYvw, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_5miSL3kM, 10.0f);
  numBytes += cBinop_init(&cBinop_7M90kSP8, 0.0f); // __div
  numBytes += sVarf_init(&sVarf_OQxFUwWU, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_Kolo1L1g, "floatatom");
  numBytes += sVarf_init(&sVarf_sCMes5G2, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_K2BiNpv9, 0.0f);
  numBytes += cDelay_init(this, &cDelay_rPoqKuln, 0.0f);
  numBytes += hTable_init(&hTable_x7yW6Isu, 256);
  numBytes += sVarf_init(&sVarf_nWHFzWDP, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_k06XdDYL, "floatatom");
  numBytes += cDelay_init(this, &cDelay_gnEZnS5V, 0.0f);
  numBytes += cVar_init_f(&cVar_ncd4NLaV, 20.0f);
  numBytes += cBinop_init(&cBinop_KgP5tCo9, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_JbxJFpgi, 0.0f);
  numBytes += cSlice_init(&cSlice_5xOp8eOf, 1, -1);
  numBytes += cSlice_init(&cSlice_Dm6OtPjz, 1, -1);
  numBytes += cVar_init_f(&cVar_HD8S4Pol, 0.0f);
  numBytes += cVar_init_f(&cVar_Jav6hQnb, 20.0f);
  numBytes += cVar_init_f(&cVar_BTpVXvBJ, 0.0f);
  numBytes += cVar_init_f(&cVar_H11lwsNO, 0.0f);
  numBytes += cVar_init_f(&cVar_exPuLLpA, 0.0f);
  numBytes += cSlice_init(&cSlice_HwGPcSwD, 1, 1);
  numBytes += cSlice_init(&cSlice_2tioCZwK, 0, 1);
  numBytes += cBinop_init(&cBinop_GMZZQjuQ, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_YXkbI7rJ, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_gzQNRuYj, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_AsVfKV9V, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_n9vbwqCG, 20.0f); // __div
  numBytes += cBinop_init(&cBinop_MZK0xM9W, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_SsBhT7hu, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_W63lvv5X, 0.0f); // __sub
  numBytes += cVar_init_s(&cVar_j2tAghve, "floatatom");
  numBytes += cPack_init(&cPack_KE3SbkZa, 2, 0.0f, 1000.0f);
  numBytes += cDelay_init(this, &cDelay_wN31GZ6x, 0.0f);
  numBytes += cVar_init_f(&cVar_9DPzXJzk, 20.0f);
  numBytes += cBinop_init(&cBinop_3mkbqC6V, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_kHXk1qH5, 0.0f);
  numBytes += cSlice_init(&cSlice_nwhv0OLO, 1, -1);
  numBytes += cSlice_init(&cSlice_Ycpcmo2r, 1, -1);
  numBytes += cVar_init_f(&cVar_eUB2axKk, 0.0f);
  numBytes += cVar_init_f(&cVar_IMcPdQOU, 20.0f);
  numBytes += cVar_init_f(&cVar_xE3PY6vU, 0.0f);
  numBytes += cVar_init_f(&cVar_nKOWpStL, 0.0f);
  numBytes += cVar_init_f(&cVar_cSyP1io4, 0.0f);
  numBytes += cSlice_init(&cSlice_7ga1aHIx, 1, 1);
  numBytes += cSlice_init(&cSlice_saNjZKPV, 0, 1);
  numBytes += cBinop_init(&cBinop_gvFbFUOb, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_aSkp7Ezs, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_yk7tUSWF, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_pUO37GHx, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_lFqAchSF, 20.0f); // __div
  numBytes += cBinop_init(&cBinop_10va4fzI, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_aT12NGAb, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_kC8yKEZi, 0.0f); // __sub
  numBytes += cPack_init(&cPack_3qfWCaZ6, 2, 0.0f, 1000.0f);
  numBytes += cPack_init(&cPack_GVvoVYO8, 2, 0.0f, 1000.0f);
  numBytes += sVarf_init(&sVarf_O7n4PLVN, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_wEgefPHf, 5.0f);
  numBytes += cBinop_init(&cBinop_DOFw6xat, 0.0f); // __div
  numBytes += sVarf_init(&sVarf_irTY8WQQ, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_nEgDisUK, "floatatom");
  numBytes += cIf_init(&cIf_AF1XkyBF, false);
  numBytes += cIf_init(&cIf_7pjy8meb, false);
  numBytes += cIf_init(&cIf_jjdDjr09, false);
  numBytes += cIf_init(&cIf_noTtZVs1, false);
  numBytes += cRandom_init(&cRandom_XsETpGvX, -961868784);
  numBytes += cSlice_init(&cSlice_iEYNF5dB, 1, 1);
  numBytes += sVari_init(&sVari_PV4lGAPF, 0, 0, false);
  numBytes += cTabhead_init(&cTabhead_ZEBE9mCN, &hTable_QGCM5bjp);
  numBytes += cVar_init_s(&cVar_rzu47SIA, "del-1418-delay");
  numBytes += cDelay_init(this, &cDelay_P6kpQkfw, 12.0f);
  numBytes += cDelay_init(this, &cDelay_CHhabVuK, 0.0f);
  numBytes += cBinop_init(&cBinop_Xf4lCH1e, 12.0f); // __mul
  numBytes += cBinop_init(&cBinop_SGFdBFzW, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_UEKMM6P5, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_TqypGGB0, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_VoSa65Mb, 1.0f); // __pow
  numBytes += cVar_init_s(&cVar_6jjiWVWa, "floatatom");
  numBytes += cDelay_init(this, &cDelay_TklAUP8T, 5.0f);
  numBytes += cVar_init_f(&cVar_jKarz4n1, 3800.0f);
  numBytes += cBinop_init(&cBinop_VHkuh3eo, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_78SG5i07, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_3kLMESJK, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_SNm3tw24, 0.0f);
  numBytes += cDelay_init(this, &cDelay_gMOGbzys, 0.0f);
  numBytes += hTable_init(&hTable_QGCM5bjp, 256);
  numBytes += cBinop_init(&cBinop_lgk2nqoS, 0.0f); // __div
  numBytes += sVarf_init(&sVarf_O0FWSn7k, 0.999f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_xlIY8NZW, 1.0f);
  numBytes += cDelay_init(this, &cDelay_mnruniYL, 0.0f);
  numBytes += cVar_init_f(&cVar_NoZr9Ai2, 2000.0f);
  numBytes += cBinop_init(&cBinop_EhDfVZyu, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_LbmRsRt5, 60.0f);
  numBytes += cRandom_init(&cRandom_XbYt5NUb, 1308269849);
  numBytes += cSlice_init(&cSlice_oRzitJP5, 1, 1);
  numBytes += cVar_init_f(&cVar_Fk3OB7EV, 0.0f);
  numBytes += cIf_init(&cIf_n9HzMYMz, false);
  numBytes += cIf_init(&cIf_QtX0IUln, false);
  numBytes += cIf_init(&cIf_W6un9OED, false);
  numBytes += cIf_init(&cIf_oi0gKjFC, false);
  numBytes += cPack_init(&cPack_y8P8qVQg, 2, 0.0f, 50.0f);
  numBytes += cPack_init(&cPack_3xHLeGU5, 2, 0.0f, 80.0f);
  numBytes += cVar_init_s(&cVar_TkPuS1l4, "floatatom");
  numBytes += cRandom_init(&cRandom_UfwipOxb, -327021226);
  numBytes += cSlice_init(&cSlice_19ocJNTE, 1, 1);
  numBytes += cVar_init_s(&cVar_OxE9FGc5, "floatatom");
  numBytes += cVar_init_f(&cVar_5w2x6vXo, 1.0f);
  numBytes += cVar_init_f(&cVar_d0Ft8teU, 0.0f);
  numBytes += cVar_init_f(&cVar_dIaVyjCy, 0.0f);
  numBytes += cRandom_init(&cRandom_P5AAzFNP, 1572083792);
  numBytes += cSlice_init(&cSlice_7A6BtOl6, 1, 1);
  numBytes += cRandom_init(&cRandom_eInFKQHX, 1777140109);
  numBytes += cSlice_init(&cSlice_unDImarG, 1, 1);
  numBytes += cRandom_init(&cRandom_jhuYr3xb, 190195658);
  numBytes += cSlice_init(&cSlice_QTYjtCO2, 1, 1);
  numBytes += cBinop_init(&cBinop_4uzunjZu, 1.0f); // __pow
  numBytes += cRandom_init(&cRandom_h4YnVJoK, -657767080);
  numBytes += cSlice_init(&cSlice_f74woDHz, 1, 1);
  numBytes += cPack_init(&cPack_5gGnCKHq, 2, 0.0f, 50.0f);
  numBytes += cVar_init_s(&cVar_x4xINvkE, "floatatom");
  numBytes += cVar_init_s(&cVar_M18x5i90, "floatatom");
  numBytes += cVar_init_f(&cVar_k0RrR1xv, 0.0f);
  numBytes += cVar_init_s(&cVar_LCShkyro, "floatatom");
  numBytes += cVar_init_s(&cVar_wSZWF4Fa, "floatatom");
  numBytes += cVar_init_s(&cVar_YkEc34Ic, "floatatom");
  numBytes += cDelay_init(this, &cDelay_lL5wFiBM, 25.0f);
  numBytes += cVar_init_f(&cVar_wbRwO1xJ, 0.0f);
  numBytes += sVarf_init(&sVarf_2kvbRuso, 0.0f, 0.0f, false);
  numBytes += cRandom_init(&cRandom_SHVkVZC8, -2132257692);
  numBytes += cSlice_init(&cSlice_TVoz83hS, 1, 1);
  numBytes += sVari_init(&sVari_SYsiY7cX, 0, 0, false);
  numBytes += cTabhead_init(&cTabhead_yByfXtt9, &hTable_CgtUdKbt);
  numBytes += cVar_init_s(&cVar_3A2ohpsB, "del-1497-delay");
  numBytes += cDelay_init(this, &cDelay_cAIe9dlT, 12.0f);
  numBytes += cDelay_init(this, &cDelay_1FACIYW2, 0.0f);
  numBytes += cBinop_init(&cBinop_SEliAVSi, 12.0f); // __mul
  numBytes += cBinop_init(&cBinop_gQ55hn80, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_L7PTkLxx, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_zmXoBkut, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_KxsED7oV, 1.0f); // __pow
  numBytes += cVar_init_s(&cVar_jpev2ICq, "floatatom");
  numBytes += cDelay_init(this, &cDelay_pzniaKYf, 5.0f);
  numBytes += cVar_init_f(&cVar_08LWfvXU, 3800.0f);
  numBytes += cBinop_init(&cBinop_meBH6uKn, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_YnWcGaHO, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_GqzXrUBn, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_5eL5qQcn, 0.0f);
  numBytes += cDelay_init(this, &cDelay_gQmSPTN6, 0.0f);
  numBytes += hTable_init(&hTable_CgtUdKbt, 256);
  numBytes += cBinop_init(&cBinop_8fzQYmgM, 0.0f); // __div
  numBytes += sVarf_init(&sVarf_YUE8cA4Y, 0.999f, 0.0f, false);
  numBytes += cPack_init(&cPack_T7W2kkRW, 2, 0.0f, 10.0f);
  numBytes += cPack_init(&cPack_FxA2aSP9, 2, 0.0f, 10.0f);
  numBytes += cSlice_init(&cSlice_xWzcgVhx, 1, 1);
  numBytes += cSlice_init(&cSlice_KCxKR3ti, 0, 1);
  numBytes += cBinop_init(&cBinop_VTPtDmUs, 1.0f); // __mul
  numBytes += cVar_init_f(&cVar_5qQXuOYL, 98.0f);
  numBytes += cIf_init(&cIf_DKNUOKEk, false);
  numBytes += cBinop_init(&cBinop_MeX14mcZ, 0.0f); // __pow
  numBytes += cPack_init(&cPack_uaNnTTU2, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_FKIQ7qcR, 0.0f);
  numBytes += cVar_init_f(&cVar_PuGlDK1h, 98.0f);
  numBytes += cIf_init(&cIf_SfC5Ljnp, false);
  numBytes += cBinop_init(&cBinop_7eKlM6zZ, 0.0f); // __pow
  numBytes += cPack_init(&cPack_0tRN5aSl, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_tfVeb2xy, 0.0f);
  numBytes += cRandom_init(&cRandom_Wk3K6xtn, 1272630695);
  numBytes += cSlice_init(&cSlice_BahkjKum, 1, 1);
  numBytes += cBinop_init(&cBinop_osiUgZAA, 1.0f); // __pow
  numBytes += cRandom_init(&cRandom_reWDhLfP, 31610975);
  numBytes += cSlice_init(&cSlice_v0gapoXA, 1, 1);
  numBytes += cPack_init(&cPack_hCzuDCpN, 2, 0.0f, 50.0f);
  numBytes += cVar_init_s(&cVar_JZ3XSc9B, "floatatom");
  numBytes += cVar_init_s(&cVar_IBICAOIV, "floatatom");
  numBytes += cVar_init_f(&cVar_GXHAgQOI, 0.0f);
  numBytes += cVar_init_s(&cVar_43dzlu6h, "floatatom");
  numBytes += cVar_init_s(&cVar_sk4Y9Ht3, "floatatom");
  numBytes += cVar_init_s(&cVar_Mt4QMNTY, "floatatom");
  numBytes += cDelay_init(this, &cDelay_x6ol5WrW, 25.0f);
  numBytes += cVar_init_f(&cVar_zF6EHPd4, 0.0f);
  numBytes += sVarf_init(&sVarf_xOQ29moC, 0.0f, 0.0f, false);
  numBytes += cRandom_init(&cRandom_s3dCaREo, -788150532);
  numBytes += cSlice_init(&cSlice_MdOC04bo, 1, 1);
  numBytes += sVari_init(&sVari_iBYv4MCZ, 0, 0, false);
  numBytes += cTabhead_init(&cTabhead_lTp1bLjF, &hTable_pAWAx67h);
  numBytes += cVar_init_s(&cVar_TZPELRDt, "del-1565-delay");
  numBytes += cDelay_init(this, &cDelay_Ork5rMcG, 12.0f);
  numBytes += cDelay_init(this, &cDelay_9f4R3sez, 0.0f);
  numBytes += cBinop_init(&cBinop_YRZ1SPcf, 12.0f); // __mul
  numBytes += cBinop_init(&cBinop_7XnvE9pm, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_LniiIGVg, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_mimXuNBU, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_hzkePoF6, 1.0f); // __pow
  numBytes += cVar_init_s(&cVar_EWsoX6Gd, "floatatom");
  numBytes += cDelay_init(this, &cDelay_ZhWybiFR, 5.0f);
  numBytes += cVar_init_f(&cVar_mbStdtfa, 3800.0f);
  numBytes += cBinop_init(&cBinop_hTFROYhq, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_ktRlGh6b, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_y4UkHvqz, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_o50wx0uD, 0.0f);
  numBytes += cDelay_init(this, &cDelay_T6npqPi4, 0.0f);
  numBytes += hTable_init(&hTable_pAWAx67h, 256);
  numBytes += cBinop_init(&cBinop_GN1qCahY, 0.0f); // __div
  numBytes += sVarf_init(&sVarf_WulfmN9E, 0.999f, 0.0f, false);
  numBytes += cPack_init(&cPack_Rc6e8PUp, 2, 0.0f, 10.0f);
  numBytes += cPack_init(&cPack_N4ekobgR, 2, 0.0f, 10.0f);
  numBytes += cSlice_init(&cSlice_YZIyJR1o, 1, 1);
  numBytes += cSlice_init(&cSlice_fb0yezsH, 0, 1);
  numBytes += cBinop_init(&cBinop_LyrRfBnr, 1.0f); // __mul
  numBytes += cRandom_init(&cRandom_Y7tqDUMW, -1197146532);
  numBytes += cSlice_init(&cSlice_zhr3JG2l, 1, 1);
  numBytes += cBinop_init(&cBinop_SAsI28XZ, 1.0f); // __pow
  numBytes += cRandom_init(&cRandom_KXfHXQD9, 1069107282);
  numBytes += cSlice_init(&cSlice_xIKsFmL1, 1, 1);
  numBytes += cPack_init(&cPack_upolaOH3, 2, 0.0f, 50.0f);
  numBytes += cVar_init_s(&cVar_dKrLjoSm, "floatatom");
  numBytes += cVar_init_s(&cVar_b1go0ylg, "floatatom");
  numBytes += cVar_init_f(&cVar_WrBsBufF, 0.0f);
  numBytes += cVar_init_s(&cVar_EqKxQ7Ju, "floatatom");
  numBytes += cVar_init_s(&cVar_ICD2vIGz, "floatatom");
  numBytes += cVar_init_s(&cVar_OEWMLfBh, "floatatom");
  numBytes += cDelay_init(this, &cDelay_ua925bI6, 25.0f);
  numBytes += cVar_init_f(&cVar_15RSA0yi, 0.0f);
  numBytes += sVarf_init(&sVarf_Fw6A8D3a, 0.0f, 0.0f, false);
  numBytes += cRandom_init(&cRandom_s2exTMOw, -585593571);
  numBytes += cSlice_init(&cSlice_C7l4LOOL, 1, 1);
  numBytes += sVari_init(&sVari_jZfuUXMV, 0, 0, false);
  numBytes += cTabhead_init(&cTabhead_jzrfxRrt, &hTable_GeWiHfXt);
  numBytes += cVar_init_s(&cVar_PhBzj2gg, "del-1616-delay");
  numBytes += cDelay_init(this, &cDelay_z3N94oiZ, 12.0f);
  numBytes += cDelay_init(this, &cDelay_gsBwub5T, 0.0f);
  numBytes += cBinop_init(&cBinop_JtRGawT0, 12.0f); // __mul
  numBytes += cBinop_init(&cBinop_yLdaFLO4, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_cSlocEHL, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_Q996IrGi, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_VlOx6y79, 1.0f); // __pow
  numBytes += cVar_init_s(&cVar_8rEbM5ui, "floatatom");
  numBytes += cDelay_init(this, &cDelay_axfoSm30, 5.0f);
  numBytes += cVar_init_f(&cVar_ucInTxs1, 3800.0f);
  numBytes += cBinop_init(&cBinop_JxYcj07j, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_Mq7nUbi8, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_IeUPh9s6, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_iz20TZzC, 0.0f);
  numBytes += cDelay_init(this, &cDelay_L0Hk6U7p, 0.0f);
  numBytes += hTable_init(&hTable_GeWiHfXt, 256);
  numBytes += cBinop_init(&cBinop_ck1tlMUG, 0.0f); // __div
  numBytes += sVarf_init(&sVarf_AlwSpVoN, 0.999f, 0.0f, false);
  numBytes += cPack_init(&cPack_UmEJwr0x, 2, 0.0f, 10.0f);
  numBytes += cPack_init(&cPack_RKe3Cx3d, 2, 0.0f, 10.0f);
  numBytes += cSlice_init(&cSlice_nZ7Ji8aR, 1, 1);
  numBytes += cSlice_init(&cSlice_2ifoyNME, 0, 1);
  numBytes += cBinop_init(&cBinop_n3XreU96, 1.0f); // __mul
  numBytes += cRandom_init(&cRandom_hBBSWHl6, 1525104478);
  numBytes += cSlice_init(&cSlice_LrkUjDhG, 1, 1);
  numBytes += cBinop_init(&cBinop_eplcbp2f, 1.0f); // __pow
  numBytes += cRandom_init(&cRandom_KgBVTbI0, -2108256234);
  numBytes += cSlice_init(&cSlice_1tUganas, 1, 1);
  numBytes += cPack_init(&cPack_wat93oqB, 2, 0.0f, 50.0f);
  numBytes += cVar_init_s(&cVar_VLGCtr4H, "floatatom");
  numBytes += cVar_init_s(&cVar_va0Z8BCC, "floatatom");
  numBytes += cVar_init_f(&cVar_MWZdEgFV, 0.0f);
  numBytes += cVar_init_s(&cVar_6z0EVIRH, "floatatom");
  numBytes += cVar_init_s(&cVar_OA2EGsAz, "floatatom");
  numBytes += cVar_init_s(&cVar_DpQIec65, "floatatom");
  numBytes += cDelay_init(this, &cDelay_KFIisT1k, 25.0f);
  numBytes += cVar_init_f(&cVar_NedJERv8, 0.0f);
  numBytes += sVarf_init(&sVarf_UDmQxbMg, 0.0f, 0.0f, false);
  numBytes += cRandom_init(&cRandom_eeDEEmJI, -1069523198);
  numBytes += cSlice_init(&cSlice_W9v0j2IA, 1, 1);
  numBytes += sVari_init(&sVari_EOOMzvK0, 0, 0, false);
  numBytes += cTabhead_init(&cTabhead_uF0bu8WL, &hTable_ecnrv29S);
  numBytes += cVar_init_s(&cVar_K2cULozm, "del-1667-delay");
  numBytes += cDelay_init(this, &cDelay_NyesR6w0, 12.0f);
  numBytes += cDelay_init(this, &cDelay_yc7dikPw, 0.0f);
  numBytes += cBinop_init(&cBinop_mqbl9kzx, 12.0f); // __mul
  numBytes += cBinop_init(&cBinop_j0uxr84E, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_jHXYdqEM, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_qioYzcjb, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_x00aQ1oV, 1.0f); // __pow
  numBytes += cVar_init_s(&cVar_wtWv2dCN, "floatatom");
  numBytes += cDelay_init(this, &cDelay_Xcx9bFyI, 5.0f);
  numBytes += cVar_init_f(&cVar_KgJd8Gmx, 3800.0f);
  numBytes += cBinop_init(&cBinop_14yRBkP8, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_z2ylGeUi, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_XPajirxG, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_83Vpe0xH, 0.0f);
  numBytes += cDelay_init(this, &cDelay_vNFw2PHh, 0.0f);
  numBytes += hTable_init(&hTable_ecnrv29S, 256);
  numBytes += cBinop_init(&cBinop_wCOZwrdf, 0.0f); // __div
  numBytes += sVarf_init(&sVarf_hjy7RmaU, 0.999f, 0.0f, false);
  numBytes += cPack_init(&cPack_6L7LSBnh, 2, 0.0f, 10.0f);
  numBytes += cPack_init(&cPack_bDbDNV3b, 2, 0.0f, 10.0f);
  numBytes += cSlice_init(&cSlice_DNFsvgjW, 1, 1);
  numBytes += cSlice_init(&cSlice_k2abEYDJ, 0, 1);
  numBytes += cBinop_init(&cBinop_dm9hnv5t, 1.0f); // __mul
  numBytes += cVar_init_f(&cVar_j1oUZmqA, 100.0f);
  numBytes += cIf_init(&cIf_zyPXI7wu, false);
  numBytes += cBinop_init(&cBinop_Lt6TVY3A, 0.0f); // __pow
  numBytes += cPack_init(&cPack_OFeCfyhv, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_2FkmBTue, 0.0f);
  numBytes += cVar_init_f(&cVar_AOYPt2KL, 100.0f);
  numBytes += cIf_init(&cIf_3VGKCTvb, false);
  numBytes += cBinop_init(&cBinop_KqrfkLKG, 0.0f); // __pow
  numBytes += cPack_init(&cPack_szVszC0H, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_qYKLSbLk, 0.0f);
  numBytes += cVar_init_f(&cVar_UO9Ao0DX, 98.0f);
  numBytes += cIf_init(&cIf_Z3OsSUYc, false);
  numBytes += cBinop_init(&cBinop_86vakDBR, 0.0f); // __pow
  numBytes += cPack_init(&cPack_Uq6uKPVc, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_Zu3HJcmd, 0.0f);
  numBytes += cIf_init(&cIf_1iBabhhk, false);
  numBytes += cIf_init(&cIf_tvbYkS06, false);
  numBytes += cVar_init_f(&cVar_bKAVODIw, 89.0f);
  numBytes += cIf_init(&cIf_la6D2bTq, false);
  numBytes += cBinop_init(&cBinop_wzy55oZ0, 0.0f); // __pow
  numBytes += cPack_init(&cPack_stG5TFJk, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_LWI7IMpl, 0.0f);
  numBytes += cPack_init(&cPack_i1JJg3xN, 2, 0.0f, 0.0f);
  numBytes += cSlice_init(&cSlice_LUboW4WX, 1, 1);
  numBytes += cSlice_init(&cSlice_TbEBJSv7, 0, 1);
  numBytes += cIf_init(&cIf_5d75bUlZ, false);
  numBytes += cIf_init(&cIf_7P1ZmEFw, false);
  numBytes += cIf_init(&cIf_WkTttCOy, false);
  numBytes += cSlice_init(&cSlice_mNrtE3jJ, 1, 1);
  numBytes += cSlice_init(&cSlice_tyNf9wV7, 0, 1);
  numBytes += cVar_init_f(&cVar_doNbZc4Q, 0.0f);
  numBytes += cIf_init(&cIf_8I8e6CBD, false);
  numBytes += cPack_init(&cPack_cJvMOmg4, 2, 0.0f, 0.0f);
  numBytes += cSlice_init(&cSlice_D4bzfOnH, 1, -1);
  numBytes += cSlice_init(&cSlice_OsG4fnNS, 1, -1);
  numBytes += cSlice_init(&cSlice_QmvyGpOh, 1, -1);
  numBytes += cSlice_init(&cSlice_q5dci14u, 1, -1);
  numBytes += cIf_init(&cIf_asLxdEsN, false);
  numBytes += cVar_init_f(&cVar_OPq1mGMn, 1.0f);
  numBytes += cPack_init(&cPack_5qSjqcfM, 3, 0.0f, 0.0f, 0.0f);
  numBytes += cVar_init_f(&cVar_C51LgecL, 0.0f);
  
  // schedule a message to trigger all loadbangs via the __hv_init receiver
  scheduleMessageForReceiver(0xCE5CC65B, msg_initWithBang(HV_MESSAGE_ON_STACK(1), 0));
}

Heavy_CircleStrings::~Heavy_CircleStrings() {
  hTable_free(&hTable_62hDuIO0);
  hTable_free(&hTable_ic2BCxPF);
  hTable_free(&hTable_a0KlujJP);
  hTable_free(&hTable_NozjZiDX);
  cPack_free(&cPack_f89bIcHb);
  cPack_free(&cPack_IMHAk3xx);
  hTable_free(&hTable_MDyfFE7k);
  hTable_free(&hTable_UDmNhHRL);
  hTable_free(&hTable_d6NDtEiX);
  hTable_free(&hTable_Rfr27aWp);
  hTable_free(&hTable_KuGU5Jpc);
  hTable_free(&hTable_bcdDm4fS);
  cPack_free(&cPack_1Sx0Kv6j);
  cPack_free(&cPack_nuZVo1Wl);
  cPack_free(&cPack_L6PZHb9X);
  hTable_free(&hTable_lolUrs0K);
  hTable_free(&hTable_693LwEav);
  hTable_free(&hTable_mIJTHwRg);
  hTable_free(&hTable_HwCmPlvs);
  hTable_free(&hTable_Nvcb34fO);
  cPack_free(&cPack_U6eEgHtR);
  cPack_free(&cPack_FiHZCJ7s);
  hTable_free(&hTable_6V7bd8B9);
  hTable_free(&hTable_ChiS8qHr);
  hTable_free(&hTable_pJEI10v8);
  hTable_free(&hTable_GJF7fb4n);
  hTable_free(&hTable_5ijKsCE4);
  hTable_free(&hTable_fyDX5noA);
  cPack_free(&cPack_YUG6igGk);
  hTable_free(&hTable_PPlwW0wY);
  cPack_free(&cPack_9yqCXNnu);
  cPack_free(&cPack_iWA2L3Rc);
  cPack_free(&cPack_bgIgn5yg);
  hTable_free(&hTable_7jsQ9opx);
  hTable_free(&hTable_x7yW6Isu);
  cPack_free(&cPack_KE3SbkZa);
  cPack_free(&cPack_3qfWCaZ6);
  cPack_free(&cPack_GVvoVYO8);
  hTable_free(&hTable_QGCM5bjp);
  cPack_free(&cPack_y8P8qVQg);
  cPack_free(&cPack_3xHLeGU5);
  cPack_free(&cPack_5gGnCKHq);
  hTable_free(&hTable_CgtUdKbt);
  cPack_free(&cPack_T7W2kkRW);
  cPack_free(&cPack_FxA2aSP9);
  cPack_free(&cPack_uaNnTTU2);
  cPack_free(&cPack_0tRN5aSl);
  cPack_free(&cPack_hCzuDCpN);
  hTable_free(&hTable_pAWAx67h);
  cPack_free(&cPack_Rc6e8PUp);
  cPack_free(&cPack_N4ekobgR);
  cPack_free(&cPack_upolaOH3);
  hTable_free(&hTable_GeWiHfXt);
  cPack_free(&cPack_UmEJwr0x);
  cPack_free(&cPack_RKe3Cx3d);
  cPack_free(&cPack_wat93oqB);
  hTable_free(&hTable_ecnrv29S);
  cPack_free(&cPack_6L7LSBnh);
  cPack_free(&cPack_bDbDNV3b);
  cPack_free(&cPack_OFeCfyhv);
  cPack_free(&cPack_szVszC0H);
  cPack_free(&cPack_Uq6uKPVc);
  cPack_free(&cPack_stG5TFJk);
  cPack_free(&cPack_i1JJg3xN);
  cPack_free(&cPack_cJvMOmg4);
  cPack_free(&cPack_5qSjqcfM);
}

HvTable *Heavy_CircleStrings::getTableForHash(hv_uint32_t tableHash) {switch (tableHash) {
    case 0xCA4BE954: return &hTable_62hDuIO0; // del-1011-del1
    case 0x244CE923: return &hTable_ic2BCxPF; // del-1011-del2
    case 0xBF68886F: return &hTable_a0KlujJP; // del-1011-del3
    case 0x55632928: return &hTable_NozjZiDX; // del-1011-del4
    case 0x96995032: return &hTable_MDyfFE7k; // del-1011-ref6
    case 0xBDA899C7: return &hTable_UDmNhHRL; // del-1011-ref5
    case 0xC66C0031: return &hTable_d6NDtEiX; // del-1011-ref4
    case 0x87263188: return &hTable_Rfr27aWp; // del-1011-ref3
    case 0xABC596E9: return &hTable_KuGU5Jpc; // del-1011-ref2
    case 0x4E55A0D9: return &hTable_bcdDm4fS; // del-1011-ref1
    case 0x1F09EB02: return &hTable_lolUrs0K; // del-1118-del
    case 0xB5F303E3: return &hTable_693LwEav; // del-1181-del1
    case 0x6E18225F: return &hTable_mIJTHwRg; // del-1181-del2
    case 0x272AEAC5: return &hTable_HwCmPlvs; // del-1181-del3
    case 0x1EF3B8AB: return &hTable_Nvcb34fO; // del-1181-del4
    case 0x908630F0: return &hTable_6V7bd8B9; // del-1181-ref6
    case 0x571D5EBB: return &hTable_ChiS8qHr; // del-1181-ref5
    case 0xCD1DF3EE: return &hTable_pJEI10v8; // del-1181-ref4
    case 0x32F70D4: return &hTable_GJF7fb4n; // del-1181-ref3
    case 0x2649C1A0: return &hTable_5ijKsCE4; // del-1181-ref2
    case 0x2A4E9F1A: return &hTable_fyDX5noA; // del-1181-ref1
    case 0xCDA70ACE: return &hTable_PPlwW0wY; // del-1280-del1
    case 0x1880FCC4: return &hTable_7jsQ9opx; // del-1311-del
    case 0xDA0DD3E: return &hTable_x7yW6Isu; // del-1340-del1
    case 0xF059E6C5: return &hTable_QGCM5bjp; // del-1418-delay
    case 0x1B841D52: return &hTable_CgtUdKbt; // del-1497-delay
    case 0xDE86E2B1: return &hTable_pAWAx67h; // del-1565-delay
    case 0x308D60F2: return &hTable_GeWiHfXt; // del-1616-delay
    case 0x4D4CF87C: return &hTable_ecnrv29S; // del-1667-delay
    default: return nullptr;
  }
}

void Heavy_CircleStrings::scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) {
  switch (receiverHash) {
    case 0xE9CDF196: { // 1474-att
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_H6obejJw_sendMessage);
      break;
    }
    case 0x318534AD: { // 1474-envrel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_vgfTutZr_sendMessage);
      break;
    }
    case 0x73BE02B2: { // 1474-envvol
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_AhseCEqk_sendMessage);
      break;
    }
    case 0x20FBEFA2: { // 1474-index
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_dKHTl5Gy_sendMessage);
      break;
    }
    case 0xB3D2781B: { // 1474-rel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_BJqx0LBS_sendMessage);
      break;
    }
    case 0xEB419491: { // 1474-vel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_3u04fSnV_sendMessage);
      break;
    }
    case 0x49301F33: { // 1526-levelin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_002zsoz5_sendMessage);
      break;
    }
    case 0x3EA097: { // 1526-levelout
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_qa37TAUQ_sendMessage);
      break;
    }
    case 0x1D57784C: { // 1534-levelin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_kKfsjFPE_sendMessage);
      break;
    }
    case 0xB6B2C532: { // 1534-levelout
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_6P36y0JI_sendMessage);
      break;
    }
    case 0xEA6E47A2: { // 1542-att
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_EDggbWw1_sendMessage);
      break;
    }
    case 0x39641416: { // 1542-envrel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_bgcZimyq_sendMessage);
      break;
    }
    case 0xD0ED04C0: { // 1542-envvol
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_EujQ5qdA_sendMessage);
      break;
    }
    case 0x1E007032: { // 1542-index
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_vzmWrOtl_sendMessage);
      break;
    }
    case 0x20600A8E: { // 1542-rel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_woqS8Xio_sendMessage);
      break;
    }
    case 0xEB9D289: { // 1542-vel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_M7G3MMuu_sendMessage);
      break;
    }
    case 0x12164925: { // 1593-att
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_33EGZ9B2_sendMessage);
      break;
    }
    case 0x9F106978: { // 1593-envrel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_rfywEDQd_sendMessage);
      break;
    }
    case 0xF8CC5130: { // 1593-envvol
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_LFS2MKvw_sendMessage);
      break;
    }
    case 0xCF824326: { // 1593-index
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_UsbLKWib_sendMessage);
      break;
    }
    case 0x57F149E1: { // 1593-rel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_SY3wwCjD_sendMessage);
      break;
    }
    case 0x7BCAFFC2: { // 1593-vel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_HWtXeN6Y_sendMessage);
      break;
    }
    case 0xCCAC5F0A: { // 1644-att
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_C8ubQwHc_sendMessage);
      break;
    }
    case 0x19A77C92: { // 1644-envrel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_rgeeVsCt_sendMessage);
      break;
    }
    case 0xD26C853B: { // 1644-envvol
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_DIxKq28q_sendMessage);
      break;
    }
    case 0x76816227: { // 1644-index
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_fBFJQqQH_sendMessage);
      break;
    }
    case 0xE6DAD6CC: { // 1644-rel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_B5YHdcYw_sendMessage);
      break;
    }
    case 0xDDDC8674: { // 1644-vel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_RWGEA916_sendMessage);
      break;
    }
    case 0x9D74C17D: { // 1695-levelin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_MAUl3a9R_sendMessage);
      break;
    }
    case 0x990B713A: { // 1695-levelout
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_2gwdia0O_sendMessage);
      break;
    }
    case 0x212BD48C: { // 1703-levelin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_wDEOnKsi_sendMessage);
      break;
    }
    case 0x485D1082: { // 1703-levelout
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_yse5Eb4F_sendMessage);
      break;
    }
    case 0x18B0FC6F: { // 1711-levelin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_9jj1UQMO_sendMessage);
      break;
    }
    case 0x300E52C6: { // 1711-levelout
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_wMohgGv7_sendMessage);
      break;
    }
    case 0x7B6E4E54: { // 1723-levelin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_x5L247lF_sendMessage);
      break;
    }
    case 0x64AF31A5: { // 1723-levelout
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_fMPXpATZ_sendMessage);
      break;
    }
    case 0xCE5CC65B: { // __hv_init
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_8pIITIXJ_sendMessage);
      break;
    }
    case 0x67E37CA3: { // __hv_notein
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_itLbGSUu_sendMessage);
      break;
    }
    case 0x40AA4AF1: { // changesound
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_3YmY9uz3_sendMessage);
      break;
    }
    case 0xA41806F7: { // distortlevel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_PfZW4QN9_sendMessage);
      break;
    }
    case 0xFCD12E4C: { // mastervolume
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_aIhGq4fr_sendMessage);
      break;
    }
    case 0xEF5F3308: { // panTranslation
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_j0Ufjkmw_sendMessage);
      break;
    }
    case 0x58FBFA93: { // phaseFreq
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_RtOjalu1_sendMessage);
      break;
    }
    case 0x8B2148DD: { // pitch
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_FrdgGU9i_sendMessage);
      break;
    }
    case 0x4409C659: { // processeffects
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_e2WVQP8D_sendMessage);
      break;
    }
    case 0x7B795C5A: { // resetsing
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_exe9dQR0_sendMessage);
      break;
    }
    case 0xA987B741: { // reverbvolume
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_Vjanh444_sendMessage);
      break;
    }
    case 0x7AAE6786: { // sinPanAngle
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_4SE2tV70_sendMessage);
      break;
    }
    case 0x6731B2E0: { // sing
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_FgDF1r96_sendMessage);
      break;
    }
    case 0x57292445: { // singlevel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_8nCpMyc8_sendMessage);
      break;
    }
    case 0xC7DE3B07: { // singpitch
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_83M9Hmpd_sendMessage);
      break;
    }
    case 0x4E809B1C: { // testbutton
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_bzy700uZ_sendMessage);
      break;
    }
    case 0x853B1BE7: { // velocity
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_U4ehvbIg_sendMessage);
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


void Heavy_CircleStrings::cSlice_4CQFOYWS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_1mM6bScQ_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cSlice_ItLuudPt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cIf_onMessage(_c, &Context(_c)->cIf_uprOBJVX, 0, m, &cIf_uprOBJVX_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_IPLmrg3G, 0, m, &cIf_IPLmrg3G_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cSlice_m0ZXlN5E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cIf_onMessage(_c, &Context(_c)->cIf_JqI8TfzU, 0, m, &cIf_JqI8TfzU_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_83rTHMfq, 0, m, &cIf_83rTHMfq_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cVar_fUDhmIEA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_epYywjIB_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_6KO4fxbH, 0, m, &cIf_6KO4fxbH_sendMessage);
}

void Heavy_CircleStrings::cUnop_S2h9VZUs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_QlX5LTtu_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_VC9ZhJL5, HV_BINOP_EQ, 1, m, &cBinop_VC9ZhJL5_sendMessage);
}

void Heavy_CircleStrings::cUnop_rwok8cgN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_QlX5LTtu_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_VC9ZhJL5, HV_BINOP_EQ, 1, m, &cBinop_VC9ZhJL5_sendMessage);
}

void Heavy_CircleStrings::cIf_6KO4fxbH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_rwok8cgN_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_S2h9VZUs_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_epYywjIB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_6KO4fxbH, 1, m, &cIf_6KO4fxbH_sendMessage);
}

void Heavy_CircleStrings::cIf_IPLmrg3G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSend_hkt7lj8l_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cIf_83rTHMfq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSend_bPEXEpUs_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cIf_uprOBJVX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSend_hkt7lj8l_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cIf_JqI8TfzU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSend_bPEXEpUs_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_1mM6bScQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_VC9ZhJL5, HV_BINOP_EQ, 0, m, &cBinop_VC9ZhJL5_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_wbT3dDbn_sendMessage);
}

void Heavy_CircleStrings::cBinop_QlX5LTtu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_wWIBGl31_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_nddHQlui_sendMessage);
}

void Heavy_CircleStrings::cBinop_VC9ZhJL5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_4oJPe4Uk_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_J05xVFgz_sendMessage);
}

void Heavy_CircleStrings::cCast_J05xVFgz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_JqI8TfzU, 1, m, &cIf_JqI8TfzU_sendMessage);
}

void Heavy_CircleStrings::cCast_4oJPe4Uk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_IPLmrg3G, 1, m, &cIf_IPLmrg3G_sendMessage);
}

void Heavy_CircleStrings::cCast_nddHQlui_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_83rTHMfq, 1, m, &cIf_83rTHMfq_sendMessage);
}

void Heavy_CircleStrings::cCast_wWIBGl31_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_uprOBJVX, 1, m, &cIf_uprOBJVX_sendMessage);
}

void Heavy_CircleStrings::cBinop_wbT3dDbn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_txx1kjFz_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cTabhead_k99OEdhR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_InXP8p9K, HV_BINOP_SUBTRACT, 0, m, &cBinop_InXP8p9K_sendMessage);
}

void Heavy_CircleStrings::cMsg_yzScGxj4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_zYSlMMwZ_sendMessage);
}

void Heavy_CircleStrings::cSystem_zYSlMMwZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_SNQzN27i_sendMessage);
}

void Heavy_CircleStrings::cVar_l9At09eB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_kaUFueax_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_xeYkwa81_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_xeYkwa81, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_JOX96AWh, 0, m, &cDelay_JOX96AWh_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_R2nhUQCO, 0, m, &sTabread_R2nhUQCO_sendMessage);
}

void Heavy_CircleStrings::cDelay_JOX96AWh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_JOX96AWh, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_R2nhUQCO, 0, m, &sTabread_R2nhUQCO_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_JOX96AWh, 0, m, &cDelay_JOX96AWh_sendMessage);
}

void Heavy_CircleStrings::sTabread_R2nhUQCO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_hCg53tHS, HV_BINOP_SUBTRACT, 0, m, &cBinop_hCg53tHS_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_Dgp3LCjN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_BEuewHj0, HV_BINOP_MAX, 0, m, &cBinop_BEuewHj0_sendMessage);
}

void Heavy_CircleStrings::cBinop_SNQzN27i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Dgp3LCjN, HV_BINOP_MULTIPLY, 0, m, &cBinop_Dgp3LCjN_sendMessage);
}

void Heavy_CircleStrings::cBinop_InXP8p9K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_weYiPYHs_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_R2nhUQCO, 0, m, &sTabread_R2nhUQCO_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_VN1eUGu8_sendMessage);
}

void Heavy_CircleStrings::cSystem_vVgVRLe4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_hCg53tHS, HV_BINOP_SUBTRACT, 1, m, &cBinop_hCg53tHS_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_JOX96AWh, 2, m, &cDelay_JOX96AWh_sendMessage);
}

void Heavy_CircleStrings::cMsg_kaUFueax_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_vVgVRLe4_sendMessage);
}

void Heavy_CircleStrings::cMsg_weYiPYHs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_xeYkwa81, 0, m, &cDelay_xeYkwa81_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_JOX96AWh, 0, m, &cDelay_JOX96AWh_sendMessage);
}

void Heavy_CircleStrings::cMsg_Uw9EWPPa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_BEuewHj0, HV_BINOP_MAX, 1, m, &cBinop_BEuewHj0_sendMessage);
}

void Heavy_CircleStrings::cBinop_BEuewHj0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_InXP8p9K, HV_BINOP_SUBTRACT, 1, m, &cBinop_InXP8p9K_sendMessage);
}

void Heavy_CircleStrings::cCast_VN1eUGu8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_xeYkwa81, 0, m, &cDelay_xeYkwa81_sendMessage);
}

void Heavy_CircleStrings::cBinop_ThcJ4bKA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_xeYkwa81, 2, m, &cDelay_xeYkwa81_sendMessage);
}

void Heavy_CircleStrings::cBinop_hCg53tHS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_ThcJ4bKA_sendMessage);
}

void Heavy_CircleStrings::cCast_rXchkkO7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_l9At09eB, 0, m, &cVar_l9At09eB_sendMessage);
  cMsg_yzScGxj4_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_k99OEdhR, 0, m, &cTabhead_k99OEdhR_sendMessage);
}

void Heavy_CircleStrings::cTabhead_V60sfg3B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_A6mUlUPV, HV_BINOP_SUBTRACT, 0, m, &cBinop_A6mUlUPV_sendMessage);
}

void Heavy_CircleStrings::cMsg_HuubA4Th_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_eXq8LgI8_sendMessage);
}

void Heavy_CircleStrings::cSystem_eXq8LgI8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_3DYzPqXp_sendMessage);
}

void Heavy_CircleStrings::cVar_lccHhdAk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_jORfcrFt_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_VShIEnYr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_VShIEnYr, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ftuCjdpO, 0, m, &cDelay_ftuCjdpO_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_RZSGtOPH, 0, m, &sTabread_RZSGtOPH_sendMessage);
}

void Heavy_CircleStrings::cDelay_ftuCjdpO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_ftuCjdpO, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_RZSGtOPH, 0, m, &sTabread_RZSGtOPH_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ftuCjdpO, 0, m, &cDelay_ftuCjdpO_sendMessage);
}

void Heavy_CircleStrings::sTabread_RZSGtOPH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_WCbsk20x, HV_BINOP_SUBTRACT, 0, m, &cBinop_WCbsk20x_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_J1Yk88eC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_PqxXzQPB, HV_BINOP_MAX, 0, m, &cBinop_PqxXzQPB_sendMessage);
}

void Heavy_CircleStrings::cBinop_3DYzPqXp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_J1Yk88eC, HV_BINOP_MULTIPLY, 0, m, &cBinop_J1Yk88eC_sendMessage);
}

void Heavy_CircleStrings::cBinop_A6mUlUPV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_lWbwRyx8_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_RZSGtOPH, 0, m, &sTabread_RZSGtOPH_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_lOM4Lhfh_sendMessage);
}

void Heavy_CircleStrings::cSystem_R95MRfpK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_WCbsk20x, HV_BINOP_SUBTRACT, 1, m, &cBinop_WCbsk20x_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ftuCjdpO, 2, m, &cDelay_ftuCjdpO_sendMessage);
}

void Heavy_CircleStrings::cMsg_jORfcrFt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_R95MRfpK_sendMessage);
}

void Heavy_CircleStrings::cMsg_lWbwRyx8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_VShIEnYr, 0, m, &cDelay_VShIEnYr_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ftuCjdpO, 0, m, &cDelay_ftuCjdpO_sendMessage);
}

void Heavy_CircleStrings::cMsg_1nBQ1RzG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_PqxXzQPB, HV_BINOP_MAX, 1, m, &cBinop_PqxXzQPB_sendMessage);
}

void Heavy_CircleStrings::cBinop_PqxXzQPB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_A6mUlUPV, HV_BINOP_SUBTRACT, 1, m, &cBinop_A6mUlUPV_sendMessage);
}

void Heavy_CircleStrings::cCast_lOM4Lhfh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_VShIEnYr, 0, m, &cDelay_VShIEnYr_sendMessage);
}

void Heavy_CircleStrings::cBinop_B9mf2TpS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_VShIEnYr, 2, m, &cDelay_VShIEnYr_sendMessage);
}

void Heavy_CircleStrings::cBinop_WCbsk20x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_B9mf2TpS_sendMessage);
}

void Heavy_CircleStrings::cCast_sTzDMGHD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_lccHhdAk, 0, m, &cVar_lccHhdAk_sendMessage);
  cMsg_HuubA4Th_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_V60sfg3B, 0, m, &cTabhead_V60sfg3B_sendMessage);
}

void Heavy_CircleStrings::cTabhead_Hgm0S4ZL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6mApdeW8, HV_BINOP_SUBTRACT, 0, m, &cBinop_6mApdeW8_sendMessage);
}

void Heavy_CircleStrings::cMsg_VvHSLGh3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_JIuK5X8c_sendMessage);
}

void Heavy_CircleStrings::cSystem_JIuK5X8c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_5Qrne0ab_sendMessage);
}

void Heavy_CircleStrings::cVar_zdthsmSI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_yc9hjvcv_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_3mIdcFP8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_3mIdcFP8, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_3BybnsYh, 0, m, &cDelay_3BybnsYh_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_gZHpBzAs, 0, m, &sTabread_gZHpBzAs_sendMessage);
}

void Heavy_CircleStrings::cDelay_3BybnsYh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_3BybnsYh, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_gZHpBzAs, 0, m, &sTabread_gZHpBzAs_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_3BybnsYh, 0, m, &cDelay_3BybnsYh_sendMessage);
}

void Heavy_CircleStrings::sTabread_gZHpBzAs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_6MzhhNyW, HV_BINOP_SUBTRACT, 0, m, &cBinop_6MzhhNyW_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_oIbxo1rt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_AXtvflEv, HV_BINOP_MAX, 0, m, &cBinop_AXtvflEv_sendMessage);
}

void Heavy_CircleStrings::cBinop_5Qrne0ab_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_oIbxo1rt, HV_BINOP_MULTIPLY, 0, m, &cBinop_oIbxo1rt_sendMessage);
}

void Heavy_CircleStrings::cBinop_6mApdeW8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_X6HiAV1t_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_gZHpBzAs, 0, m, &sTabread_gZHpBzAs_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ehNfejY6_sendMessage);
}

void Heavy_CircleStrings::cSystem_By3In5QD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6MzhhNyW, HV_BINOP_SUBTRACT, 1, m, &cBinop_6MzhhNyW_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_3BybnsYh, 2, m, &cDelay_3BybnsYh_sendMessage);
}

void Heavy_CircleStrings::cMsg_yc9hjvcv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_By3In5QD_sendMessage);
}

void Heavy_CircleStrings::cMsg_X6HiAV1t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_3mIdcFP8, 0, m, &cDelay_3mIdcFP8_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_3BybnsYh, 0, m, &cDelay_3BybnsYh_sendMessage);
}

void Heavy_CircleStrings::cMsg_LotDbnR8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_AXtvflEv, HV_BINOP_MAX, 1, m, &cBinop_AXtvflEv_sendMessage);
}

void Heavy_CircleStrings::cBinop_AXtvflEv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6mApdeW8, HV_BINOP_SUBTRACT, 1, m, &cBinop_6mApdeW8_sendMessage);
}

void Heavy_CircleStrings::cCast_ehNfejY6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_3mIdcFP8, 0, m, &cDelay_3mIdcFP8_sendMessage);
}

void Heavy_CircleStrings::cBinop_RthSef4r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_3mIdcFP8, 2, m, &cDelay_3mIdcFP8_sendMessage);
}

void Heavy_CircleStrings::cBinop_6MzhhNyW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_RthSef4r_sendMessage);
}

void Heavy_CircleStrings::cCast_Seq6cIOR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_zdthsmSI, 0, m, &cVar_zdthsmSI_sendMessage);
  cMsg_VvHSLGh3_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_Hgm0S4ZL, 0, m, &cTabhead_Hgm0S4ZL_sendMessage);
}

void Heavy_CircleStrings::cTabhead_xpLrQIFc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_beWTQVa2, HV_BINOP_SUBTRACT, 0, m, &cBinop_beWTQVa2_sendMessage);
}

void Heavy_CircleStrings::cMsg_G4JtrXms_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_SA6GX7BW_sendMessage);
}

void Heavy_CircleStrings::cSystem_SA6GX7BW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_aDkePagn_sendMessage);
}

void Heavy_CircleStrings::cVar_kkbVxf51_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_KL4sYDVx_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_e2mk3JmM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_e2mk3JmM, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_seUecXvb, 0, m, &cDelay_seUecXvb_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_piljFgdR, 0, m, &sTabread_piljFgdR_sendMessage);
}

void Heavy_CircleStrings::cDelay_seUecXvb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_seUecXvb, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_piljFgdR, 0, m, &sTabread_piljFgdR_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_seUecXvb, 0, m, &cDelay_seUecXvb_sendMessage);
}

void Heavy_CircleStrings::sTabread_piljFgdR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_kqdDtq9I, HV_BINOP_SUBTRACT, 0, m, &cBinop_kqdDtq9I_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_WhZvdGYh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_hDGdOb8e, HV_BINOP_MAX, 0, m, &cBinop_hDGdOb8e_sendMessage);
}

void Heavy_CircleStrings::cBinop_aDkePagn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_WhZvdGYh, HV_BINOP_MULTIPLY, 0, m, &cBinop_WhZvdGYh_sendMessage);
}

void Heavy_CircleStrings::cBinop_beWTQVa2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_kzzgJjRh_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_piljFgdR, 0, m, &sTabread_piljFgdR_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_zASipU6A_sendMessage);
}

void Heavy_CircleStrings::cSystem_gBVu7nHT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_kqdDtq9I, HV_BINOP_SUBTRACT, 1, m, &cBinop_kqdDtq9I_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_seUecXvb, 2, m, &cDelay_seUecXvb_sendMessage);
}

void Heavy_CircleStrings::cMsg_KL4sYDVx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_gBVu7nHT_sendMessage);
}

void Heavy_CircleStrings::cMsg_kzzgJjRh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_e2mk3JmM, 0, m, &cDelay_e2mk3JmM_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_seUecXvb, 0, m, &cDelay_seUecXvb_sendMessage);
}

void Heavy_CircleStrings::cMsg_tJt6EZvc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_hDGdOb8e, HV_BINOP_MAX, 1, m, &cBinop_hDGdOb8e_sendMessage);
}

void Heavy_CircleStrings::cBinop_hDGdOb8e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_beWTQVa2, HV_BINOP_SUBTRACT, 1, m, &cBinop_beWTQVa2_sendMessage);
}

void Heavy_CircleStrings::cCast_zASipU6A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_e2mk3JmM, 0, m, &cDelay_e2mk3JmM_sendMessage);
}

void Heavy_CircleStrings::cBinop_zWNr9Mi7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_e2mk3JmM, 2, m, &cDelay_e2mk3JmM_sendMessage);
}

void Heavy_CircleStrings::cBinop_kqdDtq9I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_zWNr9Mi7_sendMessage);
}

void Heavy_CircleStrings::cCast_k1vKcFkT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_kkbVxf51, 0, m, &cVar_kkbVxf51_sendMessage);
  cMsg_G4JtrXms_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_xpLrQIFc, 0, m, &cTabhead_xpLrQIFc_sendMessage);
}

void Heavy_CircleStrings::cMsg_TeUpXtOn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_w2Pis68a_sendMessage);
}

void Heavy_CircleStrings::cSystem_w2Pis68a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_S3yCIibd_sendMessage);
}

void Heavy_CircleStrings::cDelay_ycCaMdEp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_ycCaMdEp, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Y6FjtKcR, 0, m, &cDelay_Y6FjtKcR_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ycCaMdEp, 0, m, &cDelay_ycCaMdEp_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_IqaXUoUH, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_Y6FjtKcR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Y6FjtKcR, m);
  cMsg_S4FrnBWP_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_po6U2v0b_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_ObG1Jab0_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_6X2S4c7P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Wtb7d2th_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_62hDuIO0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_VzcnSYAq_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ycCaMdEp, 2, m, &cDelay_ycCaMdEp_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_FLrHY6v2_sendMessage);
}

void Heavy_CircleStrings::cMsg_Wtb7d2th_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_62hDuIO0, 0, m, &hTable_62hDuIO0_sendMessage);
}

void Heavy_CircleStrings::cBinop_S3yCIibd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 58.6435f, 0, m, &cBinop_6X2S4c7P_sendMessage);
}

void Heavy_CircleStrings::cMsg_S4FrnBWP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_62hDuIO0, 0, m, &hTable_62hDuIO0_sendMessage);
}

void Heavy_CircleStrings::cCast_FLrHY6v2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_ycCaMdEp, 0, m, &cDelay_ycCaMdEp_sendMessage);
}

void Heavy_CircleStrings::cMsg_VzcnSYAq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_Y6FjtKcR, 2, m, &cDelay_Y6FjtKcR_sendMessage);
}

void Heavy_CircleStrings::cMsg_ObG1Jab0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_IqaXUoUH, 1, m, NULL);
}

void Heavy_CircleStrings::cMsg_8SOPytuh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_CC06QuNa_sendMessage);
}

void Heavy_CircleStrings::cSystem_CC06QuNa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_RnAwQ9IY_sendMessage);
}

void Heavy_CircleStrings::cDelay_fURKbCBq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_fURKbCBq, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_2ifWIAsw, 0, m, &cDelay_2ifWIAsw_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_fURKbCBq, 0, m, &cDelay_fURKbCBq_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_vCdB43tf, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_2ifWIAsw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_2ifWIAsw, m);
  cMsg_1FzlgsS9_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_DJyAA6hE_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_n3d2TmRw_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_BbMVdwqv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_SppSqtCR_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_ic2BCxPF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_76hIGMmi_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_fURKbCBq, 2, m, &cDelay_fURKbCBq_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_iNgGhaa3_sendMessage);
}

void Heavy_CircleStrings::cMsg_SppSqtCR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_ic2BCxPF, 0, m, &hTable_ic2BCxPF_sendMessage);
}

void Heavy_CircleStrings::cBinop_RnAwQ9IY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 69.4325f, 0, m, &cBinop_BbMVdwqv_sendMessage);
}

void Heavy_CircleStrings::cMsg_1FzlgsS9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_ic2BCxPF, 0, m, &hTable_ic2BCxPF_sendMessage);
}

void Heavy_CircleStrings::cCast_iNgGhaa3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_fURKbCBq, 0, m, &cDelay_fURKbCBq_sendMessage);
}

void Heavy_CircleStrings::cMsg_76hIGMmi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_2ifWIAsw, 2, m, &cDelay_2ifWIAsw_sendMessage);
}

void Heavy_CircleStrings::cMsg_n3d2TmRw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_vCdB43tf, 1, m, NULL);
}

void Heavy_CircleStrings::cMsg_qA2HgMPK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_R4nFtH9i_sendMessage);
}

void Heavy_CircleStrings::cSystem_R4nFtH9i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_28uLHdDG_sendMessage);
}

void Heavy_CircleStrings::cDelay_ipCbEJIw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_ipCbEJIw, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Q5Ghcj2P, 0, m, &cDelay_Q5Ghcj2P_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ipCbEJIw, 0, m, &cDelay_ipCbEJIw_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_rgXxbEN7, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_Q5Ghcj2P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Q5Ghcj2P, m);
  cMsg_wPB3kBm6_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_VvCQy9f3_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_d8loH4fV_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_k7Uwf30l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_gSfAFwoL_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_a0KlujJP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_5Up2ZzKO_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ipCbEJIw, 2, m, &cDelay_ipCbEJIw_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_fcqBQa47_sendMessage);
}

void Heavy_CircleStrings::cMsg_gSfAFwoL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_a0KlujJP, 0, m, &hTable_a0KlujJP_sendMessage);
}

void Heavy_CircleStrings::cBinop_28uLHdDG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 74.5234f, 0, m, &cBinop_k7Uwf30l_sendMessage);
}

void Heavy_CircleStrings::cMsg_wPB3kBm6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_a0KlujJP, 0, m, &hTable_a0KlujJP_sendMessage);
}

void Heavy_CircleStrings::cCast_fcqBQa47_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_ipCbEJIw, 0, m, &cDelay_ipCbEJIw_sendMessage);
}

void Heavy_CircleStrings::cMsg_5Up2ZzKO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_Q5Ghcj2P, 2, m, &cDelay_Q5Ghcj2P_sendMessage);
}

void Heavy_CircleStrings::cMsg_d8loH4fV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_rgXxbEN7, 1, m, NULL);
}

void Heavy_CircleStrings::cMsg_wXGyi58e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_8NKO3fGP_sendMessage);
}

void Heavy_CircleStrings::cSystem_8NKO3fGP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_P2wAYlHM_sendMessage);
}

void Heavy_CircleStrings::cDelay_fzHSqhUd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_fzHSqhUd, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_MjcLHBAo, 0, m, &cDelay_MjcLHBAo_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_fzHSqhUd, 0, m, &cDelay_fzHSqhUd_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_INPjIsYP, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_MjcLHBAo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_MjcLHBAo, m);
  cMsg_g80mBoIx_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_s9MT6QwC_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_YahpVaoZ_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_uPYCvIGk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_7j52Rh00_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_NozjZiDX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_TiOXRYYD_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_fzHSqhUd, 2, m, &cDelay_fzHSqhUd_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_sDCkDF6O_sendMessage);
}

void Heavy_CircleStrings::cMsg_7j52Rh00_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_NozjZiDX, 0, m, &hTable_NozjZiDX_sendMessage);
}

void Heavy_CircleStrings::cBinop_P2wAYlHM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 86.1244f, 0, m, &cBinop_uPYCvIGk_sendMessage);
}

void Heavy_CircleStrings::cMsg_g80mBoIx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_NozjZiDX, 0, m, &hTable_NozjZiDX_sendMessage);
}

void Heavy_CircleStrings::cCast_sDCkDF6O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_fzHSqhUd, 0, m, &cDelay_fzHSqhUd_sendMessage);
}

void Heavy_CircleStrings::cMsg_TiOXRYYD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_MjcLHBAo, 2, m, &cDelay_MjcLHBAo_sendMessage);
}

void Heavy_CircleStrings::cMsg_YahpVaoZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_INPjIsYP, 1, m, NULL);
}

void Heavy_CircleStrings::cIf_Lbbr0aJB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_zHDpQrHp_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_cRErEG5U_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cMsg_V4UQqlbv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_PMicCRzf, HV_BINOP_POW, 0, m, &cBinop_PMicCRzf_sendMessage);
}

void Heavy_CircleStrings::cBinop_PMicCRzf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.125f, 0, m, &cBinop_ufZi9rnf_sendMessage);
}

void Heavy_CircleStrings::cBinop_uzSCqpk7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_vHKUBIyT_sendMessage);
}

void Heavy_CircleStrings::cCast_3FF5AE4y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_Lbbr0aJB, 0, m, &cIf_Lbbr0aJB_sendMessage);
}

void Heavy_CircleStrings::cCast_q93z0z3e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_at93SRJW_sendMessage);
}

void Heavy_CircleStrings::cBinop_at93SRJW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_Lbbr0aJB, 1, m, &cIf_Lbbr0aJB_sendMessage);
}

void Heavy_CircleStrings::cBinop_cRErEG5U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_uzSCqpk7_sendMessage);
}

void Heavy_CircleStrings::cMsg_zHDpQrHp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.125f, 0, m, &cBinop_ufZi9rnf_sendMessage);
}

void Heavy_CircleStrings::cBinop_vHKUBIyT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_PMicCRzf, HV_BINOP_POW, 1, m, &cBinop_PMicCRzf_sendMessage);
  cMsg_V4UQqlbv_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cPack_f89bIcHb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_Dm7v1JWx, 0, m, NULL);
}

void Heavy_CircleStrings::cPack_IMHAk3xx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_xU0GRrnN, 0, m, NULL);
}

void Heavy_CircleStrings::cBinop_rJSC6o3s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_vI0Wp9PM_sendMessage);
}

void Heavy_CircleStrings::cBinop_vI0Wp9PM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 200.0f, 0, m, &cBinop_yAXJqlgR_sendMessage);
}

void Heavy_CircleStrings::cVar_Cpd1irMP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_eDb4Vw1s, HV_BINOP_MULTIPLY, 0, m, &cBinop_eDb4Vw1s_sendMessage);
}

void Heavy_CircleStrings::cMsg_Ubi6Vcef_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_3IJh8PPV_sendMessage);
}

void Heavy_CircleStrings::cSystem_3IJh8PPV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_7pFaotRR_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_eDb4Vw1s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_IqqBsj2a_sendMessage);
}

void Heavy_CircleStrings::cBinop_Gmqx3SWg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_eDb4Vw1s, HV_BINOP_MULTIPLY, 1, m, &cBinop_eDb4Vw1s_sendMessage);
}

void Heavy_CircleStrings::cMsg_7pFaotRR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_Gmqx3SWg_sendMessage);
}

void Heavy_CircleStrings::cBinop_IqqBsj2a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_vslQ6WJa_sendMessage);
}

void Heavy_CircleStrings::cBinop_vslQ6WJa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_ljTaf727_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_Ay061GBp, m);
}

void Heavy_CircleStrings::cBinop_ljTaf727_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_kZCD107q, m);
}

void Heavy_CircleStrings::cVar_Wk4Ut97v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_q93z0z3e_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_3FF5AE4y_sendMessage);
}

void Heavy_CircleStrings::cVar_POglyt9T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 100.0f, 0, m, &cBinop_rJSC6o3s_sendMessage);
}

void Heavy_CircleStrings::cVar_q537VAx5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_cLg9olGc_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_Uar8IAEc, 0, m, &cIf_Uar8IAEc_sendMessage);
}

void Heavy_CircleStrings::cVar_aW7RwTuh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 100.0f, 0, m, &cBinop_1AyrgDju_sendMessage);
}

void Heavy_CircleStrings::cIf_Uar8IAEc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_f0wd269R_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cVar_onMessage(_c, &Context(_c)->cVar_uOkPvVs3, 0, m, &cVar_uOkPvVs3_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_cLg9olGc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_Uar8IAEc, 1, m, &cIf_Uar8IAEc_sendMessage);
}

void Heavy_CircleStrings::cBinop_1AyrgDju_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_AmvEV9zQ_sendMessage);
}

void Heavy_CircleStrings::cBinop_AmvEV9zQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_wHlgybfY, 0, m, &cVar_wHlgybfY_sendMessage);
}

void Heavy_CircleStrings::cTabhead_W12nQhiI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_9suFUNsd, HV_BINOP_SUBTRACT, 0, m, &cBinop_9suFUNsd_sendMessage);
}

void Heavy_CircleStrings::cMsg_q9hpsFpN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_3phc6tBi_sendMessage);
}

void Heavy_CircleStrings::cSystem_3phc6tBi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_b4J2AZYf_sendMessage);
}

void Heavy_CircleStrings::cVar_BdefvVic_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_XMYqvZgE_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_teCwDox1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_teCwDox1, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_35ZbNYTe, 0, m, &cDelay_35ZbNYTe_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_NQu5hP1y, 0, m, &sTabread_NQu5hP1y_sendMessage);
}

void Heavy_CircleStrings::cDelay_35ZbNYTe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_35ZbNYTe, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_NQu5hP1y, 0, m, &sTabread_NQu5hP1y_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_35ZbNYTe, 0, m, &cDelay_35ZbNYTe_sendMessage);
}

void Heavy_CircleStrings::sTabread_NQu5hP1y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_AAncTKcn, HV_BINOP_SUBTRACT, 0, m, &cBinop_AAncTKcn_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_MLOcEGeD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_YWI1gBaK, HV_BINOP_MAX, 0, m, &cBinop_YWI1gBaK_sendMessage);
}

void Heavy_CircleStrings::cBinop_b4J2AZYf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MLOcEGeD, HV_BINOP_MULTIPLY, 0, m, &cBinop_MLOcEGeD_sendMessage);
}

void Heavy_CircleStrings::cBinop_9suFUNsd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_tvTAxp6C_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_NQu5hP1y, 0, m, &sTabread_NQu5hP1y_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_FK5bZPTU_sendMessage);
}

void Heavy_CircleStrings::cSystem_X5sxwCQA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_AAncTKcn, HV_BINOP_SUBTRACT, 1, m, &cBinop_AAncTKcn_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_35ZbNYTe, 2, m, &cDelay_35ZbNYTe_sendMessage);
}

void Heavy_CircleStrings::cMsg_XMYqvZgE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_X5sxwCQA_sendMessage);
}

void Heavy_CircleStrings::cMsg_tvTAxp6C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_teCwDox1, 0, m, &cDelay_teCwDox1_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_35ZbNYTe, 0, m, &cDelay_35ZbNYTe_sendMessage);
}

void Heavy_CircleStrings::cMsg_BPFQPVKv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_YWI1gBaK, HV_BINOP_MAX, 1, m, &cBinop_YWI1gBaK_sendMessage);
}

void Heavy_CircleStrings::cBinop_YWI1gBaK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_9suFUNsd, HV_BINOP_SUBTRACT, 1, m, &cBinop_9suFUNsd_sendMessage);
}

void Heavy_CircleStrings::cCast_FK5bZPTU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_teCwDox1, 0, m, &cDelay_teCwDox1_sendMessage);
}

void Heavy_CircleStrings::cBinop_ZgqyV6zQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_teCwDox1, 2, m, &cDelay_teCwDox1_sendMessage);
}

void Heavy_CircleStrings::cBinop_AAncTKcn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_ZgqyV6zQ_sendMessage);
}

void Heavy_CircleStrings::cCast_ZyrGjsq9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_BdefvVic, 0, m, &cVar_BdefvVic_sendMessage);
  cMsg_q9hpsFpN_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_W12nQhiI, 0, m, &cTabhead_W12nQhiI_sendMessage);
}

void Heavy_CircleStrings::cMsg_6ni9pvkX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_E7HuyxtD_sendMessage);
}

void Heavy_CircleStrings::cSystem_E7HuyxtD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_sTn6AJO1_sendMessage);
}

void Heavy_CircleStrings::cDelay_8M1fqqGX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_8M1fqqGX, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_dqUKsgez, 0, m, &cDelay_dqUKsgez_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_8M1fqqGX, 0, m, &cDelay_8M1fqqGX_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_frPCoSZ3, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_dqUKsgez_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_dqUKsgez, m);
  cMsg_uOxI33yQ_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_ZgQjCcG7_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_SXqpb8Y2_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_DfSHjt8l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_qEPzRBkT_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_MDyfFE7k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ZX6uMtnC_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_8M1fqqGX, 2, m, &cDelay_8M1fqqGX_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_GGUh3Omr_sendMessage);
}

void Heavy_CircleStrings::cMsg_qEPzRBkT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_MDyfFE7k, 0, m, &hTable_MDyfFE7k_sendMessage);
}

void Heavy_CircleStrings::cBinop_sTn6AJO1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 13.645f, 0, m, &cBinop_DfSHjt8l_sendMessage);
}

void Heavy_CircleStrings::cMsg_uOxI33yQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_MDyfFE7k, 0, m, &hTable_MDyfFE7k_sendMessage);
}

void Heavy_CircleStrings::cCast_GGUh3Omr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_8M1fqqGX, 0, m, &cDelay_8M1fqqGX_sendMessage);
}

void Heavy_CircleStrings::cMsg_ZX6uMtnC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_dqUKsgez, 2, m, &cDelay_dqUKsgez_sendMessage);
}

void Heavy_CircleStrings::cMsg_SXqpb8Y2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_frPCoSZ3, 1, m, NULL);
}

void Heavy_CircleStrings::cTabhead_pFDGeXDK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_caRpDJL5, HV_BINOP_SUBTRACT, 0, m, &cBinop_caRpDJL5_sendMessage);
}

void Heavy_CircleStrings::cMsg_17H3yZWO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_cep8hbj7_sendMessage);
}

void Heavy_CircleStrings::cSystem_cep8hbj7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_Ho2Q854W_sendMessage);
}

void Heavy_CircleStrings::cVar_jYPWt4j5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_y4SzwNZr_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_cAjjYTAd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_cAjjYTAd, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_WK7cBIkV, 0, m, &cDelay_WK7cBIkV_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_lPXorp1b, 0, m, &sTabread_lPXorp1b_sendMessage);
}

void Heavy_CircleStrings::cDelay_WK7cBIkV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_WK7cBIkV, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_lPXorp1b, 0, m, &sTabread_lPXorp1b_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_WK7cBIkV, 0, m, &cDelay_WK7cBIkV_sendMessage);
}

void Heavy_CircleStrings::sTabread_lPXorp1b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_YlLBoPVj, HV_BINOP_SUBTRACT, 0, m, &cBinop_YlLBoPVj_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_GWklnQoo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Dp3QFw5T, HV_BINOP_MAX, 0, m, &cBinop_Dp3QFw5T_sendMessage);
}

void Heavy_CircleStrings::cBinop_Ho2Q854W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_GWklnQoo, HV_BINOP_MULTIPLY, 0, m, &cBinop_GWklnQoo_sendMessage);
}

void Heavy_CircleStrings::cBinop_caRpDJL5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_tInNPTSU_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_lPXorp1b, 0, m, &sTabread_lPXorp1b_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_tPWqVLag_sendMessage);
}

void Heavy_CircleStrings::cSystem_HalfnJoE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_YlLBoPVj, HV_BINOP_SUBTRACT, 1, m, &cBinop_YlLBoPVj_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_WK7cBIkV, 2, m, &cDelay_WK7cBIkV_sendMessage);
}

void Heavy_CircleStrings::cMsg_y4SzwNZr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_HalfnJoE_sendMessage);
}

void Heavy_CircleStrings::cMsg_tInNPTSU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_cAjjYTAd, 0, m, &cDelay_cAjjYTAd_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_WK7cBIkV, 0, m, &cDelay_WK7cBIkV_sendMessage);
}

void Heavy_CircleStrings::cMsg_4FapKxJ7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_Dp3QFw5T, HV_BINOP_MAX, 1, m, &cBinop_Dp3QFw5T_sendMessage);
}

void Heavy_CircleStrings::cBinop_Dp3QFw5T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_caRpDJL5, HV_BINOP_SUBTRACT, 1, m, &cBinop_caRpDJL5_sendMessage);
}

void Heavy_CircleStrings::cCast_tPWqVLag_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_cAjjYTAd, 0, m, &cDelay_cAjjYTAd_sendMessage);
}

void Heavy_CircleStrings::cBinop_N5lxoYod_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_cAjjYTAd, 2, m, &cDelay_cAjjYTAd_sendMessage);
}

void Heavy_CircleStrings::cBinop_YlLBoPVj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_N5lxoYod_sendMessage);
}

void Heavy_CircleStrings::cCast_mrnRtM7z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_jYPWt4j5, 0, m, &cVar_jYPWt4j5_sendMessage);
  cMsg_17H3yZWO_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_pFDGeXDK, 0, m, &cTabhead_pFDGeXDK_sendMessage);
}

void Heavy_CircleStrings::cMsg_CxemCxti_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_prx05T5t_sendMessage);
}

void Heavy_CircleStrings::cSystem_prx05T5t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_3bvpsz2O_sendMessage);
}

void Heavy_CircleStrings::cDelay_5NCkIlAO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_5NCkIlAO, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_1FCU5FtI, 0, m, &cDelay_1FCU5FtI_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_5NCkIlAO, 0, m, &cDelay_5NCkIlAO_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_dyRlqrv2, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_1FCU5FtI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_1FCU5FtI, m);
  cMsg_quRaj4ox_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_dpICfr7c_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_yvAUSDxj_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_HMom5Yin_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_GFZVmFkR_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_UDmNhHRL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_p5Rtz5Un_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_5NCkIlAO, 2, m, &cDelay_5NCkIlAO_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_4921suN2_sendMessage);
}

void Heavy_CircleStrings::cMsg_GFZVmFkR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_UDmNhHRL, 0, m, &hTable_UDmNhHRL_sendMessage);
}

void Heavy_CircleStrings::cBinop_3bvpsz2O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 16.364f, 0, m, &cBinop_HMom5Yin_sendMessage);
}

void Heavy_CircleStrings::cMsg_quRaj4ox_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_UDmNhHRL, 0, m, &hTable_UDmNhHRL_sendMessage);
}

void Heavy_CircleStrings::cCast_4921suN2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_5NCkIlAO, 0, m, &cDelay_5NCkIlAO_sendMessage);
}

void Heavy_CircleStrings::cMsg_p5Rtz5Un_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_1FCU5FtI, 2, m, &cDelay_1FCU5FtI_sendMessage);
}

void Heavy_CircleStrings::cMsg_yvAUSDxj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_dyRlqrv2, 1, m, NULL);
}

void Heavy_CircleStrings::cTabhead_SJU0AhS9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_q8G36MYb, HV_BINOP_SUBTRACT, 0, m, &cBinop_q8G36MYb_sendMessage);
}

void Heavy_CircleStrings::cMsg_pdQWnZOq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_fIGsP1sS_sendMessage);
}

void Heavy_CircleStrings::cSystem_fIGsP1sS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_3KlqKYwl_sendMessage);
}

void Heavy_CircleStrings::cVar_6RaAIoMM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_VMBaBdQw_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_Ra3EwIrS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Ra3EwIrS, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Zdqypl3Q, 0, m, &cDelay_Zdqypl3Q_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_yJRpdmxp, 0, m, &sTabread_yJRpdmxp_sendMessage);
}

void Heavy_CircleStrings::cDelay_Zdqypl3Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Zdqypl3Q, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_yJRpdmxp, 0, m, &sTabread_yJRpdmxp_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Zdqypl3Q, 0, m, &cDelay_Zdqypl3Q_sendMessage);
}

void Heavy_CircleStrings::sTabread_yJRpdmxp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_PO94euK0, HV_BINOP_SUBTRACT, 0, m, &cBinop_PO94euK0_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_mFexVCMv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_g7OjrY6Z, HV_BINOP_MAX, 0, m, &cBinop_g7OjrY6Z_sendMessage);
}

void Heavy_CircleStrings::cBinop_3KlqKYwl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_mFexVCMv, HV_BINOP_MULTIPLY, 0, m, &cBinop_mFexVCMv_sendMessage);
}

void Heavy_CircleStrings::cBinop_q8G36MYb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_aN5kvguU_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_yJRpdmxp, 0, m, &sTabread_yJRpdmxp_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_CpEYnGb2_sendMessage);
}

void Heavy_CircleStrings::cSystem_bITKaYHi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_PO94euK0, HV_BINOP_SUBTRACT, 1, m, &cBinop_PO94euK0_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Zdqypl3Q, 2, m, &cDelay_Zdqypl3Q_sendMessage);
}

void Heavy_CircleStrings::cMsg_VMBaBdQw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_bITKaYHi_sendMessage);
}

void Heavy_CircleStrings::cMsg_aN5kvguU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_Ra3EwIrS, 0, m, &cDelay_Ra3EwIrS_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Zdqypl3Q, 0, m, &cDelay_Zdqypl3Q_sendMessage);
}

void Heavy_CircleStrings::cMsg_rRJqojfJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_g7OjrY6Z, HV_BINOP_MAX, 1, m, &cBinop_g7OjrY6Z_sendMessage);
}

void Heavy_CircleStrings::cBinop_g7OjrY6Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_q8G36MYb, HV_BINOP_SUBTRACT, 1, m, &cBinop_q8G36MYb_sendMessage);
}

void Heavy_CircleStrings::cCast_CpEYnGb2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Ra3EwIrS, 0, m, &cDelay_Ra3EwIrS_sendMessage);
}

void Heavy_CircleStrings::cBinop_h95uoFhk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Ra3EwIrS, 2, m, &cDelay_Ra3EwIrS_sendMessage);
}

void Heavy_CircleStrings::cBinop_PO94euK0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_h95uoFhk_sendMessage);
}

void Heavy_CircleStrings::cCast_FWDbBCks_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_6RaAIoMM, 0, m, &cVar_6RaAIoMM_sendMessage);
  cMsg_pdQWnZOq_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_SJU0AhS9, 0, m, &cTabhead_SJU0AhS9_sendMessage);
}

void Heavy_CircleStrings::cMsg_DL2p9fa2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_a0hgWqfg_sendMessage);
}

void Heavy_CircleStrings::cSystem_a0hgWqfg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_Wc7Meian_sendMessage);
}

void Heavy_CircleStrings::cDelay_mBEraUQY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_mBEraUQY, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_b5rA6Ok7, 0, m, &cDelay_b5rA6Ok7_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_mBEraUQY, 0, m, &cDelay_mBEraUQY_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_EEcxaAkq, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_b5rA6Ok7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_b5rA6Ok7, m);
  cMsg_0lY0BUI9_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_6DZlc9hX_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_tRMo5fEV_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_KwdTWWyr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_yAqRSaMq_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_d6NDtEiX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_epSrZHE0_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_mBEraUQY, 2, m, &cDelay_mBEraUQY_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_CvnyZ671_sendMessage);
}

void Heavy_CircleStrings::cMsg_yAqRSaMq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_d6NDtEiX, 0, m, &hTable_d6NDtEiX_sendMessage);
}

void Heavy_CircleStrings::cBinop_Wc7Meian_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 19.392f, 0, m, &cBinop_KwdTWWyr_sendMessage);
}

void Heavy_CircleStrings::cMsg_0lY0BUI9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_d6NDtEiX, 0, m, &hTable_d6NDtEiX_sendMessage);
}

void Heavy_CircleStrings::cCast_CvnyZ671_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_mBEraUQY, 0, m, &cDelay_mBEraUQY_sendMessage);
}

void Heavy_CircleStrings::cMsg_epSrZHE0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_b5rA6Ok7, 2, m, &cDelay_b5rA6Ok7_sendMessage);
}

void Heavy_CircleStrings::cMsg_tRMo5fEV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_EEcxaAkq, 1, m, NULL);
}

void Heavy_CircleStrings::cTabhead_RjkRPhh7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_RYpawCal, HV_BINOP_SUBTRACT, 0, m, &cBinop_RYpawCal_sendMessage);
}

void Heavy_CircleStrings::cMsg_jGeb9EEa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_8GhJkRCr_sendMessage);
}

void Heavy_CircleStrings::cSystem_8GhJkRCr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_1JEbB80K_sendMessage);
}

void Heavy_CircleStrings::cVar_rSqpGWhk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ZenbTH8f_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_zCKPFSaT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_zCKPFSaT, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_gMysgU3O, 0, m, &cDelay_gMysgU3O_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_ezpmAwAi, 0, m, &sTabread_ezpmAwAi_sendMessage);
}

void Heavy_CircleStrings::cDelay_gMysgU3O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_gMysgU3O, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_ezpmAwAi, 0, m, &sTabread_ezpmAwAi_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_gMysgU3O, 0, m, &cDelay_gMysgU3O_sendMessage);
}

void Heavy_CircleStrings::sTabread_ezpmAwAi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_FDFK0hjD, HV_BINOP_SUBTRACT, 0, m, &cBinop_FDFK0hjD_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_pSk6ZQDh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_QIfY8q4O, HV_BINOP_MAX, 0, m, &cBinop_QIfY8q4O_sendMessage);
}

void Heavy_CircleStrings::cBinop_1JEbB80K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_pSk6ZQDh, HV_BINOP_MULTIPLY, 0, m, &cBinop_pSk6ZQDh_sendMessage);
}

void Heavy_CircleStrings::cBinop_RYpawCal_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_SQd9FOIE_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_ezpmAwAi, 0, m, &sTabread_ezpmAwAi_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_d5700nWv_sendMessage);
}

void Heavy_CircleStrings::cSystem_kawLNK8T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_FDFK0hjD, HV_BINOP_SUBTRACT, 1, m, &cBinop_FDFK0hjD_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_gMysgU3O, 2, m, &cDelay_gMysgU3O_sendMessage);
}

void Heavy_CircleStrings::cMsg_ZenbTH8f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_kawLNK8T_sendMessage);
}

void Heavy_CircleStrings::cMsg_SQd9FOIE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_zCKPFSaT, 0, m, &cDelay_zCKPFSaT_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_gMysgU3O, 0, m, &cDelay_gMysgU3O_sendMessage);
}

void Heavy_CircleStrings::cMsg_ucUf09nE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_QIfY8q4O, HV_BINOP_MAX, 1, m, &cBinop_QIfY8q4O_sendMessage);
}

void Heavy_CircleStrings::cBinop_QIfY8q4O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_RYpawCal, HV_BINOP_SUBTRACT, 1, m, &cBinop_RYpawCal_sendMessage);
}

void Heavy_CircleStrings::cCast_d5700nWv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_zCKPFSaT, 0, m, &cDelay_zCKPFSaT_sendMessage);
}

void Heavy_CircleStrings::cBinop_iax2sDDX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_zCKPFSaT, 2, m, &cDelay_zCKPFSaT_sendMessage);
}

void Heavy_CircleStrings::cBinop_FDFK0hjD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_iax2sDDX_sendMessage);
}

void Heavy_CircleStrings::cCast_FsO8yDHF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_rSqpGWhk, 0, m, &cVar_rSqpGWhk_sendMessage);
  cMsg_jGeb9EEa_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_RjkRPhh7, 0, m, &cTabhead_RjkRPhh7_sendMessage);
}

void Heavy_CircleStrings::cMsg_DByq07I6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_S5CihN1e_sendMessage);
}

void Heavy_CircleStrings::cSystem_S5CihN1e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_LmNcwaOV_sendMessage);
}

void Heavy_CircleStrings::cDelay_0PivsHSF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_0PivsHSF, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_9dikc2t3, 0, m, &cDelay_9dikc2t3_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_0PivsHSF, 0, m, &cDelay_0PivsHSF_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_ZGT5NuOT, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_9dikc2t3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_9dikc2t3, m);
  cMsg_nrQmPcu9_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_r8FhhcXs_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_10yUQhSl_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_Cq1P8lYa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ndDyTrbX_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_Rfr27aWp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_84NQFjla_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_0PivsHSF, 2, m, &cDelay_0PivsHSF_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Xc8jbpX9_sendMessage);
}

void Heavy_CircleStrings::cMsg_ndDyTrbX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_Rfr27aWp, 0, m, &hTable_Rfr27aWp_sendMessage);
}

void Heavy_CircleStrings::cBinop_LmNcwaOV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 25.796f, 0, m, &cBinop_Cq1P8lYa_sendMessage);
}

void Heavy_CircleStrings::cMsg_nrQmPcu9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_Rfr27aWp, 0, m, &hTable_Rfr27aWp_sendMessage);
}

void Heavy_CircleStrings::cCast_Xc8jbpX9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_0PivsHSF, 0, m, &cDelay_0PivsHSF_sendMessage);
}

void Heavy_CircleStrings::cMsg_84NQFjla_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_9dikc2t3, 2, m, &cDelay_9dikc2t3_sendMessage);
}

void Heavy_CircleStrings::cMsg_10yUQhSl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_ZGT5NuOT, 1, m, NULL);
}

void Heavy_CircleStrings::cTabhead_IDWB45r9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_U69frbgf, HV_BINOP_SUBTRACT, 0, m, &cBinop_U69frbgf_sendMessage);
}

void Heavy_CircleStrings::cMsg_EaFMODOK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_1oGUyqwn_sendMessage);
}

void Heavy_CircleStrings::cSystem_1oGUyqwn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_Qh0e8AtP_sendMessage);
}

void Heavy_CircleStrings::cVar_7zeNrBua_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_69tUqVPk_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_ZEeFLkqp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_ZEeFLkqp, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_UYMMXjtm, 0, m, &cDelay_UYMMXjtm_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_etC13G1g, 0, m, &sTabread_etC13G1g_sendMessage);
}

void Heavy_CircleStrings::cDelay_UYMMXjtm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_UYMMXjtm, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_etC13G1g, 0, m, &sTabread_etC13G1g_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_UYMMXjtm, 0, m, &cDelay_UYMMXjtm_sendMessage);
}

void Heavy_CircleStrings::sTabread_etC13G1g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_2uOy5l0S, HV_BINOP_SUBTRACT, 0, m, &cBinop_2uOy5l0S_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_sS1sypQH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_auaUy3C1, HV_BINOP_MAX, 0, m, &cBinop_auaUy3C1_sendMessage);
}

void Heavy_CircleStrings::cBinop_Qh0e8AtP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_sS1sypQH, HV_BINOP_MULTIPLY, 0, m, &cBinop_sS1sypQH_sendMessage);
}

void Heavy_CircleStrings::cBinop_U69frbgf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_MGUy5s3x_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_etC13G1g, 0, m, &sTabread_etC13G1g_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ZpxrhUB0_sendMessage);
}

void Heavy_CircleStrings::cSystem_WyG9NTt1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_2uOy5l0S, HV_BINOP_SUBTRACT, 1, m, &cBinop_2uOy5l0S_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_UYMMXjtm, 2, m, &cDelay_UYMMXjtm_sendMessage);
}

void Heavy_CircleStrings::cMsg_69tUqVPk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_WyG9NTt1_sendMessage);
}

void Heavy_CircleStrings::cMsg_MGUy5s3x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_ZEeFLkqp, 0, m, &cDelay_ZEeFLkqp_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_UYMMXjtm, 0, m, &cDelay_UYMMXjtm_sendMessage);
}

void Heavy_CircleStrings::cMsg_Sz6iUFMX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_auaUy3C1, HV_BINOP_MAX, 1, m, &cBinop_auaUy3C1_sendMessage);
}

void Heavy_CircleStrings::cBinop_auaUy3C1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_U69frbgf, HV_BINOP_SUBTRACT, 1, m, &cBinop_U69frbgf_sendMessage);
}

void Heavy_CircleStrings::cCast_ZpxrhUB0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_ZEeFLkqp, 0, m, &cDelay_ZEeFLkqp_sendMessage);
}

void Heavy_CircleStrings::cBinop_ZsVTe8Yq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_ZEeFLkqp, 2, m, &cDelay_ZEeFLkqp_sendMessage);
}

void Heavy_CircleStrings::cBinop_2uOy5l0S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_ZsVTe8Yq_sendMessage);
}

void Heavy_CircleStrings::cCast_GkabsELm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_7zeNrBua, 0, m, &cVar_7zeNrBua_sendMessage);
  cMsg_EaFMODOK_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_IDWB45r9, 0, m, &cTabhead_IDWB45r9_sendMessage);
}

void Heavy_CircleStrings::cMsg_sQL8yL4q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_DbFO1835_sendMessage);
}

void Heavy_CircleStrings::cSystem_DbFO1835_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_19tjmkO4_sendMessage);
}

void Heavy_CircleStrings::cDelay_ijqxhDxI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_ijqxhDxI, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_cmxuNVEJ, 0, m, &cDelay_cmxuNVEJ_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ijqxhDxI, 0, m, &cDelay_ijqxhDxI_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_CoTpm3wp, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_cmxuNVEJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_cmxuNVEJ, m);
  cMsg_M5rD99kh_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_wGGA7raO_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_TTouvWs3_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_Pn6z7B90_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_SRBVtnOH_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_KuGU5Jpc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ygLB9Y49_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ijqxhDxI, 2, m, &cDelay_ijqxhDxI_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_4m48GnAd_sendMessage);
}

void Heavy_CircleStrings::cMsg_SRBVtnOH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_KuGU5Jpc, 0, m, &hTable_KuGU5Jpc_sendMessage);
}

void Heavy_CircleStrings::cBinop_19tjmkO4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 43.5337f, 0, m, &cBinop_Pn6z7B90_sendMessage);
}

void Heavy_CircleStrings::cMsg_M5rD99kh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_KuGU5Jpc, 0, m, &hTable_KuGU5Jpc_sendMessage);
}

void Heavy_CircleStrings::cCast_4m48GnAd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_ijqxhDxI, 0, m, &cDelay_ijqxhDxI_sendMessage);
}

void Heavy_CircleStrings::cMsg_ygLB9Y49_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_cmxuNVEJ, 2, m, &cDelay_cmxuNVEJ_sendMessage);
}

void Heavy_CircleStrings::cMsg_TTouvWs3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_CoTpm3wp, 1, m, NULL);
}

void Heavy_CircleStrings::cTabhead_8wBSygWM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_FB5UBd4T, HV_BINOP_SUBTRACT, 0, m, &cBinop_FB5UBd4T_sendMessage);
}

void Heavy_CircleStrings::cMsg_r9pykefT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Lb7Ux2UT_sendMessage);
}

void Heavy_CircleStrings::cSystem_Lb7Ux2UT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_YYDAsRjd_sendMessage);
}

void Heavy_CircleStrings::cVar_mSWPORcU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_6Xg2SY42_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_sIbDxW4h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_sIbDxW4h, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_alYA2iHS, 0, m, &cDelay_alYA2iHS_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_6VyhQ8l7, 0, m, &sTabread_6VyhQ8l7_sendMessage);
}

void Heavy_CircleStrings::cDelay_alYA2iHS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_alYA2iHS, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_6VyhQ8l7, 0, m, &sTabread_6VyhQ8l7_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_alYA2iHS, 0, m, &cDelay_alYA2iHS_sendMessage);
}

void Heavy_CircleStrings::sTabread_6VyhQ8l7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_aK7KnSMd, HV_BINOP_SUBTRACT, 0, m, &cBinop_aK7KnSMd_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_BDvBEZDy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_9AQzGy4Y, HV_BINOP_MAX, 0, m, &cBinop_9AQzGy4Y_sendMessage);
}

void Heavy_CircleStrings::cBinop_YYDAsRjd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_BDvBEZDy, HV_BINOP_MULTIPLY, 0, m, &cBinop_BDvBEZDy_sendMessage);
}

void Heavy_CircleStrings::cBinop_FB5UBd4T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_XAMLy2eR_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_6VyhQ8l7, 0, m, &sTabread_6VyhQ8l7_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_W8Q8jh01_sendMessage);
}

void Heavy_CircleStrings::cSystem_uEm76CMU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_aK7KnSMd, HV_BINOP_SUBTRACT, 1, m, &cBinop_aK7KnSMd_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_alYA2iHS, 2, m, &cDelay_alYA2iHS_sendMessage);
}

void Heavy_CircleStrings::cMsg_6Xg2SY42_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_uEm76CMU_sendMessage);
}

void Heavy_CircleStrings::cMsg_XAMLy2eR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_sIbDxW4h, 0, m, &cDelay_sIbDxW4h_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_alYA2iHS, 0, m, &cDelay_alYA2iHS_sendMessage);
}

void Heavy_CircleStrings::cMsg_TZE8jh1U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_9AQzGy4Y, HV_BINOP_MAX, 1, m, &cBinop_9AQzGy4Y_sendMessage);
}

void Heavy_CircleStrings::cBinop_9AQzGy4Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_FB5UBd4T, HV_BINOP_SUBTRACT, 1, m, &cBinop_FB5UBd4T_sendMessage);
}

void Heavy_CircleStrings::cCast_W8Q8jh01_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_sIbDxW4h, 0, m, &cDelay_sIbDxW4h_sendMessage);
}

void Heavy_CircleStrings::cBinop_NNlz5foO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_sIbDxW4h, 2, m, &cDelay_sIbDxW4h_sendMessage);
}

void Heavy_CircleStrings::cBinop_aK7KnSMd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_NNlz5foO_sendMessage);
}

void Heavy_CircleStrings::cCast_XBIPzAau_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_mSWPORcU, 0, m, &cVar_mSWPORcU_sendMessage);
  cMsg_r9pykefT_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_8wBSygWM, 0, m, &cTabhead_8wBSygWM_sendMessage);
}

void Heavy_CircleStrings::cMsg_RSqoNwlV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_R0QyBaRM_sendMessage);
}

void Heavy_CircleStrings::cSystem_R0QyBaRM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_mNvjRU7H_sendMessage);
}

void Heavy_CircleStrings::cDelay_8qLrD0hh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_8qLrD0hh, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_854wOtGx, 0, m, &cDelay_854wOtGx_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_8qLrD0hh, 0, m, &cDelay_8qLrD0hh_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_SPOqW7ds, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_854wOtGx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_854wOtGx, m);
  cMsg_76TPDove_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_CZvm7EnZ_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_O2daSmZ2_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_nPfJeAsg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_nyPfZWXS_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_bcdDm4fS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_VPnz6S5q_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_8qLrD0hh, 2, m, &cDelay_8qLrD0hh_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_tNwbL0C1_sendMessage);
}

void Heavy_CircleStrings::cMsg_nyPfZWXS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_bcdDm4fS, 0, m, &hTable_bcdDm4fS_sendMessage);
}

void Heavy_CircleStrings::cBinop_mNvjRU7H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 75.2546f, 0, m, &cBinop_nPfJeAsg_sendMessage);
}

void Heavy_CircleStrings::cMsg_76TPDove_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_bcdDm4fS, 0, m, &hTable_bcdDm4fS_sendMessage);
}

void Heavy_CircleStrings::cCast_tNwbL0C1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_8qLrD0hh, 0, m, &cDelay_8qLrD0hh_sendMessage);
}

void Heavy_CircleStrings::cMsg_VPnz6S5q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_854wOtGx, 2, m, &cDelay_854wOtGx_sendMessage);
}

void Heavy_CircleStrings::cMsg_O2daSmZ2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_SPOqW7ds, 1, m, NULL);
}

void Heavy_CircleStrings::cVar_uOkPvVs3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Cpd1irMP, 0, m, &cVar_Cpd1irMP_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_HnAqA7yD, 0, m, &cVar_HnAqA7yD_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_xCK4ZhN0, 0, m, &cVar_xCK4ZhN0_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_SjAvNGPm, 0, m, &cVar_SjAvNGPm_sendMessage);
}

void Heavy_CircleStrings::cVar_wHlgybfY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.01f, 0, m, &cBinop_eTFhqfW8_sendMessage);
}

void Heavy_CircleStrings::cPack_1Sx0Kv6j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_r1mxZfA7, 0, m, NULL);
}

void Heavy_CircleStrings::cVar_HnAqA7yD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Rn2sqEfs, HV_BINOP_MULTIPLY, 0, m, &cBinop_Rn2sqEfs_sendMessage);
}

void Heavy_CircleStrings::cMsg_669bFNut_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_0cEtLJ8h_sendMessage);
}

void Heavy_CircleStrings::cSystem_0cEtLJ8h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_M9F8cBiJ_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_Rn2sqEfs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_dSOQxO08_sendMessage);
}

void Heavy_CircleStrings::cBinop_mOaSopLn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Rn2sqEfs, HV_BINOP_MULTIPLY, 1, m, &cBinop_Rn2sqEfs_sendMessage);
}

void Heavy_CircleStrings::cMsg_M9F8cBiJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_mOaSopLn_sendMessage);
}

void Heavy_CircleStrings::cBinop_dSOQxO08_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_3oHOZ6Da_sendMessage);
}

void Heavy_CircleStrings::cBinop_3oHOZ6Da_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_No61E8Ib_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_G1n7slCX, m);
}

void Heavy_CircleStrings::cBinop_No61E8Ib_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_TvRuAm6w, m);
}

void Heavy_CircleStrings::cVar_xCK4ZhN0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_unLTGUPq, HV_BINOP_MULTIPLY, 0, m, &cBinop_unLTGUPq_sendMessage);
}

void Heavy_CircleStrings::cMsg_hapuUYAE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_xoSutX2x_sendMessage);
}

void Heavy_CircleStrings::cSystem_xoSutX2x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_5Scz1IW3_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_unLTGUPq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_yKcyp9c2_sendMessage);
}

void Heavy_CircleStrings::cBinop_QkNP1i6W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_unLTGUPq, HV_BINOP_MULTIPLY, 1, m, &cBinop_unLTGUPq_sendMessage);
}

void Heavy_CircleStrings::cMsg_5Scz1IW3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_QkNP1i6W_sendMessage);
}

void Heavy_CircleStrings::cBinop_yKcyp9c2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_VHw4MVKm_sendMessage);
}

void Heavy_CircleStrings::cBinop_VHw4MVKm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_PRGhJcNt_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_GyyKHMIl, m);
}

void Heavy_CircleStrings::cBinop_PRGhJcNt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_grSayqOn, m);
}

void Heavy_CircleStrings::cVar_SjAvNGPm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_D6w9o1j3, HV_BINOP_MULTIPLY, 0, m, &cBinop_D6w9o1j3_sendMessage);
}

void Heavy_CircleStrings::cMsg_jqArntBR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_9Y278FcG_sendMessage);
}

void Heavy_CircleStrings::cSystem_9Y278FcG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_QfvuDiSw_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_D6w9o1j3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_8ajkr9Fx_sendMessage);
}

void Heavy_CircleStrings::cBinop_Dwtxl6WS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_D6w9o1j3, HV_BINOP_MULTIPLY, 1, m, &cBinop_D6w9o1j3_sendMessage);
}

void Heavy_CircleStrings::cMsg_QfvuDiSw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_Dwtxl6WS_sendMessage);
}

void Heavy_CircleStrings::cBinop_8ajkr9Fx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_b1G7N6tN_sendMessage);
}

void Heavy_CircleStrings::cBinop_b1G7N6tN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_BsTe4Opd_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_t7Y9nR5L, m);
}

void Heavy_CircleStrings::cBinop_BsTe4Opd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_nhH1AUje, m);
}

void Heavy_CircleStrings::cBinop_yAXJqlgR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_IMHAk3xx, 0, m, &cPack_IMHAk3xx_sendMessage);
}

void Heavy_CircleStrings::cMsg_f0wd269R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 3000.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_uOkPvVs3, 0, m, &cVar_uOkPvVs3_sendMessage);
}

void Heavy_CircleStrings::cBinop_eTFhqfW8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_1Sx0Kv6j, 0, m, &cPack_1Sx0Kv6j_sendMessage);
}

void Heavy_CircleStrings::cBinop_ufZi9rnf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_f89bIcHb, 0, m, &cPack_f89bIcHb_sendMessage);
}

void Heavy_CircleStrings::cIf_rz6Zb8BJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_eIsw2bZQ_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_LOG10, m, &cUnop_VfNcGEPj_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cUnop_VfNcGEPj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_QB2r3qoF_sendMessage);
}

void Heavy_CircleStrings::cCast_lTZUKjs6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_rz6Zb8BJ, 0, m, &cIf_rz6Zb8BJ_sendMessage);
}

void Heavy_CircleStrings::cCast_i9HJymI7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_sKaOk8nM_sendMessage);
}

void Heavy_CircleStrings::cMsg_eIsw2bZQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_Wk4Ut97v, 0, m, &cVar_Wk4Ut97v_sendMessage);
}

void Heavy_CircleStrings::cBinop_QB2r3qoF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 100.0f, 0, m, &cBinop_MzRPx9mZ_sendMessage);
}

void Heavy_CircleStrings::cBinop_MzRPx9mZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_jkV86pWj_sendMessage);
}

void Heavy_CircleStrings::cBinop_jkV86pWj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Wk4Ut97v, 0, m, &cVar_Wk4Ut97v_sendMessage);
}

void Heavy_CircleStrings::cBinop_sKaOk8nM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_rz6Zb8BJ, 1, m, &cIf_rz6Zb8BJ_sendMessage);
}

void Heavy_CircleStrings::cBinop_auGFldsf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_i9HJymI7_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_lTZUKjs6_sendMessage);
}

void Heavy_CircleStrings::cBinop_qSpD0SPI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_auGFldsf_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_7WmnV7kO_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_k4mA78lf_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_k4mA78lf_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_QLShzJlS, 1, m, &cDelay_QLShzJlS_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_xv0dFDjg_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cDelay_QLShzJlS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_QLShzJlS, m);
  cMsg_Je3B7m9d_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_k4mA78lf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_QLShzJlS, 0, m, &cDelay_QLShzJlS_sendMessage);
}

void Heavy_CircleStrings::cCast_xv0dFDjg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_QLShzJlS, 0, m, &cDelay_QLShzJlS_sendMessage);
}

void Heavy_CircleStrings::cVar_Mn0n43Rb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_9yqCXNnu, 0, m, &cPack_9yqCXNnu_sendMessage);
}

void Heavy_CircleStrings::cVar_O8ScjlCf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.05776f, 0, m, &cBinop_KlthMgMR_sendMessage);
}

void Heavy_CircleStrings::cVar_RixifLWy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_VBe2dWSy_sendMessage);
}

void Heavy_CircleStrings::cPack_nuZVo1Wl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_2pwa6h8r, 0, m, NULL);
}

void Heavy_CircleStrings::cUnop_4EVNMrmO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_6ZEzFwQo_sendMessage);
}

void Heavy_CircleStrings::cBinop_xKAAz0Vu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_EXP, m, &cUnop_4EVNMrmO_sendMessage);
}

void Heavy_CircleStrings::cPack_L6PZHb9X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_txO1buxi, 0, m, NULL);
}

void Heavy_CircleStrings::cVar_qeaeQjYg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.5f, 0, m, &cBinop_oYQGhUkd_sendMessage);
}

void Heavy_CircleStrings::cMsg_npSfMmxn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_2A5uMAsX_sendMessage);
}

void Heavy_CircleStrings::cSystem_2A5uMAsX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_CzBRy0RF_sendMessage);
}

void Heavy_CircleStrings::cDelay_Rqe1Qiyh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Rqe1Qiyh, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_OX134EPe, 0, m, &cDelay_OX134EPe_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Rqe1Qiyh, 0, m, &cDelay_Rqe1Qiyh_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_mBOpqpai, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_OX134EPe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_OX134EPe, m);
  cMsg_J5ZVkDIb_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_iXliSpfg_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_RzqS3JRM_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_VBXvB3jw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_qwbUn3yv_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_lolUrs0K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Vo0gZJfv_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Rqe1Qiyh, 2, m, &cDelay_Rqe1Qiyh_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_vDzvj8Mt_sendMessage);
}

void Heavy_CircleStrings::cMsg_qwbUn3yv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_lolUrs0K, 0, m, &hTable_lolUrs0K_sendMessage);
}

void Heavy_CircleStrings::cBinop_CzBRy0RF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 5000.0f, 0, m, &cBinop_VBXvB3jw_sendMessage);
}

void Heavy_CircleStrings::cMsg_J5ZVkDIb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_lolUrs0K, 0, m, &hTable_lolUrs0K_sendMessage);
}

void Heavy_CircleStrings::cCast_vDzvj8Mt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Rqe1Qiyh, 0, m, &cDelay_Rqe1Qiyh_sendMessage);
}

void Heavy_CircleStrings::cMsg_Vo0gZJfv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_OX134EPe, 2, m, &cDelay_OX134EPe_sendMessage);
}

void Heavy_CircleStrings::cMsg_RzqS3JRM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_mBOpqpai, 1, m, NULL);
}

void Heavy_CircleStrings::cMsg_ps3UHWjg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_OC7sAmct_sendMessage);
}

void Heavy_CircleStrings::cSystem_OC7sAmct_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_FqjSaai0_sendMessage);
}

void Heavy_CircleStrings::cVar_TD1mAJWS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_WZzp7Nyf_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSystem_PiFJsASH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_q4rvmu0P_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_rsAhOaTe, m);
}

void Heavy_CircleStrings::cBinop_FqjSaai0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_mZ8IKVM3, m);
}

void Heavy_CircleStrings::cMsg_WZzp7Nyf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_PiFJsASH_sendMessage);
}

void Heavy_CircleStrings::cBinop_q4rvmu0P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_s6Oie7e9, m);
}

void Heavy_CircleStrings::cMsg_G3Hw7DZY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_hBJV5h8U_sendMessage);
}

void Heavy_CircleStrings::cSystem_hBJV5h8U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_qTA0Li6X_sendMessage);
}

void Heavy_CircleStrings::cVar_Zhuzvvft_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_TJsear7x_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSystem_BlSrUVJo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_tHarU4p4_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_R0yv6RKX, m);
}

void Heavy_CircleStrings::cBinop_qTA0Li6X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_FuNqBcWG, m);
}

void Heavy_CircleStrings::cMsg_TJsear7x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_BlSrUVJo_sendMessage);
}

void Heavy_CircleStrings::cBinop_tHarU4p4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_vc7mgObN, m);
}

void Heavy_CircleStrings::cBinop_3b9OMNhm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_78xagqly_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_tsSZfR0x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_TSK6O097_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_FBUCqKOz_sendMessage);
}

void Heavy_CircleStrings::cCast_TSK6O097_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_3b9OMNhm, HV_BINOP_DIVIDE, 1, m, &cBinop_3b9OMNhm_sendMessage);
}

void Heavy_CircleStrings::cCast_FBUCqKOz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_3b9OMNhm, HV_BINOP_DIVIDE, 0, m, &cBinop_3b9OMNhm_sendMessage);
}

void Heavy_CircleStrings::cBinop_6ZEzFwQo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_2xDPaWrZ_sendMessage);
}

void Heavy_CircleStrings::cBinop_KlthMgMR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 87.3365f, 0, m, &cBinop_xKAAz0Vu_sendMessage);
}

void Heavy_CircleStrings::cBinop_2xDPaWrZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_3b9OMNhm, HV_BINOP_DIVIDE, 0, m, &cBinop_3b9OMNhm_sendMessage);
}

void Heavy_CircleStrings::cBinop_oYQGhUkd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_L6PZHb9X, 0, m, &cPack_L6PZHb9X_sendMessage);
}

void Heavy_CircleStrings::cBinop_VBe2dWSy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.001f, 0, m, &cBinop_tsSZfR0x_sendMessage);
  cPack_onMessage(_c, &Context(_c)->cPack_nuZVo1Wl, 0, m, &cPack_nuZVo1Wl_sendMessage);
}

void Heavy_CircleStrings::cMsg_Lh3OVNce_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 100.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_RixifLWy, 0, m, &cVar_RixifLWy_sendMessage);
}

void Heavy_CircleStrings::cMsg_z9GTGC6o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.5f);
  cVar_onMessage(_c, &Context(_c)->cVar_qeaeQjYg, 0, m, &cVar_qeaeQjYg_sendMessage);
}

void Heavy_CircleStrings::cMsg_78xagqly_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 30.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_pNzIvBl4, 0, m, NULL);
}

void Heavy_CircleStrings::cVar_6xH2yGXb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_3sO952Su, HV_BINOP_MULTIPLY, 0, m, &cBinop_3sO952Su_sendMessage);
}

void Heavy_CircleStrings::cMsg_VJOOcq8E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_0cVpd8qz_sendMessage);
}

void Heavy_CircleStrings::cSystem_0cVpd8qz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_UFSZdYnr_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_3sO952Su_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_iNt8g3yN_sendMessage);
}

void Heavy_CircleStrings::cBinop_xyinxahe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_3sO952Su, HV_BINOP_MULTIPLY, 1, m, &cBinop_3sO952Su_sendMessage);
}

void Heavy_CircleStrings::cMsg_UFSZdYnr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_xyinxahe_sendMessage);
}

void Heavy_CircleStrings::cBinop_iNt8g3yN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_oamHerxF_sendMessage);
}

void Heavy_CircleStrings::cBinop_oamHerxF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_3qiCoEYe_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_xY3ipPOC, m);
}

void Heavy_CircleStrings::cBinop_3qiCoEYe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_VKAgcFB1, m);
}

void Heavy_CircleStrings::cVar_9J7oUWi4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_CEAZgqVl, HV_BINOP_MULTIPLY, 0, m, &cBinop_CEAZgqVl_sendMessage);
}

void Heavy_CircleStrings::cMsg_nnA1CjoW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_pGkpPHli_sendMessage);
}

void Heavy_CircleStrings::cSystem_pGkpPHli_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_4FWWQfTt_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_CEAZgqVl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_kSIblOPu_sendMessage);
}

void Heavy_CircleStrings::cBinop_Gw7Vr3zQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_CEAZgqVl, HV_BINOP_MULTIPLY, 1, m, &cBinop_CEAZgqVl_sendMessage);
}

void Heavy_CircleStrings::cMsg_4FWWQfTt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_Gw7Vr3zQ_sendMessage);
}

void Heavy_CircleStrings::cBinop_kSIblOPu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_cqTAYol0_sendMessage);
}

void Heavy_CircleStrings::cBinop_cqTAYol0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_PmxU8HuI_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_rhjM9usw, m);
}

void Heavy_CircleStrings::cBinop_PmxU8HuI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_42IxV9sU, m);
}

void Heavy_CircleStrings::cVar_M60VxuUX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_q2OVagHu, HV_BINOP_MULTIPLY, 0, m, &cBinop_q2OVagHu_sendMessage);
}

void Heavy_CircleStrings::cMsg_0wm2F7hG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_IaifBlkg_sendMessage);
}

void Heavy_CircleStrings::cSystem_IaifBlkg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_meckoV29_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_q2OVagHu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_bVfUJF8H_sendMessage);
}

void Heavy_CircleStrings::cBinop_eY1xxVVF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_q2OVagHu, HV_BINOP_MULTIPLY, 1, m, &cBinop_q2OVagHu_sendMessage);
}

void Heavy_CircleStrings::cMsg_meckoV29_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_eY1xxVVF_sendMessage);
}

void Heavy_CircleStrings::cBinop_bVfUJF8H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_XlXzgQrl_sendMessage);
}

void Heavy_CircleStrings::cBinop_XlXzgQrl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_QMMD1uq3_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_XYMdoB53, m);
}

void Heavy_CircleStrings::cBinop_QMMD1uq3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_6LGAkaPh, m);
}

void Heavy_CircleStrings::cMsg_FfHMed1B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_WK0d3kh7_sendMessage);
}

void Heavy_CircleStrings::cSystem_WK0d3kh7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_W5QF8qfH_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cVar_xVJJAgrn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1e-05f, 0, m, &cBinop_WhwOwaqO_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_76xFv2h9, 0, m, &cIf_76xFv2h9_sendMessage);
}

void Heavy_CircleStrings::cIf_76xFv2h9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_i8pVNLh9_sendMessage(_c, 0, m);
      cMsg_rQxyTebZ_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_2FLlgMYk_sendMessage(_c, 0, m);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_ycZxyO9N_sendMessage);
      sVarf_onMessage(_c, &Context(_c)->sVarf_0GIWISEr, m);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_WhwOwaqO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_76xFv2h9, 1, m, &cIf_76xFv2h9_sendMessage);
}

void Heavy_CircleStrings::cMsg_2FLlgMYk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_qzhFMn6c_sendMessage);
}

void Heavy_CircleStrings::cBinop_qzhFMn6c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_OYbaVLUb, m);
}

void Heavy_CircleStrings::cBinop_ycZxyO9N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ki3ZTrV9_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_ki3ZTrV9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_KsSeBLEV_sendMessage);
}

void Heavy_CircleStrings::cBinop_KsSeBLEV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_TpTFhL9O_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_TpTFhL9O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_Nsxl7LbI_sendMessage);
}

void Heavy_CircleStrings::cBinop_Nsxl7LbI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_naCcrDP3, m);
}

void Heavy_CircleStrings::cBinop_SfjVWEgY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_q4lDNi3b, m);
}

void Heavy_CircleStrings::cMsg_W5QF8qfH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_SfjVWEgY_sendMessage);
}

void Heavy_CircleStrings::cMsg_i8pVNLh9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_ycZxyO9N_sendMessage);
}

void Heavy_CircleStrings::cMsg_rQxyTebZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, -1.0f);
  sVarf_onMessage(_c, &Context(_c)->sVarf_OYbaVLUb, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_0GIWISEr, m);
}

void Heavy_CircleStrings::cBinop_IHZSlRs7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_9J7oUWi4, 0, m, &cVar_9J7oUWi4_sendMessage);
}

void Heavy_CircleStrings::cBinop_ZdJOhjls_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_6xH2yGXb, 0, m, &cVar_6xH2yGXb_sendMessage);
}

void Heavy_CircleStrings::cBinop_ZGu6cUHP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_M60VxuUX, 0, m, &cVar_M60VxuUX_sendMessage);
}

void Heavy_CircleStrings::cCast_kqr688Nr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.0f, 0, m, &cBinop_ZGu6cUHP_sendMessage);
}

void Heavy_CircleStrings::cCast_tHSa2GRZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_DooJ3X7R, m);
}

void Heavy_CircleStrings::cCast_flRwdQWi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.0f, 0, m, &cBinop_ZdJOhjls_sendMessage);
}

void Heavy_CircleStrings::cCast_eF1JVXzY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.0f, 0, m, &cBinop_IHZSlRs7_sendMessage);
}

void Heavy_CircleStrings::cTabhead_lfZwwRrn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_lQ9n4GZv, HV_BINOP_SUBTRACT, 0, m, &cBinop_lQ9n4GZv_sendMessage);
}

void Heavy_CircleStrings::cMsg_OlIhUEiJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_mqRNYlYz_sendMessage);
}

void Heavy_CircleStrings::cSystem_mqRNYlYz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_VYFQEts1_sendMessage);
}

void Heavy_CircleStrings::cVar_fRj7lVHS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_IOUQiCEo_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_KWAtcvFr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_KWAtcvFr, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_I1EgURsV, 0, m, &cDelay_I1EgURsV_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_OIwQQ3dw, 0, m, &sTabread_OIwQQ3dw_sendMessage);
}

void Heavy_CircleStrings::cDelay_I1EgURsV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_I1EgURsV, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_OIwQQ3dw, 0, m, &sTabread_OIwQQ3dw_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_I1EgURsV, 0, m, &cDelay_I1EgURsV_sendMessage);
}

void Heavy_CircleStrings::sTabread_OIwQQ3dw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_4XPErmtq, HV_BINOP_SUBTRACT, 0, m, &cBinop_4XPErmtq_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_Zv2mcQ9q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_FZGof6DW, HV_BINOP_MAX, 0, m, &cBinop_FZGof6DW_sendMessage);
}

void Heavy_CircleStrings::cBinop_VYFQEts1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Zv2mcQ9q, HV_BINOP_MULTIPLY, 0, m, &cBinop_Zv2mcQ9q_sendMessage);
}

void Heavy_CircleStrings::cBinop_lQ9n4GZv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_LplKZPRc_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_OIwQQ3dw, 0, m, &sTabread_OIwQQ3dw_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ipFgIpkj_sendMessage);
}

void Heavy_CircleStrings::cSystem_wHRrAw3n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4XPErmtq, HV_BINOP_SUBTRACT, 1, m, &cBinop_4XPErmtq_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_I1EgURsV, 2, m, &cDelay_I1EgURsV_sendMessage);
}

void Heavy_CircleStrings::cMsg_IOUQiCEo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_wHRrAw3n_sendMessage);
}

void Heavy_CircleStrings::cMsg_LplKZPRc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_KWAtcvFr, 0, m, &cDelay_KWAtcvFr_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_I1EgURsV, 0, m, &cDelay_I1EgURsV_sendMessage);
}

void Heavy_CircleStrings::cMsg_FsBpgK6g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_FZGof6DW, HV_BINOP_MAX, 1, m, &cBinop_FZGof6DW_sendMessage);
}

void Heavy_CircleStrings::cBinop_FZGof6DW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_lQ9n4GZv, HV_BINOP_SUBTRACT, 1, m, &cBinop_lQ9n4GZv_sendMessage);
}

void Heavy_CircleStrings::cCast_ipFgIpkj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_KWAtcvFr, 0, m, &cDelay_KWAtcvFr_sendMessage);
}

void Heavy_CircleStrings::cBinop_tc34vSuH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_KWAtcvFr, 2, m, &cDelay_KWAtcvFr_sendMessage);
}

void Heavy_CircleStrings::cBinop_4XPErmtq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_tc34vSuH_sendMessage);
}

void Heavy_CircleStrings::cCast_XQo2PPCl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_fRj7lVHS, 0, m, &cVar_fRj7lVHS_sendMessage);
  cMsg_OlIhUEiJ_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_lfZwwRrn, 0, m, &cTabhead_lfZwwRrn_sendMessage);
}

void Heavy_CircleStrings::cTabhead_K0nzYXXe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_IKazAdga, HV_BINOP_SUBTRACT, 0, m, &cBinop_IKazAdga_sendMessage);
}

void Heavy_CircleStrings::cMsg_GCyWxorY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Exd3MU4a_sendMessage);
}

void Heavy_CircleStrings::cSystem_Exd3MU4a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_SEr0rvxD_sendMessage);
}

void Heavy_CircleStrings::cVar_eM0boj18_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_dzbeKRmX_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_xpi6LQ2X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_xpi6LQ2X, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_IlT7Ycnh, 0, m, &cDelay_IlT7Ycnh_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_jeL93fIW, 0, m, &sTabread_jeL93fIW_sendMessage);
}

void Heavy_CircleStrings::cDelay_IlT7Ycnh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_IlT7Ycnh, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_jeL93fIW, 0, m, &sTabread_jeL93fIW_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_IlT7Ycnh, 0, m, &cDelay_IlT7Ycnh_sendMessage);
}

void Heavy_CircleStrings::sTabread_jeL93fIW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_ET19GtZP, HV_BINOP_SUBTRACT, 0, m, &cBinop_ET19GtZP_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_K8rFSn1o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MAzLQRKt, HV_BINOP_MAX, 0, m, &cBinop_MAzLQRKt_sendMessage);
}

void Heavy_CircleStrings::cBinop_SEr0rvxD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_K8rFSn1o, HV_BINOP_MULTIPLY, 0, m, &cBinop_K8rFSn1o_sendMessage);
}

void Heavy_CircleStrings::cBinop_IKazAdga_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_4BbTTJjT_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_jeL93fIW, 0, m, &sTabread_jeL93fIW_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_0AgN1xOI_sendMessage);
}

void Heavy_CircleStrings::cSystem_TY9NQDaD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ET19GtZP, HV_BINOP_SUBTRACT, 1, m, &cBinop_ET19GtZP_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_IlT7Ycnh, 2, m, &cDelay_IlT7Ycnh_sendMessage);
}

void Heavy_CircleStrings::cMsg_dzbeKRmX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_TY9NQDaD_sendMessage);
}

void Heavy_CircleStrings::cMsg_4BbTTJjT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_xpi6LQ2X, 0, m, &cDelay_xpi6LQ2X_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_IlT7Ycnh, 0, m, &cDelay_IlT7Ycnh_sendMessage);
}

void Heavy_CircleStrings::cMsg_NHnX96oq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_MAzLQRKt, HV_BINOP_MAX, 1, m, &cBinop_MAzLQRKt_sendMessage);
}

void Heavy_CircleStrings::cBinop_MAzLQRKt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_IKazAdga, HV_BINOP_SUBTRACT, 1, m, &cBinop_IKazAdga_sendMessage);
}

void Heavy_CircleStrings::cCast_0AgN1xOI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_xpi6LQ2X, 0, m, &cDelay_xpi6LQ2X_sendMessage);
}

void Heavy_CircleStrings::cBinop_SowBt2mh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_xpi6LQ2X, 2, m, &cDelay_xpi6LQ2X_sendMessage);
}

void Heavy_CircleStrings::cBinop_ET19GtZP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_SowBt2mh_sendMessage);
}

void Heavy_CircleStrings::cCast_LYO6oY7K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_eM0boj18, 0, m, &cVar_eM0boj18_sendMessage);
  cMsg_GCyWxorY_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_K0nzYXXe, 0, m, &cTabhead_K0nzYXXe_sendMessage);
}

void Heavy_CircleStrings::cTabhead_L330esLI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_awuFFQSn, HV_BINOP_SUBTRACT, 0, m, &cBinop_awuFFQSn_sendMessage);
}

void Heavy_CircleStrings::cMsg_6vclW6VP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ZrKD1HYH_sendMessage);
}

void Heavy_CircleStrings::cSystem_ZrKD1HYH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_94uB4Mo5_sendMessage);
}

void Heavy_CircleStrings::cVar_41BEFoI6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Ofb0WeXC_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_0cOCR6F4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_0cOCR6F4, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_1YOKVVtr, 0, m, &cDelay_1YOKVVtr_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_wMzD5ysK, 0, m, &sTabread_wMzD5ysK_sendMessage);
}

void Heavy_CircleStrings::cDelay_1YOKVVtr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_1YOKVVtr, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_wMzD5ysK, 0, m, &sTabread_wMzD5ysK_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_1YOKVVtr, 0, m, &cDelay_1YOKVVtr_sendMessage);
}

void Heavy_CircleStrings::sTabread_wMzD5ysK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_qtBMjrNr, HV_BINOP_SUBTRACT, 0, m, &cBinop_qtBMjrNr_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_jCrRIllh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_dqXiqPdo, HV_BINOP_MAX, 0, m, &cBinop_dqXiqPdo_sendMessage);
}

void Heavy_CircleStrings::cBinop_94uB4Mo5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_jCrRIllh, HV_BINOP_MULTIPLY, 0, m, &cBinop_jCrRIllh_sendMessage);
}

void Heavy_CircleStrings::cBinop_awuFFQSn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_fzsoZr8u_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_wMzD5ysK, 0, m, &sTabread_wMzD5ysK_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Dhsma17j_sendMessage);
}

void Heavy_CircleStrings::cSystem_JQpBvBh4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_qtBMjrNr, HV_BINOP_SUBTRACT, 1, m, &cBinop_qtBMjrNr_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_1YOKVVtr, 2, m, &cDelay_1YOKVVtr_sendMessage);
}

void Heavy_CircleStrings::cMsg_Ofb0WeXC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_JQpBvBh4_sendMessage);
}

void Heavy_CircleStrings::cMsg_fzsoZr8u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_0cOCR6F4, 0, m, &cDelay_0cOCR6F4_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_1YOKVVtr, 0, m, &cDelay_1YOKVVtr_sendMessage);
}

void Heavy_CircleStrings::cMsg_0mwqxay1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_dqXiqPdo, HV_BINOP_MAX, 1, m, &cBinop_dqXiqPdo_sendMessage);
}

void Heavy_CircleStrings::cBinop_dqXiqPdo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_awuFFQSn, HV_BINOP_SUBTRACT, 1, m, &cBinop_awuFFQSn_sendMessage);
}

void Heavy_CircleStrings::cCast_Dhsma17j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_0cOCR6F4, 0, m, &cDelay_0cOCR6F4_sendMessage);
}

void Heavy_CircleStrings::cBinop_v0zRwFB8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_0cOCR6F4, 2, m, &cDelay_0cOCR6F4_sendMessage);
}

void Heavy_CircleStrings::cBinop_qtBMjrNr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_v0zRwFB8_sendMessage);
}

void Heavy_CircleStrings::cCast_ajg7hD03_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_41BEFoI6, 0, m, &cVar_41BEFoI6_sendMessage);
  cMsg_6vclW6VP_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_L330esLI, 0, m, &cTabhead_L330esLI_sendMessage);
}

void Heavy_CircleStrings::cTabhead_mRXnhi5H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_xL3KSUwA, HV_BINOP_SUBTRACT, 0, m, &cBinop_xL3KSUwA_sendMessage);
}

void Heavy_CircleStrings::cMsg_ckqdEYLe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_VqOJgxeO_sendMessage);
}

void Heavy_CircleStrings::cSystem_VqOJgxeO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_1QOpmejn_sendMessage);
}

void Heavy_CircleStrings::cVar_TY5wzbag_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_tXxnzQku_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_8C9ZpkVN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_8C9ZpkVN, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_tdlUIyX3, 0, m, &cDelay_tdlUIyX3_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_JeA8qHeQ, 0, m, &sTabread_JeA8qHeQ_sendMessage);
}

void Heavy_CircleStrings::cDelay_tdlUIyX3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_tdlUIyX3, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_JeA8qHeQ, 0, m, &sTabread_JeA8qHeQ_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_tdlUIyX3, 0, m, &cDelay_tdlUIyX3_sendMessage);
}

void Heavy_CircleStrings::sTabread_JeA8qHeQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_K42iHF9V, HV_BINOP_SUBTRACT, 0, m, &cBinop_K42iHF9V_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_FHFew95o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_C4ssS6ES, HV_BINOP_MAX, 0, m, &cBinop_C4ssS6ES_sendMessage);
}

void Heavy_CircleStrings::cBinop_1QOpmejn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_FHFew95o, HV_BINOP_MULTIPLY, 0, m, &cBinop_FHFew95o_sendMessage);
}

void Heavy_CircleStrings::cBinop_xL3KSUwA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_MtJ6soAz_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_JeA8qHeQ, 0, m, &sTabread_JeA8qHeQ_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_EsXbuGYL_sendMessage);
}

void Heavy_CircleStrings::cSystem_mQWUXVne_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_K42iHF9V, HV_BINOP_SUBTRACT, 1, m, &cBinop_K42iHF9V_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_tdlUIyX3, 2, m, &cDelay_tdlUIyX3_sendMessage);
}

void Heavy_CircleStrings::cMsg_tXxnzQku_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_mQWUXVne_sendMessage);
}

void Heavy_CircleStrings::cMsg_MtJ6soAz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_8C9ZpkVN, 0, m, &cDelay_8C9ZpkVN_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_tdlUIyX3, 0, m, &cDelay_tdlUIyX3_sendMessage);
}

void Heavy_CircleStrings::cMsg_DGkcJNI8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_C4ssS6ES, HV_BINOP_MAX, 1, m, &cBinop_C4ssS6ES_sendMessage);
}

void Heavy_CircleStrings::cBinop_C4ssS6ES_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_xL3KSUwA, HV_BINOP_SUBTRACT, 1, m, &cBinop_xL3KSUwA_sendMessage);
}

void Heavy_CircleStrings::cCast_EsXbuGYL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_8C9ZpkVN, 0, m, &cDelay_8C9ZpkVN_sendMessage);
}

void Heavy_CircleStrings::cBinop_wMkHPOgt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_8C9ZpkVN, 2, m, &cDelay_8C9ZpkVN_sendMessage);
}

void Heavy_CircleStrings::cBinop_K42iHF9V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_wMkHPOgt_sendMessage);
}

void Heavy_CircleStrings::cCast_otaHnkTR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_TY5wzbag, 0, m, &cVar_TY5wzbag_sendMessage);
  cMsg_ckqdEYLe_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_mRXnhi5H, 0, m, &cTabhead_mRXnhi5H_sendMessage);
}

void Heavy_CircleStrings::cMsg_rjVjaqb3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Px0h4WEh_sendMessage);
}

void Heavy_CircleStrings::cSystem_Px0h4WEh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_ZXEnEfUl_sendMessage);
}

void Heavy_CircleStrings::cDelay_vbs1uMWO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_vbs1uMWO, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_OMVRptgi, 0, m, &cDelay_OMVRptgi_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_vbs1uMWO, 0, m, &cDelay_vbs1uMWO_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_YwUS7cjj, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_OMVRptgi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_OMVRptgi, m);
  cMsg_P3Ohh6VW_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_xNzZ8aHn_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_XRcnTaqG_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_xgb1K69R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_XJuxi7nM_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_693LwEav_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Ukd7KdgF_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_vbs1uMWO, 2, m, &cDelay_vbs1uMWO_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_sK9KLGpR_sendMessage);
}

void Heavy_CircleStrings::cMsg_XJuxi7nM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_693LwEav, 0, m, &hTable_693LwEav_sendMessage);
}

void Heavy_CircleStrings::cBinop_ZXEnEfUl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 58.6435f, 0, m, &cBinop_xgb1K69R_sendMessage);
}

void Heavy_CircleStrings::cMsg_P3Ohh6VW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_693LwEav, 0, m, &hTable_693LwEav_sendMessage);
}

void Heavy_CircleStrings::cCast_sK9KLGpR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_vbs1uMWO, 0, m, &cDelay_vbs1uMWO_sendMessage);
}

void Heavy_CircleStrings::cMsg_Ukd7KdgF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_OMVRptgi, 2, m, &cDelay_OMVRptgi_sendMessage);
}

void Heavy_CircleStrings::cMsg_XRcnTaqG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_YwUS7cjj, 1, m, NULL);
}

void Heavy_CircleStrings::cMsg_7spsJMtO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_knanDGpC_sendMessage);
}

void Heavy_CircleStrings::cSystem_knanDGpC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_XsrjXt9D_sendMessage);
}

void Heavy_CircleStrings::cDelay_KpovV8l8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_KpovV8l8, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_JJjGgun6, 0, m, &cDelay_JJjGgun6_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_KpovV8l8, 0, m, &cDelay_KpovV8l8_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_b7qgbpFi, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_JJjGgun6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_JJjGgun6, m);
  cMsg_huMSgDJP_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_uJhP26Ho_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_B3YMH7q7_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_1oqN6vw0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_BywvSVBb_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_mIJTHwRg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_0jiSgx0q_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_KpovV8l8, 2, m, &cDelay_KpovV8l8_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_VIqZzQeq_sendMessage);
}

void Heavy_CircleStrings::cMsg_BywvSVBb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_mIJTHwRg, 0, m, &hTable_mIJTHwRg_sendMessage);
}

void Heavy_CircleStrings::cBinop_XsrjXt9D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 69.4325f, 0, m, &cBinop_1oqN6vw0_sendMessage);
}

void Heavy_CircleStrings::cMsg_huMSgDJP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_mIJTHwRg, 0, m, &hTable_mIJTHwRg_sendMessage);
}

void Heavy_CircleStrings::cCast_VIqZzQeq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_KpovV8l8, 0, m, &cDelay_KpovV8l8_sendMessage);
}

void Heavy_CircleStrings::cMsg_0jiSgx0q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_JJjGgun6, 2, m, &cDelay_JJjGgun6_sendMessage);
}

void Heavy_CircleStrings::cMsg_B3YMH7q7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_b7qgbpFi, 1, m, NULL);
}

void Heavy_CircleStrings::cMsg_BKUZkhuD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_7HCvb2eZ_sendMessage);
}

void Heavy_CircleStrings::cSystem_7HCvb2eZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_vmkKS8zJ_sendMessage);
}

void Heavy_CircleStrings::cDelay_aYggH9o9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_aYggH9o9, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Birk0J5t, 0, m, &cDelay_Birk0J5t_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_aYggH9o9, 0, m, &cDelay_aYggH9o9_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_B5qVsWWH, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_Birk0J5t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Birk0J5t, m);
  cMsg_Vdt6XQ0j_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_FpVhYA81_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_wBCiN75X_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_Z7xZM9I7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_zYDxolFV_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_HwCmPlvs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_AXTA56pH_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_aYggH9o9, 2, m, &cDelay_aYggH9o9_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_2X9wBnUu_sendMessage);
}

void Heavy_CircleStrings::cMsg_zYDxolFV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_HwCmPlvs, 0, m, &hTable_HwCmPlvs_sendMessage);
}

void Heavy_CircleStrings::cBinop_vmkKS8zJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 74.5234f, 0, m, &cBinop_Z7xZM9I7_sendMessage);
}

void Heavy_CircleStrings::cMsg_Vdt6XQ0j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_HwCmPlvs, 0, m, &hTable_HwCmPlvs_sendMessage);
}

void Heavy_CircleStrings::cCast_2X9wBnUu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_aYggH9o9, 0, m, &cDelay_aYggH9o9_sendMessage);
}

void Heavy_CircleStrings::cMsg_AXTA56pH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_Birk0J5t, 2, m, &cDelay_Birk0J5t_sendMessage);
}

void Heavy_CircleStrings::cMsg_wBCiN75X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_B5qVsWWH, 1, m, NULL);
}

void Heavy_CircleStrings::cMsg_4w7B59wO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_l4Dda8f1_sendMessage);
}

void Heavy_CircleStrings::cSystem_l4Dda8f1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_tVXCunTZ_sendMessage);
}

void Heavy_CircleStrings::cDelay_UamJl6lY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_UamJl6lY, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_fIsziUV5, 0, m, &cDelay_fIsziUV5_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_UamJl6lY, 0, m, &cDelay_UamJl6lY_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_QO4KkM4X, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_fIsziUV5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_fIsziUV5, m);
  cMsg_C5enKnQX_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_OtxPkC1B_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_OFiiP3ij_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_uOIFtbZU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_SJHrgMII_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_Nvcb34fO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Y4QH3bCm_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_UamJl6lY, 2, m, &cDelay_UamJl6lY_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_13skwo2Q_sendMessage);
}

void Heavy_CircleStrings::cMsg_SJHrgMII_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_Nvcb34fO, 0, m, &hTable_Nvcb34fO_sendMessage);
}

void Heavy_CircleStrings::cBinop_tVXCunTZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 86.1244f, 0, m, &cBinop_uOIFtbZU_sendMessage);
}

void Heavy_CircleStrings::cMsg_C5enKnQX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_Nvcb34fO, 0, m, &hTable_Nvcb34fO_sendMessage);
}

void Heavy_CircleStrings::cCast_13skwo2Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_UamJl6lY, 0, m, &cDelay_UamJl6lY_sendMessage);
}

void Heavy_CircleStrings::cMsg_Y4QH3bCm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_fIsziUV5, 2, m, &cDelay_fIsziUV5_sendMessage);
}

void Heavy_CircleStrings::cMsg_OFiiP3ij_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_QO4KkM4X, 1, m, NULL);
}

void Heavy_CircleStrings::cIf_BLW1ihiA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_godJVlgk_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_HpxCwcEl_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cMsg_feSndWUx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_tY2j4yCd, HV_BINOP_POW, 0, m, &cBinop_tY2j4yCd_sendMessage);
}

void Heavy_CircleStrings::cBinop_tY2j4yCd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.125f, 0, m, &cBinop_fKimxgLz_sendMessage);
}

void Heavy_CircleStrings::cBinop_vpQSIqub_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_0OuDyjs8_sendMessage);
}

void Heavy_CircleStrings::cCast_lvX0L8zh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_BLW1ihiA, 0, m, &cIf_BLW1ihiA_sendMessage);
}

void Heavy_CircleStrings::cCast_vyycjsFs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_ZWiZRXET_sendMessage);
}

void Heavy_CircleStrings::cBinop_ZWiZRXET_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_BLW1ihiA, 1, m, &cIf_BLW1ihiA_sendMessage);
}

void Heavy_CircleStrings::cBinop_HpxCwcEl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_vpQSIqub_sendMessage);
}

void Heavy_CircleStrings::cMsg_godJVlgk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.125f, 0, m, &cBinop_fKimxgLz_sendMessage);
}

void Heavy_CircleStrings::cBinop_0OuDyjs8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_tY2j4yCd, HV_BINOP_POW, 1, m, &cBinop_tY2j4yCd_sendMessage);
  cMsg_feSndWUx_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cPack_U6eEgHtR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_sx57kZpT, 0, m, NULL);
}

void Heavy_CircleStrings::cPack_FiHZCJ7s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_zLBDCZPF, 0, m, NULL);
}

void Heavy_CircleStrings::cBinop_vYxrOIDC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_9lNo6Tdi_sendMessage);
}

void Heavy_CircleStrings::cBinop_9lNo6Tdi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 200.0f, 0, m, &cBinop_Q8mrTTCq_sendMessage);
}

void Heavy_CircleStrings::cVar_VBjv806w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_SlxoWoyF, HV_BINOP_MULTIPLY, 0, m, &cBinop_SlxoWoyF_sendMessage);
}

void Heavy_CircleStrings::cMsg_h31L5BMN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_hdVvNhL6_sendMessage);
}

void Heavy_CircleStrings::cSystem_hdVvNhL6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_pVGZFBBV_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_SlxoWoyF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_tD64PVKR_sendMessage);
}

void Heavy_CircleStrings::cBinop_5HEp6Iet_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_SlxoWoyF, HV_BINOP_MULTIPLY, 1, m, &cBinop_SlxoWoyF_sendMessage);
}

void Heavy_CircleStrings::cMsg_pVGZFBBV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_5HEp6Iet_sendMessage);
}

void Heavy_CircleStrings::cBinop_tD64PVKR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_Eh77esnl_sendMessage);
}

void Heavy_CircleStrings::cBinop_Eh77esnl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_8Wvw1M7v_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_dWmr1V6v, m);
}

void Heavy_CircleStrings::cBinop_8Wvw1M7v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_HUDZZt7U, m);
}

void Heavy_CircleStrings::cVar_GLnzeSRQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_vyycjsFs_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_lvX0L8zh_sendMessage);
}

void Heavy_CircleStrings::cVar_xc7L7wV4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 100.0f, 0, m, &cBinop_vYxrOIDC_sendMessage);
}

void Heavy_CircleStrings::cVar_5LelctpU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_mbqDzcbd_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_CfhnhkEf, 0, m, &cIf_CfhnhkEf_sendMessage);
}

void Heavy_CircleStrings::cVar_W49KAy3V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 100.0f, 0, m, &cBinop_axFHoWo1_sendMessage);
}

void Heavy_CircleStrings::cIf_CfhnhkEf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_oZnzzDYW_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cVar_onMessage(_c, &Context(_c)->cVar_9uERaytd, 0, m, &cVar_9uERaytd_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_mbqDzcbd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_CfhnhkEf, 1, m, &cIf_CfhnhkEf_sendMessage);
}

void Heavy_CircleStrings::cBinop_axFHoWo1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_ZALptx8X_sendMessage);
}

void Heavy_CircleStrings::cBinop_ZALptx8X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_S43alZiX, 0, m, &cVar_S43alZiX_sendMessage);
}

void Heavy_CircleStrings::cTabhead_aIAprJqe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_7g3sT9hm, HV_BINOP_SUBTRACT, 0, m, &cBinop_7g3sT9hm_sendMessage);
}

void Heavy_CircleStrings::cMsg_7vf0Aryo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_P6fIJt9G_sendMessage);
}

void Heavy_CircleStrings::cSystem_P6fIJt9G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_Z7WIukvh_sendMessage);
}

void Heavy_CircleStrings::cVar_PpCeroRQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Pbzv0pEu_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_Bc5eXcN4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Bc5eXcN4, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ANRjOF91, 0, m, &cDelay_ANRjOF91_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_8kp3W93J, 0, m, &sTabread_8kp3W93J_sendMessage);
}

void Heavy_CircleStrings::cDelay_ANRjOF91_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_ANRjOF91, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_8kp3W93J, 0, m, &sTabread_8kp3W93J_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ANRjOF91, 0, m, &cDelay_ANRjOF91_sendMessage);
}

void Heavy_CircleStrings::sTabread_8kp3W93J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_1JgpeFcH, HV_BINOP_SUBTRACT, 0, m, &cBinop_1JgpeFcH_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_jxJ34OLN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_2rThSboU, HV_BINOP_MAX, 0, m, &cBinop_2rThSboU_sendMessage);
}

void Heavy_CircleStrings::cBinop_Z7WIukvh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_jxJ34OLN, HV_BINOP_MULTIPLY, 0, m, &cBinop_jxJ34OLN_sendMessage);
}

void Heavy_CircleStrings::cBinop_7g3sT9hm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_dvnt0JID_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_8kp3W93J, 0, m, &sTabread_8kp3W93J_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_AmWGNf1X_sendMessage);
}

void Heavy_CircleStrings::cSystem_6PClpvzj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_1JgpeFcH, HV_BINOP_SUBTRACT, 1, m, &cBinop_1JgpeFcH_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ANRjOF91, 2, m, &cDelay_ANRjOF91_sendMessage);
}

void Heavy_CircleStrings::cMsg_Pbzv0pEu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_6PClpvzj_sendMessage);
}

void Heavy_CircleStrings::cMsg_dvnt0JID_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_Bc5eXcN4, 0, m, &cDelay_Bc5eXcN4_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ANRjOF91, 0, m, &cDelay_ANRjOF91_sendMessage);
}

void Heavy_CircleStrings::cMsg_Lynl2tqP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_2rThSboU, HV_BINOP_MAX, 1, m, &cBinop_2rThSboU_sendMessage);
}

void Heavy_CircleStrings::cBinop_2rThSboU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_7g3sT9hm, HV_BINOP_SUBTRACT, 1, m, &cBinop_7g3sT9hm_sendMessage);
}

void Heavy_CircleStrings::cCast_AmWGNf1X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Bc5eXcN4, 0, m, &cDelay_Bc5eXcN4_sendMessage);
}

void Heavy_CircleStrings::cBinop_cDJI7j4r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Bc5eXcN4, 2, m, &cDelay_Bc5eXcN4_sendMessage);
}

void Heavy_CircleStrings::cBinop_1JgpeFcH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_cDJI7j4r_sendMessage);
}

void Heavy_CircleStrings::cCast_6HQYm33L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_PpCeroRQ, 0, m, &cVar_PpCeroRQ_sendMessage);
  cMsg_7vf0Aryo_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_aIAprJqe, 0, m, &cTabhead_aIAprJqe_sendMessage);
}

void Heavy_CircleStrings::cMsg_SoY5z1dF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_rJVbQg8l_sendMessage);
}

void Heavy_CircleStrings::cSystem_rJVbQg8l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_eHjYFGoK_sendMessage);
}

void Heavy_CircleStrings::cDelay_oQIUHSX5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_oQIUHSX5, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_W6efCIBv, 0, m, &cDelay_W6efCIBv_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_oQIUHSX5, 0, m, &cDelay_oQIUHSX5_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_CQI1TuKu, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_W6efCIBv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_W6efCIBv, m);
  cMsg_LR8CCPg3_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_DbdzuC1j_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_DmhnQNsL_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_QDXBsIP5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_m2jbXP4v_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_6V7bd8B9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_pQjW4zSj_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_oQIUHSX5, 2, m, &cDelay_oQIUHSX5_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_JgB2SC0T_sendMessage);
}

void Heavy_CircleStrings::cMsg_m2jbXP4v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_6V7bd8B9, 0, m, &hTable_6V7bd8B9_sendMessage);
}

void Heavy_CircleStrings::cBinop_eHjYFGoK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 13.645f, 0, m, &cBinop_QDXBsIP5_sendMessage);
}

void Heavy_CircleStrings::cMsg_LR8CCPg3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_6V7bd8B9, 0, m, &hTable_6V7bd8B9_sendMessage);
}

void Heavy_CircleStrings::cCast_JgB2SC0T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_oQIUHSX5, 0, m, &cDelay_oQIUHSX5_sendMessage);
}

void Heavy_CircleStrings::cMsg_pQjW4zSj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_W6efCIBv, 2, m, &cDelay_W6efCIBv_sendMessage);
}

void Heavy_CircleStrings::cMsg_DmhnQNsL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_CQI1TuKu, 1, m, NULL);
}

void Heavy_CircleStrings::cTabhead_LJ1K4BM0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_EsHNret5, HV_BINOP_SUBTRACT, 0, m, &cBinop_EsHNret5_sendMessage);
}

void Heavy_CircleStrings::cMsg_o9G1rd4H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_nFcFcK5S_sendMessage);
}

void Heavy_CircleStrings::cSystem_nFcFcK5S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_8Gad6GEM_sendMessage);
}

void Heavy_CircleStrings::cVar_2bYgkoWy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_8iGD9Glr_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_YBkOGA0G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_YBkOGA0G, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_nu2y5iPL, 0, m, &cDelay_nu2y5iPL_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_jxb9fImF, 0, m, &sTabread_jxb9fImF_sendMessage);
}

void Heavy_CircleStrings::cDelay_nu2y5iPL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_nu2y5iPL, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_jxb9fImF, 0, m, &sTabread_jxb9fImF_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_nu2y5iPL, 0, m, &cDelay_nu2y5iPL_sendMessage);
}

void Heavy_CircleStrings::sTabread_jxb9fImF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_azf4Ft1H, HV_BINOP_SUBTRACT, 0, m, &cBinop_azf4Ft1H_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_A3aYv7Q3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_7BcOj0eP, HV_BINOP_MAX, 0, m, &cBinop_7BcOj0eP_sendMessage);
}

void Heavy_CircleStrings::cBinop_8Gad6GEM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_A3aYv7Q3, HV_BINOP_MULTIPLY, 0, m, &cBinop_A3aYv7Q3_sendMessage);
}

void Heavy_CircleStrings::cBinop_EsHNret5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ySr55mNX_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_jxb9fImF, 0, m, &sTabread_jxb9fImF_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_VrNG1IOw_sendMessage);
}

void Heavy_CircleStrings::cSystem_8liAKQ6i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_azf4Ft1H, HV_BINOP_SUBTRACT, 1, m, &cBinop_azf4Ft1H_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_nu2y5iPL, 2, m, &cDelay_nu2y5iPL_sendMessage);
}

void Heavy_CircleStrings::cMsg_8iGD9Glr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_8liAKQ6i_sendMessage);
}

void Heavy_CircleStrings::cMsg_ySr55mNX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_YBkOGA0G, 0, m, &cDelay_YBkOGA0G_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_nu2y5iPL, 0, m, &cDelay_nu2y5iPL_sendMessage);
}

void Heavy_CircleStrings::cMsg_bKLJrzAv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_7BcOj0eP, HV_BINOP_MAX, 1, m, &cBinop_7BcOj0eP_sendMessage);
}

void Heavy_CircleStrings::cBinop_7BcOj0eP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_EsHNret5, HV_BINOP_SUBTRACT, 1, m, &cBinop_EsHNret5_sendMessage);
}

void Heavy_CircleStrings::cCast_VrNG1IOw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_YBkOGA0G, 0, m, &cDelay_YBkOGA0G_sendMessage);
}

void Heavy_CircleStrings::cBinop_esaeZC5T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_YBkOGA0G, 2, m, &cDelay_YBkOGA0G_sendMessage);
}

void Heavy_CircleStrings::cBinop_azf4Ft1H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_esaeZC5T_sendMessage);
}

void Heavy_CircleStrings::cCast_oxaNrWhb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_2bYgkoWy, 0, m, &cVar_2bYgkoWy_sendMessage);
  cMsg_o9G1rd4H_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_LJ1K4BM0, 0, m, &cTabhead_LJ1K4BM0_sendMessage);
}

void Heavy_CircleStrings::cMsg_2XPq2wnC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_lSaeZZsq_sendMessage);
}

void Heavy_CircleStrings::cSystem_lSaeZZsq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_F3tnjjsX_sendMessage);
}

void Heavy_CircleStrings::cDelay_0ZrsnBXx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_0ZrsnBXx, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Zd6dBhc1, 0, m, &cDelay_Zd6dBhc1_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_0ZrsnBXx, 0, m, &cDelay_0ZrsnBXx_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_c3IJh3wS, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_Zd6dBhc1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Zd6dBhc1, m);
  cMsg_dn02XKxR_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_BkUiS8jG_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_4yL07AOS_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_jVMoUmBa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_qtkx0IYr_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_ChiS8qHr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_juuowc2G_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_0ZrsnBXx, 2, m, &cDelay_0ZrsnBXx_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_GVsX93Du_sendMessage);
}

void Heavy_CircleStrings::cMsg_qtkx0IYr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_ChiS8qHr, 0, m, &hTable_ChiS8qHr_sendMessage);
}

void Heavy_CircleStrings::cBinop_F3tnjjsX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 16.364f, 0, m, &cBinop_jVMoUmBa_sendMessage);
}

void Heavy_CircleStrings::cMsg_dn02XKxR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_ChiS8qHr, 0, m, &hTable_ChiS8qHr_sendMessage);
}

void Heavy_CircleStrings::cCast_GVsX93Du_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_0ZrsnBXx, 0, m, &cDelay_0ZrsnBXx_sendMessage);
}

void Heavy_CircleStrings::cMsg_juuowc2G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_Zd6dBhc1, 2, m, &cDelay_Zd6dBhc1_sendMessage);
}

void Heavy_CircleStrings::cMsg_4yL07AOS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_c3IJh3wS, 1, m, NULL);
}

void Heavy_CircleStrings::cTabhead_U4zTwJnH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_33c2MSaH, HV_BINOP_SUBTRACT, 0, m, &cBinop_33c2MSaH_sendMessage);
}

void Heavy_CircleStrings::cMsg_UP0lHKmv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_aqRwgnyx_sendMessage);
}

void Heavy_CircleStrings::cSystem_aqRwgnyx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_O3z9wvRF_sendMessage);
}

void Heavy_CircleStrings::cVar_6hSfbrPG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_gC2NC7tK_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_LTYYipcg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_LTYYipcg, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_2tlt5Tqq, 0, m, &cDelay_2tlt5Tqq_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_tvRNOEqN, 0, m, &sTabread_tvRNOEqN_sendMessage);
}

void Heavy_CircleStrings::cDelay_2tlt5Tqq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_2tlt5Tqq, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_tvRNOEqN, 0, m, &sTabread_tvRNOEqN_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_2tlt5Tqq, 0, m, &cDelay_2tlt5Tqq_sendMessage);
}

void Heavy_CircleStrings::sTabread_tvRNOEqN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_ppYU6i7Z, HV_BINOP_SUBTRACT, 0, m, &cBinop_ppYU6i7Z_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_u4qa68MB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_vEzo8Vxs, HV_BINOP_MAX, 0, m, &cBinop_vEzo8Vxs_sendMessage);
}

void Heavy_CircleStrings::cBinop_O3z9wvRF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_u4qa68MB, HV_BINOP_MULTIPLY, 0, m, &cBinop_u4qa68MB_sendMessage);
}

void Heavy_CircleStrings::cBinop_33c2MSaH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_nmgeNQVT_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_tvRNOEqN, 0, m, &sTabread_tvRNOEqN_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_D0fmGjUx_sendMessage);
}

void Heavy_CircleStrings::cSystem_KFK6qAqJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ppYU6i7Z, HV_BINOP_SUBTRACT, 1, m, &cBinop_ppYU6i7Z_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_2tlt5Tqq, 2, m, &cDelay_2tlt5Tqq_sendMessage);
}

void Heavy_CircleStrings::cMsg_gC2NC7tK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_KFK6qAqJ_sendMessage);
}

void Heavy_CircleStrings::cMsg_nmgeNQVT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_LTYYipcg, 0, m, &cDelay_LTYYipcg_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_2tlt5Tqq, 0, m, &cDelay_2tlt5Tqq_sendMessage);
}

void Heavy_CircleStrings::cMsg_2QwaOjWG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_vEzo8Vxs, HV_BINOP_MAX, 1, m, &cBinop_vEzo8Vxs_sendMessage);
}

void Heavy_CircleStrings::cBinop_vEzo8Vxs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_33c2MSaH, HV_BINOP_SUBTRACT, 1, m, &cBinop_33c2MSaH_sendMessage);
}

void Heavy_CircleStrings::cCast_D0fmGjUx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_LTYYipcg, 0, m, &cDelay_LTYYipcg_sendMessage);
}

void Heavy_CircleStrings::cBinop_pC0gnjJ7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_LTYYipcg, 2, m, &cDelay_LTYYipcg_sendMessage);
}

void Heavy_CircleStrings::cBinop_ppYU6i7Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_pC0gnjJ7_sendMessage);
}

void Heavy_CircleStrings::cCast_mcS6MmMw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_6hSfbrPG, 0, m, &cVar_6hSfbrPG_sendMessage);
  cMsg_UP0lHKmv_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_U4zTwJnH, 0, m, &cTabhead_U4zTwJnH_sendMessage);
}

void Heavy_CircleStrings::cMsg_RDGBhBU7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_96FSw1Qg_sendMessage);
}

void Heavy_CircleStrings::cSystem_96FSw1Qg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_bnUVAuCK_sendMessage);
}

void Heavy_CircleStrings::cDelay_CYynC8qf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_CYynC8qf, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_YlL83GjJ, 0, m, &cDelay_YlL83GjJ_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_CYynC8qf, 0, m, &cDelay_CYynC8qf_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_GQeBmJcI, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_YlL83GjJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_YlL83GjJ, m);
  cMsg_nmfSqfml_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_JWsCyL2o_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_F8QFE81c_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_h3sXgCQM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_SuEgxyb7_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_pJEI10v8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_qAl6cQX8_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_CYynC8qf, 2, m, &cDelay_CYynC8qf_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_77UJycA0_sendMessage);
}

void Heavy_CircleStrings::cMsg_SuEgxyb7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_pJEI10v8, 0, m, &hTable_pJEI10v8_sendMessage);
}

void Heavy_CircleStrings::cBinop_bnUVAuCK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 19.392f, 0, m, &cBinop_h3sXgCQM_sendMessage);
}

void Heavy_CircleStrings::cMsg_nmfSqfml_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_pJEI10v8, 0, m, &hTable_pJEI10v8_sendMessage);
}

void Heavy_CircleStrings::cCast_77UJycA0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_CYynC8qf, 0, m, &cDelay_CYynC8qf_sendMessage);
}

void Heavy_CircleStrings::cMsg_qAl6cQX8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_YlL83GjJ, 2, m, &cDelay_YlL83GjJ_sendMessage);
}

void Heavy_CircleStrings::cMsg_F8QFE81c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_GQeBmJcI, 1, m, NULL);
}

void Heavy_CircleStrings::cTabhead_LeFC9cFs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_nTIjcDIx, HV_BINOP_SUBTRACT, 0, m, &cBinop_nTIjcDIx_sendMessage);
}

void Heavy_CircleStrings::cMsg_DP01RcKZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_zBGX6dna_sendMessage);
}

void Heavy_CircleStrings::cSystem_zBGX6dna_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_f5NP3WZf_sendMessage);
}

void Heavy_CircleStrings::cVar_MqDPT2RA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_uQur1knl_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_pAjHkumq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_pAjHkumq, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_uZ7Bsc2D, 0, m, &cDelay_uZ7Bsc2D_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_CIoSnsxn, 0, m, &sTabread_CIoSnsxn_sendMessage);
}

void Heavy_CircleStrings::cDelay_uZ7Bsc2D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_uZ7Bsc2D, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_CIoSnsxn, 0, m, &sTabread_CIoSnsxn_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_uZ7Bsc2D, 0, m, &cDelay_uZ7Bsc2D_sendMessage);
}

void Heavy_CircleStrings::sTabread_CIoSnsxn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_kKJfzpiX, HV_BINOP_SUBTRACT, 0, m, &cBinop_kKJfzpiX_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_dGEFcDQ5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_j1uUrmRd, HV_BINOP_MAX, 0, m, &cBinop_j1uUrmRd_sendMessage);
}

void Heavy_CircleStrings::cBinop_f5NP3WZf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_dGEFcDQ5, HV_BINOP_MULTIPLY, 0, m, &cBinop_dGEFcDQ5_sendMessage);
}

void Heavy_CircleStrings::cBinop_nTIjcDIx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_45e9hHPG_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_CIoSnsxn, 0, m, &sTabread_CIoSnsxn_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_irVgNNYx_sendMessage);
}

void Heavy_CircleStrings::cSystem_IUfd0LT9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_kKJfzpiX, HV_BINOP_SUBTRACT, 1, m, &cBinop_kKJfzpiX_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_uZ7Bsc2D, 2, m, &cDelay_uZ7Bsc2D_sendMessage);
}

void Heavy_CircleStrings::cMsg_uQur1knl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_IUfd0LT9_sendMessage);
}

void Heavy_CircleStrings::cMsg_45e9hHPG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_pAjHkumq, 0, m, &cDelay_pAjHkumq_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_uZ7Bsc2D, 0, m, &cDelay_uZ7Bsc2D_sendMessage);
}

void Heavy_CircleStrings::cMsg_4FH3cpGS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_j1uUrmRd, HV_BINOP_MAX, 1, m, &cBinop_j1uUrmRd_sendMessage);
}

void Heavy_CircleStrings::cBinop_j1uUrmRd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_nTIjcDIx, HV_BINOP_SUBTRACT, 1, m, &cBinop_nTIjcDIx_sendMessage);
}

void Heavy_CircleStrings::cCast_irVgNNYx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_pAjHkumq, 0, m, &cDelay_pAjHkumq_sendMessage);
}

void Heavy_CircleStrings::cBinop_BmZtaJBX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_pAjHkumq, 2, m, &cDelay_pAjHkumq_sendMessage);
}

void Heavy_CircleStrings::cBinop_kKJfzpiX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_BmZtaJBX_sendMessage);
}

void Heavy_CircleStrings::cCast_CoLXWG2M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_MqDPT2RA, 0, m, &cVar_MqDPT2RA_sendMessage);
  cMsg_DP01RcKZ_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_LeFC9cFs, 0, m, &cTabhead_LeFC9cFs_sendMessage);
}

void Heavy_CircleStrings::cMsg_20WQRphU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ih0nkZLN_sendMessage);
}

void Heavy_CircleStrings::cSystem_ih0nkZLN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_d0ZryyCm_sendMessage);
}

void Heavy_CircleStrings::cDelay_6DRglWmE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_6DRglWmE, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_2cVqcYx1, 0, m, &cDelay_2cVqcYx1_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_6DRglWmE, 0, m, &cDelay_6DRglWmE_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_vx2e8AGE, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_2cVqcYx1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_2cVqcYx1, m);
  cMsg_t82aC7ea_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_DkFBfhtU_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_FQfN4igk_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_TzwTSsfC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_oz1AHfhw_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_GJF7fb4n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_WPHV8RfL_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_6DRglWmE, 2, m, &cDelay_6DRglWmE_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_h47nhbQ1_sendMessage);
}

void Heavy_CircleStrings::cMsg_oz1AHfhw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_GJF7fb4n, 0, m, &hTable_GJF7fb4n_sendMessage);
}

void Heavy_CircleStrings::cBinop_d0ZryyCm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 25.796f, 0, m, &cBinop_TzwTSsfC_sendMessage);
}

void Heavy_CircleStrings::cMsg_t82aC7ea_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_GJF7fb4n, 0, m, &hTable_GJF7fb4n_sendMessage);
}

void Heavy_CircleStrings::cCast_h47nhbQ1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_6DRglWmE, 0, m, &cDelay_6DRglWmE_sendMessage);
}

void Heavy_CircleStrings::cMsg_WPHV8RfL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_2cVqcYx1, 2, m, &cDelay_2cVqcYx1_sendMessage);
}

void Heavy_CircleStrings::cMsg_FQfN4igk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_vx2e8AGE, 1, m, NULL);
}

void Heavy_CircleStrings::cTabhead_aP34WzdI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4raMJCcP, HV_BINOP_SUBTRACT, 0, m, &cBinop_4raMJCcP_sendMessage);
}

void Heavy_CircleStrings::cMsg_AoMI58pw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_O7S4vdMM_sendMessage);
}

void Heavy_CircleStrings::cSystem_O7S4vdMM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_0b9bMibJ_sendMessage);
}

void Heavy_CircleStrings::cVar_XjRxuH4R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_abMsNLnP_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_sIWIpZnh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_sIWIpZnh, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_SB7OOGXK, 0, m, &cDelay_SB7OOGXK_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_mKGscUIs, 0, m, &sTabread_mKGscUIs_sendMessage);
}

void Heavy_CircleStrings::cDelay_SB7OOGXK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_SB7OOGXK, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_mKGscUIs, 0, m, &sTabread_mKGscUIs_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_SB7OOGXK, 0, m, &cDelay_SB7OOGXK_sendMessage);
}

void Heavy_CircleStrings::sTabread_mKGscUIs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_Ycq0Ji5M, HV_BINOP_SUBTRACT, 0, m, &cBinop_Ycq0Ji5M_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_lR41tlTg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_c1knj7qf, HV_BINOP_MAX, 0, m, &cBinop_c1knj7qf_sendMessage);
}

void Heavy_CircleStrings::cBinop_0b9bMibJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_lR41tlTg, HV_BINOP_MULTIPLY, 0, m, &cBinop_lR41tlTg_sendMessage);
}

void Heavy_CircleStrings::cBinop_4raMJCcP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_4x99gPY6_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_mKGscUIs, 0, m, &sTabread_mKGscUIs_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_UZ5WlpaH_sendMessage);
}

void Heavy_CircleStrings::cSystem_3nm0dAvf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Ycq0Ji5M, HV_BINOP_SUBTRACT, 1, m, &cBinop_Ycq0Ji5M_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_SB7OOGXK, 2, m, &cDelay_SB7OOGXK_sendMessage);
}

void Heavy_CircleStrings::cMsg_abMsNLnP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_3nm0dAvf_sendMessage);
}

void Heavy_CircleStrings::cMsg_4x99gPY6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_sIWIpZnh, 0, m, &cDelay_sIWIpZnh_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_SB7OOGXK, 0, m, &cDelay_SB7OOGXK_sendMessage);
}

void Heavy_CircleStrings::cMsg_X3OMqnMg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_c1knj7qf, HV_BINOP_MAX, 1, m, &cBinop_c1knj7qf_sendMessage);
}

void Heavy_CircleStrings::cBinop_c1knj7qf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4raMJCcP, HV_BINOP_SUBTRACT, 1, m, &cBinop_4raMJCcP_sendMessage);
}

void Heavy_CircleStrings::cCast_UZ5WlpaH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_sIWIpZnh, 0, m, &cDelay_sIWIpZnh_sendMessage);
}

void Heavy_CircleStrings::cBinop_kTSfo05n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_sIWIpZnh, 2, m, &cDelay_sIWIpZnh_sendMessage);
}

void Heavy_CircleStrings::cBinop_Ycq0Ji5M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_kTSfo05n_sendMessage);
}

void Heavy_CircleStrings::cCast_4iFmIZdQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_XjRxuH4R, 0, m, &cVar_XjRxuH4R_sendMessage);
  cMsg_AoMI58pw_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_aP34WzdI, 0, m, &cTabhead_aP34WzdI_sendMessage);
}

void Heavy_CircleStrings::cMsg_LUnpFvAN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Ky3EdDxb_sendMessage);
}

void Heavy_CircleStrings::cSystem_Ky3EdDxb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_aJeCyTqu_sendMessage);
}

void Heavy_CircleStrings::cDelay_hJijPeeD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_hJijPeeD, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_axVWNkiI, 0, m, &cDelay_axVWNkiI_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_hJijPeeD, 0, m, &cDelay_hJijPeeD_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_5aCN7SnC, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_axVWNkiI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_axVWNkiI, m);
  cMsg_bhN3XzSx_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_q0RTiNNM_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_3PXbfgcf_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_MUYIXPQL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_EctaIuOD_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_5ijKsCE4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_625ls0CD_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_hJijPeeD, 2, m, &cDelay_hJijPeeD_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_EKAwpkNZ_sendMessage);
}

void Heavy_CircleStrings::cMsg_EctaIuOD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_5ijKsCE4, 0, m, &hTable_5ijKsCE4_sendMessage);
}

void Heavy_CircleStrings::cBinop_aJeCyTqu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 43.5337f, 0, m, &cBinop_MUYIXPQL_sendMessage);
}

void Heavy_CircleStrings::cMsg_bhN3XzSx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_5ijKsCE4, 0, m, &hTable_5ijKsCE4_sendMessage);
}

void Heavy_CircleStrings::cCast_EKAwpkNZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_hJijPeeD, 0, m, &cDelay_hJijPeeD_sendMessage);
}

void Heavy_CircleStrings::cMsg_625ls0CD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_axVWNkiI, 2, m, &cDelay_axVWNkiI_sendMessage);
}

void Heavy_CircleStrings::cMsg_3PXbfgcf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_5aCN7SnC, 1, m, NULL);
}

void Heavy_CircleStrings::cTabhead_wFy48l8R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_oQc0gkbR, HV_BINOP_SUBTRACT, 0, m, &cBinop_oQc0gkbR_sendMessage);
}

void Heavy_CircleStrings::cMsg_o1evkdXH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_sIYvKqxT_sendMessage);
}

void Heavy_CircleStrings::cSystem_sIYvKqxT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_coaAHhxV_sendMessage);
}

void Heavy_CircleStrings::cVar_piYaJnlH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_GHSURqmF_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_BKFRlsec_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_BKFRlsec, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_zf55GMUc, 0, m, &cDelay_zf55GMUc_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_gukZNESn, 0, m, &sTabread_gukZNESn_sendMessage);
}

void Heavy_CircleStrings::cDelay_zf55GMUc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_zf55GMUc, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_gukZNESn, 0, m, &sTabread_gukZNESn_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_zf55GMUc, 0, m, &cDelay_zf55GMUc_sendMessage);
}

void Heavy_CircleStrings::sTabread_gukZNESn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_R0Gygysl, HV_BINOP_SUBTRACT, 0, m, &cBinop_R0Gygysl_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_ScEyYj1b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_P39qmOhJ, HV_BINOP_MAX, 0, m, &cBinop_P39qmOhJ_sendMessage);
}

void Heavy_CircleStrings::cBinop_coaAHhxV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ScEyYj1b, HV_BINOP_MULTIPLY, 0, m, &cBinop_ScEyYj1b_sendMessage);
}

void Heavy_CircleStrings::cBinop_oQc0gkbR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_02S0zrde_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_gukZNESn, 0, m, &sTabread_gukZNESn_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_BFlAJ70O_sendMessage);
}

void Heavy_CircleStrings::cSystem_ZNagtvxz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_R0Gygysl, HV_BINOP_SUBTRACT, 1, m, &cBinop_R0Gygysl_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_zf55GMUc, 2, m, &cDelay_zf55GMUc_sendMessage);
}

void Heavy_CircleStrings::cMsg_GHSURqmF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ZNagtvxz_sendMessage);
}

void Heavy_CircleStrings::cMsg_02S0zrde_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_BKFRlsec, 0, m, &cDelay_BKFRlsec_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_zf55GMUc, 0, m, &cDelay_zf55GMUc_sendMessage);
}

void Heavy_CircleStrings::cMsg_Wqq5pfXt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_P39qmOhJ, HV_BINOP_MAX, 1, m, &cBinop_P39qmOhJ_sendMessage);
}

void Heavy_CircleStrings::cBinop_P39qmOhJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_oQc0gkbR, HV_BINOP_SUBTRACT, 1, m, &cBinop_oQc0gkbR_sendMessage);
}

void Heavy_CircleStrings::cCast_BFlAJ70O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_BKFRlsec, 0, m, &cDelay_BKFRlsec_sendMessage);
}

void Heavy_CircleStrings::cBinop_4Zts0CeY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_BKFRlsec, 2, m, &cDelay_BKFRlsec_sendMessage);
}

void Heavy_CircleStrings::cBinop_R0Gygysl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_4Zts0CeY_sendMessage);
}

void Heavy_CircleStrings::cCast_XrMYfBmf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_piYaJnlH, 0, m, &cVar_piYaJnlH_sendMessage);
  cMsg_o1evkdXH_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_wFy48l8R, 0, m, &cTabhead_wFy48l8R_sendMessage);
}

void Heavy_CircleStrings::cMsg_ADwH3lP4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_jM4WiDSG_sendMessage);
}

void Heavy_CircleStrings::cSystem_jM4WiDSG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_HmNiacUq_sendMessage);
}

void Heavy_CircleStrings::cDelay_wGyKGDwC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_wGyKGDwC, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_8kS0NbW0, 0, m, &cDelay_8kS0NbW0_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_wGyKGDwC, 0, m, &cDelay_wGyKGDwC_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_VhBxg0Z2, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_8kS0NbW0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_8kS0NbW0, m);
  cMsg_3aYcPLwy_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_XkasN3PZ_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_FJxD4sXS_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_TXwJwCdu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_UB5zmFWn_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_fyDX5noA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_VaHGRsKX_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_wGyKGDwC, 2, m, &cDelay_wGyKGDwC_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_lvfrL4Iw_sendMessage);
}

void Heavy_CircleStrings::cMsg_UB5zmFWn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_fyDX5noA, 0, m, &hTable_fyDX5noA_sendMessage);
}

void Heavy_CircleStrings::cBinop_HmNiacUq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 75.2546f, 0, m, &cBinop_TXwJwCdu_sendMessage);
}

void Heavy_CircleStrings::cMsg_3aYcPLwy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_fyDX5noA, 0, m, &hTable_fyDX5noA_sendMessage);
}

void Heavy_CircleStrings::cCast_lvfrL4Iw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_wGyKGDwC, 0, m, &cDelay_wGyKGDwC_sendMessage);
}

void Heavy_CircleStrings::cMsg_VaHGRsKX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_8kS0NbW0, 2, m, &cDelay_8kS0NbW0_sendMessage);
}

void Heavy_CircleStrings::cMsg_FJxD4sXS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_VhBxg0Z2, 1, m, NULL);
}

void Heavy_CircleStrings::cVar_9uERaytd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_VBjv806w, 0, m, &cVar_VBjv806w_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_c4ndmtKo, 0, m, &cVar_c4ndmtKo_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_zoAiLxe5, 0, m, &cVar_zoAiLxe5_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_IYbZH8FJ, 0, m, &cVar_IYbZH8FJ_sendMessage);
}

void Heavy_CircleStrings::cVar_S43alZiX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.01f, 0, m, &cBinop_NnxiSMKr_sendMessage);
}

void Heavy_CircleStrings::cPack_YUG6igGk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_VFA3AXed, 0, m, NULL);
}

void Heavy_CircleStrings::cVar_c4ndmtKo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_JfG0H3Ja, HV_BINOP_MULTIPLY, 0, m, &cBinop_JfG0H3Ja_sendMessage);
}

void Heavy_CircleStrings::cMsg_O3FKb2Ca_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ZYfr5Ncq_sendMessage);
}

void Heavy_CircleStrings::cSystem_ZYfr5Ncq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_TisEp1Di_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_JfG0H3Ja_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_EQ16O8mx_sendMessage);
}

void Heavy_CircleStrings::cBinop_5AWB3yDa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_JfG0H3Ja, HV_BINOP_MULTIPLY, 1, m, &cBinop_JfG0H3Ja_sendMessage);
}

void Heavy_CircleStrings::cMsg_TisEp1Di_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_5AWB3yDa_sendMessage);
}

void Heavy_CircleStrings::cBinop_EQ16O8mx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_NuEof5xS_sendMessage);
}

void Heavy_CircleStrings::cBinop_NuEof5xS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_8h4ETjPJ_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_umxtjKmp, m);
}

void Heavy_CircleStrings::cBinop_8h4ETjPJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_4kqT8FwB, m);
}

void Heavy_CircleStrings::cVar_zoAiLxe5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_GGLEQjZJ, HV_BINOP_MULTIPLY, 0, m, &cBinop_GGLEQjZJ_sendMessage);
}

void Heavy_CircleStrings::cMsg_2rt51FrQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_8c7nDk1F_sendMessage);
}

void Heavy_CircleStrings::cSystem_8c7nDk1F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_lCstYyfT_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_GGLEQjZJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_iHnb16mr_sendMessage);
}

void Heavy_CircleStrings::cBinop_ySarhzYY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_GGLEQjZJ, HV_BINOP_MULTIPLY, 1, m, &cBinop_GGLEQjZJ_sendMessage);
}

void Heavy_CircleStrings::cMsg_lCstYyfT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_ySarhzYY_sendMessage);
}

void Heavy_CircleStrings::cBinop_iHnb16mr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_dKnEFLbD_sendMessage);
}

void Heavy_CircleStrings::cBinop_dKnEFLbD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_BLPJYUDp_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_nTtCLfpd, m);
}

void Heavy_CircleStrings::cBinop_BLPJYUDp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_aDMvFOc4, m);
}

void Heavy_CircleStrings::cVar_IYbZH8FJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_PKzFFIW1, HV_BINOP_MULTIPLY, 0, m, &cBinop_PKzFFIW1_sendMessage);
}

void Heavy_CircleStrings::cMsg_oqnJEcfO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_SW9XnhES_sendMessage);
}

void Heavy_CircleStrings::cSystem_SW9XnhES_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_hNIuiPqa_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_PKzFFIW1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_ZfnOKDyF_sendMessage);
}

void Heavy_CircleStrings::cBinop_196zCjFN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_PKzFFIW1, HV_BINOP_MULTIPLY, 1, m, &cBinop_PKzFFIW1_sendMessage);
}

void Heavy_CircleStrings::cMsg_hNIuiPqa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_196zCjFN_sendMessage);
}

void Heavy_CircleStrings::cBinop_ZfnOKDyF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_YugcQURk_sendMessage);
}

void Heavy_CircleStrings::cBinop_YugcQURk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_WAssalBE_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_TQmuGjOM, m);
}

void Heavy_CircleStrings::cBinop_WAssalBE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_IOQX6Vkx, m);
}

void Heavy_CircleStrings::cBinop_Q8mrTTCq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_FiHZCJ7s, 0, m, &cPack_FiHZCJ7s_sendMessage);
}

void Heavy_CircleStrings::cMsg_oZnzzDYW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 3000.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_9uERaytd, 0, m, &cVar_9uERaytd_sendMessage);
}

void Heavy_CircleStrings::cBinop_NnxiSMKr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_YUG6igGk, 0, m, &cPack_YUG6igGk_sendMessage);
}

void Heavy_CircleStrings::cBinop_fKimxgLz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_U6eEgHtR, 0, m, &cPack_U6eEgHtR_sendMessage);
}

void Heavy_CircleStrings::cMsg_rO8GliYO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Q2KaJNaR_sendMessage);
}

void Heavy_CircleStrings::cSystem_Q2KaJNaR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_FrRxn7ii_sendMessage);
}

void Heavy_CircleStrings::cVar_zdRc1MtI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_VyfDRA0F_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSystem_puleCZwZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_zK2fT4vK_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_ts9piLeS, m);
}

void Heavy_CircleStrings::cBinop_FrRxn7ii_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_J7ubcf1q, m);
}

void Heavy_CircleStrings::cMsg_VyfDRA0F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_puleCZwZ_sendMessage);
}

void Heavy_CircleStrings::cBinop_zK2fT4vK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_0NHdwa0u, m);
}

void Heavy_CircleStrings::cVar_FMsMNLX8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_1ub0ChQu, HV_BINOP_MULTIPLY, 0, m, &cBinop_1ub0ChQu_sendMessage);
}

void Heavy_CircleStrings::cMsg_NETlPpn5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_YGt9EvsR_sendMessage);
}

void Heavy_CircleStrings::cSystem_YGt9EvsR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_NstHGEFg_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_1ub0ChQu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_g1debMs1_sendMessage);
}

void Heavy_CircleStrings::cBinop_qMqiUZDL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_1ub0ChQu, HV_BINOP_MULTIPLY, 1, m, &cBinop_1ub0ChQu_sendMessage);
}

void Heavy_CircleStrings::cMsg_NstHGEFg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_qMqiUZDL_sendMessage);
}

void Heavy_CircleStrings::cBinop_g1debMs1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_yZPjnHuV_sendMessage);
}

void Heavy_CircleStrings::cBinop_yZPjnHuV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_I0eCmkvn_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_3He9rWm4, m);
}

void Heavy_CircleStrings::cBinop_I0eCmkvn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_jglJru0z, m);
}

void Heavy_CircleStrings::cBinop_cYYB88Hq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, -1.0f, 0, m, &cBinop_YoCi4ieQ_sendMessage);
}

void Heavy_CircleStrings::cBinop_YoCi4ieQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_le8NBeiN, m);
}

void Heavy_CircleStrings::cBinop_sb60K0Ae_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_kb4R4eGT_sendMessage);
}

void Heavy_CircleStrings::cBinop_kb4R4eGT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_VabSha49_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_2gKj4A2Z_sendMessage);
}

void Heavy_CircleStrings::cVar_s5lWnt7x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_NnaNnBxU_sendMessage);
}

void Heavy_CircleStrings::cMsg_Qcv7mKEI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_WlRVhAWA_sendMessage);
}

void Heavy_CircleStrings::cSystem_WlRVhAWA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_YCx3vYz1, HV_BINOP_DIVIDE, 1, m, &cBinop_YCx3vYz1_sendMessage);
}

void Heavy_CircleStrings::cBinop_VabSha49_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_KjZj03Sb_sendMessage);
}

void Heavy_CircleStrings::cBinop_KjZj03Sb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_0ro2gKY6, m);
}

void Heavy_CircleStrings::cMsg_zi6j9V8m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_ftubwonU_sendMessage);
}

void Heavy_CircleStrings::cBinop_ftubwonU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_sb60K0Ae_sendMessage);
}

void Heavy_CircleStrings::cBinop_2gKj4A2Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_6FyEoIpK, m);
}

void Heavy_CircleStrings::cBinop_NnaNnBxU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_Jpo4Zk0X_sendMessage);
}

void Heavy_CircleStrings::cBinop_Jpo4Zk0X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_YCx3vYz1, HV_BINOP_DIVIDE, 0, m, &cBinop_YCx3vYz1_sendMessage);
}

void Heavy_CircleStrings::cBinop_YCx3vYz1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_zi6j9V8m_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cVar_7YBH2mnI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_VUoTiXBb_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_LsXsOFrN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_3mEbIMx2_sendMessage);
}

void Heavy_CircleStrings::cSystem_3mEbIMx2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_0rhw2hLV_sendMessage);
}

void Heavy_CircleStrings::cDelay_WzVliaRN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_WzVliaRN, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_LiCm9JlR, 0, m, &cDelay_LiCm9JlR_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_WzVliaRN, 0, m, &cDelay_WzVliaRN_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_A8RyULfA, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_LiCm9JlR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_LiCm9JlR, m);
  cMsg_jTLGlAa8_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_jdapMXJB_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_dX2qdbbm_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_RGh5kvNj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_go8NWcBc_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_PPlwW0wY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_eMHrhhcN_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_WzVliaRN, 2, m, &cDelay_WzVliaRN_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_z4vEXTjU_sendMessage);
}

void Heavy_CircleStrings::cMsg_go8NWcBc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_PPlwW0wY, 0, m, &hTable_PPlwW0wY_sendMessage);
}

void Heavy_CircleStrings::cBinop_0rhw2hLV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 500.0f, 0, m, &cBinop_RGh5kvNj_sendMessage);
}

void Heavy_CircleStrings::cMsg_jTLGlAa8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_PPlwW0wY, 0, m, &hTable_PPlwW0wY_sendMessage);
}

void Heavy_CircleStrings::cCast_z4vEXTjU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_WzVliaRN, 0, m, &cDelay_WzVliaRN_sendMessage);
}

void Heavy_CircleStrings::cMsg_eMHrhhcN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_LiCm9JlR, 2, m, &cDelay_LiCm9JlR_sendMessage);
}

void Heavy_CircleStrings::cMsg_dX2qdbbm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_A8RyULfA, 1, m, NULL);
}

void Heavy_CircleStrings::cMsg_tZ8bP8wY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cMsg_VUoTiXBb_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_VUoTiXBb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 20.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_xUxIeTT1, 0, m, NULL);
}

void Heavy_CircleStrings::cPack_9yqCXNnu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_mBKP8IzG, 0, m, NULL);
}

void Heavy_CircleStrings::cCast_03jVTN5I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_9yqCXNnu, 0, m, &cPack_9yqCXNnu_sendMessage);
}

void Heavy_CircleStrings::cCast_vUTAeXMV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_7WmnV7kO_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cMsg_Je3B7m9d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 500.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_mBKP8IzG, 0, m, NULL);
}

void Heavy_CircleStrings::cMsg_cDrw4xbC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 500.0f);
  sVarf_onMessage(_c, &Context(_c)->sVarf_qTGt7ieI, m);
}

void Heavy_CircleStrings::cMsg_UH8IJQo7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.3f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_cYYB88Hq_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_HypWcPSj_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_PHVruyi8, 0, m, &cSlice_PHVruyi8_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_nw4OIwAd, 0, m, &cRandom_nw4OIwAd_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_FUmD3duq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_AYZOaYoS_sendMessage);
}

void Heavy_CircleStrings::cUnop_AYZOaYoS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 10.0f, 0, m, &cBinop_f9BZ0mt8_sendMessage);
}

void Heavy_CircleStrings::cRandom_nw4OIwAd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 80.0f, 0, m, &cBinop_FUmD3duq_sendMessage);
}

void Heavy_CircleStrings::cSlice_PHVruyi8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_nw4OIwAd, 1, m, &cRandom_nw4OIwAd_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cSwitchcase_SIVu2Jpt_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_umNgdQMK, 0, m, &cSlice_umNgdQMK_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_DIkLfxNx, 0, m, &cRandom_DIkLfxNx_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_j5qSD1DZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_j9My7Dhi_sendMessage);
}

void Heavy_CircleStrings::cUnop_j9My7Dhi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_3qfWCaZ6, 0, m, &cPack_3qfWCaZ6_sendMessage);
}

void Heavy_CircleStrings::cRandom_DIkLfxNx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 200.0f, 0, m, &cBinop_j5qSD1DZ_sendMessage);
}

void Heavy_CircleStrings::cSlice_umNgdQMK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_DIkLfxNx, 1, m, &cRandom_DIkLfxNx_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cVar_dHcGBwCr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_px67VliA_sendMessage);
}

void Heavy_CircleStrings::cPack_iWA2L3Rc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_3qmmioih, 0, m, NULL);
}

void Heavy_CircleStrings::cUnop_5oEe41nx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_5h3q0oMO_sendMessage);
}

void Heavy_CircleStrings::cBinop_EimFHTnm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_EXP, m, &cUnop_5oEe41nx_sendMessage);
}

void Heavy_CircleStrings::cPack_bgIgn5yg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_1y3L0Pq6, 0, m, NULL);
}

void Heavy_CircleStrings::cVar_yOhHCP0t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.5f, 0, m, &cBinop_kVNqBq3s_sendMessage);
}

void Heavy_CircleStrings::cMsg_ljNaJ8u4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_EbNMifau_sendMessage);
}

void Heavy_CircleStrings::cSystem_EbNMifau_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_Y0TIJrMK_sendMessage);
}

void Heavy_CircleStrings::cDelay_O2Tzblq5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_O2Tzblq5, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_vuhaYkiM, 0, m, &cDelay_vuhaYkiM_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_O2Tzblq5, 0, m, &cDelay_O2Tzblq5_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_FmCqbKUF, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_vuhaYkiM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_vuhaYkiM, m);
  cMsg_idCbwclV_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_wweAtq2z_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_jzMuDoaB_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_RUG3ylXI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_GTQeYyVL_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_7jsQ9opx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_seiwOeU5_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_O2Tzblq5, 2, m, &cDelay_O2Tzblq5_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_QQhv772P_sendMessage);
}

void Heavy_CircleStrings::cMsg_GTQeYyVL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_7jsQ9opx, 0, m, &hTable_7jsQ9opx_sendMessage);
}

void Heavy_CircleStrings::cBinop_Y0TIJrMK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 5000.0f, 0, m, &cBinop_RUG3ylXI_sendMessage);
}

void Heavy_CircleStrings::cMsg_idCbwclV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_7jsQ9opx, 0, m, &hTable_7jsQ9opx_sendMessage);
}

void Heavy_CircleStrings::cCast_QQhv772P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_O2Tzblq5, 0, m, &cDelay_O2Tzblq5_sendMessage);
}

void Heavy_CircleStrings::cMsg_seiwOeU5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_vuhaYkiM, 2, m, &cDelay_vuhaYkiM_sendMessage);
}

void Heavy_CircleStrings::cMsg_jzMuDoaB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_FmCqbKUF, 1, m, NULL);
}

void Heavy_CircleStrings::cMsg_vhzvfOGf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ocX0H6TB_sendMessage);
}

void Heavy_CircleStrings::cSystem_ocX0H6TB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_mvjMYaok_sendMessage);
}

void Heavy_CircleStrings::cVar_rpEvAsq0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_EVxMcjvR_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSystem_So41gXki_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_pjiL81k9_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_kBeeHRFJ, m);
}

void Heavy_CircleStrings::cBinop_mvjMYaok_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_QzoTxFn1, m);
}

void Heavy_CircleStrings::cMsg_EVxMcjvR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_So41gXki_sendMessage);
}

void Heavy_CircleStrings::cBinop_pjiL81k9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_TvuZAr7q, m);
}

void Heavy_CircleStrings::cMsg_1jbiFD4M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_x1Vt6Roy_sendMessage);
}

void Heavy_CircleStrings::cSystem_x1Vt6Roy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_pIFUVvY6_sendMessage);
}

void Heavy_CircleStrings::cVar_KmuDXz2l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_D6dVwNOH_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSystem_Pr7cC1Bu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_TI2DgNNM_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_ZUGw0L1t, m);
}

void Heavy_CircleStrings::cBinop_pIFUVvY6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_4oenKeRe, m);
}

void Heavy_CircleStrings::cMsg_D6dVwNOH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Pr7cC1Bu_sendMessage);
}

void Heavy_CircleStrings::cBinop_TI2DgNNM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_KDd8cxnP, m);
}

void Heavy_CircleStrings::cBinop_pFy6wCm7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_b8b100td_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_N54HvsFx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_njf7xIx9_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_SX2bPdxx_sendMessage);
}

void Heavy_CircleStrings::cCast_njf7xIx9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_pFy6wCm7, HV_BINOP_DIVIDE, 1, m, &cBinop_pFy6wCm7_sendMessage);
}

void Heavy_CircleStrings::cCast_SX2bPdxx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_pFy6wCm7, HV_BINOP_DIVIDE, 0, m, &cBinop_pFy6wCm7_sendMessage);
}

void Heavy_CircleStrings::cBinop_5h3q0oMO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_eCbQ7uu5_sendMessage);
}

void Heavy_CircleStrings::cBinop_Co7zTFvF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 87.3365f, 0, m, &cBinop_EimFHTnm_sendMessage);
}

void Heavy_CircleStrings::cBinop_eCbQ7uu5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_pFy6wCm7, HV_BINOP_DIVIDE, 0, m, &cBinop_pFy6wCm7_sendMessage);
}

void Heavy_CircleStrings::cBinop_kVNqBq3s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_bgIgn5yg, 0, m, &cPack_bgIgn5yg_sendMessage);
}

void Heavy_CircleStrings::cBinop_px67VliA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.001f, 0, m, &cBinop_N54HvsFx_sendMessage);
  cPack_onMessage(_c, &Context(_c)->cPack_iWA2L3Rc, 0, m, &cPack_iWA2L3Rc_sendMessage);
}

void Heavy_CircleStrings::cMsg_X9F4bkKT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 100.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_dHcGBwCr, 0, m, &cVar_dHcGBwCr_sendMessage);
}

void Heavy_CircleStrings::cMsg_Yb9L5Rn2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.5f);
  cVar_onMessage(_c, &Context(_c)->cVar_yOhHCP0t, 0, m, &cVar_yOhHCP0t_sendMessage);
}

void Heavy_CircleStrings::cMsg_b8b100td_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 30.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_8e8ExncG, 0, m, NULL);
}

void Heavy_CircleStrings::cMsg_lJfhLY1H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_gxtl5tcO_sendMessage);
}

void Heavy_CircleStrings::cSystem_gxtl5tcO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_xuGezjmF_sendMessage);
}

void Heavy_CircleStrings::cVar_9f9UlSz2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_pyYCdhOX_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSystem_CsC8U5zt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_KlzoTlxY_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_n6ffOqUb, m);
}

void Heavy_CircleStrings::cBinop_xuGezjmF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_NkKeq4SG, m);
}

void Heavy_CircleStrings::cMsg_pyYCdhOX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_CsC8U5zt_sendMessage);
}

void Heavy_CircleStrings::cBinop_KlzoTlxY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_9Jh147To, m);
}

void Heavy_CircleStrings::cVar_PZGlDA4M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ErtoGu4C, HV_BINOP_MULTIPLY, 0, m, &cBinop_ErtoGu4C_sendMessage);
}

void Heavy_CircleStrings::cMsg_C8auJuRL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Awh7xJTW_sendMessage);
}

void Heavy_CircleStrings::cSystem_Awh7xJTW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_OfgQGJLT_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_ErtoGu4C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_RII77z20_sendMessage);
}

void Heavy_CircleStrings::cBinop_zCAZe20P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ErtoGu4C, HV_BINOP_MULTIPLY, 1, m, &cBinop_ErtoGu4C_sendMessage);
}

void Heavy_CircleStrings::cMsg_OfgQGJLT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_zCAZe20P_sendMessage);
}

void Heavy_CircleStrings::cBinop_RII77z20_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_rkUTjVQ5_sendMessage);
}

void Heavy_CircleStrings::cBinop_rkUTjVQ5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_GONrC7Sa_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_YoVv5H5i, m);
}

void Heavy_CircleStrings::cBinop_GONrC7Sa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_J7Mm7ASH, m);
}

void Heavy_CircleStrings::cBinop_XqHCwE1I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, -1.0f, 0, m, &cBinop_LuLVloXS_sendMessage);
}

void Heavy_CircleStrings::cBinop_LuLVloXS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_nWHFzWDP, m);
}

void Heavy_CircleStrings::cBinop_t4Rba8jj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_9k0NGaYS_sendMessage);
}

void Heavy_CircleStrings::cBinop_9k0NGaYS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_GiN7ss3q_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_GeuprA7w_sendMessage);
}

void Heavy_CircleStrings::cVar_5miSL3kM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_yk5EC6ig_sendMessage);
}

void Heavy_CircleStrings::cMsg_3rLyIgsB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_yITjePvX_sendMessage);
}

void Heavy_CircleStrings::cSystem_yITjePvX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_7M90kSP8, HV_BINOP_DIVIDE, 1, m, &cBinop_7M90kSP8_sendMessage);
}

void Heavy_CircleStrings::cBinop_GiN7ss3q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_NYPZFfmI_sendMessage);
}

void Heavy_CircleStrings::cBinop_NYPZFfmI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_OQxFUwWU, m);
}

void Heavy_CircleStrings::cMsg_XjIUXkYy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_KD7GMVld_sendMessage);
}

void Heavy_CircleStrings::cBinop_KD7GMVld_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_t4Rba8jj_sendMessage);
}

void Heavy_CircleStrings::cBinop_GeuprA7w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_W1ALPYvw, m);
}

void Heavy_CircleStrings::cBinop_yk5EC6ig_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_pmR0BojS_sendMessage);
}

void Heavy_CircleStrings::cBinop_pmR0BojS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_7M90kSP8, HV_BINOP_DIVIDE, 0, m, &cBinop_7M90kSP8_sendMessage);
}

void Heavy_CircleStrings::cBinop_7M90kSP8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_XjIUXkYy_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cVar_Kolo1L1g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_uRTH5gwM_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_xd8rJiQJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_8sHvJ2xS_sendMessage);
}

void Heavy_CircleStrings::cSystem_8sHvJ2xS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_C43MX36B_sendMessage);
}

void Heavy_CircleStrings::cDelay_K2BiNpv9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_K2BiNpv9, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_rPoqKuln, 0, m, &cDelay_rPoqKuln_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_K2BiNpv9, 0, m, &cDelay_K2BiNpv9_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_mBAjwpGT, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_rPoqKuln_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_rPoqKuln, m);
  cMsg_moEVDB3o_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_Ub32wfZZ_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_I9wFcF2F_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_JwRMEf0a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_XtzsbdQb_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_x7yW6Isu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_n4J48k2d_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_K2BiNpv9, 2, m, &cDelay_K2BiNpv9_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_E72NOSKf_sendMessage);
}

void Heavy_CircleStrings::cMsg_XtzsbdQb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_x7yW6Isu, 0, m, &hTable_x7yW6Isu_sendMessage);
}

void Heavy_CircleStrings::cBinop_C43MX36B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 200.0f, 0, m, &cBinop_JwRMEf0a_sendMessage);
}

void Heavy_CircleStrings::cMsg_moEVDB3o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_x7yW6Isu, 0, m, &hTable_x7yW6Isu_sendMessage);
}

void Heavy_CircleStrings::cCast_E72NOSKf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_K2BiNpv9, 0, m, &cDelay_K2BiNpv9_sendMessage);
}

void Heavy_CircleStrings::cMsg_n4J48k2d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_rPoqKuln, 2, m, &cDelay_rPoqKuln_sendMessage);
}

void Heavy_CircleStrings::cMsg_I9wFcF2F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_mBAjwpGT, 1, m, NULL);
}

void Heavy_CircleStrings::cMsg_sbs7Wa6i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cMsg_uRTH5gwM_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_uRTH5gwM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 20.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_0AJz5Y1w, 0, m, NULL);
}

void Heavy_CircleStrings::cVar_k06XdDYL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cMsg_QllgyywM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_pQBuIgdS_sendMessage);
}

void Heavy_CircleStrings::cSystem_pQBuIgdS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_YXkbI7rJ, HV_BINOP_MULTIPLY, 1, m, &cBinop_YXkbI7rJ_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_GMZZQjuQ, HV_BINOP_MULTIPLY, 1, m, &cBinop_GMZZQjuQ_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_3r8bAIWW_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cMsg_XGj29VGG_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_XGj29VGG_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_sj4e4rp5_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cDelay_gnEZnS5V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_gnEZnS5V, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_gnEZnS5V, 0, m, &cDelay_gnEZnS5V_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_JbxJFpgi, 0, m, &cVar_JbxJFpgi_sendMessage);
}

void Heavy_CircleStrings::cCast_sj4e4rp5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_XGj29VGG_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_gnEZnS5V, 0, m, &cDelay_gnEZnS5V_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_JbxJFpgi, 0, m, &cVar_JbxJFpgi_sendMessage);
}

void Heavy_CircleStrings::cMsg_iu4KsLkS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_5JPMffh6_sendMessage);
}

void Heavy_CircleStrings::cSystem_5JPMffh6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_qw7pX6bp_sendMessage);
}

void Heavy_CircleStrings::cVar_ncd4NLaV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_KgP5tCo9, HV_BINOP_MULTIPLY, 0, m, &cBinop_KgP5tCo9_sendMessage);
}

void Heavy_CircleStrings::cMsg_XGj29VGG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_gnEZnS5V, 0, m, &cDelay_gnEZnS5V_sendMessage);
}

void Heavy_CircleStrings::cBinop_xbhwLceg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_gnEZnS5V, 2, m, &cDelay_gnEZnS5V_sendMessage);
}

void Heavy_CircleStrings::cBinop_qw7pX6bp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_KgP5tCo9, HV_BINOP_MULTIPLY, 1, m, &cBinop_KgP5tCo9_sendMessage);
}

void Heavy_CircleStrings::cBinop_KgP5tCo9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_xbhwLceg_sendMessage);
}

void Heavy_CircleStrings::cVar_JbxJFpgi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_gzQNRuYj, HV_BINOP_SUBTRACT, 0, m, &cBinop_gzQNRuYj_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_LESS_THAN_EQL, 0.0f, 0, m, &cBinop_PdEekdLy_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_x2wtddjq_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ddl4kQup_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Qbl9sH3Q_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cCast_ddl4kQup_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_exPuLLpA, 0, m, &cVar_exPuLLpA_sendMessage);
}

void Heavy_CircleStrings::cCast_Qbl9sH3Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_8Zl6Z0QK_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_mE6mlwT9_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_D4pQQvd0_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cSlice_onMessage(_c, &Context(_c)->cSlice_5xOp8eOf, 0, m, &cSlice_5xOp8eOf_sendMessage);
      break;
    }
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_Dm6OtPjz, 0, m, &cSlice_Dm6OtPjz_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_hFuPXAuU_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_HwGPcSwD, 0, m, &cSlice_HwGPcSwD_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_2tioCZwK, 0, m, &cSlice_2tioCZwK_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_nRAoxxK9_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ObKSBICg_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cSlice_5xOp8eOf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_YpISNaUp_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_YpISNaUp_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cSlice_Dm6OtPjz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_CNEPgb9m_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_5snHCAAg_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_CNEPgb9m_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_5snHCAAg_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cVar_HD8S4Pol_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_WxN8EEaU_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_RAZMNBkU_sendMessage);
}

void Heavy_CircleStrings::cVar_Jav6hQnb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_NjfXjkAK_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cSwitchcase_NjfXjkAK_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_HyjzWOJO_sendMessage);
      break;
    }
    default: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_YXkbI7rJ, HV_BINOP_MULTIPLY, 0, m, &cBinop_YXkbI7rJ_sendMessage);
      cBinop_onMessage(_c, &Context(_c)->cBinop_n9vbwqCG, HV_BINOP_DIVIDE, 1, m, &cBinop_n9vbwqCG_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_ncd4NLaV, 0, m, &cVar_ncd4NLaV_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cCast_HyjzWOJO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_DBteqzVk_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cVar_BTpVXvBJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_W63lvv5X, HV_BINOP_SUBTRACT, 1, m, &cBinop_W63lvv5X_sendMessage);
}

void Heavy_CircleStrings::cVar_H11lwsNO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_exPuLLpA, 0, m, &cVar_exPuLLpA_sendMessage);
}

void Heavy_CircleStrings::cVar_exPuLLpA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_AsVfKV9V, HV_BINOP_ADD, 0, m, &cBinop_AsVfKV9V_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_SsBhT7hu, HV_BINOP_ADD, 0, m, &cBinop_SsBhT7hu_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_j2tAghve, 0, m, &cVar_j2tAghve_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.05776f, 0, m, &cBinop_Co7zTFvF_sendMessage);
}

void Heavy_CircleStrings::cSlice_HwGPcSwD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_WxN8EEaU_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_RAZMNBkU_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cSlice_2tioCZwK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_8t0nIIyV_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_VD60Itwc_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_vrJ06jqL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_JbxJFpgi, 1, m, &cVar_JbxJFpgi_sendMessage);
}

void Heavy_CircleStrings::cBinop_GMZZQjuQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_vrJ06jqL_sendMessage);
}

void Heavy_CircleStrings::cBinop_YXkbI7rJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_NcLi25R5_sendMessage);
}

void Heavy_CircleStrings::cBinop_NcLi25R5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_gzQNRuYj, HV_BINOP_SUBTRACT, 1, m, &cBinop_gzQNRuYj_sendMessage);
}

void Heavy_CircleStrings::cBinop_gzQNRuYj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_JbxJFpgi, 1, m, &cVar_JbxJFpgi_sendMessage);
}

void Heavy_CircleStrings::cMsg_cykH9UnI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_3r8bAIWW_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cMsg_bBdZAwZ0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_3r8bAIWW_onMessage(_c, NULL, 0, m, NULL);
  cBinop_onMessage(_c, &Context(_c)->cBinop_SsBhT7hu, HV_BINOP_ADD, 1, m, &cBinop_SsBhT7hu_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_AsVfKV9V, HV_BINOP_ADD, 1, m, &cBinop_AsVfKV9V_sendMessage);
}

void Heavy_CircleStrings::cBinop_PdEekdLy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_x2wtddjq_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cBinop_AsVfKV9V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_exPuLLpA, 1, m, &cVar_exPuLLpA_sendMessage);
}

void Heavy_CircleStrings::cBinop_n9vbwqCG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MZK0xM9W, HV_BINOP_DIVIDE, 1, m, &cBinop_MZK0xM9W_sendMessage);
}

void Heavy_CircleStrings::cBinop_MZK0xM9W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_SsBhT7hu, HV_BINOP_ADD, 1, m, &cBinop_SsBhT7hu_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_AsVfKV9V, HV_BINOP_ADD, 1, m, &cBinop_AsVfKV9V_sendMessage);
}

void Heavy_CircleStrings::cCast_RAZMNBkU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_n9vbwqCG, HV_BINOP_DIVIDE, 0, m, &cBinop_n9vbwqCG_sendMessage);
}

void Heavy_CircleStrings::cCast_WxN8EEaU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_GMZZQjuQ, HV_BINOP_MULTIPLY, 0, m, &cBinop_GMZZQjuQ_sendMessage);
}

void Heavy_CircleStrings::cCast_VD60Itwc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_W63lvv5X, HV_BINOP_SUBTRACT, 0, m, &cBinop_W63lvv5X_sendMessage);
}

void Heavy_CircleStrings::cCast_8t0nIIyV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_H11lwsNO, 1, m, &cVar_H11lwsNO_sendMessage);
}

void Heavy_CircleStrings::cCast_mE6mlwT9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_H11lwsNO, 0, m, &cVar_H11lwsNO_sendMessage);
}

void Heavy_CircleStrings::cCast_8Zl6Z0QK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_bBdZAwZ0_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_SsBhT7hu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_BTpVXvBJ, 0, m, &cVar_BTpVXvBJ_sendMessage);
}

void Heavy_CircleStrings::cMsg_YpISNaUp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_3r8bAIWW_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cMsg_CpmZ3jbl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_HD8S4Pol, 1, m, &cVar_HD8S4Pol_sendMessage);
}

void Heavy_CircleStrings::cMsg_DBteqzVk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 20.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_YXkbI7rJ, HV_BINOP_MULTIPLY, 0, m, &cBinop_YXkbI7rJ_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_n9vbwqCG, HV_BINOP_DIVIDE, 1, m, &cBinop_n9vbwqCG_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_ncd4NLaV, 0, m, &cVar_ncd4NLaV_sendMessage);
}

void Heavy_CircleStrings::cCast_5snHCAAg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_RRwIORlN_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_SsBhT7hu, HV_BINOP_ADD, 0, m, &cBinop_SsBhT7hu_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_exPuLLpA, 1, m, &cVar_exPuLLpA_sendMessage);
}

void Heavy_CircleStrings::cCast_CNEPgb9m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_YpISNaUp_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_W63lvv5X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MZK0xM9W, HV_BINOP_DIVIDE, 0, m, &cBinop_MZK0xM9W_sendMessage);
}

void Heavy_CircleStrings::cCast_RRwIORlN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_bBdZAwZ0_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_nRAoxxK9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_cykH9UnI_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_ObKSBICg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_CpmZ3jbl_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_hFuPXAuU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_HD8S4Pol, 0, m, &cVar_HD8S4Pol_sendMessage);
}

void Heavy_CircleStrings::cVar_j2tAghve_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cPack_KE3SbkZa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_D4pQQvd0_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cMsg_dtQ4jMO8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_4lwDjbM9_sendMessage);
}

void Heavy_CircleStrings::cSystem_4lwDjbM9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_aSkp7Ezs, HV_BINOP_MULTIPLY, 1, m, &cBinop_aSkp7Ezs_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_gvFbFUOb, HV_BINOP_MULTIPLY, 1, m, &cBinop_gvFbFUOb_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_F5eBYLgA_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cMsg_olOFHlES_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_olOFHlES_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Nx9j2ZCb_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cDelay_wN31GZ6x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_wN31GZ6x, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_wN31GZ6x, 0, m, &cDelay_wN31GZ6x_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_kHXk1qH5, 0, m, &cVar_kHXk1qH5_sendMessage);
}

void Heavy_CircleStrings::cCast_Nx9j2ZCb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_olOFHlES_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_wN31GZ6x, 0, m, &cDelay_wN31GZ6x_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_kHXk1qH5, 0, m, &cVar_kHXk1qH5_sendMessage);
}

void Heavy_CircleStrings::cMsg_dmneso2d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_nUAUp4n5_sendMessage);
}

void Heavy_CircleStrings::cSystem_nUAUp4n5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_KUO1qQjQ_sendMessage);
}

void Heavy_CircleStrings::cVar_9DPzXJzk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_3mkbqC6V, HV_BINOP_MULTIPLY, 0, m, &cBinop_3mkbqC6V_sendMessage);
}

void Heavy_CircleStrings::cMsg_olOFHlES_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_wN31GZ6x, 0, m, &cDelay_wN31GZ6x_sendMessage);
}

void Heavy_CircleStrings::cBinop_CG53Q7K6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_wN31GZ6x, 2, m, &cDelay_wN31GZ6x_sendMessage);
}

void Heavy_CircleStrings::cBinop_KUO1qQjQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_3mkbqC6V, HV_BINOP_MULTIPLY, 1, m, &cBinop_3mkbqC6V_sendMessage);
}

void Heavy_CircleStrings::cBinop_3mkbqC6V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_CG53Q7K6_sendMessage);
}

void Heavy_CircleStrings::cVar_kHXk1qH5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_yk7tUSWF, HV_BINOP_SUBTRACT, 0, m, &cBinop_yk7tUSWF_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_LESS_THAN_EQL, 0.0f, 0, m, &cBinop_KumEAFmG_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_6DXYGEow_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_7bkXnOi6_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_6GxK9EQh_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cCast_7bkXnOi6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_cSyP1io4, 0, m, &cVar_cSyP1io4_sendMessage);
}

void Heavy_CircleStrings::cCast_6GxK9EQh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ZLvjgOid_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_73SDg3S0_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_MW0mOHjf_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cSlice_onMessage(_c, &Context(_c)->cSlice_nwhv0OLO, 0, m, &cSlice_nwhv0OLO_sendMessage);
      break;
    }
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_Ycpcmo2r, 0, m, &cSlice_Ycpcmo2r_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_4mGY33sT_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_7ga1aHIx, 0, m, &cSlice_7ga1aHIx_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_saNjZKPV, 0, m, &cSlice_saNjZKPV_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_cDka10ll_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_zYvSeFTk_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cSlice_nwhv0OLO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_5CEgWhuH_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_5CEgWhuH_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cSlice_Ycpcmo2r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Cjdzt7Pd_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_1u2EUA3G_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Cjdzt7Pd_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_1u2EUA3G_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cVar_eUB2axKk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_MWSFRGQt_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_eBaKZjzP_sendMessage);
}

void Heavy_CircleStrings::cVar_IMcPdQOU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_HTzBdzrB_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cSwitchcase_HTzBdzrB_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_YvgupVe9_sendMessage);
      break;
    }
    default: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_aSkp7Ezs, HV_BINOP_MULTIPLY, 0, m, &cBinop_aSkp7Ezs_sendMessage);
      cBinop_onMessage(_c, &Context(_c)->cBinop_lFqAchSF, HV_BINOP_DIVIDE, 1, m, &cBinop_lFqAchSF_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_9DPzXJzk, 0, m, &cVar_9DPzXJzk_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cCast_YvgupVe9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_nwg9hXEp_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cVar_xE3PY6vU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_kC8yKEZi, HV_BINOP_SUBTRACT, 1, m, &cBinop_kC8yKEZi_sendMessage);
}

void Heavy_CircleStrings::cVar_nKOWpStL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_cSyP1io4, 0, m, &cVar_cSyP1io4_sendMessage);
}

void Heavy_CircleStrings::cVar_cSyP1io4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_pUO37GHx, HV_BINOP_ADD, 0, m, &cBinop_pUO37GHx_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_aT12NGAb, HV_BINOP_ADD, 0, m, &cBinop_aT12NGAb_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_k06XdDYL, 0, m, &cVar_k06XdDYL_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_sCMes5G2, m);
}

void Heavy_CircleStrings::cSlice_7ga1aHIx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_MWSFRGQt_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_eBaKZjzP_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cSlice_saNjZKPV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_8uwU8Q3S_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_NQmEfnIJ_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_IE9l53Z4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_kHXk1qH5, 1, m, &cVar_kHXk1qH5_sendMessage);
}

void Heavy_CircleStrings::cBinop_gvFbFUOb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_IE9l53Z4_sendMessage);
}

void Heavy_CircleStrings::cBinop_aSkp7Ezs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_rJ2kUiqE_sendMessage);
}

void Heavy_CircleStrings::cBinop_rJ2kUiqE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_yk7tUSWF, HV_BINOP_SUBTRACT, 1, m, &cBinop_yk7tUSWF_sendMessage);
}

void Heavy_CircleStrings::cBinop_yk7tUSWF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_kHXk1qH5, 1, m, &cVar_kHXk1qH5_sendMessage);
}

void Heavy_CircleStrings::cMsg_Ln0gHggE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_F5eBYLgA_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cMsg_7T0amITW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_F5eBYLgA_onMessage(_c, NULL, 0, m, NULL);
  cBinop_onMessage(_c, &Context(_c)->cBinop_aT12NGAb, HV_BINOP_ADD, 1, m, &cBinop_aT12NGAb_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_pUO37GHx, HV_BINOP_ADD, 1, m, &cBinop_pUO37GHx_sendMessage);
}

void Heavy_CircleStrings::cBinop_KumEAFmG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_6DXYGEow_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cBinop_pUO37GHx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_cSyP1io4, 1, m, &cVar_cSyP1io4_sendMessage);
}

void Heavy_CircleStrings::cBinop_lFqAchSF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_10va4fzI, HV_BINOP_DIVIDE, 1, m, &cBinop_10va4fzI_sendMessage);
}

void Heavy_CircleStrings::cBinop_10va4fzI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_aT12NGAb, HV_BINOP_ADD, 1, m, &cBinop_aT12NGAb_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_pUO37GHx, HV_BINOP_ADD, 1, m, &cBinop_pUO37GHx_sendMessage);
}

void Heavy_CircleStrings::cCast_eBaKZjzP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_lFqAchSF, HV_BINOP_DIVIDE, 0, m, &cBinop_lFqAchSF_sendMessage);
}

void Heavy_CircleStrings::cCast_MWSFRGQt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_gvFbFUOb, HV_BINOP_MULTIPLY, 0, m, &cBinop_gvFbFUOb_sendMessage);
}

void Heavy_CircleStrings::cCast_NQmEfnIJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_kC8yKEZi, HV_BINOP_SUBTRACT, 0, m, &cBinop_kC8yKEZi_sendMessage);
}

void Heavy_CircleStrings::cCast_8uwU8Q3S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_nKOWpStL, 1, m, &cVar_nKOWpStL_sendMessage);
}

void Heavy_CircleStrings::cCast_ZLvjgOid_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_7T0amITW_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_73SDg3S0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_nKOWpStL, 0, m, &cVar_nKOWpStL_sendMessage);
}

void Heavy_CircleStrings::cBinop_aT12NGAb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_xE3PY6vU, 0, m, &cVar_xE3PY6vU_sendMessage);
}

void Heavy_CircleStrings::cMsg_5CEgWhuH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_F5eBYLgA_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cMsg_O4ZaptNL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_eUB2axKk, 1, m, &cVar_eUB2axKk_sendMessage);
}

void Heavy_CircleStrings::cMsg_nwg9hXEp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 20.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_aSkp7Ezs, HV_BINOP_MULTIPLY, 0, m, &cBinop_aSkp7Ezs_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_lFqAchSF, HV_BINOP_DIVIDE, 1, m, &cBinop_lFqAchSF_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_9DPzXJzk, 0, m, &cVar_9DPzXJzk_sendMessage);
}

void Heavy_CircleStrings::cCast_1u2EUA3G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_HPIrj95h_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_aT12NGAb, HV_BINOP_ADD, 0, m, &cBinop_aT12NGAb_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_cSyP1io4, 1, m, &cVar_cSyP1io4_sendMessage);
}

void Heavy_CircleStrings::cCast_Cjdzt7Pd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_5CEgWhuH_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_kC8yKEZi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_10va4fzI, HV_BINOP_DIVIDE, 0, m, &cBinop_10va4fzI_sendMessage);
}

void Heavy_CircleStrings::cCast_HPIrj95h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_7T0amITW_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_4mGY33sT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_eUB2axKk, 0, m, &cVar_eUB2axKk_sendMessage);
}

void Heavy_CircleStrings::cCast_zYvSeFTk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_O4ZaptNL_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_cDka10ll_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Ln0gHggE_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cPack_3qfWCaZ6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_MW0mOHjf_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cPack_GVvoVYO8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_gAF7LBmc, 0, m, NULL);
}

void Heavy_CircleStrings::cBinop_GUKDDgA2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 4.0f, 0, m, &cBinop_u82GXxCQ_sendMessage);
}

void Heavy_CircleStrings::cBinop_u82GXxCQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_KE3SbkZa, 0, m, &cPack_KE3SbkZa_sendMessage);
}

void Heavy_CircleStrings::cBinop_f9BZ0mt8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_GUKDDgA2_sendMessage);
}

void Heavy_CircleStrings::cCast_FNIv0tiz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_SIVu2Jpt_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cCast_FG0oUxAc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_HypWcPSj_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cMsg_R0aTmhJD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.15f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_XqHCwE1I_sendMessage);
}

void Heavy_CircleStrings::cBinop_UwxYw4Dw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_qkKiDHiJ_sendMessage);
}

void Heavy_CircleStrings::cBinop_qkKiDHiJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_mMLpdQtp_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_UhWDwvha_sendMessage);
}

void Heavy_CircleStrings::cVar_wEgefPHf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_BtVqzDMk_sendMessage);
}

void Heavy_CircleStrings::cMsg_T35p1EbU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_my7wI3Ro_sendMessage);
}

void Heavy_CircleStrings::cSystem_my7wI3Ro_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_DOFw6xat, HV_BINOP_DIVIDE, 1, m, &cBinop_DOFw6xat_sendMessage);
}

void Heavy_CircleStrings::cBinop_mMLpdQtp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_TNlE9CvU_sendMessage);
}

void Heavy_CircleStrings::cBinop_TNlE9CvU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_irTY8WQQ, m);
}

void Heavy_CircleStrings::cMsg_xK00e3hU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_N36i1PR9_sendMessage);
}

void Heavy_CircleStrings::cBinop_N36i1PR9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_UwxYw4Dw_sendMessage);
}

void Heavy_CircleStrings::cBinop_UhWDwvha_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_O7n4PLVN, m);
}

void Heavy_CircleStrings::cBinop_BtVqzDMk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_vI9nn7Zp_sendMessage);
}

void Heavy_CircleStrings::cBinop_vI9nn7Zp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_DOFw6xat, HV_BINOP_DIVIDE, 0, m, &cBinop_DOFw6xat_sendMessage);
}

void Heavy_CircleStrings::cBinop_DOFw6xat_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_xK00e3hU_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cVar_nEgDisUK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cIf_AF1XkyBF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 0.0f, 0, m, &cBinop_YYA6GJoz_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_7pjy8meb, 0, m, &cIf_7pjy8meb_sendMessage);
      break;
    }
    case 1: {
      cMsg_xjm0xgfy_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_jDKW6UpE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_AF1XkyBF, 1, m, &cIf_AF1XkyBF_sendMessage);
}

void Heavy_CircleStrings::cIf_7pjy8meb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_v2mgTkyn_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.2f, 0, m, &cBinop_BHxqWv4v_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_YYA6GJoz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_7pjy8meb, 1, m, &cIf_7pjy8meb_sendMessage);
}

void Heavy_CircleStrings::cMsg_xjm0xgfy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.2f, 0, m, &cBinop_BHxqWv4v_sendMessage);
}

void Heavy_CircleStrings::cMsg_v2mgTkyn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.2f, 0, m, &cBinop_BHxqWv4v_sendMessage);
}

void Heavy_CircleStrings::cIf_jjdDjr09_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 0.0f, 0, m, &cBinop_JbcKjupL_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_noTtZVs1, 0, m, &cIf_noTtZVs1_sendMessage);
      break;
    }
    case 1: {
      cMsg_E7ImVjmi_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_eRVQVuo3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_jjdDjr09, 1, m, &cIf_jjdDjr09_sendMessage);
}

void Heavy_CircleStrings::cIf_noTtZVs1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_ngby8VHk_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cPack_onMessage(_c, &Context(_c)->cPack_3xHLeGU5, 0, m, &cPack_3xHLeGU5_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_JbcKjupL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_noTtZVs1, 1, m, &cIf_noTtZVs1_sendMessage);
}

void Heavy_CircleStrings::cMsg_E7ImVjmi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_3xHLeGU5, 0, m, &cPack_3xHLeGU5_sendMessage);
}

void Heavy_CircleStrings::cMsg_ngby8VHk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_3xHLeGU5, 0, m, &cPack_3xHLeGU5_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_pmFLHTEN_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_iEYNF5dB, 0, m, &cSlice_iEYNF5dB_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_XsETpGvX, 0, m, &cRandom_XsETpGvX_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_mIVi9hkK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_FwCWzv7y_sendMessage);
}

void Heavy_CircleStrings::cUnop_FwCWzv7y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_o3N7uycb_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cRandom_XsETpGvX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8388610.0f, 0, m, &cBinop_mIVi9hkK_sendMessage);
}

void Heavy_CircleStrings::cSlice_iEYNF5dB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_XsETpGvX, 1, m, &cRandom_XsETpGvX_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cMsg_o3N7uycb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 1.0f);
  sVari_onMessage(_c, &Context(_c)->sVari_PV4lGAPF, m);
}

void Heavy_CircleStrings::cTabhead_ZEBE9mCN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_SGFdBFzW, HV_BINOP_SUBTRACT, 0, m, &cBinop_SGFdBFzW_sendMessage);
}

void Heavy_CircleStrings::cMsg_y377du2T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_4sf1FrUp_sendMessage);
}

void Heavy_CircleStrings::cSystem_4sf1FrUp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_wSgWO3IM_sendMessage);
}

void Heavy_CircleStrings::cVar_rzu47SIA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_5sdrvdZw_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_P6kpQkfw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_P6kpQkfw, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_CHhabVuK, 0, m, &cDelay_CHhabVuK_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_fX1QVVSX, 0, m, &sTabread_fX1QVVSX_sendMessage);
}

void Heavy_CircleStrings::cDelay_CHhabVuK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_CHhabVuK, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_fX1QVVSX, 0, m, &sTabread_fX1QVVSX_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_CHhabVuK, 0, m, &cDelay_CHhabVuK_sendMessage);
}

void Heavy_CircleStrings::sTabread_fX1QVVSX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_TqypGGB0, HV_BINOP_SUBTRACT, 0, m, &cBinop_TqypGGB0_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_Xf4lCH1e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_UEKMM6P5, HV_BINOP_MAX, 0, m, &cBinop_UEKMM6P5_sendMessage);
}

void Heavy_CircleStrings::cBinop_wSgWO3IM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Xf4lCH1e, HV_BINOP_MULTIPLY, 0, m, &cBinop_Xf4lCH1e_sendMessage);
}

void Heavy_CircleStrings::cBinop_SGFdBFzW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_tVf4uXjP_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_fX1QVVSX, 0, m, &sTabread_fX1QVVSX_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_sHOl4dQo_sendMessage);
}

void Heavy_CircleStrings::cSystem_c8EjQ6Q7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_TqypGGB0, HV_BINOP_SUBTRACT, 1, m, &cBinop_TqypGGB0_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_CHhabVuK, 2, m, &cDelay_CHhabVuK_sendMessage);
}

void Heavy_CircleStrings::cMsg_5sdrvdZw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_c8EjQ6Q7_sendMessage);
}

void Heavy_CircleStrings::cMsg_tVf4uXjP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_P6kpQkfw, 0, m, &cDelay_P6kpQkfw_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_CHhabVuK, 0, m, &cDelay_CHhabVuK_sendMessage);
}

void Heavy_CircleStrings::cMsg_0CGmgP5w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_UEKMM6P5, HV_BINOP_MAX, 1, m, &cBinop_UEKMM6P5_sendMessage);
}

void Heavy_CircleStrings::cBinop_UEKMM6P5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_SGFdBFzW, HV_BINOP_SUBTRACT, 1, m, &cBinop_SGFdBFzW_sendMessage);
}

void Heavy_CircleStrings::cCast_sHOl4dQo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_P6kpQkfw, 0, m, &cDelay_P6kpQkfw_sendMessage);
}

void Heavy_CircleStrings::cBinop_FudIwCF3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_P6kpQkfw, 2, m, &cDelay_P6kpQkfw_sendMessage);
}

void Heavy_CircleStrings::cBinop_TqypGGB0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_FudIwCF3_sendMessage);
}

void Heavy_CircleStrings::cCast_trwVSfZW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_rzu47SIA, 0, m, &cVar_rzu47SIA_sendMessage);
  cMsg_y377du2T_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_ZEBE9mCN, 0, m, &cTabhead_ZEBE9mCN_sendMessage);
}

void Heavy_CircleStrings::cBinop_EmeLlrA5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_vKdOQVXe_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_4L6YySkd_sendMessage);
}

void Heavy_CircleStrings::cBinop_Vs5OIGSb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_dFr3mpPm_sendMessage);
}

void Heavy_CircleStrings::cBinop_dFr3mpPm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_VoSa65Mb, HV_BINOP_POW, 1, m, &cBinop_VoSa65Mb_sendMessage);
  cMsg_kzfrmWzs_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_VoSa65Mb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_EmeLlrA5_sendMessage);
}

void Heavy_CircleStrings::cMsg_kzfrmWzs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_VoSa65Mb, HV_BINOP_POW, 0, m, &cBinop_VoSa65Mb_sendMessage);
}

void Heavy_CircleStrings::cVar_6jjiWVWa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_Vs5OIGSb_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_BT8siNqp_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_c7jxblQj_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_dswBLBpx_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_2bJOuzrs_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_2bJOuzrs_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_TklAUP8T, 1, m, &cDelay_TklAUP8T_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_qYluahA3_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cDelay_TklAUP8T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_TklAUP8T, m);
  cMsg_deBwQkGx_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_2bJOuzrs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_TklAUP8T, 0, m, &cDelay_TklAUP8T_sendMessage);
}

void Heavy_CircleStrings::cCast_qYluahA3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_TklAUP8T, 0, m, &cDelay_TklAUP8T_sendMessage);
}

void Heavy_CircleStrings::cVar_jKarz4n1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_VHkuh3eo, HV_BINOP_MULTIPLY, 0, m, &cBinop_VHkuh3eo_sendMessage);
}

void Heavy_CircleStrings::cMsg_nc2tq0nv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_PwN2uRhO_sendMessage);
}

void Heavy_CircleStrings::cSystem_PwN2uRhO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_U7WmEOQP_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_VHkuh3eo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_cQGnnKV2_sendMessage);
}

void Heavy_CircleStrings::cBinop_KrexORQm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_VHkuh3eo, HV_BINOP_MULTIPLY, 1, m, &cBinop_VHkuh3eo_sendMessage);
}

void Heavy_CircleStrings::cMsg_U7WmEOQP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_KrexORQm_sendMessage);
}

void Heavy_CircleStrings::cBinop_cQGnnKV2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_7Dw51Sau_sendMessage);
}

void Heavy_CircleStrings::cBinop_7Dw51Sau_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_HIRbwO9G_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_3kLMESJK, m);
}

void Heavy_CircleStrings::cBinop_HIRbwO9G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_78SG5i07, m);
}

void Heavy_CircleStrings::cMsg_6bI1wQmp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_MWuWqyt3_sendMessage);
}

void Heavy_CircleStrings::cSystem_MWuWqyt3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_YlttdP6o_sendMessage);
}

void Heavy_CircleStrings::cDelay_SNm3tw24_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_SNm3tw24, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_gMOGbzys, 0, m, &cDelay_gMOGbzys_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_SNm3tw24, 0, m, &cDelay_SNm3tw24_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_XARTVQyO, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_gMOGbzys_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_gMOGbzys, m);
  cMsg_3DDJh4Z7_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_PpmU6n9x_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_4vVluQcm_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_b3ZVUp9m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_VYz6RDtP_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_QGCM5bjp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_dPjZmUaI_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_SNm3tw24, 2, m, &cDelay_SNm3tw24_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_A6mVvwjV_sendMessage);
}

void Heavy_CircleStrings::cMsg_VYz6RDtP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_QGCM5bjp, 0, m, &hTable_QGCM5bjp_sendMessage);
}

void Heavy_CircleStrings::cBinop_YlttdP6o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 200.0f, 0, m, &cBinop_b3ZVUp9m_sendMessage);
}

void Heavy_CircleStrings::cMsg_3DDJh4Z7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_QGCM5bjp, 0, m, &hTable_QGCM5bjp_sendMessage);
}

void Heavy_CircleStrings::cCast_A6mVvwjV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_SNm3tw24, 0, m, &cDelay_SNm3tw24_sendMessage);
}

void Heavy_CircleStrings::cMsg_dPjZmUaI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_gMOGbzys, 2, m, &cDelay_gMOGbzys_sendMessage);
}

void Heavy_CircleStrings::cMsg_4vVluQcm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_XARTVQyO, 1, m, NULL);
}

void Heavy_CircleStrings::cMsg_DidncODz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 1.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_3L017wBY, 0, m, NULL);
}

void Heavy_CircleStrings::cMsg_deBwQkGx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 1.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_3L017wBY, 0, m, NULL);
}

void Heavy_CircleStrings::cCast_c7jxblQj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_DidncODz_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_BT8siNqp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_dswBLBpx_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cMsg_bXRZusu5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 60.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_Vs5OIGSb_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_BT8siNqp_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_c7jxblQj_sendMessage);
}

void Heavy_CircleStrings::cBinop_lgk2nqoS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Xf4lCH1e, HV_BINOP_MULTIPLY, 1, m, &cBinop_Xf4lCH1e_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_trwVSfZW_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_TklAUP8T, 1, m, &cDelay_TklAUP8T_sendMessage);
}

void Heavy_CircleStrings::cMsg_bIGfzxup_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1000.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_lgk2nqoS, HV_BINOP_DIVIDE, 0, m, &cBinop_lgk2nqoS_sendMessage);
}

void Heavy_CircleStrings::cCast_vKdOQVXe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_lgk2nqoS, HV_BINOP_DIVIDE, 1, m, &cBinop_lgk2nqoS_sendMessage);
}

void Heavy_CircleStrings::cCast_4L6YySkd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_bIGfzxup_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cVar_xlIY8NZW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_MAyCiGaN_sendMessage);
  cSwitchcase_KbKtJSSO_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cBinop_MAyCiGaN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_xlIY8NZW, 1, m, &cVar_xlIY8NZW_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_KbKtJSSO_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cMsg_vgZYsll4_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_vgZYsll4_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Mv0R6zJd_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cDelay_mnruniYL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_mnruniYL, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_mnruniYL, 0, m, &cDelay_mnruniYL_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_LbmRsRt5, 0, m, &cVar_LbmRsRt5_sendMessage);
  cSwitchcase_gKdNMbo6_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cCast_Mv0R6zJd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_vgZYsll4_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_mnruniYL, 0, m, &cDelay_mnruniYL_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_LbmRsRt5, 0, m, &cVar_LbmRsRt5_sendMessage);
  cSwitchcase_gKdNMbo6_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cMsg_pi5uwmay_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_q6lwjVsx_sendMessage);
}

void Heavy_CircleStrings::cSystem_q6lwjVsx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_Eiey1l9U_sendMessage);
}

void Heavy_CircleStrings::cVar_NoZr9Ai2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_EhDfVZyu, HV_BINOP_MULTIPLY, 0, m, &cBinop_EhDfVZyu_sendMessage);
}

void Heavy_CircleStrings::cMsg_vgZYsll4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_mnruniYL, 0, m, &cDelay_mnruniYL_sendMessage);
}

void Heavy_CircleStrings::cBinop_28O1DGAv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_mnruniYL, 2, m, &cDelay_mnruniYL_sendMessage);
}

void Heavy_CircleStrings::cBinop_Eiey1l9U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_EhDfVZyu, HV_BINOP_MULTIPLY, 1, m, &cBinop_EhDfVZyu_sendMessage);
}

void Heavy_CircleStrings::cBinop_EhDfVZyu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_28O1DGAv_sendMessage);
}

void Heavy_CircleStrings::cVar_LbmRsRt5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_Vs5OIGSb_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_BT8siNqp_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_c7jxblQj_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_gKdNMbo6_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_oRzitJP5, 0, m, &cSlice_oRzitJP5_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_XbYt5NUb, 0, m, &cRandom_XbYt5NUb_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_XemJCR7C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_A9fUtXdR_sendMessage);
}

void Heavy_CircleStrings::cUnop_A9fUtXdR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 40.0f, 0, m, &cBinop_sBq34czk_sendMessage);
}

void Heavy_CircleStrings::cRandom_XbYt5NUb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 25.0f, 0, m, &cBinop_XemJCR7C_sendMessage);
}

void Heavy_CircleStrings::cSlice_oRzitJP5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_XbYt5NUb, 1, m, &cRandom_XbYt5NUb_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cVar_Fk3OB7EV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cIf_n9HzMYMz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, -1.0f, 0, m, &cBinop_KoHdUELu_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_QtX0IUln, 0, m, &cIf_QtX0IUln_sendMessage);
      break;
    }
    case 1: {
      cMsg_OzGFJeJg_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_2zWcJT0U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_n9HzMYMz, 1, m, &cIf_n9HzMYMz_sendMessage);
}

void Heavy_CircleStrings::cIf_QtX0IUln_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_mksRDmCs_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.049f, 0, m, &cBinop_tQjxYhb7_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_KoHdUELu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_QtX0IUln, 1, m, &cIf_QtX0IUln_sendMessage);
}

void Heavy_CircleStrings::cMsg_OzGFJeJg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.049f, 0, m, &cBinop_tQjxYhb7_sendMessage);
}

void Heavy_CircleStrings::cMsg_mksRDmCs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, -1.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.049f, 0, m, &cBinop_tQjxYhb7_sendMessage);
}

void Heavy_CircleStrings::cIf_W6un9OED_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 0.0f, 0, m, &cBinop_1uiK96XO_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_oi0gKjFC, 0, m, &cIf_oi0gKjFC_sendMessage);
      break;
    }
    case 1: {
      cMsg_sXCkr42M_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_06WvpFm9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_W6un9OED, 1, m, &cIf_W6un9OED_sendMessage);
}

void Heavy_CircleStrings::cIf_oi0gKjFC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_HgRH82XM_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 4600.0f, 0, m, &cBinop_taCczZfL_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_1uiK96XO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_oi0gKjFC, 1, m, &cIf_oi0gKjFC_sendMessage);
}

void Heavy_CircleStrings::cMsg_sXCkr42M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 4600.0f, 0, m, &cBinop_taCczZfL_sendMessage);
}

void Heavy_CircleStrings::cMsg_HgRH82XM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 4600.0f, 0, m, &cBinop_taCczZfL_sendMessage);
}

void Heavy_CircleStrings::cPack_y8P8qVQg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_8Y4DxCb4, 0, m, NULL);
}

void Heavy_CircleStrings::cPack_3xHLeGU5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_ShN6x0iS, 0, m, NULL);
}

void Heavy_CircleStrings::cBinop_gvR52ywe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_nEgDisUK, 0, m, &cVar_nEgDisUK_sendMessage);
}

void Heavy_CircleStrings::cBinop_BHxqWv4v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5f, 0, m, &cBinop_kGwBxchS_sendMessage);
}

void Heavy_CircleStrings::cBinop_kGwBxchS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_eRVQVuo3_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_jjdDjr09, 0, m, &cIf_jjdDjr09_sendMessage);
}

void Heavy_CircleStrings::cBinop_sBq34czk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_NoZr9Ai2, 0, m, &cVar_NoZr9Ai2_sendMessage);
}

void Heavy_CircleStrings::cBinop_fIJZlJHw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_O0FWSn7k, m);
}

void Heavy_CircleStrings::cBinop_tQjxYhb7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.95f, 0, m, &cBinop_fIJZlJHw_sendMessage);
}

void Heavy_CircleStrings::cBinop_0alrwDSt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_jKarz4n1, 0, m, &cVar_jKarz4n1_sendMessage);
}

void Heavy_CircleStrings::cBinop_taCczZfL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2200.0f, 0, m, &cBinop_0alrwDSt_sendMessage);
}

void Heavy_CircleStrings::cCast_K7Fa0OAn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_tyJWEJaw_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_TCCgvpUi_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cVar_TkPuS1l4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_EGRRlytJ_sendMessage(_c, 0, m);
  cSend_nDhbxBEw_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_tyJWEJaw_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_19ocJNTE, 0, m, &cSlice_19ocJNTE_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_UfwipOxb, 0, m, &cRandom_UfwipOxb_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_yTdJ0PAU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_vSoHmsPO_sendMessage);
}

void Heavy_CircleStrings::cUnop_vSoHmsPO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1.28f, 0, m, &cBinop_NjbszODp_sendMessage);
  cSend_iBOM7yzr_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cRandom_UfwipOxb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 128.0f, 0, m, &cBinop_yTdJ0PAU_sendMessage);
}

void Heavy_CircleStrings::cSlice_19ocJNTE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_UfwipOxb, 1, m, &cRandom_UfwipOxb_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cVar_OxE9FGc5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_RWWIhzw6_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cVar_5w2x6vXo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_CU3gTE34_sendMessage);
}

void Heavy_CircleStrings::cBinop_CU3gTE34_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_5w2x6vXo, 1, m, &cVar_5w2x6vXo_sendMessage);
}

void Heavy_CircleStrings::cCast_qrHS0uoQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cVar_d0Ft8teU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cVar_dIaVyjCy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cCast_VPYQEAb4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_7pAXlKzy_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_TCCgvpUi_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_7A6BtOl6, 0, m, &cSlice_7A6BtOl6_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_P5AAzFNP, 0, m, &cRandom_P5AAzFNP_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_emOpjiVd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_j7Ya8rRv_sendMessage);
}

void Heavy_CircleStrings::cUnop_j7Ya8rRv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 20.0f, 0, m, &cBinop_SXB1qYQK_sendMessage);
}

void Heavy_CircleStrings::cRandom_P5AAzFNP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 100.0f, 0, m, &cBinop_emOpjiVd_sendMessage);
}

void Heavy_CircleStrings::cSlice_7A6BtOl6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_P5AAzFNP, 1, m, &cRandom_P5AAzFNP_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cCast_cCtKccGN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_g5mDBZSG_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_54uYCZww_sendMessage);
}

void Heavy_CircleStrings::cBinop_NjbszODp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_OxE9FGc5, 0, m, &cVar_OxE9FGc5_sendMessage);
}

void Heavy_CircleStrings::cSend_RWWIhzw6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_8nCpMyc8_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_EGRRlytJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_FrdgGU9i_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_iBOM7yzr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_U4ehvbIg_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_nDhbxBEw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_83M9Hmpd_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_o9cntbnS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.8f);
  cSend_SMOGk6vD_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_SMOGk6vD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_j0Ufjkmw_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_GmSgfPtZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSend_SMOGk6vD_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_7pAXlKzy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_3YmY9uz3_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_SXB1qYQK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_TkPuS1l4, 0, m, &cVar_TkPuS1l4_sendMessage);
}

void Heavy_CircleStrings::cCast_54uYCZww_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_X04TLerr_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_g5mDBZSG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Q8H77chg_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_X04TLerr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 64.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_TkPuS1l4, 0, m, &cVar_TkPuS1l4_sendMessage);
}

void Heavy_CircleStrings::cMsg_Q8H77chg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 127.0f);
  cSend_iBOM7yzr_sendMessage(_c, 0, m);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1.28f, 0, m, &cBinop_NjbszODp_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_GgvMnSQr_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_unDImarG, 0, m, &cSlice_unDImarG_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_eInFKQHX, 0, m, &cRandom_eInFKQHX_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_HqxlcEfc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_nOvVY0zB_sendMessage);
}

void Heavy_CircleStrings::cUnop_nOvVY0zB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 50.0f, 0, m, &cBinop_dECSANqd_sendMessage);
}

void Heavy_CircleStrings::cRandom_eInFKQHX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 200.0f, 0, m, &cBinop_HqxlcEfc_sendMessage);
}

void Heavy_CircleStrings::cSlice_unDImarG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_eInFKQHX, 1, m, &cRandom_eInFKQHX_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cSwitchcase_A6BFWsvL_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_QTYjtCO2, 0, m, &cSlice_QTYjtCO2_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_jhuYr3xb, 0, m, &cRandom_jhuYr3xb_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_2DiiCFo3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_OB6IpxR1_sendMessage);
}

void Heavy_CircleStrings::cUnop_OB6IpxR1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_hQBclfHX_sendMessage);
}

void Heavy_CircleStrings::cRandom_jhuYr3xb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_2DiiCFo3_sendMessage);
}

void Heavy_CircleStrings::cSlice_QTYjtCO2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_jhuYr3xb, 1, m, &cRandom_jhuYr3xb_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_wJ3k6Jaq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_VTPtDmUs, HV_BINOP_MULTIPLY, 0, m, &cBinop_VTPtDmUs_sendMessage);
}

void Heavy_CircleStrings::cBinop_MUinsjfs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_Pf0KuQRe_sendMessage);
}

void Heavy_CircleStrings::cBinop_Pf0KuQRe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4uzunjZu, HV_BINOP_POW, 1, m, &cBinop_4uzunjZu_sendMessage);
  cMsg_ZdDVtm2Z_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_4uzunjZu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_wJ3k6Jaq_sendMessage);
}

void Heavy_CircleStrings::cMsg_ZdDVtm2Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_4uzunjZu, HV_BINOP_POW, 0, m, &cBinop_4uzunjZu_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_bfQDkOQE_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_f74woDHz, 0, m, &cSlice_f74woDHz_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_h4YnVJoK, 0, m, &cRandom_h4YnVJoK_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_bMAlvz57_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_rvTVHVUE_sendMessage);
}

void Heavy_CircleStrings::cUnop_rvTVHVUE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_SwSQej0W_sendMessage);
}

void Heavy_CircleStrings::cRandom_h4YnVJoK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 15.0f, 0, m, &cBinop_bMAlvz57_sendMessage);
}

void Heavy_CircleStrings::cSlice_f74woDHz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_h4YnVJoK, 1, m, &cRandom_h4YnVJoK_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cPack_5gGnCKHq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_zQZ2LjM8, 0, m, NULL);
}

void Heavy_CircleStrings::cVar_x4xINvkE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_oQwicR2X_sendMessage);
}

void Heavy_CircleStrings::cVar_M18x5i90_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_UpxD1uhe, 0, m);
}

void Heavy_CircleStrings::cVar_k0RrR1xv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_7qwabEDz_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_eUFLOvMD_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_nspavFHF_sendMessage);
}

void Heavy_CircleStrings::cVar_LCShkyro_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cVar_wSZWF4Fa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cVar_YkEc34Ic_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cSwitchcase_jFrB1nfP_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_7nTyIWxN_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_7nTyIWxN_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_lL5wFiBM, 1, m, &cDelay_lL5wFiBM_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_9MbLh8t5_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cDelay_lL5wFiBM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_lL5wFiBM, m);
  cVar_onMessage(_c, &Context(_c)->cVar_wbRwO1xJ, 0, m, &cVar_wbRwO1xJ_sendMessage);
}

void Heavy_CircleStrings::cMsg_7nTyIWxN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_lL5wFiBM, 0, m, &cDelay_lL5wFiBM_sendMessage);
}

void Heavy_CircleStrings::cCast_9MbLh8t5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_lL5wFiBM, 0, m, &cDelay_lL5wFiBM_sendMessage);
}

void Heavy_CircleStrings::cVar_wbRwO1xJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Sz3BQ6ce_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_j6iVmWxg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_k0RrR1xv, 0, m, &cVar_k0RrR1xv_sendMessage);
}

void Heavy_CircleStrings::cMsg_WDWdkX58_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 25.0f);
  cSend_3BLVzIcR_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_DZ3gqjiG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 4000.0f);
  cSend_PeEnqwa6_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_14jKHVkf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSend_F6YHzDVn_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_9GRCMlzK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_vgfTutZr_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_c2hqShIJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cSend_ZPldOHHw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_AhseCEqk_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_3BLVzIcR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cSend_PeEnqwa6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_vgfTutZr_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_F6YHzDVn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_AhseCEqk_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_uwzTfmPu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 25.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_y4A9Rpld, 0, m, NULL);
}

void Heavy_CircleStrings::cMsg_Sz3BQ6ce_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 0);
  sLine_onMessage(_c, &Context(_c)->sLine_y4A9Rpld, 0, m, NULL);
}

void Heavy_CircleStrings::cCast_eUFLOvMD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_wbRwO1xJ, 1, m, &cVar_wbRwO1xJ_sendMessage);
}

void Heavy_CircleStrings::cCast_nspavFHF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_jFrB1nfP_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cCast_7qwabEDz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_uwzTfmPu_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_D35fsASg_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_TVoz83hS, 0, m, &cSlice_TVoz83hS_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_SHVkVZC8, 0, m, &cRandom_SHVkVZC8_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_0HMi6XmW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_nB3hpmDd_sendMessage);
}

void Heavy_CircleStrings::cUnop_nB3hpmDd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_EWYfklLY_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cRandom_SHVkVZC8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8388610.0f, 0, m, &cBinop_0HMi6XmW_sendMessage);
}

void Heavy_CircleStrings::cSlice_TVoz83hS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_SHVkVZC8, 1, m, &cRandom_SHVkVZC8_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cMsg_EWYfklLY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 1.0f);
  sVari_onMessage(_c, &Context(_c)->sVari_SYsiY7cX, m);
}

void Heavy_CircleStrings::cTabhead_yByfXtt9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_gQ55hn80, HV_BINOP_SUBTRACT, 0, m, &cBinop_gQ55hn80_sendMessage);
}

void Heavy_CircleStrings::cMsg_E84FXqcz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_OuPnG1Z0_sendMessage);
}

void Heavy_CircleStrings::cSystem_OuPnG1Z0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_U5xkkEd5_sendMessage);
}

void Heavy_CircleStrings::cVar_3A2ohpsB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_9Yv78jHq_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_cAIe9dlT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_cAIe9dlT, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_1FACIYW2, 0, m, &cDelay_1FACIYW2_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_Jg3NAmnX, 0, m, &sTabread_Jg3NAmnX_sendMessage);
}

void Heavy_CircleStrings::cDelay_1FACIYW2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_1FACIYW2, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_Jg3NAmnX, 0, m, &sTabread_Jg3NAmnX_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_1FACIYW2, 0, m, &cDelay_1FACIYW2_sendMessage);
}

void Heavy_CircleStrings::sTabread_Jg3NAmnX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_zmXoBkut, HV_BINOP_SUBTRACT, 0, m, &cBinop_zmXoBkut_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_SEliAVSi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_L7PTkLxx, HV_BINOP_MAX, 0, m, &cBinop_L7PTkLxx_sendMessage);
}

void Heavy_CircleStrings::cBinop_U5xkkEd5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_SEliAVSi, HV_BINOP_MULTIPLY, 0, m, &cBinop_SEliAVSi_sendMessage);
}

void Heavy_CircleStrings::cBinop_gQ55hn80_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_XWz1UsVy_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_Jg3NAmnX, 0, m, &sTabread_Jg3NAmnX_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_bxi6AFjn_sendMessage);
}

void Heavy_CircleStrings::cSystem_PXqonRfi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_zmXoBkut, HV_BINOP_SUBTRACT, 1, m, &cBinop_zmXoBkut_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_1FACIYW2, 2, m, &cDelay_1FACIYW2_sendMessage);
}

void Heavy_CircleStrings::cMsg_9Yv78jHq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_PXqonRfi_sendMessage);
}

void Heavy_CircleStrings::cMsg_XWz1UsVy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_cAIe9dlT, 0, m, &cDelay_cAIe9dlT_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_1FACIYW2, 0, m, &cDelay_1FACIYW2_sendMessage);
}

void Heavy_CircleStrings::cMsg_WnYqLWFU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_L7PTkLxx, HV_BINOP_MAX, 1, m, &cBinop_L7PTkLxx_sendMessage);
}

void Heavy_CircleStrings::cBinop_L7PTkLxx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_gQ55hn80, HV_BINOP_SUBTRACT, 1, m, &cBinop_gQ55hn80_sendMessage);
}

void Heavy_CircleStrings::cCast_bxi6AFjn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_cAIe9dlT, 0, m, &cDelay_cAIe9dlT_sendMessage);
}

void Heavy_CircleStrings::cBinop_uBrDg1Th_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_cAIe9dlT, 2, m, &cDelay_cAIe9dlT_sendMessage);
}

void Heavy_CircleStrings::cBinop_zmXoBkut_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_uBrDg1Th_sendMessage);
}

void Heavy_CircleStrings::cCast_GYpMHw2z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_3A2ohpsB, 0, m, &cVar_3A2ohpsB_sendMessage);
  cMsg_E84FXqcz_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_yByfXtt9, 0, m, &cTabhead_yByfXtt9_sendMessage);
}

void Heavy_CircleStrings::cBinop_dr4wd8fY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Y0u4LgXp_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_M3oSkJeT_sendMessage);
}

void Heavy_CircleStrings::cBinop_rDmMav6G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_TrtMu0JM_sendMessage);
}

void Heavy_CircleStrings::cBinop_TrtMu0JM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_KxsED7oV, HV_BINOP_POW, 1, m, &cBinop_KxsED7oV_sendMessage);
  cMsg_sGnUmesX_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_KxsED7oV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_dr4wd8fY_sendMessage);
}

void Heavy_CircleStrings::cMsg_sGnUmesX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_KxsED7oV, HV_BINOP_POW, 0, m, &cBinop_KxsED7oV_sendMessage);
}

void Heavy_CircleStrings::cVar_jpev2ICq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_rDmMav6G_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_96VCuVPo_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_9QnxtwP0_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_KYpbykeD_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_gGbcExzP_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_gGbcExzP_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_pzniaKYf, 1, m, &cDelay_pzniaKYf_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_p5P7lo31_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cDelay_pzniaKYf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_pzniaKYf, m);
  cMsg_DlzokgZL_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_gGbcExzP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_pzniaKYf, 0, m, &cDelay_pzniaKYf_sendMessage);
}

void Heavy_CircleStrings::cCast_p5P7lo31_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_pzniaKYf, 0, m, &cDelay_pzniaKYf_sendMessage);
}

void Heavy_CircleStrings::cVar_08LWfvXU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_meBH6uKn, HV_BINOP_MULTIPLY, 0, m, &cBinop_meBH6uKn_sendMessage);
}

void Heavy_CircleStrings::cMsg_riz0oF0M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_JLZWQPlm_sendMessage);
}

void Heavy_CircleStrings::cSystem_JLZWQPlm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_CQi5QAWG_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_meBH6uKn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_kOAGFQqc_sendMessage);
}

void Heavy_CircleStrings::cBinop_Fmcjmp8u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_meBH6uKn, HV_BINOP_MULTIPLY, 1, m, &cBinop_meBH6uKn_sendMessage);
}

void Heavy_CircleStrings::cMsg_CQi5QAWG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_Fmcjmp8u_sendMessage);
}

void Heavy_CircleStrings::cBinop_kOAGFQqc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_FZa6LNxA_sendMessage);
}

void Heavy_CircleStrings::cBinop_FZa6LNxA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_Too4zzHt_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_GqzXrUBn, m);
}

void Heavy_CircleStrings::cBinop_Too4zzHt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_YnWcGaHO, m);
}

void Heavy_CircleStrings::cMsg_WFvL6j9p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_GvsbkXL3_sendMessage);
}

void Heavy_CircleStrings::cSystem_GvsbkXL3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_6SiwI7J3_sendMessage);
}

void Heavy_CircleStrings::cDelay_5eL5qQcn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_5eL5qQcn, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_gQmSPTN6, 0, m, &cDelay_gQmSPTN6_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_5eL5qQcn, 0, m, &cDelay_5eL5qQcn_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_qojkXJOH, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_gQmSPTN6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_gQmSPTN6, m);
  cMsg_9Bu0r7T8_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_WS7axiXt_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_ZLPbPbts_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_HFtJcTtG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_IFO6kxRU_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_CgtUdKbt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_SAt1mDQp_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_5eL5qQcn, 2, m, &cDelay_5eL5qQcn_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_VQp0dxwW_sendMessage);
}

void Heavy_CircleStrings::cMsg_IFO6kxRU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_CgtUdKbt, 0, m, &hTable_CgtUdKbt_sendMessage);
}

void Heavy_CircleStrings::cBinop_6SiwI7J3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 200.0f, 0, m, &cBinop_HFtJcTtG_sendMessage);
}

void Heavy_CircleStrings::cMsg_9Bu0r7T8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_CgtUdKbt, 0, m, &hTable_CgtUdKbt_sendMessage);
}

void Heavy_CircleStrings::cCast_VQp0dxwW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_5eL5qQcn, 0, m, &cDelay_5eL5qQcn_sendMessage);
}

void Heavy_CircleStrings::cMsg_SAt1mDQp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_gQmSPTN6, 2, m, &cDelay_gQmSPTN6_sendMessage);
}

void Heavy_CircleStrings::cMsg_ZLPbPbts_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_qojkXJOH, 1, m, NULL);
}

void Heavy_CircleStrings::cMsg_iyQQPhpk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 1.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_XWWDuggY, 0, m, NULL);
}

void Heavy_CircleStrings::cMsg_DlzokgZL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 1.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_XWWDuggY, 0, m, NULL);
}

void Heavy_CircleStrings::cCast_9QnxtwP0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_iyQQPhpk_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_96VCuVPo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_KYpbykeD_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cMsg_YE8CnoeZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 60.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_rDmMav6G_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_96VCuVPo_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_9QnxtwP0_sendMessage);
}

void Heavy_CircleStrings::cBinop_8fzQYmgM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_SEliAVSi, HV_BINOP_MULTIPLY, 1, m, &cBinop_SEliAVSi_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_GYpMHw2z_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_pzniaKYf, 1, m, &cDelay_pzniaKYf_sendMessage);
}

void Heavy_CircleStrings::cMsg_9HUvonJm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1000.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_8fzQYmgM, HV_BINOP_DIVIDE, 0, m, &cBinop_8fzQYmgM_sendMessage);
}

void Heavy_CircleStrings::cCast_Y0u4LgXp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_8fzQYmgM, HV_BINOP_DIVIDE, 1, m, &cBinop_8fzQYmgM_sendMessage);
}

void Heavy_CircleStrings::cCast_M3oSkJeT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_9HUvonJm_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cUnop_GWrhu5R6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_FxA2aSP9, 0, m, &cPack_FxA2aSP9_sendMessage);
}

void Heavy_CircleStrings::cUnop_OiSH3XqI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_T7W2kkRW, 0, m, &cPack_T7W2kkRW_sendMessage);
}

void Heavy_CircleStrings::cPack_T7W2kkRW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_3ILYiCrq, 0, m, NULL);
}

void Heavy_CircleStrings::cPack_FxA2aSP9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_5QXNhSok, 0, m, NULL);
}

void Heavy_CircleStrings::cBinop_8kmGQVht_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_GWrhu5R6_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_SIN, m, &cUnop_OiSH3XqI_sendMessage);
}

void Heavy_CircleStrings::cMsg_21lmMX2j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.5f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_8kmGQVht_sendMessage);
}

void Heavy_CircleStrings::cSlice_xWzcgVhx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 127.0f, 0, m, &cBinop_DeGJcfVe_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cSlice_KCxKR3ti_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_rnvtnAgH_sendMessage);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_MUinsjfs_sendMessage);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_rDmMav6G_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_96VCuVPo_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_9QnxtwP0_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_hQBclfHX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.4f, 0, m, &cBinop_36UDMhR9_sendMessage);
}

void Heavy_CircleStrings::cBinop_36UDMhR9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_8kmGQVht_sendMessage);
}

void Heavy_CircleStrings::cBinop_DeGJcfVe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_nHmuUl37_sendMessage(_c, 0, m);
  cSend_xsLAwwJT_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_VTPtDmUs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_80NvrE4B_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_XBcXr0Tk_sendMessage);
}

void Heavy_CircleStrings::cBinop_SwSQej0W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.99f, 0, m, &cBinop_gqrlqGG2_sendMessage);
}

void Heavy_CircleStrings::cBinop_gqrlqGG2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_VTPtDmUs, HV_BINOP_MULTIPLY, 1, m, &cBinop_VTPtDmUs_sendMessage);
}

void Heavy_CircleStrings::cSend_nHmuUl37_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_3u04fSnV_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_XBcXr0Tk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_j6iVmWxg_sendMessage);
}

void Heavy_CircleStrings::cCast_80NvrE4B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_A6BFWsvL_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cBinop_oQwicR2X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_5gGnCKHq, 0, m, &cPack_5gGnCKHq_sendMessage);
}

void Heavy_CircleStrings::cSend_xsLAwwJT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_dKHTl5Gy_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_bL3tvsO7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_BJqx0LBS_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_tY43nCvs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 200.0f);
  cSend_bL3tvsO7_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_oflD9A5U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.999f);
  sVarf_onMessage(_c, &Context(_c)->sVarf_YUE8cA4Y, m);
}

void Heavy_CircleStrings::cCast_rnvtnAgH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_bfQDkOQE_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cVar_5qQXuOYL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_zFrIpapS_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_qz8xrhJo_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_MBHYslFr_sendMessage);
}

void Heavy_CircleStrings::cIf_DKNUOKEk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_ufIMkssV_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_geiAm6h1_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cMsg_0gWOr9ue_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_MeX14mcZ, HV_BINOP_POW, 0, m, &cBinop_MeX14mcZ_sendMessage);
}

void Heavy_CircleStrings::cBinop_MeX14mcZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_uaNnTTU2, 0, m, &cPack_uaNnTTU2_sendMessage);
}

void Heavy_CircleStrings::cBinop_AkOaxGuM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_LLFWSEhI_sendMessage);
}

void Heavy_CircleStrings::cCast_MBHYslFr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_DKNUOKEk, 0, m, &cIf_DKNUOKEk_sendMessage);
}

void Heavy_CircleStrings::cCast_qz8xrhJo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_0sIskbsm_sendMessage);
}

void Heavy_CircleStrings::cBinop_0sIskbsm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_DKNUOKEk, 1, m, &cIf_DKNUOKEk_sendMessage);
}

void Heavy_CircleStrings::cBinop_geiAm6h1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_AkOaxGuM_sendMessage);
}

void Heavy_CircleStrings::cMsg_ufIMkssV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_uaNnTTU2, 0, m, &cPack_uaNnTTU2_sendMessage);
}

void Heavy_CircleStrings::cBinop_LLFWSEhI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MeX14mcZ, HV_BINOP_POW, 1, m, &cBinop_MeX14mcZ_sendMessage);
  cMsg_0gWOr9ue_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cPack_uaNnTTU2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_sSDYtBHt, 0, m, NULL);
}

void Heavy_CircleStrings::cVar_FKIQ7qcR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_nw6sLeqF_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_zFrIpapS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSend_laDdAbWj_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_laDdAbWj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_002zsoz5_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_nw6sLeqF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_qa37TAUQ_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cVar_PuGlDK1h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_luKtdxiD_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_3uLdNv0I_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_hoKeUWYz_sendMessage);
}

void Heavy_CircleStrings::cIf_SfC5Ljnp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_0FM5qpya_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_ya8BnLel_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cMsg_nhEVnEVN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_7eKlM6zZ, HV_BINOP_POW, 0, m, &cBinop_7eKlM6zZ_sendMessage);
}

void Heavy_CircleStrings::cBinop_7eKlM6zZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_0tRN5aSl, 0, m, &cPack_0tRN5aSl_sendMessage);
}

void Heavy_CircleStrings::cBinop_61RGHCN6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_1c2AwtlB_sendMessage);
}

void Heavy_CircleStrings::cCast_hoKeUWYz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_SfC5Ljnp, 0, m, &cIf_SfC5Ljnp_sendMessage);
}

void Heavy_CircleStrings::cCast_3uLdNv0I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_cxUQSGvL_sendMessage);
}

void Heavy_CircleStrings::cBinop_cxUQSGvL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_SfC5Ljnp, 1, m, &cIf_SfC5Ljnp_sendMessage);
}

void Heavy_CircleStrings::cBinop_ya8BnLel_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_61RGHCN6_sendMessage);
}

void Heavy_CircleStrings::cMsg_0FM5qpya_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_0tRN5aSl, 0, m, &cPack_0tRN5aSl_sendMessage);
}

void Heavy_CircleStrings::cBinop_1c2AwtlB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_7eKlM6zZ, HV_BINOP_POW, 1, m, &cBinop_7eKlM6zZ_sendMessage);
  cMsg_nhEVnEVN_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cPack_0tRN5aSl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_HjQedXwF, 0, m, NULL);
}

void Heavy_CircleStrings::cVar_tfVeb2xy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_2S9dOJJ6_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_luKtdxiD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSend_Zx8FHB47_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_Zx8FHB47_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_kKfsjFPE_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_2S9dOJJ6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_6P36y0JI_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_AXBlKb7q_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_BahkjKum, 0, m, &cSlice_BahkjKum_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_Wk3K6xtn, 0, m, &cRandom_Wk3K6xtn_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_MfbdFWQL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_lj9VsoSj_sendMessage);
}

void Heavy_CircleStrings::cUnop_lj9VsoSj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_n8sq5uqS_sendMessage);
}

void Heavy_CircleStrings::cRandom_Wk3K6xtn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_MfbdFWQL_sendMessage);
}

void Heavy_CircleStrings::cSlice_BahkjKum_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_Wk3K6xtn, 1, m, &cRandom_Wk3K6xtn_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_WDEw8r7N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_LyrRfBnr, HV_BINOP_MULTIPLY, 0, m, &cBinop_LyrRfBnr_sendMessage);
}

void Heavy_CircleStrings::cBinop_HzwNVoUR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_bhOdurqE_sendMessage);
}

void Heavy_CircleStrings::cBinop_bhOdurqE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_osiUgZAA, HV_BINOP_POW, 1, m, &cBinop_osiUgZAA_sendMessage);
  cMsg_yzeeQcN4_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_osiUgZAA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_WDEw8r7N_sendMessage);
}

void Heavy_CircleStrings::cMsg_yzeeQcN4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_osiUgZAA, HV_BINOP_POW, 0, m, &cBinop_osiUgZAA_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_El1zaMwR_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_v0gapoXA, 0, m, &cSlice_v0gapoXA_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_reWDhLfP, 0, m, &cRandom_reWDhLfP_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_Kyp1yG8R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_aPmPsKqS_sendMessage);
}

void Heavy_CircleStrings::cUnop_aPmPsKqS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_cGvUvWTS_sendMessage);
}

void Heavy_CircleStrings::cRandom_reWDhLfP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 15.0f, 0, m, &cBinop_Kyp1yG8R_sendMessage);
}

void Heavy_CircleStrings::cSlice_v0gapoXA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_reWDhLfP, 1, m, &cRandom_reWDhLfP_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cPack_hCzuDCpN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_J7fLbiEL, 0, m, NULL);
}

void Heavy_CircleStrings::cVar_JZ3XSc9B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_ryboxt3a_sendMessage);
}

void Heavy_CircleStrings::cVar_IBICAOIV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_wQ7iei15, 0, m);
}

void Heavy_CircleStrings::cVar_GXHAgQOI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_HZmY2qzS_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_5m0TKM40_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_sbJIofuJ_sendMessage);
}

void Heavy_CircleStrings::cVar_43dzlu6h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cVar_sk4Y9Ht3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cVar_Mt4QMNTY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cSwitchcase_Cj2fvFoM_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_soBfMhtQ_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_soBfMhtQ_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_x6ol5WrW, 1, m, &cDelay_x6ol5WrW_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_jOoT4chL_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cDelay_x6ol5WrW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_x6ol5WrW, m);
  cVar_onMessage(_c, &Context(_c)->cVar_zF6EHPd4, 0, m, &cVar_zF6EHPd4_sendMessage);
}

void Heavy_CircleStrings::cMsg_soBfMhtQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_x6ol5WrW, 0, m, &cDelay_x6ol5WrW_sendMessage);
}

void Heavy_CircleStrings::cCast_jOoT4chL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_x6ol5WrW, 0, m, &cDelay_x6ol5WrW_sendMessage);
}

void Heavy_CircleStrings::cVar_zF6EHPd4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_aRmFaCch_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_hcl8Cg8H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_GXHAgQOI, 0, m, &cVar_GXHAgQOI_sendMessage);
}

void Heavy_CircleStrings::cMsg_stGk5hxY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 25.0f);
  cSend_tMi1V7OB_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_aYSnjeNL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 4000.0f);
  cSend_sDztq2Wz_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_xpcHeQUP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSend_HUukXCpM_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_HT15MpsU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_bgcZimyq_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_KnYa58e5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cSend_sKxjXcV9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_EujQ5qdA_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_tMi1V7OB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cSend_sDztq2Wz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_bgcZimyq_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_HUukXCpM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_EujQ5qdA_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_SfrNPTRM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 25.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_T2nrutbX, 0, m, NULL);
}

void Heavy_CircleStrings::cMsg_aRmFaCch_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 0);
  sLine_onMessage(_c, &Context(_c)->sLine_T2nrutbX, 0, m, NULL);
}

void Heavy_CircleStrings::cCast_5m0TKM40_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_zF6EHPd4, 1, m, &cVar_zF6EHPd4_sendMessage);
}

void Heavy_CircleStrings::cCast_sbJIofuJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_Cj2fvFoM_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cCast_HZmY2qzS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_SfrNPTRM_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_uPe1KPdG_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_MdOC04bo, 0, m, &cSlice_MdOC04bo_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_s3dCaREo, 0, m, &cRandom_s3dCaREo_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_qztU2QA7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_zo6XyHbt_sendMessage);
}

void Heavy_CircleStrings::cUnop_zo6XyHbt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_KjHwNVRc_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cRandom_s3dCaREo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8388610.0f, 0, m, &cBinop_qztU2QA7_sendMessage);
}

void Heavy_CircleStrings::cSlice_MdOC04bo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_s3dCaREo, 1, m, &cRandom_s3dCaREo_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cMsg_KjHwNVRc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 1.0f);
  sVari_onMessage(_c, &Context(_c)->sVari_iBYv4MCZ, m);
}

void Heavy_CircleStrings::cTabhead_lTp1bLjF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_7XnvE9pm, HV_BINOP_SUBTRACT, 0, m, &cBinop_7XnvE9pm_sendMessage);
}

void Heavy_CircleStrings::cMsg_y0zgSvPC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_7NsgZe9u_sendMessage);
}

void Heavy_CircleStrings::cSystem_7NsgZe9u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_YnSobg9D_sendMessage);
}

void Heavy_CircleStrings::cVar_TZPELRDt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_zt4RCJMb_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_Ork5rMcG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Ork5rMcG, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_9f4R3sez, 0, m, &cDelay_9f4R3sez_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_uz45IUr4, 0, m, &sTabread_uz45IUr4_sendMessage);
}

void Heavy_CircleStrings::cDelay_9f4R3sez_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_9f4R3sez, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_uz45IUr4, 0, m, &sTabread_uz45IUr4_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_9f4R3sez, 0, m, &cDelay_9f4R3sez_sendMessage);
}

void Heavy_CircleStrings::sTabread_uz45IUr4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_mimXuNBU, HV_BINOP_SUBTRACT, 0, m, &cBinop_mimXuNBU_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_YRZ1SPcf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_LniiIGVg, HV_BINOP_MAX, 0, m, &cBinop_LniiIGVg_sendMessage);
}

void Heavy_CircleStrings::cBinop_YnSobg9D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_YRZ1SPcf, HV_BINOP_MULTIPLY, 0, m, &cBinop_YRZ1SPcf_sendMessage);
}

void Heavy_CircleStrings::cBinop_7XnvE9pm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_upJQjHN6_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_uz45IUr4, 0, m, &sTabread_uz45IUr4_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_PKggF2B0_sendMessage);
}

void Heavy_CircleStrings::cSystem_NCgUrx3Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_mimXuNBU, HV_BINOP_SUBTRACT, 1, m, &cBinop_mimXuNBU_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_9f4R3sez, 2, m, &cDelay_9f4R3sez_sendMessage);
}

void Heavy_CircleStrings::cMsg_zt4RCJMb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_NCgUrx3Z_sendMessage);
}

void Heavy_CircleStrings::cMsg_upJQjHN6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_Ork5rMcG, 0, m, &cDelay_Ork5rMcG_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_9f4R3sez, 0, m, &cDelay_9f4R3sez_sendMessage);
}

void Heavy_CircleStrings::cMsg_35HkjHaM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_LniiIGVg, HV_BINOP_MAX, 1, m, &cBinop_LniiIGVg_sendMessage);
}

void Heavy_CircleStrings::cBinop_LniiIGVg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_7XnvE9pm, HV_BINOP_SUBTRACT, 1, m, &cBinop_7XnvE9pm_sendMessage);
}

void Heavy_CircleStrings::cCast_PKggF2B0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Ork5rMcG, 0, m, &cDelay_Ork5rMcG_sendMessage);
}

void Heavy_CircleStrings::cBinop_ALxmmyd7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Ork5rMcG, 2, m, &cDelay_Ork5rMcG_sendMessage);
}

void Heavy_CircleStrings::cBinop_mimXuNBU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_ALxmmyd7_sendMessage);
}

void Heavy_CircleStrings::cCast_sTQsvUuo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_TZPELRDt, 0, m, &cVar_TZPELRDt_sendMessage);
  cMsg_y0zgSvPC_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_lTp1bLjF, 0, m, &cTabhead_lTp1bLjF_sendMessage);
}

void Heavy_CircleStrings::cBinop_6uz9PaSg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_4I4Wslgd_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_RbjgmHx7_sendMessage);
}

void Heavy_CircleStrings::cBinop_K7osmVM3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_pIbkI484_sendMessage);
}

void Heavy_CircleStrings::cBinop_pIbkI484_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_hzkePoF6, HV_BINOP_POW, 1, m, &cBinop_hzkePoF6_sendMessage);
  cMsg_SWCOb1pa_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_hzkePoF6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_6uz9PaSg_sendMessage);
}

void Heavy_CircleStrings::cMsg_SWCOb1pa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_hzkePoF6, HV_BINOP_POW, 0, m, &cBinop_hzkePoF6_sendMessage);
}

void Heavy_CircleStrings::cVar_EWsoX6Gd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_K7osmVM3_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_LTaarTzJ_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_nPHDCCEd_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_EayLeEMO_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_KXULnJY5_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_KXULnJY5_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_ZhWybiFR, 1, m, &cDelay_ZhWybiFR_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_T2AAJzZR_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cDelay_ZhWybiFR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_ZhWybiFR, m);
  cMsg_zyUwl21C_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_KXULnJY5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_ZhWybiFR, 0, m, &cDelay_ZhWybiFR_sendMessage);
}

void Heavy_CircleStrings::cCast_T2AAJzZR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_ZhWybiFR, 0, m, &cDelay_ZhWybiFR_sendMessage);
}

void Heavy_CircleStrings::cVar_mbStdtfa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_hTFROYhq, HV_BINOP_MULTIPLY, 0, m, &cBinop_hTFROYhq_sendMessage);
}

void Heavy_CircleStrings::cMsg_FyjUiHwx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_BBi8N59U_sendMessage);
}

void Heavy_CircleStrings::cSystem_BBi8N59U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_W33aW9SE_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_hTFROYhq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_CQRyAx4N_sendMessage);
}

void Heavy_CircleStrings::cBinop_tQjHY5Zt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_hTFROYhq, HV_BINOP_MULTIPLY, 1, m, &cBinop_hTFROYhq_sendMessage);
}

void Heavy_CircleStrings::cMsg_W33aW9SE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_tQjHY5Zt_sendMessage);
}

void Heavy_CircleStrings::cBinop_CQRyAx4N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_FBhfXl8Q_sendMessage);
}

void Heavy_CircleStrings::cBinop_FBhfXl8Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_naOOeWhm_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_y4UkHvqz, m);
}

void Heavy_CircleStrings::cBinop_naOOeWhm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_ktRlGh6b, m);
}

void Heavy_CircleStrings::cMsg_coQBEVFC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_PI1UlpsM_sendMessage);
}

void Heavy_CircleStrings::cSystem_PI1UlpsM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_oQ5ESKJI_sendMessage);
}

void Heavy_CircleStrings::cDelay_o50wx0uD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_o50wx0uD, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_T6npqPi4, 0, m, &cDelay_T6npqPi4_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_o50wx0uD, 0, m, &cDelay_o50wx0uD_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_nJP4myYz, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_T6npqPi4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_T6npqPi4, m);
  cMsg_B3udgfXP_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_9c5Nx2Nc_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_mDH0Xuj5_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_TUrmtOGi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_GlRp9CxS_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_pAWAx67h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_nagrznUy_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_o50wx0uD, 2, m, &cDelay_o50wx0uD_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_rWE2Gtfi_sendMessage);
}

void Heavy_CircleStrings::cMsg_GlRp9CxS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_pAWAx67h, 0, m, &hTable_pAWAx67h_sendMessage);
}

void Heavy_CircleStrings::cBinop_oQ5ESKJI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 200.0f, 0, m, &cBinop_TUrmtOGi_sendMessage);
}

void Heavy_CircleStrings::cMsg_B3udgfXP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_pAWAx67h, 0, m, &hTable_pAWAx67h_sendMessage);
}

void Heavy_CircleStrings::cCast_rWE2Gtfi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_o50wx0uD, 0, m, &cDelay_o50wx0uD_sendMessage);
}

void Heavy_CircleStrings::cMsg_nagrznUy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_T6npqPi4, 2, m, &cDelay_T6npqPi4_sendMessage);
}

void Heavy_CircleStrings::cMsg_mDH0Xuj5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_nJP4myYz, 1, m, NULL);
}

void Heavy_CircleStrings::cMsg_Bj0TxGIu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 1.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_H0Shf6Kn, 0, m, NULL);
}

void Heavy_CircleStrings::cMsg_zyUwl21C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 1.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_H0Shf6Kn, 0, m, NULL);
}

void Heavy_CircleStrings::cCast_LTaarTzJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_EayLeEMO_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cCast_nPHDCCEd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Bj0TxGIu_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_nq60htiL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 60.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_K7osmVM3_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_LTaarTzJ_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_nPHDCCEd_sendMessage);
}

void Heavy_CircleStrings::cBinop_GN1qCahY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_YRZ1SPcf, HV_BINOP_MULTIPLY, 1, m, &cBinop_YRZ1SPcf_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_sTQsvUuo_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ZhWybiFR, 1, m, &cDelay_ZhWybiFR_sendMessage);
}

void Heavy_CircleStrings::cMsg_8JYs1V3S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1000.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_GN1qCahY, HV_BINOP_DIVIDE, 0, m, &cBinop_GN1qCahY_sendMessage);
}

void Heavy_CircleStrings::cCast_4I4Wslgd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_GN1qCahY, HV_BINOP_DIVIDE, 1, m, &cBinop_GN1qCahY_sendMessage);
}

void Heavy_CircleStrings::cCast_RbjgmHx7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_8JYs1V3S_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cUnop_yKr84Er3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_N4ekobgR, 0, m, &cPack_N4ekobgR_sendMessage);
}

void Heavy_CircleStrings::cUnop_f16oS7pi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_Rc6e8PUp, 0, m, &cPack_Rc6e8PUp_sendMessage);
}

void Heavy_CircleStrings::cPack_Rc6e8PUp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_JzK53Cnd, 0, m, NULL);
}

void Heavy_CircleStrings::cPack_N4ekobgR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_OaYhTckm, 0, m, NULL);
}

void Heavy_CircleStrings::cBinop_DyGocOOI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_yKr84Er3_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_SIN, m, &cUnop_f16oS7pi_sendMessage);
}

void Heavy_CircleStrings::cMsg_BeXihz1x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.5f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_DyGocOOI_sendMessage);
}

void Heavy_CircleStrings::cSlice_YZIyJR1o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 127.0f, 0, m, &cBinop_Syes6dUL_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cSlice_fb0yezsH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_7h0TZSJt_sendMessage);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_HzwNVoUR_sendMessage);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_K7osmVM3_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_LTaarTzJ_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_nPHDCCEd_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_n8sq5uqS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.4f, 0, m, &cBinop_IAeSxdpe_sendMessage);
}

void Heavy_CircleStrings::cBinop_IAeSxdpe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_DyGocOOI_sendMessage);
}

void Heavy_CircleStrings::cBinop_Syes6dUL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_YVaC8Tau_sendMessage(_c, 0, m);
  cSend_7Hb78VwP_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_LyrRfBnr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_xY4ZeseC_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_22yhYkvJ_sendMessage);
}

void Heavy_CircleStrings::cBinop_cGvUvWTS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.99f, 0, m, &cBinop_8mXrdQu3_sendMessage);
}

void Heavy_CircleStrings::cBinop_8mXrdQu3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_LyrRfBnr, HV_BINOP_MULTIPLY, 1, m, &cBinop_LyrRfBnr_sendMessage);
}

void Heavy_CircleStrings::cSend_YVaC8Tau_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_M7G3MMuu_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_xY4ZeseC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_AXBlKb7q_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cCast_22yhYkvJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_hcl8Cg8H_sendMessage);
}

void Heavy_CircleStrings::cBinop_ryboxt3a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_hCzuDCpN, 0, m, &cPack_hCzuDCpN_sendMessage);
}

void Heavy_CircleStrings::cSend_7Hb78VwP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_vzmWrOtl_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_hag7H7oX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_woqS8Xio_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_6DdbXwc1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 200.0f);
  cSend_hag7H7oX_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_wih9Yc9a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.999f);
  sVarf_onMessage(_c, &Context(_c)->sVarf_WulfmN9E, m);
}

void Heavy_CircleStrings::cCast_7h0TZSJt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_El1zaMwR_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cSwitchcase_d3CpLVhh_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_zhr3JG2l, 0, m, &cSlice_zhr3JG2l_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_Y7tqDUMW, 0, m, &cRandom_Y7tqDUMW_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_wYxtLg7W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_7ZDEa4ek_sendMessage);
}

void Heavy_CircleStrings::cUnop_7ZDEa4ek_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_D3Rhp4ru_sendMessage);
}

void Heavy_CircleStrings::cRandom_Y7tqDUMW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_wYxtLg7W_sendMessage);
}

void Heavy_CircleStrings::cSlice_zhr3JG2l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_Y7tqDUMW, 1, m, &cRandom_Y7tqDUMW_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_oSBDI7pe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_n3XreU96, HV_BINOP_MULTIPLY, 0, m, &cBinop_n3XreU96_sendMessage);
}

void Heavy_CircleStrings::cBinop_mCAYru1X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_Fn8yH8ru_sendMessage);
}

void Heavy_CircleStrings::cBinop_Fn8yH8ru_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_SAsI28XZ, HV_BINOP_POW, 1, m, &cBinop_SAsI28XZ_sendMessage);
  cMsg_Yh38ngSw_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_SAsI28XZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_oSBDI7pe_sendMessage);
}

void Heavy_CircleStrings::cMsg_Yh38ngSw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_SAsI28XZ, HV_BINOP_POW, 0, m, &cBinop_SAsI28XZ_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_DPv7tCOl_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_xIKsFmL1, 0, m, &cSlice_xIKsFmL1_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_KXfHXQD9, 0, m, &cRandom_KXfHXQD9_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_g0Wn7kP2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_RMllVSMr_sendMessage);
}

void Heavy_CircleStrings::cUnop_RMllVSMr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_aQiDjmXA_sendMessage);
}

void Heavy_CircleStrings::cRandom_KXfHXQD9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 15.0f, 0, m, &cBinop_g0Wn7kP2_sendMessage);
}

void Heavy_CircleStrings::cSlice_xIKsFmL1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_KXfHXQD9, 1, m, &cRandom_KXfHXQD9_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cPack_upolaOH3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_Tqa1nXEJ, 0, m, NULL);
}

void Heavy_CircleStrings::cVar_dKrLjoSm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_vd2LSB80_sendMessage);
}

void Heavy_CircleStrings::cVar_b1go0ylg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_5yq7vD4E, 0, m);
}

void Heavy_CircleStrings::cVar_WrBsBufF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_6f19cpiV_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_FQySNDac_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ud24tQxl_sendMessage);
}

void Heavy_CircleStrings::cVar_EqKxQ7Ju_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cVar_ICD2vIGz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cVar_OEWMLfBh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cSwitchcase_oSl3Y1vu_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_Y73Huj0m_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_Y73Huj0m_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_ua925bI6, 1, m, &cDelay_ua925bI6_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_1VMwlBLr_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cDelay_ua925bI6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_ua925bI6, m);
  cVar_onMessage(_c, &Context(_c)->cVar_15RSA0yi, 0, m, &cVar_15RSA0yi_sendMessage);
}

void Heavy_CircleStrings::cMsg_Y73Huj0m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_ua925bI6, 0, m, &cDelay_ua925bI6_sendMessage);
}

void Heavy_CircleStrings::cCast_1VMwlBLr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_ua925bI6, 0, m, &cDelay_ua925bI6_sendMessage);
}

void Heavy_CircleStrings::cVar_15RSA0yi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Iw0z8l6J_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_ITLcZkHD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_WrBsBufF, 0, m, &cVar_WrBsBufF_sendMessage);
}

void Heavy_CircleStrings::cMsg_hL8WJneA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 25.0f);
  cSend_UpGWm8oR_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_V68XsOfh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 4000.0f);
  cSend_nfh66iTB_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_9YJCYGn1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSend_mTplPFMb_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_yeEH4ste_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_rfywEDQd_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_PZHauXFq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cSend_HRxqRcEN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_LFS2MKvw_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_UpGWm8oR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cSend_nfh66iTB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_rfywEDQd_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_mTplPFMb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_LFS2MKvw_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_inXfiXx1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 25.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_8pq58Ush, 0, m, NULL);
}

void Heavy_CircleStrings::cMsg_Iw0z8l6J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 0);
  sLine_onMessage(_c, &Context(_c)->sLine_8pq58Ush, 0, m, NULL);
}

void Heavy_CircleStrings::cCast_FQySNDac_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_15RSA0yi, 1, m, &cVar_15RSA0yi_sendMessage);
}

void Heavy_CircleStrings::cCast_6f19cpiV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_inXfiXx1_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_ud24tQxl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_oSl3Y1vu_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cSwitchcase_3VNL2HZo_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_C7l4LOOL, 0, m, &cSlice_C7l4LOOL_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_s2exTMOw, 0, m, &cRandom_s2exTMOw_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_Gnvm3O8W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_qjaBLGiC_sendMessage);
}

void Heavy_CircleStrings::cUnop_qjaBLGiC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_FuYLEAMX_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cRandom_s2exTMOw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8388610.0f, 0, m, &cBinop_Gnvm3O8W_sendMessage);
}

void Heavy_CircleStrings::cSlice_C7l4LOOL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_s2exTMOw, 1, m, &cRandom_s2exTMOw_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cMsg_FuYLEAMX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 1.0f);
  sVari_onMessage(_c, &Context(_c)->sVari_jZfuUXMV, m);
}

void Heavy_CircleStrings::cTabhead_jzrfxRrt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_yLdaFLO4, HV_BINOP_SUBTRACT, 0, m, &cBinop_yLdaFLO4_sendMessage);
}

void Heavy_CircleStrings::cMsg_iKBadwfV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_iAXMGlrD_sendMessage);
}

void Heavy_CircleStrings::cSystem_iAXMGlrD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_Tmcubqb8_sendMessage);
}

void Heavy_CircleStrings::cVar_PhBzj2gg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_iDjowxAG_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_z3N94oiZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_z3N94oiZ, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_gsBwub5T, 0, m, &cDelay_gsBwub5T_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_5NVipHqQ, 0, m, &sTabread_5NVipHqQ_sendMessage);
}

void Heavy_CircleStrings::cDelay_gsBwub5T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_gsBwub5T, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_5NVipHqQ, 0, m, &sTabread_5NVipHqQ_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_gsBwub5T, 0, m, &cDelay_gsBwub5T_sendMessage);
}

void Heavy_CircleStrings::sTabread_5NVipHqQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_Q996IrGi, HV_BINOP_SUBTRACT, 0, m, &cBinop_Q996IrGi_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_JtRGawT0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_cSlocEHL, HV_BINOP_MAX, 0, m, &cBinop_cSlocEHL_sendMessage);
}

void Heavy_CircleStrings::cBinop_Tmcubqb8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_JtRGawT0, HV_BINOP_MULTIPLY, 0, m, &cBinop_JtRGawT0_sendMessage);
}

void Heavy_CircleStrings::cBinop_yLdaFLO4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_oXV7QWN1_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_5NVipHqQ, 0, m, &sTabread_5NVipHqQ_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_jbp9znUb_sendMessage);
}

void Heavy_CircleStrings::cSystem_M0EAePz8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Q996IrGi, HV_BINOP_SUBTRACT, 1, m, &cBinop_Q996IrGi_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_gsBwub5T, 2, m, &cDelay_gsBwub5T_sendMessage);
}

void Heavy_CircleStrings::cMsg_iDjowxAG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_M0EAePz8_sendMessage);
}

void Heavy_CircleStrings::cMsg_oXV7QWN1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_z3N94oiZ, 0, m, &cDelay_z3N94oiZ_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_gsBwub5T, 0, m, &cDelay_gsBwub5T_sendMessage);
}

void Heavy_CircleStrings::cMsg_yo4tZKJr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_cSlocEHL, HV_BINOP_MAX, 1, m, &cBinop_cSlocEHL_sendMessage);
}

void Heavy_CircleStrings::cBinop_cSlocEHL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_yLdaFLO4, HV_BINOP_SUBTRACT, 1, m, &cBinop_yLdaFLO4_sendMessage);
}

void Heavy_CircleStrings::cCast_jbp9znUb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_z3N94oiZ, 0, m, &cDelay_z3N94oiZ_sendMessage);
}

void Heavy_CircleStrings::cBinop_UtGhFOl5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_z3N94oiZ, 2, m, &cDelay_z3N94oiZ_sendMessage);
}

void Heavy_CircleStrings::cBinop_Q996IrGi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_UtGhFOl5_sendMessage);
}

void Heavy_CircleStrings::cCast_1iIwGvgD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_PhBzj2gg, 0, m, &cVar_PhBzj2gg_sendMessage);
  cMsg_iKBadwfV_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_jzrfxRrt, 0, m, &cTabhead_jzrfxRrt_sendMessage);
}

void Heavy_CircleStrings::cBinop_u7zpYie7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ODAuIlwq_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_loskSTzp_sendMessage);
}

void Heavy_CircleStrings::cBinop_dMqRFOiY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_lydYFwOi_sendMessage);
}

void Heavy_CircleStrings::cBinop_lydYFwOi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_VlOx6y79, HV_BINOP_POW, 1, m, &cBinop_VlOx6y79_sendMessage);
  cMsg_c04ipK8y_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_VlOx6y79_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_u7zpYie7_sendMessage);
}

void Heavy_CircleStrings::cMsg_c04ipK8y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_VlOx6y79, HV_BINOP_POW, 0, m, &cBinop_VlOx6y79_sendMessage);
}

void Heavy_CircleStrings::cVar_8rEbM5ui_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_dMqRFOiY_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_6gnW1Fgt_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_kDnW34jo_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_af3My4vm_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_KjDHEuW8_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_KjDHEuW8_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_axfoSm30, 1, m, &cDelay_axfoSm30_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Za981W12_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cDelay_axfoSm30_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_axfoSm30, m);
  cMsg_7nQpn3OQ_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_KjDHEuW8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_axfoSm30, 0, m, &cDelay_axfoSm30_sendMessage);
}

void Heavy_CircleStrings::cCast_Za981W12_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_axfoSm30, 0, m, &cDelay_axfoSm30_sendMessage);
}

void Heavy_CircleStrings::cVar_ucInTxs1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_JxYcj07j, HV_BINOP_MULTIPLY, 0, m, &cBinop_JxYcj07j_sendMessage);
}

void Heavy_CircleStrings::cMsg_6iVQo6PC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ZPNegW5N_sendMessage);
}

void Heavy_CircleStrings::cSystem_ZPNegW5N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_pLLu7nsq_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_JxYcj07j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_zSy1lGS3_sendMessage);
}

void Heavy_CircleStrings::cBinop_25JLyglZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_JxYcj07j, HV_BINOP_MULTIPLY, 1, m, &cBinop_JxYcj07j_sendMessage);
}

void Heavy_CircleStrings::cMsg_pLLu7nsq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_25JLyglZ_sendMessage);
}

void Heavy_CircleStrings::cBinop_zSy1lGS3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_7Ys9Epz8_sendMessage);
}

void Heavy_CircleStrings::cBinop_7Ys9Epz8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_pWRUc9FD_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_IeUPh9s6, m);
}

void Heavy_CircleStrings::cBinop_pWRUc9FD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_Mq7nUbi8, m);
}

void Heavy_CircleStrings::cMsg_3dvJTL3C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Bdwus7EW_sendMessage);
}

void Heavy_CircleStrings::cSystem_Bdwus7EW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_st38Pf5C_sendMessage);
}

void Heavy_CircleStrings::cDelay_iz20TZzC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_iz20TZzC, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_L0Hk6U7p, 0, m, &cDelay_L0Hk6U7p_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_iz20TZzC, 0, m, &cDelay_iz20TZzC_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_sWDwFtRq, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_L0Hk6U7p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_L0Hk6U7p, m);
  cMsg_NQg2ZGbk_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_I9IaKj0p_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_ZKk9H6ft_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_Ya19mh9A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_hxB5NLL1_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_GeWiHfXt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_76Mzh2iA_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_iz20TZzC, 2, m, &cDelay_iz20TZzC_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_tiXjzCYC_sendMessage);
}

void Heavy_CircleStrings::cMsg_hxB5NLL1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_GeWiHfXt, 0, m, &hTable_GeWiHfXt_sendMessage);
}

void Heavy_CircleStrings::cBinop_st38Pf5C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 200.0f, 0, m, &cBinop_Ya19mh9A_sendMessage);
}

void Heavy_CircleStrings::cMsg_NQg2ZGbk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_GeWiHfXt, 0, m, &hTable_GeWiHfXt_sendMessage);
}

void Heavy_CircleStrings::cCast_tiXjzCYC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_iz20TZzC, 0, m, &cDelay_iz20TZzC_sendMessage);
}

void Heavy_CircleStrings::cMsg_76Mzh2iA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_L0Hk6U7p, 2, m, &cDelay_L0Hk6U7p_sendMessage);
}

void Heavy_CircleStrings::cMsg_ZKk9H6ft_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_sWDwFtRq, 1, m, NULL);
}

void Heavy_CircleStrings::cMsg_mqU6Q97F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 1.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_s5nMQdih, 0, m, NULL);
}

void Heavy_CircleStrings::cMsg_7nQpn3OQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 1.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_s5nMQdih, 0, m, NULL);
}

void Heavy_CircleStrings::cCast_6gnW1Fgt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_af3My4vm_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cCast_kDnW34jo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_mqU6Q97F_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_jJ9oPNTU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 60.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_dMqRFOiY_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_6gnW1Fgt_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_kDnW34jo_sendMessage);
}

void Heavy_CircleStrings::cBinop_ck1tlMUG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_JtRGawT0, HV_BINOP_MULTIPLY, 1, m, &cBinop_JtRGawT0_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_1iIwGvgD_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_axfoSm30, 1, m, &cDelay_axfoSm30_sendMessage);
}

void Heavy_CircleStrings::cMsg_arRZY1TR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1000.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_ck1tlMUG, HV_BINOP_DIVIDE, 0, m, &cBinop_ck1tlMUG_sendMessage);
}

void Heavy_CircleStrings::cCast_ODAuIlwq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ck1tlMUG, HV_BINOP_DIVIDE, 1, m, &cBinop_ck1tlMUG_sendMessage);
}

void Heavy_CircleStrings::cCast_loskSTzp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_arRZY1TR_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cUnop_oWDWv8M6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_RKe3Cx3d, 0, m, &cPack_RKe3Cx3d_sendMessage);
}

void Heavy_CircleStrings::cUnop_d8K8NdeR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_UmEJwr0x, 0, m, &cPack_UmEJwr0x_sendMessage);
}

void Heavy_CircleStrings::cPack_UmEJwr0x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_U1ABC4bt, 0, m, NULL);
}

void Heavy_CircleStrings::cPack_RKe3Cx3d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_bgzodf4K, 0, m, NULL);
}

void Heavy_CircleStrings::cBinop_fFsFkMdA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_oWDWv8M6_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_SIN, m, &cUnop_d8K8NdeR_sendMessage);
}

void Heavy_CircleStrings::cMsg_7zA2bHc9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.5f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_fFsFkMdA_sendMessage);
}

void Heavy_CircleStrings::cSlice_nZ7Ji8aR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 127.0f, 0, m, &cBinop_GIUhNWPQ_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cSlice_2ifoyNME_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_waePj9m7_sendMessage);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_mCAYru1X_sendMessage);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_dMqRFOiY_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_6gnW1Fgt_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_kDnW34jo_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_D3Rhp4ru_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.4f, 0, m, &cBinop_McvBsrT1_sendMessage);
}

void Heavy_CircleStrings::cBinop_McvBsrT1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_fFsFkMdA_sendMessage);
}

void Heavy_CircleStrings::cBinop_GIUhNWPQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_UALRk6Td_sendMessage(_c, 0, m);
  cSend_JtrPVx2f_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_n3XreU96_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ZjEL1tfW_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_vjMvcDLw_sendMessage);
}

void Heavy_CircleStrings::cBinop_aQiDjmXA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.99f, 0, m, &cBinop_3zm7KnMD_sendMessage);
}

void Heavy_CircleStrings::cBinop_3zm7KnMD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_n3XreU96, HV_BINOP_MULTIPLY, 1, m, &cBinop_n3XreU96_sendMessage);
}

void Heavy_CircleStrings::cSend_UALRk6Td_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_HWtXeN6Y_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_vjMvcDLw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ITLcZkHD_sendMessage);
}

void Heavy_CircleStrings::cCast_ZjEL1tfW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_d3CpLVhh_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cBinop_vd2LSB80_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_upolaOH3, 0, m, &cPack_upolaOH3_sendMessage);
}

void Heavy_CircleStrings::cSend_JtrPVx2f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_UsbLKWib_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_9I40HOsY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_SY3wwCjD_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_5sw2K879_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 200.0f);
  cSend_9I40HOsY_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_BxC6CmaH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.999f);
  sVarf_onMessage(_c, &Context(_c)->sVarf_AlwSpVoN, m);
}

void Heavy_CircleStrings::cCast_waePj9m7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_DPv7tCOl_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cSwitchcase_kJOgfaXX_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_LrkUjDhG, 0, m, &cSlice_LrkUjDhG_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_hBBSWHl6, 0, m, &cRandom_hBBSWHl6_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_x3roBrz4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_WUF2Tm24_sendMessage);
}

void Heavy_CircleStrings::cUnop_WUF2Tm24_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_XUPv8UCB_sendMessage);
}

void Heavy_CircleStrings::cRandom_hBBSWHl6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_x3roBrz4_sendMessage);
}

void Heavy_CircleStrings::cSlice_LrkUjDhG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_hBBSWHl6, 1, m, &cRandom_hBBSWHl6_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_gdqwBUXV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_dm9hnv5t, HV_BINOP_MULTIPLY, 0, m, &cBinop_dm9hnv5t_sendMessage);
}

void Heavy_CircleStrings::cBinop_LoadLbyZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_YX1MWJSG_sendMessage);
}

void Heavy_CircleStrings::cBinop_YX1MWJSG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_eplcbp2f, HV_BINOP_POW, 1, m, &cBinop_eplcbp2f_sendMessage);
  cMsg_bmMvtgfr_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_eplcbp2f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_gdqwBUXV_sendMessage);
}

void Heavy_CircleStrings::cMsg_bmMvtgfr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_eplcbp2f, HV_BINOP_POW, 0, m, &cBinop_eplcbp2f_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_Bw3gtibg_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_1tUganas, 0, m, &cSlice_1tUganas_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_KgBVTbI0, 0, m, &cRandom_KgBVTbI0_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_D5DmNlx0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_lNqU38Ox_sendMessage);
}

void Heavy_CircleStrings::cUnop_lNqU38Ox_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_Fd0w3wrU_sendMessage);
}

void Heavy_CircleStrings::cRandom_KgBVTbI0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 15.0f, 0, m, &cBinop_D5DmNlx0_sendMessage);
}

void Heavy_CircleStrings::cSlice_1tUganas_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_KgBVTbI0, 1, m, &cRandom_KgBVTbI0_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cPack_wat93oqB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_nENENln6, 0, m, NULL);
}

void Heavy_CircleStrings::cVar_VLGCtr4H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_Y2menSMt_sendMessage);
}

void Heavy_CircleStrings::cVar_va0Z8BCC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_ylmnYws2, 0, m);
}

void Heavy_CircleStrings::cVar_MWZdEgFV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_VWGOFulL_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_tf1ESMBd_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_zp88z9lN_sendMessage);
}

void Heavy_CircleStrings::cVar_6z0EVIRH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cVar_OA2EGsAz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cVar_DpQIec65_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cSwitchcase_zUHLCQQy_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_FfNaZLzo_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_FfNaZLzo_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_KFIisT1k, 1, m, &cDelay_KFIisT1k_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_YcA3uNCn_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cDelay_KFIisT1k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_KFIisT1k, m);
  cVar_onMessage(_c, &Context(_c)->cVar_NedJERv8, 0, m, &cVar_NedJERv8_sendMessage);
}

void Heavy_CircleStrings::cMsg_FfNaZLzo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_KFIisT1k, 0, m, &cDelay_KFIisT1k_sendMessage);
}

void Heavy_CircleStrings::cCast_YcA3uNCn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_KFIisT1k, 0, m, &cDelay_KFIisT1k_sendMessage);
}

void Heavy_CircleStrings::cVar_NedJERv8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_cHSeEWP2_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_0FRMDekx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_MWZdEgFV, 0, m, &cVar_MWZdEgFV_sendMessage);
}

void Heavy_CircleStrings::cMsg_OfCAIAPD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 25.0f);
  cSend_vvSAcawm_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_9vBoPPmf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 4000.0f);
  cSend_2hXqmWiz_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_kszFmSfz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSend_VHY26EiV_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_oqcmhEtl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_rgeeVsCt_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_29k4x5MN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cSend_MUThTmON_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_DIxKq28q_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_vvSAcawm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cSend_2hXqmWiz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_rgeeVsCt_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_VHY26EiV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_DIxKq28q_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_RzShOmH2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 25.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_VOaxQqv5, 0, m, NULL);
}

void Heavy_CircleStrings::cMsg_cHSeEWP2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 0);
  sLine_onMessage(_c, &Context(_c)->sLine_VOaxQqv5, 0, m, NULL);
}

void Heavy_CircleStrings::cCast_zp88z9lN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_zUHLCQQy_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cCast_VWGOFulL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_RzShOmH2_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_tf1ESMBd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_NedJERv8, 1, m, &cVar_NedJERv8_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_HE6LzzQ6_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_W9v0j2IA, 0, m, &cSlice_W9v0j2IA_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_eeDEEmJI, 0, m, &cRandom_eeDEEmJI_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_DePMJfII_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_lZUDHKvA_sendMessage);
}

void Heavy_CircleStrings::cUnop_lZUDHKvA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_49Ry9ixz_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cRandom_eeDEEmJI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8388610.0f, 0, m, &cBinop_DePMJfII_sendMessage);
}

void Heavy_CircleStrings::cSlice_W9v0j2IA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_eeDEEmJI, 1, m, &cRandom_eeDEEmJI_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cMsg_49Ry9ixz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 1.0f);
  sVari_onMessage(_c, &Context(_c)->sVari_EOOMzvK0, m);
}

void Heavy_CircleStrings::cTabhead_uF0bu8WL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_j0uxr84E, HV_BINOP_SUBTRACT, 0, m, &cBinop_j0uxr84E_sendMessage);
}

void Heavy_CircleStrings::cMsg_b06c4npQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_4HBhe5E9_sendMessage);
}

void Heavy_CircleStrings::cSystem_4HBhe5E9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_dA6FGVHR_sendMessage);
}

void Heavy_CircleStrings::cVar_K2cULozm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_2q5gmIaE_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_NyesR6w0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_NyesR6w0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_yc7dikPw, 0, m, &cDelay_yc7dikPw_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_CLSQbzjP, 0, m, &sTabread_CLSQbzjP_sendMessage);
}

void Heavy_CircleStrings::cDelay_yc7dikPw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_yc7dikPw, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_CLSQbzjP, 0, m, &sTabread_CLSQbzjP_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_yc7dikPw, 0, m, &cDelay_yc7dikPw_sendMessage);
}

void Heavy_CircleStrings::sTabread_CLSQbzjP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_qioYzcjb, HV_BINOP_SUBTRACT, 0, m, &cBinop_qioYzcjb_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_mqbl9kzx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_jHXYdqEM, HV_BINOP_MAX, 0, m, &cBinop_jHXYdqEM_sendMessage);
}

void Heavy_CircleStrings::cBinop_dA6FGVHR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_mqbl9kzx, HV_BINOP_MULTIPLY, 0, m, &cBinop_mqbl9kzx_sendMessage);
}

void Heavy_CircleStrings::cBinop_j0uxr84E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_vcTEjG2e_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_CLSQbzjP, 0, m, &sTabread_CLSQbzjP_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_HiWNMxtG_sendMessage);
}

void Heavy_CircleStrings::cSystem_B9pda3Gb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_qioYzcjb, HV_BINOP_SUBTRACT, 1, m, &cBinop_qioYzcjb_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_yc7dikPw, 2, m, &cDelay_yc7dikPw_sendMessage);
}

void Heavy_CircleStrings::cMsg_2q5gmIaE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_B9pda3Gb_sendMessage);
}

void Heavy_CircleStrings::cMsg_vcTEjG2e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_NyesR6w0, 0, m, &cDelay_NyesR6w0_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_yc7dikPw, 0, m, &cDelay_yc7dikPw_sendMessage);
}

void Heavy_CircleStrings::cMsg_8I8rnGIk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_jHXYdqEM, HV_BINOP_MAX, 1, m, &cBinop_jHXYdqEM_sendMessage);
}

void Heavy_CircleStrings::cBinop_jHXYdqEM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_j0uxr84E, HV_BINOP_SUBTRACT, 1, m, &cBinop_j0uxr84E_sendMessage);
}

void Heavy_CircleStrings::cCast_HiWNMxtG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_NyesR6w0, 0, m, &cDelay_NyesR6w0_sendMessage);
}

void Heavy_CircleStrings::cBinop_XEWGx8ep_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_NyesR6w0, 2, m, &cDelay_NyesR6w0_sendMessage);
}

void Heavy_CircleStrings::cBinop_qioYzcjb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_XEWGx8ep_sendMessage);
}

void Heavy_CircleStrings::cCast_bVxPXJSD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_K2cULozm, 0, m, &cVar_K2cULozm_sendMessage);
  cMsg_b06c4npQ_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_uF0bu8WL, 0, m, &cTabhead_uF0bu8WL_sendMessage);
}

void Heavy_CircleStrings::cBinop_GhHsAQ1E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_2XyS2U5f_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_QBFCTr0O_sendMessage);
}

void Heavy_CircleStrings::cBinop_I7zDWTmt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_lCNCNRp4_sendMessage);
}

void Heavy_CircleStrings::cBinop_lCNCNRp4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_x00aQ1oV, HV_BINOP_POW, 1, m, &cBinop_x00aQ1oV_sendMessage);
  cMsg_jGFQ8cGx_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_x00aQ1oV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_GhHsAQ1E_sendMessage);
}

void Heavy_CircleStrings::cMsg_jGFQ8cGx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_x00aQ1oV, HV_BINOP_POW, 0, m, &cBinop_x00aQ1oV_sendMessage);
}

void Heavy_CircleStrings::cVar_wtWv2dCN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_I7zDWTmt_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_6augEX1o_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_G3dCDzzw_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_m4VEqSNV_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_y7Oy5fT4_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_y7Oy5fT4_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_Xcx9bFyI, 1, m, &cDelay_Xcx9bFyI_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_XUzPMCeq_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cDelay_Xcx9bFyI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Xcx9bFyI, m);
  cMsg_cH1EFJ0d_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_y7Oy5fT4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_Xcx9bFyI, 0, m, &cDelay_Xcx9bFyI_sendMessage);
}

void Heavy_CircleStrings::cCast_XUzPMCeq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Xcx9bFyI, 0, m, &cDelay_Xcx9bFyI_sendMessage);
}

void Heavy_CircleStrings::cVar_KgJd8Gmx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_14yRBkP8, HV_BINOP_MULTIPLY, 0, m, &cBinop_14yRBkP8_sendMessage);
}

void Heavy_CircleStrings::cMsg_1P7EX4pU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_hUkocaO3_sendMessage);
}

void Heavy_CircleStrings::cSystem_hUkocaO3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_nNB7Bclk_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_14yRBkP8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_W2emJzxy_sendMessage);
}

void Heavy_CircleStrings::cBinop_T14XhhGO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_14yRBkP8, HV_BINOP_MULTIPLY, 1, m, &cBinop_14yRBkP8_sendMessage);
}

void Heavy_CircleStrings::cMsg_nNB7Bclk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_T14XhhGO_sendMessage);
}

void Heavy_CircleStrings::cBinop_W2emJzxy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_2hwh5UOe_sendMessage);
}

void Heavy_CircleStrings::cBinop_2hwh5UOe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_BfJqqw5y_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_XPajirxG, m);
}

void Heavy_CircleStrings::cBinop_BfJqqw5y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_z2ylGeUi, m);
}

void Heavy_CircleStrings::cMsg_bnS4ybYQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Gg2G4WRy_sendMessage);
}

void Heavy_CircleStrings::cSystem_Gg2G4WRy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_GrIUojUB_sendMessage);
}

void Heavy_CircleStrings::cDelay_83Vpe0xH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_83Vpe0xH, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_vNFw2PHh, 0, m, &cDelay_vNFw2PHh_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_83Vpe0xH, 0, m, &cDelay_83Vpe0xH_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_cZ9dGKFv, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_vNFw2PHh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_vNFw2PHh, m);
  cMsg_JAGzyQ8g_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_TJmO33YQ_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_rfavZ9E2_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_I697vvRI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_J6TXiKlL_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_ecnrv29S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Rl5EMHc9_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_83Vpe0xH, 2, m, &cDelay_83Vpe0xH_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_FWxaQZyB_sendMessage);
}

void Heavy_CircleStrings::cMsg_J6TXiKlL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_ecnrv29S, 0, m, &hTable_ecnrv29S_sendMessage);
}

void Heavy_CircleStrings::cBinop_GrIUojUB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 200.0f, 0, m, &cBinop_I697vvRI_sendMessage);
}

void Heavy_CircleStrings::cMsg_JAGzyQ8g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_ecnrv29S, 0, m, &hTable_ecnrv29S_sendMessage);
}

void Heavy_CircleStrings::cCast_FWxaQZyB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_83Vpe0xH, 0, m, &cDelay_83Vpe0xH_sendMessage);
}

void Heavy_CircleStrings::cMsg_Rl5EMHc9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_vNFw2PHh, 2, m, &cDelay_vNFw2PHh_sendMessage);
}

void Heavy_CircleStrings::cMsg_rfavZ9E2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_cZ9dGKFv, 1, m, NULL);
}

void Heavy_CircleStrings::cMsg_tbv8rx0X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 1.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_7pC7DypZ, 0, m, NULL);
}

void Heavy_CircleStrings::cMsg_cH1EFJ0d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 1.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_7pC7DypZ, 0, m, NULL);
}

void Heavy_CircleStrings::cCast_6augEX1o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_m4VEqSNV_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cCast_G3dCDzzw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_tbv8rx0X_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_TSpw03iz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 60.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_I7zDWTmt_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_6augEX1o_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_G3dCDzzw_sendMessage);
}

void Heavy_CircleStrings::cBinop_wCOZwrdf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_mqbl9kzx, HV_BINOP_MULTIPLY, 1, m, &cBinop_mqbl9kzx_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_bVxPXJSD_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Xcx9bFyI, 1, m, &cDelay_Xcx9bFyI_sendMessage);
}

void Heavy_CircleStrings::cMsg_JawXoOb6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1000.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_wCOZwrdf, HV_BINOP_DIVIDE, 0, m, &cBinop_wCOZwrdf_sendMessage);
}

void Heavy_CircleStrings::cCast_QBFCTr0O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_JawXoOb6_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_2XyS2U5f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_wCOZwrdf, HV_BINOP_DIVIDE, 1, m, &cBinop_wCOZwrdf_sendMessage);
}

void Heavy_CircleStrings::cUnop_nHL2eqxe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_bDbDNV3b, 0, m, &cPack_bDbDNV3b_sendMessage);
}

void Heavy_CircleStrings::cUnop_CnLUT7RD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_6L7LSBnh, 0, m, &cPack_6L7LSBnh_sendMessage);
}

void Heavy_CircleStrings::cPack_6L7LSBnh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_ax8jUcg3, 0, m, NULL);
}

void Heavy_CircleStrings::cPack_bDbDNV3b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_yhuFmEbj, 0, m, NULL);
}

void Heavy_CircleStrings::cBinop_41kFPKpj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_nHL2eqxe_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_SIN, m, &cUnop_CnLUT7RD_sendMessage);
}

void Heavy_CircleStrings::cMsg_NHjl9qq4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.5f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_41kFPKpj_sendMessage);
}

void Heavy_CircleStrings::cSlice_DNFsvgjW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 127.0f, 0, m, &cBinop_gH52vQFv_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cSlice_k2abEYDJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_3onxkZCN_sendMessage);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_LoadLbyZ_sendMessage);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_I7zDWTmt_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_6augEX1o_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_G3dCDzzw_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_XUPv8UCB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.4f, 0, m, &cBinop_J1AHOihL_sendMessage);
}

void Heavy_CircleStrings::cBinop_J1AHOihL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_41kFPKpj_sendMessage);
}

void Heavy_CircleStrings::cBinop_gH52vQFv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_xHyvthC2_sendMessage(_c, 0, m);
  cSend_H9sIoiOy_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_dm9hnv5t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_b4qlvJY6_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ofHIkgiQ_sendMessage);
}

void Heavy_CircleStrings::cBinop_Fd0w3wrU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.99f, 0, m, &cBinop_FbAf7wqJ_sendMessage);
}

void Heavy_CircleStrings::cBinop_FbAf7wqJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_dm9hnv5t, HV_BINOP_MULTIPLY, 1, m, &cBinop_dm9hnv5t_sendMessage);
}

void Heavy_CircleStrings::cSend_xHyvthC2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_RWGEA916_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_ofHIkgiQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_0FRMDekx_sendMessage);
}

void Heavy_CircleStrings::cCast_b4qlvJY6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_kJOgfaXX_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cBinop_Y2menSMt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_wat93oqB, 0, m, &cPack_wat93oqB_sendMessage);
}

void Heavy_CircleStrings::cSend_H9sIoiOy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_fBFJQqQH_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_oXnn1qaF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_B5YHdcYw_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_mFjWHN4f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 200.0f);
  cSend_oXnn1qaF_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_AUk5HxPh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.999f);
  sVarf_onMessage(_c, &Context(_c)->sVarf_hjy7RmaU, m);
}

void Heavy_CircleStrings::cCast_3onxkZCN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_Bw3gtibg_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cVar_j1oUZmqA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_VYqQLo4t_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_8RXdjYOd_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_STDxfehq_sendMessage);
}

void Heavy_CircleStrings::cIf_zyPXI7wu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_v5i9mD3O_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_IOJHbCZO_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cMsg_2IisbxLa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_Lt6TVY3A, HV_BINOP_POW, 0, m, &cBinop_Lt6TVY3A_sendMessage);
}

void Heavy_CircleStrings::cBinop_Lt6TVY3A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_OFeCfyhv, 0, m, &cPack_OFeCfyhv_sendMessage);
}

void Heavy_CircleStrings::cBinop_dFrQldb3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_49fUCOFg_sendMessage);
}

void Heavy_CircleStrings::cCast_STDxfehq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_zyPXI7wu, 0, m, &cIf_zyPXI7wu_sendMessage);
}

void Heavy_CircleStrings::cCast_8RXdjYOd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_WrC2Pft5_sendMessage);
}

void Heavy_CircleStrings::cBinop_WrC2Pft5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_zyPXI7wu, 1, m, &cIf_zyPXI7wu_sendMessage);
}

void Heavy_CircleStrings::cBinop_IOJHbCZO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_dFrQldb3_sendMessage);
}

void Heavy_CircleStrings::cMsg_v5i9mD3O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_OFeCfyhv, 0, m, &cPack_OFeCfyhv_sendMessage);
}

void Heavy_CircleStrings::cBinop_49fUCOFg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Lt6TVY3A, HV_BINOP_POW, 1, m, &cBinop_Lt6TVY3A_sendMessage);
  cMsg_2IisbxLa_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cPack_OFeCfyhv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_KbMDzRgq, 0, m, NULL);
}

void Heavy_CircleStrings::cVar_2FkmBTue_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_1jKkfmnw_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_VYqQLo4t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSend_igJpvASL_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_igJpvASL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_MAUl3a9R_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_1jKkfmnw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_2gwdia0O_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cVar_AOYPt2KL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_lpA123tW_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_qTx04O27_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_YoGBbyL2_sendMessage);
}

void Heavy_CircleStrings::cIf_3VGKCTvb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_LivjrL2x_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_nWjcwSKr_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cMsg_GcNWc8ov_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_KqrfkLKG, HV_BINOP_POW, 0, m, &cBinop_KqrfkLKG_sendMessage);
}

void Heavy_CircleStrings::cBinop_KqrfkLKG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_szVszC0H, 0, m, &cPack_szVszC0H_sendMessage);
}

void Heavy_CircleStrings::cBinop_FBtjpEHG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_WQ7APhtd_sendMessage);
}

void Heavy_CircleStrings::cCast_YoGBbyL2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_3VGKCTvb, 0, m, &cIf_3VGKCTvb_sendMessage);
}

void Heavy_CircleStrings::cCast_qTx04O27_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_T5HQsggd_sendMessage);
}

void Heavy_CircleStrings::cBinop_T5HQsggd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_3VGKCTvb, 1, m, &cIf_3VGKCTvb_sendMessage);
}

void Heavy_CircleStrings::cBinop_nWjcwSKr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_FBtjpEHG_sendMessage);
}

void Heavy_CircleStrings::cMsg_LivjrL2x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_szVszC0H, 0, m, &cPack_szVszC0H_sendMessage);
}

void Heavy_CircleStrings::cBinop_WQ7APhtd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_KqrfkLKG, HV_BINOP_POW, 1, m, &cBinop_KqrfkLKG_sendMessage);
  cMsg_GcNWc8ov_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cPack_szVszC0H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_LkKfPvRR, 0, m, NULL);
}

void Heavy_CircleStrings::cVar_qYKLSbLk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_PaZo5Rhq_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_lpA123tW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSend_AEyq5hpx_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_AEyq5hpx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_wDEOnKsi_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_PaZo5Rhq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_yse5Eb4F_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cVar_UO9Ao0DX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_GhQTF94c_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Wf6c3sxj_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_N64KnOMP_sendMessage);
}

void Heavy_CircleStrings::cIf_Z3OsSUYc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_a6Sqb4ka_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_l5uyxaam_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cMsg_qy5D08Vo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_86vakDBR, HV_BINOP_POW, 0, m, &cBinop_86vakDBR_sendMessage);
}

void Heavy_CircleStrings::cBinop_86vakDBR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_Uq6uKPVc, 0, m, &cPack_Uq6uKPVc_sendMessage);
}

void Heavy_CircleStrings::cBinop_hIo4sr6c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_lwE08gEw_sendMessage);
}

void Heavy_CircleStrings::cCast_N64KnOMP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_Z3OsSUYc, 0, m, &cIf_Z3OsSUYc_sendMessage);
}

void Heavy_CircleStrings::cCast_Wf6c3sxj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_oAoALVdA_sendMessage);
}

void Heavy_CircleStrings::cBinop_oAoALVdA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_Z3OsSUYc, 1, m, &cIf_Z3OsSUYc_sendMessage);
}

void Heavy_CircleStrings::cBinop_l5uyxaam_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_hIo4sr6c_sendMessage);
}

void Heavy_CircleStrings::cMsg_a6Sqb4ka_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_Uq6uKPVc, 0, m, &cPack_Uq6uKPVc_sendMessage);
}

void Heavy_CircleStrings::cBinop_lwE08gEw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_86vakDBR, HV_BINOP_POW, 1, m, &cBinop_86vakDBR_sendMessage);
  cMsg_qy5D08Vo_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cPack_Uq6uKPVc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_5izOkr9E, 0, m, NULL);
}

void Heavy_CircleStrings::cVar_Zu3HJcmd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_yeiz7rzT_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_GhQTF94c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSend_eJxo2b6Z_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_eJxo2b6Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_9jj1UQMO_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_yeiz7rzT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_wMohgGv7_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cIf_1iBabhhk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_rfjxMGsL_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_LOG10, m, &cUnop_BNSwpyA5_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cUnop_BNSwpyA5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_pWyr7D2G_sendMessage);
}

void Heavy_CircleStrings::cCast_QidqD7wJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_1iBabhhk, 0, m, &cIf_1iBabhhk_sendMessage);
}

void Heavy_CircleStrings::cCast_2ODWqlSM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_4ZkStA6O_sendMessage);
}

void Heavy_CircleStrings::cMsg_rfjxMGsL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cMsg_VYqQLo4t_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_8RXdjYOd_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_STDxfehq_sendMessage);
}

void Heavy_CircleStrings::cBinop_pWyr7D2G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 100.0f, 0, m, &cBinop_kujVbpHS_sendMessage);
}

void Heavy_CircleStrings::cBinop_kujVbpHS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_fCbZrZ69_sendMessage);
}

void Heavy_CircleStrings::cBinop_fCbZrZ69_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_VYqQLo4t_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_8RXdjYOd_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_STDxfehq_sendMessage);
}

void Heavy_CircleStrings::cBinop_4ZkStA6O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_1iBabhhk, 1, m, &cIf_1iBabhhk_sendMessage);
}

void Heavy_CircleStrings::cBinop_OZ2BHEqS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_2ODWqlSM_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_QidqD7wJ_sendMessage);
}

void Heavy_CircleStrings::cBinop_SrAcqCr4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_OZ2BHEqS_sendMessage);
}

void Heavy_CircleStrings::cIf_tvbYkS06_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_5OtzzG5m_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_LOG10, m, &cUnop_jRwoEUfD_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cUnop_jRwoEUfD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_ANC7s6ZM_sendMessage);
}

void Heavy_CircleStrings::cCast_TpfMn73U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_tvbYkS06, 0, m, &cIf_tvbYkS06_sendMessage);
}

void Heavy_CircleStrings::cCast_JV7pcM1M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_1bebFMGH_sendMessage);
}

void Heavy_CircleStrings::cMsg_5OtzzG5m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cMsg_lpA123tW_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_qTx04O27_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_YoGBbyL2_sendMessage);
}

void Heavy_CircleStrings::cBinop_ANC7s6ZM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 100.0f, 0, m, &cBinop_nYudYVNB_sendMessage);
}

void Heavy_CircleStrings::cBinop_nYudYVNB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_TXL4K51G_sendMessage);
}

void Heavy_CircleStrings::cBinop_TXL4K51G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_lpA123tW_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_qTx04O27_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_YoGBbyL2_sendMessage);
}

void Heavy_CircleStrings::cBinop_1bebFMGH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_tvbYkS06, 1, m, &cIf_tvbYkS06_sendMessage);
}

void Heavy_CircleStrings::cBinop_Vjio6KW1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_JV7pcM1M_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_TpfMn73U_sendMessage);
}

void Heavy_CircleStrings::cBinop_NhKs4MIA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_Vjio6KW1_sendMessage);
}

void Heavy_CircleStrings::cVar_bKAVODIw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_TO7VYdb8_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_piwB7ORG_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_msvCJFyv_sendMessage);
}

void Heavy_CircleStrings::cIf_la6D2bTq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_A2qsnO42_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_PDSX3aWe_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cMsg_W8pADi2P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_wzy55oZ0, HV_BINOP_POW, 0, m, &cBinop_wzy55oZ0_sendMessage);
}

void Heavy_CircleStrings::cBinop_wzy55oZ0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_stG5TFJk, 0, m, &cPack_stG5TFJk_sendMessage);
}

void Heavy_CircleStrings::cBinop_bll5PqXJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_lGCGNram_sendMessage);
}

void Heavy_CircleStrings::cCast_piwB7ORG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_r69DbcBU_sendMessage);
}

void Heavy_CircleStrings::cCast_msvCJFyv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_la6D2bTq, 0, m, &cIf_la6D2bTq_sendMessage);
}

void Heavy_CircleStrings::cBinop_r69DbcBU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_la6D2bTq, 1, m, &cIf_la6D2bTq_sendMessage);
}

void Heavy_CircleStrings::cBinop_PDSX3aWe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_bll5PqXJ_sendMessage);
}

void Heavy_CircleStrings::cMsg_A2qsnO42_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_stG5TFJk, 0, m, &cPack_stG5TFJk_sendMessage);
}

void Heavy_CircleStrings::cBinop_lGCGNram_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_wzy55oZ0, HV_BINOP_POW, 1, m, &cBinop_wzy55oZ0_sendMessage);
  cMsg_W8pADi2P_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cPack_stG5TFJk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_NrKZS8CR, 0, m, NULL);
}

void Heavy_CircleStrings::cVar_LWI7IMpl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_93A11xLh_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_TO7VYdb8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSend_YxH1j5JZ_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_YxH1j5JZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_x5L247lF_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_93A11xLh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_fMPXpATZ_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cPack_i1JJg3xN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_asLxdEsN, 0, m, &cIf_asLxdEsN_sendMessage);
}

void Heavy_CircleStrings::cSlice_LUboW4WX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_VjGGR2wO_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_96Ffwpmd_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cSlice_TbEBJSv7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cIf_onMessage(_c, &Context(_c)->cIf_5d75bUlZ, 0, m, &cIf_5d75bUlZ_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cIf_5d75bUlZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_EuMxR1Ta_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_mi5IhdE2_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cIf_7P1ZmEFw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cPack_onMessage(_c, &Context(_c)->cPack_5qSjqcfM, 2, m, &cPack_5qSjqcfM_sendMessage);
      cPack_onMessage(_c, &Context(_c)->cPack_cJvMOmg4, 1, m, &cPack_cJvMOmg4_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cIf_WkTttCOy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_LUboW4WX, 0, m, &cSlice_LUboW4WX_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_TbEBJSv7, 0, m, &cSlice_TbEBJSv7_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cSlice_mNrtE3jJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_Wnq8QSnj_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cSlice_tyNf9wV7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_DMO419Mu_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_GsWxfsUj_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_JdOLHAoM_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cVar_doNbZc4Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_8I8e6CBD, 1, m, &cIf_8I8e6CBD_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_7Toz3V06_sendMessage);
}

void Heavy_CircleStrings::cIf_8I8e6CBD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_LUboW4WX, 0, m, &cSlice_LUboW4WX_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_TbEBJSv7, 0, m, &cSlice_TbEBJSv7_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cPack_cJvMOmg4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_WkTttCOy, 0, m, &cIf_WkTttCOy_sendMessage);
}

void Heavy_CircleStrings::cBinop_dOS6IVZ8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_5d75bUlZ, 1, m, &cIf_5d75bUlZ_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_7P1ZmEFw, 1, m, &cIf_7P1ZmEFw_sendMessage);
}

void Heavy_CircleStrings::cCast_VjGGR2wO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_NEQ, 0.0f, 0, m, &cBinop_dOS6IVZ8_sendMessage);
}

void Heavy_CircleStrings::cCast_96Ffwpmd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_7P1ZmEFw, 0, m, &cIf_7P1ZmEFw_sendMessage);
}

void Heavy_CircleStrings::cMsg_UQPbAe4k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_doNbZc4Q, 1, m, &cVar_doNbZc4Q_sendMessage);
}

void Heavy_CircleStrings::cMsg_Wnq8QSnj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_doNbZc4Q, 1, m, &cVar_doNbZc4Q_sendMessage);
}

void Heavy_CircleStrings::cCast_JdOLHAoM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_UQPbAe4k_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_DMO419Mu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_doNbZc4Q, 0, m, &cVar_doNbZc4Q_sendMessage);
}

void Heavy_CircleStrings::cCast_GsWxfsUj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_cJvMOmg4, 0, m, &cPack_cJvMOmg4_sendMessage);
}

void Heavy_CircleStrings::cBinop_7Toz3V06_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_WkTttCOy, 1, m, &cIf_WkTttCOy_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_snenanJH_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_D4bzfOnH, 0, m, &cSlice_D4bzfOnH_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_OsG4fnNS, 0, m, &cSlice_OsG4fnNS_sendMessage);
      break;
    }
    case 0x40000000: { // "2.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_QmvyGpOh, 0, m, &cSlice_QmvyGpOh_sendMessage);
      break;
    }
    case 0x40400000: { // "3.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_q5dci14u, 0, m, &cSlice_q5dci14u_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cSlice_D4bzfOnH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_xWzcgVhx, 0, m, &cSlice_xWzcgVhx_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_KCxKR3ti, 0, m, &cSlice_KCxKR3ti_sendMessage);
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_xWzcgVhx, 0, m, &cSlice_xWzcgVhx_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_KCxKR3ti, 0, m, &cSlice_KCxKR3ti_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cSlice_OsG4fnNS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_nZ7Ji8aR, 0, m, &cSlice_nZ7Ji8aR_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_2ifoyNME, 0, m, &cSlice_2ifoyNME_sendMessage);
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_nZ7Ji8aR, 0, m, &cSlice_nZ7Ji8aR_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_2ifoyNME, 0, m, &cSlice_2ifoyNME_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cSlice_QmvyGpOh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_DNFsvgjW, 0, m, &cSlice_DNFsvgjW_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_k2abEYDJ, 0, m, &cSlice_k2abEYDJ_sendMessage);
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_DNFsvgjW, 0, m, &cSlice_DNFsvgjW_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_k2abEYDJ, 0, m, &cSlice_k2abEYDJ_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cSlice_q5dci14u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_YZIyJR1o, 0, m, &cSlice_YZIyJR1o_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_fb0yezsH, 0, m, &cSlice_fb0yezsH_sendMessage);
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_YZIyJR1o, 0, m, &cSlice_YZIyJR1o_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_fb0yezsH, 0, m, &cSlice_fb0yezsH_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cSwitchcase_kLoOmuXV_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_FCcfZgMd_sendMessage);
      break;
    }
    default: {
      cMsg_hDGpaPlm_sendMessage(_c, 0, m);
      break;
    }
  }
}

void Heavy_CircleStrings::cCast_FCcfZgMd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_NV7Q6FQN_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cIf_asLxdEsN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_mNrtE3jJ, 0, m, &cSlice_mNrtE3jJ_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_tyNf9wV7, 0, m, &cSlice_tyNf9wV7_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_8I8e6CBD, 0, m, &cIf_8I8e6CBD_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cVar_OPq1mGMn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_h5ThfGU1_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_asLxdEsN, 1, m, &cIf_asLxdEsN_sendMessage);
}

void Heavy_CircleStrings::cBinop_h5ThfGU1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_OPq1mGMn, 1, m, &cVar_OPq1mGMn_sendMessage);
}

void Heavy_CircleStrings::cMsg_NV7Q6FQN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_OPq1mGMn, 0, m, &cVar_OPq1mGMn_sendMessage);
}

void Heavy_CircleStrings::cMsg_hDGpaPlm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_OPq1mGMn, 0, m, &cVar_OPq1mGMn_sendMessage);
}

void Heavy_CircleStrings::cPack_5qSjqcfM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_snenanJH_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cVar_C51LgecL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_5qSjqcfM, 0, m, &cPack_5qSjqcfM_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_lX6zzxFG_sendMessage);
}

void Heavy_CircleStrings::cBinop_lX6zzxFG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MOD_BIPOLAR, 4.0f, 0, m, &cBinop_Sq87u1IU_sendMessage);
}

void Heavy_CircleStrings::cBinop_Sq87u1IU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_C51LgecL, 1, m, &cVar_C51LgecL_sendMessage);
}

void Heavy_CircleStrings::cMsg_u6uedWd2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_kLoOmuXV_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cCast_EuMxR1Ta_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_5qSjqcfM, 1, m, &cPack_5qSjqcfM_sendMessage);
}

void Heavy_CircleStrings::cCast_mi5IhdE2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_C51LgecL, 0, m, &cVar_C51LgecL_sendMessage);
}

void Heavy_CircleStrings::cSend_bPEXEpUs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_FrdgGU9i_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_hkt7lj8l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_U4ehvbIg_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_txx1kjFz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cBinop_dECSANqd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_n86EhpXv_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_n86EhpXv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_RtOjalu1_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_5T1ws9fy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_GgvMnSQr_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cReceive_8pIITIXJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_6ni9pvkX_sendMessage(_c, 0, m);
  cMsg_CxemCxti_sendMessage(_c, 0, m);
  cMsg_DL2p9fa2_sendMessage(_c, 0, m);
  cMsg_DByq07I6_sendMessage(_c, 0, m);
  cMsg_sQL8yL4q_sendMessage(_c, 0, m);
  cMsg_RSqoNwlV_sendMessage(_c, 0, m);
  cMsg_SoY5z1dF_sendMessage(_c, 0, m);
  cMsg_2XPq2wnC_sendMessage(_c, 0, m);
  cMsg_RDGBhBU7_sendMessage(_c, 0, m);
  cMsg_20WQRphU_sendMessage(_c, 0, m);
  cMsg_LUnpFvAN_sendMessage(_c, 0, m);
  cMsg_ADwH3lP4_sendMessage(_c, 0, m);
  cMsg_TeUpXtOn_sendMessage(_c, 0, m);
  cMsg_8SOPytuh_sendMessage(_c, 0, m);
  cMsg_qA2HgMPK_sendMessage(_c, 0, m);
  cMsg_wXGyi58e_sendMessage(_c, 0, m);
  cMsg_Ubi6Vcef_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_Cpd1irMP, 0, m, &cVar_Cpd1irMP_sendMessage);
  cMsg_669bFNut_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_HnAqA7yD, 0, m, &cVar_HnAqA7yD_sendMessage);
  cMsg_hapuUYAE_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_xCK4ZhN0, 0, m, &cVar_xCK4ZhN0_sendMessage);
  cMsg_jqArntBR_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_SjAvNGPm, 0, m, &cVar_SjAvNGPm_sendMessage);
  cMsg_npSfMmxn_sendMessage(_c, 0, m);
  cMsg_VJOOcq8E_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_6xH2yGXb, 0, m, &cVar_6xH2yGXb_sendMessage);
  cMsg_nnA1CjoW_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_9J7oUWi4, 0, m, &cVar_9J7oUWi4_sendMessage);
  cMsg_0wm2F7hG_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_M60VxuUX, 0, m, &cVar_M60VxuUX_sendMessage);
  cMsg_FfHMed1B_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_xVJJAgrn, 0, m, &cVar_xVJJAgrn_sendMessage);
  cMsg_rjVjaqb3_sendMessage(_c, 0, m);
  cMsg_7spsJMtO_sendMessage(_c, 0, m);
  cMsg_BKUZkhuD_sendMessage(_c, 0, m);
  cMsg_4w7B59wO_sendMessage(_c, 0, m);
  cMsg_h31L5BMN_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_VBjv806w, 0, m, &cVar_VBjv806w_sendMessage);
  cMsg_O3FKb2Ca_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_c4ndmtKo, 0, m, &cVar_c4ndmtKo_sendMessage);
  cMsg_2rt51FrQ_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_zoAiLxe5, 0, m, &cVar_zoAiLxe5_sendMessage);
  cMsg_oqnJEcfO_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_IYbZH8FJ, 0, m, &cVar_IYbZH8FJ_sendMessage);
  cMsg_NETlPpn5_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_FMsMNLX8, 0, m, &cVar_FMsMNLX8_sendMessage);
  cMsg_Qcv7mKEI_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_s5lWnt7x, 0, m, &cVar_s5lWnt7x_sendMessage);
  cMsg_LsXsOFrN_sendMessage(_c, 0, m);
  cMsg_ljNaJ8u4_sendMessage(_c, 0, m);
  cMsg_C8auJuRL_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_PZGlDA4M, 0, m, &cVar_PZGlDA4M_sendMessage);
  cMsg_3rLyIgsB_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_5miSL3kM, 0, m, &cVar_5miSL3kM_sendMessage);
  cMsg_xd8rJiQJ_sendMessage(_c, 0, m);
  cMsg_iu4KsLkS_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_ncd4NLaV, 0, m, &cVar_ncd4NLaV_sendMessage);
  cMsg_dmneso2d_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_9DPzXJzk, 0, m, &cVar_9DPzXJzk_sendMessage);
  cSwitchcase_pmFLHTEN_onMessage(_c, NULL, 0, m, NULL);
  cMsg_nc2tq0nv_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_jKarz4n1, 0, m, &cVar_jKarz4n1_sendMessage);
  cMsg_6bI1wQmp_sendMessage(_c, 0, m);
  cSwitchcase_D35fsASg_onMessage(_c, NULL, 0, m, NULL);
  cMsg_riz0oF0M_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_08LWfvXU, 0, m, &cVar_08LWfvXU_sendMessage);
  cMsg_WFvL6j9p_sendMessage(_c, 0, m);
  cSwitchcase_uPe1KPdG_onMessage(_c, NULL, 0, m, NULL);
  cMsg_FyjUiHwx_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_mbStdtfa, 0, m, &cVar_mbStdtfa_sendMessage);
  cMsg_coQBEVFC_sendMessage(_c, 0, m);
  cSwitchcase_3VNL2HZo_onMessage(_c, NULL, 0, m, NULL);
  cMsg_6iVQo6PC_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_ucInTxs1, 0, m, &cVar_ucInTxs1_sendMessage);
  cMsg_3dvJTL3C_sendMessage(_c, 0, m);
  cSwitchcase_HE6LzzQ6_onMessage(_c, NULL, 0, m, NULL);
  cMsg_1P7EX4pU_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_KgJd8Gmx, 0, m, &cVar_KgJd8Gmx_sendMessage);
  cMsg_bnS4ybYQ_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_Wk4Ut97v, 0, m, &cVar_Wk4Ut97v_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_POglyt9T, 0, m, &cVar_POglyt9T_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_q537VAx5, 0, m, &cVar_q537VAx5_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_aW7RwTuh, 0, m, &cVar_aW7RwTuh_sendMessage);
  cMsg_Lh3OVNce_sendMessage(_c, 0, m);
  cMsg_z9GTGC6o_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_GLnzeSRQ, 0, m, &cVar_GLnzeSRQ_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_xc7L7wV4, 0, m, &cVar_xc7L7wV4_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_5LelctpU, 0, m, &cVar_5LelctpU_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_W49KAy3V, 0, m, &cVar_W49KAy3V_sendMessage);
  cMsg_tZ8bP8wY_sendMessage(_c, 0, m);
  cMsg_X9F4bkKT_sendMessage(_c, 0, m);
  cMsg_Yb9L5Rn2_sendMessage(_c, 0, m);
  cMsg_sbs7Wa6i_sendMessage(_c, 0, m);
  cMsg_QllgyywM_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_BTpVXvBJ, 0, m, &cVar_BTpVXvBJ_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_Jav6hQnb, 0, m, &cVar_Jav6hQnb_sendMessage);
  cMsg_dtQ4jMO8_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_xE3PY6vU, 0, m, &cVar_xE3PY6vU_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_IMcPdQOU, 0, m, &cVar_IMcPdQOU_sendMessage);
  cMsg_T35p1EbU_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_wEgefPHf, 0, m, &cVar_wEgefPHf_sendMessage);
  cMsg_pi5uwmay_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_NoZr9Ai2, 0, m, &cVar_NoZr9Ai2_sendMessage);
  cMsg_WDWdkX58_sendMessage(_c, 0, m);
  cMsg_DZ3gqjiG_sendMessage(_c, 0, m);
  cMsg_14jKHVkf_sendMessage(_c, 0, m);
  cMsg_21lmMX2j_sendMessage(_c, 0, m);
  cMsg_stGk5hxY_sendMessage(_c, 0, m);
  cMsg_aYSnjeNL_sendMessage(_c, 0, m);
  cMsg_xpcHeQUP_sendMessage(_c, 0, m);
  cMsg_BeXihz1x_sendMessage(_c, 0, m);
  cMsg_hL8WJneA_sendMessage(_c, 0, m);
  cMsg_V68XsOfh_sendMessage(_c, 0, m);
  cMsg_9YJCYGn1_sendMessage(_c, 0, m);
  cMsg_7zA2bHc9_sendMessage(_c, 0, m);
  cMsg_OfCAIAPD_sendMessage(_c, 0, m);
  cMsg_9vBoPPmf_sendMessage(_c, 0, m);
  cMsg_kszFmSfz_sendMessage(_c, 0, m);
  cMsg_NHjl9qq4_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_fUDhmIEA, 0, m, &cVar_fUDhmIEA_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_O8ScjlCf, 0, m, &cVar_O8ScjlCf_sendMessage);
  cMsg_cDrw4xbC_sendMessage(_c, 0, m);
  cMsg_UH8IJQo7_sendMessage(_c, 0, m);
  cMsg_R0aTmhJD_sendMessage(_c, 0, m);
  cMsg_tY43nCvs_sendMessage(_c, 0, m);
  cMsg_oflD9A5U_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_5qQXuOYL, 0, m, &cVar_5qQXuOYL_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_PuGlDK1h, 0, m, &cVar_PuGlDK1h_sendMessage);
  cMsg_6DdbXwc1_sendMessage(_c, 0, m);
  cMsg_wih9Yc9a_sendMessage(_c, 0, m);
  cMsg_5sw2K879_sendMessage(_c, 0, m);
  cMsg_BxC6CmaH_sendMessage(_c, 0, m);
  cMsg_mFjWHN4f_sendMessage(_c, 0, m);
  cMsg_AUk5HxPh_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_j1oUZmqA, 0, m, &cVar_j1oUZmqA_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_AOYPt2KL, 0, m, &cVar_AOYPt2KL_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_UO9Ao0DX, 0, m, &cVar_UO9Ao0DX_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_bKAVODIw, 0, m, &cVar_bKAVODIw_sendMessage);
  cMsg_u6uedWd2_sendMessage(_c, 0, m);
  cSwitchcase_GgvMnSQr_onMessage(_c, NULL, 0, m, NULL);
  cMsg_Uw9EWPPa_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_l9At09eB, 0, m, &cVar_l9At09eB_sendMessage);
  cMsg_yzScGxj4_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_k99OEdhR, 0, m, &cTabhead_k99OEdhR_sendMessage);
  cMsg_1nBQ1RzG_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_lccHhdAk, 0, m, &cVar_lccHhdAk_sendMessage);
  cMsg_HuubA4Th_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_V60sfg3B, 0, m, &cTabhead_V60sfg3B_sendMessage);
  cMsg_LotDbnR8_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_zdthsmSI, 0, m, &cVar_zdthsmSI_sendMessage);
  cMsg_VvHSLGh3_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_Hgm0S4ZL, 0, m, &cTabhead_Hgm0S4ZL_sendMessage);
  cMsg_tJt6EZvc_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_kkbVxf51, 0, m, &cVar_kkbVxf51_sendMessage);
  cMsg_G4JtrXms_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_xpLrQIFc, 0, m, &cTabhead_xpLrQIFc_sendMessage);
  cMsg_BPFQPVKv_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_BdefvVic, 0, m, &cVar_BdefvVic_sendMessage);
  cMsg_q9hpsFpN_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_W12nQhiI, 0, m, &cTabhead_W12nQhiI_sendMessage);
  cMsg_4FapKxJ7_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_jYPWt4j5, 0, m, &cVar_jYPWt4j5_sendMessage);
  cMsg_17H3yZWO_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_pFDGeXDK, 0, m, &cTabhead_pFDGeXDK_sendMessage);
  cMsg_rRJqojfJ_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_6RaAIoMM, 0, m, &cVar_6RaAIoMM_sendMessage);
  cMsg_pdQWnZOq_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_SJU0AhS9, 0, m, &cTabhead_SJU0AhS9_sendMessage);
  cMsg_ucUf09nE_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_rSqpGWhk, 0, m, &cVar_rSqpGWhk_sendMessage);
  cMsg_jGeb9EEa_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_RjkRPhh7, 0, m, &cTabhead_RjkRPhh7_sendMessage);
  cMsg_Sz6iUFMX_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_7zeNrBua, 0, m, &cVar_7zeNrBua_sendMessage);
  cMsg_EaFMODOK_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_IDWB45r9, 0, m, &cTabhead_IDWB45r9_sendMessage);
  cMsg_TZE8jh1U_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_mSWPORcU, 0, m, &cVar_mSWPORcU_sendMessage);
  cMsg_r9pykefT_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_8wBSygWM, 0, m, &cTabhead_8wBSygWM_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_TD1mAJWS, 0, m, &cVar_TD1mAJWS_sendMessage);
  cMsg_ps3UHWjg_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_Zhuzvvft, 0, m, &cVar_Zhuzvvft_sendMessage);
  cMsg_G3Hw7DZY_sendMessage(_c, 0, m);
  cMsg_FsBpgK6g_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_fRj7lVHS, 0, m, &cVar_fRj7lVHS_sendMessage);
  cMsg_OlIhUEiJ_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_lfZwwRrn, 0, m, &cTabhead_lfZwwRrn_sendMessage);
  cMsg_NHnX96oq_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_eM0boj18, 0, m, &cVar_eM0boj18_sendMessage);
  cMsg_GCyWxorY_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_K0nzYXXe, 0, m, &cTabhead_K0nzYXXe_sendMessage);
  cMsg_0mwqxay1_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_41BEFoI6, 0, m, &cVar_41BEFoI6_sendMessage);
  cMsg_6vclW6VP_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_L330esLI, 0, m, &cTabhead_L330esLI_sendMessage);
  cMsg_DGkcJNI8_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_TY5wzbag, 0, m, &cVar_TY5wzbag_sendMessage);
  cMsg_ckqdEYLe_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_mRXnhi5H, 0, m, &cTabhead_mRXnhi5H_sendMessage);
  cMsg_Lynl2tqP_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_PpCeroRQ, 0, m, &cVar_PpCeroRQ_sendMessage);
  cMsg_7vf0Aryo_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_aIAprJqe, 0, m, &cTabhead_aIAprJqe_sendMessage);
  cMsg_bKLJrzAv_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_2bYgkoWy, 0, m, &cVar_2bYgkoWy_sendMessage);
  cMsg_o9G1rd4H_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_LJ1K4BM0, 0, m, &cTabhead_LJ1K4BM0_sendMessage);
  cMsg_2QwaOjWG_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_6hSfbrPG, 0, m, &cVar_6hSfbrPG_sendMessage);
  cMsg_UP0lHKmv_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_U4zTwJnH, 0, m, &cTabhead_U4zTwJnH_sendMessage);
  cMsg_4FH3cpGS_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_MqDPT2RA, 0, m, &cVar_MqDPT2RA_sendMessage);
  cMsg_DP01RcKZ_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_LeFC9cFs, 0, m, &cTabhead_LeFC9cFs_sendMessage);
  cMsg_X3OMqnMg_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_XjRxuH4R, 0, m, &cVar_XjRxuH4R_sendMessage);
  cMsg_AoMI58pw_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_aP34WzdI, 0, m, &cTabhead_aP34WzdI_sendMessage);
  cMsg_Wqq5pfXt_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_piYaJnlH, 0, m, &cVar_piYaJnlH_sendMessage);
  cMsg_o1evkdXH_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_wFy48l8R, 0, m, &cTabhead_wFy48l8R_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_zdRc1MtI, 0, m, &cVar_zdRc1MtI_sendMessage);
  cMsg_rO8GliYO_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_rpEvAsq0, 0, m, &cVar_rpEvAsq0_sendMessage);
  cMsg_vhzvfOGf_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_KmuDXz2l, 0, m, &cVar_KmuDXz2l_sendMessage);
  cMsg_1jbiFD4M_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_9f9UlSz2, 0, m, &cVar_9f9UlSz2_sendMessage);
  cMsg_lJfhLY1H_sendMessage(_c, 0, m);
  cMsg_0CGmgP5w_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_rzu47SIA, 0, m, &cVar_rzu47SIA_sendMessage);
  cMsg_y377du2T_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_ZEBE9mCN, 0, m, &cTabhead_ZEBE9mCN_sendMessage);
  cMsg_WnYqLWFU_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_3A2ohpsB, 0, m, &cVar_3A2ohpsB_sendMessage);
  cMsg_E84FXqcz_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_yByfXtt9, 0, m, &cTabhead_yByfXtt9_sendMessage);
  cMsg_35HkjHaM_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_TZPELRDt, 0, m, &cVar_TZPELRDt_sendMessage);
  cMsg_y0zgSvPC_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_lTp1bLjF, 0, m, &cTabhead_lTp1bLjF_sendMessage);
  cMsg_yo4tZKJr_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_PhBzj2gg, 0, m, &cVar_PhBzj2gg_sendMessage);
  cMsg_iKBadwfV_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_jzrfxRrt, 0, m, &cTabhead_jzrfxRrt_sendMessage);
  cMsg_8I8rnGIk_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_K2cULozm, 0, m, &cVar_K2cULozm_sendMessage);
  cMsg_b06c4npQ_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_uF0bu8WL, 0, m, &cTabhead_uF0bu8WL_sendMessage);
}

void Heavy_CircleStrings::cReceive_itLbGSUu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSlice_onMessage(_c, &Context(_c)->cSlice_4CQFOYWS, 0, m, &cSlice_4CQFOYWS_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_ItLuudPt, 0, m, &cSlice_ItLuudPt_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_m0ZXlN5E, 0, m, &cSlice_m0ZXlN5E_sendMessage);
}

void Heavy_CircleStrings::cReceive_FrdgGU9i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_i1JJg3xN, 0, m, &cPack_i1JJg3xN_sendMessage);
}

void Heavy_CircleStrings::cReceive_U4ehvbIg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_i1JJg3xN, 1, m, &cPack_i1JJg3xN_sendMessage);
}

void Heavy_CircleStrings::cReceive_Vjanh444_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 2.0f, 0, m, &cBinop_qSpD0SPI_sendMessage);
}

void Heavy_CircleStrings::cReceive_j0Ufjkmw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_03jVTN5I_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_vUTAeXMV_sendMessage);
}

void Heavy_CircleStrings::cReceive_PfZW4QN9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_FNIv0tiz_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_FG0oUxAc_sendMessage);
  cPack_onMessage(_c, &Context(_c)->cPack_GVvoVYO8, 0, m, &cPack_GVvoVYO8_sendMessage);
}

void Heavy_CircleStrings::cReceive_8nCpMyc8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_jDKW6UpE_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_AF1XkyBF, 0, m, &cIf_AF1XkyBF_sendMessage);
}

void Heavy_CircleStrings::cReceive_83M9Hmpd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_LbmRsRt5, 1, m, &cVar_LbmRsRt5_sendMessage);
}

void Heavy_CircleStrings::cReceive_FgDF1r96_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_xlIY8NZW, 0, m, &cVar_xlIY8NZW_sendMessage);
  cPack_onMessage(_c, &Context(_c)->cPack_y8P8qVQg, 0, m, &cPack_y8P8qVQg_sendMessage);
}

void Heavy_CircleStrings::cReceive_4SE2tV70_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 100.0f, 0, m, &cBinop_gvR52ywe_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_06WvpFm9_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_W6un9OED, 0, m, &cIf_W6un9OED_sendMessage);
}

void Heavy_CircleStrings::cReceive_exe9dQR0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cReceive_bzy700uZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_K7Fa0OAn_sendMessage);
}

void Heavy_CircleStrings::cReceive_3YmY9uz3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_5T1ws9fy_sendMessage);
}

void Heavy_CircleStrings::cReceive_RtOjalu1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_M18x5i90, 0, m, &cVar_M18x5i90_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_IBICAOIV, 0, m, &cVar_IBICAOIV_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_b1go0ylg, 0, m, &cVar_b1go0ylg_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_va0Z8BCC, 0, m, &cVar_va0Z8BCC_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_2zWcJT0U_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_n9HzMYMz, 0, m, &cIf_n9HzMYMz_sendMessage);
}

void Heavy_CircleStrings::cReceive_3u04fSnV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_ZPldOHHw_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_LCShkyro, 0, m, &cVar_LCShkyro_sendMessage);
}

void Heavy_CircleStrings::cReceive_dKHTl5Gy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_5gGnCKHq, 0, m, &cPack_5gGnCKHq_sendMessage);
}

void Heavy_CircleStrings::cReceive_vgfTutZr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_k0RrR1xv, 1, m, &cVar_k0RrR1xv_sendMessage);
}

void Heavy_CircleStrings::cReceive_AhseCEqk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_2kvbRuso, m);
}

void Heavy_CircleStrings::cReceive_H6obejJw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_c2hqShIJ_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_wSZWF4Fa, 0, m, &cVar_wSZWF4Fa_sendMessage);
}

void Heavy_CircleStrings::cReceive_BJqx0LBS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_9GRCMlzK_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_YkEc34Ic, 0, m, &cVar_YkEc34Ic_sendMessage);
}

void Heavy_CircleStrings::cReceive_002zsoz5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_FKIQ7qcR, 0, m, &cVar_FKIQ7qcR_sendMessage);
}

void Heavy_CircleStrings::cReceive_qa37TAUQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_qz8xrhJo_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_MBHYslFr_sendMessage);
}

void Heavy_CircleStrings::cReceive_kKfsjFPE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_tfVeb2xy, 0, m, &cVar_tfVeb2xy_sendMessage);
}

void Heavy_CircleStrings::cReceive_6P36y0JI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_3uLdNv0I_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_hoKeUWYz_sendMessage);
}

void Heavy_CircleStrings::cReceive_M7G3MMuu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_sKxjXcV9_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_43dzlu6h, 0, m, &cVar_43dzlu6h_sendMessage);
}

void Heavy_CircleStrings::cReceive_vzmWrOtl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_hCzuDCpN, 0, m, &cPack_hCzuDCpN_sendMessage);
}

void Heavy_CircleStrings::cReceive_bgcZimyq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_GXHAgQOI, 1, m, &cVar_GXHAgQOI_sendMessage);
}

void Heavy_CircleStrings::cReceive_EujQ5qdA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_xOQ29moC, m);
}

void Heavy_CircleStrings::cReceive_EDggbWw1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_KnYa58e5_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_sk4Y9Ht3, 0, m, &cVar_sk4Y9Ht3_sendMessage);
}

void Heavy_CircleStrings::cReceive_woqS8Xio_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_HT15MpsU_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_Mt4QMNTY, 0, m, &cVar_Mt4QMNTY_sendMessage);
}

void Heavy_CircleStrings::cReceive_HWtXeN6Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_HRxqRcEN_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_EqKxQ7Ju, 0, m, &cVar_EqKxQ7Ju_sendMessage);
}

void Heavy_CircleStrings::cReceive_UsbLKWib_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_upolaOH3, 0, m, &cPack_upolaOH3_sendMessage);
}

void Heavy_CircleStrings::cReceive_rfywEDQd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_WrBsBufF, 1, m, &cVar_WrBsBufF_sendMessage);
}

void Heavy_CircleStrings::cReceive_LFS2MKvw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_Fw6A8D3a, m);
}

void Heavy_CircleStrings::cReceive_33EGZ9B2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_PZHauXFq_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_ICD2vIGz, 0, m, &cVar_ICD2vIGz_sendMessage);
}

void Heavy_CircleStrings::cReceive_SY3wwCjD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_yeEH4ste_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_OEWMLfBh, 0, m, &cVar_OEWMLfBh_sendMessage);
}

void Heavy_CircleStrings::cReceive_RWGEA916_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_MUThTmON_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_6z0EVIRH, 0, m, &cVar_6z0EVIRH_sendMessage);
}

void Heavy_CircleStrings::cReceive_fBFJQqQH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_wat93oqB, 0, m, &cPack_wat93oqB_sendMessage);
}

void Heavy_CircleStrings::cReceive_rgeeVsCt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_MWZdEgFV, 1, m, &cVar_MWZdEgFV_sendMessage);
}

void Heavy_CircleStrings::cReceive_DIxKq28q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_UDmQxbMg, m);
}

void Heavy_CircleStrings::cReceive_C8ubQwHc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_29k4x5MN_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_OA2EGsAz, 0, m, &cVar_OA2EGsAz_sendMessage);
}

void Heavy_CircleStrings::cReceive_B5YHdcYw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_oqcmhEtl_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_DpQIec65, 0, m, &cVar_DpQIec65_sendMessage);
}

void Heavy_CircleStrings::cReceive_MAUl3a9R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_2FkmBTue, 0, m, &cVar_2FkmBTue_sendMessage);
}

void Heavy_CircleStrings::cReceive_2gwdia0O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_8RXdjYOd_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_STDxfehq_sendMessage);
}

void Heavy_CircleStrings::cReceive_e2WVQP8D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 2.0f, 0, m, &cBinop_SrAcqCr4_sendMessage);
}

void Heavy_CircleStrings::cReceive_wDEOnKsi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_qYKLSbLk, 0, m, &cVar_qYKLSbLk_sendMessage);
}

void Heavy_CircleStrings::cReceive_yse5Eb4F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_qTx04O27_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_YoGBbyL2_sendMessage);
}

void Heavy_CircleStrings::cReceive_aIhGq4fr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 2.0f, 0, m, &cBinop_NhKs4MIA_sendMessage);
}

void Heavy_CircleStrings::cReceive_9jj1UQMO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Zu3HJcmd, 0, m, &cVar_Zu3HJcmd_sendMessage);
}

void Heavy_CircleStrings::cReceive_wMohgGv7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Wf6c3sxj_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_N64KnOMP_sendMessage);
}

void Heavy_CircleStrings::cReceive_x5L247lF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_LWI7IMpl, 0, m, &cVar_LWI7IMpl_sendMessage);
}

void Heavy_CircleStrings::cReceive_fMPXpATZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_piwB7ORG_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_msvCJFyv_sendMessage);
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
    __hv_tabread_f(&sTabread_Jg3NAmnX, VOf(Bf0));
    __hv_varread_f(&sVarf_GqzXrUBn, VOf(Bf1));
    __hv_mul_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_YnWcGaHO, VOf(Bf0));
    __hv_rpole_f(&sRPole_L4pw2rd9, VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_YUE8cA4Y, VOf(Bf1));
    __hv_mul_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_line_f(&sLine_XWWDuggY, VOf(Bf0));
    __hv_varread_i(&sVari_SYsiY7cX, VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 16807, 16807, 16807, 16807, 16807, 16807, 16807, 16807);
    __hv_mul_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_cast_if(VIi(Bi1), VOf(Bf2));
    __hv_var_k_f(VOf(Bf3), 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f);
    __hv_mul_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_varwrite_i(&sVari_SYsiY7cX, VIi(Bi1));
    __hv_fma_f(VIf(Bf0), VIf(Bf3), VIf(Bf1), VOf(Bf3));
    __hv_tabwrite_f(&sTabwrite_qojkXJOH, VIf(Bf3));
    __hv_line_f(&sLine_y4A9Rpld, VOf(Bf3));
    __hv_varread_f(&sVarf_2kvbRuso, VOf(Bf0));
    __hv_mul_f(VIf(Bf3), VIf(Bf0), VOf(Bf0));
    __hv_mul_f(VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_line_f(&sLine_5QXNhSok, VOf(Bf1));
    __hv_mul_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_line_f(&sLine_3ILYiCrq, VOf(Bf3));
    __hv_mul_f(VIf(Bf0), VIf(Bf3), VOf(Bf3));
    __hv_phasor_k_f(&sPhasor_UpxD1uhe, VOf(Bf0));
    __hv_var_k_f(VOf(Bf2), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf0), VIf(Bf2), VOf(Bf2));
    __hv_abs_f(VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf0), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf2), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf2), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf0), VIf(Bf2), VOf(Bf2));
    __hv_mul_f(VIf(Bf2), VIf(Bf2), VOf(Bf0));
    __hv_mul_f(VIf(Bf2), VIf(Bf0), VOf(Bf4));
    __hv_mul_f(VIf(Bf4), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf5), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf6), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf4), VIf(Bf6), VIf(Bf2), VOf(Bf2));
    __hv_fma_f(VIf(Bf0), VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_line_f(&sLine_zQZ2LjM8, VOf(Bf2));
    __hv_tabread_f(&sTabread_uz45IUr4, VOf(Bf2));
    __hv_varread_f(&sVarf_y4UkHvqz, VOf(Bf5));
    __hv_mul_f(VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_ktRlGh6b, VOf(Bf2));
    __hv_rpole_f(&sRPole_h9VJRh0E, VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_WulfmN9E, VOf(Bf5));
    __hv_mul_f(VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_line_f(&sLine_H0Shf6Kn, VOf(Bf2));
    __hv_varread_i(&sVari_iBYv4MCZ, VOi(Bi1));
    __hv_var_k_i(VOi(Bi0), 16807, 16807, 16807, 16807, 16807, 16807, 16807, 16807);
    __hv_mul_i(VIi(Bi1), VIi(Bi0), VOi(Bi0));
    __hv_cast_if(VIi(Bi0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf6), 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f);
    __hv_mul_f(VIf(Bf0), VIf(Bf6), VOf(Bf6));
    __hv_varwrite_i(&sVari_iBYv4MCZ, VIi(Bi0));
    __hv_fma_f(VIf(Bf2), VIf(Bf6), VIf(Bf5), VOf(Bf6));
    __hv_tabwrite_f(&sTabwrite_nJP4myYz, VIf(Bf6));
    __hv_line_f(&sLine_T2nrutbX, VOf(Bf6));
    __hv_varread_f(&sVarf_xOQ29moC, VOf(Bf2));
    __hv_mul_f(VIf(Bf6), VIf(Bf2), VOf(Bf2));
    __hv_mul_f(VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_line_f(&sLine_OaYhTckm, VOf(Bf5));
    __hv_mul_f(VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_line_f(&sLine_JzK53Cnd, VOf(Bf6));
    __hv_mul_f(VIf(Bf2), VIf(Bf6), VOf(Bf6));
    __hv_phasor_k_f(&sPhasor_wQ7iei15, VOf(Bf2));
    __hv_var_k_f(VOf(Bf0), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf2), VIf(Bf0), VOf(Bf0));
    __hv_abs_f(VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf2), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf0), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf0), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf2), VIf(Bf0), VOf(Bf0));
    __hv_mul_f(VIf(Bf0), VIf(Bf0), VOf(Bf2));
    __hv_mul_f(VIf(Bf0), VIf(Bf2), VOf(Bf4));
    __hv_mul_f(VIf(Bf4), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf7), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf8), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf4), VIf(Bf8), VIf(Bf0), VOf(Bf0));
    __hv_fma_f(VIf(Bf2), VIf(Bf7), VIf(Bf0), VOf(Bf0));
    __hv_line_f(&sLine_J7fLbiEL, VOf(Bf0));
    __hv_add_f(VIf(Bf1), VIf(Bf5), VOf(Bf5));
    __hv_tabread_f(&sTabread_5NVipHqQ, VOf(Bf1));
    __hv_varread_f(&sVarf_IeUPh9s6, VOf(Bf0));
    __hv_mul_f(VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_Mq7nUbi8, VOf(Bf1));
    __hv_rpole_f(&sRPole_BsDIu7qo, VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_AlwSpVoN, VOf(Bf0));
    __hv_mul_f(VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_line_f(&sLine_s5nMQdih, VOf(Bf1));
    __hv_varread_i(&sVari_jZfuUXMV, VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 16807, 16807, 16807, 16807, 16807, 16807, 16807, 16807);
    __hv_mul_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_cast_if(VIi(Bi1), VOf(Bf7));
    __hv_var_k_f(VOf(Bf2), 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f);
    __hv_mul_f(VIf(Bf7), VIf(Bf2), VOf(Bf2));
    __hv_varwrite_i(&sVari_jZfuUXMV, VIi(Bi1));
    __hv_fma_f(VIf(Bf1), VIf(Bf2), VIf(Bf0), VOf(Bf2));
    __hv_tabwrite_f(&sTabwrite_sWDwFtRq, VIf(Bf2));
    __hv_line_f(&sLine_8pq58Ush, VOf(Bf2));
    __hv_varread_f(&sVarf_Fw6A8D3a, VOf(Bf1));
    __hv_mul_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_mul_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_line_f(&sLine_bgzodf4K, VOf(Bf0));
    __hv_mul_f(VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_line_f(&sLine_U1ABC4bt, VOf(Bf2));
    __hv_mul_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_phasor_k_f(&sPhasor_5yq7vD4E, VOf(Bf1));
    __hv_var_k_f(VOf(Bf7), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf1), VIf(Bf7), VOf(Bf7));
    __hv_abs_f(VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf1), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf7), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf7), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf1), VIf(Bf7), VOf(Bf7));
    __hv_mul_f(VIf(Bf7), VIf(Bf7), VOf(Bf1));
    __hv_mul_f(VIf(Bf7), VIf(Bf1), VOf(Bf8));
    __hv_mul_f(VIf(Bf8), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf4), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf9), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf8), VIf(Bf9), VIf(Bf7), VOf(Bf7));
    __hv_fma_f(VIf(Bf1), VIf(Bf4), VIf(Bf7), VOf(Bf7));
    __hv_line_f(&sLine_Tqa1nXEJ, VOf(Bf7));
    __hv_add_f(VIf(Bf5), VIf(Bf0), VOf(Bf0));
    __hv_tabread_f(&sTabread_CLSQbzjP, VOf(Bf5));
    __hv_varread_f(&sVarf_XPajirxG, VOf(Bf7));
    __hv_mul_f(VIf(Bf5), VIf(Bf7), VOf(Bf7));
    __hv_varread_f(&sVarf_z2ylGeUi, VOf(Bf5));
    __hv_rpole_f(&sRPole_hDDoj1Qp, VIf(Bf7), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_hjy7RmaU, VOf(Bf7));
    __hv_mul_f(VIf(Bf5), VIf(Bf7), VOf(Bf7));
    __hv_line_f(&sLine_7pC7DypZ, VOf(Bf5));
    __hv_varread_i(&sVari_EOOMzvK0, VOi(Bi1));
    __hv_var_k_i(VOi(Bi0), 16807, 16807, 16807, 16807, 16807, 16807, 16807, 16807);
    __hv_mul_i(VIi(Bi1), VIi(Bi0), VOi(Bi0));
    __hv_cast_if(VIi(Bi0), VOf(Bf4));
    __hv_var_k_f(VOf(Bf1), 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f);
    __hv_mul_f(VIf(Bf4), VIf(Bf1), VOf(Bf1));
    __hv_varwrite_i(&sVari_EOOMzvK0, VIi(Bi0));
    __hv_fma_f(VIf(Bf5), VIf(Bf1), VIf(Bf7), VOf(Bf1));
    __hv_tabwrite_f(&sTabwrite_cZ9dGKFv, VIf(Bf1));
    __hv_line_f(&sLine_VOaxQqv5, VOf(Bf1));
    __hv_varread_f(&sVarf_UDmQxbMg, VOf(Bf5));
    __hv_mul_f(VIf(Bf1), VIf(Bf5), VOf(Bf5));
    __hv_mul_f(VIf(Bf7), VIf(Bf5), VOf(Bf5));
    __hv_line_f(&sLine_yhuFmEbj, VOf(Bf7));
    __hv_mul_f(VIf(Bf5), VIf(Bf7), VOf(Bf7));
    __hv_line_f(&sLine_ax8jUcg3, VOf(Bf1));
    __hv_mul_f(VIf(Bf5), VIf(Bf1), VOf(Bf1));
    __hv_phasor_k_f(&sPhasor_ylmnYws2, VOf(Bf5));
    __hv_var_k_f(VOf(Bf4), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf5), VIf(Bf4), VOf(Bf4));
    __hv_abs_f(VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf5), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf4), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf4), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf5), VIf(Bf4), VOf(Bf4));
    __hv_mul_f(VIf(Bf4), VIf(Bf4), VOf(Bf5));
    __hv_mul_f(VIf(Bf4), VIf(Bf5), VOf(Bf9));
    __hv_mul_f(VIf(Bf9), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf8), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf10), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf9), VIf(Bf10), VIf(Bf4), VOf(Bf4));
    __hv_fma_f(VIf(Bf5), VIf(Bf8), VIf(Bf4), VOf(Bf4));
    __hv_line_f(&sLine_nENENln6, VOf(Bf4));
    __hv_add_f(VIf(Bf0), VIf(Bf7), VOf(Bf7));
    __hv_add_f(VIf(Bf3), VIf(Bf6), VOf(Bf6));
    __hv_add_f(VIf(Bf6), VIf(Bf2), VOf(Bf2));
    __hv_add_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_line_f(&sLine_sSDYtBHt, VOf(Bf2));
    __hv_mul_f(VIf(Bf7), VIf(Bf2), VOf(Bf7));
    __hv_mul_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_tabread_f(&sTabread_fX1QVVSX, VOf(Bf1));
    __hv_varread_f(&sVarf_3kLMESJK, VOf(Bf6));
    __hv_mul_f(VIf(Bf1), VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_78SG5i07, VOf(Bf1));
    __hv_rpole_f(&sRPole_KsJ4z6WV, VIf(Bf6), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_O0FWSn7k, VOf(Bf6));
    __hv_mul_f(VIf(Bf1), VIf(Bf6), VOf(Bf6));
    __hv_line_f(&sLine_3L017wBY, VOf(Bf1));
    __hv_varread_i(&sVari_PV4lGAPF, VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 16807, 16807, 16807, 16807, 16807, 16807, 16807, 16807);
    __hv_mul_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_cast_if(VIi(Bi1), VOf(Bf3));
    __hv_var_k_f(VOf(Bf0), 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f);
    __hv_mul_f(VIf(Bf3), VIf(Bf0), VOf(Bf0));
    __hv_varwrite_i(&sVari_PV4lGAPF, VIi(Bi1));
    __hv_fma_f(VIf(Bf1), VIf(Bf0), VIf(Bf6), VOf(Bf0));
    __hv_tabwrite_f(&sTabwrite_XARTVQyO, VIf(Bf0));
    __hv_line_f(&sLine_ShN6x0iS, VOf(Bf0));
    __hv_mul_f(VIf(Bf6), VIf(Bf0), VOf(Bf0));
    __hv_line_f(&sLine_8Y4DxCb4, VOf(Bf6));
    __hv_mul_f(VIf(Bf0), VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_O7n4PLVN, VOf(Bf0));
    __hv_rpole_f(&sRPole_rBsPYpaz, VIf(Bf6), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf6), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_del1_f(&sDel1_GiygMIoK, VIf(Bf0), VOf(Bf1));
    __hv_mul_f(VIf(Bf1), VIf(Bf6), VOf(Bf6));
    __hv_sub_f(VIf(Bf0), VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_irTY8WQQ, VOf(Bf0));
    __hv_mul_f(VIf(Bf6), VIf(Bf0), VOf(Bf0));
    __hv_line_f(&sLine_NrKZS8CR, VOf(Bf6));
    __hv_mul_f(VIf(Bf0), VIf(Bf6), VOf(Bf6));
    __hv_add_f(VIf(Bf7), VIf(Bf6), VOf(Bf7));
    __hv_add_f(VIf(Bf2), VIf(Bf6), VOf(Bf0));
    __hv_line_f(&sLine_HjQedXwF, VOf(Bf1));
    __hv_mul_f(VIf(Bf7), VIf(Bf1), VOf(Bf7));
    __hv_mul_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_add_f(VIf(Bf2), VIf(Bf6), VOf(Bf6));
    __hv_line_f(&sLine_KbMDzRgq, VOf(Bf2));
    __hv_mul_f(VIf(Bf6), VIf(Bf2), VOf(Bf2));
    __hv_tabread_f(&sTabread_R2nhUQCO, VOf(Bf6));
    __hv_varread_f(&sVarf_Ay061GBp, VOf(Bf0));
    __hv_mul_f(VIf(Bf6), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_kZCD107q, VOf(Bf3));
    __hv_rpole_f(&sRPole_d4ZFwnlm, VIf(Bf0), VIf(Bf3), VOf(Bf3));
    __hv_sub_f(VIf(Bf3), VIf(Bf6), VOf(Bf3));
    __hv_line_f(&sLine_r1mxZfA7, VOf(Bf0));
    __hv_fma_f(VIf(Bf3), VIf(Bf0), VIf(Bf6), VOf(Bf6));
    __hv_line_f(&sLine_xU0GRrnN, VOf(Bf3));
    __hv_tabread_f(&sTabread_6VyhQ8l7, VOf(Bf4));
    __hv_add_f(VIf(Bf2), VIf(Bf4), VOf(Bf8));
    __hv_tabread_f(&sTabread_etC13G1g, VOf(Bf5));
    __hv_add_f(VIf(Bf8), VIf(Bf5), VOf(Bf10));
    __hv_tabread_f(&sTabread_ezpmAwAi, VOf(Bf9));
    __hv_add_f(VIf(Bf10), VIf(Bf9), VOf(Bf11));
    __hv_tabread_f(&sTabread_yJRpdmxp, VOf(Bf12));
    __hv_add_f(VIf(Bf11), VIf(Bf12), VOf(Bf13));
    __hv_tabread_f(&sTabread_lPXorp1b, VOf(Bf14));
    __hv_sub_f(VIf(Bf13), VIf(Bf14), VOf(Bf15));
    __hv_tabwrite_f(&sTabwrite_frPCoSZ3, VIf(Bf15));
    __hv_sub_f(VIf(Bf11), VIf(Bf12), VOf(Bf12));
    __hv_tabwrite_f(&sTabwrite_dyRlqrv2, VIf(Bf12));
    __hv_sub_f(VIf(Bf10), VIf(Bf9), VOf(Bf9));
    __hv_tabwrite_f(&sTabwrite_EEcxaAkq, VIf(Bf9));
    __hv_sub_f(VIf(Bf8), VIf(Bf5), VOf(Bf5));
    __hv_tabwrite_f(&sTabwrite_ZGT5NuOT, VIf(Bf5));
    __hv_sub_f(VIf(Bf2), VIf(Bf4), VOf(Bf4));
    __hv_tabwrite_f(&sTabwrite_CoTpm3wp, VIf(Bf4));
    __hv_tabwrite_f(&sTabwrite_SPOqW7ds, VIf(Bf2));
    __hv_add_f(VIf(Bf13), VIf(Bf14), VOf(Bf14));
    __hv_tabread_f(&sTabread_NQu5hP1y, VOf(Bf13));
    __hv_fma_f(VIf(Bf6), VIf(Bf3), VIf(Bf14), VOf(Bf14));
    __hv_tabread_f(&sTabread_RZSGtOPH, VOf(Bf6));
    __hv_varread_f(&sVarf_G1n7slCX, VOf(Bf4));
    __hv_mul_f(VIf(Bf6), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_TvRuAm6w, VOf(Bf5));
    __hv_rpole_f(&sRPole_xdDbEPUX, VIf(Bf4), VIf(Bf5), VOf(Bf5));
    __hv_sub_f(VIf(Bf5), VIf(Bf6), VOf(Bf5));
    __hv_fma_f(VIf(Bf5), VIf(Bf0), VIf(Bf6), VOf(Bf6));
    __hv_fma_f(VIf(Bf6), VIf(Bf3), VIf(Bf13), VOf(Bf13));
    __hv_add_f(VIf(Bf14), VIf(Bf13), VOf(Bf6));
    __hv_tabread_f(&sTabread_gZHpBzAs, VOf(Bf5));
    __hv_varread_f(&sVarf_GyyKHMIl, VOf(Bf4));
    __hv_mul_f(VIf(Bf5), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_grSayqOn, VOf(Bf8));
    __hv_rpole_f(&sRPole_EBUvXHUp, VIf(Bf4), VIf(Bf8), VOf(Bf8));
    __hv_sub_f(VIf(Bf8), VIf(Bf5), VOf(Bf8));
    __hv_fma_f(VIf(Bf8), VIf(Bf0), VIf(Bf5), VOf(Bf5));
    __hv_mul_f(VIf(Bf5), VIf(Bf3), VOf(Bf5));
    __hv_tabread_f(&sTabread_piljFgdR, VOf(Bf8));
    __hv_varread_f(&sVarf_t7Y9nR5L, VOf(Bf4));
    __hv_mul_f(VIf(Bf8), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_nhH1AUje, VOf(Bf9));
    __hv_rpole_f(&sRPole_yLCqpiyJ, VIf(Bf4), VIf(Bf9), VOf(Bf9));
    __hv_sub_f(VIf(Bf9), VIf(Bf8), VOf(Bf9));
    __hv_fma_f(VIf(Bf9), VIf(Bf0), VIf(Bf8), VOf(Bf8));
    __hv_mul_f(VIf(Bf8), VIf(Bf3), VOf(Bf3));
    __hv_add_f(VIf(Bf5), VIf(Bf3), VOf(Bf8));
    __hv_add_f(VIf(Bf6), VIf(Bf8), VOf(Bf0));
    __hv_tabwrite_f(&sTabwrite_IqaXUoUH, VIf(Bf0));
    __hv_sub_f(VIf(Bf14), VIf(Bf13), VOf(Bf0));
    __hv_sub_f(VIf(Bf5), VIf(Bf3), VOf(Bf9));
    __hv_add_f(VIf(Bf0), VIf(Bf9), VOf(Bf4));
    __hv_tabwrite_f(&sTabwrite_vCdB43tf, VIf(Bf4));
    __hv_sub_f(VIf(Bf6), VIf(Bf8), VOf(Bf8));
    __hv_tabwrite_f(&sTabwrite_rgXxbEN7, VIf(Bf8));
    __hv_sub_f(VIf(Bf0), VIf(Bf9), VOf(Bf9));
    __hv_tabwrite_f(&sTabwrite_INPjIsYP, VIf(Bf9));
    __hv_line_f(&sLine_Dm7v1JWx, VOf(Bf9));
    __hv_mul_f(VIf(Bf14), VIf(Bf9), VOf(Bf14));
    __hv_mul_f(VIf(Bf13), VIf(Bf9), VOf(Bf13));
    __hv_mul_f(VIf(Bf5), VIf(Bf9), VOf(Bf5));
    __hv_mul_f(VIf(Bf3), VIf(Bf9), VOf(Bf9));
    __hv_line_f(&sLine_mBKP8IzG, VOf(Bf9));
    __hv_mul_f(VIf(Bf2), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf5), 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f);
    __hv_mul_f(VIf(Bf9), VIf(Bf5), VOf(Bf5));
    __hv_tabwrite_f(&sTabwrite_mBOpqpai, VIf(Bf5));
    __hv_line_f(&sLine_pNzIvBl4, VOf(Bf9));
    __hv_phasor_f(&sPhasor_4sp13981, VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf3), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf9), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf0), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf3), VIf(Bf0), VOf(Bf0));
    __hv_floor_f(VIf(Bf0), VOf(Bf3));
    __hv_sub_f(VIf(Bf0), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf0), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf3), VIf(Bf0), VOf(Bf0));
    __hv_abs_f(VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf3), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf0), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf0), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf3), VIf(Bf0), VOf(Bf0));
    __hv_mul_f(VIf(Bf0), VIf(Bf0), VOf(Bf3));
    __hv_mul_f(VIf(Bf0), VIf(Bf3), VOf(Bf8));
    __hv_mul_f(VIf(Bf8), VIf(Bf3), VOf(Bf6));
    __hv_mul_f(VIf(Bf6), VIf(Bf3), VOf(Bf4));
    __hv_mul_f(VIf(Bf4), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf10), 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f);
    __hv_var_k_f(VOf(Bf12), 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f);
    __hv_var_k_f(VOf(Bf11), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf8), VIf(Bf11), VOf(Bf11));
    __hv_sub_f(VIf(Bf0), VIf(Bf11), VOf(Bf11));
    __hv_fma_f(VIf(Bf6), VIf(Bf12), VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf12), 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f);
    __hv_mul_f(VIf(Bf4), VIf(Bf12), VOf(Bf12));
    __hv_sub_f(VIf(Bf11), VIf(Bf12), VOf(Bf12));
    __hv_fma_f(VIf(Bf3), VIf(Bf10), VIf(Bf12), VOf(Bf12));
    __hv_line_f(&sLine_2pwa6h8r, VOf(Bf10));
    __hv_line_f(&sLine_txO1buxi, VOf(Bf3));
    __hv_fma_f(VIf(Bf9), VIf(Bf10), VIf(Bf3), VOf(Bf11));
    __hv_tabhead_f(&sTabhead_pieJMk3j, VOf(Bf4));
    __hv_var_k_f_r(VOf(Bf6), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf4), VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_mZ8IKVM3, VOf(Bf4));
    __hv_mul_f(VIf(Bf11), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_s6Oie7e9, VOf(Bf11));
    __hv_min_f(VIf(Bf4), VIf(Bf11), VOf(Bf11));
    __hv_zero_f(VOf(Bf4));
    __hv_max_f(VIf(Bf11), VIf(Bf4), VOf(Bf4));
    __hv_sub_f(VIf(Bf6), VIf(Bf4), VOf(Bf4));
    __hv_floor_f(VIf(Bf4), VOf(Bf6));
    __hv_varread_f(&sVarf_rsAhOaTe, VOf(Bf11));
    __hv_zero_f(VOf(Bf0));
    __hv_lt_f(VIf(Bf6), VIf(Bf0), VOf(Bf0));
    __hv_and_f(VIf(Bf11), VIf(Bf0), VOf(Bf0));
    __hv_add_f(VIf(Bf6), VIf(Bf0), VOf(Bf0));
    __hv_cast_fi(VIf(Bf0), VOi(Bi1));
    __hv_var_k_i(VOi(Bi0), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi1), VIi(Bi0), VOi(Bi0));
    __hv_tabread_if(&sTabread_1xNWoshy, VIi(Bi0), VOf(Bf0));
    __hv_tabread_if(&sTabread_V7wWabam, VIi(Bi1), VOf(Bf11));
    __hv_sub_f(VIf(Bf0), VIf(Bf11), VOf(Bf0));
    __hv_sub_f(VIf(Bf4), VIf(Bf6), VOf(Bf6));
    __hv_fma_f(VIf(Bf0), VIf(Bf6), VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf6), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_add_f(VIf(Bf9), VIf(Bf6), VOf(Bf6));
    __hv_floor_f(VIf(Bf6), VOf(Bf9));
    __hv_sub_f(VIf(Bf6), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf6), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf9), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf0), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf6), VIf(Bf0), VOf(Bf0));
    __hv_floor_f(VIf(Bf0), VOf(Bf6));
    __hv_sub_f(VIf(Bf0), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf0), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf6), VIf(Bf0), VOf(Bf0));
    __hv_abs_f(VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf6), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf0), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf0), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf6), VIf(Bf0), VOf(Bf0));
    __hv_mul_f(VIf(Bf0), VIf(Bf0), VOf(Bf6));
    __hv_mul_f(VIf(Bf0), VIf(Bf6), VOf(Bf4));
    __hv_mul_f(VIf(Bf4), VIf(Bf6), VOf(Bf8));
    __hv_mul_f(VIf(Bf8), VIf(Bf6), VOf(Bf15));
    __hv_mul_f(VIf(Bf15), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf16), 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f);
    __hv_var_k_f(VOf(Bf17), 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f);
    __hv_var_k_f(VOf(Bf18), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf4), VIf(Bf18), VOf(Bf18));
    __hv_sub_f(VIf(Bf0), VIf(Bf18), VOf(Bf18));
    __hv_fma_f(VIf(Bf8), VIf(Bf17), VIf(Bf18), VOf(Bf18));
    __hv_var_k_f(VOf(Bf17), 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f);
    __hv_mul_f(VIf(Bf15), VIf(Bf17), VOf(Bf17));
    __hv_sub_f(VIf(Bf18), VIf(Bf17), VOf(Bf17));
    __hv_fma_f(VIf(Bf6), VIf(Bf16), VIf(Bf17), VOf(Bf17));
    __hv_fma_f(VIf(Bf9), VIf(Bf10), VIf(Bf3), VOf(Bf3));
    __hv_tabhead_f(&sTabhead_5FhunfAy, VOf(Bf10));
    __hv_var_k_f_r(VOf(Bf9), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf10), VIf(Bf9), VOf(Bf9));
    __hv_varread_f(&sVarf_FuNqBcWG, VOf(Bf10));
    __hv_mul_f(VIf(Bf3), VIf(Bf10), VOf(Bf10));
    __hv_varread_f(&sVarf_vc7mgObN, VOf(Bf3));
    __hv_min_f(VIf(Bf10), VIf(Bf3), VOf(Bf3));
    __hv_zero_f(VOf(Bf10));
    __hv_max_f(VIf(Bf3), VIf(Bf10), VOf(Bf10));
    __hv_sub_f(VIf(Bf9), VIf(Bf10), VOf(Bf10));
    __hv_floor_f(VIf(Bf10), VOf(Bf9));
    __hv_varread_f(&sVarf_R0yv6RKX, VOf(Bf3));
    __hv_zero_f(VOf(Bf16));
    __hv_lt_f(VIf(Bf9), VIf(Bf16), VOf(Bf16));
    __hv_and_f(VIf(Bf3), VIf(Bf16), VOf(Bf16));
    __hv_add_f(VIf(Bf9), VIf(Bf16), VOf(Bf16));
    __hv_cast_fi(VIf(Bf16), VOi(Bi1));
    __hv_var_k_i(VOi(Bi0), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi1), VIi(Bi0), VOi(Bi0));
    __hv_tabread_if(&sTabread_zYoSW3Am, VIi(Bi0), VOf(Bf16));
    __hv_tabread_if(&sTabread_DGbMPWUr, VIi(Bi1), VOf(Bf3));
    __hv_sub_f(VIf(Bf16), VIf(Bf3), VOf(Bf16));
    __hv_sub_f(VIf(Bf10), VIf(Bf9), VOf(Bf9));
    __hv_fma_f(VIf(Bf16), VIf(Bf9), VIf(Bf3), VOf(Bf3));
    __hv_mul_f(VIf(Bf17), VIf(Bf3), VOf(Bf3));
    __hv_fma_f(VIf(Bf12), VIf(Bf11), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_qTGt7ieI, VOf(Bf11));
    __hv_tabhead_f(&sTabhead_VwavwnRe, VOf(Bf12));
    __hv_var_k_f_r(VOf(Bf17), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf12), VIf(Bf17), VOf(Bf17));
    __hv_varread_f(&sVarf_J7ubcf1q, VOf(Bf12));
    __hv_mul_f(VIf(Bf11), VIf(Bf12), VOf(Bf12));
    __hv_varread_f(&sVarf_0NHdwa0u, VOf(Bf11));
    __hv_min_f(VIf(Bf12), VIf(Bf11), VOf(Bf11));
    __hv_zero_f(VOf(Bf12));
    __hv_max_f(VIf(Bf11), VIf(Bf12), VOf(Bf12));
    __hv_sub_f(VIf(Bf17), VIf(Bf12), VOf(Bf12));
    __hv_floor_f(VIf(Bf12), VOf(Bf17));
    __hv_varread_f(&sVarf_ts9piLeS, VOf(Bf11));
    __hv_zero_f(VOf(Bf9));
    __hv_lt_f(VIf(Bf17), VIf(Bf9), VOf(Bf9));
    __hv_and_f(VIf(Bf11), VIf(Bf9), VOf(Bf9));
    __hv_add_f(VIf(Bf17), VIf(Bf9), VOf(Bf9));
    __hv_cast_fi(VIf(Bf9), VOi(Bi1));
    __hv_var_k_i(VOi(Bi0), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi1), VIi(Bi0), VOi(Bi0));
    __hv_tabread_if(&sTabread_wZmuTPIq, VIi(Bi0), VOf(Bf9));
    __hv_tabread_if(&sTabread_UhXcrMiE, VIi(Bi1), VOf(Bf11));
    __hv_sub_f(VIf(Bf9), VIf(Bf11), VOf(Bf9));
    __hv_sub_f(VIf(Bf12), VIf(Bf17), VOf(Bf17));
    __hv_fma_f(VIf(Bf9), VIf(Bf17), VIf(Bf11), VOf(Bf11));
    __hv_varread_f(&sVarf_6FyEoIpK, VOf(Bf17));
    __hv_rpole_f(&sRPole_VVbRVl4k, VIf(Bf11), VIf(Bf17), VOf(Bf17));
    __hv_var_k_f(VOf(Bf11), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_del1_f(&sDel1_jbqDqc8e, VIf(Bf17), VOf(Bf9));
    __hv_mul_f(VIf(Bf9), VIf(Bf11), VOf(Bf11));
    __hv_sub_f(VIf(Bf17), VIf(Bf11), VOf(Bf11));
    __hv_varread_f(&sVarf_0ro2gKY6, VOf(Bf17));
    __hv_mul_f(VIf(Bf11), VIf(Bf17), VOf(Bf17));
    __hv_varread_f(&sVarf_le8NBeiN, VOf(Bf11));
    __hv_mul_f(VIf(Bf17), VIf(Bf11), VOf(Bf11));
    __hv_add_f(VIf(Bf3), VIf(Bf11), VOf(Bf17));
    __hv_line_f(&sLine_xUxIeTT1, VOf(Bf9));
    __hv_varread_f(&sVarf_3He9rWm4, VOf(Bf12));
    __hv_mul_f(VIf(Bf11), VIf(Bf12), VOf(Bf12));
    __hv_varread_f(&sVarf_jglJru0z, VOf(Bf11));
    __hv_rpole_f(&sRPole_aCj21o4k, VIf(Bf12), VIf(Bf11), VOf(Bf11));
    __hv_fma_f(VIf(Bf3), VIf(Bf9), VIf(Bf11), VOf(Bf11));
    __hv_tabwrite_f(&sTabwrite_A8RyULfA, VIf(Bf11));
    __hv_add_f(VIf(Bf17), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_DooJ3X7R, VOf(Bf17));
    __hv_varread_f(&sVarf_q4lDNi3b, VOf(Bf11));
    __hv_mul_f(VIf(Bf17), VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf17), 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f);
    __hv_max_f(VIf(Bf11), VIf(Bf17), VOf(Bf17));
    __hv_varread_f(&sVarf_0GIWISEr, VOf(Bf11));
    __hv_min_f(VIf(Bf17), VIf(Bf11), VOf(Bf11));
    __hv_varread_f(&sVarf_OYbaVLUb, VOf(Bf9));
    __hv_mul_f(VIf(Bf11), VIf(Bf9), VOf(Bf9));
    __hv_mul_f(VIf(Bf5), VIf(Bf9), VOf(Bf5));
    __hv_varread_f(&sVarf_naCcrDP3, VOf(Bf11));
    __hv_mul_f(VIf(Bf5), VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf5), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_sub_f(VIf(Bf9), VIf(Bf5), VOf(Bf9));
    __hv_cos_f(VIf(Bf17), VOf(Bf17));
    __hv_mul_f(VIf(Bf9), VIf(Bf17), VOf(Bf3));
    __hv_mul_f(VIf(Bf17), VIf(Bf17), VOf(Bf17));
    __hv_sub_f(VIf(Bf5), VIf(Bf17), VOf(Bf17));
    __hv_zero_f(VOf(Bf5));
    __hv_gt_f(VIf(Bf17), VIf(Bf5), VOf(Bf5));
    __hv_sqrt_f(VIf(Bf17), VOf(Bf17));
    __hv_and_f(VIf(Bf5), VIf(Bf17), VOf(Bf17));
    __hv_mul_f(VIf(Bf9), VIf(Bf17), VOf(Bf17));
    __hv_cpole_f(&sCPole_gCtJVn8z, VIf(Bf11), VIf(ZERO), VIf(Bf3), VIf(Bf17), VOf(Bf17), VOf(Bf3));
    __hv_varread_f(&sVarf_xY3ipPOC, VOf(Bf3));
    __hv_mul_f(VIf(Bf17), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_VKAgcFB1, VOf(Bf17));
    __hv_rpole_f(&sRPole_5Ej1x3Nf, VIf(Bf3), VIf(Bf17), VOf(Bf17));
    __hv_varread_f(&sVarf_rhjM9usw, VOf(Bf3));
    __hv_mul_f(VIf(Bf17), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_42IxV9sU, VOf(Bf17));
    __hv_rpole_f(&sRPole_6UjMlbez, VIf(Bf3), VIf(Bf17), VOf(Bf17));
    __hv_varread_f(&sVarf_XYMdoB53, VOf(Bf3));
    __hv_mul_f(VIf(Bf17), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_6LGAkaPh, VOf(Bf17));
    __hv_rpole_f(&sRPole_yZIb4Lo3, VIf(Bf3), VIf(Bf17), VOf(Bf17));
    __hv_tabread_f(&sTabread_OIwQQ3dw, VOf(Bf3));
    __hv_varread_f(&sVarf_dWmr1V6v, VOf(Bf11));
    __hv_mul_f(VIf(Bf3), VIf(Bf11), VOf(Bf11));
    __hv_varread_f(&sVarf_HUDZZt7U, VOf(Bf9));
    __hv_rpole_f(&sRPole_iTiV8VDs, VIf(Bf11), VIf(Bf9), VOf(Bf9));
    __hv_sub_f(VIf(Bf9), VIf(Bf3), VOf(Bf9));
    __hv_line_f(&sLine_VFA3AXed, VOf(Bf11));
    __hv_fma_f(VIf(Bf9), VIf(Bf11), VIf(Bf3), VOf(Bf3));
    __hv_line_f(&sLine_zLBDCZPF, VOf(Bf9));
    __hv_tabread_f(&sTabread_gukZNESn, VOf(Bf5));
    __hv_add_f(VIf(Bf17), VIf(Bf5), VOf(Bf12));
    __hv_tabread_f(&sTabread_mKGscUIs, VOf(Bf16));
    __hv_add_f(VIf(Bf12), VIf(Bf16), VOf(Bf10));
    __hv_tabread_f(&sTabread_CIoSnsxn, VOf(Bf6));
    __hv_add_f(VIf(Bf10), VIf(Bf6), VOf(Bf18));
    __hv_tabread_f(&sTabread_tvRNOEqN, VOf(Bf15));
    __hv_add_f(VIf(Bf18), VIf(Bf15), VOf(Bf8));
    __hv_tabread_f(&sTabread_jxb9fImF, VOf(Bf0));
    __hv_sub_f(VIf(Bf8), VIf(Bf0), VOf(Bf4));
    __hv_tabwrite_f(&sTabwrite_CQI1TuKu, VIf(Bf4));
    __hv_sub_f(VIf(Bf18), VIf(Bf15), VOf(Bf15));
    __hv_tabwrite_f(&sTabwrite_c3IJh3wS, VIf(Bf15));
    __hv_sub_f(VIf(Bf10), VIf(Bf6), VOf(Bf6));
    __hv_tabwrite_f(&sTabwrite_GQeBmJcI, VIf(Bf6));
    __hv_sub_f(VIf(Bf12), VIf(Bf16), VOf(Bf16));
    __hv_tabwrite_f(&sTabwrite_vx2e8AGE, VIf(Bf16));
    __hv_sub_f(VIf(Bf17), VIf(Bf5), VOf(Bf5));
    __hv_tabwrite_f(&sTabwrite_5aCN7SnC, VIf(Bf5));
    __hv_tabwrite_f(&sTabwrite_VhBxg0Z2, VIf(Bf17));
    __hv_add_f(VIf(Bf8), VIf(Bf0), VOf(Bf0));
    __hv_tabread_f(&sTabread_8kp3W93J, VOf(Bf8));
    __hv_fma_f(VIf(Bf3), VIf(Bf9), VIf(Bf0), VOf(Bf0));
    __hv_tabread_f(&sTabread_jeL93fIW, VOf(Bf3));
    __hv_varread_f(&sVarf_umxtjKmp, VOf(Bf5));
    __hv_mul_f(VIf(Bf3), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_4kqT8FwB, VOf(Bf16));
    __hv_rpole_f(&sRPole_iCXdsLGN, VIf(Bf5), VIf(Bf16), VOf(Bf16));
    __hv_sub_f(VIf(Bf16), VIf(Bf3), VOf(Bf16));
    __hv_fma_f(VIf(Bf16), VIf(Bf11), VIf(Bf3), VOf(Bf3));
    __hv_fma_f(VIf(Bf3), VIf(Bf9), VIf(Bf8), VOf(Bf8));
    __hv_add_f(VIf(Bf0), VIf(Bf8), VOf(Bf3));
    __hv_tabread_f(&sTabread_wMzD5ysK, VOf(Bf16));
    __hv_varread_f(&sVarf_nTtCLfpd, VOf(Bf5));
    __hv_mul_f(VIf(Bf16), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_aDMvFOc4, VOf(Bf12));
    __hv_rpole_f(&sRPole_OYRK8Iyg, VIf(Bf5), VIf(Bf12), VOf(Bf12));
    __hv_sub_f(VIf(Bf12), VIf(Bf16), VOf(Bf12));
    __hv_fma_f(VIf(Bf12), VIf(Bf11), VIf(Bf16), VOf(Bf16));
    __hv_mul_f(VIf(Bf16), VIf(Bf9), VOf(Bf16));
    __hv_tabread_f(&sTabread_JeA8qHeQ, VOf(Bf12));
    __hv_varread_f(&sVarf_TQmuGjOM, VOf(Bf5));
    __hv_mul_f(VIf(Bf12), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_IOQX6Vkx, VOf(Bf6));
    __hv_rpole_f(&sRPole_tPnNZ60H, VIf(Bf5), VIf(Bf6), VOf(Bf6));
    __hv_sub_f(VIf(Bf6), VIf(Bf12), VOf(Bf6));
    __hv_fma_f(VIf(Bf6), VIf(Bf11), VIf(Bf12), VOf(Bf12));
    __hv_mul_f(VIf(Bf12), VIf(Bf9), VOf(Bf9));
    __hv_add_f(VIf(Bf16), VIf(Bf9), VOf(Bf12));
    __hv_add_f(VIf(Bf3), VIf(Bf12), VOf(Bf11));
    __hv_tabwrite_f(&sTabwrite_YwUS7cjj, VIf(Bf11));
    __hv_sub_f(VIf(Bf0), VIf(Bf8), VOf(Bf11));
    __hv_sub_f(VIf(Bf16), VIf(Bf9), VOf(Bf6));
    __hv_add_f(VIf(Bf11), VIf(Bf6), VOf(Bf5));
    __hv_tabwrite_f(&sTabwrite_b7qgbpFi, VIf(Bf5));
    __hv_sub_f(VIf(Bf3), VIf(Bf12), VOf(Bf12));
    __hv_tabwrite_f(&sTabwrite_B5qVsWWH, VIf(Bf12));
    __hv_sub_f(VIf(Bf11), VIf(Bf6), VOf(Bf6));
    __hv_tabwrite_f(&sTabwrite_QO4KkM4X, VIf(Bf6));
    __hv_line_f(&sLine_sx57kZpT, VOf(Bf6));
    __hv_mul_f(VIf(Bf0), VIf(Bf6), VOf(Bf0));
    __hv_mul_f(VIf(Bf8), VIf(Bf6), VOf(Bf8));
    __hv_mul_f(VIf(Bf16), VIf(Bf6), VOf(Bf16));
    __hv_mul_f(VIf(Bf9), VIf(Bf6), VOf(Bf6));
    __hv_add_f(VIf(Bf17), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf17), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf0), VIf(Bf17), VOf(Bf17));
    __hv_add_f(VIf(Bf14), VIf(Bf17), VOf(Bf14));
    __hv_line_f(&sLine_gAF7LBmc, VOf(Bf0));
    __hv_mul_f(VIf(Bf2), VIf(Bf0), VOf(Bf0));
    __hv_tabwrite_f(&sTabwrite_FmCqbKUF, VIf(Bf0));
    __hv_line_f(&sLine_8e8ExncG, VOf(Bf0));
    __hv_phasor_f(&sPhasor_vBCtyhJ5, VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf2), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf0), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf6), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf2), VIf(Bf6), VOf(Bf6));
    __hv_floor_f(VIf(Bf6), VOf(Bf2));
    __hv_sub_f(VIf(Bf6), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf6), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf2), VIf(Bf6), VOf(Bf6));
    __hv_abs_f(VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf2), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf6), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf6), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf2), VIf(Bf6), VOf(Bf6));
    __hv_mul_f(VIf(Bf6), VIf(Bf6), VOf(Bf2));
    __hv_mul_f(VIf(Bf6), VIf(Bf2), VOf(Bf16));
    __hv_mul_f(VIf(Bf16), VIf(Bf2), VOf(Bf8));
    __hv_mul_f(VIf(Bf8), VIf(Bf2), VOf(Bf9));
    __hv_mul_f(VIf(Bf9), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf11), 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f);
    __hv_var_k_f(VOf(Bf12), 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f);
    __hv_var_k_f(VOf(Bf3), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf16), VIf(Bf3), VOf(Bf3));
    __hv_sub_f(VIf(Bf6), VIf(Bf3), VOf(Bf3));
    __hv_fma_f(VIf(Bf8), VIf(Bf12), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf12), 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f);
    __hv_mul_f(VIf(Bf9), VIf(Bf12), VOf(Bf12));
    __hv_sub_f(VIf(Bf3), VIf(Bf12), VOf(Bf12));
    __hv_fma_f(VIf(Bf2), VIf(Bf11), VIf(Bf12), VOf(Bf12));
    __hv_line_f(&sLine_3qmmioih, VOf(Bf11));
    __hv_line_f(&sLine_1y3L0Pq6, VOf(Bf2));
    __hv_fma_f(VIf(Bf0), VIf(Bf11), VIf(Bf2), VOf(Bf3));
    __hv_tabhead_f(&sTabhead_t6cLCSzm, VOf(Bf9));
    __hv_var_k_f_r(VOf(Bf8), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf9), VIf(Bf8), VOf(Bf8));
    __hv_varread_f(&sVarf_QzoTxFn1, VOf(Bf9));
    __hv_mul_f(VIf(Bf3), VIf(Bf9), VOf(Bf9));
    __hv_varread_f(&sVarf_TvuZAr7q, VOf(Bf3));
    __hv_min_f(VIf(Bf9), VIf(Bf3), VOf(Bf3));
    __hv_zero_f(VOf(Bf9));
    __hv_max_f(VIf(Bf3), VIf(Bf9), VOf(Bf9));
    __hv_sub_f(VIf(Bf8), VIf(Bf9), VOf(Bf9));
    __hv_floor_f(VIf(Bf9), VOf(Bf8));
    __hv_varread_f(&sVarf_kBeeHRFJ, VOf(Bf3));
    __hv_zero_f(VOf(Bf6));
    __hv_lt_f(VIf(Bf8), VIf(Bf6), VOf(Bf6));
    __hv_and_f(VIf(Bf3), VIf(Bf6), VOf(Bf6));
    __hv_add_f(VIf(Bf8), VIf(Bf6), VOf(Bf6));
    __hv_cast_fi(VIf(Bf6), VOi(Bi1));
    __hv_var_k_i(VOi(Bi0), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi1), VIi(Bi0), VOi(Bi0));
    __hv_tabread_if(&sTabread_6pVlLsJ5, VIi(Bi0), VOf(Bf6));
    __hv_tabread_if(&sTabread_vkfiQeHh, VIi(Bi1), VOf(Bf3));
    __hv_sub_f(VIf(Bf6), VIf(Bf3), VOf(Bf6));
    __hv_sub_f(VIf(Bf9), VIf(Bf8), VOf(Bf8));
    __hv_fma_f(VIf(Bf6), VIf(Bf8), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf8), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_add_f(VIf(Bf0), VIf(Bf8), VOf(Bf8));
    __hv_floor_f(VIf(Bf8), VOf(Bf0));
    __hv_sub_f(VIf(Bf8), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf8), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf0), VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf6), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf8), VIf(Bf6), VOf(Bf6));
    __hv_floor_f(VIf(Bf6), VOf(Bf8));
    __hv_sub_f(VIf(Bf6), VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf6), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf8), VIf(Bf6), VOf(Bf6));
    __hv_abs_f(VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf8), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf6), VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf6), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf8), VIf(Bf6), VOf(Bf6));
    __hv_mul_f(VIf(Bf6), VIf(Bf6), VOf(Bf8));
    __hv_mul_f(VIf(Bf6), VIf(Bf8), VOf(Bf9));
    __hv_mul_f(VIf(Bf9), VIf(Bf8), VOf(Bf16));
    __hv_mul_f(VIf(Bf16), VIf(Bf8), VOf(Bf5));
    __hv_mul_f(VIf(Bf5), VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf10), 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f);
    __hv_var_k_f(VOf(Bf15), 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f);
    __hv_var_k_f(VOf(Bf18), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf9), VIf(Bf18), VOf(Bf18));
    __hv_sub_f(VIf(Bf6), VIf(Bf18), VOf(Bf18));
    __hv_fma_f(VIf(Bf16), VIf(Bf15), VIf(Bf18), VOf(Bf18));
    __hv_var_k_f(VOf(Bf15), 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f);
    __hv_mul_f(VIf(Bf5), VIf(Bf15), VOf(Bf15));
    __hv_sub_f(VIf(Bf18), VIf(Bf15), VOf(Bf15));
    __hv_fma_f(VIf(Bf8), VIf(Bf10), VIf(Bf15), VOf(Bf15));
    __hv_fma_f(VIf(Bf0), VIf(Bf11), VIf(Bf2), VOf(Bf2));
    __hv_tabhead_f(&sTabhead_uGnMe1Qx, VOf(Bf11));
    __hv_var_k_f_r(VOf(Bf0), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf11), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_4oenKeRe, VOf(Bf11));
    __hv_mul_f(VIf(Bf2), VIf(Bf11), VOf(Bf11));
    __hv_varread_f(&sVarf_KDd8cxnP, VOf(Bf2));
    __hv_min_f(VIf(Bf11), VIf(Bf2), VOf(Bf2));
    __hv_zero_f(VOf(Bf11));
    __hv_max_f(VIf(Bf2), VIf(Bf11), VOf(Bf11));
    __hv_sub_f(VIf(Bf0), VIf(Bf11), VOf(Bf11));
    __hv_floor_f(VIf(Bf11), VOf(Bf0));
    __hv_varread_f(&sVarf_ZUGw0L1t, VOf(Bf2));
    __hv_zero_f(VOf(Bf10));
    __hv_lt_f(VIf(Bf0), VIf(Bf10), VOf(Bf10));
    __hv_and_f(VIf(Bf2), VIf(Bf10), VOf(Bf10));
    __hv_add_f(VIf(Bf0), VIf(Bf10), VOf(Bf10));
    __hv_cast_fi(VIf(Bf10), VOi(Bi1));
    __hv_var_k_i(VOi(Bi0), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi1), VIi(Bi0), VOi(Bi0));
    __hv_tabread_if(&sTabread_DOrFKgN0, VIi(Bi0), VOf(Bf10));
    __hv_tabread_if(&sTabread_Q1yDLO8h, VIi(Bi1), VOf(Bf2));
    __hv_sub_f(VIf(Bf10), VIf(Bf2), VOf(Bf10));
    __hv_sub_f(VIf(Bf11), VIf(Bf0), VOf(Bf0));
    __hv_fma_f(VIf(Bf10), VIf(Bf0), VIf(Bf2), VOf(Bf2));
    __hv_mul_f(VIf(Bf15), VIf(Bf2), VOf(Bf2));
    __hv_fma_f(VIf(Bf12), VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_sCMes5G2, VOf(Bf3));
    __hv_tabhead_f(&sTabhead_lMHjt8tV, VOf(Bf12));
    __hv_var_k_f_r(VOf(Bf15), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf12), VIf(Bf15), VOf(Bf15));
    __hv_varread_f(&sVarf_NkKeq4SG, VOf(Bf12));
    __hv_mul_f(VIf(Bf3), VIf(Bf12), VOf(Bf12));
    __hv_varread_f(&sVarf_9Jh147To, VOf(Bf3));
    __hv_min_f(VIf(Bf12), VIf(Bf3), VOf(Bf3));
    __hv_zero_f(VOf(Bf12));
    __hv_max_f(VIf(Bf3), VIf(Bf12), VOf(Bf12));
    __hv_sub_f(VIf(Bf15), VIf(Bf12), VOf(Bf12));
    __hv_floor_f(VIf(Bf12), VOf(Bf15));
    __hv_varread_f(&sVarf_n6ffOqUb, VOf(Bf3));
    __hv_zero_f(VOf(Bf0));
    __hv_lt_f(VIf(Bf15), VIf(Bf0), VOf(Bf0));
    __hv_and_f(VIf(Bf3), VIf(Bf0), VOf(Bf0));
    __hv_add_f(VIf(Bf15), VIf(Bf0), VOf(Bf0));
    __hv_cast_fi(VIf(Bf0), VOi(Bi1));
    __hv_var_k_i(VOi(Bi0), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi1), VIi(Bi0), VOi(Bi0));
    __hv_tabread_if(&sTabread_pBz64i4z, VIi(Bi0), VOf(Bf0));
    __hv_tabread_if(&sTabread_4ZpF1ZQS, VIi(Bi1), VOf(Bf3));
    __hv_sub_f(VIf(Bf0), VIf(Bf3), VOf(Bf0));
    __hv_sub_f(VIf(Bf12), VIf(Bf15), VOf(Bf15));
    __hv_fma_f(VIf(Bf0), VIf(Bf15), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_W1ALPYvw, VOf(Bf15));
    __hv_rpole_f(&sRPole_EXNlqRDk, VIf(Bf3), VIf(Bf15), VOf(Bf15));
    __hv_var_k_f(VOf(Bf3), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_del1_f(&sDel1_16leHbnf, VIf(Bf15), VOf(Bf0));
    __hv_mul_f(VIf(Bf0), VIf(Bf3), VOf(Bf3));
    __hv_sub_f(VIf(Bf15), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_OQxFUwWU, VOf(Bf15));
    __hv_mul_f(VIf(Bf3), VIf(Bf15), VOf(Bf15));
    __hv_varread_f(&sVarf_nWHFzWDP, VOf(Bf3));
    __hv_mul_f(VIf(Bf15), VIf(Bf3), VOf(Bf3));
    __hv_add_f(VIf(Bf2), VIf(Bf3), VOf(Bf15));
    __hv_line_f(&sLine_0AJz5Y1w, VOf(Bf0));
    __hv_varread_f(&sVarf_YoVv5H5i, VOf(Bf12));
    __hv_mul_f(VIf(Bf3), VIf(Bf12), VOf(Bf12));
    __hv_varread_f(&sVarf_J7Mm7ASH, VOf(Bf3));
    __hv_rpole_f(&sRPole_c9WrJ54V, VIf(Bf12), VIf(Bf3), VOf(Bf3));
    __hv_fma_f(VIf(Bf2), VIf(Bf0), VIf(Bf3), VOf(Bf3));
    __hv_tabwrite_f(&sTabwrite_mBAjwpGT, VIf(Bf3));
    __hv_var_k_f(VOf(Bf3), 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f);
    __hv_mul_f(VIf(Bf15), VIf(Bf3), VOf(Bf3));
    __hv_add_f(VIf(Bf14), VIf(Bf3), VOf(Bf14));
    __hv_add_f(VIf(Bf13), VIf(Bf17), VOf(Bf17));
    __hv_add_f(VIf(Bf17), VIf(Bf3), VOf(Bf3));
    __hv_line_f(&sLine_5izOkr9E, VOf(Bf17));
    __hv_mul_f(VIf(Bf14), VIf(Bf17), VOf(Bf14));
    __hv_mul_f(VIf(Bf3), VIf(Bf17), VOf(Bf17));
    __hv_add_f(VIf(Bf7), VIf(Bf14), VOf(Bf14));
    __hv_add_f(VIf(Bf1), VIf(Bf17), VOf(Bf17));
    __hv_line_f(&sLine_LkKfPvRR, VOf(Bf1));
    __hv_mul_f(VIf(Bf14), VIf(Bf1), VOf(Bf14));
    __hv_mul_f(VIf(Bf17), VIf(Bf1), VOf(Bf1));
    __hv_add_f(VIf(Bf1), VIf(O1), VOf(O1));
    __hv_add_f(VIf(Bf14), VIf(O0), VOf(O0));

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

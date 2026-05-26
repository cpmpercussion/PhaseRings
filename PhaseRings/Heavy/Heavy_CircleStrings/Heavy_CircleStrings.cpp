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
  numBytes += sTabread_init(&sTabread_Zg8sDcKY, &hTable_f2MY0Eli, true);
  numBytes += sRPole_init(&sRPole_mGrNxlqr);
  numBytes += sLine_init(&sLine_Hbf64OgS);
  numBytes += sTabwrite_init(&sTabwrite_6JpljZfs, &hTable_f2MY0Eli);
  numBytes += sLine_init(&sLine_LWWCwcju);
  numBytes += sLine_init(&sLine_E22viBkU);
  numBytes += sLine_init(&sLine_BCylCxST);
  numBytes += sPhasor_k_init(&sPhasor_U4Qsnyii, 0.0f, sampleRate);
  numBytes += sLine_init(&sLine_OKfHXmaS);
  numBytes += sTabread_init(&sTabread_68eizEgF, &hTable_09wS09Ef, true);
  numBytes += sRPole_init(&sRPole_RHysYMoR);
  numBytes += sLine_init(&sLine_RcOn8tR1);
  numBytes += sTabwrite_init(&sTabwrite_I9x9JcTu, &hTable_09wS09Ef);
  numBytes += sLine_init(&sLine_ZATZCSqw);
  numBytes += sLine_init(&sLine_CFJMbUzK);
  numBytes += sLine_init(&sLine_RYeyrni5);
  numBytes += sPhasor_k_init(&sPhasor_TnAQtKCp, 0.0f, sampleRate);
  numBytes += sLine_init(&sLine_A9nxHXLL);
  numBytes += sTabread_init(&sTabread_yHs0GT09, &hTable_xRdA4qp0, true);
  numBytes += sRPole_init(&sRPole_nY8Dm5cA);
  numBytes += sLine_init(&sLine_6k24F53H);
  numBytes += sTabwrite_init(&sTabwrite_o5PUcACM, &hTable_xRdA4qp0);
  numBytes += sLine_init(&sLine_rnfc601c);
  numBytes += sLine_init(&sLine_CLdEiIdZ);
  numBytes += sLine_init(&sLine_OoVkWdWH);
  numBytes += sPhasor_k_init(&sPhasor_fNoS14U3, 0.0f, sampleRate);
  numBytes += sLine_init(&sLine_whQbWXMV);
  numBytes += sTabread_init(&sTabread_qmKzqtG1, &hTable_c60lHUpc, true);
  numBytes += sRPole_init(&sRPole_b8Ae99gM);
  numBytes += sLine_init(&sLine_Uwdduvwe);
  numBytes += sTabwrite_init(&sTabwrite_I0CXtZeH, &hTable_c60lHUpc);
  numBytes += sLine_init(&sLine_Ejidq5xI);
  numBytes += sLine_init(&sLine_CPLwMQlZ);
  numBytes += sLine_init(&sLine_owtRzKrP);
  numBytes += sPhasor_k_init(&sPhasor_vxBYdwZj, 0.0f, sampleRate);
  numBytes += sLine_init(&sLine_Uu2HTcOD);
  numBytes += sLine_init(&sLine_1PW1Q8Bq);
  numBytes += sTabread_init(&sTabread_oYmmQCpE, &hTable_L6MOTeCE, true);
  numBytes += sRPole_init(&sRPole_CXyafDI3);
  numBytes += sLine_init(&sLine_Dra3dAfS);
  numBytes += sTabwrite_init(&sTabwrite_gx6f2ZZ0, &hTable_L6MOTeCE);
  numBytes += sLine_init(&sLine_wVRBvxvx);
  numBytes += sLine_init(&sLine_E7rN8JNU);
  numBytes += sRPole_init(&sRPole_BHQx0pEj);
  numBytes += sDel1_init(&sDel1_a8TLSseJ);
  numBytes += sLine_init(&sLine_cGEIGLun);
  numBytes += sLine_init(&sLine_tV4FpGzc);
  numBytes += sLine_init(&sLine_3OZgPisP);
  numBytes += sTabread_init(&sTabread_ywcjT7su, &hTable_VjGitjUm, true);
  numBytes += sRPole_init(&sRPole_xADaUC4F);
  numBytes += sLine_init(&sLine_SWhbiqr5);
  numBytes += sLine_init(&sLine_6bwWLUBX);
  numBytes += sTabread_init(&sTabread_B79On196, &hTable_mxTyjspJ, true);
  numBytes += sTabread_init(&sTabread_2qIgAhN0, &hTable_Shq5AKqO, true);
  numBytes += sTabread_init(&sTabread_nHNLlL2V, &hTable_2kfZz5Sk, true);
  numBytes += sTabread_init(&sTabread_kfbBBM5d, &hTable_x9dQjkz4, true);
  numBytes += sTabread_init(&sTabread_TirDdr2E, &hTable_pTOltC5v, true);
  numBytes += sTabwrite_init(&sTabwrite_RhGEUY4H, &hTable_8zkdx3Ry);
  numBytes += sTabwrite_init(&sTabwrite_kHoR6950, &hTable_pTOltC5v);
  numBytes += sTabwrite_init(&sTabwrite_ejTtB6aH, &hTable_x9dQjkz4);
  numBytes += sTabwrite_init(&sTabwrite_G96thh7P, &hTable_2kfZz5Sk);
  numBytes += sTabwrite_init(&sTabwrite_8vTQ81nk, &hTable_Shq5AKqO);
  numBytes += sTabwrite_init(&sTabwrite_EWFzdDQF, &hTable_mxTyjspJ);
  numBytes += sTabread_init(&sTabread_mdnOTK7O, &hTable_8zkdx3Ry, true);
  numBytes += sTabread_init(&sTabread_qX2EGmbw, &hTable_1yNlBKZm, true);
  numBytes += sRPole_init(&sRPole_X5ribujV);
  numBytes += sTabread_init(&sTabread_yxeMnGOd, &hTable_Vl89S9S8, true);
  numBytes += sRPole_init(&sRPole_AsB1MFAv);
  numBytes += sTabread_init(&sTabread_0FARaxkz, &hTable_tGr4wwQI, true);
  numBytes += sRPole_init(&sRPole_NwvidYT1);
  numBytes += sTabwrite_init(&sTabwrite_Mq1Sp84A, &hTable_VjGitjUm);
  numBytes += sTabwrite_init(&sTabwrite_sSh6lvI0, &hTable_1yNlBKZm);
  numBytes += sTabwrite_init(&sTabwrite_Lp38jFK6, &hTable_Vl89S9S8);
  numBytes += sTabwrite_init(&sTabwrite_uClPPI22, &hTable_tGr4wwQI);
  numBytes += sLine_init(&sLine_uzqrU8zH);
  numBytes += sLine_init(&sLine_lGbUqyqN);
  numBytes += sTabwrite_init(&sTabwrite_E1m7FFOE, &hTable_bBdX6WS1);
  numBytes += sLine_init(&sLine_w9JQDaIN);
  numBytes += sPhasor_init(&sPhasor_X2Jws0fR, sampleRate);
  numBytes += sLine_init(&sLine_dC2qmDFS);
  numBytes += sLine_init(&sLine_3AWksRZ0);
  numBytes += sTabhead_init(&sTabhead_98jkAo1F, &hTable_bBdX6WS1);
  numBytes += sTabread_init(&sTabread_0yZQbMrl, &hTable_bBdX6WS1, false);
  numBytes += sTabread_init(&sTabread_OfVT6Kmr, &hTable_bBdX6WS1, false);
  numBytes += sTabhead_init(&sTabhead_mvVfn1bj, &hTable_bBdX6WS1);
  numBytes += sTabread_init(&sTabread_SQVOCRmR, &hTable_bBdX6WS1, false);
  numBytes += sTabread_init(&sTabread_6nrkYXVm, &hTable_bBdX6WS1, false);
  numBytes += sTabhead_init(&sTabhead_10DWziux, &hTable_r3uhFRAO);
  numBytes += sTabread_init(&sTabread_mCqCtznq, &hTable_r3uhFRAO, false);
  numBytes += sTabread_init(&sTabread_P4Efx2P1, &hTable_r3uhFRAO, false);
  numBytes += sRPole_init(&sRPole_NG0fD60I);
  numBytes += sDel1_init(&sDel1_fLFg5rev);
  numBytes += sLine_init(&sLine_socRXfBC);
  numBytes += sRPole_init(&sRPole_hvXBxnvu);
  numBytes += sTabwrite_init(&sTabwrite_HgqY4tum, &hTable_r3uhFRAO);
  numBytes += sCPole_init(&sCPole_r4f1lZ1Z);
  numBytes += sRPole_init(&sRPole_kL1C0jMu);
  numBytes += sRPole_init(&sRPole_u7jgWGsV);
  numBytes += sRPole_init(&sRPole_T1gRgzlZ);
  numBytes += sTabread_init(&sTabread_BMVI4rfq, &hTable_tfHJlVqH, true);
  numBytes += sRPole_init(&sRPole_ngV7xBHX);
  numBytes += sLine_init(&sLine_WI5IkPof);
  numBytes += sLine_init(&sLine_5aVZ062v);
  numBytes += sTabread_init(&sTabread_IUZVy1z9, &hTable_UT8gYIoQ, true);
  numBytes += sTabread_init(&sTabread_F0xS8TOw, &hTable_2gfCxAKy, true);
  numBytes += sTabread_init(&sTabread_fGWXKbAe, &hTable_X7MOLq8C, true);
  numBytes += sTabread_init(&sTabread_3jtdNVgY, &hTable_6sSB7Hy6, true);
  numBytes += sTabread_init(&sTabread_fOeppglu, &hTable_KaldRfq7, true);
  numBytes += sTabwrite_init(&sTabwrite_tCOQ2ItD, &hTable_KGTj6IPY);
  numBytes += sTabwrite_init(&sTabwrite_vglPAOff, &hTable_KaldRfq7);
  numBytes += sTabwrite_init(&sTabwrite_BIcl6Py6, &hTable_6sSB7Hy6);
  numBytes += sTabwrite_init(&sTabwrite_7Xefv0Vw, &hTable_X7MOLq8C);
  numBytes += sTabwrite_init(&sTabwrite_U60LhyMp, &hTable_2gfCxAKy);
  numBytes += sTabwrite_init(&sTabwrite_9zWFmF8i, &hTable_UT8gYIoQ);
  numBytes += sTabread_init(&sTabread_vX2N3qtx, &hTable_KGTj6IPY, true);
  numBytes += sTabread_init(&sTabread_sCx6s3vi, &hTable_s05kBe0N, true);
  numBytes += sRPole_init(&sRPole_PKUqbWGf);
  numBytes += sTabread_init(&sTabread_0eJsMEEd, &hTable_dAH5iQND, true);
  numBytes += sRPole_init(&sRPole_NVrdmnbq);
  numBytes += sTabread_init(&sTabread_Om1xZlX2, &hTable_rxv0WHA4, true);
  numBytes += sRPole_init(&sRPole_fzJ36fZA);
  numBytes += sTabwrite_init(&sTabwrite_tHqeJ7HG, &hTable_tfHJlVqH);
  numBytes += sTabwrite_init(&sTabwrite_onLuFq4X, &hTable_s05kBe0N);
  numBytes += sTabwrite_init(&sTabwrite_iiXtjGK3, &hTable_dAH5iQND);
  numBytes += sTabwrite_init(&sTabwrite_MUpFJI2Y, &hTable_rxv0WHA4);
  numBytes += sLine_init(&sLine_bCgciRWS);
  numBytes += sLine_init(&sLine_HGNNrImW);
  numBytes += sTabwrite_init(&sTabwrite_NQBcNdSe, &hTable_Hi9yYgYc);
  numBytes += sLine_init(&sLine_mrEpoKCx);
  numBytes += sPhasor_init(&sPhasor_01Q83644, sampleRate);
  numBytes += sLine_init(&sLine_stjxvo35);
  numBytes += sLine_init(&sLine_S2udaKf5);
  numBytes += sTabhead_init(&sTabhead_gSR2X83P, &hTable_Hi9yYgYc);
  numBytes += sTabread_init(&sTabread_TfUhR3Td, &hTable_Hi9yYgYc, false);
  numBytes += sTabread_init(&sTabread_fQHzVTKa, &hTable_Hi9yYgYc, false);
  numBytes += sTabhead_init(&sTabhead_suWTolvU, &hTable_Hi9yYgYc);
  numBytes += sTabread_init(&sTabread_552Pmcbl, &hTable_Hi9yYgYc, false);
  numBytes += sTabread_init(&sTabread_zAAjWPdt, &hTable_Hi9yYgYc, false);
  numBytes += sTabhead_init(&sTabhead_K2HXcIpX, &hTable_ljdEM2pb);
  numBytes += sTabread_init(&sTabread_JPrDPGAi, &hTable_ljdEM2pb, false);
  numBytes += sTabread_init(&sTabread_CzU2165J, &hTable_ljdEM2pb, false);
  numBytes += sRPole_init(&sRPole_sl6K3zV6);
  numBytes += sDel1_init(&sDel1_kDCA1D00);
  numBytes += sLine_init(&sLine_89rTH9lR);
  numBytes += sRPole_init(&sRPole_gnHAEfB0);
  numBytes += sTabwrite_init(&sTabwrite_sjhaynXz, &hTable_ljdEM2pb);
  numBytes += sLine_init(&sLine_RtwkKZ3Y);
  numBytes += sLine_init(&sLine_qkpQNjIv);
  numBytes += cSlice_init(&cSlice_WHLC3370, 2, 1);
  numBytes += cSlice_init(&cSlice_cSd8zlmu, 1, 1);
  numBytes += cSlice_init(&cSlice_OcDc4dL4, 0, 1);
  numBytes += cVar_init_f(&cVar_ZDzcTu3w, 0.0f);
  numBytes += cIf_init(&cIf_PEbysWy5, false);
  numBytes += cIf_init(&cIf_KuyP4YvJ, false);
  numBytes += cIf_init(&cIf_GqBQqr3O, false);
  numBytes += cIf_init(&cIf_HDjUjixc, false);
  numBytes += cIf_init(&cIf_udFYo8iR, false);
  numBytes += cBinop_init(&cBinop_ZjiYq2Gm, 0.0f); // __eq
  numBytes += cTabhead_init(&cTabhead_bFxfaTiX, &hTable_VjGitjUm);
  numBytes += cVar_init_s(&cVar_wV0HlpNw, "del-1011-del1");
  numBytes += cDelay_init(this, &cDelay_pUrrykqG, 58.6435f);
  numBytes += cDelay_init(this, &cDelay_VNOwLfDV, 0.0f);
  numBytes += cBinop_init(&cBinop_KNnwZi9v, 58.6435f); // __mul
  numBytes += cBinop_init(&cBinop_MHvsctNC, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_qkkxpdc4, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_8hxM4aG7, 0.0f); // __sub
  numBytes += cTabhead_init(&cTabhead_MdMvcFss, &hTable_1yNlBKZm);
  numBytes += cVar_init_s(&cVar_OvLKxvPA, "del-1011-del2");
  numBytes += cDelay_init(this, &cDelay_TXWJF1Ym, 69.4325f);
  numBytes += cDelay_init(this, &cDelay_L0cOh9fz, 0.0f);
  numBytes += cBinop_init(&cBinop_KDfPwFor, 69.4325f); // __mul
  numBytes += cBinop_init(&cBinop_07moxoSM, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_76Q9a3Ad, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_3XVsNNIz, 0.0f); // __sub
  numBytes += cTabhead_init(&cTabhead_VrnFMHJK, &hTable_Vl89S9S8);
  numBytes += cVar_init_s(&cVar_4PwUZG4n, "del-1011-del3");
  numBytes += cDelay_init(this, &cDelay_wIT86wHE, 74.5234f);
  numBytes += cDelay_init(this, &cDelay_5LEJsLlD, 0.0f);
  numBytes += cBinop_init(&cBinop_qzlTyR8u, 74.5234f); // __mul
  numBytes += cBinop_init(&cBinop_H0TlEE5M, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_H2MbHG7J, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_HngZrJRM, 0.0f); // __sub
  numBytes += cTabhead_init(&cTabhead_WraOhQ2g, &hTable_tGr4wwQI);
  numBytes += cVar_init_s(&cVar_iIKIVMKO, "del-1011-del4");
  numBytes += cDelay_init(this, &cDelay_wlrVK1RQ, 86.1244f);
  numBytes += cDelay_init(this, &cDelay_bpTRsktE, 0.0f);
  numBytes += cBinop_init(&cBinop_4hD7mMmI, 86.1244f); // __mul
  numBytes += cBinop_init(&cBinop_2cuGUmKQ, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_J3bXEsAj, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_zZHcMFiM, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_UgKdb1UA, 0.0f);
  numBytes += cDelay_init(this, &cDelay_0eD3uHmO, 0.0f);
  numBytes += hTable_init(&hTable_VjGitjUm, 256);
  numBytes += cDelay_init(this, &cDelay_UUYmsL8M, 0.0f);
  numBytes += cDelay_init(this, &cDelay_BCnbgvOC, 0.0f);
  numBytes += hTable_init(&hTable_1yNlBKZm, 256);
  numBytes += cDelay_init(this, &cDelay_sehfXdXe, 0.0f);
  numBytes += cDelay_init(this, &cDelay_jyKYM4OU, 0.0f);
  numBytes += hTable_init(&hTable_Vl89S9S8, 256);
  numBytes += cDelay_init(this, &cDelay_k75fGOaW, 0.0f);
  numBytes += cDelay_init(this, &cDelay_Wrm5RvtG, 0.0f);
  numBytes += hTable_init(&hTable_tGr4wwQI, 256);
  numBytes += cIf_init(&cIf_aJPsfG8q, false);
  numBytes += cBinop_init(&cBinop_pycMEp4d, 0.0f); // __pow
  numBytes += cPack_init(&cPack_Svh0sPrD, 2, 0.0f, 30.0f);
  numBytes += cPack_init(&cPack_pASNgx7Q, 2, 0.0f, 50.0f);
  numBytes += cVar_init_f(&cVar_8LJGdBjr, 22050.0f);
  numBytes += cBinop_init(&cBinop_mfNymDjS, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_VgADkB3Q, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_ct5nnFHj, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_UsY1wa68, 95.0f);
  numBytes += cVar_init_f(&cVar_Tn0F1Q3X, 90.0f);
  numBytes += cVar_init_f(&cVar_wiXZaPgr, 6000.0f);
  numBytes += cVar_init_f(&cVar_8iahlenK, 60.0f);
  numBytes += cIf_init(&cIf_0FGCkbZ6, false);
  numBytes += cTabhead_init(&cTabhead_8gY1XbVk, &hTable_8zkdx3Ry);
  numBytes += cVar_init_s(&cVar_7L2XjG1F, "del-1011-ref6");
  numBytes += cDelay_init(this, &cDelay_0P5OQRDA, 13.645f);
  numBytes += cDelay_init(this, &cDelay_RlLmDDra, 0.0f);
  numBytes += cBinop_init(&cBinop_7uWLEae0, 13.645f); // __mul
  numBytes += cBinop_init(&cBinop_FKkpjFjE, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_Nu1nRwrp, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_aTRKAD6q, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_n26YEsmj, 0.0f);
  numBytes += cDelay_init(this, &cDelay_ubAShj59, 0.0f);
  numBytes += hTable_init(&hTable_8zkdx3Ry, 256);
  numBytes += cTabhead_init(&cTabhead_DXWbipj5, &hTable_pTOltC5v);
  numBytes += cVar_init_s(&cVar_dlHrsWtW, "del-1011-ref5");
  numBytes += cDelay_init(this, &cDelay_2rwDErTA, 16.364f);
  numBytes += cDelay_init(this, &cDelay_HvY5rFUP, 0.0f);
  numBytes += cBinop_init(&cBinop_2Xgr1Lvk, 16.364f); // __mul
  numBytes += cBinop_init(&cBinop_PuVXk7sG, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_BCqjoOcz, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_QVWsypLa, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_TUoTq2rW, 0.0f);
  numBytes += cDelay_init(this, &cDelay_99p6cEpE, 0.0f);
  numBytes += hTable_init(&hTable_pTOltC5v, 256);
  numBytes += cTabhead_init(&cTabhead_hQym7h4O, &hTable_x9dQjkz4);
  numBytes += cVar_init_s(&cVar_zPUihtmJ, "del-1011-ref4");
  numBytes += cDelay_init(this, &cDelay_LabxNM1M, 19.392f);
  numBytes += cDelay_init(this, &cDelay_VNkMW7UY, 0.0f);
  numBytes += cBinop_init(&cBinop_4sJUHREm, 19.392f); // __mul
  numBytes += cBinop_init(&cBinop_LjomvqwD, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_kdJn05Wo, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_GnIHNDw8, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_LPyvyOWc, 0.0f);
  numBytes += cDelay_init(this, &cDelay_ASwfuSEe, 0.0f);
  numBytes += hTable_init(&hTable_x9dQjkz4, 256);
  numBytes += cTabhead_init(&cTabhead_IjB0ZulE, &hTable_2kfZz5Sk);
  numBytes += cVar_init_s(&cVar_HS0sEN5a, "del-1011-ref3");
  numBytes += cDelay_init(this, &cDelay_GCgNbZPh, 25.796f);
  numBytes += cDelay_init(this, &cDelay_5KpbaNZ6, 0.0f);
  numBytes += cBinop_init(&cBinop_MbHCx8jH, 25.796f); // __mul
  numBytes += cBinop_init(&cBinop_GKoweOLq, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_ATKWt2tR, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_hFSVehYt, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_GbzgcgjF, 0.0f);
  numBytes += cDelay_init(this, &cDelay_7rknLyRm, 0.0f);
  numBytes += hTable_init(&hTable_2kfZz5Sk, 256);
  numBytes += cTabhead_init(&cTabhead_04PPr6iL, &hTable_Shq5AKqO);
  numBytes += cVar_init_s(&cVar_qTN8XMKJ, "del-1011-ref2");
  numBytes += cDelay_init(this, &cDelay_T0XiBPXm, 43.5337f);
  numBytes += cDelay_init(this, &cDelay_NeQkz5L9, 0.0f);
  numBytes += cBinop_init(&cBinop_cOjOFsxJ, 43.5337f); // __mul
  numBytes += cBinop_init(&cBinop_wP8vlgB0, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_SWEnxSja, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_4iWPfWH8, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_4lthWf8X, 0.0f);
  numBytes += cDelay_init(this, &cDelay_iWmjTw3T, 0.0f);
  numBytes += hTable_init(&hTable_Shq5AKqO, 256);
  numBytes += cTabhead_init(&cTabhead_EK6hcK0H, &hTable_mxTyjspJ);
  numBytes += cVar_init_s(&cVar_yvp5oFHT, "del-1011-ref1");
  numBytes += cDelay_init(this, &cDelay_6Oqm83Fv, 75.2546f);
  numBytes += cDelay_init(this, &cDelay_xqzf4D4a, 0.0f);
  numBytes += cBinop_init(&cBinop_i062Zfal, 75.2546f); // __mul
  numBytes += cBinop_init(&cBinop_EiSRWrog, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_fdsc6XCO, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_hiStwKKn, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_kr8oXvGo, 0.0f);
  numBytes += cDelay_init(this, &cDelay_n8RsjQ6V, 0.0f);
  numBytes += hTable_init(&hTable_mxTyjspJ, 256);
  numBytes += cVar_init_f(&cVar_PhPurmce, 0.0f);
  numBytes += cVar_init_f(&cVar_mhUMjZuf, 0.0f);
  numBytes += cPack_init(&cPack_OUXbIyoL, 2, 0.0f, 50.0f);
  numBytes += cVar_init_f(&cVar_FQQ2DcxT, 22050.0f);
  numBytes += cBinop_init(&cBinop_7oKX8rkc, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_ZTXdCxRr, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_pLlRY8Vb, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_Km7aDGyB, 22050.0f);
  numBytes += cBinop_init(&cBinop_26YsOxqc, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_Lzp8pV6Y, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_J2LEHm81, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_OOEpDFt5, 22050.0f);
  numBytes += cBinop_init(&cBinop_WBniqUcV, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_GMNI2Gzz, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_5QWBrofr, 0.0f, 0.0f, false);
  numBytes += cIf_init(&cIf_NcPRsVhT, false);
  numBytes += cDelay_init(this, &cDelay_FwdBr2VK, 50.0f);
  numBytes += cVar_init_f(&cVar_GixuPu9q, 0.0f);
  numBytes += cVar_init_f(&cVar_427lAlvE, 12.0f);
  numBytes += cVar_init_s(&cVar_1ENawIex, "floatatom");
  numBytes += cPack_init(&cPack_Dye63Fxo, 2, 0.0f, 200.0f);
  numBytes += cPack_init(&cPack_1kt8obzy, 2, 0.0f, 200.0f);
  numBytes += cVar_init_s(&cVar_ahMrVFPJ, "floatatom");
  numBytes += cDelay_init(this, &cDelay_i49vmS8I, 0.0f);
  numBytes += cDelay_init(this, &cDelay_B3lWBMTt, 0.0f);
  numBytes += hTable_init(&hTable_bBdX6WS1, 256);
  numBytes += cVar_init_s(&cVar_EhN78tzK, "del-1118-del");
  numBytes += sVarf_init(&sVarf_N3LQ7K9s, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_kZij7zhD, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_jmrBReYA, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_9iyxHJcb, "del-1118-del");
  numBytes += sVarf_init(&sVarf_alB1g67Z, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_fi0IdYHn, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_iTxHKcnV, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_DkAuhJ4B, 0.0f); // __div
  numBytes += cVar_init_f(&cVar_tC1ETIrK, 4720.0f);
  numBytes += cBinop_init(&cBinop_6LxV0ohk, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_OYekWWvr, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_9e0AsWyy, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_pNJnok0N, 4720.0f);
  numBytes += cBinop_init(&cBinop_OxwmpTKC, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_wzcESr4V, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_AMFe2ILE, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_1DOFW6CV, 4720.0f);
  numBytes += cBinop_init(&cBinop_kMLpOHww, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_ZSA5JPpm, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_suZnWLke, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_qwQ7Na3d, 1.0f);
  numBytes += cIf_init(&cIf_NRu50uh8, false);
  numBytes += sVarf_init(&sVarf_9T6ZYngT, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_9K5qRupb, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_TkPJyfvg, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_tGQJ5UOH, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_sdQZbveA, 4720.0f, 0.0f, false);
  numBytes += cTabhead_init(&cTabhead_BhCdQpx4, &hTable_tfHJlVqH);
  numBytes += cVar_init_s(&cVar_32wrEBxC, "del-1181-del1");
  numBytes += cDelay_init(this, &cDelay_udYXoKMg, 58.6435f);
  numBytes += cDelay_init(this, &cDelay_SPe7zgcK, 0.0f);
  numBytes += cBinop_init(&cBinop_a2hAK04P, 58.6435f); // __mul
  numBytes += cBinop_init(&cBinop_zWQmu9NG, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_jnaJk5Br, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_QYe3YmoE, 0.0f); // __sub
  numBytes += cTabhead_init(&cTabhead_vWjX6wtf, &hTable_s05kBe0N);
  numBytes += cVar_init_s(&cVar_D4i1hYXb, "del-1181-del2");
  numBytes += cDelay_init(this, &cDelay_VgxIpwUe, 69.4325f);
  numBytes += cDelay_init(this, &cDelay_pwporhgO, 0.0f);
  numBytes += cBinop_init(&cBinop_lzB0lg8v, 69.4325f); // __mul
  numBytes += cBinop_init(&cBinop_5BHXKZRg, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_YPc3Idbv, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_59x31kei, 0.0f); // __sub
  numBytes += cTabhead_init(&cTabhead_MX3InhKt, &hTable_dAH5iQND);
  numBytes += cVar_init_s(&cVar_BDVggPgY, "del-1181-del3");
  numBytes += cDelay_init(this, &cDelay_uy0bqKsH, 74.5234f);
  numBytes += cDelay_init(this, &cDelay_QCSsLFAT, 0.0f);
  numBytes += cBinop_init(&cBinop_AWK53yqy, 74.5234f); // __mul
  numBytes += cBinop_init(&cBinop_rkVHlaGI, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_Y6wFnb0W, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_038tyPoP, 0.0f); // __sub
  numBytes += cTabhead_init(&cTabhead_BMpi2f4B, &hTable_rxv0WHA4);
  numBytes += cVar_init_s(&cVar_ZK9JIqoN, "del-1181-del4");
  numBytes += cDelay_init(this, &cDelay_OwX574dn, 86.1244f);
  numBytes += cDelay_init(this, &cDelay_82G0SwR2, 0.0f);
  numBytes += cBinop_init(&cBinop_wwk0CUx4, 86.1244f); // __mul
  numBytes += cBinop_init(&cBinop_4G7eKyBT, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_HURxE1rC, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_hak1NBMF, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_LInV59xw, 0.0f);
  numBytes += cDelay_init(this, &cDelay_JM5GLEwE, 0.0f);
  numBytes += hTable_init(&hTable_tfHJlVqH, 256);
  numBytes += cDelay_init(this, &cDelay_oUO4rvPz, 0.0f);
  numBytes += cDelay_init(this, &cDelay_yIKfIE6N, 0.0f);
  numBytes += hTable_init(&hTable_s05kBe0N, 256);
  numBytes += cDelay_init(this, &cDelay_wYJhQNlE, 0.0f);
  numBytes += cDelay_init(this, &cDelay_8UK5FtGx, 0.0f);
  numBytes += hTable_init(&hTable_dAH5iQND, 256);
  numBytes += cDelay_init(this, &cDelay_z2pjONm3, 0.0f);
  numBytes += cDelay_init(this, &cDelay_Uhz2So1z, 0.0f);
  numBytes += hTable_init(&hTable_rxv0WHA4, 256);
  numBytes += cIf_init(&cIf_qgEM6tvd, false);
  numBytes += cBinop_init(&cBinop_0qEnwt5p, 0.0f); // __pow
  numBytes += cPack_init(&cPack_GHi8oYBG, 2, 0.0f, 30.0f);
  numBytes += cPack_init(&cPack_3AmPPqfy, 2, 0.0f, 50.0f);
  numBytes += cVar_init_f(&cVar_74RnRCDV, 22050.0f);
  numBytes += cBinop_init(&cBinop_dM0DE3nI, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_agHcru4M, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_8x9Hf6B3, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_mn5VjOIv, 100.0f);
  numBytes += cVar_init_f(&cVar_qFiQRHjD, 95.0f);
  numBytes += cVar_init_f(&cVar_ysfqpLHP, 14400.0f);
  numBytes += cVar_init_f(&cVar_wHlfSVwo, 60.0f);
  numBytes += cIf_init(&cIf_tAm4wH24, false);
  numBytes += cTabhead_init(&cTabhead_w2T4YJ1q, &hTable_KGTj6IPY);
  numBytes += cVar_init_s(&cVar_rdfC08lm, "del-1181-ref6");
  numBytes += cDelay_init(this, &cDelay_yT4NhXO8, 13.645f);
  numBytes += cDelay_init(this, &cDelay_5oRRxdeu, 0.0f);
  numBytes += cBinop_init(&cBinop_kVRcn5an, 13.645f); // __mul
  numBytes += cBinop_init(&cBinop_NfZB2BXI, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_nmr1YjAj, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_SUw1AlV5, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_lT6kKxrB, 0.0f);
  numBytes += cDelay_init(this, &cDelay_VyaWh0Y3, 0.0f);
  numBytes += hTable_init(&hTable_KGTj6IPY, 256);
  numBytes += cTabhead_init(&cTabhead_iMMGmHQl, &hTable_KaldRfq7);
  numBytes += cVar_init_s(&cVar_neczr5hd, "del-1181-ref5");
  numBytes += cDelay_init(this, &cDelay_3clS3tMj, 16.364f);
  numBytes += cDelay_init(this, &cDelay_sE6ru9gP, 0.0f);
  numBytes += cBinop_init(&cBinop_Claw70y0, 16.364f); // __mul
  numBytes += cBinop_init(&cBinop_bnnMdO4r, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_E5Ga3tL1, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_wDKY7NpH, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_1tU5iEsk, 0.0f);
  numBytes += cDelay_init(this, &cDelay_WV10wl9I, 0.0f);
  numBytes += hTable_init(&hTable_KaldRfq7, 256);
  numBytes += cTabhead_init(&cTabhead_KtH8ozvz, &hTable_6sSB7Hy6);
  numBytes += cVar_init_s(&cVar_GuOl5wKF, "del-1181-ref4");
  numBytes += cDelay_init(this, &cDelay_TzI79mT9, 19.392f);
  numBytes += cDelay_init(this, &cDelay_tdQGp3Yq, 0.0f);
  numBytes += cBinop_init(&cBinop_tWdgblUC, 19.392f); // __mul
  numBytes += cBinop_init(&cBinop_Iw8fG938, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_9YOUEU9I, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_nuX0Rd0K, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_ao06001U, 0.0f);
  numBytes += cDelay_init(this, &cDelay_4nyuHINW, 0.0f);
  numBytes += hTable_init(&hTable_6sSB7Hy6, 256);
  numBytes += cTabhead_init(&cTabhead_nh1v6TXI, &hTable_X7MOLq8C);
  numBytes += cVar_init_s(&cVar_BN0zJU9V, "del-1181-ref3");
  numBytes += cDelay_init(this, &cDelay_Dpum5Z6c, 25.796f);
  numBytes += cDelay_init(this, &cDelay_6GbSm2iR, 0.0f);
  numBytes += cBinop_init(&cBinop_AWLhKV2m, 25.796f); // __mul
  numBytes += cBinop_init(&cBinop_XCQszdrD, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_s7wbdsCU, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_vfhcbiQR, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_VsugkJeQ, 0.0f);
  numBytes += cDelay_init(this, &cDelay_nBliQNTW, 0.0f);
  numBytes += hTable_init(&hTable_X7MOLq8C, 256);
  numBytes += cTabhead_init(&cTabhead_m3DF7heY, &hTable_2gfCxAKy);
  numBytes += cVar_init_s(&cVar_gjDOvGBK, "del-1181-ref2");
  numBytes += cDelay_init(this, &cDelay_cXXHnfKg, 43.5337f);
  numBytes += cDelay_init(this, &cDelay_z3dCw8os, 0.0f);
  numBytes += cBinop_init(&cBinop_Ma022gkD, 43.5337f); // __mul
  numBytes += cBinop_init(&cBinop_PYVK8qUG, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_vMP2Pyuj, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_nF58nSNS, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_W6nNWxVM, 0.0f);
  numBytes += cDelay_init(this, &cDelay_WrGOGpi0, 0.0f);
  numBytes += hTable_init(&hTable_2gfCxAKy, 256);
  numBytes += cTabhead_init(&cTabhead_eKzW24RL, &hTable_UT8gYIoQ);
  numBytes += cVar_init_s(&cVar_XC5Lpguv, "del-1181-ref1");
  numBytes += cDelay_init(this, &cDelay_Fgunxv5b, 75.2546f);
  numBytes += cDelay_init(this, &cDelay_zV1nuDoY, 0.0f);
  numBytes += cBinop_init(&cBinop_gxqNasS1, 75.2546f); // __mul
  numBytes += cBinop_init(&cBinop_Xzawq8LB, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_HubjzxEk, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_mu6hkjVD, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_BAUXMOAX, 0.0f);
  numBytes += cDelay_init(this, &cDelay_MI8QUrNU, 0.0f);
  numBytes += hTable_init(&hTable_UT8gYIoQ, 256);
  numBytes += cVar_init_f(&cVar_uuE2YQjm, 0.0f);
  numBytes += cVar_init_f(&cVar_J62g29j8, 0.0f);
  numBytes += cPack_init(&cPack_kSSoJ2sU, 2, 0.0f, 50.0f);
  numBytes += cVar_init_f(&cVar_ZcCqvYFc, 22050.0f);
  numBytes += cBinop_init(&cBinop_RB7LKaxx, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_tDrCQpcP, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_fgbIvbik, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_ulNJrwP1, 22050.0f);
  numBytes += cBinop_init(&cBinop_OYc9sUe4, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_60UokQL2, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_h01R1Ld9, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_kCPY6E1j, 22050.0f);
  numBytes += cBinop_init(&cBinop_vztLTuSL, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_hVJ19mrl, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_RVRjBK8D, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_e7Wnw651, "del-1280-del1");
  numBytes += sVarf_init(&sVarf_z3V7FGDC, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_SQsCBqpT, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_xpAQZRaH, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_Pr4kJt9x, 10000.0f);
  numBytes += cBinop_init(&cBinop_1rLN6CNM, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_3QE3btHo, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_OdteWPZx, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_iLpkvaHj, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_gNYN7LI5, 10.0f);
  numBytes += cBinop_init(&cBinop_v4ao5Z2v, 0.0f); // __div
  numBytes += sVarf_init(&sVarf_2qLwisnm, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_gjIuhEB1, "floatatom");
  numBytes += sVarf_init(&sVarf_gD2uy6r5, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_OMCmfLwL, 0.0f);
  numBytes += cDelay_init(this, &cDelay_O7IM9YxK, 0.0f);
  numBytes += hTable_init(&hTable_r3uhFRAO, 256);
  numBytes += sVarf_init(&sVarf_RZyu0DjM, 0.0f, 0.0f, false);
  numBytes += cPack_init(&cPack_rEvwJGWN, 2, 0.0f, 50.0f);
  numBytes += cRandom_init(&cRandom_DoLL23Bx, 1145538674);
  numBytes += cSlice_init(&cSlice_owQExA90, 1, 1);
  numBytes += cRandom_init(&cRandom_ARKuTEhg, -2105438596);
  numBytes += cSlice_init(&cSlice_leFLfzus, 1, 1);
  numBytes += cVar_init_s(&cVar_rwTFIpvJ, "floatatom");
  numBytes += cPack_init(&cPack_DDQYfJK0, 2, 0.0f, 200.0f);
  numBytes += cPack_init(&cPack_2EQ9qJlo, 2, 0.0f, 200.0f);
  numBytes += cVar_init_s(&cVar_NG1201mj, "floatatom");
  numBytes += cDelay_init(this, &cDelay_aTimklCN, 0.0f);
  numBytes += cDelay_init(this, &cDelay_r05jxH4U, 0.0f);
  numBytes += hTable_init(&hTable_Hi9yYgYc, 256);
  numBytes += cVar_init_s(&cVar_rE5M39Qj, "del-1311-del");
  numBytes += sVarf_init(&sVarf_YDwwWFrn, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_FuWhBjDZ, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_J5wGu32K, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_L9otMwf8, "del-1311-del");
  numBytes += sVarf_init(&sVarf_SuuDqkwe, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_WEOggCsQ, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_6CqxHACL, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_rXfOqtyh, 0.0f); // __div
  numBytes += cVar_init_s(&cVar_LhGF5E3Z, "del-1340-del1");
  numBytes += sVarf_init(&sVarf_0avF5hF4, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_7ELSxx6o, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_NepA7IB1, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_hIOCEH11, 10000.0f);
  numBytes += cBinop_init(&cBinop_Wpmr75c2, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_94IIpfHb, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_SGJmRoOS, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_G4Ad08ON, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_OSAzhwCX, 10.0f);
  numBytes += cBinop_init(&cBinop_ADQtuyEc, 0.0f); // __div
  numBytes += sVarf_init(&sVarf_4IsnjDWd, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_K2ZLhkH3, "floatatom");
  numBytes += sVarf_init(&sVarf_b20AZw3F, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_wvdoWBLL, 0.0f);
  numBytes += cDelay_init(this, &cDelay_rshMajKA, 0.0f);
  numBytes += hTable_init(&hTable_ljdEM2pb, 256);
  numBytes += sVarf_init(&sVarf_uxWdVfH0, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_ItSYF4l3, "floatatom");
  numBytes += cDelay_init(this, &cDelay_vo08GyYq, 0.0f);
  numBytes += cVar_init_f(&cVar_iG6Q9AMR, 20.0f);
  numBytes += cBinop_init(&cBinop_yiLTvZsA, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_CYIQFSze, 0.0f);
  numBytes += cSlice_init(&cSlice_3WKevw0c, 1, -1);
  numBytes += cSlice_init(&cSlice_GhkRFBFi, 1, -1);
  numBytes += cVar_init_f(&cVar_pwBLqF7J, 0.0f);
  numBytes += cVar_init_f(&cVar_djXXQNug, 20.0f);
  numBytes += cVar_init_f(&cVar_5dmjvb45, 0.0f);
  numBytes += cVar_init_f(&cVar_qvNTVEml, 0.0f);
  numBytes += cVar_init_f(&cVar_FhdG7NPX, 0.0f);
  numBytes += cSlice_init(&cSlice_2Ihd9p5X, 1, 1);
  numBytes += cSlice_init(&cSlice_xL9rIoq5, 0, 1);
  numBytes += cBinop_init(&cBinop_RQhBn7YV, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_G9eocWrv, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_y2kcfRI7, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_S3AYjpd7, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_gtudRimd, 20.0f); // __div
  numBytes += cBinop_init(&cBinop_D6884NBg, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_fnYYIWGR, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_gSBG6SPY, 0.0f); // __sub
  numBytes += cVar_init_s(&cVar_TQBaiFpx, "floatatom");
  numBytes += cPack_init(&cPack_cysyNOV1, 2, 0.0f, 1000.0f);
  numBytes += cDelay_init(this, &cDelay_eyIdlOhM, 0.0f);
  numBytes += cVar_init_f(&cVar_05zfhTHZ, 20.0f);
  numBytes += cBinop_init(&cBinop_RSTOe3dx, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_lqjrklkx, 0.0f);
  numBytes += cSlice_init(&cSlice_0MnQNyRL, 1, -1);
  numBytes += cSlice_init(&cSlice_I5TA7xOd, 1, -1);
  numBytes += cVar_init_f(&cVar_k6z3pVxx, 0.0f);
  numBytes += cVar_init_f(&cVar_q6orzG1H, 20.0f);
  numBytes += cVar_init_f(&cVar_eTOirtGv, 0.0f);
  numBytes += cVar_init_f(&cVar_MTnPwSC8, 0.0f);
  numBytes += cVar_init_f(&cVar_X1zDQ0L8, 0.0f);
  numBytes += cSlice_init(&cSlice_ifZ2iUEY, 1, 1);
  numBytes += cSlice_init(&cSlice_bXRWTXOP, 0, 1);
  numBytes += cBinop_init(&cBinop_jX9eDMgF, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_hq1WEs5C, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_DOmWXtIq, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_Y4MwPX5c, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_0FTfUIS5, 20.0f); // __div
  numBytes += cBinop_init(&cBinop_B9RbKhYP, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_8stjlBnt, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_z0gxxexp, 0.0f); // __sub
  numBytes += cPack_init(&cPack_N161spau, 2, 0.0f, 1000.0f);
  numBytes += cPack_init(&cPack_UMl2RfDo, 2, 0.0f, 1000.0f);
  numBytes += sVarf_init(&sVarf_5r1xjknQ, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_87DbvT2A, 5.0f);
  numBytes += cBinop_init(&cBinop_qW5NlNh8, 0.0f); // __div
  numBytes += sVarf_init(&sVarf_saHl7w3A, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_eFucoNgD, "floatatom");
  numBytes += cIf_init(&cIf_LijsdTxW, false);
  numBytes += cIf_init(&cIf_cer3fsJv, false);
  numBytes += cIf_init(&cIf_6QVDJmcx, false);
  numBytes += cIf_init(&cIf_hvgAfv1D, false);
  numBytes += cRandom_init(&cRandom_dYfAyvlQ, -883296793);
  numBytes += cSlice_init(&cSlice_6NxxO4IG, 1, 1);
  numBytes += sVari_init(&sVari_eOByYFnj, 0, 0, false);
  numBytes += cTabhead_init(&cTabhead_rOuB54cf, &hTable_L6MOTeCE);
  numBytes += cVar_init_s(&cVar_9GVghihj, "del-1418-delay");
  numBytes += cDelay_init(this, &cDelay_AdVLVXqp, 12.0f);
  numBytes += cDelay_init(this, &cDelay_WaaEB9so, 0.0f);
  numBytes += cBinop_init(&cBinop_Swaub8pe, 12.0f); // __mul
  numBytes += cBinop_init(&cBinop_rtWMl1L2, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_Oq2rUOCU, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_rfAEnC5U, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_oF4eg9fl, 1.0f); // __pow
  numBytes += cVar_init_s(&cVar_DaYIr1Tx, "floatatom");
  numBytes += cDelay_init(this, &cDelay_cN1qg1Ez, 5.0f);
  numBytes += cVar_init_f(&cVar_MsuxkGXm, 3800.0f);
  numBytes += cBinop_init(&cBinop_npUfZQFg, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_uugT5Juj, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_LIHn206i, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_5hcWN5wq, 0.0f);
  numBytes += cDelay_init(this, &cDelay_GSaN18KR, 0.0f);
  numBytes += hTable_init(&hTable_L6MOTeCE, 256);
  numBytes += cBinop_init(&cBinop_1viVckc7, 0.0f); // __div
  numBytes += sVarf_init(&sVarf_oUvkWwHu, 0.999f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_YiuOaEHl, 1.0f);
  numBytes += cDelay_init(this, &cDelay_ZX6yMN56, 0.0f);
  numBytes += cVar_init_f(&cVar_LBrR9mOt, 2000.0f);
  numBytes += cBinop_init(&cBinop_5ZP62Jaq, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_8zNrYrmx, 60.0f);
  numBytes += cRandom_init(&cRandom_pgD5ODH4, 794266971);
  numBytes += cSlice_init(&cSlice_41FqvrHV, 1, 1);
  numBytes += cVar_init_f(&cVar_xFwOQwqQ, 0.0f);
  numBytes += cIf_init(&cIf_aKFKiW3J, false);
  numBytes += cIf_init(&cIf_I02B0pKu, false);
  numBytes += cIf_init(&cIf_748loJLv, false);
  numBytes += cIf_init(&cIf_68YIpKEu, false);
  numBytes += cPack_init(&cPack_tVAZy8DP, 2, 0.0f, 50.0f);
  numBytes += cPack_init(&cPack_zjXlUEf5, 2, 0.0f, 80.0f);
  numBytes += cVar_init_s(&cVar_PrfIVMut, "floatatom");
  numBytes += cRandom_init(&cRandom_S84jBn66, 1064276492);
  numBytes += cSlice_init(&cSlice_5oWon6Ly, 1, 1);
  numBytes += cVar_init_s(&cVar_rpW8SQPS, "floatatom");
  numBytes += cVar_init_f(&cVar_l4GTod4w, 1.0f);
  numBytes += cVar_init_f(&cVar_Z7QV9U8f, 0.0f);
  numBytes += cVar_init_f(&cVar_Mt5EA5wd, 0.0f);
  numBytes += cRandom_init(&cRandom_FmpcyDM2, 1904253154);
  numBytes += cSlice_init(&cSlice_s0ZNc6zC, 1, 1);
  numBytes += cRandom_init(&cRandom_qvXfcIYV, -1326168333);
  numBytes += cSlice_init(&cSlice_lixM8v2T, 1, 1);
  numBytes += cRandom_init(&cRandom_X8chaVAR, 1662313954);
  numBytes += cSlice_init(&cSlice_38rCsSyN, 1, 1);
  numBytes += cBinop_init(&cBinop_EJkBcX8R, 1.0f); // __pow
  numBytes += cRandom_init(&cRandom_GQLz0iDs, -1172845683);
  numBytes += cSlice_init(&cSlice_VqK2VIG8, 1, 1);
  numBytes += cPack_init(&cPack_96rLYEgW, 2, 0.0f, 50.0f);
  numBytes += cVar_init_s(&cVar_K6f46STl, "floatatom");
  numBytes += cVar_init_s(&cVar_r7CZbbdC, "floatatom");
  numBytes += cVar_init_f(&cVar_DrrnP6n6, 0.0f);
  numBytes += cVar_init_s(&cVar_9uqHUoqy, "floatatom");
  numBytes += cVar_init_s(&cVar_41KPvXEI, "floatatom");
  numBytes += cVar_init_s(&cVar_kPdyvOZq, "floatatom");
  numBytes += cDelay_init(this, &cDelay_QmNnfow6, 25.0f);
  numBytes += cVar_init_f(&cVar_vnv23JiP, 0.0f);
  numBytes += sVarf_init(&sVarf_mF4KqpcY, 0.0f, 0.0f, false);
  numBytes += cRandom_init(&cRandom_lKPIHZ1I, 2064603158);
  numBytes += cSlice_init(&cSlice_lm58TzkW, 1, 1);
  numBytes += sVari_init(&sVari_nS0e1uCy, 0, 0, false);
  numBytes += cTabhead_init(&cTabhead_hTm3mJ9u, &hTable_f2MY0Eli);
  numBytes += cVar_init_s(&cVar_3CKWKr6R, "del-1497-delay");
  numBytes += cDelay_init(this, &cDelay_P35YTh9Z, 12.0f);
  numBytes += cDelay_init(this, &cDelay_fjojXfn5, 0.0f);
  numBytes += cBinop_init(&cBinop_NFkFZOa7, 12.0f); // __mul
  numBytes += cBinop_init(&cBinop_OxIMMNbF, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_xYwHFiX3, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_RKT37uAo, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_T9U7zVBe, 1.0f); // __pow
  numBytes += cVar_init_s(&cVar_XzF5DlWi, "floatatom");
  numBytes += cDelay_init(this, &cDelay_0L7n5bYW, 5.0f);
  numBytes += cVar_init_f(&cVar_n7fikkrY, 3800.0f);
  numBytes += cBinop_init(&cBinop_FCcJcPSY, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_XDfieX4W, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_viUoN3mQ, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_C2MmuP9k, 0.0f);
  numBytes += cDelay_init(this, &cDelay_cN2ukW3L, 0.0f);
  numBytes += hTable_init(&hTable_f2MY0Eli, 256);
  numBytes += cBinop_init(&cBinop_6pTizkQW, 0.0f); // __div
  numBytes += sVarf_init(&sVarf_ntdg74Xc, 0.999f, 0.0f, false);
  numBytes += cPack_init(&cPack_JYwEgJUw, 2, 0.0f, 10.0f);
  numBytes += cPack_init(&cPack_ICFm3Jex, 2, 0.0f, 10.0f);
  numBytes += cSlice_init(&cSlice_cxB7DDzC, 1, 1);
  numBytes += cSlice_init(&cSlice_Dp1N1jdC, 0, 1);
  numBytes += cBinop_init(&cBinop_ZZeE3tg9, 1.0f); // __mul
  numBytes += cVar_init_f(&cVar_uqsLIPqF, 98.0f);
  numBytes += cIf_init(&cIf_ihNkOZdb, false);
  numBytes += cBinop_init(&cBinop_IKqRPfgz, 0.0f); // __pow
  numBytes += cPack_init(&cPack_2gPdsgkN, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_9UniTBM9, 0.0f);
  numBytes += cVar_init_f(&cVar_hpHZHG8w, 98.0f);
  numBytes += cIf_init(&cIf_qMtGKiX6, false);
  numBytes += cBinop_init(&cBinop_PrWE99Rd, 0.0f); // __pow
  numBytes += cPack_init(&cPack_2zVazh8B, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_OQeJwARA, 0.0f);
  numBytes += cRandom_init(&cRandom_8Rp5DjS2, -976760388);
  numBytes += cSlice_init(&cSlice_FH0UNgTD, 1, 1);
  numBytes += cBinop_init(&cBinop_3BPvUi81, 1.0f); // __pow
  numBytes += cRandom_init(&cRandom_RTVI7H0A, 220297048);
  numBytes += cSlice_init(&cSlice_REzBtACR, 1, 1);
  numBytes += cPack_init(&cPack_B3Kat4VK, 2, 0.0f, 50.0f);
  numBytes += cVar_init_s(&cVar_GckwBvYW, "floatatom");
  numBytes += cVar_init_s(&cVar_DUACWizl, "floatatom");
  numBytes += cVar_init_f(&cVar_qFc7csLF, 0.0f);
  numBytes += cVar_init_s(&cVar_P4ruzqrw, "floatatom");
  numBytes += cVar_init_s(&cVar_X7cuYeYA, "floatatom");
  numBytes += cVar_init_s(&cVar_zrlvFyeW, "floatatom");
  numBytes += cDelay_init(this, &cDelay_mDQ6DWtY, 25.0f);
  numBytes += cVar_init_f(&cVar_hfe51u7G, 0.0f);
  numBytes += sVarf_init(&sVarf_F9eR8esI, 0.0f, 0.0f, false);
  numBytes += cRandom_init(&cRandom_0ZwZ0twV, -2032847718);
  numBytes += cSlice_init(&cSlice_LOFarNr5, 1, 1);
  numBytes += sVari_init(&sVari_MHW0ClgY, 0, 0, false);
  numBytes += cTabhead_init(&cTabhead_wuoBFLpF, &hTable_09wS09Ef);
  numBytes += cVar_init_s(&cVar_8dVjwqxB, "del-1564-delay");
  numBytes += cDelay_init(this, &cDelay_SnmJLfEq, 12.0f);
  numBytes += cDelay_init(this, &cDelay_KAZzikd6, 0.0f);
  numBytes += cBinop_init(&cBinop_SrGd5mFE, 12.0f); // __mul
  numBytes += cBinop_init(&cBinop_n7n3TX8R, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_k5k8LXia, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_jh9ucEZJ, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_sd8m7DSi, 1.0f); // __pow
  numBytes += cVar_init_s(&cVar_62UBDu2I, "floatatom");
  numBytes += cDelay_init(this, &cDelay_QWDvcLTZ, 5.0f);
  numBytes += cVar_init_f(&cVar_qfnM3aRI, 3800.0f);
  numBytes += cBinop_init(&cBinop_So89Qwzb, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_YL39BZG2, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_gbKxd1Qy, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_RtFQVGmD, 0.0f);
  numBytes += cDelay_init(this, &cDelay_sVxNBKrQ, 0.0f);
  numBytes += hTable_init(&hTable_09wS09Ef, 256);
  numBytes += cBinop_init(&cBinop_FJNkhkMw, 0.0f); // __div
  numBytes += sVarf_init(&sVarf_g8p8Mjcd, 0.999f, 0.0f, false);
  numBytes += cPack_init(&cPack_WuQibfMZ, 2, 0.0f, 10.0f);
  numBytes += cPack_init(&cPack_Fmz1NpuH, 2, 0.0f, 10.0f);
  numBytes += cSlice_init(&cSlice_bMO4J7Eo, 1, 1);
  numBytes += cSlice_init(&cSlice_zWJwkxZA, 0, 1);
  numBytes += cBinop_init(&cBinop_sB5EJ13L, 1.0f); // __mul
  numBytes += cRandom_init(&cRandom_KywFe7Be, 207826605);
  numBytes += cSlice_init(&cSlice_lLWgYqNt, 1, 1);
  numBytes += cBinop_init(&cBinop_tv9JS2ex, 1.0f); // __pow
  numBytes += cRandom_init(&cRandom_XaroSBc7, -1899641691);
  numBytes += cSlice_init(&cSlice_ruSTsWhB, 1, 1);
  numBytes += cPack_init(&cPack_l4iZ1JLD, 2, 0.0f, 50.0f);
  numBytes += cVar_init_s(&cVar_6l45wIo5, "floatatom");
  numBytes += cVar_init_s(&cVar_bdRnAwRu, "floatatom");
  numBytes += cVar_init_f(&cVar_9aYgMeAL, 0.0f);
  numBytes += cVar_init_s(&cVar_rKYyfb7b, "floatatom");
  numBytes += cVar_init_s(&cVar_RAIf5TS8, "floatatom");
  numBytes += cVar_init_s(&cVar_btJuTAN1, "floatatom");
  numBytes += cDelay_init(this, &cDelay_TGXGtAvG, 25.0f);
  numBytes += cVar_init_f(&cVar_2BMV26Dm, 0.0f);
  numBytes += sVarf_init(&sVarf_QuL4tlXA, 0.0f, 0.0f, false);
  numBytes += cRandom_init(&cRandom_Iq1D1hZH, -1495720389);
  numBytes += cSlice_init(&cSlice_hR1Kr2HM, 1, 1);
  numBytes += sVari_init(&sVari_yElZGC0h, 0, 0, false);
  numBytes += cTabhead_init(&cTabhead_nD8rYepw, &hTable_xRdA4qp0);
  numBytes += cVar_init_s(&cVar_Ae9LXAyP, "del-1615-delay");
  numBytes += cDelay_init(this, &cDelay_SZSST4gS, 12.0f);
  numBytes += cDelay_init(this, &cDelay_VnPTZVjZ, 0.0f);
  numBytes += cBinop_init(&cBinop_XWe2MBT0, 12.0f); // __mul
  numBytes += cBinop_init(&cBinop_1DgjZTps, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_1bfh8MXq, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_NpiT9JHp, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_2Sc4VodB, 1.0f); // __pow
  numBytes += cVar_init_s(&cVar_SGy1Fu8N, "floatatom");
  numBytes += cDelay_init(this, &cDelay_DH8AaDOn, 5.0f);
  numBytes += cVar_init_f(&cVar_DFDFpVaI, 3800.0f);
  numBytes += cBinop_init(&cBinop_ZFkh6uZ8, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_Zzsa36Pg, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_dBxXmxi8, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_6hCqgoKq, 0.0f);
  numBytes += cDelay_init(this, &cDelay_3mH8JMdN, 0.0f);
  numBytes += hTable_init(&hTable_xRdA4qp0, 256);
  numBytes += cBinop_init(&cBinop_vwLHfLeX, 0.0f); // __div
  numBytes += sVarf_init(&sVarf_t4D28GUq, 0.999f, 0.0f, false);
  numBytes += cPack_init(&cPack_BQtOqjzH, 2, 0.0f, 10.0f);
  numBytes += cPack_init(&cPack_ykbzodLd, 2, 0.0f, 10.0f);
  numBytes += cSlice_init(&cSlice_aDh3KdBV, 1, 1);
  numBytes += cSlice_init(&cSlice_5ZO90l66, 0, 1);
  numBytes += cBinop_init(&cBinop_pIY7x5qF, 1.0f); // __mul
  numBytes += cRandom_init(&cRandom_fQUjFfhR, 1743275209);
  numBytes += cSlice_init(&cSlice_6PuuWynS, 1, 1);
  numBytes += cBinop_init(&cBinop_Bwq4Jpd4, 1.0f); // __pow
  numBytes += cRandom_init(&cRandom_9Ll2ULnG, -1742685529);
  numBytes += cSlice_init(&cSlice_cy9q8bzK, 1, 1);
  numBytes += cPack_init(&cPack_eqaPpdVA, 2, 0.0f, 50.0f);
  numBytes += cVar_init_s(&cVar_lp41rcdZ, "floatatom");
  numBytes += cVar_init_s(&cVar_IsFN3WHs, "floatatom");
  numBytes += cVar_init_f(&cVar_HFc0rQEf, 0.0f);
  numBytes += cVar_init_s(&cVar_9H3xucx5, "floatatom");
  numBytes += cVar_init_s(&cVar_l3yfjaJm, "floatatom");
  numBytes += cVar_init_s(&cVar_mpoZnz5U, "floatatom");
  numBytes += cDelay_init(this, &cDelay_07sAnDiR, 25.0f);
  numBytes += cVar_init_f(&cVar_SkY36zJg, 0.0f);
  numBytes += sVarf_init(&sVarf_7RfjPVWo, 0.0f, 0.0f, false);
  numBytes += cRandom_init(&cRandom_zzv73S6D, 2086797016);
  numBytes += cSlice_init(&cSlice_hit0CKTz, 1, 1);
  numBytes += sVari_init(&sVari_9nW8mwS9, 0, 0, false);
  numBytes += cTabhead_init(&cTabhead_BfQ99xL1, &hTable_c60lHUpc);
  numBytes += cVar_init_s(&cVar_9keS29QT, "del-1666-delay");
  numBytes += cDelay_init(this, &cDelay_P5zEZZ5h, 12.0f);
  numBytes += cDelay_init(this, &cDelay_Mq4e45Wi, 0.0f);
  numBytes += cBinop_init(&cBinop_1bnzVpGw, 12.0f); // __mul
  numBytes += cBinop_init(&cBinop_DZ2jvEFl, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_pTE8jIDw, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_DuEse51a, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_hLBqjsvQ, 1.0f); // __pow
  numBytes += cVar_init_s(&cVar_QDBTb7Gw, "floatatom");
  numBytes += cDelay_init(this, &cDelay_JzAtoJP3, 5.0f);
  numBytes += cVar_init_f(&cVar_mT0RV9wd, 3800.0f);
  numBytes += cBinop_init(&cBinop_04tbGSdj, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_AFW9daME, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_1lKsZJBG, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_Sgf5oX5W, 0.0f);
  numBytes += cDelay_init(this, &cDelay_pP39T0wm, 0.0f);
  numBytes += hTable_init(&hTable_c60lHUpc, 256);
  numBytes += cBinop_init(&cBinop_grJjpu0a, 0.0f); // __div
  numBytes += sVarf_init(&sVarf_mtrIyW7L, 0.999f, 0.0f, false);
  numBytes += cPack_init(&cPack_QJyqM7KF, 2, 0.0f, 10.0f);
  numBytes += cPack_init(&cPack_0e04MzDN, 2, 0.0f, 10.0f);
  numBytes += cSlice_init(&cSlice_5PgzWz1k, 1, 1);
  numBytes += cSlice_init(&cSlice_AHkpNVRV, 0, 1);
  numBytes += cBinop_init(&cBinop_liJVsEqt, 1.0f); // __mul
  numBytes += cVar_init_f(&cVar_OPqRhSpX, 100.0f);
  numBytes += cIf_init(&cIf_ZxVgbyLY, false);
  numBytes += cBinop_init(&cBinop_ZpzaBL1D, 0.0f); // __pow
  numBytes += cPack_init(&cPack_ISjFmIBk, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_r7D7p4AF, 0.0f);
  numBytes += cVar_init_f(&cVar_sKSAdDpv, 100.0f);
  numBytes += cIf_init(&cIf_zBbaa17g, false);
  numBytes += cBinop_init(&cBinop_V8DtGmZc, 0.0f); // __pow
  numBytes += cPack_init(&cPack_tpMHi0Dn, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_gbLAogxP, 0.0f);
  numBytes += cVar_init_f(&cVar_oazj6wfs, 98.0f);
  numBytes += cIf_init(&cIf_EV0eII3u, false);
  numBytes += cBinop_init(&cBinop_m0N3TVvr, 0.0f); // __pow
  numBytes += cPack_init(&cPack_KycihIt3, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_25P9ZxKG, 0.0f);
  numBytes += cIf_init(&cIf_aLLEuGrF, false);
  numBytes += cIf_init(&cIf_DgqgXyro, false);
  numBytes += cVar_init_f(&cVar_TINEmFIc, 89.0f);
  numBytes += cIf_init(&cIf_D5obTfxA, false);
  numBytes += cBinop_init(&cBinop_5edb9N8W, 0.0f); // __pow
  numBytes += cPack_init(&cPack_FZEOJKIJ, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_sWwEZrZX, 0.0f);
  numBytes += cPack_init(&cPack_V098JCdl, 2, 0.0f, 0.0f);
  numBytes += cSlice_init(&cSlice_QIT8Lk6p, 1, 1);
  numBytes += cSlice_init(&cSlice_RYrcwGwi, 0, 1);
  numBytes += cIf_init(&cIf_peivcNGa, false);
  numBytes += cIf_init(&cIf_AE6tacRy, false);
  numBytes += cIf_init(&cIf_mkefamLf, false);
  numBytes += cSlice_init(&cSlice_oJRk260f, 1, 1);
  numBytes += cSlice_init(&cSlice_vDluaycK, 0, 1);
  numBytes += cVar_init_f(&cVar_UCvE3Csl, 0.0f);
  numBytes += cIf_init(&cIf_guMLWwta, false);
  numBytes += cPack_init(&cPack_L8yS86S7, 2, 0.0f, 0.0f);
  numBytes += cSlice_init(&cSlice_wLgIS9sg, 1, -1);
  numBytes += cSlice_init(&cSlice_ixwizXQT, 1, -1);
  numBytes += cSlice_init(&cSlice_vjPCy1JW, 1, -1);
  numBytes += cSlice_init(&cSlice_3VAIpURy, 1, -1);
  numBytes += cIf_init(&cIf_qP4uO1u9, false);
  numBytes += cVar_init_f(&cVar_rDY4O9VY, 1.0f);
  numBytes += cPack_init(&cPack_oIpDJQDh, 3, 0.0f, 0.0f, 0.0f);
  numBytes += cVar_init_f(&cVar_w2NUvcoh, 0.0f);
  
  // schedule a message to trigger all loadbangs via the __hv_init receiver
  scheduleMessageForReceiver(0xCE5CC65B, msg_initWithBang(HV_MESSAGE_ON_STACK(1), 0));
}

Heavy_CircleStrings::~Heavy_CircleStrings() {
  hTable_free(&hTable_VjGitjUm);
  hTable_free(&hTable_1yNlBKZm);
  hTable_free(&hTable_Vl89S9S8);
  hTable_free(&hTable_tGr4wwQI);
  cPack_free(&cPack_Svh0sPrD);
  cPack_free(&cPack_pASNgx7Q);
  hTable_free(&hTable_8zkdx3Ry);
  hTable_free(&hTable_pTOltC5v);
  hTable_free(&hTable_x9dQjkz4);
  hTable_free(&hTable_2kfZz5Sk);
  hTable_free(&hTable_Shq5AKqO);
  hTable_free(&hTable_mxTyjspJ);
  cPack_free(&cPack_OUXbIyoL);
  cPack_free(&cPack_Dye63Fxo);
  cPack_free(&cPack_1kt8obzy);
  hTable_free(&hTable_bBdX6WS1);
  hTable_free(&hTable_tfHJlVqH);
  hTable_free(&hTable_s05kBe0N);
  hTable_free(&hTable_dAH5iQND);
  hTable_free(&hTable_rxv0WHA4);
  cPack_free(&cPack_GHi8oYBG);
  cPack_free(&cPack_3AmPPqfy);
  hTable_free(&hTable_KGTj6IPY);
  hTable_free(&hTable_KaldRfq7);
  hTable_free(&hTable_6sSB7Hy6);
  hTable_free(&hTable_X7MOLq8C);
  hTable_free(&hTable_2gfCxAKy);
  hTable_free(&hTable_UT8gYIoQ);
  cPack_free(&cPack_kSSoJ2sU);
  hTable_free(&hTable_r3uhFRAO);
  cPack_free(&cPack_rEvwJGWN);
  cPack_free(&cPack_DDQYfJK0);
  cPack_free(&cPack_2EQ9qJlo);
  hTable_free(&hTable_Hi9yYgYc);
  hTable_free(&hTable_ljdEM2pb);
  cPack_free(&cPack_cysyNOV1);
  cPack_free(&cPack_N161spau);
  cPack_free(&cPack_UMl2RfDo);
  hTable_free(&hTable_L6MOTeCE);
  cPack_free(&cPack_tVAZy8DP);
  cPack_free(&cPack_zjXlUEf5);
  cPack_free(&cPack_96rLYEgW);
  hTable_free(&hTable_f2MY0Eli);
  cPack_free(&cPack_JYwEgJUw);
  cPack_free(&cPack_ICFm3Jex);
  cPack_free(&cPack_2gPdsgkN);
  cPack_free(&cPack_2zVazh8B);
  cPack_free(&cPack_B3Kat4VK);
  hTable_free(&hTable_09wS09Ef);
  cPack_free(&cPack_WuQibfMZ);
  cPack_free(&cPack_Fmz1NpuH);
  cPack_free(&cPack_l4iZ1JLD);
  hTable_free(&hTable_xRdA4qp0);
  cPack_free(&cPack_BQtOqjzH);
  cPack_free(&cPack_ykbzodLd);
  cPack_free(&cPack_eqaPpdVA);
  hTable_free(&hTable_c60lHUpc);
  cPack_free(&cPack_QJyqM7KF);
  cPack_free(&cPack_0e04MzDN);
  cPack_free(&cPack_ISjFmIBk);
  cPack_free(&cPack_tpMHi0Dn);
  cPack_free(&cPack_KycihIt3);
  cPack_free(&cPack_FZEOJKIJ);
  cPack_free(&cPack_V098JCdl);
  cPack_free(&cPack_L8yS86S7);
  cPack_free(&cPack_oIpDJQDh);
}

HvTable *Heavy_CircleStrings::getTableForHash(hv_uint32_t tableHash) {switch (tableHash) {
    case 0xCA4BE954: return &hTable_VjGitjUm; // del-1011-del1
    case 0x244CE923: return &hTable_1yNlBKZm; // del-1011-del2
    case 0xBF68886F: return &hTable_Vl89S9S8; // del-1011-del3
    case 0x55632928: return &hTable_tGr4wwQI; // del-1011-del4
    case 0x96995032: return &hTable_8zkdx3Ry; // del-1011-ref6
    case 0xBDA899C7: return &hTable_pTOltC5v; // del-1011-ref5
    case 0xC66C0031: return &hTable_x9dQjkz4; // del-1011-ref4
    case 0x87263188: return &hTable_2kfZz5Sk; // del-1011-ref3
    case 0xABC596E9: return &hTable_Shq5AKqO; // del-1011-ref2
    case 0x4E55A0D9: return &hTable_mxTyjspJ; // del-1011-ref1
    case 0x1F09EB02: return &hTable_bBdX6WS1; // del-1118-del
    case 0xB5F303E3: return &hTable_tfHJlVqH; // del-1181-del1
    case 0x6E18225F: return &hTable_s05kBe0N; // del-1181-del2
    case 0x272AEAC5: return &hTable_dAH5iQND; // del-1181-del3
    case 0x1EF3B8AB: return &hTable_rxv0WHA4; // del-1181-del4
    case 0x908630F0: return &hTable_KGTj6IPY; // del-1181-ref6
    case 0x571D5EBB: return &hTable_KaldRfq7; // del-1181-ref5
    case 0xCD1DF3EE: return &hTable_6sSB7Hy6; // del-1181-ref4
    case 0x32F70D4: return &hTable_X7MOLq8C; // del-1181-ref3
    case 0x2649C1A0: return &hTable_2gfCxAKy; // del-1181-ref2
    case 0x2A4E9F1A: return &hTable_UT8gYIoQ; // del-1181-ref1
    case 0xCDA70ACE: return &hTable_r3uhFRAO; // del-1280-del1
    case 0x1880FCC4: return &hTable_Hi9yYgYc; // del-1311-del
    case 0xDA0DD3E: return &hTable_ljdEM2pb; // del-1340-del1
    case 0xF059E6C5: return &hTable_L6MOTeCE; // del-1418-delay
    case 0x1B841D52: return &hTable_f2MY0Eli; // del-1497-delay
    case 0xDDCE7CE3: return &hTable_09wS09Ef; // del-1564-delay
    case 0x267B6FA5: return &hTable_xRdA4qp0; // del-1615-delay
    case 0xA939BCAF: return &hTable_c60lHUpc; // del-1666-delay
    default: return nullptr;
  }
}

void Heavy_CircleStrings::scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) {
  switch (receiverHash) {
    case 0xE9CDF196: { // 1474-att
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_3CsrTNVs_sendMessage);
      break;
    }
    case 0x318534AD: { // 1474-envrel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_Q8TGUP0C_sendMessage);
      break;
    }
    case 0x73BE02B2: { // 1474-envvol
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_RVXwoU7w_sendMessage);
      break;
    }
    case 0x20FBEFA2: { // 1474-index
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_7ihRb34k_sendMessage);
      break;
    }
    case 0xB3D2781B: { // 1474-rel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_K0aMEN3J_sendMessage);
      break;
    }
    case 0xEB419491: { // 1474-vel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_vtoDkdrb_sendMessage);
      break;
    }
    case 0x287969C8: { // 1525-levelin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_OkaclTJY_sendMessage);
      break;
    }
    case 0xF758C0B7: { // 1525-levelout
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_viock29s_sendMessage);
      break;
    }
    case 0xEC622ADF: { // 1533-levelin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_xWa6HxGE_sendMessage);
      break;
    }
    case 0x706EBE7F: { // 1533-levelout
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_EX63h6Sm_sendMessage);
      break;
    }
    case 0x961222E8: { // 1541-att
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_hkwTEt4T_sendMessage);
      break;
    }
    case 0x5DFAB282: { // 1541-envrel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_2Dyirtxb_sendMessage);
      break;
    }
    case 0xA73CF987: { // 1541-envvol
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_Jri6FEKs_sendMessage);
      break;
    }
    case 0xDE176410: { // 1541-index
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_xedTPFFX_sendMessage);
      break;
    }
    case 0x8027D6B0: { // 1541-rel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_CMr3LFZ9_sendMessage);
      break;
    }
    case 0x5F30AB7: { // 1541-vel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_byLS6igX_sendMessage);
      break;
    }
    case 0xDAF501EE: { // 1592-att
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_XcXwLiDi_sendMessage);
      break;
    }
    case 0x97DF0634: { // 1592-envrel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_Ewr7zMGz_sendMessage);
      break;
    }
    case 0xED939F1D: { // 1592-envvol
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_Y81Wizul_sendMessage);
      break;
    }
    case 0x6824A5FB: { // 1592-index
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_r0FPSQXF_sendMessage);
      break;
    }
    case 0xD73B2171: { // 1592-rel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_aPKrVrEs_sendMessage);
      break;
    }
    case 0x42AF91EE: { // 1592-vel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_jpyWujMt_sendMessage);
      break;
    }
    case 0xA1F992A3: { // 1643-att
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_RexepgLO_sendMessage);
      break;
    }
    case 0x3A383FAD: { // 1643-envrel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_oS5paxUB_sendMessage);
      break;
    }
    case 0x5381C841: { // 1643-envvol
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_7c0Toumm_sendMessage);
      break;
    }
    case 0x17698774: { // 1643-index
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_FhxRPYyu_sendMessage);
      break;
    }
    case 0xB064A0B2: { // 1643-rel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_Ub07IFlG_sendMessage);
      break;
    }
    case 0x48B0D745: { // 1643-vel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_klp7MXi1_sendMessage);
      break;
    }
    case 0xA97D2594: { // 1694-levelin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_feFavkjj_sendMessage);
      break;
    }
    case 0x17BA9CFD: { // 1694-levelout
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_u48u97dr_sendMessage);
      break;
    }
    case 0x563C50D1: { // 1702-levelin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_VuXin3GN_sendMessage);
      break;
    }
    case 0x50C55BB2: { // 1702-levelout
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_NPT5s9E3_sendMessage);
      break;
    }
    case 0x60821E7E: { // 1710-levelin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_CM3u2TM7_sendMessage);
      break;
    }
    case 0x2917EC99: { // 1710-levelout
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_K6mrzayL_sendMessage);
      break;
    }
    case 0xA773C924: { // 1722-levelin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_FMhQvKP8_sendMessage);
      break;
    }
    case 0xCA11C605: { // 1722-levelout
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_NLFpyWGf_sendMessage);
      break;
    }
    case 0xCE5CC65B: { // __hv_init
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_tZrykMO0_sendMessage);
      break;
    }
    case 0x67E37CA3: { // __hv_notein
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_HfIlgq1D_sendMessage);
      break;
    }
    case 0x40AA4AF1: { // changesound
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_DXbynMog_sendMessage);
      break;
    }
    case 0xA41806F7: { // distortlevel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_V3Ch0YsM_sendMessage);
      break;
    }
    case 0xFCD12E4C: { // mastervolume
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_cJuiuTEb_sendMessage);
      break;
    }
    case 0xEF5F3308: { // panTranslation
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_61PVQMSs_sendMessage);
      break;
    }
    case 0x58FBFA93: { // phaseFreq
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_ChG0pS8g_sendMessage);
      break;
    }
    case 0x8B2148DD: { // pitch
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_46kiA3qm_sendMessage);
      break;
    }
    case 0x4409C659: { // processeffects
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_90GNHSya_sendMessage);
      break;
    }
    case 0x7B795C5A: { // resetsing
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_0B4HNIal_sendMessage);
      break;
    }
    case 0xA987B741: { // reverbvolume
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_rhMuCMt4_sendMessage);
      break;
    }
    case 0x7AAE6786: { // sinPanAngle
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_jQPTW08B_sendMessage);
      break;
    }
    case 0x6731B2E0: { // sing
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_pXdL8bTu_sendMessage);
      break;
    }
    case 0x57292445: { // singlevel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_RpWWRCwt_sendMessage);
      break;
    }
    case 0xC7DE3B07: { // singpitch
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_b3mkhP8y_sendMessage);
      break;
    }
    case 0x4E809B1C: { // testbutton
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_QinxAnpD_sendMessage);
      break;
    }
    case 0x853B1BE7: { // velocity
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_SHnLV9E2_sendMessage);
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


void Heavy_CircleStrings::cSlice_WHLC3370_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_CMc4gIZ8_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cSlice_cSd8zlmu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cIf_onMessage(_c, &Context(_c)->cIf_HDjUjixc, 0, m, &cIf_HDjUjixc_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_KuyP4YvJ, 0, m, &cIf_KuyP4YvJ_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cSlice_OcDc4dL4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cIf_onMessage(_c, &Context(_c)->cIf_udFYo8iR, 0, m, &cIf_udFYo8iR_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_GqBQqr3O, 0, m, &cIf_GqBQqr3O_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cVar_ZDzcTu3w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_eCEXetEl_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_PEbysWy5, 0, m, &cIf_PEbysWy5_sendMessage);
}

void Heavy_CircleStrings::cUnop_EfYBHeUv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_WBzt9Zu3_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_ZjiYq2Gm, HV_BINOP_EQ, 1, m, &cBinop_ZjiYq2Gm_sendMessage);
}

void Heavy_CircleStrings::cUnop_IeE0qKuu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_WBzt9Zu3_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_ZjiYq2Gm, HV_BINOP_EQ, 1, m, &cBinop_ZjiYq2Gm_sendMessage);
}

void Heavy_CircleStrings::cIf_PEbysWy5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_IeE0qKuu_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_EfYBHeUv_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_eCEXetEl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_PEbysWy5, 1, m, &cIf_PEbysWy5_sendMessage);
}

void Heavy_CircleStrings::cIf_KuyP4YvJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSend_FsDLJ4TL_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cIf_GqBQqr3O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSend_7dcVOQfI_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cIf_HDjUjixc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSend_FsDLJ4TL_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cIf_udFYo8iR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSend_7dcVOQfI_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_CMc4gIZ8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ZjiYq2Gm, HV_BINOP_EQ, 0, m, &cBinop_ZjiYq2Gm_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_VjExOGxc_sendMessage);
}

void Heavy_CircleStrings::cBinop_WBzt9Zu3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_6cij0ewy_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_u8tuigtx_sendMessage);
}

void Heavy_CircleStrings::cBinop_ZjiYq2Gm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_vLtwcmsv_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_pXbeOXHd_sendMessage);
}

void Heavy_CircleStrings::cCast_pXbeOXHd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_udFYo8iR, 1, m, &cIf_udFYo8iR_sendMessage);
}

void Heavy_CircleStrings::cCast_vLtwcmsv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_KuyP4YvJ, 1, m, &cIf_KuyP4YvJ_sendMessage);
}

void Heavy_CircleStrings::cCast_u8tuigtx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_GqBQqr3O, 1, m, &cIf_GqBQqr3O_sendMessage);
}

void Heavy_CircleStrings::cCast_6cij0ewy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_HDjUjixc, 1, m, &cIf_HDjUjixc_sendMessage);
}

void Heavy_CircleStrings::cBinop_VjExOGxc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_sLF3QqtO_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cTabhead_bFxfaTiX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MHvsctNC, HV_BINOP_SUBTRACT, 0, m, &cBinop_MHvsctNC_sendMessage);
}

void Heavy_CircleStrings::cMsg_9GROLOom_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ug4az1nz_sendMessage);
}

void Heavy_CircleStrings::cSystem_ug4az1nz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_OFAEJoiW_sendMessage);
}

void Heavy_CircleStrings::cVar_wV0HlpNw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_zprlnTrZ_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_pUrrykqG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_pUrrykqG, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_VNOwLfDV, 0, m, &cDelay_VNOwLfDV_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_ywcjT7su, 0, m, &sTabread_ywcjT7su_sendMessage);
}

void Heavy_CircleStrings::cDelay_VNOwLfDV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_VNOwLfDV, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_ywcjT7su, 0, m, &sTabread_ywcjT7su_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_VNOwLfDV, 0, m, &cDelay_VNOwLfDV_sendMessage);
}

void Heavy_CircleStrings::sTabread_ywcjT7su_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_8hxM4aG7, HV_BINOP_SUBTRACT, 0, m, &cBinop_8hxM4aG7_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_KNnwZi9v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_qkkxpdc4, HV_BINOP_MAX, 0, m, &cBinop_qkkxpdc4_sendMessage);
}

void Heavy_CircleStrings::cBinop_OFAEJoiW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_KNnwZi9v, HV_BINOP_MULTIPLY, 0, m, &cBinop_KNnwZi9v_sendMessage);
}

void Heavy_CircleStrings::cBinop_MHvsctNC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_QAneKcPN_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_ywcjT7su, 0, m, &sTabread_ywcjT7su_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_46japgvH_sendMessage);
}

void Heavy_CircleStrings::cSystem_doMjuN1g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_8hxM4aG7, HV_BINOP_SUBTRACT, 1, m, &cBinop_8hxM4aG7_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_VNOwLfDV, 2, m, &cDelay_VNOwLfDV_sendMessage);
}

void Heavy_CircleStrings::cMsg_zprlnTrZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_doMjuN1g_sendMessage);
}

void Heavy_CircleStrings::cMsg_QAneKcPN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_pUrrykqG, 0, m, &cDelay_pUrrykqG_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_VNOwLfDV, 0, m, &cDelay_VNOwLfDV_sendMessage);
}

void Heavy_CircleStrings::cMsg_5loY0EWF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_qkkxpdc4, HV_BINOP_MAX, 1, m, &cBinop_qkkxpdc4_sendMessage);
}

void Heavy_CircleStrings::cBinop_qkkxpdc4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MHvsctNC, HV_BINOP_SUBTRACT, 1, m, &cBinop_MHvsctNC_sendMessage);
}

void Heavy_CircleStrings::cCast_46japgvH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_pUrrykqG, 0, m, &cDelay_pUrrykqG_sendMessage);
}

void Heavy_CircleStrings::cBinop_s5hktp9a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_pUrrykqG, 2, m, &cDelay_pUrrykqG_sendMessage);
}

void Heavy_CircleStrings::cBinop_8hxM4aG7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_s5hktp9a_sendMessage);
}

void Heavy_CircleStrings::cCast_MTkuJjDh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_wV0HlpNw, 0, m, &cVar_wV0HlpNw_sendMessage);
  cMsg_9GROLOom_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_bFxfaTiX, 0, m, &cTabhead_bFxfaTiX_sendMessage);
}

void Heavy_CircleStrings::cTabhead_MdMvcFss_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_07moxoSM, HV_BINOP_SUBTRACT, 0, m, &cBinop_07moxoSM_sendMessage);
}

void Heavy_CircleStrings::cMsg_UMXCdHdB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_9Uwogp0Y_sendMessage);
}

void Heavy_CircleStrings::cSystem_9Uwogp0Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_tQMpmwTF_sendMessage);
}

void Heavy_CircleStrings::cVar_OvLKxvPA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Q2HYygEO_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_TXWJF1Ym_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_TXWJF1Ym, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_L0cOh9fz, 0, m, &cDelay_L0cOh9fz_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_qX2EGmbw, 0, m, &sTabread_qX2EGmbw_sendMessage);
}

void Heavy_CircleStrings::cDelay_L0cOh9fz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_L0cOh9fz, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_qX2EGmbw, 0, m, &sTabread_qX2EGmbw_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_L0cOh9fz, 0, m, &cDelay_L0cOh9fz_sendMessage);
}

void Heavy_CircleStrings::sTabread_qX2EGmbw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_3XVsNNIz, HV_BINOP_SUBTRACT, 0, m, &cBinop_3XVsNNIz_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_KDfPwFor_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_76Q9a3Ad, HV_BINOP_MAX, 0, m, &cBinop_76Q9a3Ad_sendMessage);
}

void Heavy_CircleStrings::cBinop_tQMpmwTF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_KDfPwFor, HV_BINOP_MULTIPLY, 0, m, &cBinop_KDfPwFor_sendMessage);
}

void Heavy_CircleStrings::cBinop_07moxoSM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ua732YRY_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_qX2EGmbw, 0, m, &sTabread_qX2EGmbw_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_gYLAD1m0_sendMessage);
}

void Heavy_CircleStrings::cSystem_buZM1Lfw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_3XVsNNIz, HV_BINOP_SUBTRACT, 1, m, &cBinop_3XVsNNIz_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_L0cOh9fz, 2, m, &cDelay_L0cOh9fz_sendMessage);
}

void Heavy_CircleStrings::cMsg_Q2HYygEO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_buZM1Lfw_sendMessage);
}

void Heavy_CircleStrings::cMsg_ua732YRY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_TXWJF1Ym, 0, m, &cDelay_TXWJF1Ym_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_L0cOh9fz, 0, m, &cDelay_L0cOh9fz_sendMessage);
}

void Heavy_CircleStrings::cMsg_xPy2DfeL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_76Q9a3Ad, HV_BINOP_MAX, 1, m, &cBinop_76Q9a3Ad_sendMessage);
}

void Heavy_CircleStrings::cBinop_76Q9a3Ad_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_07moxoSM, HV_BINOP_SUBTRACT, 1, m, &cBinop_07moxoSM_sendMessage);
}

void Heavy_CircleStrings::cCast_gYLAD1m0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_TXWJF1Ym, 0, m, &cDelay_TXWJF1Ym_sendMessage);
}

void Heavy_CircleStrings::cBinop_tKvdAsm0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_TXWJF1Ym, 2, m, &cDelay_TXWJF1Ym_sendMessage);
}

void Heavy_CircleStrings::cBinop_3XVsNNIz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_tKvdAsm0_sendMessage);
}

void Heavy_CircleStrings::cCast_IdPQ6cvA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_OvLKxvPA, 0, m, &cVar_OvLKxvPA_sendMessage);
  cMsg_UMXCdHdB_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_MdMvcFss, 0, m, &cTabhead_MdMvcFss_sendMessage);
}

void Heavy_CircleStrings::cTabhead_VrnFMHJK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_H0TlEE5M, HV_BINOP_SUBTRACT, 0, m, &cBinop_H0TlEE5M_sendMessage);
}

void Heavy_CircleStrings::cMsg_eWfVUjRN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_hhO1MiYx_sendMessage);
}

void Heavy_CircleStrings::cSystem_hhO1MiYx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_bAUmhmAt_sendMessage);
}

void Heavy_CircleStrings::cVar_4PwUZG4n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_E3AFa1KT_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_wIT86wHE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_wIT86wHE, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_5LEJsLlD, 0, m, &cDelay_5LEJsLlD_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_yxeMnGOd, 0, m, &sTabread_yxeMnGOd_sendMessage);
}

void Heavy_CircleStrings::cDelay_5LEJsLlD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_5LEJsLlD, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_yxeMnGOd, 0, m, &sTabread_yxeMnGOd_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_5LEJsLlD, 0, m, &cDelay_5LEJsLlD_sendMessage);
}

void Heavy_CircleStrings::sTabread_yxeMnGOd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_HngZrJRM, HV_BINOP_SUBTRACT, 0, m, &cBinop_HngZrJRM_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_qzlTyR8u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_H2MbHG7J, HV_BINOP_MAX, 0, m, &cBinop_H2MbHG7J_sendMessage);
}

void Heavy_CircleStrings::cBinop_bAUmhmAt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_qzlTyR8u, HV_BINOP_MULTIPLY, 0, m, &cBinop_qzlTyR8u_sendMessage);
}

void Heavy_CircleStrings::cBinop_H0TlEE5M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_PVBwsUTV_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_yxeMnGOd, 0, m, &sTabread_yxeMnGOd_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_IsRbaE6y_sendMessage);
}

void Heavy_CircleStrings::cSystem_B8jDnpAd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_HngZrJRM, HV_BINOP_SUBTRACT, 1, m, &cBinop_HngZrJRM_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_5LEJsLlD, 2, m, &cDelay_5LEJsLlD_sendMessage);
}

void Heavy_CircleStrings::cMsg_E3AFa1KT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_B8jDnpAd_sendMessage);
}

void Heavy_CircleStrings::cMsg_PVBwsUTV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_wIT86wHE, 0, m, &cDelay_wIT86wHE_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_5LEJsLlD, 0, m, &cDelay_5LEJsLlD_sendMessage);
}

void Heavy_CircleStrings::cMsg_ce2NNiCW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_H2MbHG7J, HV_BINOP_MAX, 1, m, &cBinop_H2MbHG7J_sendMessage);
}

void Heavy_CircleStrings::cBinop_H2MbHG7J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_H0TlEE5M, HV_BINOP_SUBTRACT, 1, m, &cBinop_H0TlEE5M_sendMessage);
}

void Heavy_CircleStrings::cCast_IsRbaE6y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_wIT86wHE, 0, m, &cDelay_wIT86wHE_sendMessage);
}

void Heavy_CircleStrings::cBinop_1N8loFxz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_wIT86wHE, 2, m, &cDelay_wIT86wHE_sendMessage);
}

void Heavy_CircleStrings::cBinop_HngZrJRM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_1N8loFxz_sendMessage);
}

void Heavy_CircleStrings::cCast_KB3G7E0B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_4PwUZG4n, 0, m, &cVar_4PwUZG4n_sendMessage);
  cMsg_eWfVUjRN_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_VrnFMHJK, 0, m, &cTabhead_VrnFMHJK_sendMessage);
}

void Heavy_CircleStrings::cTabhead_WraOhQ2g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_2cuGUmKQ, HV_BINOP_SUBTRACT, 0, m, &cBinop_2cuGUmKQ_sendMessage);
}

void Heavy_CircleStrings::cMsg_wzKLj8n8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_hGn2u5aw_sendMessage);
}

void Heavy_CircleStrings::cSystem_hGn2u5aw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_iGOu60XO_sendMessage);
}

void Heavy_CircleStrings::cVar_iIKIVMKO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_SSl43AGd_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_wlrVK1RQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_wlrVK1RQ, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_bpTRsktE, 0, m, &cDelay_bpTRsktE_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_0FARaxkz, 0, m, &sTabread_0FARaxkz_sendMessage);
}

void Heavy_CircleStrings::cDelay_bpTRsktE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_bpTRsktE, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_0FARaxkz, 0, m, &sTabread_0FARaxkz_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_bpTRsktE, 0, m, &cDelay_bpTRsktE_sendMessage);
}

void Heavy_CircleStrings::sTabread_0FARaxkz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_zZHcMFiM, HV_BINOP_SUBTRACT, 0, m, &cBinop_zZHcMFiM_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_4hD7mMmI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_J3bXEsAj, HV_BINOP_MAX, 0, m, &cBinop_J3bXEsAj_sendMessage);
}

void Heavy_CircleStrings::cBinop_iGOu60XO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4hD7mMmI, HV_BINOP_MULTIPLY, 0, m, &cBinop_4hD7mMmI_sendMessage);
}

void Heavy_CircleStrings::cBinop_2cuGUmKQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ZtP4gIiA_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_0FARaxkz, 0, m, &sTabread_0FARaxkz_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_eS5gNjPa_sendMessage);
}

void Heavy_CircleStrings::cSystem_l04W5zEz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_zZHcMFiM, HV_BINOP_SUBTRACT, 1, m, &cBinop_zZHcMFiM_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_bpTRsktE, 2, m, &cDelay_bpTRsktE_sendMessage);
}

void Heavy_CircleStrings::cMsg_SSl43AGd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_l04W5zEz_sendMessage);
}

void Heavy_CircleStrings::cMsg_ZtP4gIiA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_wlrVK1RQ, 0, m, &cDelay_wlrVK1RQ_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_bpTRsktE, 0, m, &cDelay_bpTRsktE_sendMessage);
}

void Heavy_CircleStrings::cMsg_z4Hl6qWZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_J3bXEsAj, HV_BINOP_MAX, 1, m, &cBinop_J3bXEsAj_sendMessage);
}

void Heavy_CircleStrings::cBinop_J3bXEsAj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_2cuGUmKQ, HV_BINOP_SUBTRACT, 1, m, &cBinop_2cuGUmKQ_sendMessage);
}

void Heavy_CircleStrings::cCast_eS5gNjPa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_wlrVK1RQ, 0, m, &cDelay_wlrVK1RQ_sendMessage);
}

void Heavy_CircleStrings::cBinop_JI6UpyIM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_wlrVK1RQ, 2, m, &cDelay_wlrVK1RQ_sendMessage);
}

void Heavy_CircleStrings::cBinop_zZHcMFiM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_JI6UpyIM_sendMessage);
}

void Heavy_CircleStrings::cCast_R0fLVvDW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_iIKIVMKO, 0, m, &cVar_iIKIVMKO_sendMessage);
  cMsg_wzKLj8n8_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_WraOhQ2g, 0, m, &cTabhead_WraOhQ2g_sendMessage);
}

void Heavy_CircleStrings::cMsg_e1JlqWjd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_iQpuOo8n_sendMessage);
}

void Heavy_CircleStrings::cSystem_iQpuOo8n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_X3RXsYgO_sendMessage);
}

void Heavy_CircleStrings::cDelay_UgKdb1UA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_UgKdb1UA, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_0eD3uHmO, 0, m, &cDelay_0eD3uHmO_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_UgKdb1UA, 0, m, &cDelay_UgKdb1UA_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_Mq1Sp84A, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_0eD3uHmO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_0eD3uHmO, m);
  cMsg_YZYreM8o_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_AP0GzCSt_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_Ubk8QUQ0_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_a6fNii0w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_t92l0Rn7_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_VjGitjUm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_oUfrI9EZ_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_UgKdb1UA, 2, m, &cDelay_UgKdb1UA_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_YrDx7V74_sendMessage);
}

void Heavy_CircleStrings::cMsg_t92l0Rn7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_VjGitjUm, 0, m, &hTable_VjGitjUm_sendMessage);
}

void Heavy_CircleStrings::cBinop_X3RXsYgO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 58.6435f, 0, m, &cBinop_a6fNii0w_sendMessage);
}

void Heavy_CircleStrings::cMsg_YZYreM8o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_VjGitjUm, 0, m, &hTable_VjGitjUm_sendMessage);
}

void Heavy_CircleStrings::cCast_YrDx7V74_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_UgKdb1UA, 0, m, &cDelay_UgKdb1UA_sendMessage);
}

void Heavy_CircleStrings::cMsg_oUfrI9EZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_0eD3uHmO, 2, m, &cDelay_0eD3uHmO_sendMessage);
}

void Heavy_CircleStrings::cMsg_Ubk8QUQ0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_Mq1Sp84A, 1, m, NULL);
}

void Heavy_CircleStrings::cMsg_DMwIWsTx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_XU6fFeZ9_sendMessage);
}

void Heavy_CircleStrings::cSystem_XU6fFeZ9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_7cWoPizS_sendMessage);
}

void Heavy_CircleStrings::cDelay_UUYmsL8M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_UUYmsL8M, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_BCnbgvOC, 0, m, &cDelay_BCnbgvOC_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_UUYmsL8M, 0, m, &cDelay_UUYmsL8M_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_sSh6lvI0, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_BCnbgvOC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_BCnbgvOC, m);
  cMsg_XeDQaxQY_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_rFhs424g_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_WwsONg2G_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_1OlyBpqK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_37kM7QfT_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_1yNlBKZm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_m3bd0oL6_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_UUYmsL8M, 2, m, &cDelay_UUYmsL8M_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_FmwMOPae_sendMessage);
}

void Heavy_CircleStrings::cMsg_37kM7QfT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_1yNlBKZm, 0, m, &hTable_1yNlBKZm_sendMessage);
}

void Heavy_CircleStrings::cBinop_7cWoPizS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 69.4325f, 0, m, &cBinop_1OlyBpqK_sendMessage);
}

void Heavy_CircleStrings::cMsg_XeDQaxQY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_1yNlBKZm, 0, m, &hTable_1yNlBKZm_sendMessage);
}

void Heavy_CircleStrings::cCast_FmwMOPae_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_UUYmsL8M, 0, m, &cDelay_UUYmsL8M_sendMessage);
}

void Heavy_CircleStrings::cMsg_m3bd0oL6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_BCnbgvOC, 2, m, &cDelay_BCnbgvOC_sendMessage);
}

void Heavy_CircleStrings::cMsg_WwsONg2G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_sSh6lvI0, 1, m, NULL);
}

void Heavy_CircleStrings::cMsg_oD9IrDz5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_TsdjsRIq_sendMessage);
}

void Heavy_CircleStrings::cSystem_TsdjsRIq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_UB9Bh5qt_sendMessage);
}

void Heavy_CircleStrings::cDelay_sehfXdXe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_sehfXdXe, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_jyKYM4OU, 0, m, &cDelay_jyKYM4OU_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_sehfXdXe, 0, m, &cDelay_sehfXdXe_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_Lp38jFK6, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_jyKYM4OU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_jyKYM4OU, m);
  cMsg_9bz678Jz_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_WOMF5Kji_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_NI942fOP_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_SRVYFwZY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_b9O5pwPt_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_Vl89S9S8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_62NtYjoa_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_sehfXdXe, 2, m, &cDelay_sehfXdXe_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_NfE4lwV5_sendMessage);
}

void Heavy_CircleStrings::cMsg_b9O5pwPt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_Vl89S9S8, 0, m, &hTable_Vl89S9S8_sendMessage);
}

void Heavy_CircleStrings::cBinop_UB9Bh5qt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 74.5234f, 0, m, &cBinop_SRVYFwZY_sendMessage);
}

void Heavy_CircleStrings::cMsg_9bz678Jz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_Vl89S9S8, 0, m, &hTable_Vl89S9S8_sendMessage);
}

void Heavy_CircleStrings::cCast_NfE4lwV5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_sehfXdXe, 0, m, &cDelay_sehfXdXe_sendMessage);
}

void Heavy_CircleStrings::cMsg_62NtYjoa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_jyKYM4OU, 2, m, &cDelay_jyKYM4OU_sendMessage);
}

void Heavy_CircleStrings::cMsg_NI942fOP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_Lp38jFK6, 1, m, NULL);
}

void Heavy_CircleStrings::cMsg_Y9CJUGqU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_IErmKmBS_sendMessage);
}

void Heavy_CircleStrings::cSystem_IErmKmBS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_BpNJjHZr_sendMessage);
}

void Heavy_CircleStrings::cDelay_k75fGOaW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_k75fGOaW, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Wrm5RvtG, 0, m, &cDelay_Wrm5RvtG_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_k75fGOaW, 0, m, &cDelay_k75fGOaW_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_uClPPI22, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_Wrm5RvtG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Wrm5RvtG, m);
  cMsg_C5rIbyIh_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_JCX7n6vS_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_3uEhhMpR_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_w4zvIboW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_zw9bejJh_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_tGr4wwQI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_meSMhTOs_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_k75fGOaW, 2, m, &cDelay_k75fGOaW_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_3ChQVR9g_sendMessage);
}

void Heavy_CircleStrings::cMsg_zw9bejJh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_tGr4wwQI, 0, m, &hTable_tGr4wwQI_sendMessage);
}

void Heavy_CircleStrings::cBinop_BpNJjHZr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 86.1244f, 0, m, &cBinop_w4zvIboW_sendMessage);
}

void Heavy_CircleStrings::cMsg_C5rIbyIh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_tGr4wwQI, 0, m, &hTable_tGr4wwQI_sendMessage);
}

void Heavy_CircleStrings::cCast_3ChQVR9g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_k75fGOaW, 0, m, &cDelay_k75fGOaW_sendMessage);
}

void Heavy_CircleStrings::cMsg_meSMhTOs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_Wrm5RvtG, 2, m, &cDelay_Wrm5RvtG_sendMessage);
}

void Heavy_CircleStrings::cMsg_3uEhhMpR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_uClPPI22, 1, m, NULL);
}

void Heavy_CircleStrings::cIf_aJPsfG8q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_xa3C9lAY_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_zY1hlbdH_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cMsg_wHqsljWj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_pycMEp4d, HV_BINOP_POW, 0, m, &cBinop_pycMEp4d_sendMessage);
}

void Heavy_CircleStrings::cBinop_pycMEp4d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.125f, 0, m, &cBinop_If7I7TBn_sendMessage);
}

void Heavy_CircleStrings::cBinop_uuujyZwp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_w1EN785U_sendMessage);
}

void Heavy_CircleStrings::cCast_rTg73xPY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_aJPsfG8q, 0, m, &cIf_aJPsfG8q_sendMessage);
}

void Heavy_CircleStrings::cCast_25dYB0g8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_wm6xV6bV_sendMessage);
}

void Heavy_CircleStrings::cBinop_wm6xV6bV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_aJPsfG8q, 1, m, &cIf_aJPsfG8q_sendMessage);
}

void Heavy_CircleStrings::cBinop_zY1hlbdH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_uuujyZwp_sendMessage);
}

void Heavy_CircleStrings::cMsg_xa3C9lAY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.125f, 0, m, &cBinop_If7I7TBn_sendMessage);
}

void Heavy_CircleStrings::cBinop_w1EN785U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_pycMEp4d, HV_BINOP_POW, 1, m, &cBinop_pycMEp4d_sendMessage);
  cMsg_wHqsljWj_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cPack_Svh0sPrD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_uzqrU8zH, 0, m, NULL);
}

void Heavy_CircleStrings::cPack_pASNgx7Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_6bwWLUBX, 0, m, NULL);
}

void Heavy_CircleStrings::cBinop_PccyZYhT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_QqIFtUMi_sendMessage);
}

void Heavy_CircleStrings::cBinop_QqIFtUMi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 200.0f, 0, m, &cBinop_1ci1zAtH_sendMessage);
}

void Heavy_CircleStrings::cVar_8LJGdBjr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_mfNymDjS, HV_BINOP_MULTIPLY, 0, m, &cBinop_mfNymDjS_sendMessage);
}

void Heavy_CircleStrings::cMsg_LTEO30mm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_fbf6JsSs_sendMessage);
}

void Heavy_CircleStrings::cSystem_fbf6JsSs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_SniXWaXy_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_mfNymDjS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_Zdveg2F9_sendMessage);
}

void Heavy_CircleStrings::cBinop_KWBt8fJV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_mfNymDjS, HV_BINOP_MULTIPLY, 1, m, &cBinop_mfNymDjS_sendMessage);
}

void Heavy_CircleStrings::cMsg_SniXWaXy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_KWBt8fJV_sendMessage);
}

void Heavy_CircleStrings::cBinop_Zdveg2F9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_YhCQv1wE_sendMessage);
}

void Heavy_CircleStrings::cBinop_YhCQv1wE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_kscb5mzZ_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_ct5nnFHj, m);
}

void Heavy_CircleStrings::cBinop_kscb5mzZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_VgADkB3Q, m);
}

void Heavy_CircleStrings::cVar_UsY1wa68_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_25dYB0g8_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_rTg73xPY_sendMessage);
}

void Heavy_CircleStrings::cVar_Tn0F1Q3X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 100.0f, 0, m, &cBinop_PccyZYhT_sendMessage);
}

void Heavy_CircleStrings::cVar_wiXZaPgr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_ztc0BGjt_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_0FGCkbZ6, 0, m, &cIf_0FGCkbZ6_sendMessage);
}

void Heavy_CircleStrings::cVar_8iahlenK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 100.0f, 0, m, &cBinop_jbuk8y0a_sendMessage);
}

void Heavy_CircleStrings::cIf_0FGCkbZ6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_XkKWhwgN_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cVar_onMessage(_c, &Context(_c)->cVar_PhPurmce, 0, m, &cVar_PhPurmce_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_ztc0BGjt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_0FGCkbZ6, 1, m, &cIf_0FGCkbZ6_sendMessage);
}

void Heavy_CircleStrings::cBinop_jbuk8y0a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_9ETGAzIY_sendMessage);
}

void Heavy_CircleStrings::cBinop_9ETGAzIY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_mhUMjZuf, 0, m, &cVar_mhUMjZuf_sendMessage);
}

void Heavy_CircleStrings::cTabhead_8gY1XbVk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_FKkpjFjE, HV_BINOP_SUBTRACT, 0, m, &cBinop_FKkpjFjE_sendMessage);
}

void Heavy_CircleStrings::cMsg_4E6u3FyK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_TKN3YOTT_sendMessage);
}

void Heavy_CircleStrings::cSystem_TKN3YOTT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_is0hoaal_sendMessage);
}

void Heavy_CircleStrings::cVar_7L2XjG1F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_WguEdzqK_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_0P5OQRDA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_0P5OQRDA, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_RlLmDDra, 0, m, &cDelay_RlLmDDra_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_mdnOTK7O, 0, m, &sTabread_mdnOTK7O_sendMessage);
}

void Heavy_CircleStrings::cDelay_RlLmDDra_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_RlLmDDra, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_mdnOTK7O, 0, m, &sTabread_mdnOTK7O_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_RlLmDDra, 0, m, &cDelay_RlLmDDra_sendMessage);
}

void Heavy_CircleStrings::sTabread_mdnOTK7O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_aTRKAD6q, HV_BINOP_SUBTRACT, 0, m, &cBinop_aTRKAD6q_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_7uWLEae0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Nu1nRwrp, HV_BINOP_MAX, 0, m, &cBinop_Nu1nRwrp_sendMessage);
}

void Heavy_CircleStrings::cBinop_is0hoaal_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_7uWLEae0, HV_BINOP_MULTIPLY, 0, m, &cBinop_7uWLEae0_sendMessage);
}

void Heavy_CircleStrings::cBinop_FKkpjFjE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ctymOuoj_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_mdnOTK7O, 0, m, &sTabread_mdnOTK7O_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_13tsqvQo_sendMessage);
}

void Heavy_CircleStrings::cSystem_wQdKAFd8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_aTRKAD6q, HV_BINOP_SUBTRACT, 1, m, &cBinop_aTRKAD6q_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_RlLmDDra, 2, m, &cDelay_RlLmDDra_sendMessage);
}

void Heavy_CircleStrings::cMsg_WguEdzqK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_wQdKAFd8_sendMessage);
}

void Heavy_CircleStrings::cMsg_ctymOuoj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_0P5OQRDA, 0, m, &cDelay_0P5OQRDA_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_RlLmDDra, 0, m, &cDelay_RlLmDDra_sendMessage);
}

void Heavy_CircleStrings::cMsg_2Kqpe1pH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_Nu1nRwrp, HV_BINOP_MAX, 1, m, &cBinop_Nu1nRwrp_sendMessage);
}

void Heavy_CircleStrings::cBinop_Nu1nRwrp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_FKkpjFjE, HV_BINOP_SUBTRACT, 1, m, &cBinop_FKkpjFjE_sendMessage);
}

void Heavy_CircleStrings::cCast_13tsqvQo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_0P5OQRDA, 0, m, &cDelay_0P5OQRDA_sendMessage);
}

void Heavy_CircleStrings::cBinop_CHNovKRf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_0P5OQRDA, 2, m, &cDelay_0P5OQRDA_sendMessage);
}

void Heavy_CircleStrings::cBinop_aTRKAD6q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_CHNovKRf_sendMessage);
}

void Heavy_CircleStrings::cCast_L0Uqekqt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_7L2XjG1F, 0, m, &cVar_7L2XjG1F_sendMessage);
  cMsg_4E6u3FyK_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_8gY1XbVk, 0, m, &cTabhead_8gY1XbVk_sendMessage);
}

void Heavy_CircleStrings::cMsg_szfEii68_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_6HXCC4Xu_sendMessage);
}

void Heavy_CircleStrings::cSystem_6HXCC4Xu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_P5YADUWf_sendMessage);
}

void Heavy_CircleStrings::cDelay_n26YEsmj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_n26YEsmj, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ubAShj59, 0, m, &cDelay_ubAShj59_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_n26YEsmj, 0, m, &cDelay_n26YEsmj_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_RhGEUY4H, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_ubAShj59_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_ubAShj59, m);
  cMsg_emib9g8u_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_9nnmbbIB_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_lX4A8PP0_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_t4IeAB6m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_pNBQ4njt_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_8zkdx3Ry_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_OTMzpl5s_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_n26YEsmj, 2, m, &cDelay_n26YEsmj_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_8d0ChfTO_sendMessage);
}

void Heavy_CircleStrings::cMsg_pNBQ4njt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_8zkdx3Ry, 0, m, &hTable_8zkdx3Ry_sendMessage);
}

void Heavy_CircleStrings::cBinop_P5YADUWf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 13.645f, 0, m, &cBinop_t4IeAB6m_sendMessage);
}

void Heavy_CircleStrings::cMsg_emib9g8u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_8zkdx3Ry, 0, m, &hTable_8zkdx3Ry_sendMessage);
}

void Heavy_CircleStrings::cCast_8d0ChfTO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_n26YEsmj, 0, m, &cDelay_n26YEsmj_sendMessage);
}

void Heavy_CircleStrings::cMsg_OTMzpl5s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_ubAShj59, 2, m, &cDelay_ubAShj59_sendMessage);
}

void Heavy_CircleStrings::cMsg_lX4A8PP0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_RhGEUY4H, 1, m, NULL);
}

void Heavy_CircleStrings::cTabhead_DXWbipj5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_PuVXk7sG, HV_BINOP_SUBTRACT, 0, m, &cBinop_PuVXk7sG_sendMessage);
}

void Heavy_CircleStrings::cMsg_Xhm1uhYx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_sTZ30hJs_sendMessage);
}

void Heavy_CircleStrings::cSystem_sTZ30hJs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_l5tjsDg2_sendMessage);
}

void Heavy_CircleStrings::cVar_dlHrsWtW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_kbMmwQXc_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_2rwDErTA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_2rwDErTA, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_HvY5rFUP, 0, m, &cDelay_HvY5rFUP_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_TirDdr2E, 0, m, &sTabread_TirDdr2E_sendMessage);
}

void Heavy_CircleStrings::cDelay_HvY5rFUP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_HvY5rFUP, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_TirDdr2E, 0, m, &sTabread_TirDdr2E_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_HvY5rFUP, 0, m, &cDelay_HvY5rFUP_sendMessage);
}

void Heavy_CircleStrings::sTabread_TirDdr2E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_QVWsypLa, HV_BINOP_SUBTRACT, 0, m, &cBinop_QVWsypLa_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_2Xgr1Lvk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_BCqjoOcz, HV_BINOP_MAX, 0, m, &cBinop_BCqjoOcz_sendMessage);
}

void Heavy_CircleStrings::cBinop_l5tjsDg2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_2Xgr1Lvk, HV_BINOP_MULTIPLY, 0, m, &cBinop_2Xgr1Lvk_sendMessage);
}

void Heavy_CircleStrings::cBinop_PuVXk7sG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_e7puJkvK_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_TirDdr2E, 0, m, &sTabread_TirDdr2E_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_86dMpBPI_sendMessage);
}

void Heavy_CircleStrings::cSystem_fPFWdGzu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_QVWsypLa, HV_BINOP_SUBTRACT, 1, m, &cBinop_QVWsypLa_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_HvY5rFUP, 2, m, &cDelay_HvY5rFUP_sendMessage);
}

void Heavy_CircleStrings::cMsg_kbMmwQXc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_fPFWdGzu_sendMessage);
}

void Heavy_CircleStrings::cMsg_e7puJkvK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_2rwDErTA, 0, m, &cDelay_2rwDErTA_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_HvY5rFUP, 0, m, &cDelay_HvY5rFUP_sendMessage);
}

void Heavy_CircleStrings::cMsg_5ARccrPy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_BCqjoOcz, HV_BINOP_MAX, 1, m, &cBinop_BCqjoOcz_sendMessage);
}

void Heavy_CircleStrings::cBinop_BCqjoOcz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_PuVXk7sG, HV_BINOP_SUBTRACT, 1, m, &cBinop_PuVXk7sG_sendMessage);
}

void Heavy_CircleStrings::cCast_86dMpBPI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_2rwDErTA, 0, m, &cDelay_2rwDErTA_sendMessage);
}

void Heavy_CircleStrings::cBinop_6t72NCBZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_2rwDErTA, 2, m, &cDelay_2rwDErTA_sendMessage);
}

void Heavy_CircleStrings::cBinop_QVWsypLa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_6t72NCBZ_sendMessage);
}

void Heavy_CircleStrings::cCast_JhvxpxMu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_dlHrsWtW, 0, m, &cVar_dlHrsWtW_sendMessage);
  cMsg_Xhm1uhYx_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_DXWbipj5, 0, m, &cTabhead_DXWbipj5_sendMessage);
}

void Heavy_CircleStrings::cMsg_JRlypzck_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_eN8xWVW2_sendMessage);
}

void Heavy_CircleStrings::cSystem_eN8xWVW2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_eeUqUSAH_sendMessage);
}

void Heavy_CircleStrings::cDelay_TUoTq2rW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_TUoTq2rW, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_99p6cEpE, 0, m, &cDelay_99p6cEpE_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_TUoTq2rW, 0, m, &cDelay_TUoTq2rW_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_kHoR6950, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_99p6cEpE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_99p6cEpE, m);
  cMsg_bC63ctA2_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_3ce1EoDq_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_m4nfSu83_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_7AjuZFM9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_W1cdX8RH_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_pTOltC5v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_rBNjmniH_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_TUoTq2rW, 2, m, &cDelay_TUoTq2rW_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_womnFp8h_sendMessage);
}

void Heavy_CircleStrings::cMsg_W1cdX8RH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_pTOltC5v, 0, m, &hTable_pTOltC5v_sendMessage);
}

void Heavy_CircleStrings::cBinop_eeUqUSAH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 16.364f, 0, m, &cBinop_7AjuZFM9_sendMessage);
}

void Heavy_CircleStrings::cMsg_bC63ctA2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_pTOltC5v, 0, m, &hTable_pTOltC5v_sendMessage);
}

void Heavy_CircleStrings::cCast_womnFp8h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_TUoTq2rW, 0, m, &cDelay_TUoTq2rW_sendMessage);
}

void Heavy_CircleStrings::cMsg_rBNjmniH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_99p6cEpE, 2, m, &cDelay_99p6cEpE_sendMessage);
}

void Heavy_CircleStrings::cMsg_m4nfSu83_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_kHoR6950, 1, m, NULL);
}

void Heavy_CircleStrings::cTabhead_hQym7h4O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_LjomvqwD, HV_BINOP_SUBTRACT, 0, m, &cBinop_LjomvqwD_sendMessage);
}

void Heavy_CircleStrings::cMsg_tyQI5Imy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_A15iQFwp_sendMessage);
}

void Heavy_CircleStrings::cSystem_A15iQFwp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_lbn8JFNm_sendMessage);
}

void Heavy_CircleStrings::cVar_zPUihtmJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_LFG2A368_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_LabxNM1M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_LabxNM1M, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_VNkMW7UY, 0, m, &cDelay_VNkMW7UY_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_kfbBBM5d, 0, m, &sTabread_kfbBBM5d_sendMessage);
}

void Heavy_CircleStrings::cDelay_VNkMW7UY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_VNkMW7UY, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_kfbBBM5d, 0, m, &sTabread_kfbBBM5d_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_VNkMW7UY, 0, m, &cDelay_VNkMW7UY_sendMessage);
}

void Heavy_CircleStrings::sTabread_kfbBBM5d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_GnIHNDw8, HV_BINOP_SUBTRACT, 0, m, &cBinop_GnIHNDw8_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_4sJUHREm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_kdJn05Wo, HV_BINOP_MAX, 0, m, &cBinop_kdJn05Wo_sendMessage);
}

void Heavy_CircleStrings::cBinop_lbn8JFNm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4sJUHREm, HV_BINOP_MULTIPLY, 0, m, &cBinop_4sJUHREm_sendMessage);
}

void Heavy_CircleStrings::cBinop_LjomvqwD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_0Lq1Jy0G_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_kfbBBM5d, 0, m, &sTabread_kfbBBM5d_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_AkCZD7F8_sendMessage);
}

void Heavy_CircleStrings::cSystem_uUq1i0Rj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_GnIHNDw8, HV_BINOP_SUBTRACT, 1, m, &cBinop_GnIHNDw8_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_VNkMW7UY, 2, m, &cDelay_VNkMW7UY_sendMessage);
}

void Heavy_CircleStrings::cMsg_LFG2A368_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_uUq1i0Rj_sendMessage);
}

void Heavy_CircleStrings::cMsg_0Lq1Jy0G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_LabxNM1M, 0, m, &cDelay_LabxNM1M_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_VNkMW7UY, 0, m, &cDelay_VNkMW7UY_sendMessage);
}

void Heavy_CircleStrings::cMsg_qcyPwM0K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_kdJn05Wo, HV_BINOP_MAX, 1, m, &cBinop_kdJn05Wo_sendMessage);
}

void Heavy_CircleStrings::cBinop_kdJn05Wo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_LjomvqwD, HV_BINOP_SUBTRACT, 1, m, &cBinop_LjomvqwD_sendMessage);
}

void Heavy_CircleStrings::cCast_AkCZD7F8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_LabxNM1M, 0, m, &cDelay_LabxNM1M_sendMessage);
}

void Heavy_CircleStrings::cBinop_G3fhfU27_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_LabxNM1M, 2, m, &cDelay_LabxNM1M_sendMessage);
}

void Heavy_CircleStrings::cBinop_GnIHNDw8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_G3fhfU27_sendMessage);
}

void Heavy_CircleStrings::cCast_3VfbaDws_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_zPUihtmJ, 0, m, &cVar_zPUihtmJ_sendMessage);
  cMsg_tyQI5Imy_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_hQym7h4O, 0, m, &cTabhead_hQym7h4O_sendMessage);
}

void Heavy_CircleStrings::cMsg_bFAPUi6K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_0ok17dHJ_sendMessage);
}

void Heavy_CircleStrings::cSystem_0ok17dHJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_XqS5OmHp_sendMessage);
}

void Heavy_CircleStrings::cDelay_LPyvyOWc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_LPyvyOWc, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ASwfuSEe, 0, m, &cDelay_ASwfuSEe_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_LPyvyOWc, 0, m, &cDelay_LPyvyOWc_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_ejTtB6aH, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_ASwfuSEe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_ASwfuSEe, m);
  cMsg_iTk1Ymmm_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_Yln40DYu_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_WEsBYLLX_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_CQskmgDQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_XdCOmBFS_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_x9dQjkz4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_bnZv2QZO_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_LPyvyOWc, 2, m, &cDelay_LPyvyOWc_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_XKC42bQL_sendMessage);
}

void Heavy_CircleStrings::cMsg_XdCOmBFS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_x9dQjkz4, 0, m, &hTable_x9dQjkz4_sendMessage);
}

void Heavy_CircleStrings::cBinop_XqS5OmHp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 19.392f, 0, m, &cBinop_CQskmgDQ_sendMessage);
}

void Heavy_CircleStrings::cMsg_iTk1Ymmm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_x9dQjkz4, 0, m, &hTable_x9dQjkz4_sendMessage);
}

void Heavy_CircleStrings::cCast_XKC42bQL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_LPyvyOWc, 0, m, &cDelay_LPyvyOWc_sendMessage);
}

void Heavy_CircleStrings::cMsg_bnZv2QZO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_ASwfuSEe, 2, m, &cDelay_ASwfuSEe_sendMessage);
}

void Heavy_CircleStrings::cMsg_WEsBYLLX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_ejTtB6aH, 1, m, NULL);
}

void Heavy_CircleStrings::cTabhead_IjB0ZulE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_GKoweOLq, HV_BINOP_SUBTRACT, 0, m, &cBinop_GKoweOLq_sendMessage);
}

void Heavy_CircleStrings::cMsg_JhT288bn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_l2S6UFMX_sendMessage);
}

void Heavy_CircleStrings::cSystem_l2S6UFMX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_9YcR5Mrc_sendMessage);
}

void Heavy_CircleStrings::cVar_HS0sEN5a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_5JpDBgLx_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_GCgNbZPh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_GCgNbZPh, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_5KpbaNZ6, 0, m, &cDelay_5KpbaNZ6_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_nHNLlL2V, 0, m, &sTabread_nHNLlL2V_sendMessage);
}

void Heavy_CircleStrings::cDelay_5KpbaNZ6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_5KpbaNZ6, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_nHNLlL2V, 0, m, &sTabread_nHNLlL2V_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_5KpbaNZ6, 0, m, &cDelay_5KpbaNZ6_sendMessage);
}

void Heavy_CircleStrings::sTabread_nHNLlL2V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_hFSVehYt, HV_BINOP_SUBTRACT, 0, m, &cBinop_hFSVehYt_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_MbHCx8jH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ATKWt2tR, HV_BINOP_MAX, 0, m, &cBinop_ATKWt2tR_sendMessage);
}

void Heavy_CircleStrings::cBinop_9YcR5Mrc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MbHCx8jH, HV_BINOP_MULTIPLY, 0, m, &cBinop_MbHCx8jH_sendMessage);
}

void Heavy_CircleStrings::cBinop_GKoweOLq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ZaauAMHN_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_nHNLlL2V, 0, m, &sTabread_nHNLlL2V_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_0PAjOlFa_sendMessage);
}

void Heavy_CircleStrings::cSystem_IKBSHUrP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_hFSVehYt, HV_BINOP_SUBTRACT, 1, m, &cBinop_hFSVehYt_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_5KpbaNZ6, 2, m, &cDelay_5KpbaNZ6_sendMessage);
}

void Heavy_CircleStrings::cMsg_5JpDBgLx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_IKBSHUrP_sendMessage);
}

void Heavy_CircleStrings::cMsg_ZaauAMHN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_GCgNbZPh, 0, m, &cDelay_GCgNbZPh_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_5KpbaNZ6, 0, m, &cDelay_5KpbaNZ6_sendMessage);
}

void Heavy_CircleStrings::cMsg_MATDoC6i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_ATKWt2tR, HV_BINOP_MAX, 1, m, &cBinop_ATKWt2tR_sendMessage);
}

void Heavy_CircleStrings::cBinop_ATKWt2tR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_GKoweOLq, HV_BINOP_SUBTRACT, 1, m, &cBinop_GKoweOLq_sendMessage);
}

void Heavy_CircleStrings::cCast_0PAjOlFa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_GCgNbZPh, 0, m, &cDelay_GCgNbZPh_sendMessage);
}

void Heavy_CircleStrings::cBinop_BfUYPNtL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_GCgNbZPh, 2, m, &cDelay_GCgNbZPh_sendMessage);
}

void Heavy_CircleStrings::cBinop_hFSVehYt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_BfUYPNtL_sendMessage);
}

void Heavy_CircleStrings::cCast_kp1FynbF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_HS0sEN5a, 0, m, &cVar_HS0sEN5a_sendMessage);
  cMsg_JhT288bn_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_IjB0ZulE, 0, m, &cTabhead_IjB0ZulE_sendMessage);
}

void Heavy_CircleStrings::cMsg_gRHZTs9a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_GMo5Td3J_sendMessage);
}

void Heavy_CircleStrings::cSystem_GMo5Td3J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_HkD1yCRj_sendMessage);
}

void Heavy_CircleStrings::cDelay_GbzgcgjF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_GbzgcgjF, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_7rknLyRm, 0, m, &cDelay_7rknLyRm_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_GbzgcgjF, 0, m, &cDelay_GbzgcgjF_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_G96thh7P, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_7rknLyRm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_7rknLyRm, m);
  cMsg_8I7GoSuf_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_cK9uRdK2_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_0rUvHYns_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_lA297OfX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_PjQpyyGF_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_2kfZz5Sk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_cxHiNU37_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_GbzgcgjF, 2, m, &cDelay_GbzgcgjF_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_JcqbmTbL_sendMessage);
}

void Heavy_CircleStrings::cMsg_PjQpyyGF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_2kfZz5Sk, 0, m, &hTable_2kfZz5Sk_sendMessage);
}

void Heavy_CircleStrings::cBinop_HkD1yCRj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 25.796f, 0, m, &cBinop_lA297OfX_sendMessage);
}

void Heavy_CircleStrings::cMsg_8I7GoSuf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_2kfZz5Sk, 0, m, &hTable_2kfZz5Sk_sendMessage);
}

void Heavy_CircleStrings::cCast_JcqbmTbL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_GbzgcgjF, 0, m, &cDelay_GbzgcgjF_sendMessage);
}

void Heavy_CircleStrings::cMsg_cxHiNU37_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_7rknLyRm, 2, m, &cDelay_7rknLyRm_sendMessage);
}

void Heavy_CircleStrings::cMsg_0rUvHYns_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_G96thh7P, 1, m, NULL);
}

void Heavy_CircleStrings::cTabhead_04PPr6iL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_wP8vlgB0, HV_BINOP_SUBTRACT, 0, m, &cBinop_wP8vlgB0_sendMessage);
}

void Heavy_CircleStrings::cMsg_H19Srgy0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_omYKZimv_sendMessage);
}

void Heavy_CircleStrings::cSystem_omYKZimv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_wuY5HdVV_sendMessage);
}

void Heavy_CircleStrings::cVar_qTN8XMKJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_rFVuk5YZ_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_T0XiBPXm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_T0XiBPXm, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_NeQkz5L9, 0, m, &cDelay_NeQkz5L9_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_2qIgAhN0, 0, m, &sTabread_2qIgAhN0_sendMessage);
}

void Heavy_CircleStrings::cDelay_NeQkz5L9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_NeQkz5L9, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_2qIgAhN0, 0, m, &sTabread_2qIgAhN0_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_NeQkz5L9, 0, m, &cDelay_NeQkz5L9_sendMessage);
}

void Heavy_CircleStrings::sTabread_2qIgAhN0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_4iWPfWH8, HV_BINOP_SUBTRACT, 0, m, &cBinop_4iWPfWH8_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_cOjOFsxJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_SWEnxSja, HV_BINOP_MAX, 0, m, &cBinop_SWEnxSja_sendMessage);
}

void Heavy_CircleStrings::cBinop_wuY5HdVV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_cOjOFsxJ, HV_BINOP_MULTIPLY, 0, m, &cBinop_cOjOFsxJ_sendMessage);
}

void Heavy_CircleStrings::cBinop_wP8vlgB0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_OsFLD00B_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_2qIgAhN0, 0, m, &sTabread_2qIgAhN0_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_AwXgdrb3_sendMessage);
}

void Heavy_CircleStrings::cSystem_2VTVHXe9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4iWPfWH8, HV_BINOP_SUBTRACT, 1, m, &cBinop_4iWPfWH8_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_NeQkz5L9, 2, m, &cDelay_NeQkz5L9_sendMessage);
}

void Heavy_CircleStrings::cMsg_rFVuk5YZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_2VTVHXe9_sendMessage);
}

void Heavy_CircleStrings::cMsg_OsFLD00B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_T0XiBPXm, 0, m, &cDelay_T0XiBPXm_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_NeQkz5L9, 0, m, &cDelay_NeQkz5L9_sendMessage);
}

void Heavy_CircleStrings::cMsg_SHpJjJBD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_SWEnxSja, HV_BINOP_MAX, 1, m, &cBinop_SWEnxSja_sendMessage);
}

void Heavy_CircleStrings::cBinop_SWEnxSja_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_wP8vlgB0, HV_BINOP_SUBTRACT, 1, m, &cBinop_wP8vlgB0_sendMessage);
}

void Heavy_CircleStrings::cCast_AwXgdrb3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_T0XiBPXm, 0, m, &cDelay_T0XiBPXm_sendMessage);
}

void Heavy_CircleStrings::cBinop_4saAM1hW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_T0XiBPXm, 2, m, &cDelay_T0XiBPXm_sendMessage);
}

void Heavy_CircleStrings::cBinop_4iWPfWH8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_4saAM1hW_sendMessage);
}

void Heavy_CircleStrings::cCast_gcvWiY88_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_qTN8XMKJ, 0, m, &cVar_qTN8XMKJ_sendMessage);
  cMsg_H19Srgy0_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_04PPr6iL, 0, m, &cTabhead_04PPr6iL_sendMessage);
}

void Heavy_CircleStrings::cMsg_2Reyfg5I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_sJ1qKwDu_sendMessage);
}

void Heavy_CircleStrings::cSystem_sJ1qKwDu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_0m7CyrZo_sendMessage);
}

void Heavy_CircleStrings::cDelay_4lthWf8X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_4lthWf8X, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_iWmjTw3T, 0, m, &cDelay_iWmjTw3T_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_4lthWf8X, 0, m, &cDelay_4lthWf8X_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_8vTQ81nk, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_iWmjTw3T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_iWmjTw3T, m);
  cMsg_9FeceV6f_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_npW6fE3c_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_OhYrJ13m_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_4nryFD9U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_uPKndNAB_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_Shq5AKqO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_r7hfwXuQ_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_4lthWf8X, 2, m, &cDelay_4lthWf8X_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_1pxuEhJd_sendMessage);
}

void Heavy_CircleStrings::cMsg_uPKndNAB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_Shq5AKqO, 0, m, &hTable_Shq5AKqO_sendMessage);
}

void Heavy_CircleStrings::cBinop_0m7CyrZo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 43.5337f, 0, m, &cBinop_4nryFD9U_sendMessage);
}

void Heavy_CircleStrings::cMsg_9FeceV6f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_Shq5AKqO, 0, m, &hTable_Shq5AKqO_sendMessage);
}

void Heavy_CircleStrings::cCast_1pxuEhJd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_4lthWf8X, 0, m, &cDelay_4lthWf8X_sendMessage);
}

void Heavy_CircleStrings::cMsg_r7hfwXuQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_iWmjTw3T, 2, m, &cDelay_iWmjTw3T_sendMessage);
}

void Heavy_CircleStrings::cMsg_OhYrJ13m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_8vTQ81nk, 1, m, NULL);
}

void Heavy_CircleStrings::cTabhead_EK6hcK0H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_EiSRWrog, HV_BINOP_SUBTRACT, 0, m, &cBinop_EiSRWrog_sendMessage);
}

void Heavy_CircleStrings::cMsg_nlrjnf74_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_rkohlf1m_sendMessage);
}

void Heavy_CircleStrings::cSystem_rkohlf1m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_AcJcbzJN_sendMessage);
}

void Heavy_CircleStrings::cVar_yvp5oFHT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_WG1xsen9_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_6Oqm83Fv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_6Oqm83Fv, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_xqzf4D4a, 0, m, &cDelay_xqzf4D4a_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_B79On196, 0, m, &sTabread_B79On196_sendMessage);
}

void Heavy_CircleStrings::cDelay_xqzf4D4a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_xqzf4D4a, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_B79On196, 0, m, &sTabread_B79On196_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_xqzf4D4a, 0, m, &cDelay_xqzf4D4a_sendMessage);
}

void Heavy_CircleStrings::sTabread_B79On196_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_hiStwKKn, HV_BINOP_SUBTRACT, 0, m, &cBinop_hiStwKKn_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_i062Zfal_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_fdsc6XCO, HV_BINOP_MAX, 0, m, &cBinop_fdsc6XCO_sendMessage);
}

void Heavy_CircleStrings::cBinop_AcJcbzJN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_i062Zfal, HV_BINOP_MULTIPLY, 0, m, &cBinop_i062Zfal_sendMessage);
}

void Heavy_CircleStrings::cBinop_EiSRWrog_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_CQHOOk06_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_B79On196, 0, m, &sTabread_B79On196_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ovWYMr45_sendMessage);
}

void Heavy_CircleStrings::cSystem_7keZiaDQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_hiStwKKn, HV_BINOP_SUBTRACT, 1, m, &cBinop_hiStwKKn_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_xqzf4D4a, 2, m, &cDelay_xqzf4D4a_sendMessage);
}

void Heavy_CircleStrings::cMsg_WG1xsen9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_7keZiaDQ_sendMessage);
}

void Heavy_CircleStrings::cMsg_CQHOOk06_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_6Oqm83Fv, 0, m, &cDelay_6Oqm83Fv_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_xqzf4D4a, 0, m, &cDelay_xqzf4D4a_sendMessage);
}

void Heavy_CircleStrings::cMsg_QL7pCvZy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_fdsc6XCO, HV_BINOP_MAX, 1, m, &cBinop_fdsc6XCO_sendMessage);
}

void Heavy_CircleStrings::cBinop_fdsc6XCO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_EiSRWrog, HV_BINOP_SUBTRACT, 1, m, &cBinop_EiSRWrog_sendMessage);
}

void Heavy_CircleStrings::cCast_ovWYMr45_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_6Oqm83Fv, 0, m, &cDelay_6Oqm83Fv_sendMessage);
}

void Heavy_CircleStrings::cBinop_IK4rdyHk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_6Oqm83Fv, 2, m, &cDelay_6Oqm83Fv_sendMessage);
}

void Heavy_CircleStrings::cBinop_hiStwKKn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_IK4rdyHk_sendMessage);
}

void Heavy_CircleStrings::cCast_98NR7qnE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_yvp5oFHT, 0, m, &cVar_yvp5oFHT_sendMessage);
  cMsg_nlrjnf74_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_EK6hcK0H, 0, m, &cTabhead_EK6hcK0H_sendMessage);
}

void Heavy_CircleStrings::cMsg_Nz7ozaPz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_J59YB0ig_sendMessage);
}

void Heavy_CircleStrings::cSystem_J59YB0ig_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_fcjGu9ru_sendMessage);
}

void Heavy_CircleStrings::cDelay_kr8oXvGo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_kr8oXvGo, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_n8RsjQ6V, 0, m, &cDelay_n8RsjQ6V_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_kr8oXvGo, 0, m, &cDelay_kr8oXvGo_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_EWFzdDQF, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_n8RsjQ6V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_n8RsjQ6V, m);
  cMsg_ZuSKQuf1_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_YHxK1kvV_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_7VLrrQ3B_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_hZVBXTra_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_226jnR9y_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_mxTyjspJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_6aMc5Cwv_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_kr8oXvGo, 2, m, &cDelay_kr8oXvGo_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_GSa9zzWd_sendMessage);
}

void Heavy_CircleStrings::cMsg_226jnR9y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_mxTyjspJ, 0, m, &hTable_mxTyjspJ_sendMessage);
}

void Heavy_CircleStrings::cBinop_fcjGu9ru_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 75.2546f, 0, m, &cBinop_hZVBXTra_sendMessage);
}

void Heavy_CircleStrings::cMsg_ZuSKQuf1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_mxTyjspJ, 0, m, &hTable_mxTyjspJ_sendMessage);
}

void Heavy_CircleStrings::cCast_GSa9zzWd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_kr8oXvGo, 0, m, &cDelay_kr8oXvGo_sendMessage);
}

void Heavy_CircleStrings::cMsg_6aMc5Cwv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_n8RsjQ6V, 2, m, &cDelay_n8RsjQ6V_sendMessage);
}

void Heavy_CircleStrings::cMsg_7VLrrQ3B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_EWFzdDQF, 1, m, NULL);
}

void Heavy_CircleStrings::cVar_PhPurmce_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_8LJGdBjr, 0, m, &cVar_8LJGdBjr_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_FQQ2DcxT, 0, m, &cVar_FQQ2DcxT_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_Km7aDGyB, 0, m, &cVar_Km7aDGyB_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_OOEpDFt5, 0, m, &cVar_OOEpDFt5_sendMessage);
}

void Heavy_CircleStrings::cVar_mhUMjZuf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.01f, 0, m, &cBinop_oP0gNFqX_sendMessage);
}

void Heavy_CircleStrings::cPack_OUXbIyoL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_SWhbiqr5, 0, m, NULL);
}

void Heavy_CircleStrings::cVar_FQQ2DcxT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_7oKX8rkc, HV_BINOP_MULTIPLY, 0, m, &cBinop_7oKX8rkc_sendMessage);
}

void Heavy_CircleStrings::cMsg_O8J4G3FE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_7Sui12ol_sendMessage);
}

void Heavy_CircleStrings::cSystem_7Sui12ol_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_AJbs9VYq_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_7oKX8rkc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_mirLIueQ_sendMessage);
}

void Heavy_CircleStrings::cBinop_otELPyyB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_7oKX8rkc, HV_BINOP_MULTIPLY, 1, m, &cBinop_7oKX8rkc_sendMessage);
}

void Heavy_CircleStrings::cMsg_AJbs9VYq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_otELPyyB_sendMessage);
}

void Heavy_CircleStrings::cBinop_mirLIueQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_Wb1loAdr_sendMessage);
}

void Heavy_CircleStrings::cBinop_Wb1loAdr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_pGoGPMsy_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_pLlRY8Vb, m);
}

void Heavy_CircleStrings::cBinop_pGoGPMsy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_ZTXdCxRr, m);
}

void Heavy_CircleStrings::cVar_Km7aDGyB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_26YsOxqc, HV_BINOP_MULTIPLY, 0, m, &cBinop_26YsOxqc_sendMessage);
}

void Heavy_CircleStrings::cMsg_gLngQSRE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_g6B1s8lq_sendMessage);
}

void Heavy_CircleStrings::cSystem_g6B1s8lq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_rnvC0RRV_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_26YsOxqc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_yfjXPLH1_sendMessage);
}

void Heavy_CircleStrings::cBinop_YEKouWfi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_26YsOxqc, HV_BINOP_MULTIPLY, 1, m, &cBinop_26YsOxqc_sendMessage);
}

void Heavy_CircleStrings::cMsg_rnvC0RRV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_YEKouWfi_sendMessage);
}

void Heavy_CircleStrings::cBinop_yfjXPLH1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_gzzB4uRK_sendMessage);
}

void Heavy_CircleStrings::cBinop_gzzB4uRK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_x3lc6KuX_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_J2LEHm81, m);
}

void Heavy_CircleStrings::cBinop_x3lc6KuX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_Lzp8pV6Y, m);
}

void Heavy_CircleStrings::cVar_OOEpDFt5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_WBniqUcV, HV_BINOP_MULTIPLY, 0, m, &cBinop_WBniqUcV_sendMessage);
}

void Heavy_CircleStrings::cMsg_SHPJNAdC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_KdfC2NLP_sendMessage);
}

void Heavy_CircleStrings::cSystem_KdfC2NLP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_olb73bVg_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_WBniqUcV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_Yvm5eYB7_sendMessage);
}

void Heavy_CircleStrings::cBinop_DeOmgi8P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_WBniqUcV, HV_BINOP_MULTIPLY, 1, m, &cBinop_WBniqUcV_sendMessage);
}

void Heavy_CircleStrings::cMsg_olb73bVg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_DeOmgi8P_sendMessage);
}

void Heavy_CircleStrings::cBinop_Yvm5eYB7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_KsKdoScp_sendMessage);
}

void Heavy_CircleStrings::cBinop_KsKdoScp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_ZQFb4jRx_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_5QWBrofr, m);
}

void Heavy_CircleStrings::cBinop_ZQFb4jRx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_GMNI2Gzz, m);
}

void Heavy_CircleStrings::cBinop_1ci1zAtH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_pASNgx7Q, 0, m, &cPack_pASNgx7Q_sendMessage);
}

void Heavy_CircleStrings::cMsg_XkKWhwgN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 3000.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_PhPurmce, 0, m, &cVar_PhPurmce_sendMessage);
}

void Heavy_CircleStrings::cBinop_oP0gNFqX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_OUXbIyoL, 0, m, &cPack_OUXbIyoL_sendMessage);
}

void Heavy_CircleStrings::cBinop_If7I7TBn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_Svh0sPrD, 0, m, &cPack_Svh0sPrD_sendMessage);
}

void Heavy_CircleStrings::cIf_NcPRsVhT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_aMgVIpwF_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_LOG10, m, &cUnop_MhBeQkgk_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cUnop_MhBeQkgk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_5BYc9pGE_sendMessage);
}

void Heavy_CircleStrings::cCast_W1Cp38dj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_NcPRsVhT, 0, m, &cIf_NcPRsVhT_sendMessage);
}

void Heavy_CircleStrings::cCast_XZ9tClRw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_luE5vDku_sendMessage);
}

void Heavy_CircleStrings::cMsg_aMgVIpwF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_UsY1wa68, 0, m, &cVar_UsY1wa68_sendMessage);
}

void Heavy_CircleStrings::cBinop_5BYc9pGE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 100.0f, 0, m, &cBinop_yhLIvOut_sendMessage);
}

void Heavy_CircleStrings::cBinop_yhLIvOut_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_TdNK5Y79_sendMessage);
}

void Heavy_CircleStrings::cBinop_TdNK5Y79_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_UsY1wa68, 0, m, &cVar_UsY1wa68_sendMessage);
}

void Heavy_CircleStrings::cBinop_luE5vDku_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_NcPRsVhT, 1, m, &cIf_NcPRsVhT_sendMessage);
}

void Heavy_CircleStrings::cBinop_ldtfAmjg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_XZ9tClRw_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_W1Cp38dj_sendMessage);
}

void Heavy_CircleStrings::cBinop_AUjjzC2t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_ldtfAmjg_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_xqMTFkdu_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_GNcSDJ3W_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_GNcSDJ3W_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_FwdBr2VK, 1, m, &cDelay_FwdBr2VK_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_DdMHBkTW_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cDelay_FwdBr2VK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_FwdBr2VK, m);
  cMsg_1gFCZUcK_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_GNcSDJ3W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_FwdBr2VK, 0, m, &cDelay_FwdBr2VK_sendMessage);
}

void Heavy_CircleStrings::cCast_DdMHBkTW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_FwdBr2VK, 0, m, &cDelay_FwdBr2VK_sendMessage);
}

void Heavy_CircleStrings::cVar_GixuPu9q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_rEvwJGWN, 0, m, &cPack_rEvwJGWN_sendMessage);
}

void Heavy_CircleStrings::cVar_427lAlvE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.05776f, 0, m, &cBinop_6Wwct2Ny_sendMessage);
}

void Heavy_CircleStrings::cVar_1ENawIex_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_RMpBSl91_sendMessage);
}

void Heavy_CircleStrings::cPack_Dye63Fxo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_dC2qmDFS, 0, m, NULL);
}

void Heavy_CircleStrings::cUnop_zCQ7lWYI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_Hld4vmRX_sendMessage);
}

void Heavy_CircleStrings::cBinop_4ttIAYjj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_EXP, m, &cUnop_zCQ7lWYI_sendMessage);
}

void Heavy_CircleStrings::cPack_1kt8obzy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_3AWksRZ0, 0, m, NULL);
}

void Heavy_CircleStrings::cVar_ahMrVFPJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.5f, 0, m, &cBinop_DcA6qXZv_sendMessage);
}

void Heavy_CircleStrings::cMsg_h7v6CSpR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Xatg7y3V_sendMessage);
}

void Heavy_CircleStrings::cSystem_Xatg7y3V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_b87Rrump_sendMessage);
}

void Heavy_CircleStrings::cDelay_i49vmS8I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_i49vmS8I, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_B3lWBMTt, 0, m, &cDelay_B3lWBMTt_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_i49vmS8I, 0, m, &cDelay_i49vmS8I_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_E1m7FFOE, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_B3lWBMTt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_B3lWBMTt, m);
  cMsg_hZprdDC2_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_5bN2AZfl_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_v6LjOEua_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_RWPMnHqG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Tzzbc1bT_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_bBdX6WS1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_G5a4mCvg_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_i49vmS8I, 2, m, &cDelay_i49vmS8I_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_CoOghbP5_sendMessage);
}

void Heavy_CircleStrings::cMsg_Tzzbc1bT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_bBdX6WS1, 0, m, &hTable_bBdX6WS1_sendMessage);
}

void Heavy_CircleStrings::cBinop_b87Rrump_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 5000.0f, 0, m, &cBinop_RWPMnHqG_sendMessage);
}

void Heavy_CircleStrings::cMsg_hZprdDC2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_bBdX6WS1, 0, m, &hTable_bBdX6WS1_sendMessage);
}

void Heavy_CircleStrings::cCast_CoOghbP5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_i49vmS8I, 0, m, &cDelay_i49vmS8I_sendMessage);
}

void Heavy_CircleStrings::cMsg_G5a4mCvg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_B3lWBMTt, 2, m, &cDelay_B3lWBMTt_sendMessage);
}

void Heavy_CircleStrings::cMsg_v6LjOEua_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_E1m7FFOE, 1, m, NULL);
}

void Heavy_CircleStrings::cMsg_kRt9htYD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_9kfa1AEg_sendMessage);
}

void Heavy_CircleStrings::cSystem_9kfa1AEg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_Srvgz8uF_sendMessage);
}

void Heavy_CircleStrings::cVar_EhN78tzK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_5C3F65s1_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSystem_M3F35I9z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_Ro7FXROQ_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_N3LQ7K9s, m);
}

void Heavy_CircleStrings::cBinop_Srvgz8uF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_kZij7zhD, m);
}

void Heavy_CircleStrings::cMsg_5C3F65s1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_M3F35I9z_sendMessage);
}

void Heavy_CircleStrings::cBinop_Ro7FXROQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_jmrBReYA, m);
}

void Heavy_CircleStrings::cMsg_9nSh7ePs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_2nOd7VYf_sendMessage);
}

void Heavy_CircleStrings::cSystem_2nOd7VYf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_gqlYRF36_sendMessage);
}

void Heavy_CircleStrings::cVar_9iyxHJcb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_pqJjLACr_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSystem_gIzMVuot_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_O03FGliD_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_alB1g67Z, m);
}

void Heavy_CircleStrings::cBinop_gqlYRF36_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_fi0IdYHn, m);
}

void Heavy_CircleStrings::cMsg_pqJjLACr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_gIzMVuot_sendMessage);
}

void Heavy_CircleStrings::cBinop_O03FGliD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_iTxHKcnV, m);
}

void Heavy_CircleStrings::cBinop_DkAuhJ4B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_sjtWtBna_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_nW9ZkPuw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_XaLoKxeB_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_IogDVCZ0_sendMessage);
}

void Heavy_CircleStrings::cCast_IogDVCZ0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_DkAuhJ4B, HV_BINOP_DIVIDE, 0, m, &cBinop_DkAuhJ4B_sendMessage);
}

void Heavy_CircleStrings::cCast_XaLoKxeB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_DkAuhJ4B, HV_BINOP_DIVIDE, 1, m, &cBinop_DkAuhJ4B_sendMessage);
}

void Heavy_CircleStrings::cBinop_Hld4vmRX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_R3y0RfAc_sendMessage);
}

void Heavy_CircleStrings::cBinop_6Wwct2Ny_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 87.3365f, 0, m, &cBinop_4ttIAYjj_sendMessage);
}

void Heavy_CircleStrings::cBinop_R3y0RfAc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_DkAuhJ4B, HV_BINOP_DIVIDE, 0, m, &cBinop_DkAuhJ4B_sendMessage);
}

void Heavy_CircleStrings::cBinop_DcA6qXZv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_1kt8obzy, 0, m, &cPack_1kt8obzy_sendMessage);
}

void Heavy_CircleStrings::cBinop_RMpBSl91_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.001f, 0, m, &cBinop_nW9ZkPuw_sendMessage);
  cPack_onMessage(_c, &Context(_c)->cPack_Dye63Fxo, 0, m, &cPack_Dye63Fxo_sendMessage);
}

void Heavy_CircleStrings::cMsg_FDzWpQbU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 100.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_1ENawIex, 0, m, &cVar_1ENawIex_sendMessage);
}

void Heavy_CircleStrings::cMsg_SoxSW8qA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.5f);
  cVar_onMessage(_c, &Context(_c)->cVar_ahMrVFPJ, 0, m, &cVar_ahMrVFPJ_sendMessage);
}

void Heavy_CircleStrings::cMsg_sjtWtBna_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 30.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_w9JQDaIN, 0, m, NULL);
}

void Heavy_CircleStrings::cVar_tC1ETIrK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6LxV0ohk, HV_BINOP_MULTIPLY, 0, m, &cBinop_6LxV0ohk_sendMessage);
}

void Heavy_CircleStrings::cMsg_IRatPKQU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_QocTF1Ad_sendMessage);
}

void Heavy_CircleStrings::cSystem_QocTF1Ad_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_JMCc63mG_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_6LxV0ohk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_nI3Yhv8P_sendMessage);
}

void Heavy_CircleStrings::cBinop_NGlnDWrM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6LxV0ohk, HV_BINOP_MULTIPLY, 1, m, &cBinop_6LxV0ohk_sendMessage);
}

void Heavy_CircleStrings::cMsg_JMCc63mG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_NGlnDWrM_sendMessage);
}

void Heavy_CircleStrings::cBinop_nI3Yhv8P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_WtlSmi05_sendMessage);
}

void Heavy_CircleStrings::cBinop_WtlSmi05_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_VwELSOoO_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_9e0AsWyy, m);
}

void Heavy_CircleStrings::cBinop_VwELSOoO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_OYekWWvr, m);
}

void Heavy_CircleStrings::cVar_pNJnok0N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_OxwmpTKC, HV_BINOP_MULTIPLY, 0, m, &cBinop_OxwmpTKC_sendMessage);
}

void Heavy_CircleStrings::cMsg_NeUouPo9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_fK8VYa5Q_sendMessage);
}

void Heavy_CircleStrings::cSystem_fK8VYa5Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Ajed1LSg_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_OxwmpTKC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_nklIqkFT_sendMessage);
}

void Heavy_CircleStrings::cBinop_QMYXxCm5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_OxwmpTKC, HV_BINOP_MULTIPLY, 1, m, &cBinop_OxwmpTKC_sendMessage);
}

void Heavy_CircleStrings::cMsg_Ajed1LSg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_QMYXxCm5_sendMessage);
}

void Heavy_CircleStrings::cBinop_nklIqkFT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_43RomQy5_sendMessage);
}

void Heavy_CircleStrings::cBinop_43RomQy5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_23FGl6lE_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_AMFe2ILE, m);
}

void Heavy_CircleStrings::cBinop_23FGl6lE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_wzcESr4V, m);
}

void Heavy_CircleStrings::cVar_1DOFW6CV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_kMLpOHww, HV_BINOP_MULTIPLY, 0, m, &cBinop_kMLpOHww_sendMessage);
}

void Heavy_CircleStrings::cMsg_Mh7fs2fl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_4vGg73mZ_sendMessage);
}

void Heavy_CircleStrings::cSystem_4vGg73mZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_qzEjZBjZ_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_kMLpOHww_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_2IhSRDxy_sendMessage);
}

void Heavy_CircleStrings::cBinop_iSBLZ7Lb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_kMLpOHww, HV_BINOP_MULTIPLY, 1, m, &cBinop_kMLpOHww_sendMessage);
}

void Heavy_CircleStrings::cMsg_qzEjZBjZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_iSBLZ7Lb_sendMessage);
}

void Heavy_CircleStrings::cBinop_2IhSRDxy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_cM4FiPlh_sendMessage);
}

void Heavy_CircleStrings::cBinop_cM4FiPlh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_KpD8lYvz_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_suZnWLke, m);
}

void Heavy_CircleStrings::cBinop_KpD8lYvz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_ZSA5JPpm, m);
}

void Heavy_CircleStrings::cMsg_EHKdOBIZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_gOPkNnk6_sendMessage);
}

void Heavy_CircleStrings::cSystem_gOPkNnk6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_lkaa1t6C_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cVar_qwQ7Na3d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1e-05f, 0, m, &cBinop_975Wii0b_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_NRu50uh8, 0, m, &cIf_NRu50uh8_sendMessage);
}

void Heavy_CircleStrings::cIf_NRu50uh8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_O5lGdSJ6_sendMessage(_c, 0, m);
      cMsg_8kWdhHOh_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_BeB7euzg_sendMessage(_c, 0, m);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_R9RPl94C_sendMessage);
      sVarf_onMessage(_c, &Context(_c)->sVarf_tGQJ5UOH, m);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_975Wii0b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_NRu50uh8, 1, m, &cIf_NRu50uh8_sendMessage);
}

void Heavy_CircleStrings::cMsg_BeB7euzg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_Kh3JBXQf_sendMessage);
}

void Heavy_CircleStrings::cBinop_Kh3JBXQf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_9K5qRupb, m);
}

void Heavy_CircleStrings::cBinop_R9RPl94C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_njo2rNAh_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_njo2rNAh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_c04b66K2_sendMessage);
}

void Heavy_CircleStrings::cBinop_c04b66K2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_8dem2SiP_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_8dem2SiP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_SfZBrfB2_sendMessage);
}

void Heavy_CircleStrings::cBinop_SfZBrfB2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_TkPJyfvg, m);
}

void Heavy_CircleStrings::cBinop_w06KHHBy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_9T6ZYngT, m);
}

void Heavy_CircleStrings::cMsg_lkaa1t6C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_w06KHHBy_sendMessage);
}

void Heavy_CircleStrings::cMsg_O5lGdSJ6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_R9RPl94C_sendMessage);
}

void Heavy_CircleStrings::cMsg_8kWdhHOh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, -1.0f);
  sVarf_onMessage(_c, &Context(_c)->sVarf_9K5qRupb, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_tGQJ5UOH, m);
}

void Heavy_CircleStrings::cBinop_nLKP5SEM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_pNJnok0N, 0, m, &cVar_pNJnok0N_sendMessage);
}

void Heavy_CircleStrings::cBinop_rwspi45V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_tC1ETIrK, 0, m, &cVar_tC1ETIrK_sendMessage);
}

void Heavy_CircleStrings::cBinop_MQkQQkVD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_1DOFW6CV, 0, m, &cVar_1DOFW6CV_sendMessage);
}

void Heavy_CircleStrings::cCast_3yNM5eNV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_sdQZbveA, m);
}

void Heavy_CircleStrings::cCast_joJPwmVZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.0f, 0, m, &cBinop_nLKP5SEM_sendMessage);
}

void Heavy_CircleStrings::cCast_YL8sbbCA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.0f, 0, m, &cBinop_rwspi45V_sendMessage);
}

void Heavy_CircleStrings::cCast_06ihyZdv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.0f, 0, m, &cBinop_MQkQQkVD_sendMessage);
}

void Heavy_CircleStrings::cTabhead_BhCdQpx4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_zWQmu9NG, HV_BINOP_SUBTRACT, 0, m, &cBinop_zWQmu9NG_sendMessage);
}

void Heavy_CircleStrings::cMsg_17mUytTt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Kejuxhtu_sendMessage);
}

void Heavy_CircleStrings::cSystem_Kejuxhtu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_MLrDAjOJ_sendMessage);
}

void Heavy_CircleStrings::cVar_32wrEBxC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ZDSNEvhD_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_udYXoKMg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_udYXoKMg, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_SPe7zgcK, 0, m, &cDelay_SPe7zgcK_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_BMVI4rfq, 0, m, &sTabread_BMVI4rfq_sendMessage);
}

void Heavy_CircleStrings::cDelay_SPe7zgcK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_SPe7zgcK, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_BMVI4rfq, 0, m, &sTabread_BMVI4rfq_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_SPe7zgcK, 0, m, &cDelay_SPe7zgcK_sendMessage);
}

void Heavy_CircleStrings::sTabread_BMVI4rfq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_QYe3YmoE, HV_BINOP_SUBTRACT, 0, m, &cBinop_QYe3YmoE_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_a2hAK04P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_jnaJk5Br, HV_BINOP_MAX, 0, m, &cBinop_jnaJk5Br_sendMessage);
}

void Heavy_CircleStrings::cBinop_MLrDAjOJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_a2hAK04P, HV_BINOP_MULTIPLY, 0, m, &cBinop_a2hAK04P_sendMessage);
}

void Heavy_CircleStrings::cBinop_zWQmu9NG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_aviZnCZl_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_BMVI4rfq, 0, m, &sTabread_BMVI4rfq_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_1iUZvnN5_sendMessage);
}

void Heavy_CircleStrings::cSystem_f2iD35dh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_QYe3YmoE, HV_BINOP_SUBTRACT, 1, m, &cBinop_QYe3YmoE_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_SPe7zgcK, 2, m, &cDelay_SPe7zgcK_sendMessage);
}

void Heavy_CircleStrings::cMsg_ZDSNEvhD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_f2iD35dh_sendMessage);
}

void Heavy_CircleStrings::cMsg_aviZnCZl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_udYXoKMg, 0, m, &cDelay_udYXoKMg_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_SPe7zgcK, 0, m, &cDelay_SPe7zgcK_sendMessage);
}

void Heavy_CircleStrings::cMsg_AfPt3QDJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_jnaJk5Br, HV_BINOP_MAX, 1, m, &cBinop_jnaJk5Br_sendMessage);
}

void Heavy_CircleStrings::cBinop_jnaJk5Br_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_zWQmu9NG, HV_BINOP_SUBTRACT, 1, m, &cBinop_zWQmu9NG_sendMessage);
}

void Heavy_CircleStrings::cCast_1iUZvnN5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_udYXoKMg, 0, m, &cDelay_udYXoKMg_sendMessage);
}

void Heavy_CircleStrings::cBinop_pTKlZrsu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_udYXoKMg, 2, m, &cDelay_udYXoKMg_sendMessage);
}

void Heavy_CircleStrings::cBinop_QYe3YmoE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_pTKlZrsu_sendMessage);
}

void Heavy_CircleStrings::cCast_SxZQL9QP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_32wrEBxC, 0, m, &cVar_32wrEBxC_sendMessage);
  cMsg_17mUytTt_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_BhCdQpx4, 0, m, &cTabhead_BhCdQpx4_sendMessage);
}

void Heavy_CircleStrings::cTabhead_vWjX6wtf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_5BHXKZRg, HV_BINOP_SUBTRACT, 0, m, &cBinop_5BHXKZRg_sendMessage);
}

void Heavy_CircleStrings::cMsg_wVqJ27qo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ixrKR2JM_sendMessage);
}

void Heavy_CircleStrings::cSystem_ixrKR2JM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_p9fN1wcb_sendMessage);
}

void Heavy_CircleStrings::cVar_D4i1hYXb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_w41rukYd_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_VgxIpwUe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_VgxIpwUe, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_pwporhgO, 0, m, &cDelay_pwporhgO_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_sCx6s3vi, 0, m, &sTabread_sCx6s3vi_sendMessage);
}

void Heavy_CircleStrings::cDelay_pwporhgO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_pwporhgO, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_sCx6s3vi, 0, m, &sTabread_sCx6s3vi_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_pwporhgO, 0, m, &cDelay_pwporhgO_sendMessage);
}

void Heavy_CircleStrings::sTabread_sCx6s3vi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_59x31kei, HV_BINOP_SUBTRACT, 0, m, &cBinop_59x31kei_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_lzB0lg8v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_YPc3Idbv, HV_BINOP_MAX, 0, m, &cBinop_YPc3Idbv_sendMessage);
}

void Heavy_CircleStrings::cBinop_p9fN1wcb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_lzB0lg8v, HV_BINOP_MULTIPLY, 0, m, &cBinop_lzB0lg8v_sendMessage);
}

void Heavy_CircleStrings::cBinop_5BHXKZRg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_r9VWBmzz_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_sCx6s3vi, 0, m, &sTabread_sCx6s3vi_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_8VCACb0S_sendMessage);
}

void Heavy_CircleStrings::cSystem_wuCSHdtM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_59x31kei, HV_BINOP_SUBTRACT, 1, m, &cBinop_59x31kei_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_pwporhgO, 2, m, &cDelay_pwporhgO_sendMessage);
}

void Heavy_CircleStrings::cMsg_w41rukYd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_wuCSHdtM_sendMessage);
}

void Heavy_CircleStrings::cMsg_r9VWBmzz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_VgxIpwUe, 0, m, &cDelay_VgxIpwUe_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_pwporhgO, 0, m, &cDelay_pwporhgO_sendMessage);
}

void Heavy_CircleStrings::cMsg_cUFQkDAi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_YPc3Idbv, HV_BINOP_MAX, 1, m, &cBinop_YPc3Idbv_sendMessage);
}

void Heavy_CircleStrings::cBinop_YPc3Idbv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_5BHXKZRg, HV_BINOP_SUBTRACT, 1, m, &cBinop_5BHXKZRg_sendMessage);
}

void Heavy_CircleStrings::cCast_8VCACb0S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_VgxIpwUe, 0, m, &cDelay_VgxIpwUe_sendMessage);
}

void Heavy_CircleStrings::cBinop_vmF66zFa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_VgxIpwUe, 2, m, &cDelay_VgxIpwUe_sendMessage);
}

void Heavy_CircleStrings::cBinop_59x31kei_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_vmF66zFa_sendMessage);
}

void Heavy_CircleStrings::cCast_Jus8fwWL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_D4i1hYXb, 0, m, &cVar_D4i1hYXb_sendMessage);
  cMsg_wVqJ27qo_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_vWjX6wtf, 0, m, &cTabhead_vWjX6wtf_sendMessage);
}

void Heavy_CircleStrings::cTabhead_MX3InhKt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_rkVHlaGI, HV_BINOP_SUBTRACT, 0, m, &cBinop_rkVHlaGI_sendMessage);
}

void Heavy_CircleStrings::cMsg_OCpWLuTQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_njHv9ZaU_sendMessage);
}

void Heavy_CircleStrings::cSystem_njHv9ZaU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_gJfNlLp6_sendMessage);
}

void Heavy_CircleStrings::cVar_BDVggPgY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_yPi2afgB_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_uy0bqKsH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_uy0bqKsH, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_QCSsLFAT, 0, m, &cDelay_QCSsLFAT_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_0eJsMEEd, 0, m, &sTabread_0eJsMEEd_sendMessage);
}

void Heavy_CircleStrings::cDelay_QCSsLFAT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_QCSsLFAT, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_0eJsMEEd, 0, m, &sTabread_0eJsMEEd_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_QCSsLFAT, 0, m, &cDelay_QCSsLFAT_sendMessage);
}

void Heavy_CircleStrings::sTabread_0eJsMEEd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_038tyPoP, HV_BINOP_SUBTRACT, 0, m, &cBinop_038tyPoP_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_AWK53yqy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Y6wFnb0W, HV_BINOP_MAX, 0, m, &cBinop_Y6wFnb0W_sendMessage);
}

void Heavy_CircleStrings::cBinop_gJfNlLp6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_AWK53yqy, HV_BINOP_MULTIPLY, 0, m, &cBinop_AWK53yqy_sendMessage);
}

void Heavy_CircleStrings::cBinop_rkVHlaGI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_WYOWoXUE_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_0eJsMEEd, 0, m, &sTabread_0eJsMEEd_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_s04PvM6M_sendMessage);
}

void Heavy_CircleStrings::cSystem_He30bNtN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_038tyPoP, HV_BINOP_SUBTRACT, 1, m, &cBinop_038tyPoP_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_QCSsLFAT, 2, m, &cDelay_QCSsLFAT_sendMessage);
}

void Heavy_CircleStrings::cMsg_yPi2afgB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_He30bNtN_sendMessage);
}

void Heavy_CircleStrings::cMsg_WYOWoXUE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_uy0bqKsH, 0, m, &cDelay_uy0bqKsH_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_QCSsLFAT, 0, m, &cDelay_QCSsLFAT_sendMessage);
}

void Heavy_CircleStrings::cMsg_1vtIP7lB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_Y6wFnb0W, HV_BINOP_MAX, 1, m, &cBinop_Y6wFnb0W_sendMessage);
}

void Heavy_CircleStrings::cBinop_Y6wFnb0W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_rkVHlaGI, HV_BINOP_SUBTRACT, 1, m, &cBinop_rkVHlaGI_sendMessage);
}

void Heavy_CircleStrings::cCast_s04PvM6M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_uy0bqKsH, 0, m, &cDelay_uy0bqKsH_sendMessage);
}

void Heavy_CircleStrings::cBinop_NETRU1iy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_uy0bqKsH, 2, m, &cDelay_uy0bqKsH_sendMessage);
}

void Heavy_CircleStrings::cBinop_038tyPoP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_NETRU1iy_sendMessage);
}

void Heavy_CircleStrings::cCast_1ZE3L146_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_BDVggPgY, 0, m, &cVar_BDVggPgY_sendMessage);
  cMsg_OCpWLuTQ_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_MX3InhKt, 0, m, &cTabhead_MX3InhKt_sendMessage);
}

void Heavy_CircleStrings::cTabhead_BMpi2f4B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4G7eKyBT, HV_BINOP_SUBTRACT, 0, m, &cBinop_4G7eKyBT_sendMessage);
}

void Heavy_CircleStrings::cMsg_8O6Dr7Qo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_5goNRrEP_sendMessage);
}

void Heavy_CircleStrings::cSystem_5goNRrEP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_sleIaJkW_sendMessage);
}

void Heavy_CircleStrings::cVar_ZK9JIqoN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_U5nNGubv_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_OwX574dn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_OwX574dn, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_82G0SwR2, 0, m, &cDelay_82G0SwR2_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_Om1xZlX2, 0, m, &sTabread_Om1xZlX2_sendMessage);
}

void Heavy_CircleStrings::cDelay_82G0SwR2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_82G0SwR2, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_Om1xZlX2, 0, m, &sTabread_Om1xZlX2_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_82G0SwR2, 0, m, &cDelay_82G0SwR2_sendMessage);
}

void Heavy_CircleStrings::sTabread_Om1xZlX2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_hak1NBMF, HV_BINOP_SUBTRACT, 0, m, &cBinop_hak1NBMF_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_wwk0CUx4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_HURxE1rC, HV_BINOP_MAX, 0, m, &cBinop_HURxE1rC_sendMessage);
}

void Heavy_CircleStrings::cBinop_sleIaJkW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_wwk0CUx4, HV_BINOP_MULTIPLY, 0, m, &cBinop_wwk0CUx4_sendMessage);
}

void Heavy_CircleStrings::cBinop_4G7eKyBT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_VaXgDPHa_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_Om1xZlX2, 0, m, &sTabread_Om1xZlX2_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_uOccIWCg_sendMessage);
}

void Heavy_CircleStrings::cSystem_4m7SngS2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_hak1NBMF, HV_BINOP_SUBTRACT, 1, m, &cBinop_hak1NBMF_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_82G0SwR2, 2, m, &cDelay_82G0SwR2_sendMessage);
}

void Heavy_CircleStrings::cMsg_U5nNGubv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_4m7SngS2_sendMessage);
}

void Heavy_CircleStrings::cMsg_VaXgDPHa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_OwX574dn, 0, m, &cDelay_OwX574dn_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_82G0SwR2, 0, m, &cDelay_82G0SwR2_sendMessage);
}

void Heavy_CircleStrings::cMsg_hiRmTKpG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_HURxE1rC, HV_BINOP_MAX, 1, m, &cBinop_HURxE1rC_sendMessage);
}

void Heavy_CircleStrings::cBinop_HURxE1rC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4G7eKyBT, HV_BINOP_SUBTRACT, 1, m, &cBinop_4G7eKyBT_sendMessage);
}

void Heavy_CircleStrings::cCast_uOccIWCg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_OwX574dn, 0, m, &cDelay_OwX574dn_sendMessage);
}

void Heavy_CircleStrings::cBinop_dDcAGL4G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_OwX574dn, 2, m, &cDelay_OwX574dn_sendMessage);
}

void Heavy_CircleStrings::cBinop_hak1NBMF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_dDcAGL4G_sendMessage);
}

void Heavy_CircleStrings::cCast_H8SzKvrO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ZK9JIqoN, 0, m, &cVar_ZK9JIqoN_sendMessage);
  cMsg_8O6Dr7Qo_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_BMpi2f4B, 0, m, &cTabhead_BMpi2f4B_sendMessage);
}

void Heavy_CircleStrings::cMsg_R31Sr1kK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_J8u07YJn_sendMessage);
}

void Heavy_CircleStrings::cSystem_J8u07YJn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_L2HxbBMZ_sendMessage);
}

void Heavy_CircleStrings::cDelay_LInV59xw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_LInV59xw, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_JM5GLEwE, 0, m, &cDelay_JM5GLEwE_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_LInV59xw, 0, m, &cDelay_LInV59xw_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_tHqeJ7HG, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_JM5GLEwE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_JM5GLEwE, m);
  cMsg_becjfXUz_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_bo3Y0mck_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_j67X6FD7_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_mEOyItJc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_pi7rkkmm_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_tfHJlVqH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_nqDQbdBJ_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_LInV59xw, 2, m, &cDelay_LInV59xw_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ZuvsGVnv_sendMessage);
}

void Heavy_CircleStrings::cMsg_pi7rkkmm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_tfHJlVqH, 0, m, &hTable_tfHJlVqH_sendMessage);
}

void Heavy_CircleStrings::cBinop_L2HxbBMZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 58.6435f, 0, m, &cBinop_mEOyItJc_sendMessage);
}

void Heavy_CircleStrings::cMsg_becjfXUz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_tfHJlVqH, 0, m, &hTable_tfHJlVqH_sendMessage);
}

void Heavy_CircleStrings::cCast_ZuvsGVnv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_LInV59xw, 0, m, &cDelay_LInV59xw_sendMessage);
}

void Heavy_CircleStrings::cMsg_nqDQbdBJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_JM5GLEwE, 2, m, &cDelay_JM5GLEwE_sendMessage);
}

void Heavy_CircleStrings::cMsg_j67X6FD7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_tHqeJ7HG, 1, m, NULL);
}

void Heavy_CircleStrings::cMsg_UyAk7c0B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_gLPHaqVN_sendMessage);
}

void Heavy_CircleStrings::cSystem_gLPHaqVN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_xHFpSBGZ_sendMessage);
}

void Heavy_CircleStrings::cDelay_oUO4rvPz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_oUO4rvPz, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_yIKfIE6N, 0, m, &cDelay_yIKfIE6N_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_oUO4rvPz, 0, m, &cDelay_oUO4rvPz_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_onLuFq4X, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_yIKfIE6N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_yIKfIE6N, m);
  cMsg_6E2nwbh5_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_gy50w6Za_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_jdOL0q2C_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_72MCpJB7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_jTmz9tkt_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_s05kBe0N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_6kZqm5Uk_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_oUO4rvPz, 2, m, &cDelay_oUO4rvPz_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ZZuyo70m_sendMessage);
}

void Heavy_CircleStrings::cMsg_jTmz9tkt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_s05kBe0N, 0, m, &hTable_s05kBe0N_sendMessage);
}

void Heavy_CircleStrings::cBinop_xHFpSBGZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 69.4325f, 0, m, &cBinop_72MCpJB7_sendMessage);
}

void Heavy_CircleStrings::cMsg_6E2nwbh5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_s05kBe0N, 0, m, &hTable_s05kBe0N_sendMessage);
}

void Heavy_CircleStrings::cCast_ZZuyo70m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_oUO4rvPz, 0, m, &cDelay_oUO4rvPz_sendMessage);
}

void Heavy_CircleStrings::cMsg_6kZqm5Uk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_yIKfIE6N, 2, m, &cDelay_yIKfIE6N_sendMessage);
}

void Heavy_CircleStrings::cMsg_jdOL0q2C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_onLuFq4X, 1, m, NULL);
}

void Heavy_CircleStrings::cMsg_zNpjy91C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_t9lF1ifJ_sendMessage);
}

void Heavy_CircleStrings::cSystem_t9lF1ifJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_NFt4rNHp_sendMessage);
}

void Heavy_CircleStrings::cDelay_wYJhQNlE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_wYJhQNlE, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_8UK5FtGx, 0, m, &cDelay_8UK5FtGx_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_wYJhQNlE, 0, m, &cDelay_wYJhQNlE_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_iiXtjGK3, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_8UK5FtGx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_8UK5FtGx, m);
  cMsg_53T4oPSN_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_ztxxcVkF_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_JY4sEM4A_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_WuxBa1Qm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_R6QRuiJX_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_dAH5iQND_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_LCMBS7X4_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_wYJhQNlE, 2, m, &cDelay_wYJhQNlE_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ygNhRMJL_sendMessage);
}

void Heavy_CircleStrings::cMsg_R6QRuiJX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_dAH5iQND, 0, m, &hTable_dAH5iQND_sendMessage);
}

void Heavy_CircleStrings::cBinop_NFt4rNHp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 74.5234f, 0, m, &cBinop_WuxBa1Qm_sendMessage);
}

void Heavy_CircleStrings::cMsg_53T4oPSN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_dAH5iQND, 0, m, &hTable_dAH5iQND_sendMessage);
}

void Heavy_CircleStrings::cCast_ygNhRMJL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_wYJhQNlE, 0, m, &cDelay_wYJhQNlE_sendMessage);
}

void Heavy_CircleStrings::cMsg_LCMBS7X4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_8UK5FtGx, 2, m, &cDelay_8UK5FtGx_sendMessage);
}

void Heavy_CircleStrings::cMsg_JY4sEM4A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_iiXtjGK3, 1, m, NULL);
}

void Heavy_CircleStrings::cMsg_zyp2k7BZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_tiYyyiYt_sendMessage);
}

void Heavy_CircleStrings::cSystem_tiYyyiYt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_tR1kcp6T_sendMessage);
}

void Heavy_CircleStrings::cDelay_z2pjONm3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_z2pjONm3, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Uhz2So1z, 0, m, &cDelay_Uhz2So1z_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_z2pjONm3, 0, m, &cDelay_z2pjONm3_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_MUpFJI2Y, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_Uhz2So1z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Uhz2So1z, m);
  cMsg_Su7g5G43_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_vt1hiPjH_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_ex15RAGA_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_O3dtjUse_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_1lVp52Uv_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_rxv0WHA4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_hQTTBxtn_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_z2pjONm3, 2, m, &cDelay_z2pjONm3_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ebm9s28e_sendMessage);
}

void Heavy_CircleStrings::cMsg_1lVp52Uv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_rxv0WHA4, 0, m, &hTable_rxv0WHA4_sendMessage);
}

void Heavy_CircleStrings::cBinop_tR1kcp6T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 86.1244f, 0, m, &cBinop_O3dtjUse_sendMessage);
}

void Heavy_CircleStrings::cMsg_Su7g5G43_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_rxv0WHA4, 0, m, &hTable_rxv0WHA4_sendMessage);
}

void Heavy_CircleStrings::cCast_ebm9s28e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_z2pjONm3, 0, m, &cDelay_z2pjONm3_sendMessage);
}

void Heavy_CircleStrings::cMsg_hQTTBxtn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_Uhz2So1z, 2, m, &cDelay_Uhz2So1z_sendMessage);
}

void Heavy_CircleStrings::cMsg_ex15RAGA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_MUpFJI2Y, 1, m, NULL);
}

void Heavy_CircleStrings::cIf_qgEM6tvd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_g0SwIz5f_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_D7A079pI_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cMsg_YzRTP3gd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_0qEnwt5p, HV_BINOP_POW, 0, m, &cBinop_0qEnwt5p_sendMessage);
}

void Heavy_CircleStrings::cBinop_0qEnwt5p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.125f, 0, m, &cBinop_PzvvelhO_sendMessage);
}

void Heavy_CircleStrings::cBinop_mE5IuPVx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_Oc9Hwhf3_sendMessage);
}

void Heavy_CircleStrings::cCast_MCXb3EvB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_qgEM6tvd, 0, m, &cIf_qgEM6tvd_sendMessage);
}

void Heavy_CircleStrings::cCast_7apQnMNC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_rEpgtwTS_sendMessage);
}

void Heavy_CircleStrings::cBinop_rEpgtwTS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_qgEM6tvd, 1, m, &cIf_qgEM6tvd_sendMessage);
}

void Heavy_CircleStrings::cBinop_D7A079pI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_mE5IuPVx_sendMessage);
}

void Heavy_CircleStrings::cMsg_g0SwIz5f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.125f, 0, m, &cBinop_PzvvelhO_sendMessage);
}

void Heavy_CircleStrings::cBinop_Oc9Hwhf3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_0qEnwt5p, HV_BINOP_POW, 1, m, &cBinop_0qEnwt5p_sendMessage);
  cMsg_YzRTP3gd_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cPack_GHi8oYBG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_bCgciRWS, 0, m, NULL);
}

void Heavy_CircleStrings::cPack_3AmPPqfy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_5aVZ062v, 0, m, NULL);
}

void Heavy_CircleStrings::cBinop_fmt3o8vX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_XXJsRNYe_sendMessage);
}

void Heavy_CircleStrings::cBinop_XXJsRNYe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 200.0f, 0, m, &cBinop_wJBbioPS_sendMessage);
}

void Heavy_CircleStrings::cVar_74RnRCDV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_dM0DE3nI, HV_BINOP_MULTIPLY, 0, m, &cBinop_dM0DE3nI_sendMessage);
}

void Heavy_CircleStrings::cMsg_iv0xrKXo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_7drul0Jf_sendMessage);
}

void Heavy_CircleStrings::cSystem_7drul0Jf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Q1kAMdxP_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_dM0DE3nI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_CwOY4WwW_sendMessage);
}

void Heavy_CircleStrings::cBinop_vFtoEZ5t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_dM0DE3nI, HV_BINOP_MULTIPLY, 1, m, &cBinop_dM0DE3nI_sendMessage);
}

void Heavy_CircleStrings::cMsg_Q1kAMdxP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_vFtoEZ5t_sendMessage);
}

void Heavy_CircleStrings::cBinop_CwOY4WwW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_MjoMuu2i_sendMessage);
}

void Heavy_CircleStrings::cBinop_MjoMuu2i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_ee3fdc3m_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_8x9Hf6B3, m);
}

void Heavy_CircleStrings::cBinop_ee3fdc3m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_agHcru4M, m);
}

void Heavy_CircleStrings::cVar_mn5VjOIv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_7apQnMNC_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_MCXb3EvB_sendMessage);
}

void Heavy_CircleStrings::cVar_qFiQRHjD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 100.0f, 0, m, &cBinop_fmt3o8vX_sendMessage);
}

void Heavy_CircleStrings::cVar_ysfqpLHP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_2eR8F0Uw_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_tAm4wH24, 0, m, &cIf_tAm4wH24_sendMessage);
}

void Heavy_CircleStrings::cVar_wHlfSVwo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 100.0f, 0, m, &cBinop_oaGYytjO_sendMessage);
}

void Heavy_CircleStrings::cIf_tAm4wH24_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_UCtIL46u_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cVar_onMessage(_c, &Context(_c)->cVar_uuE2YQjm, 0, m, &cVar_uuE2YQjm_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_2eR8F0Uw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_tAm4wH24, 1, m, &cIf_tAm4wH24_sendMessage);
}

void Heavy_CircleStrings::cBinop_oaGYytjO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_Q538LsKq_sendMessage);
}

void Heavy_CircleStrings::cBinop_Q538LsKq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_J62g29j8, 0, m, &cVar_J62g29j8_sendMessage);
}

void Heavy_CircleStrings::cTabhead_w2T4YJ1q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_NfZB2BXI, HV_BINOP_SUBTRACT, 0, m, &cBinop_NfZB2BXI_sendMessage);
}

void Heavy_CircleStrings::cMsg_k5WA9nVe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_y112Y4rm_sendMessage);
}

void Heavy_CircleStrings::cSystem_y112Y4rm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_thEn4Nb3_sendMessage);
}

void Heavy_CircleStrings::cVar_rdfC08lm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_2WT0KQ47_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_yT4NhXO8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_yT4NhXO8, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_5oRRxdeu, 0, m, &cDelay_5oRRxdeu_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_vX2N3qtx, 0, m, &sTabread_vX2N3qtx_sendMessage);
}

void Heavy_CircleStrings::cDelay_5oRRxdeu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_5oRRxdeu, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_vX2N3qtx, 0, m, &sTabread_vX2N3qtx_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_5oRRxdeu, 0, m, &cDelay_5oRRxdeu_sendMessage);
}

void Heavy_CircleStrings::sTabread_vX2N3qtx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_SUw1AlV5, HV_BINOP_SUBTRACT, 0, m, &cBinop_SUw1AlV5_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_kVRcn5an_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_nmr1YjAj, HV_BINOP_MAX, 0, m, &cBinop_nmr1YjAj_sendMessage);
}

void Heavy_CircleStrings::cBinop_thEn4Nb3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_kVRcn5an, HV_BINOP_MULTIPLY, 0, m, &cBinop_kVRcn5an_sendMessage);
}

void Heavy_CircleStrings::cBinop_NfZB2BXI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_kzgjtTUS_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_vX2N3qtx, 0, m, &sTabread_vX2N3qtx_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ovVt9d4a_sendMessage);
}

void Heavy_CircleStrings::cSystem_4PzU0CAQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_SUw1AlV5, HV_BINOP_SUBTRACT, 1, m, &cBinop_SUw1AlV5_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_5oRRxdeu, 2, m, &cDelay_5oRRxdeu_sendMessage);
}

void Heavy_CircleStrings::cMsg_2WT0KQ47_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_4PzU0CAQ_sendMessage);
}

void Heavy_CircleStrings::cMsg_kzgjtTUS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_yT4NhXO8, 0, m, &cDelay_yT4NhXO8_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_5oRRxdeu, 0, m, &cDelay_5oRRxdeu_sendMessage);
}

void Heavy_CircleStrings::cMsg_Wj0dMM2A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_nmr1YjAj, HV_BINOP_MAX, 1, m, &cBinop_nmr1YjAj_sendMessage);
}

void Heavy_CircleStrings::cBinop_nmr1YjAj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_NfZB2BXI, HV_BINOP_SUBTRACT, 1, m, &cBinop_NfZB2BXI_sendMessage);
}

void Heavy_CircleStrings::cCast_ovVt9d4a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_yT4NhXO8, 0, m, &cDelay_yT4NhXO8_sendMessage);
}

void Heavy_CircleStrings::cBinop_12Xeh48W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_yT4NhXO8, 2, m, &cDelay_yT4NhXO8_sendMessage);
}

void Heavy_CircleStrings::cBinop_SUw1AlV5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_12Xeh48W_sendMessage);
}

void Heavy_CircleStrings::cCast_3vLYrpnS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_rdfC08lm, 0, m, &cVar_rdfC08lm_sendMessage);
  cMsg_k5WA9nVe_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_w2T4YJ1q, 0, m, &cTabhead_w2T4YJ1q_sendMessage);
}

void Heavy_CircleStrings::cMsg_9ojwDwH0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_7q310Smg_sendMessage);
}

void Heavy_CircleStrings::cSystem_7q310Smg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_Qnk2F0hi_sendMessage);
}

void Heavy_CircleStrings::cDelay_lT6kKxrB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_lT6kKxrB, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_VyaWh0Y3, 0, m, &cDelay_VyaWh0Y3_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_lT6kKxrB, 0, m, &cDelay_lT6kKxrB_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_tCOQ2ItD, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_VyaWh0Y3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_VyaWh0Y3, m);
  cMsg_ltzpiFgx_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_Q8HMJvRW_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_BmlBA4tt_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_6PWlek6A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_TMyXBRFr_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_KGTj6IPY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_5t3Bh1ev_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_lT6kKxrB, 2, m, &cDelay_lT6kKxrB_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_CCK2yGcK_sendMessage);
}

void Heavy_CircleStrings::cMsg_TMyXBRFr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_KGTj6IPY, 0, m, &hTable_KGTj6IPY_sendMessage);
}

void Heavy_CircleStrings::cBinop_Qnk2F0hi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 13.645f, 0, m, &cBinop_6PWlek6A_sendMessage);
}

void Heavy_CircleStrings::cMsg_ltzpiFgx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_KGTj6IPY, 0, m, &hTable_KGTj6IPY_sendMessage);
}

void Heavy_CircleStrings::cCast_CCK2yGcK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_lT6kKxrB, 0, m, &cDelay_lT6kKxrB_sendMessage);
}

void Heavy_CircleStrings::cMsg_5t3Bh1ev_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_VyaWh0Y3, 2, m, &cDelay_VyaWh0Y3_sendMessage);
}

void Heavy_CircleStrings::cMsg_BmlBA4tt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_tCOQ2ItD, 1, m, NULL);
}

void Heavy_CircleStrings::cTabhead_iMMGmHQl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_bnnMdO4r, HV_BINOP_SUBTRACT, 0, m, &cBinop_bnnMdO4r_sendMessage);
}

void Heavy_CircleStrings::cMsg_UTv39Lhu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_dujjTiUJ_sendMessage);
}

void Heavy_CircleStrings::cSystem_dujjTiUJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_eMmvjuMZ_sendMessage);
}

void Heavy_CircleStrings::cVar_neczr5hd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_k25ggqH8_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_3clS3tMj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_3clS3tMj, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_sE6ru9gP, 0, m, &cDelay_sE6ru9gP_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_fOeppglu, 0, m, &sTabread_fOeppglu_sendMessage);
}

void Heavy_CircleStrings::cDelay_sE6ru9gP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_sE6ru9gP, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_fOeppglu, 0, m, &sTabread_fOeppglu_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_sE6ru9gP, 0, m, &cDelay_sE6ru9gP_sendMessage);
}

void Heavy_CircleStrings::sTabread_fOeppglu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_wDKY7NpH, HV_BINOP_SUBTRACT, 0, m, &cBinop_wDKY7NpH_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_Claw70y0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_E5Ga3tL1, HV_BINOP_MAX, 0, m, &cBinop_E5Ga3tL1_sendMessage);
}

void Heavy_CircleStrings::cBinop_eMmvjuMZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Claw70y0, HV_BINOP_MULTIPLY, 0, m, &cBinop_Claw70y0_sendMessage);
}

void Heavy_CircleStrings::cBinop_bnnMdO4r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_c8IXpBOP_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_fOeppglu, 0, m, &sTabread_fOeppglu_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_XBTywm4C_sendMessage);
}

void Heavy_CircleStrings::cSystem_syFO6Ceh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_wDKY7NpH, HV_BINOP_SUBTRACT, 1, m, &cBinop_wDKY7NpH_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_sE6ru9gP, 2, m, &cDelay_sE6ru9gP_sendMessage);
}

void Heavy_CircleStrings::cMsg_k25ggqH8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_syFO6Ceh_sendMessage);
}

void Heavy_CircleStrings::cMsg_c8IXpBOP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_3clS3tMj, 0, m, &cDelay_3clS3tMj_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_sE6ru9gP, 0, m, &cDelay_sE6ru9gP_sendMessage);
}

void Heavy_CircleStrings::cMsg_mOxyfHI4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_E5Ga3tL1, HV_BINOP_MAX, 1, m, &cBinop_E5Ga3tL1_sendMessage);
}

void Heavy_CircleStrings::cBinop_E5Ga3tL1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_bnnMdO4r, HV_BINOP_SUBTRACT, 1, m, &cBinop_bnnMdO4r_sendMessage);
}

void Heavy_CircleStrings::cCast_XBTywm4C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_3clS3tMj, 0, m, &cDelay_3clS3tMj_sendMessage);
}

void Heavy_CircleStrings::cBinop_h57L0GOb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_3clS3tMj, 2, m, &cDelay_3clS3tMj_sendMessage);
}

void Heavy_CircleStrings::cBinop_wDKY7NpH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_h57L0GOb_sendMessage);
}

void Heavy_CircleStrings::cCast_U4Jt2sVe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_neczr5hd, 0, m, &cVar_neczr5hd_sendMessage);
  cMsg_UTv39Lhu_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_iMMGmHQl, 0, m, &cTabhead_iMMGmHQl_sendMessage);
}

void Heavy_CircleStrings::cMsg_Dy7lO5lU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_gvnfiOhP_sendMessage);
}

void Heavy_CircleStrings::cSystem_gvnfiOhP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_YdJExux3_sendMessage);
}

void Heavy_CircleStrings::cDelay_1tU5iEsk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_1tU5iEsk, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_WV10wl9I, 0, m, &cDelay_WV10wl9I_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_1tU5iEsk, 0, m, &cDelay_1tU5iEsk_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_vglPAOff, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_WV10wl9I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_WV10wl9I, m);
  cMsg_wsswp8XA_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_zZTKsmPK_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_I5kEnm84_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_25bFlBh2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_n3Mlkgwu_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_KaldRfq7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_KbgYYpQt_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_1tU5iEsk, 2, m, &cDelay_1tU5iEsk_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_bithaPLJ_sendMessage);
}

void Heavy_CircleStrings::cMsg_n3Mlkgwu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_KaldRfq7, 0, m, &hTable_KaldRfq7_sendMessage);
}

void Heavy_CircleStrings::cBinop_YdJExux3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 16.364f, 0, m, &cBinop_25bFlBh2_sendMessage);
}

void Heavy_CircleStrings::cMsg_wsswp8XA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_KaldRfq7, 0, m, &hTable_KaldRfq7_sendMessage);
}

void Heavy_CircleStrings::cCast_bithaPLJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_1tU5iEsk, 0, m, &cDelay_1tU5iEsk_sendMessage);
}

void Heavy_CircleStrings::cMsg_KbgYYpQt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_WV10wl9I, 2, m, &cDelay_WV10wl9I_sendMessage);
}

void Heavy_CircleStrings::cMsg_I5kEnm84_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_vglPAOff, 1, m, NULL);
}

void Heavy_CircleStrings::cTabhead_KtH8ozvz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Iw8fG938, HV_BINOP_SUBTRACT, 0, m, &cBinop_Iw8fG938_sendMessage);
}

void Heavy_CircleStrings::cMsg_n1M2IJBQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_xbohcxx9_sendMessage);
}

void Heavy_CircleStrings::cSystem_xbohcxx9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_xxKOsqmP_sendMessage);
}

void Heavy_CircleStrings::cVar_GuOl5wKF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_fH1oGKgQ_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_TzI79mT9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_TzI79mT9, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_tdQGp3Yq, 0, m, &cDelay_tdQGp3Yq_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_3jtdNVgY, 0, m, &sTabread_3jtdNVgY_sendMessage);
}

void Heavy_CircleStrings::cDelay_tdQGp3Yq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_tdQGp3Yq, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_3jtdNVgY, 0, m, &sTabread_3jtdNVgY_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_tdQGp3Yq, 0, m, &cDelay_tdQGp3Yq_sendMessage);
}

void Heavy_CircleStrings::sTabread_3jtdNVgY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_nuX0Rd0K, HV_BINOP_SUBTRACT, 0, m, &cBinop_nuX0Rd0K_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_tWdgblUC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_9YOUEU9I, HV_BINOP_MAX, 0, m, &cBinop_9YOUEU9I_sendMessage);
}

void Heavy_CircleStrings::cBinop_xxKOsqmP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_tWdgblUC, HV_BINOP_MULTIPLY, 0, m, &cBinop_tWdgblUC_sendMessage);
}

void Heavy_CircleStrings::cBinop_Iw8fG938_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_zOTX5oHU_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_3jtdNVgY, 0, m, &sTabread_3jtdNVgY_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_2vzgZHD9_sendMessage);
}

void Heavy_CircleStrings::cSystem_y159Af6W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_nuX0Rd0K, HV_BINOP_SUBTRACT, 1, m, &cBinop_nuX0Rd0K_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_tdQGp3Yq, 2, m, &cDelay_tdQGp3Yq_sendMessage);
}

void Heavy_CircleStrings::cMsg_fH1oGKgQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_y159Af6W_sendMessage);
}

void Heavy_CircleStrings::cMsg_zOTX5oHU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_TzI79mT9, 0, m, &cDelay_TzI79mT9_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_tdQGp3Yq, 0, m, &cDelay_tdQGp3Yq_sendMessage);
}

void Heavy_CircleStrings::cMsg_NN5DDkeJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_9YOUEU9I, HV_BINOP_MAX, 1, m, &cBinop_9YOUEU9I_sendMessage);
}

void Heavy_CircleStrings::cBinop_9YOUEU9I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Iw8fG938, HV_BINOP_SUBTRACT, 1, m, &cBinop_Iw8fG938_sendMessage);
}

void Heavy_CircleStrings::cCast_2vzgZHD9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_TzI79mT9, 0, m, &cDelay_TzI79mT9_sendMessage);
}

void Heavy_CircleStrings::cBinop_WUS8v4mp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_TzI79mT9, 2, m, &cDelay_TzI79mT9_sendMessage);
}

void Heavy_CircleStrings::cBinop_nuX0Rd0K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_WUS8v4mp_sendMessage);
}

void Heavy_CircleStrings::cCast_uPqafRx2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_GuOl5wKF, 0, m, &cVar_GuOl5wKF_sendMessage);
  cMsg_n1M2IJBQ_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_KtH8ozvz, 0, m, &cTabhead_KtH8ozvz_sendMessage);
}

void Heavy_CircleStrings::cMsg_sBLO9kCh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_vW5kfk4U_sendMessage);
}

void Heavy_CircleStrings::cSystem_vW5kfk4U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_PgsWLHmJ_sendMessage);
}

void Heavy_CircleStrings::cDelay_ao06001U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_ao06001U, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_4nyuHINW, 0, m, &cDelay_4nyuHINW_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ao06001U, 0, m, &cDelay_ao06001U_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_BIcl6Py6, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_4nyuHINW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_4nyuHINW, m);
  cMsg_x36gxxsU_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_mOjKRWIm_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_5CPOhiLr_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_uWW9kERH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_soWlfJAT_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_6sSB7Hy6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_rSOW8O5X_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ao06001U, 2, m, &cDelay_ao06001U_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_8gpn98nw_sendMessage);
}

void Heavy_CircleStrings::cMsg_soWlfJAT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_6sSB7Hy6, 0, m, &hTable_6sSB7Hy6_sendMessage);
}

void Heavy_CircleStrings::cBinop_PgsWLHmJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 19.392f, 0, m, &cBinop_uWW9kERH_sendMessage);
}

void Heavy_CircleStrings::cMsg_x36gxxsU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_6sSB7Hy6, 0, m, &hTable_6sSB7Hy6_sendMessage);
}

void Heavy_CircleStrings::cCast_8gpn98nw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_ao06001U, 0, m, &cDelay_ao06001U_sendMessage);
}

void Heavy_CircleStrings::cMsg_rSOW8O5X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_4nyuHINW, 2, m, &cDelay_4nyuHINW_sendMessage);
}

void Heavy_CircleStrings::cMsg_5CPOhiLr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_BIcl6Py6, 1, m, NULL);
}

void Heavy_CircleStrings::cTabhead_nh1v6TXI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_XCQszdrD, HV_BINOP_SUBTRACT, 0, m, &cBinop_XCQszdrD_sendMessage);
}

void Heavy_CircleStrings::cMsg_0WJWlYKo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_bSnslrL7_sendMessage);
}

void Heavy_CircleStrings::cSystem_bSnslrL7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_41euMwOj_sendMessage);
}

void Heavy_CircleStrings::cVar_BN0zJU9V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_YKUpd4BG_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_Dpum5Z6c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Dpum5Z6c, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_6GbSm2iR, 0, m, &cDelay_6GbSm2iR_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_fGWXKbAe, 0, m, &sTabread_fGWXKbAe_sendMessage);
}

void Heavy_CircleStrings::cDelay_6GbSm2iR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_6GbSm2iR, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_fGWXKbAe, 0, m, &sTabread_fGWXKbAe_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_6GbSm2iR, 0, m, &cDelay_6GbSm2iR_sendMessage);
}

void Heavy_CircleStrings::sTabread_fGWXKbAe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_vfhcbiQR, HV_BINOP_SUBTRACT, 0, m, &cBinop_vfhcbiQR_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_AWLhKV2m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_s7wbdsCU, HV_BINOP_MAX, 0, m, &cBinop_s7wbdsCU_sendMessage);
}

void Heavy_CircleStrings::cBinop_41euMwOj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_AWLhKV2m, HV_BINOP_MULTIPLY, 0, m, &cBinop_AWLhKV2m_sendMessage);
}

void Heavy_CircleStrings::cBinop_XCQszdrD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Sb0oARSZ_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_fGWXKbAe, 0, m, &sTabread_fGWXKbAe_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_BFGN4EKr_sendMessage);
}

void Heavy_CircleStrings::cSystem_JjEyPQS1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_vfhcbiQR, HV_BINOP_SUBTRACT, 1, m, &cBinop_vfhcbiQR_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_6GbSm2iR, 2, m, &cDelay_6GbSm2iR_sendMessage);
}

void Heavy_CircleStrings::cMsg_YKUpd4BG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_JjEyPQS1_sendMessage);
}

void Heavy_CircleStrings::cMsg_Sb0oARSZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_Dpum5Z6c, 0, m, &cDelay_Dpum5Z6c_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_6GbSm2iR, 0, m, &cDelay_6GbSm2iR_sendMessage);
}

void Heavy_CircleStrings::cMsg_M57SglBd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_s7wbdsCU, HV_BINOP_MAX, 1, m, &cBinop_s7wbdsCU_sendMessage);
}

void Heavy_CircleStrings::cBinop_s7wbdsCU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_XCQszdrD, HV_BINOP_SUBTRACT, 1, m, &cBinop_XCQszdrD_sendMessage);
}

void Heavy_CircleStrings::cCast_BFGN4EKr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Dpum5Z6c, 0, m, &cDelay_Dpum5Z6c_sendMessage);
}

void Heavy_CircleStrings::cBinop_U7m672Mm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Dpum5Z6c, 2, m, &cDelay_Dpum5Z6c_sendMessage);
}

void Heavy_CircleStrings::cBinop_vfhcbiQR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_U7m672Mm_sendMessage);
}

void Heavy_CircleStrings::cCast_UZsybCGL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_BN0zJU9V, 0, m, &cVar_BN0zJU9V_sendMessage);
  cMsg_0WJWlYKo_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_nh1v6TXI, 0, m, &cTabhead_nh1v6TXI_sendMessage);
}

void Heavy_CircleStrings::cMsg_zbddsGqf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_UsWmQHWv_sendMessage);
}

void Heavy_CircleStrings::cSystem_UsWmQHWv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_e57NiUjo_sendMessage);
}

void Heavy_CircleStrings::cDelay_VsugkJeQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_VsugkJeQ, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_nBliQNTW, 0, m, &cDelay_nBliQNTW_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_VsugkJeQ, 0, m, &cDelay_VsugkJeQ_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_7Xefv0Vw, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_nBliQNTW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_nBliQNTW, m);
  cMsg_EeB0WmKY_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_7sp4UszR_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_PipCMfxN_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_odMoLbAo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_4nR7LjEt_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_X7MOLq8C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Id2pMwiO_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_VsugkJeQ, 2, m, &cDelay_VsugkJeQ_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_MT5s9Uf3_sendMessage);
}

void Heavy_CircleStrings::cMsg_4nR7LjEt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_X7MOLq8C, 0, m, &hTable_X7MOLq8C_sendMessage);
}

void Heavy_CircleStrings::cBinop_e57NiUjo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 25.796f, 0, m, &cBinop_odMoLbAo_sendMessage);
}

void Heavy_CircleStrings::cMsg_EeB0WmKY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_X7MOLq8C, 0, m, &hTable_X7MOLq8C_sendMessage);
}

void Heavy_CircleStrings::cCast_MT5s9Uf3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_VsugkJeQ, 0, m, &cDelay_VsugkJeQ_sendMessage);
}

void Heavy_CircleStrings::cMsg_Id2pMwiO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_nBliQNTW, 2, m, &cDelay_nBliQNTW_sendMessage);
}

void Heavy_CircleStrings::cMsg_PipCMfxN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_7Xefv0Vw, 1, m, NULL);
}

void Heavy_CircleStrings::cTabhead_m3DF7heY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_PYVK8qUG, HV_BINOP_SUBTRACT, 0, m, &cBinop_PYVK8qUG_sendMessage);
}

void Heavy_CircleStrings::cMsg_LbK4uXZ3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_bCromGIq_sendMessage);
}

void Heavy_CircleStrings::cSystem_bCromGIq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_cMTW4lMd_sendMessage);
}

void Heavy_CircleStrings::cVar_gjDOvGBK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_XyWBstGV_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_cXXHnfKg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_cXXHnfKg, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_z3dCw8os, 0, m, &cDelay_z3dCw8os_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_F0xS8TOw, 0, m, &sTabread_F0xS8TOw_sendMessage);
}

void Heavy_CircleStrings::cDelay_z3dCw8os_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_z3dCw8os, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_F0xS8TOw, 0, m, &sTabread_F0xS8TOw_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_z3dCw8os, 0, m, &cDelay_z3dCw8os_sendMessage);
}

void Heavy_CircleStrings::sTabread_F0xS8TOw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_nF58nSNS, HV_BINOP_SUBTRACT, 0, m, &cBinop_nF58nSNS_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_Ma022gkD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_vMP2Pyuj, HV_BINOP_MAX, 0, m, &cBinop_vMP2Pyuj_sendMessage);
}

void Heavy_CircleStrings::cBinop_cMTW4lMd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Ma022gkD, HV_BINOP_MULTIPLY, 0, m, &cBinop_Ma022gkD_sendMessage);
}

void Heavy_CircleStrings::cBinop_PYVK8qUG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_tivyvn0A_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_F0xS8TOw, 0, m, &sTabread_F0xS8TOw_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_iDOo5ofD_sendMessage);
}

void Heavy_CircleStrings::cSystem_8C7zIJfg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_nF58nSNS, HV_BINOP_SUBTRACT, 1, m, &cBinop_nF58nSNS_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_z3dCw8os, 2, m, &cDelay_z3dCw8os_sendMessage);
}

void Heavy_CircleStrings::cMsg_XyWBstGV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_8C7zIJfg_sendMessage);
}

void Heavy_CircleStrings::cMsg_tivyvn0A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_cXXHnfKg, 0, m, &cDelay_cXXHnfKg_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_z3dCw8os, 0, m, &cDelay_z3dCw8os_sendMessage);
}

void Heavy_CircleStrings::cMsg_GX9W5YTl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_vMP2Pyuj, HV_BINOP_MAX, 1, m, &cBinop_vMP2Pyuj_sendMessage);
}

void Heavy_CircleStrings::cBinop_vMP2Pyuj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_PYVK8qUG, HV_BINOP_SUBTRACT, 1, m, &cBinop_PYVK8qUG_sendMessage);
}

void Heavy_CircleStrings::cCast_iDOo5ofD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_cXXHnfKg, 0, m, &cDelay_cXXHnfKg_sendMessage);
}

void Heavy_CircleStrings::cBinop_p3dtjHDA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_cXXHnfKg, 2, m, &cDelay_cXXHnfKg_sendMessage);
}

void Heavy_CircleStrings::cBinop_nF58nSNS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_p3dtjHDA_sendMessage);
}

void Heavy_CircleStrings::cCast_Bi6ym8Sk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_gjDOvGBK, 0, m, &cVar_gjDOvGBK_sendMessage);
  cMsg_LbK4uXZ3_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_m3DF7heY, 0, m, &cTabhead_m3DF7heY_sendMessage);
}

void Heavy_CircleStrings::cMsg_761ANgX5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_fGMoVCrx_sendMessage);
}

void Heavy_CircleStrings::cSystem_fGMoVCrx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_YyHzc2tG_sendMessage);
}

void Heavy_CircleStrings::cDelay_W6nNWxVM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_W6nNWxVM, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_WrGOGpi0, 0, m, &cDelay_WrGOGpi0_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_W6nNWxVM, 0, m, &cDelay_W6nNWxVM_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_U60LhyMp, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_WrGOGpi0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_WrGOGpi0, m);
  cMsg_DnLbPLlg_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_lfFJ7EKx_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_0LiPyddR_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_yE3lHXKp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_fqOXq3io_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_2gfCxAKy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_l5Mxtah1_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_W6nNWxVM, 2, m, &cDelay_W6nNWxVM_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_I25U924Z_sendMessage);
}

void Heavy_CircleStrings::cMsg_fqOXq3io_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_2gfCxAKy, 0, m, &hTable_2gfCxAKy_sendMessage);
}

void Heavy_CircleStrings::cBinop_YyHzc2tG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 43.5337f, 0, m, &cBinop_yE3lHXKp_sendMessage);
}

void Heavy_CircleStrings::cMsg_DnLbPLlg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_2gfCxAKy, 0, m, &hTable_2gfCxAKy_sendMessage);
}

void Heavy_CircleStrings::cCast_I25U924Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_W6nNWxVM, 0, m, &cDelay_W6nNWxVM_sendMessage);
}

void Heavy_CircleStrings::cMsg_l5Mxtah1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_WrGOGpi0, 2, m, &cDelay_WrGOGpi0_sendMessage);
}

void Heavy_CircleStrings::cMsg_0LiPyddR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_U60LhyMp, 1, m, NULL);
}

void Heavy_CircleStrings::cTabhead_eKzW24RL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Xzawq8LB, HV_BINOP_SUBTRACT, 0, m, &cBinop_Xzawq8LB_sendMessage);
}

void Heavy_CircleStrings::cMsg_yJGaigD9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_PWDHuOMG_sendMessage);
}

void Heavy_CircleStrings::cSystem_PWDHuOMG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_QPJRSzMo_sendMessage);
}

void Heavy_CircleStrings::cVar_XC5Lpguv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_DTvqj0ax_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_Fgunxv5b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Fgunxv5b, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_zV1nuDoY, 0, m, &cDelay_zV1nuDoY_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_IUZVy1z9, 0, m, &sTabread_IUZVy1z9_sendMessage);
}

void Heavy_CircleStrings::cDelay_zV1nuDoY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_zV1nuDoY, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_IUZVy1z9, 0, m, &sTabread_IUZVy1z9_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_zV1nuDoY, 0, m, &cDelay_zV1nuDoY_sendMessage);
}

void Heavy_CircleStrings::sTabread_IUZVy1z9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_mu6hkjVD, HV_BINOP_SUBTRACT, 0, m, &cBinop_mu6hkjVD_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_gxqNasS1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_HubjzxEk, HV_BINOP_MAX, 0, m, &cBinop_HubjzxEk_sendMessage);
}

void Heavy_CircleStrings::cBinop_QPJRSzMo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_gxqNasS1, HV_BINOP_MULTIPLY, 0, m, &cBinop_gxqNasS1_sendMessage);
}

void Heavy_CircleStrings::cBinop_Xzawq8LB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_AqMVA9v4_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_IUZVy1z9, 0, m, &sTabread_IUZVy1z9_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_NmztAIof_sendMessage);
}

void Heavy_CircleStrings::cSystem_Pa9vAI0v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_mu6hkjVD, HV_BINOP_SUBTRACT, 1, m, &cBinop_mu6hkjVD_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_zV1nuDoY, 2, m, &cDelay_zV1nuDoY_sendMessage);
}

void Heavy_CircleStrings::cMsg_DTvqj0ax_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Pa9vAI0v_sendMessage);
}

void Heavy_CircleStrings::cMsg_AqMVA9v4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_Fgunxv5b, 0, m, &cDelay_Fgunxv5b_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_zV1nuDoY, 0, m, &cDelay_zV1nuDoY_sendMessage);
}

void Heavy_CircleStrings::cMsg_pLWvNmkn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_HubjzxEk, HV_BINOP_MAX, 1, m, &cBinop_HubjzxEk_sendMessage);
}

void Heavy_CircleStrings::cBinop_HubjzxEk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Xzawq8LB, HV_BINOP_SUBTRACT, 1, m, &cBinop_Xzawq8LB_sendMessage);
}

void Heavy_CircleStrings::cCast_NmztAIof_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Fgunxv5b, 0, m, &cDelay_Fgunxv5b_sendMessage);
}

void Heavy_CircleStrings::cBinop_8pAPkE0q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Fgunxv5b, 2, m, &cDelay_Fgunxv5b_sendMessage);
}

void Heavy_CircleStrings::cBinop_mu6hkjVD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_8pAPkE0q_sendMessage);
}

void Heavy_CircleStrings::cCast_UIJZbdis_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_XC5Lpguv, 0, m, &cVar_XC5Lpguv_sendMessage);
  cMsg_yJGaigD9_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_eKzW24RL, 0, m, &cTabhead_eKzW24RL_sendMessage);
}

void Heavy_CircleStrings::cMsg_RwSeDKMn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_zuzy8YhU_sendMessage);
}

void Heavy_CircleStrings::cSystem_zuzy8YhU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_Sz1UlJFD_sendMessage);
}

void Heavy_CircleStrings::cDelay_BAUXMOAX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_BAUXMOAX, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_MI8QUrNU, 0, m, &cDelay_MI8QUrNU_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_BAUXMOAX, 0, m, &cDelay_BAUXMOAX_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_9zWFmF8i, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_MI8QUrNU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_MI8QUrNU, m);
  cMsg_U1DpjFig_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_Q7UZhMB2_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_rhIH4JhL_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_D963xMa4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_F946txJV_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_UT8gYIoQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_PgWlE7RP_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_BAUXMOAX, 2, m, &cDelay_BAUXMOAX_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ohBJqhVx_sendMessage);
}

void Heavy_CircleStrings::cMsg_F946txJV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_UT8gYIoQ, 0, m, &hTable_UT8gYIoQ_sendMessage);
}

void Heavy_CircleStrings::cBinop_Sz1UlJFD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 75.2546f, 0, m, &cBinop_D963xMa4_sendMessage);
}

void Heavy_CircleStrings::cMsg_U1DpjFig_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_UT8gYIoQ, 0, m, &hTable_UT8gYIoQ_sendMessage);
}

void Heavy_CircleStrings::cCast_ohBJqhVx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_BAUXMOAX, 0, m, &cDelay_BAUXMOAX_sendMessage);
}

void Heavy_CircleStrings::cMsg_PgWlE7RP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_MI8QUrNU, 2, m, &cDelay_MI8QUrNU_sendMessage);
}

void Heavy_CircleStrings::cMsg_rhIH4JhL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_9zWFmF8i, 1, m, NULL);
}

void Heavy_CircleStrings::cVar_uuE2YQjm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_74RnRCDV, 0, m, &cVar_74RnRCDV_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_ZcCqvYFc, 0, m, &cVar_ZcCqvYFc_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_ulNJrwP1, 0, m, &cVar_ulNJrwP1_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_kCPY6E1j, 0, m, &cVar_kCPY6E1j_sendMessage);
}

void Heavy_CircleStrings::cVar_J62g29j8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.01f, 0, m, &cBinop_z7nD1Iea_sendMessage);
}

void Heavy_CircleStrings::cPack_kSSoJ2sU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_WI5IkPof, 0, m, NULL);
}

void Heavy_CircleStrings::cVar_ZcCqvYFc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_RB7LKaxx, HV_BINOP_MULTIPLY, 0, m, &cBinop_RB7LKaxx_sendMessage);
}

void Heavy_CircleStrings::cMsg_uzkKcGEb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_f1yXaKHJ_sendMessage);
}

void Heavy_CircleStrings::cSystem_f1yXaKHJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_2Z6e1qFS_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_RB7LKaxx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_PmiaY8fx_sendMessage);
}

void Heavy_CircleStrings::cBinop_41hUnenA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_RB7LKaxx, HV_BINOP_MULTIPLY, 1, m, &cBinop_RB7LKaxx_sendMessage);
}

void Heavy_CircleStrings::cMsg_2Z6e1qFS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_41hUnenA_sendMessage);
}

void Heavy_CircleStrings::cBinop_PmiaY8fx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_lYgJXQWN_sendMessage);
}

void Heavy_CircleStrings::cBinop_lYgJXQWN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_SxMBxVu0_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_fgbIvbik, m);
}

void Heavy_CircleStrings::cBinop_SxMBxVu0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_tDrCQpcP, m);
}

void Heavy_CircleStrings::cVar_ulNJrwP1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_OYc9sUe4, HV_BINOP_MULTIPLY, 0, m, &cBinop_OYc9sUe4_sendMessage);
}

void Heavy_CircleStrings::cMsg_nHZorksF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_kgW3D2dC_sendMessage);
}

void Heavy_CircleStrings::cSystem_kgW3D2dC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_2fqvySgQ_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_OYc9sUe4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_4BUzGknh_sendMessage);
}

void Heavy_CircleStrings::cBinop_oTQJ1eSh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_OYc9sUe4, HV_BINOP_MULTIPLY, 1, m, &cBinop_OYc9sUe4_sendMessage);
}

void Heavy_CircleStrings::cMsg_2fqvySgQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_oTQJ1eSh_sendMessage);
}

void Heavy_CircleStrings::cBinop_4BUzGknh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_gEA3Hopg_sendMessage);
}

void Heavy_CircleStrings::cBinop_gEA3Hopg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_H5aHZwOu_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_h01R1Ld9, m);
}

void Heavy_CircleStrings::cBinop_H5aHZwOu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_60UokQL2, m);
}

void Heavy_CircleStrings::cVar_kCPY6E1j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_vztLTuSL, HV_BINOP_MULTIPLY, 0, m, &cBinop_vztLTuSL_sendMessage);
}

void Heavy_CircleStrings::cMsg_a3nnS5xU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_uE1IUFCV_sendMessage);
}

void Heavy_CircleStrings::cSystem_uE1IUFCV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_tsGqwNgg_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_vztLTuSL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_3o9RDQ5q_sendMessage);
}

void Heavy_CircleStrings::cBinop_hjlJ1Ufv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_vztLTuSL, HV_BINOP_MULTIPLY, 1, m, &cBinop_vztLTuSL_sendMessage);
}

void Heavy_CircleStrings::cMsg_tsGqwNgg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_hjlJ1Ufv_sendMessage);
}

void Heavy_CircleStrings::cBinop_3o9RDQ5q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_5zotNNEv_sendMessage);
}

void Heavy_CircleStrings::cBinop_5zotNNEv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_TdyKGUPw_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_RVRjBK8D, m);
}

void Heavy_CircleStrings::cBinop_TdyKGUPw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_hVJ19mrl, m);
}

void Heavy_CircleStrings::cBinop_wJBbioPS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_3AmPPqfy, 0, m, &cPack_3AmPPqfy_sendMessage);
}

void Heavy_CircleStrings::cMsg_UCtIL46u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 3000.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_uuE2YQjm, 0, m, &cVar_uuE2YQjm_sendMessage);
}

void Heavy_CircleStrings::cBinop_z7nD1Iea_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_kSSoJ2sU, 0, m, &cPack_kSSoJ2sU_sendMessage);
}

void Heavy_CircleStrings::cBinop_PzvvelhO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_GHi8oYBG, 0, m, &cPack_GHi8oYBG_sendMessage);
}

void Heavy_CircleStrings::cMsg_RE3sI7DQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Qt98QfpX_sendMessage);
}

void Heavy_CircleStrings::cSystem_Qt98QfpX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_UeHdNdK5_sendMessage);
}

void Heavy_CircleStrings::cVar_e7Wnw651_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ZPxU0PUb_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSystem_D662J87I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_5DOPlnEa_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_z3V7FGDC, m);
}

void Heavy_CircleStrings::cBinop_UeHdNdK5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_SQsCBqpT, m);
}

void Heavy_CircleStrings::cMsg_ZPxU0PUb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_D662J87I_sendMessage);
}

void Heavy_CircleStrings::cBinop_5DOPlnEa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_xpAQZRaH, m);
}

void Heavy_CircleStrings::cVar_Pr4kJt9x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_1rLN6CNM, HV_BINOP_MULTIPLY, 0, m, &cBinop_1rLN6CNM_sendMessage);
}

void Heavy_CircleStrings::cMsg_kMb8lKdl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_x4XTC9Ru_sendMessage);
}

void Heavy_CircleStrings::cSystem_x4XTC9Ru_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_YA6H9uuQ_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_1rLN6CNM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_teuRofaT_sendMessage);
}

void Heavy_CircleStrings::cBinop_zEhe0vZU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_1rLN6CNM, HV_BINOP_MULTIPLY, 1, m, &cBinop_1rLN6CNM_sendMessage);
}

void Heavy_CircleStrings::cMsg_YA6H9uuQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_zEhe0vZU_sendMessage);
}

void Heavy_CircleStrings::cBinop_teuRofaT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_x0KFrbJg_sendMessage);
}

void Heavy_CircleStrings::cBinop_x0KFrbJg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_Irz3fw1l_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_OdteWPZx, m);
}

void Heavy_CircleStrings::cBinop_Irz3fw1l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_3QE3btHo, m);
}

void Heavy_CircleStrings::cBinop_585Y30b4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, -1.0f, 0, m, &cBinop_CblxjiGt_sendMessage);
}

void Heavy_CircleStrings::cBinop_CblxjiGt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_RZyu0DjM, m);
}

void Heavy_CircleStrings::cBinop_ROkxOkOk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_QBdQWAag_sendMessage);
}

void Heavy_CircleStrings::cBinop_QBdQWAag_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_9l8LsQyn_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_AW0gTrLw_sendMessage);
}

void Heavy_CircleStrings::cVar_gNYN7LI5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_UzDnGrXu_sendMessage);
}

void Heavy_CircleStrings::cMsg_n25CeRfX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_eLU1Fw1B_sendMessage);
}

void Heavy_CircleStrings::cSystem_eLU1Fw1B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_v4ao5Z2v, HV_BINOP_DIVIDE, 1, m, &cBinop_v4ao5Z2v_sendMessage);
}

void Heavy_CircleStrings::cBinop_9l8LsQyn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_5zrJUHFU_sendMessage);
}

void Heavy_CircleStrings::cBinop_5zrJUHFU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_2qLwisnm, m);
}

void Heavy_CircleStrings::cMsg_66ioaYmh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_IDDWsd50_sendMessage);
}

void Heavy_CircleStrings::cBinop_IDDWsd50_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_ROkxOkOk_sendMessage);
}

void Heavy_CircleStrings::cBinop_AW0gTrLw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_iLpkvaHj, m);
}

void Heavy_CircleStrings::cBinop_UzDnGrXu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_jSvENuU5_sendMessage);
}

void Heavy_CircleStrings::cBinop_jSvENuU5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_v4ao5Z2v, HV_BINOP_DIVIDE, 0, m, &cBinop_v4ao5Z2v_sendMessage);
}

void Heavy_CircleStrings::cBinop_v4ao5Z2v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_66ioaYmh_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cVar_gjIuhEB1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_XeAoxUEC_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_5IHmfa9u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_v5eCgH4R_sendMessage);
}

void Heavy_CircleStrings::cSystem_v5eCgH4R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_qdnba8sZ_sendMessage);
}

void Heavy_CircleStrings::cDelay_OMCmfLwL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_OMCmfLwL, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_O7IM9YxK, 0, m, &cDelay_O7IM9YxK_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_OMCmfLwL, 0, m, &cDelay_OMCmfLwL_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_HgqY4tum, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_O7IM9YxK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_O7IM9YxK, m);
  cMsg_5LtCbMce_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_yRTqeXmT_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_3YyQgsxN_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_tq8PKzQR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_q8X9pPXZ_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_r3uhFRAO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_23C3VBmL_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_OMCmfLwL, 2, m, &cDelay_OMCmfLwL_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_rC1PcLi4_sendMessage);
}

void Heavy_CircleStrings::cMsg_q8X9pPXZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_r3uhFRAO, 0, m, &hTable_r3uhFRAO_sendMessage);
}

void Heavy_CircleStrings::cBinop_qdnba8sZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 500.0f, 0, m, &cBinop_tq8PKzQR_sendMessage);
}

void Heavy_CircleStrings::cMsg_5LtCbMce_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_r3uhFRAO, 0, m, &hTable_r3uhFRAO_sendMessage);
}

void Heavy_CircleStrings::cCast_rC1PcLi4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_OMCmfLwL, 0, m, &cDelay_OMCmfLwL_sendMessage);
}

void Heavy_CircleStrings::cMsg_23C3VBmL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_O7IM9YxK, 2, m, &cDelay_O7IM9YxK_sendMessage);
}

void Heavy_CircleStrings::cMsg_3YyQgsxN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_HgqY4tum, 1, m, NULL);
}

void Heavy_CircleStrings::cMsg_b4IFSR5L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cMsg_XeAoxUEC_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_XeAoxUEC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 20.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_socRXfBC, 0, m, NULL);
}

void Heavy_CircleStrings::cPack_rEvwJGWN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_lGbUqyqN, 0, m, NULL);
}

void Heavy_CircleStrings::cCast_V7jZHueA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_rEvwJGWN, 0, m, &cPack_rEvwJGWN_sendMessage);
}

void Heavy_CircleStrings::cCast_raLvftWU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_xqMTFkdu_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cMsg_1gFCZUcK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 500.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_lGbUqyqN, 0, m, NULL);
}

void Heavy_CircleStrings::cMsg_CKPR4RaG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 500.0f);
  sVarf_onMessage(_c, &Context(_c)->sVarf_gD2uy6r5, m);
}

void Heavy_CircleStrings::cMsg_MS9tzzCB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.3f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_585Y30b4_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_9q7Jnlwq_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_owQExA90, 0, m, &cSlice_owQExA90_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_DoLL23Bx, 0, m, &cRandom_DoLL23Bx_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_9ISrol5l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_cHOeG4Jw_sendMessage);
}

void Heavy_CircleStrings::cUnop_cHOeG4Jw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 10.0f, 0, m, &cBinop_cO7ttehm_sendMessage);
}

void Heavy_CircleStrings::cRandom_DoLL23Bx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 80.0f, 0, m, &cBinop_9ISrol5l_sendMessage);
}

void Heavy_CircleStrings::cSlice_owQExA90_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_DoLL23Bx, 1, m, &cRandom_DoLL23Bx_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cSwitchcase_HzsmGwI1_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_leFLfzus, 0, m, &cSlice_leFLfzus_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_ARKuTEhg, 0, m, &cRandom_ARKuTEhg_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_PU4PAG1T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_yTqzG8Fr_sendMessage);
}

void Heavy_CircleStrings::cUnop_yTqzG8Fr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_N161spau, 0, m, &cPack_N161spau_sendMessage);
}

void Heavy_CircleStrings::cRandom_ARKuTEhg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 200.0f, 0, m, &cBinop_PU4PAG1T_sendMessage);
}

void Heavy_CircleStrings::cSlice_leFLfzus_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_ARKuTEhg, 1, m, &cRandom_ARKuTEhg_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cVar_rwTFIpvJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_HcMFpN59_sendMessage);
}

void Heavy_CircleStrings::cPack_DDQYfJK0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_stjxvo35, 0, m, NULL);
}

void Heavy_CircleStrings::cUnop_L4ZfI7pq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_e7xhqeiH_sendMessage);
}

void Heavy_CircleStrings::cBinop_z3gV2bQp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_EXP, m, &cUnop_L4ZfI7pq_sendMessage);
}

void Heavy_CircleStrings::cPack_2EQ9qJlo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_S2udaKf5, 0, m, NULL);
}

void Heavy_CircleStrings::cVar_NG1201mj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.5f, 0, m, &cBinop_F7lQfToe_sendMessage);
}

void Heavy_CircleStrings::cMsg_70kPl2Zd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_YZFk2x3x_sendMessage);
}

void Heavy_CircleStrings::cSystem_YZFk2x3x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_6LXE7IwI_sendMessage);
}

void Heavy_CircleStrings::cDelay_aTimklCN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_aTimklCN, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_r05jxH4U, 0, m, &cDelay_r05jxH4U_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_aTimklCN, 0, m, &cDelay_aTimklCN_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_NQBcNdSe, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_r05jxH4U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_r05jxH4U, m);
  cMsg_GQcU4cof_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_NdHqHLpL_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_kIbqPNTo_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_zCjePVGW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_v6drLk7W_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_Hi9yYgYc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_gSED7B7Y_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_aTimklCN, 2, m, &cDelay_aTimklCN_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_wp746y98_sendMessage);
}

void Heavy_CircleStrings::cMsg_v6drLk7W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_Hi9yYgYc, 0, m, &hTable_Hi9yYgYc_sendMessage);
}

void Heavy_CircleStrings::cBinop_6LXE7IwI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 5000.0f, 0, m, &cBinop_zCjePVGW_sendMessage);
}

void Heavy_CircleStrings::cMsg_GQcU4cof_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_Hi9yYgYc, 0, m, &hTable_Hi9yYgYc_sendMessage);
}

void Heavy_CircleStrings::cCast_wp746y98_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_aTimklCN, 0, m, &cDelay_aTimklCN_sendMessage);
}

void Heavy_CircleStrings::cMsg_gSED7B7Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_r05jxH4U, 2, m, &cDelay_r05jxH4U_sendMessage);
}

void Heavy_CircleStrings::cMsg_kIbqPNTo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_NQBcNdSe, 1, m, NULL);
}

void Heavy_CircleStrings::cMsg_Hhvp9rP5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_a04XM5WG_sendMessage);
}

void Heavy_CircleStrings::cSystem_a04XM5WG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_CbjNifcn_sendMessage);
}

void Heavy_CircleStrings::cVar_rE5M39Qj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_q7ZHWs3w_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSystem_AsMV1Tqc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_3Oc5jxMe_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_YDwwWFrn, m);
}

void Heavy_CircleStrings::cBinop_CbjNifcn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_FuWhBjDZ, m);
}

void Heavy_CircleStrings::cMsg_q7ZHWs3w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_AsMV1Tqc_sendMessage);
}

void Heavy_CircleStrings::cBinop_3Oc5jxMe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_J5wGu32K, m);
}

void Heavy_CircleStrings::cMsg_OlBaV9B6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_2dayjOBe_sendMessage);
}

void Heavy_CircleStrings::cSystem_2dayjOBe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_LrQKh0im_sendMessage);
}

void Heavy_CircleStrings::cVar_L9otMwf8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_HJbblXgR_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSystem_UpQGIWaX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_QjmSW4Hk_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_SuuDqkwe, m);
}

void Heavy_CircleStrings::cBinop_LrQKh0im_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_WEOggCsQ, m);
}

void Heavy_CircleStrings::cMsg_HJbblXgR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_UpQGIWaX_sendMessage);
}

void Heavy_CircleStrings::cBinop_QjmSW4Hk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_6CqxHACL, m);
}

void Heavy_CircleStrings::cBinop_rXfOqtyh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_DxWr2q9M_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_p8vlgXwC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_7Kf9hhA2_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ozGN7pj3_sendMessage);
}

void Heavy_CircleStrings::cCast_7Kf9hhA2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_rXfOqtyh, HV_BINOP_DIVIDE, 1, m, &cBinop_rXfOqtyh_sendMessage);
}

void Heavy_CircleStrings::cCast_ozGN7pj3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_rXfOqtyh, HV_BINOP_DIVIDE, 0, m, &cBinop_rXfOqtyh_sendMessage);
}

void Heavy_CircleStrings::cBinop_e7xhqeiH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_JUiUJ2Wp_sendMessage);
}

void Heavy_CircleStrings::cBinop_EuGatUjG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 87.3365f, 0, m, &cBinop_z3gV2bQp_sendMessage);
}

void Heavy_CircleStrings::cBinop_JUiUJ2Wp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_rXfOqtyh, HV_BINOP_DIVIDE, 0, m, &cBinop_rXfOqtyh_sendMessage);
}

void Heavy_CircleStrings::cBinop_F7lQfToe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_2EQ9qJlo, 0, m, &cPack_2EQ9qJlo_sendMessage);
}

void Heavy_CircleStrings::cBinop_HcMFpN59_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.001f, 0, m, &cBinop_p8vlgXwC_sendMessage);
  cPack_onMessage(_c, &Context(_c)->cPack_DDQYfJK0, 0, m, &cPack_DDQYfJK0_sendMessage);
}

void Heavy_CircleStrings::cMsg_LahMcEml_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 100.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_rwTFIpvJ, 0, m, &cVar_rwTFIpvJ_sendMessage);
}

void Heavy_CircleStrings::cMsg_TmORWmC7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.5f);
  cVar_onMessage(_c, &Context(_c)->cVar_NG1201mj, 0, m, &cVar_NG1201mj_sendMessage);
}

void Heavy_CircleStrings::cMsg_DxWr2q9M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 30.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_mrEpoKCx, 0, m, NULL);
}

void Heavy_CircleStrings::cMsg_zVSdTfGr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_fRgfxrVl_sendMessage);
}

void Heavy_CircleStrings::cSystem_fRgfxrVl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_qect9GNS_sendMessage);
}

void Heavy_CircleStrings::cVar_LhGF5E3Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Nu1uAfOD_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSystem_w0mSIlRN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_dFhqguSI_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_0avF5hF4, m);
}

void Heavy_CircleStrings::cBinop_qect9GNS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_7ELSxx6o, m);
}

void Heavy_CircleStrings::cMsg_Nu1uAfOD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_w0mSIlRN_sendMessage);
}

void Heavy_CircleStrings::cBinop_dFhqguSI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_NepA7IB1, m);
}

void Heavy_CircleStrings::cVar_hIOCEH11_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Wpmr75c2, HV_BINOP_MULTIPLY, 0, m, &cBinop_Wpmr75c2_sendMessage);
}

void Heavy_CircleStrings::cMsg_uHHkqg2S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ijMJMPf3_sendMessage);
}

void Heavy_CircleStrings::cSystem_ijMJMPf3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Ni8XjQk9_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_Wpmr75c2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_W2qNdkMR_sendMessage);
}

void Heavy_CircleStrings::cBinop_0WlznKGk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Wpmr75c2, HV_BINOP_MULTIPLY, 1, m, &cBinop_Wpmr75c2_sendMessage);
}

void Heavy_CircleStrings::cMsg_Ni8XjQk9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_0WlznKGk_sendMessage);
}

void Heavy_CircleStrings::cBinop_W2qNdkMR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_Zb2WcvW1_sendMessage);
}

void Heavy_CircleStrings::cBinop_Zb2WcvW1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_y1h53nso_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_SGJmRoOS, m);
}

void Heavy_CircleStrings::cBinop_y1h53nso_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_94IIpfHb, m);
}

void Heavy_CircleStrings::cBinop_2N7FpMST_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, -1.0f, 0, m, &cBinop_aCQRx01a_sendMessage);
}

void Heavy_CircleStrings::cBinop_aCQRx01a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_uxWdVfH0, m);
}

void Heavy_CircleStrings::cBinop_14itbeiW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_aY5YCN9H_sendMessage);
}

void Heavy_CircleStrings::cBinop_aY5YCN9H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_VSzrChGA_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_NHOcsYRX_sendMessage);
}

void Heavy_CircleStrings::cVar_OSAzhwCX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_XOSLE9cR_sendMessage);
}

void Heavy_CircleStrings::cMsg_sxPI51H4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_xMuqmdKK_sendMessage);
}

void Heavy_CircleStrings::cSystem_xMuqmdKK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ADQtuyEc, HV_BINOP_DIVIDE, 1, m, &cBinop_ADQtuyEc_sendMessage);
}

void Heavy_CircleStrings::cBinop_VSzrChGA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_wG2JxO2z_sendMessage);
}

void Heavy_CircleStrings::cBinop_wG2JxO2z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_4IsnjDWd, m);
}

void Heavy_CircleStrings::cMsg_s9oc0DKN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_pqxifPpN_sendMessage);
}

void Heavy_CircleStrings::cBinop_pqxifPpN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_14itbeiW_sendMessage);
}

void Heavy_CircleStrings::cBinop_NHOcsYRX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_G4Ad08ON, m);
}

void Heavy_CircleStrings::cBinop_XOSLE9cR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_fbDZHbCj_sendMessage);
}

void Heavy_CircleStrings::cBinop_fbDZHbCj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ADQtuyEc, HV_BINOP_DIVIDE, 0, m, &cBinop_ADQtuyEc_sendMessage);
}

void Heavy_CircleStrings::cBinop_ADQtuyEc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_s9oc0DKN_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cVar_K2ZLhkH3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_0W0trgSH_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_te0tlirW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_7cSL87D0_sendMessage);
}

void Heavy_CircleStrings::cSystem_7cSL87D0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_d4q3aFeu_sendMessage);
}

void Heavy_CircleStrings::cDelay_wvdoWBLL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_wvdoWBLL, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_rshMajKA, 0, m, &cDelay_rshMajKA_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_wvdoWBLL, 0, m, &cDelay_wvdoWBLL_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_sjhaynXz, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_rshMajKA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_rshMajKA, m);
  cMsg_wSH9m99v_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_zII5B84N_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_DkhiNQXt_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_IVQ8GJl5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_MEObqo81_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_ljdEM2pb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_wYXgmTLG_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_wvdoWBLL, 2, m, &cDelay_wvdoWBLL_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_MGbJccD8_sendMessage);
}

void Heavy_CircleStrings::cMsg_MEObqo81_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_ljdEM2pb, 0, m, &hTable_ljdEM2pb_sendMessage);
}

void Heavy_CircleStrings::cBinop_d4q3aFeu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 200.0f, 0, m, &cBinop_IVQ8GJl5_sendMessage);
}

void Heavy_CircleStrings::cMsg_wSH9m99v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_ljdEM2pb, 0, m, &hTable_ljdEM2pb_sendMessage);
}

void Heavy_CircleStrings::cCast_MGbJccD8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_wvdoWBLL, 0, m, &cDelay_wvdoWBLL_sendMessage);
}

void Heavy_CircleStrings::cMsg_wYXgmTLG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_rshMajKA, 2, m, &cDelay_rshMajKA_sendMessage);
}

void Heavy_CircleStrings::cMsg_DkhiNQXt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_sjhaynXz, 1, m, NULL);
}

void Heavy_CircleStrings::cMsg_zKRcXJP1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cMsg_0W0trgSH_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_0W0trgSH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 20.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_89rTH9lR, 0, m, NULL);
}

void Heavy_CircleStrings::cVar_ItSYF4l3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cMsg_xem8TcTJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_FBKFkUL1_sendMessage);
}

void Heavy_CircleStrings::cSystem_FBKFkUL1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_G9eocWrv, HV_BINOP_MULTIPLY, 1, m, &cBinop_G9eocWrv_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_RQhBn7YV, HV_BINOP_MULTIPLY, 1, m, &cBinop_RQhBn7YV_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_ulfsRb0B_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cMsg_sInGxqd2_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_sInGxqd2_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_QaJ1A0Hc_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cDelay_vo08GyYq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_vo08GyYq, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_vo08GyYq, 0, m, &cDelay_vo08GyYq_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_CYIQFSze, 0, m, &cVar_CYIQFSze_sendMessage);
}

void Heavy_CircleStrings::cCast_QaJ1A0Hc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_sInGxqd2_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_vo08GyYq, 0, m, &cDelay_vo08GyYq_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_CYIQFSze, 0, m, &cVar_CYIQFSze_sendMessage);
}

void Heavy_CircleStrings::cMsg_1zEJmngq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_rdeuOSTo_sendMessage);
}

void Heavy_CircleStrings::cSystem_rdeuOSTo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_onJoJ5nr_sendMessage);
}

void Heavy_CircleStrings::cVar_iG6Q9AMR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_yiLTvZsA, HV_BINOP_MULTIPLY, 0, m, &cBinop_yiLTvZsA_sendMessage);
}

void Heavy_CircleStrings::cMsg_sInGxqd2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_vo08GyYq, 0, m, &cDelay_vo08GyYq_sendMessage);
}

void Heavy_CircleStrings::cBinop_zqSylLhR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_vo08GyYq, 2, m, &cDelay_vo08GyYq_sendMessage);
}

void Heavy_CircleStrings::cBinop_onJoJ5nr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_yiLTvZsA, HV_BINOP_MULTIPLY, 1, m, &cBinop_yiLTvZsA_sendMessage);
}

void Heavy_CircleStrings::cBinop_yiLTvZsA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_zqSylLhR_sendMessage);
}

void Heavy_CircleStrings::cVar_CYIQFSze_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_y2kcfRI7, HV_BINOP_SUBTRACT, 0, m, &cBinop_y2kcfRI7_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_LESS_THAN_EQL, 0.0f, 0, m, &cBinop_rSJusAbq_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_L7W8tYHm_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_FEK0wwA7_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_OoR5zRXv_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cCast_FEK0wwA7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_FhdG7NPX, 0, m, &cVar_FhdG7NPX_sendMessage);
}

void Heavy_CircleStrings::cCast_OoR5zRXv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_atghbYcv_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_sxr90dvQ_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_50LJtuNQ_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cSlice_onMessage(_c, &Context(_c)->cSlice_3WKevw0c, 0, m, &cSlice_3WKevw0c_sendMessage);
      break;
    }
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_GhkRFBFi, 0, m, &cSlice_GhkRFBFi_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_VTrhXZ6e_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_2Ihd9p5X, 0, m, &cSlice_2Ihd9p5X_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_xL9rIoq5, 0, m, &cSlice_xL9rIoq5_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_4QIHVDKE_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_8NXN9Onn_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cSlice_3WKevw0c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_IVjEaOn8_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_IVjEaOn8_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cSlice_GhkRFBFi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ATPlCr4l_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ozlem00L_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ATPlCr4l_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ozlem00L_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cVar_pwBLqF7J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_5UrVx6Lh_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_1Kkm6apz_sendMessage);
}

void Heavy_CircleStrings::cVar_djXXQNug_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_3kmbYdIj_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cSwitchcase_3kmbYdIj_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_NrCMiXsx_sendMessage);
      break;
    }
    default: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_G9eocWrv, HV_BINOP_MULTIPLY, 0, m, &cBinop_G9eocWrv_sendMessage);
      cBinop_onMessage(_c, &Context(_c)->cBinop_gtudRimd, HV_BINOP_DIVIDE, 1, m, &cBinop_gtudRimd_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_iG6Q9AMR, 0, m, &cVar_iG6Q9AMR_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cCast_NrCMiXsx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_PYLwMMyt_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cVar_5dmjvb45_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_gSBG6SPY, HV_BINOP_SUBTRACT, 1, m, &cBinop_gSBG6SPY_sendMessage);
}

void Heavy_CircleStrings::cVar_qvNTVEml_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_FhdG7NPX, 0, m, &cVar_FhdG7NPX_sendMessage);
}

void Heavy_CircleStrings::cVar_FhdG7NPX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_S3AYjpd7, HV_BINOP_ADD, 0, m, &cBinop_S3AYjpd7_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_fnYYIWGR, HV_BINOP_ADD, 0, m, &cBinop_fnYYIWGR_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_TQBaiFpx, 0, m, &cVar_TQBaiFpx_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.05776f, 0, m, &cBinop_EuGatUjG_sendMessage);
}

void Heavy_CircleStrings::cSlice_2Ihd9p5X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_5UrVx6Lh_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_1Kkm6apz_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cSlice_xL9rIoq5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_sIxIPrAQ_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_bEhaUkLD_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_02yTqVTX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_CYIQFSze, 1, m, &cVar_CYIQFSze_sendMessage);
}

void Heavy_CircleStrings::cBinop_RQhBn7YV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_02yTqVTX_sendMessage);
}

void Heavy_CircleStrings::cBinop_G9eocWrv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_dvy0atFU_sendMessage);
}

void Heavy_CircleStrings::cBinop_dvy0atFU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_y2kcfRI7, HV_BINOP_SUBTRACT, 1, m, &cBinop_y2kcfRI7_sendMessage);
}

void Heavy_CircleStrings::cBinop_y2kcfRI7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_CYIQFSze, 1, m, &cVar_CYIQFSze_sendMessage);
}

void Heavy_CircleStrings::cMsg_9IQCsUZr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_ulfsRb0B_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cMsg_LQMwEsgX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_ulfsRb0B_onMessage(_c, NULL, 0, m, NULL);
  cBinop_onMessage(_c, &Context(_c)->cBinop_fnYYIWGR, HV_BINOP_ADD, 1, m, &cBinop_fnYYIWGR_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_S3AYjpd7, HV_BINOP_ADD, 1, m, &cBinop_S3AYjpd7_sendMessage);
}

void Heavy_CircleStrings::cBinop_rSJusAbq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_L7W8tYHm_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cBinop_S3AYjpd7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_FhdG7NPX, 1, m, &cVar_FhdG7NPX_sendMessage);
}

void Heavy_CircleStrings::cBinop_gtudRimd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_D6884NBg, HV_BINOP_DIVIDE, 1, m, &cBinop_D6884NBg_sendMessage);
}

void Heavy_CircleStrings::cBinop_D6884NBg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_fnYYIWGR, HV_BINOP_ADD, 1, m, &cBinop_fnYYIWGR_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_S3AYjpd7, HV_BINOP_ADD, 1, m, &cBinop_S3AYjpd7_sendMessage);
}

void Heavy_CircleStrings::cCast_5UrVx6Lh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_RQhBn7YV, HV_BINOP_MULTIPLY, 0, m, &cBinop_RQhBn7YV_sendMessage);
}

void Heavy_CircleStrings::cCast_1Kkm6apz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_gtudRimd, HV_BINOP_DIVIDE, 0, m, &cBinop_gtudRimd_sendMessage);
}

void Heavy_CircleStrings::cCast_bEhaUkLD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_gSBG6SPY, HV_BINOP_SUBTRACT, 0, m, &cBinop_gSBG6SPY_sendMessage);
}

void Heavy_CircleStrings::cCast_sIxIPrAQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_qvNTVEml, 1, m, &cVar_qvNTVEml_sendMessage);
}

void Heavy_CircleStrings::cCast_sxr90dvQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_qvNTVEml, 0, m, &cVar_qvNTVEml_sendMessage);
}

void Heavy_CircleStrings::cCast_atghbYcv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_LQMwEsgX_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_fnYYIWGR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_5dmjvb45, 0, m, &cVar_5dmjvb45_sendMessage);
}

void Heavy_CircleStrings::cMsg_IVjEaOn8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_ulfsRb0B_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cMsg_riqkPRrt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_pwBLqF7J, 1, m, &cVar_pwBLqF7J_sendMessage);
}

void Heavy_CircleStrings::cMsg_PYLwMMyt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 20.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_G9eocWrv, HV_BINOP_MULTIPLY, 0, m, &cBinop_G9eocWrv_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_gtudRimd, HV_BINOP_DIVIDE, 1, m, &cBinop_gtudRimd_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_iG6Q9AMR, 0, m, &cVar_iG6Q9AMR_sendMessage);
}

void Heavy_CircleStrings::cCast_ATPlCr4l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_IVjEaOn8_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_ozlem00L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_d0tDPuPZ_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_fnYYIWGR, HV_BINOP_ADD, 0, m, &cBinop_fnYYIWGR_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_FhdG7NPX, 1, m, &cVar_FhdG7NPX_sendMessage);
}

void Heavy_CircleStrings::cBinop_gSBG6SPY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_D6884NBg, HV_BINOP_DIVIDE, 0, m, &cBinop_D6884NBg_sendMessage);
}

void Heavy_CircleStrings::cCast_d0tDPuPZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_LQMwEsgX_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_8NXN9Onn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_riqkPRrt_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_4QIHVDKE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_9IQCsUZr_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_VTrhXZ6e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_pwBLqF7J, 0, m, &cVar_pwBLqF7J_sendMessage);
}

void Heavy_CircleStrings::cVar_TQBaiFpx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cPack_cysyNOV1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_50LJtuNQ_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cMsg_pwvESEQD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_1mNhAuQe_sendMessage);
}

void Heavy_CircleStrings::cSystem_1mNhAuQe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_hq1WEs5C, HV_BINOP_MULTIPLY, 1, m, &cBinop_hq1WEs5C_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_jX9eDMgF, HV_BINOP_MULTIPLY, 1, m, &cBinop_jX9eDMgF_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_nXPDk9kK_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cMsg_JRoDYtz8_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_JRoDYtz8_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_FvOYw4Ef_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cDelay_eyIdlOhM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_eyIdlOhM, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_eyIdlOhM, 0, m, &cDelay_eyIdlOhM_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_lqjrklkx, 0, m, &cVar_lqjrklkx_sendMessage);
}

void Heavy_CircleStrings::cCast_FvOYw4Ef_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_JRoDYtz8_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_eyIdlOhM, 0, m, &cDelay_eyIdlOhM_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_lqjrklkx, 0, m, &cVar_lqjrklkx_sendMessage);
}

void Heavy_CircleStrings::cMsg_xiuWqnl1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_fbcSspZs_sendMessage);
}

void Heavy_CircleStrings::cSystem_fbcSspZs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_FCKvcVcP_sendMessage);
}

void Heavy_CircleStrings::cVar_05zfhTHZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_RSTOe3dx, HV_BINOP_MULTIPLY, 0, m, &cBinop_RSTOe3dx_sendMessage);
}

void Heavy_CircleStrings::cMsg_JRoDYtz8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_eyIdlOhM, 0, m, &cDelay_eyIdlOhM_sendMessage);
}

void Heavy_CircleStrings::cBinop_lbZK68tV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_eyIdlOhM, 2, m, &cDelay_eyIdlOhM_sendMessage);
}

void Heavy_CircleStrings::cBinop_FCKvcVcP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_RSTOe3dx, HV_BINOP_MULTIPLY, 1, m, &cBinop_RSTOe3dx_sendMessage);
}

void Heavy_CircleStrings::cBinop_RSTOe3dx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_lbZK68tV_sendMessage);
}

void Heavy_CircleStrings::cVar_lqjrklkx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_DOmWXtIq, HV_BINOP_SUBTRACT, 0, m, &cBinop_DOmWXtIq_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_LESS_THAN_EQL, 0.0f, 0, m, &cBinop_NMxDP6yZ_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_kkQlmUDL_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_x4plryeu_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_THz6bFD7_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cCast_x4plryeu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_X1zDQ0L8, 0, m, &cVar_X1zDQ0L8_sendMessage);
}

void Heavy_CircleStrings::cCast_THz6bFD7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_P8yBizBH_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_GTTmX9G7_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_wOeMAJUZ_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cSlice_onMessage(_c, &Context(_c)->cSlice_0MnQNyRL, 0, m, &cSlice_0MnQNyRL_sendMessage);
      break;
    }
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_I5TA7xOd, 0, m, &cSlice_I5TA7xOd_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_MRynMaBv_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_ifZ2iUEY, 0, m, &cSlice_ifZ2iUEY_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_bXRWTXOP, 0, m, &cSlice_bXRWTXOP_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_UoEu3YFx_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_dpu132FR_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cSlice_0MnQNyRL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_HisnC8Et_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_HisnC8Et_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cSlice_I5TA7xOd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_rqlyDHMK_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_eJgYtORP_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_rqlyDHMK_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_eJgYtORP_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cVar_k6z3pVxx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_SgdhYojs_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_nCDS1Zfk_sendMessage);
}

void Heavy_CircleStrings::cVar_q6orzG1H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_TXtwfWrh_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cSwitchcase_TXtwfWrh_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_QzawFuO1_sendMessage);
      break;
    }
    default: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_hq1WEs5C, HV_BINOP_MULTIPLY, 0, m, &cBinop_hq1WEs5C_sendMessage);
      cBinop_onMessage(_c, &Context(_c)->cBinop_0FTfUIS5, HV_BINOP_DIVIDE, 1, m, &cBinop_0FTfUIS5_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_05zfhTHZ, 0, m, &cVar_05zfhTHZ_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cCast_QzawFuO1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_pdkjuxOD_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cVar_eTOirtGv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_z0gxxexp, HV_BINOP_SUBTRACT, 1, m, &cBinop_z0gxxexp_sendMessage);
}

void Heavy_CircleStrings::cVar_MTnPwSC8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_X1zDQ0L8, 0, m, &cVar_X1zDQ0L8_sendMessage);
}

void Heavy_CircleStrings::cVar_X1zDQ0L8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Y4MwPX5c, HV_BINOP_ADD, 0, m, &cBinop_Y4MwPX5c_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_8stjlBnt, HV_BINOP_ADD, 0, m, &cBinop_8stjlBnt_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_ItSYF4l3, 0, m, &cVar_ItSYF4l3_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_b20AZw3F, m);
}

void Heavy_CircleStrings::cSlice_ifZ2iUEY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_SgdhYojs_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_nCDS1Zfk_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cSlice_bXRWTXOP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_scTyy1SB_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_4X8kZuPp_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_KdO5YH2I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_lqjrklkx, 1, m, &cVar_lqjrklkx_sendMessage);
}

void Heavy_CircleStrings::cBinop_jX9eDMgF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_KdO5YH2I_sendMessage);
}

void Heavy_CircleStrings::cBinop_hq1WEs5C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_pNNYENPP_sendMessage);
}

void Heavy_CircleStrings::cBinop_pNNYENPP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_DOmWXtIq, HV_BINOP_SUBTRACT, 1, m, &cBinop_DOmWXtIq_sendMessage);
}

void Heavy_CircleStrings::cBinop_DOmWXtIq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_lqjrklkx, 1, m, &cVar_lqjrklkx_sendMessage);
}

void Heavy_CircleStrings::cMsg_hu2AMQ5k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_nXPDk9kK_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cMsg_O47qVT5K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_nXPDk9kK_onMessage(_c, NULL, 0, m, NULL);
  cBinop_onMessage(_c, &Context(_c)->cBinop_8stjlBnt, HV_BINOP_ADD, 1, m, &cBinop_8stjlBnt_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_Y4MwPX5c, HV_BINOP_ADD, 1, m, &cBinop_Y4MwPX5c_sendMessage);
}

void Heavy_CircleStrings::cBinop_NMxDP6yZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_kkQlmUDL_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cBinop_Y4MwPX5c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_X1zDQ0L8, 1, m, &cVar_X1zDQ0L8_sendMessage);
}

void Heavy_CircleStrings::cBinop_0FTfUIS5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_B9RbKhYP, HV_BINOP_DIVIDE, 1, m, &cBinop_B9RbKhYP_sendMessage);
}

void Heavy_CircleStrings::cBinop_B9RbKhYP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_8stjlBnt, HV_BINOP_ADD, 1, m, &cBinop_8stjlBnt_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_Y4MwPX5c, HV_BINOP_ADD, 1, m, &cBinop_Y4MwPX5c_sendMessage);
}

void Heavy_CircleStrings::cCast_nCDS1Zfk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_0FTfUIS5, HV_BINOP_DIVIDE, 0, m, &cBinop_0FTfUIS5_sendMessage);
}

void Heavy_CircleStrings::cCast_SgdhYojs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_jX9eDMgF, HV_BINOP_MULTIPLY, 0, m, &cBinop_jX9eDMgF_sendMessage);
}

void Heavy_CircleStrings::cCast_scTyy1SB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_MTnPwSC8, 1, m, &cVar_MTnPwSC8_sendMessage);
}

void Heavy_CircleStrings::cCast_4X8kZuPp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_z0gxxexp, HV_BINOP_SUBTRACT, 0, m, &cBinop_z0gxxexp_sendMessage);
}

void Heavy_CircleStrings::cCast_P8yBizBH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_O47qVT5K_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_GTTmX9G7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_MTnPwSC8, 0, m, &cVar_MTnPwSC8_sendMessage);
}

void Heavy_CircleStrings::cBinop_8stjlBnt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_eTOirtGv, 0, m, &cVar_eTOirtGv_sendMessage);
}

void Heavy_CircleStrings::cMsg_HisnC8Et_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_nXPDk9kK_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cMsg_t518O4O8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_k6z3pVxx, 1, m, &cVar_k6z3pVxx_sendMessage);
}

void Heavy_CircleStrings::cMsg_pdkjuxOD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 20.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_hq1WEs5C, HV_BINOP_MULTIPLY, 0, m, &cBinop_hq1WEs5C_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_0FTfUIS5, HV_BINOP_DIVIDE, 1, m, &cBinop_0FTfUIS5_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_05zfhTHZ, 0, m, &cVar_05zfhTHZ_sendMessage);
}

void Heavy_CircleStrings::cCast_eJgYtORP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Vui78rqE_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_8stjlBnt, HV_BINOP_ADD, 0, m, &cBinop_8stjlBnt_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_X1zDQ0L8, 1, m, &cVar_X1zDQ0L8_sendMessage);
}

void Heavy_CircleStrings::cCast_rqlyDHMK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_HisnC8Et_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_z0gxxexp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_B9RbKhYP, HV_BINOP_DIVIDE, 0, m, &cBinop_B9RbKhYP_sendMessage);
}

void Heavy_CircleStrings::cCast_Vui78rqE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_O47qVT5K_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_dpu132FR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_t518O4O8_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_MRynMaBv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_k6z3pVxx, 0, m, &cVar_k6z3pVxx_sendMessage);
}

void Heavy_CircleStrings::cCast_UoEu3YFx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_hu2AMQ5k_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cPack_N161spau_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_wOeMAJUZ_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cPack_UMl2RfDo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_HGNNrImW, 0, m, NULL);
}

void Heavy_CircleStrings::cBinop_zF5RNZGA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 4.0f, 0, m, &cBinop_APihIHPc_sendMessage);
}

void Heavy_CircleStrings::cBinop_APihIHPc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_cysyNOV1, 0, m, &cPack_cysyNOV1_sendMessage);
}

void Heavy_CircleStrings::cBinop_cO7ttehm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_zF5RNZGA_sendMessage);
}

void Heavy_CircleStrings::cCast_DxR0Euwn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_HzsmGwI1_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cCast_HgAbB6lI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_9q7Jnlwq_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cMsg_H0DkXdQA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.15f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_2N7FpMST_sendMessage);
}

void Heavy_CircleStrings::cBinop_TZR2m9pc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_wjOurq2M_sendMessage);
}

void Heavy_CircleStrings::cBinop_wjOurq2M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_TV3pu8FM_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_AqSr7Wf1_sendMessage);
}

void Heavy_CircleStrings::cVar_87DbvT2A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_kChDM8hS_sendMessage);
}

void Heavy_CircleStrings::cMsg_TGtdDtXv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_tGxITYJB_sendMessage);
}

void Heavy_CircleStrings::cSystem_tGxITYJB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_qW5NlNh8, HV_BINOP_DIVIDE, 1, m, &cBinop_qW5NlNh8_sendMessage);
}

void Heavy_CircleStrings::cBinop_TV3pu8FM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_WkVIcJtk_sendMessage);
}

void Heavy_CircleStrings::cBinop_WkVIcJtk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_saHl7w3A, m);
}

void Heavy_CircleStrings::cMsg_s8tCfOmc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_q2lwxaHm_sendMessage);
}

void Heavy_CircleStrings::cBinop_q2lwxaHm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_TZR2m9pc_sendMessage);
}

void Heavy_CircleStrings::cBinop_AqSr7Wf1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_5r1xjknQ, m);
}

void Heavy_CircleStrings::cBinop_kChDM8hS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_YStpJw7G_sendMessage);
}

void Heavy_CircleStrings::cBinop_YStpJw7G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_qW5NlNh8, HV_BINOP_DIVIDE, 0, m, &cBinop_qW5NlNh8_sendMessage);
}

void Heavy_CircleStrings::cBinop_qW5NlNh8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_s8tCfOmc_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cVar_eFucoNgD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cIf_LijsdTxW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 0.0f, 0, m, &cBinop_MD0PVbqa_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_cer3fsJv, 0, m, &cIf_cer3fsJv_sendMessage);
      break;
    }
    case 1: {
      cMsg_WqeoBndY_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_C1rCRU9a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_LijsdTxW, 1, m, &cIf_LijsdTxW_sendMessage);
}

void Heavy_CircleStrings::cIf_cer3fsJv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_F9wy7Vaa_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.2f, 0, m, &cBinop_IIh3YlnH_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_MD0PVbqa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_cer3fsJv, 1, m, &cIf_cer3fsJv_sendMessage);
}

void Heavy_CircleStrings::cMsg_WqeoBndY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.2f, 0, m, &cBinop_IIh3YlnH_sendMessage);
}

void Heavy_CircleStrings::cMsg_F9wy7Vaa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.2f, 0, m, &cBinop_IIh3YlnH_sendMessage);
}

void Heavy_CircleStrings::cIf_6QVDJmcx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 0.0f, 0, m, &cBinop_u0VWQdsr_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_hvgAfv1D, 0, m, &cIf_hvgAfv1D_sendMessage);
      break;
    }
    case 1: {
      cMsg_W91Z19O7_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_rxGyWZSb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_6QVDJmcx, 1, m, &cIf_6QVDJmcx_sendMessage);
}

void Heavy_CircleStrings::cIf_hvgAfv1D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_Hrr6drBf_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cPack_onMessage(_c, &Context(_c)->cPack_zjXlUEf5, 0, m, &cPack_zjXlUEf5_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_u0VWQdsr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_hvgAfv1D, 1, m, &cIf_hvgAfv1D_sendMessage);
}

void Heavy_CircleStrings::cMsg_W91Z19O7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_zjXlUEf5, 0, m, &cPack_zjXlUEf5_sendMessage);
}

void Heavy_CircleStrings::cMsg_Hrr6drBf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_zjXlUEf5, 0, m, &cPack_zjXlUEf5_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_fje2xgmB_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_6NxxO4IG, 0, m, &cSlice_6NxxO4IG_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_dYfAyvlQ, 0, m, &cRandom_dYfAyvlQ_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_dETbuUOH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_qsmwRnh7_sendMessage);
}

void Heavy_CircleStrings::cUnop_qsmwRnh7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_7wXHxaQA_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cRandom_dYfAyvlQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8388610.0f, 0, m, &cBinop_dETbuUOH_sendMessage);
}

void Heavy_CircleStrings::cSlice_6NxxO4IG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_dYfAyvlQ, 1, m, &cRandom_dYfAyvlQ_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cMsg_7wXHxaQA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 1.0f);
  sVari_onMessage(_c, &Context(_c)->sVari_eOByYFnj, m);
}

void Heavy_CircleStrings::cTabhead_rOuB54cf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_rtWMl1L2, HV_BINOP_SUBTRACT, 0, m, &cBinop_rtWMl1L2_sendMessage);
}

void Heavy_CircleStrings::cMsg_5tq3nCyg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Zmbdlqsv_sendMessage);
}

void Heavy_CircleStrings::cSystem_Zmbdlqsv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_iDVbMJbk_sendMessage);
}

void Heavy_CircleStrings::cVar_9GVghihj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_HBCvGT7n_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_AdVLVXqp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_AdVLVXqp, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_WaaEB9so, 0, m, &cDelay_WaaEB9so_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_oYmmQCpE, 0, m, &sTabread_oYmmQCpE_sendMessage);
}

void Heavy_CircleStrings::cDelay_WaaEB9so_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_WaaEB9so, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_oYmmQCpE, 0, m, &sTabread_oYmmQCpE_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_WaaEB9so, 0, m, &cDelay_WaaEB9so_sendMessage);
}

void Heavy_CircleStrings::sTabread_oYmmQCpE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_rfAEnC5U, HV_BINOP_SUBTRACT, 0, m, &cBinop_rfAEnC5U_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_Swaub8pe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Oq2rUOCU, HV_BINOP_MAX, 0, m, &cBinop_Oq2rUOCU_sendMessage);
}

void Heavy_CircleStrings::cBinop_iDVbMJbk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Swaub8pe, HV_BINOP_MULTIPLY, 0, m, &cBinop_Swaub8pe_sendMessage);
}

void Heavy_CircleStrings::cBinop_rtWMl1L2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_9oGAVvgM_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_oYmmQCpE, 0, m, &sTabread_oYmmQCpE_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_eNaYPLhf_sendMessage);
}

void Heavy_CircleStrings::cSystem_AAzBWU1V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_rfAEnC5U, HV_BINOP_SUBTRACT, 1, m, &cBinop_rfAEnC5U_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_WaaEB9so, 2, m, &cDelay_WaaEB9so_sendMessage);
}

void Heavy_CircleStrings::cMsg_HBCvGT7n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_AAzBWU1V_sendMessage);
}

void Heavy_CircleStrings::cMsg_9oGAVvgM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_AdVLVXqp, 0, m, &cDelay_AdVLVXqp_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_WaaEB9so, 0, m, &cDelay_WaaEB9so_sendMessage);
}

void Heavy_CircleStrings::cMsg_XFhSsGYw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_Oq2rUOCU, HV_BINOP_MAX, 1, m, &cBinop_Oq2rUOCU_sendMessage);
}

void Heavy_CircleStrings::cBinop_Oq2rUOCU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_rtWMl1L2, HV_BINOP_SUBTRACT, 1, m, &cBinop_rtWMl1L2_sendMessage);
}

void Heavy_CircleStrings::cCast_eNaYPLhf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_AdVLVXqp, 0, m, &cDelay_AdVLVXqp_sendMessage);
}

void Heavy_CircleStrings::cBinop_XUXEqS0O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_AdVLVXqp, 2, m, &cDelay_AdVLVXqp_sendMessage);
}

void Heavy_CircleStrings::cBinop_rfAEnC5U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_XUXEqS0O_sendMessage);
}

void Heavy_CircleStrings::cCast_uF0qf4S3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_9GVghihj, 0, m, &cVar_9GVghihj_sendMessage);
  cMsg_5tq3nCyg_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_rOuB54cf, 0, m, &cTabhead_rOuB54cf_sendMessage);
}

void Heavy_CircleStrings::cBinop_BUdWB32g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_u10F3kc6_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Urpx6hUH_sendMessage);
}

void Heavy_CircleStrings::cBinop_NbT5OIEP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_0DLH0vtc_sendMessage);
}

void Heavy_CircleStrings::cBinop_0DLH0vtc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_oF4eg9fl, HV_BINOP_POW, 1, m, &cBinop_oF4eg9fl_sendMessage);
  cMsg_4FLnqOpq_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_oF4eg9fl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_BUdWB32g_sendMessage);
}

void Heavy_CircleStrings::cMsg_4FLnqOpq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_oF4eg9fl, HV_BINOP_POW, 0, m, &cBinop_oF4eg9fl_sendMessage);
}

void Heavy_CircleStrings::cVar_DaYIr1Tx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_NbT5OIEP_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Z9cm28rT_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_8RamcyMF_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_d0UwtJit_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_hxrCptZO_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_hxrCptZO_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_cN1qg1Ez, 1, m, &cDelay_cN1qg1Ez_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_syqa0Mvz_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cDelay_cN1qg1Ez_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_cN1qg1Ez, m);
  cMsg_wyr7lR7X_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_hxrCptZO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_cN1qg1Ez, 0, m, &cDelay_cN1qg1Ez_sendMessage);
}

void Heavy_CircleStrings::cCast_syqa0Mvz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_cN1qg1Ez, 0, m, &cDelay_cN1qg1Ez_sendMessage);
}

void Heavy_CircleStrings::cVar_MsuxkGXm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_npUfZQFg, HV_BINOP_MULTIPLY, 0, m, &cBinop_npUfZQFg_sendMessage);
}

void Heavy_CircleStrings::cMsg_AMqc2L1c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_vS8MkvnN_sendMessage);
}

void Heavy_CircleStrings::cSystem_vS8MkvnN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_6c5E7K7Q_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_npUfZQFg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_lbH0XQ85_sendMessage);
}

void Heavy_CircleStrings::cBinop_vr4iuqoB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_npUfZQFg, HV_BINOP_MULTIPLY, 1, m, &cBinop_npUfZQFg_sendMessage);
}

void Heavy_CircleStrings::cMsg_6c5E7K7Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_vr4iuqoB_sendMessage);
}

void Heavy_CircleStrings::cBinop_lbH0XQ85_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_vMRCt19u_sendMessage);
}

void Heavy_CircleStrings::cBinop_vMRCt19u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_Sq585MVV_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_LIHn206i, m);
}

void Heavy_CircleStrings::cBinop_Sq585MVV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_uugT5Juj, m);
}

void Heavy_CircleStrings::cMsg_48tkRfeN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_FvFJXvB9_sendMessage);
}

void Heavy_CircleStrings::cSystem_FvFJXvB9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_8CHH4XZ3_sendMessage);
}

void Heavy_CircleStrings::cDelay_5hcWN5wq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_5hcWN5wq, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_GSaN18KR, 0, m, &cDelay_GSaN18KR_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_5hcWN5wq, 0, m, &cDelay_5hcWN5wq_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_gx6f2ZZ0, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_GSaN18KR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_GSaN18KR, m);
  cMsg_i6g3uihW_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_cDrLwPkf_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_4dNy8Th7_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_gqFU3Vmj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_W27PYnye_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_L6MOTeCE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_eJ1hWJ1X_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_5hcWN5wq, 2, m, &cDelay_5hcWN5wq_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_RyIh6nTb_sendMessage);
}

void Heavy_CircleStrings::cMsg_W27PYnye_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_L6MOTeCE, 0, m, &hTable_L6MOTeCE_sendMessage);
}

void Heavy_CircleStrings::cBinop_8CHH4XZ3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 200.0f, 0, m, &cBinop_gqFU3Vmj_sendMessage);
}

void Heavy_CircleStrings::cMsg_i6g3uihW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_L6MOTeCE, 0, m, &hTable_L6MOTeCE_sendMessage);
}

void Heavy_CircleStrings::cCast_RyIh6nTb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_5hcWN5wq, 0, m, &cDelay_5hcWN5wq_sendMessage);
}

void Heavy_CircleStrings::cMsg_eJ1hWJ1X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_GSaN18KR, 2, m, &cDelay_GSaN18KR_sendMessage);
}

void Heavy_CircleStrings::cMsg_4dNy8Th7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_gx6f2ZZ0, 1, m, NULL);
}

void Heavy_CircleStrings::cMsg_KwmVF935_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 1.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_Dra3dAfS, 0, m, NULL);
}

void Heavy_CircleStrings::cMsg_wyr7lR7X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 1.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_Dra3dAfS, 0, m, NULL);
}

void Heavy_CircleStrings::cCast_8RamcyMF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_KwmVF935_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_Z9cm28rT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_d0UwtJit_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cMsg_1AMjifKP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 60.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_NbT5OIEP_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Z9cm28rT_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_8RamcyMF_sendMessage);
}

void Heavy_CircleStrings::cBinop_1viVckc7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Swaub8pe, HV_BINOP_MULTIPLY, 1, m, &cBinop_Swaub8pe_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_uF0qf4S3_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_cN1qg1Ez, 1, m, &cDelay_cN1qg1Ez_sendMessage);
}

void Heavy_CircleStrings::cMsg_mpdLNqgo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1000.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_1viVckc7, HV_BINOP_DIVIDE, 0, m, &cBinop_1viVckc7_sendMessage);
}

void Heavy_CircleStrings::cCast_Urpx6hUH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_mpdLNqgo_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_u10F3kc6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_1viVckc7, HV_BINOP_DIVIDE, 1, m, &cBinop_1viVckc7_sendMessage);
}

void Heavy_CircleStrings::cVar_YiuOaEHl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_q04INMZg_sendMessage);
  cSwitchcase_Kp9ScDca_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cBinop_q04INMZg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_YiuOaEHl, 1, m, &cVar_YiuOaEHl_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_Kp9ScDca_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cMsg_u2hrEgkV_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_u2hrEgkV_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_AzxUVOXE_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cDelay_ZX6yMN56_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_ZX6yMN56, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ZX6yMN56, 0, m, &cDelay_ZX6yMN56_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_8zNrYrmx, 0, m, &cVar_8zNrYrmx_sendMessage);
  cSwitchcase_WDvPAF2s_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cCast_AzxUVOXE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_u2hrEgkV_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ZX6yMN56, 0, m, &cDelay_ZX6yMN56_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_8zNrYrmx, 0, m, &cVar_8zNrYrmx_sendMessage);
  cSwitchcase_WDvPAF2s_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cMsg_C0HhVjWw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_aH70gidM_sendMessage);
}

void Heavy_CircleStrings::cSystem_aH70gidM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_gSKD7bTl_sendMessage);
}

void Heavy_CircleStrings::cVar_LBrR9mOt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_5ZP62Jaq, HV_BINOP_MULTIPLY, 0, m, &cBinop_5ZP62Jaq_sendMessage);
}

void Heavy_CircleStrings::cMsg_u2hrEgkV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_ZX6yMN56, 0, m, &cDelay_ZX6yMN56_sendMessage);
}

void Heavy_CircleStrings::cBinop_uEgnWfVm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_ZX6yMN56, 2, m, &cDelay_ZX6yMN56_sendMessage);
}

void Heavy_CircleStrings::cBinop_gSKD7bTl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_5ZP62Jaq, HV_BINOP_MULTIPLY, 1, m, &cBinop_5ZP62Jaq_sendMessage);
}

void Heavy_CircleStrings::cBinop_5ZP62Jaq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_uEgnWfVm_sendMessage);
}

void Heavy_CircleStrings::cVar_8zNrYrmx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_NbT5OIEP_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Z9cm28rT_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_8RamcyMF_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_WDvPAF2s_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_41FqvrHV, 0, m, &cSlice_41FqvrHV_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_pgD5ODH4, 0, m, &cRandom_pgD5ODH4_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_86KT3WKp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_RDJj4351_sendMessage);
}

void Heavy_CircleStrings::cUnop_RDJj4351_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 40.0f, 0, m, &cBinop_uKoJAIxW_sendMessage);
}

void Heavy_CircleStrings::cRandom_pgD5ODH4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 25.0f, 0, m, &cBinop_86KT3WKp_sendMessage);
}

void Heavy_CircleStrings::cSlice_41FqvrHV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_pgD5ODH4, 1, m, &cRandom_pgD5ODH4_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cVar_xFwOQwqQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cIf_aKFKiW3J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, -1.0f, 0, m, &cBinop_p4oeLNqb_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_I02B0pKu, 0, m, &cIf_I02B0pKu_sendMessage);
      break;
    }
    case 1: {
      cMsg_MDLP41Aa_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_6NqkvLpn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_aKFKiW3J, 1, m, &cIf_aKFKiW3J_sendMessage);
}

void Heavy_CircleStrings::cIf_I02B0pKu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_Bc1mwrAV_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.049f, 0, m, &cBinop_14NvlO3Q_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_p4oeLNqb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_I02B0pKu, 1, m, &cIf_I02B0pKu_sendMessage);
}

void Heavy_CircleStrings::cMsg_MDLP41Aa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.049f, 0, m, &cBinop_14NvlO3Q_sendMessage);
}

void Heavy_CircleStrings::cMsg_Bc1mwrAV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, -1.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.049f, 0, m, &cBinop_14NvlO3Q_sendMessage);
}

void Heavy_CircleStrings::cIf_748loJLv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 0.0f, 0, m, &cBinop_udqzu853_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_68YIpKEu, 0, m, &cIf_68YIpKEu_sendMessage);
      break;
    }
    case 1: {
      cMsg_Imt47kBP_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_4dlTqBLB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_748loJLv, 1, m, &cIf_748loJLv_sendMessage);
}

void Heavy_CircleStrings::cIf_68YIpKEu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_ir630G3w_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 4600.0f, 0, m, &cBinop_TH5v6GT4_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_udqzu853_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_68YIpKEu, 1, m, &cIf_68YIpKEu_sendMessage);
}

void Heavy_CircleStrings::cMsg_Imt47kBP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 4600.0f, 0, m, &cBinop_TH5v6GT4_sendMessage);
}

void Heavy_CircleStrings::cMsg_ir630G3w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 4600.0f, 0, m, &cBinop_TH5v6GT4_sendMessage);
}

void Heavy_CircleStrings::cPack_tVAZy8DP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_E7rN8JNU, 0, m, NULL);
}

void Heavy_CircleStrings::cPack_zjXlUEf5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_wVRBvxvx, 0, m, NULL);
}

void Heavy_CircleStrings::cBinop_bNkY8eq0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_eFucoNgD, 0, m, &cVar_eFucoNgD_sendMessage);
}

void Heavy_CircleStrings::cBinop_IIh3YlnH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5f, 0, m, &cBinop_9qidfpEs_sendMessage);
}

void Heavy_CircleStrings::cBinop_9qidfpEs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_rxGyWZSb_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_6QVDJmcx, 0, m, &cIf_6QVDJmcx_sendMessage);
}

void Heavy_CircleStrings::cBinop_uKoJAIxW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_LBrR9mOt, 0, m, &cVar_LBrR9mOt_sendMessage);
}

void Heavy_CircleStrings::cBinop_xCbuuPj1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_oUvkWwHu, m);
}

void Heavy_CircleStrings::cBinop_14NvlO3Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.95f, 0, m, &cBinop_xCbuuPj1_sendMessage);
}

void Heavy_CircleStrings::cBinop_Hm1f1rmi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_MsuxkGXm, 0, m, &cVar_MsuxkGXm_sendMessage);
}

void Heavy_CircleStrings::cBinop_TH5v6GT4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2200.0f, 0, m, &cBinop_Hm1f1rmi_sendMessage);
}

void Heavy_CircleStrings::cCast_M0pkJX55_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_od8Cl7cZ_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_LrTjEUue_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cVar_PrfIVMut_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_8sXq6GVY_sendMessage(_c, 0, m);
  cSend_4lgBuz4l_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_od8Cl7cZ_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_5oWon6Ly, 0, m, &cSlice_5oWon6Ly_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_S84jBn66, 0, m, &cRandom_S84jBn66_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_oCC7yEq9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_McwFRN9f_sendMessage);
}

void Heavy_CircleStrings::cUnop_McwFRN9f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1.28f, 0, m, &cBinop_WbAey53B_sendMessage);
  cSend_tUIWLhgr_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cRandom_S84jBn66_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 128.0f, 0, m, &cBinop_oCC7yEq9_sendMessage);
}

void Heavy_CircleStrings::cSlice_5oWon6Ly_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_S84jBn66, 1, m, &cRandom_S84jBn66_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cVar_rpW8SQPS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_GdBavOmr_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cVar_l4GTod4w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_uVG2mXzk_sendMessage);
}

void Heavy_CircleStrings::cBinop_uVG2mXzk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_l4GTod4w, 1, m, &cVar_l4GTod4w_sendMessage);
}

void Heavy_CircleStrings::cCast_X0c63xDR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cVar_Z7QV9U8f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cVar_Mt5EA5wd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cCast_GxfGfjZ6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_76Dcs4hl_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_LrTjEUue_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_s0ZNc6zC, 0, m, &cSlice_s0ZNc6zC_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_FmpcyDM2, 0, m, &cRandom_FmpcyDM2_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_B3Z7A1Vw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_aiKk2htM_sendMessage);
}

void Heavy_CircleStrings::cUnop_aiKk2htM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 20.0f, 0, m, &cBinop_ody6Kj61_sendMessage);
}

void Heavy_CircleStrings::cRandom_FmpcyDM2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 100.0f, 0, m, &cBinop_B3Z7A1Vw_sendMessage);
}

void Heavy_CircleStrings::cSlice_s0ZNc6zC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_FmpcyDM2, 1, m, &cRandom_FmpcyDM2_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cCast_pLc0tJz2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_n1sDM1Kb_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ucrDUTrZ_sendMessage);
}

void Heavy_CircleStrings::cBinop_WbAey53B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_rpW8SQPS, 0, m, &cVar_rpW8SQPS_sendMessage);
}

void Heavy_CircleStrings::cSend_GdBavOmr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_RpWWRCwt_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_8sXq6GVY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_46kiA3qm_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_tUIWLhgr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_SHnLV9E2_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_4lgBuz4l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_b3mkhP8y_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_Qu1dTsBw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.8f);
  cSend_xAjKXpEJ_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_xAjKXpEJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_61PVQMSs_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_j6a49YkX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSend_xAjKXpEJ_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_76Dcs4hl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_DXbynMog_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_ody6Kj61_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_PrfIVMut, 0, m, &cVar_PrfIVMut_sendMessage);
}

void Heavy_CircleStrings::cCast_n1sDM1Kb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_SclvyEGc_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_ucrDUTrZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_q3XUwGk5_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_q3XUwGk5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 64.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_PrfIVMut, 0, m, &cVar_PrfIVMut_sendMessage);
}

void Heavy_CircleStrings::cMsg_SclvyEGc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 127.0f);
  cSend_tUIWLhgr_sendMessage(_c, 0, m);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1.28f, 0, m, &cBinop_WbAey53B_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_3Z9z43vB_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_lixM8v2T, 0, m, &cSlice_lixM8v2T_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_qvXfcIYV, 0, m, &cRandom_qvXfcIYV_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_cDotsPzy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_n5mbAzPk_sendMessage);
}

void Heavy_CircleStrings::cUnop_n5mbAzPk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 50.0f, 0, m, &cBinop_vGtEnYxj_sendMessage);
}

void Heavy_CircleStrings::cRandom_qvXfcIYV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 200.0f, 0, m, &cBinop_cDotsPzy_sendMessage);
}

void Heavy_CircleStrings::cSlice_lixM8v2T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_qvXfcIYV, 1, m, &cRandom_qvXfcIYV_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cSwitchcase_zh6e8Ngy_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_38rCsSyN, 0, m, &cSlice_38rCsSyN_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_X8chaVAR, 0, m, &cRandom_X8chaVAR_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_HWgOswqw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_WWpHY1lI_sendMessage);
}

void Heavy_CircleStrings::cUnop_WWpHY1lI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_h3JmPiRe_sendMessage);
}

void Heavy_CircleStrings::cRandom_X8chaVAR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_HWgOswqw_sendMessage);
}

void Heavy_CircleStrings::cSlice_38rCsSyN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_X8chaVAR, 1, m, &cRandom_X8chaVAR_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_VF4sbUGi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ZZeE3tg9, HV_BINOP_MULTIPLY, 0, m, &cBinop_ZZeE3tg9_sendMessage);
}

void Heavy_CircleStrings::cBinop_qOo6NO9V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_41hXkwuT_sendMessage);
}

void Heavy_CircleStrings::cBinop_41hXkwuT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_EJkBcX8R, HV_BINOP_POW, 1, m, &cBinop_EJkBcX8R_sendMessage);
  cMsg_YG3xHfvI_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_EJkBcX8R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_VF4sbUGi_sendMessage);
}

void Heavy_CircleStrings::cMsg_YG3xHfvI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_EJkBcX8R, HV_BINOP_POW, 0, m, &cBinop_EJkBcX8R_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_sFc71zlt_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_VqK2VIG8, 0, m, &cSlice_VqK2VIG8_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_GQLz0iDs, 0, m, &cRandom_GQLz0iDs_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_loxFFdFQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_WH3ghkJl_sendMessage);
}

void Heavy_CircleStrings::cUnop_WH3ghkJl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_EhEPUSrP_sendMessage);
}

void Heavy_CircleStrings::cRandom_GQLz0iDs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 15.0f, 0, m, &cBinop_loxFFdFQ_sendMessage);
}

void Heavy_CircleStrings::cSlice_VqK2VIG8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_GQLz0iDs, 1, m, &cRandom_GQLz0iDs_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cPack_96rLYEgW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_OKfHXmaS, 0, m, NULL);
}

void Heavy_CircleStrings::cVar_K6f46STl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_RmJPvmOj_sendMessage);
}

void Heavy_CircleStrings::cVar_r7CZbbdC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_U4Qsnyii, 0, m);
}

void Heavy_CircleStrings::cVar_DrrnP6n6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_zWjMtM8n_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_LzhenEEl_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_2IVMeHxj_sendMessage);
}

void Heavy_CircleStrings::cVar_9uqHUoqy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cVar_41KPvXEI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cVar_kPdyvOZq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cSwitchcase_grwlhI6B_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_7M4uVAC0_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_7M4uVAC0_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_QmNnfow6, 1, m, &cDelay_QmNnfow6_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_AMxkeEwC_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cDelay_QmNnfow6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_QmNnfow6, m);
  cVar_onMessage(_c, &Context(_c)->cVar_vnv23JiP, 0, m, &cVar_vnv23JiP_sendMessage);
}

void Heavy_CircleStrings::cMsg_7M4uVAC0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_QmNnfow6, 0, m, &cDelay_QmNnfow6_sendMessage);
}

void Heavy_CircleStrings::cCast_AMxkeEwC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_QmNnfow6, 0, m, &cDelay_QmNnfow6_sendMessage);
}

void Heavy_CircleStrings::cVar_vnv23JiP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_5e8HFqD0_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_17QpVgKh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_DrrnP6n6, 0, m, &cVar_DrrnP6n6_sendMessage);
}

void Heavy_CircleStrings::cMsg_z82OXGb5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 25.0f);
  cSend_Zzfl26Cz_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_NyQnRE8B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 4000.0f);
  cSend_sXVv6F1J_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_3tkz51Zx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSend_tn3a5tZm_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_3c8HK6GC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_Q8TGUP0C_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_Us4MSLxG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cSend_K8PfbEk2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_RVXwoU7w_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_Zzfl26Cz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cSend_sXVv6F1J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_Q8TGUP0C_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_tn3a5tZm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_RVXwoU7w_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_MF6PrQG9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 25.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_LWWCwcju, 0, m, NULL);
}

void Heavy_CircleStrings::cMsg_5e8HFqD0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 0);
  sLine_onMessage(_c, &Context(_c)->sLine_LWWCwcju, 0, m, NULL);
}

void Heavy_CircleStrings::cCast_2IVMeHxj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_grwlhI6B_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cCast_LzhenEEl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_vnv23JiP, 1, m, &cVar_vnv23JiP_sendMessage);
}

void Heavy_CircleStrings::cCast_zWjMtM8n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_MF6PrQG9_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_OHlzQIyh_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_lm58TzkW, 0, m, &cSlice_lm58TzkW_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_lKPIHZ1I, 0, m, &cRandom_lKPIHZ1I_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_UCRqAp21_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_OrD2dirn_sendMessage);
}

void Heavy_CircleStrings::cUnop_OrD2dirn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_MoPVkQP6_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cRandom_lKPIHZ1I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8388610.0f, 0, m, &cBinop_UCRqAp21_sendMessage);
}

void Heavy_CircleStrings::cSlice_lm58TzkW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_lKPIHZ1I, 1, m, &cRandom_lKPIHZ1I_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cMsg_MoPVkQP6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 1.0f);
  sVari_onMessage(_c, &Context(_c)->sVari_nS0e1uCy, m);
}

void Heavy_CircleStrings::cTabhead_hTm3mJ9u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_OxIMMNbF, HV_BINOP_SUBTRACT, 0, m, &cBinop_OxIMMNbF_sendMessage);
}

void Heavy_CircleStrings::cMsg_SUAqrnb9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_jSTTL1TT_sendMessage);
}

void Heavy_CircleStrings::cSystem_jSTTL1TT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_kDxPPwuz_sendMessage);
}

void Heavy_CircleStrings::cVar_3CKWKr6R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_VnPLOIst_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_P35YTh9Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_P35YTh9Z, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_fjojXfn5, 0, m, &cDelay_fjojXfn5_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_Zg8sDcKY, 0, m, &sTabread_Zg8sDcKY_sendMessage);
}

void Heavy_CircleStrings::cDelay_fjojXfn5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_fjojXfn5, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_Zg8sDcKY, 0, m, &sTabread_Zg8sDcKY_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_fjojXfn5, 0, m, &cDelay_fjojXfn5_sendMessage);
}

void Heavy_CircleStrings::sTabread_Zg8sDcKY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_RKT37uAo, HV_BINOP_SUBTRACT, 0, m, &cBinop_RKT37uAo_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_NFkFZOa7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_xYwHFiX3, HV_BINOP_MAX, 0, m, &cBinop_xYwHFiX3_sendMessage);
}

void Heavy_CircleStrings::cBinop_kDxPPwuz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_NFkFZOa7, HV_BINOP_MULTIPLY, 0, m, &cBinop_NFkFZOa7_sendMessage);
}

void Heavy_CircleStrings::cBinop_OxIMMNbF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_DYCUhMCB_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_Zg8sDcKY, 0, m, &sTabread_Zg8sDcKY_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_hlVeKSPE_sendMessage);
}

void Heavy_CircleStrings::cSystem_e9WeYPNp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_RKT37uAo, HV_BINOP_SUBTRACT, 1, m, &cBinop_RKT37uAo_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_fjojXfn5, 2, m, &cDelay_fjojXfn5_sendMessage);
}

void Heavy_CircleStrings::cMsg_VnPLOIst_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_e9WeYPNp_sendMessage);
}

void Heavy_CircleStrings::cMsg_DYCUhMCB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_P35YTh9Z, 0, m, &cDelay_P35YTh9Z_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_fjojXfn5, 0, m, &cDelay_fjojXfn5_sendMessage);
}

void Heavy_CircleStrings::cMsg_YByQXBzt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_xYwHFiX3, HV_BINOP_MAX, 1, m, &cBinop_xYwHFiX3_sendMessage);
}

void Heavy_CircleStrings::cBinop_xYwHFiX3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_OxIMMNbF, HV_BINOP_SUBTRACT, 1, m, &cBinop_OxIMMNbF_sendMessage);
}

void Heavy_CircleStrings::cCast_hlVeKSPE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_P35YTh9Z, 0, m, &cDelay_P35YTh9Z_sendMessage);
}

void Heavy_CircleStrings::cBinop_sGaj4z0z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_P35YTh9Z, 2, m, &cDelay_P35YTh9Z_sendMessage);
}

void Heavy_CircleStrings::cBinop_RKT37uAo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_sGaj4z0z_sendMessage);
}

void Heavy_CircleStrings::cCast_ypIT2AhI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_3CKWKr6R, 0, m, &cVar_3CKWKr6R_sendMessage);
  cMsg_SUAqrnb9_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_hTm3mJ9u, 0, m, &cTabhead_hTm3mJ9u_sendMessage);
}

void Heavy_CircleStrings::cBinop_4HwsqaMq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_TmWrEOfU_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_wL6PDDrI_sendMessage);
}

void Heavy_CircleStrings::cBinop_ceptTBje_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_lA7wv7nZ_sendMessage);
}

void Heavy_CircleStrings::cBinop_lA7wv7nZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_T9U7zVBe, HV_BINOP_POW, 1, m, &cBinop_T9U7zVBe_sendMessage);
  cMsg_jsj8RkXv_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_T9U7zVBe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_4HwsqaMq_sendMessage);
}

void Heavy_CircleStrings::cMsg_jsj8RkXv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_T9U7zVBe, HV_BINOP_POW, 0, m, &cBinop_T9U7zVBe_sendMessage);
}

void Heavy_CircleStrings::cVar_XzF5DlWi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_ceptTBje_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_CHzv0Rki_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_n3pXgz9W_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_ALyY10Lk_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_IfJh4Iiy_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_IfJh4Iiy_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_0L7n5bYW, 1, m, &cDelay_0L7n5bYW_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_73wQ8oPj_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cDelay_0L7n5bYW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_0L7n5bYW, m);
  cMsg_LPKcXiHI_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_IfJh4Iiy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_0L7n5bYW, 0, m, &cDelay_0L7n5bYW_sendMessage);
}

void Heavy_CircleStrings::cCast_73wQ8oPj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_0L7n5bYW, 0, m, &cDelay_0L7n5bYW_sendMessage);
}

void Heavy_CircleStrings::cVar_n7fikkrY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_FCcJcPSY, HV_BINOP_MULTIPLY, 0, m, &cBinop_FCcJcPSY_sendMessage);
}

void Heavy_CircleStrings::cMsg_Wn9GvRuS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Ch6ZrM6T_sendMessage);
}

void Heavy_CircleStrings::cSystem_Ch6ZrM6T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_AhtX970M_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_FCcJcPSY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_nAMHrssq_sendMessage);
}

void Heavy_CircleStrings::cBinop_pU6nm0Ly_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_FCcJcPSY, HV_BINOP_MULTIPLY, 1, m, &cBinop_FCcJcPSY_sendMessage);
}

void Heavy_CircleStrings::cMsg_AhtX970M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_pU6nm0Ly_sendMessage);
}

void Heavy_CircleStrings::cBinop_nAMHrssq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_VqeNYRNd_sendMessage);
}

void Heavy_CircleStrings::cBinop_VqeNYRNd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_nQ8I82qN_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_viUoN3mQ, m);
}

void Heavy_CircleStrings::cBinop_nQ8I82qN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_XDfieX4W, m);
}

void Heavy_CircleStrings::cMsg_POtkarPb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_9FI2YGCb_sendMessage);
}

void Heavy_CircleStrings::cSystem_9FI2YGCb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_4yJLM4gv_sendMessage);
}

void Heavy_CircleStrings::cDelay_C2MmuP9k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_C2MmuP9k, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_cN2ukW3L, 0, m, &cDelay_cN2ukW3L_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_C2MmuP9k, 0, m, &cDelay_C2MmuP9k_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_6JpljZfs, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_cN2ukW3L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_cN2ukW3L, m);
  cMsg_Uje4PXip_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_bwGw7BA3_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_4yfUAntm_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_Bpbw4fqY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_KCOm63Zf_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_f2MY0Eli_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_0Nq7xiN3_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_C2MmuP9k, 2, m, &cDelay_C2MmuP9k_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_HhTrF5vC_sendMessage);
}

void Heavy_CircleStrings::cMsg_KCOm63Zf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_f2MY0Eli, 0, m, &hTable_f2MY0Eli_sendMessage);
}

void Heavy_CircleStrings::cBinop_4yJLM4gv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 200.0f, 0, m, &cBinop_Bpbw4fqY_sendMessage);
}

void Heavy_CircleStrings::cMsg_Uje4PXip_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_f2MY0Eli, 0, m, &hTable_f2MY0Eli_sendMessage);
}

void Heavy_CircleStrings::cCast_HhTrF5vC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_C2MmuP9k, 0, m, &cDelay_C2MmuP9k_sendMessage);
}

void Heavy_CircleStrings::cMsg_0Nq7xiN3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_cN2ukW3L, 2, m, &cDelay_cN2ukW3L_sendMessage);
}

void Heavy_CircleStrings::cMsg_4yfUAntm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_6JpljZfs, 1, m, NULL);
}

void Heavy_CircleStrings::cMsg_xju6jsoE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 1.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_Hbf64OgS, 0, m, NULL);
}

void Heavy_CircleStrings::cMsg_LPKcXiHI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 1.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_Hbf64OgS, 0, m, NULL);
}

void Heavy_CircleStrings::cCast_CHzv0Rki_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_ALyY10Lk_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cCast_n3pXgz9W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_xju6jsoE_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_Ni08eFs3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 60.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_ceptTBje_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_CHzv0Rki_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_n3pXgz9W_sendMessage);
}

void Heavy_CircleStrings::cBinop_6pTizkQW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_NFkFZOa7, HV_BINOP_MULTIPLY, 1, m, &cBinop_NFkFZOa7_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ypIT2AhI_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_0L7n5bYW, 1, m, &cDelay_0L7n5bYW_sendMessage);
}

void Heavy_CircleStrings::cMsg_YVawdHgo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1000.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_6pTizkQW, HV_BINOP_DIVIDE, 0, m, &cBinop_6pTizkQW_sendMessage);
}

void Heavy_CircleStrings::cCast_wL6PDDrI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_YVawdHgo_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_TmWrEOfU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6pTizkQW, HV_BINOP_DIVIDE, 1, m, &cBinop_6pTizkQW_sendMessage);
}

void Heavy_CircleStrings::cUnop_lbm82JUZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_ICFm3Jex, 0, m, &cPack_ICFm3Jex_sendMessage);
}

void Heavy_CircleStrings::cUnop_zY4Ew86t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_JYwEgJUw, 0, m, &cPack_JYwEgJUw_sendMessage);
}

void Heavy_CircleStrings::cPack_JYwEgJUw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_BCylCxST, 0, m, NULL);
}

void Heavy_CircleStrings::cPack_ICFm3Jex_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_E22viBkU, 0, m, NULL);
}

void Heavy_CircleStrings::cBinop_phesXkFw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_lbm82JUZ_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_SIN, m, &cUnop_zY4Ew86t_sendMessage);
}

void Heavy_CircleStrings::cMsg_dtiZeF1n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.5f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_phesXkFw_sendMessage);
}

void Heavy_CircleStrings::cSlice_cxB7DDzC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 127.0f, 0, m, &cBinop_wl86KGjz_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cSlice_Dp1N1jdC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_WCxmntWP_sendMessage);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_qOo6NO9V_sendMessage);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_ceptTBje_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_CHzv0Rki_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_n3pXgz9W_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_h3JmPiRe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.4f, 0, m, &cBinop_TTSGyH8P_sendMessage);
}

void Heavy_CircleStrings::cBinop_TTSGyH8P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_phesXkFw_sendMessage);
}

void Heavy_CircleStrings::cBinop_wl86KGjz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_LAwbQhmQ_sendMessage(_c, 0, m);
  cSend_fL6CNksQ_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_ZZeE3tg9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_DnTKF5M5_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_CdZtDWYq_sendMessage);
}

void Heavy_CircleStrings::cBinop_EhEPUSrP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.99f, 0, m, &cBinop_e5gqxoAs_sendMessage);
}

void Heavy_CircleStrings::cBinop_e5gqxoAs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ZZeE3tg9, HV_BINOP_MULTIPLY, 1, m, &cBinop_ZZeE3tg9_sendMessage);
}

void Heavy_CircleStrings::cSend_LAwbQhmQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_vtoDkdrb_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_DnTKF5M5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_zh6e8Ngy_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cCast_CdZtDWYq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_17QpVgKh_sendMessage);
}

void Heavy_CircleStrings::cBinop_RmJPvmOj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_96rLYEgW, 0, m, &cPack_96rLYEgW_sendMessage);
}

void Heavy_CircleStrings::cSend_fL6CNksQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_7ihRb34k_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_SfoxGO90_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_K0aMEN3J_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_Xf42bRzl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 200.0f);
  cSend_SfoxGO90_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_h8OXHvA3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.999f);
  sVarf_onMessage(_c, &Context(_c)->sVarf_ntdg74Xc, m);
}

void Heavy_CircleStrings::cCast_WCxmntWP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_sFc71zlt_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cVar_uqsLIPqF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_IKWFVfkw_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Iz8lpQLg_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_flgHG1DO_sendMessage);
}

void Heavy_CircleStrings::cIf_ihNkOZdb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_rlU9kOuo_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_iVVaFy3M_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cMsg_wLlv2aPs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_IKqRPfgz, HV_BINOP_POW, 0, m, &cBinop_IKqRPfgz_sendMessage);
}

void Heavy_CircleStrings::cBinop_IKqRPfgz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_2gPdsgkN, 0, m, &cPack_2gPdsgkN_sendMessage);
}

void Heavy_CircleStrings::cBinop_5P07zM0J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_cv05A4wx_sendMessage);
}

void Heavy_CircleStrings::cCast_Iz8lpQLg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_QD98X4hw_sendMessage);
}

void Heavy_CircleStrings::cCast_flgHG1DO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_ihNkOZdb, 0, m, &cIf_ihNkOZdb_sendMessage);
}

void Heavy_CircleStrings::cBinop_QD98X4hw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_ihNkOZdb, 1, m, &cIf_ihNkOZdb_sendMessage);
}

void Heavy_CircleStrings::cBinop_iVVaFy3M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_5P07zM0J_sendMessage);
}

void Heavy_CircleStrings::cMsg_rlU9kOuo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_2gPdsgkN, 0, m, &cPack_2gPdsgkN_sendMessage);
}

void Heavy_CircleStrings::cBinop_cv05A4wx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_IKqRPfgz, HV_BINOP_POW, 1, m, &cBinop_IKqRPfgz_sendMessage);
  cMsg_wLlv2aPs_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cPack_2gPdsgkN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_1PW1Q8Bq, 0, m, NULL);
}

void Heavy_CircleStrings::cVar_9UniTBM9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_jSxw971J_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_IKWFVfkw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSend_lDJZNOd0_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_lDJZNOd0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_OkaclTJY_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_jSxw971J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_viock29s_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cVar_hpHZHG8w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_4zuFpV8j_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_X7JRvs8f_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_r4Q2ar95_sendMessage);
}

void Heavy_CircleStrings::cIf_qMtGKiX6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_Q9UkPbAf_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_Ju3SNfti_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cMsg_PWyl09aD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_PrWE99Rd, HV_BINOP_POW, 0, m, &cBinop_PrWE99Rd_sendMessage);
}

void Heavy_CircleStrings::cBinop_PrWE99Rd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_2zVazh8B, 0, m, &cPack_2zVazh8B_sendMessage);
}

void Heavy_CircleStrings::cBinop_t2Y19NEN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_4WMyj9XO_sendMessage);
}

void Heavy_CircleStrings::cCast_X7JRvs8f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_03ZYohtF_sendMessage);
}

void Heavy_CircleStrings::cCast_r4Q2ar95_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_qMtGKiX6, 0, m, &cIf_qMtGKiX6_sendMessage);
}

void Heavy_CircleStrings::cBinop_03ZYohtF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_qMtGKiX6, 1, m, &cIf_qMtGKiX6_sendMessage);
}

void Heavy_CircleStrings::cBinop_Ju3SNfti_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_t2Y19NEN_sendMessage);
}

void Heavy_CircleStrings::cMsg_Q9UkPbAf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_2zVazh8B, 0, m, &cPack_2zVazh8B_sendMessage);
}

void Heavy_CircleStrings::cBinop_4WMyj9XO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_PrWE99Rd, HV_BINOP_POW, 1, m, &cBinop_PrWE99Rd_sendMessage);
  cMsg_PWyl09aD_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cPack_2zVazh8B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_tV4FpGzc, 0, m, NULL);
}

void Heavy_CircleStrings::cVar_OQeJwARA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_2jomjq7S_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_4zuFpV8j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSend_NOCJVmr2_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_NOCJVmr2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_xWa6HxGE_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_2jomjq7S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_EX63h6Sm_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_YcF2qB0Y_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_FH0UNgTD, 0, m, &cSlice_FH0UNgTD_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_8Rp5DjS2, 0, m, &cRandom_8Rp5DjS2_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_nqTH0JxO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_NC9D58z1_sendMessage);
}

void Heavy_CircleStrings::cUnop_NC9D58z1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_1XQUFboy_sendMessage);
}

void Heavy_CircleStrings::cRandom_8Rp5DjS2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_nqTH0JxO_sendMessage);
}

void Heavy_CircleStrings::cSlice_FH0UNgTD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_8Rp5DjS2, 1, m, &cRandom_8Rp5DjS2_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_ID8jk252_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_sB5EJ13L, HV_BINOP_MULTIPLY, 0, m, &cBinop_sB5EJ13L_sendMessage);
}

void Heavy_CircleStrings::cBinop_hxqJk4js_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_xSNAVqnw_sendMessage);
}

void Heavy_CircleStrings::cBinop_xSNAVqnw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_3BPvUi81, HV_BINOP_POW, 1, m, &cBinop_3BPvUi81_sendMessage);
  cMsg_agUa3AHV_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_3BPvUi81_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_ID8jk252_sendMessage);
}

void Heavy_CircleStrings::cMsg_agUa3AHV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_3BPvUi81, HV_BINOP_POW, 0, m, &cBinop_3BPvUi81_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_fK9ALo6Q_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_REzBtACR, 0, m, &cSlice_REzBtACR_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_RTVI7H0A, 0, m, &cRandom_RTVI7H0A_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_omsg5SSg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_qE5ZkyQ8_sendMessage);
}

void Heavy_CircleStrings::cUnop_qE5ZkyQ8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_YcLTFVkP_sendMessage);
}

void Heavy_CircleStrings::cRandom_RTVI7H0A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 15.0f, 0, m, &cBinop_omsg5SSg_sendMessage);
}

void Heavy_CircleStrings::cSlice_REzBtACR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_RTVI7H0A, 1, m, &cRandom_RTVI7H0A_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cPack_B3Kat4VK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_A9nxHXLL, 0, m, NULL);
}

void Heavy_CircleStrings::cVar_GckwBvYW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_aLC6LHHs_sendMessage);
}

void Heavy_CircleStrings::cVar_DUACWizl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_TnAQtKCp, 0, m);
}

void Heavy_CircleStrings::cVar_qFc7csLF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ckabkoAF_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_nm18z5hc_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_tIz2sssZ_sendMessage);
}

void Heavy_CircleStrings::cVar_P4ruzqrw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cVar_X7cuYeYA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cVar_zrlvFyeW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cSwitchcase_n6yE75ZV_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_3D5pYBkh_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_3D5pYBkh_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_mDQ6DWtY, 1, m, &cDelay_mDQ6DWtY_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_o2IvLznj_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cDelay_mDQ6DWtY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_mDQ6DWtY, m);
  cVar_onMessage(_c, &Context(_c)->cVar_hfe51u7G, 0, m, &cVar_hfe51u7G_sendMessage);
}

void Heavy_CircleStrings::cMsg_3D5pYBkh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_mDQ6DWtY, 0, m, &cDelay_mDQ6DWtY_sendMessage);
}

void Heavy_CircleStrings::cCast_o2IvLznj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_mDQ6DWtY, 0, m, &cDelay_mDQ6DWtY_sendMessage);
}

void Heavy_CircleStrings::cVar_hfe51u7G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_KX4NqNXA_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_6BTHBSCn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_qFc7csLF, 0, m, &cVar_qFc7csLF_sendMessage);
}

void Heavy_CircleStrings::cMsg_rZ0gWIuy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 25.0f);
  cSend_poDLXa4L_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_VcRDWbuy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 4000.0f);
  cSend_2BIBwh9y_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_gIwHmAQp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSend_O975roPE_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_lc9m05wa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_2Dyirtxb_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_wShhJwAm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cSend_U2PnmPiO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_Jri6FEKs_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_poDLXa4L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cSend_2BIBwh9y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_2Dyirtxb_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_O975roPE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_Jri6FEKs_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_4JXPMud2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 25.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_ZATZCSqw, 0, m, NULL);
}

void Heavy_CircleStrings::cMsg_KX4NqNXA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 0);
  sLine_onMessage(_c, &Context(_c)->sLine_ZATZCSqw, 0, m, NULL);
}

void Heavy_CircleStrings::cCast_ckabkoAF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_4JXPMud2_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_tIz2sssZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_n6yE75ZV_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cCast_nm18z5hc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_hfe51u7G, 1, m, &cVar_hfe51u7G_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_dJHDR6vO_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_LOFarNr5, 0, m, &cSlice_LOFarNr5_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_0ZwZ0twV, 0, m, &cRandom_0ZwZ0twV_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_nWKaZYTP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_5wng632f_sendMessage);
}

void Heavy_CircleStrings::cUnop_5wng632f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_b3muSfKA_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cRandom_0ZwZ0twV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8388610.0f, 0, m, &cBinop_nWKaZYTP_sendMessage);
}

void Heavy_CircleStrings::cSlice_LOFarNr5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_0ZwZ0twV, 1, m, &cRandom_0ZwZ0twV_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cMsg_b3muSfKA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 1.0f);
  sVari_onMessage(_c, &Context(_c)->sVari_MHW0ClgY, m);
}

void Heavy_CircleStrings::cTabhead_wuoBFLpF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_n7n3TX8R, HV_BINOP_SUBTRACT, 0, m, &cBinop_n7n3TX8R_sendMessage);
}

void Heavy_CircleStrings::cMsg_H5RNN6NQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_1Ma4bD62_sendMessage);
}

void Heavy_CircleStrings::cSystem_1Ma4bD62_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_NnlxvWcw_sendMessage);
}

void Heavy_CircleStrings::cVar_8dVjwqxB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_UlHlcD60_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_SnmJLfEq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_SnmJLfEq, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_KAZzikd6, 0, m, &cDelay_KAZzikd6_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_68eizEgF, 0, m, &sTabread_68eizEgF_sendMessage);
}

void Heavy_CircleStrings::cDelay_KAZzikd6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_KAZzikd6, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_68eizEgF, 0, m, &sTabread_68eizEgF_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_KAZzikd6, 0, m, &cDelay_KAZzikd6_sendMessage);
}

void Heavy_CircleStrings::sTabread_68eizEgF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_jh9ucEZJ, HV_BINOP_SUBTRACT, 0, m, &cBinop_jh9ucEZJ_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_SrGd5mFE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_k5k8LXia, HV_BINOP_MAX, 0, m, &cBinop_k5k8LXia_sendMessage);
}

void Heavy_CircleStrings::cBinop_NnlxvWcw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_SrGd5mFE, HV_BINOP_MULTIPLY, 0, m, &cBinop_SrGd5mFE_sendMessage);
}

void Heavy_CircleStrings::cBinop_n7n3TX8R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_2ZSmXeNo_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_68eizEgF, 0, m, &sTabread_68eizEgF_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_UqAJHSA9_sendMessage);
}

void Heavy_CircleStrings::cSystem_swChKPmT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_jh9ucEZJ, HV_BINOP_SUBTRACT, 1, m, &cBinop_jh9ucEZJ_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_KAZzikd6, 2, m, &cDelay_KAZzikd6_sendMessage);
}

void Heavy_CircleStrings::cMsg_UlHlcD60_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_swChKPmT_sendMessage);
}

void Heavy_CircleStrings::cMsg_2ZSmXeNo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_SnmJLfEq, 0, m, &cDelay_SnmJLfEq_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_KAZzikd6, 0, m, &cDelay_KAZzikd6_sendMessage);
}

void Heavy_CircleStrings::cMsg_HLyecE7Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_k5k8LXia, HV_BINOP_MAX, 1, m, &cBinop_k5k8LXia_sendMessage);
}

void Heavy_CircleStrings::cBinop_k5k8LXia_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_n7n3TX8R, HV_BINOP_SUBTRACT, 1, m, &cBinop_n7n3TX8R_sendMessage);
}

void Heavy_CircleStrings::cCast_UqAJHSA9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_SnmJLfEq, 0, m, &cDelay_SnmJLfEq_sendMessage);
}

void Heavy_CircleStrings::cBinop_SeHKjpXS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_SnmJLfEq, 2, m, &cDelay_SnmJLfEq_sendMessage);
}

void Heavy_CircleStrings::cBinop_jh9ucEZJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_SeHKjpXS_sendMessage);
}

void Heavy_CircleStrings::cCast_71cDIlfB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_8dVjwqxB, 0, m, &cVar_8dVjwqxB_sendMessage);
  cMsg_H5RNN6NQ_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_wuoBFLpF, 0, m, &cTabhead_wuoBFLpF_sendMessage);
}

void Heavy_CircleStrings::cBinop_u3bBkCqo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_eBvLYK1Q_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_DXG39gCn_sendMessage);
}

void Heavy_CircleStrings::cBinop_4mcrCbUc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_qhnl6ywZ_sendMessage);
}

void Heavy_CircleStrings::cBinop_qhnl6ywZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_sd8m7DSi, HV_BINOP_POW, 1, m, &cBinop_sd8m7DSi_sendMessage);
  cMsg_HpTM8YDj_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_sd8m7DSi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_u3bBkCqo_sendMessage);
}

void Heavy_CircleStrings::cMsg_HpTM8YDj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_sd8m7DSi, HV_BINOP_POW, 0, m, &cBinop_sd8m7DSi_sendMessage);
}

void Heavy_CircleStrings::cVar_62UBDu2I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_4mcrCbUc_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_WMPplbtI_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_pZRjIPH6_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_fYJleqVB_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_1Et5gwL6_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_1Et5gwL6_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_QWDvcLTZ, 1, m, &cDelay_QWDvcLTZ_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_NX3LTNmc_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cDelay_QWDvcLTZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_QWDvcLTZ, m);
  cMsg_vtpTLnbt_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_1Et5gwL6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_QWDvcLTZ, 0, m, &cDelay_QWDvcLTZ_sendMessage);
}

void Heavy_CircleStrings::cCast_NX3LTNmc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_QWDvcLTZ, 0, m, &cDelay_QWDvcLTZ_sendMessage);
}

void Heavy_CircleStrings::cVar_qfnM3aRI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_So89Qwzb, HV_BINOP_MULTIPLY, 0, m, &cBinop_So89Qwzb_sendMessage);
}

void Heavy_CircleStrings::cMsg_kfSltSgA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_EDXyBvx8_sendMessage);
}

void Heavy_CircleStrings::cSystem_EDXyBvx8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_uvw6tZeh_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_So89Qwzb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_Qqxixs02_sendMessage);
}

void Heavy_CircleStrings::cBinop_qLJIXg1D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_So89Qwzb, HV_BINOP_MULTIPLY, 1, m, &cBinop_So89Qwzb_sendMessage);
}

void Heavy_CircleStrings::cMsg_uvw6tZeh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_qLJIXg1D_sendMessage);
}

void Heavy_CircleStrings::cBinop_Qqxixs02_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_RCuRLA4d_sendMessage);
}

void Heavy_CircleStrings::cBinop_RCuRLA4d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_neQ8pzb9_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_gbKxd1Qy, m);
}

void Heavy_CircleStrings::cBinop_neQ8pzb9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_YL39BZG2, m);
}

void Heavy_CircleStrings::cMsg_zRmbzlnP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Rvz3znvg_sendMessage);
}

void Heavy_CircleStrings::cSystem_Rvz3znvg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_c9g0wHN1_sendMessage);
}

void Heavy_CircleStrings::cDelay_RtFQVGmD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_RtFQVGmD, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_sVxNBKrQ, 0, m, &cDelay_sVxNBKrQ_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_RtFQVGmD, 0, m, &cDelay_RtFQVGmD_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_I9x9JcTu, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_sVxNBKrQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_sVxNBKrQ, m);
  cMsg_PisLiZYV_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_iOF2OcxA_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_8XFZgTl1_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_2pSZxfh0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_pmU7wQkt_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_09wS09Ef_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_6RvVBYgE_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_RtFQVGmD, 2, m, &cDelay_RtFQVGmD_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_9gP0hhlz_sendMessage);
}

void Heavy_CircleStrings::cMsg_pmU7wQkt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_09wS09Ef, 0, m, &hTable_09wS09Ef_sendMessage);
}

void Heavy_CircleStrings::cBinop_c9g0wHN1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 200.0f, 0, m, &cBinop_2pSZxfh0_sendMessage);
}

void Heavy_CircleStrings::cMsg_PisLiZYV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_09wS09Ef, 0, m, &hTable_09wS09Ef_sendMessage);
}

void Heavy_CircleStrings::cCast_9gP0hhlz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_RtFQVGmD, 0, m, &cDelay_RtFQVGmD_sendMessage);
}

void Heavy_CircleStrings::cMsg_6RvVBYgE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_sVxNBKrQ, 2, m, &cDelay_sVxNBKrQ_sendMessage);
}

void Heavy_CircleStrings::cMsg_8XFZgTl1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_I9x9JcTu, 1, m, NULL);
}

void Heavy_CircleStrings::cMsg_MmTB0o4l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 1.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_RcOn8tR1, 0, m, NULL);
}

void Heavy_CircleStrings::cMsg_vtpTLnbt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 1.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_RcOn8tR1, 0, m, NULL);
}

void Heavy_CircleStrings::cCast_pZRjIPH6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_MmTB0o4l_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_WMPplbtI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_fYJleqVB_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cMsg_4EC5DgdX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 60.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_4mcrCbUc_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_WMPplbtI_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_pZRjIPH6_sendMessage);
}

void Heavy_CircleStrings::cBinop_FJNkhkMw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_SrGd5mFE, HV_BINOP_MULTIPLY, 1, m, &cBinop_SrGd5mFE_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_71cDIlfB_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_QWDvcLTZ, 1, m, &cDelay_QWDvcLTZ_sendMessage);
}

void Heavy_CircleStrings::cMsg_rvtwdPkn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1000.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_FJNkhkMw, HV_BINOP_DIVIDE, 0, m, &cBinop_FJNkhkMw_sendMessage);
}

void Heavy_CircleStrings::cCast_eBvLYK1Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_FJNkhkMw, HV_BINOP_DIVIDE, 1, m, &cBinop_FJNkhkMw_sendMessage);
}

void Heavy_CircleStrings::cCast_DXG39gCn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_rvtwdPkn_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cUnop_YQRwxhPM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_Fmz1NpuH, 0, m, &cPack_Fmz1NpuH_sendMessage);
}

void Heavy_CircleStrings::cUnop_Lc44Et5l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_WuQibfMZ, 0, m, &cPack_WuQibfMZ_sendMessage);
}

void Heavy_CircleStrings::cPack_WuQibfMZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_RYeyrni5, 0, m, NULL);
}

void Heavy_CircleStrings::cPack_Fmz1NpuH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_CFJMbUzK, 0, m, NULL);
}

void Heavy_CircleStrings::cBinop_oDwo1nHp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_YQRwxhPM_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_SIN, m, &cUnop_Lc44Et5l_sendMessage);
}

void Heavy_CircleStrings::cMsg_hXYYiybc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.5f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_oDwo1nHp_sendMessage);
}

void Heavy_CircleStrings::cSlice_bMO4J7Eo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 127.0f, 0, m, &cBinop_cyJmo76z_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cSlice_zWJwkxZA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_g7LUIysO_sendMessage);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_hxqJk4js_sendMessage);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_4mcrCbUc_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_WMPplbtI_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_pZRjIPH6_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_1XQUFboy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.4f, 0, m, &cBinop_TCADAnRt_sendMessage);
}

void Heavy_CircleStrings::cBinop_TCADAnRt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_oDwo1nHp_sendMessage);
}

void Heavy_CircleStrings::cBinop_cyJmo76z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_PQ2johGX_sendMessage(_c, 0, m);
  cSend_Q0XHu7Zi_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_sB5EJ13L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_piCNqURO_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_vTxCro9z_sendMessage);
}

void Heavy_CircleStrings::cBinop_YcLTFVkP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.99f, 0, m, &cBinop_34fRprl0_sendMessage);
}

void Heavy_CircleStrings::cBinop_34fRprl0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_sB5EJ13L, HV_BINOP_MULTIPLY, 1, m, &cBinop_sB5EJ13L_sendMessage);
}

void Heavy_CircleStrings::cSend_PQ2johGX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_byLS6igX_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_piCNqURO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_YcF2qB0Y_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cCast_vTxCro9z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_6BTHBSCn_sendMessage);
}

void Heavy_CircleStrings::cBinop_aLC6LHHs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_B3Kat4VK, 0, m, &cPack_B3Kat4VK_sendMessage);
}

void Heavy_CircleStrings::cSend_Q0XHu7Zi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_xedTPFFX_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_JhL5XM5O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_CMr3LFZ9_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_UM7Omoc2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 200.0f);
  cSend_JhL5XM5O_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_7rsDM7UX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.999f);
  sVarf_onMessage(_c, &Context(_c)->sVarf_g8p8Mjcd, m);
}

void Heavy_CircleStrings::cCast_g7LUIysO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_fK9ALo6Q_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cSwitchcase_SNzf7ynS_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_lLWgYqNt, 0, m, &cSlice_lLWgYqNt_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_KywFe7Be, 0, m, &cRandom_KywFe7Be_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_dn1EMdxb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_gNw1FN08_sendMessage);
}

void Heavy_CircleStrings::cUnop_gNw1FN08_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_f1ez5cDH_sendMessage);
}

void Heavy_CircleStrings::cRandom_KywFe7Be_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_dn1EMdxb_sendMessage);
}

void Heavy_CircleStrings::cSlice_lLWgYqNt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_KywFe7Be, 1, m, &cRandom_KywFe7Be_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_tkO6kpCP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_pIY7x5qF, HV_BINOP_MULTIPLY, 0, m, &cBinop_pIY7x5qF_sendMessage);
}

void Heavy_CircleStrings::cBinop_1qzttrMO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_R88LSDNt_sendMessage);
}

void Heavy_CircleStrings::cBinop_R88LSDNt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_tv9JS2ex, HV_BINOP_POW, 1, m, &cBinop_tv9JS2ex_sendMessage);
  cMsg_xs9bpL0Q_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_tv9JS2ex_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_tkO6kpCP_sendMessage);
}

void Heavy_CircleStrings::cMsg_xs9bpL0Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_tv9JS2ex, HV_BINOP_POW, 0, m, &cBinop_tv9JS2ex_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_oHUzW0gw_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_ruSTsWhB, 0, m, &cSlice_ruSTsWhB_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_XaroSBc7, 0, m, &cRandom_XaroSBc7_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_6XOnasIi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_m9hOo3z8_sendMessage);
}

void Heavy_CircleStrings::cUnop_m9hOo3z8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_lP0opnKA_sendMessage);
}

void Heavy_CircleStrings::cRandom_XaroSBc7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 15.0f, 0, m, &cBinop_6XOnasIi_sendMessage);
}

void Heavy_CircleStrings::cSlice_ruSTsWhB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_XaroSBc7, 1, m, &cRandom_XaroSBc7_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cPack_l4iZ1JLD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_whQbWXMV, 0, m, NULL);
}

void Heavy_CircleStrings::cVar_6l45wIo5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_jpwLY43g_sendMessage);
}

void Heavy_CircleStrings::cVar_bdRnAwRu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_fNoS14U3, 0, m);
}

void Heavy_CircleStrings::cVar_9aYgMeAL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_qp71nUId_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_qxfvQ6K5_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_WewsoAWQ_sendMessage);
}

void Heavy_CircleStrings::cVar_rKYyfb7b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cVar_RAIf5TS8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cVar_btJuTAN1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cSwitchcase_5bP6ahtC_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_TSSZtcE5_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_TSSZtcE5_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_TGXGtAvG, 1, m, &cDelay_TGXGtAvG_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_01uE18GK_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cDelay_TGXGtAvG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_TGXGtAvG, m);
  cVar_onMessage(_c, &Context(_c)->cVar_2BMV26Dm, 0, m, &cVar_2BMV26Dm_sendMessage);
}

void Heavy_CircleStrings::cMsg_TSSZtcE5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_TGXGtAvG, 0, m, &cDelay_TGXGtAvG_sendMessage);
}

void Heavy_CircleStrings::cCast_01uE18GK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_TGXGtAvG, 0, m, &cDelay_TGXGtAvG_sendMessage);
}

void Heavy_CircleStrings::cVar_2BMV26Dm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_oFTk3izM_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_HJud7MNE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_9aYgMeAL, 0, m, &cVar_9aYgMeAL_sendMessage);
}

void Heavy_CircleStrings::cMsg_E8auMZAT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 25.0f);
  cSend_Mbx2yd6J_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_7dhQr2nz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 4000.0f);
  cSend_mNqbVTHN_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_98EefR56_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSend_DjbSkzqU_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_otA1S4rx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_Ewr7zMGz_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_rtcEI2OT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cSend_vkELbSXe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_Y81Wizul_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_Mbx2yd6J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cSend_mNqbVTHN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_Ewr7zMGz_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_DjbSkzqU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_Y81Wizul_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_smSOuft9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 25.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_rnfc601c, 0, m, NULL);
}

void Heavy_CircleStrings::cMsg_oFTk3izM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 0);
  sLine_onMessage(_c, &Context(_c)->sLine_rnfc601c, 0, m, NULL);
}

void Heavy_CircleStrings::cCast_qxfvQ6K5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_2BMV26Dm, 1, m, &cVar_2BMV26Dm_sendMessage);
}

void Heavy_CircleStrings::cCast_WewsoAWQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_5bP6ahtC_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cCast_qp71nUId_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_smSOuft9_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_JS7AOFlo_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_hR1Kr2HM, 0, m, &cSlice_hR1Kr2HM_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_Iq1D1hZH, 0, m, &cRandom_Iq1D1hZH_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_aLWSu0J2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_n4iCEFkL_sendMessage);
}

void Heavy_CircleStrings::cUnop_n4iCEFkL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_tDL3L1D4_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cRandom_Iq1D1hZH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8388610.0f, 0, m, &cBinop_aLWSu0J2_sendMessage);
}

void Heavy_CircleStrings::cSlice_hR1Kr2HM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_Iq1D1hZH, 1, m, &cRandom_Iq1D1hZH_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cMsg_tDL3L1D4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 1.0f);
  sVari_onMessage(_c, &Context(_c)->sVari_yElZGC0h, m);
}

void Heavy_CircleStrings::cTabhead_nD8rYepw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_1DgjZTps, HV_BINOP_SUBTRACT, 0, m, &cBinop_1DgjZTps_sendMessage);
}

void Heavy_CircleStrings::cMsg_hVbl5kAh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_tSj37nXB_sendMessage);
}

void Heavy_CircleStrings::cSystem_tSj37nXB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_fuG2GDtG_sendMessage);
}

void Heavy_CircleStrings::cVar_Ae9LXAyP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_DOShY8Y8_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_SZSST4gS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_SZSST4gS, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_VnPTZVjZ, 0, m, &cDelay_VnPTZVjZ_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_yHs0GT09, 0, m, &sTabread_yHs0GT09_sendMessage);
}

void Heavy_CircleStrings::cDelay_VnPTZVjZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_VnPTZVjZ, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_yHs0GT09, 0, m, &sTabread_yHs0GT09_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_VnPTZVjZ, 0, m, &cDelay_VnPTZVjZ_sendMessage);
}

void Heavy_CircleStrings::sTabread_yHs0GT09_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_NpiT9JHp, HV_BINOP_SUBTRACT, 0, m, &cBinop_NpiT9JHp_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_XWe2MBT0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_1bfh8MXq, HV_BINOP_MAX, 0, m, &cBinop_1bfh8MXq_sendMessage);
}

void Heavy_CircleStrings::cBinop_fuG2GDtG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_XWe2MBT0, HV_BINOP_MULTIPLY, 0, m, &cBinop_XWe2MBT0_sendMessage);
}

void Heavy_CircleStrings::cBinop_1DgjZTps_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_4pQ2NAFS_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_yHs0GT09, 0, m, &sTabread_yHs0GT09_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_O2mV0fRb_sendMessage);
}

void Heavy_CircleStrings::cSystem_GmAANNUs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_NpiT9JHp, HV_BINOP_SUBTRACT, 1, m, &cBinop_NpiT9JHp_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_VnPTZVjZ, 2, m, &cDelay_VnPTZVjZ_sendMessage);
}

void Heavy_CircleStrings::cMsg_DOShY8Y8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_GmAANNUs_sendMessage);
}

void Heavy_CircleStrings::cMsg_4pQ2NAFS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_SZSST4gS, 0, m, &cDelay_SZSST4gS_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_VnPTZVjZ, 0, m, &cDelay_VnPTZVjZ_sendMessage);
}

void Heavy_CircleStrings::cMsg_G0NI423s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_1bfh8MXq, HV_BINOP_MAX, 1, m, &cBinop_1bfh8MXq_sendMessage);
}

void Heavy_CircleStrings::cBinop_1bfh8MXq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_1DgjZTps, HV_BINOP_SUBTRACT, 1, m, &cBinop_1DgjZTps_sendMessage);
}

void Heavy_CircleStrings::cCast_O2mV0fRb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_SZSST4gS, 0, m, &cDelay_SZSST4gS_sendMessage);
}

void Heavy_CircleStrings::cBinop_hmf3wcFM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_SZSST4gS, 2, m, &cDelay_SZSST4gS_sendMessage);
}

void Heavy_CircleStrings::cBinop_NpiT9JHp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_hmf3wcFM_sendMessage);
}

void Heavy_CircleStrings::cCast_4ovQ8QKw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Ae9LXAyP, 0, m, &cVar_Ae9LXAyP_sendMessage);
  cMsg_hVbl5kAh_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_nD8rYepw, 0, m, &cTabhead_nD8rYepw_sendMessage);
}

void Heavy_CircleStrings::cBinop_M7VuKD9p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_TYBgQbOA_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_KQEK2NQZ_sendMessage);
}

void Heavy_CircleStrings::cBinop_D6lFdsuH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_NeeWGhFY_sendMessage);
}

void Heavy_CircleStrings::cBinop_NeeWGhFY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_2Sc4VodB, HV_BINOP_POW, 1, m, &cBinop_2Sc4VodB_sendMessage);
  cMsg_Vpw8sTwl_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_2Sc4VodB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_M7VuKD9p_sendMessage);
}

void Heavy_CircleStrings::cMsg_Vpw8sTwl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_2Sc4VodB, HV_BINOP_POW, 0, m, &cBinop_2Sc4VodB_sendMessage);
}

void Heavy_CircleStrings::cVar_SGy1Fu8N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_D6lFdsuH_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_SC2SeUFt_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_DPTbt347_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_G1OphG2R_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_HxjImBu9_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_HxjImBu9_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_DH8AaDOn, 1, m, &cDelay_DH8AaDOn_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_llBdcUtw_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cDelay_DH8AaDOn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_DH8AaDOn, m);
  cMsg_H3xq3kuh_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_HxjImBu9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_DH8AaDOn, 0, m, &cDelay_DH8AaDOn_sendMessage);
}

void Heavy_CircleStrings::cCast_llBdcUtw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_DH8AaDOn, 0, m, &cDelay_DH8AaDOn_sendMessage);
}

void Heavy_CircleStrings::cVar_DFDFpVaI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ZFkh6uZ8, HV_BINOP_MULTIPLY, 0, m, &cBinop_ZFkh6uZ8_sendMessage);
}

void Heavy_CircleStrings::cMsg_FykzmL5g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_iElF2AEY_sendMessage);
}

void Heavy_CircleStrings::cSystem_iElF2AEY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_nKksS6Mp_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_ZFkh6uZ8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_waEPZqOF_sendMessage);
}

void Heavy_CircleStrings::cBinop_gpXegg6X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ZFkh6uZ8, HV_BINOP_MULTIPLY, 1, m, &cBinop_ZFkh6uZ8_sendMessage);
}

void Heavy_CircleStrings::cMsg_nKksS6Mp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_gpXegg6X_sendMessage);
}

void Heavy_CircleStrings::cBinop_waEPZqOF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_5aOf3WKx_sendMessage);
}

void Heavy_CircleStrings::cBinop_5aOf3WKx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_d2rzejC8_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_dBxXmxi8, m);
}

void Heavy_CircleStrings::cBinop_d2rzejC8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_Zzsa36Pg, m);
}

void Heavy_CircleStrings::cMsg_aEj0GFx6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ygtSFGmr_sendMessage);
}

void Heavy_CircleStrings::cSystem_ygtSFGmr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_xzGJ3hnX_sendMessage);
}

void Heavy_CircleStrings::cDelay_6hCqgoKq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_6hCqgoKq, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_3mH8JMdN, 0, m, &cDelay_3mH8JMdN_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_6hCqgoKq, 0, m, &cDelay_6hCqgoKq_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_o5PUcACM, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_3mH8JMdN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_3mH8JMdN, m);
  cMsg_aMerwewV_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_VBK5hQI5_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_6QOnHlhW_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_CjDA02yO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_QtjSglyo_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_xRdA4qp0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_U4Ch4eqv_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_6hCqgoKq, 2, m, &cDelay_6hCqgoKq_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ORyno4W7_sendMessage);
}

void Heavy_CircleStrings::cMsg_QtjSglyo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_xRdA4qp0, 0, m, &hTable_xRdA4qp0_sendMessage);
}

void Heavy_CircleStrings::cBinop_xzGJ3hnX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 200.0f, 0, m, &cBinop_CjDA02yO_sendMessage);
}

void Heavy_CircleStrings::cMsg_aMerwewV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_xRdA4qp0, 0, m, &hTable_xRdA4qp0_sendMessage);
}

void Heavy_CircleStrings::cCast_ORyno4W7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_6hCqgoKq, 0, m, &cDelay_6hCqgoKq_sendMessage);
}

void Heavy_CircleStrings::cMsg_U4Ch4eqv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_3mH8JMdN, 2, m, &cDelay_3mH8JMdN_sendMessage);
}

void Heavy_CircleStrings::cMsg_6QOnHlhW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_o5PUcACM, 1, m, NULL);
}

void Heavy_CircleStrings::cMsg_mzl87EUi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 1.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_6k24F53H, 0, m, NULL);
}

void Heavy_CircleStrings::cMsg_H3xq3kuh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 1.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_6k24F53H, 0, m, NULL);
}

void Heavy_CircleStrings::cCast_DPTbt347_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_mzl87EUi_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_SC2SeUFt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_G1OphG2R_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cMsg_Cn56sjg8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 60.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_D6lFdsuH_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_SC2SeUFt_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_DPTbt347_sendMessage);
}

void Heavy_CircleStrings::cBinop_vwLHfLeX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_XWe2MBT0, HV_BINOP_MULTIPLY, 1, m, &cBinop_XWe2MBT0_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_4ovQ8QKw_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_DH8AaDOn, 1, m, &cDelay_DH8AaDOn_sendMessage);
}

void Heavy_CircleStrings::cMsg_ixColt0E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1000.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_vwLHfLeX, HV_BINOP_DIVIDE, 0, m, &cBinop_vwLHfLeX_sendMessage);
}

void Heavy_CircleStrings::cCast_KQEK2NQZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ixColt0E_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_TYBgQbOA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_vwLHfLeX, HV_BINOP_DIVIDE, 1, m, &cBinop_vwLHfLeX_sendMessage);
}

void Heavy_CircleStrings::cUnop_xVqWZiKW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_ykbzodLd, 0, m, &cPack_ykbzodLd_sendMessage);
}

void Heavy_CircleStrings::cUnop_P3qrEwFP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_BQtOqjzH, 0, m, &cPack_BQtOqjzH_sendMessage);
}

void Heavy_CircleStrings::cPack_BQtOqjzH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_OoVkWdWH, 0, m, NULL);
}

void Heavy_CircleStrings::cPack_ykbzodLd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_CLdEiIdZ, 0, m, NULL);
}

void Heavy_CircleStrings::cBinop_M4koMG0z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_xVqWZiKW_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_SIN, m, &cUnop_P3qrEwFP_sendMessage);
}

void Heavy_CircleStrings::cMsg_tp2FfUz5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.5f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_M4koMG0z_sendMessage);
}

void Heavy_CircleStrings::cSlice_aDh3KdBV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 127.0f, 0, m, &cBinop_Y9SPWzqH_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cSlice_5ZO90l66_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_vN1EVGGa_sendMessage);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_1qzttrMO_sendMessage);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_D6lFdsuH_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_SC2SeUFt_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_DPTbt347_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_f1ez5cDH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.4f, 0, m, &cBinop_K4dsp40f_sendMessage);
}

void Heavy_CircleStrings::cBinop_K4dsp40f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_M4koMG0z_sendMessage);
}

void Heavy_CircleStrings::cBinop_Y9SPWzqH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_MN3eumAE_sendMessage(_c, 0, m);
  cSend_mN9E1bea_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_pIY7x5qF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_i33vR1Mt_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_yv9HTP7S_sendMessage);
}

void Heavy_CircleStrings::cBinop_lP0opnKA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.99f, 0, m, &cBinop_lA1JWIKT_sendMessage);
}

void Heavy_CircleStrings::cBinop_lA1JWIKT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_pIY7x5qF, HV_BINOP_MULTIPLY, 1, m, &cBinop_pIY7x5qF_sendMessage);
}

void Heavy_CircleStrings::cSend_MN3eumAE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_jpyWujMt_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_yv9HTP7S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_HJud7MNE_sendMessage);
}

void Heavy_CircleStrings::cCast_i33vR1Mt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_SNzf7ynS_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cBinop_jpwLY43g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_l4iZ1JLD, 0, m, &cPack_l4iZ1JLD_sendMessage);
}

void Heavy_CircleStrings::cSend_mN9E1bea_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_r0FPSQXF_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_kkr6vfQk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_aPKrVrEs_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_3kQjt736_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 200.0f);
  cSend_kkr6vfQk_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_GCCZGxXP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.999f);
  sVarf_onMessage(_c, &Context(_c)->sVarf_t4D28GUq, m);
}

void Heavy_CircleStrings::cCast_vN1EVGGa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_oHUzW0gw_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cSwitchcase_sz59YDvM_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_6PuuWynS, 0, m, &cSlice_6PuuWynS_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_fQUjFfhR, 0, m, &cRandom_fQUjFfhR_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_8XzR4qKI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_DiwScA2V_sendMessage);
}

void Heavy_CircleStrings::cUnop_DiwScA2V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_iUte0eX4_sendMessage);
}

void Heavy_CircleStrings::cRandom_fQUjFfhR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_8XzR4qKI_sendMessage);
}

void Heavy_CircleStrings::cSlice_6PuuWynS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_fQUjFfhR, 1, m, &cRandom_fQUjFfhR_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_7XET1CEu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_liJVsEqt, HV_BINOP_MULTIPLY, 0, m, &cBinop_liJVsEqt_sendMessage);
}

void Heavy_CircleStrings::cBinop_78syovO7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_pgoWtf0u_sendMessage);
}

void Heavy_CircleStrings::cBinop_pgoWtf0u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Bwq4Jpd4, HV_BINOP_POW, 1, m, &cBinop_Bwq4Jpd4_sendMessage);
  cMsg_39DUy333_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_Bwq4Jpd4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_7XET1CEu_sendMessage);
}

void Heavy_CircleStrings::cMsg_39DUy333_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_Bwq4Jpd4, HV_BINOP_POW, 0, m, &cBinop_Bwq4Jpd4_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_0WEaG4ca_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_cy9q8bzK, 0, m, &cSlice_cy9q8bzK_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_9Ll2ULnG, 0, m, &cRandom_9Ll2ULnG_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_4abrHOiE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_7KYsdSHo_sendMessage);
}

void Heavy_CircleStrings::cUnop_7KYsdSHo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_FBUHWDm8_sendMessage);
}

void Heavy_CircleStrings::cRandom_9Ll2ULnG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 15.0f, 0, m, &cBinop_4abrHOiE_sendMessage);
}

void Heavy_CircleStrings::cSlice_cy9q8bzK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_9Ll2ULnG, 1, m, &cRandom_9Ll2ULnG_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cPack_eqaPpdVA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_Uu2HTcOD, 0, m, NULL);
}

void Heavy_CircleStrings::cVar_lp41rcdZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_6G8lE89h_sendMessage);
}

void Heavy_CircleStrings::cVar_IsFN3WHs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_vxBYdwZj, 0, m);
}

void Heavy_CircleStrings::cVar_HFc0rQEf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_f51gZe2L_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_OIFRXElr_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_lcxGmJpj_sendMessage);
}

void Heavy_CircleStrings::cVar_9H3xucx5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cVar_l3yfjaJm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cVar_mpoZnz5U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cSwitchcase_FpwBclZU_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_BcIGxCLN_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_BcIGxCLN_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_07sAnDiR, 1, m, &cDelay_07sAnDiR_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_NekAB4lU_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cDelay_07sAnDiR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_07sAnDiR, m);
  cVar_onMessage(_c, &Context(_c)->cVar_SkY36zJg, 0, m, &cVar_SkY36zJg_sendMessage);
}

void Heavy_CircleStrings::cMsg_BcIGxCLN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_07sAnDiR, 0, m, &cDelay_07sAnDiR_sendMessage);
}

void Heavy_CircleStrings::cCast_NekAB4lU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_07sAnDiR, 0, m, &cDelay_07sAnDiR_sendMessage);
}

void Heavy_CircleStrings::cVar_SkY36zJg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Hkh4quwB_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_eKHsWMTz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_HFc0rQEf, 0, m, &cVar_HFc0rQEf_sendMessage);
}

void Heavy_CircleStrings::cMsg_wHQyZ5nd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 25.0f);
  cSend_RVatBNRy_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_cnnZzlMn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 4000.0f);
  cSend_wUbM8FDG_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_14PwjGEE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSend_o6gnhxx2_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_im54KyY8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_oS5paxUB_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_VSMG5NMK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cSend_sf3mSnxf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_7c0Toumm_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_RVatBNRy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cSend_wUbM8FDG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_oS5paxUB_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_o6gnhxx2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_7c0Toumm_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_R9MlaYIl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 25.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_Ejidq5xI, 0, m, NULL);
}

void Heavy_CircleStrings::cMsg_Hkh4quwB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 0);
  sLine_onMessage(_c, &Context(_c)->sLine_Ejidq5xI, 0, m, NULL);
}

void Heavy_CircleStrings::cCast_OIFRXElr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_SkY36zJg, 1, m, &cVar_SkY36zJg_sendMessage);
}

void Heavy_CircleStrings::cCast_f51gZe2L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_R9MlaYIl_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_lcxGmJpj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_FpwBclZU_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cSwitchcase_73ZwiGwe_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_hit0CKTz, 0, m, &cSlice_hit0CKTz_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_zzv73S6D, 0, m, &cRandom_zzv73S6D_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_zPapdyTt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_kfk1Km9b_sendMessage);
}

void Heavy_CircleStrings::cUnop_kfk1Km9b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_J4DyiUuw_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cRandom_zzv73S6D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8388610.0f, 0, m, &cBinop_zPapdyTt_sendMessage);
}

void Heavy_CircleStrings::cSlice_hit0CKTz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_zzv73S6D, 1, m, &cRandom_zzv73S6D_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cMsg_J4DyiUuw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 1.0f);
  sVari_onMessage(_c, &Context(_c)->sVari_9nW8mwS9, m);
}

void Heavy_CircleStrings::cTabhead_BfQ99xL1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_DZ2jvEFl, HV_BINOP_SUBTRACT, 0, m, &cBinop_DZ2jvEFl_sendMessage);
}

void Heavy_CircleStrings::cMsg_3zKAN5uv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_GxLqU3jF_sendMessage);
}

void Heavy_CircleStrings::cSystem_GxLqU3jF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_VWdl2Ms0_sendMessage);
}

void Heavy_CircleStrings::cVar_9keS29QT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_80MXRdgU_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cDelay_P5zEZZ5h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_P5zEZZ5h, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Mq4e45Wi, 0, m, &cDelay_Mq4e45Wi_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_qmKzqtG1, 0, m, &sTabread_qmKzqtG1_sendMessage);
}

void Heavy_CircleStrings::cDelay_Mq4e45Wi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Mq4e45Wi, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_qmKzqtG1, 0, m, &sTabread_qmKzqtG1_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Mq4e45Wi, 0, m, &cDelay_Mq4e45Wi_sendMessage);
}

void Heavy_CircleStrings::sTabread_qmKzqtG1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_DuEse51a, HV_BINOP_SUBTRACT, 0, m, &cBinop_DuEse51a_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_1bnzVpGw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_pTE8jIDw, HV_BINOP_MAX, 0, m, &cBinop_pTE8jIDw_sendMessage);
}

void Heavy_CircleStrings::cBinop_VWdl2Ms0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_1bnzVpGw, HV_BINOP_MULTIPLY, 0, m, &cBinop_1bnzVpGw_sendMessage);
}

void Heavy_CircleStrings::cBinop_DZ2jvEFl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_lOY92VhQ_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_qmKzqtG1, 0, m, &sTabread_qmKzqtG1_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_CwnkPU9L_sendMessage);
}

void Heavy_CircleStrings::cSystem_kpoYpQMi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_DuEse51a, HV_BINOP_SUBTRACT, 1, m, &cBinop_DuEse51a_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Mq4e45Wi, 2, m, &cDelay_Mq4e45Wi_sendMessage);
}

void Heavy_CircleStrings::cMsg_80MXRdgU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_kpoYpQMi_sendMessage);
}

void Heavy_CircleStrings::cMsg_lOY92VhQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_P5zEZZ5h, 0, m, &cDelay_P5zEZZ5h_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Mq4e45Wi, 0, m, &cDelay_Mq4e45Wi_sendMessage);
}

void Heavy_CircleStrings::cMsg_eD9Ow2eh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_pTE8jIDw, HV_BINOP_MAX, 1, m, &cBinop_pTE8jIDw_sendMessage);
}

void Heavy_CircleStrings::cBinop_pTE8jIDw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_DZ2jvEFl, HV_BINOP_SUBTRACT, 1, m, &cBinop_DZ2jvEFl_sendMessage);
}

void Heavy_CircleStrings::cCast_CwnkPU9L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_P5zEZZ5h, 0, m, &cDelay_P5zEZZ5h_sendMessage);
}

void Heavy_CircleStrings::cBinop_yEPE2qW0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_P5zEZZ5h, 2, m, &cDelay_P5zEZZ5h_sendMessage);
}

void Heavy_CircleStrings::cBinop_DuEse51a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_yEPE2qW0_sendMessage);
}

void Heavy_CircleStrings::cCast_Z3nFLMj9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_9keS29QT, 0, m, &cVar_9keS29QT_sendMessage);
  cMsg_3zKAN5uv_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_BfQ99xL1, 0, m, &cTabhead_BfQ99xL1_sendMessage);
}

void Heavy_CircleStrings::cBinop_jATpQ5uc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_4Dh4OLSR_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_dZTSefew_sendMessage);
}

void Heavy_CircleStrings::cBinop_O4gZQEps_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_xMoziyHn_sendMessage);
}

void Heavy_CircleStrings::cBinop_xMoziyHn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_hLBqjsvQ, HV_BINOP_POW, 1, m, &cBinop_hLBqjsvQ_sendMessage);
  cMsg_qD2cOZaw_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_hLBqjsvQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_jATpQ5uc_sendMessage);
}

void Heavy_CircleStrings::cMsg_qD2cOZaw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_hLBqjsvQ, HV_BINOP_POW, 0, m, &cBinop_hLBqjsvQ_sendMessage);
}

void Heavy_CircleStrings::cVar_QDBTb7Gw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_O4gZQEps_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_q65Hj2e0_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_oCDcTr0p_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_HFTIyVFe_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_9wfKc5ba_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_9wfKc5ba_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_JzAtoJP3, 1, m, &cDelay_JzAtoJP3_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_J6VbGgqG_sendMessage);
      break;
    }
  }
}

void Heavy_CircleStrings::cDelay_JzAtoJP3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_JzAtoJP3, m);
  cMsg_VAUunZKn_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_9wfKc5ba_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_JzAtoJP3, 0, m, &cDelay_JzAtoJP3_sendMessage);
}

void Heavy_CircleStrings::cCast_J6VbGgqG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_JzAtoJP3, 0, m, &cDelay_JzAtoJP3_sendMessage);
}

void Heavy_CircleStrings::cVar_mT0RV9wd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_04tbGSdj, HV_BINOP_MULTIPLY, 0, m, &cBinop_04tbGSdj_sendMessage);
}

void Heavy_CircleStrings::cMsg_uCMQDqDS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_nqYyGDc6_sendMessage);
}

void Heavy_CircleStrings::cSystem_nqYyGDc6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_5j9Mtybd_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_04tbGSdj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_hdInkJNY_sendMessage);
}

void Heavy_CircleStrings::cBinop_qUbvcSd1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_04tbGSdj, HV_BINOP_MULTIPLY, 1, m, &cBinop_04tbGSdj_sendMessage);
}

void Heavy_CircleStrings::cMsg_5j9Mtybd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_qUbvcSd1_sendMessage);
}

void Heavy_CircleStrings::cBinop_hdInkJNY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_Jwbnb0jG_sendMessage);
}

void Heavy_CircleStrings::cBinop_Jwbnb0jG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_0OaJDtI4_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_1lKsZJBG, m);
}

void Heavy_CircleStrings::cBinop_0OaJDtI4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_AFW9daME, m);
}

void Heavy_CircleStrings::cMsg_9J5DyhTT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_TQvNApP0_sendMessage);
}

void Heavy_CircleStrings::cSystem_TQvNApP0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_3LajVpB4_sendMessage);
}

void Heavy_CircleStrings::cDelay_Sgf5oX5W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Sgf5oX5W, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_pP39T0wm, 0, m, &cDelay_pP39T0wm_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Sgf5oX5W, 0, m, &cDelay_Sgf5oX5W_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_I0CXtZeH, 1, m, NULL);
}

void Heavy_CircleStrings::cDelay_pP39T0wm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_pP39T0wm, m);
  cMsg_FjvIbECQ_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSwitchcase_Qs0bX93Z_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_MQ5Dv6P4_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cBinop_aLMlJuA9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_cQN9dWsb_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::hTable_c60lHUpc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Xva2H59j_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Sgf5oX5W, 2, m, &cDelay_Sgf5oX5W_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_WTeNGWVd_sendMessage);
}

void Heavy_CircleStrings::cMsg_cQN9dWsb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_c60lHUpc, 0, m, &hTable_c60lHUpc_sendMessage);
}

void Heavy_CircleStrings::cBinop_3LajVpB4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 200.0f, 0, m, &cBinop_aLMlJuA9_sendMessage);
}

void Heavy_CircleStrings::cMsg_FjvIbECQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_c60lHUpc, 0, m, &hTable_c60lHUpc_sendMessage);
}

void Heavy_CircleStrings::cCast_WTeNGWVd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Sgf5oX5W, 0, m, &cDelay_Sgf5oX5W_sendMessage);
}

void Heavy_CircleStrings::cMsg_Xva2H59j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_pP39T0wm, 2, m, &cDelay_pP39T0wm_sendMessage);
}

void Heavy_CircleStrings::cMsg_MQ5Dv6P4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_I0CXtZeH, 1, m, NULL);
}

void Heavy_CircleStrings::cMsg_1qgEv1gE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 1.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_Uwdduvwe, 0, m, NULL);
}

void Heavy_CircleStrings::cMsg_VAUunZKn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 1.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_Uwdduvwe, 0, m, NULL);
}

void Heavy_CircleStrings::cCast_oCDcTr0p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_1qgEv1gE_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_q65Hj2e0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_HFTIyVFe_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cMsg_UQ54Ck2b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 60.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_O4gZQEps_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_q65Hj2e0_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_oCDcTr0p_sendMessage);
}

void Heavy_CircleStrings::cBinop_grJjpu0a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_1bnzVpGw, HV_BINOP_MULTIPLY, 1, m, &cBinop_1bnzVpGw_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Z3nFLMj9_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_JzAtoJP3, 1, m, &cDelay_JzAtoJP3_sendMessage);
}

void Heavy_CircleStrings::cMsg_r4RPqpgf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1000.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_grJjpu0a, HV_BINOP_DIVIDE, 0, m, &cBinop_grJjpu0a_sendMessage);
}

void Heavy_CircleStrings::cCast_dZTSefew_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_r4RPqpgf_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_4Dh4OLSR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_grJjpu0a, HV_BINOP_DIVIDE, 1, m, &cBinop_grJjpu0a_sendMessage);
}

void Heavy_CircleStrings::cUnop_JBnRA41t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_0e04MzDN, 0, m, &cPack_0e04MzDN_sendMessage);
}

void Heavy_CircleStrings::cUnop_j336CBXa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_QJyqM7KF, 0, m, &cPack_QJyqM7KF_sendMessage);
}

void Heavy_CircleStrings::cPack_QJyqM7KF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_owtRzKrP, 0, m, NULL);
}

void Heavy_CircleStrings::cPack_0e04MzDN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_CPLwMQlZ, 0, m, NULL);
}

void Heavy_CircleStrings::cBinop_1bG8Rf0N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_JBnRA41t_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_SIN, m, &cUnop_j336CBXa_sendMessage);
}

void Heavy_CircleStrings::cMsg_06LbI1wq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.5f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_1bG8Rf0N_sendMessage);
}

void Heavy_CircleStrings::cSlice_5PgzWz1k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 127.0f, 0, m, &cBinop_cG4H5N6M_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cSlice_AHkpNVRV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_2dzPUyEO_sendMessage);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_78syovO7_sendMessage);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_O4gZQEps_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_q65Hj2e0_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_oCDcTr0p_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cBinop_iUte0eX4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.4f, 0, m, &cBinop_V1s6NEUQ_sendMessage);
}

void Heavy_CircleStrings::cBinop_V1s6NEUQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_1bG8Rf0N_sendMessage);
}

void Heavy_CircleStrings::cBinop_cG4H5N6M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_Qc9ZGDLH_sendMessage(_c, 0, m);
  cSend_qCrOGg4x_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_liJVsEqt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_dyKQ6SQH_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_XutPNt6L_sendMessage);
}

void Heavy_CircleStrings::cBinop_FBUHWDm8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.99f, 0, m, &cBinop_6xqXUZVJ_sendMessage);
}

void Heavy_CircleStrings::cBinop_6xqXUZVJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_liJVsEqt, HV_BINOP_MULTIPLY, 1, m, &cBinop_liJVsEqt_sendMessage);
}

void Heavy_CircleStrings::cSend_Qc9ZGDLH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_klp7MXi1_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_XutPNt6L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_eKHsWMTz_sendMessage);
}

void Heavy_CircleStrings::cCast_dyKQ6SQH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_sz59YDvM_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cBinop_6G8lE89h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_eqaPpdVA, 0, m, &cPack_eqaPpdVA_sendMessage);
}

void Heavy_CircleStrings::cSend_qCrOGg4x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_FhxRPYyu_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_GtaqFTpk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_Ub07IFlG_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_MnOSjm2r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 200.0f);
  cSend_GtaqFTpk_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_WjDvaTJZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.999f);
  sVarf_onMessage(_c, &Context(_c)->sVarf_mtrIyW7L, m);
}

void Heavy_CircleStrings::cCast_2dzPUyEO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_0WEaG4ca_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cVar_OPqRhSpX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_KOA9QkIm_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_cwvtdy9o_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_BDkLeWvo_sendMessage);
}

void Heavy_CircleStrings::cIf_ZxVgbyLY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_jMgntqZc_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_6TYkspuO_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cMsg_XmykxTTz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_ZpzaBL1D, HV_BINOP_POW, 0, m, &cBinop_ZpzaBL1D_sendMessage);
}

void Heavy_CircleStrings::cBinop_ZpzaBL1D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_ISjFmIBk, 0, m, &cPack_ISjFmIBk_sendMessage);
}

void Heavy_CircleStrings::cBinop_4orKVL5N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_XYyS4WKQ_sendMessage);
}

void Heavy_CircleStrings::cCast_BDkLeWvo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_ZxVgbyLY, 0, m, &cIf_ZxVgbyLY_sendMessage);
}

void Heavy_CircleStrings::cCast_cwvtdy9o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_18sLn9mG_sendMessage);
}

void Heavy_CircleStrings::cBinop_18sLn9mG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_ZxVgbyLY, 1, m, &cIf_ZxVgbyLY_sendMessage);
}

void Heavy_CircleStrings::cBinop_6TYkspuO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_4orKVL5N_sendMessage);
}

void Heavy_CircleStrings::cMsg_jMgntqZc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_ISjFmIBk, 0, m, &cPack_ISjFmIBk_sendMessage);
}

void Heavy_CircleStrings::cBinop_XYyS4WKQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ZpzaBL1D, HV_BINOP_POW, 1, m, &cBinop_ZpzaBL1D_sendMessage);
  cMsg_XmykxTTz_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cPack_ISjFmIBk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_3OZgPisP, 0, m, NULL);
}

void Heavy_CircleStrings::cVar_r7D7p4AF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_PUXxzWNF_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_KOA9QkIm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSend_cpfqoPtp_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_cpfqoPtp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_feFavkjj_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_PUXxzWNF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_u48u97dr_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cVar_sKSAdDpv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_9upywHl2_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_FSjPC78N_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_LQsMFmA3_sendMessage);
}

void Heavy_CircleStrings::cIf_zBbaa17g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_gdXj5D6a_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_o54uF0SX_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cMsg_H3oeLU5O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_V8DtGmZc, HV_BINOP_POW, 0, m, &cBinop_V8DtGmZc_sendMessage);
}

void Heavy_CircleStrings::cBinop_V8DtGmZc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_tpMHi0Dn, 0, m, &cPack_tpMHi0Dn_sendMessage);
}

void Heavy_CircleStrings::cBinop_yuXyTYVX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_Vbm72RTc_sendMessage);
}

void Heavy_CircleStrings::cCast_LQsMFmA3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_zBbaa17g, 0, m, &cIf_zBbaa17g_sendMessage);
}

void Heavy_CircleStrings::cCast_FSjPC78N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_NoRrYkzs_sendMessage);
}

void Heavy_CircleStrings::cBinop_NoRrYkzs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_zBbaa17g, 1, m, &cIf_zBbaa17g_sendMessage);
}

void Heavy_CircleStrings::cBinop_o54uF0SX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_yuXyTYVX_sendMessage);
}

void Heavy_CircleStrings::cMsg_gdXj5D6a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_tpMHi0Dn, 0, m, &cPack_tpMHi0Dn_sendMessage);
}

void Heavy_CircleStrings::cBinop_Vbm72RTc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_V8DtGmZc, HV_BINOP_POW, 1, m, &cBinop_V8DtGmZc_sendMessage);
  cMsg_H3oeLU5O_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cPack_tpMHi0Dn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_qkpQNjIv, 0, m, NULL);
}

void Heavy_CircleStrings::cVar_gbLAogxP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_B54NQBG4_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_9upywHl2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSend_BrXWhueB_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_BrXWhueB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_VuXin3GN_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_B54NQBG4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_NPT5s9E3_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cVar_oazj6wfs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_tbL9DkM7_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_XDCUiyrY_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_yzIDEy4b_sendMessage);
}

void Heavy_CircleStrings::cIf_EV0eII3u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_nFVtPICv_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_3qXQ400r_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cMsg_FiNXqWaL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_m0N3TVvr, HV_BINOP_POW, 0, m, &cBinop_m0N3TVvr_sendMessage);
}

void Heavy_CircleStrings::cBinop_m0N3TVvr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_KycihIt3, 0, m, &cPack_KycihIt3_sendMessage);
}

void Heavy_CircleStrings::cBinop_0BdSR3sW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_2jOrYwqy_sendMessage);
}

void Heavy_CircleStrings::cCast_yzIDEy4b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_EV0eII3u, 0, m, &cIf_EV0eII3u_sendMessage);
}

void Heavy_CircleStrings::cCast_XDCUiyrY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_eMAgdAbH_sendMessage);
}

void Heavy_CircleStrings::cBinop_eMAgdAbH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_EV0eII3u, 1, m, &cIf_EV0eII3u_sendMessage);
}

void Heavy_CircleStrings::cBinop_3qXQ400r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_0BdSR3sW_sendMessage);
}

void Heavy_CircleStrings::cMsg_nFVtPICv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_KycihIt3, 0, m, &cPack_KycihIt3_sendMessage);
}

void Heavy_CircleStrings::cBinop_2jOrYwqy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_m0N3TVvr, HV_BINOP_POW, 1, m, &cBinop_m0N3TVvr_sendMessage);
  cMsg_FiNXqWaL_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cPack_KycihIt3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_RtwkKZ3Y, 0, m, NULL);
}

void Heavy_CircleStrings::cVar_25P9ZxKG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_XRhWxEDE_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_tbL9DkM7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSend_C29JCw7B_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_C29JCw7B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_CM3u2TM7_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_XRhWxEDE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_K6mrzayL_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cIf_aLLEuGrF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_4j4h4SkG_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_LOG10, m, &cUnop_RYOJiduG_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cUnop_RYOJiduG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_TZpEaGLW_sendMessage);
}

void Heavy_CircleStrings::cCast_q7lznVM8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_aw2jPzvG_sendMessage);
}

void Heavy_CircleStrings::cCast_IdA7HQIN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_aLLEuGrF, 0, m, &cIf_aLLEuGrF_sendMessage);
}

void Heavy_CircleStrings::cMsg_4j4h4SkG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cMsg_KOA9QkIm_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_cwvtdy9o_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_BDkLeWvo_sendMessage);
}

void Heavy_CircleStrings::cBinop_TZpEaGLW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 100.0f, 0, m, &cBinop_UVpIeSxN_sendMessage);
}

void Heavy_CircleStrings::cBinop_UVpIeSxN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_rAx4Dwk1_sendMessage);
}

void Heavy_CircleStrings::cBinop_rAx4Dwk1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_KOA9QkIm_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_cwvtdy9o_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_BDkLeWvo_sendMessage);
}

void Heavy_CircleStrings::cBinop_aw2jPzvG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_aLLEuGrF, 1, m, &cIf_aLLEuGrF_sendMessage);
}

void Heavy_CircleStrings::cBinop_gbcJe8ls_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_q7lznVM8_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_IdA7HQIN_sendMessage);
}

void Heavy_CircleStrings::cBinop_NeiLLNov_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_gbcJe8ls_sendMessage);
}

void Heavy_CircleStrings::cIf_DgqgXyro_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_0ukrVzYi_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_LOG10, m, &cUnop_ZfU8akFL_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cUnop_ZfU8akFL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_kirxY0AL_sendMessage);
}

void Heavy_CircleStrings::cCast_49J5GJLl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_fpSJeJ5B_sendMessage);
}

void Heavy_CircleStrings::cCast_ZHnHKrxb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_DgqgXyro, 0, m, &cIf_DgqgXyro_sendMessage);
}

void Heavy_CircleStrings::cMsg_0ukrVzYi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cMsg_9upywHl2_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_FSjPC78N_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_LQsMFmA3_sendMessage);
}

void Heavy_CircleStrings::cBinop_kirxY0AL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 100.0f, 0, m, &cBinop_wAjiwJWj_sendMessage);
}

void Heavy_CircleStrings::cBinop_wAjiwJWj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_DdMhDttg_sendMessage);
}

void Heavy_CircleStrings::cBinop_DdMhDttg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_9upywHl2_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_FSjPC78N_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_LQsMFmA3_sendMessage);
}

void Heavy_CircleStrings::cBinop_fpSJeJ5B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_DgqgXyro, 1, m, &cIf_DgqgXyro_sendMessage);
}

void Heavy_CircleStrings::cBinop_6kJ7P6BA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_49J5GJLl_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ZHnHKrxb_sendMessage);
}

void Heavy_CircleStrings::cBinop_kSstVz8G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_6kJ7P6BA_sendMessage);
}

void Heavy_CircleStrings::cVar_TINEmFIc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_MoE4kGzo_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_2Ci4NivK_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ZHdhpnAw_sendMessage);
}

void Heavy_CircleStrings::cIf_D5obTfxA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_KFBOcSAi_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_9jEjV0TS_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cMsg_olZSQYZF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_5edb9N8W, HV_BINOP_POW, 0, m, &cBinop_5edb9N8W_sendMessage);
}

void Heavy_CircleStrings::cBinop_5edb9N8W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_FZEOJKIJ, 0, m, &cPack_FZEOJKIJ_sendMessage);
}

void Heavy_CircleStrings::cBinop_QGK09P29_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_7MVUyhBg_sendMessage);
}

void Heavy_CircleStrings::cCast_ZHdhpnAw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_D5obTfxA, 0, m, &cIf_D5obTfxA_sendMessage);
}

void Heavy_CircleStrings::cCast_2Ci4NivK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_vVgoq0sx_sendMessage);
}

void Heavy_CircleStrings::cBinop_vVgoq0sx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_D5obTfxA, 1, m, &cIf_D5obTfxA_sendMessage);
}

void Heavy_CircleStrings::cBinop_9jEjV0TS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_QGK09P29_sendMessage);
}

void Heavy_CircleStrings::cMsg_KFBOcSAi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_FZEOJKIJ, 0, m, &cPack_FZEOJKIJ_sendMessage);
}

void Heavy_CircleStrings::cBinop_7MVUyhBg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_5edb9N8W, HV_BINOP_POW, 1, m, &cBinop_5edb9N8W_sendMessage);
  cMsg_olZSQYZF_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cPack_FZEOJKIJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_cGEIGLun, 0, m, NULL);
}

void Heavy_CircleStrings::cVar_sWwEZrZX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_q9sOALzE_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cMsg_MoE4kGzo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSend_vKqxZM8V_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_vKqxZM8V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_FMhQvKP8_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_q9sOALzE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_NLFpyWGf_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cPack_V098JCdl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_qP4uO1u9, 0, m, &cIf_qP4uO1u9_sendMessage);
}

void Heavy_CircleStrings::cSlice_QIT8Lk6p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_uV6N59rE_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_823L66An_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cSlice_RYrcwGwi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cIf_onMessage(_c, &Context(_c)->cIf_peivcNGa, 0, m, &cIf_peivcNGa_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cIf_peivcNGa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_tHYPlQuW_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_X1oqAZoY_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cIf_AE6tacRy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cPack_onMessage(_c, &Context(_c)->cPack_oIpDJQDh, 2, m, &cPack_oIpDJQDh_sendMessage);
      cPack_onMessage(_c, &Context(_c)->cPack_L8yS86S7, 1, m, &cPack_L8yS86S7_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cIf_mkefamLf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_QIT8Lk6p, 0, m, &cSlice_QIT8Lk6p_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_RYrcwGwi, 0, m, &cSlice_RYrcwGwi_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cSlice_oJRk260f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_vy6rw08Q_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cSlice_vDluaycK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_djTMGiaD_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_biPZZyHV_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_WGrknQus_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cVar_UCvE3Csl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_guMLWwta, 1, m, &cIf_guMLWwta_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_tlxOpMDc_sendMessage);
}

void Heavy_CircleStrings::cIf_guMLWwta_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_QIT8Lk6p, 0, m, &cSlice_QIT8Lk6p_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_RYrcwGwi, 0, m, &cSlice_RYrcwGwi_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cPack_L8yS86S7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_mkefamLf, 0, m, &cIf_mkefamLf_sendMessage);
}

void Heavy_CircleStrings::cBinop_JTlwVGHX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_peivcNGa, 1, m, &cIf_peivcNGa_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_AE6tacRy, 1, m, &cIf_AE6tacRy_sendMessage);
}

void Heavy_CircleStrings::cCast_uV6N59rE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_NEQ, 0.0f, 0, m, &cBinop_JTlwVGHX_sendMessage);
}

void Heavy_CircleStrings::cCast_823L66An_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_AE6tacRy, 0, m, &cIf_AE6tacRy_sendMessage);
}

void Heavy_CircleStrings::cMsg_oCrX8yPd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_UCvE3Csl, 1, m, &cVar_UCvE3Csl_sendMessage);
}

void Heavy_CircleStrings::cMsg_vy6rw08Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_UCvE3Csl, 1, m, &cVar_UCvE3Csl_sendMessage);
}

void Heavy_CircleStrings::cCast_biPZZyHV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_L8yS86S7, 0, m, &cPack_L8yS86S7_sendMessage);
}

void Heavy_CircleStrings::cCast_djTMGiaD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_UCvE3Csl, 0, m, &cVar_UCvE3Csl_sendMessage);
}

void Heavy_CircleStrings::cCast_WGrknQus_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_oCrX8yPd_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cBinop_tlxOpMDc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_mkefamLf, 1, m, &cIf_mkefamLf_sendMessage);
}

void Heavy_CircleStrings::cSwitchcase_0ychEGtr_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_wLgIS9sg, 0, m, &cSlice_wLgIS9sg_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_ixwizXQT, 0, m, &cSlice_ixwizXQT_sendMessage);
      break;
    }
    case 0x40000000: { // "2.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_vjPCy1JW, 0, m, &cSlice_vjPCy1JW_sendMessage);
      break;
    }
    case 0x40400000: { // "3.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_3VAIpURy, 0, m, &cSlice_3VAIpURy_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_CircleStrings::cSlice_wLgIS9sg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_cxB7DDzC, 0, m, &cSlice_cxB7DDzC_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_Dp1N1jdC, 0, m, &cSlice_Dp1N1jdC_sendMessage);
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_cxB7DDzC, 0, m, &cSlice_cxB7DDzC_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_Dp1N1jdC, 0, m, &cSlice_Dp1N1jdC_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cSlice_ixwizXQT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_aDh3KdBV, 0, m, &cSlice_aDh3KdBV_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_5ZO90l66, 0, m, &cSlice_5ZO90l66_sendMessage);
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_aDh3KdBV, 0, m, &cSlice_aDh3KdBV_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_5ZO90l66, 0, m, &cSlice_5ZO90l66_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cSlice_vjPCy1JW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_5PgzWz1k, 0, m, &cSlice_5PgzWz1k_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_AHkpNVRV, 0, m, &cSlice_AHkpNVRV_sendMessage);
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_5PgzWz1k, 0, m, &cSlice_5PgzWz1k_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_AHkpNVRV, 0, m, &cSlice_AHkpNVRV_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cSlice_3VAIpURy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_bMO4J7Eo, 0, m, &cSlice_bMO4J7Eo_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_zWJwkxZA, 0, m, &cSlice_zWJwkxZA_sendMessage);
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_bMO4J7Eo, 0, m, &cSlice_bMO4J7Eo_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_zWJwkxZA, 0, m, &cSlice_zWJwkxZA_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cSwitchcase_9BvUL1KB_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_HfkF99D1_sendMessage);
      break;
    }
    default: {
      cMsg_EfEDbGdY_sendMessage(_c, 0, m);
      break;
    }
  }
}

void Heavy_CircleStrings::cCast_HfkF99D1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_RmbSwGC4_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cIf_qP4uO1u9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_oJRk260f, 0, m, &cSlice_oJRk260f_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_vDluaycK, 0, m, &cSlice_vDluaycK_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_guMLWwta, 0, m, &cIf_guMLWwta_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_CircleStrings::cVar_rDY4O9VY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_Wmj1yvsb_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_qP4uO1u9, 1, m, &cIf_qP4uO1u9_sendMessage);
}

void Heavy_CircleStrings::cBinop_Wmj1yvsb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_rDY4O9VY, 1, m, &cVar_rDY4O9VY_sendMessage);
}

void Heavy_CircleStrings::cMsg_RmbSwGC4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_rDY4O9VY, 0, m, &cVar_rDY4O9VY_sendMessage);
}

void Heavy_CircleStrings::cMsg_EfEDbGdY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_rDY4O9VY, 0, m, &cVar_rDY4O9VY_sendMessage);
}

void Heavy_CircleStrings::cPack_oIpDJQDh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_0ychEGtr_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cVar_w2NUvcoh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_oIpDJQDh, 0, m, &cPack_oIpDJQDh_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_LX9ZXMxw_sendMessage);
}

void Heavy_CircleStrings::cBinop_LX9ZXMxw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MOD_BIPOLAR, 4.0f, 0, m, &cBinop_VVXwPTo8_sendMessage);
}

void Heavy_CircleStrings::cBinop_VVXwPTo8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_w2NUvcoh, 1, m, &cVar_w2NUvcoh_sendMessage);
}

void Heavy_CircleStrings::cMsg_2N4JYl9A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_9BvUL1KB_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cCast_X1oqAZoY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_w2NUvcoh, 0, m, &cVar_w2NUvcoh_sendMessage);
}

void Heavy_CircleStrings::cCast_tHYPlQuW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_oIpDJQDh, 1, m, &cPack_oIpDJQDh_sendMessage);
}

void Heavy_CircleStrings::cSend_7dcVOQfI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_46kiA3qm_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_FsDLJ4TL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_SHnLV9E2_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_sLF3QqtO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cBinop_vGtEnYxj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_liNoDReR_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cSend_liNoDReR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_ChG0pS8g_sendMessage(_c, 0, m);
}

void Heavy_CircleStrings::cCast_Kbgcark8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_3Z9z43vB_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_CircleStrings::cReceive_tZrykMO0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_szfEii68_sendMessage(_c, 0, m);
  cMsg_JRlypzck_sendMessage(_c, 0, m);
  cMsg_bFAPUi6K_sendMessage(_c, 0, m);
  cMsg_gRHZTs9a_sendMessage(_c, 0, m);
  cMsg_2Reyfg5I_sendMessage(_c, 0, m);
  cMsg_Nz7ozaPz_sendMessage(_c, 0, m);
  cMsg_9ojwDwH0_sendMessage(_c, 0, m);
  cMsg_Dy7lO5lU_sendMessage(_c, 0, m);
  cMsg_sBLO9kCh_sendMessage(_c, 0, m);
  cMsg_zbddsGqf_sendMessage(_c, 0, m);
  cMsg_761ANgX5_sendMessage(_c, 0, m);
  cMsg_RwSeDKMn_sendMessage(_c, 0, m);
  cMsg_e1JlqWjd_sendMessage(_c, 0, m);
  cMsg_DMwIWsTx_sendMessage(_c, 0, m);
  cMsg_oD9IrDz5_sendMessage(_c, 0, m);
  cMsg_Y9CJUGqU_sendMessage(_c, 0, m);
  cMsg_LTEO30mm_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_8LJGdBjr, 0, m, &cVar_8LJGdBjr_sendMessage);
  cMsg_O8J4G3FE_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_FQQ2DcxT, 0, m, &cVar_FQQ2DcxT_sendMessage);
  cMsg_gLngQSRE_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_Km7aDGyB, 0, m, &cVar_Km7aDGyB_sendMessage);
  cMsg_SHPJNAdC_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_OOEpDFt5, 0, m, &cVar_OOEpDFt5_sendMessage);
  cMsg_h7v6CSpR_sendMessage(_c, 0, m);
  cMsg_IRatPKQU_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_tC1ETIrK, 0, m, &cVar_tC1ETIrK_sendMessage);
  cMsg_NeUouPo9_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_pNJnok0N, 0, m, &cVar_pNJnok0N_sendMessage);
  cMsg_Mh7fs2fl_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_1DOFW6CV, 0, m, &cVar_1DOFW6CV_sendMessage);
  cMsg_EHKdOBIZ_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_qwQ7Na3d, 0, m, &cVar_qwQ7Na3d_sendMessage);
  cMsg_R31Sr1kK_sendMessage(_c, 0, m);
  cMsg_UyAk7c0B_sendMessage(_c, 0, m);
  cMsg_zNpjy91C_sendMessage(_c, 0, m);
  cMsg_zyp2k7BZ_sendMessage(_c, 0, m);
  cMsg_iv0xrKXo_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_74RnRCDV, 0, m, &cVar_74RnRCDV_sendMessage);
  cMsg_uzkKcGEb_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_ZcCqvYFc, 0, m, &cVar_ZcCqvYFc_sendMessage);
  cMsg_nHZorksF_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_ulNJrwP1, 0, m, &cVar_ulNJrwP1_sendMessage);
  cMsg_a3nnS5xU_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_kCPY6E1j, 0, m, &cVar_kCPY6E1j_sendMessage);
  cMsg_kMb8lKdl_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_Pr4kJt9x, 0, m, &cVar_Pr4kJt9x_sendMessage);
  cMsg_n25CeRfX_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_gNYN7LI5, 0, m, &cVar_gNYN7LI5_sendMessage);
  cMsg_5IHmfa9u_sendMessage(_c, 0, m);
  cMsg_70kPl2Zd_sendMessage(_c, 0, m);
  cMsg_uHHkqg2S_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_hIOCEH11, 0, m, &cVar_hIOCEH11_sendMessage);
  cMsg_sxPI51H4_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_OSAzhwCX, 0, m, &cVar_OSAzhwCX_sendMessage);
  cMsg_te0tlirW_sendMessage(_c, 0, m);
  cMsg_1zEJmngq_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_iG6Q9AMR, 0, m, &cVar_iG6Q9AMR_sendMessage);
  cMsg_xiuWqnl1_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_05zfhTHZ, 0, m, &cVar_05zfhTHZ_sendMessage);
  cSwitchcase_fje2xgmB_onMessage(_c, NULL, 0, m, NULL);
  cMsg_AMqc2L1c_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_MsuxkGXm, 0, m, &cVar_MsuxkGXm_sendMessage);
  cMsg_48tkRfeN_sendMessage(_c, 0, m);
  cSwitchcase_OHlzQIyh_onMessage(_c, NULL, 0, m, NULL);
  cMsg_Wn9GvRuS_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_n7fikkrY, 0, m, &cVar_n7fikkrY_sendMessage);
  cMsg_POtkarPb_sendMessage(_c, 0, m);
  cSwitchcase_dJHDR6vO_onMessage(_c, NULL, 0, m, NULL);
  cMsg_kfSltSgA_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_qfnM3aRI, 0, m, &cVar_qfnM3aRI_sendMessage);
  cMsg_zRmbzlnP_sendMessage(_c, 0, m);
  cSwitchcase_JS7AOFlo_onMessage(_c, NULL, 0, m, NULL);
  cMsg_FykzmL5g_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_DFDFpVaI, 0, m, &cVar_DFDFpVaI_sendMessage);
  cMsg_aEj0GFx6_sendMessage(_c, 0, m);
  cSwitchcase_73ZwiGwe_onMessage(_c, NULL, 0, m, NULL);
  cMsg_uCMQDqDS_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_mT0RV9wd, 0, m, &cVar_mT0RV9wd_sendMessage);
  cMsg_9J5DyhTT_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_UsY1wa68, 0, m, &cVar_UsY1wa68_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_Tn0F1Q3X, 0, m, &cVar_Tn0F1Q3X_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_wiXZaPgr, 0, m, &cVar_wiXZaPgr_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_8iahlenK, 0, m, &cVar_8iahlenK_sendMessage);
  cMsg_FDzWpQbU_sendMessage(_c, 0, m);
  cMsg_SoxSW8qA_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_mn5VjOIv, 0, m, &cVar_mn5VjOIv_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_qFiQRHjD, 0, m, &cVar_qFiQRHjD_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_ysfqpLHP, 0, m, &cVar_ysfqpLHP_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_wHlfSVwo, 0, m, &cVar_wHlfSVwo_sendMessage);
  cMsg_b4IFSR5L_sendMessage(_c, 0, m);
  cMsg_LahMcEml_sendMessage(_c, 0, m);
  cMsg_TmORWmC7_sendMessage(_c, 0, m);
  cMsg_zKRcXJP1_sendMessage(_c, 0, m);
  cMsg_xem8TcTJ_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_5dmjvb45, 0, m, &cVar_5dmjvb45_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_djXXQNug, 0, m, &cVar_djXXQNug_sendMessage);
  cMsg_pwvESEQD_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_eTOirtGv, 0, m, &cVar_eTOirtGv_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_q6orzG1H, 0, m, &cVar_q6orzG1H_sendMessage);
  cMsg_TGtdDtXv_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_87DbvT2A, 0, m, &cVar_87DbvT2A_sendMessage);
  cMsg_C0HhVjWw_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_LBrR9mOt, 0, m, &cVar_LBrR9mOt_sendMessage);
  cMsg_z82OXGb5_sendMessage(_c, 0, m);
  cMsg_NyQnRE8B_sendMessage(_c, 0, m);
  cMsg_3tkz51Zx_sendMessage(_c, 0, m);
  cMsg_dtiZeF1n_sendMessage(_c, 0, m);
  cMsg_rZ0gWIuy_sendMessage(_c, 0, m);
  cMsg_VcRDWbuy_sendMessage(_c, 0, m);
  cMsg_gIwHmAQp_sendMessage(_c, 0, m);
  cMsg_hXYYiybc_sendMessage(_c, 0, m);
  cMsg_E8auMZAT_sendMessage(_c, 0, m);
  cMsg_7dhQr2nz_sendMessage(_c, 0, m);
  cMsg_98EefR56_sendMessage(_c, 0, m);
  cMsg_tp2FfUz5_sendMessage(_c, 0, m);
  cMsg_wHQyZ5nd_sendMessage(_c, 0, m);
  cMsg_cnnZzlMn_sendMessage(_c, 0, m);
  cMsg_14PwjGEE_sendMessage(_c, 0, m);
  cMsg_06LbI1wq_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_ZDzcTu3w, 0, m, &cVar_ZDzcTu3w_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_427lAlvE, 0, m, &cVar_427lAlvE_sendMessage);
  cMsg_CKPR4RaG_sendMessage(_c, 0, m);
  cMsg_MS9tzzCB_sendMessage(_c, 0, m);
  cMsg_H0DkXdQA_sendMessage(_c, 0, m);
  cMsg_Xf42bRzl_sendMessage(_c, 0, m);
  cMsg_h8OXHvA3_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_uqsLIPqF, 0, m, &cVar_uqsLIPqF_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_hpHZHG8w, 0, m, &cVar_hpHZHG8w_sendMessage);
  cMsg_UM7Omoc2_sendMessage(_c, 0, m);
  cMsg_7rsDM7UX_sendMessage(_c, 0, m);
  cMsg_3kQjt736_sendMessage(_c, 0, m);
  cMsg_GCCZGxXP_sendMessage(_c, 0, m);
  cMsg_MnOSjm2r_sendMessage(_c, 0, m);
  cMsg_WjDvaTJZ_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_OPqRhSpX, 0, m, &cVar_OPqRhSpX_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_sKSAdDpv, 0, m, &cVar_sKSAdDpv_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_oazj6wfs, 0, m, &cVar_oazj6wfs_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_TINEmFIc, 0, m, &cVar_TINEmFIc_sendMessage);
  cMsg_2N4JYl9A_sendMessage(_c, 0, m);
  cSwitchcase_3Z9z43vB_onMessage(_c, NULL, 0, m, NULL);
  cMsg_5loY0EWF_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_wV0HlpNw, 0, m, &cVar_wV0HlpNw_sendMessage);
  cMsg_9GROLOom_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_bFxfaTiX, 0, m, &cTabhead_bFxfaTiX_sendMessage);
  cMsg_xPy2DfeL_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_OvLKxvPA, 0, m, &cVar_OvLKxvPA_sendMessage);
  cMsg_UMXCdHdB_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_MdMvcFss, 0, m, &cTabhead_MdMvcFss_sendMessage);
  cMsg_ce2NNiCW_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_4PwUZG4n, 0, m, &cVar_4PwUZG4n_sendMessage);
  cMsg_eWfVUjRN_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_VrnFMHJK, 0, m, &cTabhead_VrnFMHJK_sendMessage);
  cMsg_z4Hl6qWZ_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_iIKIVMKO, 0, m, &cVar_iIKIVMKO_sendMessage);
  cMsg_wzKLj8n8_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_WraOhQ2g, 0, m, &cTabhead_WraOhQ2g_sendMessage);
  cMsg_2Kqpe1pH_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_7L2XjG1F, 0, m, &cVar_7L2XjG1F_sendMessage);
  cMsg_4E6u3FyK_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_8gY1XbVk, 0, m, &cTabhead_8gY1XbVk_sendMessage);
  cMsg_5ARccrPy_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_dlHrsWtW, 0, m, &cVar_dlHrsWtW_sendMessage);
  cMsg_Xhm1uhYx_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_DXWbipj5, 0, m, &cTabhead_DXWbipj5_sendMessage);
  cMsg_qcyPwM0K_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_zPUihtmJ, 0, m, &cVar_zPUihtmJ_sendMessage);
  cMsg_tyQI5Imy_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_hQym7h4O, 0, m, &cTabhead_hQym7h4O_sendMessage);
  cMsg_MATDoC6i_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_HS0sEN5a, 0, m, &cVar_HS0sEN5a_sendMessage);
  cMsg_JhT288bn_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_IjB0ZulE, 0, m, &cTabhead_IjB0ZulE_sendMessage);
  cMsg_SHpJjJBD_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_qTN8XMKJ, 0, m, &cVar_qTN8XMKJ_sendMessage);
  cMsg_H19Srgy0_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_04PPr6iL, 0, m, &cTabhead_04PPr6iL_sendMessage);
  cMsg_QL7pCvZy_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_yvp5oFHT, 0, m, &cVar_yvp5oFHT_sendMessage);
  cMsg_nlrjnf74_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_EK6hcK0H, 0, m, &cTabhead_EK6hcK0H_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_EhN78tzK, 0, m, &cVar_EhN78tzK_sendMessage);
  cMsg_kRt9htYD_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_9iyxHJcb, 0, m, &cVar_9iyxHJcb_sendMessage);
  cMsg_9nSh7ePs_sendMessage(_c, 0, m);
  cMsg_AfPt3QDJ_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_32wrEBxC, 0, m, &cVar_32wrEBxC_sendMessage);
  cMsg_17mUytTt_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_BhCdQpx4, 0, m, &cTabhead_BhCdQpx4_sendMessage);
  cMsg_cUFQkDAi_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_D4i1hYXb, 0, m, &cVar_D4i1hYXb_sendMessage);
  cMsg_wVqJ27qo_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_vWjX6wtf, 0, m, &cTabhead_vWjX6wtf_sendMessage);
  cMsg_1vtIP7lB_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_BDVggPgY, 0, m, &cVar_BDVggPgY_sendMessage);
  cMsg_OCpWLuTQ_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_MX3InhKt, 0, m, &cTabhead_MX3InhKt_sendMessage);
  cMsg_hiRmTKpG_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_ZK9JIqoN, 0, m, &cVar_ZK9JIqoN_sendMessage);
  cMsg_8O6Dr7Qo_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_BMpi2f4B, 0, m, &cTabhead_BMpi2f4B_sendMessage);
  cMsg_Wj0dMM2A_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_rdfC08lm, 0, m, &cVar_rdfC08lm_sendMessage);
  cMsg_k5WA9nVe_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_w2T4YJ1q, 0, m, &cTabhead_w2T4YJ1q_sendMessage);
  cMsg_mOxyfHI4_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_neczr5hd, 0, m, &cVar_neczr5hd_sendMessage);
  cMsg_UTv39Lhu_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_iMMGmHQl, 0, m, &cTabhead_iMMGmHQl_sendMessage);
  cMsg_NN5DDkeJ_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_GuOl5wKF, 0, m, &cVar_GuOl5wKF_sendMessage);
  cMsg_n1M2IJBQ_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_KtH8ozvz, 0, m, &cTabhead_KtH8ozvz_sendMessage);
  cMsg_M57SglBd_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_BN0zJU9V, 0, m, &cVar_BN0zJU9V_sendMessage);
  cMsg_0WJWlYKo_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_nh1v6TXI, 0, m, &cTabhead_nh1v6TXI_sendMessage);
  cMsg_GX9W5YTl_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_gjDOvGBK, 0, m, &cVar_gjDOvGBK_sendMessage);
  cMsg_LbK4uXZ3_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_m3DF7heY, 0, m, &cTabhead_m3DF7heY_sendMessage);
  cMsg_pLWvNmkn_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_XC5Lpguv, 0, m, &cVar_XC5Lpguv_sendMessage);
  cMsg_yJGaigD9_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_eKzW24RL, 0, m, &cTabhead_eKzW24RL_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_e7Wnw651, 0, m, &cVar_e7Wnw651_sendMessage);
  cMsg_RE3sI7DQ_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_rE5M39Qj, 0, m, &cVar_rE5M39Qj_sendMessage);
  cMsg_Hhvp9rP5_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_L9otMwf8, 0, m, &cVar_L9otMwf8_sendMessage);
  cMsg_OlBaV9B6_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_LhGF5E3Z, 0, m, &cVar_LhGF5E3Z_sendMessage);
  cMsg_zVSdTfGr_sendMessage(_c, 0, m);
  cMsg_XFhSsGYw_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_9GVghihj, 0, m, &cVar_9GVghihj_sendMessage);
  cMsg_5tq3nCyg_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_rOuB54cf, 0, m, &cTabhead_rOuB54cf_sendMessage);
  cMsg_YByQXBzt_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_3CKWKr6R, 0, m, &cVar_3CKWKr6R_sendMessage);
  cMsg_SUAqrnb9_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_hTm3mJ9u, 0, m, &cTabhead_hTm3mJ9u_sendMessage);
  cMsg_HLyecE7Z_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_8dVjwqxB, 0, m, &cVar_8dVjwqxB_sendMessage);
  cMsg_H5RNN6NQ_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_wuoBFLpF, 0, m, &cTabhead_wuoBFLpF_sendMessage);
  cMsg_G0NI423s_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_Ae9LXAyP, 0, m, &cVar_Ae9LXAyP_sendMessage);
  cMsg_hVbl5kAh_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_nD8rYepw, 0, m, &cTabhead_nD8rYepw_sendMessage);
  cMsg_eD9Ow2eh_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_9keS29QT, 0, m, &cVar_9keS29QT_sendMessage);
  cMsg_3zKAN5uv_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_BfQ99xL1, 0, m, &cTabhead_BfQ99xL1_sendMessage);
}

void Heavy_CircleStrings::cReceive_HfIlgq1D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSlice_onMessage(_c, &Context(_c)->cSlice_WHLC3370, 0, m, &cSlice_WHLC3370_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_cSd8zlmu, 0, m, &cSlice_cSd8zlmu_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_OcDc4dL4, 0, m, &cSlice_OcDc4dL4_sendMessage);
}

void Heavy_CircleStrings::cReceive_46kiA3qm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_V098JCdl, 0, m, &cPack_V098JCdl_sendMessage);
}

void Heavy_CircleStrings::cReceive_SHnLV9E2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_V098JCdl, 1, m, &cPack_V098JCdl_sendMessage);
}

void Heavy_CircleStrings::cReceive_rhMuCMt4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 2.0f, 0, m, &cBinop_AUjjzC2t_sendMessage);
}

void Heavy_CircleStrings::cReceive_61PVQMSs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_V7jZHueA_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_raLvftWU_sendMessage);
}

void Heavy_CircleStrings::cReceive_V3Ch0YsM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_DxR0Euwn_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_HgAbB6lI_sendMessage);
  cPack_onMessage(_c, &Context(_c)->cPack_UMl2RfDo, 0, m, &cPack_UMl2RfDo_sendMessage);
}

void Heavy_CircleStrings::cReceive_RpWWRCwt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_C1rCRU9a_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_LijsdTxW, 0, m, &cIf_LijsdTxW_sendMessage);
}

void Heavy_CircleStrings::cReceive_b3mkhP8y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_8zNrYrmx, 1, m, &cVar_8zNrYrmx_sendMessage);
}

void Heavy_CircleStrings::cReceive_pXdL8bTu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_YiuOaEHl, 0, m, &cVar_YiuOaEHl_sendMessage);
  cPack_onMessage(_c, &Context(_c)->cPack_tVAZy8DP, 0, m, &cPack_tVAZy8DP_sendMessage);
}

void Heavy_CircleStrings::cReceive_jQPTW08B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 100.0f, 0, m, &cBinop_bNkY8eq0_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_4dlTqBLB_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_748loJLv, 0, m, &cIf_748loJLv_sendMessage);
}

void Heavy_CircleStrings::cReceive_0B4HNIal_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_CircleStrings::cReceive_QinxAnpD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_M0pkJX55_sendMessage);
}

void Heavy_CircleStrings::cReceive_DXbynMog_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Kbgcark8_sendMessage);
}

void Heavy_CircleStrings::cReceive_ChG0pS8g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_r7CZbbdC, 0, m, &cVar_r7CZbbdC_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_DUACWizl, 0, m, &cVar_DUACWizl_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_bdRnAwRu, 0, m, &cVar_bdRnAwRu_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_IsFN3WHs, 0, m, &cVar_IsFN3WHs_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_6NqkvLpn_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_aKFKiW3J, 0, m, &cIf_aKFKiW3J_sendMessage);
}

void Heavy_CircleStrings::cReceive_vtoDkdrb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_K8PfbEk2_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_9uqHUoqy, 0, m, &cVar_9uqHUoqy_sendMessage);
}

void Heavy_CircleStrings::cReceive_7ihRb34k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_96rLYEgW, 0, m, &cPack_96rLYEgW_sendMessage);
}

void Heavy_CircleStrings::cReceive_Q8TGUP0C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_DrrnP6n6, 1, m, &cVar_DrrnP6n6_sendMessage);
}

void Heavy_CircleStrings::cReceive_RVXwoU7w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_mF4KqpcY, m);
}

void Heavy_CircleStrings::cReceive_3CsrTNVs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_Us4MSLxG_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_41KPvXEI, 0, m, &cVar_41KPvXEI_sendMessage);
}

void Heavy_CircleStrings::cReceive_K0aMEN3J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_3c8HK6GC_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_kPdyvOZq, 0, m, &cVar_kPdyvOZq_sendMessage);
}

void Heavy_CircleStrings::cReceive_OkaclTJY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_9UniTBM9, 0, m, &cVar_9UniTBM9_sendMessage);
}

void Heavy_CircleStrings::cReceive_viock29s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Iz8lpQLg_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_flgHG1DO_sendMessage);
}

void Heavy_CircleStrings::cReceive_xWa6HxGE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_OQeJwARA, 0, m, &cVar_OQeJwARA_sendMessage);
}

void Heavy_CircleStrings::cReceive_EX63h6Sm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_X7JRvs8f_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_r4Q2ar95_sendMessage);
}

void Heavy_CircleStrings::cReceive_byLS6igX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_U2PnmPiO_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_P4ruzqrw, 0, m, &cVar_P4ruzqrw_sendMessage);
}

void Heavy_CircleStrings::cReceive_xedTPFFX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_B3Kat4VK, 0, m, &cPack_B3Kat4VK_sendMessage);
}

void Heavy_CircleStrings::cReceive_2Dyirtxb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_qFc7csLF, 1, m, &cVar_qFc7csLF_sendMessage);
}

void Heavy_CircleStrings::cReceive_Jri6FEKs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_F9eR8esI, m);
}

void Heavy_CircleStrings::cReceive_hkwTEt4T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_wShhJwAm_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_X7cuYeYA, 0, m, &cVar_X7cuYeYA_sendMessage);
}

void Heavy_CircleStrings::cReceive_CMr3LFZ9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_lc9m05wa_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_zrlvFyeW, 0, m, &cVar_zrlvFyeW_sendMessage);
}

void Heavy_CircleStrings::cReceive_jpyWujMt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_vkELbSXe_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_rKYyfb7b, 0, m, &cVar_rKYyfb7b_sendMessage);
}

void Heavy_CircleStrings::cReceive_r0FPSQXF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_l4iZ1JLD, 0, m, &cPack_l4iZ1JLD_sendMessage);
}

void Heavy_CircleStrings::cReceive_Ewr7zMGz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_9aYgMeAL, 1, m, &cVar_9aYgMeAL_sendMessage);
}

void Heavy_CircleStrings::cReceive_Y81Wizul_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_QuL4tlXA, m);
}

void Heavy_CircleStrings::cReceive_XcXwLiDi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_rtcEI2OT_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_RAIf5TS8, 0, m, &cVar_RAIf5TS8_sendMessage);
}

void Heavy_CircleStrings::cReceive_aPKrVrEs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_otA1S4rx_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_btJuTAN1, 0, m, &cVar_btJuTAN1_sendMessage);
}

void Heavy_CircleStrings::cReceive_klp7MXi1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_sf3mSnxf_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_9H3xucx5, 0, m, &cVar_9H3xucx5_sendMessage);
}

void Heavy_CircleStrings::cReceive_FhxRPYyu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_eqaPpdVA, 0, m, &cPack_eqaPpdVA_sendMessage);
}

void Heavy_CircleStrings::cReceive_oS5paxUB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_HFc0rQEf, 1, m, &cVar_HFc0rQEf_sendMessage);
}

void Heavy_CircleStrings::cReceive_7c0Toumm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_7RfjPVWo, m);
}

void Heavy_CircleStrings::cReceive_RexepgLO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_VSMG5NMK_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_l3yfjaJm, 0, m, &cVar_l3yfjaJm_sendMessage);
}

void Heavy_CircleStrings::cReceive_Ub07IFlG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_im54KyY8_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_mpoZnz5U, 0, m, &cVar_mpoZnz5U_sendMessage);
}

void Heavy_CircleStrings::cReceive_feFavkjj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_r7D7p4AF, 0, m, &cVar_r7D7p4AF_sendMessage);
}

void Heavy_CircleStrings::cReceive_u48u97dr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_cwvtdy9o_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_BDkLeWvo_sendMessage);
}

void Heavy_CircleStrings::cReceive_90GNHSya_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 2.0f, 0, m, &cBinop_NeiLLNov_sendMessage);
}

void Heavy_CircleStrings::cReceive_VuXin3GN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_gbLAogxP, 0, m, &cVar_gbLAogxP_sendMessage);
}

void Heavy_CircleStrings::cReceive_NPT5s9E3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_FSjPC78N_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_LQsMFmA3_sendMessage);
}

void Heavy_CircleStrings::cReceive_cJuiuTEb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 2.0f, 0, m, &cBinop_kSstVz8G_sendMessage);
}

void Heavy_CircleStrings::cReceive_CM3u2TM7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_25P9ZxKG, 0, m, &cVar_25P9ZxKG_sendMessage);
}

void Heavy_CircleStrings::cReceive_K6mrzayL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_XDCUiyrY_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_yzIDEy4b_sendMessage);
}

void Heavy_CircleStrings::cReceive_FMhQvKP8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_sWwEZrZX, 0, m, &cVar_sWwEZrZX_sendMessage);
}

void Heavy_CircleStrings::cReceive_NLFpyWGf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_2Ci4NivK_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ZHdhpnAw_sendMessage);
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
    __hv_tabread_f(&sTabread_Zg8sDcKY, VOf(Bf0));
    __hv_varread_f(&sVarf_viUoN3mQ, VOf(Bf1));
    __hv_mul_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_XDfieX4W, VOf(Bf0));
    __hv_rpole_f(&sRPole_mGrNxlqr, VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_ntdg74Xc, VOf(Bf1));
    __hv_mul_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_line_f(&sLine_Hbf64OgS, VOf(Bf0));
    __hv_varread_i(&sVari_nS0e1uCy, VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 16807, 16807, 16807, 16807, 16807, 16807, 16807, 16807);
    __hv_mul_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_cast_if(VIi(Bi1), VOf(Bf2));
    __hv_var_k_f(VOf(Bf3), 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f);
    __hv_mul_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_varwrite_i(&sVari_nS0e1uCy, VIi(Bi1));
    __hv_fma_f(VIf(Bf0), VIf(Bf3), VIf(Bf1), VOf(Bf3));
    __hv_tabwrite_f(&sTabwrite_6JpljZfs, VIf(Bf3));
    __hv_line_f(&sLine_LWWCwcju, VOf(Bf3));
    __hv_varread_f(&sVarf_mF4KqpcY, VOf(Bf0));
    __hv_mul_f(VIf(Bf3), VIf(Bf0), VOf(Bf0));
    __hv_mul_f(VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_line_f(&sLine_E22viBkU, VOf(Bf1));
    __hv_mul_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_line_f(&sLine_BCylCxST, VOf(Bf3));
    __hv_mul_f(VIf(Bf0), VIf(Bf3), VOf(Bf3));
    __hv_phasor_k_f(&sPhasor_U4Qsnyii, VOf(Bf0));
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
    __hv_line_f(&sLine_OKfHXmaS, VOf(Bf2));
    __hv_tabread_f(&sTabread_68eizEgF, VOf(Bf2));
    __hv_varread_f(&sVarf_gbKxd1Qy, VOf(Bf5));
    __hv_mul_f(VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_YL39BZG2, VOf(Bf2));
    __hv_rpole_f(&sRPole_RHysYMoR, VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_g8p8Mjcd, VOf(Bf5));
    __hv_mul_f(VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_line_f(&sLine_RcOn8tR1, VOf(Bf2));
    __hv_varread_i(&sVari_MHW0ClgY, VOi(Bi1));
    __hv_var_k_i(VOi(Bi0), 16807, 16807, 16807, 16807, 16807, 16807, 16807, 16807);
    __hv_mul_i(VIi(Bi1), VIi(Bi0), VOi(Bi0));
    __hv_cast_if(VIi(Bi0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf6), 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f);
    __hv_mul_f(VIf(Bf0), VIf(Bf6), VOf(Bf6));
    __hv_varwrite_i(&sVari_MHW0ClgY, VIi(Bi0));
    __hv_fma_f(VIf(Bf2), VIf(Bf6), VIf(Bf5), VOf(Bf6));
    __hv_tabwrite_f(&sTabwrite_I9x9JcTu, VIf(Bf6));
    __hv_line_f(&sLine_ZATZCSqw, VOf(Bf6));
    __hv_varread_f(&sVarf_F9eR8esI, VOf(Bf2));
    __hv_mul_f(VIf(Bf6), VIf(Bf2), VOf(Bf2));
    __hv_mul_f(VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_line_f(&sLine_CFJMbUzK, VOf(Bf5));
    __hv_mul_f(VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_line_f(&sLine_RYeyrni5, VOf(Bf6));
    __hv_mul_f(VIf(Bf2), VIf(Bf6), VOf(Bf6));
    __hv_phasor_k_f(&sPhasor_TnAQtKCp, VOf(Bf2));
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
    __hv_line_f(&sLine_A9nxHXLL, VOf(Bf0));
    __hv_add_f(VIf(Bf1), VIf(Bf5), VOf(Bf5));
    __hv_tabread_f(&sTabread_yHs0GT09, VOf(Bf1));
    __hv_varread_f(&sVarf_dBxXmxi8, VOf(Bf0));
    __hv_mul_f(VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_Zzsa36Pg, VOf(Bf1));
    __hv_rpole_f(&sRPole_nY8Dm5cA, VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_t4D28GUq, VOf(Bf0));
    __hv_mul_f(VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_line_f(&sLine_6k24F53H, VOf(Bf1));
    __hv_varread_i(&sVari_yElZGC0h, VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 16807, 16807, 16807, 16807, 16807, 16807, 16807, 16807);
    __hv_mul_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_cast_if(VIi(Bi1), VOf(Bf7));
    __hv_var_k_f(VOf(Bf2), 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f);
    __hv_mul_f(VIf(Bf7), VIf(Bf2), VOf(Bf2));
    __hv_varwrite_i(&sVari_yElZGC0h, VIi(Bi1));
    __hv_fma_f(VIf(Bf1), VIf(Bf2), VIf(Bf0), VOf(Bf2));
    __hv_tabwrite_f(&sTabwrite_o5PUcACM, VIf(Bf2));
    __hv_line_f(&sLine_rnfc601c, VOf(Bf2));
    __hv_varread_f(&sVarf_QuL4tlXA, VOf(Bf1));
    __hv_mul_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_mul_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_line_f(&sLine_CLdEiIdZ, VOf(Bf0));
    __hv_mul_f(VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_line_f(&sLine_OoVkWdWH, VOf(Bf2));
    __hv_mul_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_phasor_k_f(&sPhasor_fNoS14U3, VOf(Bf1));
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
    __hv_line_f(&sLine_whQbWXMV, VOf(Bf7));
    __hv_add_f(VIf(Bf5), VIf(Bf0), VOf(Bf0));
    __hv_tabread_f(&sTabread_qmKzqtG1, VOf(Bf5));
    __hv_varread_f(&sVarf_1lKsZJBG, VOf(Bf7));
    __hv_mul_f(VIf(Bf5), VIf(Bf7), VOf(Bf7));
    __hv_varread_f(&sVarf_AFW9daME, VOf(Bf5));
    __hv_rpole_f(&sRPole_b8Ae99gM, VIf(Bf7), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_mtrIyW7L, VOf(Bf7));
    __hv_mul_f(VIf(Bf5), VIf(Bf7), VOf(Bf7));
    __hv_line_f(&sLine_Uwdduvwe, VOf(Bf5));
    __hv_varread_i(&sVari_9nW8mwS9, VOi(Bi1));
    __hv_var_k_i(VOi(Bi0), 16807, 16807, 16807, 16807, 16807, 16807, 16807, 16807);
    __hv_mul_i(VIi(Bi1), VIi(Bi0), VOi(Bi0));
    __hv_cast_if(VIi(Bi0), VOf(Bf4));
    __hv_var_k_f(VOf(Bf1), 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f);
    __hv_mul_f(VIf(Bf4), VIf(Bf1), VOf(Bf1));
    __hv_varwrite_i(&sVari_9nW8mwS9, VIi(Bi0));
    __hv_fma_f(VIf(Bf5), VIf(Bf1), VIf(Bf7), VOf(Bf1));
    __hv_tabwrite_f(&sTabwrite_I0CXtZeH, VIf(Bf1));
    __hv_line_f(&sLine_Ejidq5xI, VOf(Bf1));
    __hv_varread_f(&sVarf_7RfjPVWo, VOf(Bf5));
    __hv_mul_f(VIf(Bf1), VIf(Bf5), VOf(Bf5));
    __hv_mul_f(VIf(Bf7), VIf(Bf5), VOf(Bf5));
    __hv_line_f(&sLine_CPLwMQlZ, VOf(Bf7));
    __hv_mul_f(VIf(Bf5), VIf(Bf7), VOf(Bf7));
    __hv_line_f(&sLine_owtRzKrP, VOf(Bf1));
    __hv_mul_f(VIf(Bf5), VIf(Bf1), VOf(Bf1));
    __hv_phasor_k_f(&sPhasor_vxBYdwZj, VOf(Bf5));
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
    __hv_line_f(&sLine_Uu2HTcOD, VOf(Bf4));
    __hv_add_f(VIf(Bf0), VIf(Bf7), VOf(Bf7));
    __hv_add_f(VIf(Bf3), VIf(Bf6), VOf(Bf6));
    __hv_add_f(VIf(Bf6), VIf(Bf2), VOf(Bf2));
    __hv_add_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_line_f(&sLine_1PW1Q8Bq, VOf(Bf2));
    __hv_mul_f(VIf(Bf7), VIf(Bf2), VOf(Bf7));
    __hv_mul_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_tabread_f(&sTabread_oYmmQCpE, VOf(Bf1));
    __hv_varread_f(&sVarf_LIHn206i, VOf(Bf6));
    __hv_mul_f(VIf(Bf1), VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_uugT5Juj, VOf(Bf1));
    __hv_rpole_f(&sRPole_CXyafDI3, VIf(Bf6), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_oUvkWwHu, VOf(Bf6));
    __hv_mul_f(VIf(Bf1), VIf(Bf6), VOf(Bf6));
    __hv_line_f(&sLine_Dra3dAfS, VOf(Bf1));
    __hv_varread_i(&sVari_eOByYFnj, VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 16807, 16807, 16807, 16807, 16807, 16807, 16807, 16807);
    __hv_mul_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_cast_if(VIi(Bi1), VOf(Bf3));
    __hv_var_k_f(VOf(Bf0), 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f);
    __hv_mul_f(VIf(Bf3), VIf(Bf0), VOf(Bf0));
    __hv_varwrite_i(&sVari_eOByYFnj, VIi(Bi1));
    __hv_fma_f(VIf(Bf1), VIf(Bf0), VIf(Bf6), VOf(Bf0));
    __hv_tabwrite_f(&sTabwrite_gx6f2ZZ0, VIf(Bf0));
    __hv_line_f(&sLine_wVRBvxvx, VOf(Bf0));
    __hv_mul_f(VIf(Bf6), VIf(Bf0), VOf(Bf0));
    __hv_line_f(&sLine_E7rN8JNU, VOf(Bf6));
    __hv_mul_f(VIf(Bf0), VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_5r1xjknQ, VOf(Bf0));
    __hv_rpole_f(&sRPole_BHQx0pEj, VIf(Bf6), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf6), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_del1_f(&sDel1_a8TLSseJ, VIf(Bf0), VOf(Bf1));
    __hv_mul_f(VIf(Bf1), VIf(Bf6), VOf(Bf6));
    __hv_sub_f(VIf(Bf0), VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_saHl7w3A, VOf(Bf0));
    __hv_mul_f(VIf(Bf6), VIf(Bf0), VOf(Bf0));
    __hv_line_f(&sLine_cGEIGLun, VOf(Bf6));
    __hv_mul_f(VIf(Bf0), VIf(Bf6), VOf(Bf6));
    __hv_add_f(VIf(Bf7), VIf(Bf6), VOf(Bf7));
    __hv_add_f(VIf(Bf2), VIf(Bf6), VOf(Bf0));
    __hv_line_f(&sLine_tV4FpGzc, VOf(Bf1));
    __hv_mul_f(VIf(Bf7), VIf(Bf1), VOf(Bf7));
    __hv_mul_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_add_f(VIf(Bf2), VIf(Bf6), VOf(Bf6));
    __hv_line_f(&sLine_3OZgPisP, VOf(Bf2));
    __hv_mul_f(VIf(Bf6), VIf(Bf2), VOf(Bf2));
    __hv_tabread_f(&sTabread_ywcjT7su, VOf(Bf6));
    __hv_varread_f(&sVarf_ct5nnFHj, VOf(Bf0));
    __hv_mul_f(VIf(Bf6), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_VgADkB3Q, VOf(Bf3));
    __hv_rpole_f(&sRPole_xADaUC4F, VIf(Bf0), VIf(Bf3), VOf(Bf3));
    __hv_sub_f(VIf(Bf3), VIf(Bf6), VOf(Bf3));
    __hv_line_f(&sLine_SWhbiqr5, VOf(Bf0));
    __hv_fma_f(VIf(Bf3), VIf(Bf0), VIf(Bf6), VOf(Bf6));
    __hv_line_f(&sLine_6bwWLUBX, VOf(Bf3));
    __hv_tabread_f(&sTabread_B79On196, VOf(Bf4));
    __hv_add_f(VIf(Bf2), VIf(Bf4), VOf(Bf8));
    __hv_tabread_f(&sTabread_2qIgAhN0, VOf(Bf5));
    __hv_add_f(VIf(Bf8), VIf(Bf5), VOf(Bf10));
    __hv_tabread_f(&sTabread_nHNLlL2V, VOf(Bf9));
    __hv_add_f(VIf(Bf10), VIf(Bf9), VOf(Bf11));
    __hv_tabread_f(&sTabread_kfbBBM5d, VOf(Bf12));
    __hv_add_f(VIf(Bf11), VIf(Bf12), VOf(Bf13));
    __hv_tabread_f(&sTabread_TirDdr2E, VOf(Bf14));
    __hv_sub_f(VIf(Bf13), VIf(Bf14), VOf(Bf15));
    __hv_tabwrite_f(&sTabwrite_RhGEUY4H, VIf(Bf15));
    __hv_sub_f(VIf(Bf11), VIf(Bf12), VOf(Bf12));
    __hv_tabwrite_f(&sTabwrite_kHoR6950, VIf(Bf12));
    __hv_sub_f(VIf(Bf10), VIf(Bf9), VOf(Bf9));
    __hv_tabwrite_f(&sTabwrite_ejTtB6aH, VIf(Bf9));
    __hv_sub_f(VIf(Bf8), VIf(Bf5), VOf(Bf5));
    __hv_tabwrite_f(&sTabwrite_G96thh7P, VIf(Bf5));
    __hv_sub_f(VIf(Bf2), VIf(Bf4), VOf(Bf4));
    __hv_tabwrite_f(&sTabwrite_8vTQ81nk, VIf(Bf4));
    __hv_tabwrite_f(&sTabwrite_EWFzdDQF, VIf(Bf2));
    __hv_add_f(VIf(Bf13), VIf(Bf14), VOf(Bf14));
    __hv_tabread_f(&sTabread_mdnOTK7O, VOf(Bf13));
    __hv_fma_f(VIf(Bf6), VIf(Bf3), VIf(Bf14), VOf(Bf14));
    __hv_tabread_f(&sTabread_qX2EGmbw, VOf(Bf6));
    __hv_varread_f(&sVarf_pLlRY8Vb, VOf(Bf4));
    __hv_mul_f(VIf(Bf6), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_ZTXdCxRr, VOf(Bf5));
    __hv_rpole_f(&sRPole_X5ribujV, VIf(Bf4), VIf(Bf5), VOf(Bf5));
    __hv_sub_f(VIf(Bf5), VIf(Bf6), VOf(Bf5));
    __hv_fma_f(VIf(Bf5), VIf(Bf0), VIf(Bf6), VOf(Bf6));
    __hv_fma_f(VIf(Bf6), VIf(Bf3), VIf(Bf13), VOf(Bf13));
    __hv_add_f(VIf(Bf14), VIf(Bf13), VOf(Bf6));
    __hv_tabread_f(&sTabread_yxeMnGOd, VOf(Bf5));
    __hv_varread_f(&sVarf_J2LEHm81, VOf(Bf4));
    __hv_mul_f(VIf(Bf5), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_Lzp8pV6Y, VOf(Bf8));
    __hv_rpole_f(&sRPole_AsB1MFAv, VIf(Bf4), VIf(Bf8), VOf(Bf8));
    __hv_sub_f(VIf(Bf8), VIf(Bf5), VOf(Bf8));
    __hv_fma_f(VIf(Bf8), VIf(Bf0), VIf(Bf5), VOf(Bf5));
    __hv_mul_f(VIf(Bf5), VIf(Bf3), VOf(Bf5));
    __hv_tabread_f(&sTabread_0FARaxkz, VOf(Bf8));
    __hv_varread_f(&sVarf_5QWBrofr, VOf(Bf4));
    __hv_mul_f(VIf(Bf8), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_GMNI2Gzz, VOf(Bf9));
    __hv_rpole_f(&sRPole_NwvidYT1, VIf(Bf4), VIf(Bf9), VOf(Bf9));
    __hv_sub_f(VIf(Bf9), VIf(Bf8), VOf(Bf9));
    __hv_fma_f(VIf(Bf9), VIf(Bf0), VIf(Bf8), VOf(Bf8));
    __hv_mul_f(VIf(Bf8), VIf(Bf3), VOf(Bf3));
    __hv_add_f(VIf(Bf5), VIf(Bf3), VOf(Bf8));
    __hv_add_f(VIf(Bf6), VIf(Bf8), VOf(Bf0));
    __hv_tabwrite_f(&sTabwrite_Mq1Sp84A, VIf(Bf0));
    __hv_sub_f(VIf(Bf14), VIf(Bf13), VOf(Bf0));
    __hv_sub_f(VIf(Bf5), VIf(Bf3), VOf(Bf9));
    __hv_add_f(VIf(Bf0), VIf(Bf9), VOf(Bf4));
    __hv_tabwrite_f(&sTabwrite_sSh6lvI0, VIf(Bf4));
    __hv_sub_f(VIf(Bf6), VIf(Bf8), VOf(Bf8));
    __hv_tabwrite_f(&sTabwrite_Lp38jFK6, VIf(Bf8));
    __hv_sub_f(VIf(Bf0), VIf(Bf9), VOf(Bf9));
    __hv_tabwrite_f(&sTabwrite_uClPPI22, VIf(Bf9));
    __hv_line_f(&sLine_uzqrU8zH, VOf(Bf9));
    __hv_mul_f(VIf(Bf14), VIf(Bf9), VOf(Bf14));
    __hv_mul_f(VIf(Bf13), VIf(Bf9), VOf(Bf13));
    __hv_mul_f(VIf(Bf5), VIf(Bf9), VOf(Bf5));
    __hv_mul_f(VIf(Bf3), VIf(Bf9), VOf(Bf9));
    __hv_line_f(&sLine_lGbUqyqN, VOf(Bf9));
    __hv_mul_f(VIf(Bf2), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf5), 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f);
    __hv_mul_f(VIf(Bf9), VIf(Bf5), VOf(Bf5));
    __hv_tabwrite_f(&sTabwrite_E1m7FFOE, VIf(Bf5));
    __hv_line_f(&sLine_w9JQDaIN, VOf(Bf9));
    __hv_phasor_f(&sPhasor_X2Jws0fR, VIf(Bf9), VOf(Bf9));
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
    __hv_line_f(&sLine_dC2qmDFS, VOf(Bf10));
    __hv_line_f(&sLine_3AWksRZ0, VOf(Bf3));
    __hv_fma_f(VIf(Bf9), VIf(Bf10), VIf(Bf3), VOf(Bf11));
    __hv_tabhead_f(&sTabhead_98jkAo1F, VOf(Bf4));
    __hv_var_k_f_r(VOf(Bf6), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf4), VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_kZij7zhD, VOf(Bf4));
    __hv_mul_f(VIf(Bf11), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_jmrBReYA, VOf(Bf11));
    __hv_min_f(VIf(Bf4), VIf(Bf11), VOf(Bf11));
    __hv_zero_f(VOf(Bf4));
    __hv_max_f(VIf(Bf11), VIf(Bf4), VOf(Bf4));
    __hv_sub_f(VIf(Bf6), VIf(Bf4), VOf(Bf4));
    __hv_floor_f(VIf(Bf4), VOf(Bf6));
    __hv_varread_f(&sVarf_N3LQ7K9s, VOf(Bf11));
    __hv_zero_f(VOf(Bf0));
    __hv_lt_f(VIf(Bf6), VIf(Bf0), VOf(Bf0));
    __hv_and_f(VIf(Bf11), VIf(Bf0), VOf(Bf0));
    __hv_add_f(VIf(Bf6), VIf(Bf0), VOf(Bf0));
    __hv_cast_fi(VIf(Bf0), VOi(Bi1));
    __hv_var_k_i(VOi(Bi0), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi1), VIi(Bi0), VOi(Bi0));
    __hv_tabread_if(&sTabread_0yZQbMrl, VIi(Bi0), VOf(Bf0));
    __hv_tabread_if(&sTabread_OfVT6Kmr, VIi(Bi1), VOf(Bf11));
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
    __hv_tabhead_f(&sTabhead_mvVfn1bj, VOf(Bf10));
    __hv_var_k_f_r(VOf(Bf9), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf10), VIf(Bf9), VOf(Bf9));
    __hv_varread_f(&sVarf_fi0IdYHn, VOf(Bf10));
    __hv_mul_f(VIf(Bf3), VIf(Bf10), VOf(Bf10));
    __hv_varread_f(&sVarf_iTxHKcnV, VOf(Bf3));
    __hv_min_f(VIf(Bf10), VIf(Bf3), VOf(Bf3));
    __hv_zero_f(VOf(Bf10));
    __hv_max_f(VIf(Bf3), VIf(Bf10), VOf(Bf10));
    __hv_sub_f(VIf(Bf9), VIf(Bf10), VOf(Bf10));
    __hv_floor_f(VIf(Bf10), VOf(Bf9));
    __hv_varread_f(&sVarf_alB1g67Z, VOf(Bf3));
    __hv_zero_f(VOf(Bf16));
    __hv_lt_f(VIf(Bf9), VIf(Bf16), VOf(Bf16));
    __hv_and_f(VIf(Bf3), VIf(Bf16), VOf(Bf16));
    __hv_add_f(VIf(Bf9), VIf(Bf16), VOf(Bf16));
    __hv_cast_fi(VIf(Bf16), VOi(Bi1));
    __hv_var_k_i(VOi(Bi0), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi1), VIi(Bi0), VOi(Bi0));
    __hv_tabread_if(&sTabread_SQVOCRmR, VIi(Bi0), VOf(Bf16));
    __hv_tabread_if(&sTabread_6nrkYXVm, VIi(Bi1), VOf(Bf3));
    __hv_sub_f(VIf(Bf16), VIf(Bf3), VOf(Bf16));
    __hv_sub_f(VIf(Bf10), VIf(Bf9), VOf(Bf9));
    __hv_fma_f(VIf(Bf16), VIf(Bf9), VIf(Bf3), VOf(Bf3));
    __hv_mul_f(VIf(Bf17), VIf(Bf3), VOf(Bf3));
    __hv_fma_f(VIf(Bf12), VIf(Bf11), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_gD2uy6r5, VOf(Bf11));
    __hv_tabhead_f(&sTabhead_10DWziux, VOf(Bf12));
    __hv_var_k_f_r(VOf(Bf17), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf12), VIf(Bf17), VOf(Bf17));
    __hv_varread_f(&sVarf_SQsCBqpT, VOf(Bf12));
    __hv_mul_f(VIf(Bf11), VIf(Bf12), VOf(Bf12));
    __hv_varread_f(&sVarf_xpAQZRaH, VOf(Bf11));
    __hv_min_f(VIf(Bf12), VIf(Bf11), VOf(Bf11));
    __hv_zero_f(VOf(Bf12));
    __hv_max_f(VIf(Bf11), VIf(Bf12), VOf(Bf12));
    __hv_sub_f(VIf(Bf17), VIf(Bf12), VOf(Bf12));
    __hv_floor_f(VIf(Bf12), VOf(Bf17));
    __hv_varread_f(&sVarf_z3V7FGDC, VOf(Bf11));
    __hv_zero_f(VOf(Bf9));
    __hv_lt_f(VIf(Bf17), VIf(Bf9), VOf(Bf9));
    __hv_and_f(VIf(Bf11), VIf(Bf9), VOf(Bf9));
    __hv_add_f(VIf(Bf17), VIf(Bf9), VOf(Bf9));
    __hv_cast_fi(VIf(Bf9), VOi(Bi1));
    __hv_var_k_i(VOi(Bi0), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi1), VIi(Bi0), VOi(Bi0));
    __hv_tabread_if(&sTabread_mCqCtznq, VIi(Bi0), VOf(Bf9));
    __hv_tabread_if(&sTabread_P4Efx2P1, VIi(Bi1), VOf(Bf11));
    __hv_sub_f(VIf(Bf9), VIf(Bf11), VOf(Bf9));
    __hv_sub_f(VIf(Bf12), VIf(Bf17), VOf(Bf17));
    __hv_fma_f(VIf(Bf9), VIf(Bf17), VIf(Bf11), VOf(Bf11));
    __hv_varread_f(&sVarf_iLpkvaHj, VOf(Bf17));
    __hv_rpole_f(&sRPole_NG0fD60I, VIf(Bf11), VIf(Bf17), VOf(Bf17));
    __hv_var_k_f(VOf(Bf11), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_del1_f(&sDel1_fLFg5rev, VIf(Bf17), VOf(Bf9));
    __hv_mul_f(VIf(Bf9), VIf(Bf11), VOf(Bf11));
    __hv_sub_f(VIf(Bf17), VIf(Bf11), VOf(Bf11));
    __hv_varread_f(&sVarf_2qLwisnm, VOf(Bf17));
    __hv_mul_f(VIf(Bf11), VIf(Bf17), VOf(Bf17));
    __hv_varread_f(&sVarf_RZyu0DjM, VOf(Bf11));
    __hv_mul_f(VIf(Bf17), VIf(Bf11), VOf(Bf11));
    __hv_add_f(VIf(Bf3), VIf(Bf11), VOf(Bf17));
    __hv_line_f(&sLine_socRXfBC, VOf(Bf9));
    __hv_varread_f(&sVarf_OdteWPZx, VOf(Bf12));
    __hv_mul_f(VIf(Bf11), VIf(Bf12), VOf(Bf12));
    __hv_varread_f(&sVarf_3QE3btHo, VOf(Bf11));
    __hv_rpole_f(&sRPole_hvXBxnvu, VIf(Bf12), VIf(Bf11), VOf(Bf11));
    __hv_fma_f(VIf(Bf3), VIf(Bf9), VIf(Bf11), VOf(Bf11));
    __hv_tabwrite_f(&sTabwrite_HgqY4tum, VIf(Bf11));
    __hv_add_f(VIf(Bf17), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_sdQZbveA, VOf(Bf17));
    __hv_varread_f(&sVarf_9T6ZYngT, VOf(Bf11));
    __hv_mul_f(VIf(Bf17), VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf17), 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f);
    __hv_max_f(VIf(Bf11), VIf(Bf17), VOf(Bf17));
    __hv_varread_f(&sVarf_tGQJ5UOH, VOf(Bf11));
    __hv_min_f(VIf(Bf17), VIf(Bf11), VOf(Bf11));
    __hv_varread_f(&sVarf_9K5qRupb, VOf(Bf9));
    __hv_mul_f(VIf(Bf11), VIf(Bf9), VOf(Bf9));
    __hv_mul_f(VIf(Bf5), VIf(Bf9), VOf(Bf5));
    __hv_varread_f(&sVarf_TkPJyfvg, VOf(Bf11));
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
    __hv_cpole_f(&sCPole_r4f1lZ1Z, VIf(Bf11), VIf(ZERO), VIf(Bf3), VIf(Bf17), VOf(Bf17), VOf(Bf3));
    __hv_varread_f(&sVarf_9e0AsWyy, VOf(Bf3));
    __hv_mul_f(VIf(Bf17), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_OYekWWvr, VOf(Bf17));
    __hv_rpole_f(&sRPole_kL1C0jMu, VIf(Bf3), VIf(Bf17), VOf(Bf17));
    __hv_varread_f(&sVarf_AMFe2ILE, VOf(Bf3));
    __hv_mul_f(VIf(Bf17), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_wzcESr4V, VOf(Bf17));
    __hv_rpole_f(&sRPole_u7jgWGsV, VIf(Bf3), VIf(Bf17), VOf(Bf17));
    __hv_varread_f(&sVarf_suZnWLke, VOf(Bf3));
    __hv_mul_f(VIf(Bf17), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_ZSA5JPpm, VOf(Bf17));
    __hv_rpole_f(&sRPole_T1gRgzlZ, VIf(Bf3), VIf(Bf17), VOf(Bf17));
    __hv_tabread_f(&sTabread_BMVI4rfq, VOf(Bf3));
    __hv_varread_f(&sVarf_8x9Hf6B3, VOf(Bf11));
    __hv_mul_f(VIf(Bf3), VIf(Bf11), VOf(Bf11));
    __hv_varread_f(&sVarf_agHcru4M, VOf(Bf9));
    __hv_rpole_f(&sRPole_ngV7xBHX, VIf(Bf11), VIf(Bf9), VOf(Bf9));
    __hv_sub_f(VIf(Bf9), VIf(Bf3), VOf(Bf9));
    __hv_line_f(&sLine_WI5IkPof, VOf(Bf11));
    __hv_fma_f(VIf(Bf9), VIf(Bf11), VIf(Bf3), VOf(Bf3));
    __hv_line_f(&sLine_5aVZ062v, VOf(Bf9));
    __hv_tabread_f(&sTabread_IUZVy1z9, VOf(Bf5));
    __hv_add_f(VIf(Bf17), VIf(Bf5), VOf(Bf12));
    __hv_tabread_f(&sTabread_F0xS8TOw, VOf(Bf16));
    __hv_add_f(VIf(Bf12), VIf(Bf16), VOf(Bf10));
    __hv_tabread_f(&sTabread_fGWXKbAe, VOf(Bf6));
    __hv_add_f(VIf(Bf10), VIf(Bf6), VOf(Bf18));
    __hv_tabread_f(&sTabread_3jtdNVgY, VOf(Bf15));
    __hv_add_f(VIf(Bf18), VIf(Bf15), VOf(Bf8));
    __hv_tabread_f(&sTabread_fOeppglu, VOf(Bf0));
    __hv_sub_f(VIf(Bf8), VIf(Bf0), VOf(Bf4));
    __hv_tabwrite_f(&sTabwrite_tCOQ2ItD, VIf(Bf4));
    __hv_sub_f(VIf(Bf18), VIf(Bf15), VOf(Bf15));
    __hv_tabwrite_f(&sTabwrite_vglPAOff, VIf(Bf15));
    __hv_sub_f(VIf(Bf10), VIf(Bf6), VOf(Bf6));
    __hv_tabwrite_f(&sTabwrite_BIcl6Py6, VIf(Bf6));
    __hv_sub_f(VIf(Bf12), VIf(Bf16), VOf(Bf16));
    __hv_tabwrite_f(&sTabwrite_7Xefv0Vw, VIf(Bf16));
    __hv_sub_f(VIf(Bf17), VIf(Bf5), VOf(Bf5));
    __hv_tabwrite_f(&sTabwrite_U60LhyMp, VIf(Bf5));
    __hv_tabwrite_f(&sTabwrite_9zWFmF8i, VIf(Bf17));
    __hv_add_f(VIf(Bf8), VIf(Bf0), VOf(Bf0));
    __hv_tabread_f(&sTabread_vX2N3qtx, VOf(Bf8));
    __hv_fma_f(VIf(Bf3), VIf(Bf9), VIf(Bf0), VOf(Bf0));
    __hv_tabread_f(&sTabread_sCx6s3vi, VOf(Bf3));
    __hv_varread_f(&sVarf_fgbIvbik, VOf(Bf5));
    __hv_mul_f(VIf(Bf3), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_tDrCQpcP, VOf(Bf16));
    __hv_rpole_f(&sRPole_PKUqbWGf, VIf(Bf5), VIf(Bf16), VOf(Bf16));
    __hv_sub_f(VIf(Bf16), VIf(Bf3), VOf(Bf16));
    __hv_fma_f(VIf(Bf16), VIf(Bf11), VIf(Bf3), VOf(Bf3));
    __hv_fma_f(VIf(Bf3), VIf(Bf9), VIf(Bf8), VOf(Bf8));
    __hv_add_f(VIf(Bf0), VIf(Bf8), VOf(Bf3));
    __hv_tabread_f(&sTabread_0eJsMEEd, VOf(Bf16));
    __hv_varread_f(&sVarf_h01R1Ld9, VOf(Bf5));
    __hv_mul_f(VIf(Bf16), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_60UokQL2, VOf(Bf12));
    __hv_rpole_f(&sRPole_NVrdmnbq, VIf(Bf5), VIf(Bf12), VOf(Bf12));
    __hv_sub_f(VIf(Bf12), VIf(Bf16), VOf(Bf12));
    __hv_fma_f(VIf(Bf12), VIf(Bf11), VIf(Bf16), VOf(Bf16));
    __hv_mul_f(VIf(Bf16), VIf(Bf9), VOf(Bf16));
    __hv_tabread_f(&sTabread_Om1xZlX2, VOf(Bf12));
    __hv_varread_f(&sVarf_RVRjBK8D, VOf(Bf5));
    __hv_mul_f(VIf(Bf12), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_hVJ19mrl, VOf(Bf6));
    __hv_rpole_f(&sRPole_fzJ36fZA, VIf(Bf5), VIf(Bf6), VOf(Bf6));
    __hv_sub_f(VIf(Bf6), VIf(Bf12), VOf(Bf6));
    __hv_fma_f(VIf(Bf6), VIf(Bf11), VIf(Bf12), VOf(Bf12));
    __hv_mul_f(VIf(Bf12), VIf(Bf9), VOf(Bf9));
    __hv_add_f(VIf(Bf16), VIf(Bf9), VOf(Bf12));
    __hv_add_f(VIf(Bf3), VIf(Bf12), VOf(Bf11));
    __hv_tabwrite_f(&sTabwrite_tHqeJ7HG, VIf(Bf11));
    __hv_sub_f(VIf(Bf0), VIf(Bf8), VOf(Bf11));
    __hv_sub_f(VIf(Bf16), VIf(Bf9), VOf(Bf6));
    __hv_add_f(VIf(Bf11), VIf(Bf6), VOf(Bf5));
    __hv_tabwrite_f(&sTabwrite_onLuFq4X, VIf(Bf5));
    __hv_sub_f(VIf(Bf3), VIf(Bf12), VOf(Bf12));
    __hv_tabwrite_f(&sTabwrite_iiXtjGK3, VIf(Bf12));
    __hv_sub_f(VIf(Bf11), VIf(Bf6), VOf(Bf6));
    __hv_tabwrite_f(&sTabwrite_MUpFJI2Y, VIf(Bf6));
    __hv_line_f(&sLine_bCgciRWS, VOf(Bf6));
    __hv_mul_f(VIf(Bf0), VIf(Bf6), VOf(Bf0));
    __hv_mul_f(VIf(Bf8), VIf(Bf6), VOf(Bf8));
    __hv_mul_f(VIf(Bf16), VIf(Bf6), VOf(Bf16));
    __hv_mul_f(VIf(Bf9), VIf(Bf6), VOf(Bf6));
    __hv_add_f(VIf(Bf17), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf17), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf0), VIf(Bf17), VOf(Bf17));
    __hv_add_f(VIf(Bf14), VIf(Bf17), VOf(Bf14));
    __hv_line_f(&sLine_HGNNrImW, VOf(Bf0));
    __hv_mul_f(VIf(Bf2), VIf(Bf0), VOf(Bf0));
    __hv_tabwrite_f(&sTabwrite_NQBcNdSe, VIf(Bf0));
    __hv_line_f(&sLine_mrEpoKCx, VOf(Bf0));
    __hv_phasor_f(&sPhasor_01Q83644, VIf(Bf0), VOf(Bf0));
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
    __hv_line_f(&sLine_stjxvo35, VOf(Bf11));
    __hv_line_f(&sLine_S2udaKf5, VOf(Bf2));
    __hv_fma_f(VIf(Bf0), VIf(Bf11), VIf(Bf2), VOf(Bf3));
    __hv_tabhead_f(&sTabhead_gSR2X83P, VOf(Bf9));
    __hv_var_k_f_r(VOf(Bf8), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf9), VIf(Bf8), VOf(Bf8));
    __hv_varread_f(&sVarf_FuWhBjDZ, VOf(Bf9));
    __hv_mul_f(VIf(Bf3), VIf(Bf9), VOf(Bf9));
    __hv_varread_f(&sVarf_J5wGu32K, VOf(Bf3));
    __hv_min_f(VIf(Bf9), VIf(Bf3), VOf(Bf3));
    __hv_zero_f(VOf(Bf9));
    __hv_max_f(VIf(Bf3), VIf(Bf9), VOf(Bf9));
    __hv_sub_f(VIf(Bf8), VIf(Bf9), VOf(Bf9));
    __hv_floor_f(VIf(Bf9), VOf(Bf8));
    __hv_varread_f(&sVarf_YDwwWFrn, VOf(Bf3));
    __hv_zero_f(VOf(Bf6));
    __hv_lt_f(VIf(Bf8), VIf(Bf6), VOf(Bf6));
    __hv_and_f(VIf(Bf3), VIf(Bf6), VOf(Bf6));
    __hv_add_f(VIf(Bf8), VIf(Bf6), VOf(Bf6));
    __hv_cast_fi(VIf(Bf6), VOi(Bi1));
    __hv_var_k_i(VOi(Bi0), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi1), VIi(Bi0), VOi(Bi0));
    __hv_tabread_if(&sTabread_TfUhR3Td, VIi(Bi0), VOf(Bf6));
    __hv_tabread_if(&sTabread_fQHzVTKa, VIi(Bi1), VOf(Bf3));
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
    __hv_tabhead_f(&sTabhead_suWTolvU, VOf(Bf11));
    __hv_var_k_f_r(VOf(Bf0), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf11), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_WEOggCsQ, VOf(Bf11));
    __hv_mul_f(VIf(Bf2), VIf(Bf11), VOf(Bf11));
    __hv_varread_f(&sVarf_6CqxHACL, VOf(Bf2));
    __hv_min_f(VIf(Bf11), VIf(Bf2), VOf(Bf2));
    __hv_zero_f(VOf(Bf11));
    __hv_max_f(VIf(Bf2), VIf(Bf11), VOf(Bf11));
    __hv_sub_f(VIf(Bf0), VIf(Bf11), VOf(Bf11));
    __hv_floor_f(VIf(Bf11), VOf(Bf0));
    __hv_varread_f(&sVarf_SuuDqkwe, VOf(Bf2));
    __hv_zero_f(VOf(Bf10));
    __hv_lt_f(VIf(Bf0), VIf(Bf10), VOf(Bf10));
    __hv_and_f(VIf(Bf2), VIf(Bf10), VOf(Bf10));
    __hv_add_f(VIf(Bf0), VIf(Bf10), VOf(Bf10));
    __hv_cast_fi(VIf(Bf10), VOi(Bi1));
    __hv_var_k_i(VOi(Bi0), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi1), VIi(Bi0), VOi(Bi0));
    __hv_tabread_if(&sTabread_552Pmcbl, VIi(Bi0), VOf(Bf10));
    __hv_tabread_if(&sTabread_zAAjWPdt, VIi(Bi1), VOf(Bf2));
    __hv_sub_f(VIf(Bf10), VIf(Bf2), VOf(Bf10));
    __hv_sub_f(VIf(Bf11), VIf(Bf0), VOf(Bf0));
    __hv_fma_f(VIf(Bf10), VIf(Bf0), VIf(Bf2), VOf(Bf2));
    __hv_mul_f(VIf(Bf15), VIf(Bf2), VOf(Bf2));
    __hv_fma_f(VIf(Bf12), VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_b20AZw3F, VOf(Bf3));
    __hv_tabhead_f(&sTabhead_K2HXcIpX, VOf(Bf12));
    __hv_var_k_f_r(VOf(Bf15), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf12), VIf(Bf15), VOf(Bf15));
    __hv_varread_f(&sVarf_7ELSxx6o, VOf(Bf12));
    __hv_mul_f(VIf(Bf3), VIf(Bf12), VOf(Bf12));
    __hv_varread_f(&sVarf_NepA7IB1, VOf(Bf3));
    __hv_min_f(VIf(Bf12), VIf(Bf3), VOf(Bf3));
    __hv_zero_f(VOf(Bf12));
    __hv_max_f(VIf(Bf3), VIf(Bf12), VOf(Bf12));
    __hv_sub_f(VIf(Bf15), VIf(Bf12), VOf(Bf12));
    __hv_floor_f(VIf(Bf12), VOf(Bf15));
    __hv_varread_f(&sVarf_0avF5hF4, VOf(Bf3));
    __hv_zero_f(VOf(Bf0));
    __hv_lt_f(VIf(Bf15), VIf(Bf0), VOf(Bf0));
    __hv_and_f(VIf(Bf3), VIf(Bf0), VOf(Bf0));
    __hv_add_f(VIf(Bf15), VIf(Bf0), VOf(Bf0));
    __hv_cast_fi(VIf(Bf0), VOi(Bi1));
    __hv_var_k_i(VOi(Bi0), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi1), VIi(Bi0), VOi(Bi0));
    __hv_tabread_if(&sTabread_JPrDPGAi, VIi(Bi0), VOf(Bf0));
    __hv_tabread_if(&sTabread_CzU2165J, VIi(Bi1), VOf(Bf3));
    __hv_sub_f(VIf(Bf0), VIf(Bf3), VOf(Bf0));
    __hv_sub_f(VIf(Bf12), VIf(Bf15), VOf(Bf15));
    __hv_fma_f(VIf(Bf0), VIf(Bf15), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_G4Ad08ON, VOf(Bf15));
    __hv_rpole_f(&sRPole_sl6K3zV6, VIf(Bf3), VIf(Bf15), VOf(Bf15));
    __hv_var_k_f(VOf(Bf3), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_del1_f(&sDel1_kDCA1D00, VIf(Bf15), VOf(Bf0));
    __hv_mul_f(VIf(Bf0), VIf(Bf3), VOf(Bf3));
    __hv_sub_f(VIf(Bf15), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_4IsnjDWd, VOf(Bf15));
    __hv_mul_f(VIf(Bf3), VIf(Bf15), VOf(Bf15));
    __hv_varread_f(&sVarf_uxWdVfH0, VOf(Bf3));
    __hv_mul_f(VIf(Bf15), VIf(Bf3), VOf(Bf3));
    __hv_add_f(VIf(Bf2), VIf(Bf3), VOf(Bf15));
    __hv_line_f(&sLine_89rTH9lR, VOf(Bf0));
    __hv_varread_f(&sVarf_SGJmRoOS, VOf(Bf12));
    __hv_mul_f(VIf(Bf3), VIf(Bf12), VOf(Bf12));
    __hv_varread_f(&sVarf_94IIpfHb, VOf(Bf3));
    __hv_rpole_f(&sRPole_gnHAEfB0, VIf(Bf12), VIf(Bf3), VOf(Bf3));
    __hv_fma_f(VIf(Bf2), VIf(Bf0), VIf(Bf3), VOf(Bf3));
    __hv_tabwrite_f(&sTabwrite_sjhaynXz, VIf(Bf3));
    __hv_var_k_f(VOf(Bf3), 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f);
    __hv_mul_f(VIf(Bf15), VIf(Bf3), VOf(Bf3));
    __hv_add_f(VIf(Bf14), VIf(Bf3), VOf(Bf14));
    __hv_add_f(VIf(Bf13), VIf(Bf17), VOf(Bf17));
    __hv_add_f(VIf(Bf17), VIf(Bf3), VOf(Bf3));
    __hv_line_f(&sLine_RtwkKZ3Y, VOf(Bf17));
    __hv_mul_f(VIf(Bf14), VIf(Bf17), VOf(Bf14));
    __hv_mul_f(VIf(Bf3), VIf(Bf17), VOf(Bf17));
    __hv_add_f(VIf(Bf7), VIf(Bf14), VOf(Bf14));
    __hv_add_f(VIf(Bf1), VIf(Bf17), VOf(Bf17));
    __hv_line_f(&sLine_qkpQNjIv, VOf(Bf1));
    __hv_mul_f(VIf(Bf14), VIf(Bf1), VOf(Bf14));
    __hv_mul_f(VIf(Bf17), VIf(Bf1), VOf(Bf1));
    __hv_add_f(VIf(Bf14), VIf(O0), VOf(O0));
    __hv_add_f(VIf(Bf1), VIf(O1), VOf(O1));

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

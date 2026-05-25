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

#include "Heavy_PhaseRing.hpp"

#include <new>

#define Context(_c) static_cast<Heavy_PhaseRing *>(_c)


/*
 * C Functions
 */

extern "C" {
  HV_EXPORT HeavyContextInterface *hv_PhaseRing_new(double sampleRate) {
    // allocate aligned memory
    void *ptr = hv_malloc(sizeof(Heavy_PhaseRing));
    // ensure non-null
    if (!ptr) return nullptr;
    // call constructor
    new(ptr) Heavy_PhaseRing(sampleRate);
    return Context(ptr);
  }

  HV_EXPORT HeavyContextInterface *hv_PhaseRing_new_with_options(double sampleRate,
      int poolKb, int inQueueKb, int outQueueKb) {
    // allocate aligned memory
    void *ptr = hv_malloc(sizeof(Heavy_PhaseRing));
    // ensure non-null
    if (!ptr) return nullptr;
    // call constructor
    new(ptr) Heavy_PhaseRing(sampleRate, poolKb, inQueueKb, outQueueKb);
    return Context(ptr);
  }

  HV_EXPORT void hv_PhaseRing_free(HeavyContextInterface *instance) {
    // call destructor
    Context(instance)->~Heavy_PhaseRing();
    // free memory
    hv_free(instance);
  }
} // extern "C"







/*
 * Class Functions
 */

Heavy_PhaseRing::Heavy_PhaseRing(double sampleRate, int poolKb, int inQueueKb, int outQueueKb)
    : HeavyContext(sampleRate, poolKb, inQueueKb, outQueueKb) {
  numBytes += sPhasor_k_init(&sPhasor_8xjvbFM4, 0.0f, sampleRate);
  numBytes += sLine_init(&sLine_Vnqry04P);
  numBytes += sPhasor_k_init(&sPhasor_2h68xAfX, 0.0f, sampleRate);
  numBytes += sLine_init(&sLine_0FiL2UtP);
  numBytes += sLine_init(&sLine_pqDwP36A);
  numBytes += sLine_init(&sLine_lJJYPFY0);
  numBytes += sPhasor_k_init(&sPhasor_hXgxF3mQ, 0.0f, sampleRate);
  numBytes += sLine_init(&sLine_Ei8Ad6TM);
  numBytes += sPhasor_k_init(&sPhasor_3t5OeHne, 0.0f, sampleRate);
  numBytes += sLine_init(&sLine_SyuuZYQq);
  numBytes += sLine_init(&sLine_hR0mzLSV);
  numBytes += sLine_init(&sLine_tbWCPgeO);
  numBytes += sPhasor_k_init(&sPhasor_NfUPZeBd, 0.0f, sampleRate);
  numBytes += sLine_init(&sLine_ovVB64wb);
  numBytes += sPhasor_k_init(&sPhasor_1M3FhNn6, 0.0f, sampleRate);
  numBytes += sLine_init(&sLine_7fBIVWou);
  numBytes += sLine_init(&sLine_vsVeom0q);
  numBytes += sLine_init(&sLine_giRKzRuL);
  numBytes += sPhasor_k_init(&sPhasor_XOGQDcF2, 0.0f, sampleRate);
  numBytes += sLine_init(&sLine_66n4HwTr);
  numBytes += sPhasor_k_init(&sPhasor_bd7RL59k, 0.0f, sampleRate);
  numBytes += sLine_init(&sLine_0wbImGNT);
  numBytes += sLine_init(&sLine_T2jB01bg);
  numBytes += sLine_init(&sLine_X2Ctjfu6);
  numBytes += sLine_init(&sLine_lL5QB7I5);
  numBytes += sLine_init(&sLine_0jMSPHJD);
  numBytes += sPhasor_init(&sPhasor_iGrYHzLO, sampleRate);
  numBytes += sLine_init(&sLine_grwHmHUl);
  numBytes += sPhasor_k_init(&sPhasor_JaqReih0, 0.0f, sampleRate);
  numBytes += sLine_init(&sLine_KWnuyXK0);
  numBytes += sLine_init(&sLine_bh3mAzj0);
  numBytes += sRPole_init(&sRPole_sTcvMtMw);
  numBytes += sDel1_init(&sDel1_qwjMvj5G);
  numBytes += sLine_init(&sLine_1xyjGWfZ);
  numBytes += sLine_init(&sLine_hDQCHo1p);
  numBytes += sLine_init(&sLine_zgmiZzxA);
  numBytes += sTabread_init(&sTabread_jw80FZK9, &hTable_hk8uR4SZ, true);
  numBytes += sRPole_init(&sRPole_Wck1LVDH);
  numBytes += sLine_init(&sLine_O5wXZwZz);
  numBytes += sLine_init(&sLine_vjEi2ef9);
  numBytes += sTabread_init(&sTabread_9iULrxbh, &hTable_PF8nREmZ, true);
  numBytes += sTabread_init(&sTabread_GyrieBLV, &hTable_dbrOf1mE, true);
  numBytes += sTabread_init(&sTabread_Mt91ilfO, &hTable_OUSNvdru, true);
  numBytes += sTabread_init(&sTabread_oSgV7GEt, &hTable_YVvjvH1Q, true);
  numBytes += sTabread_init(&sTabread_czQn5Hxr, &hTable_ASDeXuBy, true);
  numBytes += sTabwrite_init(&sTabwrite_s86jEh8Y, &hTable_x1926MpT);
  numBytes += sTabwrite_init(&sTabwrite_mYgV1uUy, &hTable_ASDeXuBy);
  numBytes += sTabwrite_init(&sTabwrite_vKgcxULU, &hTable_YVvjvH1Q);
  numBytes += sTabwrite_init(&sTabwrite_gDJsvhqR, &hTable_OUSNvdru);
  numBytes += sTabwrite_init(&sTabwrite_Nv5UT25H, &hTable_dbrOf1mE);
  numBytes += sTabwrite_init(&sTabwrite_X0TP5DSm, &hTable_PF8nREmZ);
  numBytes += sTabread_init(&sTabread_hUsGN24Q, &hTable_x1926MpT, true);
  numBytes += sTabread_init(&sTabread_TSq8QRuP, &hTable_lxlLALuN, true);
  numBytes += sRPole_init(&sRPole_TvA7EZcr);
  numBytes += sTabread_init(&sTabread_h4nHhP0C, &hTable_OutROxhq, true);
  numBytes += sRPole_init(&sRPole_esEqkN9B);
  numBytes += sTabread_init(&sTabread_evj4GBrQ, &hTable_LdIxdeSA, true);
  numBytes += sRPole_init(&sRPole_Q2T7y7xt);
  numBytes += sTabwrite_init(&sTabwrite_CaFt55s4, &hTable_hk8uR4SZ);
  numBytes += sTabwrite_init(&sTabwrite_W5hkesFL, &hTable_lxlLALuN);
  numBytes += sTabwrite_init(&sTabwrite_qGv01GnR, &hTable_OutROxhq);
  numBytes += sTabwrite_init(&sTabwrite_L7WOB0wH, &hTable_LdIxdeSA);
  numBytes += sLine_init(&sLine_hOiOVTYt);
  numBytes += sLine_init(&sLine_lHcwtND4);
  numBytes += sTabwrite_init(&sTabwrite_51eNDjbo, &hTable_dW7OaQK2);
  numBytes += sLine_init(&sLine_WlHXNuWP);
  numBytes += sPhasor_init(&sPhasor_RvPlim6J, sampleRate);
  numBytes += sLine_init(&sLine_tuaBH17A);
  numBytes += sLine_init(&sLine_sxvqfvcd);
  numBytes += sTabhead_init(&sTabhead_PMLtdrpw, &hTable_dW7OaQK2);
  numBytes += sTabread_init(&sTabread_I0H38l03, &hTable_dW7OaQK2, false);
  numBytes += sTabread_init(&sTabread_CPezLUZB, &hTable_dW7OaQK2, false);
  numBytes += sTabhead_init(&sTabhead_L2IXd7wk, &hTable_dW7OaQK2);
  numBytes += sTabread_init(&sTabread_kNN0j8Z2, &hTable_dW7OaQK2, false);
  numBytes += sTabread_init(&sTabread_XJPTuspF, &hTable_dW7OaQK2, false);
  numBytes += sTabhead_init(&sTabhead_giiQwRtq, &hTable_x6GDlK7A);
  numBytes += sTabread_init(&sTabread_3nASrSsT, &hTable_x6GDlK7A, false);
  numBytes += sTabread_init(&sTabread_ech3nxre, &hTable_x6GDlK7A, false);
  numBytes += sRPole_init(&sRPole_444mGrFd);
  numBytes += sDel1_init(&sDel1_6XyvKq36);
  numBytes += sLine_init(&sLine_Op6ntHhI);
  numBytes += sRPole_init(&sRPole_BgGAIs7i);
  numBytes += sTabwrite_init(&sTabwrite_RYeAX991, &hTable_x6GDlK7A);
  numBytes += sCPole_init(&sCPole_oF7L3vVo);
  numBytes += sRPole_init(&sRPole_WGmCYktU);
  numBytes += sRPole_init(&sRPole_s0g7hGgY);
  numBytes += sRPole_init(&sRPole_v6XMoTBh);
  numBytes += sTabread_init(&sTabread_asKRgqEu, &hTable_rHA5FkX9, true);
  numBytes += sRPole_init(&sRPole_KsOlL7xe);
  numBytes += sLine_init(&sLine_eI1d28fs);
  numBytes += sLine_init(&sLine_aYQ4VZ5j);
  numBytes += sTabread_init(&sTabread_Qh0CG6EU, &hTable_T2zZRC6o, true);
  numBytes += sTabread_init(&sTabread_8foYB517, &hTable_owKST7i5, true);
  numBytes += sTabread_init(&sTabread_VGfjzqHs, &hTable_RMwcv6FY, true);
  numBytes += sTabread_init(&sTabread_Lp3ejuyW, &hTable_uvayZRpY, true);
  numBytes += sTabread_init(&sTabread_uCY5INTW, &hTable_AD9rNiKP, true);
  numBytes += sTabwrite_init(&sTabwrite_j404L5Zw, &hTable_YVZi9ELj);
  numBytes += sTabwrite_init(&sTabwrite_xFHFKq7r, &hTable_AD9rNiKP);
  numBytes += sTabwrite_init(&sTabwrite_QySLbTzx, &hTable_uvayZRpY);
  numBytes += sTabwrite_init(&sTabwrite_2mSse9h2, &hTable_RMwcv6FY);
  numBytes += sTabwrite_init(&sTabwrite_odX501h4, &hTable_owKST7i5);
  numBytes += sTabwrite_init(&sTabwrite_wRRsYXfs, &hTable_T2zZRC6o);
  numBytes += sTabread_init(&sTabread_bAhyqN7O, &hTable_YVZi9ELj, true);
  numBytes += sTabread_init(&sTabread_3O74jFKr, &hTable_3DbJfxpg, true);
  numBytes += sRPole_init(&sRPole_W4tWYkIB);
  numBytes += sTabread_init(&sTabread_KyYkqv9N, &hTable_3IFV6IkW, true);
  numBytes += sRPole_init(&sRPole_kFOrIQEr);
  numBytes += sTabread_init(&sTabread_Jan5l5fZ, &hTable_88pSgIIG, true);
  numBytes += sRPole_init(&sRPole_iXBFhA1M);
  numBytes += sTabwrite_init(&sTabwrite_D9LtEcPs, &hTable_rHA5FkX9);
  numBytes += sTabwrite_init(&sTabwrite_jPyR4a4t, &hTable_3DbJfxpg);
  numBytes += sTabwrite_init(&sTabwrite_6b7yuS5B, &hTable_3IFV6IkW);
  numBytes += sTabwrite_init(&sTabwrite_ElpbN6Kw, &hTable_88pSgIIG);
  numBytes += sLine_init(&sLine_DfVbyDW7);
  numBytes += sLine_init(&sLine_m6r8KmmR);
  numBytes += sTabwrite_init(&sTabwrite_coE7euhU, &hTable_17BVN5Ee);
  numBytes += sLine_init(&sLine_YcekOZL7);
  numBytes += sPhasor_init(&sPhasor_31EzkRjE, sampleRate);
  numBytes += sLine_init(&sLine_36dYtuzu);
  numBytes += sLine_init(&sLine_mQEdlnwW);
  numBytes += sTabhead_init(&sTabhead_5fF3IAoe, &hTable_17BVN5Ee);
  numBytes += sTabread_init(&sTabread_BjJk5MLX, &hTable_17BVN5Ee, false);
  numBytes += sTabread_init(&sTabread_Rm24NaLW, &hTable_17BVN5Ee, false);
  numBytes += sTabhead_init(&sTabhead_rTuzGRZM, &hTable_17BVN5Ee);
  numBytes += sTabread_init(&sTabread_Z7IUu2a1, &hTable_17BVN5Ee, false);
  numBytes += sTabread_init(&sTabread_jcVFnlOu, &hTable_17BVN5Ee, false);
  numBytes += sTabhead_init(&sTabhead_XiYdHUxj, &hTable_BnH9zZ2A);
  numBytes += sTabread_init(&sTabread_Lwfmi9Hs, &hTable_BnH9zZ2A, false);
  numBytes += sTabread_init(&sTabread_E1MAtL8n, &hTable_BnH9zZ2A, false);
  numBytes += sRPole_init(&sRPole_gCMUpcst);
  numBytes += sDel1_init(&sDel1_BhwCJ4YN);
  numBytes += sLine_init(&sLine_HvrvnWCE);
  numBytes += sRPole_init(&sRPole_lsmy9sLq);
  numBytes += sTabwrite_init(&sTabwrite_uXBoxlN4, &hTable_BnH9zZ2A);
  numBytes += sLine_init(&sLine_9IcO3ryA);
  numBytes += sLine_init(&sLine_KKusIHT9);
  numBytes += cSlice_init(&cSlice_t152vozy, 2, 1);
  numBytes += cSlice_init(&cSlice_R7G9iIVs, 1, 1);
  numBytes += cSlice_init(&cSlice_N7p4BpPZ, 0, 1);
  numBytes += cVar_init_f(&cVar_01ZVbxBp, 0.0f);
  numBytes += cIf_init(&cIf_Qfq0NVSj, false);
  numBytes += cIf_init(&cIf_QcRXjCqW, false);
  numBytes += cIf_init(&cIf_5i1cOaaL, false);
  numBytes += cIf_init(&cIf_iU6nTGXy, false);
  numBytes += cIf_init(&cIf_8FXYppWY, false);
  numBytes += cBinop_init(&cBinop_uYFjaLmz, 0.0f); // __eq
  numBytes += cBinop_init(&cBinop_B0NVdsVR, 1.0f); // __pow
  numBytes += sVarf_init(&sVarf_4MfzdEiX, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_DmH27y1p, 5.0f);
  numBytes += cBinop_init(&cBinop_cbnNemAY, 0.0f); // __div
  numBytes += sVarf_init(&sVarf_qThy7gmp, 0.0f, 0.0f, false);
  numBytes += cPack_init(&cPack_Jzdhm5Yb, 2, 0.0f, 50.0f);
  numBytes += cVar_init_s(&cVar_Dn7qHgRv, "floatatom");
  numBytes += cVar_init_s(&cVar_qeQUI1Uf, "floatatom");
  numBytes += cIf_init(&cIf_IHrogl3L, false);
  numBytes += cIf_init(&cIf_FeeFl7Pq, false);
  numBytes += cIf_init(&cIf_aNHrILee, false);
  numBytes += cIf_init(&cIf_GEQwZJLR, false);
  numBytes += cPack_init(&cPack_AbB5bNvQ, 2, 0.0f, 50.0f);
  numBytes += cPack_init(&cPack_NFvoL6wi, 2, 0.0f, 80.0f);
  numBytes += cPack_init(&cPack_UcYdq4P5, 2, 0.0f, 50.0f);
  numBytes += cRandom_init(&cRandom_VpTHgJ6p, -1634678460);
  numBytes += cSlice_init(&cSlice_GuFN7Ce2, 1, 1);
  numBytes += cVar_init_s(&cVar_J8lMDuOJ, "floatatom");
  numBytes += cRandom_init(&cRandom_e6f64zA1, -1763293342);
  numBytes += cSlice_init(&cSlice_a8Jk5wKz, 1, 1);
  numBytes += cVar_init_s(&cVar_hSWX9zQC, "floatatom");
  numBytes += cVar_init_f(&cVar_l6KRBcSw, 1.0f);
  numBytes += cVar_init_f(&cVar_d3oUWrVK, 0.0f);
  numBytes += cVar_init_f(&cVar_Rg9blt1C, 0.0f);
  numBytes += cRandom_init(&cRandom_DPwLP8zX, 1549013607);
  numBytes += cSlice_init(&cSlice_twY6tbPv, 1, 1);
  numBytes += cRandom_init(&cRandom_vm83XZye, 1750386115);
  numBytes += cSlice_init(&cSlice_rQvKBxkN, 1, 1);
  numBytes += cRandom_init(&cRandom_0Zz6mSgJ, 1783535048);
  numBytes += cSlice_init(&cSlice_qFsmSlso, 1, 1);
  numBytes += cBinop_init(&cBinop_4SEAAyeN, 1.0f); // __pow
  numBytes += cRandom_init(&cRandom_3SYa5Baw, 428099429);
  numBytes += cSlice_init(&cSlice_RVeDvs4A, 1, 1);
  numBytes += cPack_init(&cPack_dwzpjVVs, 2, 0.0f, 50.0f);
  numBytes += cVar_init_s(&cVar_TnESUc3i, "floatatom");
  numBytes += cVar_init_s(&cVar_pYF2rsxM, "floatatom");
  numBytes += cVar_init_s(&cVar_VKP3VFKA, "floatatom");
  numBytes += cVar_init_f(&cVar_ggZbEbIr, 0.0f);
  numBytes += cVar_init_s(&cVar_iz6ZM54m, "floatatom");
  numBytes += cVar_init_s(&cVar_8o20CKEB, "floatatom");
  numBytes += cVar_init_s(&cVar_yM5d0sHz, "floatatom");
  numBytes += cDelay_init(this, &cDelay_fYQxGE0m, 25.0f);
  numBytes += cVar_init_f(&cVar_fQNf48LS, 0.0f);
  numBytes += sVarf_init(&sVarf_79xccx8L, 0.0f, 0.0f, false);
  numBytes += cPack_init(&cPack_m7i5Gb0A, 2, 0.0f, 10.0f);
  numBytes += cPack_init(&cPack_FDZi6xaM, 2, 0.0f, 10.0f);
  numBytes += cSlice_init(&cSlice_ChSpvips, 1, 1);
  numBytes += cSlice_init(&cSlice_99pisYur, 0, 1);
  numBytes += cBinop_init(&cBinop_SxeCvDOi, 1.0f); // __mul
  numBytes += cVar_init_f(&cVar_UpZ3dMgq, 98.0f);
  numBytes += cIf_init(&cIf_t1HvB1O9, false);
  numBytes += cBinop_init(&cBinop_GWBszAwt, 0.0f); // __pow
  numBytes += cPack_init(&cPack_5OIoexmP, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_xMBWSgGD, 0.0f);
  numBytes += cRandom_init(&cRandom_fqCDhpKa, -747177739);
  numBytes += cSlice_init(&cSlice_vEM3AGRr, 1, 1);
  numBytes += cBinop_init(&cBinop_Db3j0yUa, 1.0f); // __pow
  numBytes += cRandom_init(&cRandom_bIL6R9KT, 1969858174);
  numBytes += cSlice_init(&cSlice_Nr747al7, 1, 1);
  numBytes += cPack_init(&cPack_4ydY3gu5, 2, 0.0f, 50.0f);
  numBytes += cVar_init_s(&cVar_o0CYjto4, "floatatom");
  numBytes += cVar_init_s(&cVar_4rvMlW8n, "floatatom");
  numBytes += cVar_init_s(&cVar_MqY9ptxz, "floatatom");
  numBytes += cVar_init_f(&cVar_HPyzL3XY, 0.0f);
  numBytes += cVar_init_s(&cVar_qtRNSrp1, "floatatom");
  numBytes += cVar_init_s(&cVar_uKGIor9U, "floatatom");
  numBytes += cVar_init_s(&cVar_eDfkzju1, "floatatom");
  numBytes += cDelay_init(this, &cDelay_6DtpdvKW, 25.0f);
  numBytes += cVar_init_f(&cVar_He7iKBnF, 0.0f);
  numBytes += sVarf_init(&sVarf_ldg2SXAq, 0.0f, 0.0f, false);
  numBytes += cPack_init(&cPack_OxAJKTTJ, 2, 0.0f, 10.0f);
  numBytes += cPack_init(&cPack_LIXfGDXo, 2, 0.0f, 10.0f);
  numBytes += cSlice_init(&cSlice_1mX6OInW, 1, 1);
  numBytes += cSlice_init(&cSlice_sO28ZsSo, 0, 1);
  numBytes += cBinop_init(&cBinop_gH52d7pI, 1.0f); // __mul
  numBytes += cRandom_init(&cRandom_4SblHlb5, -1744210598);
  numBytes += cSlice_init(&cSlice_1KTvIfR4, 1, 1);
  numBytes += cBinop_init(&cBinop_btNWu7g2, 1.0f); // __pow
  numBytes += cRandom_init(&cRandom_At03ZDoQ, 572247381);
  numBytes += cSlice_init(&cSlice_MOMTkd4O, 1, 1);
  numBytes += cPack_init(&cPack_PpfQqbnP, 2, 0.0f, 50.0f);
  numBytes += cVar_init_s(&cVar_jICr70ZL, "floatatom");
  numBytes += cVar_init_s(&cVar_328UnsqH, "floatatom");
  numBytes += cVar_init_s(&cVar_vGgZ7YPI, "floatatom");
  numBytes += cVar_init_f(&cVar_LdK2880n, 0.0f);
  numBytes += cVar_init_s(&cVar_2HiJmuno, "floatatom");
  numBytes += cVar_init_s(&cVar_0TAJRVHO, "floatatom");
  numBytes += cVar_init_s(&cVar_lo2HXstj, "floatatom");
  numBytes += cDelay_init(this, &cDelay_PRBpC8wr, 25.0f);
  numBytes += cVar_init_f(&cVar_2IslpTAh, 0.0f);
  numBytes += sVarf_init(&sVarf_rzONZbPW, 0.0f, 0.0f, false);
  numBytes += cPack_init(&cPack_pZvPIMg4, 2, 0.0f, 10.0f);
  numBytes += cPack_init(&cPack_ROtddZFW, 2, 0.0f, 10.0f);
  numBytes += cSlice_init(&cSlice_ADDInxI0, 1, 1);
  numBytes += cSlice_init(&cSlice_p3O1i843, 0, 1);
  numBytes += cBinop_init(&cBinop_MCX8JOoK, 1.0f); // __mul
  numBytes += cRandom_init(&cRandom_fUBYaCdv, 2081611757);
  numBytes += cSlice_init(&cSlice_PLeGxjdZ, 1, 1);
  numBytes += cBinop_init(&cBinop_koZ7cvS2, 1.0f); // __pow
  numBytes += cRandom_init(&cRandom_6C42TlKP, 1478852946);
  numBytes += cSlice_init(&cSlice_V0yf5gSF, 1, 1);
  numBytes += cPack_init(&cPack_vwrQKZI6, 2, 0.0f, 50.0f);
  numBytes += cVar_init_s(&cVar_km4mMAIk, "floatatom");
  numBytes += cVar_init_s(&cVar_BBPNlROP, "floatatom");
  numBytes += cVar_init_s(&cVar_fW6U5gtX, "floatatom");
  numBytes += cVar_init_f(&cVar_nyFf79KP, 0.0f);
  numBytes += cVar_init_s(&cVar_jCMxTrIC, "floatatom");
  numBytes += cVar_init_s(&cVar_OZb1oely, "floatatom");
  numBytes += cVar_init_s(&cVar_9eRyPZDv, "floatatom");
  numBytes += cDelay_init(this, &cDelay_CeWQNIu9, 25.0f);
  numBytes += cVar_init_f(&cVar_vmwwlejN, 0.0f);
  numBytes += sVarf_init(&sVarf_eEbQ7xl6, 0.0f, 0.0f, false);
  numBytes += cPack_init(&cPack_yeCJUcsL, 2, 0.0f, 10.0f);
  numBytes += cPack_init(&cPack_6Sad23V9, 2, 0.0f, 10.0f);
  numBytes += cSlice_init(&cSlice_koQ36P8X, 1, 1);
  numBytes += cSlice_init(&cSlice_fM3STcNv, 0, 1);
  numBytes += cBinop_init(&cBinop_FNJv16oK, 1.0f); // __mul
  numBytes += cTabhead_init(&cTabhead_PKJAoYgQ, &hTable_hk8uR4SZ);
  numBytes += cVar_init_s(&cVar_ymCsbo9w, "del-1210-del1");
  numBytes += cDelay_init(this, &cDelay_YdButG8r, 58.6435f);
  numBytes += cDelay_init(this, &cDelay_m3uz3rjK, 0.0f);
  numBytes += cBinop_init(&cBinop_FGBKOujW, 58.6435f); // __mul
  numBytes += cBinop_init(&cBinop_ue3Qixuy, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_6HP4xFs2, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_oYbWWVrl, 0.0f); // __sub
  numBytes += cTabhead_init(&cTabhead_YRdUMsRO, &hTable_lxlLALuN);
  numBytes += cVar_init_s(&cVar_xkqRYso3, "del-1210-del2");
  numBytes += cDelay_init(this, &cDelay_k1jBD6no, 69.4325f);
  numBytes += cDelay_init(this, &cDelay_hiih9MkY, 0.0f);
  numBytes += cBinop_init(&cBinop_Qhk2RbSC, 69.4325f); // __mul
  numBytes += cBinop_init(&cBinop_7vJ0WWYD, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_5qeSjR4L, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_Soj9KsB4, 0.0f); // __sub
  numBytes += cTabhead_init(&cTabhead_MzangppQ, &hTable_OutROxhq);
  numBytes += cVar_init_s(&cVar_JkPGihsM, "del-1210-del3");
  numBytes += cDelay_init(this, &cDelay_rK9Aq3e3, 74.5234f);
  numBytes += cDelay_init(this, &cDelay_vucFyCgk, 0.0f);
  numBytes += cBinop_init(&cBinop_wS8HWjQC, 74.5234f); // __mul
  numBytes += cBinop_init(&cBinop_xikB8isq, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_BGzT3BIU, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_6h6ZNaa8, 0.0f); // __sub
  numBytes += cTabhead_init(&cTabhead_ZG38nnqM, &hTable_LdIxdeSA);
  numBytes += cVar_init_s(&cVar_jCF6TWWn, "del-1210-del4");
  numBytes += cDelay_init(this, &cDelay_RI6OHaI5, 86.1244f);
  numBytes += cDelay_init(this, &cDelay_7FfummxH, 0.0f);
  numBytes += cBinop_init(&cBinop_hhOZj78g, 86.1244f); // __mul
  numBytes += cBinop_init(&cBinop_0Iv0LCC2, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_hcU9DCa0, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_S23WeoJP, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_q7WhoAWy, 0.0f);
  numBytes += cDelay_init(this, &cDelay_BmyFeitd, 0.0f);
  numBytes += hTable_init(&hTable_hk8uR4SZ, 256);
  numBytes += cDelay_init(this, &cDelay_kvJ9GrLw, 0.0f);
  numBytes += cDelay_init(this, &cDelay_UgcTnX09, 0.0f);
  numBytes += hTable_init(&hTable_lxlLALuN, 256);
  numBytes += cDelay_init(this, &cDelay_5dJo6EmK, 0.0f);
  numBytes += cDelay_init(this, &cDelay_yqAO5wXV, 0.0f);
  numBytes += hTable_init(&hTable_OutROxhq, 256);
  numBytes += cDelay_init(this, &cDelay_nCSUIJd7, 0.0f);
  numBytes += cDelay_init(this, &cDelay_TNpE8Nhx, 0.0f);
  numBytes += hTable_init(&hTable_LdIxdeSA, 256);
  numBytes += cIf_init(&cIf_BwLvbS79, false);
  numBytes += cBinop_init(&cBinop_Tl6pkW1v, 0.0f); // __pow
  numBytes += cPack_init(&cPack_Dr2kPUep, 2, 0.0f, 30.0f);
  numBytes += cPack_init(&cPack_UtJkCIRJ, 2, 0.0f, 50.0f);
  numBytes += cVar_init_f(&cVar_6LRTzgMY, 22050.0f);
  numBytes += cBinop_init(&cBinop_RSAM2qmG, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_osSX212V, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_SbHORNfz, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_V0YU1TVm, 95.0f);
  numBytes += cVar_init_f(&cVar_KQJ9X5YQ, 90.0f);
  numBytes += cVar_init_f(&cVar_TRSC3Dk6, 6000.0f);
  numBytes += cVar_init_f(&cVar_FkBlJBq4, 60.0f);
  numBytes += cIf_init(&cIf_sqRyq0oS, false);
  numBytes += cTabhead_init(&cTabhead_HoXZ04Un, &hTable_x1926MpT);
  numBytes += cVar_init_s(&cVar_18e9SGzg, "del-1210-ref6");
  numBytes += cDelay_init(this, &cDelay_q4l2hDwA, 13.645f);
  numBytes += cDelay_init(this, &cDelay_TVpGZQ1E, 0.0f);
  numBytes += cBinop_init(&cBinop_ERMYPR0H, 13.645f); // __mul
  numBytes += cBinop_init(&cBinop_iZGQkpx1, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_YGitIJDh, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_oIMr4Kav, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_1eo9jHqt, 0.0f);
  numBytes += cDelay_init(this, &cDelay_RKSFUslk, 0.0f);
  numBytes += hTable_init(&hTable_x1926MpT, 256);
  numBytes += cTabhead_init(&cTabhead_y4Bq6gfx, &hTable_ASDeXuBy);
  numBytes += cVar_init_s(&cVar_IsgQPszk, "del-1210-ref5");
  numBytes += cDelay_init(this, &cDelay_yoRKm6hX, 16.364f);
  numBytes += cDelay_init(this, &cDelay_LikuCG38, 0.0f);
  numBytes += cBinop_init(&cBinop_JCgD0nEf, 16.364f); // __mul
  numBytes += cBinop_init(&cBinop_Qj7vpWOD, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_zhdgwIsR, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_ELN7mzjj, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_Zoq2xtyx, 0.0f);
  numBytes += cDelay_init(this, &cDelay_ymnh9Mnd, 0.0f);
  numBytes += hTable_init(&hTable_ASDeXuBy, 256);
  numBytes += cTabhead_init(&cTabhead_M7RUb4H8, &hTable_YVvjvH1Q);
  numBytes += cVar_init_s(&cVar_ZNI0gAFB, "del-1210-ref4");
  numBytes += cDelay_init(this, &cDelay_HuZZCmyU, 19.392f);
  numBytes += cDelay_init(this, &cDelay_vQJmAk9q, 0.0f);
  numBytes += cBinop_init(&cBinop_77C9bXAd, 19.392f); // __mul
  numBytes += cBinop_init(&cBinop_thjTyt69, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_KtLchMfu, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_1xGlfPLh, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_FGlW7dGn, 0.0f);
  numBytes += cDelay_init(this, &cDelay_Ap8Kjblu, 0.0f);
  numBytes += hTable_init(&hTable_YVvjvH1Q, 256);
  numBytes += cTabhead_init(&cTabhead_y1YWpaio, &hTable_OUSNvdru);
  numBytes += cVar_init_s(&cVar_kUYYAuQl, "del-1210-ref3");
  numBytes += cDelay_init(this, &cDelay_UxRaIVKk, 25.796f);
  numBytes += cDelay_init(this, &cDelay_BpKKTtAG, 0.0f);
  numBytes += cBinop_init(&cBinop_fHWPRtUb, 25.796f); // __mul
  numBytes += cBinop_init(&cBinop_c4Fu8MNv, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_HxHHiAxZ, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_0gWdQTHL, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_xjwuI8my, 0.0f);
  numBytes += cDelay_init(this, &cDelay_kXwxpTBz, 0.0f);
  numBytes += hTable_init(&hTable_OUSNvdru, 256);
  numBytes += cTabhead_init(&cTabhead_6DgCmMTD, &hTable_dbrOf1mE);
  numBytes += cVar_init_s(&cVar_AIrMCi7o, "del-1210-ref2");
  numBytes += cDelay_init(this, &cDelay_o0jECghx, 43.5337f);
  numBytes += cDelay_init(this, &cDelay_t1zCdCRk, 0.0f);
  numBytes += cBinop_init(&cBinop_UYELI28S, 43.5337f); // __mul
  numBytes += cBinop_init(&cBinop_FueBxgI1, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_XoIxavbh, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_MJaRptpQ, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_joqrYw8Z, 0.0f);
  numBytes += cDelay_init(this, &cDelay_xLqzWgwM, 0.0f);
  numBytes += hTable_init(&hTable_dbrOf1mE, 256);
  numBytes += cTabhead_init(&cTabhead_QFpfnUpP, &hTable_PF8nREmZ);
  numBytes += cVar_init_s(&cVar_p1m54qKC, "del-1210-ref1");
  numBytes += cDelay_init(this, &cDelay_PkT7LPkb, 75.2546f);
  numBytes += cDelay_init(this, &cDelay_UTRr6u5E, 0.0f);
  numBytes += cBinop_init(&cBinop_kCb4FlW0, 75.2546f); // __mul
  numBytes += cBinop_init(&cBinop_Sib9jbMB, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_SgtRxxgb, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_i7E5SOQG, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_akVdhqDH, 0.0f);
  numBytes += cDelay_init(this, &cDelay_ehmZRURG, 0.0f);
  numBytes += hTable_init(&hTable_PF8nREmZ, 256);
  numBytes += cVar_init_f(&cVar_Ypxx9KMu, 0.0f);
  numBytes += cVar_init_f(&cVar_DHJ9VxY7, 0.0f);
  numBytes += cPack_init(&cPack_mcP6UC3C, 2, 0.0f, 50.0f);
  numBytes += cVar_init_f(&cVar_dfxLSRfh, 22050.0f);
  numBytes += cBinop_init(&cBinop_VhLjGT1y, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_vCqxGV1F, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_pLwCfYWS, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_R4LRTRsI, 22050.0f);
  numBytes += cBinop_init(&cBinop_axPZlzYm, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_PrrAT8iu, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_2GBhmOo7, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_szbmEw9T, 22050.0f);
  numBytes += cBinop_init(&cBinop_MiEt9Jgy, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_vtrYp3df, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_y7wiJVwz, 0.0f, 0.0f, false);
  numBytes += cIf_init(&cIf_UpldvUnY, false);
  numBytes += cDelay_init(this, &cDelay_GUVMNm0o, 50.0f);
  numBytes += cVar_init_f(&cVar_eVA9oNX5, 0.0f);
  numBytes += cVar_init_f(&cVar_kFBk3sAx, 12.0f);
  numBytes += cVar_init_s(&cVar_9F9lwmxe, "floatatom");
  numBytes += cPack_init(&cPack_8J49SzJl, 2, 0.0f, 200.0f);
  numBytes += cPack_init(&cPack_zZXJDA0v, 2, 0.0f, 200.0f);
  numBytes += cVar_init_s(&cVar_Ty9qbdiW, "floatatom");
  numBytes += cDelay_init(this, &cDelay_XX9oIoCn, 0.0f);
  numBytes += cDelay_init(this, &cDelay_4r4fXfvw, 0.0f);
  numBytes += hTable_init(&hTable_dW7OaQK2, 256);
  numBytes += cVar_init_s(&cVar_ZWEmzime, "del-1317-del");
  numBytes += sVarf_init(&sVarf_AhTj46c4, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_L9y5R30m, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_R18Afh3V, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_80yF5D8Y, "del-1317-del");
  numBytes += sVarf_init(&sVarf_HaKYpd9K, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_jDXW83IH, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_ozr8VZvi, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_9tZp3LzP, 0.0f); // __div
  numBytes += cVar_init_f(&cVar_TocowoRV, 4720.0f);
  numBytes += cBinop_init(&cBinop_sh1zz2uW, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_08CbyBYq, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_bj2eZCY4, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_1V6rz622, 4720.0f);
  numBytes += cBinop_init(&cBinop_iq0dyH4B, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_YJer2oM4, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_OSmCag9h, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_6kqa7WwG, 4720.0f);
  numBytes += cBinop_init(&cBinop_8CgtTAiB, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_NYESUzF7, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_BkxhEV53, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_Xe9Np1Ow, 1.0f);
  numBytes += cIf_init(&cIf_vBqFdSCQ, false);
  numBytes += sVarf_init(&sVarf_poylECiY, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_6eiusMfy, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_3Osityy7, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_kTPQgpHs, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_qntFe5GV, 4720.0f, 0.0f, false);
  numBytes += cTabhead_init(&cTabhead_WsZHRWlg, &hTable_rHA5FkX9);
  numBytes += cVar_init_s(&cVar_XthSwvQT, "del-1380-del1");
  numBytes += cDelay_init(this, &cDelay_MVnO0n9W, 58.6435f);
  numBytes += cDelay_init(this, &cDelay_zU2TAv1u, 0.0f);
  numBytes += cBinop_init(&cBinop_kKNh0Z1C, 58.6435f); // __mul
  numBytes += cBinop_init(&cBinop_jeKPq1qD, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_Prv3aDNF, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_xBsQkQji, 0.0f); // __sub
  numBytes += cTabhead_init(&cTabhead_SOQTdbn3, &hTable_3DbJfxpg);
  numBytes += cVar_init_s(&cVar_XGhd7fqo, "del-1380-del2");
  numBytes += cDelay_init(this, &cDelay_zyoYRBTE, 69.4325f);
  numBytes += cDelay_init(this, &cDelay_NLHDBrgj, 0.0f);
  numBytes += cBinop_init(&cBinop_YzrSfIlJ, 69.4325f); // __mul
  numBytes += cBinop_init(&cBinop_unQtei3o, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_vRYuhFmg, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_ZAryfs8e, 0.0f); // __sub
  numBytes += cTabhead_init(&cTabhead_8Xfd0Yjh, &hTable_3IFV6IkW);
  numBytes += cVar_init_s(&cVar_J7EQE7NA, "del-1380-del3");
  numBytes += cDelay_init(this, &cDelay_V5OCkCgf, 74.5234f);
  numBytes += cDelay_init(this, &cDelay_rAO4jTiS, 0.0f);
  numBytes += cBinop_init(&cBinop_hm9F1nMK, 74.5234f); // __mul
  numBytes += cBinop_init(&cBinop_Vem5iuxx, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_9VVdhNp0, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_cpmykcSH, 0.0f); // __sub
  numBytes += cTabhead_init(&cTabhead_uP65eeQc, &hTable_88pSgIIG);
  numBytes += cVar_init_s(&cVar_dHJgW9Vn, "del-1380-del4");
  numBytes += cDelay_init(this, &cDelay_uKKR5B2w, 86.1244f);
  numBytes += cDelay_init(this, &cDelay_8QWS7v0a, 0.0f);
  numBytes += cBinop_init(&cBinop_E5NbDk0d, 86.1244f); // __mul
  numBytes += cBinop_init(&cBinop_0NHbbd25, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_DVwohSoS, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_j7Gb85U9, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_Pa8fXC6Y, 0.0f);
  numBytes += cDelay_init(this, &cDelay_PWBNBgSY, 0.0f);
  numBytes += hTable_init(&hTable_rHA5FkX9, 256);
  numBytes += cDelay_init(this, &cDelay_2xZ3624t, 0.0f);
  numBytes += cDelay_init(this, &cDelay_KTnbVxcz, 0.0f);
  numBytes += hTable_init(&hTable_3DbJfxpg, 256);
  numBytes += cDelay_init(this, &cDelay_40rfzunH, 0.0f);
  numBytes += cDelay_init(this, &cDelay_zgvHbjai, 0.0f);
  numBytes += hTable_init(&hTable_3IFV6IkW, 256);
  numBytes += cDelay_init(this, &cDelay_nFkM3sva, 0.0f);
  numBytes += cDelay_init(this, &cDelay_3v3UVkYh, 0.0f);
  numBytes += hTable_init(&hTable_88pSgIIG, 256);
  numBytes += cIf_init(&cIf_7IzFaJX1, false);
  numBytes += cBinop_init(&cBinop_JaVhOH2g, 0.0f); // __pow
  numBytes += cPack_init(&cPack_b2GzXqjm, 2, 0.0f, 30.0f);
  numBytes += cPack_init(&cPack_QAEz3vyM, 2, 0.0f, 50.0f);
  numBytes += cVar_init_f(&cVar_FZGTin4Z, 22050.0f);
  numBytes += cBinop_init(&cBinop_JNW1IMkA, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_0bYQByIo, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_whuH0hKj, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_SqDghORD, 100.0f);
  numBytes += cVar_init_f(&cVar_2iZB8TKO, 95.0f);
  numBytes += cVar_init_f(&cVar_l6gCb4pB, 14400.0f);
  numBytes += cVar_init_f(&cVar_u4M5Kw45, 60.0f);
  numBytes += cIf_init(&cIf_RQZyFSTO, false);
  numBytes += cTabhead_init(&cTabhead_y2zRwp8g, &hTable_YVZi9ELj);
  numBytes += cVar_init_s(&cVar_ainKTSfH, "del-1380-ref6");
  numBytes += cDelay_init(this, &cDelay_h5bbSav9, 13.645f);
  numBytes += cDelay_init(this, &cDelay_IbcwKoGK, 0.0f);
  numBytes += cBinop_init(&cBinop_ZO5msVAn, 13.645f); // __mul
  numBytes += cBinop_init(&cBinop_FbEHPrDi, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_pj3Ad1r0, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_TM0ILdUR, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_6DGg2TUX, 0.0f);
  numBytes += cDelay_init(this, &cDelay_WWZTc3kF, 0.0f);
  numBytes += hTable_init(&hTable_YVZi9ELj, 256);
  numBytes += cTabhead_init(&cTabhead_bWdTlbUx, &hTable_AD9rNiKP);
  numBytes += cVar_init_s(&cVar_VSRAw14X, "del-1380-ref5");
  numBytes += cDelay_init(this, &cDelay_A2OUM1SP, 16.364f);
  numBytes += cDelay_init(this, &cDelay_8Vzol3Gu, 0.0f);
  numBytes += cBinop_init(&cBinop_lye2Iy7j, 16.364f); // __mul
  numBytes += cBinop_init(&cBinop_AuUsiIhB, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_oIQvI664, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_7UegN5Fv, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_2X0wazg8, 0.0f);
  numBytes += cDelay_init(this, &cDelay_HGfm0ZFZ, 0.0f);
  numBytes += hTable_init(&hTable_AD9rNiKP, 256);
  numBytes += cTabhead_init(&cTabhead_UZcQgShe, &hTable_uvayZRpY);
  numBytes += cVar_init_s(&cVar_4GEfLeRi, "del-1380-ref4");
  numBytes += cDelay_init(this, &cDelay_J1AOdxMX, 19.392f);
  numBytes += cDelay_init(this, &cDelay_Aolthp52, 0.0f);
  numBytes += cBinop_init(&cBinop_M9N5hzie, 19.392f); // __mul
  numBytes += cBinop_init(&cBinop_U8yZPEND, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_7w31au2A, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_HVsSnsj0, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_1Db0KMuv, 0.0f);
  numBytes += cDelay_init(this, &cDelay_C6OeSu87, 0.0f);
  numBytes += hTable_init(&hTable_uvayZRpY, 256);
  numBytes += cTabhead_init(&cTabhead_wf2et4NE, &hTable_RMwcv6FY);
  numBytes += cVar_init_s(&cVar_InMgz6dl, "del-1380-ref3");
  numBytes += cDelay_init(this, &cDelay_7YBPLB8I, 25.796f);
  numBytes += cDelay_init(this, &cDelay_pOhN26LU, 0.0f);
  numBytes += cBinop_init(&cBinop_ao8hGc9g, 25.796f); // __mul
  numBytes += cBinop_init(&cBinop_DuGJGnlZ, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_A0B3JkLQ, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_XUhn444L, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_BsGIM45O, 0.0f);
  numBytes += cDelay_init(this, &cDelay_0V3YErs2, 0.0f);
  numBytes += hTable_init(&hTable_RMwcv6FY, 256);
  numBytes += cTabhead_init(&cTabhead_Cwy4JVJP, &hTable_owKST7i5);
  numBytes += cVar_init_s(&cVar_5NOlhK1a, "del-1380-ref2");
  numBytes += cDelay_init(this, &cDelay_tKy8pBhI, 43.5337f);
  numBytes += cDelay_init(this, &cDelay_Fh1Dk3UE, 0.0f);
  numBytes += cBinop_init(&cBinop_jrubf91n, 43.5337f); // __mul
  numBytes += cBinop_init(&cBinop_eaChx4rh, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_XhZf4iv0, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_CYWOT8En, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_Dd5JMAZu, 0.0f);
  numBytes += cDelay_init(this, &cDelay_MZ4rwCXU, 0.0f);
  numBytes += hTable_init(&hTable_owKST7i5, 256);
  numBytes += cTabhead_init(&cTabhead_Od7cPgu2, &hTable_T2zZRC6o);
  numBytes += cVar_init_s(&cVar_aJKqne9N, "del-1380-ref1");
  numBytes += cDelay_init(this, &cDelay_UNB7vev9, 75.2546f);
  numBytes += cDelay_init(this, &cDelay_n46sK5N4, 0.0f);
  numBytes += cBinop_init(&cBinop_dOE2bvnS, 75.2546f); // __mul
  numBytes += cBinop_init(&cBinop_w0KFQ6Lp, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_D74lFvSo, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_gHZDZOtv, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_22pNTNpF, 0.0f);
  numBytes += cDelay_init(this, &cDelay_PB4j3p2n, 0.0f);
  numBytes += hTable_init(&hTable_T2zZRC6o, 256);
  numBytes += cVar_init_f(&cVar_8fy6E54J, 0.0f);
  numBytes += cVar_init_f(&cVar_t6Cl0HAh, 0.0f);
  numBytes += cPack_init(&cPack_EgR18v6D, 2, 0.0f, 50.0f);
  numBytes += cVar_init_f(&cVar_3bYVVJ2t, 22050.0f);
  numBytes += cBinop_init(&cBinop_W1T4CFMc, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_K2FA8eor, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_7PLCXbqK, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_uz1WtjY3, 22050.0f);
  numBytes += cBinop_init(&cBinop_76a43th3, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_ho69Xjjz, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_ePqZtHSi, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_9Mk4b4EK, 22050.0f);
  numBytes += cBinop_init(&cBinop_Vqt2M4zZ, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_UxXwpOiT, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_2TOgOlRb, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_9wAZSxKR, "del-1479-del1");
  numBytes += sVarf_init(&sVarf_xuk4n1dP, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_kDiruckg, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_HwFWfFNM, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_D9G8DfNz, 10000.0f);
  numBytes += cBinop_init(&cBinop_AsMYOJl7, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_qeoDPrmj, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_GwYXgCuK, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_6aYJjZ2P, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_x5XmyhZz, 10.0f);
  numBytes += cBinop_init(&cBinop_o2t5G1qo, 0.0f); // __div
  numBytes += sVarf_init(&sVarf_BrQsobmA, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_rdWGkaCI, "floatatom");
  numBytes += sVarf_init(&sVarf_LIVUU1FQ, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_UzXc5got, 0.0f);
  numBytes += cDelay_init(this, &cDelay_ijCAOWZo, 0.0f);
  numBytes += hTable_init(&hTable_x6GDlK7A, 256);
  numBytes += sVarf_init(&sVarf_pCBZ9CxV, 0.0f, 0.0f, false);
  numBytes += cPack_init(&cPack_2Mtgs0Xo, 2, 0.0f, 50.0f);
  numBytes += cRandom_init(&cRandom_MvWnBiOI, 546859554);
  numBytes += cSlice_init(&cSlice_Y9eOFBcP, 1, 1);
  numBytes += cRandom_init(&cRandom_t03jILK6, 261635042);
  numBytes += cSlice_init(&cSlice_649hqpev, 1, 1);
  numBytes += cVar_init_s(&cVar_paHj86ia, "floatatom");
  numBytes += cPack_init(&cPack_EIhy5NBR, 2, 0.0f, 200.0f);
  numBytes += cPack_init(&cPack_LRlh0V4F, 2, 0.0f, 200.0f);
  numBytes += cVar_init_s(&cVar_cFZ09Ivb, "floatatom");
  numBytes += cDelay_init(this, &cDelay_tMemUujr, 0.0f);
  numBytes += cDelay_init(this, &cDelay_0vixRJlU, 0.0f);
  numBytes += hTable_init(&hTable_17BVN5Ee, 256);
  numBytes += cVar_init_s(&cVar_Dn4DoP5Y, "del-1510-del");
  numBytes += sVarf_init(&sVarf_Oln9UMIu, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_G6b7jUQ2, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_t46iamp4, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_909CY1Yr, "del-1510-del");
  numBytes += sVarf_init(&sVarf_GCrHknxZ, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_zmtDYAVK, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_NLQvdtS2, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_NIUwvhU3, 0.0f); // __div
  numBytes += cVar_init_s(&cVar_ZV0iPES5, "del-1539-del1");
  numBytes += sVarf_init(&sVarf_r3Ua9Jir, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_25RKwJ8C, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_1drvCDm3, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_WZnOZDqG, 10000.0f);
  numBytes += cBinop_init(&cBinop_vrc48qBY, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_uMa0hI9E, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_SyniOFL9, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_mLl7yrEg, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_XaqVHJDX, 10.0f);
  numBytes += cBinop_init(&cBinop_cqLyuUE0, 0.0f); // __div
  numBytes += sVarf_init(&sVarf_l5HTGxd2, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_N8g4fied, "floatatom");
  numBytes += sVarf_init(&sVarf_wLskBSGz, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_G3LcqFii, 0.0f);
  numBytes += cDelay_init(this, &cDelay_8q5z4DsZ, 0.0f);
  numBytes += hTable_init(&hTable_BnH9zZ2A, 256);
  numBytes += sVarf_init(&sVarf_XWVtQp3n, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_U4GHQjgq, "floatatom");
  numBytes += cDelay_init(this, &cDelay_8Wlo2hIf, 0.0f);
  numBytes += cVar_init_f(&cVar_vxawBnJw, 20.0f);
  numBytes += cBinop_init(&cBinop_qNgGpLV3, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_qPTOxsmZ, 0.0f);
  numBytes += cSlice_init(&cSlice_9R6m0LYg, 1, -1);
  numBytes += cSlice_init(&cSlice_k0Gii2wf, 1, -1);
  numBytes += cVar_init_f(&cVar_dd7wFzLY, 0.0f);
  numBytes += cVar_init_f(&cVar_dt67yyR2, 20.0f);
  numBytes += cVar_init_f(&cVar_B6xNNFYD, 0.0f);
  numBytes += cVar_init_f(&cVar_uSbT8saN, 0.0f);
  numBytes += cVar_init_f(&cVar_eyZZ3pZL, 0.0f);
  numBytes += cSlice_init(&cSlice_bTUCbMqb, 1, 1);
  numBytes += cSlice_init(&cSlice_4pwYQI55, 0, 1);
  numBytes += cBinop_init(&cBinop_vTgUKyC9, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_R4NGT6nx, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_AX6w4yy3, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_486P2IMR, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_PgyAnDzC, 20.0f); // __div
  numBytes += cBinop_init(&cBinop_SIiZcn4u, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_RqFhT3p9, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_MOBCWmjY, 0.0f); // __sub
  numBytes += cVar_init_s(&cVar_DnG6BMa0, "floatatom");
  numBytes += cDelay_init(this, &cDelay_qCMO8teq, 0.0f);
  numBytes += cVar_init_f(&cVar_LimWL3jb, 20.0f);
  numBytes += cBinop_init(&cBinop_zRwzOYgR, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_xyeFHQY7, 0.0f);
  numBytes += cSlice_init(&cSlice_MJ0G22IW, 1, -1);
  numBytes += cSlice_init(&cSlice_PB3shP67, 1, -1);
  numBytes += cVar_init_f(&cVar_nu6fPq21, 0.0f);
  numBytes += cVar_init_f(&cVar_OQOud2rS, 20.0f);
  numBytes += cVar_init_f(&cVar_nLwfxbG4, 0.0f);
  numBytes += cVar_init_f(&cVar_119JiQ1X, 0.0f);
  numBytes += cVar_init_f(&cVar_dRjtgjRd, 0.0f);
  numBytes += cSlice_init(&cSlice_XIRJg9Qg, 1, 1);
  numBytes += cSlice_init(&cSlice_gAmIWIq9, 0, 1);
  numBytes += cBinop_init(&cBinop_m1QqeOKy, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_s6zK2fFd, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_PDFGHtzS, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_WpkBxPvw, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_lpzxIi27, 20.0f); // __div
  numBytes += cBinop_init(&cBinop_gb7Apdkq, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_KSqJgAZ3, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_3gQkZXdH, 0.0f); // __sub
  numBytes += cPack_init(&cPack_HSpiA0OO, 2, 0.0f, 1000.0f);
  numBytes += cPack_init(&cPack_kXFfnPU1, 2, 0.0f, 1000.0f);
  numBytes += cPack_init(&cPack_SnSqMnRc, 2, 0.0f, 1000.0f);
  numBytes += cVar_init_f(&cVar_TuH5b9Yo, 100.0f);
  numBytes += cIf_init(&cIf_c5WljKov, false);
  numBytes += cBinop_init(&cBinop_2wr0Xvf5, 0.0f); // __pow
  numBytes += cPack_init(&cPack_1TzmywYg, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_ReOXdNEE, 0.0f);
  numBytes += cVar_init_f(&cVar_g4Bpzf2Q, 100.0f);
  numBytes += cIf_init(&cIf_oyyjS3Qr, false);
  numBytes += cBinop_init(&cBinop_vMYSiGUC, 0.0f); // __pow
  numBytes += cPack_init(&cPack_wTe331j2, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_61ONUGQJ, 0.0f);
  numBytes += cIf_init(&cIf_k3iId86a, false);
  numBytes += cIf_init(&cIf_324zeaYn, false);
  numBytes += cVar_init_f(&cVar_qYUDKa91, 97.0f);
  numBytes += cIf_init(&cIf_mAxgEf8c, false);
  numBytes += cBinop_init(&cBinop_1mn7H34x, 0.0f); // __pow
  numBytes += cPack_init(&cPack_6F89ZCCj, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_FRWHdrnN, 0.0f);
  numBytes += cVar_init_f(&cVar_JOcjshYM, 89.0f);
  numBytes += cIf_init(&cIf_nPSo9AE5, false);
  numBytes += cBinop_init(&cBinop_whEG4Ig2, 0.0f); // __pow
  numBytes += cPack_init(&cPack_lg0gCXZA, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_6DYfFFgu, 0.0f);
  numBytes += cVar_init_f(&cVar_Eaeu68ou, 97.0f);
  numBytes += cIf_init(&cIf_NjnWCxGE, false);
  numBytes += cBinop_init(&cBinop_Wjhvd4cJ, 0.0f); // __pow
  numBytes += cPack_init(&cPack_NxscTYms, 2, 0.0f, 10.0f);
  numBytes += cVar_init_f(&cVar_JUJXUbZL, 0.0f);
  numBytes += cPack_init(&cPack_cfKMRaSE, 2, 0.0f, 0.0f);
  numBytes += cSlice_init(&cSlice_3P6ee7E9, 1, 1);
  numBytes += cSlice_init(&cSlice_vFY2Ab3A, 0, 1);
  numBytes += cIf_init(&cIf_VFcTRfki, false);
  numBytes += cIf_init(&cIf_I8GORitp, false);
  numBytes += cIf_init(&cIf_K7cIEOGf, false);
  numBytes += cSlice_init(&cSlice_rBqKbWu5, 1, 1);
  numBytes += cSlice_init(&cSlice_Y4ymYJMJ, 0, 1);
  numBytes += cVar_init_f(&cVar_fOqcTO6h, 0.0f);
  numBytes += cIf_init(&cIf_SZYFN63k, false);
  numBytes += cPack_init(&cPack_uug9Nvpe, 2, 0.0f, 0.0f);
  numBytes += cSlice_init(&cSlice_naKUAxcS, 1, -1);
  numBytes += cSlice_init(&cSlice_kLSVbBme, 1, -1);
  numBytes += cSlice_init(&cSlice_OYMmqkuX, 1, -1);
  numBytes += cSlice_init(&cSlice_RBQIAbgh, 1, -1);
  numBytes += cIf_init(&cIf_L8GP2e5D, false);
  numBytes += cVar_init_f(&cVar_aQzJcq0l, 1.0f);
  numBytes += cPack_init(&cPack_uiQKWEt8, 3, 0.0f, 0.0f, 0.0f);
  numBytes += cVar_init_f(&cVar_a53F9EnR, 0.0f);
  
  // schedule a message to trigger all loadbangs via the __hv_init receiver
  scheduleMessageForReceiver(0xCE5CC65B, msg_initWithBang(HV_MESSAGE_ON_STACK(1), 0));
}

Heavy_PhaseRing::~Heavy_PhaseRing() {
  cPack_free(&cPack_Jzdhm5Yb);
  cPack_free(&cPack_AbB5bNvQ);
  cPack_free(&cPack_NFvoL6wi);
  cPack_free(&cPack_UcYdq4P5);
  cPack_free(&cPack_dwzpjVVs);
  cPack_free(&cPack_m7i5Gb0A);
  cPack_free(&cPack_FDZi6xaM);
  cPack_free(&cPack_5OIoexmP);
  cPack_free(&cPack_4ydY3gu5);
  cPack_free(&cPack_OxAJKTTJ);
  cPack_free(&cPack_LIXfGDXo);
  cPack_free(&cPack_PpfQqbnP);
  cPack_free(&cPack_pZvPIMg4);
  cPack_free(&cPack_ROtddZFW);
  cPack_free(&cPack_vwrQKZI6);
  cPack_free(&cPack_yeCJUcsL);
  cPack_free(&cPack_6Sad23V9);
  hTable_free(&hTable_hk8uR4SZ);
  hTable_free(&hTable_lxlLALuN);
  hTable_free(&hTable_OutROxhq);
  hTable_free(&hTable_LdIxdeSA);
  cPack_free(&cPack_Dr2kPUep);
  cPack_free(&cPack_UtJkCIRJ);
  hTable_free(&hTable_x1926MpT);
  hTable_free(&hTable_ASDeXuBy);
  hTable_free(&hTable_YVvjvH1Q);
  hTable_free(&hTable_OUSNvdru);
  hTable_free(&hTable_dbrOf1mE);
  hTable_free(&hTable_PF8nREmZ);
  cPack_free(&cPack_mcP6UC3C);
  cPack_free(&cPack_8J49SzJl);
  cPack_free(&cPack_zZXJDA0v);
  hTable_free(&hTable_dW7OaQK2);
  hTable_free(&hTable_rHA5FkX9);
  hTable_free(&hTable_3DbJfxpg);
  hTable_free(&hTable_3IFV6IkW);
  hTable_free(&hTable_88pSgIIG);
  cPack_free(&cPack_b2GzXqjm);
  cPack_free(&cPack_QAEz3vyM);
  hTable_free(&hTable_YVZi9ELj);
  hTable_free(&hTable_AD9rNiKP);
  hTable_free(&hTable_uvayZRpY);
  hTable_free(&hTable_RMwcv6FY);
  hTable_free(&hTable_owKST7i5);
  hTable_free(&hTable_T2zZRC6o);
  cPack_free(&cPack_EgR18v6D);
  hTable_free(&hTable_x6GDlK7A);
  cPack_free(&cPack_2Mtgs0Xo);
  cPack_free(&cPack_EIhy5NBR);
  cPack_free(&cPack_LRlh0V4F);
  hTable_free(&hTable_17BVN5Ee);
  hTable_free(&hTable_BnH9zZ2A);
  cPack_free(&cPack_HSpiA0OO);
  cPack_free(&cPack_kXFfnPU1);
  cPack_free(&cPack_SnSqMnRc);
  cPack_free(&cPack_1TzmywYg);
  cPack_free(&cPack_wTe331j2);
  cPack_free(&cPack_6F89ZCCj);
  cPack_free(&cPack_lg0gCXZA);
  cPack_free(&cPack_NxscTYms);
  cPack_free(&cPack_cfKMRaSE);
  cPack_free(&cPack_uug9Nvpe);
  cPack_free(&cPack_uiQKWEt8);
}

HvTable *Heavy_PhaseRing::getTableForHash(hv_uint32_t tableHash) {switch (tableHash) {
    case 0xB0671461: return &hTable_hk8uR4SZ; // del-1210-del1
    case 0xD3F5721F: return &hTable_lxlLALuN; // del-1210-del2
    case 0xC10D6C35: return &hTable_OutROxhq; // del-1210-del3
    case 0xB5FEED7B: return &hTable_LdIxdeSA; // del-1210-del4
    case 0x2A9662CE: return &hTable_x1926MpT; // del-1210-ref6
    case 0x3096656F: return &hTable_ASDeXuBy; // del-1210-ref5
    case 0x70243206: return &hTable_YVvjvH1Q; // del-1210-ref4
    case 0xEEED6608: return &hTable_OUSNvdru; // del-1210-ref3
    case 0xDBBB6EB0: return &hTable_dbrOf1mE; // del-1210-ref2
    case 0xB68B4BD4: return &hTable_PF8nREmZ; // del-1210-ref1
    case 0x405083F: return &hTable_dW7OaQK2; // del-1317-del
    case 0xF19F8B56: return &hTable_rHA5FkX9; // del-1380-del1
    case 0x308C8562: return &hTable_3DbJfxpg; // del-1380-del2
    case 0x21526483: return &hTable_3IFV6IkW; // del-1380-del3
    case 0xBE3EFFE1: return &hTable_88pSgIIG; // del-1380-del4
    case 0xEB7F6762: return &hTable_YVZi9ELj; // del-1380-ref6
    case 0x198895E2: return &hTable_AD9rNiKP; // del-1380-ref5
    case 0x28608A96: return &hTable_uvayZRpY; // del-1380-ref4
    case 0xAC336734: return &hTable_RMwcv6FY; // del-1380-ref3
    case 0xB3E48849: return &hTable_owKST7i5; // del-1380-ref2
    case 0x78A7871A: return &hTable_T2zZRC6o; // del-1380-ref1
    case 0xB4A4BA2: return &hTable_x6GDlK7A; // del-1479-del1
    case 0x74129230: return &hTable_17BVN5Ee; // del-1510-del
    case 0x3CFB0B3: return &hTable_BnH9zZ2A; // del-1539-del1
    default: return nullptr;
  }
}

void Heavy_PhaseRing::scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) {
  switch (receiverHash) {
    case 0x9DBB052E: { // 1057-att
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_T1X8bEvl_sendMessage);
      break;
    }
    case 0xF1DE93DD: { // 1057-envrel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_Nv5OWljY_sendMessage);
      break;
    }
    case 0x6CD381D4: { // 1057-envvol
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_JzLiDlwB_sendMessage);
      break;
    }
    case 0xCF6D3C3F: { // 1057-index
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_ExvrLLbX_sendMessage);
      break;
    }
    case 0xEDDFD30D: { // 1057-rel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_houNTp4F_sendMessage);
      break;
    }
    case 0xF2BA3B2A: { // 1057-vel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_JDOgHzIi_sendMessage);
      break;
    }
    case 0x4C999BDD: { // 1094-levelin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_4FRzEyY0_sendMessage);
      break;
    }
    case 0xB7ADD52E: { // 1094-levelout
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_2JIVmhmZ_sendMessage);
      break;
    }
    case 0x3A67A583: { // 1102-att
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_yPucuyRw_sendMessage);
      break;
    }
    case 0x106C8009: { // 1102-envrel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_SqqMOqSE_sendMessage);
      break;
    }
    case 0x42BC8229: { // 1102-envvol
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_dpijk8jP_sendMessage);
      break;
    }
    case 0xC1FC464: { // 1102-index
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_8kWYcDR8_sendMessage);
      break;
    }
    case 0x2189FF6C: { // 1102-rel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_Ts5SryUo_sendMessage);
      break;
    }
    case 0xEC7D062A: { // 1102-vel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_M0NFbTDl_sendMessage);
      break;
    }
    case 0xA936B970: { // 1138-att
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_Jsi2KsUT_sendMessage);
      break;
    }
    case 0x2A8844A1: { // 1138-envrel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_MSOHPAY8_sendMessage);
      break;
    }
    case 0xB529824: { // 1138-envvol
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_AkusoDBT_sendMessage);
      break;
    }
    case 0x9097A2AD: { // 1138-index
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_EN0yeAGn_sendMessage);
      break;
    }
    case 0x7F7D0117: { // 1138-rel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_iQVfA9MC_sendMessage);
      break;
    }
    case 0x574B730F: { // 1138-vel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_5S4XP6By_sendMessage);
      break;
    }
    case 0x585707AB: { // 1174-att
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_dmxv91Sr_sendMessage);
      break;
    }
    case 0x7B3A6787: { // 1174-envrel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_yQQq0HF1_sendMessage);
      break;
    }
    case 0xF29D7AC3: { // 1174-envvol
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_tFO6OEUW_sendMessage);
      break;
    }
    case 0x75F9193E: { // 1174-index
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_KDKDC1DZ_sendMessage);
      break;
    }
    case 0xB840EC84: { // 1174-rel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_aWis9EXq_sendMessage);
      break;
    }
    case 0x2F34E032: { // 1174-vel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_s4LpBP5s_sendMessage);
      break;
    }
    case 0xEA1C03D1: { // 1600-levelin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_K6kYGOoT_sendMessage);
      break;
    }
    case 0x6CD92272: { // 1600-levelout
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_EuF8WM5Q_sendMessage);
      break;
    }
    case 0x95ACE67F: { // 1608-levelin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_RTeaCjQs_sendMessage);
      break;
    }
    case 0x3FE1AFF3: { // 1608-levelout
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_m3j1YjTv_sendMessage);
      break;
    }
    case 0x17DE41C5: { // 1620-levelin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_Yggd9BMG_sendMessage);
      break;
    }
    case 0x8C4E88AD: { // 1620-levelout
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_e5WijMKm_sendMessage);
      break;
    }
    case 0x864A3907: { // 1628-levelin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_FaHapAJH_sendMessage);
      break;
    }
    case 0x7E3F5388: { // 1628-levelout
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_AH3Jw1fB_sendMessage);
      break;
    }
    case 0xF2EB190A: { // 1636-levelin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_eHDqS1ro_sendMessage);
      break;
    }
    case 0x4DD3A5BD: { // 1636-levelout
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_G1ZjrBZW_sendMessage);
      break;
    }
    case 0xCE5CC65B: { // __hv_init
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_qRUvZRqY_sendMessage);
      break;
    }
    case 0x67E37CA3: { // __hv_notein
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_s4ZhpCup_sendMessage);
      break;
    }
    case 0x40AA4AF1: { // changesound
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_RuhEF7ii_sendMessage);
      break;
    }
    case 0xA41806F7: { // distortlevel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_2tS2bTD5_sendMessage);
      break;
    }
    case 0xFCD12E4C: { // mastervolume
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_SlMi2liB_sendMessage);
      break;
    }
    case 0xEF5F3308: { // panTranslation
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_HbVaARHM_sendMessage);
      break;
    }
    case 0x58FBFA93: { // phaseFreq
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_fPanzfoc_sendMessage);
      break;
    }
    case 0x8B2148DD: { // pitch
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_DjA1XxId_sendMessage);
      break;
    }
    case 0x4409C659: { // processeffects
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_X9il3AO2_sendMessage);
      break;
    }
    case 0x7B795C5A: { // resetsing
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_G9qUHfjt_sendMessage);
      break;
    }
    case 0xA987B741: { // reverbvolume
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_fgs3rCYw_sendMessage);
      break;
    }
    case 0x7AAE6786: { // sinPanAngle
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_9Ig8YbV4_sendMessage);
      break;
    }
    case 0x6731B2E0: { // sing
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_PFWEuaTR_sendMessage);
      break;
    }
    case 0x57292445: { // singlevel
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_Y8q0WfVZ_sendMessage);
      break;
    }
    case 0xC7DE3B07: { // singpitch
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_ameDsnCC_sendMessage);
      break;
    }
    case 0x4E809B1C: { // testbutton
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_wZeMyHKU_sendMessage);
      break;
    }
    case 0x853B1BE7: { // velocity
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_yJ1v9AAQ_sendMessage);
      break;
    }
    default: return;
  }
}

int Heavy_PhaseRing::getParameterInfo(int index, HvParameterInfo *info) {
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


void Heavy_PhaseRing::cSlice_t152vozy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_zZZLCWrn_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cSlice_R7G9iIVs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cIf_onMessage(_c, &Context(_c)->cIf_iU6nTGXy, 0, m, &cIf_iU6nTGXy_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_QcRXjCqW, 0, m, &cIf_QcRXjCqW_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cSlice_N7p4BpPZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cIf_onMessage(_c, &Context(_c)->cIf_8FXYppWY, 0, m, &cIf_8FXYppWY_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_5i1cOaaL, 0, m, &cIf_5i1cOaaL_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cVar_01ZVbxBp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_uDkU8Ndq_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_Qfq0NVSj, 0, m, &cIf_Qfq0NVSj_sendMessage);
}

void Heavy_PhaseRing::cUnop_y8m75pUe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_0ttO5ajK_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_uYFjaLmz, HV_BINOP_EQ, 1, m, &cBinop_uYFjaLmz_sendMessage);
}

void Heavy_PhaseRing::cUnop_1hiBJwqF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_0ttO5ajK_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_uYFjaLmz, HV_BINOP_EQ, 1, m, &cBinop_uYFjaLmz_sendMessage);
}

void Heavy_PhaseRing::cIf_Qfq0NVSj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_1hiBJwqF_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_y8m75pUe_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_uDkU8Ndq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_Qfq0NVSj, 1, m, &cIf_Qfq0NVSj_sendMessage);
}

void Heavy_PhaseRing::cIf_QcRXjCqW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSend_jDDBRUsK_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cIf_5i1cOaaL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSend_EdQSfCDP_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cIf_iU6nTGXy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSend_jDDBRUsK_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cIf_8FXYppWY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSend_EdQSfCDP_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_zZZLCWrn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_uYFjaLmz, HV_BINOP_EQ, 0, m, &cBinop_uYFjaLmz_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_WXTihJQw_sendMessage);
}

void Heavy_PhaseRing::cBinop_0ttO5ajK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ikWwo42H_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_fiVLLKaV_sendMessage);
}

void Heavy_PhaseRing::cBinop_uYFjaLmz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_QgIweRgd_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_pZpHAu7P_sendMessage);
}

void Heavy_PhaseRing::cCast_QgIweRgd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_QcRXjCqW, 1, m, &cIf_QcRXjCqW_sendMessage);
}

void Heavy_PhaseRing::cCast_pZpHAu7P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_8FXYppWY, 1, m, &cIf_8FXYppWY_sendMessage);
}

void Heavy_PhaseRing::cCast_fiVLLKaV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_5i1cOaaL, 1, m, &cIf_5i1cOaaL_sendMessage);
}

void Heavy_PhaseRing::cCast_ikWwo42H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_iU6nTGXy, 1, m, &cIf_iU6nTGXy_sendMessage);
}

void Heavy_PhaseRing::cBinop_WXTihJQw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_YJzOet2d_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_hzyyv2Rl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_qeQUI1Uf, 0, m, &cVar_qeQUI1Uf_sendMessage);
}

void Heavy_PhaseRing::cBinop_wtZ9WGDr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_eKkja9U9_sendMessage);
}

void Heavy_PhaseRing::cBinop_eKkja9U9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_B0NVdsVR, HV_BINOP_POW, 1, m, &cBinop_B0NVdsVR_sendMessage);
  cMsg_dGCl5r5k_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_B0NVdsVR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_hzyyv2Rl_sendMessage);
}

void Heavy_PhaseRing::cMsg_dGCl5r5k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_B0NVdsVR, HV_BINOP_POW, 0, m, &cBinop_B0NVdsVR_sendMessage);
}

void Heavy_PhaseRing::cBinop_UeUan7L0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_0qol9gyr_sendMessage);
}

void Heavy_PhaseRing::cBinop_0qol9gyr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_FIqdrwOo_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_lnBKBmCo_sendMessage);
}

void Heavy_PhaseRing::cVar_DmH27y1p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_n8S8lqCi_sendMessage);
}

void Heavy_PhaseRing::cMsg_e10rBvPP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_kRrWt38E_sendMessage);
}

void Heavy_PhaseRing::cSystem_kRrWt38E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_cbnNemAY, HV_BINOP_DIVIDE, 1, m, &cBinop_cbnNemAY_sendMessage);
}

void Heavy_PhaseRing::cBinop_FIqdrwOo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_yAitqWfu_sendMessage);
}

void Heavy_PhaseRing::cBinop_yAitqWfu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_qThy7gmp, m);
}

void Heavy_PhaseRing::cMsg_LnmhHHn8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_pw5Jklli_sendMessage);
}

void Heavy_PhaseRing::cBinop_pw5Jklli_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_UeUan7L0_sendMessage);
}

void Heavy_PhaseRing::cBinop_lnBKBmCo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_4MfzdEiX, m);
}

void Heavy_PhaseRing::cBinop_n8S8lqCi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_u3YmUhtd_sendMessage);
}

void Heavy_PhaseRing::cBinop_u3YmUhtd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_cbnNemAY, HV_BINOP_DIVIDE, 0, m, &cBinop_cbnNemAY_sendMessage);
}

void Heavy_PhaseRing::cBinop_cbnNemAY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_LnmhHHn8_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cPack_Jzdhm5Yb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_grwHmHUl, 0, m, NULL);
}

void Heavy_PhaseRing::cVar_Dn7qHgRv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_UKwkOWzp_sendMessage);
}

void Heavy_PhaseRing::cVar_qeQUI1Uf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_JaqReih0, 0, m);
}

void Heavy_PhaseRing::cIf_IHrogl3L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 0.0f, 0, m, &cBinop_XR5xAh9W_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_FeeFl7Pq, 0, m, &cIf_FeeFl7Pq_sendMessage);
      break;
    }
    case 1: {
      cMsg_91HrgqwC_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_1EYqqImq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_IHrogl3L, 1, m, &cIf_IHrogl3L_sendMessage);
}

void Heavy_PhaseRing::cIf_FeeFl7Pq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_gxnqjtuu_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.2f, 0, m, &cBinop_kov1QnF0_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_XR5xAh9W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_FeeFl7Pq, 1, m, &cIf_FeeFl7Pq_sendMessage);
}

void Heavy_PhaseRing::cMsg_91HrgqwC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.2f, 0, m, &cBinop_kov1QnF0_sendMessage);
}

void Heavy_PhaseRing::cMsg_gxnqjtuu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.2f, 0, m, &cBinop_kov1QnF0_sendMessage);
}

void Heavy_PhaseRing::cIf_aNHrILee_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 0.0f, 0, m, &cBinop_NIod3W4E_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_GEQwZJLR, 0, m, &cIf_GEQwZJLR_sendMessage);
      break;
    }
    case 1: {
      cMsg_zd9beask_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_wE3JXZFg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_aNHrILee, 1, m, &cIf_aNHrILee_sendMessage);
}

void Heavy_PhaseRing::cIf_GEQwZJLR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_BkZVjGB4_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cPack_onMessage(_c, &Context(_c)->cPack_NFvoL6wi, 0, m, &cPack_NFvoL6wi_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_NIod3W4E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_GEQwZJLR, 1, m, &cIf_GEQwZJLR_sendMessage);
}

void Heavy_PhaseRing::cMsg_zd9beask_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_NFvoL6wi, 0, m, &cPack_NFvoL6wi_sendMessage);
}

void Heavy_PhaseRing::cMsg_BkZVjGB4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_NFvoL6wi, 0, m, &cPack_NFvoL6wi_sendMessage);
}

void Heavy_PhaseRing::cPack_AbB5bNvQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_0jMSPHJD, 0, m, NULL);
}

void Heavy_PhaseRing::cPack_NFvoL6wi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_KWnuyXK0, 0, m, NULL);
}

void Heavy_PhaseRing::cPack_UcYdq4P5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_bh3mAzj0, 0, m, NULL);
}

void Heavy_PhaseRing::cBinop_UKwkOWzp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.1f, 0, m, &cBinop_7dT0S1vQ_sendMessage);
}

void Heavy_PhaseRing::cBinop_FFVLC2zk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Dn7qHgRv, 0, m, &cVar_Dn7qHgRv_sendMessage);
}

void Heavy_PhaseRing::cBinop_7dT0S1vQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_Jzdhm5Yb, 0, m, &cPack_Jzdhm5Yb_sendMessage);
}

void Heavy_PhaseRing::cBinop_kov1QnF0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5f, 0, m, &cBinop_oCLlUbMT_sendMessage);
}

void Heavy_PhaseRing::cBinop_oCLlUbMT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_wE3JXZFg_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_aNHrILee, 0, m, &cIf_aNHrILee_sendMessage);
}

void Heavy_PhaseRing::cCast_VcADsDTx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_MaY7iZ0G_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_Rio2JPMN_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cSwitchcase_MaY7iZ0G_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_GuFN7Ce2, 0, m, &cSlice_GuFN7Ce2_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_VpTHgJ6p, 0, m, &cRandom_VpTHgJ6p_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_kZacv7kf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_1ypGjkxH_sendMessage);
}

void Heavy_PhaseRing::cUnop_1ypGjkxH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_J8lMDuOJ, 0, m, &cVar_J8lMDuOJ_sendMessage);
}

void Heavy_PhaseRing::cRandom_VpTHgJ6p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 128.0f, 0, m, &cBinop_kZacv7kf_sendMessage);
}

void Heavy_PhaseRing::cSlice_GuFN7Ce2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_VpTHgJ6p, 1, m, &cRandom_VpTHgJ6p_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cVar_J8lMDuOJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_pzweIGx9_sendMessage(_c, 0, m);
  cSend_sRilQPbl_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_Rio2JPMN_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_a8Jk5wKz, 0, m, &cSlice_a8Jk5wKz_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_e6f64zA1, 0, m, &cRandom_e6f64zA1_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_HBHK5dQ1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_kbsTagXs_sendMessage);
}

void Heavy_PhaseRing::cUnop_kbsTagXs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1.28f, 0, m, &cBinop_WI9a6Hvo_sendMessage);
  cSend_gWGoitPG_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cRandom_e6f64zA1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 128.0f, 0, m, &cBinop_HBHK5dQ1_sendMessage);
}

void Heavy_PhaseRing::cSlice_a8Jk5wKz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_e6f64zA1, 1, m, &cRandom_e6f64zA1_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cVar_hSWX9zQC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_9p8Q1xJY_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cVar_l6KRBcSw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_Rz7Udmtv_sendMessage);
}

void Heavy_PhaseRing::cBinop_Rz7Udmtv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_l6KRBcSw, 1, m, &cVar_l6KRBcSw_sendMessage);
}

void Heavy_PhaseRing::cCast_F8WGMsjh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cVar_d3oUWrVK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cVar_Rg9blt1C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cCast_marwEZ4c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_P9emeZe2_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_WI9a6Hvo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_hSWX9zQC, 0, m, &cVar_hSWX9zQC_sendMessage);
}

void Heavy_PhaseRing::cSend_9p8Q1xJY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_Y8q0WfVZ_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_pzweIGx9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_DjA1XxId_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_gWGoitPG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_yJ1v9AAQ_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_sRilQPbl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_ameDsnCC_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_UN279QYD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.8f);
  cSend_spfPQSuj_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_spfPQSuj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_HbVaARHM_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_k872PsTW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSend_spfPQSuj_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_P9emeZe2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_RuhEF7ii_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_kAFTulCR_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_twY6tbPv, 0, m, &cSlice_twY6tbPv_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_DPwLP8zX, 0, m, &cRandom_DPwLP8zX_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_ulPAaDkc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_fsjYM75U_sendMessage);
}

void Heavy_PhaseRing::cUnop_fsjYM75U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 50.0f, 0, m, &cBinop_3ldLjlYp_sendMessage);
}

void Heavy_PhaseRing::cRandom_DPwLP8zX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 900.0f, 0, m, &cBinop_ulPAaDkc_sendMessage);
}

void Heavy_PhaseRing::cSlice_twY6tbPv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_DPwLP8zX, 1, m, &cRandom_DPwLP8zX_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cSwitchcase_gOTbLInu_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_rQvKBxkN, 0, m, &cSlice_rQvKBxkN_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_vm83XZye, 0, m, &cRandom_vm83XZye_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_bQqkbPFW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_9WjsYp5K_sendMessage);
}

void Heavy_PhaseRing::cUnop_9WjsYp5K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 50.0f, 0, m, &cBinop_oxGxCIt5_sendMessage);
}

void Heavy_PhaseRing::cRandom_vm83XZye_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 200.0f, 0, m, &cBinop_bQqkbPFW_sendMessage);
}

void Heavy_PhaseRing::cSlice_rQvKBxkN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_vm83XZye, 1, m, &cRandom_vm83XZye_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cSwitchcase_gqxHfboE_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_qFsmSlso, 0, m, &cSlice_qFsmSlso_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_0Zz6mSgJ, 0, m, &cRandom_0Zz6mSgJ_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_L5Kx6EYr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_dlvGFZEe_sendMessage);
}

void Heavy_PhaseRing::cUnop_dlvGFZEe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_ocEH4jb4_sendMessage);
}

void Heavy_PhaseRing::cRandom_0Zz6mSgJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_L5Kx6EYr_sendMessage);
}

void Heavy_PhaseRing::cSlice_qFsmSlso_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_0Zz6mSgJ, 1, m, &cRandom_0Zz6mSgJ_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_P03JFccp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_SxeCvDOi, HV_BINOP_MULTIPLY, 0, m, &cBinop_SxeCvDOi_sendMessage);
}

void Heavy_PhaseRing::cBinop_HTFb5Bbo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_2HhtlEBv_sendMessage);
}

void Heavy_PhaseRing::cBinop_2HhtlEBv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4SEAAyeN, HV_BINOP_POW, 1, m, &cBinop_4SEAAyeN_sendMessage);
  cMsg_OKFQaxAs_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_4SEAAyeN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_P03JFccp_sendMessage);
}

void Heavy_PhaseRing::cMsg_OKFQaxAs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_4SEAAyeN, HV_BINOP_POW, 0, m, &cBinop_4SEAAyeN_sendMessage);
}

void Heavy_PhaseRing::cSwitchcase_oHJhJguH_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_RVeDvs4A, 0, m, &cSlice_RVeDvs4A_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_3SYa5Baw, 0, m, &cRandom_3SYa5Baw_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_9w8ixDjF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_C7LD2eNI_sendMessage);
}

void Heavy_PhaseRing::cUnop_C7LD2eNI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_rYaOcu0V_sendMessage);
}

void Heavy_PhaseRing::cRandom_3SYa5Baw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 15.0f, 0, m, &cBinop_9w8ixDjF_sendMessage);
}

void Heavy_PhaseRing::cSlice_RVeDvs4A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_3SYa5Baw, 1, m, &cRandom_3SYa5Baw_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cPack_dwzpjVVs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_Vnqry04P, 0, m, NULL);
}

void Heavy_PhaseRing::cVar_TnESUc3i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_AxNIXJWr_sendMessage);
}

void Heavy_PhaseRing::cVar_pYF2rsxM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_8xjvbFM4, 0, m);
}

void Heavy_PhaseRing::cVar_VKP3VFKA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_2h68xAfX, 0, m);
}

void Heavy_PhaseRing::cVar_ggZbEbIr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_oSwEG6OC_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_5wE0XJ0q_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_dcxgcLAt_sendMessage);
}

void Heavy_PhaseRing::cCast_cfOaRKfu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cVar_iz6ZM54m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cVar_8o20CKEB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cVar_yM5d0sHz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cSwitchcase_utBXdcxY_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_GktA2BrD_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_GktA2BrD_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_fYQxGE0m, 1, m, &cDelay_fYQxGE0m_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_s3pFkgSc_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cDelay_fYQxGE0m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_fYQxGE0m, m);
  cVar_onMessage(_c, &Context(_c)->cVar_fQNf48LS, 0, m, &cVar_fQNf48LS_sendMessage);
}

void Heavy_PhaseRing::cMsg_GktA2BrD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_fYQxGE0m, 0, m, &cDelay_fYQxGE0m_sendMessage);
}

void Heavy_PhaseRing::cCast_s3pFkgSc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_fYQxGE0m, 0, m, &cDelay_fYQxGE0m_sendMessage);
}

void Heavy_PhaseRing::cVar_fQNf48LS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_JwFwF4gf_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cCast_tuqjqOpx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ggZbEbIr, 0, m, &cVar_ggZbEbIr_sendMessage);
}

void Heavy_PhaseRing::cMsg_eA2EBN5F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 25.0f);
  cSend_yPVyqpeu_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_W3XgenVh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 4000.0f);
  cSend_gnSiGgBE_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_pYWtGf0L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSend_Vg2yx9tY_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_HMTYrv4g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_Nv5OWljY_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_SPfM46CO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cSend_p69Ew7PL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_JzLiDlwB_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_yPVyqpeu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cSend_gnSiGgBE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_Nv5OWljY_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_Vg2yx9tY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_JzLiDlwB_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_djoofizf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 25.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_0FiL2UtP, 0, m, NULL);
}

void Heavy_PhaseRing::cMsg_JwFwF4gf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 0);
  sLine_onMessage(_c, &Context(_c)->sLine_0FiL2UtP, 0, m, NULL);
}

void Heavy_PhaseRing::cCast_dcxgcLAt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_utBXdcxY_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cCast_5wE0XJ0q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_fQNf48LS, 1, m, &cVar_fQNf48LS_sendMessage);
}

void Heavy_PhaseRing::cCast_oSwEG6OC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_djoofizf_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cCast_TEI03sLt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cUnop_FPfJPjkm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_FDZi6xaM, 0, m, &cPack_FDZi6xaM_sendMessage);
}

void Heavy_PhaseRing::cUnop_hqOR4L48_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_m7i5Gb0A, 0, m, &cPack_m7i5Gb0A_sendMessage);
}

void Heavy_PhaseRing::cPack_m7i5Gb0A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_lJJYPFY0, 0, m, NULL);
}

void Heavy_PhaseRing::cPack_FDZi6xaM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_pqDwP36A, 0, m, NULL);
}

void Heavy_PhaseRing::cBinop_dPVV4Su2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_FPfJPjkm_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_SIN, m, &cUnop_hqOR4L48_sendMessage);
}

void Heavy_PhaseRing::cMsg_qI7ca1qn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.5f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_dPVV4Su2_sendMessage);
}

void Heavy_PhaseRing::cSlice_ChSpvips_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 127.0f, 0, m, &cBinop_cLoGasZi_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cSlice_99pisYur_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_JLXz4EPm_sendMessage);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_HTFb5Bbo_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_ocEH4jb4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.4f, 0, m, &cBinop_eecEY1Qf_sendMessage);
}

void Heavy_PhaseRing::cBinop_eecEY1Qf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_dPVV4Su2_sendMessage);
}

void Heavy_PhaseRing::cBinop_cLoGasZi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_o3Lm04MN_sendMessage(_c, 0, m);
  cSend_3VKGhAp9_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_SxeCvDOi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_8ootrexv_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_qft6vqbm_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_VKP3VFKA, 0, m, &cVar_VKP3VFKA_sendMessage);
}

void Heavy_PhaseRing::cBinop_rYaOcu0V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.99f, 0, m, &cBinop_Zj9sofPT_sendMessage);
}

void Heavy_PhaseRing::cBinop_Zj9sofPT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_SxeCvDOi, HV_BINOP_MULTIPLY, 1, m, &cBinop_SxeCvDOi_sendMessage);
}

void Heavy_PhaseRing::cCast_JLXz4EPm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_oHJhJguH_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cSend_o3Lm04MN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_JDOgHzIi_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cCast_qft6vqbm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_gqxHfboE_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cCast_8ootrexv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_tuqjqOpx_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_TEI03sLt_sendMessage);
}

void Heavy_PhaseRing::cBinop_AxNIXJWr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_dwzpjVVs, 0, m, &cPack_dwzpjVVs_sendMessage);
}

void Heavy_PhaseRing::cSend_3VKGhAp9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_ExvrLLbX_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_37o1T9iq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_houNTp4F_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_ACSgB3AO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 200.0f);
  cSend_37o1T9iq_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cVar_UpZ3dMgq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_zXvzpKFl_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_NG1ZfrJS_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ajFkWJnt_sendMessage);
}

void Heavy_PhaseRing::cIf_t1HvB1O9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_9psbPNUi_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_bpbjjVDC_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cMsg_ZL7AzGYI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_GWBszAwt, HV_BINOP_POW, 0, m, &cBinop_GWBszAwt_sendMessage);
}

void Heavy_PhaseRing::cBinop_GWBszAwt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_5OIoexmP, 0, m, &cPack_5OIoexmP_sendMessage);
}

void Heavy_PhaseRing::cBinop_4k3LWMPT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_GXksMi6N_sendMessage);
}

void Heavy_PhaseRing::cCast_ajFkWJnt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_t1HvB1O9, 0, m, &cIf_t1HvB1O9_sendMessage);
}

void Heavy_PhaseRing::cCast_NG1ZfrJS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_ueQq0zKR_sendMessage);
}

void Heavy_PhaseRing::cBinop_ueQq0zKR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_t1HvB1O9, 1, m, &cIf_t1HvB1O9_sendMessage);
}

void Heavy_PhaseRing::cBinop_bpbjjVDC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_4k3LWMPT_sendMessage);
}

void Heavy_PhaseRing::cMsg_9psbPNUi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_5OIoexmP, 0, m, &cPack_5OIoexmP_sendMessage);
}

void Heavy_PhaseRing::cBinop_GXksMi6N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_GWBszAwt, HV_BINOP_POW, 1, m, &cBinop_GWBszAwt_sendMessage);
  cMsg_ZL7AzGYI_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cPack_5OIoexmP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_lL5QB7I5, 0, m, NULL);
}

void Heavy_PhaseRing::cVar_xMBWSgGD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_ojpj12tM_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_zXvzpKFl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSend_ahUGH15I_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_ahUGH15I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_4FRzEyY0_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_ojpj12tM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_2JIVmhmZ_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_Gj2I9cHP_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_vEM3AGRr, 0, m, &cSlice_vEM3AGRr_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_fqCDhpKa, 0, m, &cRandom_fqCDhpKa_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_mPA32JKv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_7LuQzweq_sendMessage);
}

void Heavy_PhaseRing::cUnop_7LuQzweq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_f49HjQTp_sendMessage);
}

void Heavy_PhaseRing::cRandom_fqCDhpKa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_mPA32JKv_sendMessage);
}

void Heavy_PhaseRing::cSlice_vEM3AGRr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_fqCDhpKa, 1, m, &cRandom_fqCDhpKa_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_ZjRNTx4O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_gH52d7pI, HV_BINOP_MULTIPLY, 0, m, &cBinop_gH52d7pI_sendMessage);
}

void Heavy_PhaseRing::cBinop_d1z37A4F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_9OWieY47_sendMessage);
}

void Heavy_PhaseRing::cBinop_9OWieY47_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Db3j0yUa, HV_BINOP_POW, 1, m, &cBinop_Db3j0yUa_sendMessage);
  cMsg_qnYnaIeC_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_Db3j0yUa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_ZjRNTx4O_sendMessage);
}

void Heavy_PhaseRing::cMsg_qnYnaIeC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_Db3j0yUa, HV_BINOP_POW, 0, m, &cBinop_Db3j0yUa_sendMessage);
}

void Heavy_PhaseRing::cSwitchcase_0ZEz2adq_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_Nr747al7, 0, m, &cSlice_Nr747al7_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_bIL6R9KT, 0, m, &cRandom_bIL6R9KT_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_vO1F0gex_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_2MRsLSeW_sendMessage);
}

void Heavy_PhaseRing::cUnop_2MRsLSeW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_LOlH2wTW_sendMessage);
}

void Heavy_PhaseRing::cRandom_bIL6R9KT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 15.0f, 0, m, &cBinop_vO1F0gex_sendMessage);
}

void Heavy_PhaseRing::cSlice_Nr747al7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_bIL6R9KT, 1, m, &cRandom_bIL6R9KT_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cPack_4ydY3gu5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_Ei8Ad6TM, 0, m, NULL);
}

void Heavy_PhaseRing::cVar_o0CYjto4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_etyIjOeX_sendMessage);
}

void Heavy_PhaseRing::cVar_4rvMlW8n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_hXgxF3mQ, 0, m);
}

void Heavy_PhaseRing::cVar_MqY9ptxz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_3t5OeHne, 0, m);
}

void Heavy_PhaseRing::cVar_HPyzL3XY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_iOfk4bbr_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_QdmlQTfw_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_MwrGJSk4_sendMessage);
}

void Heavy_PhaseRing::cCast_O7hrWydY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cVar_qtRNSrp1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cVar_uKGIor9U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cVar_eDfkzju1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cSwitchcase_dsNdd18E_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_utIjPIdh_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_utIjPIdh_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_6DtpdvKW, 1, m, &cDelay_6DtpdvKW_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_DT4gxNTN_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cDelay_6DtpdvKW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_6DtpdvKW, m);
  cVar_onMessage(_c, &Context(_c)->cVar_He7iKBnF, 0, m, &cVar_He7iKBnF_sendMessage);
}

void Heavy_PhaseRing::cMsg_utIjPIdh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_6DtpdvKW, 0, m, &cDelay_6DtpdvKW_sendMessage);
}

void Heavy_PhaseRing::cCast_DT4gxNTN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_6DtpdvKW, 0, m, &cDelay_6DtpdvKW_sendMessage);
}

void Heavy_PhaseRing::cVar_He7iKBnF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_2se0ozpg_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cCast_1vl3WEK5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_HPyzL3XY, 0, m, &cVar_HPyzL3XY_sendMessage);
}

void Heavy_PhaseRing::cMsg_izBttSKD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 25.0f);
  cSend_EiZzLzEd_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_pHBE2kUj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 4000.0f);
  cSend_RykxKnyd_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_C2VDyfXt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSend_dG9nQ3rt_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_fT6hIj95_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_SqqMOqSE_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_DxUMSgFj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cSend_cxbaGcO3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_dpijk8jP_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_EiZzLzEd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cSend_RykxKnyd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_SqqMOqSE_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_dG9nQ3rt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_dpijk8jP_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_Fid8bVUA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 25.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_SyuuZYQq, 0, m, NULL);
}

void Heavy_PhaseRing::cMsg_2se0ozpg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 0);
  sLine_onMessage(_c, &Context(_c)->sLine_SyuuZYQq, 0, m, NULL);
}

void Heavy_PhaseRing::cCast_QdmlQTfw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_He7iKBnF, 1, m, &cVar_He7iKBnF_sendMessage);
}

void Heavy_PhaseRing::cCast_MwrGJSk4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_dsNdd18E_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cCast_iOfk4bbr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Fid8bVUA_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cCast_R3s0CoVt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cUnop_cSMTsXAo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_LIXfGDXo, 0, m, &cPack_LIXfGDXo_sendMessage);
}

void Heavy_PhaseRing::cUnop_GQ1CQG2E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_OxAJKTTJ, 0, m, &cPack_OxAJKTTJ_sendMessage);
}

void Heavy_PhaseRing::cPack_OxAJKTTJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_tbWCPgeO, 0, m, NULL);
}

void Heavy_PhaseRing::cPack_LIXfGDXo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_hR0mzLSV, 0, m, NULL);
}

void Heavy_PhaseRing::cBinop_Th2NiTKm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_cSMTsXAo_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_SIN, m, &cUnop_GQ1CQG2E_sendMessage);
}

void Heavy_PhaseRing::cMsg_a8lzoC4W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.5f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_Th2NiTKm_sendMessage);
}

void Heavy_PhaseRing::cSlice_1mX6OInW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 127.0f, 0, m, &cBinop_uYynLvIq_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cSlice_sO28ZsSo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_IxMhoha8_sendMessage);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_d1z37A4F_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_f49HjQTp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.4f, 0, m, &cBinop_wVSzS7QZ_sendMessage);
}

void Heavy_PhaseRing::cBinop_wVSzS7QZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_Th2NiTKm_sendMessage);
}

void Heavy_PhaseRing::cBinop_uYynLvIq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_b6ibrWCh_sendMessage(_c, 0, m);
  cSend_K6TQ5M6w_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_gH52d7pI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_FI2AlxMy_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_wyThFyUg_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_MqY9ptxz, 0, m, &cVar_MqY9ptxz_sendMessage);
}

void Heavy_PhaseRing::cBinop_LOlH2wTW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.99f, 0, m, &cBinop_57eevXhS_sendMessage);
}

void Heavy_PhaseRing::cBinop_57eevXhS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_gH52d7pI, HV_BINOP_MULTIPLY, 1, m, &cBinop_gH52d7pI_sendMessage);
}

void Heavy_PhaseRing::cCast_IxMhoha8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_0ZEz2adq_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cSend_b6ibrWCh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_M0NFbTDl_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cCast_FI2AlxMy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_1vl3WEK5_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_R3s0CoVt_sendMessage);
}

void Heavy_PhaseRing::cCast_wyThFyUg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_Gj2I9cHP_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cBinop_etyIjOeX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_4ydY3gu5, 0, m, &cPack_4ydY3gu5_sendMessage);
}

void Heavy_PhaseRing::cSend_K6TQ5M6w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_8kWYcDR8_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_KkJ3punb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_Ts5SryUo_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_94Z8kmJ1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 200.0f);
  cSend_KkJ3punb_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_lk18C10L_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_1KTvIfR4, 0, m, &cSlice_1KTvIfR4_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_4SblHlb5, 0, m, &cRandom_4SblHlb5_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_k4VmS1SF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_QvuxJDAC_sendMessage);
}

void Heavy_PhaseRing::cUnop_QvuxJDAC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_hdsFJIsg_sendMessage);
}

void Heavy_PhaseRing::cRandom_4SblHlb5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_k4VmS1SF_sendMessage);
}

void Heavy_PhaseRing::cSlice_1KTvIfR4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_4SblHlb5, 1, m, &cRandom_4SblHlb5_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_rcfWJQ3G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MCX8JOoK, HV_BINOP_MULTIPLY, 0, m, &cBinop_MCX8JOoK_sendMessage);
}

void Heavy_PhaseRing::cBinop_hbCkV52I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_cutydHsC_sendMessage);
}

void Heavy_PhaseRing::cBinop_cutydHsC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_btNWu7g2, HV_BINOP_POW, 1, m, &cBinop_btNWu7g2_sendMessage);
  cMsg_VxejpwS2_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_btNWu7g2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_rcfWJQ3G_sendMessage);
}

void Heavy_PhaseRing::cMsg_VxejpwS2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_btNWu7g2, HV_BINOP_POW, 0, m, &cBinop_btNWu7g2_sendMessage);
}

void Heavy_PhaseRing::cSwitchcase_8MIX15oX_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_MOMTkd4O, 0, m, &cSlice_MOMTkd4O_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_At03ZDoQ, 0, m, &cRandom_At03ZDoQ_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_JDj3ksTg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_m3VhAblL_sendMessage);
}

void Heavy_PhaseRing::cUnop_m3VhAblL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_YwgvP8p6_sendMessage);
}

void Heavy_PhaseRing::cRandom_At03ZDoQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 15.0f, 0, m, &cBinop_JDj3ksTg_sendMessage);
}

void Heavy_PhaseRing::cSlice_MOMTkd4O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_At03ZDoQ, 1, m, &cRandom_At03ZDoQ_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cPack_PpfQqbnP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_ovVB64wb, 0, m, NULL);
}

void Heavy_PhaseRing::cVar_jICr70ZL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_4k5IKJI9_sendMessage);
}

void Heavy_PhaseRing::cVar_328UnsqH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_NfUPZeBd, 0, m);
}

void Heavy_PhaseRing::cVar_vGgZ7YPI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_1M3FhNn6, 0, m);
}

void Heavy_PhaseRing::cVar_LdK2880n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_krs0B2c6_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_b4pch0GY_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_kLsmjMp7_sendMessage);
}

void Heavy_PhaseRing::cCast_qWOV8S4i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cVar_2HiJmuno_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cVar_0TAJRVHO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cVar_lo2HXstj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cSwitchcase_xplH8nWj_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_3fyNZa2s_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_3fyNZa2s_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_PRBpC8wr, 1, m, &cDelay_PRBpC8wr_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_aTy4Ehdq_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cDelay_PRBpC8wr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_PRBpC8wr, m);
  cVar_onMessage(_c, &Context(_c)->cVar_2IslpTAh, 0, m, &cVar_2IslpTAh_sendMessage);
}

void Heavy_PhaseRing::cMsg_3fyNZa2s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_PRBpC8wr, 0, m, &cDelay_PRBpC8wr_sendMessage);
}

void Heavy_PhaseRing::cCast_aTy4Ehdq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_PRBpC8wr, 0, m, &cDelay_PRBpC8wr_sendMessage);
}

void Heavy_PhaseRing::cVar_2IslpTAh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_cSotblGQ_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cCast_g194TxtX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_LdK2880n, 0, m, &cVar_LdK2880n_sendMessage);
}

void Heavy_PhaseRing::cMsg_UHUvrq52_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 25.0f);
  cSend_pDB5vHpC_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_uA1NvSwS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 4000.0f);
  cSend_ezBWkoXQ_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_6SpKZ2en_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSend_OrFfNTiM_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_Tf9sMAjj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_MSOHPAY8_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_OmQmmaTB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cSend_7GHoLK5f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_AkusoDBT_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_pDB5vHpC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cSend_ezBWkoXQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_MSOHPAY8_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_OrFfNTiM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_AkusoDBT_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_t1GVWtWe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 25.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_7fBIVWou, 0, m, NULL);
}

void Heavy_PhaseRing::cMsg_cSotblGQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 0);
  sLine_onMessage(_c, &Context(_c)->sLine_7fBIVWou, 0, m, NULL);
}

void Heavy_PhaseRing::cCast_b4pch0GY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_2IslpTAh, 1, m, &cVar_2IslpTAh_sendMessage);
}

void Heavy_PhaseRing::cCast_kLsmjMp7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_xplH8nWj_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cCast_krs0B2c6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_t1GVWtWe_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cCast_6zgR14BN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cUnop_20yTW3wZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_ROtddZFW, 0, m, &cPack_ROtddZFW_sendMessage);
}

void Heavy_PhaseRing::cUnop_h7fiuYnS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_pZvPIMg4, 0, m, &cPack_pZvPIMg4_sendMessage);
}

void Heavy_PhaseRing::cPack_pZvPIMg4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_giRKzRuL, 0, m, NULL);
}

void Heavy_PhaseRing::cPack_ROtddZFW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_vsVeom0q, 0, m, NULL);
}

void Heavy_PhaseRing::cBinop_lmOfXFya_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_20yTW3wZ_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_SIN, m, &cUnop_h7fiuYnS_sendMessage);
}

void Heavy_PhaseRing::cMsg_EA38cOFd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.5f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_lmOfXFya_sendMessage);
}

void Heavy_PhaseRing::cSlice_ADDInxI0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 127.0f, 0, m, &cBinop_whooZ6KD_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cSlice_p3O1i843_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_mSBpJppU_sendMessage);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_hbCkV52I_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_hdsFJIsg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.4f, 0, m, &cBinop_34EVeQDY_sendMessage);
}

void Heavy_PhaseRing::cBinop_34EVeQDY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_lmOfXFya_sendMessage);
}

void Heavy_PhaseRing::cBinop_whooZ6KD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_ZFasyrs4_sendMessage(_c, 0, m);
  cSend_3XbJ2AXX_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_MCX8JOoK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_h02P1YyI_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Nf8TzOlY_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_vGgZ7YPI, 0, m, &cVar_vGgZ7YPI_sendMessage);
}

void Heavy_PhaseRing::cBinop_YwgvP8p6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.99f, 0, m, &cBinop_Yp5NnKgr_sendMessage);
}

void Heavy_PhaseRing::cBinop_Yp5NnKgr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MCX8JOoK, HV_BINOP_MULTIPLY, 1, m, &cBinop_MCX8JOoK_sendMessage);
}

void Heavy_PhaseRing::cCast_mSBpJppU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_8MIX15oX_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cSend_ZFasyrs4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_5S4XP6By_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cCast_h02P1YyI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_g194TxtX_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_6zgR14BN_sendMessage);
}

void Heavy_PhaseRing::cCast_Nf8TzOlY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_lk18C10L_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cBinop_4k5IKJI9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_PpfQqbnP, 0, m, &cPack_PpfQqbnP_sendMessage);
}

void Heavy_PhaseRing::cSend_3XbJ2AXX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_EN0yeAGn_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_OWU43LY2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_iQVfA9MC_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_fjKk81SI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 200.0f);
  cSend_OWU43LY2_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_xwD8WOSC_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_PLeGxjdZ, 0, m, &cSlice_PLeGxjdZ_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_fUBYaCdv, 0, m, &cRandom_fUBYaCdv_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_sfFqyGvK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_CbO89Jl4_sendMessage);
}

void Heavy_PhaseRing::cUnop_CbO89Jl4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_c7QKpGqH_sendMessage);
}

void Heavy_PhaseRing::cRandom_fUBYaCdv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_sfFqyGvK_sendMessage);
}

void Heavy_PhaseRing::cSlice_PLeGxjdZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_fUBYaCdv, 1, m, &cRandom_fUBYaCdv_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_FffVNK92_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_FNJv16oK, HV_BINOP_MULTIPLY, 0, m, &cBinop_FNJv16oK_sendMessage);
}

void Heavy_PhaseRing::cBinop_T5b3WaGe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_7WZRJbw9_sendMessage);
}

void Heavy_PhaseRing::cBinop_7WZRJbw9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_koZ7cvS2, HV_BINOP_POW, 1, m, &cBinop_koZ7cvS2_sendMessage);
  cMsg_B86A2tN7_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_koZ7cvS2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_FffVNK92_sendMessage);
}

void Heavy_PhaseRing::cMsg_B86A2tN7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_koZ7cvS2, HV_BINOP_POW, 0, m, &cBinop_koZ7cvS2_sendMessage);
}

void Heavy_PhaseRing::cSwitchcase_HlLnBc7u_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_V0yf5gSF, 0, m, &cSlice_V0yf5gSF_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_6C42TlKP, 0, m, &cRandom_6C42TlKP_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_VkA1KoaS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_pWpFkvgO_sendMessage);
}

void Heavy_PhaseRing::cUnop_pWpFkvgO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_eCed3LNR_sendMessage);
}

void Heavy_PhaseRing::cRandom_6C42TlKP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 15.0f, 0, m, &cBinop_VkA1KoaS_sendMessage);
}

void Heavy_PhaseRing::cSlice_V0yf5gSF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_6C42TlKP, 1, m, &cRandom_6C42TlKP_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cPack_vwrQKZI6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_66n4HwTr, 0, m, NULL);
}

void Heavy_PhaseRing::cVar_km4mMAIk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_jmWT7e1q_sendMessage);
}

void Heavy_PhaseRing::cVar_BBPNlROP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_XOGQDcF2, 0, m);
}

void Heavy_PhaseRing::cVar_fW6U5gtX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_bd7RL59k, 0, m);
}

void Heavy_PhaseRing::cVar_nyFf79KP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_nnBLFuMy_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_OKwG32Wd_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_irn0z6Ew_sendMessage);
}

void Heavy_PhaseRing::cCast_2JFHOUsk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cVar_jCMxTrIC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cVar_OZb1oely_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cVar_9eRyPZDv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cSwitchcase_ECWO2rtC_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_yEDz5F6a_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_yEDz5F6a_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_CeWQNIu9, 1, m, &cDelay_CeWQNIu9_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_NrJrs9lE_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cDelay_CeWQNIu9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_CeWQNIu9, m);
  cVar_onMessage(_c, &Context(_c)->cVar_vmwwlejN, 0, m, &cVar_vmwwlejN_sendMessage);
}

void Heavy_PhaseRing::cMsg_yEDz5F6a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_CeWQNIu9, 0, m, &cDelay_CeWQNIu9_sendMessage);
}

void Heavy_PhaseRing::cCast_NrJrs9lE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_CeWQNIu9, 0, m, &cDelay_CeWQNIu9_sendMessage);
}

void Heavy_PhaseRing::cVar_vmwwlejN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_SZJOqm3j_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cCast_dD0V1qBW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_nyFf79KP, 0, m, &cVar_nyFf79KP_sendMessage);
}

void Heavy_PhaseRing::cMsg_D47Y4gY7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 25.0f);
  cSend_idJApE40_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_a3i1HnEd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 4000.0f);
  cSend_O9QNyfxi_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_Iw3mLRAf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSend_M0PQg6Ud_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_HKLFW5mi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_yQQq0HF1_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_bOFnyVPT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cSend_JRJfSw4q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_tFO6OEUW_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_idJApE40_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cSend_O9QNyfxi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_yQQq0HF1_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_M0PQg6Ud_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_tFO6OEUW_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_cj8EGiAb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 25.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_0wbImGNT, 0, m, NULL);
}

void Heavy_PhaseRing::cMsg_SZJOqm3j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 0);
  sLine_onMessage(_c, &Context(_c)->sLine_0wbImGNT, 0, m, NULL);
}

void Heavy_PhaseRing::cCast_nnBLFuMy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_cj8EGiAb_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cCast_OKwG32Wd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_vmwwlejN, 1, m, &cVar_vmwwlejN_sendMessage);
}

void Heavy_PhaseRing::cCast_irn0z6Ew_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_ECWO2rtC_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cCast_QQVuRfoE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cUnop_q4bJlGTy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_6Sad23V9, 0, m, &cPack_6Sad23V9_sendMessage);
}

void Heavy_PhaseRing::cUnop_mOyW3dIs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_yeCJUcsL, 0, m, &cPack_yeCJUcsL_sendMessage);
}

void Heavy_PhaseRing::cPack_yeCJUcsL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_X2Ctjfu6, 0, m, NULL);
}

void Heavy_PhaseRing::cPack_6Sad23V9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_T2jB01bg, 0, m, NULL);
}

void Heavy_PhaseRing::cBinop_rFc9jF0Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_q4bJlGTy_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_SIN, m, &cUnop_mOyW3dIs_sendMessage);
}

void Heavy_PhaseRing::cMsg_wKcFDzHm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.5f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_rFc9jF0Y_sendMessage);
}

void Heavy_PhaseRing::cSlice_koQ36P8X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 127.0f, 0, m, &cBinop_hmQ5BAfd_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cSlice_fM3STcNv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_J5Syn6x3_sendMessage);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_T5b3WaGe_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_c7QKpGqH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.4f, 0, m, &cBinop_g4zNeRMw_sendMessage);
}

void Heavy_PhaseRing::cBinop_g4zNeRMw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.5708f, 0, m, &cBinop_rFc9jF0Y_sendMessage);
}

void Heavy_PhaseRing::cBinop_hmQ5BAfd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_SKt5eSr6_sendMessage(_c, 0, m);
  cSend_hyz9hFao_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_FNJv16oK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_F76zeLqX_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_b7allUtm_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_fW6U5gtX, 0, m, &cVar_fW6U5gtX_sendMessage);
}

void Heavy_PhaseRing::cBinop_eCed3LNR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.99f, 0, m, &cBinop_yEx1dqrC_sendMessage);
}

void Heavy_PhaseRing::cBinop_yEx1dqrC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_FNJv16oK, HV_BINOP_MULTIPLY, 1, m, &cBinop_FNJv16oK_sendMessage);
}

void Heavy_PhaseRing::cCast_J5Syn6x3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_HlLnBc7u_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cSend_SKt5eSr6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_s4LpBP5s_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cCast_b7allUtm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_xwD8WOSC_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cCast_F76zeLqX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_dD0V1qBW_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_QQVuRfoE_sendMessage);
}

void Heavy_PhaseRing::cBinop_jmWT7e1q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_vwrQKZI6, 0, m, &cPack_vwrQKZI6_sendMessage);
}

void Heavy_PhaseRing::cSend_hyz9hFao_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_KDKDC1DZ_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_Z3xBgpqy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_aWis9EXq_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_bDB5eSej_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 200.0f);
  cSend_Z3xBgpqy_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cTabhead_PKJAoYgQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ue3Qixuy, HV_BINOP_SUBTRACT, 0, m, &cBinop_ue3Qixuy_sendMessage);
}

void Heavy_PhaseRing::cMsg_JeasGwhu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_WWtdVZEe_sendMessage);
}

void Heavy_PhaseRing::cSystem_WWtdVZEe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_Hm0zbSEI_sendMessage);
}

void Heavy_PhaseRing::cVar_ymCsbo9w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_lCkEbkVH_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cDelay_YdButG8r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_YdButG8r, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_m3uz3rjK, 0, m, &cDelay_m3uz3rjK_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_jw80FZK9, 0, m, &sTabread_jw80FZK9_sendMessage);
}

void Heavy_PhaseRing::cDelay_m3uz3rjK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_m3uz3rjK, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_jw80FZK9, 0, m, &sTabread_jw80FZK9_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_m3uz3rjK, 0, m, &cDelay_m3uz3rjK_sendMessage);
}

void Heavy_PhaseRing::sTabread_jw80FZK9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_oYbWWVrl, HV_BINOP_SUBTRACT, 0, m, &cBinop_oYbWWVrl_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_FGBKOujW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6HP4xFs2, HV_BINOP_MAX, 0, m, &cBinop_6HP4xFs2_sendMessage);
}

void Heavy_PhaseRing::cBinop_Hm0zbSEI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_FGBKOujW, HV_BINOP_MULTIPLY, 0, m, &cBinop_FGBKOujW_sendMessage);
}

void Heavy_PhaseRing::cBinop_ue3Qixuy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_F49N50Xl_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_jw80FZK9, 0, m, &sTabread_jw80FZK9_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_bSctuxvX_sendMessage);
}

void Heavy_PhaseRing::cSystem_JTnX8M60_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_oYbWWVrl, HV_BINOP_SUBTRACT, 1, m, &cBinop_oYbWWVrl_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_m3uz3rjK, 2, m, &cDelay_m3uz3rjK_sendMessage);
}

void Heavy_PhaseRing::cMsg_lCkEbkVH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_JTnX8M60_sendMessage);
}

void Heavy_PhaseRing::cMsg_F49N50Xl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_YdButG8r, 0, m, &cDelay_YdButG8r_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_m3uz3rjK, 0, m, &cDelay_m3uz3rjK_sendMessage);
}

void Heavy_PhaseRing::cMsg_2ELOijWs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_6HP4xFs2, HV_BINOP_MAX, 1, m, &cBinop_6HP4xFs2_sendMessage);
}

void Heavy_PhaseRing::cBinop_6HP4xFs2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ue3Qixuy, HV_BINOP_SUBTRACT, 1, m, &cBinop_ue3Qixuy_sendMessage);
}

void Heavy_PhaseRing::cCast_bSctuxvX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_YdButG8r, 0, m, &cDelay_YdButG8r_sendMessage);
}

void Heavy_PhaseRing::cBinop_D02HNuEN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_YdButG8r, 2, m, &cDelay_YdButG8r_sendMessage);
}

void Heavy_PhaseRing::cBinop_oYbWWVrl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_D02HNuEN_sendMessage);
}

void Heavy_PhaseRing::cCast_HZQT3XyW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ymCsbo9w, 0, m, &cVar_ymCsbo9w_sendMessage);
  cMsg_JeasGwhu_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_PKJAoYgQ, 0, m, &cTabhead_PKJAoYgQ_sendMessage);
}

void Heavy_PhaseRing::cTabhead_YRdUMsRO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_7vJ0WWYD, HV_BINOP_SUBTRACT, 0, m, &cBinop_7vJ0WWYD_sendMessage);
}

void Heavy_PhaseRing::cMsg_OYXWxyLk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_gfdLEf3g_sendMessage);
}

void Heavy_PhaseRing::cSystem_gfdLEf3g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_ltxrQvO9_sendMessage);
}

void Heavy_PhaseRing::cVar_xkqRYso3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_gs9Mm8kF_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cDelay_k1jBD6no_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_k1jBD6no, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_hiih9MkY, 0, m, &cDelay_hiih9MkY_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_TSq8QRuP, 0, m, &sTabread_TSq8QRuP_sendMessage);
}

void Heavy_PhaseRing::cDelay_hiih9MkY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_hiih9MkY, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_TSq8QRuP, 0, m, &sTabread_TSq8QRuP_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_hiih9MkY, 0, m, &cDelay_hiih9MkY_sendMessage);
}

void Heavy_PhaseRing::sTabread_TSq8QRuP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_Soj9KsB4, HV_BINOP_SUBTRACT, 0, m, &cBinop_Soj9KsB4_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_Qhk2RbSC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_5qeSjR4L, HV_BINOP_MAX, 0, m, &cBinop_5qeSjR4L_sendMessage);
}

void Heavy_PhaseRing::cBinop_ltxrQvO9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Qhk2RbSC, HV_BINOP_MULTIPLY, 0, m, &cBinop_Qhk2RbSC_sendMessage);
}

void Heavy_PhaseRing::cBinop_7vJ0WWYD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_u4Qwcyhb_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_TSq8QRuP, 0, m, &sTabread_TSq8QRuP_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_7czrGtmO_sendMessage);
}

void Heavy_PhaseRing::cSystem_IDwjP9cT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Soj9KsB4, HV_BINOP_SUBTRACT, 1, m, &cBinop_Soj9KsB4_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_hiih9MkY, 2, m, &cDelay_hiih9MkY_sendMessage);
}

void Heavy_PhaseRing::cMsg_gs9Mm8kF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_IDwjP9cT_sendMessage);
}

void Heavy_PhaseRing::cMsg_u4Qwcyhb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_k1jBD6no, 0, m, &cDelay_k1jBD6no_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_hiih9MkY, 0, m, &cDelay_hiih9MkY_sendMessage);
}

void Heavy_PhaseRing::cMsg_RFLS85b2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_5qeSjR4L, HV_BINOP_MAX, 1, m, &cBinop_5qeSjR4L_sendMessage);
}

void Heavy_PhaseRing::cBinop_5qeSjR4L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_7vJ0WWYD, HV_BINOP_SUBTRACT, 1, m, &cBinop_7vJ0WWYD_sendMessage);
}

void Heavy_PhaseRing::cCast_7czrGtmO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_k1jBD6no, 0, m, &cDelay_k1jBD6no_sendMessage);
}

void Heavy_PhaseRing::cBinop_VZ4Ktkii_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_k1jBD6no, 2, m, &cDelay_k1jBD6no_sendMessage);
}

void Heavy_PhaseRing::cBinop_Soj9KsB4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_VZ4Ktkii_sendMessage);
}

void Heavy_PhaseRing::cCast_YOV9ll36_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_xkqRYso3, 0, m, &cVar_xkqRYso3_sendMessage);
  cMsg_OYXWxyLk_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_YRdUMsRO, 0, m, &cTabhead_YRdUMsRO_sendMessage);
}

void Heavy_PhaseRing::cTabhead_MzangppQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_xikB8isq, HV_BINOP_SUBTRACT, 0, m, &cBinop_xikB8isq_sendMessage);
}

void Heavy_PhaseRing::cMsg_0Y0M7hdy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_BPgn5DYB_sendMessage);
}

void Heavy_PhaseRing::cSystem_BPgn5DYB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_3hsZC0xU_sendMessage);
}

void Heavy_PhaseRing::cVar_JkPGihsM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Y7EBYcfU_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cDelay_rK9Aq3e3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_rK9Aq3e3, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_vucFyCgk, 0, m, &cDelay_vucFyCgk_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_h4nHhP0C, 0, m, &sTabread_h4nHhP0C_sendMessage);
}

void Heavy_PhaseRing::cDelay_vucFyCgk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_vucFyCgk, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_h4nHhP0C, 0, m, &sTabread_h4nHhP0C_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_vucFyCgk, 0, m, &cDelay_vucFyCgk_sendMessage);
}

void Heavy_PhaseRing::sTabread_h4nHhP0C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_6h6ZNaa8, HV_BINOP_SUBTRACT, 0, m, &cBinop_6h6ZNaa8_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_wS8HWjQC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_BGzT3BIU, HV_BINOP_MAX, 0, m, &cBinop_BGzT3BIU_sendMessage);
}

void Heavy_PhaseRing::cBinop_3hsZC0xU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_wS8HWjQC, HV_BINOP_MULTIPLY, 0, m, &cBinop_wS8HWjQC_sendMessage);
}

void Heavy_PhaseRing::cBinop_xikB8isq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ArtmhLMi_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_h4nHhP0C, 0, m, &sTabread_h4nHhP0C_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ND7EfC1G_sendMessage);
}

void Heavy_PhaseRing::cSystem_rzcho9CI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6h6ZNaa8, HV_BINOP_SUBTRACT, 1, m, &cBinop_6h6ZNaa8_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_vucFyCgk, 2, m, &cDelay_vucFyCgk_sendMessage);
}

void Heavy_PhaseRing::cMsg_Y7EBYcfU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_rzcho9CI_sendMessage);
}

void Heavy_PhaseRing::cMsg_ArtmhLMi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_rK9Aq3e3, 0, m, &cDelay_rK9Aq3e3_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_vucFyCgk, 0, m, &cDelay_vucFyCgk_sendMessage);
}

void Heavy_PhaseRing::cMsg_aylrYR0a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_BGzT3BIU, HV_BINOP_MAX, 1, m, &cBinop_BGzT3BIU_sendMessage);
}

void Heavy_PhaseRing::cBinop_BGzT3BIU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_xikB8isq, HV_BINOP_SUBTRACT, 1, m, &cBinop_xikB8isq_sendMessage);
}

void Heavy_PhaseRing::cCast_ND7EfC1G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_rK9Aq3e3, 0, m, &cDelay_rK9Aq3e3_sendMessage);
}

void Heavy_PhaseRing::cBinop_97lrBikF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_rK9Aq3e3, 2, m, &cDelay_rK9Aq3e3_sendMessage);
}

void Heavy_PhaseRing::cBinop_6h6ZNaa8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_97lrBikF_sendMessage);
}

void Heavy_PhaseRing::cCast_LlWjws9o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_JkPGihsM, 0, m, &cVar_JkPGihsM_sendMessage);
  cMsg_0Y0M7hdy_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_MzangppQ, 0, m, &cTabhead_MzangppQ_sendMessage);
}

void Heavy_PhaseRing::cTabhead_ZG38nnqM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_0Iv0LCC2, HV_BINOP_SUBTRACT, 0, m, &cBinop_0Iv0LCC2_sendMessage);
}

void Heavy_PhaseRing::cMsg_f0RjTs9m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_WMIItgD7_sendMessage);
}

void Heavy_PhaseRing::cSystem_WMIItgD7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_T2hTqKhW_sendMessage);
}

void Heavy_PhaseRing::cVar_jCF6TWWn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_bvFkg0qC_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cDelay_RI6OHaI5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_RI6OHaI5, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_7FfummxH, 0, m, &cDelay_7FfummxH_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_evj4GBrQ, 0, m, &sTabread_evj4GBrQ_sendMessage);
}

void Heavy_PhaseRing::cDelay_7FfummxH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_7FfummxH, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_evj4GBrQ, 0, m, &sTabread_evj4GBrQ_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_7FfummxH, 0, m, &cDelay_7FfummxH_sendMessage);
}

void Heavy_PhaseRing::sTabread_evj4GBrQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_S23WeoJP, HV_BINOP_SUBTRACT, 0, m, &cBinop_S23WeoJP_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_hhOZj78g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_hcU9DCa0, HV_BINOP_MAX, 0, m, &cBinop_hcU9DCa0_sendMessage);
}

void Heavy_PhaseRing::cBinop_T2hTqKhW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_hhOZj78g, HV_BINOP_MULTIPLY, 0, m, &cBinop_hhOZj78g_sendMessage);
}

void Heavy_PhaseRing::cBinop_0Iv0LCC2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Ry667AFg_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_evj4GBrQ, 0, m, &sTabread_evj4GBrQ_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_A3hUR3Px_sendMessage);
}

void Heavy_PhaseRing::cSystem_A3HkxVOg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_S23WeoJP, HV_BINOP_SUBTRACT, 1, m, &cBinop_S23WeoJP_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_7FfummxH, 2, m, &cDelay_7FfummxH_sendMessage);
}

void Heavy_PhaseRing::cMsg_bvFkg0qC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_A3HkxVOg_sendMessage);
}

void Heavy_PhaseRing::cMsg_Ry667AFg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_RI6OHaI5, 0, m, &cDelay_RI6OHaI5_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_7FfummxH, 0, m, &cDelay_7FfummxH_sendMessage);
}

void Heavy_PhaseRing::cMsg_2rRnA4Ox_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_hcU9DCa0, HV_BINOP_MAX, 1, m, &cBinop_hcU9DCa0_sendMessage);
}

void Heavy_PhaseRing::cBinop_hcU9DCa0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_0Iv0LCC2, HV_BINOP_SUBTRACT, 1, m, &cBinop_0Iv0LCC2_sendMessage);
}

void Heavy_PhaseRing::cCast_A3hUR3Px_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_RI6OHaI5, 0, m, &cDelay_RI6OHaI5_sendMessage);
}

void Heavy_PhaseRing::cBinop_WpSQGC7m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_RI6OHaI5, 2, m, &cDelay_RI6OHaI5_sendMessage);
}

void Heavy_PhaseRing::cBinop_S23WeoJP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_WpSQGC7m_sendMessage);
}

void Heavy_PhaseRing::cCast_fZD7pTaL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_jCF6TWWn, 0, m, &cVar_jCF6TWWn_sendMessage);
  cMsg_f0RjTs9m_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_ZG38nnqM, 0, m, &cTabhead_ZG38nnqM_sendMessage);
}

void Heavy_PhaseRing::cMsg_rSpqhgBO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_b8d4g5ul_sendMessage);
}

void Heavy_PhaseRing::cSystem_b8d4g5ul_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_iOxVSIz4_sendMessage);
}

void Heavy_PhaseRing::cDelay_q7WhoAWy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_q7WhoAWy, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_BmyFeitd, 0, m, &cDelay_BmyFeitd_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_q7WhoAWy, 0, m, &cDelay_q7WhoAWy_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_CaFt55s4, 1, m, NULL);
}

void Heavy_PhaseRing::cDelay_BmyFeitd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_BmyFeitd, m);
  cMsg_k6K5csLx_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_GcA5UJDe_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_SfjQ03nb_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_MjghKi7h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_gNfbozfD_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::hTable_hk8uR4SZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_NPKDSXRw_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_q7WhoAWy, 2, m, &cDelay_q7WhoAWy_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_OuorqCor_sendMessage);
}

void Heavy_PhaseRing::cMsg_gNfbozfD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_hk8uR4SZ, 0, m, &hTable_hk8uR4SZ_sendMessage);
}

void Heavy_PhaseRing::cBinop_iOxVSIz4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 58.6435f, 0, m, &cBinop_MjghKi7h_sendMessage);
}

void Heavy_PhaseRing::cMsg_k6K5csLx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_hk8uR4SZ, 0, m, &hTable_hk8uR4SZ_sendMessage);
}

void Heavy_PhaseRing::cCast_OuorqCor_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_q7WhoAWy, 0, m, &cDelay_q7WhoAWy_sendMessage);
}

void Heavy_PhaseRing::cMsg_NPKDSXRw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_BmyFeitd, 2, m, &cDelay_BmyFeitd_sendMessage);
}

void Heavy_PhaseRing::cMsg_SfjQ03nb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_CaFt55s4, 1, m, NULL);
}

void Heavy_PhaseRing::cMsg_sV6zeNQD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_eZLQqZmM_sendMessage);
}

void Heavy_PhaseRing::cSystem_eZLQqZmM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_zxnlhM8q_sendMessage);
}

void Heavy_PhaseRing::cDelay_kvJ9GrLw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_kvJ9GrLw, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_UgcTnX09, 0, m, &cDelay_UgcTnX09_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_kvJ9GrLw, 0, m, &cDelay_kvJ9GrLw_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_W5hkesFL, 1, m, NULL);
}

void Heavy_PhaseRing::cDelay_UgcTnX09_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_UgcTnX09, m);
  cMsg_6U3cp5Be_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_AQGxphx8_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_g6LuNDqJ_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_DjhlTEft_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_a92WuH1Z_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::hTable_lxlLALuN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_QrD9Urq4_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_kvJ9GrLw, 2, m, &cDelay_kvJ9GrLw_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_97fU3nzp_sendMessage);
}

void Heavy_PhaseRing::cMsg_a92WuH1Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_lxlLALuN, 0, m, &hTable_lxlLALuN_sendMessage);
}

void Heavy_PhaseRing::cBinop_zxnlhM8q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 69.4325f, 0, m, &cBinop_DjhlTEft_sendMessage);
}

void Heavy_PhaseRing::cMsg_6U3cp5Be_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_lxlLALuN, 0, m, &hTable_lxlLALuN_sendMessage);
}

void Heavy_PhaseRing::cCast_97fU3nzp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_kvJ9GrLw, 0, m, &cDelay_kvJ9GrLw_sendMessage);
}

void Heavy_PhaseRing::cMsg_QrD9Urq4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_UgcTnX09, 2, m, &cDelay_UgcTnX09_sendMessage);
}

void Heavy_PhaseRing::cMsg_g6LuNDqJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_W5hkesFL, 1, m, NULL);
}

void Heavy_PhaseRing::cMsg_HNlauUI2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_KiNrxwxy_sendMessage);
}

void Heavy_PhaseRing::cSystem_KiNrxwxy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_UEnNSEOx_sendMessage);
}

void Heavy_PhaseRing::cDelay_5dJo6EmK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_5dJo6EmK, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_yqAO5wXV, 0, m, &cDelay_yqAO5wXV_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_5dJo6EmK, 0, m, &cDelay_5dJo6EmK_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_qGv01GnR, 1, m, NULL);
}

void Heavy_PhaseRing::cDelay_yqAO5wXV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_yqAO5wXV, m);
  cMsg_eP4QdG69_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_mdR5g8xg_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_827MCjsP_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_ZLcvmYJk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_oY8tk4mJ_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::hTable_OutROxhq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_nWL2bY3j_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_5dJo6EmK, 2, m, &cDelay_5dJo6EmK_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_mUZq8Jy8_sendMessage);
}

void Heavy_PhaseRing::cMsg_oY8tk4mJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_OutROxhq, 0, m, &hTable_OutROxhq_sendMessage);
}

void Heavy_PhaseRing::cBinop_UEnNSEOx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 74.5234f, 0, m, &cBinop_ZLcvmYJk_sendMessage);
}

void Heavy_PhaseRing::cMsg_eP4QdG69_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_OutROxhq, 0, m, &hTable_OutROxhq_sendMessage);
}

void Heavy_PhaseRing::cCast_mUZq8Jy8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_5dJo6EmK, 0, m, &cDelay_5dJo6EmK_sendMessage);
}

void Heavy_PhaseRing::cMsg_nWL2bY3j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_yqAO5wXV, 2, m, &cDelay_yqAO5wXV_sendMessage);
}

void Heavy_PhaseRing::cMsg_827MCjsP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_qGv01GnR, 1, m, NULL);
}

void Heavy_PhaseRing::cMsg_pxYlYqFr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_udhQZhpY_sendMessage);
}

void Heavy_PhaseRing::cSystem_udhQZhpY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_sU4oil9r_sendMessage);
}

void Heavy_PhaseRing::cDelay_nCSUIJd7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_nCSUIJd7, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_TNpE8Nhx, 0, m, &cDelay_TNpE8Nhx_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_nCSUIJd7, 0, m, &cDelay_nCSUIJd7_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_L7WOB0wH, 1, m, NULL);
}

void Heavy_PhaseRing::cDelay_TNpE8Nhx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_TNpE8Nhx, m);
  cMsg_1oWKx6AV_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_R1wnMrkT_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_xjwicfy5_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_dPvaElA3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_fcJzA1Eo_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::hTable_LdIxdeSA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_n3bWDCjY_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_nCSUIJd7, 2, m, &cDelay_nCSUIJd7_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_3PSKEcgO_sendMessage);
}

void Heavy_PhaseRing::cMsg_fcJzA1Eo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_LdIxdeSA, 0, m, &hTable_LdIxdeSA_sendMessage);
}

void Heavy_PhaseRing::cBinop_sU4oil9r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 86.1244f, 0, m, &cBinop_dPvaElA3_sendMessage);
}

void Heavy_PhaseRing::cMsg_1oWKx6AV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_LdIxdeSA, 0, m, &hTable_LdIxdeSA_sendMessage);
}

void Heavy_PhaseRing::cCast_3PSKEcgO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_nCSUIJd7, 0, m, &cDelay_nCSUIJd7_sendMessage);
}

void Heavy_PhaseRing::cMsg_n3bWDCjY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_TNpE8Nhx, 2, m, &cDelay_TNpE8Nhx_sendMessage);
}

void Heavy_PhaseRing::cMsg_xjwicfy5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_L7WOB0wH, 1, m, NULL);
}

void Heavy_PhaseRing::cIf_BwLvbS79_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_WLsHKQ0d_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_89pDLyTB_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cMsg_DsQsgks9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_Tl6pkW1v, HV_BINOP_POW, 0, m, &cBinop_Tl6pkW1v_sendMessage);
}

void Heavy_PhaseRing::cBinop_Tl6pkW1v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.125f, 0, m, &cBinop_jyU3oBi3_sendMessage);
}

void Heavy_PhaseRing::cBinop_f5bxc8bI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_Duh4S4XV_sendMessage);
}

void Heavy_PhaseRing::cCast_rpalmjnS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_BwLvbS79, 0, m, &cIf_BwLvbS79_sendMessage);
}

void Heavy_PhaseRing::cCast_AtZvgYJI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_UDEHlZBX_sendMessage);
}

void Heavy_PhaseRing::cBinop_UDEHlZBX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_BwLvbS79, 1, m, &cIf_BwLvbS79_sendMessage);
}

void Heavy_PhaseRing::cBinop_89pDLyTB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_f5bxc8bI_sendMessage);
}

void Heavy_PhaseRing::cMsg_WLsHKQ0d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.125f, 0, m, &cBinop_jyU3oBi3_sendMessage);
}

void Heavy_PhaseRing::cBinop_Duh4S4XV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Tl6pkW1v, HV_BINOP_POW, 1, m, &cBinop_Tl6pkW1v_sendMessage);
  cMsg_DsQsgks9_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cPack_Dr2kPUep_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_hOiOVTYt, 0, m, NULL);
}

void Heavy_PhaseRing::cPack_UtJkCIRJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_vjEi2ef9, 0, m, NULL);
}

void Heavy_PhaseRing::cBinop_i0QZtdZV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_IFzPQ851_sendMessage);
}

void Heavy_PhaseRing::cBinop_IFzPQ851_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 200.0f, 0, m, &cBinop_pS3SvNMU_sendMessage);
}

void Heavy_PhaseRing::cVar_6LRTzgMY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_RSAM2qmG, HV_BINOP_MULTIPLY, 0, m, &cBinop_RSAM2qmG_sendMessage);
}

void Heavy_PhaseRing::cMsg_t9EShhj3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_InftYljY_sendMessage);
}

void Heavy_PhaseRing::cSystem_InftYljY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_m6Jz9rTf_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_RSAM2qmG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_5OsF1xX5_sendMessage);
}

void Heavy_PhaseRing::cBinop_dJu6Ojja_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_RSAM2qmG, HV_BINOP_MULTIPLY, 1, m, &cBinop_RSAM2qmG_sendMessage);
}

void Heavy_PhaseRing::cMsg_m6Jz9rTf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_dJu6Ojja_sendMessage);
}

void Heavy_PhaseRing::cBinop_5OsF1xX5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_iWRV3Hun_sendMessage);
}

void Heavy_PhaseRing::cBinop_iWRV3Hun_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_XpjsEdNo_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_SbHORNfz, m);
}

void Heavy_PhaseRing::cBinop_XpjsEdNo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_osSX212V, m);
}

void Heavy_PhaseRing::cVar_V0YU1TVm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_AtZvgYJI_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_rpalmjnS_sendMessage);
}

void Heavy_PhaseRing::cVar_KQJ9X5YQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 100.0f, 0, m, &cBinop_i0QZtdZV_sendMessage);
}

void Heavy_PhaseRing::cVar_TRSC3Dk6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_8pqydVal_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_sqRyq0oS, 0, m, &cIf_sqRyq0oS_sendMessage);
}

void Heavy_PhaseRing::cVar_FkBlJBq4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 100.0f, 0, m, &cBinop_fRy4Ynp2_sendMessage);
}

void Heavy_PhaseRing::cIf_sqRyq0oS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_hQVJcr9m_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cVar_onMessage(_c, &Context(_c)->cVar_Ypxx9KMu, 0, m, &cVar_Ypxx9KMu_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_8pqydVal_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_sqRyq0oS, 1, m, &cIf_sqRyq0oS_sendMessage);
}

void Heavy_PhaseRing::cBinop_fRy4Ynp2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_tM8jJAC9_sendMessage);
}

void Heavy_PhaseRing::cBinop_tM8jJAC9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_DHJ9VxY7, 0, m, &cVar_DHJ9VxY7_sendMessage);
}

void Heavy_PhaseRing::cTabhead_HoXZ04Un_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_iZGQkpx1, HV_BINOP_SUBTRACT, 0, m, &cBinop_iZGQkpx1_sendMessage);
}

void Heavy_PhaseRing::cMsg_uI52HFYF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_0JKIAiO8_sendMessage);
}

void Heavy_PhaseRing::cSystem_0JKIAiO8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_vtfanj4L_sendMessage);
}

void Heavy_PhaseRing::cVar_18e9SGzg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_CrX0m4kg_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cDelay_q4l2hDwA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_q4l2hDwA, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_TVpGZQ1E, 0, m, &cDelay_TVpGZQ1E_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_hUsGN24Q, 0, m, &sTabread_hUsGN24Q_sendMessage);
}

void Heavy_PhaseRing::cDelay_TVpGZQ1E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_TVpGZQ1E, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_hUsGN24Q, 0, m, &sTabread_hUsGN24Q_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_TVpGZQ1E, 0, m, &cDelay_TVpGZQ1E_sendMessage);
}

void Heavy_PhaseRing::sTabread_hUsGN24Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_oIMr4Kav, HV_BINOP_SUBTRACT, 0, m, &cBinop_oIMr4Kav_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_ERMYPR0H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_YGitIJDh, HV_BINOP_MAX, 0, m, &cBinop_YGitIJDh_sendMessage);
}

void Heavy_PhaseRing::cBinop_vtfanj4L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ERMYPR0H, HV_BINOP_MULTIPLY, 0, m, &cBinop_ERMYPR0H_sendMessage);
}

void Heavy_PhaseRing::cBinop_iZGQkpx1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_YjuhckgN_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_hUsGN24Q, 0, m, &sTabread_hUsGN24Q_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_xCXnpnMP_sendMessage);
}

void Heavy_PhaseRing::cSystem_ZR0UKN3O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_oIMr4Kav, HV_BINOP_SUBTRACT, 1, m, &cBinop_oIMr4Kav_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_TVpGZQ1E, 2, m, &cDelay_TVpGZQ1E_sendMessage);
}

void Heavy_PhaseRing::cMsg_CrX0m4kg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ZR0UKN3O_sendMessage);
}

void Heavy_PhaseRing::cMsg_YjuhckgN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_q4l2hDwA, 0, m, &cDelay_q4l2hDwA_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_TVpGZQ1E, 0, m, &cDelay_TVpGZQ1E_sendMessage);
}

void Heavy_PhaseRing::cMsg_VnyC99wd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_YGitIJDh, HV_BINOP_MAX, 1, m, &cBinop_YGitIJDh_sendMessage);
}

void Heavy_PhaseRing::cBinop_YGitIJDh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_iZGQkpx1, HV_BINOP_SUBTRACT, 1, m, &cBinop_iZGQkpx1_sendMessage);
}

void Heavy_PhaseRing::cCast_xCXnpnMP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_q4l2hDwA, 0, m, &cDelay_q4l2hDwA_sendMessage);
}

void Heavy_PhaseRing::cBinop_SuUykPB3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_q4l2hDwA, 2, m, &cDelay_q4l2hDwA_sendMessage);
}

void Heavy_PhaseRing::cBinop_oIMr4Kav_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_SuUykPB3_sendMessage);
}

void Heavy_PhaseRing::cCast_HVw1Qtqi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_18e9SGzg, 0, m, &cVar_18e9SGzg_sendMessage);
  cMsg_uI52HFYF_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_HoXZ04Un, 0, m, &cTabhead_HoXZ04Un_sendMessage);
}

void Heavy_PhaseRing::cMsg_iN6RLwCo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_N2YQz2Er_sendMessage);
}

void Heavy_PhaseRing::cSystem_N2YQz2Er_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_U9wsWPfP_sendMessage);
}

void Heavy_PhaseRing::cDelay_1eo9jHqt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_1eo9jHqt, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_RKSFUslk, 0, m, &cDelay_RKSFUslk_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_1eo9jHqt, 0, m, &cDelay_1eo9jHqt_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_s86jEh8Y, 1, m, NULL);
}

void Heavy_PhaseRing::cDelay_RKSFUslk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_RKSFUslk, m);
  cMsg_6piWbWVK_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_YbFHYmij_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_20w8BvOO_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_V6dyNymw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_pvcYL3mj_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::hTable_x1926MpT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_8NZCQQs5_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_1eo9jHqt, 2, m, &cDelay_1eo9jHqt_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_HDdoax0s_sendMessage);
}

void Heavy_PhaseRing::cMsg_pvcYL3mj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_x1926MpT, 0, m, &hTable_x1926MpT_sendMessage);
}

void Heavy_PhaseRing::cBinop_U9wsWPfP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 13.645f, 0, m, &cBinop_V6dyNymw_sendMessage);
}

void Heavy_PhaseRing::cMsg_6piWbWVK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_x1926MpT, 0, m, &hTable_x1926MpT_sendMessage);
}

void Heavy_PhaseRing::cCast_HDdoax0s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_1eo9jHqt, 0, m, &cDelay_1eo9jHqt_sendMessage);
}

void Heavy_PhaseRing::cMsg_8NZCQQs5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_RKSFUslk, 2, m, &cDelay_RKSFUslk_sendMessage);
}

void Heavy_PhaseRing::cMsg_20w8BvOO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_s86jEh8Y, 1, m, NULL);
}

void Heavy_PhaseRing::cTabhead_y4Bq6gfx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Qj7vpWOD, HV_BINOP_SUBTRACT, 0, m, &cBinop_Qj7vpWOD_sendMessage);
}

void Heavy_PhaseRing::cMsg_QL1siCbT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_k48SUNNw_sendMessage);
}

void Heavy_PhaseRing::cSystem_k48SUNNw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_K6s6wbsk_sendMessage);
}

void Heavy_PhaseRing::cVar_IsgQPszk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_lPFUJmJe_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cDelay_yoRKm6hX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_yoRKm6hX, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_LikuCG38, 0, m, &cDelay_LikuCG38_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_czQn5Hxr, 0, m, &sTabread_czQn5Hxr_sendMessage);
}

void Heavy_PhaseRing::cDelay_LikuCG38_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_LikuCG38, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_czQn5Hxr, 0, m, &sTabread_czQn5Hxr_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_LikuCG38, 0, m, &cDelay_LikuCG38_sendMessage);
}

void Heavy_PhaseRing::sTabread_czQn5Hxr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_ELN7mzjj, HV_BINOP_SUBTRACT, 0, m, &cBinop_ELN7mzjj_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_JCgD0nEf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_zhdgwIsR, HV_BINOP_MAX, 0, m, &cBinop_zhdgwIsR_sendMessage);
}

void Heavy_PhaseRing::cBinop_K6s6wbsk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_JCgD0nEf, HV_BINOP_MULTIPLY, 0, m, &cBinop_JCgD0nEf_sendMessage);
}

void Heavy_PhaseRing::cBinop_Qj7vpWOD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_lwjuzwSj_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_czQn5Hxr, 0, m, &sTabread_czQn5Hxr_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_NJyrTBCQ_sendMessage);
}

void Heavy_PhaseRing::cSystem_4nbnEsai_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ELN7mzjj, HV_BINOP_SUBTRACT, 1, m, &cBinop_ELN7mzjj_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_LikuCG38, 2, m, &cDelay_LikuCG38_sendMessage);
}

void Heavy_PhaseRing::cMsg_lPFUJmJe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_4nbnEsai_sendMessage);
}

void Heavy_PhaseRing::cMsg_lwjuzwSj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_yoRKm6hX, 0, m, &cDelay_yoRKm6hX_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_LikuCG38, 0, m, &cDelay_LikuCG38_sendMessage);
}

void Heavy_PhaseRing::cMsg_SPwU5nNK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_zhdgwIsR, HV_BINOP_MAX, 1, m, &cBinop_zhdgwIsR_sendMessage);
}

void Heavy_PhaseRing::cBinop_zhdgwIsR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Qj7vpWOD, HV_BINOP_SUBTRACT, 1, m, &cBinop_Qj7vpWOD_sendMessage);
}

void Heavy_PhaseRing::cCast_NJyrTBCQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_yoRKm6hX, 0, m, &cDelay_yoRKm6hX_sendMessage);
}

void Heavy_PhaseRing::cBinop_cC7nnNQC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_yoRKm6hX, 2, m, &cDelay_yoRKm6hX_sendMessage);
}

void Heavy_PhaseRing::cBinop_ELN7mzjj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_cC7nnNQC_sendMessage);
}

void Heavy_PhaseRing::cCast_H8iqBHnL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_IsgQPszk, 0, m, &cVar_IsgQPszk_sendMessage);
  cMsg_QL1siCbT_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_y4Bq6gfx, 0, m, &cTabhead_y4Bq6gfx_sendMessage);
}

void Heavy_PhaseRing::cMsg_vwh2TsXL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_C31kodWn_sendMessage);
}

void Heavy_PhaseRing::cSystem_C31kodWn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_iUZhFO4h_sendMessage);
}

void Heavy_PhaseRing::cDelay_Zoq2xtyx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Zoq2xtyx, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ymnh9Mnd, 0, m, &cDelay_ymnh9Mnd_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Zoq2xtyx, 0, m, &cDelay_Zoq2xtyx_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_mYgV1uUy, 1, m, NULL);
}

void Heavy_PhaseRing::cDelay_ymnh9Mnd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_ymnh9Mnd, m);
  cMsg_5rOHliPk_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_gEzZLrrc_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_KfICZd1E_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_CNhWTGtg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_bHWwAoAF_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::hTable_ASDeXuBy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_XBcmcA2A_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Zoq2xtyx, 2, m, &cDelay_Zoq2xtyx_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_VUsHvvsJ_sendMessage);
}

void Heavy_PhaseRing::cMsg_bHWwAoAF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_ASDeXuBy, 0, m, &hTable_ASDeXuBy_sendMessage);
}

void Heavy_PhaseRing::cBinop_iUZhFO4h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 16.364f, 0, m, &cBinop_CNhWTGtg_sendMessage);
}

void Heavy_PhaseRing::cMsg_5rOHliPk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_ASDeXuBy, 0, m, &hTable_ASDeXuBy_sendMessage);
}

void Heavy_PhaseRing::cCast_VUsHvvsJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Zoq2xtyx, 0, m, &cDelay_Zoq2xtyx_sendMessage);
}

void Heavy_PhaseRing::cMsg_XBcmcA2A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_ymnh9Mnd, 2, m, &cDelay_ymnh9Mnd_sendMessage);
}

void Heavy_PhaseRing::cMsg_KfICZd1E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_mYgV1uUy, 1, m, NULL);
}

void Heavy_PhaseRing::cTabhead_M7RUb4H8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_thjTyt69, HV_BINOP_SUBTRACT, 0, m, &cBinop_thjTyt69_sendMessage);
}

void Heavy_PhaseRing::cMsg_tZdq0l8v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_QtgA7qSq_sendMessage);
}

void Heavy_PhaseRing::cSystem_QtgA7qSq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_twzGBUhc_sendMessage);
}

void Heavy_PhaseRing::cVar_ZNI0gAFB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_HCBekirG_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cDelay_HuZZCmyU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_HuZZCmyU, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_vQJmAk9q, 0, m, &cDelay_vQJmAk9q_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_oSgV7GEt, 0, m, &sTabread_oSgV7GEt_sendMessage);
}

void Heavy_PhaseRing::cDelay_vQJmAk9q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_vQJmAk9q, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_oSgV7GEt, 0, m, &sTabread_oSgV7GEt_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_vQJmAk9q, 0, m, &cDelay_vQJmAk9q_sendMessage);
}

void Heavy_PhaseRing::sTabread_oSgV7GEt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_1xGlfPLh, HV_BINOP_SUBTRACT, 0, m, &cBinop_1xGlfPLh_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_77C9bXAd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_KtLchMfu, HV_BINOP_MAX, 0, m, &cBinop_KtLchMfu_sendMessage);
}

void Heavy_PhaseRing::cBinop_twzGBUhc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_77C9bXAd, HV_BINOP_MULTIPLY, 0, m, &cBinop_77C9bXAd_sendMessage);
}

void Heavy_PhaseRing::cBinop_thjTyt69_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_PbgsN3e0_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_oSgV7GEt, 0, m, &sTabread_oSgV7GEt_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_WgFOPZ6y_sendMessage);
}

void Heavy_PhaseRing::cSystem_HXQfHkkN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_1xGlfPLh, HV_BINOP_SUBTRACT, 1, m, &cBinop_1xGlfPLh_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_vQJmAk9q, 2, m, &cDelay_vQJmAk9q_sendMessage);
}

void Heavy_PhaseRing::cMsg_HCBekirG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_HXQfHkkN_sendMessage);
}

void Heavy_PhaseRing::cMsg_PbgsN3e0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_HuZZCmyU, 0, m, &cDelay_HuZZCmyU_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_vQJmAk9q, 0, m, &cDelay_vQJmAk9q_sendMessage);
}

void Heavy_PhaseRing::cMsg_MyLzixvw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_KtLchMfu, HV_BINOP_MAX, 1, m, &cBinop_KtLchMfu_sendMessage);
}

void Heavy_PhaseRing::cBinop_KtLchMfu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_thjTyt69, HV_BINOP_SUBTRACT, 1, m, &cBinop_thjTyt69_sendMessage);
}

void Heavy_PhaseRing::cCast_WgFOPZ6y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_HuZZCmyU, 0, m, &cDelay_HuZZCmyU_sendMessage);
}

void Heavy_PhaseRing::cBinop_ud7NjB0m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_HuZZCmyU, 2, m, &cDelay_HuZZCmyU_sendMessage);
}

void Heavy_PhaseRing::cBinop_1xGlfPLh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_ud7NjB0m_sendMessage);
}

void Heavy_PhaseRing::cCast_qkWswo8F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ZNI0gAFB, 0, m, &cVar_ZNI0gAFB_sendMessage);
  cMsg_tZdq0l8v_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_M7RUb4H8, 0, m, &cTabhead_M7RUb4H8_sendMessage);
}

void Heavy_PhaseRing::cMsg_jN8HL5tY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_aJiV6Gzm_sendMessage);
}

void Heavy_PhaseRing::cSystem_aJiV6Gzm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_R1RbGxFC_sendMessage);
}

void Heavy_PhaseRing::cDelay_FGlW7dGn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_FGlW7dGn, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Ap8Kjblu, 0, m, &cDelay_Ap8Kjblu_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_FGlW7dGn, 0, m, &cDelay_FGlW7dGn_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_vKgcxULU, 1, m, NULL);
}

void Heavy_PhaseRing::cDelay_Ap8Kjblu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Ap8Kjblu, m);
  cMsg_xhCJZpd2_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_EtSQaRkM_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_ltGKcagn_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_0jf2Usog_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_zY4FoqRQ_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::hTable_YVvjvH1Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_G7PtBbJs_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_FGlW7dGn, 2, m, &cDelay_FGlW7dGn_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_4Btdkqno_sendMessage);
}

void Heavy_PhaseRing::cMsg_zY4FoqRQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_YVvjvH1Q, 0, m, &hTable_YVvjvH1Q_sendMessage);
}

void Heavy_PhaseRing::cBinop_R1RbGxFC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 19.392f, 0, m, &cBinop_0jf2Usog_sendMessage);
}

void Heavy_PhaseRing::cMsg_xhCJZpd2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_YVvjvH1Q, 0, m, &hTable_YVvjvH1Q_sendMessage);
}

void Heavy_PhaseRing::cCast_4Btdkqno_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_FGlW7dGn, 0, m, &cDelay_FGlW7dGn_sendMessage);
}

void Heavy_PhaseRing::cMsg_G7PtBbJs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_Ap8Kjblu, 2, m, &cDelay_Ap8Kjblu_sendMessage);
}

void Heavy_PhaseRing::cMsg_ltGKcagn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_vKgcxULU, 1, m, NULL);
}

void Heavy_PhaseRing::cTabhead_y1YWpaio_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_c4Fu8MNv, HV_BINOP_SUBTRACT, 0, m, &cBinop_c4Fu8MNv_sendMessage);
}

void Heavy_PhaseRing::cMsg_rCyRjsTK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_VpNwBqgs_sendMessage);
}

void Heavy_PhaseRing::cSystem_VpNwBqgs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_xTcnyiYa_sendMessage);
}

void Heavy_PhaseRing::cVar_kUYYAuQl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_lklzLVuL_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cDelay_UxRaIVKk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_UxRaIVKk, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_BpKKTtAG, 0, m, &cDelay_BpKKTtAG_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_Mt91ilfO, 0, m, &sTabread_Mt91ilfO_sendMessage);
}

void Heavy_PhaseRing::cDelay_BpKKTtAG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_BpKKTtAG, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_Mt91ilfO, 0, m, &sTabread_Mt91ilfO_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_BpKKTtAG, 0, m, &cDelay_BpKKTtAG_sendMessage);
}

void Heavy_PhaseRing::sTabread_Mt91ilfO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_0gWdQTHL, HV_BINOP_SUBTRACT, 0, m, &cBinop_0gWdQTHL_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_fHWPRtUb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_HxHHiAxZ, HV_BINOP_MAX, 0, m, &cBinop_HxHHiAxZ_sendMessage);
}

void Heavy_PhaseRing::cBinop_xTcnyiYa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_fHWPRtUb, HV_BINOP_MULTIPLY, 0, m, &cBinop_fHWPRtUb_sendMessage);
}

void Heavy_PhaseRing::cBinop_c4Fu8MNv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_PXbrI9o1_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_Mt91ilfO, 0, m, &sTabread_Mt91ilfO_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_mxIL9u74_sendMessage);
}

void Heavy_PhaseRing::cSystem_WrmqoOnU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_0gWdQTHL, HV_BINOP_SUBTRACT, 1, m, &cBinop_0gWdQTHL_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_BpKKTtAG, 2, m, &cDelay_BpKKTtAG_sendMessage);
}

void Heavy_PhaseRing::cMsg_lklzLVuL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_WrmqoOnU_sendMessage);
}

void Heavy_PhaseRing::cMsg_PXbrI9o1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_UxRaIVKk, 0, m, &cDelay_UxRaIVKk_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_BpKKTtAG, 0, m, &cDelay_BpKKTtAG_sendMessage);
}

void Heavy_PhaseRing::cMsg_9XM6FGcR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_HxHHiAxZ, HV_BINOP_MAX, 1, m, &cBinop_HxHHiAxZ_sendMessage);
}

void Heavy_PhaseRing::cBinop_HxHHiAxZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_c4Fu8MNv, HV_BINOP_SUBTRACT, 1, m, &cBinop_c4Fu8MNv_sendMessage);
}

void Heavy_PhaseRing::cCast_mxIL9u74_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_UxRaIVKk, 0, m, &cDelay_UxRaIVKk_sendMessage);
}

void Heavy_PhaseRing::cBinop_8PT7dkj8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_UxRaIVKk, 2, m, &cDelay_UxRaIVKk_sendMessage);
}

void Heavy_PhaseRing::cBinop_0gWdQTHL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_8PT7dkj8_sendMessage);
}

void Heavy_PhaseRing::cCast_ViRRCAP2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_kUYYAuQl, 0, m, &cVar_kUYYAuQl_sendMessage);
  cMsg_rCyRjsTK_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_y1YWpaio, 0, m, &cTabhead_y1YWpaio_sendMessage);
}

void Heavy_PhaseRing::cMsg_ccigFJUs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_YD5ptDSa_sendMessage);
}

void Heavy_PhaseRing::cSystem_YD5ptDSa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_yeI6PtWE_sendMessage);
}

void Heavy_PhaseRing::cDelay_xjwuI8my_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_xjwuI8my, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_kXwxpTBz, 0, m, &cDelay_kXwxpTBz_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_xjwuI8my, 0, m, &cDelay_xjwuI8my_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_gDJsvhqR, 1, m, NULL);
}

void Heavy_PhaseRing::cDelay_kXwxpTBz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_kXwxpTBz, m);
  cMsg_H206DmL4_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_MEKGtudJ_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_quWOvxRV_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_jKo9MjaP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_klxTYVIZ_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::hTable_OUSNvdru_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_zpXw1kNM_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_xjwuI8my, 2, m, &cDelay_xjwuI8my_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Xs9n3Qmx_sendMessage);
}

void Heavy_PhaseRing::cMsg_klxTYVIZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_OUSNvdru, 0, m, &hTable_OUSNvdru_sendMessage);
}

void Heavy_PhaseRing::cBinop_yeI6PtWE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 25.796f, 0, m, &cBinop_jKo9MjaP_sendMessage);
}

void Heavy_PhaseRing::cMsg_H206DmL4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_OUSNvdru, 0, m, &hTable_OUSNvdru_sendMessage);
}

void Heavy_PhaseRing::cCast_Xs9n3Qmx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_xjwuI8my, 0, m, &cDelay_xjwuI8my_sendMessage);
}

void Heavy_PhaseRing::cMsg_zpXw1kNM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_kXwxpTBz, 2, m, &cDelay_kXwxpTBz_sendMessage);
}

void Heavy_PhaseRing::cMsg_quWOvxRV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_gDJsvhqR, 1, m, NULL);
}

void Heavy_PhaseRing::cTabhead_6DgCmMTD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_FueBxgI1, HV_BINOP_SUBTRACT, 0, m, &cBinop_FueBxgI1_sendMessage);
}

void Heavy_PhaseRing::cMsg_K7sAQcAH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_eRqPPTBa_sendMessage);
}

void Heavy_PhaseRing::cSystem_eRqPPTBa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_IPf9Mynm_sendMessage);
}

void Heavy_PhaseRing::cVar_AIrMCi7o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_IgToVfvn_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cDelay_o0jECghx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_o0jECghx, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_t1zCdCRk, 0, m, &cDelay_t1zCdCRk_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_GyrieBLV, 0, m, &sTabread_GyrieBLV_sendMessage);
}

void Heavy_PhaseRing::cDelay_t1zCdCRk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_t1zCdCRk, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_GyrieBLV, 0, m, &sTabread_GyrieBLV_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_t1zCdCRk, 0, m, &cDelay_t1zCdCRk_sendMessage);
}

void Heavy_PhaseRing::sTabread_GyrieBLV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_MJaRptpQ, HV_BINOP_SUBTRACT, 0, m, &cBinop_MJaRptpQ_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_UYELI28S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_XoIxavbh, HV_BINOP_MAX, 0, m, &cBinop_XoIxavbh_sendMessage);
}

void Heavy_PhaseRing::cBinop_IPf9Mynm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_UYELI28S, HV_BINOP_MULTIPLY, 0, m, &cBinop_UYELI28S_sendMessage);
}

void Heavy_PhaseRing::cBinop_FueBxgI1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Ew4lc86c_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_GyrieBLV, 0, m, &sTabread_GyrieBLV_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_I8bDXvN4_sendMessage);
}

void Heavy_PhaseRing::cSystem_3Von2tTZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MJaRptpQ, HV_BINOP_SUBTRACT, 1, m, &cBinop_MJaRptpQ_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_t1zCdCRk, 2, m, &cDelay_t1zCdCRk_sendMessage);
}

void Heavy_PhaseRing::cMsg_IgToVfvn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_3Von2tTZ_sendMessage);
}

void Heavy_PhaseRing::cMsg_Ew4lc86c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_o0jECghx, 0, m, &cDelay_o0jECghx_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_t1zCdCRk, 0, m, &cDelay_t1zCdCRk_sendMessage);
}

void Heavy_PhaseRing::cMsg_t3Kz71VC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_XoIxavbh, HV_BINOP_MAX, 1, m, &cBinop_XoIxavbh_sendMessage);
}

void Heavy_PhaseRing::cBinop_XoIxavbh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_FueBxgI1, HV_BINOP_SUBTRACT, 1, m, &cBinop_FueBxgI1_sendMessage);
}

void Heavy_PhaseRing::cCast_I8bDXvN4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_o0jECghx, 0, m, &cDelay_o0jECghx_sendMessage);
}

void Heavy_PhaseRing::cBinop_pP3LeO7w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_o0jECghx, 2, m, &cDelay_o0jECghx_sendMessage);
}

void Heavy_PhaseRing::cBinop_MJaRptpQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_pP3LeO7w_sendMessage);
}

void Heavy_PhaseRing::cCast_1hNLJnaK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_AIrMCi7o, 0, m, &cVar_AIrMCi7o_sendMessage);
  cMsg_K7sAQcAH_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_6DgCmMTD, 0, m, &cTabhead_6DgCmMTD_sendMessage);
}

void Heavy_PhaseRing::cMsg_AlMTJXmB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_MoHBFiVG_sendMessage);
}

void Heavy_PhaseRing::cSystem_MoHBFiVG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_aF77krFx_sendMessage);
}

void Heavy_PhaseRing::cDelay_joqrYw8Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_joqrYw8Z, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_xLqzWgwM, 0, m, &cDelay_xLqzWgwM_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_joqrYw8Z, 0, m, &cDelay_joqrYw8Z_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_Nv5UT25H, 1, m, NULL);
}

void Heavy_PhaseRing::cDelay_xLqzWgwM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_xLqzWgwM, m);
  cMsg_mfvp5IfK_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_BlFLW0nd_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_QIU8N1Bs_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_hmmUV5dT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ofX8G8Jf_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::hTable_dbrOf1mE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_gw6SZU2m_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_joqrYw8Z, 2, m, &cDelay_joqrYw8Z_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_sSo54IvZ_sendMessage);
}

void Heavy_PhaseRing::cMsg_ofX8G8Jf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_dbrOf1mE, 0, m, &hTable_dbrOf1mE_sendMessage);
}

void Heavy_PhaseRing::cBinop_aF77krFx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 43.5337f, 0, m, &cBinop_hmmUV5dT_sendMessage);
}

void Heavy_PhaseRing::cMsg_mfvp5IfK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_dbrOf1mE, 0, m, &hTable_dbrOf1mE_sendMessage);
}

void Heavy_PhaseRing::cCast_sSo54IvZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_joqrYw8Z, 0, m, &cDelay_joqrYw8Z_sendMessage);
}

void Heavy_PhaseRing::cMsg_gw6SZU2m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_xLqzWgwM, 2, m, &cDelay_xLqzWgwM_sendMessage);
}

void Heavy_PhaseRing::cMsg_QIU8N1Bs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_Nv5UT25H, 1, m, NULL);
}

void Heavy_PhaseRing::cTabhead_QFpfnUpP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Sib9jbMB, HV_BINOP_SUBTRACT, 0, m, &cBinop_Sib9jbMB_sendMessage);
}

void Heavy_PhaseRing::cMsg_wIwvaL8s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_oWe4Iu3y_sendMessage);
}

void Heavy_PhaseRing::cSystem_oWe4Iu3y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_Pv3WRheU_sendMessage);
}

void Heavy_PhaseRing::cVar_p1m54qKC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_h2F4cK3M_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cDelay_PkT7LPkb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_PkT7LPkb, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_UTRr6u5E, 0, m, &cDelay_UTRr6u5E_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_9iULrxbh, 0, m, &sTabread_9iULrxbh_sendMessage);
}

void Heavy_PhaseRing::cDelay_UTRr6u5E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_UTRr6u5E, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_9iULrxbh, 0, m, &sTabread_9iULrxbh_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_UTRr6u5E, 0, m, &cDelay_UTRr6u5E_sendMessage);
}

void Heavy_PhaseRing::sTabread_9iULrxbh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_i7E5SOQG, HV_BINOP_SUBTRACT, 0, m, &cBinop_i7E5SOQG_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_kCb4FlW0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_SgtRxxgb, HV_BINOP_MAX, 0, m, &cBinop_SgtRxxgb_sendMessage);
}

void Heavy_PhaseRing::cBinop_Pv3WRheU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_kCb4FlW0, HV_BINOP_MULTIPLY, 0, m, &cBinop_kCb4FlW0_sendMessage);
}

void Heavy_PhaseRing::cBinop_Sib9jbMB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_PbDCjzSL_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_9iULrxbh, 0, m, &sTabread_9iULrxbh_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_bvzj7y0B_sendMessage);
}

void Heavy_PhaseRing::cSystem_i7gn0Sz8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_i7E5SOQG, HV_BINOP_SUBTRACT, 1, m, &cBinop_i7E5SOQG_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_UTRr6u5E, 2, m, &cDelay_UTRr6u5E_sendMessage);
}

void Heavy_PhaseRing::cMsg_h2F4cK3M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_i7gn0Sz8_sendMessage);
}

void Heavy_PhaseRing::cMsg_PbDCjzSL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_PkT7LPkb, 0, m, &cDelay_PkT7LPkb_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_UTRr6u5E, 0, m, &cDelay_UTRr6u5E_sendMessage);
}

void Heavy_PhaseRing::cMsg_DuM3fqKJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_SgtRxxgb, HV_BINOP_MAX, 1, m, &cBinop_SgtRxxgb_sendMessage);
}

void Heavy_PhaseRing::cBinop_SgtRxxgb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Sib9jbMB, HV_BINOP_SUBTRACT, 1, m, &cBinop_Sib9jbMB_sendMessage);
}

void Heavy_PhaseRing::cCast_bvzj7y0B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_PkT7LPkb, 0, m, &cDelay_PkT7LPkb_sendMessage);
}

void Heavy_PhaseRing::cBinop_j6oE7iD1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_PkT7LPkb, 2, m, &cDelay_PkT7LPkb_sendMessage);
}

void Heavy_PhaseRing::cBinop_i7E5SOQG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_j6oE7iD1_sendMessage);
}

void Heavy_PhaseRing::cCast_ouB2KDgM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_p1m54qKC, 0, m, &cVar_p1m54qKC_sendMessage);
  cMsg_wIwvaL8s_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_QFpfnUpP, 0, m, &cTabhead_QFpfnUpP_sendMessage);
}

void Heavy_PhaseRing::cMsg_8JVXfjhi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_805Kf16s_sendMessage);
}

void Heavy_PhaseRing::cSystem_805Kf16s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_FW5MzxDE_sendMessage);
}

void Heavy_PhaseRing::cDelay_akVdhqDH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_akVdhqDH, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ehmZRURG, 0, m, &cDelay_ehmZRURG_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_akVdhqDH, 0, m, &cDelay_akVdhqDH_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_X0TP5DSm, 1, m, NULL);
}

void Heavy_PhaseRing::cDelay_ehmZRURG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_ehmZRURG, m);
  cMsg_r2Fay4U7_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_l2m3E7Xl_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_SRddBWSJ_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_nCh3W6gu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_z3k1xv9D_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::hTable_PF8nREmZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_j8MrYpY0_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_akVdhqDH, 2, m, &cDelay_akVdhqDH_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_7MB5CJEY_sendMessage);
}

void Heavy_PhaseRing::cMsg_z3k1xv9D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_PF8nREmZ, 0, m, &hTable_PF8nREmZ_sendMessage);
}

void Heavy_PhaseRing::cBinop_FW5MzxDE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 75.2546f, 0, m, &cBinop_nCh3W6gu_sendMessage);
}

void Heavy_PhaseRing::cMsg_r2Fay4U7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_PF8nREmZ, 0, m, &hTable_PF8nREmZ_sendMessage);
}

void Heavy_PhaseRing::cCast_7MB5CJEY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_akVdhqDH, 0, m, &cDelay_akVdhqDH_sendMessage);
}

void Heavy_PhaseRing::cMsg_j8MrYpY0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_ehmZRURG, 2, m, &cDelay_ehmZRURG_sendMessage);
}

void Heavy_PhaseRing::cMsg_SRddBWSJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_X0TP5DSm, 1, m, NULL);
}

void Heavy_PhaseRing::cVar_Ypxx9KMu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_6LRTzgMY, 0, m, &cVar_6LRTzgMY_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_dfxLSRfh, 0, m, &cVar_dfxLSRfh_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_R4LRTRsI, 0, m, &cVar_R4LRTRsI_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_szbmEw9T, 0, m, &cVar_szbmEw9T_sendMessage);
}

void Heavy_PhaseRing::cVar_DHJ9VxY7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.01f, 0, m, &cBinop_SbJSyuoi_sendMessage);
}

void Heavy_PhaseRing::cPack_mcP6UC3C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_O5wXZwZz, 0, m, NULL);
}

void Heavy_PhaseRing::cVar_dfxLSRfh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_VhLjGT1y, HV_BINOP_MULTIPLY, 0, m, &cBinop_VhLjGT1y_sendMessage);
}

void Heavy_PhaseRing::cMsg_yNShKW90_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Mqzm7Xgd_sendMessage);
}

void Heavy_PhaseRing::cSystem_Mqzm7Xgd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_u84V71qG_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_VhLjGT1y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_nRkBS7FS_sendMessage);
}

void Heavy_PhaseRing::cBinop_HMTUg6bi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_VhLjGT1y, HV_BINOP_MULTIPLY, 1, m, &cBinop_VhLjGT1y_sendMessage);
}

void Heavy_PhaseRing::cMsg_u84V71qG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_HMTUg6bi_sendMessage);
}

void Heavy_PhaseRing::cBinop_nRkBS7FS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_Lz5dQCVv_sendMessage);
}

void Heavy_PhaseRing::cBinop_Lz5dQCVv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_482Hrjvu_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_pLwCfYWS, m);
}

void Heavy_PhaseRing::cBinop_482Hrjvu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_vCqxGV1F, m);
}

void Heavy_PhaseRing::cVar_R4LRTRsI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_axPZlzYm, HV_BINOP_MULTIPLY, 0, m, &cBinop_axPZlzYm_sendMessage);
}

void Heavy_PhaseRing::cMsg_bpJHA15v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_5hv9hxcy_sendMessage);
}

void Heavy_PhaseRing::cSystem_5hv9hxcy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Qq4UsMpW_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_axPZlzYm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_J6Ujuhqc_sendMessage);
}

void Heavy_PhaseRing::cBinop_w3FtVf8I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_axPZlzYm, HV_BINOP_MULTIPLY, 1, m, &cBinop_axPZlzYm_sendMessage);
}

void Heavy_PhaseRing::cMsg_Qq4UsMpW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_w3FtVf8I_sendMessage);
}

void Heavy_PhaseRing::cBinop_J6Ujuhqc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_gS2yBeyS_sendMessage);
}

void Heavy_PhaseRing::cBinop_gS2yBeyS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_eSCXfp8b_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_2GBhmOo7, m);
}

void Heavy_PhaseRing::cBinop_eSCXfp8b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_PrrAT8iu, m);
}

void Heavy_PhaseRing::cVar_szbmEw9T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MiEt9Jgy, HV_BINOP_MULTIPLY, 0, m, &cBinop_MiEt9Jgy_sendMessage);
}

void Heavy_PhaseRing::cMsg_N9C6l6YR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Vib6VrEC_sendMessage);
}

void Heavy_PhaseRing::cSystem_Vib6VrEC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_EkaX9xyi_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_MiEt9Jgy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_06y8ItNS_sendMessage);
}

void Heavy_PhaseRing::cBinop_tttHxJ3O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MiEt9Jgy, HV_BINOP_MULTIPLY, 1, m, &cBinop_MiEt9Jgy_sendMessage);
}

void Heavy_PhaseRing::cMsg_EkaX9xyi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_tttHxJ3O_sendMessage);
}

void Heavy_PhaseRing::cBinop_06y8ItNS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_01333VVM_sendMessage);
}

void Heavy_PhaseRing::cBinop_01333VVM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_Dql8BRhX_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_y7wiJVwz, m);
}

void Heavy_PhaseRing::cBinop_Dql8BRhX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_vtrYp3df, m);
}

void Heavy_PhaseRing::cBinop_pS3SvNMU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_UtJkCIRJ, 0, m, &cPack_UtJkCIRJ_sendMessage);
}

void Heavy_PhaseRing::cMsg_hQVJcr9m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 3000.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_Ypxx9KMu, 0, m, &cVar_Ypxx9KMu_sendMessage);
}

void Heavy_PhaseRing::cBinop_SbJSyuoi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_mcP6UC3C, 0, m, &cPack_mcP6UC3C_sendMessage);
}

void Heavy_PhaseRing::cBinop_jyU3oBi3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_Dr2kPUep, 0, m, &cPack_Dr2kPUep_sendMessage);
}

void Heavy_PhaseRing::cIf_UpldvUnY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_zRIDapa4_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_LOG10, m, &cUnop_cFgO5hKK_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cUnop_cFgO5hKK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_xZ3AIhjV_sendMessage);
}

void Heavy_PhaseRing::cCast_jc9qVWPL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_ZgF1ebX2_sendMessage);
}

void Heavy_PhaseRing::cCast_HdyNh4M2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_UpldvUnY, 0, m, &cIf_UpldvUnY_sendMessage);
}

void Heavy_PhaseRing::cMsg_zRIDapa4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_V0YU1TVm, 0, m, &cVar_V0YU1TVm_sendMessage);
}

void Heavy_PhaseRing::cBinop_xZ3AIhjV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 100.0f, 0, m, &cBinop_dyDksuEX_sendMessage);
}

void Heavy_PhaseRing::cBinop_dyDksuEX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_bDJexQOZ_sendMessage);
}

void Heavy_PhaseRing::cBinop_bDJexQOZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_V0YU1TVm, 0, m, &cVar_V0YU1TVm_sendMessage);
}

void Heavy_PhaseRing::cBinop_ZgF1ebX2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_UpldvUnY, 1, m, &cIf_UpldvUnY_sendMessage);
}

void Heavy_PhaseRing::cBinop_dPqThHAb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_jc9qVWPL_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_HdyNh4M2_sendMessage);
}

void Heavy_PhaseRing::cBinop_aayfKTMC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_dPqThHAb_sendMessage);
}

void Heavy_PhaseRing::cSwitchcase_4bVBwCEP_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_4rwHw4Xv_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_4rwHw4Xv_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_GUVMNm0o, 1, m, &cDelay_GUVMNm0o_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_nF4IC6F7_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cDelay_GUVMNm0o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_GUVMNm0o, m);
  cMsg_MPDfbrjk_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_4rwHw4Xv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_GUVMNm0o, 0, m, &cDelay_GUVMNm0o_sendMessage);
}

void Heavy_PhaseRing::cCast_nF4IC6F7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_GUVMNm0o, 0, m, &cDelay_GUVMNm0o_sendMessage);
}

void Heavy_PhaseRing::cVar_eVA9oNX5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_2Mtgs0Xo, 0, m, &cPack_2Mtgs0Xo_sendMessage);
}

void Heavy_PhaseRing::cVar_kFBk3sAx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.05776f, 0, m, &cBinop_qXd73Oo1_sendMessage);
}

void Heavy_PhaseRing::cVar_9F9lwmxe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_uX9V0ffD_sendMessage);
}

void Heavy_PhaseRing::cPack_8J49SzJl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_tuaBH17A, 0, m, NULL);
}

void Heavy_PhaseRing::cUnop_qNFFgsXc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_XZ2wZEkm_sendMessage);
}

void Heavy_PhaseRing::cBinop_UbYhqA4Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_EXP, m, &cUnop_qNFFgsXc_sendMessage);
}

void Heavy_PhaseRing::cPack_zZXJDA0v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_sxvqfvcd, 0, m, NULL);
}

void Heavy_PhaseRing::cVar_Ty9qbdiW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.5f, 0, m, &cBinop_Vs63Ok3H_sendMessage);
}

void Heavy_PhaseRing::cMsg_ZR8GZi8j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_dscHyY3z_sendMessage);
}

void Heavy_PhaseRing::cSystem_dscHyY3z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_NYV3UKjF_sendMessage);
}

void Heavy_PhaseRing::cDelay_XX9oIoCn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_XX9oIoCn, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_4r4fXfvw, 0, m, &cDelay_4r4fXfvw_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_XX9oIoCn, 0, m, &cDelay_XX9oIoCn_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_51eNDjbo, 1, m, NULL);
}

void Heavy_PhaseRing::cDelay_4r4fXfvw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_4r4fXfvw, m);
  cMsg_8kX2bQso_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_omoW12OW_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_2nmG4SzB_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_lWhWnnSy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_2MLVcb9h_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::hTable_dW7OaQK2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_bXOr6S0K_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_XX9oIoCn, 2, m, &cDelay_XX9oIoCn_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ezwC4bNi_sendMessage);
}

void Heavy_PhaseRing::cMsg_2MLVcb9h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_dW7OaQK2, 0, m, &hTable_dW7OaQK2_sendMessage);
}

void Heavy_PhaseRing::cBinop_NYV3UKjF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 5000.0f, 0, m, &cBinop_lWhWnnSy_sendMessage);
}

void Heavy_PhaseRing::cMsg_8kX2bQso_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_dW7OaQK2, 0, m, &hTable_dW7OaQK2_sendMessage);
}

void Heavy_PhaseRing::cCast_ezwC4bNi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_XX9oIoCn, 0, m, &cDelay_XX9oIoCn_sendMessage);
}

void Heavy_PhaseRing::cMsg_bXOr6S0K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_4r4fXfvw, 2, m, &cDelay_4r4fXfvw_sendMessage);
}

void Heavy_PhaseRing::cMsg_2nmG4SzB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_51eNDjbo, 1, m, NULL);
}

void Heavy_PhaseRing::cMsg_MT6gTPMd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_QG36Qni2_sendMessage);
}

void Heavy_PhaseRing::cSystem_QG36Qni2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_qwNSVErD_sendMessage);
}

void Heavy_PhaseRing::cVar_ZWEmzime_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_1FxOXmbY_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSystem_PI0fOqZr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_Mqow0B9G_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_AhTj46c4, m);
}

void Heavy_PhaseRing::cBinop_qwNSVErD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_L9y5R30m, m);
}

void Heavy_PhaseRing::cMsg_1FxOXmbY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_PI0fOqZr_sendMessage);
}

void Heavy_PhaseRing::cBinop_Mqow0B9G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_R18Afh3V, m);
}

void Heavy_PhaseRing::cMsg_HSbVO19H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_daAu74M7_sendMessage);
}

void Heavy_PhaseRing::cSystem_daAu74M7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_OMoygwWg_sendMessage);
}

void Heavy_PhaseRing::cVar_80yF5D8Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_6DUEXvnY_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSystem_VhimR4Yd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_3Wq7phbm_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_HaKYpd9K, m);
}

void Heavy_PhaseRing::cBinop_OMoygwWg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_jDXW83IH, m);
}

void Heavy_PhaseRing::cMsg_6DUEXvnY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_VhimR4Yd_sendMessage);
}

void Heavy_PhaseRing::cBinop_3Wq7phbm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_ozr8VZvi, m);
}

void Heavy_PhaseRing::cBinop_9tZp3LzP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_UNmxbtJA_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_r2SigIO4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_nXJU8Mnj_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_GRdgOBwv_sendMessage);
}

void Heavy_PhaseRing::cCast_nXJU8Mnj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_9tZp3LzP, HV_BINOP_DIVIDE, 1, m, &cBinop_9tZp3LzP_sendMessage);
}

void Heavy_PhaseRing::cCast_GRdgOBwv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_9tZp3LzP, HV_BINOP_DIVIDE, 0, m, &cBinop_9tZp3LzP_sendMessage);
}

void Heavy_PhaseRing::cBinop_XZ2wZEkm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_prdfvbiA_sendMessage);
}

void Heavy_PhaseRing::cBinop_qXd73Oo1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 87.3365f, 0, m, &cBinop_UbYhqA4Y_sendMessage);
}

void Heavy_PhaseRing::cBinop_prdfvbiA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_9tZp3LzP, HV_BINOP_DIVIDE, 0, m, &cBinop_9tZp3LzP_sendMessage);
}

void Heavy_PhaseRing::cBinop_Vs63Ok3H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_zZXJDA0v, 0, m, &cPack_zZXJDA0v_sendMessage);
}

void Heavy_PhaseRing::cBinop_uX9V0ffD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.001f, 0, m, &cBinop_r2SigIO4_sendMessage);
  cPack_onMessage(_c, &Context(_c)->cPack_8J49SzJl, 0, m, &cPack_8J49SzJl_sendMessage);
}

void Heavy_PhaseRing::cMsg_IIcGIExe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 100.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_9F9lwmxe, 0, m, &cVar_9F9lwmxe_sendMessage);
}

void Heavy_PhaseRing::cMsg_l4kawpgZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.5f);
  cVar_onMessage(_c, &Context(_c)->cVar_Ty9qbdiW, 0, m, &cVar_Ty9qbdiW_sendMessage);
}

void Heavy_PhaseRing::cMsg_UNmxbtJA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 30.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_WlHXNuWP, 0, m, NULL);
}

void Heavy_PhaseRing::cVar_TocowoRV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_sh1zz2uW, HV_BINOP_MULTIPLY, 0, m, &cBinop_sh1zz2uW_sendMessage);
}

void Heavy_PhaseRing::cMsg_DnVkcDUh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_e6kD2NUW_sendMessage);
}

void Heavy_PhaseRing::cSystem_e6kD2NUW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_lCyswKzr_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_sh1zz2uW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_Kx5LgrSb_sendMessage);
}

void Heavy_PhaseRing::cBinop_I7Qm6GSN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_sh1zz2uW, HV_BINOP_MULTIPLY, 1, m, &cBinop_sh1zz2uW_sendMessage);
}

void Heavy_PhaseRing::cMsg_lCyswKzr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_I7Qm6GSN_sendMessage);
}

void Heavy_PhaseRing::cBinop_Kx5LgrSb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_zVVHdBLh_sendMessage);
}

void Heavy_PhaseRing::cBinop_zVVHdBLh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_KwGjKM10_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_bj2eZCY4, m);
}

void Heavy_PhaseRing::cBinop_KwGjKM10_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_08CbyBYq, m);
}

void Heavy_PhaseRing::cVar_1V6rz622_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_iq0dyH4B, HV_BINOP_MULTIPLY, 0, m, &cBinop_iq0dyH4B_sendMessage);
}

void Heavy_PhaseRing::cMsg_Tzr9FRRg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_bflSTCh3_sendMessage);
}

void Heavy_PhaseRing::cSystem_bflSTCh3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_b7Xce9oy_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_iq0dyH4B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_4XGEGhFK_sendMessage);
}

void Heavy_PhaseRing::cBinop_ZCD4QQG9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_iq0dyH4B, HV_BINOP_MULTIPLY, 1, m, &cBinop_iq0dyH4B_sendMessage);
}

void Heavy_PhaseRing::cMsg_b7Xce9oy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_ZCD4QQG9_sendMessage);
}

void Heavy_PhaseRing::cBinop_4XGEGhFK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_84B0G2AP_sendMessage);
}

void Heavy_PhaseRing::cBinop_84B0G2AP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_TcVK4ceR_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_OSmCag9h, m);
}

void Heavy_PhaseRing::cBinop_TcVK4ceR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_YJer2oM4, m);
}

void Heavy_PhaseRing::cVar_6kqa7WwG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_8CgtTAiB, HV_BINOP_MULTIPLY, 0, m, &cBinop_8CgtTAiB_sendMessage);
}

void Heavy_PhaseRing::cMsg_Gzt9gv5h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_HAQtJNuB_sendMessage);
}

void Heavy_PhaseRing::cSystem_HAQtJNuB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_gU5JHpkt_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_8CgtTAiB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_BlidmU85_sendMessage);
}

void Heavy_PhaseRing::cBinop_y3zqkAvF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_8CgtTAiB, HV_BINOP_MULTIPLY, 1, m, &cBinop_8CgtTAiB_sendMessage);
}

void Heavy_PhaseRing::cMsg_gU5JHpkt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_y3zqkAvF_sendMessage);
}

void Heavy_PhaseRing::cBinop_BlidmU85_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_0pTgdEeP_sendMessage);
}

void Heavy_PhaseRing::cBinop_0pTgdEeP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_P60oVJfE_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_BkxhEV53, m);
}

void Heavy_PhaseRing::cBinop_P60oVJfE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_NYESUzF7, m);
}

void Heavy_PhaseRing::cMsg_DMZlK2IE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_xspwI7b7_sendMessage);
}

void Heavy_PhaseRing::cSystem_xspwI7b7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ZxhjdphL_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cVar_Xe9Np1Ow_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1e-05f, 0, m, &cBinop_rhfH5baZ_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_vBqFdSCQ, 0, m, &cIf_vBqFdSCQ_sendMessage);
}

void Heavy_PhaseRing::cIf_vBqFdSCQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_sCWXLFjM_sendMessage(_c, 0, m);
      cMsg_36T9VQjZ_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_JGzqVk8s_sendMessage(_c, 0, m);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_Ln1Wd6s8_sendMessage);
      sVarf_onMessage(_c, &Context(_c)->sVarf_kTPQgpHs, m);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_rhfH5baZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_vBqFdSCQ, 1, m, &cIf_vBqFdSCQ_sendMessage);
}

void Heavy_PhaseRing::cMsg_JGzqVk8s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_CkFuaqu9_sendMessage);
}

void Heavy_PhaseRing::cBinop_CkFuaqu9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_6eiusMfy, m);
}

void Heavy_PhaseRing::cBinop_Ln1Wd6s8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_GdzWlef2_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_GdzWlef2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_ivd1Pvx1_sendMessage);
}

void Heavy_PhaseRing::cBinop_ivd1Pvx1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_YpVVkTue_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_YpVVkTue_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_dDE2Qw22_sendMessage);
}

void Heavy_PhaseRing::cBinop_dDE2Qw22_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_3Osityy7, m);
}

void Heavy_PhaseRing::cBinop_WzrPc2Db_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_poylECiY, m);
}

void Heavy_PhaseRing::cMsg_ZxhjdphL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_WzrPc2Db_sendMessage);
}

void Heavy_PhaseRing::cMsg_sCWXLFjM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_Ln1Wd6s8_sendMessage);
}

void Heavy_PhaseRing::cMsg_36T9VQjZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, -1.0f);
  sVarf_onMessage(_c, &Context(_c)->sVarf_6eiusMfy, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_kTPQgpHs, m);
}

void Heavy_PhaseRing::cBinop_AO9pCsX9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_1V6rz622, 0, m, &cVar_1V6rz622_sendMessage);
}

void Heavy_PhaseRing::cBinop_H9skCRUc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_TocowoRV, 0, m, &cVar_TocowoRV_sendMessage);
}

void Heavy_PhaseRing::cBinop_d2iJdJ5N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_6kqa7WwG, 0, m, &cVar_6kqa7WwG_sendMessage);
}

void Heavy_PhaseRing::cCast_fZKTl8qi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.0f, 0, m, &cBinop_H9skCRUc_sendMessage);
}

void Heavy_PhaseRing::cCast_iYPY8JgN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.0f, 0, m, &cBinop_d2iJdJ5N_sendMessage);
}

void Heavy_PhaseRing::cCast_2wQulzCB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_qntFe5GV, m);
}

void Heavy_PhaseRing::cCast_6A1Jdj2H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.0f, 0, m, &cBinop_AO9pCsX9_sendMessage);
}

void Heavy_PhaseRing::cTabhead_WsZHRWlg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_jeKPq1qD, HV_BINOP_SUBTRACT, 0, m, &cBinop_jeKPq1qD_sendMessage);
}

void Heavy_PhaseRing::cMsg_4uf04fqp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_6vOCJe9k_sendMessage);
}

void Heavy_PhaseRing::cSystem_6vOCJe9k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_6bi4zDWJ_sendMessage);
}

void Heavy_PhaseRing::cVar_XthSwvQT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_EiqOYd9M_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cDelay_MVnO0n9W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_MVnO0n9W, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_zU2TAv1u, 0, m, &cDelay_zU2TAv1u_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_asKRgqEu, 0, m, &sTabread_asKRgqEu_sendMessage);
}

void Heavy_PhaseRing::cDelay_zU2TAv1u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_zU2TAv1u, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_asKRgqEu, 0, m, &sTabread_asKRgqEu_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_zU2TAv1u, 0, m, &cDelay_zU2TAv1u_sendMessage);
}

void Heavy_PhaseRing::sTabread_asKRgqEu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_xBsQkQji, HV_BINOP_SUBTRACT, 0, m, &cBinop_xBsQkQji_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_kKNh0Z1C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Prv3aDNF, HV_BINOP_MAX, 0, m, &cBinop_Prv3aDNF_sendMessage);
}

void Heavy_PhaseRing::cBinop_6bi4zDWJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_kKNh0Z1C, HV_BINOP_MULTIPLY, 0, m, &cBinop_kKNh0Z1C_sendMessage);
}

void Heavy_PhaseRing::cBinop_jeKPq1qD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_qcKK8N0n_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_asKRgqEu, 0, m, &sTabread_asKRgqEu_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_u1WjIVYo_sendMessage);
}

void Heavy_PhaseRing::cSystem_9y4GYbRn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_xBsQkQji, HV_BINOP_SUBTRACT, 1, m, &cBinop_xBsQkQji_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_zU2TAv1u, 2, m, &cDelay_zU2TAv1u_sendMessage);
}

void Heavy_PhaseRing::cMsg_EiqOYd9M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_9y4GYbRn_sendMessage);
}

void Heavy_PhaseRing::cMsg_qcKK8N0n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_MVnO0n9W, 0, m, &cDelay_MVnO0n9W_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_zU2TAv1u, 0, m, &cDelay_zU2TAv1u_sendMessage);
}

void Heavy_PhaseRing::cMsg_JiEcyKEe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_Prv3aDNF, HV_BINOP_MAX, 1, m, &cBinop_Prv3aDNF_sendMessage);
}

void Heavy_PhaseRing::cBinop_Prv3aDNF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_jeKPq1qD, HV_BINOP_SUBTRACT, 1, m, &cBinop_jeKPq1qD_sendMessage);
}

void Heavy_PhaseRing::cCast_u1WjIVYo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_MVnO0n9W, 0, m, &cDelay_MVnO0n9W_sendMessage);
}

void Heavy_PhaseRing::cBinop_xkvv7xjX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_MVnO0n9W, 2, m, &cDelay_MVnO0n9W_sendMessage);
}

void Heavy_PhaseRing::cBinop_xBsQkQji_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_xkvv7xjX_sendMessage);
}

void Heavy_PhaseRing::cCast_rtEPdpC1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_XthSwvQT, 0, m, &cVar_XthSwvQT_sendMessage);
  cMsg_4uf04fqp_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_WsZHRWlg, 0, m, &cTabhead_WsZHRWlg_sendMessage);
}

void Heavy_PhaseRing::cTabhead_SOQTdbn3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_unQtei3o, HV_BINOP_SUBTRACT, 0, m, &cBinop_unQtei3o_sendMessage);
}

void Heavy_PhaseRing::cMsg_ZWo7INuH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Tan46Yi9_sendMessage);
}

void Heavy_PhaseRing::cSystem_Tan46Yi9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_D32iC55A_sendMessage);
}

void Heavy_PhaseRing::cVar_XGhd7fqo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_6ANpKzWL_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cDelay_zyoYRBTE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_zyoYRBTE, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_NLHDBrgj, 0, m, &cDelay_NLHDBrgj_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_3O74jFKr, 0, m, &sTabread_3O74jFKr_sendMessage);
}

void Heavy_PhaseRing::cDelay_NLHDBrgj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_NLHDBrgj, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_3O74jFKr, 0, m, &sTabread_3O74jFKr_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_NLHDBrgj, 0, m, &cDelay_NLHDBrgj_sendMessage);
}

void Heavy_PhaseRing::sTabread_3O74jFKr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_ZAryfs8e, HV_BINOP_SUBTRACT, 0, m, &cBinop_ZAryfs8e_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_YzrSfIlJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_vRYuhFmg, HV_BINOP_MAX, 0, m, &cBinop_vRYuhFmg_sendMessage);
}

void Heavy_PhaseRing::cBinop_D32iC55A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_YzrSfIlJ, HV_BINOP_MULTIPLY, 0, m, &cBinop_YzrSfIlJ_sendMessage);
}

void Heavy_PhaseRing::cBinop_unQtei3o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_QOODJf3I_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_3O74jFKr, 0, m, &sTabread_3O74jFKr_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_4naReEQI_sendMessage);
}

void Heavy_PhaseRing::cSystem_8nbVt3hO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ZAryfs8e, HV_BINOP_SUBTRACT, 1, m, &cBinop_ZAryfs8e_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_NLHDBrgj, 2, m, &cDelay_NLHDBrgj_sendMessage);
}

void Heavy_PhaseRing::cMsg_6ANpKzWL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_8nbVt3hO_sendMessage);
}

void Heavy_PhaseRing::cMsg_QOODJf3I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_zyoYRBTE, 0, m, &cDelay_zyoYRBTE_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_NLHDBrgj, 0, m, &cDelay_NLHDBrgj_sendMessage);
}

void Heavy_PhaseRing::cMsg_o7fTwwgi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_vRYuhFmg, HV_BINOP_MAX, 1, m, &cBinop_vRYuhFmg_sendMessage);
}

void Heavy_PhaseRing::cBinop_vRYuhFmg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_unQtei3o, HV_BINOP_SUBTRACT, 1, m, &cBinop_unQtei3o_sendMessage);
}

void Heavy_PhaseRing::cCast_4naReEQI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_zyoYRBTE, 0, m, &cDelay_zyoYRBTE_sendMessage);
}

void Heavy_PhaseRing::cBinop_xTS3Rc6h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_zyoYRBTE, 2, m, &cDelay_zyoYRBTE_sendMessage);
}

void Heavy_PhaseRing::cBinop_ZAryfs8e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_xTS3Rc6h_sendMessage);
}

void Heavy_PhaseRing::cCast_R2Ne7Vqd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_XGhd7fqo, 0, m, &cVar_XGhd7fqo_sendMessage);
  cMsg_ZWo7INuH_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_SOQTdbn3, 0, m, &cTabhead_SOQTdbn3_sendMessage);
}

void Heavy_PhaseRing::cTabhead_8Xfd0Yjh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Vem5iuxx, HV_BINOP_SUBTRACT, 0, m, &cBinop_Vem5iuxx_sendMessage);
}

void Heavy_PhaseRing::cMsg_WV7IXGms_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_sTytTkvu_sendMessage);
}

void Heavy_PhaseRing::cSystem_sTytTkvu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_m1HKpj8v_sendMessage);
}

void Heavy_PhaseRing::cVar_J7EQE7NA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_krBkmqdW_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cDelay_V5OCkCgf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_V5OCkCgf, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_rAO4jTiS, 0, m, &cDelay_rAO4jTiS_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_KyYkqv9N, 0, m, &sTabread_KyYkqv9N_sendMessage);
}

void Heavy_PhaseRing::cDelay_rAO4jTiS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_rAO4jTiS, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_KyYkqv9N, 0, m, &sTabread_KyYkqv9N_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_rAO4jTiS, 0, m, &cDelay_rAO4jTiS_sendMessage);
}

void Heavy_PhaseRing::sTabread_KyYkqv9N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_cpmykcSH, HV_BINOP_SUBTRACT, 0, m, &cBinop_cpmykcSH_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_hm9F1nMK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_9VVdhNp0, HV_BINOP_MAX, 0, m, &cBinop_9VVdhNp0_sendMessage);
}

void Heavy_PhaseRing::cBinop_m1HKpj8v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_hm9F1nMK, HV_BINOP_MULTIPLY, 0, m, &cBinop_hm9F1nMK_sendMessage);
}

void Heavy_PhaseRing::cBinop_Vem5iuxx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ahKR2DFv_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_KyYkqv9N, 0, m, &sTabread_KyYkqv9N_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_TP88uwYc_sendMessage);
}

void Heavy_PhaseRing::cSystem_VkBzMrEp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_cpmykcSH, HV_BINOP_SUBTRACT, 1, m, &cBinop_cpmykcSH_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_rAO4jTiS, 2, m, &cDelay_rAO4jTiS_sendMessage);
}

void Heavy_PhaseRing::cMsg_krBkmqdW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_VkBzMrEp_sendMessage);
}

void Heavy_PhaseRing::cMsg_ahKR2DFv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_V5OCkCgf, 0, m, &cDelay_V5OCkCgf_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_rAO4jTiS, 0, m, &cDelay_rAO4jTiS_sendMessage);
}

void Heavy_PhaseRing::cMsg_l0m8oKyS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_9VVdhNp0, HV_BINOP_MAX, 1, m, &cBinop_9VVdhNp0_sendMessage);
}

void Heavy_PhaseRing::cBinop_9VVdhNp0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Vem5iuxx, HV_BINOP_SUBTRACT, 1, m, &cBinop_Vem5iuxx_sendMessage);
}

void Heavy_PhaseRing::cCast_TP88uwYc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_V5OCkCgf, 0, m, &cDelay_V5OCkCgf_sendMessage);
}

void Heavy_PhaseRing::cBinop_ZjLckMYZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_V5OCkCgf, 2, m, &cDelay_V5OCkCgf_sendMessage);
}

void Heavy_PhaseRing::cBinop_cpmykcSH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_ZjLckMYZ_sendMessage);
}

void Heavy_PhaseRing::cCast_IVIfl59i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_J7EQE7NA, 0, m, &cVar_J7EQE7NA_sendMessage);
  cMsg_WV7IXGms_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_8Xfd0Yjh, 0, m, &cTabhead_8Xfd0Yjh_sendMessage);
}

void Heavy_PhaseRing::cTabhead_uP65eeQc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_0NHbbd25, HV_BINOP_SUBTRACT, 0, m, &cBinop_0NHbbd25_sendMessage);
}

void Heavy_PhaseRing::cMsg_3EiEXYQx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_znhU0IVb_sendMessage);
}

void Heavy_PhaseRing::cSystem_znhU0IVb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_1BeELTSL_sendMessage);
}

void Heavy_PhaseRing::cVar_dHJgW9Vn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_nhHoaZdu_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cDelay_uKKR5B2w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_uKKR5B2w, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_8QWS7v0a, 0, m, &cDelay_8QWS7v0a_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_Jan5l5fZ, 0, m, &sTabread_Jan5l5fZ_sendMessage);
}

void Heavy_PhaseRing::cDelay_8QWS7v0a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_8QWS7v0a, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_Jan5l5fZ, 0, m, &sTabread_Jan5l5fZ_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_8QWS7v0a, 0, m, &cDelay_8QWS7v0a_sendMessage);
}

void Heavy_PhaseRing::sTabread_Jan5l5fZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_j7Gb85U9, HV_BINOP_SUBTRACT, 0, m, &cBinop_j7Gb85U9_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_E5NbDk0d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_DVwohSoS, HV_BINOP_MAX, 0, m, &cBinop_DVwohSoS_sendMessage);
}

void Heavy_PhaseRing::cBinop_1BeELTSL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_E5NbDk0d, HV_BINOP_MULTIPLY, 0, m, &cBinop_E5NbDk0d_sendMessage);
}

void Heavy_PhaseRing::cBinop_0NHbbd25_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_i1s63LuH_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_Jan5l5fZ, 0, m, &sTabread_Jan5l5fZ_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_THgMQs4D_sendMessage);
}

void Heavy_PhaseRing::cSystem_yh8QOtQ4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_j7Gb85U9, HV_BINOP_SUBTRACT, 1, m, &cBinop_j7Gb85U9_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_8QWS7v0a, 2, m, &cDelay_8QWS7v0a_sendMessage);
}

void Heavy_PhaseRing::cMsg_nhHoaZdu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_yh8QOtQ4_sendMessage);
}

void Heavy_PhaseRing::cMsg_i1s63LuH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_uKKR5B2w, 0, m, &cDelay_uKKR5B2w_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_8QWS7v0a, 0, m, &cDelay_8QWS7v0a_sendMessage);
}

void Heavy_PhaseRing::cMsg_XCW9ujSH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_DVwohSoS, HV_BINOP_MAX, 1, m, &cBinop_DVwohSoS_sendMessage);
}

void Heavy_PhaseRing::cBinop_DVwohSoS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_0NHbbd25, HV_BINOP_SUBTRACT, 1, m, &cBinop_0NHbbd25_sendMessage);
}

void Heavy_PhaseRing::cCast_THgMQs4D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_uKKR5B2w, 0, m, &cDelay_uKKR5B2w_sendMessage);
}

void Heavy_PhaseRing::cBinop_qo2NKPAP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_uKKR5B2w, 2, m, &cDelay_uKKR5B2w_sendMessage);
}

void Heavy_PhaseRing::cBinop_j7Gb85U9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_qo2NKPAP_sendMessage);
}

void Heavy_PhaseRing::cCast_qazOJ5zn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_dHJgW9Vn, 0, m, &cVar_dHJgW9Vn_sendMessage);
  cMsg_3EiEXYQx_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_uP65eeQc, 0, m, &cTabhead_uP65eeQc_sendMessage);
}

void Heavy_PhaseRing::cMsg_ElKS9Gb3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_1iFpjKhL_sendMessage);
}

void Heavy_PhaseRing::cSystem_1iFpjKhL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_1PrbqhUg_sendMessage);
}

void Heavy_PhaseRing::cDelay_Pa8fXC6Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Pa8fXC6Y, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_PWBNBgSY, 0, m, &cDelay_PWBNBgSY_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Pa8fXC6Y, 0, m, &cDelay_Pa8fXC6Y_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_D9LtEcPs, 1, m, NULL);
}

void Heavy_PhaseRing::cDelay_PWBNBgSY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_PWBNBgSY, m);
  cMsg_Pvg4NVz7_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_wXqP0Eeg_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_iNtSNPbj_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_6sZikY1Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_SuNNQqZS_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::hTable_rHA5FkX9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_zRnxIYWC_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Pa8fXC6Y, 2, m, &cDelay_Pa8fXC6Y_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_h5TO095a_sendMessage);
}

void Heavy_PhaseRing::cMsg_SuNNQqZS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_rHA5FkX9, 0, m, &hTable_rHA5FkX9_sendMessage);
}

void Heavy_PhaseRing::cBinop_1PrbqhUg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 58.6435f, 0, m, &cBinop_6sZikY1Y_sendMessage);
}

void Heavy_PhaseRing::cMsg_Pvg4NVz7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_rHA5FkX9, 0, m, &hTable_rHA5FkX9_sendMessage);
}

void Heavy_PhaseRing::cCast_h5TO095a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Pa8fXC6Y, 0, m, &cDelay_Pa8fXC6Y_sendMessage);
}

void Heavy_PhaseRing::cMsg_zRnxIYWC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_PWBNBgSY, 2, m, &cDelay_PWBNBgSY_sendMessage);
}

void Heavy_PhaseRing::cMsg_iNtSNPbj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_D9LtEcPs, 1, m, NULL);
}

void Heavy_PhaseRing::cMsg_sOKjRJ4u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_48czae3g_sendMessage);
}

void Heavy_PhaseRing::cSystem_48czae3g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_uWi562LO_sendMessage);
}

void Heavy_PhaseRing::cDelay_2xZ3624t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_2xZ3624t, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_KTnbVxcz, 0, m, &cDelay_KTnbVxcz_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_2xZ3624t, 0, m, &cDelay_2xZ3624t_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_jPyR4a4t, 1, m, NULL);
}

void Heavy_PhaseRing::cDelay_KTnbVxcz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_KTnbVxcz, m);
  cMsg_TznUohqg_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_awvbYIak_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_I4Sbp2wV_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_wVNe8bT3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_OnDVtLZ6_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::hTable_3DbJfxpg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_SIEYluX0_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_2xZ3624t, 2, m, &cDelay_2xZ3624t_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_1n4CHTIL_sendMessage);
}

void Heavy_PhaseRing::cMsg_OnDVtLZ6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_3DbJfxpg, 0, m, &hTable_3DbJfxpg_sendMessage);
}

void Heavy_PhaseRing::cBinop_uWi562LO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 69.4325f, 0, m, &cBinop_wVNe8bT3_sendMessage);
}

void Heavy_PhaseRing::cMsg_TznUohqg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_3DbJfxpg, 0, m, &hTable_3DbJfxpg_sendMessage);
}

void Heavy_PhaseRing::cCast_1n4CHTIL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_2xZ3624t, 0, m, &cDelay_2xZ3624t_sendMessage);
}

void Heavy_PhaseRing::cMsg_SIEYluX0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_KTnbVxcz, 2, m, &cDelay_KTnbVxcz_sendMessage);
}

void Heavy_PhaseRing::cMsg_I4Sbp2wV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_jPyR4a4t, 1, m, NULL);
}

void Heavy_PhaseRing::cMsg_XJW8pwMJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_tqa5k9Du_sendMessage);
}

void Heavy_PhaseRing::cSystem_tqa5k9Du_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_beFInTZH_sendMessage);
}

void Heavy_PhaseRing::cDelay_40rfzunH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_40rfzunH, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_zgvHbjai, 0, m, &cDelay_zgvHbjai_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_40rfzunH, 0, m, &cDelay_40rfzunH_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_6b7yuS5B, 1, m, NULL);
}

void Heavy_PhaseRing::cDelay_zgvHbjai_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_zgvHbjai, m);
  cMsg_1WIHgIQu_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_nPfTBqSr_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_aB9OBBUG_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_14PSemxk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_5lyejNbv_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::hTable_3IFV6IkW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_yEhZlQyl_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_40rfzunH, 2, m, &cDelay_40rfzunH_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_PQZEI9ZA_sendMessage);
}

void Heavy_PhaseRing::cMsg_5lyejNbv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_3IFV6IkW, 0, m, &hTable_3IFV6IkW_sendMessage);
}

void Heavy_PhaseRing::cBinop_beFInTZH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 74.5234f, 0, m, &cBinop_14PSemxk_sendMessage);
}

void Heavy_PhaseRing::cMsg_1WIHgIQu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_3IFV6IkW, 0, m, &hTable_3IFV6IkW_sendMessage);
}

void Heavy_PhaseRing::cCast_PQZEI9ZA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_40rfzunH, 0, m, &cDelay_40rfzunH_sendMessage);
}

void Heavy_PhaseRing::cMsg_yEhZlQyl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_zgvHbjai, 2, m, &cDelay_zgvHbjai_sendMessage);
}

void Heavy_PhaseRing::cMsg_aB9OBBUG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_6b7yuS5B, 1, m, NULL);
}

void Heavy_PhaseRing::cMsg_7E7iYlMU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_vLNe4CTb_sendMessage);
}

void Heavy_PhaseRing::cSystem_vLNe4CTb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_t9MXcJ1W_sendMessage);
}

void Heavy_PhaseRing::cDelay_nFkM3sva_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_nFkM3sva, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_3v3UVkYh, 0, m, &cDelay_3v3UVkYh_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_nFkM3sva, 0, m, &cDelay_nFkM3sva_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_ElpbN6Kw, 1, m, NULL);
}

void Heavy_PhaseRing::cDelay_3v3UVkYh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_3v3UVkYh, m);
  cMsg_P8WmLY7U_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_d4ix5YO6_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_wOAJj2ys_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_ovtjcpuH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_seSbKUMK_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::hTable_88pSgIIG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_7jjwFYVw_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_nFkM3sva, 2, m, &cDelay_nFkM3sva_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_b4os4aFk_sendMessage);
}

void Heavy_PhaseRing::cMsg_seSbKUMK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_88pSgIIG, 0, m, &hTable_88pSgIIG_sendMessage);
}

void Heavy_PhaseRing::cBinop_t9MXcJ1W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 86.1244f, 0, m, &cBinop_ovtjcpuH_sendMessage);
}

void Heavy_PhaseRing::cMsg_P8WmLY7U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_88pSgIIG, 0, m, &hTable_88pSgIIG_sendMessage);
}

void Heavy_PhaseRing::cCast_b4os4aFk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_nFkM3sva, 0, m, &cDelay_nFkM3sva_sendMessage);
}

void Heavy_PhaseRing::cMsg_7jjwFYVw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_3v3UVkYh, 2, m, &cDelay_3v3UVkYh_sendMessage);
}

void Heavy_PhaseRing::cMsg_wOAJj2ys_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_ElpbN6Kw, 1, m, NULL);
}

void Heavy_PhaseRing::cIf_7IzFaJX1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_qHv0jvyG_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_c81bkAv1_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cMsg_67WAeWN4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_JaVhOH2g, HV_BINOP_POW, 0, m, &cBinop_JaVhOH2g_sendMessage);
}

void Heavy_PhaseRing::cBinop_JaVhOH2g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.125f, 0, m, &cBinop_zkclMXzD_sendMessage);
}

void Heavy_PhaseRing::cBinop_XetxJi7Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_ZmSKuQEQ_sendMessage);
}

void Heavy_PhaseRing::cCast_umVEEwdc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_7IzFaJX1, 0, m, &cIf_7IzFaJX1_sendMessage);
}

void Heavy_PhaseRing::cCast_9l3YyNDO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_AoZTiWzT_sendMessage);
}

void Heavy_PhaseRing::cBinop_AoZTiWzT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_7IzFaJX1, 1, m, &cIf_7IzFaJX1_sendMessage);
}

void Heavy_PhaseRing::cBinop_c81bkAv1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_XetxJi7Q_sendMessage);
}

void Heavy_PhaseRing::cMsg_qHv0jvyG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.125f, 0, m, &cBinop_zkclMXzD_sendMessage);
}

void Heavy_PhaseRing::cBinop_ZmSKuQEQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_JaVhOH2g, HV_BINOP_POW, 1, m, &cBinop_JaVhOH2g_sendMessage);
  cMsg_67WAeWN4_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cPack_b2GzXqjm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_DfVbyDW7, 0, m, NULL);
}

void Heavy_PhaseRing::cPack_QAEz3vyM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_aYQ4VZ5j, 0, m, NULL);
}

void Heavy_PhaseRing::cBinop_y1WD1rXv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_ZonVM2zm_sendMessage);
}

void Heavy_PhaseRing::cBinop_ZonVM2zm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 200.0f, 0, m, &cBinop_2phWpGZM_sendMessage);
}

void Heavy_PhaseRing::cVar_FZGTin4Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_JNW1IMkA, HV_BINOP_MULTIPLY, 0, m, &cBinop_JNW1IMkA_sendMessage);
}

void Heavy_PhaseRing::cMsg_7d71pZs7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_PfeN7RA1_sendMessage);
}

void Heavy_PhaseRing::cSystem_PfeN7RA1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_wnpjnZaW_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_JNW1IMkA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_nxu8ibhy_sendMessage);
}

void Heavy_PhaseRing::cBinop_rCPcNff7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_JNW1IMkA, HV_BINOP_MULTIPLY, 1, m, &cBinop_JNW1IMkA_sendMessage);
}

void Heavy_PhaseRing::cMsg_wnpjnZaW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_rCPcNff7_sendMessage);
}

void Heavy_PhaseRing::cBinop_nxu8ibhy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_OPshUpWm_sendMessage);
}

void Heavy_PhaseRing::cBinop_OPshUpWm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_NoNr95uN_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_whuH0hKj, m);
}

void Heavy_PhaseRing::cBinop_NoNr95uN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_0bYQByIo, m);
}

void Heavy_PhaseRing::cVar_SqDghORD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_9l3YyNDO_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_umVEEwdc_sendMessage);
}

void Heavy_PhaseRing::cVar_2iZB8TKO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 100.0f, 0, m, &cBinop_y1WD1rXv_sendMessage);
}

void Heavy_PhaseRing::cVar_l6gCb4pB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_W7OwG7sr_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_RQZyFSTO, 0, m, &cIf_RQZyFSTO_sendMessage);
}

void Heavy_PhaseRing::cVar_u4M5Kw45_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 100.0f, 0, m, &cBinop_YgvdDSPV_sendMessage);
}

void Heavy_PhaseRing::cIf_RQZyFSTO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_jhSsI3KR_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cVar_onMessage(_c, &Context(_c)->cVar_8fy6E54J, 0, m, &cVar_8fy6E54J_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_W7OwG7sr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_RQZyFSTO, 1, m, &cIf_RQZyFSTO_sendMessage);
}

void Heavy_PhaseRing::cBinop_YgvdDSPV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_XylS7tsW_sendMessage);
}

void Heavy_PhaseRing::cBinop_XylS7tsW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_t6Cl0HAh, 0, m, &cVar_t6Cl0HAh_sendMessage);
}

void Heavy_PhaseRing::cTabhead_y2zRwp8g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_FbEHPrDi, HV_BINOP_SUBTRACT, 0, m, &cBinop_FbEHPrDi_sendMessage);
}

void Heavy_PhaseRing::cMsg_FbRXpCBn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_YvkAvQXw_sendMessage);
}

void Heavy_PhaseRing::cSystem_YvkAvQXw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_9KrJz9NW_sendMessage);
}

void Heavy_PhaseRing::cVar_ainKTSfH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_mCuMh0YO_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cDelay_h5bbSav9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_h5bbSav9, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_IbcwKoGK, 0, m, &cDelay_IbcwKoGK_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_bAhyqN7O, 0, m, &sTabread_bAhyqN7O_sendMessage);
}

void Heavy_PhaseRing::cDelay_IbcwKoGK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_IbcwKoGK, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_bAhyqN7O, 0, m, &sTabread_bAhyqN7O_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_IbcwKoGK, 0, m, &cDelay_IbcwKoGK_sendMessage);
}

void Heavy_PhaseRing::sTabread_bAhyqN7O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_TM0ILdUR, HV_BINOP_SUBTRACT, 0, m, &cBinop_TM0ILdUR_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_ZO5msVAn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_pj3Ad1r0, HV_BINOP_MAX, 0, m, &cBinop_pj3Ad1r0_sendMessage);
}

void Heavy_PhaseRing::cBinop_9KrJz9NW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ZO5msVAn, HV_BINOP_MULTIPLY, 0, m, &cBinop_ZO5msVAn_sendMessage);
}

void Heavy_PhaseRing::cBinop_FbEHPrDi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Bxd3tROe_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_bAhyqN7O, 0, m, &sTabread_bAhyqN7O_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_aHmEkjtL_sendMessage);
}

void Heavy_PhaseRing::cSystem_iqgC5GT1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_TM0ILdUR, HV_BINOP_SUBTRACT, 1, m, &cBinop_TM0ILdUR_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_IbcwKoGK, 2, m, &cDelay_IbcwKoGK_sendMessage);
}

void Heavy_PhaseRing::cMsg_mCuMh0YO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_iqgC5GT1_sendMessage);
}

void Heavy_PhaseRing::cMsg_Bxd3tROe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_h5bbSav9, 0, m, &cDelay_h5bbSav9_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_IbcwKoGK, 0, m, &cDelay_IbcwKoGK_sendMessage);
}

void Heavy_PhaseRing::cMsg_1PFVB6sf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_pj3Ad1r0, HV_BINOP_MAX, 1, m, &cBinop_pj3Ad1r0_sendMessage);
}

void Heavy_PhaseRing::cBinop_pj3Ad1r0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_FbEHPrDi, HV_BINOP_SUBTRACT, 1, m, &cBinop_FbEHPrDi_sendMessage);
}

void Heavy_PhaseRing::cCast_aHmEkjtL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_h5bbSav9, 0, m, &cDelay_h5bbSav9_sendMessage);
}

void Heavy_PhaseRing::cBinop_7qNs9T73_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_h5bbSav9, 2, m, &cDelay_h5bbSav9_sendMessage);
}

void Heavy_PhaseRing::cBinop_TM0ILdUR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_7qNs9T73_sendMessage);
}

void Heavy_PhaseRing::cCast_TH5gTZ5g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ainKTSfH, 0, m, &cVar_ainKTSfH_sendMessage);
  cMsg_FbRXpCBn_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_y2zRwp8g, 0, m, &cTabhead_y2zRwp8g_sendMessage);
}

void Heavy_PhaseRing::cMsg_7l1k6ESF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_YAKL6O2q_sendMessage);
}

void Heavy_PhaseRing::cSystem_YAKL6O2q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_tFDZvQEM_sendMessage);
}

void Heavy_PhaseRing::cDelay_6DGg2TUX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_6DGg2TUX, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_WWZTc3kF, 0, m, &cDelay_WWZTc3kF_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_6DGg2TUX, 0, m, &cDelay_6DGg2TUX_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_j404L5Zw, 1, m, NULL);
}

void Heavy_PhaseRing::cDelay_WWZTc3kF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_WWZTc3kF, m);
  cMsg_FuOjfA38_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_uf1PMeWC_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_LE4OOQFe_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_8ln7a8tU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_nzEsAnR4_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::hTable_YVZi9ELj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_xNkRcRs4_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_6DGg2TUX, 2, m, &cDelay_6DGg2TUX_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_SYWSI67w_sendMessage);
}

void Heavy_PhaseRing::cMsg_nzEsAnR4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_YVZi9ELj, 0, m, &hTable_YVZi9ELj_sendMessage);
}

void Heavy_PhaseRing::cBinop_tFDZvQEM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 13.645f, 0, m, &cBinop_8ln7a8tU_sendMessage);
}

void Heavy_PhaseRing::cMsg_FuOjfA38_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_YVZi9ELj, 0, m, &hTable_YVZi9ELj_sendMessage);
}

void Heavy_PhaseRing::cCast_SYWSI67w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_6DGg2TUX, 0, m, &cDelay_6DGg2TUX_sendMessage);
}

void Heavy_PhaseRing::cMsg_xNkRcRs4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_WWZTc3kF, 2, m, &cDelay_WWZTc3kF_sendMessage);
}

void Heavy_PhaseRing::cMsg_LE4OOQFe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_j404L5Zw, 1, m, NULL);
}

void Heavy_PhaseRing::cTabhead_bWdTlbUx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_AuUsiIhB, HV_BINOP_SUBTRACT, 0, m, &cBinop_AuUsiIhB_sendMessage);
}

void Heavy_PhaseRing::cMsg_jq55np6a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_mGF0eg0n_sendMessage);
}

void Heavy_PhaseRing::cSystem_mGF0eg0n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_YPSjXbq3_sendMessage);
}

void Heavy_PhaseRing::cVar_VSRAw14X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_tCIQKVS5_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cDelay_A2OUM1SP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_A2OUM1SP, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_8Vzol3Gu, 0, m, &cDelay_8Vzol3Gu_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_uCY5INTW, 0, m, &sTabread_uCY5INTW_sendMessage);
}

void Heavy_PhaseRing::cDelay_8Vzol3Gu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_8Vzol3Gu, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_uCY5INTW, 0, m, &sTabread_uCY5INTW_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_8Vzol3Gu, 0, m, &cDelay_8Vzol3Gu_sendMessage);
}

void Heavy_PhaseRing::sTabread_uCY5INTW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_7UegN5Fv, HV_BINOP_SUBTRACT, 0, m, &cBinop_7UegN5Fv_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_lye2Iy7j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_oIQvI664, HV_BINOP_MAX, 0, m, &cBinop_oIQvI664_sendMessage);
}

void Heavy_PhaseRing::cBinop_YPSjXbq3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_lye2Iy7j, HV_BINOP_MULTIPLY, 0, m, &cBinop_lye2Iy7j_sendMessage);
}

void Heavy_PhaseRing::cBinop_AuUsiIhB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_uthm3ntk_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_uCY5INTW, 0, m, &sTabread_uCY5INTW_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_6xFMvqqZ_sendMessage);
}

void Heavy_PhaseRing::cSystem_sQeTuzJW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_7UegN5Fv, HV_BINOP_SUBTRACT, 1, m, &cBinop_7UegN5Fv_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_8Vzol3Gu, 2, m, &cDelay_8Vzol3Gu_sendMessage);
}

void Heavy_PhaseRing::cMsg_tCIQKVS5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_sQeTuzJW_sendMessage);
}

void Heavy_PhaseRing::cMsg_uthm3ntk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_A2OUM1SP, 0, m, &cDelay_A2OUM1SP_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_8Vzol3Gu, 0, m, &cDelay_8Vzol3Gu_sendMessage);
}

void Heavy_PhaseRing::cMsg_0dvKkeC5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_oIQvI664, HV_BINOP_MAX, 1, m, &cBinop_oIQvI664_sendMessage);
}

void Heavy_PhaseRing::cBinop_oIQvI664_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_AuUsiIhB, HV_BINOP_SUBTRACT, 1, m, &cBinop_AuUsiIhB_sendMessage);
}

void Heavy_PhaseRing::cCast_6xFMvqqZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_A2OUM1SP, 0, m, &cDelay_A2OUM1SP_sendMessage);
}

void Heavy_PhaseRing::cBinop_BBA30ONP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_A2OUM1SP, 2, m, &cDelay_A2OUM1SP_sendMessage);
}

void Heavy_PhaseRing::cBinop_7UegN5Fv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_BBA30ONP_sendMessage);
}

void Heavy_PhaseRing::cCast_jKRCL5e4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_VSRAw14X, 0, m, &cVar_VSRAw14X_sendMessage);
  cMsg_jq55np6a_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_bWdTlbUx, 0, m, &cTabhead_bWdTlbUx_sendMessage);
}

void Heavy_PhaseRing::cMsg_umhDlmvg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_YlNNthk7_sendMessage);
}

void Heavy_PhaseRing::cSystem_YlNNthk7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_sJcXaQIL_sendMessage);
}

void Heavy_PhaseRing::cDelay_2X0wazg8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_2X0wazg8, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_HGfm0ZFZ, 0, m, &cDelay_HGfm0ZFZ_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_2X0wazg8, 0, m, &cDelay_2X0wazg8_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_xFHFKq7r, 1, m, NULL);
}

void Heavy_PhaseRing::cDelay_HGfm0ZFZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_HGfm0ZFZ, m);
  cMsg_GgiTO1A2_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_mcDvnJDg_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_5hi15Nei_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_afsRjsrg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_7dOV1rJs_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::hTable_AD9rNiKP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Fc4nzQ1Z_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_2X0wazg8, 2, m, &cDelay_2X0wazg8_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_kMoUdzqt_sendMessage);
}

void Heavy_PhaseRing::cMsg_7dOV1rJs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_AD9rNiKP, 0, m, &hTable_AD9rNiKP_sendMessage);
}

void Heavy_PhaseRing::cBinop_sJcXaQIL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 16.364f, 0, m, &cBinop_afsRjsrg_sendMessage);
}

void Heavy_PhaseRing::cMsg_GgiTO1A2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_AD9rNiKP, 0, m, &hTable_AD9rNiKP_sendMessage);
}

void Heavy_PhaseRing::cCast_kMoUdzqt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_2X0wazg8, 0, m, &cDelay_2X0wazg8_sendMessage);
}

void Heavy_PhaseRing::cMsg_Fc4nzQ1Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_HGfm0ZFZ, 2, m, &cDelay_HGfm0ZFZ_sendMessage);
}

void Heavy_PhaseRing::cMsg_5hi15Nei_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_xFHFKq7r, 1, m, NULL);
}

void Heavy_PhaseRing::cTabhead_UZcQgShe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_U8yZPEND, HV_BINOP_SUBTRACT, 0, m, &cBinop_U8yZPEND_sendMessage);
}

void Heavy_PhaseRing::cMsg_eNn1DDOz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_D4R8Vggg_sendMessage);
}

void Heavy_PhaseRing::cSystem_D4R8Vggg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_e72mDZeY_sendMessage);
}

void Heavy_PhaseRing::cVar_4GEfLeRi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_kk2BZFWM_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cDelay_J1AOdxMX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_J1AOdxMX, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Aolthp52, 0, m, &cDelay_Aolthp52_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_Lp3ejuyW, 0, m, &sTabread_Lp3ejuyW_sendMessage);
}

void Heavy_PhaseRing::cDelay_Aolthp52_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Aolthp52, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_Lp3ejuyW, 0, m, &sTabread_Lp3ejuyW_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Aolthp52, 0, m, &cDelay_Aolthp52_sendMessage);
}

void Heavy_PhaseRing::sTabread_Lp3ejuyW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_HVsSnsj0, HV_BINOP_SUBTRACT, 0, m, &cBinop_HVsSnsj0_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_M9N5hzie_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_7w31au2A, HV_BINOP_MAX, 0, m, &cBinop_7w31au2A_sendMessage);
}

void Heavy_PhaseRing::cBinop_e72mDZeY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_M9N5hzie, HV_BINOP_MULTIPLY, 0, m, &cBinop_M9N5hzie_sendMessage);
}

void Heavy_PhaseRing::cBinop_U8yZPEND_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_xlnQnLZz_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_Lp3ejuyW, 0, m, &sTabread_Lp3ejuyW_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_zyMZOigo_sendMessage);
}

void Heavy_PhaseRing::cSystem_XfgE2Vpr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_HVsSnsj0, HV_BINOP_SUBTRACT, 1, m, &cBinop_HVsSnsj0_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Aolthp52, 2, m, &cDelay_Aolthp52_sendMessage);
}

void Heavy_PhaseRing::cMsg_kk2BZFWM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_XfgE2Vpr_sendMessage);
}

void Heavy_PhaseRing::cMsg_xlnQnLZz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_J1AOdxMX, 0, m, &cDelay_J1AOdxMX_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Aolthp52, 0, m, &cDelay_Aolthp52_sendMessage);
}

void Heavy_PhaseRing::cMsg_aMOfB8ql_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_7w31au2A, HV_BINOP_MAX, 1, m, &cBinop_7w31au2A_sendMessage);
}

void Heavy_PhaseRing::cBinop_7w31au2A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_U8yZPEND, HV_BINOP_SUBTRACT, 1, m, &cBinop_U8yZPEND_sendMessage);
}

void Heavy_PhaseRing::cCast_zyMZOigo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_J1AOdxMX, 0, m, &cDelay_J1AOdxMX_sendMessage);
}

void Heavy_PhaseRing::cBinop_0HIHDVpm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_J1AOdxMX, 2, m, &cDelay_J1AOdxMX_sendMessage);
}

void Heavy_PhaseRing::cBinop_HVsSnsj0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_0HIHDVpm_sendMessage);
}

void Heavy_PhaseRing::cCast_bf1p1Ao4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_4GEfLeRi, 0, m, &cVar_4GEfLeRi_sendMessage);
  cMsg_eNn1DDOz_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_UZcQgShe, 0, m, &cTabhead_UZcQgShe_sendMessage);
}

void Heavy_PhaseRing::cMsg_w12cHGAo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_H6Njb6gv_sendMessage);
}

void Heavy_PhaseRing::cSystem_H6Njb6gv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_DfvvoxSf_sendMessage);
}

void Heavy_PhaseRing::cDelay_1Db0KMuv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_1Db0KMuv, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_C6OeSu87, 0, m, &cDelay_C6OeSu87_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_1Db0KMuv, 0, m, &cDelay_1Db0KMuv_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_QySLbTzx, 1, m, NULL);
}

void Heavy_PhaseRing::cDelay_C6OeSu87_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_C6OeSu87, m);
  cMsg_GTuYkj1a_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_dUk9KpsV_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_degcgzmp_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_YeTZlxY6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_fvqnbqIn_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::hTable_uvayZRpY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_RPADG25i_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_1Db0KMuv, 2, m, &cDelay_1Db0KMuv_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_drDQMPKG_sendMessage);
}

void Heavy_PhaseRing::cMsg_fvqnbqIn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_uvayZRpY, 0, m, &hTable_uvayZRpY_sendMessage);
}

void Heavy_PhaseRing::cBinop_DfvvoxSf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 19.392f, 0, m, &cBinop_YeTZlxY6_sendMessage);
}

void Heavy_PhaseRing::cMsg_GTuYkj1a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_uvayZRpY, 0, m, &hTable_uvayZRpY_sendMessage);
}

void Heavy_PhaseRing::cCast_drDQMPKG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_1Db0KMuv, 0, m, &cDelay_1Db0KMuv_sendMessage);
}

void Heavy_PhaseRing::cMsg_RPADG25i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_C6OeSu87, 2, m, &cDelay_C6OeSu87_sendMessage);
}

void Heavy_PhaseRing::cMsg_degcgzmp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_QySLbTzx, 1, m, NULL);
}

void Heavy_PhaseRing::cTabhead_wf2et4NE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_DuGJGnlZ, HV_BINOP_SUBTRACT, 0, m, &cBinop_DuGJGnlZ_sendMessage);
}

void Heavy_PhaseRing::cMsg_3nNJ1LnE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_S0GIVXgC_sendMessage);
}

void Heavy_PhaseRing::cSystem_S0GIVXgC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_dMnOCjQF_sendMessage);
}

void Heavy_PhaseRing::cVar_InMgz6dl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_jezFEwIX_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cDelay_7YBPLB8I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_7YBPLB8I, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_pOhN26LU, 0, m, &cDelay_pOhN26LU_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_VGfjzqHs, 0, m, &sTabread_VGfjzqHs_sendMessage);
}

void Heavy_PhaseRing::cDelay_pOhN26LU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_pOhN26LU, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_VGfjzqHs, 0, m, &sTabread_VGfjzqHs_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_pOhN26LU, 0, m, &cDelay_pOhN26LU_sendMessage);
}

void Heavy_PhaseRing::sTabread_VGfjzqHs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_XUhn444L, HV_BINOP_SUBTRACT, 0, m, &cBinop_XUhn444L_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_ao8hGc9g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_A0B3JkLQ, HV_BINOP_MAX, 0, m, &cBinop_A0B3JkLQ_sendMessage);
}

void Heavy_PhaseRing::cBinop_dMnOCjQF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ao8hGc9g, HV_BINOP_MULTIPLY, 0, m, &cBinop_ao8hGc9g_sendMessage);
}

void Heavy_PhaseRing::cBinop_DuGJGnlZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_laXTlrij_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_VGfjzqHs, 0, m, &sTabread_VGfjzqHs_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_04KHkFOu_sendMessage);
}

void Heavy_PhaseRing::cSystem_oR5iIEbh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_XUhn444L, HV_BINOP_SUBTRACT, 1, m, &cBinop_XUhn444L_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_pOhN26LU, 2, m, &cDelay_pOhN26LU_sendMessage);
}

void Heavy_PhaseRing::cMsg_jezFEwIX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_oR5iIEbh_sendMessage);
}

void Heavy_PhaseRing::cMsg_laXTlrij_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_7YBPLB8I, 0, m, &cDelay_7YBPLB8I_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_pOhN26LU, 0, m, &cDelay_pOhN26LU_sendMessage);
}

void Heavy_PhaseRing::cMsg_q8l4LAOd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_A0B3JkLQ, HV_BINOP_MAX, 1, m, &cBinop_A0B3JkLQ_sendMessage);
}

void Heavy_PhaseRing::cBinop_A0B3JkLQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_DuGJGnlZ, HV_BINOP_SUBTRACT, 1, m, &cBinop_DuGJGnlZ_sendMessage);
}

void Heavy_PhaseRing::cCast_04KHkFOu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_7YBPLB8I, 0, m, &cDelay_7YBPLB8I_sendMessage);
}

void Heavy_PhaseRing::cBinop_BRdD5b2s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_7YBPLB8I, 2, m, &cDelay_7YBPLB8I_sendMessage);
}

void Heavy_PhaseRing::cBinop_XUhn444L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_BRdD5b2s_sendMessage);
}

void Heavy_PhaseRing::cCast_MOxZ7cMQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_InMgz6dl, 0, m, &cVar_InMgz6dl_sendMessage);
  cMsg_3nNJ1LnE_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_wf2et4NE, 0, m, &cTabhead_wf2et4NE_sendMessage);
}

void Heavy_PhaseRing::cMsg_1ZF7J6Ho_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_AfKlM54W_sendMessage);
}

void Heavy_PhaseRing::cSystem_AfKlM54W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_Pd8LR9TA_sendMessage);
}

void Heavy_PhaseRing::cDelay_BsGIM45O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_BsGIM45O, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_0V3YErs2, 0, m, &cDelay_0V3YErs2_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_BsGIM45O, 0, m, &cDelay_BsGIM45O_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_2mSse9h2, 1, m, NULL);
}

void Heavy_PhaseRing::cDelay_0V3YErs2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_0V3YErs2, m);
  cMsg_tJ2sh8PO_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_n1JeTUvd_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_OgveTf8x_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_J6uUArhP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_eo33O8iD_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::hTable_RMwcv6FY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_XVLX4kif_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_BsGIM45O, 2, m, &cDelay_BsGIM45O_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_YE9DshGo_sendMessage);
}

void Heavy_PhaseRing::cMsg_eo33O8iD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_RMwcv6FY, 0, m, &hTable_RMwcv6FY_sendMessage);
}

void Heavy_PhaseRing::cBinop_Pd8LR9TA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 25.796f, 0, m, &cBinop_J6uUArhP_sendMessage);
}

void Heavy_PhaseRing::cMsg_tJ2sh8PO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_RMwcv6FY, 0, m, &hTable_RMwcv6FY_sendMessage);
}

void Heavy_PhaseRing::cCast_YE9DshGo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_BsGIM45O, 0, m, &cDelay_BsGIM45O_sendMessage);
}

void Heavy_PhaseRing::cMsg_XVLX4kif_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_0V3YErs2, 2, m, &cDelay_0V3YErs2_sendMessage);
}

void Heavy_PhaseRing::cMsg_OgveTf8x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_2mSse9h2, 1, m, NULL);
}

void Heavy_PhaseRing::cTabhead_Cwy4JVJP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_eaChx4rh, HV_BINOP_SUBTRACT, 0, m, &cBinop_eaChx4rh_sendMessage);
}

void Heavy_PhaseRing::cMsg_Ut7Tlvxh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_c17JzByw_sendMessage);
}

void Heavy_PhaseRing::cSystem_c17JzByw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_ZD2FSCYh_sendMessage);
}

void Heavy_PhaseRing::cVar_5NOlhK1a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_z8071baz_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cDelay_tKy8pBhI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_tKy8pBhI, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Fh1Dk3UE, 0, m, &cDelay_Fh1Dk3UE_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_8foYB517, 0, m, &sTabread_8foYB517_sendMessage);
}

void Heavy_PhaseRing::cDelay_Fh1Dk3UE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Fh1Dk3UE, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_8foYB517, 0, m, &sTabread_8foYB517_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Fh1Dk3UE, 0, m, &cDelay_Fh1Dk3UE_sendMessage);
}

void Heavy_PhaseRing::sTabread_8foYB517_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_CYWOT8En, HV_BINOP_SUBTRACT, 0, m, &cBinop_CYWOT8En_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_jrubf91n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_XhZf4iv0, HV_BINOP_MAX, 0, m, &cBinop_XhZf4iv0_sendMessage);
}

void Heavy_PhaseRing::cBinop_ZD2FSCYh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_jrubf91n, HV_BINOP_MULTIPLY, 0, m, &cBinop_jrubf91n_sendMessage);
}

void Heavy_PhaseRing::cBinop_eaChx4rh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_l7oNlRHI_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_8foYB517, 0, m, &sTabread_8foYB517_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_HHFqWDem_sendMessage);
}

void Heavy_PhaseRing::cSystem_ELYrfbqX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_CYWOT8En, HV_BINOP_SUBTRACT, 1, m, &cBinop_CYWOT8En_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Fh1Dk3UE, 2, m, &cDelay_Fh1Dk3UE_sendMessage);
}

void Heavy_PhaseRing::cMsg_z8071baz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ELYrfbqX_sendMessage);
}

void Heavy_PhaseRing::cMsg_l7oNlRHI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_tKy8pBhI, 0, m, &cDelay_tKy8pBhI_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Fh1Dk3UE, 0, m, &cDelay_Fh1Dk3UE_sendMessage);
}

void Heavy_PhaseRing::cMsg_pNEGaJdY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_XhZf4iv0, HV_BINOP_MAX, 1, m, &cBinop_XhZf4iv0_sendMessage);
}

void Heavy_PhaseRing::cBinop_XhZf4iv0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_eaChx4rh, HV_BINOP_SUBTRACT, 1, m, &cBinop_eaChx4rh_sendMessage);
}

void Heavy_PhaseRing::cCast_HHFqWDem_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_tKy8pBhI, 0, m, &cDelay_tKy8pBhI_sendMessage);
}

void Heavy_PhaseRing::cBinop_Ve2fvjuk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_tKy8pBhI, 2, m, &cDelay_tKy8pBhI_sendMessage);
}

void Heavy_PhaseRing::cBinop_CYWOT8En_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_Ve2fvjuk_sendMessage);
}

void Heavy_PhaseRing::cCast_kQNvNeNg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_5NOlhK1a, 0, m, &cVar_5NOlhK1a_sendMessage);
  cMsg_Ut7Tlvxh_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_Cwy4JVJP, 0, m, &cTabhead_Cwy4JVJP_sendMessage);
}

void Heavy_PhaseRing::cMsg_LMKr9yU2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_bIvjiEIz_sendMessage);
}

void Heavy_PhaseRing::cSystem_bIvjiEIz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_r5IduTMS_sendMessage);
}

void Heavy_PhaseRing::cDelay_Dd5JMAZu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Dd5JMAZu, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_MZ4rwCXU, 0, m, &cDelay_MZ4rwCXU_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Dd5JMAZu, 0, m, &cDelay_Dd5JMAZu_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_odX501h4, 1, m, NULL);
}

void Heavy_PhaseRing::cDelay_MZ4rwCXU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_MZ4rwCXU, m);
  cMsg_xcN3jWR7_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_Kw6jZ642_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_2YNcZGmx_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_HD4YVthA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_kPbn9HPn_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::hTable_owKST7i5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_RtSEHJne_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Dd5JMAZu, 2, m, &cDelay_Dd5JMAZu_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_P5gLzneE_sendMessage);
}

void Heavy_PhaseRing::cMsg_kPbn9HPn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_owKST7i5, 0, m, &hTable_owKST7i5_sendMessage);
}

void Heavy_PhaseRing::cBinop_r5IduTMS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 43.5337f, 0, m, &cBinop_HD4YVthA_sendMessage);
}

void Heavy_PhaseRing::cMsg_xcN3jWR7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_owKST7i5, 0, m, &hTable_owKST7i5_sendMessage);
}

void Heavy_PhaseRing::cCast_P5gLzneE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Dd5JMAZu, 0, m, &cDelay_Dd5JMAZu_sendMessage);
}

void Heavy_PhaseRing::cMsg_RtSEHJne_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_MZ4rwCXU, 2, m, &cDelay_MZ4rwCXU_sendMessage);
}

void Heavy_PhaseRing::cMsg_2YNcZGmx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_odX501h4, 1, m, NULL);
}

void Heavy_PhaseRing::cTabhead_Od7cPgu2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_w0KFQ6Lp, HV_BINOP_SUBTRACT, 0, m, &cBinop_w0KFQ6Lp_sendMessage);
}

void Heavy_PhaseRing::cMsg_zIRL8FL6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_i0BjB3YB_sendMessage);
}

void Heavy_PhaseRing::cSystem_i0BjB3YB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_S9yn8gju_sendMessage);
}

void Heavy_PhaseRing::cVar_aJKqne9N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ZMm3IXDw_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cDelay_UNB7vev9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_UNB7vev9, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_n46sK5N4, 0, m, &cDelay_n46sK5N4_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_Qh0CG6EU, 0, m, &sTabread_Qh0CG6EU_sendMessage);
}

void Heavy_PhaseRing::cDelay_n46sK5N4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_n46sK5N4, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_Qh0CG6EU, 0, m, &sTabread_Qh0CG6EU_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_n46sK5N4, 0, m, &cDelay_n46sK5N4_sendMessage);
}

void Heavy_PhaseRing::sTabread_Qh0CG6EU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_gHZDZOtv, HV_BINOP_SUBTRACT, 0, m, &cBinop_gHZDZOtv_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_dOE2bvnS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_D74lFvSo, HV_BINOP_MAX, 0, m, &cBinop_D74lFvSo_sendMessage);
}

void Heavy_PhaseRing::cBinop_S9yn8gju_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_dOE2bvnS, HV_BINOP_MULTIPLY, 0, m, &cBinop_dOE2bvnS_sendMessage);
}

void Heavy_PhaseRing::cBinop_w0KFQ6Lp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_0D8BGrqu_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_Qh0CG6EU, 0, m, &sTabread_Qh0CG6EU_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_TCJPSxJm_sendMessage);
}

void Heavy_PhaseRing::cSystem_kC5abOsg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_gHZDZOtv, HV_BINOP_SUBTRACT, 1, m, &cBinop_gHZDZOtv_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_n46sK5N4, 2, m, &cDelay_n46sK5N4_sendMessage);
}

void Heavy_PhaseRing::cMsg_ZMm3IXDw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_kC5abOsg_sendMessage);
}

void Heavy_PhaseRing::cMsg_0D8BGrqu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_UNB7vev9, 0, m, &cDelay_UNB7vev9_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_n46sK5N4, 0, m, &cDelay_n46sK5N4_sendMessage);
}

void Heavy_PhaseRing::cMsg_lnr2VvNg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_D74lFvSo, HV_BINOP_MAX, 1, m, &cBinop_D74lFvSo_sendMessage);
}

void Heavy_PhaseRing::cBinop_D74lFvSo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_w0KFQ6Lp, HV_BINOP_SUBTRACT, 1, m, &cBinop_w0KFQ6Lp_sendMessage);
}

void Heavy_PhaseRing::cCast_TCJPSxJm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_UNB7vev9, 0, m, &cDelay_UNB7vev9_sendMessage);
}

void Heavy_PhaseRing::cBinop_mb5wN6H2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_UNB7vev9, 2, m, &cDelay_UNB7vev9_sendMessage);
}

void Heavy_PhaseRing::cBinop_gHZDZOtv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_mb5wN6H2_sendMessage);
}

void Heavy_PhaseRing::cCast_w2qSrXcV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_aJKqne9N, 0, m, &cVar_aJKqne9N_sendMessage);
  cMsg_zIRL8FL6_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_Od7cPgu2, 0, m, &cTabhead_Od7cPgu2_sendMessage);
}

void Heavy_PhaseRing::cMsg_5uSuEj6w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_8hKWNIUR_sendMessage);
}

void Heavy_PhaseRing::cSystem_8hKWNIUR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_qM0XxzHi_sendMessage);
}

void Heavy_PhaseRing::cDelay_22pNTNpF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_22pNTNpF, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_PB4j3p2n, 0, m, &cDelay_PB4j3p2n_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_22pNTNpF, 0, m, &cDelay_22pNTNpF_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_wRRsYXfs, 1, m, NULL);
}

void Heavy_PhaseRing::cDelay_PB4j3p2n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_PB4j3p2n, m);
  cMsg_QvJGmTJV_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_4EICjvV2_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_NZi2rgoc_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_r9nNFP7B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_jonOiEpd_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::hTable_T2zZRC6o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_z4NJHAOj_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_22pNTNpF, 2, m, &cDelay_22pNTNpF_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_wspdEKn8_sendMessage);
}

void Heavy_PhaseRing::cMsg_jonOiEpd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_T2zZRC6o, 0, m, &hTable_T2zZRC6o_sendMessage);
}

void Heavy_PhaseRing::cBinop_qM0XxzHi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 75.2546f, 0, m, &cBinop_r9nNFP7B_sendMessage);
}

void Heavy_PhaseRing::cMsg_QvJGmTJV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_T2zZRC6o, 0, m, &hTable_T2zZRC6o_sendMessage);
}

void Heavy_PhaseRing::cCast_wspdEKn8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_22pNTNpF, 0, m, &cDelay_22pNTNpF_sendMessage);
}

void Heavy_PhaseRing::cMsg_z4NJHAOj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_PB4j3p2n, 2, m, &cDelay_PB4j3p2n_sendMessage);
}

void Heavy_PhaseRing::cMsg_NZi2rgoc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_wRRsYXfs, 1, m, NULL);
}

void Heavy_PhaseRing::cVar_8fy6E54J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_FZGTin4Z, 0, m, &cVar_FZGTin4Z_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_3bYVVJ2t, 0, m, &cVar_3bYVVJ2t_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_uz1WtjY3, 0, m, &cVar_uz1WtjY3_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_9Mk4b4EK, 0, m, &cVar_9Mk4b4EK_sendMessage);
}

void Heavy_PhaseRing::cVar_t6Cl0HAh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.01f, 0, m, &cBinop_rUUP1Idx_sendMessage);
}

void Heavy_PhaseRing::cPack_EgR18v6D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_eI1d28fs, 0, m, NULL);
}

void Heavy_PhaseRing::cVar_3bYVVJ2t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_W1T4CFMc, HV_BINOP_MULTIPLY, 0, m, &cBinop_W1T4CFMc_sendMessage);
}

void Heavy_PhaseRing::cMsg_Os06LL27_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Cy0XVNXa_sendMessage);
}

void Heavy_PhaseRing::cSystem_Cy0XVNXa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_FE6BdfBw_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_W1T4CFMc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_8BNnfVis_sendMessage);
}

void Heavy_PhaseRing::cBinop_GnecEoOo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_W1T4CFMc, HV_BINOP_MULTIPLY, 1, m, &cBinop_W1T4CFMc_sendMessage);
}

void Heavy_PhaseRing::cMsg_FE6BdfBw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_GnecEoOo_sendMessage);
}

void Heavy_PhaseRing::cBinop_8BNnfVis_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_6JSYQr6A_sendMessage);
}

void Heavy_PhaseRing::cBinop_6JSYQr6A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_0tge04W1_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_7PLCXbqK, m);
}

void Heavy_PhaseRing::cBinop_0tge04W1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_K2FA8eor, m);
}

void Heavy_PhaseRing::cVar_uz1WtjY3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_76a43th3, HV_BINOP_MULTIPLY, 0, m, &cBinop_76a43th3_sendMessage);
}

void Heavy_PhaseRing::cMsg_tD6ARp3q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Fh7wAuIV_sendMessage);
}

void Heavy_PhaseRing::cSystem_Fh7wAuIV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_XXfzQeMq_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_76a43th3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_9cHzZGhL_sendMessage);
}

void Heavy_PhaseRing::cBinop_p9oY0eet_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_76a43th3, HV_BINOP_MULTIPLY, 1, m, &cBinop_76a43th3_sendMessage);
}

void Heavy_PhaseRing::cMsg_XXfzQeMq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_p9oY0eet_sendMessage);
}

void Heavy_PhaseRing::cBinop_9cHzZGhL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_BUn0Mlhn_sendMessage);
}

void Heavy_PhaseRing::cBinop_BUn0Mlhn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_8b9pwFlP_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_ePqZtHSi, m);
}

void Heavy_PhaseRing::cBinop_8b9pwFlP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_ho69Xjjz, m);
}

void Heavy_PhaseRing::cVar_9Mk4b4EK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Vqt2M4zZ, HV_BINOP_MULTIPLY, 0, m, &cBinop_Vqt2M4zZ_sendMessage);
}

void Heavy_PhaseRing::cMsg_i5W2rULe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_f45R6PtM_sendMessage);
}

void Heavy_PhaseRing::cSystem_f45R6PtM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_DOTgb5zn_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_Vqt2M4zZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_WB3gXSvj_sendMessage);
}

void Heavy_PhaseRing::cBinop_Fh8Ddjaj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Vqt2M4zZ, HV_BINOP_MULTIPLY, 1, m, &cBinop_Vqt2M4zZ_sendMessage);
}

void Heavy_PhaseRing::cMsg_DOTgb5zn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_Fh8Ddjaj_sendMessage);
}

void Heavy_PhaseRing::cBinop_WB3gXSvj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_zEmr6eyi_sendMessage);
}

void Heavy_PhaseRing::cBinop_zEmr6eyi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_tUrf67Lx_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_2TOgOlRb, m);
}

void Heavy_PhaseRing::cBinop_tUrf67Lx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_UxXwpOiT, m);
}

void Heavy_PhaseRing::cBinop_2phWpGZM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_QAEz3vyM, 0, m, &cPack_QAEz3vyM_sendMessage);
}

void Heavy_PhaseRing::cMsg_jhSsI3KR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 3000.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_8fy6E54J, 0, m, &cVar_8fy6E54J_sendMessage);
}

void Heavy_PhaseRing::cBinop_rUUP1Idx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_EgR18v6D, 0, m, &cPack_EgR18v6D_sendMessage);
}

void Heavy_PhaseRing::cBinop_zkclMXzD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_b2GzXqjm, 0, m, &cPack_b2GzXqjm_sendMessage);
}

void Heavy_PhaseRing::cMsg_fA69qNCc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_7hMVf28v_sendMessage);
}

void Heavy_PhaseRing::cSystem_7hMVf28v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_9nNWKyOi_sendMessage);
}

void Heavy_PhaseRing::cVar_9wAZSxKR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_2Okd8k9B_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSystem_1jGIO7Qv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_gBi0IXLu_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_xuk4n1dP, m);
}

void Heavy_PhaseRing::cBinop_9nNWKyOi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_kDiruckg, m);
}

void Heavy_PhaseRing::cMsg_2Okd8k9B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_1jGIO7Qv_sendMessage);
}

void Heavy_PhaseRing::cBinop_gBi0IXLu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_HwFWfFNM, m);
}

void Heavy_PhaseRing::cVar_D9G8DfNz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_AsMYOJl7, HV_BINOP_MULTIPLY, 0, m, &cBinop_AsMYOJl7_sendMessage);
}

void Heavy_PhaseRing::cMsg_dG5pWqJN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_XSdxtEcP_sendMessage);
}

void Heavy_PhaseRing::cSystem_XSdxtEcP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_wi0fL4lb_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_AsMYOJl7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_0RPkpEza_sendMessage);
}

void Heavy_PhaseRing::cBinop_S0DBsZ0D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_AsMYOJl7, HV_BINOP_MULTIPLY, 1, m, &cBinop_AsMYOJl7_sendMessage);
}

void Heavy_PhaseRing::cMsg_wi0fL4lb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_S0DBsZ0D_sendMessage);
}

void Heavy_PhaseRing::cBinop_0RPkpEza_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_mkOUqRg9_sendMessage);
}

void Heavy_PhaseRing::cBinop_mkOUqRg9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_8Zkqx99n_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_GwYXgCuK, m);
}

void Heavy_PhaseRing::cBinop_8Zkqx99n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_qeoDPrmj, m);
}

void Heavy_PhaseRing::cBinop_zCUQJUCd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, -1.0f, 0, m, &cBinop_5O6naNpF_sendMessage);
}

void Heavy_PhaseRing::cBinop_5O6naNpF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_pCBZ9CxV, m);
}

void Heavy_PhaseRing::cBinop_F6tWo38P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_FAU02R59_sendMessage);
}

void Heavy_PhaseRing::cBinop_FAU02R59_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_1WIjYv41_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_bUxuUGKL_sendMessage);
}

void Heavy_PhaseRing::cVar_x5XmyhZz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_NJOrfAlZ_sendMessage);
}

void Heavy_PhaseRing::cMsg_3AMtolcL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_CxJUitL3_sendMessage);
}

void Heavy_PhaseRing::cSystem_CxJUitL3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_o2t5G1qo, HV_BINOP_DIVIDE, 1, m, &cBinop_o2t5G1qo_sendMessage);
}

void Heavy_PhaseRing::cBinop_1WIjYv41_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_qo9wX9Uy_sendMessage);
}

void Heavy_PhaseRing::cBinop_qo9wX9Uy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_BrQsobmA, m);
}

void Heavy_PhaseRing::cMsg_eN6n4F1x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_rKwa4dWI_sendMessage);
}

void Heavy_PhaseRing::cBinop_rKwa4dWI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_F6tWo38P_sendMessage);
}

void Heavy_PhaseRing::cBinop_bUxuUGKL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_6aYJjZ2P, m);
}

void Heavy_PhaseRing::cBinop_NJOrfAlZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_ATUNFFJL_sendMessage);
}

void Heavy_PhaseRing::cBinop_ATUNFFJL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_o2t5G1qo, HV_BINOP_DIVIDE, 0, m, &cBinop_o2t5G1qo_sendMessage);
}

void Heavy_PhaseRing::cBinop_o2t5G1qo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_eN6n4F1x_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cVar_rdWGkaCI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Cj3n8I9n_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_NOlhxJJf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_TsUJClbW_sendMessage);
}

void Heavy_PhaseRing::cSystem_TsUJClbW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_blVdqbVe_sendMessage);
}

void Heavy_PhaseRing::cDelay_UzXc5got_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_UzXc5got, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ijCAOWZo, 0, m, &cDelay_ijCAOWZo_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_UzXc5got, 0, m, &cDelay_UzXc5got_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_RYeAX991, 1, m, NULL);
}

void Heavy_PhaseRing::cDelay_ijCAOWZo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_ijCAOWZo, m);
  cMsg_BqpvSB0B_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_dKxweU5n_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_fXdrJVWY_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_EdTuLisC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_3Of6u9ft_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::hTable_x6GDlK7A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_pt4QxV81_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_UzXc5got, 2, m, &cDelay_UzXc5got_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_iZ31hyfk_sendMessage);
}

void Heavy_PhaseRing::cMsg_3Of6u9ft_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_x6GDlK7A, 0, m, &hTable_x6GDlK7A_sendMessage);
}

void Heavy_PhaseRing::cBinop_blVdqbVe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 500.0f, 0, m, &cBinop_EdTuLisC_sendMessage);
}

void Heavy_PhaseRing::cMsg_BqpvSB0B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_x6GDlK7A, 0, m, &hTable_x6GDlK7A_sendMessage);
}

void Heavy_PhaseRing::cCast_iZ31hyfk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_UzXc5got, 0, m, &cDelay_UzXc5got_sendMessage);
}

void Heavy_PhaseRing::cMsg_pt4QxV81_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_ijCAOWZo, 2, m, &cDelay_ijCAOWZo_sendMessage);
}

void Heavy_PhaseRing::cMsg_fXdrJVWY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_RYeAX991, 1, m, NULL);
}

void Heavy_PhaseRing::cMsg_b72HuPth_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cMsg_Cj3n8I9n_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_Cj3n8I9n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 20.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_Op6ntHhI, 0, m, NULL);
}

void Heavy_PhaseRing::cPack_2Mtgs0Xo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_lHcwtND4, 0, m, NULL);
}

void Heavy_PhaseRing::cCast_I58hh5V1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_2Mtgs0Xo, 0, m, &cPack_2Mtgs0Xo_sendMessage);
}

void Heavy_PhaseRing::cCast_9EFjEJA7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_4bVBwCEP_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cMsg_MPDfbrjk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 500.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_lHcwtND4, 0, m, NULL);
}

void Heavy_PhaseRing::cMsg_IRsShFXg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 500.0f);
  sVarf_onMessage(_c, &Context(_c)->sVarf_LIVUU1FQ, m);
}

void Heavy_PhaseRing::cMsg_VV1wwgUp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.3f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_zCUQJUCd_sendMessage);
}

void Heavy_PhaseRing::cSwitchcase_8pVPJfkl_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_Y9eOFBcP, 0, m, &cSlice_Y9eOFBcP_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_MvWnBiOI, 0, m, &cRandom_MvWnBiOI_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_mozyyRcn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_VyMR8lK6_sendMessage);
}

void Heavy_PhaseRing::cUnop_VyMR8lK6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 10.0f, 0, m, &cBinop_ONHo7qtg_sendMessage);
}

void Heavy_PhaseRing::cRandom_MvWnBiOI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 80.0f, 0, m, &cBinop_mozyyRcn_sendMessage);
}

void Heavy_PhaseRing::cSlice_Y9eOFBcP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_MvWnBiOI, 1, m, &cRandom_MvWnBiOI_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cSwitchcase_0XkX1LV2_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_649hqpev, 0, m, &cSlice_649hqpev_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_t03jILK6, 0, m, &cRandom_t03jILK6_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_dYbH6Zjn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_wQ0XO7N7_sendMessage);
}

void Heavy_PhaseRing::cUnop_wQ0XO7N7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_SnSqMnRc, 0, m, &cPack_SnSqMnRc_sendMessage);
}

void Heavy_PhaseRing::cRandom_t03jILK6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 200.0f, 0, m, &cBinop_dYbH6Zjn_sendMessage);
}

void Heavy_PhaseRing::cSlice_649hqpev_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_t03jILK6, 1, m, &cRandom_t03jILK6_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cVar_paHj86ia_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_jbHl3zZV_sendMessage);
}

void Heavy_PhaseRing::cPack_EIhy5NBR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_36dYtuzu, 0, m, NULL);
}

void Heavy_PhaseRing::cUnop_84fPzdoV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_7EjDuyj7_sendMessage);
}

void Heavy_PhaseRing::cBinop_hf18LEMq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_EXP, m, &cUnop_84fPzdoV_sendMessage);
}

void Heavy_PhaseRing::cPack_LRlh0V4F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_mQEdlnwW, 0, m, NULL);
}

void Heavy_PhaseRing::cVar_cFZ09Ivb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.5f, 0, m, &cBinop_swcP7ilw_sendMessage);
}

void Heavy_PhaseRing::cMsg_4RhTq7bE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_87VLxhlP_sendMessage);
}

void Heavy_PhaseRing::cSystem_87VLxhlP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_A9F60Kn2_sendMessage);
}

void Heavy_PhaseRing::cDelay_tMemUujr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_tMemUujr, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_0vixRJlU, 0, m, &cDelay_0vixRJlU_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_tMemUujr, 0, m, &cDelay_tMemUujr_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_coE7euhU, 1, m, NULL);
}

void Heavy_PhaseRing::cDelay_0vixRJlU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_0vixRJlU, m);
  cMsg_WJR3sQ7s_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_rlgSlBNA_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_XAYTM4bY_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_uANzA6mr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_CgJ89sCQ_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::hTable_17BVN5Ee_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_rhMFrxEi_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_tMemUujr, 2, m, &cDelay_tMemUujr_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_pF9nzSQd_sendMessage);
}

void Heavy_PhaseRing::cMsg_CgJ89sCQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_17BVN5Ee, 0, m, &hTable_17BVN5Ee_sendMessage);
}

void Heavy_PhaseRing::cBinop_A9F60Kn2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 5000.0f, 0, m, &cBinop_uANzA6mr_sendMessage);
}

void Heavy_PhaseRing::cMsg_WJR3sQ7s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_17BVN5Ee, 0, m, &hTable_17BVN5Ee_sendMessage);
}

void Heavy_PhaseRing::cCast_pF9nzSQd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_tMemUujr, 0, m, &cDelay_tMemUujr_sendMessage);
}

void Heavy_PhaseRing::cMsg_rhMFrxEi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_0vixRJlU, 2, m, &cDelay_0vixRJlU_sendMessage);
}

void Heavy_PhaseRing::cMsg_XAYTM4bY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_coE7euhU, 1, m, NULL);
}

void Heavy_PhaseRing::cMsg_uvTtembw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_0DHjZdv8_sendMessage);
}

void Heavy_PhaseRing::cSystem_0DHjZdv8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_q2xO0R5l_sendMessage);
}

void Heavy_PhaseRing::cVar_Dn4DoP5Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_KdkX8KxT_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSystem_lCyQrNkp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_zXawaiGq_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_Oln9UMIu, m);
}

void Heavy_PhaseRing::cBinop_q2xO0R5l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_G6b7jUQ2, m);
}

void Heavy_PhaseRing::cMsg_KdkX8KxT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_lCyQrNkp_sendMessage);
}

void Heavy_PhaseRing::cBinop_zXawaiGq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_t46iamp4, m);
}

void Heavy_PhaseRing::cMsg_sdEMNG7s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_zSeLgXn8_sendMessage);
}

void Heavy_PhaseRing::cSystem_zSeLgXn8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_JVRhCLRj_sendMessage);
}

void Heavy_PhaseRing::cVar_909CY1Yr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_AfMtrGsN_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSystem_fIusSDDy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_Gvk96SBp_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_GCrHknxZ, m);
}

void Heavy_PhaseRing::cBinop_JVRhCLRj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_zmtDYAVK, m);
}

void Heavy_PhaseRing::cMsg_AfMtrGsN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_fIusSDDy_sendMessage);
}

void Heavy_PhaseRing::cBinop_Gvk96SBp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_NLQvdtS2, m);
}

void Heavy_PhaseRing::cBinop_NIUwvhU3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_fxFaLb3O_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_zbCvQ64h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_SsmN6oPB_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_qqKp3hVz_sendMessage);
}

void Heavy_PhaseRing::cCast_qqKp3hVz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_NIUwvhU3, HV_BINOP_DIVIDE, 0, m, &cBinop_NIUwvhU3_sendMessage);
}

void Heavy_PhaseRing::cCast_SsmN6oPB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_NIUwvhU3, HV_BINOP_DIVIDE, 1, m, &cBinop_NIUwvhU3_sendMessage);
}

void Heavy_PhaseRing::cBinop_7EjDuyj7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_0wrlFXEm_sendMessage);
}

void Heavy_PhaseRing::cBinop_OMMGed91_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 87.3365f, 0, m, &cBinop_hf18LEMq_sendMessage);
}

void Heavy_PhaseRing::cBinop_0wrlFXEm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_NIUwvhU3, HV_BINOP_DIVIDE, 0, m, &cBinop_NIUwvhU3_sendMessage);
}

void Heavy_PhaseRing::cBinop_swcP7ilw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_LRlh0V4F, 0, m, &cPack_LRlh0V4F_sendMessage);
}

void Heavy_PhaseRing::cBinop_jbHl3zZV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.001f, 0, m, &cBinop_zbCvQ64h_sendMessage);
  cPack_onMessage(_c, &Context(_c)->cPack_EIhy5NBR, 0, m, &cPack_EIhy5NBR_sendMessage);
}

void Heavy_PhaseRing::cMsg_2EsKc4pi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 100.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_paHj86ia, 0, m, &cVar_paHj86ia_sendMessage);
}

void Heavy_PhaseRing::cMsg_hulCPwoa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.5f);
  cVar_onMessage(_c, &Context(_c)->cVar_cFZ09Ivb, 0, m, &cVar_cFZ09Ivb_sendMessage);
}

void Heavy_PhaseRing::cMsg_fxFaLb3O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 30.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_YcekOZL7, 0, m, NULL);
}

void Heavy_PhaseRing::cMsg_s0MZ56ay_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_KIcXjUFa_sendMessage);
}

void Heavy_PhaseRing::cSystem_KIcXjUFa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_79y8o8Kh_sendMessage);
}

void Heavy_PhaseRing::cVar_ZV0iPES5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_7IBy7FAM_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSystem_3F452Ewl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_TltrDwCU_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_r3Ua9Jir, m);
}

void Heavy_PhaseRing::cBinop_79y8o8Kh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_25RKwJ8C, m);
}

void Heavy_PhaseRing::cMsg_7IBy7FAM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_3F452Ewl_sendMessage);
}

void Heavy_PhaseRing::cBinop_TltrDwCU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_1drvCDm3, m);
}

void Heavy_PhaseRing::cVar_WZnOZDqG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_vrc48qBY, HV_BINOP_MULTIPLY, 0, m, &cBinop_vrc48qBY_sendMessage);
}

void Heavy_PhaseRing::cMsg_y7hYwbmY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Xr2LWNkl_sendMessage);
}

void Heavy_PhaseRing::cSystem_Xr2LWNkl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_KNNZuZvT_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_vrc48qBY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_34gK5xcG_sendMessage);
}

void Heavy_PhaseRing::cBinop_kpvzbVRT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_vrc48qBY, HV_BINOP_MULTIPLY, 1, m, &cBinop_vrc48qBY_sendMessage);
}

void Heavy_PhaseRing::cMsg_KNNZuZvT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_kpvzbVRT_sendMessage);
}

void Heavy_PhaseRing::cBinop_34gK5xcG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_Kc6KWUVD_sendMessage);
}

void Heavy_PhaseRing::cBinop_Kc6KWUVD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_oTPFtzEK_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_SyniOFL9, m);
}

void Heavy_PhaseRing::cBinop_oTPFtzEK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_uMa0hI9E, m);
}

void Heavy_PhaseRing::cBinop_ZeSVb9wm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, -1.0f, 0, m, &cBinop_rjnqKVQa_sendMessage);
}

void Heavy_PhaseRing::cBinop_rjnqKVQa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_XWVtQp3n, m);
}

void Heavy_PhaseRing::cBinop_Otrm07ld_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_wVjj9JMr_sendMessage);
}

void Heavy_PhaseRing::cBinop_wVjj9JMr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_XqyOXGKJ_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_tSWlcBSk_sendMessage);
}

void Heavy_PhaseRing::cVar_XaqVHJDX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_bc7iy3Mn_sendMessage);
}

void Heavy_PhaseRing::cMsg_oBcYT3Kc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_MGeHhRcK_sendMessage);
}

void Heavy_PhaseRing::cSystem_MGeHhRcK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_cqLyuUE0, HV_BINOP_DIVIDE, 1, m, &cBinop_cqLyuUE0_sendMessage);
}

void Heavy_PhaseRing::cBinop_XqyOXGKJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_DfnvuUWx_sendMessage);
}

void Heavy_PhaseRing::cBinop_DfnvuUWx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_l5HTGxd2, m);
}

void Heavy_PhaseRing::cMsg_Uo56ss49_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_XaKFzSdv_sendMessage);
}

void Heavy_PhaseRing::cBinop_XaKFzSdv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_Otrm07ld_sendMessage);
}

void Heavy_PhaseRing::cBinop_tSWlcBSk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_mLl7yrEg, m);
}

void Heavy_PhaseRing::cBinop_bc7iy3Mn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_MGhcCQoq_sendMessage);
}

void Heavy_PhaseRing::cBinop_MGhcCQoq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_cqLyuUE0, HV_BINOP_DIVIDE, 0, m, &cBinop_cqLyuUE0_sendMessage);
}

void Heavy_PhaseRing::cBinop_cqLyuUE0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Uo56ss49_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cVar_N8g4fied_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_clD7X4qi_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_k7ai2Rly_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_85nkCsGC_sendMessage);
}

void Heavy_PhaseRing::cSystem_85nkCsGC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_UoB2RBmq_sendMessage);
}

void Heavy_PhaseRing::cDelay_G3LcqFii_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_G3LcqFii, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_8q5z4DsZ, 0, m, &cDelay_8q5z4DsZ_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_G3LcqFii, 0, m, &cDelay_G3LcqFii_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_uXBoxlN4, 1, m, NULL);
}

void Heavy_PhaseRing::cDelay_8q5z4DsZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_8q5z4DsZ, m);
  cMsg_tks47yDI_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSwitchcase_CsdiTlol_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_zQ41tsKp_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cBinop_ZZy75XUq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_NE2yNHkJ_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::hTable_BnH9zZ2A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_YBADUO1o_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_G3LcqFii, 2, m, &cDelay_G3LcqFii_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_KUqOAoYf_sendMessage);
}

void Heavy_PhaseRing::cMsg_NE2yNHkJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_BnH9zZ2A, 0, m, &hTable_BnH9zZ2A_sendMessage);
}

void Heavy_PhaseRing::cBinop_UoB2RBmq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 200.0f, 0, m, &cBinop_ZZy75XUq_sendMessage);
}

void Heavy_PhaseRing::cMsg_tks47yDI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_BnH9zZ2A, 0, m, &hTable_BnH9zZ2A_sendMessage);
}

void Heavy_PhaseRing::cCast_KUqOAoYf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_G3LcqFii, 0, m, &cDelay_G3LcqFii_sendMessage);
}

void Heavy_PhaseRing::cMsg_YBADUO1o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_8q5z4DsZ, 2, m, &cDelay_8q5z4DsZ_sendMessage);
}

void Heavy_PhaseRing::cMsg_zQ41tsKp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_uXBoxlN4, 1, m, NULL);
}

void Heavy_PhaseRing::cMsg_qQhIeoPK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cMsg_clD7X4qi_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_clD7X4qi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 20.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_HvrvnWCE, 0, m, NULL);
}

void Heavy_PhaseRing::cVar_U4GHQjgq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cMsg_dqjuQOA4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_fp9tOprY_sendMessage);
}

void Heavy_PhaseRing::cSystem_fp9tOprY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_R4NGT6nx, HV_BINOP_MULTIPLY, 1, m, &cBinop_R4NGT6nx_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_vTgUKyC9, HV_BINOP_MULTIPLY, 1, m, &cBinop_vTgUKyC9_sendMessage);
}

void Heavy_PhaseRing::cSwitchcase_G2UStf2f_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cMsg_wyxfMaX4_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_wyxfMaX4_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_LIUMjkA3_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cDelay_8Wlo2hIf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_8Wlo2hIf, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_8Wlo2hIf, 0, m, &cDelay_8Wlo2hIf_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_qPTOxsmZ, 0, m, &cVar_qPTOxsmZ_sendMessage);
}

void Heavy_PhaseRing::cCast_LIUMjkA3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_wyxfMaX4_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_8Wlo2hIf, 0, m, &cDelay_8Wlo2hIf_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_qPTOxsmZ, 0, m, &cVar_qPTOxsmZ_sendMessage);
}

void Heavy_PhaseRing::cMsg_uYPZIHNE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_6EGJgsQH_sendMessage);
}

void Heavy_PhaseRing::cSystem_6EGJgsQH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_9KlRQZZb_sendMessage);
}

void Heavy_PhaseRing::cVar_vxawBnJw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_qNgGpLV3, HV_BINOP_MULTIPLY, 0, m, &cBinop_qNgGpLV3_sendMessage);
}

void Heavy_PhaseRing::cMsg_wyxfMaX4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_8Wlo2hIf, 0, m, &cDelay_8Wlo2hIf_sendMessage);
}

void Heavy_PhaseRing::cBinop_XeMKmnKC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_8Wlo2hIf, 2, m, &cDelay_8Wlo2hIf_sendMessage);
}

void Heavy_PhaseRing::cBinop_9KlRQZZb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_qNgGpLV3, HV_BINOP_MULTIPLY, 1, m, &cBinop_qNgGpLV3_sendMessage);
}

void Heavy_PhaseRing::cBinop_qNgGpLV3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_XeMKmnKC_sendMessage);
}

void Heavy_PhaseRing::cVar_qPTOxsmZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_AX6w4yy3, HV_BINOP_SUBTRACT, 0, m, &cBinop_AX6w4yy3_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_LESS_THAN_EQL, 0.0f, 0, m, &cBinop_JGUoNusW_sendMessage);
}

void Heavy_PhaseRing::cSwitchcase_8FelHEBn_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_T3KxjSvo_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_YzpOa7su_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cCast_T3KxjSvo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_eyZZ3pZL, 0, m, &cVar_eyZZ3pZL_sendMessage);
}

void Heavy_PhaseRing::cCast_YzpOa7su_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_f9xAGol4_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ndtoOZdy_sendMessage);
}

void Heavy_PhaseRing::cSwitchcase_sCVVVJ9o_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cSlice_onMessage(_c, &Context(_c)->cSlice_9R6m0LYg, 0, m, &cSlice_9R6m0LYg_sendMessage);
      break;
    }
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_k0Gii2wf, 0, m, &cSlice_k0Gii2wf_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_7uDGn6wg_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_bTUCbMqb, 0, m, &cSlice_bTUCbMqb_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_4pwYQI55, 0, m, &cSlice_4pwYQI55_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_s9z4iG5z_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_InsdxMtS_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cSlice_9R6m0LYg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_ir7tBwxd_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_ir7tBwxd_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cSlice_k0Gii2wf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_zz7tKLi4_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_nVA2Retm_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_zz7tKLi4_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_nVA2Retm_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cVar_dd7wFzLY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_6F7aG31r_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_tpOS8E8n_sendMessage);
}

void Heavy_PhaseRing::cVar_dt67yyR2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_qpVLCDZU_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cSwitchcase_qpVLCDZU_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Lny5wWwT_sendMessage);
      break;
    }
    default: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_R4NGT6nx, HV_BINOP_MULTIPLY, 0, m, &cBinop_R4NGT6nx_sendMessage);
      cBinop_onMessage(_c, &Context(_c)->cBinop_PgyAnDzC, HV_BINOP_DIVIDE, 1, m, &cBinop_PgyAnDzC_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_vxawBnJw, 0, m, &cVar_vxawBnJw_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cCast_Lny5wWwT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_SQugGZt7_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cVar_B6xNNFYD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MOBCWmjY, HV_BINOP_SUBTRACT, 1, m, &cBinop_MOBCWmjY_sendMessage);
}

void Heavy_PhaseRing::cVar_uSbT8saN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_eyZZ3pZL, 0, m, &cVar_eyZZ3pZL_sendMessage);
}

void Heavy_PhaseRing::cVar_eyZZ3pZL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_486P2IMR, HV_BINOP_ADD, 0, m, &cBinop_486P2IMR_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_RqFhT3p9, HV_BINOP_ADD, 0, m, &cBinop_RqFhT3p9_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_DnG6BMa0, 0, m, &cVar_DnG6BMa0_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.05776f, 0, m, &cBinop_OMMGed91_sendMessage);
}

void Heavy_PhaseRing::cSlice_bTUCbMqb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_6F7aG31r_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_tpOS8E8n_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cSlice_4pwYQI55_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_zMfoAygf_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_AjcPV2H2_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_KW1uZm5e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_qPTOxsmZ, 1, m, &cVar_qPTOxsmZ_sendMessage);
}

void Heavy_PhaseRing::cBinop_vTgUKyC9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_KW1uZm5e_sendMessage);
}

void Heavy_PhaseRing::cBinop_R4NGT6nx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_x2cTlHTw_sendMessage);
}

void Heavy_PhaseRing::cBinop_x2cTlHTw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_AX6w4yy3, HV_BINOP_SUBTRACT, 1, m, &cBinop_AX6w4yy3_sendMessage);
}

void Heavy_PhaseRing::cBinop_AX6w4yy3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_qPTOxsmZ, 1, m, &cVar_qPTOxsmZ_sendMessage);
}

void Heavy_PhaseRing::cMsg_F4kp0L4g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_G2UStf2f_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cMsg_dttepi3V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_G2UStf2f_onMessage(_c, NULL, 0, m, NULL);
  cBinop_onMessage(_c, &Context(_c)->cBinop_RqFhT3p9, HV_BINOP_ADD, 1, m, &cBinop_RqFhT3p9_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_486P2IMR, HV_BINOP_ADD, 1, m, &cBinop_486P2IMR_sendMessage);
}

void Heavy_PhaseRing::cBinop_JGUoNusW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_8FelHEBn_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cBinop_486P2IMR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_eyZZ3pZL, 1, m, &cVar_eyZZ3pZL_sendMessage);
}

void Heavy_PhaseRing::cBinop_PgyAnDzC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_SIiZcn4u, HV_BINOP_DIVIDE, 1, m, &cBinop_SIiZcn4u_sendMessage);
}

void Heavy_PhaseRing::cBinop_SIiZcn4u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_RqFhT3p9, HV_BINOP_ADD, 1, m, &cBinop_RqFhT3p9_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_486P2IMR, HV_BINOP_ADD, 1, m, &cBinop_486P2IMR_sendMessage);
}

void Heavy_PhaseRing::cCast_6F7aG31r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_vTgUKyC9, HV_BINOP_MULTIPLY, 0, m, &cBinop_vTgUKyC9_sendMessage);
}

void Heavy_PhaseRing::cCast_tpOS8E8n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_PgyAnDzC, HV_BINOP_DIVIDE, 0, m, &cBinop_PgyAnDzC_sendMessage);
}

void Heavy_PhaseRing::cCast_zMfoAygf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_uSbT8saN, 1, m, &cVar_uSbT8saN_sendMessage);
}

void Heavy_PhaseRing::cCast_AjcPV2H2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MOBCWmjY, HV_BINOP_SUBTRACT, 0, m, &cBinop_MOBCWmjY_sendMessage);
}

void Heavy_PhaseRing::cCast_ndtoOZdy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_uSbT8saN, 0, m, &cVar_uSbT8saN_sendMessage);
}

void Heavy_PhaseRing::cCast_f9xAGol4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_dttepi3V_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_RqFhT3p9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_B6xNNFYD, 0, m, &cVar_B6xNNFYD_sendMessage);
}

void Heavy_PhaseRing::cMsg_ir7tBwxd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_G2UStf2f_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cMsg_kNyZcKOT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_dd7wFzLY, 1, m, &cVar_dd7wFzLY_sendMessage);
}

void Heavy_PhaseRing::cMsg_SQugGZt7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 20.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_R4NGT6nx, HV_BINOP_MULTIPLY, 0, m, &cBinop_R4NGT6nx_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_PgyAnDzC, HV_BINOP_DIVIDE, 1, m, &cBinop_PgyAnDzC_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_vxawBnJw, 0, m, &cVar_vxawBnJw_sendMessage);
}

void Heavy_PhaseRing::cCast_zz7tKLi4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ir7tBwxd_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cCast_nVA2Retm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_wWVwQ92w_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_RqFhT3p9, HV_BINOP_ADD, 0, m, &cBinop_RqFhT3p9_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_eyZZ3pZL, 1, m, &cVar_eyZZ3pZL_sendMessage);
}

void Heavy_PhaseRing::cBinop_MOBCWmjY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_SIiZcn4u, HV_BINOP_DIVIDE, 0, m, &cBinop_SIiZcn4u_sendMessage);
}

void Heavy_PhaseRing::cCast_wWVwQ92w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_dttepi3V_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cCast_7uDGn6wg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_dd7wFzLY, 0, m, &cVar_dd7wFzLY_sendMessage);
}

void Heavy_PhaseRing::cCast_InsdxMtS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_kNyZcKOT_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cCast_s9z4iG5z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_F4kp0L4g_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cVar_DnG6BMa0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cMsg_PbgNkEp7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_bRNk7rMv_sendMessage);
}

void Heavy_PhaseRing::cSystem_bRNk7rMv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_s6zK2fFd, HV_BINOP_MULTIPLY, 1, m, &cBinop_s6zK2fFd_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_m1QqeOKy, HV_BINOP_MULTIPLY, 1, m, &cBinop_m1QqeOKy_sendMessage);
}

void Heavy_PhaseRing::cSwitchcase_pdaZf2PE_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cMsg_mJZb5AnS_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_mJZb5AnS_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_4WoTR73H_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cDelay_qCMO8teq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_qCMO8teq, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_qCMO8teq, 0, m, &cDelay_qCMO8teq_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_xyeFHQY7, 0, m, &cVar_xyeFHQY7_sendMessage);
}

void Heavy_PhaseRing::cCast_4WoTR73H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_mJZb5AnS_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_qCMO8teq, 0, m, &cDelay_qCMO8teq_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_xyeFHQY7, 0, m, &cVar_xyeFHQY7_sendMessage);
}

void Heavy_PhaseRing::cMsg_IhhfgJIs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_IywUrNKJ_sendMessage);
}

void Heavy_PhaseRing::cSystem_IywUrNKJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_1DTEd6DS_sendMessage);
}

void Heavy_PhaseRing::cVar_LimWL3jb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_zRwzOYgR, HV_BINOP_MULTIPLY, 0, m, &cBinop_zRwzOYgR_sendMessage);
}

void Heavy_PhaseRing::cMsg_mJZb5AnS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_qCMO8teq, 0, m, &cDelay_qCMO8teq_sendMessage);
}

void Heavy_PhaseRing::cBinop_3nTgul8H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_qCMO8teq, 2, m, &cDelay_qCMO8teq_sendMessage);
}

void Heavy_PhaseRing::cBinop_1DTEd6DS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_zRwzOYgR, HV_BINOP_MULTIPLY, 1, m, &cBinop_zRwzOYgR_sendMessage);
}

void Heavy_PhaseRing::cBinop_zRwzOYgR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_3nTgul8H_sendMessage);
}

void Heavy_PhaseRing::cVar_xyeFHQY7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_PDFGHtzS, HV_BINOP_SUBTRACT, 0, m, &cBinop_PDFGHtzS_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_LESS_THAN_EQL, 0.0f, 0, m, &cBinop_2rqDGpp5_sendMessage);
}

void Heavy_PhaseRing::cSwitchcase_OSOlowfP_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_kBO4MmdX_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_onFuNcVh_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cCast_kBO4MmdX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_dRjtgjRd, 0, m, &cVar_dRjtgjRd_sendMessage);
}

void Heavy_PhaseRing::cCast_onFuNcVh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_sxDEOCHP_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Y5PGrCgO_sendMessage);
}

void Heavy_PhaseRing::cSwitchcase_WfrtAK5F_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cSlice_onMessage(_c, &Context(_c)->cSlice_MJ0G22IW, 0, m, &cSlice_MJ0G22IW_sendMessage);
      break;
    }
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_PB3shP67, 0, m, &cSlice_PB3shP67_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_56bASkyq_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_XIRJg9Qg, 0, m, &cSlice_XIRJg9Qg_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_gAmIWIq9, 0, m, &cSlice_gAmIWIq9_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_5PmFQLjX_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_rEdR4WIv_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cSlice_MJ0G22IW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_81xgk6lt_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_81xgk6lt_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cSlice_PB3shP67_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_bUE9WXGQ_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_dK2bMgNG_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_bUE9WXGQ_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_dK2bMgNG_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cVar_nu6fPq21_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_khqgPUhW_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_BZWy02po_sendMessage);
}

void Heavy_PhaseRing::cVar_OQOud2rS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_HiWBk8kM_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cSwitchcase_HiWBk8kM_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_REec0Xmk_sendMessage);
      break;
    }
    default: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_s6zK2fFd, HV_BINOP_MULTIPLY, 0, m, &cBinop_s6zK2fFd_sendMessage);
      cBinop_onMessage(_c, &Context(_c)->cBinop_lpzxIi27, HV_BINOP_DIVIDE, 1, m, &cBinop_lpzxIi27_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_LimWL3jb, 0, m, &cVar_LimWL3jb_sendMessage);
      break;
    }
  }
}

void Heavy_PhaseRing::cCast_REec0Xmk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_eeEB8404_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cVar_nLwfxbG4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_3gQkZXdH, HV_BINOP_SUBTRACT, 1, m, &cBinop_3gQkZXdH_sendMessage);
}

void Heavy_PhaseRing::cVar_119JiQ1X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_dRjtgjRd, 0, m, &cVar_dRjtgjRd_sendMessage);
}

void Heavy_PhaseRing::cVar_dRjtgjRd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_WpkBxPvw, HV_BINOP_ADD, 0, m, &cBinop_WpkBxPvw_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_KSqJgAZ3, HV_BINOP_ADD, 0, m, &cBinop_KSqJgAZ3_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_U4GHQjgq, 0, m, &cVar_U4GHQjgq_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_wLskBSGz, m);
}

void Heavy_PhaseRing::cSlice_XIRJg9Qg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_khqgPUhW_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_BZWy02po_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cSlice_gAmIWIq9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_wzQ8vP6S_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_dy7MHV4s_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cBinop_4G3lfGmw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_xyeFHQY7, 1, m, &cVar_xyeFHQY7_sendMessage);
}

void Heavy_PhaseRing::cBinop_m1QqeOKy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_4G3lfGmw_sendMessage);
}

void Heavy_PhaseRing::cBinop_s6zK2fFd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_AGvK1XWj_sendMessage);
}

void Heavy_PhaseRing::cBinop_AGvK1XWj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_PDFGHtzS, HV_BINOP_SUBTRACT, 1, m, &cBinop_PDFGHtzS_sendMessage);
}

void Heavy_PhaseRing::cBinop_PDFGHtzS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_xyeFHQY7, 1, m, &cVar_xyeFHQY7_sendMessage);
}

void Heavy_PhaseRing::cMsg_mMuYJL0d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_pdaZf2PE_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cMsg_KP8a6AmV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_pdaZf2PE_onMessage(_c, NULL, 0, m, NULL);
  cBinop_onMessage(_c, &Context(_c)->cBinop_KSqJgAZ3, HV_BINOP_ADD, 1, m, &cBinop_KSqJgAZ3_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_WpkBxPvw, HV_BINOP_ADD, 1, m, &cBinop_WpkBxPvw_sendMessage);
}

void Heavy_PhaseRing::cBinop_2rqDGpp5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_OSOlowfP_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cBinop_WpkBxPvw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_dRjtgjRd, 1, m, &cVar_dRjtgjRd_sendMessage);
}

void Heavy_PhaseRing::cBinop_lpzxIi27_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_gb7Apdkq, HV_BINOP_DIVIDE, 1, m, &cBinop_gb7Apdkq_sendMessage);
}

void Heavy_PhaseRing::cBinop_gb7Apdkq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_KSqJgAZ3, HV_BINOP_ADD, 1, m, &cBinop_KSqJgAZ3_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_WpkBxPvw, HV_BINOP_ADD, 1, m, &cBinop_WpkBxPvw_sendMessage);
}

void Heavy_PhaseRing::cCast_BZWy02po_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_lpzxIi27, HV_BINOP_DIVIDE, 0, m, &cBinop_lpzxIi27_sendMessage);
}

void Heavy_PhaseRing::cCast_khqgPUhW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_m1QqeOKy, HV_BINOP_MULTIPLY, 0, m, &cBinop_m1QqeOKy_sendMessage);
}

void Heavy_PhaseRing::cCast_dy7MHV4s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_3gQkZXdH, HV_BINOP_SUBTRACT, 0, m, &cBinop_3gQkZXdH_sendMessage);
}

void Heavy_PhaseRing::cCast_wzQ8vP6S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_119JiQ1X, 1, m, &cVar_119JiQ1X_sendMessage);
}

void Heavy_PhaseRing::cCast_Y5PGrCgO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_119JiQ1X, 0, m, &cVar_119JiQ1X_sendMessage);
}

void Heavy_PhaseRing::cCast_sxDEOCHP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_KP8a6AmV_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_KSqJgAZ3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_nLwfxbG4, 0, m, &cVar_nLwfxbG4_sendMessage);
}

void Heavy_PhaseRing::cMsg_81xgk6lt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_pdaZf2PE_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cMsg_rBdxUddS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_nu6fPq21, 1, m, &cVar_nu6fPq21_sendMessage);
}

void Heavy_PhaseRing::cMsg_eeEB8404_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 20.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_s6zK2fFd, HV_BINOP_MULTIPLY, 0, m, &cBinop_s6zK2fFd_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_lpzxIi27, HV_BINOP_DIVIDE, 1, m, &cBinop_lpzxIi27_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_LimWL3jb, 0, m, &cVar_LimWL3jb_sendMessage);
}

void Heavy_PhaseRing::cCast_dK2bMgNG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_gLwtY9Ly_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_KSqJgAZ3, HV_BINOP_ADD, 0, m, &cBinop_KSqJgAZ3_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_dRjtgjRd, 1, m, &cVar_dRjtgjRd_sendMessage);
}

void Heavy_PhaseRing::cCast_bUE9WXGQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_81xgk6lt_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_3gQkZXdH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_gb7Apdkq, HV_BINOP_DIVIDE, 0, m, &cBinop_gb7Apdkq_sendMessage);
}

void Heavy_PhaseRing::cCast_gLwtY9Ly_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_KP8a6AmV_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cCast_5PmFQLjX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_mMuYJL0d_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cCast_rEdR4WIv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_rBdxUddS_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cCast_56bASkyq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_nu6fPq21, 0, m, &cVar_nu6fPq21_sendMessage);
}

void Heavy_PhaseRing::cPack_HSpiA0OO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_m6r8KmmR, 0, m, NULL);
}

void Heavy_PhaseRing::cPack_kXFfnPU1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_sCVVVJ9o_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cPack_SnSqMnRc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_WfrtAK5F_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cBinop_7VSW2c0k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 4.0f, 0, m, &cBinop_rzoyKLa2_sendMessage);
}

void Heavy_PhaseRing::cBinop_rzoyKLa2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_kXFfnPU1, 0, m, &cPack_kXFfnPU1_sendMessage);
}

void Heavy_PhaseRing::cBinop_ONHo7qtg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_7VSW2c0k_sendMessage);
}

void Heavy_PhaseRing::cCast_hOPUKVf0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_8pVPJfkl_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cCast_sG1wr6ON_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_0XkX1LV2_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cMsg_dmm87hDk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.15f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_ZeSVb9wm_sendMessage);
}

void Heavy_PhaseRing::cVar_TuH5b9Yo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_2ioxtSCA_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_UghgvAXH_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_HwuNHsCy_sendMessage);
}

void Heavy_PhaseRing::cIf_c5WljKov_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_v43CKr3P_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_fMGHzOTP_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cMsg_aZcSHuLU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_2wr0Xvf5, HV_BINOP_POW, 0, m, &cBinop_2wr0Xvf5_sendMessage);
}

void Heavy_PhaseRing::cBinop_2wr0Xvf5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_1TzmywYg, 0, m, &cPack_1TzmywYg_sendMessage);
}

void Heavy_PhaseRing::cBinop_sxLA24Nn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_5TEcCo16_sendMessage);
}

void Heavy_PhaseRing::cCast_HwuNHsCy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_c5WljKov, 0, m, &cIf_c5WljKov_sendMessage);
}

void Heavy_PhaseRing::cCast_UghgvAXH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_RCVlFaQb_sendMessage);
}

void Heavy_PhaseRing::cBinop_RCVlFaQb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_c5WljKov, 1, m, &cIf_c5WljKov_sendMessage);
}

void Heavy_PhaseRing::cBinop_fMGHzOTP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_sxLA24Nn_sendMessage);
}

void Heavy_PhaseRing::cMsg_v43CKr3P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_1TzmywYg, 0, m, &cPack_1TzmywYg_sendMessage);
}

void Heavy_PhaseRing::cBinop_5TEcCo16_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_2wr0Xvf5, HV_BINOP_POW, 1, m, &cBinop_2wr0Xvf5_sendMessage);
  cMsg_aZcSHuLU_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cPack_1TzmywYg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_zgmiZzxA, 0, m, NULL);
}

void Heavy_PhaseRing::cVar_ReOXdNEE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_p149E8Do_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_2ioxtSCA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSend_h9RAWtxh_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_h9RAWtxh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_K6kYGOoT_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_p149E8Do_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_EuF8WM5Q_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cVar_g4Bpzf2Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_qZ8PYCnl_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_P5CnOrQ8_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_fEW0vi56_sendMessage);
}

void Heavy_PhaseRing::cIf_oyyjS3Qr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_P5AvmM4S_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_KlT2aZXq_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cMsg_JLKXXJDh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_vMYSiGUC, HV_BINOP_POW, 0, m, &cBinop_vMYSiGUC_sendMessage);
}

void Heavy_PhaseRing::cBinop_vMYSiGUC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_wTe331j2, 0, m, &cPack_wTe331j2_sendMessage);
}

void Heavy_PhaseRing::cBinop_oQSn9GdV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_DaqHsEp2_sendMessage);
}

void Heavy_PhaseRing::cCast_P5CnOrQ8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_lwawarCL_sendMessage);
}

void Heavy_PhaseRing::cCast_fEW0vi56_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_oyyjS3Qr, 0, m, &cIf_oyyjS3Qr_sendMessage);
}

void Heavy_PhaseRing::cBinop_lwawarCL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_oyyjS3Qr, 1, m, &cIf_oyyjS3Qr_sendMessage);
}

void Heavy_PhaseRing::cBinop_KlT2aZXq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_oQSn9GdV_sendMessage);
}

void Heavy_PhaseRing::cMsg_P5AvmM4S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_wTe331j2, 0, m, &cPack_wTe331j2_sendMessage);
}

void Heavy_PhaseRing::cBinop_DaqHsEp2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_vMYSiGUC, HV_BINOP_POW, 1, m, &cBinop_vMYSiGUC_sendMessage);
  cMsg_JLKXXJDh_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cPack_wTe331j2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_KKusIHT9, 0, m, NULL);
}

void Heavy_PhaseRing::cVar_61ONUGQJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_ITksANZM_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_qZ8PYCnl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSend_siUq6lOd_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_siUq6lOd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_RTeaCjQs_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_ITksANZM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_m3j1YjTv_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cIf_k3iId86a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_iJNWtDQq_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_LOG10, m, &cUnop_fOaNUsYH_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cUnop_fOaNUsYH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_rTHrHtdc_sendMessage);
}

void Heavy_PhaseRing::cCast_H0QEDIgm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_QsSgnWLK_sendMessage);
}

void Heavy_PhaseRing::cCast_IlVaSMuQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_k3iId86a, 0, m, &cIf_k3iId86a_sendMessage);
}

void Heavy_PhaseRing::cMsg_iJNWtDQq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cMsg_2ioxtSCA_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_UghgvAXH_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_HwuNHsCy_sendMessage);
}

void Heavy_PhaseRing::cBinop_rTHrHtdc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 100.0f, 0, m, &cBinop_J0HgQfS3_sendMessage);
}

void Heavy_PhaseRing::cBinop_J0HgQfS3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_VcofKHfj_sendMessage);
}

void Heavy_PhaseRing::cBinop_VcofKHfj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_2ioxtSCA_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_UghgvAXH_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_HwuNHsCy_sendMessage);
}

void Heavy_PhaseRing::cBinop_QsSgnWLK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_k3iId86a, 1, m, &cIf_k3iId86a_sendMessage);
}

void Heavy_PhaseRing::cBinop_joKUKaL0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_H0QEDIgm_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_IlVaSMuQ_sendMessage);
}

void Heavy_PhaseRing::cBinop_J0oZ1swG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_joKUKaL0_sendMessage);
}

void Heavy_PhaseRing::cIf_324zeaYn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_KFXUS7tQ_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_LOG10, m, &cUnop_RiAbX1eB_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cUnop_RiAbX1eB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_3ksQqgj8_sendMessage);
}

void Heavy_PhaseRing::cCast_Ogrv1mWk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_324zeaYn, 0, m, &cIf_324zeaYn_sendMessage);
}

void Heavy_PhaseRing::cCast_RDmqqQeI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_On94rhte_sendMessage);
}

void Heavy_PhaseRing::cMsg_KFXUS7tQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cMsg_qZ8PYCnl_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_P5CnOrQ8_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_fEW0vi56_sendMessage);
}

void Heavy_PhaseRing::cBinop_3ksQqgj8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 100.0f, 0, m, &cBinop_ICgX2TU6_sendMessage);
}

void Heavy_PhaseRing::cBinop_ICgX2TU6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_HKtA6KSM_sendMessage);
}

void Heavy_PhaseRing::cBinop_HKtA6KSM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_qZ8PYCnl_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_P5CnOrQ8_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_fEW0vi56_sendMessage);
}

void Heavy_PhaseRing::cBinop_On94rhte_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_324zeaYn, 1, m, &cIf_324zeaYn_sendMessage);
}

void Heavy_PhaseRing::cBinop_iFy1oRMD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_RDmqqQeI_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Ogrv1mWk_sendMessage);
}

void Heavy_PhaseRing::cBinop_VtFCNrAv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_iFy1oRMD_sendMessage);
}

void Heavy_PhaseRing::cVar_qYUDKa91_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_K2AJ07xx_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Xjzf4MN4_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ZBptP23i_sendMessage);
}

void Heavy_PhaseRing::cIf_mAxgEf8c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_IuUZ9I1f_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_xYIZPLpB_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cMsg_UXS0KE7X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_1mn7H34x, HV_BINOP_POW, 0, m, &cBinop_1mn7H34x_sendMessage);
}

void Heavy_PhaseRing::cBinop_1mn7H34x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_6F89ZCCj, 0, m, &cPack_6F89ZCCj_sendMessage);
}

void Heavy_PhaseRing::cBinop_VaWjV4KT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_kIN09P8Y_sendMessage);
}

void Heavy_PhaseRing::cCast_ZBptP23i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_mAxgEf8c, 0, m, &cIf_mAxgEf8c_sendMessage);
}

void Heavy_PhaseRing::cCast_Xjzf4MN4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_4FSnO00Y_sendMessage);
}

void Heavy_PhaseRing::cBinop_4FSnO00Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_mAxgEf8c, 1, m, &cIf_mAxgEf8c_sendMessage);
}

void Heavy_PhaseRing::cBinop_xYIZPLpB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_VaWjV4KT_sendMessage);
}

void Heavy_PhaseRing::cMsg_IuUZ9I1f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_6F89ZCCj, 0, m, &cPack_6F89ZCCj_sendMessage);
}

void Heavy_PhaseRing::cBinop_kIN09P8Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_1mn7H34x, HV_BINOP_POW, 1, m, &cBinop_1mn7H34x_sendMessage);
  cMsg_UXS0KE7X_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cPack_6F89ZCCj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_hDQCHo1p, 0, m, NULL);
}

void Heavy_PhaseRing::cVar_FRWHdrnN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_xbvavIpe_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_K2AJ07xx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSend_aVgMCHkr_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_aVgMCHkr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_Yggd9BMG_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_xbvavIpe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_e5WijMKm_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cVar_JOcjshYM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_YG8wOFE2_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_HdQJmptV_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_mPYIitSz_sendMessage);
}

void Heavy_PhaseRing::cIf_nPSo9AE5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_3gWcbbcZ_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_Ilah4sLH_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cMsg_4mL5qFIN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_whEG4Ig2, HV_BINOP_POW, 0, m, &cBinop_whEG4Ig2_sendMessage);
}

void Heavy_PhaseRing::cBinop_whEG4Ig2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_lg0gCXZA, 0, m, &cPack_lg0gCXZA_sendMessage);
}

void Heavy_PhaseRing::cBinop_1JaLnYe0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_26pxNTA1_sendMessage);
}

void Heavy_PhaseRing::cCast_HdQJmptV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_3FN5lZuG_sendMessage);
}

void Heavy_PhaseRing::cCast_mPYIitSz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_nPSo9AE5, 0, m, &cIf_nPSo9AE5_sendMessage);
}

void Heavy_PhaseRing::cBinop_3FN5lZuG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_nPSo9AE5, 1, m, &cIf_nPSo9AE5_sendMessage);
}

void Heavy_PhaseRing::cBinop_Ilah4sLH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_1JaLnYe0_sendMessage);
}

void Heavy_PhaseRing::cMsg_3gWcbbcZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_lg0gCXZA, 0, m, &cPack_lg0gCXZA_sendMessage);
}

void Heavy_PhaseRing::cBinop_26pxNTA1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_whEG4Ig2, HV_BINOP_POW, 1, m, &cBinop_whEG4Ig2_sendMessage);
  cMsg_4mL5qFIN_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cPack_lg0gCXZA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_1xyjGWfZ, 0, m, NULL);
}

void Heavy_PhaseRing::cVar_6DYfFFgu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_J8VlGYYR_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_YG8wOFE2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSend_MtvoZvCO_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_MtvoZvCO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_FaHapAJH_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_J8VlGYYR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_AH3Jw1fB_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cVar_Eaeu68ou_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_6sgQ3BOp_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_N0iKfc4Z_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_qOYFMPo6_sendMessage);
}

void Heavy_PhaseRing::cIf_NjnWCxGE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_bNRy6SbT_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_aRJxE1Oy_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cMsg_5bn9LJfi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_Wjhvd4cJ, HV_BINOP_POW, 0, m, &cBinop_Wjhvd4cJ_sendMessage);
}

void Heavy_PhaseRing::cBinop_Wjhvd4cJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_NxscTYms, 0, m, &cPack_NxscTYms_sendMessage);
}

void Heavy_PhaseRing::cBinop_ofEeVgiL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_bWIgJjf9_sendMessage);
}

void Heavy_PhaseRing::cCast_qOYFMPo6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_NjnWCxGE, 0, m, &cIf_NjnWCxGE_sendMessage);
}

void Heavy_PhaseRing::cCast_N0iKfc4Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_dlg40Jk5_sendMessage);
}

void Heavy_PhaseRing::cBinop_dlg40Jk5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_NjnWCxGE, 1, m, &cIf_NjnWCxGE_sendMessage);
}

void Heavy_PhaseRing::cBinop_aRJxE1Oy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_ofEeVgiL_sendMessage);
}

void Heavy_PhaseRing::cMsg_bNRy6SbT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_NxscTYms, 0, m, &cPack_NxscTYms_sendMessage);
}

void Heavy_PhaseRing::cBinop_bWIgJjf9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Wjhvd4cJ, HV_BINOP_POW, 1, m, &cBinop_Wjhvd4cJ_sendMessage);
  cMsg_5bn9LJfi_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cPack_NxscTYms_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_9IcO3ryA, 0, m, NULL);
}

void Heavy_PhaseRing::cVar_JUJXUbZL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_WEpWYLYK_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cMsg_6sgQ3BOp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setElementToFrom(m, 1, n, 0);
  cSend_yER0Cpn4_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_yER0Cpn4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_eHDqS1ro_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_WEpWYLYK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_G1ZjrBZW_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cPack_cfKMRaSE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_L8GP2e5D, 0, m, &cIf_L8GP2e5D_sendMessage);
}

void Heavy_PhaseRing::cSlice_3P6ee7E9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_q7RQbaVF_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_F3y1GzKq_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cSlice_vFY2Ab3A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cIf_onMessage(_c, &Context(_c)->cIf_VFcTRfki, 0, m, &cIf_VFcTRfki_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cIf_VFcTRfki_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_1Iea8vT2_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_rxxT7Dom_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cIf_I8GORitp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cPack_onMessage(_c, &Context(_c)->cPack_uiQKWEt8, 2, m, &cPack_uiQKWEt8_sendMessage);
      cPack_onMessage(_c, &Context(_c)->cPack_uug9Nvpe, 1, m, &cPack_uug9Nvpe_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cIf_K7cIEOGf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_3P6ee7E9, 0, m, &cSlice_3P6ee7E9_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_vFY2Ab3A, 0, m, &cSlice_vFY2Ab3A_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cSlice_rBqKbWu5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_KuSYj587_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cSlice_Y4ymYJMJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Q0WPbtJ0_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_GZCvZvC1_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_1M9i0dlp_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cVar_fOqcTO6h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_SZYFN63k, 1, m, &cIf_SZYFN63k_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_keXYevjE_sendMessage);
}

void Heavy_PhaseRing::cIf_SZYFN63k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_3P6ee7E9, 0, m, &cSlice_3P6ee7E9_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_vFY2Ab3A, 0, m, &cSlice_vFY2Ab3A_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cPack_uug9Nvpe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_K7cIEOGf, 0, m, &cIf_K7cIEOGf_sendMessage);
}

void Heavy_PhaseRing::cBinop_qi7RBNRe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_VFcTRfki, 1, m, &cIf_VFcTRfki_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_I8GORitp, 1, m, &cIf_I8GORitp_sendMessage);
}

void Heavy_PhaseRing::cCast_F3y1GzKq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_I8GORitp, 0, m, &cIf_I8GORitp_sendMessage);
}

void Heavy_PhaseRing::cCast_q7RQbaVF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_NEQ, 0.0f, 0, m, &cBinop_qi7RBNRe_sendMessage);
}

void Heavy_PhaseRing::cMsg_wiL71ht1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_fOqcTO6h, 1, m, &cVar_fOqcTO6h_sendMessage);
}

void Heavy_PhaseRing::cMsg_KuSYj587_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_fOqcTO6h, 1, m, &cVar_fOqcTO6h_sendMessage);
}

void Heavy_PhaseRing::cCast_GZCvZvC1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_uug9Nvpe, 0, m, &cPack_uug9Nvpe_sendMessage);
}

void Heavy_PhaseRing::cCast_1M9i0dlp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_wiL71ht1_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cCast_Q0WPbtJ0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_fOqcTO6h, 0, m, &cVar_fOqcTO6h_sendMessage);
}

void Heavy_PhaseRing::cBinop_keXYevjE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_K7cIEOGf, 1, m, &cIf_K7cIEOGf_sendMessage);
}

void Heavy_PhaseRing::cSwitchcase_cGEfyp8i_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_naKUAxcS, 0, m, &cSlice_naKUAxcS_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_kLSVbBme, 0, m, &cSlice_kLSVbBme_sendMessage);
      break;
    }
    case 0x40000000: { // "2.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_OYMmqkuX, 0, m, &cSlice_OYMmqkuX_sendMessage);
      break;
    }
    case 0x40400000: { // "3.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_RBQIAbgh, 0, m, &cSlice_RBQIAbgh_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_PhaseRing::cSlice_naKUAxcS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_ChSpvips, 0, m, &cSlice_ChSpvips_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_99pisYur, 0, m, &cSlice_99pisYur_sendMessage);
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_ChSpvips, 0, m, &cSlice_ChSpvips_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_99pisYur, 0, m, &cSlice_99pisYur_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cSlice_kLSVbBme_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_ADDInxI0, 0, m, &cSlice_ADDInxI0_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_p3O1i843, 0, m, &cSlice_p3O1i843_sendMessage);
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_ADDInxI0, 0, m, &cSlice_ADDInxI0_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_p3O1i843, 0, m, &cSlice_p3O1i843_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cSlice_OYMmqkuX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_koQ36P8X, 0, m, &cSlice_koQ36P8X_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_fM3STcNv, 0, m, &cSlice_fM3STcNv_sendMessage);
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_koQ36P8X, 0, m, &cSlice_koQ36P8X_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_fM3STcNv, 0, m, &cSlice_fM3STcNv_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cSlice_RBQIAbgh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_1mX6OInW, 0, m, &cSlice_1mX6OInW_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_sO28ZsSo, 0, m, &cSlice_sO28ZsSo_sendMessage);
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_1mX6OInW, 0, m, &cSlice_1mX6OInW_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_sO28ZsSo, 0, m, &cSlice_sO28ZsSo_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cSwitchcase_g7H0zRBw_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_5pAj1Wte_sendMessage);
      break;
    }
    default: {
      cMsg_L5pxz3IN_sendMessage(_c, 0, m);
      break;
    }
  }
}

void Heavy_PhaseRing::cCast_5pAj1Wte_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_QflhTxkZ_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cIf_L8GP2e5D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_rBqKbWu5, 0, m, &cSlice_rBqKbWu5_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_Y4ymYJMJ, 0, m, &cSlice_Y4ymYJMJ_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_SZYFN63k, 0, m, &cIf_SZYFN63k_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_PhaseRing::cVar_aQzJcq0l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_sHGa6IQY_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_L8GP2e5D, 1, m, &cIf_L8GP2e5D_sendMessage);
}

void Heavy_PhaseRing::cBinop_sHGa6IQY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_aQzJcq0l, 1, m, &cVar_aQzJcq0l_sendMessage);
}

void Heavy_PhaseRing::cMsg_QflhTxkZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_aQzJcq0l, 0, m, &cVar_aQzJcq0l_sendMessage);
}

void Heavy_PhaseRing::cMsg_L5pxz3IN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_aQzJcq0l, 0, m, &cVar_aQzJcq0l_sendMessage);
}

void Heavy_PhaseRing::cPack_uiQKWEt8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_cGEfyp8i_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cVar_a53F9EnR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_uiQKWEt8, 0, m, &cPack_uiQKWEt8_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_Snph5qh7_sendMessage);
}

void Heavy_PhaseRing::cBinop_Snph5qh7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MOD_BIPOLAR, 4.0f, 0, m, &cBinop_ektFjC8y_sendMessage);
}

void Heavy_PhaseRing::cBinop_ektFjC8y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_a53F9EnR, 1, m, &cVar_a53F9EnR_sendMessage);
}

void Heavy_PhaseRing::cMsg_oGaZ4LFZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_g7H0zRBw_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cCast_1Iea8vT2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_uiQKWEt8, 1, m, &cPack_uiQKWEt8_sendMessage);
}

void Heavy_PhaseRing::cCast_rxxT7Dom_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_a53F9EnR, 0, m, &cVar_a53F9EnR_sendMessage);
}

void Heavy_PhaseRing::cSend_EdQSfCDP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_DjA1XxId_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_jDDBRUsK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_yJ1v9AAQ_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_YJzOet2d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cBinop_oxGxCIt5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_cpOkZJK3_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cBinop_3ldLjlYp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_1mDVzfSu_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_cpOkZJK3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_fPanzfoc_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cSend_1mDVzfSu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cCast_R5lyrSSI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_kAFTulCR_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_gOTbLInu_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_PhaseRing::cReceive_qRUvZRqY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_iN6RLwCo_sendMessage(_c, 0, m);
  cMsg_vwh2TsXL_sendMessage(_c, 0, m);
  cMsg_jN8HL5tY_sendMessage(_c, 0, m);
  cMsg_ccigFJUs_sendMessage(_c, 0, m);
  cMsg_AlMTJXmB_sendMessage(_c, 0, m);
  cMsg_8JVXfjhi_sendMessage(_c, 0, m);
  cMsg_7l1k6ESF_sendMessage(_c, 0, m);
  cMsg_umhDlmvg_sendMessage(_c, 0, m);
  cMsg_w12cHGAo_sendMessage(_c, 0, m);
  cMsg_1ZF7J6Ho_sendMessage(_c, 0, m);
  cMsg_LMKr9yU2_sendMessage(_c, 0, m);
  cMsg_5uSuEj6w_sendMessage(_c, 0, m);
  cMsg_rSpqhgBO_sendMessage(_c, 0, m);
  cMsg_sV6zeNQD_sendMessage(_c, 0, m);
  cMsg_HNlauUI2_sendMessage(_c, 0, m);
  cMsg_pxYlYqFr_sendMessage(_c, 0, m);
  cMsg_t9EShhj3_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_6LRTzgMY, 0, m, &cVar_6LRTzgMY_sendMessage);
  cMsg_yNShKW90_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_dfxLSRfh, 0, m, &cVar_dfxLSRfh_sendMessage);
  cMsg_bpJHA15v_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_R4LRTRsI, 0, m, &cVar_R4LRTRsI_sendMessage);
  cMsg_N9C6l6YR_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_szbmEw9T, 0, m, &cVar_szbmEw9T_sendMessage);
  cMsg_ZR8GZi8j_sendMessage(_c, 0, m);
  cMsg_DnVkcDUh_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_TocowoRV, 0, m, &cVar_TocowoRV_sendMessage);
  cMsg_Tzr9FRRg_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_1V6rz622, 0, m, &cVar_1V6rz622_sendMessage);
  cMsg_Gzt9gv5h_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_6kqa7WwG, 0, m, &cVar_6kqa7WwG_sendMessage);
  cMsg_DMZlK2IE_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_Xe9Np1Ow, 0, m, &cVar_Xe9Np1Ow_sendMessage);
  cMsg_ElKS9Gb3_sendMessage(_c, 0, m);
  cMsg_sOKjRJ4u_sendMessage(_c, 0, m);
  cMsg_XJW8pwMJ_sendMessage(_c, 0, m);
  cMsg_7E7iYlMU_sendMessage(_c, 0, m);
  cMsg_7d71pZs7_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_FZGTin4Z, 0, m, &cVar_FZGTin4Z_sendMessage);
  cMsg_Os06LL27_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_3bYVVJ2t, 0, m, &cVar_3bYVVJ2t_sendMessage);
  cMsg_tD6ARp3q_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_uz1WtjY3, 0, m, &cVar_uz1WtjY3_sendMessage);
  cMsg_i5W2rULe_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_9Mk4b4EK, 0, m, &cVar_9Mk4b4EK_sendMessage);
  cMsg_dG5pWqJN_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_D9G8DfNz, 0, m, &cVar_D9G8DfNz_sendMessage);
  cMsg_3AMtolcL_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_x5XmyhZz, 0, m, &cVar_x5XmyhZz_sendMessage);
  cMsg_NOlhxJJf_sendMessage(_c, 0, m);
  cMsg_4RhTq7bE_sendMessage(_c, 0, m);
  cMsg_y7hYwbmY_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_WZnOZDqG, 0, m, &cVar_WZnOZDqG_sendMessage);
  cMsg_oBcYT3Kc_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_XaqVHJDX, 0, m, &cVar_XaqVHJDX_sendMessage);
  cMsg_k7ai2Rly_sendMessage(_c, 0, m);
  cMsg_uYPZIHNE_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_vxawBnJw, 0, m, &cVar_vxawBnJw_sendMessage);
  cMsg_IhhfgJIs_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_LimWL3jb, 0, m, &cVar_LimWL3jb_sendMessage);
  cMsg_e10rBvPP_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_DmH27y1p, 0, m, &cVar_DmH27y1p_sendMessage);
  cMsg_eA2EBN5F_sendMessage(_c, 0, m);
  cMsg_W3XgenVh_sendMessage(_c, 0, m);
  cMsg_pYWtGf0L_sendMessage(_c, 0, m);
  cMsg_qI7ca1qn_sendMessage(_c, 0, m);
  cMsg_izBttSKD_sendMessage(_c, 0, m);
  cMsg_pHBE2kUj_sendMessage(_c, 0, m);
  cMsg_C2VDyfXt_sendMessage(_c, 0, m);
  cMsg_a8lzoC4W_sendMessage(_c, 0, m);
  cMsg_UHUvrq52_sendMessage(_c, 0, m);
  cMsg_uA1NvSwS_sendMessage(_c, 0, m);
  cMsg_6SpKZ2en_sendMessage(_c, 0, m);
  cMsg_EA38cOFd_sendMessage(_c, 0, m);
  cMsg_D47Y4gY7_sendMessage(_c, 0, m);
  cMsg_a3i1HnEd_sendMessage(_c, 0, m);
  cMsg_Iw3mLRAf_sendMessage(_c, 0, m);
  cMsg_wKcFDzHm_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_V0YU1TVm, 0, m, &cVar_V0YU1TVm_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_KQJ9X5YQ, 0, m, &cVar_KQJ9X5YQ_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_TRSC3Dk6, 0, m, &cVar_TRSC3Dk6_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_FkBlJBq4, 0, m, &cVar_FkBlJBq4_sendMessage);
  cMsg_IIcGIExe_sendMessage(_c, 0, m);
  cMsg_l4kawpgZ_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_SqDghORD, 0, m, &cVar_SqDghORD_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_2iZB8TKO, 0, m, &cVar_2iZB8TKO_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_l6gCb4pB, 0, m, &cVar_l6gCb4pB_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_u4M5Kw45, 0, m, &cVar_u4M5Kw45_sendMessage);
  cMsg_b72HuPth_sendMessage(_c, 0, m);
  cMsg_2EsKc4pi_sendMessage(_c, 0, m);
  cMsg_hulCPwoa_sendMessage(_c, 0, m);
  cMsg_qQhIeoPK_sendMessage(_c, 0, m);
  cMsg_dqjuQOA4_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_B6xNNFYD, 0, m, &cVar_B6xNNFYD_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_dt67yyR2, 0, m, &cVar_dt67yyR2_sendMessage);
  cMsg_PbgNkEp7_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_nLwfxbG4, 0, m, &cVar_nLwfxbG4_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_OQOud2rS, 0, m, &cVar_OQOud2rS_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_01ZVbxBp, 0, m, &cVar_01ZVbxBp_sendMessage);
  cMsg_ACSgB3AO_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_UpZ3dMgq, 0, m, &cVar_UpZ3dMgq_sendMessage);
  cMsg_94Z8kmJ1_sendMessage(_c, 0, m);
  cMsg_fjKk81SI_sendMessage(_c, 0, m);
  cMsg_bDB5eSej_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_kFBk3sAx, 0, m, &cVar_kFBk3sAx_sendMessage);
  cMsg_IRsShFXg_sendMessage(_c, 0, m);
  cMsg_VV1wwgUp_sendMessage(_c, 0, m);
  cMsg_dmm87hDk_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_TuH5b9Yo, 0, m, &cVar_TuH5b9Yo_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_g4Bpzf2Q, 0, m, &cVar_g4Bpzf2Q_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_qYUDKa91, 0, m, &cVar_qYUDKa91_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_JOcjshYM, 0, m, &cVar_JOcjshYM_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_Eaeu68ou, 0, m, &cVar_Eaeu68ou_sendMessage);
  cMsg_oGaZ4LFZ_sendMessage(_c, 0, m);
  cSwitchcase_kAFTulCR_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_gOTbLInu_onMessage(_c, NULL, 0, m, NULL);
  cMsg_2ELOijWs_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_ymCsbo9w, 0, m, &cVar_ymCsbo9w_sendMessage);
  cMsg_JeasGwhu_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_PKJAoYgQ, 0, m, &cTabhead_PKJAoYgQ_sendMessage);
  cMsg_RFLS85b2_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_xkqRYso3, 0, m, &cVar_xkqRYso3_sendMessage);
  cMsg_OYXWxyLk_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_YRdUMsRO, 0, m, &cTabhead_YRdUMsRO_sendMessage);
  cMsg_aylrYR0a_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_JkPGihsM, 0, m, &cVar_JkPGihsM_sendMessage);
  cMsg_0Y0M7hdy_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_MzangppQ, 0, m, &cTabhead_MzangppQ_sendMessage);
  cMsg_2rRnA4Ox_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_jCF6TWWn, 0, m, &cVar_jCF6TWWn_sendMessage);
  cMsg_f0RjTs9m_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_ZG38nnqM, 0, m, &cTabhead_ZG38nnqM_sendMessage);
  cMsg_VnyC99wd_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_18e9SGzg, 0, m, &cVar_18e9SGzg_sendMessage);
  cMsg_uI52HFYF_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_HoXZ04Un, 0, m, &cTabhead_HoXZ04Un_sendMessage);
  cMsg_SPwU5nNK_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_IsgQPszk, 0, m, &cVar_IsgQPszk_sendMessage);
  cMsg_QL1siCbT_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_y4Bq6gfx, 0, m, &cTabhead_y4Bq6gfx_sendMessage);
  cMsg_MyLzixvw_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_ZNI0gAFB, 0, m, &cVar_ZNI0gAFB_sendMessage);
  cMsg_tZdq0l8v_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_M7RUb4H8, 0, m, &cTabhead_M7RUb4H8_sendMessage);
  cMsg_9XM6FGcR_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_kUYYAuQl, 0, m, &cVar_kUYYAuQl_sendMessage);
  cMsg_rCyRjsTK_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_y1YWpaio, 0, m, &cTabhead_y1YWpaio_sendMessage);
  cMsg_t3Kz71VC_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_AIrMCi7o, 0, m, &cVar_AIrMCi7o_sendMessage);
  cMsg_K7sAQcAH_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_6DgCmMTD, 0, m, &cTabhead_6DgCmMTD_sendMessage);
  cMsg_DuM3fqKJ_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_p1m54qKC, 0, m, &cVar_p1m54qKC_sendMessage);
  cMsg_wIwvaL8s_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_QFpfnUpP, 0, m, &cTabhead_QFpfnUpP_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_ZWEmzime, 0, m, &cVar_ZWEmzime_sendMessage);
  cMsg_MT6gTPMd_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_80yF5D8Y, 0, m, &cVar_80yF5D8Y_sendMessage);
  cMsg_HSbVO19H_sendMessage(_c, 0, m);
  cMsg_JiEcyKEe_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_XthSwvQT, 0, m, &cVar_XthSwvQT_sendMessage);
  cMsg_4uf04fqp_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_WsZHRWlg, 0, m, &cTabhead_WsZHRWlg_sendMessage);
  cMsg_o7fTwwgi_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_XGhd7fqo, 0, m, &cVar_XGhd7fqo_sendMessage);
  cMsg_ZWo7INuH_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_SOQTdbn3, 0, m, &cTabhead_SOQTdbn3_sendMessage);
  cMsg_l0m8oKyS_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_J7EQE7NA, 0, m, &cVar_J7EQE7NA_sendMessage);
  cMsg_WV7IXGms_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_8Xfd0Yjh, 0, m, &cTabhead_8Xfd0Yjh_sendMessage);
  cMsg_XCW9ujSH_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_dHJgW9Vn, 0, m, &cVar_dHJgW9Vn_sendMessage);
  cMsg_3EiEXYQx_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_uP65eeQc, 0, m, &cTabhead_uP65eeQc_sendMessage);
  cMsg_1PFVB6sf_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_ainKTSfH, 0, m, &cVar_ainKTSfH_sendMessage);
  cMsg_FbRXpCBn_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_y2zRwp8g, 0, m, &cTabhead_y2zRwp8g_sendMessage);
  cMsg_0dvKkeC5_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_VSRAw14X, 0, m, &cVar_VSRAw14X_sendMessage);
  cMsg_jq55np6a_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_bWdTlbUx, 0, m, &cTabhead_bWdTlbUx_sendMessage);
  cMsg_aMOfB8ql_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_4GEfLeRi, 0, m, &cVar_4GEfLeRi_sendMessage);
  cMsg_eNn1DDOz_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_UZcQgShe, 0, m, &cTabhead_UZcQgShe_sendMessage);
  cMsg_q8l4LAOd_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_InMgz6dl, 0, m, &cVar_InMgz6dl_sendMessage);
  cMsg_3nNJ1LnE_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_wf2et4NE, 0, m, &cTabhead_wf2et4NE_sendMessage);
  cMsg_pNEGaJdY_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_5NOlhK1a, 0, m, &cVar_5NOlhK1a_sendMessage);
  cMsg_Ut7Tlvxh_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_Cwy4JVJP, 0, m, &cTabhead_Cwy4JVJP_sendMessage);
  cMsg_lnr2VvNg_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_aJKqne9N, 0, m, &cVar_aJKqne9N_sendMessage);
  cMsg_zIRL8FL6_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_Od7cPgu2, 0, m, &cTabhead_Od7cPgu2_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_9wAZSxKR, 0, m, &cVar_9wAZSxKR_sendMessage);
  cMsg_fA69qNCc_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_Dn4DoP5Y, 0, m, &cVar_Dn4DoP5Y_sendMessage);
  cMsg_uvTtembw_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_909CY1Yr, 0, m, &cVar_909CY1Yr_sendMessage);
  cMsg_sdEMNG7s_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_ZV0iPES5, 0, m, &cVar_ZV0iPES5_sendMessage);
  cMsg_s0MZ56ay_sendMessage(_c, 0, m);
}

void Heavy_PhaseRing::cReceive_s4ZhpCup_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSlice_onMessage(_c, &Context(_c)->cSlice_t152vozy, 0, m, &cSlice_t152vozy_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_R7G9iIVs, 0, m, &cSlice_R7G9iIVs_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_N7p4BpPZ, 0, m, &cSlice_N7p4BpPZ_sendMessage);
}

void Heavy_PhaseRing::cReceive_DjA1XxId_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_cfKMRaSE, 0, m, &cPack_cfKMRaSE_sendMessage);
}

void Heavy_PhaseRing::cReceive_yJ1v9AAQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_cfKMRaSE, 1, m, &cPack_cfKMRaSE_sendMessage);
}

void Heavy_PhaseRing::cReceive_Y8q0WfVZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_1EYqqImq_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_IHrogl3L, 0, m, &cIf_IHrogl3L_sendMessage);
}

void Heavy_PhaseRing::cReceive_ameDsnCC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_wtZ9WGDr_sendMessage);
}

void Heavy_PhaseRing::cReceive_PFWEuaTR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_UcYdq4P5, 0, m, &cPack_UcYdq4P5_sendMessage);
}

void Heavy_PhaseRing::cReceive_9Ig8YbV4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 100.0f, 0, m, &cBinop_FFVLC2zk_sendMessage);
}

void Heavy_PhaseRing::cReceive_G9qUHfjt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_PhaseRing::cReceive_wZeMyHKU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_VcADsDTx_sendMessage);
}

void Heavy_PhaseRing::cReceive_HbVaARHM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_I58hh5V1_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_9EFjEJA7_sendMessage);
}

void Heavy_PhaseRing::cReceive_RuhEF7ii_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_R5lyrSSI_sendMessage);
}

void Heavy_PhaseRing::cReceive_fPanzfoc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_pYF2rsxM, 0, m, &cVar_pYF2rsxM_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_4rvMlW8n, 0, m, &cVar_4rvMlW8n_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_328UnsqH, 0, m, &cVar_328UnsqH_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_BBPNlROP, 0, m, &cVar_BBPNlROP_sendMessage);
  cPack_onMessage(_c, &Context(_c)->cPack_AbB5bNvQ, 0, m, &cPack_AbB5bNvQ_sendMessage);
}

void Heavy_PhaseRing::cReceive_JDOgHzIi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_p69Ew7PL_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_iz6ZM54m, 0, m, &cVar_iz6ZM54m_sendMessage);
}

void Heavy_PhaseRing::cReceive_ExvrLLbX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_dwzpjVVs, 0, m, &cPack_dwzpjVVs_sendMessage);
}

void Heavy_PhaseRing::cReceive_Nv5OWljY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ggZbEbIr, 1, m, &cVar_ggZbEbIr_sendMessage);
}

void Heavy_PhaseRing::cReceive_JzLiDlwB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_79xccx8L, m);
}

void Heavy_PhaseRing::cReceive_T1X8bEvl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_SPfM46CO_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_8o20CKEB, 0, m, &cVar_8o20CKEB_sendMessage);
}

void Heavy_PhaseRing::cReceive_houNTp4F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_HMTYrv4g_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_yM5d0sHz, 0, m, &cVar_yM5d0sHz_sendMessage);
}

void Heavy_PhaseRing::cReceive_4FRzEyY0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_xMBWSgGD, 0, m, &cVar_xMBWSgGD_sendMessage);
}

void Heavy_PhaseRing::cReceive_2JIVmhmZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_NG1ZfrJS_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ajFkWJnt_sendMessage);
}

void Heavy_PhaseRing::cReceive_M0NFbTDl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_cxbaGcO3_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_qtRNSrp1, 0, m, &cVar_qtRNSrp1_sendMessage);
}

void Heavy_PhaseRing::cReceive_8kWYcDR8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_4ydY3gu5, 0, m, &cPack_4ydY3gu5_sendMessage);
}

void Heavy_PhaseRing::cReceive_SqqMOqSE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_HPyzL3XY, 1, m, &cVar_HPyzL3XY_sendMessage);
}

void Heavy_PhaseRing::cReceive_dpijk8jP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_ldg2SXAq, m);
}

void Heavy_PhaseRing::cReceive_yPucuyRw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_DxUMSgFj_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_uKGIor9U, 0, m, &cVar_uKGIor9U_sendMessage);
}

void Heavy_PhaseRing::cReceive_Ts5SryUo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_fT6hIj95_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_eDfkzju1, 0, m, &cVar_eDfkzju1_sendMessage);
}

void Heavy_PhaseRing::cReceive_5S4XP6By_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_7GHoLK5f_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_2HiJmuno, 0, m, &cVar_2HiJmuno_sendMessage);
}

void Heavy_PhaseRing::cReceive_EN0yeAGn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_PpfQqbnP, 0, m, &cPack_PpfQqbnP_sendMessage);
}

void Heavy_PhaseRing::cReceive_MSOHPAY8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_LdK2880n, 1, m, &cVar_LdK2880n_sendMessage);
}

void Heavy_PhaseRing::cReceive_AkusoDBT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_rzONZbPW, m);
}

void Heavy_PhaseRing::cReceive_Jsi2KsUT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_OmQmmaTB_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_0TAJRVHO, 0, m, &cVar_0TAJRVHO_sendMessage);
}

void Heavy_PhaseRing::cReceive_iQVfA9MC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_Tf9sMAjj_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_lo2HXstj, 0, m, &cVar_lo2HXstj_sendMessage);
}

void Heavy_PhaseRing::cReceive_s4LpBP5s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_JRJfSw4q_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_jCMxTrIC, 0, m, &cVar_jCMxTrIC_sendMessage);
}

void Heavy_PhaseRing::cReceive_KDKDC1DZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_vwrQKZI6, 0, m, &cPack_vwrQKZI6_sendMessage);
}

void Heavy_PhaseRing::cReceive_yQQq0HF1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_nyFf79KP, 1, m, &cVar_nyFf79KP_sendMessage);
}

void Heavy_PhaseRing::cReceive_tFO6OEUW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_eEbQ7xl6, m);
}

void Heavy_PhaseRing::cReceive_dmxv91Sr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_bOFnyVPT_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_OZb1oely, 0, m, &cVar_OZb1oely_sendMessage);
}

void Heavy_PhaseRing::cReceive_aWis9EXq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_HKLFW5mi_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_9eRyPZDv, 0, m, &cVar_9eRyPZDv_sendMessage);
}

void Heavy_PhaseRing::cReceive_fgs3rCYw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 2.0f, 0, m, &cBinop_aayfKTMC_sendMessage);
}

void Heavy_PhaseRing::cReceive_2tS2bTD5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_sG1wr6ON_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_hOPUKVf0_sendMessage);
  cPack_onMessage(_c, &Context(_c)->cPack_HSpiA0OO, 0, m, &cPack_HSpiA0OO_sendMessage);
}

void Heavy_PhaseRing::cReceive_K6kYGOoT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ReOXdNEE, 0, m, &cVar_ReOXdNEE_sendMessage);
}

void Heavy_PhaseRing::cReceive_EuF8WM5Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_UghgvAXH_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_HwuNHsCy_sendMessage);
}

void Heavy_PhaseRing::cReceive_X9il3AO2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 2.0f, 0, m, &cBinop_J0oZ1swG_sendMessage);
}

void Heavy_PhaseRing::cReceive_RTeaCjQs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_61ONUGQJ, 0, m, &cVar_61ONUGQJ_sendMessage);
}

void Heavy_PhaseRing::cReceive_m3j1YjTv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_P5CnOrQ8_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_fEW0vi56_sendMessage);
}

void Heavy_PhaseRing::cReceive_SlMi2liB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 2.0f, 0, m, &cBinop_VtFCNrAv_sendMessage);
}

void Heavy_PhaseRing::cReceive_Yggd9BMG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_FRWHdrnN, 0, m, &cVar_FRWHdrnN_sendMessage);
}

void Heavy_PhaseRing::cReceive_e5WijMKm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Xjzf4MN4_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ZBptP23i_sendMessage);
}

void Heavy_PhaseRing::cReceive_FaHapAJH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_6DYfFFgu, 0, m, &cVar_6DYfFFgu_sendMessage);
}

void Heavy_PhaseRing::cReceive_AH3Jw1fB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_HdQJmptV_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_mPYIitSz_sendMessage);
}

void Heavy_PhaseRing::cReceive_eHDqS1ro_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_JUJXUbZL, 0, m, &cVar_JUJXUbZL_sendMessage);
}

void Heavy_PhaseRing::cReceive_G1ZjrBZW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_N0iKfc4Z_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_qOYFMPo6_sendMessage);
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

int Heavy_PhaseRing::process(float **inputBuffers, float **outputBuffers, int n) {
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
    __hv_phasor_k_f(&sPhasor_8xjvbFM4, VOf(Bf0));
    __hv_var_k_f(VOf(Bf1), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_abs_f(VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf0), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf1), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_mul_f(VIf(Bf1), VIf(Bf1), VOf(Bf0));
    __hv_mul_f(VIf(Bf1), VIf(Bf0), VOf(Bf2));
    __hv_mul_f(VIf(Bf2), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf3), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf4), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf2), VIf(Bf4), VIf(Bf1), VOf(Bf1));
    __hv_fma_f(VIf(Bf0), VIf(Bf3), VIf(Bf1), VOf(Bf1));
    __hv_line_f(&sLine_Vnqry04P, VOf(Bf3));
    __hv_phasor_k_f(&sPhasor_2h68xAfX, VOf(Bf0));
    __hv_fma_f(VIf(Bf1), VIf(Bf3), VIf(Bf0), VOf(Bf0));
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
    __hv_mul_f(VIf(Bf0), VIf(Bf3), VOf(Bf1));
    __hv_mul_f(VIf(Bf1), VIf(Bf3), VOf(Bf4));
    __hv_mul_f(VIf(Bf4), VIf(Bf3), VOf(Bf2));
    __hv_mul_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf5), 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f);
    __hv_var_k_f(VOf(Bf6), 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f);
    __hv_var_k_f(VOf(Bf7), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf1), VIf(Bf7), VOf(Bf7));
    __hv_sub_f(VIf(Bf0), VIf(Bf7), VOf(Bf7));
    __hv_fma_f(VIf(Bf4), VIf(Bf6), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf6), 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f);
    __hv_mul_f(VIf(Bf2), VIf(Bf6), VOf(Bf6));
    __hv_sub_f(VIf(Bf7), VIf(Bf6), VOf(Bf6));
    __hv_fma_f(VIf(Bf3), VIf(Bf5), VIf(Bf6), VOf(Bf6));
    __hv_line_f(&sLine_0FiL2UtP, VOf(Bf5));
    __hv_varread_f(&sVarf_79xccx8L, VOf(Bf3));
    __hv_mul_f(VIf(Bf5), VIf(Bf3), VOf(Bf3));
    __hv_mul_f(VIf(Bf6), VIf(Bf3), VOf(Bf3));
    __hv_line_f(&sLine_pqDwP36A, VOf(Bf6));
    __hv_mul_f(VIf(Bf3), VIf(Bf6), VOf(Bf6));
    __hv_line_f(&sLine_lJJYPFY0, VOf(Bf5));
    __hv_mul_f(VIf(Bf3), VIf(Bf5), VOf(Bf5));
    __hv_phasor_k_f(&sPhasor_hXgxF3mQ, VOf(Bf3));
    __hv_var_k_f(VOf(Bf7), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf3), VIf(Bf7), VOf(Bf7));
    __hv_abs_f(VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf3), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf7), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf7), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf3), VIf(Bf7), VOf(Bf7));
    __hv_mul_f(VIf(Bf7), VIf(Bf7), VOf(Bf3));
    __hv_mul_f(VIf(Bf7), VIf(Bf3), VOf(Bf2));
    __hv_mul_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf4), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf0), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf2), VIf(Bf0), VIf(Bf7), VOf(Bf7));
    __hv_fma_f(VIf(Bf3), VIf(Bf4), VIf(Bf7), VOf(Bf7));
    __hv_line_f(&sLine_Ei8Ad6TM, VOf(Bf4));
    __hv_phasor_k_f(&sPhasor_3t5OeHne, VOf(Bf3));
    __hv_fma_f(VIf(Bf7), VIf(Bf4), VIf(Bf3), VOf(Bf3));
    __hv_floor_f(VIf(Bf3), VOf(Bf4));
    __hv_sub_f(VIf(Bf3), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf3), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf4), VIf(Bf3), VOf(Bf3));
    __hv_abs_f(VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf4), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf3), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf3), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf4), VIf(Bf3), VOf(Bf3));
    __hv_mul_f(VIf(Bf3), VIf(Bf3), VOf(Bf4));
    __hv_mul_f(VIf(Bf3), VIf(Bf4), VOf(Bf7));
    __hv_mul_f(VIf(Bf7), VIf(Bf4), VOf(Bf0));
    __hv_mul_f(VIf(Bf0), VIf(Bf4), VOf(Bf2));
    __hv_mul_f(VIf(Bf2), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf1), 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f);
    __hv_var_k_f(VOf(Bf8), 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f);
    __hv_var_k_f(VOf(Bf9), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf7), VIf(Bf9), VOf(Bf9));
    __hv_sub_f(VIf(Bf3), VIf(Bf9), VOf(Bf9));
    __hv_fma_f(VIf(Bf0), VIf(Bf8), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf8), 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f);
    __hv_mul_f(VIf(Bf2), VIf(Bf8), VOf(Bf8));
    __hv_sub_f(VIf(Bf9), VIf(Bf8), VOf(Bf8));
    __hv_fma_f(VIf(Bf4), VIf(Bf1), VIf(Bf8), VOf(Bf8));
    __hv_line_f(&sLine_SyuuZYQq, VOf(Bf1));
    __hv_varread_f(&sVarf_ldg2SXAq, VOf(Bf4));
    __hv_mul_f(VIf(Bf1), VIf(Bf4), VOf(Bf4));
    __hv_mul_f(VIf(Bf8), VIf(Bf4), VOf(Bf4));
    __hv_line_f(&sLine_hR0mzLSV, VOf(Bf8));
    __hv_mul_f(VIf(Bf4), VIf(Bf8), VOf(Bf8));
    __hv_line_f(&sLine_tbWCPgeO, VOf(Bf1));
    __hv_mul_f(VIf(Bf4), VIf(Bf1), VOf(Bf1));
    __hv_add_f(VIf(Bf6), VIf(Bf8), VOf(Bf8));
    __hv_phasor_k_f(&sPhasor_NfUPZeBd, VOf(Bf6));
    __hv_var_k_f(VOf(Bf4), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf6), VIf(Bf4), VOf(Bf4));
    __hv_abs_f(VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf6), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf4), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf4), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf6), VIf(Bf4), VOf(Bf4));
    __hv_mul_f(VIf(Bf4), VIf(Bf4), VOf(Bf6));
    __hv_mul_f(VIf(Bf4), VIf(Bf6), VOf(Bf9));
    __hv_mul_f(VIf(Bf9), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf2), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf0), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf9), VIf(Bf0), VIf(Bf4), VOf(Bf4));
    __hv_fma_f(VIf(Bf6), VIf(Bf2), VIf(Bf4), VOf(Bf4));
    __hv_line_f(&sLine_ovVB64wb, VOf(Bf2));
    __hv_phasor_k_f(&sPhasor_1M3FhNn6, VOf(Bf6));
    __hv_fma_f(VIf(Bf4), VIf(Bf2), VIf(Bf6), VOf(Bf6));
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
    __hv_mul_f(VIf(Bf6), VIf(Bf2), VOf(Bf4));
    __hv_mul_f(VIf(Bf4), VIf(Bf2), VOf(Bf0));
    __hv_mul_f(VIf(Bf0), VIf(Bf2), VOf(Bf9));
    __hv_mul_f(VIf(Bf9), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf3), 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f);
    __hv_var_k_f(VOf(Bf7), 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f);
    __hv_var_k_f(VOf(Bf10), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf4), VIf(Bf10), VOf(Bf10));
    __hv_sub_f(VIf(Bf6), VIf(Bf10), VOf(Bf10));
    __hv_fma_f(VIf(Bf0), VIf(Bf7), VIf(Bf10), VOf(Bf10));
    __hv_var_k_f(VOf(Bf7), 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f);
    __hv_mul_f(VIf(Bf9), VIf(Bf7), VOf(Bf7));
    __hv_sub_f(VIf(Bf10), VIf(Bf7), VOf(Bf7));
    __hv_fma_f(VIf(Bf2), VIf(Bf3), VIf(Bf7), VOf(Bf7));
    __hv_line_f(&sLine_7fBIVWou, VOf(Bf3));
    __hv_varread_f(&sVarf_rzONZbPW, VOf(Bf2));
    __hv_mul_f(VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_mul_f(VIf(Bf7), VIf(Bf2), VOf(Bf2));
    __hv_line_f(&sLine_vsVeom0q, VOf(Bf7));
    __hv_mul_f(VIf(Bf2), VIf(Bf7), VOf(Bf7));
    __hv_line_f(&sLine_giRKzRuL, VOf(Bf3));
    __hv_mul_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_add_f(VIf(Bf8), VIf(Bf7), VOf(Bf7));
    __hv_phasor_k_f(&sPhasor_XOGQDcF2, VOf(Bf8));
    __hv_var_k_f(VOf(Bf2), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf8), VIf(Bf2), VOf(Bf2));
    __hv_abs_f(VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf8), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf2), VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf2), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf8), VIf(Bf2), VOf(Bf2));
    __hv_mul_f(VIf(Bf2), VIf(Bf2), VOf(Bf8));
    __hv_mul_f(VIf(Bf2), VIf(Bf8), VOf(Bf10));
    __hv_mul_f(VIf(Bf10), VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf9), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf0), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf10), VIf(Bf0), VIf(Bf2), VOf(Bf2));
    __hv_fma_f(VIf(Bf8), VIf(Bf9), VIf(Bf2), VOf(Bf2));
    __hv_line_f(&sLine_66n4HwTr, VOf(Bf9));
    __hv_phasor_k_f(&sPhasor_bd7RL59k, VOf(Bf8));
    __hv_fma_f(VIf(Bf2), VIf(Bf9), VIf(Bf8), VOf(Bf8));
    __hv_floor_f(VIf(Bf8), VOf(Bf9));
    __hv_sub_f(VIf(Bf8), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf8), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf9), VIf(Bf8), VOf(Bf8));
    __hv_abs_f(VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf9), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf8), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf8), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf9), VIf(Bf8), VOf(Bf8));
    __hv_mul_f(VIf(Bf8), VIf(Bf8), VOf(Bf9));
    __hv_mul_f(VIf(Bf8), VIf(Bf9), VOf(Bf2));
    __hv_mul_f(VIf(Bf2), VIf(Bf9), VOf(Bf0));
    __hv_mul_f(VIf(Bf0), VIf(Bf9), VOf(Bf10));
    __hv_mul_f(VIf(Bf10), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf6), 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f);
    __hv_var_k_f(VOf(Bf4), 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f);
    __hv_var_k_f(VOf(Bf11), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf2), VIf(Bf11), VOf(Bf11));
    __hv_sub_f(VIf(Bf8), VIf(Bf11), VOf(Bf11));
    __hv_fma_f(VIf(Bf0), VIf(Bf4), VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf4), 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f);
    __hv_mul_f(VIf(Bf10), VIf(Bf4), VOf(Bf4));
    __hv_sub_f(VIf(Bf11), VIf(Bf4), VOf(Bf4));
    __hv_fma_f(VIf(Bf9), VIf(Bf6), VIf(Bf4), VOf(Bf4));
    __hv_line_f(&sLine_0wbImGNT, VOf(Bf6));
    __hv_varread_f(&sVarf_eEbQ7xl6, VOf(Bf9));
    __hv_mul_f(VIf(Bf6), VIf(Bf9), VOf(Bf9));
    __hv_mul_f(VIf(Bf4), VIf(Bf9), VOf(Bf9));
    __hv_line_f(&sLine_T2jB01bg, VOf(Bf4));
    __hv_mul_f(VIf(Bf9), VIf(Bf4), VOf(Bf4));
    __hv_line_f(&sLine_X2Ctjfu6, VOf(Bf6));
    __hv_mul_f(VIf(Bf9), VIf(Bf6), VOf(Bf6));
    __hv_add_f(VIf(Bf7), VIf(Bf4), VOf(Bf4));
    __hv_add_f(VIf(Bf5), VIf(Bf1), VOf(Bf1));
    __hv_add_f(VIf(Bf1), VIf(Bf3), VOf(Bf3));
    __hv_add_f(VIf(Bf3), VIf(Bf6), VOf(Bf6));
    __hv_line_f(&sLine_lL5QB7I5, VOf(Bf3));
    __hv_mul_f(VIf(Bf4), VIf(Bf3), VOf(Bf4));
    __hv_mul_f(VIf(Bf6), VIf(Bf3), VOf(Bf3));
    __hv_line_f(&sLine_0jMSPHJD, VOf(Bf6));
    __hv_phasor_f(&sPhasor_iGrYHzLO, VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf1), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf6), VIf(Bf1), VOf(Bf1));
    __hv_abs_f(VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf6), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf1), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf1), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf6), VIf(Bf1), VOf(Bf1));
    __hv_mul_f(VIf(Bf1), VIf(Bf1), VOf(Bf6));
    __hv_mul_f(VIf(Bf1), VIf(Bf6), VOf(Bf5));
    __hv_mul_f(VIf(Bf5), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf7), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf9), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf5), VIf(Bf9), VIf(Bf1), VOf(Bf1));
    __hv_fma_f(VIf(Bf6), VIf(Bf7), VIf(Bf1), VOf(Bf1));
    __hv_line_f(&sLine_grwHmHUl, VOf(Bf7));
    __hv_phasor_k_f(&sPhasor_JaqReih0, VOf(Bf6));
    __hv_fma_f(VIf(Bf1), VIf(Bf7), VIf(Bf6), VOf(Bf6));
    __hv_floor_f(VIf(Bf6), VOf(Bf7));
    __hv_sub_f(VIf(Bf6), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf6), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf7), VIf(Bf6), VOf(Bf6));
    __hv_abs_f(VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf7), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf6), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf6), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf7), VIf(Bf6), VOf(Bf6));
    __hv_mul_f(VIf(Bf6), VIf(Bf6), VOf(Bf7));
    __hv_mul_f(VIf(Bf6), VIf(Bf7), VOf(Bf1));
    __hv_mul_f(VIf(Bf1), VIf(Bf7), VOf(Bf9));
    __hv_mul_f(VIf(Bf9), VIf(Bf7), VOf(Bf5));
    __hv_mul_f(VIf(Bf5), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf11), 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f);
    __hv_var_k_f(VOf(Bf10), 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f);
    __hv_var_k_f(VOf(Bf0), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_sub_f(VIf(Bf6), VIf(Bf0), VOf(Bf0));
    __hv_fma_f(VIf(Bf9), VIf(Bf10), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf10), 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f);
    __hv_mul_f(VIf(Bf5), VIf(Bf10), VOf(Bf10));
    __hv_sub_f(VIf(Bf0), VIf(Bf10), VOf(Bf10));
    __hv_fma_f(VIf(Bf7), VIf(Bf11), VIf(Bf10), VOf(Bf10));
    __hv_line_f(&sLine_KWnuyXK0, VOf(Bf11));
    __hv_mul_f(VIf(Bf10), VIf(Bf11), VOf(Bf11));
    __hv_line_f(&sLine_bh3mAzj0, VOf(Bf10));
    __hv_mul_f(VIf(Bf11), VIf(Bf10), VOf(Bf10));
    __hv_varread_f(&sVarf_4MfzdEiX, VOf(Bf11));
    __hv_rpole_f(&sRPole_sTcvMtMw, VIf(Bf10), VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf10), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_del1_f(&sDel1_qwjMvj5G, VIf(Bf11), VOf(Bf7));
    __hv_mul_f(VIf(Bf7), VIf(Bf10), VOf(Bf10));
    __hv_sub_f(VIf(Bf11), VIf(Bf10), VOf(Bf10));
    __hv_varread_f(&sVarf_qThy7gmp, VOf(Bf11));
    __hv_mul_f(VIf(Bf10), VIf(Bf11), VOf(Bf11));
    __hv_line_f(&sLine_1xyjGWfZ, VOf(Bf10));
    __hv_mul_f(VIf(Bf11), VIf(Bf10), VOf(Bf7));
    __hv_mul_f(VIf(Bf11), VIf(Bf10), VOf(Bf10));
    __hv_add_f(VIf(Bf4), VIf(Bf7), VOf(Bf4));
    __hv_add_f(VIf(Bf3), VIf(Bf10), VOf(Bf10));
    __hv_line_f(&sLine_hDQCHo1p, VOf(Bf11));
    __hv_mul_f(VIf(Bf4), VIf(Bf11), VOf(Bf4));
    __hv_mul_f(VIf(Bf10), VIf(Bf11), VOf(Bf11));
    __hv_add_f(VIf(Bf3), VIf(Bf7), VOf(Bf7));
    __hv_line_f(&sLine_zgmiZzxA, VOf(Bf3));
    __hv_mul_f(VIf(Bf7), VIf(Bf3), VOf(Bf3));
    __hv_tabread_f(&sTabread_jw80FZK9, VOf(Bf7));
    __hv_varread_f(&sVarf_SbHORNfz, VOf(Bf10));
    __hv_mul_f(VIf(Bf7), VIf(Bf10), VOf(Bf10));
    __hv_varread_f(&sVarf_osSX212V, VOf(Bf0));
    __hv_rpole_f(&sRPole_Wck1LVDH, VIf(Bf10), VIf(Bf0), VOf(Bf0));
    __hv_sub_f(VIf(Bf0), VIf(Bf7), VOf(Bf0));
    __hv_line_f(&sLine_O5wXZwZz, VOf(Bf10));
    __hv_fma_f(VIf(Bf0), VIf(Bf10), VIf(Bf7), VOf(Bf7));
    __hv_line_f(&sLine_vjEi2ef9, VOf(Bf0));
    __hv_tabread_f(&sTabread_9iULrxbh, VOf(Bf5));
    __hv_add_f(VIf(Bf3), VIf(Bf5), VOf(Bf9));
    __hv_tabread_f(&sTabread_GyrieBLV, VOf(Bf6));
    __hv_add_f(VIf(Bf9), VIf(Bf6), VOf(Bf1));
    __hv_tabread_f(&sTabread_Mt91ilfO, VOf(Bf8));
    __hv_add_f(VIf(Bf1), VIf(Bf8), VOf(Bf2));
    __hv_tabread_f(&sTabread_oSgV7GEt, VOf(Bf12));
    __hv_add_f(VIf(Bf2), VIf(Bf12), VOf(Bf13));
    __hv_tabread_f(&sTabread_czQn5Hxr, VOf(Bf14));
    __hv_sub_f(VIf(Bf13), VIf(Bf14), VOf(Bf15));
    __hv_tabwrite_f(&sTabwrite_s86jEh8Y, VIf(Bf15));
    __hv_sub_f(VIf(Bf2), VIf(Bf12), VOf(Bf12));
    __hv_tabwrite_f(&sTabwrite_mYgV1uUy, VIf(Bf12));
    __hv_sub_f(VIf(Bf1), VIf(Bf8), VOf(Bf8));
    __hv_tabwrite_f(&sTabwrite_vKgcxULU, VIf(Bf8));
    __hv_sub_f(VIf(Bf9), VIf(Bf6), VOf(Bf6));
    __hv_tabwrite_f(&sTabwrite_gDJsvhqR, VIf(Bf6));
    __hv_sub_f(VIf(Bf3), VIf(Bf5), VOf(Bf5));
    __hv_tabwrite_f(&sTabwrite_Nv5UT25H, VIf(Bf5));
    __hv_tabwrite_f(&sTabwrite_X0TP5DSm, VIf(Bf3));
    __hv_add_f(VIf(Bf13), VIf(Bf14), VOf(Bf14));
    __hv_tabread_f(&sTabread_hUsGN24Q, VOf(Bf13));
    __hv_fma_f(VIf(Bf7), VIf(Bf0), VIf(Bf14), VOf(Bf14));
    __hv_tabread_f(&sTabread_TSq8QRuP, VOf(Bf7));
    __hv_varread_f(&sVarf_pLwCfYWS, VOf(Bf5));
    __hv_mul_f(VIf(Bf7), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_vCqxGV1F, VOf(Bf6));
    __hv_rpole_f(&sRPole_TvA7EZcr, VIf(Bf5), VIf(Bf6), VOf(Bf6));
    __hv_sub_f(VIf(Bf6), VIf(Bf7), VOf(Bf6));
    __hv_fma_f(VIf(Bf6), VIf(Bf10), VIf(Bf7), VOf(Bf7));
    __hv_fma_f(VIf(Bf7), VIf(Bf0), VIf(Bf13), VOf(Bf13));
    __hv_add_f(VIf(Bf14), VIf(Bf13), VOf(Bf7));
    __hv_tabread_f(&sTabread_h4nHhP0C, VOf(Bf6));
    __hv_varread_f(&sVarf_2GBhmOo7, VOf(Bf5));
    __hv_mul_f(VIf(Bf6), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_PrrAT8iu, VOf(Bf9));
    __hv_rpole_f(&sRPole_esEqkN9B, VIf(Bf5), VIf(Bf9), VOf(Bf9));
    __hv_sub_f(VIf(Bf9), VIf(Bf6), VOf(Bf9));
    __hv_fma_f(VIf(Bf9), VIf(Bf10), VIf(Bf6), VOf(Bf6));
    __hv_mul_f(VIf(Bf6), VIf(Bf0), VOf(Bf6));
    __hv_tabread_f(&sTabread_evj4GBrQ, VOf(Bf9));
    __hv_varread_f(&sVarf_y7wiJVwz, VOf(Bf5));
    __hv_mul_f(VIf(Bf9), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_vtrYp3df, VOf(Bf8));
    __hv_rpole_f(&sRPole_Q2T7y7xt, VIf(Bf5), VIf(Bf8), VOf(Bf8));
    __hv_sub_f(VIf(Bf8), VIf(Bf9), VOf(Bf8));
    __hv_fma_f(VIf(Bf8), VIf(Bf10), VIf(Bf9), VOf(Bf9));
    __hv_mul_f(VIf(Bf9), VIf(Bf0), VOf(Bf0));
    __hv_add_f(VIf(Bf6), VIf(Bf0), VOf(Bf9));
    __hv_add_f(VIf(Bf7), VIf(Bf9), VOf(Bf10));
    __hv_tabwrite_f(&sTabwrite_CaFt55s4, VIf(Bf10));
    __hv_sub_f(VIf(Bf14), VIf(Bf13), VOf(Bf10));
    __hv_sub_f(VIf(Bf6), VIf(Bf0), VOf(Bf8));
    __hv_add_f(VIf(Bf10), VIf(Bf8), VOf(Bf5));
    __hv_tabwrite_f(&sTabwrite_W5hkesFL, VIf(Bf5));
    __hv_sub_f(VIf(Bf7), VIf(Bf9), VOf(Bf9));
    __hv_tabwrite_f(&sTabwrite_qGv01GnR, VIf(Bf9));
    __hv_sub_f(VIf(Bf10), VIf(Bf8), VOf(Bf8));
    __hv_tabwrite_f(&sTabwrite_L7WOB0wH, VIf(Bf8));
    __hv_line_f(&sLine_hOiOVTYt, VOf(Bf8));
    __hv_mul_f(VIf(Bf14), VIf(Bf8), VOf(Bf14));
    __hv_mul_f(VIf(Bf13), VIf(Bf8), VOf(Bf13));
    __hv_mul_f(VIf(Bf6), VIf(Bf8), VOf(Bf6));
    __hv_mul_f(VIf(Bf0), VIf(Bf8), VOf(Bf8));
    __hv_line_f(&sLine_lHcwtND4, VOf(Bf8));
    __hv_mul_f(VIf(Bf3), VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf6), 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f);
    __hv_mul_f(VIf(Bf8), VIf(Bf6), VOf(Bf6));
    __hv_tabwrite_f(&sTabwrite_51eNDjbo, VIf(Bf6));
    __hv_line_f(&sLine_WlHXNuWP, VOf(Bf8));
    __hv_phasor_f(&sPhasor_RvPlim6J, VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf0), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf8), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf10), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf0), VIf(Bf10), VOf(Bf10));
    __hv_floor_f(VIf(Bf10), VOf(Bf0));
    __hv_sub_f(VIf(Bf10), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf10), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf0), VIf(Bf10), VOf(Bf10));
    __hv_abs_f(VIf(Bf10), VOf(Bf10));
    __hv_var_k_f(VOf(Bf0), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf10), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf10), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf0), VIf(Bf10), VOf(Bf10));
    __hv_mul_f(VIf(Bf10), VIf(Bf10), VOf(Bf0));
    __hv_mul_f(VIf(Bf10), VIf(Bf0), VOf(Bf9));
    __hv_mul_f(VIf(Bf9), VIf(Bf0), VOf(Bf7));
    __hv_mul_f(VIf(Bf7), VIf(Bf0), VOf(Bf5));
    __hv_mul_f(VIf(Bf5), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf1), 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f);
    __hv_var_k_f(VOf(Bf12), 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f);
    __hv_var_k_f(VOf(Bf2), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf9), VIf(Bf2), VOf(Bf2));
    __hv_sub_f(VIf(Bf10), VIf(Bf2), VOf(Bf2));
    __hv_fma_f(VIf(Bf7), VIf(Bf12), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf12), 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f);
    __hv_mul_f(VIf(Bf5), VIf(Bf12), VOf(Bf12));
    __hv_sub_f(VIf(Bf2), VIf(Bf12), VOf(Bf12));
    __hv_fma_f(VIf(Bf0), VIf(Bf1), VIf(Bf12), VOf(Bf12));
    __hv_line_f(&sLine_tuaBH17A, VOf(Bf1));
    __hv_line_f(&sLine_sxvqfvcd, VOf(Bf0));
    __hv_fma_f(VIf(Bf8), VIf(Bf1), VIf(Bf0), VOf(Bf2));
    __hv_tabhead_f(&sTabhead_PMLtdrpw, VOf(Bf5));
    __hv_var_k_f_r(VOf(Bf7), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf5), VIf(Bf7), VOf(Bf7));
    __hv_varread_f(&sVarf_L9y5R30m, VOf(Bf5));
    __hv_mul_f(VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_R18Afh3V, VOf(Bf2));
    __hv_min_f(VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_zero_f(VOf(Bf5));
    __hv_max_f(VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_sub_f(VIf(Bf7), VIf(Bf5), VOf(Bf5));
    __hv_floor_f(VIf(Bf5), VOf(Bf7));
    __hv_varread_f(&sVarf_AhTj46c4, VOf(Bf2));
    __hv_zero_f(VOf(Bf10));
    __hv_lt_f(VIf(Bf7), VIf(Bf10), VOf(Bf10));
    __hv_and_f(VIf(Bf2), VIf(Bf10), VOf(Bf10));
    __hv_add_f(VIf(Bf7), VIf(Bf10), VOf(Bf10));
    __hv_cast_fi(VIf(Bf10), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_I0H38l03, VIi(Bi1), VOf(Bf10));
    __hv_tabread_if(&sTabread_CPezLUZB, VIi(Bi0), VOf(Bf2));
    __hv_sub_f(VIf(Bf10), VIf(Bf2), VOf(Bf10));
    __hv_sub_f(VIf(Bf5), VIf(Bf7), VOf(Bf7));
    __hv_fma_f(VIf(Bf10), VIf(Bf7), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf7), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_add_f(VIf(Bf8), VIf(Bf7), VOf(Bf7));
    __hv_floor_f(VIf(Bf7), VOf(Bf8));
    __hv_sub_f(VIf(Bf7), VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf7), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf8), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf10), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf7), VIf(Bf10), VOf(Bf10));
    __hv_floor_f(VIf(Bf10), VOf(Bf7));
    __hv_sub_f(VIf(Bf10), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf10), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf7), VIf(Bf10), VOf(Bf10));
    __hv_abs_f(VIf(Bf10), VOf(Bf10));
    __hv_var_k_f(VOf(Bf7), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf10), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf10), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf7), VIf(Bf10), VOf(Bf10));
    __hv_mul_f(VIf(Bf10), VIf(Bf10), VOf(Bf7));
    __hv_mul_f(VIf(Bf10), VIf(Bf7), VOf(Bf5));
    __hv_mul_f(VIf(Bf5), VIf(Bf7), VOf(Bf9));
    __hv_mul_f(VIf(Bf9), VIf(Bf7), VOf(Bf15));
    __hv_mul_f(VIf(Bf15), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf16), 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f);
    __hv_var_k_f(VOf(Bf17), 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f);
    __hv_var_k_f(VOf(Bf18), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf5), VIf(Bf18), VOf(Bf18));
    __hv_sub_f(VIf(Bf10), VIf(Bf18), VOf(Bf18));
    __hv_fma_f(VIf(Bf9), VIf(Bf17), VIf(Bf18), VOf(Bf18));
    __hv_var_k_f(VOf(Bf17), 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f);
    __hv_mul_f(VIf(Bf15), VIf(Bf17), VOf(Bf17));
    __hv_sub_f(VIf(Bf18), VIf(Bf17), VOf(Bf17));
    __hv_fma_f(VIf(Bf7), VIf(Bf16), VIf(Bf17), VOf(Bf17));
    __hv_fma_f(VIf(Bf8), VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_tabhead_f(&sTabhead_L2IXd7wk, VOf(Bf1));
    __hv_var_k_f_r(VOf(Bf8), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf1), VIf(Bf8), VOf(Bf8));
    __hv_varread_f(&sVarf_jDXW83IH, VOf(Bf1));
    __hv_mul_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_ozr8VZvi, VOf(Bf0));
    __hv_min_f(VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_zero_f(VOf(Bf1));
    __hv_max_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_sub_f(VIf(Bf8), VIf(Bf1), VOf(Bf1));
    __hv_floor_f(VIf(Bf1), VOf(Bf8));
    __hv_varread_f(&sVarf_HaKYpd9K, VOf(Bf0));
    __hv_zero_f(VOf(Bf16));
    __hv_lt_f(VIf(Bf8), VIf(Bf16), VOf(Bf16));
    __hv_and_f(VIf(Bf0), VIf(Bf16), VOf(Bf16));
    __hv_add_f(VIf(Bf8), VIf(Bf16), VOf(Bf16));
    __hv_cast_fi(VIf(Bf16), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_kNN0j8Z2, VIi(Bi1), VOf(Bf16));
    __hv_tabread_if(&sTabread_XJPTuspF, VIi(Bi0), VOf(Bf0));
    __hv_sub_f(VIf(Bf16), VIf(Bf0), VOf(Bf16));
    __hv_sub_f(VIf(Bf1), VIf(Bf8), VOf(Bf8));
    __hv_fma_f(VIf(Bf16), VIf(Bf8), VIf(Bf0), VOf(Bf0));
    __hv_mul_f(VIf(Bf17), VIf(Bf0), VOf(Bf0));
    __hv_fma_f(VIf(Bf12), VIf(Bf2), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_LIVUU1FQ, VOf(Bf2));
    __hv_tabhead_f(&sTabhead_giiQwRtq, VOf(Bf12));
    __hv_var_k_f_r(VOf(Bf17), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf12), VIf(Bf17), VOf(Bf17));
    __hv_varread_f(&sVarf_kDiruckg, VOf(Bf12));
    __hv_mul_f(VIf(Bf2), VIf(Bf12), VOf(Bf12));
    __hv_varread_f(&sVarf_HwFWfFNM, VOf(Bf2));
    __hv_min_f(VIf(Bf12), VIf(Bf2), VOf(Bf2));
    __hv_zero_f(VOf(Bf12));
    __hv_max_f(VIf(Bf2), VIf(Bf12), VOf(Bf12));
    __hv_sub_f(VIf(Bf17), VIf(Bf12), VOf(Bf12));
    __hv_floor_f(VIf(Bf12), VOf(Bf17));
    __hv_varread_f(&sVarf_xuk4n1dP, VOf(Bf2));
    __hv_zero_f(VOf(Bf8));
    __hv_lt_f(VIf(Bf17), VIf(Bf8), VOf(Bf8));
    __hv_and_f(VIf(Bf2), VIf(Bf8), VOf(Bf8));
    __hv_add_f(VIf(Bf17), VIf(Bf8), VOf(Bf8));
    __hv_cast_fi(VIf(Bf8), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_3nASrSsT, VIi(Bi1), VOf(Bf8));
    __hv_tabread_if(&sTabread_ech3nxre, VIi(Bi0), VOf(Bf2));
    __hv_sub_f(VIf(Bf8), VIf(Bf2), VOf(Bf8));
    __hv_sub_f(VIf(Bf12), VIf(Bf17), VOf(Bf17));
    __hv_fma_f(VIf(Bf8), VIf(Bf17), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_6aYJjZ2P, VOf(Bf17));
    __hv_rpole_f(&sRPole_444mGrFd, VIf(Bf2), VIf(Bf17), VOf(Bf17));
    __hv_var_k_f(VOf(Bf2), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_del1_f(&sDel1_6XyvKq36, VIf(Bf17), VOf(Bf8));
    __hv_mul_f(VIf(Bf8), VIf(Bf2), VOf(Bf2));
    __hv_sub_f(VIf(Bf17), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_BrQsobmA, VOf(Bf17));
    __hv_mul_f(VIf(Bf2), VIf(Bf17), VOf(Bf17));
    __hv_varread_f(&sVarf_pCBZ9CxV, VOf(Bf2));
    __hv_mul_f(VIf(Bf17), VIf(Bf2), VOf(Bf2));
    __hv_add_f(VIf(Bf0), VIf(Bf2), VOf(Bf17));
    __hv_line_f(&sLine_Op6ntHhI, VOf(Bf8));
    __hv_varread_f(&sVarf_GwYXgCuK, VOf(Bf12));
    __hv_mul_f(VIf(Bf2), VIf(Bf12), VOf(Bf12));
    __hv_varread_f(&sVarf_qeoDPrmj, VOf(Bf2));
    __hv_rpole_f(&sRPole_BgGAIs7i, VIf(Bf12), VIf(Bf2), VOf(Bf2));
    __hv_fma_f(VIf(Bf0), VIf(Bf8), VIf(Bf2), VOf(Bf2));
    __hv_tabwrite_f(&sTabwrite_RYeAX991, VIf(Bf2));
    __hv_add_f(VIf(Bf17), VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_qntFe5GV, VOf(Bf17));
    __hv_varread_f(&sVarf_poylECiY, VOf(Bf2));
    __hv_mul_f(VIf(Bf17), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf17), 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f);
    __hv_max_f(VIf(Bf2), VIf(Bf17), VOf(Bf17));
    __hv_varread_f(&sVarf_kTPQgpHs, VOf(Bf2));
    __hv_min_f(VIf(Bf17), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_6eiusMfy, VOf(Bf8));
    __hv_mul_f(VIf(Bf2), VIf(Bf8), VOf(Bf8));
    __hv_mul_f(VIf(Bf6), VIf(Bf8), VOf(Bf6));
    __hv_varread_f(&sVarf_3Osityy7, VOf(Bf2));
    __hv_mul_f(VIf(Bf6), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf6), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_sub_f(VIf(Bf8), VIf(Bf6), VOf(Bf8));
    __hv_cos_f(VIf(Bf17), VOf(Bf17));
    __hv_mul_f(VIf(Bf8), VIf(Bf17), VOf(Bf0));
    __hv_mul_f(VIf(Bf17), VIf(Bf17), VOf(Bf17));
    __hv_sub_f(VIf(Bf6), VIf(Bf17), VOf(Bf17));
    __hv_zero_f(VOf(Bf6));
    __hv_gt_f(VIf(Bf17), VIf(Bf6), VOf(Bf6));
    __hv_sqrt_f(VIf(Bf17), VOf(Bf17));
    __hv_and_f(VIf(Bf6), VIf(Bf17), VOf(Bf17));
    __hv_mul_f(VIf(Bf8), VIf(Bf17), VOf(Bf17));
    __hv_cpole_f(&sCPole_oF7L3vVo, VIf(Bf2), VIf(ZERO), VIf(Bf0), VIf(Bf17), VOf(Bf17), VOf(Bf0));
    __hv_varread_f(&sVarf_bj2eZCY4, VOf(Bf0));
    __hv_mul_f(VIf(Bf17), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_08CbyBYq, VOf(Bf17));
    __hv_rpole_f(&sRPole_WGmCYktU, VIf(Bf0), VIf(Bf17), VOf(Bf17));
    __hv_varread_f(&sVarf_OSmCag9h, VOf(Bf0));
    __hv_mul_f(VIf(Bf17), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_YJer2oM4, VOf(Bf17));
    __hv_rpole_f(&sRPole_s0g7hGgY, VIf(Bf0), VIf(Bf17), VOf(Bf17));
    __hv_varread_f(&sVarf_BkxhEV53, VOf(Bf0));
    __hv_mul_f(VIf(Bf17), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_NYESUzF7, VOf(Bf17));
    __hv_rpole_f(&sRPole_v6XMoTBh, VIf(Bf0), VIf(Bf17), VOf(Bf17));
    __hv_tabread_f(&sTabread_asKRgqEu, VOf(Bf0));
    __hv_varread_f(&sVarf_whuH0hKj, VOf(Bf2));
    __hv_mul_f(VIf(Bf0), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_0bYQByIo, VOf(Bf8));
    __hv_rpole_f(&sRPole_KsOlL7xe, VIf(Bf2), VIf(Bf8), VOf(Bf8));
    __hv_sub_f(VIf(Bf8), VIf(Bf0), VOf(Bf8));
    __hv_line_f(&sLine_eI1d28fs, VOf(Bf2));
    __hv_fma_f(VIf(Bf8), VIf(Bf2), VIf(Bf0), VOf(Bf0));
    __hv_line_f(&sLine_aYQ4VZ5j, VOf(Bf8));
    __hv_tabread_f(&sTabread_Qh0CG6EU, VOf(Bf6));
    __hv_add_f(VIf(Bf17), VIf(Bf6), VOf(Bf12));
    __hv_tabread_f(&sTabread_8foYB517, VOf(Bf16));
    __hv_add_f(VIf(Bf12), VIf(Bf16), VOf(Bf1));
    __hv_tabread_f(&sTabread_VGfjzqHs, VOf(Bf7));
    __hv_add_f(VIf(Bf1), VIf(Bf7), VOf(Bf18));
    __hv_tabread_f(&sTabread_Lp3ejuyW, VOf(Bf15));
    __hv_add_f(VIf(Bf18), VIf(Bf15), VOf(Bf9));
    __hv_tabread_f(&sTabread_uCY5INTW, VOf(Bf10));
    __hv_sub_f(VIf(Bf9), VIf(Bf10), VOf(Bf5));
    __hv_tabwrite_f(&sTabwrite_j404L5Zw, VIf(Bf5));
    __hv_sub_f(VIf(Bf18), VIf(Bf15), VOf(Bf15));
    __hv_tabwrite_f(&sTabwrite_xFHFKq7r, VIf(Bf15));
    __hv_sub_f(VIf(Bf1), VIf(Bf7), VOf(Bf7));
    __hv_tabwrite_f(&sTabwrite_QySLbTzx, VIf(Bf7));
    __hv_sub_f(VIf(Bf12), VIf(Bf16), VOf(Bf16));
    __hv_tabwrite_f(&sTabwrite_2mSse9h2, VIf(Bf16));
    __hv_sub_f(VIf(Bf17), VIf(Bf6), VOf(Bf6));
    __hv_tabwrite_f(&sTabwrite_odX501h4, VIf(Bf6));
    __hv_tabwrite_f(&sTabwrite_wRRsYXfs, VIf(Bf17));
    __hv_add_f(VIf(Bf9), VIf(Bf10), VOf(Bf10));
    __hv_tabread_f(&sTabread_bAhyqN7O, VOf(Bf9));
    __hv_fma_f(VIf(Bf0), VIf(Bf8), VIf(Bf10), VOf(Bf10));
    __hv_tabread_f(&sTabread_3O74jFKr, VOf(Bf0));
    __hv_varread_f(&sVarf_7PLCXbqK, VOf(Bf6));
    __hv_mul_f(VIf(Bf0), VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_K2FA8eor, VOf(Bf16));
    __hv_rpole_f(&sRPole_W4tWYkIB, VIf(Bf6), VIf(Bf16), VOf(Bf16));
    __hv_sub_f(VIf(Bf16), VIf(Bf0), VOf(Bf16));
    __hv_fma_f(VIf(Bf16), VIf(Bf2), VIf(Bf0), VOf(Bf0));
    __hv_fma_f(VIf(Bf0), VIf(Bf8), VIf(Bf9), VOf(Bf9));
    __hv_add_f(VIf(Bf10), VIf(Bf9), VOf(Bf0));
    __hv_tabread_f(&sTabread_KyYkqv9N, VOf(Bf16));
    __hv_varread_f(&sVarf_ePqZtHSi, VOf(Bf6));
    __hv_mul_f(VIf(Bf16), VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_ho69Xjjz, VOf(Bf12));
    __hv_rpole_f(&sRPole_kFOrIQEr, VIf(Bf6), VIf(Bf12), VOf(Bf12));
    __hv_sub_f(VIf(Bf12), VIf(Bf16), VOf(Bf12));
    __hv_fma_f(VIf(Bf12), VIf(Bf2), VIf(Bf16), VOf(Bf16));
    __hv_mul_f(VIf(Bf16), VIf(Bf8), VOf(Bf16));
    __hv_tabread_f(&sTabread_Jan5l5fZ, VOf(Bf12));
    __hv_varread_f(&sVarf_2TOgOlRb, VOf(Bf6));
    __hv_mul_f(VIf(Bf12), VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_UxXwpOiT, VOf(Bf7));
    __hv_rpole_f(&sRPole_iXBFhA1M, VIf(Bf6), VIf(Bf7), VOf(Bf7));
    __hv_sub_f(VIf(Bf7), VIf(Bf12), VOf(Bf7));
    __hv_fma_f(VIf(Bf7), VIf(Bf2), VIf(Bf12), VOf(Bf12));
    __hv_mul_f(VIf(Bf12), VIf(Bf8), VOf(Bf8));
    __hv_add_f(VIf(Bf16), VIf(Bf8), VOf(Bf12));
    __hv_add_f(VIf(Bf0), VIf(Bf12), VOf(Bf2));
    __hv_tabwrite_f(&sTabwrite_D9LtEcPs, VIf(Bf2));
    __hv_sub_f(VIf(Bf10), VIf(Bf9), VOf(Bf2));
    __hv_sub_f(VIf(Bf16), VIf(Bf8), VOf(Bf7));
    __hv_add_f(VIf(Bf2), VIf(Bf7), VOf(Bf6));
    __hv_tabwrite_f(&sTabwrite_jPyR4a4t, VIf(Bf6));
    __hv_sub_f(VIf(Bf0), VIf(Bf12), VOf(Bf12));
    __hv_tabwrite_f(&sTabwrite_6b7yuS5B, VIf(Bf12));
    __hv_sub_f(VIf(Bf2), VIf(Bf7), VOf(Bf7));
    __hv_tabwrite_f(&sTabwrite_ElpbN6Kw, VIf(Bf7));
    __hv_line_f(&sLine_DfVbyDW7, VOf(Bf7));
    __hv_mul_f(VIf(Bf10), VIf(Bf7), VOf(Bf10));
    __hv_mul_f(VIf(Bf9), VIf(Bf7), VOf(Bf9));
    __hv_mul_f(VIf(Bf16), VIf(Bf7), VOf(Bf16));
    __hv_mul_f(VIf(Bf8), VIf(Bf7), VOf(Bf7));
    __hv_add_f(VIf(Bf17), VIf(Bf10), VOf(Bf10));
    __hv_var_k_f(VOf(Bf17), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf10), VIf(Bf17), VOf(Bf17));
    __hv_add_f(VIf(Bf14), VIf(Bf17), VOf(Bf14));
    __hv_line_f(&sLine_m6r8KmmR, VOf(Bf10));
    __hv_mul_f(VIf(Bf3), VIf(Bf10), VOf(Bf10));
    __hv_tabwrite_f(&sTabwrite_coE7euhU, VIf(Bf10));
    __hv_line_f(&sLine_YcekOZL7, VOf(Bf10));
    __hv_phasor_f(&sPhasor_31EzkRjE, VIf(Bf10), VOf(Bf10));
    __hv_var_k_f(VOf(Bf3), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf10), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf7), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf3), VIf(Bf7), VOf(Bf7));
    __hv_floor_f(VIf(Bf7), VOf(Bf3));
    __hv_sub_f(VIf(Bf7), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf7), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf3), VIf(Bf7), VOf(Bf7));
    __hv_abs_f(VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf3), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf7), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf7), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf3), VIf(Bf7), VOf(Bf7));
    __hv_mul_f(VIf(Bf7), VIf(Bf7), VOf(Bf3));
    __hv_mul_f(VIf(Bf7), VIf(Bf3), VOf(Bf16));
    __hv_mul_f(VIf(Bf16), VIf(Bf3), VOf(Bf9));
    __hv_mul_f(VIf(Bf9), VIf(Bf3), VOf(Bf8));
    __hv_mul_f(VIf(Bf8), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf2), 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f);
    __hv_var_k_f(VOf(Bf12), 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f);
    __hv_var_k_f(VOf(Bf0), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf16), VIf(Bf0), VOf(Bf0));
    __hv_sub_f(VIf(Bf7), VIf(Bf0), VOf(Bf0));
    __hv_fma_f(VIf(Bf9), VIf(Bf12), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf12), 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f);
    __hv_mul_f(VIf(Bf8), VIf(Bf12), VOf(Bf12));
    __hv_sub_f(VIf(Bf0), VIf(Bf12), VOf(Bf12));
    __hv_fma_f(VIf(Bf3), VIf(Bf2), VIf(Bf12), VOf(Bf12));
    __hv_line_f(&sLine_36dYtuzu, VOf(Bf2));
    __hv_line_f(&sLine_mQEdlnwW, VOf(Bf3));
    __hv_fma_f(VIf(Bf10), VIf(Bf2), VIf(Bf3), VOf(Bf0));
    __hv_tabhead_f(&sTabhead_5fF3IAoe, VOf(Bf8));
    __hv_var_k_f_r(VOf(Bf9), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf8), VIf(Bf9), VOf(Bf9));
    __hv_varread_f(&sVarf_G6b7jUQ2, VOf(Bf8));
    __hv_mul_f(VIf(Bf0), VIf(Bf8), VOf(Bf8));
    __hv_varread_f(&sVarf_t46iamp4, VOf(Bf0));
    __hv_min_f(VIf(Bf8), VIf(Bf0), VOf(Bf0));
    __hv_zero_f(VOf(Bf8));
    __hv_max_f(VIf(Bf0), VIf(Bf8), VOf(Bf8));
    __hv_sub_f(VIf(Bf9), VIf(Bf8), VOf(Bf8));
    __hv_floor_f(VIf(Bf8), VOf(Bf9));
    __hv_varread_f(&sVarf_Oln9UMIu, VOf(Bf0));
    __hv_zero_f(VOf(Bf7));
    __hv_lt_f(VIf(Bf9), VIf(Bf7), VOf(Bf7));
    __hv_and_f(VIf(Bf0), VIf(Bf7), VOf(Bf7));
    __hv_add_f(VIf(Bf9), VIf(Bf7), VOf(Bf7));
    __hv_cast_fi(VIf(Bf7), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_BjJk5MLX, VIi(Bi1), VOf(Bf7));
    __hv_tabread_if(&sTabread_Rm24NaLW, VIi(Bi0), VOf(Bf0));
    __hv_sub_f(VIf(Bf7), VIf(Bf0), VOf(Bf7));
    __hv_sub_f(VIf(Bf8), VIf(Bf9), VOf(Bf9));
    __hv_fma_f(VIf(Bf7), VIf(Bf9), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf9), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_add_f(VIf(Bf10), VIf(Bf9), VOf(Bf9));
    __hv_floor_f(VIf(Bf9), VOf(Bf10));
    __hv_sub_f(VIf(Bf9), VIf(Bf10), VOf(Bf10));
    __hv_var_k_f(VOf(Bf9), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf10), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf7), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf9), VIf(Bf7), VOf(Bf7));
    __hv_floor_f(VIf(Bf7), VOf(Bf9));
    __hv_sub_f(VIf(Bf7), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf7), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf9), VIf(Bf7), VOf(Bf7));
    __hv_abs_f(VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf9), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf7), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf7), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf9), VIf(Bf7), VOf(Bf7));
    __hv_mul_f(VIf(Bf7), VIf(Bf7), VOf(Bf9));
    __hv_mul_f(VIf(Bf7), VIf(Bf9), VOf(Bf8));
    __hv_mul_f(VIf(Bf8), VIf(Bf9), VOf(Bf16));
    __hv_mul_f(VIf(Bf16), VIf(Bf9), VOf(Bf6));
    __hv_mul_f(VIf(Bf6), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf1), 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f);
    __hv_var_k_f(VOf(Bf15), 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f);
    __hv_var_k_f(VOf(Bf18), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf8), VIf(Bf18), VOf(Bf18));
    __hv_sub_f(VIf(Bf7), VIf(Bf18), VOf(Bf18));
    __hv_fma_f(VIf(Bf16), VIf(Bf15), VIf(Bf18), VOf(Bf18));
    __hv_var_k_f(VOf(Bf15), 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f);
    __hv_mul_f(VIf(Bf6), VIf(Bf15), VOf(Bf15));
    __hv_sub_f(VIf(Bf18), VIf(Bf15), VOf(Bf15));
    __hv_fma_f(VIf(Bf9), VIf(Bf1), VIf(Bf15), VOf(Bf15));
    __hv_fma_f(VIf(Bf10), VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_tabhead_f(&sTabhead_rTuzGRZM, VOf(Bf2));
    __hv_var_k_f_r(VOf(Bf10), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf2), VIf(Bf10), VOf(Bf10));
    __hv_varread_f(&sVarf_zmtDYAVK, VOf(Bf2));
    __hv_mul_f(VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_NLQvdtS2, VOf(Bf3));
    __hv_min_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_zero_f(VOf(Bf2));
    __hv_max_f(VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_sub_f(VIf(Bf10), VIf(Bf2), VOf(Bf2));
    __hv_floor_f(VIf(Bf2), VOf(Bf10));
    __hv_varread_f(&sVarf_GCrHknxZ, VOf(Bf3));
    __hv_zero_f(VOf(Bf1));
    __hv_lt_f(VIf(Bf10), VIf(Bf1), VOf(Bf1));
    __hv_and_f(VIf(Bf3), VIf(Bf1), VOf(Bf1));
    __hv_add_f(VIf(Bf10), VIf(Bf1), VOf(Bf1));
    __hv_cast_fi(VIf(Bf1), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_Z7IUu2a1, VIi(Bi1), VOf(Bf1));
    __hv_tabread_if(&sTabread_jcVFnlOu, VIi(Bi0), VOf(Bf3));
    __hv_sub_f(VIf(Bf1), VIf(Bf3), VOf(Bf1));
    __hv_sub_f(VIf(Bf2), VIf(Bf10), VOf(Bf10));
    __hv_fma_f(VIf(Bf1), VIf(Bf10), VIf(Bf3), VOf(Bf3));
    __hv_mul_f(VIf(Bf15), VIf(Bf3), VOf(Bf3));
    __hv_fma_f(VIf(Bf12), VIf(Bf0), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_wLskBSGz, VOf(Bf0));
    __hv_tabhead_f(&sTabhead_XiYdHUxj, VOf(Bf12));
    __hv_var_k_f_r(VOf(Bf15), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf12), VIf(Bf15), VOf(Bf15));
    __hv_varread_f(&sVarf_25RKwJ8C, VOf(Bf12));
    __hv_mul_f(VIf(Bf0), VIf(Bf12), VOf(Bf12));
    __hv_varread_f(&sVarf_1drvCDm3, VOf(Bf0));
    __hv_min_f(VIf(Bf12), VIf(Bf0), VOf(Bf0));
    __hv_zero_f(VOf(Bf12));
    __hv_max_f(VIf(Bf0), VIf(Bf12), VOf(Bf12));
    __hv_sub_f(VIf(Bf15), VIf(Bf12), VOf(Bf12));
    __hv_floor_f(VIf(Bf12), VOf(Bf15));
    __hv_varread_f(&sVarf_r3Ua9Jir, VOf(Bf0));
    __hv_zero_f(VOf(Bf10));
    __hv_lt_f(VIf(Bf15), VIf(Bf10), VOf(Bf10));
    __hv_and_f(VIf(Bf0), VIf(Bf10), VOf(Bf10));
    __hv_add_f(VIf(Bf15), VIf(Bf10), VOf(Bf10));
    __hv_cast_fi(VIf(Bf10), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_Lwfmi9Hs, VIi(Bi1), VOf(Bf10));
    __hv_tabread_if(&sTabread_E1MAtL8n, VIi(Bi0), VOf(Bf0));
    __hv_sub_f(VIf(Bf10), VIf(Bf0), VOf(Bf10));
    __hv_sub_f(VIf(Bf12), VIf(Bf15), VOf(Bf15));
    __hv_fma_f(VIf(Bf10), VIf(Bf15), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_mLl7yrEg, VOf(Bf15));
    __hv_rpole_f(&sRPole_gCMUpcst, VIf(Bf0), VIf(Bf15), VOf(Bf15));
    __hv_var_k_f(VOf(Bf0), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_del1_f(&sDel1_BhwCJ4YN, VIf(Bf15), VOf(Bf10));
    __hv_mul_f(VIf(Bf10), VIf(Bf0), VOf(Bf0));
    __hv_sub_f(VIf(Bf15), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_l5HTGxd2, VOf(Bf15));
    __hv_mul_f(VIf(Bf0), VIf(Bf15), VOf(Bf15));
    __hv_varread_f(&sVarf_XWVtQp3n, VOf(Bf0));
    __hv_mul_f(VIf(Bf15), VIf(Bf0), VOf(Bf0));
    __hv_add_f(VIf(Bf3), VIf(Bf0), VOf(Bf15));
    __hv_line_f(&sLine_HvrvnWCE, VOf(Bf10));
    __hv_varread_f(&sVarf_SyniOFL9, VOf(Bf12));
    __hv_mul_f(VIf(Bf0), VIf(Bf12), VOf(Bf12));
    __hv_varread_f(&sVarf_uMa0hI9E, VOf(Bf0));
    __hv_rpole_f(&sRPole_lsmy9sLq, VIf(Bf12), VIf(Bf0), VOf(Bf0));
    __hv_fma_f(VIf(Bf3), VIf(Bf10), VIf(Bf0), VOf(Bf0));
    __hv_tabwrite_f(&sTabwrite_uXBoxlN4, VIf(Bf0));
    __hv_var_k_f(VOf(Bf0), 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f);
    __hv_mul_f(VIf(Bf15), VIf(Bf0), VOf(Bf0));
    __hv_add_f(VIf(Bf14), VIf(Bf0), VOf(Bf14));
    __hv_add_f(VIf(Bf13), VIf(Bf17), VOf(Bf17));
    __hv_add_f(VIf(Bf17), VIf(Bf0), VOf(Bf0));
    __hv_line_f(&sLine_9IcO3ryA, VOf(Bf17));
    __hv_mul_f(VIf(Bf14), VIf(Bf17), VOf(Bf14));
    __hv_mul_f(VIf(Bf0), VIf(Bf17), VOf(Bf17));
    __hv_add_f(VIf(Bf4), VIf(Bf14), VOf(Bf14));
    __hv_add_f(VIf(Bf11), VIf(Bf17), VOf(Bf17));
    __hv_line_f(&sLine_KKusIHT9, VOf(Bf11));
    __hv_mul_f(VIf(Bf14), VIf(Bf11), VOf(Bf14));
    __hv_mul_f(VIf(Bf17), VIf(Bf11), VOf(Bf11));
    __hv_add_f(VIf(Bf14), VIf(O0), VOf(O0));
    __hv_add_f(VIf(Bf11), VIf(O1), VOf(O1));

    // save output vars to output buffer
    __hv_store_f(outputBuffers[0]+n, VIf(O0));
    __hv_store_f(outputBuffers[1]+n, VIf(O1));
  }

  blockStartTimestamp = nextBlock;

  return n4; // return the number of frames processed

}

int Heavy_PhaseRing::processInline(float *inputBuffers, float *outputBuffers, int n4) {
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

int Heavy_PhaseRing::processInlineInterleaved(float *inputBuffers, float *outputBuffers, int n4) {
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
